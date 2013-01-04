
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
#line 87 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"


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
#line 79 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 909 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 1034 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 109 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"

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
#line 178 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
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
#line 907 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 285 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 124: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 906 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 294 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 149: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 905 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 303 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 312 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 321 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 330 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 339 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 348 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 357 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 366 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 375 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 384 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 393 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 402 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 411 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 420 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 429 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 438 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 447 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 456 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 465 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 474 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 483 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 492 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 501 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 510 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 519 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 528 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 537 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 546 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 555 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 564 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 573 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 582 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 591 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 600 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 609 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 618 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 627 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 636 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 645 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 654 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 663 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 672 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 681 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 690 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 699 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 708 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 717 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 726 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 735 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 744 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 753 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 762 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 771 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 780 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 789 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 825 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 834 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 843 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 861 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 870 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 897 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 906 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 915 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 933 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 942 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 951 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 960 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 969 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 978 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 987 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 996 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1005 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1014 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1023 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1032 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1041 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1050 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1059 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1068 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1077 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1086 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1095 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1104 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1113 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1122 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1131 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1140 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1149 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1158 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1167 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1176 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1185 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1194 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1203 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1212 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1221 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1230 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1239 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1248 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1257 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1266 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1275 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1284 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1293 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1302 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1311 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1320 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1329 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1338 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1347 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1356 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1365 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1374 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1383 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1392 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1401 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1410 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1419 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1428 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1437 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1446 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1455 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1464 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1473 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1482 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1491 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1500 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1509 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1518 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1527 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1536 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1545 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1554 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1563 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1572 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1581 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1590 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1599 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1608 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1617 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1626 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1635 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1644 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1653 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1662 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1671 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1680 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1689 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1698 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1707 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1716 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1725 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1734 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1743 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1752 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1761 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1770 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1779 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1788 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1797 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1806 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1815 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1824 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1833 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1842 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1851 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1860 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1869 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1878 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1887 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1896 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1905 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1914 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1923 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1932 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1941 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1950 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1959 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1968 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1977 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1986 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1995 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2004 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2013 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2022 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2031 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2040 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2049 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2058 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2067 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2076 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2085 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2094 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2103 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2112 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2121 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2130 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2139 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2148 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2157 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2166 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2175 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2184 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2193 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2202 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2211 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2220 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2229 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2238 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2247 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2256 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2265 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2274 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2283 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2292 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2301 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2310 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2319 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2328 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2337 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2346 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2355 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2364 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2373 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2382 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2391 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2400 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2409 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2418 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2427 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2436 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2445 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2454 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2463 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2472 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2481 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2490 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2499 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2508 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2517 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2526 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2535 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2544 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 614: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2553 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 615: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2562 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2571 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2580 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2589 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2598 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2607 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2616 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 630: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2625 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 631: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2634 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 632: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2643 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 633: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2652 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 634: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2661 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 635: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2670 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 636: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2679 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 637: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2688 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 638: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2697 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 639: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2706 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2715 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 641: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2724 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 642: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2733 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 643: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2742 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 644: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2751 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 645: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2760 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 646: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2769 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 647: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2778 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 654: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2787 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 655: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2796 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 656: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2805 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
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
#line 140 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 553 of lalr1.cc  */
#line 2890 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1052 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 1056 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 1060 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1071 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1080 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1086 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1094 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1100 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1111 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1116 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1124 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1131 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1138 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1147 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1154 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1162 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1170 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1178 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1189 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1194 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1201 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1208 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1220 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1230 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 1237 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 1244 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 1279 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1284 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1292 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1300 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1308 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1313 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1321 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1326 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1334 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1339 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1347 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1352 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 1357 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 1362 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1375 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1385 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1390 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1398 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1406 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1417 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1424 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1435 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1440 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1448 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1455 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1462 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1471 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 1484 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1492 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1499 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1509 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1516 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1523 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1546 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1552 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1561 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1568 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1578 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1587 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1588 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1589 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1590 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1591 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1592 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1593 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1594 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1595 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1596 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1602 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1610 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1618 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1626 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1633 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1641 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1648 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1653 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1661 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1669 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 1683 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 1697 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 1714 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1719 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1727 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1735 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1746 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1751 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1760 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1765 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1772 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1777 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1787 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1792 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1801 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1807 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1820 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1825 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1833 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 1844 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 1859 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 1871 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 1886 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1891 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1896 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1901 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1909 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1916 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1927 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1932 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1942 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1951 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1960 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1969 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1981 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1985 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1991 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1995 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 2005 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);

      static_cast<AST_IndexDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(8) - (1)].sval)) );
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 2015 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                             (yysemantic_stack_[(9) - (7)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                             static_cast<AnnotationListParsenode*>((yysemantic_stack_[(9) - (2)].node)));

      static_cast<AST_IndexDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(9) - (1)].sval)) );
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 2028 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 2034 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 2043 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 2048 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 2055 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 2062 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 2074 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2084 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2094 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2105 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2121 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2141 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2145 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2149 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2157 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2161 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2165 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2173 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2178 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2190 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2197 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2226 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2231 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2239 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2256 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2264 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 2272 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 2279 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 2286 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 2297 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2306 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2315 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2324 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2337 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 2345 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 2353 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 2361 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2376 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 2381 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2389 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2403 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2420 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2445 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2453 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2460 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 2471 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 2481 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 2486 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2498 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(4) - (1)].expr); // to prevent the Bison warning
      (yyval.expr) = (yysemantic_stack_[(4) - (3)].expr); // to prevent the Bison warning
      error((yylocation_stack_[(4) - (2)]), "syntax error, unexpected ExprSingle (missing comma \",\" between expressions?)");
      delete (yysemantic_stack_[(4) - (1)].expr); // these need to be deleted here because the parser deallocator will skip them
      delete (yysemantic_stack_[(4) - (3)].expr);
      YYERROR;
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 2507 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2550 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2564 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2572 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2577 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2585 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2590 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2595 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2603 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2612 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2624 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2634 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2647 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2671 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2678 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2688 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2694 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2703 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL; // to prevent the Bison warning
      error((yylocation_stack_[(2) - (2)]), ""); // the error message is already set in the driver's parseError member
      YYERROR;
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2713 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2720 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2728 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2740 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2750 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2760 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2770 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2780 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2790 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2800 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2810 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2821 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2830 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2840 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2850 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2866 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2875 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2884 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2892 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2898 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2910 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2918 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2928 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2936 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 2948 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2954 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2967 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2971 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2979 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2983 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2992 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2996 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 3000 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 3010 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 3018 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 3025 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 3031 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 3041 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3045 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3049 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 3057 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 3065 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 3073 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 3085 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3093 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3099 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3109 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3115 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3125 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3129 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3139 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3145 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3151 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3157 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 3166 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 3175 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 3184 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 3197 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3201 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3209 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3215 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3225 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3233 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 3242 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 3255 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3262 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3274 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3278 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3290 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3297 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3303 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3312 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3319 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3325 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3336 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3343 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3349 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3358 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3367 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3374 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 3385 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3392 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 3404 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3410 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3422 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3428 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3439 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3445 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3456 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3462 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3473 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3482 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3486 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3495 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3499 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3507 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3511 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 3521 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3528 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 3537 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 3546 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3551 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 3560 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 3569 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 3578 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 3591 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3595 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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
#line 3607 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3611 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3618 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3622 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3629 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3633 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3642 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3646 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3650 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3658 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3662 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3668 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3674 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3680 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3690 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3694 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3698 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3706 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3710 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3716 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3726 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3730 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3740 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3744 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3754 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3758 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3768 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3772 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3782 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3786 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3795 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3799 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3807 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3811 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3815 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3819 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3829 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3833 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3837 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3844 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3849 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3857 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3861 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3865 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3869 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3873 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3877 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3885 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3889 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3893 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3901 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3905 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3909 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3913 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3940 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3946 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3956 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3960 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3964 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 4002 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 4006 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 4016 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 4026 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 4039 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4048 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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

  case 431:

/* Line 678 of lalr1.cc  */
#line 4058 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4062 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4071 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4075 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4084 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4090 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4098 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4104 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4116 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4122 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4132 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4136 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4140 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4144 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4148 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4154 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4160 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4168 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4172 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4180 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4184 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4195 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4199 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4203 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4209 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4213 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4227 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4231 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4239 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4243 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4253 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4257 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4261 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4265 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4274 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4278 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4282 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4286 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4294 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4300 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4310 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4318 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4322 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4326 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4330 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4334 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4338 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4342 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4346 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4350 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4354 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4359 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4363 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4367 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4371 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4379 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4383 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4391 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4398 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4405 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4416 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4424 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4428 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4436 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4444 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4452 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4506 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4510 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4523 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4529 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4539 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4543 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4551 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4555 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4559 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4567 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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

  case 507:

/* Line 678 of lalr1.cc  */
#line 4577 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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

  case 508:

/* Line 678 of lalr1.cc  */
#line 4587 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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

  case 509:

/* Line 678 of lalr1.cc  */
#line 4604 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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

  case 510:

/* Line 678 of lalr1.cc  */
#line 4621 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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

  case 511:

/* Line 678 of lalr1.cc  */
#line 4638 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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

  case 512:

/* Line 678 of lalr1.cc  */
#line 4660 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4666 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4677 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4683 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4694 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4711 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4716 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4725 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4729 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4736 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4742 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4748 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4756 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4768 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4772 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4779 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4785 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4791 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4798 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4809 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4813 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4823 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4827 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4837 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4841 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4845 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4850 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4859 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4865 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4871 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4877 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4885 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4890 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4898 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4903 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4911 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4919 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4929 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4934 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4939 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4944 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4953 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4961 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4965 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4982 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4986 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4994 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 5002 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 5010 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5014 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5022 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5030 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5034 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5038 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5073 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5079 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5085 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5095 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5099 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5103 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5107 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5111 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5115 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5119 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5126 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5132 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5142 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5150 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5158 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5162 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5166 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5170 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5174 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5178 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5182 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5186 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5190 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5198 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5206 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5210 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5214 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5224 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5232 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5240 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5244 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5248 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5256 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5260 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5266 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5272 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5276 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5286 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5294 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5298 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5304 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5313 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5322 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5328 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5334 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5344 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5361 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5368 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5383 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5419 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5423 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5431 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5439 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5451 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5455 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5463 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5471 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5475 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5486 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5503 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5509 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5515 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5525 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5529 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5535 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5541 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5545 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5551 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5555 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5561 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5567 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5574 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5584 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5589 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5597 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5603 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5613 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5635 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5644 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5650 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5663 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5677 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5684 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5690 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5700 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5709 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5717 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5723 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5741 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5749 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5753 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5760 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5765 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5773 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5777 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5784 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5788 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5795 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5799 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5806 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5810 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5819 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5831 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5835 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5842 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5846 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5854 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5862 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5870 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5874 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5881 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5885 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5893 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5904 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5908 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5916 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5928 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5934 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5943 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5947 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5955 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5959 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5963 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5970 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5974 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5981 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5985 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5993 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5997 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 6001 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 6005 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 6009 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 6017 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 6025 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 6037 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 6049 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 6053 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 6057 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 6065 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 6071 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 6081 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 6085 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 6089 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 6093 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 6097 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 6101 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 6105 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 6109 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6117 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6121 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6125 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 6129 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6137 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6143 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 6153 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 6163 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 6167 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 6175 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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

  case 727:

/* Line 678 of lalr1.cc  */
#line 6185 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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

  case 728:

/* Line 678 of lalr1.cc  */
#line 6196 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 6203 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6207 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6214 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 6218 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 6225 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 6230 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6239 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6248 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6252 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 6259 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 6263 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6271 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 6280 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 6287 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 6297 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6301 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 6308 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 6314 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6323 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6327 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 6334 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6339 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6351 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6359 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6371 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6379 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6383 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6391 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6395 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6399 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6407 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6415 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 6419 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6423 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6427 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6435 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 6443 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6455 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 6459 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 6467 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6481 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 6485 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 6492 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6497 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6505 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 6510 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 6519 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6527 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 6533 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 6543 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 6549 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (3)].node));
          (yyval.expr) = new JSONObjectInsertExpr(
              LOC((yyloc)),
              new JSONDirectObjectConstructor(
                  LOC((yyloc)),
                  jpl),
              (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 6559 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 6566 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6573 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation =
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(3) - (3)].expr));

          if (lDynamicFunctionInvocation == NULL)
          {
            error((yylocation_stack_[(3) - (3)]), "An object invocation is expected. A filter was found instead.");
            YYERROR;
          }

          if (lDynamicFunctionInvocation->getArgList()->size() != 1)
          {
            error((yylocation_stack_[(3) - (3)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            YYERROR;
          }

          (yyval.expr) = new JSONDeleteExpr(
                LOC((yyloc)),
                lDynamicFunctionInvocation->getPrimaryExpr(),
                lDynamicFunctionInvocation->getArgList()->operator[](0));
        }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 6598 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation =
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(5) - (3)].expr));

          if(lDynamicFunctionInvocation == NULL)
          {
            error((yylocation_stack_[(5) - (3)]), "An object invocation is expected. A filter was found instead.");
            delete (yysemantic_stack_[(5) - (5)].expr);
            YYERROR;
          }

          if (lDynamicFunctionInvocation->getArgList()->size() != 1)
          {
            error((yylocation_stack_[(5) - (3)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            delete (yysemantic_stack_[(5) - (5)].expr);
            YYERROR;
          }

          (yyval.expr) = new JSONRenameExpr(
                LOC((yyloc)),
                lDynamicFunctionInvocation->getPrimaryExpr(),
                lDynamicFunctionInvocation->getArgList()->operator[](0),
                (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 6626 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation =
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(7) - (5)].expr));

          if(lDynamicFunctionInvocation == NULL)
          {
            error((yylocation_stack_[(7) - (3)]), "An object invocation is expected. A filter was found instead.");
            delete (yysemantic_stack_[(7) - (7)].expr);
            YYERROR;
          }

          if (lDynamicFunctionInvocation->getArgList()->size() != 1)
          {
            error((yylocation_stack_[(7) - (3)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            delete (yysemantic_stack_[(7) - (7)].expr);
            YYERROR;
          }

          (yyval.expr) = new JSONReplaceExpr(
                LOC((yyloc)),
                lDynamicFunctionInvocation->getPrimaryExpr(),
                lDynamicFunctionInvocation->getArgList()->operator[](0),
                (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6654 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 6658 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 6662 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 6669 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6676 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6683 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6700 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
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

  case 795:

/* Line 678 of lalr1.cc  */
#line 6713 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6714 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6715 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6716 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6717 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6718 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6719 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6720 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6721 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6722 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6723 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6724 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6725 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6726 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6727 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6732 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6733 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6734 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6735 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6736 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6737 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6738 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6739 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6740 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6741 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6742 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6743 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6744 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6745 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6746 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6747 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6748 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6749 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6750 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6751 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6752 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6753 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6754 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6755 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6756 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6757 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6758 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6759 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6760 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6761 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6762 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6763 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6764 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6765 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6766 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6767 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6768 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6769 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6770 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6771 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6772 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6773 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6774 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6775 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6776 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6777 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6778 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6779 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6780 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6781 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6782 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6783 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6784 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6785 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6786 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6787 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6788 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6789 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6790 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6791 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6792 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6793 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6794 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6795 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6796 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6797 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6798 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6799 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6800 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6801 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6802 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6803 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6804 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6805 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6806 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6807 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6808 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6809 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6810 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6811 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6812 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6813 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6814 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6815 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6816 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6817 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6818 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6819 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6820 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6821 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6822 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6823 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6824 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6825 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6826 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6827 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6828 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6829 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6830 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6831 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6832 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6833 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6834 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6835 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6836 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6837 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6838 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6839 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6840 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6841 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6842 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6843 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6844 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6845 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6846 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6847 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6848 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6849 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6850 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6851 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6852 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6853 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6854 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6855 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6856 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6857 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6858 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6859 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6860 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6861 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6862 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6863 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6864 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6865 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6866 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6867 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6868 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 948:

/* Line 678 of lalr1.cc  */
#line 6869 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 949:

/* Line 678 of lalr1.cc  */
#line 6870 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 950:

/* Line 678 of lalr1.cc  */
#line 6871 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 951:

/* Line 678 of lalr1.cc  */
#line 6872 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 952:

/* Line 678 of lalr1.cc  */
#line 6873 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 953:

/* Line 678 of lalr1.cc  */
#line 6874 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 954:

/* Line 678 of lalr1.cc  */
#line 6875 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 955:

/* Line 678 of lalr1.cc  */
#line 6876 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 956:

/* Line 678 of lalr1.cc  */
#line 6877 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 957:

/* Line 678 of lalr1.cc  */
#line 6878 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 958:

/* Line 678 of lalr1.cc  */
#line 6879 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 959:

/* Line 678 of lalr1.cc  */
#line 6880 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 960:

/* Line 678 of lalr1.cc  */
#line 6881 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 961:

/* Line 678 of lalr1.cc  */
#line 6882 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 962:

/* Line 678 of lalr1.cc  */
#line 6883 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 963:

/* Line 678 of lalr1.cc  */
#line 6884 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 964:

/* Line 678 of lalr1.cc  */
#line 6885 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 965:

/* Line 678 of lalr1.cc  */
#line 6886 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 966:

/* Line 678 of lalr1.cc  */
#line 6887 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 967:

/* Line 678 of lalr1.cc  */
#line 6888 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 968:

/* Line 678 of lalr1.cc  */
#line 6889 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 969:

/* Line 678 of lalr1.cc  */
#line 6890 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 970:

/* Line 678 of lalr1.cc  */
#line 6891 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 971:

/* Line 678 of lalr1.cc  */
#line 6892 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 972:

/* Line 678 of lalr1.cc  */
#line 6893 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 973:

/* Line 678 of lalr1.cc  */
#line 6894 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 974:

/* Line 678 of lalr1.cc  */
#line 6895 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 975:

/* Line 678 of lalr1.cc  */
#line 6896 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 976:

/* Line 678 of lalr1.cc  */
#line 6897 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 977:

/* Line 678 of lalr1.cc  */
#line 6898 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 978:

/* Line 678 of lalr1.cc  */
#line 6899 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 979:

/* Line 678 of lalr1.cc  */
#line 6900 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 980:

/* Line 678 of lalr1.cc  */
#line 6901 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 981:

/* Line 678 of lalr1.cc  */
#line 6902 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 982:

/* Line 678 of lalr1.cc  */
#line 6903 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 983:

/* Line 678 of lalr1.cc  */
#line 6904 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 984:

/* Line 678 of lalr1.cc  */
#line 6905 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 985:

/* Line 678 of lalr1.cc  */
#line 6906 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 986:

/* Line 678 of lalr1.cc  */
#line 6907 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 987:

/* Line 678 of lalr1.cc  */
#line 6908 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 988:

/* Line 678 of lalr1.cc  */
#line 6909 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 989:

/* Line 678 of lalr1.cc  */
#line 6910 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 990:

/* Line 678 of lalr1.cc  */
#line 6911 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 991:

/* Line 678 of lalr1.cc  */
#line 6912 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 992:

/* Line 678 of lalr1.cc  */
#line 6913 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 993:

/* Line 678 of lalr1.cc  */
#line 6914 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 994:

/* Line 678 of lalr1.cc  */
#line 6915 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 995:

/* Line 678 of lalr1.cc  */
#line 6916 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 996:

/* Line 678 of lalr1.cc  */
#line 6917 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 997:

/* Line 678 of lalr1.cc  */
#line 6918 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 998:

/* Line 678 of lalr1.cc  */
#line 6919 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 999:

/* Line 678 of lalr1.cc  */
#line 6920 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1000:

/* Line 678 of lalr1.cc  */
#line 6921 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1001:

/* Line 678 of lalr1.cc  */
#line 6922 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1002:

/* Line 678 of lalr1.cc  */
#line 6923 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1003:

/* Line 678 of lalr1.cc  */
#line 6924 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1004:

/* Line 678 of lalr1.cc  */
#line 6925 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1005:

/* Line 678 of lalr1.cc  */
#line 6926 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1006:

/* Line 678 of lalr1.cc  */
#line 6927 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1007:

/* Line 678 of lalr1.cc  */
#line 6928 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1008:

/* Line 678 of lalr1.cc  */
#line 6929 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1009:

/* Line 678 of lalr1.cc  */
#line 6930 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 1010:

/* Line 678 of lalr1.cc  */
#line 6931 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 1011:

/* Line 678 of lalr1.cc  */
#line 6932 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1012:

/* Line 678 of lalr1.cc  */
#line 6933 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 1013:

/* Line 678 of lalr1.cc  */
#line 6934 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 1014:

/* Line 678 of lalr1.cc  */
#line 6935 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 1015:

/* Line 678 of lalr1.cc  */
#line 6936 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 1016:

/* Line 678 of lalr1.cc  */
#line 6941 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 678 of lalr1.cc  */
#line 12207 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1510;
  const short int
  xquery_parser::yypact_[] =
  {
      3594, -1510, -1510, -1510,  5458,  5458,  5458, -1510, -1510,    27,
     310, -1510,   843,     4, -1510, -1510, -1510,   695, -1510, -1510,
   -1510,   319,   350,   786,  2723,   466,   570,   723, -1510,    59,
   -1510, -1510, -1510, -1510, -1510, -1510,   792, -1510,   574,   604,
   -1510, -1510, -1510, -1510,   555, -1510,   793, -1510,   608,   703,
   -1510,   378, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510,
   -1510, -1510, -1510, -1510, -1510, -1510,   648,   749, -1510, -1510,
   -1510, -1510,   641, 11348, -1510, -1510, -1510,   772, -1510, -1510,
   -1510,   578, -1510,   784,   790, -1510, -1510, 15735, -1510, -1510,
   -1510, -1510, -1510, -1510, -1510, -1510,   697, -1510, -1510,   801,
     809, -1510, -1510, -1510, -1510, -1510, -1510, -1510,  4218,  7318,
    7628, 15735, -1510, -1510, -1510, -1510, -1510, -1510, -1510,   800,
   -1510, -1510,   815, 12243, -1510, 12546,   842,   846, -1510, -1510,
   -1510,   848, -1510, 10728, -1510, -1510, -1510, -1510, -1510, -1510,
     821, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510,   115,
     761, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510,   213,
     823,   252, -1510,  -101,   -93, -1510, -1510, -1510, -1510, -1510,
   -1510,   864, -1510,   744,   746,   748, -1510, -1510,   840,   844,
   -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510,
   -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510,
   -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510,
   -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510,
   -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510,
   -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510,
   -1510, -1510, -1510,  7938,  8248, -1510,   685, -1510, -1510, -1510,
   -1510, -1510,  3906,  5768,  1001, -1510,  6078, -1510, -1510,   408,
      91, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510,
   -1510, -1510, -1510, -1510, -1510,   102, -1510, -1510, -1510, -1510,
   -1510, -1510,   405, -1510, -1510, -1510, -1510, -1510, -1510, -1510,
   -1510,  5458, -1510, -1510, -1510, -1510,    56, -1510, -1510, -1510,
   -1510, -1510, -1510, -1510, -1510,   230, -1510,   812, -1510, -1510,
   -1510,   693, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510,
     837,   913, -1510,  1008,   757,   908,   585,    23,   676,   670,
   -1510,   959,   814,   917,   919,  9488, -1510,   829, -1510, -1510,
     505, -1510, -1510, 11038, -1510,   377, -1510,   880, 11348, -1510,
     880, 11348, -1510, -1510, -1510,   711, -1510, -1510, -1510, -1510,
   -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510,
   -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510,
   -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510,
   -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510,
   -1510, -1510, -1510, -1510, -1510, -1510, -1510,   890,   883, -1510,
   -1510, -1510, -1510, -1510,   854, -1510,  5458,   857,   859,   497,
     497,  1015,   634,   644,    26, 16023, 15735,   482,   999, 15735,
     895,   930,   630, 12243,   729,   803, 15735, 15735,   753,   782,
      60, -1510, -1510, -1510, 12243,  5458,   865,  5458,   167,  9798,
   13431, 15735, -1510,   766,   769, 15735,   936,    31,   911,  9798,
    1064,    83,    94, 15735,   948,   925,   961, -1510,  9798, 11946,
   15735, 15735, 15735,  5458,   884,  9798,  9798, 15735,  5458,   921,
     922, -1510, -1510, -1510,  9798, 13719,   914, -1510,   916, -1510,
   -1510, -1510, -1510,   924, -1510,   926, -1510, -1510, -1510, -1510,
   -1510,   928, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510,
   -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510,
   -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510,
   15735, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510,
   -1510, -1510, -1510,   935, 15735, -1510, -1510, -1510,   894,  4528,
     960,   336,   929,   931,   932, 15735,  5458, -1510,   937,   159,
   -1510,   750, -1510,   116,  1056,  9798, -1510, -1510,    97, -1510,
   -1510, -1510,  1075, -1510, -1510, -1510, -1510,  9798,   879, -1510,
    1065,  9798,  9798, 12846,   909,  9798,  9798,  9798,  9798, 12846,
    9798,   867,   869, 15735,   912,   918,  9798,  9798,  4218,   856,
   -1510,    69, -1510,    68,  9798,  5768, -1510, -1510, -1510, -1510,
   -1510,   843,   723,   105,   108,  1103,  6388,  6388,  6698,  6698,
     578, -1510, -1510,   236,   578, -1510,  3284,  9798,  9798, -1510,
     989,   715,    59,   941,   940,   945,  5458,  9798, -1510, -1510,
   -1510, -1510, -1510, -1510, -1510, -1510, 10108, 10108, 10108, -1510,
   10108, 10108, -1510, 10108, -1510, 10108, -1510, -1510, -1510, -1510,
   -1510, -1510, -1510, 10108, 10108,  1041, 10108, 10108, 10108, 10108,
   10108, 10108, 10108, 10108, 10108, 10108, 10108, 10108,   885,  1023,
    1024,  1025, -1510, -1510, -1510, 10418,  8558, -1510, -1510, 10728,
   10728,  9798,   880, -1510, -1510,   880, -1510,  8868,   880,   975,
    9178, -1510, -1510, -1510,   265, -1510,   293, -1510, -1510, -1510,
   -1510, -1510, -1510,  1018,  1026,   466,  1102, -1510, -1510, 16023,
     944,   539, 15735,   974,   976,   944,  1015,  1017,  1003, -1510,
   -1510, -1510,   414,   896,  1051,   851, 15735,  1005,  9798,  1034,
   15735, 15735, -1510,  1028,   973,  5458, -1510,   977,   916,   604,
   -1510,   971,   979,   231, -1510,   322,   353,  1055, -1510,    52,
   -1510, -1510,  1055, 15735,    66, 15735,  1070,   384, -1510,  5458,
   -1510,   134, -1510, 12243,  1071,  1123, 12243,  1015,  1073,   340,
   15735,  9798,    59,   241,   984, -1510,   985,   986,   987,    37,
   -1510,    64,   991, -1510,   141,   177,  1027, -1510,   992,  5458,
    5458,   264, -1510,   387,   406,   493,  9798,   224, -1510, -1510,
    9798,  9798, -1510,  9798,  9798,  9798, -1510,  9798, -1510,  9798,
   -1510, 15735,  1056, -1510,    25,   339, -1510, -1510, -1510,   369,
   -1510,    50, -1510, -1510,  1029,  1030,  1031,  1032,  1033,   711,
     890, -1510,   311,   329,    40,     6,  1083,   496,   942,   953,
     950,    15, -1510,  1046, -1510, -1510,  1000,   178,  4838,   389,
   11649,   856, -1510, -1510, -1510,   956, -1510,   408,   614,  1159,
    1159, -1510, -1510,   110, -1510, -1510,   119, -1510,    54, -1510,
   -1510, -1510, -1510, -1510, -1510,  1192, -1510, -1510, 15735,  1036,
    9798,  1076, -1510, -1510, -1510,   913, -1510, -1510, -1510, -1510,
   -1510, 10108, -1510, -1510, -1510,    47, -1510,    23,    23,    12,
     676,   676,   676,   676,   670,   670, -1510, -1510, 14871, 14871,
   15735, 15735, -1510, -1510,   391, -1510, -1510,   243, -1510, -1510,
   -1510,   421, -1510, -1510,   451,   497, -1510, -1510,   593,   601,
     517, -1510,   466, -1510, -1510, -1510, -1510, -1510, -1510, -1510,
   -1510, -1510, -1510,   944, -1510,  1063, 15159,  1054,  9798, -1510,
   -1510, -1510,  1104,  1015,  1015,   944, -1510,   659,  1015,   649,
   15735,   540,   568,  1168, -1510, -1510,   915,   467, -1510, -1510,
   -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510,   414,
      34,   972,   583,  9798, -1510, 15735,  1106,   903,  1015, -1510,
   -1510, -1510, -1510,  1050, 15735, -1510, 15735, -1510, 15447,  1077,
   14871,  1089,  9798,     9,  1061,    63,   442,   955, -1510, -1510,
     675,    66,  1104, 14871,  1092,  1124,  1035,  1019,  1088,  1015,
    1062,  1091,  1125,  1015,  9798,   -24, -1510, -1510, -1510,  1072,
   -1510, -1510, -1510, -1510,  1108,  9798,  9798,  1080, -1510,  1128,
    1131,  5458, -1510,  1040,  1048,  1082, 15735, -1510, 15735, -1510,
    9798,  1096,  1043,  9798, -1510,  1121,   179,   186,   189,  1209,
   -1510,   238, -1510,    81, -1510, -1510,  1217, -1510,   653,  9798,
    9798,  9798,   731,  9798,  9798,  9798,  9798,  9798,  9798,  9798,
    9798,  9798, 12846,  1129,  9798,  9798, -1510,  7008,  1093,  1094,
    1097,  1095,   812,   874,  1007, -1510,   234, -1510,  9798,   124,
     157,    54,  6698,  6698,  6698,  1178, -1510, -1510,  9798,   728,
    1152, -1510, 15735,  1153, -1510, -1510,  9798,    47,   435,   506,
   -1510,   978,   149,  1004,  1006, -1510, -1510,   803, -1510,   994,
     503,  1111,  1112, 15159,  1113,  1114,  1115,  1116,  1118, -1510,
     523, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510,
   -1510, -1510, -1510, -1510,  1120, -1510, -1510, -1510, -1510,  9798,
   -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510,   652,
   -1510,  1246,   796, -1510, -1510, -1510, -1510, -1510, -1510, -1510,
   -1510, -1510,   993, -1510, -1510,  1248, -1510, -1510, -1510, -1510,
   -1510,   518,  1249, -1510,   672, -1510, -1510, -1510,   914,   350,
     924,   574,   926,   928,   823,  1114,  1115,  1116, -1510,   523,
     523, 10418,   995,   980, -1510,  1104,    34,  1053,  1098,  5458,
    1105,  1107,  1139,  1109,  1110, 15735, -1510,   283, -1510, 15735,
   -1510,  9798,  1138,  9798,  1162,  9798,    88,  1143,  9798,  1154,
   -1510,  1181,  1184,  9798, 15735,   882,  1227, -1510, -1510, -1510,
   -1510, -1510, -1510, 14871, -1510,  5458,  1015,  1198, -1510, -1510,
   -1510,  1015,  1198, -1510,  9798,  1165,  5458, 15735, -1510, -1510,
    9798,  9798,   621, -1510,    85,   712, -1510, 14007,   747, -1510,
     788, -1510,  1126, -1510, -1510,  5458,  1122,  1127, -1510,  9798,
   -1510, -1510,  9798,  1130,  1128,  1208, -1510,  1179, -1510,   679,
   -1510, -1510,  1305, -1510, -1510,  5458, 15735, -1510,   863, -1510,
   -1510, -1510,  1132,  1085,  1086, -1510, -1510, -1510,  1087,  1099,
   -1510, -1510, -1510,  1220, -1510, -1510, -1510, -1510,  1084,   309,
   15735,  1144, -1510, -1510,  9798,  9798,  9798,  5148,  7008, 11649,
    1007, -1510, 11649, -1510, -1510,  1159,   404, -1510, -1510, -1510,
    1152, -1510,  1015, -1510,   832, -1510,   560,  1207, -1510,  9798,
     399,  1076,   392,  1137, -1510,    47,  1079, -1510, -1510,   -26,
   -1510,   447,   106,  1081,    47,   447, 10108, -1510,   155, -1510,
   -1510, -1510, -1510, -1510, -1510,    47,  1186,  1052,   896,   106,
   -1510, -1510,  1039,  1257, -1510, -1510, -1510, 13143,  1149,  1151,
    1155,  1156,  1157,  1158,  1163, -1510, -1510, -1510, -1510, -1510,
   -1510, -1510, -1510, -1510, -1510, -1510, -1510,  1310,    14,  1311,
      14,  1078,  1234, -1510, -1510,  1176, 15735,  1119, -1510, -1510,
   10418, -1510,  1167, -1510, -1510, -1510, -1510, -1510, -1510,  9798,
    1205, -1510, -1510,  9798, -1510,   407, -1510,  9798,  1206,  9798,
   -1510,  9798, 15735, 15735, -1510,   650, -1510,  9798, -1510,  1228,
    1233,  1264,  1015,  1198, -1510,  9798,  1177, -1510, -1510, -1510,
    1180, -1510,   256,  9798,  5458,  1182,   275, -1510, 15735,  1183,
   14295,   285, -1510, 14583,  1185, -1510, -1510,  1188, -1510, -1510,
   -1510, -1510,  9798,   789,  1209, 15735,   866, -1510,  1189,  1209,
   15735, -1510, -1510,  9798,  9798,  9798,  9798,  1049,  9798,  9798,
   -1510,  9798,   208,   226,   232,   484, -1510, -1510, -1510, -1510,
   -1510,  1207, -1510, -1510, -1510,  1015,  9798, -1510,  1237, -1510,
   -1510, -1510, -1510,  1196, 10108, -1510, -1510, -1510, -1510, -1510,
     452, 10108, 10108,   576, -1510,  1004, -1510,   316, -1510,  1006,
      47,  1229, -1510, -1510,  1090, -1510, -1510, -1510, -1510,  1268,
    1194, -1510,   470, -1510, -1510, -1510, -1510, -1510, -1510, -1510,
   -1510,   366,   366, -1510,    14, -1510, -1510,   475, -1510,  1354,
     106,  1289,  1199, 10418,   -20,  1100,  1218, -1510, -1510,  9798,
   -1510,  9798,  1242, -1510,  9798, -1510, -1510, -1510,  1337, -1510,
   -1510,  7008,  9798,  1015, -1510, -1510, -1510,  9798,  9798, -1510,
   -1510, -1510,  7008,  7008,  1297,  5458, 15735,  1210, 15735,  9798,
   15735,  1211,  7008, -1510,   304,    33,  1209, 15735, -1510,  1195,
    1209, -1510, -1510, -1510, -1510,  9798, -1510, -1510, -1510,  1197,
    1128,  1131,  9798, -1510, -1510, -1510,  1287,  9798, -1510,   676,
   10108, 10108,    12,   596, -1510, -1510, -1510, -1510, -1510, -1510,
    9798, -1510, 14871, -1510, 14871,  1300, -1510, -1510, -1510,  1369,
   -1510, -1510, -1510,  1134,  1293, -1510, -1510,  1294, -1510,   661,
   15735,  1284,  1187, 15735, 10418, -1510, -1510,  9798, -1510,  1285,
   -1510, -1510,  1198, -1510, -1510, 14871, -1510, -1510,  1312,  9798,
    1219, -1510,  1313,  7008, -1510, 15735,   507,   606, -1510,  1212,
    1209, -1510,  1213, -1510,  7008,   797,   395, -1510,  1287,    12,
      12, 10108,   436, -1510, -1510, 14871, -1510, -1510,  1289, 10418,
   -1510,  1207,  1117, 15735,  1286,  1190,  1294, -1510, 15735,  1222,
   14871,  5458, 14871,  1225, -1510, -1510,  1320,   516, -1510, -1510,
   -1510, -1510,  1231,   704, -1510, -1510, -1510,  1221, -1510,  1298,
   -1510, -1510,    12, -1510, -1510, -1510, -1510, -1510,  9798,  1133,
   15735,  1299, -1510,  5458,  1235, -1510, -1510,  1238,  9798, -1510,
   -1510, -1510, -1510, -1510, -1510, -1510, 15735, -1510,  1135,  1141,
   15735, -1510, -1510,  9798,  7008,  1239,  1142,  9798,  1145,  7008,
   10418, -1510, 10418, -1510,  1224,  1140, 15735,  1201,  1301, 15735,
    1148, 10418, -1510
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       163,   462,   463,   464,   166,   166,   166,   811,  1016,   118,
     120,   617,   903,   912,   852,   816,   814,   796,   904,   907,
     859,   820,   797,   798,     0,   913,   800,   910,   881,   861,
     836,   856,   857,   908,   905,   855,   802,   911,   803,   804,
     952,   964,   951,   853,   872,   866,   805,   854,   807,   806,
     953,   890,   891,   858,   833,   974,   975,   976,   977,   978,
     979,   980,   981,   982,   983,   984,   998,  1005,   880,   876,
     867,   847,   795,     0,   875,   883,   892,   999,   871,   488,
     848,   849,   906,  1000,  1006,   868,   885,     0,   494,   451,
     490,   878,   813,   869,   870,   899,   873,   889,   898,  1004,
    1007,   819,   860,   901,   489,   888,   894,   799,     0,     0,
       0,     0,   397,   886,   897,   902,   900,   879,   865,   954,
     863,   864,  1001,     0,   396,     0,  1002,  1008,   895,   850,
     874,  1003,   429,     0,   461,   896,   877,   884,   893,   887,
     955,   841,   846,   845,   844,   843,   842,   808,   862,     0,
     812,   909,   834,   943,   942,   944,   818,   817,   837,   949,
     801,   941,   946,   947,   938,   840,   882,   940,   950,   948,
     939,   838,   945,   959,   960,   957,   958,   956,   809,   961,
     962,   963,   929,   928,   915,   832,   825,   922,   918,   835,
     831,   930,   931,   821,   822,   815,   824,   927,   926,   923,
     919,   936,   937,   935,   925,   921,   914,   823,   934,   933,
     827,   829,   828,   920,   924,   916,   830,   917,   826,   932,
     985,   986,   987,   988,   989,   990,   966,   967,   965,   971,
     972,   973,   968,   969,   970,   839,   991,   992,   993,   994,
     995,   996,   997,     0,     0,  1009,  1010,  1011,  1014,  1013,
    1012,  1015,   163,   163,     0,     2,   163,     7,     9,    21,
       0,    26,    29,    34,    35,    36,    37,    38,    39,    40,
      30,    56,    57,    31,    32,     0,    74,    77,    78,    33,
      79,    80,     0,   116,    81,    82,    83,    84,    16,   160,
     161,   162,   169,   171,   481,   172,     0,   173,   174,   175,
     176,   177,   178,   179,   182,     0,   208,   217,   212,   244,
     250,     0,   242,   243,   219,   213,   181,   214,   180,   215,
     218,   348,   350,   352,   362,   364,   368,   370,   373,   378,
     381,   384,   386,   388,   390,     0,   394,   401,   400,   402,
       0,   420,   403,   425,   428,   430,   433,   435,     0,   440,
     437,     0,   448,   458,   460,   434,   465,   472,   486,   473,
     474,   475,   478,   479,   476,   477,   501,   503,   504,   505,
     502,   550,   551,   552,   553,   554,   555,   457,   591,   583,
     590,   589,   588,   585,   587,   584,   586,   487,   480,   618,
     619,    41,   220,   221,   223,   222,   224,   216,   483,   484,
     485,   482,   226,   229,   225,   227,   228,   459,   794,   810,
     903,   912,   910,   812,     0,   164,   165,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   124,   126,   127,     0,     0,     0,     0,     0,     0,
       0,     0,   254,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   272,   273,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   453,   456,   443,     0,     0,   796,   820,   798,   851,
     913,   800,   861,   802,   872,   805,   807,   806,   890,   998,
    1005,   795,   999,   849,  1000,  1006,   873,  1004,  1007,   954,
    1001,  1002,  1008,  1003,   955,   949,   941,   947,   938,   838,
     959,   960,   957,   809,   961,  1010,   449,   459,   794,   441,
       0,   189,   442,   445,   796,   797,   798,   802,   803,   804,
     805,   795,   801,   491,     0,   447,   446,   184,     0,     0,
     208,     0,   800,   807,   806,     0,   166,   769,   961,     0,
     217,     0,   492,     0,   517,     0,   452,   792,     0,   793,
     423,   424,     0,   455,   454,   444,   427,     0,     0,   546,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     771,     0,   773,     0,     0,   163,     3,     4,     1,     8,
      10,     0,     0,     0,     0,     0,   163,   163,   163,   163,
       0,   117,   170,     0,     0,   187,     0,     0,     0,   196,
       0,     0,     0,     0,     0,     0,     0,     0,   201,   230,
     249,   245,   251,   246,   248,   247,     0,     0,     0,   413,
       0,     0,   411,     0,   357,     0,   412,   405,   410,   409,
     408,   407,   406,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   399,   398,   395,     0,     0,   421,   426,     0,
       0,     0,   436,   469,   439,   438,   450,     0,   466,     0,
       0,   557,   559,   563,     0,   122,     0,   791,    45,    42,
      43,    46,    47,     0,     0,     0,     0,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   628,
     629,   630,     0,   101,   140,     0,     0,   110,     0,     0,
       0,     0,   125,     0,     0,     0,   597,     0,     0,     0,
     593,     0,     0,     0,   607,     0,     0,   253,   255,     0,
     232,   233,   252,     0,     0,     0,   132,     0,   136,   166,
     621,     0,    58,     0,    67,     0,     0,     0,    59,     0,
       0,     0,     0,     0,     0,   598,     0,     0,     0,     0,
     321,     0,     0,   596,     0,     0,     0,   615,     0,     0,
       0,     0,   601,     0,     0,   191,     0,     0,   185,   183,
       0,     0,   775,     0,     0,     0,   491,     0,   770,     0,
     493,   518,   517,   514,     0,     0,   548,   547,   422,     0,
     545,     0,   641,   642,   796,   798,   802,   805,   795,   782,
       0,   592,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   647,     0,   199,   200,     0,     0,     0,     0,
       0,   204,   205,   772,   774,     0,     5,    22,     0,    23,
       0,     6,    27,     0,    13,    28,     0,    17,   903,    75,
      14,    76,    18,   190,   188,     0,   209,   211,     0,     0,
       0,     0,   202,   231,   290,   349,   351,   355,   361,   360,
     359,     0,   356,   353,   354,     0,   365,   372,   371,   369,
     375,   376,   377,   374,   379,   380,   383,   382,     0,     0,
       0,     0,   404,   418,     0,   431,   432,     0,   470,   467,
     499,     0,   620,   497,     0,     0,   119,   121,     0,     0,
       0,   100,     0,    90,    92,    93,    94,    95,    97,    98,
      99,    91,    96,    86,    87,     0,     0,   106,     0,   102,
     104,   105,   112,     0,     0,    85,    44,     0,     0,     0,
       0,     0,     0,     0,   719,   724,     0,     0,   720,   754,
     707,   709,   710,   711,   713,   715,   714,   712,   716,     0,
       0,     0,     0,     0,   109,     0,   142,     0,     0,   562,
     556,   594,   595,     0,     0,   611,     0,   608,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   234,   235,
       0,   240,   138,     0,     0,   133,     0,     0,     0,     0,
       0,     0,    60,     0,     0,     0,   271,   277,   274,     0,
     600,   599,   606,   614,     0,     0,     0,     0,   561,     0,
       0,     0,   414,     0,     0,     0,     0,   604,     0,   602,
       0,   192,     0,     0,   776,     0,     0,     0,     0,   517,
     515,     0,   506,     0,   495,   496,     0,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   197,     0,   800,   807,
     806,   961,     0,     0,     0,   655,     0,   206,     0,     0,
       0,     0,   163,   163,   163,     0,   210,   241,     0,   305,
     301,   303,     0,   291,   292,   358,     0,     0,     0,     0,
     685,   366,   658,   662,   664,   666,   668,   671,   678,   679,
     687,   913,   799,     0,   808,  1014,  1013,  1012,  1015,   385,
     566,   572,   573,   576,   622,   623,   577,   578,   785,   786,
     787,   581,   387,   389,   392,   582,   391,   419,   471,     0,
     468,   498,   123,    54,    55,    52,    53,   129,   128,     0,
      88,     0,     0,   107,   108,   113,    72,    73,    50,    51,
      71,   725,     0,   728,   755,     0,   718,   717,   722,   721,
     753,     0,     0,   730,     0,   726,   729,   708,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   141,   144,
     146,     0,     0,     0,   111,   114,     0,     0,     0,   166,
       0,     0,   615,     0,     0,     0,   257,     0,   565,     0,
     258,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,     0,     0,     0,     0,   284,     0,   281,   286,   239,
     139,   134,   137,     0,   186,     0,     0,    69,    63,    66,
      65,     0,    61,   275,     0,     0,   166,     0,   319,   323,
       0,     0,     0,   326,     0,     0,   332,     0,     0,   339,
       0,   343,     0,   416,   415,   166,     0,     0,   193,     0,
     195,   320,     0,     0,     0,     0,   518,     0,   507,     0,
     541,   538,     0,   542,   543,     0,     0,   537,     0,   512,
     540,   539,     0,     0,     0,   634,   635,   631,     0,     0,
     639,   640,   636,   778,   779,   645,   783,   643,     0,     0,
       0,     0,   649,   198,     0,     0,     0,     0,     0,     0,
     650,   651,     0,   207,   781,    24,     0,    15,    19,    20,
     302,   314,     0,   315,     0,   306,   307,   308,   309,     0,
     294,     0,     0,     0,   669,   682,     0,   363,   367,     0,
     701,     0,     0,     0,     0,     0,     0,   657,   659,   660,
     696,   697,   698,   700,   699,     0,     0,   673,   672,     0,
     676,   680,   694,   692,   691,   684,   688,     0,     0,     0,
       0,     0,     0,     0,     0,   569,   571,   570,   567,   393,
     500,   131,   130,    89,   103,   742,   723,     0,   747,     0,
     747,   736,   731,   145,   147,     0,     0,     0,   115,   143,
       0,    25,     0,   612,   613,   616,   609,   610,   256,     0,
       0,   270,   262,     0,   266,     0,   260,     0,     0,     0,
     279,     0,     0,     0,   238,   282,   285,     0,   135,     0,
       0,    68,     0,    62,   276,     0,     0,   322,   324,   329,
       0,   327,     0,     0,     0,     0,     0,   333,     0,     0,
       0,     0,   340,     0,     0,   344,   417,     0,   605,   603,
     194,   777,     0,     0,   517,     0,     0,   549,     0,   517,
       0,   513,    12,     0,     0,     0,     0,     0,     0,     0,
     648,     0,     0,     0,     0,     0,   652,   656,   318,   316,
     317,   310,   311,   312,   304,     0,     0,   299,     0,   293,
     686,   677,   683,     0,     0,   756,   757,   767,   766,   765,
       0,     0,     0,     0,   758,   663,   764,     0,   661,   665,
       0,     0,   670,   674,     0,   695,   690,   693,   689,     0,
       0,   579,     0,   574,   627,   568,   789,   790,   788,   575,
     743,     0,     0,   741,   748,   749,   745,     0,   740,     0,
     738,     0,     0,     0,     0,     0,     0,   558,   259,     0,
     268,     0,     0,   264,     0,   267,   280,   288,   289,   283,
     237,     0,     0,     0,    64,   278,   564,     0,     0,   330,
     334,   328,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   560,     0,     0,   517,     0,   544,     0,
     517,   632,   633,   637,   638,     0,   644,   784,   646,     0,
       0,     0,     0,   653,   313,   300,   295,     0,   681,   768,
       0,     0,   760,     0,   706,   705,   704,   703,   702,   667,
       0,   759,     0,   624,     0,     0,   752,   751,   750,     0,
     744,   737,   735,     0,   732,   733,   727,   148,   150,   152,
       0,     0,     0,     0,     0,   263,   261,     0,   269,     0,
     203,   347,    70,   325,   331,     0,   345,   341,     0,     0,
       0,   335,     0,     0,   337,     0,   527,   521,   516,     0,
     517,   508,     0,   780,     0,     0,     0,   298,   296,   762,
     761,     0,     0,   625,   580,     0,   746,   739,     0,     0,
     154,   153,     0,     0,     0,     0,   149,   265,     0,     0,
       0,     0,     0,     0,   535,   529,     0,   528,   530,   536,
     533,   523,     0,   522,   524,   534,   510,     0,   509,     0,
     654,   297,   763,   675,   626,   734,   151,   155,     0,     0,
       0,     0,   287,     0,     0,   338,   336,     0,     0,   520,
     531,   532,   519,   525,   526,   511,     0,   156,     0,     0,
       0,   346,   342,     0,     0,     0,     0,     0,     0,     0,
       0,   158,     0,   157,     0,     0,     0,     0,     0,     0,
       0,     0,   159
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1510, -1510,  -231,  -188, -1510,  1164,  1173, -1510,  1171,  -533,
   -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510,
   -1002, -1510, -1510, -1510, -1510,  -219,  -580, -1510,   706,  -791,
   -1510, -1510, -1510, -1510, -1510,   250,   476, -1510, -1510,    18,
    -182,  1014, -1510,   996, -1510, -1510,  -640, -1510,   411, -1510,
     211, -1510,  -255,  -299, -1510,  -562, -1510,     5,    22,    11,
    -248,  -172, -1510,  -868, -1510, -1510,  -431, -1510, -1510, -1510,
   -1510, -1510, -1510, -1510, -1510, -1510, -1510,   582,   -90,  1496,
       0, -1510, -1510, -1510, -1510,   423, -1510, -1510,  -286, -1510,
       8, -1510,  1002,  -923,  -718,  -708, -1510, -1510,   665, -1510,
   -1510,   -15,   200, -1510, -1510, -1510,    87, -1509, -1510,   338,
      90, -1510, -1510,    95, -1305, -1510,   920,   185, -1510, -1510,
     181, -1007, -1510, -1510,   183, -1510, -1510, -1252, -1240, -1510,
     182, -1510, -1510,   827,   822, -1510,  -512,   811, -1510, -1510,
    -648,   305,  -637,   306,   307, -1510, -1510, -1510,   554, -1510,
   -1510,  1146, -1510, -1510, -1510, -1510, -1510,  -860,  -316,  -684,
   -1510,   -86, -1510, -1510, -1510, -1510, -1510, -1510, -1510,    -6,
    -810, -1510,  -537,   594,   216, -1510,  -417, -1510, -1510, -1510,
   -1510, -1510, -1510, -1510,   778, -1510, -1005, -1510,   171, -1510,
     660,  -790, -1510, -1510, -1510, -1510, -1510,  -280,  -267, -1229,
   -1015, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510,
   -1510,  -742,  -837,  -227,  -827, -1510, -1510, -1510,  -896, -1510,
   -1510, -1510, -1510, -1510, -1510, -1510,  1047,  1057,  -163,   485,
     313, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510,
   -1510, -1510, -1510, -1510, -1510,   156, -1510, -1510,   147, -1510,
     150, -1056, -1510, -1510, -1510,   118,   109,   -60,   379, -1510,
   -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510, -1510,
   -1510, -1510,   120, -1510, -1510, -1510,   -51,   372,   521, -1510,
   -1510, -1510, -1510, -1510,   312, -1510, -1510, -1476, -1510, -1510,
   -1510,  -587, -1510,    84, -1510,   -73, -1510, -1510, -1510, -1510,
   -1302, -1510,   128, -1510, -1510, -1510, -1510, -1510,   933, -1510,
   -1510, -1510, -1510, -1510,  -916, -1510, -1510, -1510,  -403,  -367,
     235,  1016, -1510
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   254,   628,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
    1267,   777,   272,   273,   274,   275,   276,   277,   953,   954,
     955,   278,   279,   280,   959,   960,   961,   281,   439,   282,
     283,   704,   284,   441,   442,   443,   458,   767,   768,   285,
    1218,   286,  1687,  1688,   287,   288,   289,   548,   290,   291,
     292,   293,   294,   770,   295,   296,   531,   297,   298,   299,
     300,   301,   302,   638,   303,   304,   861,   862,   305,   306,
     560,   308,   639,   456,  1020,  1021,   309,   640,   310,   642,
     561,   312,   757,   758,  1255,   465,   313,   466,   467,   764,
    1256,  1257,  1258,   643,   644,  1123,  1124,  1537,   645,  1120,
    1121,  1365,  1366,  1367,  1368,   314,   789,   790,   315,  1282,
    1283,  1482,   316,  1285,  1286,   317,   318,  1288,  1289,  1290,
    1291,   319,   320,   321,   322,   901,   323,   324,  1377,   325,
     326,   327,   328,   329,   330,   331,   332,   333,  1163,   334,
     335,   336,   337,   663,   664,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   698,   693,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   931,   365,   366,   367,  1318,   822,
     823,   824,  1718,  1762,  1763,  1756,  1757,  1764,  1758,  1319,
    1320,   368,   369,  1321,   370,   371,   372,   373,   374,   375,
     376,  1015,  1149,  1418,  1150,  1572,  1151,  1164,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   796,  1231,
     387,   388,   389,   390,  1153,  1154,  1155,  1156,   391,   392,
     393,   394,   395,   396,   851,   852,   397,  1350,  1351,  1653,
    1106,  1131,  1387,  1388,  1132,  1133,  1134,  1135,  1136,  1397,
    1562,  1563,  1137,  1400,  1138,  1543,  1139,  1140,  1405,  1406,
    1568,  1566,  1389,  1390,  1391,  1392,  1667,   733,   980,   981,
     982,   983,   984,   985,  1205,  1592,  1684,  1206,  1590,  1682,
     986,  1430,  1587,  1583,  1584,  1585,   987,   988,  1393,  1401,
    1553,  1394,  1549,  1378,   398,   399,   400,   401,   551,   402,
     403,   404,   405,   406,  1157,  1158,  1159,  1160,  1268,   568,
     407,   408,   409
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int xquery_parser::yytable_ninf_ = -852;
  const short int
  xquery_parser::yytable_[] =
  {
       307,   922,   705,   705,   307,   307,   307,   599,   311,   414,
     417,   418,   311,   311,   311,   416,   416,   416,   708,   559,
     563,   909,  1152,  1152,   687,   641,   415,   415,   415,   617,
     440,  1272,  1071,   910,   911,   912,   913,  1035,   879,   881,
     614,  1013,  1284,   622,   619,  1129,   839,   576,  1492,  1047,
    1105,  1014,   847,  1503,   874,   877,   880,   882,   774,   778,
    1152,  1532,  1533,  1061,   606,   607,   728,   526,  1317,   626,
     626,  1373,  1178,  1208,  1220,   940,    11,   743,  1209,   748,
       9,    10,  1162,   872,   875,  1236,     9,    10,  1009,  1511,
    1310,  1311,   615,  1210,  1219,  1211,   749,  1564,  1690,  1244,
     621,   425,   786,   615,  1212,   826,   615,   425,   307,   615,
     426,   615,   707,   811,  1152,  1685,   311,   626,  1274,   549,
     615,  1017,  1093,   707,   588,   615,  1716,  1152,   428,  1182,
     415,  1213,   590,   429,   428,   626,   897,   591,   898,   899,
     670,   900,   626,   902,  1044,   578,  1010,  1727,  1011,   765,
    1581,   903,   904,   601,   603,  1072,  1241,    79,  1010,  1011,
     626,   810,  1180,   624,   444,   430,   431,  1115,   622,   671,
     667,    90,   739,  1238,  1180,   627,   627,   463,   626,   626,
     626,  1076,   672,   419,  1312,  1483,  1261,   626,   668,   883,
     626,  1545,   713,   884,   421,   422,   104,   423,   424,  1012,
    1126,   623,  1550,  1127,  1313,  1691,  1314,   775,   714,   626,
    1245,  1046,   748,   589,   427,  1582,  1717,   673,   766,  1771,
    1185,   592,  1073,   627,   125,  1045,  1654,   626,  1546,   749,
    -167,   626,   626,   626,  1315,  1457,  -168,   626,   111,  1087,
    1077,   627,   626,   773,   626,  1379,   625,  1152,   627,   464,
    1094,  1379,   307,   307,   776,   123,   307,   688,   621,  1214,
     311,   311,  1775,  1492,   311,   626,   627,  1129,  1129,  1473,
    1356,  1484,   827,  1086,  1249,   641,  1316,  1511,  1486,  1307,
    1260,   616,   464,  1018,   627,   627,   627,  1692,  1683,   879,
     881,   307,   618,   627,   149,   867,   627,  1246,   869,   311,
    1112,   622,  1179,   820,  1317,  1242,  1128,  1247,   527,  1114,
    1220,  1422,  1448,  1317,  1355,   627,  1409,   433,  1380,  1542,
    1019,  1027,   543,   966,  1380,   464,   623,  1275,  1049,   579,
    1219,  1044,   464,   627,   872,   875,   464,   627,   627,   627,
     626,   436,   694,   627,   818,   696,   564,   740,   627,   437,
     627,  1215,  1216,  1217,   750,   741,  1483,   438,   569,   753,
     572,   464,  1551,  1552,  1050,  1097,  1303,  1152,  1308,   771,
     626,   627,   935,  1304,  1032,  1483,  1305,   434,   783,  1011,
     863,   864,   868,   870,  1740,   794,   795,  1347,   892,  1125,
     626,  1152,   626,   626,   801,  1649,   626,   873,   876,  1725,
     935,  1381,  1382,  1628,  1383,  1078,  1028,  1381,  1382,  1031,
    1383,  1384,  1063,  1650,  -167,  1003,   307,   866,   435,  1651,
    -168,  1385,  1715,  1082,   311,  1039,  1468,  1385,  1168,  1004,
    1449,     9,    10,  1386,  1010,  1309,  1777,   626,   581,  1386,
     582,   611,  1618,   811,  1352,   307,   627,   307,  1055,   723,
    1489,   724,   936,   311,   477,   311,   745,   612,   745,   623,
    1006,  1623,  1427,   691,    11,   697,   420,   744,   969,   747,
     970,  1629,   447,   307,   667,   825,   627,   585,   307,   586,
     937,   311,  1034,  1438,   745,  1492,   311,   829,  1130,   745,
    1629,  1024,   668,  1010,  1056,   792,   627,   622,   627,   627,
     798,  1317,   627,  1011,  1660,  1535,   448,   857,   859,  1005,
     726,  1152,  1754,  1058,   971,  1129,  1310,   620,  1172,  1450,
     812,  1754,  1429,  1074,  1129,  1310,    11,   583,  1169,  1079,
    1080,   478,   879,   881,   879,  1129,  1010,  1435,  1458,  1105,
    1007,  1536,  1527,   627,  1081,    79,  1519,  1083,  1084,   307,
    1357,  1358,  1359,  1075,  1601,  1339,   307,   311,  1169,    90,
    1186,  1187,  1085,  1202,   311,  1190,   587,   416,   689,   690,
    1571,  1025,   727,  1104,  1057,  1167,  1540,  1674,   415,  1770,
    1203,  1661,  1679,   527,   104,  1664,   527,  1010,  1126,  1248,
    1089,  1127,  1665,  1059,  1152,  1228,   924,  1152,   307,   479,
     480,   927,  1666,   925,   926,   307,   311,    79,  1170,   858,
     622,  1702,   125,   311,  1427,  1310,   307,   307,   307,   307,
    1773,    90,   457,  1204,   311,   311,   311,   311,  1538,   440,
    1313,  1428,  1314,   956,  1760,  1060,   307,  1652,  1171,  1313,
    1755,  1314,  1113,  1486,   311,   870,   104,  1110,  1109,  1790,
     691,   717,   697,  1627,  1177,   623,  1631,  1675,   686,  1375,
    1315,   716,  1680,   612,   720,   972,  1362,  1415,   569,  1315,
     769,   734,   735,   472,  1429,   723,   957,   724,   973,   569,
     974,   958,   125,   125,   718,   756,   759,  1364,  1310,  1311,
     759,   975,   976,   977,  1352,   978,   530,   979,   779,  1416,
    1129,  1759,  1765,  1251,   569,   787,   788,   791,  1252,   725,
    1130,  1130,   797,  1310,  1635,  1547,   451,  1417,   452,  1639,
     804,  1281,  1548,  1066,  1067,  1068,   459,   859,  1251,  1313,
     470,  1314,  1760,  1252,  1480,   630,   726,  1602,  1557,   631,
    1761,  1173,  1759,   667,   632,   307,  1011,   460,  1765,  1175,
    1402,  1403,  1253,   311,   667,  1010,  1596,   461,  1174,  1315,
     471,   668,   633,   483,   475,   805,  1176,  1362,  1202,   307,
     481,  1011,   668,  1404,  1026,   879,  1152,   311,  1152,   791,
     416,   453,  1312,   462,   669,  1203,   454,  1188,  1189,  1421,
     816,   415,   630,  1254,   484,  1731,   631,   485,   727,   307,
     307,   632,  1313,  1196,  1314,   769,   676,   311,   311,  1152,
     745,   745,  1281,   687,  1197,   544,   709,   641,   840,   633,
     677,  1053,  1054,  1361,   840,  1485,   711,  1313,   853,  1314,
     710,  1198,  1315,   455,  1362,  1733,   111,  1734,  1793,  1152,
     712,  1230,  1199,  1233,  1363,  1664,  1719,  1490,   445,  1343,
    1722,   446,  1665,   123,  1152,  1364,  1152,  1315,  1102,   476,
    1491,   634,  1666,  1471,   635,   691,  1103,   697,  1749,     9,
      10,   482,  1310,  1311,  1505,  1310,  1311,   674,   870,   636,
     421,   422,  1222,   423,   424,  1323,   675,  1324,  1493,  1490,
     425,  1223,   149,  1296,   529,  1297,   440,  1490,  1774,   426,
     427,  1494,  1634,  1662,  1663,   637,   532,  1659,   928,  1689,
    1769,   928,   533,  1784,   928,  1787,   630,   428,   634,   737,
     631,   635,   429,   545,   738,   632,  1191,  1192,  1193,   599,
    1767,   546,  1194,   957,  1353,  1251,   819,   566,   958,   449,
    1252,   692,   450,   633,   695,   468,   473,  1741,   469,   474,
     729,   730,   731,   565,   430,   431,   432,   962,  1130,  1528,
    1529,  1530,   637,  1328,   573,  1329,  1312,  1130,   574,  1312,
     575,   992,   907,   908,   577,   996,   997,   580,  1130,   584,
     914,   915,   593,   916,   917,   594,  1313,   595,  1314,  1313,
     596,  1314,  1433,  1434,  1676,  1677,   597,   598,  1016,   604,
    1022,   608,   629,   433,   646,   647,   665,   666,   569,   678,
    1689,   569,  1729,  1730,   679,  1036,  1315,  1469,   680,  1315,
     111,   681,   685,   111,   943,   944,   945,   946,   947,   948,
     949,   950,   951,   952,   691,   699,  1372,   123,   701,   700,
     123,   702,   634,   703,   707,   635,   719,   721,   722,   732,
     760,   307,   746,   761,   763,  1689,  1069,   736,  1510,   311,
    1348,  1637,   745,   434,   769,   772,   780,   781,   782,  1614,
     446,   793,   450,  1292,   799,   800,   149,   806,   808,   149,
     469,   810,   474,  1772,   485,   813,   637,   814,   815,   528,
     817,   821,   828,   830,   831,   527,   841,  1102,   849,   850,
     892,   860,   854,   528,   435,  1103,   871,   888,   855,   889,
     890,   905,   307,   307,   307,   891,   918,   919,   920,   921,
     311,   311,   311,  1117,   932,   938,  1813,   528,  1814,   440,
     436,   941,  1655,   939,   963,   968,   964,  1822,   437,   528,
     648,   528,   989,  1130,   967,   990,   438,   993,   649,   650,
     991,   651,   995,  1161,  1161,  1165,  1165,   999,  1001,   652,
     998,  1000,  1008,   653,  1023,   654,  1002,  1029,  1030,  1033,
     655,  1040,  1041,  1042,  1043,  1048,  1052,  1088,  1091,  1090,
    1051,  1092,   445,   449,   468,   473,   484,   656,  1095,  1108,
    1096,  1161,  1111,  1116,  1122,  1181,   958,  1200,  1010,  1221,
    1226,  1201,  1227,  1229,  1237,  1195,  1118,  1239,  1243,  1250,
     765,   657,   658,   659,   660,   661,   662,  1265,  1263,  1264,
    1266,  1271,  1269,  1270,  1293,  1276,  1277,  1280,  1281,   307,
    1225,  1287,  1294,  1300,  1442,  1295,  1620,   311,  1299,  1232,
     416,  1232,  1302,   759,  1306,  1161,  1322,  1340,  1347,  1344,
    1345,   415,  1349,  1346,  1522,  1523,  1524,   725,  1161,  1369,
    1371,  1399,  1395,  1376,  1419,   307,  1396,  1407,  1408,  1410,
    1411,  1412,  1413,   311,  1414,    11,   307,  1426,  1431,  1425,
    1440,  1476,  1436,  1445,   311,  1453,  1437,   416,  1441,  1455,
    1459,   797,  1443,   797,  1444,   307,  1446,  1447,   415,  1462,
    1497,  1461,  1463,   311,  1467,  1472,   416,  1475,  1490,  1498,
    1496,  1504,  1507,  1362,  1499,   307,  1517,   415,  1513,  1514,
    1515,  1518,  1512,   311,  1541,  1565,   745,   840,  1502,  1544,
    1521,  1554,  1516,  1560,  1561,  1567,  1573,  1508,  1574,  1580,
    1586,  1591,  1575,  1576,  1577,  1578,  1593,  1102,  1102,  1589,
    1579,  1597,  1599,  1604,  1611,  1103,  1103,  1370,   858,  1612,
    1613,  1616,  1672,  1700,   528,  1645,  1617,   528,  1622,  1625,
    1671,  1632,  1633,  1638,  1704,  1620,  1595,  1706,  1161,  1657,
    1658,  1673,  1670,  1681,  1714,  1202,  1686,  1693,  1694,  1697,
    1699,  1705,  1721,  1535,  1735,  1724,  1709,  1713,  1736,  1737,
    1738,  1739,  1743,  1748,  1780,  1751,  1750,  1752,  1783,  1766,
    1768,  1788,  1744,  1789,  1792,  1781,  1796,  1800,  1795,  1819,
     609,  1803,  1778,  1815,  1804,  1809,  1818,  1816,  1806,   610,
     613,   965,  1424,  1183,   706,  1262,   742,  1439,  1798,  1746,
    1776,   715,   528,  1107,  1259,   528,  1807,  1038,  1810,   528,
    1609,  1812,   528,   528,  1821,  1466,  1360,   762,  1539,  1534,
     528,  1531,  1477,  1481,   807,  1706,   528,   528,  1487,   896,
     759,   528,  1495,   895,  1451,  1166,  1469,   906,   934,   528,
    1506,   684,  1070,  1794,   307,   528,   528,   528,   528,  1465,
    1791,  1234,   311,   528,  1423,   751,  1520,  1526,  1161,  1525,
    1669,   528,  1555,  1785,  1559,   752,  1668,  1374,  1558,  1398,
    1207,  1678,   791,  1556,  1588,     0,  1432,     0,     0,     0,
     845,     0,  1161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1801,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   528,     0,     0,     0,
       0,  1509,     0,     0,     0,     0,  1801,     0,     0,     0,
     528,  1785,  1726,     0,     0,     0,     0,     0,     0,     0,
       0,   528,     0,     0,     0,   853,     0,     0,     0,     0,
    1732,     0,     0,     0,   527,     0,     0,   527,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   550,     0,     0,     0,     0,   528,
       0,  1102,     0,     0,     0,     0,     0,     0,     0,  1103,
       0,     0,  1102,  1102,     0,   307,     0,     0,     0,     0,
    1103,  1103,  1102,   311,     0,     0,     0,     0,     0,     0,
    1103,     0,  1161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1594,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1607,  1608,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1102,     0,     0,     0,     0,     0,     0,
       0,  1103,     0,  1624,  1102,  1161,     0,     0,  1161,     0,
       0,     0,  1103,     0,     0,   942,     0,     0,   528,     0,
    1636,     0,     0,     0,     0,  1640,     0,     0,     0,     0,
       0,   307,   528,     0,     0,     0,   528,   528,     0,   311,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   528,
       0,   528,     0,   307,     0,     0,     0,     0,     0,   528,
       0,   311,   528,     0,     0,     0,   528,     0,     0,     0,
       0,     0,     0,     0,  1102,     0,     0,     0,     0,  1102,
       0,     0,  1103,     0,     0,     0,     0,  1103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   528,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1708,     0,  1710,     0,  1712,     0,     0,     0,     0,
       0,     0,  1720,     0,     0,     0,   528,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   528,     0,     0,  1161,     0,  1161,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1742,     0,     0,  1745,     0,
       0,     0,     0,     0,   528,   528,   528,   528,     0,     0,
    1161,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1753,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1161,     0,   528,     0,     0,     0,     0,     0,  1779,     0,
       0,     0,     0,  1782,     0,  1161,   528,  1161,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   528,     0,     0,     0,  1799,     0,     0,     0,     0,
     528,     0,   528,     0,   528,     0,   528,     0,     0,     0,
       0,  1805,     0,     0,     0,  1808,     0,     0,     0,   528,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1817,   550,     0,  1820,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,     0,   528,     0,     0,   832,   833,     0,
       0,   842,   843,   844,   846,     0,   848,     0,     0,     0,
       0,     0,   856,     0,     0,     0,     0,     0,     0,     0,
     865,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   885,   886,   887,     0,     0,     0,     0,     0,
       0,     0,   893,   894,     0,     0,     0,     0,   528,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   528,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   930,     0,     0,   930,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   994,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   528,     0,     0,     0,   528,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     528,     0,     0,     0,     0,     0,     0,  1037,     0,   528,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   528,     0,     0,     0,     0,     0,     0,
       0,     0,  1062,   528,     0,     0,  1064,  1065,     0,     0,
       0,     0,     0,     0,     0,   893,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   528,     0,     0,     0,
       0,     0,     0,     0,     0,   528,     0,     0,   528,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   528,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,     0,  1184,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   528,   528,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1224,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   528,     0,   528,     0,  1240,   528,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   528,     0,     0,     0,     0,   528,     0,     0,     0,
    1273,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1278,  1279,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1298,     0,     0,  1301,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1325,  1326,  1327,     0,  1330,
    1331,  1332,  1333,  1334,  1335,  1336,  1337,  1338,     0,     0,
    1341,  1342,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1354,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,     0,   528,     0,   528,     0,     0,     0,
       0,     0,     0,   528,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1420,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   528,     0,
     528,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   528,     0,     0,   528,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   528,     0,  -851,   451,     0,   452,     0,     0,     0,
       0,   528,     0,     0,     0,     0,     0,  1452,     0,  1454,
       0,  1456,     0,     0,  1460,     0,     0,     0,     0,  1464,
       0,   528,     0,     0,     0,     0,     0,     0,     0,   528,
       0,  1470,     0,     0,   528,  -851,   528,     0,   528,  -851,
    1474,     0,     0,  -851,  -851,     0,  1478,  1479,  -851,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   453,
       0,     0,  -851,     0,   454,  1500,   528,     0,  1501,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,     0,     0,  -851,   528,  -851,  -851,  -851,
       0,     0,  -851,  -851,  -851,  -851,     0,     0,     0,  -851,
    -851,     0,   528,     0,     0,   528,  -851,     0,     0,  -851,
    -851,   455,     0,     0,  -851,     0,     0,     0,     0,  -851,
    -851,     0,     0,     0,     0,  -851,     0,     0,     0,  -851,
       0,     0,     0,  -851,  -851,  1119,  -851,     0,  -851,  -851,
       0,     0,     0,  -851,  -851,     0,     0,  -851,  -851,  -851,
    -851,  -851,  -851,     0,     0,  -851,     0,     0,     0,     0,
    -851,  -851,     0,     0,  -851,     0,     0,     0,     0,  -851,
       0,     0,  -851,     0,     0,     0,     0,  -851,  -851,  -851,
    -851,  -851,     0,  -851,  -851,  -851,  -851,  -851,     0,     0,
       0,     0,  -851,  -851,  -851,     0,  -851,  -851,  -851,  -851,
    -851,  -851,     0,  -851,     0,  -851,     0,     0,     0,     0,
    -851,  -851,  -851,     0,     0,  1598,     0,     0,     0,  1600,
       0,     0,     0,  1603,     0,  1605,  -851,  1606,  -851,     0,
    -851,     0,     0,  1610,     0,     0,     0,     0,     0,     0,
       0,  1615,  -851,     0,     0,     0,     0,  -851,     0,  1619,
    1621,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1470,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1641,
    1642,  1643,  1644,     0,  1646,  1647,     0,  1648,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1656,     0,  -851,     0,  -851,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1695,     0,  1696,     0,     0,
    1698,     0,     0,     0,     0,     0,     0,     0,  1701,     0,
       0,     0,     0,  1703,  1621,     0,     0,     0,     0,     0,
       0,  1707,     0,     0,     0,  1711,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1723,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1728,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1747,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1707,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1786,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1797,     0,     0,     0,     0,  1802,
       0,     0,     0,     0,  1786,     0,     0,   871,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     0,     0,  1802,
       0,     0,     0,  1811,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   552,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   553,   554,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   556,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   520,   521,   522,   176,   177,   523,   558,   180,
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
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
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
       0,     0,   129,     0,   130,   131,     0,   132,   133,     0,
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
     245,   246,   247,   248,   249,   250,   251,     0,   605,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   412,    28,    29,
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
     128,     0,   547,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
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
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   412,    28,    29,
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
     128,     0,   809,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
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
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,  1098,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
    1099,  1100,    50,    51,    52,    53,    54,    55,    56,    57,
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
     128,     0,   809,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,  1101,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,  1098,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
    1099,  1100,    50,    51,    52,    53,    54,    55,    56,    57,
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
     128,     0,   547,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,  1101,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   412,    28,    29,
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
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
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
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
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
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
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
       0,    12,   411,     0,    14,    15,    16,    17,    18,    19,
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
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
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
       0,   878,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   412,    28,    29,
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
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
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
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,  1098,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
    1099,  1100,    50,    51,    52,    53,    54,    55,    56,    57,
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
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,  1101,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   552,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     553,   554,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,   557,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   520,   521,   522,   176,
     177,   523,   558,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   552,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     553,   554,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,   562,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   520,   521,   522,   176,
     177,   523,   558,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   552,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     553,   554,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   520,   521,   522,   176,
     177,   523,   558,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   600,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   552,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     553,   554,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   520,   521,   522,   176,
     177,   523,   558,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,   602,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   552,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     553,   554,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,   923,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   520,   521,   522,   176,
     177,   523,   558,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   552,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     553,   554,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,   929,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   520,   521,   522,   176,
     177,   523,   558,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   552,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     553,   554,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,   933,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   520,   521,   522,   176,
     177,   523,   558,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   489,    25,   491,   412,    28,   492,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   494,     0,    45,    46,    47,
     496,   497,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   506,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   682,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   683,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   515,   160,   516,   162,   517,   518,   165,   166,
     167,   168,   169,   170,   519,   172,   520,   521,   522,   176,
     177,   523,   524,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   525,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   552,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     553,   554,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   520,   521,   522,   176,
     177,   523,   558,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   489,    25,   491,   412,    28,   492,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   494,     0,    45,    46,    47,
     496,   497,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   506,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   515,   160,   516,   162,   517,   518,   165,   166,
     167,   168,   169,   170,   519,   172,   520,   521,   522,   176,
     177,   523,   524,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   525,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   489,    25,   491,   412,    28,   492,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   494,     0,    45,    46,    47,
     496,   497,    50,   498,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   506,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,     0,     0,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   515,   160,   516,   162,   517,   518,   165,   166,
     167,   168,   169,   170,   519,   172,   520,   521,   522,   176,
     177,   523,   524,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   525,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   489,    25,   491,   412,    28,   492,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   494,     0,    45,    46,    47,
     496,   497,    50,   498,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   506,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,     0,     0,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,     0,
       0,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   515,   160,   516,   162,   517,   518,   165,   166,
     167,   168,   169,   170,   519,   172,   520,   521,   522,   176,
     177,   523,   524,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   525,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   489,    25,   491,   412,    28,   492,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   494,     0,    45,    46,    47,
     496,   497,    50,   498,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   506,     0,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,     0,   106,
     107,   556,   109,     0,   110,   111,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,     0,     0,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,     0,
       0,     0,   134,     0,   135,     0,   136,     0,   138,     0,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   515,   160,   516,   162,   517,   518,   165,   166,
     167,   168,   169,   170,   519,   172,   520,   521,   522,   176,
     177,   523,   524,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   525,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,   410,   411,     0,    14,    15,    16,   486,    18,    19,
      20,   487,    22,   488,   489,   490,   491,   412,    28,   492,
      30,    31,     0,    32,    33,    34,    35,   493,    37,    38,
      39,    40,    41,    42,    43,   494,     0,    45,   495,    47,
     496,   497,    50,   498,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   499,   500,
      68,     0,    69,    70,    71,   501,     0,     0,    74,    75,
      76,     0,     0,   502,    78,     0,     0,     0,     0,    80,
     503,    82,   504,   505,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   506,    97,    98,   507,   508,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
     107,     0,     0,     0,     0,     0,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   509,   120,   121,
     510,     0,     0,     0,     0,     0,     0,     0,   511,   512,
     128,     0,     0,     0,   129,     0,   130,   513,     0,     0,
       0,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     514,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,     0,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   515,   160,   516,   162,   517,   518,   165,   166,
     167,   168,   169,   170,   519,   172,   520,   521,   522,   176,
     177,   523,   524,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     0,     0,
       1,     2,   245,   525,   247,   248,   249,   250,   251,     3,
       0,     0,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,   410,   411,     0,    14,    15,    16,   534,    18,
      19,    20,   487,   535,   536,   489,   490,   491,   412,    28,
     492,    30,    31,     0,    32,    33,    34,    35,   537,    37,
     538,   539,    40,    41,    42,    43,   494,     0,    45,   540,
      47,   496,   497,    50,   498,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   499,
     500,    68,     0,    69,    70,    71,   541,     0,     0,    74,
      75,    76,     0,     0,   502,    78,     0,     0,     0,     0,
      80,   503,    82,   504,   505,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   506,    97,    98,   507,   508,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   509,   120,
     121,   510,     0,     0,     0,     0,     0,     0,     0,   511,
     512,   128,     0,     0,     0,   129,     0,   130,   513,     0,
       0,     0,     0,   134,     0,   135,     0,   136,   137,   138,
     139,   514,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,     0,     0,   413,   151,   152,   153,   154,   155,
     156,   157,   158,   515,   542,   516,   162,   517,   518,   165,
     166,   167,   168,   169,   170,   519,   172,   520,   521,   522,
     176,   177,   523,   524,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     0,   567,   245,   525,   247,   248,   249,   250,   251,
       7,     8,     0,     0,     0,   784,     0,     0,     0,   410,
     411,     0,    14,    15,    16,   534,    18,    19,    20,   487,
     535,   536,   489,   490,   491,   412,    28,   492,    30,    31,
       0,    32,    33,    34,    35,   537,    37,   538,   539,    40,
      41,    42,    43,   494,     0,    45,   540,    47,   496,   497,
      50,   498,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   499,   500,    68,     0,
      69,    70,    71,   541,     0,     0,    74,    75,    76,     0,
       0,   502,    78,     0,     0,     0,     0,    80,   503,    82,
     504,   505,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   506,    97,    98,   507,   508,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   509,   120,   121,   510,     0,
       0,     0,     0,     0,     0,     0,   511,   512,   128,     0,
       0,     0,   129,   785,   130,   513,     0,     0,     0,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   514,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,     0,
       0,   413,   151,   152,   153,   154,   155,   156,   157,   158,
     515,   542,   516,   162,   517,   518,   165,   166,   167,   168,
     169,   170,   519,   172,   520,   521,   522,   176,   177,   523,
     524,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,     0,     0,   567,
     245,   525,   247,   248,   249,   250,   251,     7,     8,     0,
       0,     0,     0,     0,     0,     0,   410,   411,     0,    14,
      15,    16,   534,    18,    19,    20,   487,   535,   536,   489,
     490,   491,   412,    28,   492,    30,    31,     0,    32,    33,
      34,    35,   537,    37,   538,   539,    40,    41,    42,    43,
     494,     0,    45,   540,    47,   496,   497,    50,   498,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   499,   500,    68,     0,    69,    70,    71,
     541,     0,     0,    74,    75,    76,     0,     0,   502,    78,
       0,     0,     0,     0,    80,   503,    82,   504,   505,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   506,    97,
      98,   507,   508,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,   107,     0,     0,     0,     0,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   509,   120,   121,   510,     0,     0,     0,     0,
       0,     0,     0,   511,   512,   128,     0,     0,     0,   129,
       0,   130,   513,     0,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   514,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,     0,     0,   413,   151,
     152,   153,   154,   155,   156,   157,   158,   515,   542,   516,
     162,   517,   518,   165,   166,   167,   168,   169,   170,   519,
     172,   520,   521,   522,   176,   177,   523,   524,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,     0,     0,     0,   245,   525,   247,
     248,   249,   250,   251,   570,   571,     0,     0,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   410,
     411,     0,    14,    15,    16,   534,    18,    19,    20,   487,
     535,   536,   489,   490,   491,   412,    28,   492,    30,    31,
       0,    32,    33,    34,    35,   537,    37,   538,   539,    40,
      41,    42,    43,   494,     0,    45,   540,    47,   496,   497,
      50,   498,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   499,   500,    68,     0,
      69,    70,    71,   541,     0,     0,    74,    75,    76,     0,
       0,   502,    78,     0,     0,     0,     0,    80,   503,    82,
     504,   505,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   506,    97,    98,   507,   508,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   509,   120,   121,   510,     0,
       0,     0,     0,     0,     0,     0,   511,   512,   128,     0,
       0,     0,   129,     0,   130,   513,     0,     0,     0,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   514,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,     0,
       0,   413,   151,   152,   153,   154,   155,   156,   157,   158,
     515,   542,   516,   162,   517,   518,   165,   166,   167,   168,
     169,   170,   519,   172,   520,   521,   522,   176,   177,   523,
     524,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,     0,     0,     0,
     245,   525,   247,   248,   249,   250,   251,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   410,
     411,     0,    14,    15,    16,   834,    18,    19,    20,    21,
     535,   835,   489,    25,   491,   412,    28,   492,    30,    31,
       0,    32,    33,    34,    35,   836,    37,   538,   539,    40,
      41,    42,    43,   494,     0,    45,   837,    47,   496,   497,
      50,   498,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   499,   500,    68,     0,
      69,    70,    71,   838,     0,     0,    74,    75,    76,     0,
       0,   502,    78,     0,     0,     0,    79,    80,   503,    82,
     504,   505,    85,    86,   555,    88,     0,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   506,    97,    98,   507,   508,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   556,
     109,     0,   110,   111,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   510,     0,
     123,     0,     0,     0,     0,     0,   511,   512,   128,     0,
       0,     0,   129,     0,   130,   513,     0,     0,     0,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   413,   151,   152,   153,   154,   155,   156,   157,   158,
     515,   542,   516,   162,   517,   518,   165,   166,   167,   168,
     169,   170,   519,   172,   520,   521,   522,   176,   177,   523,
     524,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     0,   244,     0,
     245,   525,   247,   248,   249,   250,   251,     7,     8,     0,
       0,     0,     0,     0,     0,     0,   410,   411,     0,    14,
      15,    16,   486,    18,    19,    20,   487,    22,   488,   489,
    1141,   491,   412,    28,   492,    30,    31,     0,    32,    33,
      34,    35,   493,    37,    38,    39,    40,    41,    42,    43,
     494,     0,    45,   495,    47,   496,   497,    50,   498,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   499,   500,    68,     0,    69,    70,    71,
     501,     0,     0,    74,    75,    76,     0,     0,   502,    78,
       0,     0,     0,     0,    80,   503,    82,   504,   505,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   506,    97,
      98,   507,   508,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,  1142,     0,     0,     0,  1143,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   509,   120,   121,   510,     0,     0,     0,     0,
       0,     0,     0,   511,   512,   128,     0,     0,     0,   129,
    1569,   130,   513,     0,     0,     0,     0,  1570,     0,   135,
       0,   136,   137,   138,   139,   514,   141,   142,   143,   144,
     145,   146,     0,     0,  1144,   148,     0,     0,   413,   151,
     152,   153,   154,   155,   156,   157,   158,   515,   160,   516,
     162,   517,   518,   165,   166,   167,   168,   169,   170,   519,
     172,   520,   521,   522,   176,   177,   523,   524,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,     0,     7,     8,   245,   525,   247,
    1145,  1146,  1147,  1148,   410,   411,     0,    14,    15,    16,
     534,    18,    19,    20,   487,   535,   536,   489,   490,   491,
     412,    28,   492,    30,    31,     0,    32,    33,    34,    35,
     537,    37,   538,   539,    40,    41,    42,    43,   494,     0,
      45,   540,    47,   496,   497,    50,   498,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   499,   500,    68,     0,    69,    70,    71,   541,     0,
       0,    74,    75,    76,     0,     0,   502,    78,     0,     0,
       0,     0,    80,   503,    82,   504,   505,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   506,    97,    98,   507,
     508,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,   107,     0,     0,     0,     0,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     509,   120,   121,   510,     0,     0,     0,     0,     0,     0,
       0,   511,   512,   128,     0,     0,     0,   129,   754,   130,
     513,     0,     0,     0,     0,   755,     0,   135,     0,   136,
     137,   138,   139,   514,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,     0,     0,   413,   151,   152,   153,
     154,   155,   156,   157,   158,   515,   542,   516,   162,   517,
     518,   165,   166,   167,   168,   169,   170,   519,   172,   520,
     521,   522,   176,   177,   523,   524,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,     0,     7,     8,   245,   525,   247,   248,   249,
     250,   251,   410,   411,     0,    14,    15,    16,   534,    18,
      19,    20,   487,   535,   536,   489,   490,   491,   412,    28,
     492,    30,    31,     0,    32,    33,    34,    35,   537,    37,
     538,   539,    40,    41,    42,    43,   494,     0,    45,   540,
      47,   496,   497,    50,   498,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   499,
     500,    68,     0,    69,    70,    71,   541,     0,     0,    74,
      75,    76,     0,     0,   502,    78,     0,     0,     0,     0,
      80,   503,    82,   504,   505,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   506,    97,    98,   507,   508,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   509,   120,
     121,   510,     0,     0,     0,     0,     0,     0,     0,   511,
     512,   128,     0,     0,     0,   129,   802,   130,   513,     0,
       0,     0,     0,   803,     0,   135,     0,   136,   137,   138,
     139,   514,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,     0,     0,   413,   151,   152,   153,   154,   155,
     156,   157,   158,   515,   542,   516,   162,   517,   518,   165,
     166,   167,   168,   169,   170,   519,   172,   520,   521,   522,
     176,   177,   523,   524,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     7,     8,   245,   525,   247,   248,   249,   250,   251,
     410,   411,     0,    14,    15,    16,   486,    18,    19,    20,
     487,    22,   488,   489,  1141,   491,   412,    28,   492,    30,
      31,     0,    32,    33,    34,    35,   493,    37,    38,    39,
      40,    41,    42,    43,   494,     0,    45,   495,    47,   496,
     497,    50,   498,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   499,   500,    68,
       0,    69,    70,    71,   501,     0,     0,    74,    75,    76,
       0,     0,   502,    78,     0,     0,     0,     0,    80,   503,
      82,   504,   505,    85,    86,  1488,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   506,    97,    98,   507,   508,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,  1142,
       0,     0,     0,  1143,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   509,   120,   121,   510,
       0,     0,     0,     0,     0,     0,     0,   511,   512,   128,
       0,     0,     0,   129,     0,   130,   513,     0,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   514,
     141,   142,   143,   144,   145,   146,     0,     0,  1144,   148,
       0,     0,   413,   151,   152,   153,   154,   155,   156,   157,
     158,   515,   160,   516,   162,   517,   518,   165,   166,   167,
     168,   169,   170,   519,   172,   520,   521,   522,   176,   177,
     523,   524,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,     0,     7,
       8,   245,   525,   247,  1145,  1146,  1147,  1148,   410,   411,
       0,    14,    15,    16,   486,    18,    19,    20,   487,    22,
     488,   489,  1141,   491,   412,    28,   492,    30,    31,     0,
      32,    33,    34,    35,   493,    37,    38,    39,    40,    41,
      42,    43,   494,     0,    45,   495,    47,   496,   497,    50,
     498,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   499,   500,    68,     0,    69,
      70,    71,   501,     0,     0,    74,    75,    76,     0,     0,
     502,    78,     0,     0,     0,     0,    80,   503,    82,   504,
     505,    85,    86,  1626,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     506,    97,    98,   507,   508,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,  1142,     0,     0,
       0,  1143,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   509,   120,   121,   510,     0,     0,
       0,     0,     0,     0,     0,   511,   512,   128,     0,     0,
       0,   129,     0,   130,   513,     0,     0,     0,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   514,   141,   142,
     143,   144,   145,   146,     0,     0,  1144,   148,     0,     0,
     413,   151,   152,   153,   154,   155,   156,   157,   158,   515,
     160,   516,   162,   517,   518,   165,   166,   167,   168,   169,
     170,   519,   172,   520,   521,   522,   176,   177,   523,   524,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     7,     8,   245,
     525,   247,  1145,  1146,  1147,  1148,   410,   411,     0,    14,
      15,    16,   486,    18,    19,    20,   487,    22,   488,   489,
    1141,   491,   412,    28,   492,    30,    31,     0,    32,    33,
      34,    35,   493,    37,    38,    39,    40,    41,    42,    43,
     494,     0,    45,   495,    47,   496,   497,    50,   498,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   499,   500,    68,     0,    69,    70,    71,
     501,     0,     0,    74,    75,    76,     0,     0,   502,    78,
       0,     0,     0,     0,    80,   503,    82,   504,   505,    85,
      86,  1630,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   506,    97,
      98,   507,   508,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,  1142,     0,     0,     0,  1143,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   509,   120,   121,   510,     0,     0,     0,     0,
       0,     0,     0,   511,   512,   128,     0,     0,     0,   129,
       0,   130,   513,     0,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   514,   141,   142,   143,   144,
     145,   146,     0,     0,  1144,   148,     0,     0,   413,   151,
     152,   153,   154,   155,   156,   157,   158,   515,   160,   516,
     162,   517,   518,   165,   166,   167,   168,   169,   170,   519,
     172,   520,   521,   522,   176,   177,   523,   524,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,     0,     7,     8,   245,   525,   247,
    1145,  1146,  1147,  1148,   410,   411,     0,    14,    15,    16,
     486,    18,    19,    20,   487,    22,   488,   489,  1141,   491,
     412,    28,   492,    30,    31,     0,    32,    33,    34,    35,
     493,    37,    38,    39,    40,    41,    42,    43,   494,     0,
      45,   495,    47,   496,   497,    50,   498,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   499,   500,    68,     0,    69,    70,    71,   501,     0,
       0,    74,    75,    76,     0,     0,   502,    78,     0,     0,
       0,     0,    80,   503,    82,   504,   505,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   506,    97,    98,   507,
     508,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,  1142,     0,     0,     0,  1143,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     509,   120,   121,   510,     0,     0,     0,     0,     0,     0,
       0,   511,   512,   128,     0,     0,     0,   129,     0,   130,
     513,     0,     0,     0,     0,     0,     0,   135,     0,   136,
     137,   138,   139,   514,   141,   142,   143,   144,   145,   146,
       0,     0,  1144,   148,     0,     0,   413,   151,   152,   153,
     154,   155,   156,   157,   158,   515,   160,   516,   162,   517,
     518,   165,   166,   167,   168,   169,   170,   519,   172,   520,
     521,   522,   176,   177,   523,   524,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,     0,     7,     8,   245,   525,   247,  1145,  1146,
    1147,  1148,   410,   411,     0,    14,    15,    16,   486,    18,
      19,    20,   487,    22,   488,   489,  1141,   491,   412,    28,
     492,    30,    31,     0,    32,    33,    34,    35,   493,    37,
      38,    39,    40,    41,    42,    43,   494,     0,    45,   495,
      47,   496,   497,    50,   498,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   499,
     500,    68,     0,    69,    70,    71,   501,     0,     0,    74,
      75,    76,     0,     0,   502,    78,     0,     0,     0,     0,
      80,   503,    82,   504,   505,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   506,    97,    98,   507,   508,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,  1142,     0,     0,     0,  1143,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   509,   120,
     121,   510,     0,     0,     0,     0,     0,     0,     0,   511,
     512,   128,     0,     0,     0,   129,     0,   130,   513,     0,
       0,     0,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   514,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,     0,     0,   413,   151,   152,   153,   154,   155,
     156,   157,   158,   515,   160,   516,   162,   517,   518,   165,
     166,   167,   168,   169,   170,   519,   172,   520,   521,   522,
     176,   177,   523,   524,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     7,     8,   245,   525,   247,  1145,  1146,  1147,  1148,
     410,   411,     0,    14,    15,    16,   534,    18,    19,    20,
     487,   535,   536,   489,   490,   491,   412,    28,   492,    30,
      31,     0,    32,    33,    34,    35,   537,    37,   538,   539,
      40,    41,    42,    43,   494,     0,    45,   540,    47,   496,
     497,    50,   498,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   499,   500,    68,
       0,    69,    70,    71,   541,     0,     0,    74,    75,    76,
       0,     0,   502,    78,     0,     0,     0,     0,    80,   503,
      82,   504,   505,    85,    86,  1235,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   506,    97,    98,   507,   508,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   509,   120,   121,   510,
       0,     0,     0,     0,     0,     0,     0,   511,   512,   128,
       0,     0,     0,   129,     0,   130,   513,     0,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   514,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
       0,     0,   413,   151,   152,   153,   154,   155,   156,   157,
     158,   515,   542,   516,   162,   517,   518,   165,   166,   167,
     168,   169,   170,   519,   172,   520,   521,   522,   176,   177,
     523,   524,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,     0,     7,
       8,   245,   525,   247,   248,   249,   250,   251,   410,   411,
       0,    14,    15,    16,   534,    18,    19,    20,   487,   535,
     536,   489,   490,   491,   412,    28,   492,    30,    31,     0,
      32,    33,    34,    35,   537,    37,   538,   539,    40,    41,
      42,    43,   494,     0,    45,   540,    47,   496,   497,    50,
     498,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   499,   500,    68,     0,    69,
      70,    71,   541,     0,     0,    74,    75,    76,     0,     0,
     502,    78,     0,     0,     0,     0,    80,   503,    82,   504,
     505,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     506,    97,    98,   507,   508,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,   107,     0,     0,
       0,     0,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   509,   120,   121,   510,     0,     0,
       0,     0,     0,     0,     0,   511,   512,   128,     0,     0,
       0,   129,     0,   130,   513,     0,     0,     0,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   514,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     413,   151,   152,   153,   154,   155,   156,   157,   158,   515,
     542,   516,   162,   517,   518,   165,   166,   167,   168,   169,
     170,   519,   172,   520,   521,   522,   176,   177,   523,   524,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     7,     8,   245,
     525,   247,   248,   249,   250,   251,   410,   411,     0,    14,
      15,    16,     0,    18,    19,    20,   487,     0,     0,   489,
     490,     0,   412,    28,   492,    30,    31,     0,    32,    33,
      34,    35,     0,    37,     0,     0,    40,    41,    42,    43,
     494,     0,    45,     0,    47,     0,     0,    50,   498,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   499,   500,    68,     0,    69,    70,    71,
       0,     0,     0,    74,    75,    76,     0,     0,   502,    78,
       0,     0,     0,     0,    80,   503,    82,   504,   505,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   506,    97,
      98,   507,   508,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,     0,     0,     0,     0,     0,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   509,   120,   121,   510,     0,     0,     0,     0,
       0,     0,     0,   511,   512,   128,     0,     0,     0,   129,
       0,   130,   513,     0,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   514,   141,   142,   143,   144,
     145,   146,     0,     0,     0,   148,     0,     0,   413,   151,
     152,   153,   154,   155,   156,   157,   158,   515,     0,   516,
     162,   517,   518,   165,   166,   167,   168,   169,   170,   519,
     172,   520,   521,   522,   176,   177,     0,   524,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,     0,     0,     0,   245,   525,   247,
     248,   249,   250,   251
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   685,   419,   420,     4,     5,     6,   179,     0,     4,
       5,     6,     4,     5,     6,     4,     5,     6,   421,   109,
     110,   669,   918,   919,   340,   311,     4,     5,     6,   260,
      12,  1033,   822,   670,   671,   672,   673,   779,   618,   619,
     259,   759,  1049,   291,   275,   905,   583,   133,  1288,   791,
     860,   759,   589,  1305,   616,   617,   618,   619,   461,   462,
     956,  1366,  1367,   805,   252,   253,   433,    73,  1073,     1,
       1,  1127,   940,    39,   990,   715,    29,   444,    44,    45,
      26,    27,   919,   616,   617,  1008,    26,    27,    36,  1318,
       9,    10,     1,    59,   990,    61,    62,  1399,   118,    36,
     282,    47,   469,     1,    70,     8,     1,    47,   108,     1,
      56,     1,    29,   107,  1010,  1591,   108,     1,   142,   108,
       1,    55,   107,    29,   225,     1,    93,  1023,    74,   956,
     108,    97,   225,    79,    74,     1,   648,   230,   650,   651,
     117,   653,     1,   655,   107,    30,    94,  1656,    96,   118,
     136,   663,   664,   243,   244,   130,   147,   110,    94,    96,
       1,   121,   953,   107,   160,   111,   112,   113,   416,   146,
     158,   124,   112,  1010,   965,   107,   107,   118,     1,     1,
       1,   131,   159,   156,   103,   100,  1023,     1,   176,   620,
       1,   217,   166,   624,    37,    38,   149,    40,    41,   147,
     153,   291,    96,   156,   123,   225,   125,   113,   182,     1,
     147,   147,    45,   314,    57,   201,   183,   194,   187,  1728,
     962,   314,   197,   107,   177,   188,  1531,     1,   254,    62,
       0,     1,     1,     1,   153,   147,     0,     1,   157,   233,
     190,   107,     1,   160,     1,    96,   190,  1143,   107,   273,
     235,    96,   252,   253,   160,   174,   256,   343,   440,   225,
     252,   253,  1738,  1503,   256,     1,   107,  1127,  1128,  1271,
     113,   186,   175,   233,  1016,   561,   195,  1506,  1285,  1069,
    1022,   190,   273,   217,   107,   107,   107,   307,  1590,   869,
     870,   291,   190,   107,   213,   190,   107,  1015,   190,   291,
     190,   549,   942,   187,  1309,  1013,   259,  1015,    73,   190,
    1226,  1179,  1235,  1318,   190,   107,  1143,   160,   169,  1375,
     254,   187,    87,   726,   169,   273,   416,  1035,   187,   214,
    1226,   107,   273,   107,   867,   868,   273,   107,   107,   107,
       1,   287,   348,   107,   185,   351,   111,   287,   107,   295,
     107,   317,   318,   319,   187,   295,   100,   303,   123,   449,
     125,   273,   256,   257,   187,   187,   187,  1263,   130,   459,
       1,   107,   107,   187,   777,   100,   187,   220,   468,    96,
     311,   313,   613,   614,  1689,   475,   476,   153,   636,   901,
       1,  1287,     1,     1,   484,   187,     1,   616,   617,  1651,
     107,   252,   253,   118,   255,    94,   773,   252,   253,   776,
     255,   262,   188,   187,   184,   184,   416,   605,   261,   187,
     184,   272,   118,    94,   416,   184,  1263,   272,   185,   107,
     147,    26,    27,   284,    94,   197,  1741,     1,   225,   284,
     227,    33,   186,   107,   210,   445,   107,   447,   184,    45,
    1287,    47,   187,   445,    76,   447,   445,    49,   447,   549,
     107,   186,    96,   154,    29,   156,   156,   445,    54,   447,
      56,   186,   153,   473,   158,   565,   107,   225,   478,   227,
     187,   473,   142,  1225,   473,  1725,   478,   577,   905,   478,
     186,   107,   176,    94,   107,   473,   107,   745,   107,   107,
     478,  1506,   107,    96,    52,   106,   156,   597,   598,   187,
     106,  1407,     5,   107,   100,  1375,     9,   112,   935,  1237,
     184,     5,   156,   184,  1384,     9,    29,   314,   107,   218,
     219,   153,  1112,  1113,  1114,  1395,    94,  1221,  1246,  1349,
     187,   142,  1352,   107,   233,   110,   237,   218,   219,   549,
    1112,  1113,  1114,   184,   147,  1092,   556,   549,   107,   124,
     963,   964,   233,    96,   556,   968,   314,   556,   191,   192,
    1407,   187,   168,   184,   187,   184,   184,   107,   556,   184,
     113,   129,   107,   348,   149,   269,   351,    94,   153,   147,
      94,   156,   276,   187,  1490,   998,   686,  1493,   598,   221,
     222,   691,   286,   689,   690,   605,   598,   110,   187,   598,
     858,  1613,   177,   605,    96,     9,   616,   617,   618,   619,
     184,   124,   156,   156,   616,   617,   618,   619,  1370,   611,
     123,   113,   125,    94,    28,   142,   636,   153,   187,   123,
     133,   125,   873,  1650,   636,   876,   149,    33,   867,   133,
     154,   169,   156,  1490,   137,   745,  1493,   187,   153,   153,
     153,   426,   187,    49,   429,   251,   106,   144,   433,   153,
     153,   436,   437,   118,   156,    45,   137,    47,   264,   444,
     266,   142,   177,   177,   202,   450,   451,   127,     9,    10,
     455,   277,   278,   279,   210,   281,   118,   283,   463,   176,
    1560,  1716,  1717,    53,   469,   470,   471,   472,    58,    79,
    1127,  1128,   477,     9,  1504,   268,     1,   194,     3,  1509,
     485,   100,   275,   813,   814,   815,   156,   817,    53,   123,
     156,   125,    28,    58,   113,    42,   106,  1455,  1386,    46,
     134,   148,  1757,   158,    51,   745,    96,    24,  1763,   148,
     247,   248,    77,   745,   158,    94,  1440,    34,   165,   153,
     156,   176,    69,   122,   156,   530,   165,   106,    96,   769,
     122,    96,   176,   270,   769,  1355,  1672,   769,  1674,   544,
     769,    66,   103,    60,   199,   113,    71,   128,   129,   137,
     555,   769,    42,   118,   153,   199,    46,   156,   168,   799,
     800,    51,   123,   263,   125,   153,   136,   799,   800,  1705,
     799,   800,   100,  1129,   274,   118,   182,  1103,   583,    69,
     150,   799,   800,    95,   589,   113,   182,   123,   593,   125,
     196,   263,   153,   118,   106,  1672,   157,  1674,   134,  1735,
     196,  1004,   274,  1006,   116,   269,  1636,   100,   153,  1097,
    1640,   156,   276,   174,  1750,   127,  1752,   153,   858,   156,
     113,   168,   286,  1266,   171,   154,   858,   156,  1705,    26,
      27,   122,     9,    10,   195,     9,    10,   201,  1109,   186,
      37,    38,   299,    40,    41,   232,   210,   234,   100,   100,
      47,   308,   213,  1056,   122,  1058,   878,   100,  1735,    56,
      57,   113,   113,  1551,  1552,   212,   122,  1544,   692,  1593,
     113,   695,   122,  1750,   698,  1752,    42,    74,   168,   137,
      46,   171,    79,   122,   142,    51,   277,   278,   279,  1101,
    1720,   122,   283,   137,  1106,    53,   186,   122,   142,   153,
      58,   347,   156,    69,   350,   153,   153,  1689,   156,   156,
     221,   222,   223,   153,   111,   112,   113,   722,  1375,  1362,
     128,   129,   212,   232,   122,   234,   103,  1384,   122,   103,
     122,   736,   667,   668,   153,   740,   741,   216,  1395,   156,
     674,   675,   118,   676,   677,   241,   123,   241,   125,   123,
     242,   125,  1219,  1220,  1581,  1582,   156,   153,   763,   314,
     765,     0,   190,   160,   167,    92,   249,    99,   773,    50,
    1694,   776,  1660,  1661,   200,   780,   153,  1265,   101,   153,
     157,   102,   193,   157,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,   154,   145,  1126,   174,   184,   156,
     174,   184,   168,   184,    29,   171,    47,   152,   118,   246,
     284,  1051,   187,   284,   118,  1739,   821,   304,   195,  1051,
     186,   195,  1051,   220,   153,     1,   118,   142,   107,  1472,
     156,   187,   156,  1051,   153,   153,   213,   142,   184,   213,
     156,   121,   156,  1731,   156,   156,   212,   156,   156,    73,
     153,    35,    17,   214,    29,   860,   187,  1097,   231,   230,
    1348,   245,   190,    87,   261,  1097,     3,   118,   190,   168,
     170,    70,  1112,  1113,  1114,   170,   231,    94,    94,    94,
    1112,  1113,  1114,   888,   149,   107,  1810,   111,  1812,  1111,
     287,    29,  1535,   107,   160,   132,   160,  1821,   295,   123,
     132,   125,   246,  1560,   127,    94,   303,   142,   140,   141,
     299,   143,   118,   918,   919,   920,   921,   184,   187,   151,
     132,   184,   107,   155,    94,   157,   187,    96,    45,    96,
     162,   187,   187,   187,   187,   184,   184,    94,   225,   237,
     153,   231,   153,   153,   153,   153,   153,   179,   142,   233,
     190,   956,    33,     1,   118,   132,   142,    29,    94,   227,
      94,   286,   299,   153,   127,   970,   170,   118,   147,   254,
     118,   203,   204,   205,   206,   207,   208,   198,    94,   184,
     132,    96,   160,   132,   184,   153,   118,   147,   100,  1229,
     995,   100,   184,   190,  1229,   153,  1484,  1229,   142,  1004,
    1229,  1006,   121,  1008,    35,  1010,    29,   118,   153,   156,
     156,  1229,   245,   156,  1344,  1345,  1346,    79,  1023,   107,
     107,   267,   258,   285,   144,  1265,   260,   156,   156,   156,
     156,   156,   156,  1265,   156,    29,  1276,    29,    29,   286,
     227,  1276,   287,   144,  1276,   147,   306,  1276,   190,   127,
     147,  1056,   187,  1058,   187,  1295,   187,   187,  1276,   118,
    1295,   147,   118,  1295,    77,   107,  1295,   142,   100,   187,
     184,   132,     7,   106,   187,  1315,    96,  1295,   233,   233,
     233,   237,   190,  1315,   187,   286,  1315,  1092,   198,   250,
     186,   250,   233,   147,   282,    78,   187,  1315,   187,    29,
      29,   107,   187,   187,   187,   187,   170,  1347,  1348,   271,
     187,   184,   147,   147,   126,  1347,  1348,  1122,  1347,   126,
      96,   184,    94,  1611,   348,   316,   186,   351,   186,   186,
     280,   186,   184,   184,  1622,  1623,   257,  1625,  1143,   142,
     184,   187,   153,    29,  1632,    96,   187,   287,   170,   147,
      53,    94,   197,   106,    94,   198,   186,   186,    29,   265,
     107,   107,   118,   118,   118,   186,    94,    94,   186,   197,
     197,   186,   225,    93,   183,   225,   118,   118,   197,   118,
     256,   186,   305,   199,   186,   186,   225,   287,   293,   256,
     259,   725,  1182,   957,   420,  1024,   440,  1226,   305,  1694,
    1739,   425,   426,   861,  1021,   429,   305,   782,   306,   433,
    1465,   306,   436,   437,   306,  1255,  1118,   455,  1371,  1369,
     444,  1366,  1277,  1282,   544,  1713,   450,   451,  1285,   647,
    1235,   455,  1290,   646,  1239,   921,  1724,   666,   700,   463,
    1309,   335,   822,  1763,  1484,   469,   470,   471,   472,  1254,
    1757,  1006,  1484,   477,  1181,   448,  1340,  1350,  1263,  1349,
    1560,   485,  1384,  1751,  1395,   448,  1557,  1128,  1388,  1137,
     989,  1584,  1277,  1385,  1430,    -1,  1204,    -1,    -1,    -1,
     587,    -1,  1287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1783,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   530,    -1,    -1,    -1,
      -1,  1316,    -1,    -1,    -1,    -1,  1804,    -1,    -1,    -1,
     544,  1809,  1652,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   555,    -1,    -1,    -1,  1340,    -1,    -1,    -1,    -1,
    1670,    -1,    -1,    -1,  1349,    -1,    -1,  1352,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,   593,
      -1,  1611,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1611,
      -1,    -1,  1622,  1623,    -1,  1625,    -1,    -1,    -1,    -1,
    1622,  1623,  1632,  1625,    -1,    -1,    -1,    -1,    -1,    -1,
    1632,    -1,  1407,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1462,  1463,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1713,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1713,    -1,  1488,  1724,  1490,    -1,    -1,  1493,    -1,
      -1,    -1,  1724,    -1,    -1,   719,    -1,    -1,   722,    -1,
    1505,    -1,    -1,    -1,    -1,  1510,    -1,    -1,    -1,    -1,
      -1,  1751,   736,    -1,    -1,    -1,   740,   741,    -1,  1751,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   763,
      -1,   765,    -1,  1783,    -1,    -1,    -1,    -1,    -1,   773,
      -1,  1783,   776,    -1,    -1,    -1,   780,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1804,    -1,    -1,    -1,    -1,  1809,
      -1,    -1,  1804,    -1,    -1,    -1,    -1,  1809,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   821,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1626,    -1,  1628,    -1,  1630,    -1,    -1,    -1,    -1,
      -1,    -1,  1637,    -1,    -1,    -1,   860,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   888,    -1,    -1,  1672,    -1,  1674,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1690,    -1,    -1,  1693,    -1,
      -1,    -1,    -1,    -1,   918,   919,   920,   921,    -1,    -1,
    1705,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1715,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1735,    -1,   956,    -1,    -1,    -1,    -1,    -1,  1743,    -1,
      -1,    -1,    -1,  1748,    -1,  1750,   970,  1752,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   995,    -1,    -1,    -1,  1780,    -1,    -1,    -1,    -1,
    1004,    -1,  1006,    -1,  1008,    -1,  1010,    -1,    -1,    -1,
      -1,  1796,    -1,    -1,    -1,  1800,    -1,    -1,    -1,  1023,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1816,   556,    -1,  1819,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1056,    -1,  1058,    -1,    -1,   581,   582,    -1,
      -1,   585,   586,   587,   588,    -1,   590,    -1,    -1,    -1,
      -1,    -1,   596,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     604,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   626,   627,   628,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   636,   637,    -1,    -1,    -1,    -1,  1122,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1143,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   697,    -1,    -1,   700,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   738,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1235,    -1,    -1,    -1,  1239,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1254,    -1,    -1,    -1,    -1,    -1,    -1,   781,    -1,  1263,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1277,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   806,  1287,    -1,    -1,   810,   811,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   819,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1316,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1340,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1349,    -1,    -1,  1352,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   890,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1407,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1436,    -1,   958,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1462,  1463,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   993,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1488,    -1,  1490,    -1,  1012,  1493,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1505,    -1,    -1,    -1,    -1,  1510,    -1,    -1,    -1,
    1034,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1045,  1046,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1060,    -1,    -1,  1063,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1079,  1080,  1081,    -1,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,    -1,    -1,
    1094,  1095,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1626,    -1,  1628,    -1,  1630,    -1,    -1,    -1,
      -1,    -1,    -1,  1637,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1169,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1672,    -1,
    1674,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1690,    -1,    -1,  1693,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1705,    -1,     0,     1,    -1,     3,    -1,    -1,    -1,
      -1,  1715,    -1,    -1,    -1,    -1,    -1,  1241,    -1,  1243,
      -1,  1245,    -1,    -1,  1248,    -1,    -1,    -1,    -1,  1253,
      -1,  1735,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1743,
      -1,  1265,    -1,    -1,  1748,    42,  1750,    -1,  1752,    46,
    1274,    -1,    -1,    50,    51,    -1,  1280,  1281,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    69,    -1,    71,  1299,  1780,    -1,  1302,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1796,    -1,    -1,    92,  1800,    94,    95,    96,
      -1,    -1,    99,   100,   101,   102,    -1,    -1,    -1,   106,
     107,    -1,  1816,    -1,    -1,  1819,   113,    -1,    -1,   116,
     117,   118,    -1,    -1,   121,    -1,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,   136,
      -1,    -1,    -1,   140,   141,  1369,   143,    -1,   145,   146,
      -1,    -1,    -1,   150,   151,    -1,    -1,   154,   155,   156,
     157,   158,   159,    -1,    -1,   162,    -1,    -1,    -1,    -1,
     167,   168,    -1,    -1,   171,    -1,    -1,    -1,    -1,   176,
      -1,    -1,   179,    -1,    -1,    -1,    -1,   184,   185,   186,
     187,   188,    -1,   190,   191,   192,   193,   194,    -1,    -1,
      -1,    -1,   199,   200,   201,    -1,   203,   204,   205,   206,
     207,   208,    -1,   210,    -1,   212,    -1,    -1,    -1,    -1,
     217,   218,   219,    -1,    -1,  1449,    -1,    -1,    -1,  1453,
      -1,    -1,    -1,  1457,    -1,  1459,   233,  1461,   235,    -1,
     237,    -1,    -1,  1467,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1475,   249,    -1,    -1,    -1,    -1,   254,    -1,  1483,
    1484,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1502,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1513,
    1514,  1515,  1516,    -1,  1518,  1519,    -1,  1521,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1536,    -1,   311,    -1,   313,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1599,    -1,  1601,    -1,    -1,
    1604,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1612,    -1,
      -1,    -1,    -1,  1617,  1618,    -1,    -1,    -1,    -1,    -1,
      -1,  1625,    -1,    -1,    -1,  1629,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1645,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1657,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1697,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1709,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1751,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1778,    -1,    -1,    -1,    -1,  1783,
      -1,    -1,    -1,    -1,  1788,    -1,    -1,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    12,    -1,    -1,  1803,
      -1,    -1,    -1,  1807,    20,    21,    22,    23,    24,    25,
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
     186,    -1,   188,   189,    -1,   191,   192,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
     186,    -1,   188,   189,    -1,   191,   192,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,   321,   322,    11,    12,    -1,
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
      -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,    -1,
     194,    -1,   196,    -1,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    -1,    -1,   211,   212,   213,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,    -1,   312,    -1,
     314,   315,   316,   317,   318,   319,   320,    -1,   322,    11,
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
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     182,    -1,    -1,   185,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,   313,   314,   315,   316,   317,   318,   319,   320,    11,
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
     182,    -1,   184,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
      -1,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
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
      -1,    -1,    -1,   135,    -1,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,    -1,   151,
     152,   153,   154,    -1,   156,   157,    -1,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,   194,    -1,   196,    -1,   198,    -1,   200,    -1,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,
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
      -1,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,    -1,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,    -1,    -1,
      11,    12,   314,   315,   316,   317,   318,   319,   320,    20,
      -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,
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
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
      -1,    -1,    -1,   194,    -1,   196,    -1,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,    -1,    -1,
     211,   212,    -1,    -1,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
      -1,    -1,    16,   314,   315,   316,   317,   318,   319,   320,
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
      -1,    -1,   186,   187,   188,   189,    -1,    -1,    -1,    -1,
      -1,    -1,   196,    -1,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    -1,    -1,   211,   212,    -1,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,    -1,    -1,    -1,    16,
     314,   315,   316,   317,   318,   319,   320,    24,    25,    -1,
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
      -1,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,
      -1,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,    -1,    -1,   211,   212,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,    -1,    -1,    -1,    -1,   314,   315,   316,
     317,   318,   319,   320,    18,    19,    -1,    -1,    -1,    -1,
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
      -1,    -1,   196,    -1,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    -1,    -1,   211,   212,    -1,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,    -1,    -1,    -1,    -1,
     314,   315,   316,   317,   318,   319,   320,    21,    22,    23,
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
      -1,    -1,   196,    -1,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    -1,    -1,   211,   212,   213,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,    -1,   312,    -1,
     314,   315,   316,   317,   318,   319,   320,    24,    25,    -1,
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
     187,   188,   189,    -1,    -1,    -1,    -1,   194,    -1,   196,
      -1,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,    -1,    -1,   211,   212,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,    -1,    -1,    24,    25,   314,   315,   316,
     317,   318,   319,   320,    33,    34,    -1,    36,    37,    38,
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
      -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,   188,
     189,    -1,    -1,    -1,    -1,   194,    -1,   196,    -1,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
      -1,    -1,   211,   212,    -1,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
     259,   260,   261,    -1,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,    -1,    -1,    24,    25,   314,   315,   316,   317,   318,
     319,   320,    33,    34,    -1,    36,    37,    38,    39,    40,
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
      -1,    -1,    -1,   194,    -1,   196,    -1,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,    -1,    -1,
     211,   212,    -1,    -1,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
      -1,    24,    25,   314,   315,   316,   317,   318,   319,   320,
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
      -1,    -1,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,    -1,    -1,    24,
      25,   314,   315,   316,   317,   318,   319,   320,    33,    34,
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
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,    -1,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,    -1,    -1,    24,    25,   314,
     315,   316,   317,   318,   319,   320,    33,    34,    -1,    36,
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
      -1,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,
      -1,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,    -1,    -1,   211,   212,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,    -1,    -1,    24,    25,   314,   315,   316,
     317,   318,   319,   320,    33,    34,    -1,    36,    37,    38,
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
     189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
      -1,    -1,   211,   212,    -1,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
     259,   260,   261,    -1,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,    -1,    -1,    24,    25,   314,   315,   316,   317,   318,
     319,   320,    33,    34,    -1,    36,    37,    38,    39,    40,
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
      -1,    -1,    -1,    -1,    -1,   196,    -1,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,    -1,    -1,
     211,   212,    -1,    -1,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
      -1,    24,    25,   314,   315,   316,   317,   318,   319,   320,
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
      -1,    -1,    -1,    -1,    -1,    -1,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
      -1,    -1,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,    -1,    -1,    24,
      25,   314,   315,   316,   317,   318,   319,   320,    33,    34,
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
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,    -1,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,    -1,    -1,    24,    25,   314,
     315,   316,   317,   318,   319,   320,    33,    34,    -1,    36,
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
      -1,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,
      -1,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,    -1,    -1,    -1,   212,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,    -1,    -1,    -1,    -1,   314,   315,   316,
     317,   318,   319,   320
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
     188,   189,   191,   192,   194,   196,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   211,   212,   213,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   259,   260,   261,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   312,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   335,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   356,   357,   358,   359,   360,   361,   365,   366,
     367,   371,   373,   374,   376,   383,   385,   388,   389,   390,
     392,   393,   394,   395,   396,   398,   399,   401,   402,   403,
     404,   405,   406,   408,   409,   412,   413,   414,   415,   420,
     422,   424,   425,   430,   449,   452,   456,   459,   460,   465,
     466,   467,   468,   470,   471,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   483,   484,   485,   486,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   519,   520,   521,   535,   536,
     538,   539,   540,   541,   542,   543,   544,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   564,   565,   566,
     567,   572,   573,   574,   575,   576,   577,   580,   638,   639,
     640,   641,   643,   644,   645,   646,   647,   654,   655,   656,
      33,    34,    49,   215,   391,   392,   393,   391,   391,   156,
     156,    37,    38,    40,    41,    47,    56,    57,    74,    79,
     111,   112,   113,   160,   220,   261,   287,   295,   303,   372,
     373,   377,   378,   379,   160,   153,   156,   153,   156,   153,
     156,     1,     3,    66,    71,   118,   417,   156,   380,   156,
      24,    34,    60,   118,   273,   429,   431,   432,   153,   156,
     156,   156,   118,   153,   156,   156,   156,    76,   153,   221,
     222,   122,   122,   122,   153,   156,    39,    43,    45,    46,
      47,    48,    51,    59,    67,    70,    72,    73,    75,    90,
      91,    97,   105,   112,   114,   115,   135,   138,   139,   169,
     172,   180,   181,   189,   202,   224,   226,   228,   229,   236,
     238,   239,   240,   243,   244,   315,   503,   654,   655,   122,
     118,   400,   122,   122,    39,    44,    45,    59,    61,    62,
      70,    97,   225,   654,   118,   122,   122,   184,   391,   393,
     413,   642,    48,    72,    73,   118,   153,   185,   244,   412,
     414,   424,   187,   412,   654,   153,   122,    16,   653,   654,
      18,    19,   654,   122,   122,   122,   495,   153,    30,   214,
     216,   225,   227,   314,   156,   225,   227,   314,   225,   314,
     225,   230,   314,   118,   241,   241,   242,   156,   153,   395,
     311,   412,   313,   412,   314,   322,   337,   337,     0,   339,
     340,    33,    49,   342,   359,     1,   190,   336,   190,   336,
     112,   374,   394,   412,   107,   190,     1,   107,   336,   190,
      42,    46,    51,    69,   168,   171,   186,   212,   407,   416,
     421,   422,   423,   437,   438,   442,   167,    92,   132,   140,
     141,   143,   151,   155,   157,   162,   179,   203,   204,   205,
     206,   207,   208,   487,   488,   249,    99,   158,   176,   199,
     117,   146,   159,   194,   201,   210,   136,   150,    50,   200,
     101,   102,   158,   176,   485,   193,   153,   492,   495,   191,
     192,   154,   507,   508,   503,   507,   503,   156,   507,   145,
     156,   184,   184,   184,   375,   510,   375,    29,   652,   182,
     196,   182,   196,   166,   182,   655,   654,   169,   202,    47,
     654,   152,   118,    45,    47,    79,   106,   168,   653,   221,
     222,   223,   246,   611,   654,   654,   304,   137,   142,   112,
     287,   295,   377,   653,   392,   393,   187,   392,    45,    62,
     187,   560,   561,   412,   187,   194,   654,   426,   427,   654,
     284,   284,   426,   118,   433,   118,   187,   381,   382,   153,
     397,   412,     1,   160,   652,   113,   160,   355,   652,   654,
     118,   142,   107,   412,    29,   187,   653,   654,   654,   450,
     451,   654,   392,   187,   412,   412,   562,   654,   392,   153,
     153,   412,   187,   194,   654,   654,   142,   450,   184,   184,
     121,   107,   184,   156,   156,   156,   654,   153,   185,   186,
     187,    35,   523,   524,   525,   412,     8,   175,    17,   412,
     214,    29,   413,   413,    39,    45,    59,    70,    97,   506,
     654,   187,   413,   413,   413,   642,   413,   506,   413,   231,
     230,   578,   579,   654,   190,   190,   413,   412,   393,   412,
     245,   410,   411,   311,   313,   413,   337,   190,   336,   190,
     336,     3,   343,   359,   389,   343,   359,   389,    33,   360,
     389,   360,   389,   400,   400,   413,   413,   413,   118,   168,
     170,   170,   394,   413,   413,   467,   468,   470,   470,   470,
     470,   469,   470,   470,   470,    70,   471,   475,   475,   474,
     476,   476,   476,   476,   477,   477,   478,   478,   231,    94,
      94,    94,   493,   184,   412,   495,   495,   412,   508,   187,
     413,   518,   149,   187,   518,   107,   187,   187,   107,   107,
     380,    29,   655,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,   362,   363,   364,    94,   137,   142,   368,
     369,   370,   654,   160,   160,   362,   652,   127,   132,    54,
      56,   100,   251,   264,   266,   277,   278,   279,   281,   283,
     612,   613,   614,   615,   616,   617,   624,   630,   631,   246,
      94,   299,   654,   142,   413,   118,   654,   654,   132,   184,
     184,   187,   187,   184,   107,   187,   107,   187,   107,    36,
      94,    96,   147,   428,   429,   545,   654,    55,   217,   254,
     418,   419,   654,    94,   107,   187,   391,   187,   653,    96,
      45,   653,   652,    96,   142,   545,   654,   413,   432,   184,
     187,   187,   187,   187,   107,   188,   147,   545,   184,   187,
     187,   153,   184,   392,   392,   184,   107,   187,   107,   187,
     142,   545,   413,   188,   413,   413,   412,   412,   412,   654,
     524,   525,   130,   197,   184,   184,   131,   190,    94,   218,
     219,   233,    94,   218,   219,   233,   233,   233,    94,    94,
     237,   225,   231,   107,   235,   142,   190,   187,    48,    72,
      73,   244,   414,   424,   184,   504,   584,   411,   233,   359,
      33,    33,   190,   336,   190,   113,     1,   654,   170,   413,
     443,   444,   118,   439,   440,   470,   153,   156,   259,   491,
     510,   585,   588,   589,   590,   591,   592,   596,   598,   600,
     601,    47,   152,   156,   211,   317,   318,   319,   320,   546,
     548,   550,   552,   568,   569,   570,   571,   648,   649,   650,
     651,   654,   546,   482,   551,   654,   482,   184,   185,   107,
     187,   187,   510,   148,   165,   148,   165,   137,   397,   380,
     363,   132,   548,   370,   413,   545,   652,   652,   128,   129,
     652,   277,   278,   279,   283,   654,   263,   274,   263,   274,
      29,   286,    96,   113,   156,   618,   621,   612,    39,    44,
      59,    61,    70,    97,   225,   317,   318,   319,   384,   552,
     648,   227,   299,   308,   413,   654,    94,   299,   652,   153,
     562,   563,   654,   562,   563,   118,   427,   127,   546,   118,
     413,   147,   429,   147,    36,   147,   428,   429,   147,   545,
     254,    53,    58,    77,   118,   428,   434,   435,   436,   419,
     545,   546,   382,    94,   184,   198,   132,   354,   652,   160,
     132,    96,   354,   413,   142,   429,   153,   118,   413,   413,
     147,   100,   453,   454,   455,   457,   458,   100,   461,   462,
     463,   464,   392,   184,   184,   153,   562,   562,   413,   142,
     190,   413,   121,   187,   187,   187,    35,   525,   130,   197,
       9,    10,   103,   123,   125,   153,   195,   520,   522,   533,
     534,   537,    29,   232,   234,   413,   413,   413,   232,   234,
     413,   413,   413,   413,   413,   413,   413,   413,   413,   506,
     118,   413,   413,   394,   156,   156,   156,   153,   186,   245,
     581,   582,   210,   395,   413,   190,   113,   389,   389,   389,
     443,    95,   106,   116,   127,   445,   446,   447,   448,   107,
     654,   107,   412,   585,   592,   153,   285,   472,   637,    96,
     169,   252,   253,   255,   262,   272,   284,   586,   587,   606,
     607,   608,   609,   632,   635,   258,   260,   593,   611,   267,
     597,   633,   247,   248,   270,   602,   603,   156,   156,   548,
     156,   156,   156,   156,   156,   144,   176,   194,   547,   144,
     413,   137,   397,   564,   369,   286,    29,    96,   113,   156,
     625,    29,   618,   547,   547,   493,   287,   306,   545,   384,
     227,   190,   391,   187,   187,   144,   187,   187,   427,   147,
     428,   654,   413,   147,   413,   127,   413,   147,   429,   147,
     413,   147,   118,   118,   413,   654,   436,    77,   546,   394,
     413,   652,   107,   354,   413,   142,   391,   451,   413,   413,
     113,   454,   455,   100,   186,   113,   455,   458,   118,   546,
     100,   113,   462,   100,   113,   464,   184,   391,   187,   187,
     413,   413,   198,   461,   132,   195,   522,     7,   392,   654,
     195,   533,   190,   233,   233,   233,   233,    96,   237,   237,
     579,   186,   412,   412,   412,   584,   582,   504,   652,   128,
     129,   447,   448,   448,   444,   106,   142,   441,   545,   440,
     184,   187,   585,   599,   250,   217,   254,   268,   275,   636,
      96,   256,   257,   634,   250,   589,   636,   474,   606,   590,
     147,   282,   594,   595,   634,   286,   605,    78,   604,   187,
     194,   546,   549,   187,   187,   187,   187,   187,   187,   187,
      29,   136,   201,   627,   628,   629,    29,   626,   627,   271,
     622,   107,   619,   170,   654,   257,   493,   184,   413,   147,
     413,   147,   428,   413,   147,   413,   413,   654,   654,   435,
     413,   126,   126,    96,   652,   413,   184,   186,   186,   413,
     394,   413,   186,   186,   654,   186,   118,   546,   118,   186,
     118,   546,   186,   184,   113,   525,   654,   195,   184,   525,
     654,   413,   413,   413,   413,   316,   413,   413,   413,   187,
     187,   187,   153,   583,   448,   652,   413,   142,   184,   476,
      52,   129,   474,   474,   269,   276,   286,   610,   610,   591,
     153,   280,    94,   187,   107,   187,   625,   625,   629,   107,
     187,    29,   623,   634,   620,   621,   187,   386,   387,   493,
     118,   225,   307,   287,   170,   413,   413,   147,   413,    53,
     394,   413,   354,   413,   394,    94,   394,   413,   654,   186,
     654,   413,   654,   186,   394,   118,    93,   183,   526,   525,
     654,   197,   525,   413,   198,   461,   412,   441,   413,   474,
     474,   199,   412,   546,   546,    94,    29,   265,   107,   107,
     448,   545,   654,   118,   225,   654,   386,   413,   118,   546,
      94,   186,    94,   654,     5,   133,   529,   530,   532,   534,
      28,   134,   527,   528,   531,   534,   197,   525,   197,   113,
     184,   441,   474,   184,   546,   621,   387,   448,   305,   654,
     118,   225,   654,   186,   546,   394,   413,   546,   186,    93,
     133,   532,   183,   134,   531,   197,   118,   413,   305,   654,
     118,   394,   413,   186,   186,   654,   293,   305,   654,   186,
     306,   413,   306,   493,   493,   199,   287,   654,   225,   118,
     654,   306,   493
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
     585,   586,   587,   588
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   334,   335,   335,   335,   335,   336,   337,   337,   337,
     337,   338,   338,   339,   339,   339,   339,   339,   339,   339,
     339,   340,   340,   340,   340,   341,   342,   342,   342,   343,
     343,   343,   343,   343,   344,   344,   344,   344,   344,   344,
     344,   344,   345,   345,   346,   347,   348,   348,   349,   349,
     350,   350,   351,   351,   351,   351,   352,   352,   352,   353,
     353,   353,   353,   354,   354,   355,   355,   356,   356,   356,
     356,   357,   358,   358,   359,   359,   359,   360,   360,   360,
     360,   360,   360,   360,   360,   361,   361,   362,   362,   363,
     364,   364,   364,   364,   364,   364,   364,   364,   364,   364,
     365,   366,   367,   368,   368,   369,   369,   369,   370,   371,
     371,   371,   372,   372,   372,   372,   373,   373,   374,   374,
     374,   374,   375,   375,   376,   376,   377,   377,   378,   378,
     379,   379,   380,   380,   380,   380,   381,   381,   382,   382,
     383,   383,   383,   383,   384,   384,   384,   384,   385,   385,
     386,   386,   387,   387,   387,   387,   388,   388,   388,   388,
     389,   390,   390,   390,   391,   391,   391,   392,   392,   393,
     393,   394,   394,   394,   394,   394,   394,   394,   394,   394,
     394,   394,   394,   395,   395,   396,   397,   398,   399,   399,
     399,   400,   400,   400,   400,   401,   402,   403,   404,   405,
     405,   406,   407,   408,   409,   410,   410,   411,   412,   412,
     412,   412,   413,   413,   413,   413,   413,   413,   414,   414,
     414,   414,   414,   414,   414,   414,   414,   414,   414,   414,
     415,   416,   417,   417,   418,   418,   418,   419,   419,   420,
     420,   421,   422,   422,   422,   423,   423,   423,   423,   423,
     424,   424,   425,   425,   425,   426,   426,   426,   427,   427,
     427,   427,   427,   427,   427,   427,   427,   427,   427,   427,
     428,   429,   430,   431,   431,   432,   432,   432,   432,   433,
     433,   434,   434,   434,   435,   435,   435,   436,   436,   436,
     437,   438,   439,   439,   440,   440,   440,   440,   440,   440,
     441,   442,   442,   443,   443,   444,   444,   445,   445,   445,
     445,   445,   445,   445,   446,   446,   447,   447,   448,   449,
     449,   450,   450,   451,   451,   452,   453,   453,   454,   455,
     455,   456,   457,   457,   458,   459,   459,   460,   460,   461,
     461,   462,   462,   463,   463,   464,   464,   465,   466,   466,
     467,   467,   468,   468,   468,   468,   468,   469,   468,   468,
     468,   468,   470,   470,   471,   471,   472,   472,   473,   473,
     474,   474,   474,   475,   475,   475,   475,   475,   476,   476,
     476,   477,   477,   477,   478,   478,   479,   479,   480,   480,
     481,   481,   482,   482,   483,   483,   484,   484,   484,   484,
     485,   485,   485,   486,   486,   487,   487,   487,   487,   487,
     487,   488,   488,   488,   489,   489,   489,   489,   490,   490,
     491,   491,   492,   492,   492,   493,   493,   493,   493,   494,
     495,   495,   495,   496,   496,   497,   497,   497,   497,   498,
     498,   499,   499,   499,   499,   499,   499,   499,   500,   500,
     501,   501,   502,   502,   502,   502,   502,   503,   503,   504,
     504,   505,   505,   505,   505,   506,   506,   506,   506,   507,
     507,   508,   509,   509,   509,   509,   509,   509,   509,   509,
     509,   509,   509,   509,   509,   509,   510,   510,   511,   511,
     511,   512,   513,   513,   514,   515,   516,   517,   517,   518,
     518,   519,   519,   520,   520,   520,   521,   521,   521,   521,
     521,   521,   522,   522,   523,   523,   524,   525,   525,   526,
     526,   527,   527,   528,   528,   528,   528,   529,   529,   530,
     530,   530,   530,   531,   531,   532,   532,   533,   533,   533,
     533,   534,   534,   534,   534,   535,   535,   536,   536,   537,
     538,   538,   538,   538,   538,   538,   539,   540,   540,   541,
     541,   542,   543,   544,   544,   545,   546,   546,   546,   547,
     547,   547,   548,   548,   548,   548,   548,   548,   548,   549,
     549,   550,   551,   552,   552,   552,   552,   552,   552,   552,
     552,   552,   553,   554,   554,   554,   555,   556,   557,   557,
     557,   558,   558,   558,   558,   558,   559,   560,   560,   560,
     560,   560,   560,   560,   561,   562,   563,   564,   565,   565,
     566,   567,   568,   568,   569,   570,   570,   571,   572,   572,
     572,   573,   573,   573,   573,   573,   573,   573,   573,   573,
     573,   574,   574,   575,   575,   576,   577,   578,   578,   579,
     580,   581,   581,   582,   583,   584,   584,   585,   586,   586,
     587,   587,   588,   588,   589,   589,   590,   590,   591,   591,
     592,   593,   593,   594,   594,   595,   596,   596,   596,   597,
     597,   598,   599,   599,   600,   601,   601,   602,   602,   603,
     603,   603,   604,   604,   605,   605,   606,   606,   606,   606,
     606,   607,   608,   609,   610,   610,   610,   611,   611,   612,
     612,   612,   612,   612,   612,   612,   612,   613,   613,   613,
     613,   614,   614,   615,   616,   616,   617,   617,   617,   618,
     618,   619,   619,   620,   620,   621,   622,   622,   623,   623,
     624,   624,   624,   625,   625,   626,   626,   627,   627,   628,
     628,   629,   629,   630,   631,   631,   632,   632,   632,   633,
     634,   634,   634,   634,   635,   635,   636,   636,   637,   638,
     638,   639,   639,   640,   640,   641,   642,   642,   643,   643,
     643,   644,   645,   646,   647,   648,   648,   648,   649,   650,
     651,   652,   653,   653,   654,   654,   654,   654,   654,   654,
     654,   654,   654,   654,   654,   654,   654,   654,   654,   654,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   656
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
       1,     4,     1,     2,     1,     2,     1,     1,     2,     2,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     5,     5,     6,     3,     4,
       1,     2,     3,     2,     2,     1,     2,     2,     1,     1,
       1,     3,     3,     1,     1,     1,     2,     1,     2,     2,
       1,     2,     2,     2,     2,     2,     2,     2,     1,     2,
       2,     1,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     4,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     1,     4,     4,     3,     4,     1,
       3,     1,     1,     1,     1,     1,     4,     5,     8,     9,
       9,    10,     1,     2,     1,     2,     6,     0,     1,     3,
       3,     0,     1,     1,     1,     2,     2,     0,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     2,     3,     3,     2,
       1,     1,     1,     1,     1,     1,     4,     3,     7,     3,
       7,     4,     4,     3,     7,     2,     1,     2,     3,     1,
       1,     1,     1,     1,     3,     3,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     4,     4,     3,     3,     3,     4,
       4,     3,     4,     6,     4,     6,     4,     3,     4,     6,
       6,     4,     6,     6,     4,     1,     2,     1,     1,     1,
       3,     3,     1,     1,     4,     5,     6,     3,     3,     3,
       3,     5,     7,     7,     5,     5,     5,     7,     7,     5,
       5,     3,     3,     5,     7,     5,     7,     1,     4,     3,
       5,     1,     2,     3,     3,     1,     3,     2,     0,     1,
       1,     2,     1,     3,     1,     3,     1,     4,     1,     2,
       3,     0,     1,     0,     1,     4,     2,     3,     1,     0,
       1,     4,     0,     1,     2,     1,     3,     0,     1,     2,
       2,     1,     0,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     1,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     2,     2,     3,     1,     2,     2,     5,     2,     1,
       1,     0,     2,     1,     3,     4,     0,     2,     0,     2,
       4,     4,     3,     2,     3,     1,     3,     0,     1,     1,
       2,     2,     2,     2,     1,     2,     2,     2,     2,     3,
       2,     3,     3,     4,     2,     2,     1,     1,     3,     2,
       3,     2,     3,     2,     3,     3,     3,     5,     5,     5,
       8,     5,     3,     5,     7,     1,     1,     1,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1
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
  "\"'!'\"", "\"'*'\"", "\"'</ (start tag end)'\"", "\"'strip'\"",
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
  "UNARY_PREC", "STEP_REDUCE", "SIMPLEMAPEXPR_REDUCE",
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
  "InstanceofExpr", "TreatExpr", "CastableExpr", "CastExpr", "SingleType",
  "UnaryExpr", "SignList", "ValueExpr", "SimpleMapExpr", "ValueComp",
  "NodeComp", "ValidateExpr", "ExtensionExpr", "Pragma_list", "Pragma",
  "PathExpr", "LeadingSlash", "RelativePathExpr", "StepExpr", "AxisStep",
  "ForwardStep", "ForwardAxis", "AbbrevForwardStep", "ReverseStep",
  "ReverseAxis", "NodeTest", "NameTest", "Wildcard", "FilterExpr",
  "PredicateList", "Predicate", "PrimaryExpr", "Literal", "NumericLiteral",
  "VarRef", "ParenthesizedExpr", "ContextItemExpr", "OrderedExpr",
  "UnorderedExpr", "FunctionCall", "ArgList", "Constructor",
  "DirectConstructor", "DirElemConstructor", "DirElemContentList",
  "DirAttributeList", "DirAttr", "OptionalBlank", "DirAttributeValue",
  "opt_QuoteAttrContentList", "QuoteAttrContentList",
  "opt_AposAttrContentList", "AposAttrContentList",
  "QuoteAttrValueContent", "AposAttrValueContent", "DirElemContent",
  "CommonContent", "DirCommentConstructor", "DirPIConstructor",
  "CDataSection", "ComputedConstructor", "CompDocConstructor",
  "CompElemConstructor", "CompAttrConstructor", "CompTextConstructor",
  "CompCommentConstructor", "CompPIConstructor", "TypeDeclaration",
  "SequenceType", "OccurrenceIndicator", "ItemType", "TypeList",
  "AtomicType", "SimpleType", "KindTest", "AnyKindTest", "DocumentTest",
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
       335,     0,    -1,   337,    -1,   321,   337,    -1,   322,   337,
      -1,   321,   322,   337,    -1,     1,     3,    -1,   339,    -1,
     338,   339,    -1,   340,    -1,   338,   340,    -1,   215,   216,
      29,   190,    -1,   215,   216,    29,   131,    29,   190,    -1,
     342,   190,   389,    -1,   359,   190,   389,    -1,   342,   190,
     359,   190,   389,    -1,   389,    -1,   342,   336,   389,    -1,
     359,   336,   389,    -1,   342,   190,   359,   336,   389,    -1,
     342,   336,   359,   190,   389,    -1,   341,    -1,   341,   342,
     190,    -1,   341,   359,   190,    -1,   341,   342,   190,   359,
     190,    -1,    34,   160,   653,   132,   652,   190,    -1,   343,
      -1,   342,   190,   343,    -1,   342,   336,   343,    -1,   344,
      -1,   352,    -1,   357,    -1,   358,    -1,   366,    -1,   345,
      -1,   346,    -1,   347,    -1,   348,    -1,   349,    -1,   350,
      -1,   351,    -1,   572,    -1,    33,    38,   182,    -1,    33,
      38,   196,    -1,    33,   113,   106,   652,    -1,    33,    37,
     652,    -1,    33,    40,   182,    -1,    33,    40,   196,    -1,
      33,    57,   169,    -1,    33,    57,   202,    -1,    33,   113,
     168,   127,   128,    -1,    33,   113,   168,   127,   129,    -1,
      33,    41,   182,   107,   148,    -1,    33,    41,   182,   107,
     165,    -1,    33,    41,   166,   107,   148,    -1,    33,    41,
     166,   107,   165,    -1,   353,    -1,   356,    -1,    49,    24,
       1,    -1,    49,    60,   652,    -1,    49,    60,   355,   652,
      -1,    49,    60,   652,    96,   354,    -1,    49,    60,   355,
     652,    96,   354,    -1,   652,    -1,   354,   107,   652,    -1,
     160,   653,   132,    -1,   113,    45,   160,    -1,    49,    34,
     652,    -1,    49,    34,   160,   653,   132,   652,    -1,    49,
      34,   652,    96,   354,    -1,    49,    34,   160,   653,   132,
     652,    96,   354,    -1,    33,   160,   653,   132,   652,    -1,
      33,   113,    45,   160,   652,    -1,    33,   113,    47,   160,
     652,    -1,   360,    -1,   359,   190,   360,    -1,   359,   336,
     360,    -1,   361,    -1,   365,    -1,   367,    -1,   371,    -1,
     376,    -1,   383,    -1,   385,    -1,   388,    -1,    33,   113,
      79,   362,    -1,    33,    79,   654,   362,    -1,   363,    -1,
     362,   363,    -1,   364,   132,   564,    -1,    80,    -1,    88,
      -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,    89,
      -1,    85,    -1,    86,    -1,    87,    -1,    33,    56,   654,
      29,    -1,    33,   261,   611,    -1,    33,   111,   152,   368,
      -1,    94,   548,   369,    -1,   369,    -1,   370,    -1,   137,
      -1,   137,   370,    -1,   142,   413,    -1,    33,   372,   142,
     413,    -1,    33,   372,   137,    -1,    33,   372,   137,   142,
     413,    -1,   112,   118,   654,    -1,   112,   118,   654,   545,
      -1,   373,   112,   118,   654,    -1,   373,   112,   118,   654,
     545,    -1,   374,    -1,   373,   374,    -1,    26,    -1,    26,
     156,   375,   187,    -1,    27,    -1,    27,   156,   375,   187,
      -1,   510,    -1,   375,   107,   510,    -1,    33,   377,    -1,
      33,   373,   377,    -1,   378,    -1,   379,    -1,    47,   655,
     380,   397,    -1,    47,   655,   380,   137,    -1,    74,    47,
     655,   380,   397,    -1,    74,    47,   655,   380,   137,    -1,
     156,   187,    -1,   156,   381,   187,    -1,   156,   187,    94,
     546,    -1,   156,   381,   187,    94,   546,    -1,   382,    -1,
     381,   107,   382,    -1,   118,   654,    -1,   118,   654,   545,
      -1,    33,   287,   654,    -1,    33,   287,   654,    94,   384,
      -1,    33,   373,   287,   654,    -1,    33,   373,   287,   654,
      94,   384,    -1,   552,    -1,   552,   547,    -1,   648,    -1,
     648,   547,    -1,    33,   295,   654,   299,   227,   493,   170,
     386,    -1,    33,   373,   295,   654,   299,   227,   493,   170,
     386,    -1,   387,    -1,   386,   107,   387,    -1,   493,    -1,
     493,   545,    -1,   493,   448,    -1,   493,   545,   448,    -1,
      33,   303,   304,   654,   299,   287,   654,   118,   654,   305,
     413,    -1,    33,   303,   304,   654,   299,   287,   654,   225,
     118,   654,   305,   293,   306,   493,    -1,    33,   303,   304,
     654,   299,   287,   654,   307,   225,   118,   654,   305,   413,
      -1,    33,   303,   304,   654,   308,   306,   257,   287,   654,
     225,   118,   654,   306,   493,   199,   287,   654,   225,   118,
     654,   306,   493,    -1,   390,    -1,   392,    -1,   393,    -1,
      -1,   392,    -1,   393,    -1,    -1,   412,    -1,   393,   412,
      -1,   394,    -1,   393,   394,    -1,   395,    -1,   398,    -1,
     401,    -1,   402,    -1,   403,    -1,   404,    -1,   405,    -1,
     406,    -1,   408,    -1,   460,    -1,   456,    -1,   409,    -1,
     153,   393,   184,    -1,   153,   184,    -1,   153,   391,   184,
      -1,   153,   391,   184,    -1,   399,   190,    -1,   399,   107,
     400,    -1,   112,   400,    -1,   373,   112,   400,    -1,   118,
     654,    -1,   118,   654,   545,    -1,   118,   654,   142,   413,
      -1,   118,   654,   545,   142,   413,    -1,   118,   654,   142,
     413,   190,    -1,   414,   190,    -1,   240,   242,   413,   190,
      -1,   243,   156,   412,   187,   394,    -1,   238,   241,   190,
      -1,   239,   241,   190,    -1,   424,   407,    -1,   186,   394,
      -1,    48,   156,   412,   187,   198,   394,   126,   394,    -1,
     244,   395,   410,    -1,   411,    -1,   410,   411,    -1,   245,
     584,   395,    -1,   413,    -1,   412,   107,   413,    -1,   412,
       1,   413,     1,    -1,   412,   336,   413,    -1,   415,    -1,
     452,    -1,   459,    -1,   465,    -1,   580,    -1,   414,    -1,
     466,    -1,   449,    -1,   573,    -1,   574,    -1,   576,    -1,
     575,    -1,   577,    -1,   645,    -1,   643,    -1,   646,    -1,
     647,    -1,   644,    -1,   424,   416,    -1,   186,   413,    -1,
      66,   284,    -1,    71,   284,    -1,   217,    -1,   254,    -1,
      55,   254,    -1,   418,   434,    77,   413,    -1,   418,    77,
     413,    -1,    46,   417,   433,   419,   419,    -1,    46,   417,
     433,   419,    -1,    42,   118,   654,    -1,   425,    -1,   430,
      -1,   420,    -1,   422,    -1,   437,    -1,   442,    -1,   438,
      -1,   421,    -1,   422,    -1,   424,   423,    -1,    46,   118,
     426,    -1,    46,     1,   426,    -1,    46,     3,    -1,   427,
      -1,   426,   107,   118,   427,    -1,   426,   107,   427,    -1,
     654,   147,   413,    -1,   654,    36,   127,   147,   413,    -1,
     654,   545,   147,   413,    -1,   654,   545,    36,   127,   147,
     413,    -1,   654,   428,   147,   413,    -1,   654,    36,   127,
     428,   147,   413,    -1,   654,   545,   428,   147,   413,    -1,
     654,   545,    36,   127,   428,   147,   413,    -1,   654,   429,
     147,   413,    -1,   654,   545,   429,   147,   413,    -1,   654,
     428,   429,   147,   413,    -1,   654,   545,   428,   429,   147,
     413,    -1,    96,   118,   654,    -1,   273,   118,   654,    -1,
      51,   431,    -1,   432,    -1,   431,   107,   432,    -1,   118,
     654,   142,   413,    -1,   118,   654,   545,   142,   413,    -1,
     429,   142,   413,    -1,   118,   654,   545,   429,   142,   413,
      -1,   118,   654,   147,   413,    -1,   118,   654,   545,   147,
     413,    -1,   435,    -1,   118,   654,    -1,   118,   654,   435,
      -1,   428,    -1,   428,   436,    -1,   436,    -1,    58,   118,
     654,    53,   118,   654,    -1,    53,   118,   654,    -1,    58,
     118,   654,    -1,   212,   413,    -1,   171,   170,   439,    -1,
     440,    -1,   439,   107,   440,    -1,   118,   654,    -1,   118,
     654,   142,   413,    -1,   118,   654,   545,   142,   413,    -1,
     118,   654,   545,   142,   413,   441,    -1,   118,   654,   142,
     413,   441,    -1,   118,   654,   441,    -1,   106,   652,    -1,
     168,   170,   443,    -1,    69,   168,   170,   443,    -1,   444,
      -1,   443,   107,   444,    -1,   413,    -1,   413,   445,    -1,
     446,    -1,   447,    -1,   448,    -1,   446,   447,    -1,   446,
     448,    -1,   447,   448,    -1,   446,   447,   448,    -1,    95,
      -1,   116,    -1,   127,   128,    -1,   127,   129,    -1,   106,
     652,    -1,    67,   118,   450,   188,   413,    -1,   135,   118,
     450,   188,   413,    -1,   451,    -1,   450,   107,   118,   451,
      -1,   654,   147,   413,    -1,   654,   545,   147,   413,    -1,
      72,   156,   412,   187,   453,   113,   186,   413,    -1,   454,
      -1,   453,   454,    -1,   455,   186,   413,    -1,   100,   413,
      -1,   455,   100,   413,    -1,    72,   156,   412,   187,   457,
     113,   186,   394,    -1,   458,    -1,   457,   458,    -1,   455,
     186,   394,    -1,    73,   156,   412,   187,   461,   113,   186,
     413,    -1,    73,   156,   412,   187,   461,   113,   118,   654,
     186,   413,    -1,    73,   156,   412,   187,   463,   113,   186,
     394,    -1,    73,   156,   412,   187,   461,   113,   118,   654,
     186,   394,    -1,   462,    -1,   461,   462,    -1,   100,   546,
     186,   413,    -1,   100,   118,   654,    94,   546,   186,   413,
      -1,   464,    -1,   463,   464,    -1,   100,   546,   186,   394,
      -1,   100,   118,   654,    94,   546,   186,   394,    -1,    48,
     156,   412,   187,   198,   413,   126,   413,    -1,   467,    -1,
     466,   167,   467,    -1,   468,    -1,   467,    92,   468,    -1,
     470,    -1,   470,   487,   470,    -1,   470,   488,   470,    -1,
     470,   132,   470,    -1,   470,   162,   470,    -1,    -1,   470,
     157,   469,   470,    -1,   470,   155,   470,    -1,   470,   143,
     470,    -1,   470,   141,   470,    -1,   471,    -1,   471,   249,
      70,   585,   472,    -1,   473,    -1,   473,    99,   471,    -1,
      -1,   637,    -1,   474,    -1,   474,   199,   474,    -1,   475,
      -1,   474,   176,   475,    -1,   474,   158,   475,    -1,   476,
      -1,   475,   194,   476,    -1,   475,   117,   476,    -1,   475,
     146,   476,    -1,   475,   159,   476,    -1,   477,    -1,   476,
     201,   477,    -1,   476,   210,   477,    -1,   478,    -1,   477,
     150,   478,    -1,   477,   136,   478,    -1,   479,    -1,   479,
      50,   231,   546,    -1,   480,    -1,   480,   200,    94,   546,
      -1,   481,    -1,   481,   101,    94,   482,    -1,   483,    -1,
     483,   102,    94,   482,    -1,   551,    -1,   551,   144,    -1,
     485,    -1,   484,   485,    -1,   176,    -1,   158,    -1,   484,
     176,    -1,   484,   158,    -1,   489,    -1,   486,    -1,   490,
      -1,   493,    -1,   486,   193,   493,    -1,   203,    -1,   208,
      -1,   207,    -1,   206,    -1,   205,    -1,   204,    -1,   151,
      -1,   179,    -1,   140,    -1,    75,   153,   392,   184,    -1,
      75,   222,   153,   392,   184,    -1,    75,   221,   153,   392,
     184,    -1,    75,    76,   562,   153,   392,   184,    -1,   491,
     153,   184,    -1,   491,   153,   412,   184,    -1,   492,    -1,
     491,   492,    -1,   177,   654,    17,    -1,   177,    18,    -1,
     177,    19,    -1,   494,    -1,   494,   495,    -1,   192,   495,
      -1,   495,    -1,   191,    -1,   496,    -1,   496,   191,   495,
      -1,   496,   192,   495,    -1,   497,    -1,   506,    -1,   498,
      -1,   498,   507,    -1,   501,    -1,   501,   507,    -1,   499,
     503,    -1,   500,    -1,   105,   122,    -1,   114,   122,    -1,
      97,   122,    -1,   189,   122,    -1,   115,   122,    -1,   139,
     122,    -1,   138,   122,    -1,   503,    -1,    98,   503,    -1,
     502,   503,    -1,   120,    -1,   172,   122,    -1,    90,   122,
      -1,   181,   122,    -1,   180,   122,    -1,    91,   122,    -1,
     552,    -1,   504,    -1,   654,    -1,   505,    -1,   194,    -1,
      11,    -1,    12,    -1,    20,    -1,   509,    -1,   506,   507,
      -1,   506,   156,   187,    -1,   506,   156,   518,   187,    -1,
     508,    -1,   507,   508,    -1,   154,   412,   185,    -1,   510,
      -1,   512,    -1,   513,    -1,   514,    -1,   517,    -1,   519,
      -1,   515,    -1,   516,    -1,   565,    -1,   396,    -1,   641,
      -1,   638,    -1,   639,    -1,   640,    -1,   511,    -1,   564,
      -1,   110,    -1,   149,    -1,   124,    -1,   118,   654,    -1,
     156,   187,    -1,   156,   412,   187,    -1,   119,    -1,   169,
     153,   412,   184,    -1,   202,   153,   412,   184,    -1,   655,
     156,   187,    -1,   655,   156,   518,   187,    -1,   413,    -1,
     518,   107,   413,    -1,   520,    -1,   538,    -1,   521,    -1,
     535,    -1,   536,    -1,   157,   654,   525,   130,    -1,   157,
     654,   523,   525,   130,    -1,   157,   654,   525,   197,   195,
     654,   525,   197,    -1,   157,   654,   525,   197,   522,   195,
     654,   525,   197,    -1,   157,   654,   523,   525,   197,   195,
     654,   525,   197,    -1,   157,   654,   523,   525,   197,   522,
     195,   654,   525,   197,    -1,   533,    -1,   522,   533,    -1,
     524,    -1,   523,   524,    -1,    35,   654,   525,   132,   525,
     526,    -1,    -1,    35,    -1,   183,   527,   183,    -1,    93,
     529,    93,    -1,    -1,   528,    -1,   134,    -1,   531,    -1,
     528,   134,    -1,   528,   531,    -1,    -1,   530,    -1,   133,
      -1,   532,    -1,   530,   133,    -1,   530,   532,    -1,    28,
      -1,   534,    -1,     5,    -1,   534,    -1,   520,    -1,    10,
      -1,   537,    -1,   534,    -1,     9,    -1,   123,    -1,   125,
      -1,   153,   392,   184,    -1,   213,    30,   214,    -1,   213,
     214,    -1,   174,   653,   175,    -1,   174,   653,     8,    -1,
     103,     7,    -1,   539,    -1,   540,    -1,   541,    -1,   542,
      -1,   543,    -1,   544,    -1,    43,   153,   392,   184,    -1,
      21,   391,   184,    -1,    45,   153,   412,   184,   153,   391,
     184,    -1,    22,   391,   184,    -1,    97,   153,   412,   184,
     153,   391,   184,    -1,    70,   153,   392,   184,    -1,    39,
     153,   392,   184,    -1,    23,   391,   184,    -1,    59,   153,
     412,   184,   153,   391,   184,    -1,    94,   546,    -1,   548,
      -1,   548,   547,    -1,   211,   156,   187,    -1,   144,    -1,
     194,    -1,   176,    -1,   550,    -1,   552,    -1,   152,   156,
     187,    -1,   320,   156,   187,    -1,   568,    -1,   571,    -1,
     648,    -1,   546,    -1,   549,   107,   546,    -1,   654,    -1,
     654,    -1,   554,    -1,   560,    -1,   558,    -1,   561,    -1,
     559,    -1,   557,    -1,   556,    -1,   555,    -1,   553,    -1,
     225,   156,   187,    -1,    44,   156,   187,    -1,    44,   156,
     560,   187,    -1,    44,   156,   561,   187,    -1,    70,   156,
     187,    -1,    39,   156,   187,    -1,    59,   156,   187,    -1,
      59,   156,   653,   187,    -1,    59,   156,    29,   187,    -1,
      97,   156,   187,    -1,    97,   156,   654,   187,    -1,    97,
     156,   654,   107,   562,   187,    -1,    97,   156,   194,   187,
      -1,    97,   156,   194,   107,   562,   187,    -1,    61,   156,
     654,   187,    -1,    45,   156,   187,    -1,    45,   156,   654,
     187,    -1,    45,   156,   654,   107,   562,   187,    -1,    45,
     156,   654,   107,   563,   187,    -1,    45,   156,   194,   187,
      -1,    45,   156,   194,   107,   562,   187,    -1,    45,   156,
     194,   107,   563,   187,    -1,    62,   156,   654,   187,    -1,
     654,    -1,   654,   144,    -1,    29,    -1,   566,    -1,   567,
      -1,   654,   145,   149,    -1,    47,   380,   397,    -1,   569,
      -1,   570,    -1,    47,   156,   194,   187,    -1,    47,   156,
     187,    94,   546,    -1,    47,   156,   549,   187,    94,   546,
      -1,   156,   548,   187,    -1,    33,   220,   221,    -1,    33,
     220,   222,    -1,    33,   220,   223,    -1,   226,   225,   413,
     233,   413,    -1,   226,   225,   413,    94,   232,   233,   413,
      -1,   226,   225,   413,    94,   234,   233,   413,    -1,   226,
     225,   413,   218,   413,    -1,   226,   225,   413,   219,   413,
      -1,   226,   227,   413,   233,   413,    -1,   226,   227,   413,
      94,   232,   233,   413,    -1,   226,   227,   413,    94,   234,
     233,   413,    -1,   226,   227,   413,   218,   413,    -1,   226,
     227,   413,   219,   413,    -1,   224,   225,   413,    -1,   224,
     227,   413,    -1,   229,   225,   413,   237,   413,    -1,   229,
     230,   231,   225,   413,   237,   413,    -1,   228,   225,   413,
      94,   413,    -1,   236,   118,   578,   235,   413,   186,   413,
      -1,   579,    -1,   578,   107,   118,   579,    -1,   654,   142,
     413,    -1,   244,   153,   412,   184,   581,    -1,   582,    -1,
     581,   582,    -1,   245,   584,   583,    -1,   153,   412,   184,
      -1,   504,    -1,   584,   210,   504,    -1,   588,   586,    -1,
      -1,   587,    -1,   606,    -1,   587,   606,    -1,   589,    -1,
     588,   262,   589,    -1,   590,    -1,   589,   258,   590,    -1,
     591,    -1,   590,   260,   147,   591,    -1,   592,    -1,   259,
     592,    -1,   596,   593,   594,    -1,    -1,   611,    -1,    -1,
     595,    -1,   282,   153,   412,   184,    -1,   600,   597,    -1,
     156,   585,   187,    -1,   598,    -1,    -1,   633,    -1,   491,
     153,   599,   184,    -1,    -1,   585,    -1,   601,   602,    -1,
     510,    -1,   153,   412,   184,    -1,    -1,   603,    -1,   248,
     604,    -1,   247,   605,    -1,   270,    -1,    -1,    78,    -1,
      -1,   286,    -1,   607,    -1,   608,    -1,   609,    -1,   635,
      -1,   632,    -1,   169,    -1,   284,   474,   610,    -1,   253,
     634,   610,    -1,   286,    -1,   276,    -1,   269,    -1,   246,
     612,    -1,   611,   246,   612,    -1,   613,    -1,   614,    -1,
     615,    -1,   630,    -1,   616,    -1,   624,    -1,   617,    -1,
     631,    -1,   100,   274,    -1,   100,   263,    -1,   266,    -1,
     281,    -1,   251,   274,    -1,   251,   263,    -1,    56,   654,
      29,    -1,   277,    -1,    54,   277,    -1,   279,   618,    -1,
     279,   156,   618,   619,   187,    -1,    54,   279,    -1,   621,
      -1,   113,    -1,    -1,   107,   620,    -1,   621,    -1,   620,
     107,   621,    -1,    96,    29,   622,   623,    -1,    -1,   271,
      29,    -1,    -1,   634,   265,    -1,   278,   286,   625,   627,
      -1,   278,   286,   113,   627,    -1,    54,   278,   286,    -1,
      96,    29,    -1,   156,   626,   187,    -1,    29,    -1,   626,
     107,    29,    -1,    -1,   628,    -1,   629,    -1,   628,   629,
      -1,   201,   625,    -1,   136,   625,    -1,   264,    29,    -1,
     283,    -1,    54,   283,    -1,    96,   217,    -1,    96,   254,
      -1,   255,   250,    -1,   267,   634,   280,    -1,   256,   474,
      -1,    96,   129,   474,    -1,    96,    52,   474,    -1,   257,
     474,   199,   474,    -1,   272,   636,    -1,   252,   636,    -1,
     275,    -1,   268,    -1,   285,   250,   476,    -1,   154,   185,
      -1,   154,   412,   185,    -1,   310,   311,    -1,   310,   412,
     311,    -1,   312,   313,    -1,   312,   412,   313,    -1,   153,
     642,   184,    -1,   413,   121,   413,    -1,   642,   107,   413,
     121,   413,    -1,   226,   314,   413,   233,   413,    -1,   226,
     314,   642,   233,   413,    -1,   226,   314,   413,   233,   413,
      96,   316,   413,    -1,   315,   314,   413,   233,   413,    -1,
     224,   314,   506,    -1,   228,   314,   506,    94,   413,    -1,
     229,   314,   230,   231,   506,   237,   413,    -1,   649,    -1,
     650,    -1,   651,    -1,   319,   156,   187,    -1,   317,   156,
     187,    -1,   318,   156,   187,    -1,    29,    -1,    16,    -1,
     654,    -1,   655,    -1,    97,    -1,    39,    -1,    44,    -1,
      45,    -1,   152,    -1,    48,    -1,   225,    -1,    59,    -1,
      61,    -1,    62,    -1,    70,    -1,    73,    -1,    72,    -1,
     211,    -1,   243,    -1,   656,    -1,    24,    -1,   215,    -1,
     127,    -1,    38,    -1,   261,    -1,    37,    -1,   222,    -1,
     221,    -1,   146,    -1,    43,    -1,   259,    -1,   260,    -1,
     274,    -1,   263,    -1,   251,    -1,   285,    -1,   277,    -1,
     279,    -1,   278,    -1,   283,    -1,   255,    -1,   250,    -1,
      78,    -1,   217,    -1,   254,    -1,    52,    -1,   223,    -1,
     236,    -1,   302,    -1,   230,    -1,   203,    -1,   208,    -1,
     207,    -1,   206,    -1,   205,    -1,   204,    -1,    96,    -1,
     111,    -1,   112,    -1,   186,    -1,    46,    -1,    36,    -1,
      66,    -1,    71,    -1,    58,    -1,    53,    -1,    55,    -1,
      77,    -1,    42,    -1,   147,    -1,    51,    -1,   212,    -1,
     170,    -1,   171,    -1,   168,    -1,    69,    -1,    95,    -1,
     116,    -1,   128,    -1,   129,    -1,   106,    -1,    67,    -1,
     135,    -1,   188,    -1,   100,    -1,    94,    -1,   198,    -1,
     126,    -1,   167,    -1,    92,    -1,    50,    -1,   231,    -1,
     101,    -1,   199,    -1,   117,    -1,   159,    -1,   201,    -1,
     150,    -1,   136,    -1,    75,    -1,    76,    -1,   102,    -1,
     200,    -1,   151,    -1,   182,    -1,   196,    -1,   160,    -1,
     137,    -1,   131,    -1,   166,    -1,   148,    -1,   165,    -1,
      33,    -1,    40,    -1,    57,    -1,   113,    -1,    41,    -1,
      56,    -1,   216,    -1,    49,    -1,    60,    -1,    34,    -1,
      47,    -1,   273,    -1,   249,    -1,   282,    -1,   284,    -1,
     253,    -1,   267,    -1,   280,    -1,   272,    -1,   252,    -1,
     266,    -1,   281,    -1,   271,    -1,   265,    -1,   264,    -1,
     248,    -1,   247,    -1,   256,    -1,   257,    -1,   286,    -1,
     276,    -1,   275,    -1,   270,    -1,   268,    -1,   269,    -1,
     229,    -1,   235,    -1,   232,    -1,   226,    -1,   219,    -1,
     218,    -1,   220,    -1,   237,    -1,   227,    -1,   228,    -1,
     234,    -1,   224,    -1,   233,    -1,    65,    -1,    63,    -1,
      74,    -1,   169,    -1,   202,    -1,   242,    -1,   240,    -1,
     241,    -1,   238,    -1,   239,    -1,   244,    -1,   245,    -1,
     246,    -1,    64,    -1,   295,    -1,   293,    -1,   294,    -1,
     299,    -1,   300,    -1,   301,    -1,   296,    -1,   297,    -1,
     298,    -1,    79,    -1,    80,    -1,    81,    -1,    82,    -1,
      83,    -1,    84,    -1,    85,    -1,    86,    -1,    87,    -1,
      88,    -1,    89,    -1,   287,    -1,   288,    -1,   289,    -1,
     290,    -1,   291,    -1,   292,    -1,   303,    -1,   304,    -1,
     305,    -1,   306,    -1,   307,    -1,   308,    -1,   309,    -1,
      90,    -1,   105,    -1,   114,    -1,   172,    -1,   180,    -1,
     189,    -1,   138,    -1,    91,    -1,   115,    -1,   139,    -1,
     181,    -1,   314,    -1,   315,    -1,   316,    -1,   319,    -1,
     318,    -1,   317,    -1,   320,    -1,    25,    -1
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
    1478,  1480,  1485,  1487,  1490,  1492,  1495,  1497,  1499,  1502,
    1505,  1507,  1509,  1511,  1513,  1517,  1519,  1521,  1523,  1525,
    1527,  1529,  1531,  1533,  1535,  1540,  1546,  1552,  1559,  1563,
    1568,  1570,  1573,  1577,  1580,  1583,  1585,  1588,  1591,  1593,
    1595,  1597,  1601,  1605,  1607,  1609,  1611,  1614,  1616,  1619,
    1622,  1624,  1627,  1630,  1633,  1636,  1639,  1642,  1645,  1647,
    1650,  1653,  1655,  1658,  1661,  1664,  1667,  1670,  1672,  1674,
    1676,  1678,  1680,  1682,  1684,  1686,  1688,  1691,  1695,  1700,
    1702,  1705,  1709,  1711,  1713,  1715,  1717,  1719,  1721,  1723,
    1725,  1727,  1729,  1731,  1733,  1735,  1737,  1739,  1741,  1743,
    1745,  1747,  1750,  1753,  1757,  1759,  1764,  1769,  1773,  1778,
    1780,  1784,  1786,  1788,  1790,  1792,  1794,  1799,  1805,  1814,
    1824,  1834,  1845,  1847,  1850,  1852,  1855,  1862,  1863,  1865,
    1869,  1873,  1874,  1876,  1878,  1880,  1883,  1886,  1887,  1889,
    1891,  1893,  1896,  1899,  1901,  1903,  1905,  1907,  1909,  1911,
    1913,  1915,  1917,  1919,  1921,  1925,  1929,  1932,  1936,  1940,
    1943,  1945,  1947,  1949,  1951,  1953,  1955,  1960,  1964,  1972,
    1976,  1984,  1989,  1994,  1998,  2006,  2009,  2011,  2014,  2018,
    2020,  2022,  2024,  2026,  2028,  2032,  2036,  2038,  2040,  2042,
    2044,  2048,  2050,  2052,  2054,  2056,  2058,  2060,  2062,  2064,
    2066,  2068,  2070,  2074,  2078,  2083,  2088,  2092,  2096,  2100,
    2105,  2110,  2114,  2119,  2126,  2131,  2138,  2143,  2147,  2152,
    2159,  2166,  2171,  2178,  2185,  2190,  2192,  2195,  2197,  2199,
    2201,  2205,  2209,  2211,  2213,  2218,  2224,  2231,  2235,  2239,
    2243,  2247,  2253,  2261,  2269,  2275,  2281,  2287,  2295,  2303,
    2309,  2315,  2319,  2323,  2329,  2337,  2343,  2351,  2353,  2358,
    2362,  2368,  2370,  2373,  2377,  2381,  2383,  2387,  2390,  2391,
    2393,  2395,  2398,  2400,  2404,  2406,  2410,  2412,  2417,  2419,
    2422,  2426,  2427,  2429,  2430,  2432,  2437,  2440,  2444,  2446,
    2447,  2449,  2454,  2455,  2457,  2460,  2462,  2466,  2467,  2469,
    2472,  2475,  2477,  2478,  2480,  2481,  2483,  2485,  2487,  2489,
    2491,  2493,  2495,  2499,  2503,  2505,  2507,  2509,  2512,  2516,
    2518,  2520,  2522,  2524,  2526,  2528,  2530,  2532,  2535,  2538,
    2540,  2542,  2545,  2548,  2552,  2554,  2557,  2560,  2566,  2569,
    2571,  2573,  2574,  2577,  2579,  2583,  2588,  2589,  2592,  2593,
    2596,  2601,  2606,  2610,  2613,  2617,  2619,  2623,  2624,  2626,
    2628,  2631,  2634,  2637,  2640,  2642,  2645,  2648,  2651,  2654,
    2658,  2661,  2665,  2669,  2674,  2677,  2680,  2682,  2684,  2688,
    2691,  2695,  2698,  2702,  2705,  2709,  2713,  2717,  2723,  2729,
    2735,  2744,  2750,  2754,  2760,  2768,  2770,  2772,  2774,  2778,
    2782,  2786,  2788,  2790,  2792,  2794,  2796,  2798,  2800,  2802,
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
    3224,  3226,  3228,  3230,  3232,  3234,  3236
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1050,  1050,  1051,  1055,  1059,  1070,  1079,  1085,  1093,
    1099,  1110,  1115,  1123,  1130,  1137,  1146,  1153,  1161,  1169,
    1177,  1188,  1193,  1200,  1207,  1219,  1229,  1236,  1243,  1255,
    1256,  1257,  1258,  1259,  1264,  1265,  1266,  1267,  1268,  1269,
    1270,  1273,  1278,  1283,  1291,  1299,  1307,  1312,  1320,  1325,
    1333,  1338,  1346,  1351,  1356,  1361,  1369,  1371,  1374,  1384,
    1389,  1397,  1405,  1416,  1423,  1434,  1439,  1447,  1454,  1461,
    1470,  1483,  1491,  1498,  1508,  1515,  1522,  1533,  1534,  1535,
    1536,  1537,  1538,  1539,  1540,  1545,  1551,  1560,  1567,  1577,
    1587,  1588,  1589,  1590,  1591,  1592,  1593,  1594,  1595,  1596,
    1601,  1609,  1617,  1625,  1632,  1640,  1647,  1652,  1660,  1668,
    1682,  1696,  1713,  1718,  1726,  1734,  1745,  1750,  1759,  1764,
    1771,  1776,  1786,  1791,  1800,  1806,  1819,  1824,  1832,  1843,
    1858,  1870,  1885,  1890,  1895,  1900,  1908,  1915,  1926,  1931,
    1941,  1950,  1959,  1968,  1980,  1984,  1990,  1994,  2004,  2014,
    2027,  2033,  2042,  2047,  2054,  2061,  2072,  2082,  2092,  2102,
    2120,  2140,  2144,  2149,  2156,  2160,  2165,  2172,  2177,  2189,
    2196,  2208,  2209,  2210,  2211,  2212,  2213,  2214,  2216,  2217,
    2218,  2219,  2220,  2225,  2230,  2238,  2255,  2263,  2271,  2278,
    2285,  2296,  2305,  2314,  2323,  2336,  2344,  2352,  2360,  2375,
    2380,  2388,  2402,  2419,  2444,  2452,  2459,  2470,  2480,  2485,
    2497,  2506,  2519,  2520,  2521,  2522,  2523,  2524,  2529,  2530,
    2533,  2534,  2535,  2536,  2537,  2540,  2541,  2542,  2543,  2544,
    2549,  2563,  2571,  2576,  2584,  2589,  2594,  2602,  2611,  2623,
    2633,  2646,  2654,  2655,  2656,  2661,  2662,  2663,  2664,  2665,
    2670,  2677,  2687,  2693,  2702,  2712,  2719,  2727,  2739,  2749,
    2759,  2769,  2779,  2789,  2799,  2809,  2820,  2829,  2839,  2849,
    2865,  2874,  2883,  2891,  2897,  2909,  2917,  2927,  2935,  2947,
    2953,  2964,  2966,  2970,  2978,  2982,  2987,  2991,  2995,  2999,
    3009,  3017,  3024,  3030,  3040,  3044,  3048,  3056,  3064,  3072,
    3084,  3092,  3098,  3108,  3114,  3124,  3128,  3138,  3144,  3150,
    3156,  3165,  3174,  3183,  3196,  3200,  3208,  3214,  3224,  3232,
    3241,  3254,  3261,  3273,  3277,  3289,  3296,  3302,  3311,  3318,
    3324,  3335,  3342,  3348,  3357,  3366,  3373,  3384,  3391,  3403,
    3409,  3421,  3427,  3438,  3444,  3455,  3461,  3472,  3481,  3485,
    3494,  3498,  3506,  3510,  3520,  3527,  3536,  3546,  3545,  3559,
    3568,  3577,  3590,  3594,  3606,  3610,  3618,  3621,  3628,  3632,
    3641,  3645,  3649,  3657,  3661,  3667,  3673,  3679,  3689,  3693,
    3697,  3705,  3709,  3715,  3725,  3729,  3739,  3743,  3753,  3757,
    3767,  3771,  3781,  3785,  3794,  3798,  3806,  3810,  3814,  3818,
    3828,  3832,  3836,  3843,  3848,  3856,  3860,  3864,  3868,  3872,
    3876,  3884,  3888,  3892,  3900,  3904,  3908,  3912,  3923,  3929,
    3939,  3945,  3955,  3959,  3963,  4001,  4005,  4015,  4025,  4038,
    4047,  4057,  4061,  4070,  4074,  4083,  4089,  4097,  4103,  4115,
    4121,  4131,  4135,  4139,  4143,  4147,  4153,  4159,  4167,  4171,
    4179,  4183,  4194,  4198,  4202,  4208,  4212,  4226,  4230,  4238,
    4242,  4252,  4256,  4260,  4264,  4273,  4277,  4281,  4285,  4293,
    4299,  4309,  4317,  4321,  4325,  4329,  4333,  4337,  4341,  4345,
    4349,  4353,  4358,  4362,  4366,  4370,  4378,  4382,  4390,  4397,
    4404,  4415,  4423,  4427,  4435,  4443,  4451,  4505,  4509,  4522,
    4528,  4538,  4542,  4550,  4554,  4558,  4566,  4576,  4586,  4603,
    4620,  4637,  4659,  4665,  4676,  4682,  4693,  4704,  4706,  4710,
    4715,  4725,  4728,  4735,  4741,  4747,  4755,  4768,  4771,  4778,
    4784,  4790,  4797,  4808,  4812,  4822,  4826,  4836,  4840,  4844,
    4849,  4858,  4864,  4870,  4876,  4884,  4889,  4897,  4902,  4910,
    4918,  4923,  4928,  4933,  4938,  4943,  4952,  4960,  4964,  4981,
    4985,  4993,  5001,  5009,  5013,  5021,  5029,  5033,  5037,  5072,
    5078,  5084,  5094,  5098,  5102,  5106,  5110,  5114,  5118,  5125,
    5131,  5141,  5149,  5157,  5161,  5165,  5169,  5173,  5177,  5181,
    5185,  5189,  5197,  5205,  5209,  5213,  5223,  5231,  5239,  5243,
    5247,  5255,  5259,  5265,  5271,  5275,  5285,  5293,  5297,  5303,
    5312,  5321,  5327,  5333,  5343,  5360,  5367,  5382,  5418,  5422,
    5430,  5438,  5450,  5454,  5462,  5470,  5474,  5485,  5502,  5508,
    5514,  5524,  5528,  5534,  5540,  5544,  5550,  5554,  5560,  5566,
    5573,  5583,  5588,  5596,  5602,  5612,  5634,  5643,  5649,  5662,
    5676,  5683,  5689,  5699,  5708,  5716,  5722,  5740,  5748,  5752,
    5759,  5764,  5772,  5776,  5783,  5787,  5794,  5798,  5805,  5809,
    5818,  5831,  5834,  5842,  5845,  5853,  5861,  5869,  5873,  5881,
    5884,  5892,  5904,  5907,  5915,  5927,  5933,  5943,  5946,  5954,
    5958,  5962,  5970,  5973,  5981,  5984,  5992,  5996,  6000,  6004,
    6008,  6016,  6024,  6036,  6048,  6052,  6056,  6064,  6070,  6080,
    6084,  6088,  6092,  6096,  6100,  6104,  6108,  6116,  6120,  6124,
    6128,  6136,  6142,  6152,  6162,  6166,  6174,  6184,  6195,  6202,
    6206,  6214,  6217,  6224,  6229,  6238,  6248,  6251,  6258,  6262,
    6270,  6279,  6286,  6296,  6300,  6307,  6313,  6323,  6326,  6333,
    6338,  6350,  6358,  6370,  6378,  6382,  6390,  6394,  6398,  6406,
    6414,  6418,  6422,  6426,  6434,  6442,  6454,  6458,  6466,  6480,
    6484,  6491,  6496,  6504,  6509,  6518,  6526,  6532,  6542,  6548,
    6558,  6565,  6572,  6597,  6625,  6653,  6657,  6661,  6668,  6675,
    6682,  6694,  6698,  6699,  6712,  6713,  6714,  6715,  6716,  6717,
    6718,  6719,  6720,  6721,  6722,  6723,  6724,  6725,  6726,  6727,
    6731,  6732,  6733,  6734,  6735,  6736,  6737,  6738,  6739,  6740,
    6741,  6742,  6743,  6744,  6745,  6746,  6747,  6748,  6749,  6750,
    6751,  6752,  6753,  6754,  6755,  6756,  6757,  6758,  6759,  6760,
    6761,  6762,  6763,  6764,  6765,  6766,  6767,  6768,  6769,  6770,
    6771,  6772,  6773,  6774,  6775,  6776,  6777,  6778,  6779,  6780,
    6781,  6782,  6783,  6784,  6785,  6786,  6787,  6788,  6789,  6790,
    6791,  6792,  6793,  6794,  6795,  6796,  6797,  6798,  6799,  6800,
    6801,  6802,  6803,  6804,  6805,  6806,  6807,  6808,  6809,  6810,
    6811,  6812,  6813,  6814,  6815,  6816,  6817,  6818,  6819,  6820,
    6821,  6822,  6823,  6824,  6825,  6826,  6827,  6828,  6829,  6830,
    6831,  6832,  6833,  6834,  6835,  6836,  6837,  6838,  6839,  6840,
    6841,  6842,  6843,  6844,  6845,  6846,  6847,  6848,  6849,  6850,
    6851,  6852,  6853,  6854,  6855,  6856,  6857,  6858,  6859,  6860,
    6861,  6862,  6863,  6864,  6865,  6866,  6867,  6868,  6869,  6870,
    6871,  6872,  6873,  6874,  6875,  6876,  6877,  6878,  6879,  6880,
    6881,  6882,  6883,  6884,  6885,  6886,  6887,  6888,  6889,  6890,
    6891,  6892,  6893,  6894,  6895,  6896,  6897,  6898,  6899,  6900,
    6901,  6902,  6903,  6904,  6905,  6906,  6907,  6908,  6909,  6910,
    6911,  6912,  6913,  6914,  6915,  6916,  6917,  6918,  6919,  6920,
    6921,  6922,  6923,  6924,  6925,  6926,  6927,  6928,  6929,  6930,
    6931,  6932,  6933,  6934,  6935,  6936,  6941
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
     325,   326,   327,   328,   329,   330,   331,   332,   333
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 16343;
  const int xquery_parser::yynnts_ = 323;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 608;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 334;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 588;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 17455 "/home/markos/zorba/repo/cast-to-simple-type/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6945 "/home/markos/zorba/repo/cast-to-simple-type/src/compiler/parser/xquery_parser.y"


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

