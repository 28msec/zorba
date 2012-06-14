
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
#line 87 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"


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
#line 79 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 878 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 978 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 109 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"

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
#line 178 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
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
#line 876 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 285 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 124: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 875 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 294 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 149: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 874 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 303 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 312 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 321 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 330 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 339 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 348 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 357 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 366 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 375 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 384 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 393 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 402 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 411 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 420 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 429 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 438 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 447 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 456 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 465 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 474 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 483 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 492 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 501 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 510 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 519 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 899 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 528 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 899 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 537 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 546 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 555 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 564 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 573 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 582 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 591 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 600 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 899 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 609 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 618 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 627 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 636 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 645 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 654 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 663 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 672 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 899 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 681 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 690 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 699 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 708 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 717 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 726 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 735 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 744 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 753 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 762 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 771 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 780 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 789 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 825 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 834 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 843 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 861 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 870 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 897 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 906 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 915 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 933 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 942 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 951 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 960 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 969 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 978 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 987 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 996 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1005 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1014 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1023 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1032 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1041 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1050 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1059 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1068 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1077 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1086 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1095 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1104 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1113 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1122 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1131 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1140 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1149 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1158 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1167 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1176 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1185 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1194 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1203 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1212 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1221 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1230 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1239 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1248 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1257 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1266 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1275 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1284 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1293 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1302 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1311 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1320 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1329 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1338 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1347 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1356 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1365 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1374 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1383 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1392 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1401 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1410 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1419 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1428 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1437 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1446 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1455 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1464 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1473 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1482 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1491 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1500 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1509 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1518 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1527 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1536 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1545 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1554 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1563 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1572 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1581 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1590 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1599 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1608 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1617 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1626 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1635 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1644 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1653 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1662 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1671 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1680 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1689 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1698 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1707 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1716 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1725 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1734 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1743 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1752 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1761 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1770 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1779 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1788 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1797 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1806 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1815 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1824 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1833 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1842 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1851 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1860 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1869 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1878 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1887 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1896 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1905 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1914 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1923 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1932 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1941 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1950 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1959 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1968 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1977 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1986 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1995 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2004 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2013 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2022 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2031 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2040 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2049 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2058 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2067 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2076 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2085 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2094 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2103 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2112 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2121 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2130 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2139 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2148 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2157 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2166 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2175 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2184 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2193 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2202 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2211 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 890 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2220 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2229 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2238 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2247 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2256 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2265 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2274 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2283 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2292 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2301 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2310 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2319 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 899 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2328 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2337 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2346 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2355 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2364 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2373 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2382 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2391 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2400 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2409 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2418 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2427 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2436 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2445 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2454 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2463 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2472 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2481 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2490 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2499 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2508 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2517 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2526 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2535 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2544 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2553 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2562 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2571 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2580 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2589 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2598 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2607 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2616 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2625 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2634 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2643 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2652 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 623: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2661 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2670 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 627: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2679 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2688 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2697 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
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
#line 140 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 553 of lalr1.cc  */
#line 2782 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"

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
#line 996 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 1005 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 1014 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1020 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1028 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1034 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1045 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1050 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1058 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1065 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1072 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1081 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1088 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1096 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1104 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1112 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1123 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1128 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1135 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1142 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1154 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1164 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1171 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1178 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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
#line 1213 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1218 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1226 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1234 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1242 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1247 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1255 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1260 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1268 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1273 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1281 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1288 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1295 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1302 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1317 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1327 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1332 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1340 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1348 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1359 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1366 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1377 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1382 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1390 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1397 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1404 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1413 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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
#line 1426 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1434 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1441 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1451 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1458 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1465 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1488 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1494 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1503 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1510 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1520 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1529 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1530 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1531 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1532 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1533 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1534 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1535 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1536 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1537 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1538 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1544 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1552 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1560 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1568 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1575 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1583 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1590 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1595 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1603 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1611 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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
#line 1626 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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
#line 1641 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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
#line 1659 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1664 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1672 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1680 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1691 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1696 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1705 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1710 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1717 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1722 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1732 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1737 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1746 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1752 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1765 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1770 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1778 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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
#line 1789 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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
#line 1804 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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
#line 1816 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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
#line 1831 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1836 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1841 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1846 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1854 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1861 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1872 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1877 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1887 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1894 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1901 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1908 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1918 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1922 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1932 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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
#line 1940 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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
#line 1951 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1957 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1966 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1971 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1978 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1985 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1997 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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
#line 2007 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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
#line 2017 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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
#line 2028 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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
#line 2044 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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
#line 2064 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2069 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 2073 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 2081 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2086 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2090 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2098 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2103 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2115 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2122 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2151 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2156 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2164 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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
#line 2181 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2189 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2197 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2204 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2211 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2221 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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
#line 2233 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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
#line 2246 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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
#line 2258 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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
#line 2274 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 2282 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 2290 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 2298 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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
#line 2313 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 2318 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 2326 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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
#line 2340 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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
#line 2357 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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
#line 2382 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2390 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2397 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2408 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2418 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2423 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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

  case 219:

/* Line 678 of lalr1.cc  */
#line 2461 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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

  case 220:

/* Line 678 of lalr1.cc  */
#line 2475 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2483 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 2488 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2496 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2501 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2506 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2514 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2523 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2535 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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

  case 229:

/* Line 678 of lalr1.cc  */
#line 2545 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2558 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2582 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2589 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2599 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2607 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2614 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2624 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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

  case 245:

/* Line 678 of lalr1.cc  */
#line 2634 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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

  case 246:

/* Line 678 of lalr1.cc  */
#line 2644 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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

  case 247:

/* Line 678 of lalr1.cc  */
#line 2654 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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

  case 248:

/* Line 678 of lalr1.cc  */
#line 2664 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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

  case 249:

/* Line 678 of lalr1.cc  */
#line 2674 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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

  case 250:

/* Line 678 of lalr1.cc  */
#line 2684 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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

  case 251:

/* Line 678 of lalr1.cc  */
#line 2694 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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

  case 252:

/* Line 678 of lalr1.cc  */
#line 2705 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2714 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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

  case 254:

/* Line 678 of lalr1.cc  */
#line 2724 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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

  case 255:

/* Line 678 of lalr1.cc  */
#line 2734 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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

  case 256:

/* Line 678 of lalr1.cc  */
#line 2750 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2759 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2768 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2776 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2782 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2794 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2802 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2812 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2820 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2832 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2838 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2851 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2855 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2863 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2867 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2876 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2880 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2884 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2894 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2902 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2909 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2915 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2925 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2929 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2933 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2941 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2949 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2957 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         NULL,
                         NULL,
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2969 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2977 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2983 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2993 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2999 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 3009 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 3013 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 3023 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 3029 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3035 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3041 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3050 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3059 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3068 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3081 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3085 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3093 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3099 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3109 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3117 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3126 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3139 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3146 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3158 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3162 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3174 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3181 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3187 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3196 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3203 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3209 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3220 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3227 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3233 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3242 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3251 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3258 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3269 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3276 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3288 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3294 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3306 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3312 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3323 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3329 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3340 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3346 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3357 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3366 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3370 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3379 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3383 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3391 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3395 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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

  case 340:

/* Line 678 of lalr1.cc  */
#line 3405 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3412 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3421 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3430 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3435 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3444 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3453 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3462 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3475 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3479 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3491 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3495 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3502 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3506 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3513 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3517 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3526 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3530 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3534 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3543 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3547 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3553 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3559 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3565 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3576 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3580 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3584 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3592 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3596 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3602 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3612 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3616 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3626 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3630 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3640 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3644 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3654 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3658 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3668 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3672 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3680 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3684 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3688 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3692 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3702 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3706 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3710 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3718 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3722 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3726 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3730 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3734 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3738 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3746 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3750 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3754 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3762 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3766 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3770 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3774 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3785 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3791 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3801 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3807 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3817 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3821 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3825 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3863 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3867 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3877 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3887 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3900 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3909 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      AxisStep* as = dynamic_cast<AxisStep*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (as ?
            new RelativePathExpr(LOC((yyloc)),
                                 ParseConstants::st_slash,
                                 new ContextItemExpr( LOC((yyloc)), true ), (yysemantic_stack_[(1) - (1)].expr))
            :
            (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3919 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3923 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3932 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3936 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3945 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3951 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3959 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3965 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3977 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3983 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3993 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3997 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 4001 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 4005 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 4009 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 4015 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 4021 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4029 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4033 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4041 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4045 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4056 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4060 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4064 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4070 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4074 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4088 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4092 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4100 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4104 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4114 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4118 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4122 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4126 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4135 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4139 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4143 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4147 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4155 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4161 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4171 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4179 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4183 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4187 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4191 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4195 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4199 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4203 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4207 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4211 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4221 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4229 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4233 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4241 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4248 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4255 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4266 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4274 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4278 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4286 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4294 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4302 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4356 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4360 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4373 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4379 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4389 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4393 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4401 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4405 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4409 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4417 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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

  case 485:

/* Line 678 of lalr1.cc  */
#line 4427 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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

  case 486:

/* Line 678 of lalr1.cc  */
#line 4437 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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

  case 487:

/* Line 678 of lalr1.cc  */
#line 4447 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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

  case 488:

/* Line 678 of lalr1.cc  */
#line 4457 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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

  case 489:

/* Line 678 of lalr1.cc  */
#line 4467 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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

  case 490:

/* Line 678 of lalr1.cc  */
#line 4482 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4488 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4499 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4505 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4516 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4533 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4538 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4547 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4551 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4558 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4564 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4570 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4578 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4590 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4594 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4601 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4607 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4613 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4620 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4631 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4635 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4645 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4649 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4659 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4663 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4667 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4672 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4681 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4687 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4693 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4699 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4707 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4712 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4720 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4725 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4733 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4741 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4746 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4751 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4756 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4761 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4766 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4775 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4783 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4787 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4804 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4808 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4816 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4824 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4832 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4836 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4844 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4850 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4860 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4868 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4872 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4876 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4911 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4917 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4923 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4933 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4937 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4941 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4945 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4949 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4956 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4962 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4972 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4980 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4984 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 4988 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 4992 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 4996 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5000 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5004 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5008 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5012 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5020 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5028 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5032 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5036 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5046 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5054 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5062 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5066 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5070 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5078 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5082 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5088 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5094 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5098 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5108 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5116 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5120 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5126 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5135 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5144 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5150 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5156 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5166 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5183 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5190 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5205 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5241 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5245 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5253 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5261 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5273 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5277 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5285 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5293 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5297 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5308 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5325 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5331 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5337 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5347 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5351 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5357 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5363 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5367 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5373 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5377 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5383 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5389 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5396 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5406 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5411 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5419 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5425 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5435 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5457 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5466 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5472 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5485 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5499 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5506 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5512 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5522 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5531 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5539 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5545 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5563 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5571 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5575 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5582 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5587 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5595 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5599 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5606 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5610 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5617 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5621 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5628 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5632 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5641 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5653 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5657 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5664 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5668 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5676 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5684 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5692 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5696 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5703 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5707 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5715 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5726 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5730 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5738 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5750 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5756 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5765 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5769 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5777 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5781 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5785 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5792 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5796 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5803 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5807 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5815 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5819 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5823 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5827 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5831 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5839 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5847 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5859 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5871 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5875 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5879 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5887 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5893 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5903 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5907 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5911 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5915 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5919 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5923 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5927 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5931 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5939 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5943 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5947 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5951 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5959 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5965 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5975 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5985 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5989 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5997 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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

  case 704:

/* Line 678 of lalr1.cc  */
#line 6007 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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

  case 705:

/* Line 678 of lalr1.cc  */
#line 6018 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 6025 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 6029 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 6036 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 6040 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 6047 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 6052 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 6061 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 6070 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 6074 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 6081 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 6085 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6093 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6102 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6109 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 6119 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6123 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6130 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 6136 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 6145 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 6149 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 6156 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 6161 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 6173 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 6181 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6193 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6201 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 6205 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 6213 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 6217 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6221 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6229 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6237 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 6241 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 6245 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6249 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 6257 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 6265 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 6277 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6281 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 6289 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6307 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
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

  case 750:

/* Line 678 of lalr1.cc  */
#line 6320 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6321 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6322 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6323 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6324 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6325 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6326 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6327 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6328 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6329 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6330 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 6331 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6332 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6333 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6334 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6339 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 6340 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 6341 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6342 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 6343 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 6344 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6345 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6346 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 6347 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 6348 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6349 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 6350 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 6351 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 6352 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 6353 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 6354 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6355 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 6356 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 6357 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6358 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 6359 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 6360 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 6361 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6362 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6363 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 6364 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6365 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6366 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6367 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 6368 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6369 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6370 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6371 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6372 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6373 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6374 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6375 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6376 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6377 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6378 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6379 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6380 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6381 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6382 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6383 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6384 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6385 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6386 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6387 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6388 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6389 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6390 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6391 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6392 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6393 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6394 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6395 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6396 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6397 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6398 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6399 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6400 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6401 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6402 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6403 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6404 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6405 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6406 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6407 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6408 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6409 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6410 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6411 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6412 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6413 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6414 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6415 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6416 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6417 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6418 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6419 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6420 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6421 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6422 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6423 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6424 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6425 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6426 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6427 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6428 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6429 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6430 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6431 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6432 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6433 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6434 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6435 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6436 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6437 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6438 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6439 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6440 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6441 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6442 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6443 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6444 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6445 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6446 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6447 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6448 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6449 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6450 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6451 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6452 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6453 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6454 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6455 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6456 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6457 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6458 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6459 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6460 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6461 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6462 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6463 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6464 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6465 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6466 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6467 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6468 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6469 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6470 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6471 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6472 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6473 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6474 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6475 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6476 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6477 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6478 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6479 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6480 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6481 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6482 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6483 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6484 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6485 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6486 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6487 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6488 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6489 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6490 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6491 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6492 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6493 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6494 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6495 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6496 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6497 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6498 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6499 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6500 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6501 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6502 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6503 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6504 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6505 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6506 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6507 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6508 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6509 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6510 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6511 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6512 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6513 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6514 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6515 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6516 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6517 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6518 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6519 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6520 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 948:

/* Line 678 of lalr1.cc  */
#line 6521 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 949:

/* Line 678 of lalr1.cc  */
#line 6522 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 950:

/* Line 678 of lalr1.cc  */
#line 6523 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 951:

/* Line 678 of lalr1.cc  */
#line 6524 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 952:

/* Line 678 of lalr1.cc  */
#line 6525 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 953:

/* Line 678 of lalr1.cc  */
#line 6526 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 954:

/* Line 678 of lalr1.cc  */
#line 6527 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 955:

/* Line 678 of lalr1.cc  */
#line 6528 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 956:

/* Line 678 of lalr1.cc  */
#line 6529 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 957:

/* Line 678 of lalr1.cc  */
#line 6530 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 958:

/* Line 678 of lalr1.cc  */
#line 6531 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 959:

/* Line 678 of lalr1.cc  */
#line 6532 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 960:

/* Line 678 of lalr1.cc  */
#line 6533 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 961:

/* Line 678 of lalr1.cc  */
#line 6534 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 962:

/* Line 678 of lalr1.cc  */
#line 6535 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 963:

/* Line 678 of lalr1.cc  */
#line 6536 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 964:

/* Line 678 of lalr1.cc  */
#line 6542 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    {
          // EQName's namespace URI value is whitespace normalized according to the rules for the xs:anyURI type
          std::string uri = "\"" + SYMTAB((yysemantic_stack_[(3) - (1)].sval)) + "\"";
          std::string eqname = SYMTAB(driver.symtab.put_uri(uri.c_str(), uri.size())) + ":" + SYMTAB((yysemantic_stack_[(3) - (3)].sval));
          (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT(eqname.c_str())), true);
        }
    break;

  case 965:

/* Line 678 of lalr1.cc  */
#line 6548 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 678 of lalr1.cc  */
#line 11588 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1391;
  const short int
  xquery_parser::yypact_[] =
  {
      2711, -1391, -1391, -1391,  4202,  4202,  4202, -1391, -1391,    55,
     223,   354,    39,    29, -1391, -1391, -1391,   439, -1391, -1391,
   -1391,   351,   438,   661,   631,   507,   539,   160, -1391,    -6,
   -1391, -1391, -1391, -1391, -1391, -1391,   756, -1391,   605,   609,
   -1391, -1391, -1391, -1391,   714, -1391,   766, -1391,   710,   725,
   -1391,    64, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391,
   -1391, -1391, -1391, -1391, -1391, -1391,   451,   789, -1391, -1391,
   -1391, -1391,    53,  8672, -1391, -1391, -1391,   795, -1391, -1391,
   -1391,   808, -1391,   811,   814, -1391, -1391, 12412, -1391, -1391,
   -1391, -1391, -1391, -1391, -1391, -1391,   824, -1391, -1391,   826,
     836, -1391, -1391, -1391, -1391, -1391, -1391, -1391,  3010,  5990,
   12412, -1391, -1391, -1391, -1391, -1391, -1391, -1391,   813, -1391,
   -1391,   837,  9556, -1391,  9847,   842,   843, -1391, -1391, -1391,
     857, -1391,  8374, -1391, -1391, -1391, -1391, -1391, -1391,   827,
   -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391,    80,   767,
   -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391,   418,   825,
     689, -1391,   759,   -16, -1391, -1391, -1391, -1391, -1391, -1391,
     866, -1391,   747,   751,   745, -1391, -1391,   832,   839, -1391,
   -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391,
   -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391,
   -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391,
   -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391,
   -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391,
   -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391,
   -1391, -1391,  4500,   989, -1391,  4798, -1391, -1391,   137,    82,
   -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391,
   -1391, -1391, -1391, -1391,    89, -1391, -1391, -1391, -1391, -1391,
   -1391,   128, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391,
    4202, -1391, -1391, -1391, -1391,    34, -1391, -1391, -1391, -1391,
   -1391, -1391, -1391, -1391,   886, -1391,   804, -1391, -1391, -1391,
     146, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391,   828,
     904, -1391,   806,   754,   898,   565,   377,   531,   457, -1391,
     949,   802,   902,   903,  7182, -1391, -1391, -1391,   487, -1391,
   -1391,  8374, -1391,   737, -1391,   850,  8672, -1391,   850,  8672,
   -1391, -1391, -1391,   641, -1391, -1391, -1391, -1391, -1391, -1391,
   -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391,
   -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391,
   -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391,
   -1391, -1391, -1391, -1391, -1391, -1391,   893,   862,   860, -1391,
   -1391, -1391, -1391, -1391,   833, -1391,  4202,   835,   838,   428,
     428,   991,   548,   624,   538, 12697, 12412,     9,   974, 12412,
     871,   906,   315,  9556,   703,   780, 12412, 12412,   723,   746,
      41, -1391, -1391, -1391,  9556,  4202,   840,  4202,   111,  7480,
   10417,   750,   752, 12412,   911,    43,   878,  7480,  1033,   115,
      68, 12412,   918,   895,   934, -1391,  7480,  9263, 12412, 12412,
   12412,  4202,   855,  7480,  7480, 12412,  4202,   890,   894, -1391,
   -1391, -1391,  7480, 10702, -1391,   892, -1391,   899, -1391, -1391,
   -1391, -1391,   900, -1391,   901, -1391, -1391, -1391, -1391, -1391,
     905, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391,
   -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391,
   -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, 12412, -1391,
   -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391,
   -1391,   907, 12412, -1391, -1391, -1391,   867,  3308,   908,   909,
     910, 12412,  4202, -1391,   897,    65, -1391,   675,  1023,  7480,
   -1391, -1391,   103, -1391, -1391, -1391,  1042, -1391, -1391, -1391,
   -1391,  7480,   847, -1391,  1034,  7480,  7480,   875,  7480,  7480,
    7480,  7480,   841, 12412,   877,   879,  7480,  7480,  3010,   830,
   -1391, -1391, -1391, -1391,    39,   160,    91,    97,  1065,  5096,
    5096,  5394,  5394,   808, -1391, -1391,   886,   808, -1391,  7480,
   -1391,   952,   631,    -6,   912,   913,   914,  4202,  7480, -1391,
   -1391, -1391, -1391, -1391, -1391, -1391, -1391,  7778,  7778,  7778,
   -1391,  7778,  7778, -1391,  7778, -1391,  7778, -1391, -1391, -1391,
   -1391, -1391, -1391, -1391,  7778,  7778,  1002,  7778,  7778,  7778,
    7778,  7778,  7778,  7778,  7778,  7778,  7778,  7778,  7778,   845,
     982,   983,   984, -1391, -1391, -1391,  6288, -1391, -1391,  8374,
    8374,  7480,   850, -1391, -1391,   850, -1391,  6586,   850,  9556,
     930,  6884, -1391, -1391, -1391, -1391,    84, -1391,    86, -1391,
   -1391, -1391, -1391, -1391,   975,   978,   507,  1052, -1391, -1391,
   12697,   889,   566, 12412,   926,   927,   889,   991,   962,   958,
   -1391, -1391, -1391,   236,   846,   998,   796, 12412,   951,  7480,
     977, 12412, 12412, -1391,   964,   915,  4202, -1391,   917,   899,
     609, -1391,   916,   919,   281, -1391,   200,   231, -1391, -1391,
     990, -1391,    11, 12412,    44, 12412,  1004,   235, -1391,  4202,
   -1391,   243, -1391,  9556,  1008,  1060,  9556,   991,  1011,    77,
   12412,  7480,    -6,   335,   921, -1391,   922,   923,   924,    38,
   -1391,   455,   928, -1391,   244,   252,   960, -1391,   931,  4202,
    4202,   355, -1391,   266,   301,   258,  7480,    75, -1391, -1391,
    7480,  7480,  7480, -1391,  7480, -1391,  7480, 12412,  1023, -1391,
      73,   363, -1391, -1391, -1391,   401, -1391,   187, -1391, -1391,
   -1391,   102,   113,  1020,   880,   896,    20, -1391,   980, -1391,
   -1391,   929,   310,  3606,   417,  8970,   830, -1391,   137,   686,
    1084,  1084, -1391, -1391,   119, -1391, -1391,   121, -1391,    35,
   -1391, -1391, -1391, -1391, -1391, -1391, -1391, 12412,   953,  7480,
    1006, -1391, -1391, -1391,   904, -1391, -1391, -1391, -1391, -1391,
    7778, -1391, -1391, -1391,    90, -1391,   377,   377,   483,   531,
     531,   531,   531,   457,   457, -1391, -1391, 11842, 11842, 12412,
   12412, -1391,   459, -1391, -1391,   251, -1391, -1391, -1391,   316,
   -1391, -1391, -1391,   339,   428, -1391, -1391,   261,   473,   599,
   -1391,   507, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391,
   -1391, -1391,   889, -1391,   994, 12127,   985,  7480, -1391, -1391,
   -1391,  1035,   991,   991,   889, -1391,   792,   991,   615, 12412,
     586,   607,  1099, -1391, -1391,   848,    66, -1391, -1391, -1391,
   -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391,   236,    98,
     920,   572,  7480, -1391, 12412,  1036,   834,   991, -1391, -1391,
   -1391, -1391,   981, 12412, -1391, 12412, -1391,  1013,  1014, 11842,
    1017,  7480,    19,   993,    33,   502,   885, -1391, -1391,   695,
      44,  1035, 11842,  1024,  1049,   965,   947,  1016,   991,   992,
    1018,  1055,   991,  7480,   -36, -1391, -1391, -1391,  1000, -1391,
   -1391, -1391, -1391,  1038,  7480,  7480,  1007, -1391,  1057,  1061,
    4202, -1391,   976,   986,  1009, 12412, -1391, 12412, -1391,  7480,
    1022,   987,  7480,   356,   385,   391,  1130, -1391,   196, -1391,
     497, -1391, -1391,  1142, -1391,   701,  7480,  7480,  7480,   706,
    7480,  7480,  7480,  7480,  7480,  7480,  1058,  7480,  7480, -1391,
    5692,  1025,  1027,  1028,  1026,   804,   732,   936, -1391,   249,
   -1391,   133,   164,    35,  5394,  5394,  5394,  1094, -1391,  7480,
     720,  1071, -1391, 12412,  1078, -1391, -1391,  7480,    90,   569,
     523, -1391,   932,   375,   935,   937, -1391, -1391,   780, -1391,
     925,   486,  1030,  1031, 12127,  1032, -1391,   534, -1391, -1391,
   -1391, -1391, -1391, -1391, -1391, -1391, -1391,  1045, -1391, -1391,
   -1391,  7480, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391,
   -1391,   656, -1391,  1165,   748, -1391, -1391, -1391, -1391, -1391,
   -1391, -1391, -1391, -1391,   938, -1391, -1391,  1166, -1391, -1391,
   -1391, -1391, -1391,   543,  1169, -1391,   611, -1391, -1391, -1391,
     892,   438,   900,   605,   901,   905,   825, -1391,   534,  8076,
     933,   939, -1391,  1035,    98,   973,  1010,  4202,  1019,  1021,
    1059,  1037,  1040, 12412,   464, -1391, 12412, -1391,  7480,  1063,
    7480,  1075,  7480,    36,  1064,  7480,  1066, -1391,  1086,  1087,
    7480, 12412,   815,  1137, -1391, -1391, -1391, -1391, -1391, -1391,
   11842, -1391,  4202,   991,  1100, -1391, -1391, -1391,   991,  1100,
   -1391,  7480,  1073,  4202, 12412, -1391, -1391,  7480,  7480,   729,
   -1391,    32,   731, -1391, 10987,   739, -1391,   741, -1391,  1041,
   -1391, -1391,  4202,  1043,  1046, -1391,  7480, -1391, -1391,  1039,
    1057,  1122, -1391,  1102, -1391,   500, -1391, -1391,  1225, -1391,
   -1391,  4202, 12412, -1391,   663, -1391, -1391, -1391,  1048,  1003,
    1029, -1391, -1391, -1391,  1044,  1047, -1391, -1391, -1391, -1391,
   -1391,  1005, 12412,  1056, -1391, -1391,  7480,  7480,  7480,  3904,
    5692,  8970,   936, -1391,  8970, -1391,  1084,   387, -1391, -1391,
   -1391,  1071, -1391,   991, -1391,   812, -1391,   234,  1139, -1391,
    7480,   571,  1006,   499,  1062, -1391,    90,   997, -1391, -1391,
     284, -1391,   520,   -18,   999,    90,   520,  7778, -1391,   279,
   -1391, -1391, -1391, -1391, -1391, -1391,    90,  1096,   969,   846,
     -18, -1391, -1391,   966,  1174, -1391, -1391, -1391, 10132,  1067,
    1068,  1070, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391,
   -1391, -1391, -1391, -1391,  1224,   359,  1229,   359,   995,  1155,
   -1391,  1093, 12412,  1050, -1391, -1391,  8076, -1391,  1080, -1391,
   -1391, -1391, -1391, -1391, -1391,  7480,  1119, -1391, -1391,  7480,
   -1391,   514, -1391,  7480,  1123,  7480, -1391,  7480, 12412, 12412,
   -1391,   116, -1391,  7480, -1391,  1143,  1145,  1176,   991,  1100,
   -1391,  7480,  1089, -1391, -1391, -1391,  1088, -1391,    76,  7480,
    4202,  1091,   127, -1391, 12412,  1095, 11272,    49, -1391, 11557,
    1098, -1391, -1391,  1101, -1391, -1391, -1391,  7480,   749,  1130,
   12412,   677, -1391,  1103,  1130, 12412, -1391, -1391,  7480,  7480,
    7480,  7480,  7480, -1391,  7480,   404,   422,   427,   257, -1391,
   -1391, -1391, -1391, -1391,  1139, -1391, -1391, -1391,   991,  7480,
   -1391,  1138, -1391, -1391, -1391, -1391,  1104,  7778, -1391, -1391,
   -1391, -1391, -1391,   556,  7778,  7778,   101, -1391,   935, -1391,
     170, -1391,   937,    90,  1129, -1391, -1391,  1012, -1391, -1391,
   -1391, -1391,  1192,  1106, -1391,   444, -1391, -1391, -1391, -1391,
     462,   462, -1391,   359, -1391, -1391,   446, -1391,  1265,   -18,
    1199,  1109,  8076,   -47,  1051,  1127, -1391, -1391,  7480, -1391,
    7480,  1151, -1391,  7480, -1391, -1391, -1391,  1247, -1391, -1391,
    5692,  7480,   991, -1391, -1391, -1391,  7480,  7480, -1391, -1391,
   -1391,  5692,  5692,  1207,  4202, 12412,  1116, 12412,  7480, 12412,
    1117,  5692, -1391,   225,    42,  1130, 12412, -1391,  1108,  1130,
   -1391, -1391, -1391, -1391, -1391, -1391,  1111,  1057,  1061,  7480,
   -1391, -1391, -1391,  1203,  7480, -1391,   531,  7778,  7778,   483,
     606, -1391, -1391, -1391, -1391, -1391, -1391,  7480, -1391, 11842,
   -1391, 11842,  1211, -1391, -1391, -1391,  1281, -1391, -1391, -1391,
    1053,  1204, -1391, -1391,  1205, -1391,   622, 12412,  1195,  1090,
   12412,  8076, -1391, -1391,  7480, -1391,  1197, -1391, -1391,  1100,
   -1391, -1391, 11842, -1391, -1391,  1222,  7480,  1132, -1391,  1226,
    5692, -1391, 12412,   392,   687, -1391,  1125,  1130, -1391,  1126,
    5692,   764,   505, -1391,  1203,   483,   483,  7778,   508, -1391,
   -1391, 11842, -1391, -1391,  1199,  8076, -1391,  1139,  1054, 12412,
    1201,  1105,  1205, -1391, 12412,  1140, 11842,  4202, 11842,  1141,
   -1391, -1391,  1230,   646, -1391, -1391, -1391, -1391,  1147,   753,
   -1391, -1391, -1391,  1128, -1391,  1210, -1391, -1391,   483, -1391,
   -1391, -1391, -1391, -1391,  7480,  1069, 12412,  1213, -1391,  4202,
    1146, -1391, -1391,  1149,  7480, -1391, -1391, -1391, -1391, -1391,
   -1391, -1391, 12412, -1391,  1082,  1077, 12412, -1391, -1391,  7480,
    5692,  1150,  1072,  7480,  1074,  5692,  8076, -1391,  8076, -1391,
    1144,  1076, 12412,  1114,  1221, 12412,  1079,  8076, -1391
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       159,   444,   445,   446,   162,   162,   162,   766,   965,   116,
     118,   594,   858,   867,   807,   771,   769,   751,   859,   862,
     814,   775,   752,   753,   806,   868,   755,   865,   836,   816,
     791,   811,   812,   863,   860,   810,   757,   866,   758,   759,
     907,   919,   906,   808,   827,   821,   760,   809,   762,   761,
     908,   845,   846,   813,   788,   929,   930,   931,   932,   933,
     934,   935,   936,   937,   938,   939,   953,   960,   835,   831,
     822,   802,   750,     0,   830,   838,   847,   954,   826,   466,
     803,   804,   861,   955,   961,   823,   840,     0,   472,   433,
     468,   833,   768,   824,   825,   854,   828,   844,   853,   959,
     962,   774,   815,   856,   467,   843,   849,   754,     0,     0,
       0,   381,   841,   852,   857,   855,   834,   820,   909,   818,
     819,   956,     0,   380,     0,   957,   963,   850,   805,   829,
     958,   411,     0,   443,   851,   832,   839,   848,   842,   910,
     796,   801,   800,   799,   798,   797,   763,   817,     0,   767,
     864,   789,   898,   897,   899,   773,   772,   792,   904,   756,
     896,   901,   902,   893,   795,   837,   895,   905,   903,   894,
     793,   900,   914,   915,   912,   913,   911,   764,   916,   917,
     918,   884,   883,   870,   787,   780,   877,   873,   790,   786,
     885,   886,   776,   777,   770,   779,   882,   881,   878,   874,
     891,   892,   890,   880,   876,   869,   778,   889,   888,   782,
     784,   783,   875,   879,   871,   785,   872,   781,   887,   940,
     941,   942,   943,   944,   945,   921,   922,   920,   926,   927,
     928,   923,   924,   925,   794,   946,   947,   948,   949,   950,
     951,   952,   159,     0,     2,   159,     5,     7,    19,     0,
      24,    27,    32,    33,    34,    35,    36,    37,    38,    28,
      54,    55,    29,    30,     0,    72,    75,    76,    31,    77,
      78,     0,   114,    79,    80,    81,    82,    14,   156,   157,
     158,   165,   167,   463,   168,     0,   169,   170,   171,   172,
     173,   174,   175,   178,   163,   204,   211,   206,   233,   239,
       0,   231,   232,   213,   207,   177,   208,   176,   209,   212,
     334,   336,   338,   348,   350,   354,   356,   359,   364,   367,
     370,   372,   374,   376,     0,   378,   384,   386,     0,   402,
     385,   407,   410,   412,   415,   417,     0,   422,   419,     0,
     430,   440,   442,   416,   447,   454,   464,   455,   456,   457,
     460,   461,   458,   459,   479,   481,   482,   483,   480,   528,
     529,   530,   531,   532,   533,   439,   568,   560,   567,   566,
     565,   562,   564,   561,   563,   465,   462,   595,   596,    39,
     214,   215,   217,   216,   218,   210,     0,   441,   749,   765,
     858,   867,   865,   767,     0,   160,   161,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,   124,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   258,   259,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   435,
     438,   425,     0,     0,   746,   751,   775,   753,   806,   868,
     755,   816,   757,   827,   760,   762,   761,   845,   953,   960,
     750,   954,   804,   955,   961,   828,   959,   962,   909,   956,
     957,   963,   958,   910,   904,   896,   902,   893,   793,   914,
     915,   912,   764,   916,   431,   441,   749,   423,     0,   185,
     424,   427,   751,   752,   753,   757,   758,   759,   760,   750,
     756,   469,     0,   429,   428,   180,     0,     0,   755,   762,
     761,     0,   162,   470,   916,     0,   211,     0,   495,     0,
     434,   747,     0,   748,   405,   406,     0,   437,   436,   426,
     409,     0,     0,   524,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     1,     6,     8,     0,     0,     0,     0,     0,   159,
     159,   159,   159,     0,   115,   166,   164,     0,   183,     0,
     192,     0,     0,     0,     0,     0,     0,     0,     0,   197,
     219,   238,   234,   240,   235,   237,   236,     0,     0,     0,
     395,     0,     0,   393,     0,   343,     0,   394,   387,   392,
     391,   390,   389,   388,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   383,   382,   379,     0,   403,   408,     0,
       0,     0,   418,   451,   421,   420,   432,     0,   448,     0,
       0,     0,   535,   537,   541,   594,     0,   120,     0,    43,
      40,    41,    44,    45,     0,     0,     0,     0,    46,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     605,   606,   607,     0,    99,   138,     0,     0,   108,     0,
       0,     0,     0,   123,     0,     0,     0,   574,     0,     0,
       0,   570,     0,     0,     0,   584,     0,     0,   221,   222,
     241,   242,     0,     0,     0,     0,   130,     0,   134,   162,
     598,     0,    56,     0,    65,     0,     0,     0,    57,     0,
       0,     0,     0,     0,   746,   575,     0,     0,     0,     0,
     307,     0,     0,   573,     0,     0,     0,   592,     0,     0,
       0,     0,   578,     0,     0,   187,     0,     0,   181,   179,
       0,     0,     0,   469,     0,   471,     0,   496,   495,   492,
       0,     0,   526,   525,   404,     0,   523,     0,   618,   619,
     569,     0,     0,     0,     0,     0,     0,   624,     0,   195,
     196,     0,     0,     0,     0,     0,   200,   201,    20,     0,
      21,     0,     4,    25,     0,    11,    26,     0,    15,   858,
      73,    12,    74,    16,   186,   184,   205,     0,     0,     0,
       0,   198,   220,   276,   335,   337,   341,   347,   346,   345,
       0,   342,   339,   340,     0,   351,   358,   357,   355,   361,
     362,   363,   360,   365,   366,   369,   368,     0,     0,     0,
       0,   400,     0,   413,   414,     0,   452,   449,   477,     0,
     964,   597,   475,     0,     0,   117,   119,     0,     0,     0,
      98,     0,    88,    90,    91,    92,    93,    95,    96,    97,
      89,    94,    84,    85,     0,     0,   104,     0,   100,   102,
     103,   110,     0,     0,    83,    42,     0,     0,     0,     0,
       0,     0,     0,   696,   701,     0,     0,   697,   731,   684,
     686,   687,   688,   690,   692,   691,   689,   693,     0,     0,
       0,     0,     0,   107,     0,   140,     0,     0,   540,   534,
     571,   572,     0,     0,   588,     0,   585,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   223,   224,     0,
     229,   136,     0,     0,   131,     0,     0,     0,     0,     0,
       0,    58,     0,     0,     0,   257,   263,   260,     0,   577,
     576,   583,   591,     0,     0,     0,     0,   539,     0,     0,
       0,   396,     0,     0,     0,     0,   581,     0,   579,     0,
     188,     0,     0,     0,     0,     0,   495,   493,     0,   484,
       0,   473,   474,     0,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   193,
       0,   755,   762,   761,   916,     0,     0,     0,   632,     0,
     202,     0,     0,     0,   159,   159,   159,     0,   230,     0,
     291,   287,   289,     0,   277,   278,   344,     0,     0,     0,
       0,   662,   352,   635,   639,   641,   643,   645,   648,   655,
     656,   664,   868,   754,     0,   763,   371,   546,   552,   553,
     555,   599,   600,   556,   559,   373,   375,   543,   377,   401,
     453,     0,   450,   476,   121,    52,    53,    50,    51,   127,
     126,     0,    86,     0,     0,   105,   106,   111,    70,    71,
      48,    49,    69,   702,     0,   705,   732,     0,   695,   694,
     699,   698,   730,     0,     0,   707,     0,   703,   706,   685,
       0,     0,     0,     0,     0,     0,     0,   139,   142,     0,
       0,     0,   109,   112,     0,     0,     0,   162,     0,     0,
     592,     0,     0,     0,     0,   545,     0,   244,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   225,     0,     0,
       0,     0,   270,     0,   267,   272,   228,   137,   132,   135,
       0,   182,     0,     0,    67,    61,    64,    63,     0,    59,
     261,     0,     0,   162,     0,   305,   309,     0,     0,     0,
     312,     0,     0,   318,     0,     0,   325,     0,   329,     0,
     398,   397,   162,     0,     0,   189,     0,   191,   306,     0,
       0,     0,   496,     0,   485,     0,   519,   516,     0,   520,
     521,     0,     0,   515,     0,   490,   518,   517,     0,     0,
       0,   611,   612,   608,     0,     0,   616,   617,   613,   622,
     620,     0,     0,     0,   626,   194,     0,     0,     0,     0,
       0,     0,   627,   628,     0,   203,    22,     0,    13,    17,
      18,   288,   300,     0,   301,     0,   292,   293,   294,   295,
       0,   280,     0,     0,     0,   646,   659,     0,   349,   353,
       0,   678,     0,     0,     0,     0,     0,     0,   634,   636,
     637,   673,   674,   675,   677,   676,     0,     0,   650,   649,
       0,   653,   657,   671,   669,   668,   661,   665,     0,     0,
       0,     0,   549,   551,   550,   547,   544,   478,   129,   128,
      87,   101,   719,   700,     0,   724,     0,   724,   713,   708,
     143,     0,     0,     0,   113,   141,     0,    23,     0,   589,
     590,   593,   586,   587,   243,     0,     0,   256,   248,     0,
     252,     0,   246,     0,     0,     0,   265,     0,     0,     0,
     227,   268,   271,     0,   133,     0,     0,    66,     0,    60,
     262,     0,     0,   308,   310,   315,     0,   313,     0,     0,
       0,     0,     0,   319,     0,     0,     0,     0,   326,     0,
       0,   330,   399,     0,   582,   580,   190,     0,     0,   495,
       0,     0,   527,     0,   495,     0,   491,    10,     0,     0,
       0,     0,     0,   625,     0,     0,     0,     0,     0,   629,
     633,   304,   302,   303,   296,   297,   298,   290,     0,     0,
     285,     0,   279,   663,   654,   660,     0,     0,   733,   734,
     744,   743,   742,     0,     0,     0,     0,   735,   640,   741,
       0,   638,   642,     0,     0,   647,   651,     0,   672,   667,
     670,   666,     0,     0,   557,     0,   554,   604,   548,   720,
       0,     0,   718,   725,   726,   722,     0,   717,     0,   715,
       0,     0,     0,     0,     0,     0,   536,   245,     0,   254,
       0,     0,   250,     0,   253,   266,   274,   275,   269,   226,
       0,     0,     0,    62,   264,   542,     0,     0,   316,   320,
     314,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   538,     0,     0,   495,     0,   522,     0,   495,
     609,   610,   614,   615,   621,   623,     0,     0,     0,     0,
     630,   299,   286,   281,     0,   658,   745,     0,     0,   737,
       0,   683,   682,   681,   680,   679,   644,     0,   736,     0,
     601,     0,     0,   729,   728,   727,     0,   721,   714,   712,
       0,   709,   710,   704,   144,   146,   148,     0,     0,     0,
       0,     0,   249,   247,     0,   255,     0,   199,   333,    68,
     311,   317,     0,   331,   327,     0,     0,     0,   321,     0,
       0,   323,     0,   505,   499,   494,     0,   495,   486,     0,
       0,     0,     0,   284,   282,   739,   738,     0,     0,   602,
     558,     0,   723,   716,     0,     0,   150,   149,     0,     0,
       0,     0,   145,   251,     0,     0,     0,     0,     0,     0,
     513,   507,     0,   506,   508,   514,   511,   501,     0,   500,
     502,   512,   488,     0,   487,     0,   631,   283,   740,   652,
     603,   711,   147,   151,     0,     0,     0,     0,   273,     0,
       0,   324,   322,     0,     0,   498,   509,   510,   497,   503,
     504,   489,     0,   152,     0,     0,     0,   332,   328,     0,
       0,     0,     0,     0,     0,     0,     0,   154,     0,   153,
       0,     0,     0,     0,     0,     0,     0,     0,   155
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1391, -1391,  -210,  1083, -1391,  1107,  1110, -1391,  1092,  -506,
   -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391,
    -937, -1391, -1391, -1391, -1391,  -195,  -555, -1391,   655,   -39,
   -1391, -1391, -1391, -1391, -1391,   239,   448, -1391, -1391,   -11,
    -171,   945, -1391,   940, -1391, -1391,  -592, -1391,   383, -1391,
     203, -1391,  -243,  -286, -1391,  -524, -1391,    28,    25,    16,
    -232,  -176, -1391,  -815, -1391, -1391,   151, -1391, -1391, -1391,
   -1391, -1391, -1391, -1391, -1391, -1391, -1391,   544,   -90,   810,
       0, -1391, -1391, -1391, -1391,   393, -1391, -1391,  -289, -1391,
       8, -1391, -1391,   204,  -686,  -678, -1391, -1391,   614, -1391,
   -1391,    -8,   195, -1391, -1391, -1391,   100, -1390, -1391,   334,
      92, -1391, -1391,   108, -1218, -1391,   864,   193, -1391, -1391,
     190,  -973, -1391, -1391,   189, -1391, -1391, -1204, -1177, -1391,
     185, -1391, -1391,   786,   787, -1391,  -486,   769, -1391, -1391,
    -627,   323,  -591,   259,   307, -1391, -1391, -1391, -1391, -1391,
    1081, -1391, -1391, -1391, -1391,  -826,  -321, -1089, -1391,  -108,
   -1391, -1391, -1391, -1391, -1391, -1391, -1391,   -24,  -782, -1391,
   -1391,   564,   246, -1391,  -390, -1391, -1391, -1391, -1391, -1391,
   -1391, -1391,   733, -1391,  -964, -1391,   172, -1391,   623,  -762,
   -1391, -1391, -1391, -1391, -1391,  -259,  -251, -1117,  -863, -1391,
   -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391,   546,
    -714,  -813,   265,  -810, -1391,    94,  -764, -1391, -1391, -1391,
   -1391, -1391, -1391, -1391,   988,  1001,  -590,   465,   306, -1391,
   -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391,
   -1391, -1391, -1391,   152, -1391, -1391,   149, -1391,   153,  -986,
   -1391, -1391, -1391,   117,   107,   -46,   360, -1391, -1391, -1391,
   -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391, -1391,
     123, -1391, -1391, -1391,   -42,   352,   495, -1391, -1391, -1391,
   -1391, -1391,   299, -1391, -1391, -1369, -1391, -1391, -1391,  -525,
   -1391,    93, -1391,   -57, -1391, -1391, -1391, -1391, -1207, -1391,
     131, -1391,  -338,  -343,  1015,   -35, -1391
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   243,   811,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
    1184,   737,   261,   262,   263,   264,   265,   266,   892,   893,
     894,   267,   268,   269,   898,   899,   900,   270,   419,   271,
     272,   666,   273,   421,   422,   423,   436,   727,   728,   274,
    1137,   275,  1584,  1585,   276,   277,   278,   526,   279,   280,
     281,   282,   283,   730,   284,   285,   509,   286,   287,   288,
     289,   290,   291,   599,   292,   293,   806,   807,   294,   295,
     536,   297,   600,   434,   959,   960,   298,   601,   299,   603,
     537,   301,   720,   721,  1172,   443,   302,   444,   445,   724,
    1173,  1174,  1175,   604,   605,  1054,  1055,  1440,   606,  1051,
    1052,  1276,  1277,  1278,  1279,   303,   749,   750,   304,  1199,
    1200,  1388,   305,  1202,  1203,   306,   307,  1205,  1206,  1207,
    1208,   308,   309,   310,   311,   840,   312,   313,  1288,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   624,   625,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   652,   653,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   869,   353,   354,   355,  1234,   778,   779,   780,
    1615,  1658,  1659,  1652,  1653,  1660,  1654,  1235,  1236,   356,
     357,  1237,   358,   359,   360,   361,   362,   363,   364,  1086,
     954,  1076,  1325,  1077,  1475,  1078,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   756,  1149,   375,   376,
     377,   378,  1080,  1081,  1082,  1083,   379,   380,   381,   382,
     383,   384,   796,   797,   385,  1262,  1263,  1550,  1039,  1062,
    1298,  1299,  1063,  1064,  1065,  1066,  1067,  1308,  1465,  1466,
    1068,  1311,  1069,  1446,  1070,  1071,  1316,  1317,  1471,  1469,
    1300,  1301,  1302,  1303,  1564,   694,   919,   920,   921,   922,
     923,   924,  1127,  1491,  1581,  1128,  1489,  1579,   925,  1337,
    1486,  1482,  1483,  1484,   926,   927,  1304,  1312,  1456,  1305,
    1452,  1289,   386,   542,   387,   388,   389
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int xquery_parser::yytable_ninf_ = -747;
  const short int
  xquery_parser::yytable_[] =
  {
       296,   420,   569,   848,   296,   296,   296,   647,   300,   667,
     667,   602,   300,   300,   300,  1201,  1008,  1408,  1060,   535,
     396,   396,   396,  1038,   550,   974,   820,   822,  1398,   395,
     395,   395,   394,   397,   398,  1189,   952,   986,   506,   580,
     849,   850,   851,   852,   953,  1085,  1233,   948,   585,   504,
    1341,  1000,   506,   577,   582,   815,   818,   821,   823,  1435,
    1436,     9,    10,   669,  1100,     9,    10,     9,    10,  1161,
     689,  1587,  1284,   813,   816,   506,   401,   402,  1453,   403,
     404,   704,   405,   578,   879,  1104,   405,   506,   405,   506,
     578,   406,   578,  1079,  1079,   406,   407,   464,   578,   956,
     584,   734,   738,  1467,   746,   949,  1191,   950,   296,   408,
     552,   782,   441,   408,   409,   408,   300,  1416,   409,   665,
     578,  1582,   578,   836,   527,   837,   838,  1026,   839,   950,
     841,  1079,  1389,   395,   578,  1613,  1155,  1130,   842,   843,
     455,   587,  1131,   709,   464,   983,   410,   411,  1047,  1178,
     410,   411,   412,   700,     9,    10,   709,  1132,   951,  1133,
     710,   725,  1124,  1623,   585,  1138,  1158,  1527,  1134,  1168,
     574,   949,   589,   710,  1169,   461,  1389,  1588,   678,  1125,
    1162,   735,   983,  1363,   438,  1079,   575,  1107,   591,   424,
     586,   874,   592,   874,   439,  1135,  1015,   593,  1079,   413,
      79,   401,   402,  1009,   403,   404,   462,  1019,   561,   463,
     679,   399,   950,   562,    90,   594,  1551,   456,  1390,   973,
     440,   407,  1126,   648,   588,  1614,   984,  1389,   736,  1392,
     726,  1398,  1060,  1060,  1667,  1528,   442,  1454,  1455,   104,
     583,  1166,   296,  1057,  1223,   296,  1058,  1177,   602,   584,
     300,  1379,   775,   300,  1027,   820,   822,  1495,   414,  1589,
     957,  1233,  1517,  1002,  1320,  1671,   442,   124,  1163,  1010,
    1233,   875,   579,   876,  1159,   733,  1164,  1267,   783,   581,
     296,   808,  1580,   442,   457,   458,  1329,   810,   300,  1101,
     908,   442,   909,   553,  1416,   585,  1192,   958,   711,   415,
    1445,   506,   813,   816,   506,   442,   586,   943,   442,  1044,
    1079,  1046,   654,  1522,   595,   656,   870,   596,  1013,  1016,
    1017,   416,  1136,  1266,   413,   416,  1224,   701,   628,   417,
    1020,  1021,   597,   417,  1018,   702,   910,   418,   945,   714,
    1273,   418,   963,  1612,  1621,  1022,   629,   731,  1059,   905,
     589,   589,   949,  1148,  1056,  1151,   743,   598,   589,   589,
     684,  1275,   685,   754,   755,   831,   809,  1374,  1636,  1561,
     676,   506,   761,   995,   506,  1290,  1562,  1014,   506,   400,
    1138,   506,   506,   414,   814,   817,  1563,   944,   589,   506,
     967,  1395,  1225,   970,   686,   506,   296,  1650,   506,   971,
     999,  1226,  1259,  1586,   300,  1213,   506,  1214,   997,  1095,
    1549,  1528,   506,   506,   506,   506,  1079,   589,   946,  1673,
     506,   687,   964,  1091,   415,   296,  1096,   296,   506,  1344,
     966,   988,   684,   300,   685,   300,  1090,   586,  1561,   989,
    1079,   706,   589,   706,  1398,  1562,  1091,  1233,  1291,   781,
     705,   296,   708,   996,  1061,  1563,   296,   665,  1264,   300,
    1060,   785,   589,   589,   300,   942,  1264,   706,  1356,  1060,
     589,  1290,   706,   506,   585,  -746,   752,   802,   804,  1038,
    1060,   758,  1430,   688,  1094,  1364,   911,   506,   998,   820,
     822,   820,   589,   687,   631,  1480,   506,  1030,   589,   912,
    1448,   913,  1586,  1092,   427,  1474,  1226,  1227,   589,  1226,
    1227,   589,   914,   915,   916,  1229,   917,  1230,   918,   978,
    1268,  1269,  1270,   632,   589,  1651,  1093,   296,   506,   589,
    1292,  1293,   296,  1294,   589,   300,   633,  1449,    79,   994,
     300,   863,   864,  1219,  1291,  1231,  1586,  1011,   396,   949,
    1296,  1571,    90,  1576,  1079,   688,   862,   395,  1334,  1481,
     950,   865,  1297,   420,  1108,  1109,   589,  1441,   296,  1112,
     634,   585,  1220,   459,  1392,  1599,   300,   104,  1221,   296,
     296,   296,   296,  1526,   803,  1012,  1530,   300,   300,   300,
     300,  1546,   425,   637,   428,   426,   949,   296,   665,  1146,
    1228,  1037,   985,  1228,  1045,   300,   589,   638,  1557,  1547,
     950,  1355,   589,  1041,  1548,   589,   586,  1709,  1336,  1710,
    1229,  1097,  1230,  1229,   506,  1230,  1292,  1293,  1718,  1294,
    1185,  1572,  1079,  1577,  1185,  1079,  1295,  1060,  1098,  1334,
     646,   628,   555,  1089,   556,   881,  1296,  1534,   506,  1165,
    1231,  1650,  1538,  1231,   110,  1226,  1335,   110,  1297,   629,
     895,  1500,   506,   435,   124,   949,   506,   506,  1061,  1061,
    1460,   122,  1226,  1227,   122,  1501,  1286,  1438,  1322,    79,
    1003,  1004,  1005,  1443,   804,  1558,  1226,  1227,   506,  1666,
     506,  1232,  1669,    90,  1410,   437,  1226,   431,   506,  1336,
     124,   506,   432,   896,   674,   506,   296,  1124,   897,   148,
    1323,   820,   148,  1439,   300,  1656,   949,   591,   104,  1042,
     675,   592,  1057,   628,  1125,  1058,   593,  1324,  1273,   296,
     670,   635,  1313,  1314,   824,   575,  1099,   300,   825,   647,
     636,   629,   506,   671,   594,   396,   124,   602,  1168,   433,
    1655,  1661,   729,  1169,   395,  1315,  1629,   965,  1630,   296,
     296,   448,  1226,   630,   628,   449,  1228,   300,   300,  1229,
     506,  1230,  1170,  1616,   591,   706,   706,  1619,   592,  1686,
    1228,  1656,   629,   593,   992,   993,  1229,  1450,  1230,  1645,
    1655,   950,   506,  1328,  1451,   651,  1661,   657,  1255,  1231,
    1229,   594,  1230,  1035,  1627,  1079,   672,  1079,   420,   729,
    1229,  1036,  1230,  1171,   429,  1272,  1231,   430,  1670,   673,
     110,  1657,   506,   506,   506,   506,  1273,  1559,  1560,  1198,
    1231,  1198,   450,  1680,   110,  1683,  1274,   122,  1079,  1396,
    1231,  1399,  1386,   595,  1391,  1377,   596,  1275,  1118,  1396,
    1185,   122,  1397,  1102,  1400,  1663,  1556,  1415,   569,  1119,
     506,   776,  1533,  1265,  1396,  1102,   453,  1079,  1168,  1120,
    1140,  1536,  1637,  1169,   506,   148,  1229,  1665,  1230,  1141,
    1121,   454,  1079,   698,  1079,   896,   598,  1689,   699,   148,
     897,  1113,  1114,  1115,   853,   854,  1061,  1116,   866,   506,
     595,   866,   655,   596,   866,  1061,  1231,   658,   506,   446,
     506,   460,   447,   558,   506,   559,  1061,   507,  1260,   451,
    1110,  1111,   452,   690,   691,   692,   508,   506,   649,   650,
    1625,  1626,  1239,   510,  1240,  1431,   511,  1244,   609,  1245,
    1432,  1433,   522,   598,   855,   856,   610,   611,   523,   612,
    1375,   846,   847,  1087,  1087,  1573,  1574,   613,   524,   540,
     506,   614,   506,   615,   547,   548,   539,  1283,   616,   882,
     883,   884,   885,   886,   887,   888,   889,   890,   891,   549,
     551,   557,   554,   560,   563,   617,   566,   564,   567,   571,
     296,   565,   568,   589,   590,   607,   608,   627,   300,   639,
    1668,   640,   626,   641,   651,   642,   706,   660,   618,   619,
     620,   621,   622,   623,   659,  1209,   661,   662,   506,   663,
     464,   680,   664,   682,   683,   693,   697,   707,   831,   723,
    1035,   729,   420,   718,   732,   719,   740,   741,  1036,   506,
    1513,   742,   753,   759,   296,   296,   296,   760,   426,   766,
     774,   768,   300,   300,   300,   430,   447,   452,   777,   784,
     786,   463,   790,   787,   770,   771,   772,   799,   812,   800,
     827,   795,   844,  1061,   805,   857,   858,   859,   860,   871,
     828,   880,   877,   829,   830,   878,   902,   903,   505,   906,
     907,   928,   929,   932,   930,   934,   937,   947,   962,   938,
    1552,   939,   521,   940,   968,   969,   941,   972,   979,   980,
     981,   982,   987,   990,  1023,   991,  1024,  1043,   506,  1029,
    1025,   506,  1028,  1049,  1053,   538,  1103,   897,  1122,   949,
    1144,  1153,  1145,  1123,  1147,  1156,   506,   543,  1167,   546,
    1160,  1154,   725,  1180,  1182,   506,  1139,   296,  1183,  1181,
    1187,  1188,  1186,  1193,  1197,   300,  1194,  1198,  1519,   506,
    1210,  1204,  1212,   396,  1216,  1222,  1425,  1426,  1427,   506,
    1211,  1238,   395,   686,  1185,  1348,  1252,  1217,  1280,  1259,
    1261,  1256,   296,  1257,  1258,  1282,  1318,  1319,  1321,  1326,
     300,  1310,  1306,   296,   665,  1333,  1307,   506,  1338,  1346,
    1347,   300,  1361,  1351,  1368,  1369,  1349,  1378,  1350,   396,
    1359,  1365,   296,  1367,  1373,  1381,  1287,   506,   395,  1342,
     300,  1382,  1396,  1332,  1352,  1402,   506,  1353,   396,   506,
    1404,   296,  1412,  1405,  1409,  1418,  1407,   395,  1417,   300,
    1403,  1422,  1424,  1463,  1343,  1273,  1447,   706,  1457,  1444,
    1464,  1468,  1470,  1479,  1476,  1477,  1413,  1478,  1485,  1035,
    1035,  1419,  1490,  1492,  1496,  1488,  1498,  1036,  1036,  1510,
    1503,  1511,  1512,  1515,  1516,   803,  1420,  1521,  1597,  1421,
    1554,  1524,  1567,   506,  1531,  1532,  1569,  1537,  1555,  1601,
    1519,  1568,  1603,  1570,  1578,  1124,  1583,  1591,  1594,  1611,
    1596,  1602,  1606,  1610,  1618,  1631,  1494,   506,  1620,  1438,
    1632,  1634,  1635,  1639,  1640,  1644,  1646,  1633,  1647,  1676,
    1648,  1662,  1664,  1685,  1691,   570,  1679,  1684,  1692,  1677,
    1688,  1696,  1699,   506,   506,  1700,  1705,  1590,  1714,  1715,
     576,   904,  1711,  1331,  1105,   668,  1179,  1345,  1642,  1672,
    1040,   505,   572,  1176,   505,   573,   977,  1354,  1674,   506,
     703,   506,  1712,  1508,   506,   788,   789,  1372,   791,   792,
     793,   794,  1437,  1694,  1702,   506,   801,  1706,  1603,  1708,
     506,  1703,  1442,  1271,  1717,  1434,   767,  1383,  1375,  1387,
     296,  1393,  1401,   834,   873,   835,   845,  1411,   300,   826,
    1690,  1007,  1687,  1340,  1423,   645,  1088,   832,   833,  1330,
    1152,  1429,  1458,  1462,  1428,  1681,   712,  1566,  1565,  1285,
    1309,   677,  1461,  1129,   681,  1339,  1575,  1459,   543,   713,
    1487,   695,   696,     0,     0,     0,     0,     0,     0,   543,
       0,     0,     0,     0,     0,   717,     0,  1697,   722,     0,
       0,     0,     0,     0,     0,     0,   739,     0,     0,  1622,
       0,     0,   543,   747,   748,   751,     0,   868,  1697,     0,
     757,   868,     0,  1681,     0,     0,     0,  1628,   764,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     506,     0,   506,     0,   506,     0,     0,     0,     0,     0,
       0,   506,     0,     0,     0,     0,     0,     0,     0,   933,
    1035,     0,     0,     0,     0,     0,     0,     0,  1036,     0,
       0,  1035,  1035,   765,   296,     0,     0,     0,     0,  1036,
    1036,  1035,   300,     0,   506,     0,   506,   751,     0,  1036,
       0,     0,     0,     0,     0,     0,   773,     0,     0,     0,
       0,   976,   506,     0,     0,   506,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   506,     0,     0,
       0,     0,     0,     0,     0,     0,  1001,   506,   798,     0,
       0,     0,     0,     0,     0,     0,   832,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   506,     0,     0,     0,
       0,     0,     0,     0,   506,     0,     0,     0,     0,   506,
    1035,   506,     0,   506,     0,     0,     0,     0,  1036,     0,
    1035,     0,     0,     0,     0,     0,     0,     0,  1036,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1050,
       0,   506,     0,     0,     0,     0,     0,   296,     0,     0,
       0,     0,     0,     0,     0,   300,     0,   506,     0,     0,
       0,   506,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   543,     0,     0,   506,     0,   296,
     506,     0,     0,     0,     0,     0,     0,   300,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   901,     0,
    1035,     0,     0,     0,     0,  1035,     0,  1106,  1036,     0,
       0,     0,   931,  1036,     0,     0,   935,   936,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   955,     0,
     961,     0,  1142,     0,     0,     0,     0,     0,   543,     0,
       0,   543,     0,     0,     0,   975,     0,     0,     0,     0,
       0,  1157,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1190,     0,     0,     0,     0,     0,     0,
       0,     0,  1006,     0,  1195,  1196,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1215,
       0,     0,  1218,     0,     0,     0,     0,     0,     0,     0,
     505,     0,     0,     0,     0,     0,  1241,  1242,  1243,     0,
    1246,  1247,  1248,  1249,  1250,  1251,     0,  1253,  1254,     0,
       0,     0,  1048,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1050,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1084,  1084,  1084,  1084,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1327,     0,     0,     0,     0,     0,     0,     0,     0,
    1084,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1143,
       0,     0,     0,     0,     0,     0,     0,     0,  1150,     0,
    1150,     0,     0,     0,  1084,     0,     0,     0,  1358,     0,
    1360,     0,  1362,     0,     0,  1366,     0,  1084,     0,     0,
    1370,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1376,     0,     0,     0,     0,     0,     0,     0,
       0,  1380,     0,     0,     0,     0,     0,  1384,  1385,     0,
     757,     0,   757,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1406,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1281,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1084,
    1050,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1497,     0,     0,   722,  1499,
       0,  1357,     0,  1502,     0,  1504,     0,  1505,     0,     0,
       0,     0,     0,  1509,     0,     0,  1371,     0,     0,     0,
       0,  1514,     0,     0,     0,  1084,     0,     0,     0,  1518,
    1520,     0,     0,     0,     0,     0,     0,     0,     0,   751,
       0,     0,     0,     0,     0,     0,     0,  1376,     0,  1084,
       0,     0,     0,     0,     0,     0,     0,     0,  1540,  1541,
    1542,  1543,  1544,     0,  1545,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1414,     0,  1553,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   798,     0,     0,
       0,     0,     0,     0,     0,     0,   505,     0,     0,   505,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1592,     0,
    1593,     0,     0,  1595,     0,     0,     0,     0,     0,     0,
       0,  1598,     0,     0,     0,     0,  1600,  1520,     0,     0,
       0,     0,     0,  1084,  1604,     0,     0,     0,  1608,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1493,     0,     0,
       0,     0,     0,     0,  1624,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1506,  1507,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1643,     0,     0,     0,     0,  1523,
       0,  1084,     0,     0,  1084,     0,  1604,     0,     0,     0,
       0,     0,     0,     0,     0,  1535,     0,     0,     0,     0,
    1539,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1682,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1693,     0,     0,     0,     0,  1698,
       0,     0,     0,     0,  1682,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1698,
       0,     0,     0,  1707,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1605,     0,  1607,     0,  1609,     0,     0,     0,     0,     0,
       0,  1617,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1084,     0,  1084,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1638,     0,     0,  1641,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1084,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1649,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1084,     0,     0,     0,
       0,     0,     0,     0,  1675,     0,     0,     0,     0,  1678,
       0,  1084,     0,  1084,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1695,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1701,     0,     0,
       0,  1704,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     0,     0,     0,  1713,     0,     0,
    1716,     3,     4,     5,     6,     7,     8,     9,    10,     0,
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
     104,   105,   106,   107,   108,     0,     0,   109,   110,   111,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,     0,   122,     0,   123,   124,     0,
       0,   125,   126,   127,     0,     0,     0,   128,     0,   129,
     130,     0,   131,   132,   133,     0,   134,     0,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,     0,
       0,   146,   147,   148,     0,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
       0,     0,     0,   390,   391,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   392,
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
     105,   106,   107,   108,     0,     0,   109,   110,   111,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,     0,   122,     0,   123,   124,     0,     0,
     125,   126,   127,     0,   525,     0,   128,     0,   129,   130,
       0,   131,   132,   133,     0,   134,     0,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,     0,     0,
     146,   147,   148,     0,   393,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   390,   391,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   392,    28,    29,
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
     107,   108,     0,     0,   109,   110,   111,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,     0,   122,     0,   123,   124,     0,     0,   125,   126,
     127,     0,   769,     0,   128,     0,   129,   130,     0,   131,
     132,   133,     0,   134,     0,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,     0,     0,   146,   147,
     148,     0,   393,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,     0,     0,     0,   390,
     391,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,  1031,   392,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,  1032,  1033,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   108,
       0,     0,   109,   110,   111,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,     0,
     122,     0,   123,   124,     0,     0,   125,   126,   127,     0,
     769,     0,   128,     0,   129,   130,     0,   131,   132,   133,
       0,   134,     0,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,     0,   146,   147,   148,     0,
     393,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,  1034,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   390,   391,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,  1031,   392,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,  1032,  1033,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,     0,   122,     0,
     123,   124,     0,     0,   125,   126,   127,     0,   525,     0,
     128,     0,   129,   130,     0,   131,   132,   133,     0,   134,
       0,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,   146,   147,   148,     0,   393,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,  1034,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,   390,   391,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   392,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   108,     0,     0,   109,   110,
     111,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,     0,   122,     0,   123,   124,
       0,     0,   125,   126,   127,     0,     0,     0,   128,     0,
     129,   130,     0,   131,   132,   133,     0,   134,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
       0,     0,   146,   147,   148,     0,   393,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
       0,     0,     0,    12,    13,     0,    14,    15,    16,    17,
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
     105,   106,   107,   108,     0,     0,   109,   110,   111,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,     0,   122,     0,   123,   124,     0,     0,
     125,   126,   127,     0,     0,     0,   128,     0,   129,   130,
       0,   131,   132,   133,     0,   134,     0,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,     0,     0,
     146,   147,   148,     0,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     1,
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
     107,   108,     0,     0,   109,   110,   111,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,     0,   122,     0,   123,   124,     0,     0,   125,   126,
     127,     0,     0,     0,   128,     0,   129,   130,     0,   131,
     132,   133,     0,   134,     0,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,     0,     0,   146,   147,
     148,     0,   393,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,     0,     0,     0,    12,
     391,     0,    14,    15,    16,    17,    18,    19,    20,    21,
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
       0,     0,   109,   110,   111,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,     0,
     122,     0,   123,   124,     0,     0,   125,   126,   127,     0,
       0,     0,   128,     0,   129,   130,     0,   131,   132,   133,
       0,   134,     0,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,     0,   146,   147,   148,     0,
     393,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   819,   391,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   392,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,     0,   122,     0,
     123,   124,     0,     0,   125,   126,   127,     0,     0,     0,
     128,     0,   129,   130,     0,   131,   132,   133,     0,   134,
       0,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,   146,   147,   148,     0,   393,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,   390,   391,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    1031,   392,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,  1032,  1033,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   108,     0,     0,   109,   110,
     111,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,     0,   122,     0,   123,   124,
       0,     0,   125,   126,   127,     0,     0,     0,   128,     0,
     129,   130,     0,   131,   132,   133,     0,   134,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
       0,     0,   146,   147,   148,     0,   393,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,  1034,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     0,     0,     0,    11,
       0,     0,     0,   390,   391,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   528,   392,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,   529,   530,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,     0,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,   482,    82,    83,    84,    85,    86,   531,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   532,     0,     0,   109,   110,   111,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,     0,   122,     0,   123,   124,     0,     0,
     125,   126,   127,     0,     0,     0,   128,   533,   129,   130,
       0,   131,   132,   133,     0,   134,     0,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,     0,     0,
     146,   147,   148,     0,   393,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   499,   500,   501,
     175,   176,   502,   534,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   390,   391,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   528,   392,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     529,   530,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     482,    82,    83,    84,    85,    86,   531,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   532,     0,     0,   109,   110,   111,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,     0,   122,     0,   123,   124,     0,     0,   125,   126,
     127,     0,   861,     0,   128,     0,   129,   130,     0,   131,
     132,   133,     0,   134,     0,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,     0,     0,   146,   147,
     148,     0,   393,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   499,   500,   501,   175,   176,
     502,   534,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   390,
     391,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   528,   392,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,   529,   530,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,   482,    82,
      83,    84,    85,    86,   531,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   532,
       0,     0,   109,   110,   111,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,     0,
     122,     0,   123,   124,     0,     0,   125,   126,   127,     0,
       0,     0,   128,   867,   129,   130,     0,   131,   132,   133,
       0,   134,     0,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,     0,   146,   147,   148,     0,
     393,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   499,   500,   501,   175,   176,   502,   534,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   390,   391,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   528,   392,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   529,   530,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   482,    82,    83,    84,
      85,    86,   531,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   532,     0,     0,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,     0,   122,     0,
     123,   124,     0,     0,   125,   126,   127,     0,     0,     0,
     128,   872,   129,   130,     0,   131,   132,   133,     0,   134,
       0,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,   146,   147,   148,     0,   393,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   499,   500,   501,   175,   176,   502,   534,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   390,   391,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   468,    25,
     470,   392,    28,   471,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,   473,
       0,    45,    46,    47,   475,   476,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   482,    82,    83,    84,    85,    86,
     531,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   485,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   532,     0,     0,   109,   110,
     643,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,     0,   122,     0,   644,   124,
       0,     0,   125,   126,   127,     0,     0,     0,   128,     0,
     129,   130,     0,   131,   132,   133,     0,   134,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
       0,     0,   146,   147,   148,     0,   393,   150,   151,   152,
     153,   154,   155,   156,   157,   494,   159,   495,   161,   496,
     497,   164,   165,   166,   167,   168,   169,   498,   171,   499,
     500,   501,   175,   176,   502,   503,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     0,     0,     0,    11,
       0,     0,     0,   390,   391,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   528,   392,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,   529,   530,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,     0,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,   482,    82,    83,    84,    85,    86,   531,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   532,     0,     0,   109,   110,   111,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,     0,   122,     0,   123,   124,     0,     0,
     125,   126,   127,     0,     0,     0,   128,     0,   129,   130,
       0,   131,   132,   133,     0,   134,     0,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,     0,     0,
     146,   147,   148,     0,   393,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   499,   500,   501,
     175,   176,   502,   534,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   390,   391,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   468,    25,   470,   392,    28,   471,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   473,     0,    45,    46,    47,
     475,   476,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     482,    82,    83,    84,    85,    86,   531,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   485,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   532,     0,     0,   109,   110,   111,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,     0,   122,     0,   123,   124,     0,     0,   125,   126,
     127,     0,     0,     0,   128,     0,   129,   130,     0,   131,
     132,   133,     0,   134,     0,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,     0,     0,   146,   147,
     148,     0,   393,   150,   151,   152,   153,   154,   155,   156,
     157,   494,   159,   495,   161,   496,   497,   164,   165,   166,
     167,   168,   169,   498,   171,   499,   500,   501,   175,   176,
     502,   503,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   390,
     391,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   468,    25,   470,   392,    28,   471,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,   473,     0,    45,    46,    47,   475,   476,
      50,   477,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,   482,    82,
      83,    84,    85,    86,   531,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   485,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   532,
       0,     0,   109,   110,     0,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,     0,
     122,     0,     0,     0,     0,     0,   125,   126,   127,     0,
       0,     0,   128,     0,   129,   130,     0,   131,   132,   133,
       0,   134,     0,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,     0,   146,   147,   148,     0,
     393,   150,   151,   152,   153,   154,   155,   156,   157,   494,
     159,   495,   161,   496,   497,   164,   165,   166,   167,   168,
     169,   498,   171,   499,   500,   501,   175,   176,   502,   503,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   390,   391,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     468,    25,   470,   392,    28,   471,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,   473,     0,    45,    46,    47,   475,   476,    50,   477,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   482,    82,    83,    84,
      85,    86,   531,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   485,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   532,     0,     0,
     109,   110,     0,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,     0,   122,     0,
       0,     0,     0,     0,   125,   126,   127,     0,     0,     0,
     128,     0,   129,   130,     0,     0,     0,   133,     0,   134,
       0,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,   146,   147,   148,     0,   393,   150,
     151,   152,   153,   154,   155,   156,   157,   494,   159,   495,
     161,   496,   497,   164,   165,   166,   167,   168,   169,   498,
     171,   499,   500,   501,   175,   176,   502,   503,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     0,     0,     0,     7,     8,     0,     0,
       0,   464,     0,     0,     0,   390,   391,     0,    14,    15,
      16,   465,    18,    19,    20,   466,    22,   467,   468,   469,
     470,   392,    28,   471,    30,    31,     0,    32,    33,    34,
      35,   472,    37,    38,    39,    40,    41,    42,    43,   473,
       0,    45,   474,    47,   475,   476,    50,   477,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   478,   479,    68,     0,    69,    70,    71,   480,
       0,     0,    74,    75,    76,     0,     0,   481,    78,     0,
       0,     0,     0,    80,   482,    82,   483,   484,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   485,    97,    98,
     486,   487,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,   107,     0,     0,     0,     0,     0,
       0,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   488,   119,   120,   489,     0,     0,     0,     0,     0,
       0,     0,   490,   491,   127,     0,     0,     0,   128,     0,
     129,   492,     0,     0,     0,   133,     0,   134,     0,   135,
     136,   137,   138,   493,   140,   141,   142,   143,   144,   145,
       0,     0,   146,   147,     0,     0,   393,   150,   151,   152,
     153,   154,   155,   156,   157,   494,   159,   495,   161,   496,
     497,   164,   165,   166,   167,   168,   169,   498,   171,   499,
     500,   501,   175,   176,   502,   503,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     0,     0,     0,     7,     8,     0,     0,     0,   464,
       0,     0,     0,   390,   391,     0,    14,    15,    16,   512,
      18,    19,    20,   466,   513,   514,   468,   469,   470,   392,
      28,   471,    30,    31,     0,    32,    33,    34,    35,   515,
      37,   516,   517,    40,    41,    42,    43,   473,     0,    45,
     518,    47,   475,   476,    50,   477,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     478,   479,    68,     0,    69,    70,    71,   519,     0,     0,
      74,    75,    76,     0,     0,   481,    78,     0,     0,     0,
       0,    80,   482,    82,   483,   484,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   485,    97,    98,   486,   487,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,   107,     0,     0,     0,     0,     0,     0,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   488,
     119,   120,   489,     0,     0,     0,     0,     0,     0,     0,
     490,   491,   127,     0,     0,     0,   128,     0,   129,   492,
       0,     0,     0,   133,     0,   134,     0,   135,   136,   137,
     138,   493,   140,   141,   142,   143,   144,   145,     0,     0,
     146,   147,     0,     0,   393,   150,   151,   152,   153,   154,
     155,   156,   157,   494,   520,   495,   161,   496,   497,   164,
     165,   166,   167,   168,   169,   498,   171,   499,   500,   501,
     175,   176,   502,   503,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   541,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,   744,     0,     0,     0,   390,   391,     0,    14,
      15,    16,   512,    18,    19,    20,   466,   513,   514,   468,
     469,   470,   392,    28,   471,    30,    31,     0,    32,    33,
      34,    35,   515,    37,   516,   517,    40,    41,    42,    43,
     473,     0,    45,   518,    47,   475,   476,    50,   477,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   478,   479,    68,     0,    69,    70,    71,
     519,     0,     0,    74,    75,    76,     0,     0,   481,    78,
       0,     0,     0,     0,    80,   482,    82,   483,   484,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   485,    97,
      98,   486,   487,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,   107,     0,     0,     0,     0,
       0,     0,   112,   113,     0,     0,     0,     0,   114,   115,
     116,   117,   488,   119,   120,   489,     0,     0,     0,     0,
       0,     0,     0,   490,   491,   127,     0,     0,     0,   128,
     745,   129,   492,     0,     0,     0,     0,     0,   134,     0,
     135,   136,   137,   138,   493,   140,   141,   142,   143,   144,
     145,     0,     0,   146,   147,     0,     0,   393,   150,   151,
     152,   153,   154,   155,   156,   157,   494,   520,   495,   161,
     496,   497,   164,   165,   166,   167,   168,   169,   498,   171,
     499,   500,   501,   175,   176,   502,   503,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   541,     0,     0,     0,     0,     0,     0,     0,
       7,     8,     0,     0,     0,   464,     0,     0,     0,   390,
     391,     0,    14,    15,    16,   512,    18,    19,    20,   466,
     513,   514,   468,   469,   470,   392,    28,   471,    30,    31,
       0,    32,    33,    34,    35,   515,    37,   516,   517,    40,
      41,    42,    43,   473,     0,    45,   518,    47,   475,   476,
      50,   477,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   478,   479,    68,     0,
      69,    70,    71,   519,     0,     0,    74,    75,    76,     0,
       0,   481,    78,     0,     0,     0,     0,    80,   482,    82,
     483,   484,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   485,    97,    98,   486,   487,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   488,   119,   120,   489,     0,
       0,     0,     0,     0,     0,     0,   490,   491,   127,     0,
       0,     0,   128,     0,   129,   492,     0,     0,     0,     0,
       0,   134,     0,   135,   136,   137,   138,   493,   140,   141,
     142,   143,   144,   145,     0,     0,   146,   147,     0,     0,
     393,   150,   151,   152,   153,   154,   155,   156,   157,   494,
     520,   495,   161,   496,   497,   164,   165,   166,   167,   168,
     169,   498,   171,   499,   500,   501,   175,   176,   502,   503,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   544,   545,     0,     0,     0,
       0,     7,     8,     0,     0,     0,   464,     0,     0,     0,
     390,   391,     0,    14,    15,    16,   512,    18,    19,    20,
     466,   513,   514,   468,   469,   470,   392,    28,   471,    30,
      31,     0,    32,    33,    34,    35,   515,    37,   516,   517,
      40,    41,    42,    43,   473,     0,    45,   518,    47,   475,
     476,    50,   477,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   478,   479,    68,
       0,    69,    70,    71,   519,     0,     0,    74,    75,    76,
       0,     0,   481,    78,     0,     0,     0,     0,    80,   482,
      82,   483,   484,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   485,    97,    98,   486,   487,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   117,   488,   119,   120,   489,
       0,     0,     0,     0,     0,     0,     0,   490,   491,   127,
       0,     0,     0,   128,     0,   129,   492,     0,     0,     0,
       0,     0,   134,     0,   135,   136,   137,   138,   493,   140,
     141,   142,   143,   144,   145,     0,     0,   146,   147,     0,
       0,   393,   150,   151,   152,   153,   154,   155,   156,   157,
     494,   520,   495,   161,   496,   497,   164,   165,   166,   167,
     168,   169,   498,   171,   499,   500,   501,   175,   176,   502,
     503,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     7,     8,     0,     0,
       0,   464,     0,     0,     0,   390,   391,     0,    14,    15,
      16,   465,    18,    19,    20,   466,    22,   467,   468,  1072,
     470,   392,    28,   471,    30,    31,     0,    32,    33,    34,
      35,   472,    37,    38,    39,    40,    41,    42,    43,   473,
       0,    45,   474,    47,   475,   476,    50,   477,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   478,   479,    68,     0,    69,    70,    71,   480,
       0,     0,    74,    75,    76,     0,     0,   481,    78,     0,
       0,     0,     0,    80,   482,    82,   483,   484,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   485,    97,    98,
     486,   487,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,  1073,     0,     0,     0,  1074,     0,
       0,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   488,   119,   120,   489,     0,     0,     0,     0,     0,
       0,     0,   490,   491,   127,     0,     0,     0,   128,  1472,
     129,   492,     0,     0,     0,  1473,     0,   134,     0,   135,
     136,   137,   138,   493,   140,   141,   142,   143,   144,   145,
       0,     0,  1075,   147,     0,     0,   393,   150,   151,   152,
     153,   154,   155,   156,   157,   494,   159,   495,   161,   496,
     497,   164,   165,   166,   167,   168,   169,   498,   171,   499,
     500,   501,   175,   176,   502,   503,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     7,     8,     0,     0,     0,   464,     0,     0,     0,
     390,   391,     0,    14,    15,    16,   512,    18,    19,    20,
     466,   513,   514,   468,   469,   470,   392,    28,   471,    30,
      31,     0,    32,    33,    34,    35,   515,    37,   516,   517,
      40,    41,    42,    43,   473,     0,    45,   518,    47,   475,
     476,    50,   477,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   478,   479,    68,
       0,    69,    70,    71,   519,     0,     0,    74,    75,    76,
       0,     0,   481,    78,     0,     0,     0,     0,    80,   482,
      82,   483,   484,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   485,    97,    98,   486,   487,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   117,   488,   119,   120,   489,
       0,     0,     0,     0,     0,     0,     0,   490,   491,   127,
       0,     0,     0,   128,   715,   129,   492,     0,     0,     0,
     716,     0,   134,     0,   135,   136,   137,   138,   493,   140,
     141,   142,   143,   144,   145,     0,     0,   146,   147,     0,
       0,   393,   150,   151,   152,   153,   154,   155,   156,   157,
     494,   520,   495,   161,   496,   497,   164,   165,   166,   167,
     168,   169,   498,   171,   499,   500,   501,   175,   176,   502,
     503,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     7,     8,     0,     0,
       0,   464,     0,     0,     0,   390,   391,     0,    14,    15,
      16,   512,    18,    19,    20,   466,   513,   514,   468,   469,
     470,   392,    28,   471,    30,    31,     0,    32,    33,    34,
      35,   515,    37,   516,   517,    40,    41,    42,    43,   473,
       0,    45,   518,    47,   475,   476,    50,   477,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   478,   479,    68,     0,    69,    70,    71,   519,
       0,     0,    74,    75,    76,     0,     0,   481,    78,     0,
       0,     0,     0,    80,   482,    82,   483,   484,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   485,    97,    98,
     486,   487,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,   107,     0,     0,     0,     0,     0,
       0,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   488,   119,   120,   489,     0,     0,     0,     0,     0,
       0,     0,   490,   491,   127,     0,     0,     0,   128,   762,
     129,   492,     0,     0,     0,   763,     0,   134,     0,   135,
     136,   137,   138,   493,   140,   141,   142,   143,   144,   145,
       0,     0,   146,   147,     0,     0,   393,   150,   151,   152,
     153,   154,   155,   156,   157,   494,   520,   495,   161,   496,
     497,   164,   165,   166,   167,   168,   169,   498,   171,   499,
     500,   501,   175,   176,   502,   503,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     7,     8,     0,     0,     0,   464,     0,     0,     0,
     390,   391,     0,    14,    15,    16,   465,    18,    19,    20,
     466,    22,   467,   468,  1072,   470,   392,    28,   471,    30,
      31,     0,    32,    33,    34,    35,   472,    37,    38,    39,
      40,    41,    42,    43,   473,     0,    45,   474,    47,   475,
     476,    50,   477,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   478,   479,    68,
       0,    69,    70,    71,   480,     0,     0,    74,    75,    76,
       0,     0,   481,    78,     0,     0,     0,     0,    80,   482,
      82,   483,   484,    85,    86,  1394,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   485,    97,    98,   486,   487,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,  1073,
       0,     0,     0,  1074,     0,     0,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   117,   488,   119,   120,   489,
       0,     0,     0,     0,     0,     0,     0,   490,   491,   127,
       0,     0,     0,   128,     0,   129,   492,     0,     0,     0,
       0,     0,   134,     0,   135,   136,   137,   138,   493,   140,
     141,   142,   143,   144,   145,     0,     0,  1075,   147,     0,
       0,   393,   150,   151,   152,   153,   154,   155,   156,   157,
     494,   159,   495,   161,   496,   497,   164,   165,   166,   167,
     168,   169,   498,   171,   499,   500,   501,   175,   176,   502,
     503,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     7,     8,     0,     0,
       0,   464,     0,     0,     0,   390,   391,     0,    14,    15,
      16,   465,    18,    19,    20,   466,    22,   467,   468,  1072,
     470,   392,    28,   471,    30,    31,     0,    32,    33,    34,
      35,   472,    37,    38,    39,    40,    41,    42,    43,   473,
       0,    45,   474,    47,   475,   476,    50,   477,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   478,   479,    68,     0,    69,    70,    71,   480,
       0,     0,    74,    75,    76,     0,     0,   481,    78,     0,
       0,     0,     0,    80,   482,    82,   483,   484,    85,    86,
    1525,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   485,    97,    98,
     486,   487,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,  1073,     0,     0,     0,  1074,     0,
       0,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   488,   119,   120,   489,     0,     0,     0,     0,     0,
       0,     0,   490,   491,   127,     0,     0,     0,   128,     0,
     129,   492,     0,     0,     0,     0,     0,   134,     0,   135,
     136,   137,   138,   493,   140,   141,   142,   143,   144,   145,
       0,     0,  1075,   147,     0,     0,   393,   150,   151,   152,
     153,   154,   155,   156,   157,   494,   159,   495,   161,   496,
     497,   164,   165,   166,   167,   168,   169,   498,   171,   499,
     500,   501,   175,   176,   502,   503,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     7,     8,     0,     0,     0,   464,     0,     0,     0,
     390,   391,     0,    14,    15,    16,   465,    18,    19,    20,
     466,    22,   467,   468,  1072,   470,   392,    28,   471,    30,
      31,     0,    32,    33,    34,    35,   472,    37,    38,    39,
      40,    41,    42,    43,   473,     0,    45,   474,    47,   475,
     476,    50,   477,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   478,   479,    68,
       0,    69,    70,    71,   480,     0,     0,    74,    75,    76,
       0,     0,   481,    78,     0,     0,     0,     0,    80,   482,
      82,   483,   484,    85,    86,  1529,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   485,    97,    98,   486,   487,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,  1073,
       0,     0,     0,  1074,     0,     0,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   117,   488,   119,   120,   489,
       0,     0,     0,     0,     0,     0,     0,   490,   491,   127,
       0,     0,     0,   128,     0,   129,   492,     0,     0,     0,
       0,     0,   134,     0,   135,   136,   137,   138,   493,   140,
     141,   142,   143,   144,   145,     0,     0,  1075,   147,     0,
       0,   393,   150,   151,   152,   153,   154,   155,   156,   157,
     494,   159,   495,   161,   496,   497,   164,   165,   166,   167,
     168,   169,   498,   171,   499,   500,   501,   175,   176,   502,
     503,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     7,     8,     0,     0,
       0,   464,     0,     0,     0,   390,   391,     0,    14,    15,
      16,   465,    18,    19,    20,   466,    22,   467,   468,  1072,
     470,   392,    28,   471,    30,    31,     0,    32,    33,    34,
      35,   472,    37,    38,    39,    40,    41,    42,    43,   473,
       0,    45,   474,    47,   475,   476,    50,   477,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   478,   479,    68,     0,    69,    70,    71,   480,
       0,     0,    74,    75,    76,     0,     0,   481,    78,     0,
       0,     0,     0,    80,   482,    82,   483,   484,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   485,    97,    98,
     486,   487,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,  1073,     0,     0,     0,  1074,     0,
       0,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   488,   119,   120,   489,     0,     0,     0,     0,     0,
       0,     0,   490,   491,   127,     0,     0,     0,   128,     0,
     129,   492,     0,     0,     0,     0,     0,   134,     0,   135,
     136,   137,   138,   493,   140,   141,   142,   143,   144,   145,
       0,     0,  1075,   147,     0,     0,   393,   150,   151,   152,
     153,   154,   155,   156,   157,   494,   159,   495,   161,   496,
     497,   164,   165,   166,   167,   168,   169,   498,   171,   499,
     500,   501,   175,   176,   502,   503,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     7,     8,     0,     0,     0,   464,     0,     0,     0,
     390,   391,     0,    14,    15,    16,   465,    18,    19,    20,
     466,    22,   467,   468,  1072,   470,   392,    28,   471,    30,
      31,     0,    32,    33,    34,    35,   472,    37,    38,    39,
      40,    41,    42,    43,   473,     0,    45,   474,    47,   475,
     476,    50,   477,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   478,   479,    68,
       0,    69,    70,    71,   480,     0,     0,    74,    75,    76,
       0,     0,   481,    78,     0,     0,     0,     0,    80,   482,
      82,   483,   484,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   485,    97,    98,   486,   487,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,  1073,
       0,     0,     0,  1074,     0,     0,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   117,   488,   119,   120,   489,
       0,     0,     0,     0,     0,     0,     0,   490,   491,   127,
       0,     0,     0,   128,     0,   129,   492,     0,     0,     0,
       0,     0,   134,     0,   135,   136,   137,   138,   493,   140,
     141,   142,   143,   144,   145,     0,     0,   146,   147,     0,
       0,   393,   150,   151,   152,   153,   154,   155,   156,   157,
     494,   159,   495,   161,   496,   497,   164,   165,   166,   167,
     168,   169,   498,   171,   499,   500,   501,   175,   176,   502,
     503,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     7,     8,     0,     0,
       0,   464,     0,     0,     0,   390,   391,     0,    14,    15,
      16,   512,    18,    19,    20,   466,   513,   514,   468,   469,
     470,   392,    28,   471,    30,    31,     0,    32,    33,    34,
      35,   515,    37,   516,   517,    40,    41,    42,    43,   473,
       0,    45,   518,    47,   475,   476,    50,   477,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   478,   479,    68,     0,    69,    70,    71,   519,
       0,     0,    74,    75,    76,     0,     0,   481,    78,     0,
       0,     0,     0,    80,   482,    82,   483,   484,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   485,    97,    98,
     486,   487,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,   107,     0,     0,     0,     0,     0,
       0,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   488,   119,   120,   489,     0,     0,     0,     0,     0,
       0,     0,   490,   491,   127,     0,     0,     0,   128,     0,
     129,   492,     0,     0,     0,     0,     0,   134,     0,   135,
     136,   137,   138,   493,   140,   141,   142,   143,   144,   145,
       0,     0,   146,   147,     0,     0,   393,   150,   151,   152,
     153,   154,   155,   156,   157,   494,   520,   495,   161,   496,
     497,   164,   165,   166,   167,   168,   169,   498,   171,   499,
     500,   501,   175,   176,   502,   503,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     7,     8,     0,     0,     0,   464,     0,     0,     0,
     390,   391,     0,    14,    15,    16,     0,    18,    19,    20,
     466,     0,     0,   468,   469,     0,   392,    28,   471,    30,
      31,     0,    32,    33,    34,    35,     0,    37,     0,     0,
      40,    41,    42,    43,   473,     0,    45,     0,    47,     0,
       0,    50,   477,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   478,   479,    68,
       0,    69,    70,    71,     0,     0,     0,    74,    75,    76,
       0,     0,   481,    78,     0,     0,     0,     0,    80,   482,
      82,   483,   484,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   485,    97,    98,   486,   487,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,     0,
       0,     0,     0,     0,     0,     0,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   117,   488,   119,   120,   489,
       0,     0,     0,     0,     0,     0,     0,   490,   491,   127,
       0,     0,     0,   128,     0,   129,   492,     0,     0,     0,
       0,     0,   134,     0,   135,   136,   137,   138,   493,   140,
     141,   142,   143,   144,   145,     0,     0,     0,   147,     0,
       0,   393,   150,   151,   152,   153,   154,   155,   156,   157,
     494,     0,   495,   161,   496,   497,   164,   165,   166,   167,
     168,   169,   498,   171,   499,   500,   501,   175,   176,     0,
     503,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,    12,   178,   630,     4,     5,     6,   328,     0,   399,
     400,   300,     4,     5,     6,   988,   778,  1221,   844,   109,
       4,     5,     6,   805,   132,   739,   581,   582,  1205,     4,
       5,     6,     4,     5,     6,   972,   722,   751,    73,   249,
     631,   632,   633,   634,   722,   858,  1010,    36,   280,    73,
    1139,   765,    87,   248,   264,   579,   580,   581,   582,  1277,
    1278,    26,    27,   401,   879,    26,    27,    26,    27,    36,
     413,   118,  1058,   579,   580,   110,    37,    38,    96,    40,
      41,   424,    47,     1,   676,   895,    47,   122,    47,   124,
       1,    56,     1,   857,   858,    56,    57,    29,     1,    55,
     271,   439,   440,  1310,   447,    94,   142,    96,   108,    74,
      30,     8,   118,    74,    79,    74,   108,  1234,    79,    29,
       1,  1490,     1,   609,   108,   611,   612,   107,   614,    96,
     616,   895,   100,   108,     1,    93,   949,    39,   624,   625,
      76,   107,    44,    45,    29,   107,   111,   112,   113,   962,
     111,   112,   113,   112,    26,    27,    45,    59,   147,    61,
      62,   118,    96,  1553,   396,   929,   147,   118,    70,    53,
      33,    94,   107,    62,    58,   122,   100,   224,   169,   113,
     147,   113,   107,   147,    24,   949,    49,   901,    42,   160,
     280,   107,    46,   107,    34,    97,    94,    51,   962,   160,
     110,    37,    38,   130,    40,    41,   153,    94,   224,   156,
     201,   156,    96,   229,   124,    69,  1434,   153,   186,   142,
      60,    57,   156,   331,   190,   183,   188,   100,   160,  1202,
     187,  1408,  1058,  1059,  1624,   186,   272,   255,   256,   149,
     112,   955,   242,   153,  1006,   245,   156,   961,   537,   420,
     242,  1188,   187,   245,   234,   810,   811,  1346,   219,   306,
     216,  1225,   186,   188,  1074,  1634,   272,   177,   954,   196,
    1234,   187,   190,   187,   952,   160,   954,   113,   175,   190,
     280,   190,  1489,   272,   220,   221,  1101,   190,   280,   881,
      54,   272,    56,   213,  1411,   527,   974,   253,   187,   260,
    1286,   336,   808,   809,   339,   272,   396,   107,   272,   190,
    1074,   190,   336,   186,   168,   339,   659,   171,   131,   217,
     218,   286,   224,   190,   160,   286,   130,   286,   158,   294,
     217,   218,   186,   294,   232,   294,   100,   302,   107,   429,
     106,   302,   107,   118,  1548,   232,   176,   437,   258,   687,
     107,   107,    94,   943,   840,   945,   446,   211,   107,   107,
      45,   127,    47,   453,   454,   597,   576,  1180,  1586,   268,
     405,   406,   462,   107,   409,    96,   275,   190,   413,   156,
    1144,   416,   417,   219,   579,   580,   285,   187,   107,   424,
     733,  1204,   196,   736,    79,   430,   396,     5,   433,   737,
     142,     9,   153,  1492,   396,   995,   441,   997,   107,   148,
     153,   186,   447,   448,   449,   450,  1180,   107,   187,  1637,
     455,   106,   187,   107,   260,   425,   165,   427,   463,  1143,
     187,   187,    45,   425,    47,   427,   185,   527,   268,   187,
    1204,   425,   107,   427,  1621,   275,   107,  1411,   169,   539,
     425,   451,   427,   187,   844,   285,   456,    29,   209,   451,
    1286,   551,   107,   107,   456,   184,   209,   451,  1154,  1295,
     107,    96,   456,   508,   706,   121,   451,   567,   568,  1261,
    1306,   456,  1264,   168,   874,  1163,   250,   522,   187,  1044,
    1045,  1046,   107,   106,   117,   136,   531,   187,   107,   263,
     216,   265,  1591,   187,   153,  1318,     9,    10,   107,     9,
      10,   107,   276,   277,   278,   123,   280,   125,   282,   184,
    1044,  1045,  1046,   146,   107,   133,   187,   527,   563,   107,
     251,   252,   532,   254,   107,   527,   159,   253,   110,   184,
     532,   649,   650,   187,   169,   153,  1635,   184,   532,    94,
     271,   107,   124,   107,  1318,   168,   646,   532,    96,   200,
      96,   651,   283,   574,   902,   903,   107,  1281,   568,   907,
     193,   803,   187,   122,  1547,  1512,   568,   149,   187,   579,
     580,   581,   582,  1396,   568,   184,  1399,   579,   580,   581,
     582,   187,   153,   136,   156,   156,    94,   597,    29,   937,
     103,   184,   147,   103,   814,   597,   107,   150,    52,   187,
      96,   147,   107,   808,   187,   107,   706,  1706,   156,  1708,
     123,   148,   125,   123,   659,   125,   251,   252,  1717,   254,
     968,   187,  1396,   187,   972,  1399,   261,  1463,   165,    96,
     153,   158,   224,   184,   226,   680,   271,  1409,   683,   147,
     153,     5,  1414,   153,   157,     9,   113,   157,   283,   176,
      94,   147,   697,   156,   177,    94,   701,   702,  1058,  1059,
    1297,   174,     9,    10,   174,  1361,   153,   106,   144,   110,
     770,   771,   772,   184,   774,   129,     9,    10,   723,   184,
     725,   194,   184,   124,   194,   156,     9,    66,   733,   156,
     177,   736,    71,   137,   166,   740,   706,    96,   142,   212,
     176,  1266,   212,   142,   706,    28,    94,    42,   149,    33,
     182,    46,   153,   158,   113,   156,    51,   193,   106,   729,
     182,   200,   246,   247,   583,    49,   137,   729,   587,  1060,
     209,   176,   777,   195,    69,   729,   177,  1036,    53,   118,
    1613,  1614,   153,    58,   729,   269,  1569,   729,  1571,   759,
     760,   156,     9,   198,   158,   156,   103,   759,   760,   123,
     805,   125,    77,  1535,    42,   759,   760,  1539,    46,   133,
     103,    28,   176,    51,   759,   760,   123,   267,   125,  1602,
    1653,    96,   827,   137,   274,   154,  1659,   156,  1030,   153,
     123,    69,   125,   803,   198,  1569,   182,  1571,   819,   153,
     123,   803,   125,   118,   153,    95,   153,   156,  1631,   195,
     157,   134,   857,   858,   859,   860,   106,  1454,  1455,   100,
     153,   100,   118,  1646,   157,  1648,   116,   174,  1602,   100,
     153,   100,   113,   168,   113,  1183,   171,   127,   262,   100,
    1188,   174,   113,   892,   113,  1617,  1447,   194,  1034,   273,
     895,   186,   113,  1039,   100,   904,   156,  1631,    53,   262,
     298,   194,  1586,    58,   909,   212,   123,   113,   125,   307,
     273,   156,  1646,   137,  1648,   137,   211,   134,   142,   212,
     142,   276,   277,   278,   635,   636,  1286,   282,   652,   934,
     168,   655,   338,   171,   658,  1295,   153,   343,   943,   153,
     945,   122,   156,   224,   949,   226,  1306,   122,   186,   153,
     128,   129,   156,   220,   221,   222,   118,   962,   191,   192,
    1557,  1558,   231,   122,   233,  1273,   122,   231,   132,   233,
     128,   129,   118,   211,   637,   638,   140,   141,   122,   143,
    1182,   628,   629,   859,   860,  1480,  1481,   151,   122,   122,
     995,   155,   997,   157,   122,   122,   153,  1057,   162,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,   122,
     153,   156,   215,   224,   118,   179,   241,   240,   156,     0,
     990,   240,   153,   107,   190,   167,    92,    99,   990,    50,
    1627,   199,   248,   101,   154,   102,   990,   145,   202,   203,
     204,   205,   206,   207,   121,   990,   156,   184,  1053,   184,
      29,    47,   184,   152,   118,   245,   303,   187,  1260,   118,
    1030,   153,  1043,   283,     1,   283,   118,   142,  1030,  1074,
    1378,   107,   187,   153,  1044,  1045,  1046,   153,   156,   142,
     153,   184,  1044,  1045,  1046,   156,   156,   156,    35,    17,
     213,   156,   187,    29,   156,   156,   156,   190,     3,   190,
     118,   230,    70,  1463,   244,   230,    94,    94,    94,   149,
     168,    29,   107,   170,   170,   107,   160,   160,    73,   127,
     132,   245,    94,   142,   298,   118,   132,   107,    94,   184,
    1438,   184,    87,   187,    96,    45,   187,    96,   187,   187,
     187,   187,   184,   153,    94,   184,   236,    33,  1153,   190,
     224,  1156,   142,   170,   118,   110,   132,   142,    29,    94,
      94,   118,   298,   285,   153,   118,  1171,   122,   253,   124,
     147,   127,   118,    94,   197,  1180,   226,  1147,   132,   184,
     132,    96,   160,   153,   147,  1147,   118,   100,  1390,  1194,
     184,   100,   153,  1147,   142,    35,  1256,  1257,  1258,  1204,
     184,    29,  1147,    79,  1512,  1147,   118,   190,   107,   153,
     244,   156,  1182,   156,   156,   107,   156,   156,   156,   144,
    1182,   266,   257,  1193,    29,    29,   259,  1232,    29,   226,
     190,  1193,   127,   144,   118,   118,   187,   107,   187,  1193,
     147,   147,  1212,   147,    77,   142,   284,  1252,  1193,   286,
    1212,  1193,   100,   285,   187,   184,  1261,   187,  1212,  1264,
     187,  1231,     7,   187,   132,   232,   197,  1212,   190,  1231,
    1212,   236,   186,   147,   305,   106,   249,  1231,   249,   187,
     281,   285,    78,    29,   187,   187,  1231,   187,    29,  1259,
    1260,   232,   107,   170,   184,   270,   147,  1259,  1260,   126,
     147,   126,    96,   184,   186,  1259,   232,   186,  1510,   232,
     142,   186,   153,  1318,   186,   184,    94,   184,   184,  1521,
    1522,   279,  1524,   187,    29,    96,   187,   170,   147,  1531,
      53,    94,   186,   186,   196,    94,   256,  1342,   197,   106,
      29,   107,   107,   118,   224,   118,    94,   264,   186,   118,
      94,   196,   196,    93,   196,   242,   186,   186,   118,   224,
     183,   118,   186,  1368,  1369,   186,   186,   286,   224,   118,
     248,   686,   198,  1104,   896,   400,   963,  1144,  1591,  1635,
     806,   336,   245,   960,   339,   245,   742,  1153,   304,  1394,
     420,  1396,   286,  1371,  1399,   555,   556,  1172,   558,   559,
     560,   561,  1280,   304,   292,  1410,   566,   305,  1610,   305,
    1415,   304,  1282,  1049,   305,  1277,   522,  1194,  1620,  1199,
    1390,  1202,  1207,   607,   661,   608,   627,  1225,  1390,   589,
    1659,   778,  1653,  1138,  1252,   324,   860,   597,   598,  1103,
     945,  1262,  1295,  1306,  1261,  1647,   428,  1463,  1460,  1059,
    1068,   406,  1299,   928,   409,  1126,  1483,  1296,   413,   428,
    1337,   416,   417,    -1,    -1,    -1,    -1,    -1,    -1,   424,
      -1,    -1,    -1,    -1,    -1,   430,    -1,  1679,   433,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   441,    -1,    -1,  1549,
      -1,    -1,   447,   448,   449,   450,    -1,   657,  1700,    -1,
     455,   661,    -1,  1705,    -1,    -1,    -1,  1567,   463,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1525,    -1,  1527,    -1,  1529,    -1,    -1,    -1,    -1,    -1,
      -1,  1536,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   699,
    1510,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1510,    -1,
      -1,  1521,  1522,   508,  1524,    -1,    -1,    -1,    -1,  1521,
    1522,  1531,  1524,    -1,  1569,    -1,  1571,   522,    -1,  1531,
      -1,    -1,    -1,    -1,    -1,    -1,   531,    -1,    -1,    -1,
      -1,   741,  1587,    -1,    -1,  1590,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1602,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   766,  1612,   563,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   776,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1631,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1639,    -1,    -1,    -1,    -1,  1644,
    1610,  1646,    -1,  1648,    -1,    -1,    -1,    -1,  1610,    -1,
    1620,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1620,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   829,
      -1,  1676,    -1,    -1,    -1,    -1,    -1,  1647,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1647,    -1,  1692,    -1,    -1,
      -1,  1696,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   659,    -1,    -1,  1712,    -1,  1679,
    1715,    -1,    -1,    -1,    -1,    -1,    -1,  1679,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   683,    -1,
    1700,    -1,    -1,    -1,    -1,  1705,    -1,   897,  1700,    -1,
      -1,    -1,   697,  1705,    -1,    -1,   701,   702,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   723,    -1,
     725,    -1,   932,    -1,    -1,    -1,    -1,    -1,   733,    -1,
      -1,   736,    -1,    -1,    -1,   740,    -1,    -1,    -1,    -1,
      -1,   951,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   973,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   777,    -1,   984,   985,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   999,
      -1,    -1,  1002,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     805,    -1,    -1,    -1,    -1,    -1,  1016,  1017,  1018,    -1,
    1020,  1021,  1022,  1023,  1024,  1025,    -1,  1027,  1028,    -1,
      -1,    -1,   827,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1049,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   857,   858,   859,   860,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1091,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     895,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   909,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   934,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   943,    -1,
     945,    -1,    -1,    -1,   949,    -1,    -1,    -1,  1158,    -1,
    1160,    -1,  1162,    -1,    -1,  1165,    -1,   962,    -1,    -1,
    1170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1191,    -1,    -1,    -1,    -1,    -1,  1197,  1198,    -1,
     995,    -1,   997,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1216,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1053,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1074,
    1280,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1355,    -1,    -1,  1153,  1359,
      -1,  1156,    -1,  1363,    -1,  1365,    -1,  1367,    -1,    -1,
      -1,    -1,    -1,  1373,    -1,    -1,  1171,    -1,    -1,    -1,
      -1,  1381,    -1,    -1,    -1,  1180,    -1,    -1,    -1,  1389,
    1390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1194,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1407,    -1,  1204,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1418,  1419,
    1420,  1421,  1422,    -1,  1424,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1232,    -1,  1439,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1252,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1261,    -1,    -1,  1264,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1498,    -1,
    1500,    -1,    -1,  1503,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1511,    -1,    -1,    -1,    -1,  1516,  1517,    -1,    -1,
      -1,    -1,    -1,  1318,  1524,    -1,    -1,    -1,  1528,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1342,    -1,    -1,
      -1,    -1,    -1,    -1,  1554,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1368,  1369,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1594,    -1,    -1,    -1,    -1,  1394,
      -1,  1396,    -1,    -1,  1399,    -1,  1606,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1410,    -1,    -1,    -1,    -1,
    1415,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1647,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1674,    -1,    -1,    -1,    -1,  1679,
      -1,    -1,    -1,    -1,  1684,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1699,
      -1,    -1,    -1,  1703,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1525,    -1,  1527,    -1,  1529,    -1,    -1,    -1,    -1,    -1,
      -1,  1536,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1569,    -1,  1571,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1587,    -1,    -1,  1590,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1602,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1612,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1631,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1639,    -1,    -1,    -1,    -1,  1644,
      -1,  1646,    -1,  1648,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1676,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1692,    -1,    -1,
      -1,  1696,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    11,    12,    -1,    -1,    -1,  1712,    -1,    -1,
    1715,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
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
     149,   150,   151,   152,   153,    -1,    -1,   156,   157,   158,
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
     309,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     150,   151,   152,   153,    -1,    -1,   156,   157,   158,   159,
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
     300,   301,   302,   303,   304,   305,   306,   307,   308,    11,
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
     152,   153,    -1,    -1,   156,   157,   158,   159,   160,    -1,
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
     302,   303,   304,   305,   306,   307,   308,    11,    12,    -1,
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
      -1,    -1,   156,   157,   158,   159,   160,    -1,    -1,    -1,
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
     304,   305,   306,   307,   308,    11,    12,    -1,    -1,    -1,
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
     146,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
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
     306,   307,   308,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
     148,   149,   150,   151,   152,   153,    -1,    -1,   156,   157,
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
     308,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     150,   151,   152,   153,    -1,    -1,   156,   157,   158,   159,
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
     300,   301,   302,   303,   304,   305,   306,   307,   308,    11,
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
     152,   153,    -1,    -1,   156,   157,   158,   159,   160,    -1,
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
     302,   303,   304,   305,   306,   307,   308,    11,    12,    -1,
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
      -1,    -1,   156,   157,   158,   159,   160,    -1,    -1,    -1,
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
     304,   305,   306,   307,   308,    11,    12,    -1,    -1,    -1,
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
     146,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
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
     306,   307,   308,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
     148,   149,   150,   151,   152,   153,    -1,    -1,   156,   157,
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
     308,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     150,   151,   152,   153,    -1,    -1,   156,   157,   158,   159,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,   187,   188,   189,
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
     300,   301,   302,   303,   304,   305,   306,   307,   308,    11,
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
     152,   153,    -1,    -1,   156,   157,   158,   159,   160,    -1,
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
     302,   303,   304,   305,   306,   307,   308,    11,    12,    -1,
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
      -1,    -1,   156,   157,   158,   159,   160,    -1,    -1,    -1,
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
     304,   305,   306,   307,   308,    11,    12,    -1,    -1,    -1,
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
     146,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
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
     306,   307,   308,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
     148,   149,   150,   151,   152,   153,    -1,    -1,   156,   157,
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
     308,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     150,   151,   152,   153,    -1,    -1,   156,   157,   158,   159,
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
     300,   301,   302,   303,   304,   305,   306,   307,   308,    11,
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
     152,   153,    -1,    -1,   156,   157,   158,   159,   160,    -1,
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
     302,   303,   304,   305,   306,   307,   308,    11,    12,    -1,
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
      -1,    -1,   156,   157,    -1,   159,   160,    -1,    -1,    -1,
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
     304,   305,   306,   307,   308,    11,    12,    -1,    -1,    -1,
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
     146,   147,   148,   149,   150,   151,   152,   153,    -1,    -1,
     156,   157,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,   193,    -1,   195,
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
     306,   307,   308,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    24,    25,    -1,    -1,
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
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
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
     308,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    29,
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
     300,   301,   302,   303,   304,   305,   306,   307,   308,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
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
     187,   188,   189,    -1,    -1,    -1,    -1,    -1,   195,    -1,
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
     307,   308,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
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
     304,   305,   306,   307,   308,    18,    19,    -1,    -1,    -1,
      -1,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
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
     303,   304,   305,   306,   307,   308,    24,    25,    -1,    -1,
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
     308,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
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
     303,   304,   305,   306,   307,   308,    24,    25,    -1,    -1,
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
     308,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
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
     303,   304,   305,   306,   307,   308,    24,    25,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      -1,    -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
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
     308,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
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
     303,   304,   305,   306,   307,   308,    24,    25,    -1,    -1,
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
     308,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
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
     303,   304,   305,   306,   307,   308,    24,    25,    -1,    -1,
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
     308,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    -1,    40,    41,    42,
      43,    -1,    -1,    46,    47,    -1,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    -1,    60,    -1,    -1,
      63,    64,    65,    66,    67,    -1,    69,    -1,    71,    -1,
      -1,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    -1,    -1,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
      -1,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,    -1,    -1,   211,    -1,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,    -1,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,    -1,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308
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
     139,   146,   147,   148,   149,   150,   151,   152,   153,   156,
     157,   158,   159,   160,   165,   166,   167,   168,   169,   170,
     171,   172,   174,   176,   177,   180,   181,   182,   186,   188,
     189,   191,   192,   193,   195,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   210,   211,   212,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   258,   259,   260,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   324,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   345,   346,   347,   348,   349,   350,   354,   355,   356,
     360,   362,   363,   365,   372,   374,   377,   378,   379,   381,
     382,   383,   384,   385,   387,   388,   390,   391,   392,   393,
     394,   395,   397,   398,   401,   402,   403,   404,   409,   411,
     413,   414,   419,   438,   441,   445,   448,   449,   454,   455,
     456,   457,   459,   460,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   506,   507,   508,   522,   523,   525,   526,
     527,   528,   529,   530,   531,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   551,   552,   553,   554,   559,
     560,   561,   562,   563,   564,   567,   625,   627,   628,   629,
      33,    34,    49,   214,   380,   381,   382,   380,   380,   156,
     156,    37,    38,    40,    41,    47,    56,    57,    74,    79,
     111,   112,   113,   160,   219,   260,   286,   294,   302,   361,
     362,   366,   367,   368,   160,   153,   156,   153,   156,   153,
     156,    66,    71,   118,   406,   156,   369,   156,    24,    34,
      60,   118,   272,   418,   420,   421,   153,   156,   156,   156,
     118,   153,   156,   156,   156,    76,   153,   220,   221,   122,
     122,   122,   153,   156,    29,    39,    43,    45,    46,    47,
      48,    51,    59,    67,    70,    72,    73,    75,    90,    91,
      97,   105,   112,   114,   115,   135,   138,   139,   169,   172,
     180,   181,   189,   201,   223,   225,   227,   228,   235,   237,
     238,   239,   242,   243,   490,   627,   628,   122,   118,   389,
     122,   122,    39,    44,    45,    59,    61,    62,    70,    97,
     224,   627,   118,   122,   122,   184,   380,   382,    48,    72,
      73,   118,   153,   187,   243,   401,   403,   413,   627,   153,
     122,    16,   626,   627,    18,    19,   627,   122,   122,   122,
     482,   153,    30,   213,   215,   224,   226,   156,   224,   226,
     224,   224,   229,   118,   240,   240,   241,   156,   153,   384,
     326,     0,   328,   329,    33,    49,   331,   348,     1,   190,
     325,   190,   325,   112,   363,   383,   401,   107,   190,   107,
     190,    42,    46,    51,    69,   168,   171,   186,   211,   396,
     405,   410,   411,   412,   426,   427,   431,   167,    92,   132,
     140,   141,   143,   151,   155,   157,   162,   179,   202,   203,
     204,   205,   206,   207,   474,   475,   248,    99,   158,   176,
     198,   117,   146,   159,   193,   200,   209,   136,   150,    50,
     199,   101,   102,   158,   176,   473,   153,   479,   482,   191,
     192,   154,   494,   495,   490,   494,   490,   156,   494,   121,
     145,   156,   184,   184,   184,    29,   364,   497,   364,   625,
     182,   195,   182,   195,   166,   182,   628,   627,   169,   201,
      47,   627,   152,   118,    45,    47,    79,   106,   168,   626,
     220,   221,   222,   245,   598,   627,   627,   303,   137,   142,
     112,   286,   294,   366,   626,   381,   382,   187,   381,    45,
      62,   187,   547,   548,   401,   187,   193,   627,   283,   283,
     415,   416,   627,   118,   422,   118,   187,   370,   371,   153,
     386,   401,     1,   160,   625,   113,   160,   344,   625,   627,
     118,   142,   107,   401,    29,   187,   626,   627,   627,   439,
     440,   627,   381,   187,   401,   401,   549,   627,   381,   153,
     153,   401,   187,   193,   627,   627,   142,   439,   184,   184,
     156,   156,   156,   627,   153,   187,   186,    35,   510,   511,
     512,   401,     8,   175,    17,   401,   213,    29,   402,   402,
     187,   402,   402,   402,   402,   230,   565,   566,   627,   190,
     190,   402,   401,   382,   401,   244,   399,   400,   190,   325,
     190,   325,     3,   332,   348,   378,   332,   348,   378,    33,
     349,   378,   349,   378,   389,   389,   402,   118,   168,   170,
     170,   383,   402,   402,   456,   457,   459,   459,   459,   459,
     458,   459,   459,   459,    70,   460,   464,   464,   463,   465,
     465,   465,   465,   466,   466,   467,   467,   230,    94,    94,
      94,   184,   401,   482,   482,   401,   495,   187,   402,   505,
     626,   149,   187,   505,   107,   187,   187,   107,   107,   369,
      29,   628,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,   351,   352,   353,    94,   137,   142,   357,   358,
     359,   627,   160,   160,   351,   625,   127,   132,    54,    56,
     100,   250,   263,   265,   276,   277,   278,   280,   282,   599,
     600,   601,   602,   603,   604,   611,   617,   618,   245,    94,
     298,   627,   142,   402,   118,   627,   627,   132,   184,   184,
     187,   187,   184,   107,   187,   107,   187,   107,    36,    94,
      96,   147,   417,   418,   533,   627,    55,   216,   253,   407,
     408,   627,    94,   107,   187,   380,   187,   626,    96,    45,
     626,   625,    96,   142,   533,   627,   402,   421,   184,   187,
     187,   187,   187,   107,   188,   147,   533,   184,   187,   187,
     153,   184,   381,   381,   184,   107,   187,   107,   187,   142,
     533,   402,   188,   401,   401,   401,   627,   511,   512,   130,
     196,   184,   184,   131,   190,    94,   217,   218,   232,    94,
     217,   218,   232,    94,   236,   224,   107,   234,   142,   190,
     187,    48,    72,    73,   243,   403,   413,   184,   491,   571,
     400,   348,    33,    33,   190,   325,   190,   113,   627,   170,
     402,   432,   433,   118,   428,   429,   459,   153,   156,   258,
     478,   497,   572,   575,   576,   577,   578,   579,   583,   585,
     587,   588,    47,   152,   156,   210,   534,   536,   538,   539,
     555,   556,   557,   558,   627,   534,   532,   538,   532,   184,
     185,   107,   187,   187,   497,   148,   165,   148,   165,   137,
     386,   369,   352,   132,   536,   359,   402,   533,   625,   625,
     128,   129,   625,   276,   277,   278,   282,   627,   262,   273,
     262,   273,    29,   285,    96,   113,   156,   605,   608,   599,
      39,    44,    59,    61,    70,    97,   224,   373,   539,   226,
     298,   307,   402,   627,    94,   298,   625,   153,   549,   550,
     627,   549,   550,   118,   127,   534,   118,   402,   147,   418,
     147,    36,   147,   417,   418,   147,   533,   253,    53,    58,
      77,   118,   417,   423,   424,   425,   408,   533,   534,   371,
      94,   184,   197,   132,   343,   625,   160,   132,    96,   343,
     402,   142,   418,   153,   118,   402,   402,   147,   100,   442,
     443,   444,   446,   447,   100,   450,   451,   452,   453,   381,
     184,   184,   153,   549,   549,   402,   142,   190,   402,   187,
     187,   187,    35,   512,   130,   196,     9,    10,   103,   123,
     125,   153,   194,   507,   509,   520,   521,   524,    29,   231,
     233,   402,   402,   402,   231,   233,   402,   402,   402,   402,
     402,   402,   118,   402,   402,   383,   156,   156,   156,   153,
     186,   244,   568,   569,   209,   384,   190,   113,   378,   378,
     378,   432,    95,   106,   116,   127,   434,   435,   436,   437,
     107,   627,   107,   401,   572,   579,   153,   284,   461,   624,
      96,   169,   251,   252,   254,   261,   271,   283,   573,   574,
     593,   594,   595,   596,   619,   622,   257,   259,   580,   598,
     266,   584,   620,   246,   247,   269,   589,   590,   156,   156,
     536,   156,   144,   176,   193,   535,   144,   402,   137,   386,
     551,   358,   285,    29,    96,   113,   156,   612,    29,   605,
     535,   480,   286,   305,   533,   373,   226,   190,   380,   187,
     187,   144,   187,   187,   416,   147,   417,   627,   402,   147,
     402,   127,   402,   147,   418,   147,   402,   147,   118,   118,
     402,   627,   425,    77,   534,   383,   402,   625,   107,   343,
     402,   142,   380,   440,   402,   402,   113,   443,   444,   100,
     186,   113,   444,   447,   118,   534,   100,   113,   451,   100,
     113,   453,   184,   380,   187,   187,   402,   197,   450,   132,
     194,   509,     7,   381,   627,   194,   520,   190,   232,   232,
     232,   232,   236,   566,   186,   401,   401,   401,   571,   569,
     491,   625,   128,   129,   436,   437,   437,   433,   106,   142,
     430,   533,   429,   184,   187,   572,   586,   249,   216,   253,
     267,   274,   623,    96,   255,   256,   621,   249,   576,   623,
     463,   593,   577,   147,   281,   581,   582,   621,   285,   592,
      78,   591,   187,   193,   534,   537,   187,   187,   187,    29,
     136,   200,   614,   615,   616,    29,   613,   614,   270,   609,
     107,   606,   170,   627,   256,   480,   184,   402,   147,   402,
     147,   417,   402,   147,   402,   402,   627,   627,   424,   402,
     126,   126,    96,   625,   402,   184,   186,   186,   402,   383,
     402,   186,   186,   627,   186,   118,   534,   118,   186,   118,
     534,   186,   184,   113,   512,   627,   194,   184,   512,   627,
     402,   402,   402,   402,   402,   402,   187,   187,   187,   153,
     570,   437,   625,   402,   142,   184,   465,    52,   129,   463,
     463,   268,   275,   285,   597,   597,   578,   153,   279,    94,
     187,   107,   187,   612,   612,   616,   107,   187,    29,   610,
     621,   607,   608,   187,   375,   376,   480,   118,   224,   306,
     286,   170,   402,   402,   147,   402,    53,   383,   402,   343,
     402,   383,    94,   383,   402,   627,   186,   627,   402,   627,
     186,   383,   118,    93,   183,   513,   512,   627,   196,   512,
     197,   450,   401,   430,   402,   463,   463,   198,   401,   534,
     534,    94,    29,   264,   107,   107,   437,   533,   627,   118,
     224,   627,   375,   402,   118,   534,    94,   186,    94,   627,
       5,   133,   516,   517,   519,   521,    28,   134,   514,   515,
     518,   521,   196,   512,   196,   113,   184,   430,   463,   184,
     534,   608,   376,   437,   304,   627,   118,   224,   627,   186,
     534,   383,   402,   534,   186,    93,   133,   519,   183,   134,
     518,   196,   118,   402,   304,   627,   118,   383,   402,   186,
     186,   627,   292,   304,   627,   186,   305,   402,   305,   480,
     480,   198,   286,   627,   224,   118,   627,   305,   480
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
     575,   576,   577
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   323,   324,   324,   325,   326,   326,   326,   326,   327,
     327,   328,   328,   328,   328,   328,   328,   328,   328,   329,
     329,   329,   329,   330,   331,   331,   331,   332,   332,   332,
     332,   332,   333,   333,   333,   333,   333,   333,   333,   333,
     334,   334,   335,   336,   337,   337,   338,   338,   339,   339,
     340,   340,   340,   340,   341,   341,   341,   342,   342,   342,
     342,   343,   343,   344,   344,   345,   345,   345,   345,   346,
     347,   347,   348,   348,   348,   349,   349,   349,   349,   349,
     349,   349,   349,   350,   350,   351,   351,   352,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   354,   355,
     356,   357,   357,   358,   358,   358,   359,   360,   360,   360,
     361,   361,   361,   361,   362,   362,   363,   363,   363,   363,
     364,   364,   365,   365,   366,   366,   367,   367,   368,   368,
     369,   369,   369,   369,   370,   370,   371,   371,   372,   372,
     372,   372,   373,   373,   374,   374,   375,   375,   376,   376,
     376,   376,   377,   377,   377,   377,   378,   379,   379,   379,
     380,   380,   380,   381,   381,   382,   382,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   384,
     384,   385,   386,   387,   388,   388,   388,   389,   389,   389,
     389,   390,   391,   392,   393,   394,   394,   395,   396,   397,
     398,   399,   399,   400,   401,   401,   402,   402,   402,   402,
     402,   402,   403,   403,   403,   403,   403,   403,   403,   404,
     405,   406,   406,   407,   407,   407,   408,   408,   409,   409,
     410,   411,   411,   411,   412,   412,   412,   412,   412,   413,
     413,   414,   415,   415,   416,   416,   416,   416,   416,   416,
     416,   416,   416,   416,   416,   416,   417,   418,   419,   420,
     420,   421,   421,   421,   421,   422,   422,   423,   423,   423,
     424,   424,   424,   425,   425,   425,   426,   427,   428,   428,
     429,   429,   429,   429,   429,   429,   430,   431,   431,   432,
     432,   433,   433,   434,   434,   434,   434,   434,   434,   434,
     435,   435,   436,   436,   437,   438,   438,   439,   439,   440,
     440,   441,   442,   442,   443,   444,   444,   445,   446,   446,
     447,   448,   448,   449,   449,   450,   450,   451,   451,   452,
     452,   453,   453,   454,   455,   455,   456,   456,   457,   457,
     457,   457,   457,   458,   457,   457,   457,   457,   459,   459,
     460,   460,   461,   461,   462,   462,   463,   463,   463,   464,
     464,   464,   464,   464,   465,   465,   465,   466,   466,   466,
     467,   467,   468,   468,   469,   469,   470,   470,   471,   471,
     472,   472,   472,   472,   473,   473,   473,   474,   474,   474,
     474,   474,   474,   475,   475,   475,   476,   476,   476,   476,
     477,   477,   478,   478,   479,   479,   479,   480,   480,   480,
     480,   481,   482,   482,   482,   483,   483,   484,   484,   484,
     484,   485,   485,   486,   486,   486,   486,   486,   486,   486,
     487,   487,   488,   488,   489,   489,   489,   489,   489,   490,
     490,   491,   491,   492,   492,   492,   492,   493,   493,   493,
     493,   494,   494,   495,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   497,   497,   498,   498,   498,   499,
     500,   500,   501,   502,   503,   504,   504,   505,   505,   506,
     506,   507,   507,   507,   508,   508,   508,   508,   508,   508,
     509,   509,   510,   510,   511,   512,   512,   513,   513,   514,
     514,   515,   515,   515,   515,   516,   516,   517,   517,   517,
     517,   518,   518,   519,   519,   520,   520,   520,   520,   521,
     521,   521,   521,   522,   522,   523,   523,   524,   525,   525,
     525,   525,   525,   525,   526,   527,   527,   528,   528,   529,
     530,   531,   531,   532,   532,   533,   534,   534,   534,   535,
     535,   535,   536,   536,   536,   536,   536,   537,   537,   538,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   540,
     541,   541,   541,   542,   543,   544,   544,   544,   545,   545,
     545,   545,   545,   546,   547,   547,   547,   547,   547,   547,
     547,   548,   549,   550,   551,   552,   552,   553,   554,   555,
     555,   556,   557,   557,   558,   559,   559,   559,   560,   560,
     560,   560,   560,   560,   560,   560,   560,   560,   561,   561,
     562,   562,   563,   564,   565,   565,   566,   567,   568,   568,
     569,   570,   571,   571,   572,   573,   573,   574,   574,   575,
     575,   576,   576,   577,   577,   578,   578,   579,   580,   580,
     581,   581,   582,   583,   583,   583,   584,   584,   585,   586,
     586,   587,   588,   588,   589,   589,   590,   590,   590,   591,
     591,   592,   592,   593,   593,   593,   593,   593,   594,   595,
     596,   597,   597,   597,   598,   598,   599,   599,   599,   599,
     599,   599,   599,   599,   600,   600,   600,   600,   601,   601,
     602,   603,   603,   604,   604,   604,   605,   605,   606,   606,
     607,   607,   608,   609,   609,   610,   610,   611,   611,   611,
     612,   612,   613,   613,   614,   614,   615,   615,   616,   616,
     617,   618,   618,   619,   619,   619,   620,   621,   621,   621,
     621,   622,   622,   623,   623,   624,   625,   626,   626,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   629,   629
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     1,     1,     2,     4,     3,     5,     4,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     1,     4,     3,     5,     4,     6,     4,     6,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     3,     1,     4,     4,     3,     4,     1,     3,     1,
       1,     1,     1,     1,     4,     5,     8,     9,     9,    10,
       1,     2,     1,     2,     6,     0,     1,     3,     3,     0,
       1,     1,     1,     2,     2,     0,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     2,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     4,     3,     7,     3,     7,     4,
       4,     3,     7,     1,     2,     2,     1,     2,     3,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     3,     1,
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
       4,     2,     2,     1,     1,     3,     1,     1,     1,     1,
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
       1,     1,     1,     1,     3,     1
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
  "\"'keys'\"", "\"'BOM_UTF8'\"", "RANGE_REDUCE", "ADDITIVE_REDUCE",
  "MULTIPLICATIVE_REDUCE", "UNION_REDUCE", "INTERSECT_EXCEPT_REDUCE",
  "QVARINDECLLIST_REDUCE", "COMMA_DOLLAR", "UNARY_PREC",
  "SEQUENCE_TYPE_REDUCE", "OCCURS_STAR", "OCCURS_PLUS", "OCCURS_HOOK",
  "STEP_REDUCE", "$accept", "Module", "ERROR", "ModuleWithoutBOM",
  "VersionDecl", "MainModule", "LibraryModule", "ModuleDecl",
  "SIND_DeclList", "SIND_Decl", "Setter", "BoundarySpaceDecl",
  "DefaultCollationDecl", "BaseURIDecl", "ConstructionDecl",
  "OrderingModeDecl", "EmptyOrderDecl", "CopyNamespacesDecl", "Import",
  "SchemaImport", "URILiteralList", "SchemaPrefix", "ModuleImport",
  "NamespaceDecl", "DefaultNamespaceDecl", "VFO_DeclList", "VFO_Decl",
  "DecimalFormatDecl", "DecimalFormatParamList", "DecimalFormatParam",
  "DecimalFormatParamName", "OptionDecl", "FTOptionDecl", "CtxItemDecl",
  "CtxItemDecl2", "CtxItemDecl3", "CtxItemDecl4", "VarDecl",
  "VarNameAndType", "AnnotationList", "Annotation",
  "AnnotationLiteralList", "FunctionDecl", "FunctionDecl2",
  "FunctionDeclSimple", "FunctionDeclUpdating", "FunctionSig", "ParamList",
  "Param", "CollectionDecl", "CollectionTypeDecl", "IndexDecl",
  "IndexKeyList", "IndexKeySpec", "IntegrityConstraintDecl", "QueryBody",
  "StatementsAndOptionalExprTop", "StatementsAndOptionalExpr",
  "StatementsAndExpr", "Statements", "Statement", "BlockStatement",
  "BlockExpr", "EnclosedStatementsAndOptionalExpr", "VarDeclStatement",
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
  "FTIgnoreOption", "URI_LITERAL", "NCNAME", "QNAME", "FUNCTION_NAME",
  "EQNAME", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       324,     0,    -1,   326,    -1,   309,   326,    -1,     1,     3,
      -1,   328,    -1,   327,   328,    -1,   329,    -1,   327,   329,
      -1,   214,   215,    29,   190,    -1,   214,   215,    29,   131,
      29,   190,    -1,   331,   190,   378,    -1,   348,   190,   378,
      -1,   331,   190,   348,   190,   378,    -1,   378,    -1,   331,
     325,   378,    -1,   348,   325,   378,    -1,   331,   190,   348,
     325,   378,    -1,   331,   325,   348,   190,   378,    -1,   330,
      -1,   330,   331,   190,    -1,   330,   348,   190,    -1,   330,
     331,   190,   348,   190,    -1,    34,   160,   626,   132,   625,
     190,    -1,   332,    -1,   331,   190,   332,    -1,   331,   325,
     332,    -1,   333,    -1,   341,    -1,   346,    -1,   347,    -1,
     355,    -1,   334,    -1,   335,    -1,   336,    -1,   337,    -1,
     338,    -1,   339,    -1,   340,    -1,   559,    -1,    33,    38,
     182,    -1,    33,    38,   195,    -1,    33,   113,   106,   625,
      -1,    33,    37,   625,    -1,    33,    40,   182,    -1,    33,
      40,   195,    -1,    33,    57,   169,    -1,    33,    57,   201,
      -1,    33,   113,   168,   127,   128,    -1,    33,   113,   168,
     127,   129,    -1,    33,    41,   182,   107,   148,    -1,    33,
      41,   182,   107,   165,    -1,    33,    41,   166,   107,   148,
      -1,    33,    41,   166,   107,   165,    -1,   342,    -1,   345,
      -1,    49,    24,     1,    -1,    49,    60,   625,    -1,    49,
      60,   344,   625,    -1,    49,    60,   625,    96,   343,    -1,
      49,    60,   344,   625,    96,   343,    -1,   625,    -1,   343,
     107,   625,    -1,   160,   626,   132,    -1,   113,    45,   160,
      -1,    49,    34,   625,    -1,    49,    34,   160,   626,   132,
     625,    -1,    49,    34,   625,    96,   343,    -1,    49,    34,
     160,   626,   132,   625,    96,   343,    -1,    33,   160,   626,
     132,   625,    -1,    33,   113,    45,   160,   625,    -1,    33,
     113,    47,   160,   625,    -1,   349,    -1,   348,   190,   349,
      -1,   348,   325,   349,    -1,   350,    -1,   354,    -1,   356,
      -1,   360,    -1,   365,    -1,   372,    -1,   374,    -1,   377,
      -1,    33,   113,    79,   351,    -1,    33,    79,   627,   351,
      -1,   352,    -1,   351,   352,    -1,   353,   132,   551,    -1,
      80,    -1,    88,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    89,    -1,    85,    -1,    86,    -1,    87,    -1,
      33,    56,   627,    29,    -1,    33,   260,   598,    -1,    33,
     111,   152,   357,    -1,    94,   536,   358,    -1,   358,    -1,
     359,    -1,   137,    -1,   137,   359,    -1,   142,   402,    -1,
      33,   361,   142,   402,    -1,    33,   361,   137,    -1,    33,
     361,   137,   142,   402,    -1,   112,   118,   627,    -1,   112,
     118,   627,   533,    -1,   362,   112,   118,   627,    -1,   362,
     112,   118,   627,   533,    -1,   363,    -1,   362,   363,    -1,
      26,    -1,    26,   156,   364,   187,    -1,    27,    -1,    27,
     156,   364,   187,    -1,   497,    -1,   364,   107,   497,    -1,
      33,   366,    -1,    33,   362,   366,    -1,   367,    -1,   368,
      -1,    47,   628,   369,   386,    -1,    47,   628,   369,   137,
      -1,    74,    47,   628,   369,   386,    -1,    74,    47,   628,
     369,   137,    -1,   156,   187,    -1,   156,   370,   187,    -1,
     156,   187,    94,   534,    -1,   156,   370,   187,    94,   534,
      -1,   371,    -1,   370,   107,   371,    -1,   118,   627,    -1,
     118,   627,   533,    -1,    33,   286,   627,    -1,    33,   286,
     627,    94,   373,    -1,    33,   362,   286,   627,    -1,    33,
     362,   286,   627,    94,   373,    -1,   539,    -1,   539,   535,
      -1,    33,   294,   627,   298,   226,   480,   170,   375,    -1,
      33,   362,   294,   627,   298,   226,   480,   170,   375,    -1,
     376,    -1,   375,   107,   376,    -1,   480,    -1,   480,   533,
      -1,   480,   437,    -1,   480,   533,   437,    -1,    33,   302,
     303,   627,   298,   286,   627,   118,   627,   304,   402,    -1,
      33,   302,   303,   627,   298,   286,   627,   224,   118,   627,
     304,   292,   305,   480,    -1,    33,   302,   303,   627,   298,
     286,   627,   306,   224,   118,   627,   304,   402,    -1,    33,
     302,   303,   627,   307,   305,   256,   286,   627,   224,   118,
     627,   305,   480,   198,   286,   627,   224,   118,   627,   305,
     480,    -1,   379,    -1,   381,    -1,   382,    -1,    -1,   381,
      -1,   382,    -1,    -1,   401,    -1,   382,   401,    -1,   383,
      -1,   382,   383,    -1,   384,    -1,   387,    -1,   390,    -1,
     391,    -1,   392,    -1,   393,    -1,   394,    -1,   395,    -1,
     397,    -1,   449,    -1,   445,    -1,   398,    -1,   153,   382,
     184,    -1,   153,   184,    -1,   153,   380,   184,    -1,   153,
     380,   184,    -1,   388,   190,    -1,   388,   107,   389,    -1,
     112,   389,    -1,   362,   112,   389,    -1,   118,   627,    -1,
     118,   627,   533,    -1,   118,   627,   142,   402,    -1,   118,
     627,   533,   142,   402,    -1,   118,   627,   142,   402,   190,
      -1,   403,   190,    -1,   239,   241,   402,   190,    -1,   242,
     156,   401,   187,   383,    -1,   237,   240,   190,    -1,   238,
     240,   190,    -1,   413,   396,    -1,   186,   383,    -1,    48,
     156,   401,   187,   197,   383,   126,   383,    -1,   243,   384,
     399,    -1,   400,    -1,   399,   400,    -1,   244,   571,   384,
      -1,   402,    -1,   401,   107,   402,    -1,   404,    -1,   441,
      -1,   448,    -1,   454,    -1,   567,    -1,   403,    -1,   455,
      -1,   438,    -1,   560,    -1,   561,    -1,   563,    -1,   562,
      -1,   564,    -1,   413,   405,    -1,   186,   402,    -1,    66,
     283,    -1,    71,   283,    -1,   216,    -1,   253,    -1,    55,
     253,    -1,   407,   423,    77,   402,    -1,   407,    77,   402,
      -1,    46,   406,   422,   408,   408,    -1,    46,   406,   422,
     408,    -1,    42,   118,   627,    -1,   414,    -1,   419,    -1,
     409,    -1,   411,    -1,   426,    -1,   431,    -1,   427,    -1,
     410,    -1,   411,    -1,   413,   412,    -1,    46,   118,   415,
      -1,   416,    -1,   415,   107,   118,   416,    -1,   627,   147,
     402,    -1,   627,    36,   127,   147,   402,    -1,   627,   533,
     147,   402,    -1,   627,   533,    36,   127,   147,   402,    -1,
     627,   417,   147,   402,    -1,   627,    36,   127,   417,   147,
     402,    -1,   627,   533,   417,   147,   402,    -1,   627,   533,
      36,   127,   417,   147,   402,    -1,   627,   418,   147,   402,
      -1,   627,   533,   418,   147,   402,    -1,   627,   417,   418,
     147,   402,    -1,   627,   533,   417,   418,   147,   402,    -1,
      96,   118,   627,    -1,   272,   118,   627,    -1,    51,   420,
      -1,   421,    -1,   420,   107,   421,    -1,   118,   627,   142,
     402,    -1,   118,   627,   533,   142,   402,    -1,   418,   142,
     402,    -1,   118,   627,   533,   418,   142,   402,    -1,   118,
     627,   147,   402,    -1,   118,   627,   533,   147,   402,    -1,
     424,    -1,   118,   627,    -1,   118,   627,   424,    -1,   417,
      -1,   417,   425,    -1,   425,    -1,    58,   118,   627,    53,
     118,   627,    -1,    53,   118,   627,    -1,    58,   118,   627,
      -1,   211,   402,    -1,   171,   170,   428,    -1,   429,    -1,
     428,   107,   429,    -1,   118,   627,    -1,   118,   627,   142,
     402,    -1,   118,   627,   533,   142,   402,    -1,   118,   627,
     533,   142,   402,   430,    -1,   118,   627,   142,   402,   430,
      -1,   118,   627,   430,    -1,   106,   625,    -1,   168,   170,
     432,    -1,    69,   168,   170,   432,    -1,   433,    -1,   432,
     107,   433,    -1,   402,    -1,   402,   434,    -1,   435,    -1,
     436,    -1,   437,    -1,   435,   436,    -1,   435,   437,    -1,
     436,   437,    -1,   435,   436,   437,    -1,    95,    -1,   116,
      -1,   127,   128,    -1,   127,   129,    -1,   106,   625,    -1,
      67,   118,   439,   188,   402,    -1,   135,   118,   439,   188,
     402,    -1,   440,    -1,   439,   107,   118,   440,    -1,   627,
     147,   402,    -1,   627,   533,   147,   402,    -1,    72,   156,
     401,   187,   442,   113,   186,   402,    -1,   443,    -1,   442,
     443,    -1,   444,   186,   402,    -1,   100,   402,    -1,   444,
     100,   402,    -1,    72,   156,   401,   187,   446,   113,   186,
     383,    -1,   447,    -1,   446,   447,    -1,   444,   186,   383,
      -1,    73,   156,   401,   187,   450,   113,   186,   402,    -1,
      73,   156,   401,   187,   450,   113,   118,   627,   186,   402,
      -1,    73,   156,   401,   187,   452,   113,   186,   383,    -1,
      73,   156,   401,   187,   450,   113,   118,   627,   186,   383,
      -1,   451,    -1,   450,   451,    -1,   100,   534,   186,   402,
      -1,   100,   118,   627,    94,   534,   186,   402,    -1,   453,
      -1,   452,   453,    -1,   100,   534,   186,   383,    -1,   100,
     118,   627,    94,   534,   186,   383,    -1,    48,   156,   401,
     187,   197,   402,   126,   402,    -1,   456,    -1,   455,   167,
     456,    -1,   457,    -1,   456,    92,   457,    -1,   459,    -1,
     459,   474,   459,    -1,   459,   475,   459,    -1,   459,   132,
     459,    -1,   459,   162,   459,    -1,    -1,   459,   157,   458,
     459,    -1,   459,   155,   459,    -1,   459,   143,   459,    -1,
     459,   141,   459,    -1,   460,    -1,   460,   248,    70,   572,
     461,    -1,   462,    -1,   462,    99,   460,    -1,    -1,   624,
      -1,   463,    -1,   463,   198,   463,    -1,   464,    -1,   463,
     176,   464,    -1,   463,   158,   464,    -1,   465,    -1,   464,
     193,   465,    -1,   464,   117,   465,    -1,   464,   146,   465,
      -1,   464,   159,   465,    -1,   466,    -1,   465,   200,   466,
      -1,   465,   209,   466,    -1,   467,    -1,   466,   150,   467,
      -1,   466,   136,   467,    -1,   468,    -1,   468,    50,   230,
     534,    -1,   469,    -1,   469,   199,    94,   534,    -1,   470,
      -1,   470,   101,    94,   532,    -1,   471,    -1,   471,   102,
      94,   532,    -1,   473,    -1,   472,   473,    -1,   176,    -1,
     158,    -1,   472,   176,    -1,   472,   158,    -1,   476,    -1,
     480,    -1,   477,    -1,   202,    -1,   207,    -1,   206,    -1,
     205,    -1,   204,    -1,   203,    -1,   151,    -1,   179,    -1,
     140,    -1,    75,   153,   381,   184,    -1,    75,   221,   153,
     381,   184,    -1,    75,   220,   153,   381,   184,    -1,    75,
      76,   549,   153,   381,   184,    -1,   478,   153,   184,    -1,
     478,   153,   401,   184,    -1,   479,    -1,   478,   479,    -1,
     177,   627,    17,    -1,   177,    18,    -1,   177,    19,    -1,
     481,    -1,   481,   482,    -1,   192,   482,    -1,   482,    -1,
     191,    -1,   483,    -1,   483,   191,   482,    -1,   483,   192,
     482,    -1,   484,    -1,   493,    -1,   485,    -1,   485,   494,
      -1,   488,    -1,   488,   494,    -1,   486,   490,    -1,   487,
      -1,   105,   122,    -1,   114,   122,    -1,    97,   122,    -1,
     189,   122,    -1,   115,   122,    -1,   139,   122,    -1,   138,
     122,    -1,   490,    -1,    98,   490,    -1,   489,   490,    -1,
     120,    -1,   172,   122,    -1,    90,   122,    -1,   181,   122,
      -1,   180,   122,    -1,    91,   122,    -1,   539,    -1,   491,
      -1,   627,    -1,   492,    -1,   193,    -1,    11,    -1,    12,
      -1,    20,    -1,   496,    -1,   493,   494,    -1,   493,   156,
     187,    -1,   493,   156,   505,   187,    -1,   495,    -1,   494,
     495,    -1,   154,   401,   185,    -1,   497,    -1,   499,    -1,
     500,    -1,   501,    -1,   504,    -1,   506,    -1,   502,    -1,
     503,    -1,   552,    -1,   385,    -1,   498,    -1,   551,    -1,
     110,    -1,   149,    -1,   124,    -1,   118,   627,    -1,   156,
     187,    -1,   156,   401,   187,    -1,   119,    -1,   169,   153,
     401,   184,    -1,   201,   153,   401,   184,    -1,   628,   156,
     187,    -1,   628,   156,   505,   187,    -1,   402,    -1,   505,
     107,   402,    -1,   507,    -1,   525,    -1,   508,    -1,   522,
      -1,   523,    -1,   157,   627,   512,   130,    -1,   157,   627,
     510,   512,   130,    -1,   157,   627,   512,   196,   194,   627,
     512,   196,    -1,   157,   627,   512,   196,   509,   194,   627,
     512,   196,    -1,   157,   627,   510,   512,   196,   194,   627,
     512,   196,    -1,   157,   627,   510,   512,   196,   509,   194,
     627,   512,   196,    -1,   520,    -1,   509,   520,    -1,   511,
      -1,   510,   511,    -1,    35,   627,   512,   132,   512,   513,
      -1,    -1,    35,    -1,   183,   514,   183,    -1,    93,   516,
      93,    -1,    -1,   515,    -1,   134,    -1,   518,    -1,   515,
     134,    -1,   515,   518,    -1,    -1,   517,    -1,   133,    -1,
     519,    -1,   517,   133,    -1,   517,   519,    -1,    28,    -1,
     521,    -1,     5,    -1,   521,    -1,   507,    -1,    10,    -1,
     524,    -1,   521,    -1,     9,    -1,   123,    -1,   125,    -1,
     153,   381,   184,    -1,   212,    30,   213,    -1,   212,   213,
      -1,   174,   626,   175,    -1,   174,   626,     8,    -1,   103,
       7,    -1,   526,    -1,   527,    -1,   528,    -1,   529,    -1,
     530,    -1,   531,    -1,    43,   153,   381,   184,    -1,    21,
     380,   184,    -1,    45,   153,   401,   184,   153,   380,   184,
      -1,    22,   380,   184,    -1,    97,   153,   401,   184,   153,
     380,   184,    -1,    70,   153,   381,   184,    -1,    39,   153,
     381,   184,    -1,    23,   380,   184,    -1,    59,   153,   401,
     184,   153,   380,   184,    -1,   538,    -1,   538,   144,    -1,
      94,   534,    -1,   536,    -1,   536,   535,    -1,   210,   156,
     187,    -1,   144,    -1,   193,    -1,   176,    -1,   538,    -1,
     539,    -1,   152,   156,   187,    -1,   555,    -1,   558,    -1,
     534,    -1,   537,   107,   534,    -1,   627,    -1,   541,    -1,
     547,    -1,   545,    -1,   548,    -1,   546,    -1,   544,    -1,
     543,    -1,   542,    -1,   540,    -1,   224,   156,   187,    -1,
      44,   156,   187,    -1,    44,   156,   547,   187,    -1,    44,
     156,   548,   187,    -1,    70,   156,   187,    -1,    39,   156,
     187,    -1,    59,   156,   187,    -1,    59,   156,   626,   187,
      -1,    59,   156,    29,   187,    -1,    97,   156,   187,    -1,
      97,   156,   627,   187,    -1,    97,   156,   627,   107,   549,
     187,    -1,    97,   156,   193,   187,    -1,    97,   156,   193,
     107,   549,   187,    -1,    61,   156,   627,   187,    -1,    45,
     156,   187,    -1,    45,   156,   627,   187,    -1,    45,   156,
     627,   107,   549,   187,    -1,    45,   156,   627,   107,   550,
     187,    -1,    45,   156,   193,   187,    -1,    45,   156,   193,
     107,   549,   187,    -1,    45,   156,   193,   107,   550,   187,
      -1,    62,   156,   627,   187,    -1,   627,    -1,   627,   144,
      -1,    29,    -1,   553,    -1,   554,    -1,   627,   145,   149,
      -1,    47,   369,   386,    -1,   556,    -1,   557,    -1,    47,
     156,   193,   187,    -1,    47,   156,   187,    94,   534,    -1,
      47,   156,   537,   187,    94,   534,    -1,   156,   536,   187,
      -1,    33,   219,   220,    -1,    33,   219,   221,    -1,    33,
     219,   222,    -1,   225,   224,   402,   232,   402,    -1,   225,
     224,   402,    94,   231,   232,   402,    -1,   225,   224,   402,
      94,   233,   232,   402,    -1,   225,   224,   402,   217,   402,
      -1,   225,   224,   402,   218,   402,    -1,   225,   226,   402,
     232,   402,    -1,   225,   226,   402,    94,   231,   232,   402,
      -1,   225,   226,   402,    94,   233,   232,   402,    -1,   225,
     226,   402,   217,   402,    -1,   225,   226,   402,   218,   402,
      -1,   223,   224,   402,    -1,   223,   226,   402,    -1,   228,
     224,   402,   236,   402,    -1,   228,   229,   230,   224,   402,
     236,   402,    -1,   227,   224,   402,    94,   402,    -1,   235,
     118,   565,   234,   402,   186,   402,    -1,   566,    -1,   565,
     107,   118,   566,    -1,   627,   142,   402,    -1,   243,   153,
     401,   184,   568,    -1,   569,    -1,   568,   569,    -1,   244,
     571,   570,    -1,   153,   401,   184,    -1,   491,    -1,   571,
     209,   491,    -1,   575,   573,    -1,    -1,   574,    -1,   593,
      -1,   574,   593,    -1,   576,    -1,   575,   261,   576,    -1,
     577,    -1,   576,   257,   577,    -1,   578,    -1,   577,   259,
     147,   578,    -1,   579,    -1,   258,   579,    -1,   583,   580,
     581,    -1,    -1,   598,    -1,    -1,   582,    -1,   281,   153,
     401,   184,    -1,   587,   584,    -1,   156,   572,   187,    -1,
     585,    -1,    -1,   620,    -1,   478,   153,   586,   184,    -1,
      -1,   572,    -1,   588,   589,    -1,   497,    -1,   153,   401,
     184,    -1,    -1,   590,    -1,   247,   591,    -1,   246,   592,
      -1,   269,    -1,    -1,    78,    -1,    -1,   285,    -1,   594,
      -1,   595,    -1,   596,    -1,   622,    -1,   619,    -1,   169,
      -1,   283,   463,   597,    -1,   252,   621,   597,    -1,   285,
      -1,   275,    -1,   268,    -1,   245,   599,    -1,   598,   245,
     599,    -1,   600,    -1,   601,    -1,   602,    -1,   617,    -1,
     603,    -1,   611,    -1,   604,    -1,   618,    -1,   100,   273,
      -1,   100,   262,    -1,   265,    -1,   280,    -1,   250,   273,
      -1,   250,   262,    -1,    56,   627,    29,    -1,   276,    -1,
      54,   276,    -1,   278,   605,    -1,   278,   156,   605,   606,
     187,    -1,    54,   278,    -1,   608,    -1,   113,    -1,    -1,
     107,   607,    -1,   608,    -1,   607,   107,   608,    -1,    96,
      29,   609,   610,    -1,    -1,   270,    29,    -1,    -1,   621,
     264,    -1,   277,   285,   612,   614,    -1,   277,   285,   113,
     614,    -1,    54,   277,   285,    -1,    96,    29,    -1,   156,
     613,   187,    -1,    29,    -1,   613,   107,    29,    -1,    -1,
     615,    -1,   616,    -1,   615,   616,    -1,   200,   612,    -1,
     136,   612,    -1,   263,    29,    -1,   282,    -1,    54,   282,
      -1,    96,   216,    -1,    96,   253,    -1,   254,   249,    -1,
     266,   621,   279,    -1,   255,   463,    -1,    96,   129,   463,
      -1,    96,    52,   463,    -1,   256,   463,   198,   463,    -1,
     271,   623,    -1,   251,   623,    -1,   274,    -1,   267,    -1,
     284,   249,   465,    -1,    29,    -1,    16,    -1,   627,    -1,
     628,    -1,    97,    -1,    39,    -1,    44,    -1,    45,    -1,
     152,    -1,    48,    -1,   224,    -1,    59,    -1,    61,    -1,
      62,    -1,    70,    -1,    73,    -1,    72,    -1,   210,    -1,
     242,    -1,   629,    -1,    24,    -1,   214,    -1,   127,    -1,
      38,    -1,   260,    -1,    37,    -1,   221,    -1,   220,    -1,
     146,    -1,    43,    -1,   258,    -1,   259,    -1,   273,    -1,
     262,    -1,   250,    -1,   284,    -1,   276,    -1,   278,    -1,
     277,    -1,   282,    -1,   254,    -1,   249,    -1,    78,    -1,
     216,    -1,   253,    -1,    52,    -1,   222,    -1,   235,    -1,
     301,    -1,   229,    -1,   202,    -1,   207,    -1,   206,    -1,
     205,    -1,   204,    -1,   203,    -1,    96,    -1,   111,    -1,
     112,    -1,   186,    -1,    46,    -1,    36,    -1,    66,    -1,
      71,    -1,    58,    -1,    53,    -1,    55,    -1,    77,    -1,
      42,    -1,   147,    -1,    51,    -1,   211,    -1,   170,    -1,
     171,    -1,   168,    -1,    69,    -1,    95,    -1,   116,    -1,
     128,    -1,   129,    -1,   106,    -1,    67,    -1,   135,    -1,
     188,    -1,   100,    -1,    94,    -1,   197,    -1,   126,    -1,
     167,    -1,    92,    -1,    50,    -1,   230,    -1,   101,    -1,
     198,    -1,   117,    -1,   159,    -1,   200,    -1,   150,    -1,
     136,    -1,    75,    -1,    76,    -1,   102,    -1,   199,    -1,
     151,    -1,   182,    -1,   195,    -1,   160,    -1,   137,    -1,
     131,    -1,   166,    -1,   148,    -1,   165,    -1,    33,    -1,
      40,    -1,    57,    -1,   113,    -1,    41,    -1,    56,    -1,
     215,    -1,    49,    -1,    60,    -1,    34,    -1,    47,    -1,
     272,    -1,   248,    -1,   281,    -1,   283,    -1,   252,    -1,
     266,    -1,   279,    -1,   271,    -1,   251,    -1,   265,    -1,
     280,    -1,   270,    -1,   264,    -1,   263,    -1,   247,    -1,
     246,    -1,   255,    -1,   256,    -1,   285,    -1,   275,    -1,
     274,    -1,   269,    -1,   267,    -1,   268,    -1,   228,    -1,
     234,    -1,   231,    -1,   225,    -1,   218,    -1,   217,    -1,
     219,    -1,   236,    -1,   226,    -1,   227,    -1,   233,    -1,
     223,    -1,   232,    -1,    65,    -1,    63,    -1,    74,    -1,
     169,    -1,   201,    -1,   241,    -1,   239,    -1,   240,    -1,
     237,    -1,   238,    -1,   243,    -1,   244,    -1,   245,    -1,
      64,    -1,   294,    -1,   292,    -1,   293,    -1,   298,    -1,
     299,    -1,   300,    -1,   295,    -1,   296,    -1,   297,    -1,
      79,    -1,    80,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    85,    -1,    86,    -1,    87,    -1,    88,    -1,
      89,    -1,   286,    -1,   287,    -1,   288,    -1,   289,    -1,
     290,    -1,   291,    -1,   302,    -1,   303,    -1,   304,    -1,
     305,    -1,   306,    -1,   307,    -1,   308,    -1,    90,    -1,
     105,    -1,   114,    -1,   172,    -1,   180,    -1,   189,    -1,
     138,    -1,    91,    -1,   115,    -1,   139,    -1,   181,    -1,
     625,   121,   626,    -1,    25,    -1
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
     816,   819,   822,   825,   827,   829,   832,   837,   841,   847,
     852,   856,   858,   860,   862,   864,   866,   868,   870,   872,
     874,   877,   881,   883,   888,   892,   898,   903,   910,   915,
     922,   928,   936,   941,   947,   953,   960,   964,   968,   971,
     973,   977,   982,   988,   992,   999,  1004,  1010,  1012,  1015,
    1019,  1021,  1024,  1026,  1033,  1037,  1041,  1044,  1048,  1050,
    1054,  1057,  1062,  1068,  1075,  1081,  1085,  1088,  1092,  1097,
    1099,  1103,  1105,  1108,  1110,  1112,  1114,  1117,  1120,  1123,
    1127,  1129,  1131,  1134,  1137,  1140,  1146,  1152,  1154,  1159,
    1163,  1168,  1177,  1179,  1182,  1186,  1189,  1193,  1202,  1204,
    1207,  1211,  1220,  1231,  1240,  1251,  1253,  1256,  1261,  1269,
    1271,  1274,  1279,  1287,  1296,  1298,  1302,  1304,  1308,  1310,
    1314,  1318,  1322,  1326,  1327,  1332,  1336,  1340,  1344,  1346,
    1352,  1354,  1358,  1359,  1361,  1363,  1367,  1369,  1373,  1377,
    1379,  1383,  1387,  1391,  1395,  1397,  1401,  1405,  1407,  1411,
    1415,  1417,  1422,  1424,  1429,  1431,  1436,  1438,  1443,  1445,
    1448,  1450,  1452,  1455,  1458,  1460,  1462,  1464,  1466,  1468,
    1470,  1472,  1474,  1476,  1478,  1480,  1482,  1487,  1493,  1499,
    1506,  1510,  1515,  1517,  1520,  1524,  1527,  1530,  1532,  1535,
    1538,  1540,  1542,  1544,  1548,  1552,  1554,  1556,  1558,  1561,
    1563,  1566,  1569,  1571,  1574,  1577,  1580,  1583,  1586,  1589,
    1592,  1594,  1597,  1600,  1602,  1605,  1608,  1611,  1614,  1617,
    1619,  1621,  1623,  1625,  1627,  1629,  1631,  1633,  1635,  1638,
    1642,  1647,  1649,  1652,  1656,  1658,  1660,  1662,  1664,  1666,
    1668,  1670,  1672,  1674,  1676,  1678,  1680,  1682,  1684,  1686,
    1689,  1692,  1696,  1698,  1703,  1708,  1712,  1717,  1719,  1723,
    1725,  1727,  1729,  1731,  1733,  1738,  1744,  1753,  1763,  1773,
    1784,  1786,  1789,  1791,  1794,  1801,  1802,  1804,  1808,  1812,
    1813,  1815,  1817,  1819,  1822,  1825,  1826,  1828,  1830,  1832,
    1835,  1838,  1840,  1842,  1844,  1846,  1848,  1850,  1852,  1854,
    1856,  1858,  1860,  1864,  1868,  1871,  1875,  1879,  1882,  1884,
    1886,  1888,  1890,  1892,  1894,  1899,  1903,  1911,  1915,  1923,
    1928,  1933,  1937,  1945,  1947,  1950,  1953,  1955,  1958,  1962,
    1964,  1966,  1968,  1970,  1972,  1976,  1978,  1980,  1982,  1986,
    1988,  1990,  1992,  1994,  1996,  1998,  2000,  2002,  2004,  2006,
    2010,  2014,  2019,  2024,  2028,  2032,  2036,  2041,  2046,  2050,
    2055,  2062,  2067,  2074,  2079,  2083,  2088,  2095,  2102,  2107,
    2114,  2121,  2126,  2128,  2131,  2133,  2135,  2137,  2141,  2145,
    2147,  2149,  2154,  2160,  2167,  2171,  2175,  2179,  2183,  2189,
    2197,  2205,  2211,  2217,  2223,  2231,  2239,  2245,  2251,  2255,
    2259,  2265,  2273,  2279,  2287,  2289,  2294,  2298,  2304,  2306,
    2309,  2313,  2317,  2319,  2323,  2326,  2327,  2329,  2331,  2334,
    2336,  2340,  2342,  2346,  2348,  2353,  2355,  2358,  2362,  2363,
    2365,  2366,  2368,  2373,  2376,  2380,  2382,  2383,  2385,  2390,
    2391,  2393,  2396,  2398,  2402,  2403,  2405,  2408,  2411,  2413,
    2414,  2416,  2417,  2419,  2421,  2423,  2425,  2427,  2429,  2431,
    2435,  2439,  2441,  2443,  2445,  2448,  2452,  2454,  2456,  2458,
    2460,  2462,  2464,  2466,  2468,  2471,  2474,  2476,  2478,  2481,
    2484,  2488,  2490,  2493,  2496,  2502,  2505,  2507,  2509,  2510,
    2513,  2515,  2519,  2524,  2525,  2528,  2529,  2532,  2537,  2542,
    2546,  2549,  2553,  2555,  2559,  2560,  2562,  2564,  2567,  2570,
    2573,  2576,  2578,  2581,  2584,  2587,  2590,  2594,  2597,  2601,
    2605,  2610,  2613,  2616,  2618,  2620,  2624,  2626,  2628,  2630,
    2632,  2634,  2636,  2638,  2640,  2642,  2644,  2646,  2648,  2650,
    2652,  2654,  2656,  2658,  2660,  2662,  2664,  2666,  2668,  2670,
    2672,  2674,  2676,  2678,  2680,  2682,  2684,  2686,  2688,  2690,
    2692,  2694,  2696,  2698,  2700,  2702,  2704,  2706,  2708,  2710,
    2712,  2714,  2716,  2718,  2720,  2722,  2724,  2726,  2728,  2730,
    2732,  2734,  2736,  2738,  2740,  2742,  2744,  2746,  2748,  2750,
    2752,  2754,  2756,  2758,  2760,  2762,  2764,  2766,  2768,  2770,
    2772,  2774,  2776,  2778,  2780,  2782,  2784,  2786,  2788,  2790,
    2792,  2794,  2796,  2798,  2800,  2802,  2804,  2806,  2808,  2810,
    2812,  2814,  2816,  2818,  2820,  2822,  2824,  2826,  2828,  2830,
    2832,  2834,  2836,  2838,  2840,  2842,  2844,  2846,  2848,  2850,
    2852,  2854,  2856,  2858,  2860,  2862,  2864,  2866,  2868,  2870,
    2872,  2874,  2876,  2878,  2880,  2882,  2884,  2886,  2888,  2890,
    2892,  2894,  2896,  2898,  2900,  2902,  2904,  2906,  2908,  2910,
    2912,  2914,  2916,  2918,  2920,  2922,  2924,  2926,  2928,  2930,
    2932,  2934,  2936,  2938,  2940,  2942,  2944,  2946,  2948,  2950,
    2952,  2954,  2956,  2958,  2960,  2962,  2964,  2966,  2968,  2970,
    2972,  2974,  2976,  2978,  2980,  2982,  2984,  2986,  2988,  2990,
    2992,  2994,  2996,  2998,  3000,  3002,  3004,  3006,  3008,  3010,
    3012,  3014,  3016,  3018,  3020,  3022,  3024,  3026,  3028,  3030,
    3032,  3034,  3036,  3038,  3040,  3042,  3044,  3046,  3048,  3050,
    3052,  3054,  3056,  3058,  3060,  3064
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   994,   994,   995,  1004,  1013,  1019,  1027,  1033,  1044,
    1049,  1057,  1064,  1071,  1080,  1087,  1095,  1103,  1111,  1122,
    1127,  1134,  1141,  1153,  1163,  1170,  1177,  1189,  1190,  1191,
    1192,  1193,  1198,  1199,  1200,  1201,  1202,  1203,  1204,  1207,
    1212,  1217,  1225,  1233,  1241,  1246,  1254,  1259,  1267,  1272,
    1280,  1287,  1294,  1301,  1311,  1313,  1316,  1326,  1331,  1339,
    1347,  1358,  1365,  1376,  1381,  1389,  1396,  1403,  1412,  1425,
    1433,  1440,  1450,  1457,  1464,  1475,  1476,  1477,  1478,  1479,
    1480,  1481,  1482,  1487,  1493,  1502,  1509,  1519,  1529,  1530,
    1531,  1532,  1533,  1534,  1535,  1536,  1537,  1538,  1543,  1551,
    1559,  1567,  1574,  1582,  1589,  1594,  1602,  1610,  1625,  1640,
    1658,  1663,  1671,  1679,  1690,  1695,  1704,  1709,  1716,  1721,
    1731,  1736,  1745,  1751,  1764,  1769,  1777,  1788,  1803,  1815,
    1830,  1835,  1840,  1845,  1853,  1860,  1871,  1876,  1886,  1893,
    1900,  1907,  1917,  1921,  1931,  1939,  1950,  1956,  1965,  1970,
    1977,  1984,  1995,  2005,  2015,  2025,  2043,  2063,  2068,  2073,
    2080,  2085,  2090,  2097,  2102,  2114,  2121,  2133,  2134,  2135,
    2136,  2137,  2138,  2139,  2141,  2142,  2143,  2144,  2145,  2150,
    2155,  2163,  2180,  2188,  2196,  2203,  2210,  2220,  2232,  2245,
    2257,  2273,  2281,  2289,  2297,  2312,  2317,  2325,  2339,  2356,
    2381,  2389,  2396,  2407,  2417,  2422,  2437,  2438,  2439,  2440,
    2441,  2442,  2447,  2448,  2451,  2452,  2453,  2454,  2455,  2460,
    2474,  2482,  2487,  2495,  2500,  2505,  2513,  2522,  2534,  2544,
    2557,  2565,  2566,  2567,  2572,  2573,  2574,  2575,  2576,  2581,
    2588,  2598,  2606,  2613,  2623,  2633,  2643,  2653,  2663,  2673,
    2683,  2693,  2704,  2713,  2723,  2733,  2749,  2758,  2767,  2775,
    2781,  2793,  2801,  2811,  2819,  2831,  2837,  2848,  2850,  2854,
    2862,  2866,  2871,  2875,  2879,  2883,  2893,  2901,  2908,  2914,
    2924,  2928,  2932,  2940,  2948,  2956,  2968,  2976,  2982,  2992,
    2998,  3008,  3012,  3022,  3028,  3034,  3040,  3049,  3058,  3067,
    3080,  3084,  3092,  3098,  3108,  3116,  3125,  3138,  3145,  3157,
    3161,  3173,  3180,  3186,  3195,  3202,  3208,  3219,  3226,  3232,
    3241,  3250,  3257,  3268,  3275,  3287,  3293,  3305,  3311,  3322,
    3328,  3339,  3345,  3356,  3365,  3369,  3378,  3382,  3390,  3394,
    3404,  3411,  3420,  3430,  3429,  3443,  3452,  3461,  3474,  3478,
    3490,  3494,  3502,  3505,  3512,  3516,  3525,  3529,  3533,  3542,
    3546,  3552,  3558,  3564,  3575,  3579,  3583,  3591,  3595,  3601,
    3611,  3615,  3625,  3629,  3639,  3643,  3653,  3657,  3667,  3671,
    3679,  3683,  3687,  3691,  3701,  3705,  3709,  3717,  3721,  3725,
    3729,  3733,  3737,  3745,  3749,  3753,  3761,  3765,  3769,  3773,
    3784,  3790,  3800,  3806,  3816,  3820,  3824,  3862,  3866,  3876,
    3886,  3899,  3908,  3918,  3922,  3931,  3935,  3944,  3950,  3958,
    3964,  3976,  3982,  3992,  3996,  4000,  4004,  4008,  4014,  4020,
    4028,  4032,  4040,  4044,  4055,  4059,  4063,  4069,  4073,  4087,
    4091,  4099,  4103,  4113,  4117,  4121,  4125,  4134,  4138,  4142,
    4146,  4154,  4160,  4170,  4178,  4182,  4186,  4190,  4194,  4198,
    4202,  4206,  4210,  4220,  4228,  4232,  4240,  4247,  4254,  4265,
    4273,  4277,  4285,  4293,  4301,  4355,  4359,  4372,  4378,  4388,
    4392,  4400,  4404,  4408,  4416,  4426,  4436,  4446,  4456,  4466,
    4481,  4487,  4498,  4504,  4515,  4526,  4528,  4532,  4537,  4547,
    4550,  4557,  4563,  4569,  4577,  4590,  4593,  4600,  4606,  4612,
    4619,  4630,  4634,  4644,  4648,  4658,  4662,  4666,  4671,  4680,
    4686,  4692,  4698,  4706,  4711,  4719,  4724,  4732,  4740,  4745,
    4750,  4755,  4760,  4765,  4774,  4782,  4786,  4803,  4807,  4815,
    4823,  4831,  4835,  4843,  4849,  4859,  4867,  4871,  4875,  4910,
    4916,  4922,  4932,  4936,  4940,  4944,  4948,  4955,  4961,  4971,
    4979,  4983,  4987,  4991,  4995,  4999,  5003,  5007,  5011,  5019,
    5027,  5031,  5035,  5045,  5053,  5061,  5065,  5069,  5077,  5081,
    5087,  5093,  5097,  5107,  5115,  5119,  5125,  5134,  5143,  5149,
    5155,  5165,  5182,  5189,  5204,  5240,  5244,  5252,  5260,  5272,
    5276,  5284,  5292,  5296,  5307,  5324,  5330,  5336,  5346,  5350,
    5356,  5362,  5366,  5372,  5376,  5382,  5388,  5395,  5405,  5410,
    5418,  5424,  5434,  5456,  5465,  5471,  5484,  5498,  5505,  5511,
    5521,  5530,  5538,  5544,  5562,  5571,  5574,  5581,  5586,  5594,
    5598,  5605,  5609,  5616,  5620,  5627,  5631,  5640,  5653,  5656,
    5664,  5667,  5675,  5683,  5691,  5695,  5703,  5706,  5714,  5726,
    5729,  5737,  5749,  5755,  5765,  5768,  5776,  5780,  5784,  5792,
    5795,  5803,  5806,  5814,  5818,  5822,  5826,  5830,  5838,  5846,
    5858,  5870,  5874,  5878,  5886,  5892,  5902,  5906,  5910,  5914,
    5918,  5922,  5926,  5930,  5938,  5942,  5946,  5950,  5958,  5964,
    5974,  5984,  5988,  5996,  6006,  6017,  6024,  6028,  6036,  6039,
    6046,  6051,  6060,  6070,  6073,  6081,  6084,  6092,  6101,  6108,
    6118,  6122,  6129,  6135,  6145,  6148,  6155,  6160,  6172,  6180,
    6192,  6200,  6204,  6212,  6216,  6220,  6228,  6236,  6240,  6244,
    6248,  6256,  6264,  6276,  6280,  6288,  6301,  6305,  6306,  6319,
    6320,  6321,  6322,  6323,  6324,  6325,  6326,  6327,  6328,  6329,
    6330,  6331,  6332,  6333,  6334,  6338,  6339,  6340,  6341,  6342,
    6343,  6344,  6345,  6346,  6347,  6348,  6349,  6350,  6351,  6352,
    6353,  6354,  6355,  6356,  6357,  6358,  6359,  6360,  6361,  6362,
    6363,  6364,  6365,  6366,  6367,  6368,  6369,  6370,  6371,  6372,
    6373,  6374,  6375,  6376,  6377,  6378,  6379,  6380,  6381,  6382,
    6383,  6384,  6385,  6386,  6387,  6388,  6389,  6390,  6391,  6392,
    6393,  6394,  6395,  6396,  6397,  6398,  6399,  6400,  6401,  6402,
    6403,  6404,  6405,  6406,  6407,  6408,  6409,  6410,  6411,  6412,
    6413,  6414,  6415,  6416,  6417,  6418,  6419,  6420,  6421,  6422,
    6423,  6424,  6425,  6426,  6427,  6428,  6429,  6430,  6431,  6432,
    6433,  6434,  6435,  6436,  6437,  6438,  6439,  6440,  6441,  6442,
    6443,  6444,  6445,  6446,  6447,  6448,  6449,  6450,  6451,  6452,
    6453,  6454,  6455,  6456,  6457,  6458,  6459,  6460,  6461,  6462,
    6463,  6464,  6465,  6466,  6467,  6468,  6469,  6470,  6471,  6472,
    6473,  6474,  6475,  6476,  6477,  6478,  6479,  6480,  6481,  6482,
    6483,  6484,  6485,  6486,  6487,  6488,  6489,  6490,  6491,  6492,
    6493,  6494,  6495,  6496,  6497,  6498,  6499,  6500,  6501,  6502,
    6503,  6504,  6505,  6506,  6507,  6508,  6509,  6510,  6511,  6512,
    6513,  6514,  6515,  6516,  6517,  6518,  6519,  6520,  6521,  6522,
    6523,  6524,  6525,  6526,  6527,  6528,  6529,  6530,  6531,  6532,
    6533,  6534,  6535,  6536,  6541,  6548
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
     315,   316,   317,   318,   319,   320,   321,   322
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 13005;
  const int xquery_parser::yynnts_ = 307;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 571;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 323;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 577;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 16084 "/home/markos/zorba/repo/new-groupby/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6552 "/home/markos/zorba/repo/new-groupby/src/compiler/parser/xquery_parser.y"


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

