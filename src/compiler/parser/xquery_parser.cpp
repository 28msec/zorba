
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
#line 87 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"


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
#line 79 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 900 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 1024 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 109 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"

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
#line 178 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
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
        case 109: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
#line 898 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 285 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 123: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 897 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 294 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 148: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 896 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 303 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 312 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 321 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 330 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 339 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 348 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 357 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 366 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 375 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 384 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 393 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 402 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 411 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 420 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 429 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 438 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 447 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 456 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 465 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 474 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 483 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 492 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 501 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 510 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 519 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 528 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 537 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 546 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 555 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 564 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 573 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 582 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 591 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 600 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 609 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 618 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 627 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 636 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 645 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 654 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 663 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 672 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 681 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 690 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 699 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 708 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 717 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 726 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 735 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 744 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 753 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 762 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 771 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 780 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 789 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 798 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 807 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 816 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 825 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 834 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 843 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 852 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 861 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 870 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 879 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 888 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 897 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 906 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 924 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 951 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 960 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 969 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 978 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 987 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 996 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1005 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1014 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1023 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1032 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1041 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1050 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1059 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1068 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1077 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1086 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1095 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1104 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1113 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1122 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1131 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1140 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1149 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1158 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1167 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1176 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1185 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1194 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1203 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1212 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1221 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1230 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1239 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1248 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1257 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1266 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1275 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1284 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1293 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1302 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1311 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1320 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1329 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1338 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1347 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1356 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1365 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1374 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1383 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1392 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1401 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1410 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1419 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1428 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1437 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1446 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1455 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1464 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1473 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1482 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1491 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1500 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1509 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1518 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1527 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1536 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1545 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1554 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1563 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1572 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1581 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1590 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1599 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1608 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1617 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1626 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1635 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1644 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1653 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1662 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1671 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1680 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1689 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1698 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1707 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1716 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1725 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1734 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1743 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1752 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1761 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1770 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1779 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1788 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1797 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1806 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1815 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1824 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1833 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1842 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1851 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1860 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1869 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1878 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1887 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1896 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1905 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1914 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1923 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1932 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1941 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1950 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1959 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1968 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1977 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1986 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1995 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2004 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2013 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2022 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2031 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2040 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2049 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2058 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2067 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2076 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2085 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2094 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2103 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2112 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2121 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2130 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2139 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2148 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2157 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2166 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2175 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2184 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2193 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2202 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2211 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2220 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2229 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2238 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2247 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2256 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2265 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2274 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2283 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2292 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2301 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2310 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2319 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2328 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2337 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2346 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2355 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2364 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2373 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2382 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2391 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2400 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2409 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2418 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2427 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2436 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2445 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2454 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2463 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2472 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2481 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2490 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2499 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2508 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2517 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2526 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2535 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2544 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2553 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2562 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 614: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2571 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 615: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2580 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2589 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2598 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2607 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2616 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 623: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2625 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2634 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2643 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2652 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 627: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2661 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "JSONConstructor" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2670 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "JSONComputedPairConstructor" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2679 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 630: /* "JSONComputedObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2688 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 631: /* "JSONComputedArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2697 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 632: /* "JSONDirectArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2706 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 633: /* "JSONDirectObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2715 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 634: /* "JSONDirectObjectContent" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2724 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 635: /* "JSONDirectPairConstructor" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2733 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 643: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2742 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 644: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2751 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
	break;
      case 645: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2760 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
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
#line 140 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 553 of lalr1.cc  */
#line 2845 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"

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
#line 1042 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 1051 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 1060 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1066 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1074 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1080 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1091 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1096 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1104 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1111 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1118 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1127 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1134 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1142 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1150 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1158 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1169 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1174 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1181 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1188 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1200 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1210 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1217 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1224 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 1259 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1264 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1272 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1280 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1288 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1293 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1301 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1306 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1314 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1319 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1327 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1334 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1341 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1348 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1363 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1373 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1378 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1386 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1394 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1405 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1412 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1423 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1428 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1436 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1443 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1450 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1459 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 1472 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1480 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1487 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1497 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1504 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1511 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1534 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1540 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1549 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1556 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1566 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1575 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1576 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1577 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1578 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1579 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1580 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1581 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1582 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1583 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1584 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1590 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1598 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1606 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1614 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1621 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1629 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1636 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1641 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1649 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1657 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 1672 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 1687 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 1705 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1710 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1718 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1726 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1737 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1742 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1751 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1756 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1763 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1768 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1778 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1783 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1792 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1798 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1811 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1816 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1824 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 1835 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 1850 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 1862 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 1877 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1882 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1887 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1892 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1900 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1907 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1918 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1933 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1940 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1947 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1954 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1964 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1968 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1978 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 1986 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 1997 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 2003 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 2012 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 2017 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 2024 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 2031 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 2043 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2053 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2063 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2074 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2090 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2110 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2114 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 2118 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 2126 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2130 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2134 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2142 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2147 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2159 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2166 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2195 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2200 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2208 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2225 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2233 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2241 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2248 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2255 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2265 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2277 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2290 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2302 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2318 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 2326 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 2334 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 2342 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2357 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 2362 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 2370 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2384 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2401 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2426 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2434 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2441 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2452 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2462 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2467 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2505 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2519 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2527 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 2532 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2540 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2545 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2550 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2558 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2567 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2579 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2589 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2602 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2626 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2633 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2643 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2651 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2658 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2668 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2678 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2688 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2698 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2708 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2718 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2728 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2738 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2749 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2758 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2768 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2778 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2794 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2803 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2812 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2820 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2826 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2838 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2846 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2856 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2864 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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
#line 2876 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2882 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2895 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2899 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2907 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2911 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2920 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2924 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2928 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2938 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2946 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2953 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2959 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2970 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2974 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2983 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2991 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2997 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 3007 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 3013 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 3023 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 3027 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 3037 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 3043 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 3049 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 3055 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 3064 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 3073 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3082 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3095 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3099 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3107 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3113 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3123 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3131 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3140 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3153 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3160 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3172 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3176 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3188 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3195 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3201 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3210 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3217 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3223 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3234 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3241 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3247 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3256 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3265 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3272 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3283 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3290 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3302 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3308 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3320 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3326 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3337 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3343 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3354 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3360 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3371 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3380 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3384 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3393 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3397 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3405 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3409 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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

  case 336:

/* Line 678 of lalr1.cc  */
#line 3419 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3426 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3435 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3444 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3449 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3458 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3467 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3476 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3489 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3493 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3505 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3509 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3516 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3520 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3528 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3532 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3536 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3544 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3548 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3554 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3560 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3566 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3576 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3580 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3584 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3592 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3596 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3602 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3612 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3616 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3626 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3630 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3640 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3644 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3654 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3658 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3668 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3672 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3680 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3684 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3688 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3692 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3702 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3706 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3710 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3718 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3722 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3726 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3730 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3734 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3738 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3746 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3750 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3754 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3762 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3766 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3770 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3774 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3785 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3791 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3801 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3807 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3817 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3821 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3825 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3863 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3867 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3877 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3887 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3900 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3909 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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

  case 407:

/* Line 678 of lalr1.cc  */
#line 3919 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3923 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3932 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3936 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3945 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3951 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3959 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3965 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3977 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3983 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3993 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3997 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 4001 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 4005 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 4009 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 4015 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 4021 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 4029 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 4033 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 4041 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 4045 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 4056 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 4060 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4064 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4070 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4074 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4088 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4092 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4100 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4104 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4114 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4118 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4122 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4126 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4135 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4139 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4143 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4147 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4155 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4161 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4171 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4179 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4183 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4187 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4191 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4195 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4199 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4203 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4207 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4211 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4215 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4219 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4227 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4231 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4239 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4246 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4253 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4264 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4272 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4276 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4284 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4292 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4300 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4354 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4358 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4371 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4377 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4387 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4391 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4399 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4403 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4407 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4415 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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

  case 480:

/* Line 678 of lalr1.cc  */
#line 4425 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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

  case 481:

/* Line 678 of lalr1.cc  */
#line 4435 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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

  case 482:

/* Line 678 of lalr1.cc  */
#line 4445 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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

  case 483:

/* Line 678 of lalr1.cc  */
#line 4455 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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

  case 484:

/* Line 678 of lalr1.cc  */
#line 4465 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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

  case 485:

/* Line 678 of lalr1.cc  */
#line 4480 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4486 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4497 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4503 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4514 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4531 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4536 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4545 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4549 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4556 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4562 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4568 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4576 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4588 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4592 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4599 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4605 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4611 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4618 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4629 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4633 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4643 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4647 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4657 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4661 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4665 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4670 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4679 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4685 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4691 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4697 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4705 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4710 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4718 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4723 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4731 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4739 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4744 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4749 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4754 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4759 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4764 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4773 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4781 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4785 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4802 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4806 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4814 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4822 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4830 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4834 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4842 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4848 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4858 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4866 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4870 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4874 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4909 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4915 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4931 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4935 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4939 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4943 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4947 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4951 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4955 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4962 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4968 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4978 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4986 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4990 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4994 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4998 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 5002 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 5006 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 5010 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5014 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5018 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5026 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5034 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5038 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5042 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5052 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5060 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5068 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5072 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5076 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5084 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5088 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5094 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5100 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5104 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5114 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5122 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5126 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5132 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5141 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5150 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5156 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5162 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5172 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5189 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5196 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5211 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5247 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5251 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5259 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5267 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5279 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5283 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5291 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5299 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5303 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5314 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5331 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5337 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5343 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5353 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5357 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5363 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5369 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5373 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5379 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5383 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5389 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5395 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5402 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5412 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5417 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5425 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5431 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5441 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5463 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5472 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5478 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5491 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5505 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5512 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5518 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5528 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5537 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5545 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5551 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5569 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5577 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5581 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5588 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5593 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5601 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5605 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5612 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5616 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5623 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5627 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5634 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5638 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5647 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5659 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5663 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5670 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5674 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5682 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5690 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5698 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5702 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5709 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5713 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5721 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5732 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5736 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5744 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5756 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5762 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5771 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5775 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5783 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5787 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5791 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5798 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5802 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5809 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5813 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5821 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5825 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5829 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5833 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5837 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5845 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5853 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5865 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5877 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5881 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5885 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5893 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5899 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5909 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5913 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5917 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5921 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5925 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5929 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5933 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5937 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5945 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5949 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5953 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5957 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5965 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5971 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5981 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5991 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5995 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 6003 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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

  case 701:

/* Line 678 of lalr1.cc  */
#line 6013 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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

  case 702:

/* Line 678 of lalr1.cc  */
#line 6024 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 6031 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 6035 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 6042 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 6046 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 6053 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 6058 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 6067 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 6076 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 6080 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 6087 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 6091 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 6099 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 6108 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 6115 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6125 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6129 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6136 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 6142 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6151 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6155 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 6162 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 6167 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 6179 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 6187 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 6199 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 6207 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 6211 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6219 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6223 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 6227 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 6235 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 6243 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6247 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6251 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6255 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 6263 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 6271 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6283 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 6287 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 6295 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 6304 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6308 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 6312 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 6316 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6320 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6328 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new JSON_PairConstructor(LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), (yysemantic_stack_[(6) - (5)].expr));
    }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 6336 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new JSON_ObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6340 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new JSON_ObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6344 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new JSON_ObjectConstructor(LOC((yyloc)), NULL);
    }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6352 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new JSON_ArrayConstructor(LOC((yyloc)), NULL);
    }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6356 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new JSON_ArrayConstructor(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6364 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new JSON_ArrayConstructor(LOC((yyloc)), NULL);
    }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6368 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new JSON_ArrayConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6376 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new JSON_ObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6384 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      JSON_DirectObjectContent* jpl = new JSON_DirectObjectContent(LOC((yyloc)));
      jpl->push_back((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = jpl;
    }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6390 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      static_cast<JSON_DirectObjectContent*>((yysemantic_stack_[(3) - (1)].expr))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.expr) = (yysemantic_stack_[(3) - (1)].expr);
    }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6398 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new JSON_PairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6406 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 6411 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6416 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6421 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6429 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
    }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 6436 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
    }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6443 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
    }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 6451 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonPair);
    }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 6469 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
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

  case 772:

/* Line 678 of lalr1.cc  */
#line 6482 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6483 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 6484 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 6485 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6486 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 6487 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 6488 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 6489 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 6490 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 6491 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6492 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 6493 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 6494 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6495 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 6496 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 6501 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6502 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6503 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 6504 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6505 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6506 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6507 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 6508 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6509 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6510 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6511 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6512 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6513 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6514 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6515 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6516 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6517 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6518 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6519 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6520 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6521 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6522 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6523 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6524 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6525 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6526 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6527 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6528 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6529 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6530 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6531 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6532 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6533 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6534 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6535 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6536 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6537 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6538 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6539 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6540 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6541 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6542 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6543 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6544 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6545 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6546 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6547 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6548 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6549 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6550 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6551 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6552 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6553 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6554 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6555 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6556 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6557 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6558 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6559 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6560 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6561 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6562 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6563 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6564 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6565 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6566 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6567 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6568 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6569 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6570 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6571 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6572 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6573 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6574 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6575 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6576 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6577 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6578 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6579 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6580 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6581 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6582 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6583 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6584 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6585 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6586 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6587 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6588 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6589 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6590 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6591 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6592 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6593 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6594 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6595 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6596 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6597 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6598 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6599 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6600 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6601 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6602 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6603 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6604 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6605 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6606 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6607 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6608 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6609 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6610 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6611 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6612 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6613 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6614 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6615 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6616 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6617 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6618 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6619 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6620 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6621 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6622 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6623 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6624 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6625 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6626 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6627 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6628 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6629 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6630 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6631 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6632 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6633 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6634 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6635 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6636 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6637 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6638 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6639 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6640 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6641 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6642 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6643 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6644 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6645 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6646 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6647 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6648 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6649 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6650 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6651 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6652 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6653 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6654 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6655 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6656 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6657 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6658 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6659 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6660 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 948:

/* Line 678 of lalr1.cc  */
#line 6661 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 949:

/* Line 678 of lalr1.cc  */
#line 6662 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 950:

/* Line 678 of lalr1.cc  */
#line 6663 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 951:

/* Line 678 of lalr1.cc  */
#line 6664 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 952:

/* Line 678 of lalr1.cc  */
#line 6665 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 953:

/* Line 678 of lalr1.cc  */
#line 6666 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 954:

/* Line 678 of lalr1.cc  */
#line 6667 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 955:

/* Line 678 of lalr1.cc  */
#line 6668 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 956:

/* Line 678 of lalr1.cc  */
#line 6669 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 957:

/* Line 678 of lalr1.cc  */
#line 6670 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 958:

/* Line 678 of lalr1.cc  */
#line 6671 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 959:

/* Line 678 of lalr1.cc  */
#line 6672 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 960:

/* Line 678 of lalr1.cc  */
#line 6673 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 961:

/* Line 678 of lalr1.cc  */
#line 6674 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 962:

/* Line 678 of lalr1.cc  */
#line 6675 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 963:

/* Line 678 of lalr1.cc  */
#line 6676 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 964:

/* Line 678 of lalr1.cc  */
#line 6677 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 965:

/* Line 678 of lalr1.cc  */
#line 6678 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 966:

/* Line 678 of lalr1.cc  */
#line 6679 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 967:

/* Line 678 of lalr1.cc  */
#line 6680 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 968:

/* Line 678 of lalr1.cc  */
#line 6681 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 969:

/* Line 678 of lalr1.cc  */
#line 6682 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 970:

/* Line 678 of lalr1.cc  */
#line 6683 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 971:

/* Line 678 of lalr1.cc  */
#line 6684 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 972:

/* Line 678 of lalr1.cc  */
#line 6685 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 973:

/* Line 678 of lalr1.cc  */
#line 6686 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 974:

/* Line 678 of lalr1.cc  */
#line 6687 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 975:

/* Line 678 of lalr1.cc  */
#line 6688 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 976:

/* Line 678 of lalr1.cc  */
#line 6689 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 977:

/* Line 678 of lalr1.cc  */
#line 6690 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 978:

/* Line 678 of lalr1.cc  */
#line 6691 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 979:

/* Line 678 of lalr1.cc  */
#line 6692 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 980:

/* Line 678 of lalr1.cc  */
#line 6693 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 981:

/* Line 678 of lalr1.cc  */
#line 6694 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 982:

/* Line 678 of lalr1.cc  */
#line 6695 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 983:

/* Line 678 of lalr1.cc  */
#line 6696 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 984:

/* Line 678 of lalr1.cc  */
#line 6697 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 985:

/* Line 678 of lalr1.cc  */
#line 6698 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 986:

/* Line 678 of lalr1.cc  */
#line 6699 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 987:

/* Line 678 of lalr1.cc  */
#line 6700 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 988:

/* Line 678 of lalr1.cc  */
#line 6701 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pair"))); }
    break;

  case 989:

/* Line 678 of lalr1.cc  */
#line 6702 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 990:

/* Line 678 of lalr1.cc  */
#line 6703 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 991:

/* Line 678 of lalr1.cc  */
#line 6708 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 678 of lalr1.cc  */
#line 11862 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1455;
  const short int
  xquery_parser::yypact_[] =
  {
      2959, -1455, -1455, -1455,  4470,  4470,  4470, -1455, -1455,   -24,
      12, -1455,   101,   171, -1455, -1455, -1455,   723, -1455, -1455,
   -1455,   238,   262,   740,   502,   298,   330,   658, -1455,   -35,
   -1455, -1455, -1455, -1455, -1455, -1455,   747, -1455,   461,   493,
   -1455, -1455, -1455, -1455,   315, -1455,   753, -1455,   499,   574,
   -1455,   191, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455,
   -1455, -1455, -1455, -1455, -1455, -1455,   357,   614, -1455, -1455,
   -1455, -1455,   689, 10208, -1455, -1455, -1455,   632, -1455, -1455,
   -1455,   419, -1455,   642,   695, -1455, -1455, 14000, -1455, -1455,
   -1455, -1455, -1455, -1455, -1455, -1455,   464, -1455, -1455,   733,
     763, -1455, -1455, -1455, -1455, -1455, -1455, -1455,  3262,  6282,
    6584, 14000, -1455, -1455, -1455, -1455, -1455, -1455, -1455,   688,
   -1455, -1455,   780, 11104, -1455, 11399,   790,   811, -1455, -1455,
   -1455,   815, -1455,  9604, -1455, -1455, -1455, -1455, -1455, -1455,
     767, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455,    46,
     729, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455,   381,
     786,   518, -1455,   724,   627, -1455, -1455, -1455, -1455, -1455,
   -1455,   832, -1455,   713,   717,   722, -1455, -1455,   803,   807,
   -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455,
   -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455,
   -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455,
   -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455,
   -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455,
   -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455,
   -1455, -1455, -1455, -1455,   808, -1455,   812,   814,  4772,   963,
   -1455,  5074, -1455, -1455,   477,    89, -1455, -1455, -1455, -1455,
   -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455,
      95, -1455, -1455, -1455, -1455, -1455, -1455,   152, -1455, -1455,
   -1455, -1455, -1455, -1455, -1455, -1455,  4470, -1455, -1455, -1455,
   -1455,    18, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455,
     861, -1455,   779, -1455, -1455, -1455,   146, -1455, -1455, -1455,
   -1455, -1455, -1455, -1455, -1455,   806,   877, -1455,   834,   728,
     524,   460,   486,   582, -1455,   927,   785,   878,   884,  8396,
   -1455, -1455, -1455,   217, -1455, -1455,  9906, -1455,   674, -1455,
     833, 10208, -1455,   833, 10208, -1455, -1455, -1455,   669, -1455,
   -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455,
   -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455,
   -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455,
   -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455,
   -1455, -1455, -1455, -1455, -1455, -1455, -1455,   843,   837, -1455,
   -1455, -1455, -1455, -1455,   810, -1455,  4470,   817,   818,   329,
     329,   960,   586,   592,   479, 14289, 14000,    -9,   947, 14000,
     846,   881,    90, 11104,   694,   760, 14000, 14000,   704,   573,
      32, -1455, -1455, -1455, 11104,  4470,   821,  4470,    68,  8698,
   11977,   726,   731, 14000,   893,   250,   859,  8698,  1013,    69,
      75, 14000,   898,   876,   912, -1455,  8698, 10807, 14000, 14000,
   14000,  4470,   835,  8698,  8698, 14000,  4470,   867,   870, -1455,
   -1455, -1455,  8698, 12266,   868, -1455,   869, -1455, -1455, -1455,
   -1455,   871, -1455,   872, -1455, -1455, -1455, -1455, -1455,   873,
   -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455,
   -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455,
   -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455,
   14000, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455,
   -1455, -1455, -1455,   889, 14000, -1455, -1455, -1455,   842,  3564,
     911,   187, -1455,   887,   890,   891, 14000,  4470, -1455,   892,
     236, -1455,   589, -1455,    19,  1023,  8698, -1455, -1455,    94,
   -1455, -1455, -1455,  1043, -1455, -1455, -1455, -1455,  8698,   849,
   -1455,  1033,  8698,  8698,   879,  8698,  8698,  8698,  8698,   838,
   14000,   874,   875,  8698,  8698,  3262,   823,  6886,  7188,  8698,
   -1455, -1455, -1455, -1455,   101,   658,    96,    98,  1066,  5376,
    5376,  5678,  5678,   419, -1455, -1455,   861,   419, -1455,  8698,
   -1455,   953,   502,   -35,   904,   906,   907,  4470,  8698, -1455,
   -1455, -1455, -1455, -1455, -1455, -1455, -1455,  9000,  9000,  9000,
   -1455,  9000,  9000, -1455,  9000, -1455,  9000, -1455, -1455, -1455,
   -1455, -1455, -1455, -1455,  9000,  9000,  1003,  9000,  9000,  9000,
    9000,  9000,  9000,  9000,  9000,  9000,  9000,  9000,   851,   987,
     988,   989, -1455, -1455, -1455,  7490, -1455, -1455,  9604,  9604,
    8698,   833, -1455, -1455,   833, -1455,  7792,   833,   936,  8094,
   -1455, -1455, -1455,    39, -1455,    47, -1455, -1455, -1455, -1455,
   -1455, -1455,   979,   980,   298,  1058, -1455, -1455, 14289,   968,
     557, 14000,   929,   934,   968,   960,   969,   965, -1455, -1455,
   -1455,   451,   850,  1005,   800, 14000,   959,  8698,   984, 14000,
   14000, -1455,   971,   920,  4470, -1455,   922,   869,   493, -1455,
     921,   924,   216, -1455,    67,   134, -1455, -1455,  1000, -1455,
      56, 14000,    30, 14000,  1014,   177, -1455,  4470, -1455,   209,
   -1455, 11104,  1015,  1067, 11104,   960,  1017,   462, 14000,  8698,
     -35,   251,   928, -1455,   930,   931,   932,    23, -1455,    78,
     937, -1455,   218,   229,   967, -1455,   938,  4470,  4470,   312,
   -1455,   240,   242,   481,  8698,    45, -1455, -1455,  8698,  8698,
   -1455,  8698,  8698,  8698, -1455,  8698, -1455,  8698, -1455, 14000,
    1023, -1455,   185,   321, -1455, -1455, -1455,   323, -1455,   345,
   -1455, -1455, -1455,   122,   124,  1021,   888,   899,    16, -1455,
     983, -1455, -1455,   939,   244,  3866,   325, 10510,   823, -1455,
   -1455,   350, -1455,   358,   363,  1006,   477,   635,  1092,  1092,
   -1455, -1455,   108, -1455, -1455,   111, -1455,    44, -1455, -1455,
   -1455, -1455, -1455, -1455, -1455, 14000,   958,  8698,  1012, -1455,
   -1455, -1455,   877, -1455, -1455, -1455, -1455, -1455,  9000, -1455,
   -1455, -1455,    51,   460,   460,   354,   486,   486,   486,   486,
     582,   582, -1455, -1455, 13422, 13422, 14000, 14000, -1455,   378,
   -1455, -1455,   275, -1455, -1455, -1455,   260, -1455, -1455,   271,
     329, -1455, -1455,   368,   431,   598, -1455,   298, -1455, -1455,
   -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455,   968, -1455,
     999, 13711,   990,  8698, -1455, -1455, -1455,  1038,   960,   960,
     968, -1455,   769,   960,   606, 14000,   -79,   270,  1104, -1455,
   -1455,   852,   442, -1455, -1455, -1455, -1455, -1455, -1455, -1455,
   -1455, -1455, -1455, -1455,   451,   594,   910,   555,  8698, -1455,
   14000,  1040,   840,   960, -1455, -1455, -1455, -1455,   986, 14000,
   -1455, 14000, -1455,  1022,  1016, 13422,  1024,  8698,   -12,   994,
      24,   215,   894, -1455, -1455,   718,    30,  1038, 13422,  1026,
    1050,   962,   951,  1018,   960,   991,  1020,  1052,   960,  8698,
     -25, -1455, -1455, -1455,  1001, -1455, -1455, -1455, -1455,  1035,
    8698,  8698,  1008, -1455,  1056,  1057,  4470, -1455,   974,   975,
    1007, 14000, -1455, 14000, -1455,  8698,  1019,   972,  8698, -1455,
     911, -1455,   272,   277,   279,  1127, -1455,   391, -1455,   435,
   -1455, -1455,  1134, -1455,   677,  8698,  8698,  8698,   686,  8698,
    8698,  8698,  8698,  8698,  8698,  1047,  8698,  8698, -1455,  5980,
    1010,  1011,  1025,  1027,   779,   719,   925, -1455,   401, -1455,
   -1455, -1455, -1455,  8698,   114,    37,    44,  5678,  5678,  5678,
    1088, -1455,  8698,   552,  1064, -1455, 14000,  1065, -1455, -1455,
    8698,    51,   511,   489, -1455,   900,   426,   916,   915, -1455,
   -1455,   760, -1455,   917,   585,  1029,  1030, 13711,  1031,  1034,
    1036,  1037,  1039,  1042, -1455,   415, -1455, -1455, -1455, -1455,
   -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455,
    1032, -1455, -1455, -1455,  8698, -1455, -1455, -1455, -1455, -1455,
   -1455, -1455, -1455, -1455,   602, -1455,  1145,   721, -1455, -1455,
   -1455, -1455, -1455, -1455, -1455, -1455, -1455,   914, -1455, -1455,
    1147, -1455, -1455, -1455, -1455, -1455,   471,  1148, -1455,   656,
   -1455, -1455, -1455,   868,   262,   871,   461,   872,   873,   786,
   -1455,   415,  9302,   903,   895, -1455,  1038,   594,   970,  1004,
    4470,  1028,  1041,  1059,  1044,  1045, 14000,   278, -1455, 14000,
   -1455,  8698,  1054,  8698,  1075,  8698,    40,  1060,  8698,  1061,
   -1455,  1087,  1091,  8698, 14000,   805,  1132, -1455, -1455, -1455,
   -1455, -1455, -1455, 13422, -1455,  4470,   960,  1110, -1455, -1455,
   -1455,   960,  1110, -1455,  8698,  1069,  4470, 14000, -1455, -1455,
    8698,  8698,   716, -1455,    41,   720, -1455, 12555,   727, -1455,
     735, -1455,  1049, -1455, -1455,  4470,  1048,  1051, -1455,  8698,
   -1455, -1455,  1046,  1056,  1118, -1455,  1089, -1455,   640, -1455,
   -1455,  1211, -1455, -1455,  4470, 14000, -1455,   788, -1455, -1455,
   -1455,  1055,   992,   993, -1455, -1455, -1455,   995,   997, -1455,
   -1455, -1455, -1455, -1455,  1053, 14000,  1062, -1455, -1455,  8698,
    8698,  8698,  4168,  5980, 10510,   925, -1455, 10510, -1455,  1063,
    1092,    99, -1455, -1455, -1455,  1064, -1455,   960, -1455,   797,
   -1455,    57,  1116, -1455,  8698,  1117,  1012,   383,  1068, -1455,
      51,  1071, -1455, -1455,   -30, -1455,   -43,    21,  1072,    51,
     -43,  9000, -1455,   469, -1455, -1455, -1455, -1455, -1455, -1455,
      51,  1093,   955,   850,    21, -1455, -1455,   956,  1163, -1455,
   -1455, -1455, 11688,  1070,  1073,  1074,  1076,  1077,  1078,  1079,
    1080, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455,
   -1455, -1455, -1455,  1214,   336,  1216,   336,   982,  1142, -1455,
    1098, 14000,  1083, -1455, -1455,  9302, -1455,  1086, -1455, -1455,
   -1455, -1455, -1455, -1455,  8698,  1112, -1455, -1455,  8698, -1455,
     497, -1455,  8698,  1124,  8698, -1455,  8698, 14000, 14000, -1455,
     653, -1455,  8698, -1455,  1146,  1150,  1177,   960,  1110, -1455,
    8698,  1095, -1455, -1455, -1455,  1094, -1455,   121,  8698,  4470,
    1096,   180, -1455, 14000,  1097, 12844,     9, -1455, 13133,  1099,
   -1455, -1455,  1100, -1455, -1455, -1455,  8698,   737,  1127, 14000,
     798, -1455,  1102,  1127, 14000, -1455, -1455,  8698,  8698,  8698,
    8698,  8698, -1455,  8698,   290,   297,   301,   437, -1455, -1455,
   -1455, -1455, -1455, -1455,  1116, -1455, -1455, -1455,   960, -1455,
   -1455, -1455, -1455, -1455,  1107,  9000, -1455, -1455, -1455, -1455,
   -1455,   113,  9000,  9000,   527, -1455,   916, -1455,    14, -1455,
     915,    51,  1139, -1455, -1455,   998, -1455, -1455, -1455, -1455,
    1198,  1108, -1455,   308, -1455, -1455, -1455, -1455, -1455, -1455,
   -1455, -1455, -1455,   425,   425, -1455,   336, -1455, -1455,   317,
   -1455,  1266,    21,  1200,  1111,  9302,   -14,  1085,  1129, -1455,
   -1455,  8698, -1455,  8698,  1154, -1455,  8698, -1455, -1455, -1455,
    1248, -1455, -1455,  5980,  8698,   960, -1455, -1455, -1455,  8698,
    8698, -1455, -1455, -1455,  5980,  5980,  1212,  4470, 14000,  1123,
   14000,  8698, 14000,  1125,  5980, -1455,    15,    26,  1127, 14000,
   -1455,  1114,  1127, -1455, -1455, -1455, -1455, -1455, -1455,  1115,
    1056,  1057,  8698, -1455, -1455, -1455, -1455,   486,  9000,  9000,
     354,   630, -1455, -1455, -1455, -1455, -1455, -1455,  8698, -1455,
   13422, -1455, 13422,  1218, -1455, -1455, -1455,  1284, -1455, -1455,
   -1455,  1082,  1215, -1455, -1455,  1217, -1455,   664, 14000,  1205,
    1101, 14000,  9302, -1455, -1455,  8698, -1455,  1209, -1455, -1455,
    1110, -1455, -1455, 13422, -1455, -1455,  1223,  8698,  1144, -1455,
    1236,  5980, -1455, 14000,   212,   633, -1455,  1136,  1127, -1455,
    1138,  5980,   744,   386,   354,   354,  9000,   387, -1455, -1455,
   13422, -1455, -1455,  1200,  9302, -1455,  1116,  1081, 14000,  1222,
    1119,  1217, -1455, 14000,  1149, 13422,  4470, 13422,  1155, -1455,
   -1455,  1253,   230, -1455, -1455, -1455, -1455,  1159,   660, -1455,
   -1455, -1455,  1152, -1455,  1233, -1455,   354, -1455, -1455, -1455,
   -1455, -1455,  8698,  1084, 14000,  1234, -1455,  4470,  1168, -1455,
   -1455,  1169,  8698, -1455, -1455, -1455, -1455, -1455, -1455, -1455,
   14000, -1455,  1090,  1103, 14000, -1455, -1455,  8698,  5980,  1170,
    1105,  8698,  1106,  5980,  9302, -1455,  9302, -1455,  1160,  1109,
   14000,  1135,  1242, 14000,  1113,  9302, -1455
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       159,   438,   439,   440,   162,   162,   162,   788,   991,   116,
     118,   591,   880,   889,   829,   793,   791,   773,   881,   884,
     836,   797,   774,   775,   828,   890,   777,   887,   858,   838,
     813,   833,   834,   885,   882,   832,   779,   888,   780,   781,
     929,   941,   928,   830,   849,   843,   782,   831,   784,   783,
     930,   867,   868,   835,   810,   951,   952,   953,   954,   955,
     956,   957,   958,   959,   960,   961,   975,   982,   857,   853,
     844,   824,   772,     0,   852,   860,   869,   976,   848,   461,
     825,   826,   883,   977,   983,   845,   862,     0,   467,   427,
     463,   855,   790,   846,   847,   876,   850,   866,   875,   981,
     984,   796,   837,   878,   462,   865,   871,   776,     0,     0,
       0,     0,   375,   863,   874,   879,   877,   856,   842,   931,
     840,   841,   978,     0,   374,     0,   979,   985,   872,   827,
     851,   980,   405,     0,   437,   873,   854,   861,   870,   864,
     932,   818,   823,   822,   821,   820,   819,   785,   839,     0,
     789,   886,   811,   920,   919,   921,   795,   794,   814,   926,
     778,   918,   923,   924,   915,   817,   859,   917,   927,   925,
     916,   815,   922,   936,   937,   934,   935,   933,   786,   938,
     939,   940,   906,   905,   892,   809,   802,   899,   895,   812,
     808,   907,   908,   798,   799,   792,   801,   904,   903,   900,
     896,   913,   914,   912,   902,   898,   891,   800,   911,   910,
     804,   806,   805,   897,   901,   893,   807,   894,   803,   909,
     962,   963,   964,   965,   966,   967,   943,   944,   942,   948,
     949,   950,   945,   946,   947,   816,   968,   969,   970,   971,
     972,   973,   974,   990,   987,   989,   986,   988,   159,     0,
       2,   159,     5,     7,    19,     0,    24,    27,    32,    33,
      34,    35,    36,    37,    38,    28,    54,    55,    29,    30,
       0,    72,    75,    76,    31,    77,    78,     0,   114,    79,
      80,    81,    82,    14,   156,   157,   158,   165,   167,   457,
     168,     0,   169,   170,   171,   172,   173,   174,   175,   178,
     163,   204,   211,   206,   233,   239,     0,   231,   232,   213,
     207,   177,   208,   176,   209,   212,   330,   332,   334,   344,
     348,   350,   353,   358,   361,   364,   366,   368,   370,     0,
     372,   378,   380,     0,   396,   379,   401,   404,   406,   409,
     411,     0,   416,   413,     0,   424,   434,   436,   410,   441,
     448,   459,   449,   450,   451,   454,   455,   452,   453,   474,
     476,   477,   478,   475,   523,   524,   525,   526,   527,   528,
     433,   565,   557,   564,   563,   562,   559,   561,   558,   560,
     460,   456,   592,   593,    39,   214,   215,   217,   216,   218,
     210,   458,   747,   745,   746,   743,   744,   435,   771,   787,
     880,   889,   887,   789,     0,   160,   161,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,   124,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   258,   259,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   429,
     432,   419,     0,     0,   773,   797,   775,   828,   890,   777,
     838,   779,   849,   782,   784,   783,   867,   975,   982,   772,
     976,   826,   977,   983,   850,   981,   984,   931,   978,   979,
     985,   980,   932,   926,   918,   924,   915,   815,   936,   937,
     934,   786,   938,   987,   986,   988,   425,   435,   771,   417,
       0,   185,   418,   421,   773,   774,   775,   779,   780,   781,
     782,   772,   778,   464,     0,   423,   422,   180,     0,     0,
     204,     0,   757,   777,   784,   783,     0,   162,   754,   938,
       0,   211,     0,   465,     0,   490,     0,   428,   769,     0,
     770,   399,   400,     0,   431,   430,   420,   403,     0,     0,
     519,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     1,     6,     8,     0,     0,     0,     0,     0,   159,
     159,   159,   159,     0,   115,   166,   164,     0,   183,     0,
     192,     0,     0,     0,     0,     0,     0,     0,     0,   197,
     219,   238,   234,   240,   235,   237,   236,     0,     0,     0,
     389,     0,     0,   387,     0,   339,     0,   388,   381,   386,
     385,   384,   383,   382,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   377,   376,   373,     0,   397,   402,     0,     0,
       0,   412,   445,   415,   414,   426,     0,   442,     0,     0,
     530,   532,   536,     0,   120,     0,   768,    43,    40,    41,
      44,    45,     0,     0,     0,     0,    46,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   602,   603,
     604,     0,    99,   138,     0,     0,   108,     0,     0,     0,
       0,   123,     0,     0,     0,   571,     0,     0,     0,   567,
       0,     0,     0,   581,     0,     0,   221,   222,   241,   242,
       0,     0,     0,     0,   130,     0,   134,   162,   595,     0,
      56,     0,    65,     0,     0,     0,    57,     0,     0,     0,
       0,     0,     0,   572,     0,     0,     0,     0,   303,     0,
       0,   570,     0,     0,     0,   589,     0,     0,     0,     0,
     575,     0,     0,   187,     0,     0,   181,   179,     0,     0,
     756,     0,     0,     0,   464,     0,   755,     0,   466,   491,
     490,   487,     0,     0,   521,   520,   398,     0,   518,     0,
     615,   616,   566,     0,     0,     0,     0,     0,     0,   621,
       0,   195,   196,     0,     0,     0,     0,     0,   200,   201,
     752,     0,   751,     0,     0,     0,    20,     0,    21,     0,
       4,    25,     0,    11,    26,     0,    15,   880,    73,    12,
      74,    16,   186,   184,   205,     0,     0,     0,     0,   198,
     220,   276,   331,   333,   337,   343,   342,   341,     0,   338,
     335,   336,     0,   352,   351,   349,   355,   356,   357,   354,
     359,   360,   363,   362,     0,     0,     0,     0,   394,     0,
     407,   408,     0,   446,   443,   472,     0,   594,   470,     0,
       0,   117,   119,     0,     0,     0,    98,     0,    88,    90,
      91,    92,    93,    95,    96,    97,    89,    94,    84,    85,
       0,     0,   104,     0,   100,   102,   103,   110,     0,     0,
      83,    42,     0,     0,     0,     0,     0,     0,     0,   693,
     698,     0,     0,   694,   728,   681,   683,   684,   685,   687,
     689,   688,   686,   690,     0,     0,     0,     0,     0,   107,
       0,   140,     0,     0,   535,   529,   568,   569,     0,     0,
     585,     0,   582,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   223,   224,     0,   229,   136,     0,     0,
     131,     0,     0,     0,     0,     0,     0,    58,     0,     0,
       0,   257,   263,   260,     0,   574,   573,   580,   588,     0,
       0,     0,     0,   534,     0,     0,     0,   390,     0,     0,
       0,     0,   578,     0,   576,     0,   188,     0,     0,   759,
       0,   758,     0,     0,     0,   490,   488,     0,   479,     0,
     468,   469,     0,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   193,     0,
     777,   784,   783,   938,     0,     0,     0,   629,     0,   202,
     753,   749,   750,     0,     0,     0,     0,   159,   159,   159,
       0,   230,     0,   287,   283,   285,     0,   277,   278,   340,
       0,     0,     0,     0,   659,   346,   632,   636,   638,   640,
     642,   645,   652,   653,   661,   890,   776,     0,   785,   990,
     987,   989,   986,   988,   365,   541,   547,   548,   551,   596,
     597,   552,   553,   760,   761,   762,   763,   556,   367,   369,
     538,   371,   395,   447,     0,   444,   471,   121,    52,    53,
      50,    51,   127,   126,     0,    86,     0,     0,   105,   106,
     111,    70,    71,    48,    49,    69,   699,     0,   702,   729,
       0,   692,   691,   696,   695,   727,     0,     0,   704,     0,
     700,   703,   682,     0,     0,     0,     0,     0,     0,     0,
     139,   142,     0,     0,     0,   109,   112,     0,     0,     0,
     162,     0,     0,   589,     0,     0,     0,     0,   540,     0,
     244,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     225,     0,     0,     0,     0,   270,     0,   267,   272,   228,
     137,   132,   135,     0,   182,     0,     0,    67,    61,    64,
      63,     0,    59,   261,     0,     0,   162,     0,   301,   305,
       0,     0,     0,   308,     0,     0,   314,     0,     0,   321,
       0,   325,     0,   392,   391,   162,     0,     0,   189,     0,
     191,   302,     0,     0,     0,   491,     0,   480,     0,   514,
     511,     0,   515,   516,     0,     0,   510,     0,   485,   513,
     512,     0,     0,     0,   608,   609,   605,     0,     0,   613,
     614,   610,   619,   617,     0,     0,     0,   623,   194,     0,
       0,     0,     0,     0,     0,   624,   625,     0,   203,     0,
      22,     0,    13,    17,    18,   284,   296,     0,   297,     0,
     288,   289,   290,   291,     0,   280,     0,     0,     0,   643,
     656,     0,   345,   347,     0,   675,     0,     0,     0,     0,
       0,     0,   631,   633,   634,   670,   671,   672,   674,   673,
       0,     0,   647,   646,     0,   650,   654,   668,   666,   665,
     658,   662,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   544,   546,   545,   542,   539,   473,   129,   128,    87,
     101,   716,   697,     0,   721,     0,   721,   710,   705,   143,
       0,     0,     0,   113,   141,     0,    23,     0,   586,   587,
     590,   583,   584,   243,     0,     0,   256,   248,     0,   252,
       0,   246,     0,     0,     0,   265,     0,     0,     0,   227,
     268,   271,     0,   133,     0,     0,    66,     0,    60,   262,
       0,     0,   304,   306,   311,     0,   309,     0,     0,     0,
       0,     0,   315,     0,     0,     0,     0,   322,     0,     0,
     326,   393,     0,   579,   577,   190,     0,     0,   490,     0,
       0,   522,     0,   490,     0,   486,    10,     0,     0,     0,
       0,     0,   622,     0,     0,     0,     0,     0,   626,   630,
     748,   300,   298,   299,   292,   293,   294,   286,     0,   281,
     279,   660,   651,   657,     0,     0,   730,   731,   741,   740,
     739,     0,     0,     0,     0,   732,   637,   738,     0,   635,
     639,     0,     0,   644,   648,     0,   669,   664,   667,   663,
       0,     0,   554,     0,   549,   601,   543,   550,   766,   764,
     765,   767,   717,     0,     0,   715,   722,   723,   719,     0,
     714,     0,   712,     0,     0,     0,     0,     0,     0,   531,
     245,     0,   254,     0,     0,   250,     0,   253,   266,   274,
     275,   269,   226,     0,     0,     0,    62,   264,   537,     0,
       0,   312,   316,   310,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   533,     0,     0,   490,     0,
     517,     0,   490,   606,   607,   611,   612,   618,   620,     0,
       0,     0,     0,   627,   295,   282,   655,   742,     0,     0,
     734,     0,   680,   679,   678,   677,   676,   641,     0,   733,
       0,   598,     0,     0,   726,   725,   724,     0,   718,   711,
     709,     0,   706,   707,   701,   144,   146,   148,     0,     0,
       0,     0,     0,   249,   247,     0,   255,     0,   199,   329,
      68,   307,   313,     0,   327,   323,     0,     0,     0,   317,
       0,     0,   319,     0,   500,   494,   489,     0,   490,   481,
       0,     0,     0,     0,   736,   735,     0,     0,   599,   555,
       0,   720,   713,     0,     0,   150,   149,     0,     0,     0,
       0,   145,   251,     0,     0,     0,     0,     0,     0,   508,
     502,     0,   501,   503,   509,   506,   496,     0,   495,   497,
     507,   483,     0,   482,     0,   628,   737,   649,   600,   708,
     147,   151,     0,     0,     0,     0,   273,     0,     0,   320,
     318,     0,     0,   493,   504,   505,   492,   498,   499,   484,
       0,   152,     0,     0,     0,   328,   324,     0,     0,     0,
       0,     0,     0,     0,     0,   154,     0,   153,     0,     0,
       0,     0,     0,     0,     0,     0,   155
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1455, -1455,  -217,  1128, -1455,  1120,  1121, -1455,  1126,  -532,
   -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455,
    -954, -1455, -1455, -1455, -1455,  -212,  -565, -1455,   657,  -334,
   -1455, -1455, -1455, -1455, -1455,   228,   440, -1455, -1455,    -2,
    -193,   954, -1455,   933, -1455, -1455,  -613, -1455,   376, -1455,
     190, -1455,  -264,  -305, -1455,  -554, -1455,    -3,    82,    25,
    -270,  -170, -1455,  -843, -1455, -1455,  -275, -1455, -1455, -1455,
   -1455, -1455, -1455, -1455, -1455, -1455, -1455,   558,   -88,  1240,
       0, -1455, -1455, -1455, -1455,   397, -1455, -1455,  -282, -1455,
      13, -1455, -1455,   189,  -715,  -688, -1455, -1455,   628, -1455,
   -1455,   -31,   175, -1455, -1455, -1455,    66, -1455, -1455,   311,
      71, -1455, -1455,    76, -1265, -1455,   862,   161, -1455, -1455,
     160,  -973, -1455, -1455,   158, -1455, -1455, -1210, -1205, -1455,
     154, -1455, -1455,   778,   783, -1455,  -468, -1455, -1455,  -629,
     283,  -618,   280,   282, -1455, -1455, -1455, -1455, -1455,  1122,
   -1455, -1455, -1455, -1455,  -849,  -318, -1133, -1455,  -105, -1455,
   -1455, -1455, -1455, -1455, -1455, -1455,   -34,  -777, -1455, -1455,
     528,   214, -1455,  -402, -1455, -1455, -1455, -1455, -1455, -1455,
   -1455,   734, -1455,  -988, -1455,   139, -1455,   608,  -788, -1455,
   -1455, -1455, -1455, -1455,  -296,  -288, -1204,  -992, -1455, -1455,
   -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455,   529,  -743,
    -874,   234,  -857, -1455,    59,  -774, -1455, -1455, -1455, -1455,
   -1455, -1455, -1455,   981,   985,  -151,   447,   274, -1455, -1455,
   -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455,
   -1455, -1455,   126, -1455, -1455,   117, -1455,   120, -1028, -1455,
   -1455, -1455,    92,    83,   -83,   340, -1455, -1455, -1455, -1455,
   -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455, -1455,    91,
   -1455, -1455, -1455,   -73,   335,   483, -1455, -1455, -1455, -1455,
   -1455,   269, -1455, -1455, -1454, -1455, -1455, -1455,  -607, -1455,
      54, -1455,   -94, -1455, -1455, -1455, -1455, -1271, -1455,   104,
   -1455, -1455, -1455, -1455, -1455, -1455, -1455,   857,   659, -1455,
   -1455, -1455, -1455, -1455,  -384,  -362,   909,   -18, -1455
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   249,   839,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
    1227,   755,   267,   268,   269,   270,   271,   272,   918,   919,
     920,   273,   274,   275,   924,   925,   926,   276,   429,   277,
     278,   683,   279,   431,   432,   433,   446,   745,   746,   280,
    1180,   281,  1635,  1636,   282,   283,   284,   538,   285,   286,
     287,   288,   289,   748,   290,   291,   521,   292,   293,   294,
     295,   296,   297,   619,   298,   299,   828,   829,   300,   301,
     551,   303,   620,   444,   985,   986,   304,   621,   305,   623,
     552,   307,   738,   739,  1215,   453,   308,   454,   455,   742,
    1216,  1217,  1218,   624,   625,  1087,  1088,  1489,   626,  1084,
    1085,  1320,  1321,  1322,  1323,   309,   767,   768,   310,  1242,
    1243,  1437,   311,  1245,  1246,   312,   313,  1248,  1249,  1250,
    1251,   314,   315,   316,   317,   868,   318,  1332,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     644,   645,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     671,   672,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   896,   358,   359,   360,  1277,   800,   801,   802,  1666,
    1707,  1708,  1701,  1702,  1709,  1703,  1278,  1279,   361,   362,
    1280,   363,   364,   365,   366,   367,   368,   369,  1129,   980,
    1114,  1374,  1115,  1523,  1116,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   774,  1192,   380,   381,   382,
     383,  1118,  1119,  1120,  1121,   384,   385,   386,   387,   388,
     389,   818,   819,   390,  1305,  1306,  1603,  1068,  1095,  1342,
    1343,  1096,  1097,  1098,  1099,  1100,  1352,  1513,  1514,  1101,
    1355,  1102,  1494,  1103,  1104,  1360,  1361,  1519,  1517,  1344,
    1345,  1346,  1347,  1615,   712,   945,   946,   947,   948,   949,
     950,  1170,  1544,  1632,  1171,  1542,  1630,   951,  1386,  1539,
    1535,  1536,  1537,   952,   953,  1348,  1356,  1504,  1349,  1500,
    1333,   391,   392,   393,   394,   395,   396,   541,   542,  1122,
    1123,  1124,  1125,  1126,  1228,   559,   397,   398,   399
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       302,   404,   407,   408,   302,   302,   302,   684,   684,   586,
     430,  1128,  1037,   306,  1000,   666,   605,   306,   306,   306,
     875,   550,   554,  1093,   622,   978,  1012,   687,   567,   406,
     406,   406,   876,   877,   878,   879,   848,   850,   600,   516,
    1026,  1244,   597,  1447,  1232,   843,   846,   849,   851,  1390,
    1067,  1276,   979,   602,  1457,   518,  1485,  1486,     9,    10,
    1204,   707,  1143,  1328,  1147,   752,   756,   841,   844,   518,
       9,    10,   722,  1465,   411,   412,   569,   413,   414,   415,
      11,   905,   451,  1515,   604,   982,   405,   405,   405,  1633,
     598,   415,   974,   518,   417,   764,   598,   598,   686,   598,
     416,  1198,   804,  1638,   686,   518,   418,   518,   302,   598,
    1117,  1117,   598,   727,  1221,   598,  1234,  1501,   418,  1664,
     976,   306,  1055,   419,   607,   609,  1580,     9,    10,  1009,
     728,   409,  1663,   539,  1201,   702,   605,   703,   411,   412,
    1438,   413,   414,   718,   702,   900,   703,  1117,   415,  1311,
     975,  1009,   976,   900,   420,   421,  1080,   416,   417,   696,
      79,   864,  1317,   865,   866,  1608,   867,   410,   869,   704,
    1205,   647,   975,   969,    90,   418,   870,   871,     9,    10,
     419,  1181,  1161,  1319,  1150,  1496,  1412,   753,   611,   648,
     405,   697,   612,  1162,  1581,   705,   423,   613,   606,   104,
    1581,  1117,   977,  1090,   705,   798,  1091,   608,  1665,  1639,
    1010,   420,   421,   422,  1117,   614,  1044,  1699,  1048,  1604,
    1438,  1269,  1497,  1498,  1011,   901,  1439,   125,   751,  1719,
    1499,   667,  1028,   902,   754,  1699,   452,   604,  1209,  1269,
     971,  1609,  1093,  1093,  1220,   983,   452,  1266,   302,  1056,
    1364,   302,  1447,   970,   729,   424,  1465,   706,   570,   452,
     423,   306,  1548,   603,   306,  1206,   706,   465,   805,   605,
     622,  1631,  1441,   848,   850,  1502,  1503,  1428,   599,  1438,
    1276,  1612,   984,   989,   601,   836,   302,   838,  1613,  1276,
    1202,  1640,  1207,   789,  1144,   452,   425,  1077,  1614,   306,
    1079,  1378,  1493,  1310,   841,   844,  1570,   673,  1092,   975,
     675,   452,  1235,   615,  1038,   609,   616,   719,   606,   424,
     972,   931,   609,   518,   609,   720,   518,   452,   852,   426,
     434,   617,   853,  1117,  1272,   609,  1273,   427,  1045,  1046,
    1049,  1050,   609,   466,  1700,   428,  1021,   859,  1023,  1423,
     609,   732,  1272,  1047,  1273,  1051,   618,   609,    11,   749,
     425,  1208,  1734,   990,  1274,  1575,  1134,   743,   761,   665,
     790,   997,  1685,  1444,   976,   772,   773,  1134,   609,   837,
    1039,   609,  1274,   609,   779,   609,   426,   842,   845,   993,
     437,  1672,   996,   125,   427,   992,   609,   694,   518,   968,
    1089,   518,   428,   609,  1014,   518,   302,   609,   518,   518,
     467,   468,  1637,  1181,  1622,  1015,   518,   438,   609,   306,
     796,  1721,   518,  1627,  1404,   518,  1022,   609,  1024,   609,
    1059,   609,   460,   518,  1004,   302,   744,   302,    79,   518,
     518,   518,   518,  1393,  1269,  1270,  1135,   518,   306,  1117,
     306,   606,    90,   445,   605,   518,   609,  1136,  1262,  1133,
     724,   302,   724,  1263,   609,  1264,   302,  1447,   803,   789,
    1094,  1533,  1276,  1117,   306,  1042,  1599,   104,   469,   306,
     807,  1093,  1405,  1600,   609,   447,   724,  1601,  1522,   609,
    1093,   724,   609,   609,  1623,  1020,   824,   826,  1137,   831,
     833,  1093,   518,  1628,  1040,   934,  1041,   935,  1066,  1637,
     594,   647,   848,   850,   848,  1138,   518,   723,  1413,   726,
    1267,  1383,  1334,  1312,  1313,  1314,   595,  1067,   518,   648,
    1479,  1163,  1139,  1070,  1043,  1534,   520,  1271,  1167,   302,
      11,  1071,  1164,   770,  1151,  1152,  1072,   302,   776,  1155,
     936,  1637,   306,  1302,  1168,   605,   975,  1272,  1371,  1273,
     306,  1132,   518,   890,   891,  1334,  1491,  1383,   441,  1715,
    1717,  1579,   406,   442,  1583,   975,   650,   889,  1140,  1189,
    1385,   534,   892,  1384,  1145,   302,  1268,  1274,  1117,  1602,
    1372,   111,   430,   976,  1335,  1141,  1145,  1169,   306,   302,
     302,   302,   302,   999,   572,   651,   573,  1373,   123,  1307,
     825,  1650,   306,   306,   306,   306,   458,   302,   652,   443,
      79,  1757,  1025,  1758,  1074,  1078,  1385,  1441,  1275,   405,
     306,   611,  1766,  1173,    90,   612,   606,  1335,  1174,   727,
     613,  1330,  1269,  1553,   692,  1307,   149,  1316,   459,  1269,
    1270,   921,   653,  1175,   463,  1176,   728,  1317,   614,   104,
     693,  1705,  1093,  1090,  1177,   125,  1091,  1318,  1075,  1269,
    1587,  1117,  1704,  1710,  1117,  1591,  1336,  1337,  1319,  1338,
     907,   647,   448,   518,   595,   654,  1339,   125,  1705,  1094,
    1094,  1178,   449,   922,   655,  1554,  1340,   518,   923,   648,
     937,   518,   518,  1032,  1033,  1034,  1211,   826,  1341,   716,
    1704,  1212,  1508,   938,   717,   939,  1710,   656,   450,  1336,
    1337,   649,  1338,   518,   302,   518,   940,   941,   942,   464,
     943,   657,   944,   518,  1142,   470,   518,   306,  1377,  1340,
     518,   575,  1271,   576,   991,   848,  1678,   302,  1679,   976,
     747,  1341,  1167,   519,   747,  1272,   615,  1273,   975,   616,
     306,   611,  1272,   522,  1273,   612,  1706,   688,  1168,  1317,
     613,  1211,   406,   690,   797,   666,  1212,   302,   302,  1694,
     689,   518,  1272,   622,  1273,  1274,   691,   647,   614,  1298,
     306,   306,  1274,  1737,  1612,  1213,   111,  1269,  1270,   618,
    1667,  1613,   724,   724,  1670,   648,  1718,  1269,  1270,   518,
     471,  1614,  1274,   123,   976,  1241,   523,  1179,  1191,  1241,
    1194,  1728,   670,  1731,   676,  1064,  1445,  1676,  1435,   405,
    1357,  1358,  1440,  1459,  1448,  1214,  1445,   518,  1065,  1446,
     556,   472,  1426,  1445,   473,   430,  1117,  1449,  1117,  1586,
     578,   149,  1183,  1359,   535,   579,  1714,   922,  1211,  1018,
    1019,  1184,   923,  1212,   668,   669,   518,   518,   518,   518,
    1256,   674,  1257,  1610,  1611,   435,   677,  1607,   436,  1117,
    1712,  1156,  1157,  1158,   536,   893,   615,  1159,   893,   616,
    1271,   893,   439,   586,  1686,   440,  1153,  1154,  1308,   456,
    1271,   557,   457,   518,  1303,   461,  1117,  1282,   462,  1283,
    1272,   564,  1273,   708,   709,   710,  1287,   518,  1288,   568,
    1272,  1117,  1273,  1117,  1482,  1483,  1624,  1625,  1094,   618,
     873,   874,   565,  1481,   880,   881,   566,  1094,   882,   883,
    1274,   574,   518,   571,   111,  1130,  1130,   577,  1094,   580,
    1274,   518,   581,   518,   111,  1424,   582,   518,   584,   585,
     587,   123,   583,   591,   588,   629,   589,   609,   610,   628,
     518,   123,   627,   630,   631,   646,   632,   658,   660,  1674,
    1675,  1464,   517,   659,   633,   661,   670,   678,   634,   686,
     635,  1589,   679,   680,   698,   636,   533,   700,   701,   149,
     681,   682,  1327,   518,   711,   518,   715,   725,   736,   149,
     741,   747,   637,   737,   750,   758,   302,   759,   760,   777,
     555,   771,   778,   436,   440,   786,   457,   462,   473,   306,
     784,   788,   560,   859,   563,   638,   639,   640,   641,   642,
     643,   724,   791,  1566,   795,   792,   793,  1716,   908,   909,
     910,   911,   912,   913,   914,   915,   916,   917,   799,  1064,
     806,   808,   809,   821,   822,   812,   827,   817,   518,   840,
     855,   856,  1065,   872,   430,   857,   858,   302,   302,   302,
     884,   885,   886,   887,   897,   903,   904,   906,   928,   518,
     306,   306,   306,   929,   954,   932,   933,   956,  1252,   955,
     958,   960,   963,   964,  1605,   965,   973,   966,   988,  1094,
     967,   994,   995,   998,  1005,  1052,  1006,  1007,  1008,  1016,
    1013,  1017,  1054,  1053,  1057,  1076,  1073,  1082,  1058,  1086,
    1146,   923,   975,  1165,  1187,  1182,  1166,  1188,  1190,  1196,
    1203,  1199,  1197,   743,  1223,  1224,  1210,  1225,  1231,  1226,
    1229,  1230,  1237,  1236,  1240,  1241,  1247,  1253,  1254,  1255,
    1259,  1260,  1265,  1281,  1295,  1299,  1300,   704,  1304,  1572,
    1324,  1326,  1350,  1351,    11,  1375,  1382,  1387,   518,  1302,
    1301,   518,  1354,  1331,  1362,  1363,  1365,  1397,  1391,  1366,
     302,  1367,  1368,  1396,  1369,  1395,   518,  1370,  1381,  1392,
    1408,  1410,  1400,   306,  1417,   518,  1414,  1416,  1418,  1422,
    1430,  1474,  1475,  1476,  1398,   406,  1427,  1445,  1461,   518,
    1458,  1317,  1488,  1467,  1468,   302,  1469,  1399,  1470,   518,
    1401,  1402,  1451,  1431,  1453,  1512,   302,  1454,   306,  1511,
    1516,  1518,  1456,  1532,  1466,  1538,  1480,  1473,  1543,   306,
     517,  1541,  1452,   517,  1492,   302,  1524,   518,  1551,  1525,
    1526,   406,  1527,  1528,  1529,  1530,  1531,  1545,   306,  1549,
    1556,  1563,   405,  1565,   302,  1564,  1619,   518,  1568,  1569,
     406,  1574,  1577,  1585,  1584,  1590,   518,   306,  1471,   518,
    1606,  1618,  1620,  1648,  1621,  1629,  1167,  1634,  1642,   724,
    1645,  1647,  1064,  1064,  1652,  1572,  1653,  1654,  1657,  1669,
    1661,  1671,  1680,  1681,  1662,  1065,  1065,  1695,   405,  1495,
    1505,  1683,  1688,  1684,  1689,   695,  1693,   825,   699,  1696,
    1697,  1711,   560,  1713,  1727,   713,   714,   405,  1547,  1724,
    1732,  1736,  1725,   560,   518,  1682,  1733,  1739,   540,   735,
    1740,  1744,   740,  1747,  1748,  1753,  1462,  1759,  1762,  1763,
     757,   930,  1148,   721,   685,  1222,   560,   765,   766,   769,
    1641,   592,   593,   518,   775,  1380,   590,  1394,  1691,  1720,
     596,  1750,   782,  1219,  1722,  1403,  1069,  1742,  1003,  1561,
    1421,  1654,  1490,  1315,  1760,  1487,   785,  1484,  1432,   518,
     518,  1424,  1436,  1442,  1450,   862,  1751,  1460,  1036,  1754,
    1756,   863,  1738,   899,  1735,  1389,  1131,  1765,  1195,   730,
    1379,  1472,  1478,   731,  1477,   518,  1729,   518,  1617,   783,
     518,  1506,  1329,  1510,  1509,  1616,  1353,  1172,  1388,   302,
    1540,   518,  1626,   769,  1507,   834,   518,     0,  1031,     0,
       0,   664,   306,     0,     0,   794,     0,  1745,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1745,     0,
       0,     0,     0,  1729,     0,     0,     0,     0,     0,   820,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1673,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1677,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     518,     0,   518,  1064,   518,     0,     0,     0,     0,     0,
       0,   518,     0,     0,  1064,  1064,  1065,   302,     0,     0,
       0,     0,     0,     0,  1064,     0,     0,  1065,  1065,     0,
     306,     0,     0,     0,     0,     0,     0,  1065,     0,     0,
       0,     0,   518,     0,   518,     0,     0,     0,     0,     0,
     927,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     518,     0,     0,   518,   957,     0,     0,     0,   961,   962,
       0,     0,     0,     0,     0,   518,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   518,     0,     0,     0,     0,
     981,     0,   987,     0,     0,     0,     0,     0,     0,     0,
     560,  1064,   518,   560,     0,     0,     0,  1001,     0,     0,
     518,  1064,     0,     0,  1065,   518,     0,   518,     0,   518,
       0,     0,     0,     0,  1065,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   302,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   518,     0,  1035,   306,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   518,     0,     0,     0,   518,   302,     0,     0,
       0,     0,     0,     0,     0,     0,   517,     0,     0,     0,
     306,     0,   518,     0,     0,   518,     0,     0,  1064,     0,
       0,     0,     0,  1064,     0,     0,     0,     0,     0,     0,
       0,  1065,     0,     0,  1081,     0,  1065,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   540,     0,     0,
       0,     0,     0,  1127,  1127,  1127,  1127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   810,   811,     0,   813,   814,   815,   816,     0,
       0,     0,     0,   823,     0,     0,     0,     0,   540,   835,
    1127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1160,     0,     0,     0,     0,   854,
       0,     0,     0,     0,     0,     0,     0,   860,   861,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1186,
       0,     0,     0,     0,     0,     0,     0,     0,  1193,     0,
    1193,     0,     0,     0,  1127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   895,     0,     0,   895,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     775,     0,   775,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   959,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1325,     0,     0,     0,  1002,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1127,     0,     0,     0,
       0,     0,     0,     0,  1027,     0,     0,     0,  1029,  1030,
       0,     0,     0,     0,     0,     0,     0,   860,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1083,     0,     0,
       0,     0,     0,     0,     0,   740,     0,     0,  1406,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1420,     0,     0,     0,     0,     0,     0,
       0,     0,  1127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   769,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1127,     0,     0,     0,
       0,     0,     0,  1149,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1463,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1185,     0,
       0,     0,     0,     0,   820,     0,     0,     0,     0,     0,
       0,     0,     0,   517,     0,     0,   517,  1200,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1233,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1238,  1239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1258,     0,     0,  1261,     0,
       0,  1127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1284,  1285,  1286,     0,  1289,
    1290,  1291,  1292,  1293,  1294,     0,  1296,  1297,     0,     0,
    1546,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1309,     0,     0,     0,     0,     0,     0,
       0,     0,  1083,     0,     0,     0,  1559,  1560,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1576,     0,  1127,     0,     0,  1127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1588,     0,
       0,     0,     0,  1592,  1376,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1407,     0,  1409,     0,  1411,     0,     0,  1415,     0,
       0,     0,     0,  1419,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1425,     0,     0,     0,     0,
       0,     0,     0,     0,  1429,     0,     0,     0,     0,     0,
    1433,  1434,     0,     0,     0,     0,     0,  1656,     0,  1658,
       0,  1660,     0,     0,     0,     0,     0,     0,  1668,  1455,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1127,
       0,  1127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1687,     0,     0,
    1690,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1127,     0,  1083,     0,     0,     0,     0,     0,
       0,     0,  1698,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1127,
       0,     0,     0,     0,     0,     0,     0,  1723,     0,     0,
       0,     0,  1726,     0,  1127,     0,  1127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1743,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1550,     0,     0,     0,  1552,  1749,
       0,     0,  1555,  1752,  1557,     0,  1558,     0,     0,     0,
       0,     0,  1562,     0,     0,     0,     0,     0,     0,  1761,
    1567,     0,  1764,     0,     0,     0,     0,     0,  1571,  1573,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1425,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1593,  1594,  1595,
    1596,  1597,     0,  1598,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1643,     0,  1644,     0,     0,  1646,     0,     0,     0,
       0,     0,     0,     0,  1649,     0,     0,     0,     0,  1651,
    1573,     0,     0,     0,     0,     0,     0,  1655,     0,     0,
       0,  1659,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1692,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1655,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1730,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1741,     0,     0,     0,     0,  1746,     0,     0,
       1,     2,  1730,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,  1746,    11,     0,
       0,  1755,    12,    13,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,    74,    75,
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
     149,     0,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,   400,   401,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   402,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,    74,    75,    76,     0,     0,    77,    78,     0,     0,
       0,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,     0,     0,    90,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,    96,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     0,   110,   111,   112,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,     0,   123,     0,   124,   125,     0,
       0,   126,   127,   128,     0,   537,     0,   129,     0,   130,
     131,     0,   132,   133,   134,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   403,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   400,   401,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   402,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   108,   109,     0,   110,
     111,   112,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   123,     0,   124,
     125,     0,     0,   126,   127,   128,     0,   787,     0,   129,
       0,   130,   131,     0,   132,   133,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   403,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,     0,     0,     0,   400,
     401,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,  1060,   402,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,  1061,  1062,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   108,   109,
       0,   110,   111,   112,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
       0,   124,   125,     0,     0,   126,   127,   128,     0,   787,
       0,   129,     0,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   403,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,  1063,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   400,   401,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,  1060,   402,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
    1061,  1062,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     108,   109,     0,   110,   111,   112,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,     0,   124,   125,     0,     0,   126,   127,   128,
       0,   537,     0,   129,     0,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   403,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
    1063,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
       0,     0,     0,   400,   401,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   402,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,    74,
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
     148,   149,     0,   403,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,    12,    13,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,    74,    75,    76,     0,     0,    77,    78,     0,     0,
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
       0,   147,   148,   149,     0,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,    12,    13,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,    74,    75,    76,     0,     0,    77,    78,
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
     146,     0,     0,   147,   148,   149,     0,   403,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,     0,     0,     0,    12,
     401,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,    74,    75,    76,     0,     0,
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
     144,   145,   146,     0,     0,   147,   148,   149,     0,   403,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   847,   401,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   402,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,    74,    75,    76,
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
       0,   403,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
       0,     0,     0,   400,   401,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,  1060,   402,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,  1061,  1062,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,    74,
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
     148,   149,     0,   403,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,  1063,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   400,   401,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     543,   402,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,   544,   545,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,    74,    75,    76,     0,     0,    77,    78,     0,     0,
       0,    79,    80,   491,    82,    83,    84,    85,    86,   546,
      88,    89,     0,     0,     0,    90,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,    96,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   547,   109,     0,   110,   111,   112,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,     0,   123,     0,   124,   125,     0,
       0,   126,   127,   128,     0,     0,   548,   129,     0,   130,
     131,     0,   132,   133,   134,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   403,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   508,   509,
     510,   176,   177,   511,   549,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   400,   401,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   543,   402,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   544,   545,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,   491,    82,    83,    84,    85,
      86,   546,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   547,   109,     0,   110,
     111,   112,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   123,     0,   124,
     125,     0,     0,   126,   127,   128,     0,     0,     0,   129,
     553,   130,   131,     0,   132,   133,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   403,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     508,   509,   510,   176,   177,   511,   549,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   400,
     401,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   543,   402,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,   544,   545,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,   491,    82,    83,
      84,    85,    86,   546,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   547,   109,
       0,   110,   111,   112,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
       0,   124,   125,     0,     0,   126,   127,   128,     0,   830,
       0,   129,     0,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   403,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   508,   509,   510,   176,   177,   511,   549,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   400,   401,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   543,   402,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     544,   545,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,   491,
      82,    83,    84,    85,    86,   546,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     547,   109,     0,   110,   111,   112,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,     0,   124,   125,     0,     0,   126,   127,   128,
       0,   832,     0,   129,     0,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   403,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   508,   509,   510,   176,   177,   511,
     549,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     0,     0,     0,    11,
       0,     0,     0,   400,   401,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   543,   402,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,   544,   545,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,    74,
      75,    76,     0,     0,    77,    78,     0,     0,     0,    79,
      80,   491,    82,    83,    84,    85,    86,   546,    88,    89,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,    96,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   547,   109,     0,   110,   111,   112,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   123,     0,   124,   125,     0,     0,   126,
     127,   128,     0,   888,     0,   129,     0,   130,   131,     0,
     132,   133,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   403,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   508,   509,   510,   176,
     177,   511,   549,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   400,   401,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     543,   402,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,   544,   545,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,    74,    75,    76,     0,     0,    77,    78,     0,     0,
       0,    79,    80,   491,    82,    83,    84,    85,    86,   546,
      88,    89,     0,     0,     0,    90,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,    96,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   547,   109,     0,   110,   111,   112,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,     0,   123,     0,   124,   125,     0,
       0,   126,   127,   128,     0,     0,     0,   129,   894,   130,
     131,     0,   132,   133,   134,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   403,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   508,   509,
     510,   176,   177,   511,   549,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   400,   401,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   543,   402,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   544,   545,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,   491,    82,    83,    84,    85,
      86,   546,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   547,   109,     0,   110,
     111,   112,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   123,     0,   124,
     125,     0,     0,   126,   127,   128,     0,     0,     0,   129,
     898,   130,   131,     0,   132,   133,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   403,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     508,   509,   510,   176,   177,   511,   549,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   400,
     401,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   477,    25,   479,   402,    28,   480,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,   482,     0,    45,    46,    47,   484,   485,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,   491,    82,    83,
      84,    85,    86,   546,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     494,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   547,   109,
       0,   110,   111,   662,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
       0,   663,   125,     0,     0,   126,   127,   128,     0,     0,
       0,   129,     0,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   403,
     151,   152,   153,   154,   155,   156,   157,   158,   503,   160,
     504,   162,   505,   506,   165,   166,   167,   168,   169,   170,
     507,   172,   508,   509,   510,   176,   177,   511,   512,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   400,   401,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   543,   402,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     544,   545,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,   491,
      82,    83,    84,    85,    86,   546,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     547,   109,     0,   110,   111,   112,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,     0,   124,   125,     0,     0,   126,   127,   128,
       0,     0,     0,   129,     0,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   403,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   508,   509,   510,   176,   177,   511,
     549,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     0,     0,     0,    11,
       0,     0,     0,   400,   401,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   477,    25,   479,   402,
      28,   480,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,   482,     0,    45,
      46,    47,   484,   485,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,    74,
      75,    76,     0,     0,    77,    78,     0,     0,     0,    79,
      80,   491,    82,    83,    84,    85,    86,   546,    88,    89,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   494,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   547,   109,     0,   110,   111,   112,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   123,     0,   124,   125,     0,     0,   126,
     127,   128,     0,     0,     0,   129,     0,   130,   131,     0,
     132,   133,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   403,   151,   152,   153,   154,   155,   156,
     157,   158,   503,   160,   504,   162,   505,   506,   165,   166,
     167,   168,   169,   170,   507,   172,   508,   509,   510,   176,
     177,   511,   512,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   400,   401,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   477,    25,
     479,   402,    28,   480,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,   482,
       0,    45,    46,    47,   484,   485,    50,   486,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,    74,    75,    76,     0,     0,    77,    78,     0,     0,
       0,    79,    80,   491,    82,    83,    84,    85,    86,   546,
      88,    89,     0,     0,     0,    90,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   494,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   547,   109,     0,   110,   111,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,     0,   123,     0,     0,     0,     0,
       0,   126,   127,   128,     0,     0,     0,   129,     0,   130,
     131,     0,   132,   133,   134,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   403,   151,   152,   153,   154,
     155,   156,   157,   158,   503,   160,   504,   162,   505,   506,
     165,   166,   167,   168,   169,   170,   507,   172,   508,   509,
     510,   176,   177,   511,   512,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   400,   401,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     477,    25,   479,   402,    28,   480,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,   482,     0,    45,    46,    47,   484,   485,    50,   486,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,   491,    82,    83,    84,    85,
      86,   546,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   494,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   547,   109,     0,   110,
     111,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   123,     0,     0,
       0,     0,     0,   126,   127,   128,     0,     0,     0,   129,
       0,   130,   131,     0,     0,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   403,   151,   152,
     153,   154,   155,   156,   157,   158,   503,   160,   504,   162,
     505,   506,   165,   166,   167,   168,   169,   170,   507,   172,
     508,   509,   510,   176,   177,   511,   512,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   400,
     401,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   477,    25,   479,   402,    28,   480,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,   482,     0,    45,    46,    47,   484,   485,
      50,   486,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,   491,    82,    83,
      84,    85,    86,   546,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     494,     0,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,     0,   106,   107,   547,   109,
       0,   110,   111,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
       0,     0,     0,     0,     0,   126,   127,   128,     0,     0,
       0,   129,     0,   130,   131,     0,     0,     0,   134,     0,
     135,     0,   136,     0,   138,     0,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   403,
     151,   152,   153,   154,   155,   156,   157,   158,   503,   160,
     504,   162,   505,   506,   165,   166,   167,   168,   169,   170,
     507,   172,   508,   509,   510,   176,   177,   511,   512,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,   400,   401,     0,    14,    15,    16,   474,    18,    19,
      20,   475,    22,   476,   477,   478,   479,   402,    28,   480,
      30,    31,     0,    32,    33,    34,    35,   481,    37,    38,
      39,    40,    41,    42,    43,   482,     0,    45,   483,    47,
     484,   485,    50,   486,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   487,   488,
      68,     0,    69,    70,    71,   489,     0,    74,    75,    76,
       0,     0,   490,    78,     0,     0,     0,     0,    80,   491,
      82,   492,   493,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   494,    97,    98,   495,   496,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   497,   120,   121,   498,
       0,     0,     0,     0,     0,     0,     0,   499,   500,   128,
       0,     0,     0,   129,     0,   130,   501,     0,     0,     0,
     134,     0,   135,     0,   136,   137,   138,   139,   502,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,     0,
       0,   403,   151,   152,   153,   154,   155,   156,   157,   158,
     503,   160,   504,   162,   505,   506,   165,   166,   167,   168,
     169,   170,   507,   172,   508,   509,   510,   176,   177,   511,
     512,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   513,   245,   514,
     515,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,   400,   401,     0,    14,    15,    16,   524,
      18,    19,    20,   475,   525,   526,   477,   478,   479,   402,
      28,   480,    30,    31,     0,    32,    33,    34,    35,   527,
      37,   528,   529,    40,    41,    42,    43,   482,     0,    45,
     530,    47,   484,   485,    50,   486,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     487,   488,    68,     0,    69,    70,    71,   531,     0,    74,
      75,    76,     0,     0,   490,    78,     0,     0,     0,     0,
      80,   491,    82,   492,   493,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   494,    97,    98,   495,   496,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   497,   120,
     121,   498,     0,     0,     0,     0,     0,     0,     0,   499,
     500,   128,     0,     0,     0,   129,     0,   130,   501,     0,
       0,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     502,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,     0,     0,   403,   151,   152,   153,   154,   155,   156,
     157,   158,   503,   532,   504,   162,   505,   506,   165,   166,
     167,   168,   169,   170,   507,   172,   508,   509,   510,   176,
     177,   511,   512,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   513,
     245,   514,   515,   558,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,   762,     0,     0,     0,
     400,   401,     0,    14,    15,    16,   524,    18,    19,    20,
     475,   525,   526,   477,   478,   479,   402,    28,   480,    30,
      31,     0,    32,    33,    34,    35,   527,    37,   528,   529,
      40,    41,    42,    43,   482,     0,    45,   530,    47,   484,
     485,    50,   486,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   487,   488,    68,
       0,    69,    70,    71,   531,     0,    74,    75,    76,     0,
       0,   490,    78,     0,     0,     0,     0,    80,   491,    82,
     492,   493,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   494,    97,    98,   495,   496,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   497,   120,   121,   498,     0,
       0,     0,     0,     0,     0,     0,   499,   500,   128,     0,
       0,     0,   129,   763,   130,   501,     0,     0,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   502,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     403,   151,   152,   153,   154,   155,   156,   157,   158,   503,
     532,   504,   162,   505,   506,   165,   166,   167,   168,   169,
     170,   507,   172,   508,   509,   510,   176,   177,   511,   512,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   513,   245,   514,   515,
     558,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,   400,   401,     0,
      14,    15,    16,   524,    18,    19,    20,   475,   525,   526,
     477,   478,   479,   402,    28,   480,    30,    31,     0,    32,
      33,    34,    35,   527,    37,   528,   529,    40,    41,    42,
      43,   482,     0,    45,   530,    47,   484,   485,    50,   486,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   487,   488,    68,     0,    69,    70,
      71,   531,     0,    74,    75,    76,     0,     0,   490,    78,
       0,     0,     0,     0,    80,   491,    82,   492,   493,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   494,    97,
      98,   495,   496,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,   107,     0,     0,     0,     0,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   497,   120,   121,   498,     0,     0,     0,     0,
       0,     0,     0,   499,   500,   128,     0,     0,     0,   129,
       0,   130,   501,     0,     0,     0,     0,     0,   135,     0,
     136,   137,   138,   139,   502,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,     0,     0,   403,   151,   152,
     153,   154,   155,   156,   157,   158,   503,   532,   504,   162,
     505,   506,   165,   166,   167,   168,   169,   170,   507,   172,
     508,   509,   510,   176,   177,   511,   512,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   513,   245,   514,   515,   561,   562,     0,
       0,     0,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,   400,   401,     0,    14,    15,    16,   524,    18,
      19,    20,   475,   525,   526,   477,   478,   479,   402,    28,
     480,    30,    31,     0,    32,    33,    34,    35,   527,    37,
     528,   529,    40,    41,    42,    43,   482,     0,    45,   530,
      47,   484,   485,    50,   486,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   487,
     488,    68,     0,    69,    70,    71,   531,     0,    74,    75,
      76,     0,     0,   490,    78,     0,     0,     0,     0,    80,
     491,    82,   492,   493,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   494,    97,    98,   495,   496,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
     107,     0,     0,     0,     0,     0,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   497,   120,   121,
     498,     0,     0,     0,     0,     0,     0,     0,   499,   500,
     128,     0,     0,     0,   129,     0,   130,   501,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   502,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
       0,     0,   403,   151,   152,   153,   154,   155,   156,   157,
     158,   503,   532,   504,   162,   505,   506,   165,   166,   167,
     168,   169,   170,   507,   172,   508,   509,   510,   176,   177,
     511,   512,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   513,   245,
     514,   515,     7,     8,     0,     0,     0,     0,     0,     0,
       0,   400,   401,     0,    14,    15,    16,   474,    18,    19,
      20,   475,    22,   476,   477,  1105,   479,   402,    28,   480,
      30,    31,     0,    32,    33,    34,    35,   481,    37,    38,
      39,    40,    41,    42,    43,   482,     0,    45,   483,    47,
     484,   485,    50,   486,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   487,   488,
      68,     0,    69,    70,    71,   489,     0,    74,    75,    76,
       0,     0,   490,    78,     0,     0,     0,     0,    80,   491,
      82,   492,   493,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   494,    97,    98,   495,   496,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,  1106,
       0,     0,     0,  1107,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   497,   120,   121,   498,
       0,     0,     0,     0,     0,     0,     0,   499,   500,   128,
       0,     0,     0,   129,  1520,   130,   501,     0,     0,     0,
    1521,     0,   135,     0,   136,   137,   138,   139,   502,   141,
     142,   143,   144,   145,   146,     0,     0,  1108,   148,     0,
       0,   403,   151,   152,   153,   154,   155,   156,   157,   158,
     503,   160,   504,   162,   505,   506,   165,   166,   167,   168,
     169,   170,   507,   172,   508,   509,   510,   176,   177,   511,
     512,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,  1109,  1110,  1111,  1112,
    1113,     7,     8,     0,     0,     0,     0,     0,     0,     0,
     400,   401,     0,    14,    15,    16,   524,    18,    19,    20,
     475,   525,   526,   477,   478,   479,   402,    28,   480,    30,
      31,     0,    32,    33,    34,    35,   527,    37,   528,   529,
      40,    41,    42,    43,   482,     0,    45,   530,    47,   484,
     485,    50,   486,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   487,   488,    68,
       0,    69,    70,    71,   531,     0,    74,    75,    76,     0,
       0,   490,    78,     0,     0,     0,     0,    80,   491,    82,
     492,   493,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   494,    97,    98,   495,   496,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   497,   120,   121,   498,     0,
       0,     0,     0,     0,     0,     0,   499,   500,   128,     0,
       0,     0,   129,   733,   130,   501,     0,     0,     0,   734,
       0,   135,     0,   136,   137,   138,   139,   502,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     403,   151,   152,   153,   154,   155,   156,   157,   158,   503,
     532,   504,   162,   505,   506,   165,   166,   167,   168,   169,
     170,   507,   172,   508,   509,   510,   176,   177,   511,   512,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   513,   245,   514,   515,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   400,
     401,     0,    14,    15,    16,   524,    18,    19,    20,   475,
     525,   526,   477,   478,   479,   402,    28,   480,    30,    31,
       0,    32,    33,    34,    35,   527,    37,   528,   529,    40,
      41,    42,    43,   482,     0,    45,   530,    47,   484,   485,
      50,   486,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   487,   488,    68,     0,
      69,    70,    71,   531,     0,    74,    75,    76,     0,     0,
     490,    78,     0,     0,     0,     0,    80,   491,    82,   492,
     493,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     494,    97,    98,   495,   496,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,   107,     0,     0,
       0,     0,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   497,   120,   121,   498,     0,     0,
       0,     0,     0,     0,     0,   499,   500,   128,     0,     0,
       0,   129,   780,   130,   501,     0,     0,     0,   781,     0,
     135,     0,   136,   137,   138,   139,   502,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,     0,     0,   403,
     151,   152,   153,   154,   155,   156,   157,   158,   503,   532,
     504,   162,   505,   506,   165,   166,   167,   168,   169,   170,
     507,   172,   508,   509,   510,   176,   177,   511,   512,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   513,   245,   514,   515,     7,
       8,     0,     0,     0,     0,     0,     0,     0,   400,   401,
       0,    14,    15,    16,   474,    18,    19,    20,   475,    22,
     476,   477,  1105,   479,   402,    28,   480,    30,    31,     0,
      32,    33,    34,    35,   481,    37,    38,    39,    40,    41,
      42,    43,   482,     0,    45,   483,    47,   484,   485,    50,
     486,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   487,   488,    68,     0,    69,
      70,    71,   489,     0,    74,    75,    76,     0,     0,   490,
      78,     0,     0,     0,     0,    80,   491,    82,   492,   493,
      85,    86,  1443,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   494,
      97,    98,   495,   496,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,  1106,     0,     0,     0,
    1107,     0,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   497,   120,   121,   498,     0,     0,     0,
       0,     0,     0,     0,   499,   500,   128,     0,     0,     0,
     129,     0,   130,   501,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   502,   141,   142,   143,   144,
     145,   146,     0,     0,  1108,   148,     0,     0,   403,   151,
     152,   153,   154,   155,   156,   157,   158,   503,   160,   504,
     162,   505,   506,   165,   166,   167,   168,   169,   170,   507,
     172,   508,   509,   510,   176,   177,   511,   512,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,  1109,  1110,  1111,  1112,  1113,     7,     8,
       0,     0,     0,     0,     0,     0,     0,   400,   401,     0,
      14,    15,    16,   474,    18,    19,    20,   475,    22,   476,
     477,  1105,   479,   402,    28,   480,    30,    31,     0,    32,
      33,    34,    35,   481,    37,    38,    39,    40,    41,    42,
      43,   482,     0,    45,   483,    47,   484,   485,    50,   486,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   487,   488,    68,     0,    69,    70,
      71,   489,     0,    74,    75,    76,     0,     0,   490,    78,
       0,     0,     0,     0,    80,   491,    82,   492,   493,    85,
      86,  1578,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   494,    97,
      98,   495,   496,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,  1106,     0,     0,     0,  1107,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   497,   120,   121,   498,     0,     0,     0,     0,
       0,     0,     0,   499,   500,   128,     0,     0,     0,   129,
       0,   130,   501,     0,     0,     0,     0,     0,   135,     0,
     136,   137,   138,   139,   502,   141,   142,   143,   144,   145,
     146,     0,     0,  1108,   148,     0,     0,   403,   151,   152,
     153,   154,   155,   156,   157,   158,   503,   160,   504,   162,
     505,   506,   165,   166,   167,   168,   169,   170,   507,   172,
     508,   509,   510,   176,   177,   511,   512,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,  1109,  1110,  1111,  1112,  1113,     7,     8,     0,
       0,     0,     0,     0,     0,     0,   400,   401,     0,    14,
      15,    16,   474,    18,    19,    20,   475,    22,   476,   477,
    1105,   479,   402,    28,   480,    30,    31,     0,    32,    33,
      34,    35,   481,    37,    38,    39,    40,    41,    42,    43,
     482,     0,    45,   483,    47,   484,   485,    50,   486,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   487,   488,    68,     0,    69,    70,    71,
     489,     0,    74,    75,    76,     0,     0,   490,    78,     0,
       0,     0,     0,    80,   491,    82,   492,   493,    85,    86,
    1582,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   494,    97,    98,
     495,   496,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,  1106,     0,     0,     0,  1107,     0,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   497,   120,   121,   498,     0,     0,     0,     0,     0,
       0,     0,   499,   500,   128,     0,     0,     0,   129,     0,
     130,   501,     0,     0,     0,     0,     0,   135,     0,   136,
     137,   138,   139,   502,   141,   142,   143,   144,   145,   146,
       0,     0,  1108,   148,     0,     0,   403,   151,   152,   153,
     154,   155,   156,   157,   158,   503,   160,   504,   162,   505,
     506,   165,   166,   167,   168,   169,   170,   507,   172,   508,
     509,   510,   176,   177,   511,   512,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,  1109,  1110,  1111,  1112,  1113,     7,     8,     0,     0,
       0,     0,     0,     0,     0,   400,   401,     0,    14,    15,
      16,   474,    18,    19,    20,   475,    22,   476,   477,  1105,
     479,   402,    28,   480,    30,    31,     0,    32,    33,    34,
      35,   481,    37,    38,    39,    40,    41,    42,    43,   482,
       0,    45,   483,    47,   484,   485,    50,   486,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   487,   488,    68,     0,    69,    70,    71,   489,
       0,    74,    75,    76,     0,     0,   490,    78,     0,     0,
       0,     0,    80,   491,    82,   492,   493,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   494,    97,    98,   495,
     496,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,  1106,     0,     0,     0,  1107,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     497,   120,   121,   498,     0,     0,     0,     0,     0,     0,
       0,   499,   500,   128,     0,     0,     0,   129,     0,   130,
     501,     0,     0,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   502,   141,   142,   143,   144,   145,   146,     0,
       0,  1108,   148,     0,     0,   403,   151,   152,   153,   154,
     155,   156,   157,   158,   503,   160,   504,   162,   505,   506,
     165,   166,   167,   168,   169,   170,   507,   172,   508,   509,
     510,   176,   177,   511,   512,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
    1109,  1110,  1111,  1112,  1113,     7,     8,     0,     0,     0,
       0,     0,     0,     0,   400,   401,     0,    14,    15,    16,
     474,    18,    19,    20,   475,    22,   476,   477,  1105,   479,
     402,    28,   480,    30,    31,     0,    32,    33,    34,    35,
     481,    37,    38,    39,    40,    41,    42,    43,   482,     0,
      45,   483,    47,   484,   485,    50,   486,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   487,   488,    68,     0,    69,    70,    71,   489,     0,
      74,    75,    76,     0,     0,   490,    78,     0,     0,     0,
       0,    80,   491,    82,   492,   493,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   494,    97,    98,   495,   496,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,  1106,     0,     0,     0,  1107,     0,     0,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   497,
     120,   121,   498,     0,     0,     0,     0,     0,     0,     0,
     499,   500,   128,     0,     0,     0,   129,     0,   130,   501,
       0,     0,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   502,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,     0,     0,   403,   151,   152,   153,   154,   155,
     156,   157,   158,   503,   160,   504,   162,   505,   506,   165,
     166,   167,   168,   169,   170,   507,   172,   508,   509,   510,
     176,   177,   511,   512,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,  1109,
    1110,  1111,  1112,  1113,     7,     8,     0,     0,     0,     0,
       0,     0,     0,   400,   401,     0,    14,    15,    16,   524,
      18,    19,    20,   475,   525,   526,   477,   478,   479,   402,
      28,   480,    30,    31,     0,    32,    33,    34,    35,   527,
      37,   528,   529,    40,    41,    42,    43,   482,     0,    45,
     530,    47,   484,   485,    50,   486,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     487,   488,    68,     0,    69,    70,    71,   531,     0,    74,
      75,    76,     0,     0,   490,    78,     0,     0,     0,     0,
      80,   491,    82,   492,   493,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   494,    97,    98,   495,   496,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   497,   120,
     121,   498,     0,     0,     0,     0,     0,     0,     0,   499,
     500,   128,     0,     0,     0,   129,     0,   130,   501,     0,
       0,     0,     0,     0,   135,     0,   136,   137,   138,   139,
     502,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,     0,     0,   403,   151,   152,   153,   154,   155,   156,
     157,   158,   503,   532,   504,   162,   505,   506,   165,   166,
     167,   168,   169,   170,   507,   172,   508,   509,   510,   176,
     177,   511,   512,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   513,
     245,   514,   515,     7,     8,     0,     0,     0,     0,     0,
       0,     0,   400,   401,     0,    14,    15,    16,     0,    18,
      19,    20,   475,     0,     0,   477,   478,     0,   402,    28,
     480,    30,    31,     0,    32,    33,    34,    35,     0,    37,
       0,     0,    40,    41,    42,    43,   482,     0,    45,     0,
      47,     0,     0,    50,   486,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   487,
     488,    68,     0,    69,    70,    71,     0,     0,    74,    75,
      76,     0,     0,   490,    78,     0,     0,     0,     0,    80,
     491,    82,   492,   493,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   494,    97,    98,   495,   496,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
       0,     0,     0,     0,     0,     0,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   497,   120,   121,
     498,     0,     0,     0,     0,     0,     0,     0,   499,   500,
     128,     0,     0,     0,   129,     0,   130,   501,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   502,
     141,   142,   143,   144,   145,   146,     0,     0,     0,   148,
       0,     0,   403,   151,   152,   153,   154,   155,   156,   157,
     158,   503,     0,   504,   162,   505,   506,   165,   166,   167,
     168,   169,   170,   507,   172,   508,   509,   510,   176,   177,
       0,   512,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   513,   245,
     514,   515
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,     4,     5,     6,     4,     5,     6,   409,   410,   179,
      12,   885,   800,     0,   757,   333,   286,     4,     5,     6,
     649,   109,   110,   872,   306,   740,   769,   411,   133,     4,
       5,     6,   650,   651,   652,   653,   601,   602,   255,    73,
     783,  1014,   254,  1248,   998,   599,   600,   601,   602,  1182,
     827,  1039,   740,   270,  1264,    73,  1321,  1322,    26,    27,
      36,   423,   905,  1091,   921,   449,   450,   599,   600,    87,
      26,    27,   434,  1277,    37,    38,    30,    40,    41,    47,
      29,   694,   117,  1354,   277,    55,     4,     5,     6,  1543,
       1,    47,    36,   111,    57,   457,     1,     1,    29,     1,
      56,   975,     8,   117,    29,   123,    74,   125,   108,     1,
     884,   885,     1,    45,   988,     1,   141,    96,    74,    93,
      96,   108,   106,    79,   106,   106,   117,    26,    27,   106,
      62,   155,   117,   108,   146,    45,   406,    47,    37,    38,
      99,    40,    41,   111,    45,   106,    47,   921,    47,   112,
      94,   106,    96,   106,   110,   111,   112,    56,    57,   168,
     109,   629,   105,   631,   632,    52,   634,   155,   636,    79,
     146,   157,    94,   106,   123,    74,   644,   645,    26,    27,
      79,   955,   261,   126,   927,   215,   146,   112,    42,   175,
     108,   200,    46,   272,   185,   105,   159,    51,   286,   148,
     185,   975,   146,   152,   105,   186,   155,   189,   182,   223,
     187,   110,   111,   112,   988,    69,    94,     5,    94,  1484,
      99,     9,   252,   266,   146,   186,   185,   176,   159,  1683,
     273,   336,   187,   186,   159,     5,   271,   430,   981,     9,
     106,   128,  1091,  1092,   987,   215,   271,  1035,   248,   233,
    1107,   251,  1457,   186,   186,   218,  1460,   167,   212,   271,
     159,   248,  1395,   111,   251,   980,   167,    76,   174,   539,
     552,  1542,  1245,   838,   839,   254,   255,  1231,   189,    99,
    1268,   267,   252,   106,   189,   189,   286,   189,   274,  1277,
     978,   305,   980,   106,   907,   271,   259,   189,   284,   286,
     189,  1144,  1330,   189,   836,   837,   185,   341,   257,    94,
     344,   271,  1000,   167,   129,   106,   170,   285,   406,   218,
     186,   705,   106,   341,   106,   293,   344,   271,   603,   285,
     159,   185,   607,  1107,   122,   106,   124,   293,   216,   217,
     216,   217,   106,   152,   132,   301,   106,   617,   106,  1223,
     106,   439,   122,   231,   124,   231,   210,   106,    29,   447,
     259,   146,   132,   186,   152,   185,   106,   117,   456,   152,
     183,   755,  1637,  1247,    96,   463,   464,   106,   106,   596,
     195,   106,   152,   106,   472,   106,   285,   599,   600,   751,
     152,  1601,   754,   176,   293,   186,   106,   415,   416,   183,
     868,   419,   301,   106,   186,   423,   406,   106,   426,   427,
     219,   220,  1545,  1187,   106,   186,   434,   155,   106,   406,
     184,  1686,   440,   106,   146,   443,   186,   106,   186,   106,
     186,   106,   117,   451,   183,   435,   186,   437,   109,   457,
     458,   459,   460,  1186,     9,    10,   186,   465,   435,  1223,
     437,   539,   123,   155,   724,   473,   106,   186,   186,   184,
     435,   461,   437,   186,   106,   186,   466,  1672,   556,   106,
     872,   135,  1460,  1247,   461,   130,   186,   148,   121,   466,
     568,  1330,  1197,   186,   106,   155,   461,   186,  1362,   106,
    1339,   466,   106,   106,   186,   183,   584,   585,   900,   587,
     588,  1350,   520,   186,   183,    54,   183,    56,   183,  1642,
      33,   157,  1077,  1078,  1079,   147,   534,   435,  1206,   437,
     129,    96,    96,  1077,  1078,  1079,    49,  1304,   546,   175,
    1307,   261,   164,   183,   189,   199,   117,   102,    96,   539,
      29,   183,   272,   461,   928,   929,   183,   547,   466,   933,
      99,  1684,   539,   152,   112,   825,    94,   122,   143,   124,
     547,   183,   580,   668,   669,    96,   183,    96,    66,   183,
     183,  1445,   547,    71,  1448,    94,   116,   665,   147,   963,
     155,   117,   670,   112,   918,   585,   195,   152,  1362,   152,
     175,   156,   594,    96,   168,   164,   930,   155,   585,   599,
     600,   601,   602,   141,   223,   145,   225,   192,   173,   208,
     585,  1565,   599,   600,   601,   602,   155,   617,   158,   117,
     109,  1754,   141,  1756,   836,   842,   155,  1600,   193,   547,
     617,    42,  1765,    39,   123,    46,   724,   168,    44,    45,
      51,   152,     9,   146,   165,   208,   211,    95,   155,     9,
      10,    94,   192,    59,   155,    61,    62,   105,    69,   148,
     181,    28,  1511,   152,    70,   176,   155,   115,    33,     9,
    1458,  1445,  1664,  1665,  1448,  1463,   250,   251,   126,   253,
     698,   157,    24,   701,    49,   199,   260,   176,    28,  1091,
    1092,    97,    34,   136,   208,  1410,   270,   715,   141,   175,
     249,   719,   720,   791,   792,   793,    53,   795,   282,   136,
    1702,    58,  1341,   262,   141,   264,  1708,   135,    60,   250,
     251,   197,   253,   741,   724,   743,   275,   276,   277,   155,
     279,   149,   281,   751,   136,   121,   754,   724,   136,   270,
     758,   223,   102,   225,   747,  1310,  1620,   747,  1622,    96,
     152,   282,    96,   121,   152,   122,   167,   124,    94,   170,
     747,    42,   122,   121,   124,    46,   133,   181,   112,   105,
      51,    53,   747,   181,   185,  1093,    58,   777,   778,  1653,
     194,   799,   122,  1065,   124,   152,   194,   157,    69,  1059,
     777,   778,   152,   133,   267,    77,   156,     9,    10,   210,
    1588,   274,   777,   778,  1592,   175,  1680,     9,    10,   827,
     121,   284,   152,   173,    96,    99,   121,   223,   969,    99,
     971,  1695,   153,  1697,   155,   825,    99,   197,   112,   747,
     245,   246,   112,   193,    99,   117,    99,   855,   825,   112,
     152,   152,  1226,    99,   155,   847,  1620,   112,  1622,   112,
     223,   211,   297,   268,   121,   228,   112,   136,    53,   777,
     778,   306,   141,    58,   190,   191,   884,   885,   886,   887,
    1021,   343,  1023,  1502,  1503,   152,   348,  1495,   155,  1653,
    1668,   275,   276,   277,   121,   671,   167,   281,   674,   170,
     102,   677,   152,  1063,  1637,   155,   127,   128,  1068,   152,
     102,   121,   155,   921,   185,   152,  1680,   230,   155,   232,
     122,   121,   124,   219,   220,   221,   230,   935,   232,   152,
     122,  1695,   124,  1697,   127,   128,  1533,  1534,  1330,   210,
     647,   648,   121,  1317,   654,   655,   121,  1339,   656,   657,
     152,   155,   960,   214,   156,   886,   887,   223,  1350,   117,
     152,   969,   239,   971,   156,  1225,   239,   975,   155,   152,
     152,   173,   240,     0,   152,   131,   152,   106,   189,    92,
     988,   173,   166,   139,   140,   247,   142,    50,   100,  1608,
    1609,   193,    73,   198,   150,   101,   153,   144,   154,    29,
     156,   193,   155,   183,    47,   161,    87,   151,   117,   211,
     183,   183,  1090,  1021,   244,  1023,   302,   186,   282,   211,
     117,   152,   178,   282,     1,   117,  1016,   141,   106,   152,
     111,   186,   152,   155,   155,   183,   155,   155,   155,  1016,
     141,   120,   123,  1303,   125,   201,   202,   203,   204,   205,
     206,  1016,   155,  1427,   152,   155,   155,  1676,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    35,  1059,
      17,   212,    29,   189,   189,   186,   243,   229,  1086,     3,
     117,   167,  1059,    70,  1076,   169,   169,  1077,  1078,  1079,
     229,    94,    94,    94,   148,   106,   106,    29,   159,  1107,
    1077,  1078,  1079,   159,   244,   126,   131,   297,  1016,    94,
     141,   117,   131,   183,  1488,   183,   106,   186,    94,  1511,
     186,    96,    45,    96,   186,    94,   186,   186,   186,   152,
     183,   183,   223,   235,   141,    33,   120,   169,   189,   117,
     131,   141,    94,    29,    94,   225,   284,   297,   152,   117,
     146,   117,   126,   117,    94,   183,   252,   196,    96,   131,
     159,   131,   117,   152,   146,    99,    99,   183,   183,   152,
     141,   189,    35,    29,   117,   155,   155,    79,   243,  1439,
     106,   106,   256,   258,    29,   143,    29,    29,  1196,   152,
     155,  1199,   265,   283,   155,   155,   155,  1190,   285,   155,
    1190,   155,   155,   189,   155,   225,  1214,   155,   284,   304,
     146,   126,   143,  1190,   117,  1223,   146,   146,   117,    77,
     141,  1299,  1300,  1301,   186,  1190,   106,    99,     7,  1237,
     131,   105,   105,   231,   231,  1225,   231,   186,   231,  1247,
     186,   186,   183,  1236,   186,   280,  1236,   186,  1225,   146,
     284,    78,   196,    29,   189,    29,   183,   185,   106,  1236,
     341,   269,  1255,   344,   186,  1255,   186,  1275,   146,   186,
     186,  1236,   186,   186,   186,   186,   186,   169,  1255,   183,
     146,   125,  1190,    96,  1274,   125,   278,  1295,   183,   185,
    1255,   185,   185,   183,   185,   183,  1304,  1274,   235,  1307,
     183,   152,    94,  1563,   186,    29,    96,   186,   169,  1274,
     146,    53,  1302,  1303,  1574,  1575,    94,  1577,   185,   195,
     185,   196,    94,    29,  1584,  1302,  1303,    94,  1236,   248,
     248,   106,   117,   106,   223,   416,   117,  1302,   419,   185,
      94,   195,   423,   195,   185,   426,   427,  1255,   255,   117,
     185,   182,   223,   434,  1362,   263,    93,   195,   108,   440,
     117,   117,   443,   185,   185,   185,  1274,   197,   223,   117,
     451,   704,   922,   430,   410,   989,   457,   458,   459,   460,
     285,   251,   251,  1391,   465,  1147,   248,  1187,  1642,  1684,
     254,   291,   473,   986,   303,  1196,   828,   303,   760,  1420,
    1215,  1661,  1326,  1082,   285,  1324,   534,  1321,  1237,  1417,
    1418,  1671,  1242,  1245,  1250,   627,   303,  1268,   800,   304,
     304,   628,  1708,   679,  1702,  1181,   887,   304,   971,   438,
    1146,  1295,  1305,   438,  1304,  1443,  1696,  1445,  1511,   520,
    1448,  1339,  1092,  1350,  1343,  1508,  1101,   954,  1169,  1439,
    1386,  1459,  1536,   534,  1340,   588,  1464,    -1,   789,    -1,
      -1,   329,  1439,    -1,    -1,   546,    -1,  1727,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1748,    -1,
      -1,    -1,    -1,  1753,    -1,    -1,    -1,    -1,    -1,   580,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1602,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1618,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1578,    -1,  1580,  1563,  1582,    -1,    -1,    -1,    -1,    -1,
      -1,  1589,    -1,    -1,  1574,  1575,  1563,  1577,    -1,    -1,
      -1,    -1,    -1,    -1,  1584,    -1,    -1,  1574,  1575,    -1,
    1577,    -1,    -1,    -1,    -1,    -1,    -1,  1584,    -1,    -1,
      -1,    -1,  1620,    -1,  1622,    -1,    -1,    -1,    -1,    -1,
     701,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1638,    -1,    -1,  1641,   715,    -1,    -1,    -1,   719,   720,
      -1,    -1,    -1,    -1,    -1,  1653,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1663,    -1,    -1,    -1,    -1,
     741,    -1,   743,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     751,  1661,  1680,   754,    -1,    -1,    -1,   758,    -1,    -1,
    1688,  1671,    -1,    -1,  1661,  1693,    -1,  1695,    -1,  1697,
      -1,    -1,    -1,    -1,  1671,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1696,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1724,    -1,   799,  1696,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1740,    -1,    -1,    -1,  1744,  1727,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   827,    -1,    -1,    -1,
    1727,    -1,  1760,    -1,    -1,  1763,    -1,    -1,  1748,    -1,
      -1,    -1,    -1,  1753,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1748,    -1,    -1,   855,    -1,  1753,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   547,    -1,    -1,
      -1,    -1,    -1,   884,   885,   886,   887,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   572,   573,    -1,   575,   576,   577,   578,    -1,
      -1,    -1,    -1,   583,    -1,    -1,    -1,    -1,   588,   589,
     921,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   935,    -1,    -1,    -1,    -1,   609,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   617,   618,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   960,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   969,    -1,
     971,    -1,    -1,    -1,   975,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   988,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   676,    -1,    -1,   679,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1021,    -1,  1023,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   717,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1086,    -1,    -1,    -1,   759,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   784,    -1,    -1,    -1,   788,   789,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   797,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   857,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1196,    -1,    -1,  1199,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1214,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1247,    -1,    -1,    -1,
      -1,    -1,    -1,   923,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1275,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   958,    -1,
      -1,    -1,    -1,    -1,  1295,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1304,    -1,    -1,  1307,   977,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   999,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1010,  1011,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1025,    -1,    -1,  1028,    -1,
      -1,  1362,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1045,  1046,  1047,    -1,  1049,
    1050,  1051,  1052,  1053,  1054,    -1,  1056,  1057,    -1,    -1,
    1391,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1073,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1082,    -1,    -1,    -1,  1417,  1418,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1443,    -1,  1445,    -1,    -1,  1448,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1459,    -1,
      -1,    -1,    -1,  1464,  1134,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1201,    -1,  1203,    -1,  1205,    -1,    -1,  1208,    -1,
      -1,    -1,    -1,  1213,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1225,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1234,    -1,    -1,    -1,    -1,    -1,
    1240,  1241,    -1,    -1,    -1,    -1,    -1,  1578,    -1,  1580,
      -1,  1582,    -1,    -1,    -1,    -1,    -1,    -1,  1589,  1259,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1620,
      -1,  1622,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1638,    -1,    -1,
    1641,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1653,    -1,  1324,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1663,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1680,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1688,    -1,    -1,
      -1,    -1,  1693,    -1,  1695,    -1,  1697,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1724,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1404,    -1,    -1,    -1,  1408,  1740,
      -1,    -1,  1412,  1744,  1414,    -1,  1416,    -1,    -1,    -1,
      -1,    -1,  1422,    -1,    -1,    -1,    -1,    -1,    -1,  1760,
    1430,    -1,  1763,    -1,    -1,    -1,    -1,    -1,  1438,  1439,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1456,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1467,  1468,  1469,
    1470,  1471,    -1,  1473,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1551,    -1,  1553,    -1,    -1,  1556,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1564,    -1,    -1,    -1,    -1,  1569,
    1570,    -1,    -1,    -1,    -1,    -1,    -1,  1577,    -1,    -1,
      -1,  1581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1645,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1657,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1696,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1722,    -1,    -1,    -1,    -1,  1727,    -1,    -1,
      11,    12,  1732,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,  1747,    29,    -1,
      -1,  1751,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,    -1,   123,    -1,   125,   126,   127,   128,    -1,   130,
      -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,   155,   156,   157,   158,   159,    -1,
      -1,    -1,    -1,   164,   165,   166,   167,   168,   169,   170,
     171,    -1,   173,    -1,   175,   176,    -1,    -1,   179,   180,
     181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,   190,
     191,   192,    -1,   194,    -1,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,    -1,    -1,   209,   210,
     211,    -1,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,   257,   258,   259,    -1,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,   123,    -1,   125,   126,   127,
     128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
     148,   149,   150,   151,   152,   153,    -1,   155,   156,   157,
     158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,    -1,   175,   176,    -1,
      -1,   179,   180,   181,    -1,   183,    -1,   185,    -1,   187,
     188,    -1,   190,   191,   192,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,   209,   210,   211,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,   123,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,   157,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,   173,    -1,   175,
     176,    -1,    -1,   179,   180,   181,    -1,   183,    -1,   185,
      -1,   187,   188,    -1,   190,   191,   192,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,   209,   210,   211,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,   257,   258,   259,    -1,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,   123,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,   148,   149,   150,   151,   152,   153,
      -1,   155,   156,   157,   158,   159,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,   173,
      -1,   175,   176,    -1,    -1,   179,   180,   181,    -1,   183,
      -1,   185,    -1,   187,   188,    -1,   190,   191,   192,    -1,
     194,    -1,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,    -1,   209,   210,   211,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,   257,   258,   259,    -1,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,   123,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,   155,   156,   157,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,    -1,   175,   176,    -1,    -1,   179,   180,   181,
      -1,   183,    -1,   185,    -1,   187,   188,    -1,   190,   191,
     192,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,   123,    -1,   125,   126,   127,   128,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,   155,   156,   157,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,    -1,   175,   176,    -1,    -1,   179,
     180,   181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,
     190,   191,   192,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,   209,
     210,   211,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,   123,    -1,   125,   126,   127,
     128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
     148,   149,   150,   151,   152,   153,    -1,   155,   156,   157,
     158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,    -1,   175,   176,    -1,
      -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,   187,
     188,    -1,   190,   191,   192,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,   209,   210,   211,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,   123,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,   157,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,   173,    -1,   175,
     176,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,
      -1,   187,   188,    -1,   190,   191,   192,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,   209,   210,   211,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,   257,   258,   259,    -1,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,   123,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,   148,   149,   150,   151,   152,   153,
      -1,   155,   156,   157,   158,   159,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,   173,
      -1,   175,   176,    -1,    -1,   179,   180,   181,    -1,    -1,
      -1,   185,    -1,   187,   188,    -1,   190,   191,   192,    -1,
     194,    -1,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,    -1,   209,   210,   211,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,   257,   258,   259,    -1,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,   123,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,   155,   156,   157,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,    -1,   175,   176,    -1,    -1,   179,   180,   181,
      -1,    -1,    -1,   185,    -1,   187,   188,    -1,   190,   191,
     192,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,   123,    -1,   125,   126,   127,   128,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,   155,   156,   157,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,    -1,   175,   176,    -1,    -1,   179,
     180,   181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,
     190,   191,   192,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,   209,
     210,   211,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,   123,    -1,   125,   126,   127,
     128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
     148,   149,   150,   151,   152,   153,    -1,   155,   156,   157,
     158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,    -1,   175,   176,    -1,
      -1,   179,   180,   181,    -1,    -1,   184,   185,    -1,   187,
     188,    -1,   190,   191,   192,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,   209,   210,   211,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,   123,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,   157,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,   173,    -1,   175,
     176,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,
     186,   187,   188,    -1,   190,   191,   192,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,   209,   210,   211,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,   257,   258,   259,    -1,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,   123,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,   148,   149,   150,   151,   152,   153,
      -1,   155,   156,   157,   158,   159,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,   173,
      -1,   175,   176,    -1,    -1,   179,   180,   181,    -1,   183,
      -1,   185,    -1,   187,   188,    -1,   190,   191,   192,    -1,
     194,    -1,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,    -1,   209,   210,   211,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,   257,   258,   259,    -1,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,   123,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,   155,   156,   157,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,    -1,   175,   176,    -1,    -1,   179,   180,   181,
      -1,   183,    -1,   185,    -1,   187,   188,    -1,   190,   191,
     192,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,   123,    -1,   125,   126,   127,   128,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,   155,   156,   157,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,    -1,   175,   176,    -1,    -1,   179,
     180,   181,    -1,   183,    -1,   185,    -1,   187,   188,    -1,
     190,   191,   192,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,   209,
     210,   211,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,   123,    -1,   125,   126,   127,
     128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
     148,   149,   150,   151,   152,   153,    -1,   155,   156,   157,
     158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,    -1,   175,   176,    -1,
      -1,   179,   180,   181,    -1,    -1,    -1,   185,   186,   187,
     188,    -1,   190,   191,   192,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,   209,   210,   211,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,   123,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,   157,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,   173,    -1,   175,
     176,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,
     186,   187,   188,    -1,   190,   191,   192,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,   209,   210,   211,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,   257,   258,   259,    -1,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,   123,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,   148,   149,   150,   151,   152,   153,
      -1,   155,   156,   157,   158,   159,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,   173,
      -1,   175,   176,    -1,    -1,   179,   180,   181,    -1,    -1,
      -1,   185,    -1,   187,   188,    -1,   190,   191,   192,    -1,
     194,    -1,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,    -1,   209,   210,   211,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,   257,   258,   259,    -1,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,   123,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,   155,   156,   157,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,    -1,   175,   176,    -1,    -1,   179,   180,   181,
      -1,    -1,    -1,   185,    -1,   187,   188,    -1,   190,   191,
     192,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,   123,    -1,   125,   126,   127,   128,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,   155,   156,   157,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,    -1,   175,   176,    -1,    -1,   179,
     180,   181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,
     190,   191,   192,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,   209,
     210,   211,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,   123,    -1,   125,   126,   127,
     128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
     148,   149,   150,   151,   152,   153,    -1,   155,   156,    -1,
     158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,    -1,    -1,    -1,    -1,
      -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,   187,
     188,    -1,   190,   191,   192,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,   209,   210,   211,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,   123,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,    -1,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,   173,    -1,    -1,
      -1,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,
      -1,   187,   188,    -1,    -1,    -1,   192,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,   209,   210,   211,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,   257,   258,   259,    -1,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,   123,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,    -1,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,   148,    -1,   150,   151,   152,   153,
      -1,   155,   156,    -1,   158,   159,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,   173,
      -1,    -1,    -1,    -1,    -1,   179,   180,   181,    -1,    -1,
      -1,   185,    -1,   187,   188,    -1,    -1,    -1,   192,    -1,
     194,    -1,   196,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,    -1,    -1,   209,   210,   211,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,   257,   258,   259,    -1,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    -1,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,    -1,   149,   150,   151,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
      -1,    -1,    -1,   185,    -1,   187,   188,    -1,    -1,    -1,
     192,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,    -1,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    -1,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,   147,    -1,   149,
     150,   151,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,
     180,   181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,
      -1,    -1,   192,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,   209,
     210,    -1,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    -1,    99,   100,   101,    -1,
      -1,   104,   105,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,
      -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,
      -1,    -1,   145,   146,   147,    -1,   149,   150,   151,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   159,    -1,    -1,    -1,
      -1,   164,   165,   166,   167,   168,   169,   170,   171,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,    -1,
      -1,    -1,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,    -1,    -1,   209,   210,    -1,    -1,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,   257,   258,   259,    -1,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    -1,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,    -1,   149,   150,   151,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,
      -1,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,   209,   210,    -1,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,   257,   258,   259,    -1,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,    18,    19,    -1,
      -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    -1,    99,   100,
     101,    -1,    -1,   104,   105,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,   130,
      -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   146,   147,    -1,   149,   150,
     151,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,    -1,
      -1,    -1,    -1,   164,   165,   166,   167,   168,   169,   170,
     171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,
     181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,    -1,    -1,   209,   210,
      -1,    -1,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,   257,   258,   259,    -1,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    -1,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,    -1,   149,   150,   151,
      -1,    -1,    -1,   155,    -1,    -1,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
      -1,    -1,    -1,   185,   186,   187,   188,    -1,    -1,    -1,
     192,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,    -1,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    -1,    99,   100,   101,    -1,
      -1,   104,   105,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,
      -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,
      -1,    -1,   145,   146,   147,    -1,   149,   150,   151,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   159,    -1,    -1,    -1,
      -1,   164,   165,   166,   167,   168,   169,   170,   171,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,    -1,
      -1,    -1,   185,   186,   187,   188,    -1,    -1,    -1,   192,
      -1,   194,    -1,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,    -1,    -1,   209,   210,    -1,    -1,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,   257,   258,   259,    -1,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    -1,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,    -1,   149,   150,   151,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   179,   180,   181,    -1,    -1,
      -1,   185,   186,   187,   188,    -1,    -1,    -1,   192,    -1,
     194,    -1,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,    -1,   209,   210,    -1,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,   257,   258,   259,    -1,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    -1,    99,   100,   101,    -1,    -1,   104,
     105,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,
     135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   146,   147,    -1,   149,   150,   151,    -1,    -1,    -1,
     155,    -1,    -1,   158,   159,    -1,    -1,    -1,    -1,   164,
     165,   166,   167,   168,   169,   170,   171,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,
     185,    -1,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,    -1,    -1,   209,   210,    -1,    -1,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    -1,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,    -1,   149,   150,   151,    -1,    -1,    -1,   155,
      -1,    -1,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,
      -1,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,   209,   210,    -1,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,   257,   258,   259,    -1,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    -1,    99,   100,   101,    -1,    -1,   104,   105,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,
     127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,
     137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,    -1,   149,   150,   151,    -1,    -1,    -1,   155,    -1,
      -1,   158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,
     167,   168,   169,   170,   171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
      -1,    -1,   209,   210,    -1,    -1,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
     257,   258,   259,    -1,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      -1,    99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,
     128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
      -1,   149,   150,   151,    -1,    -1,    -1,   155,    -1,    -1,
     158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,   209,   210,    -1,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    -1,
      99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,
      -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,   138,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,    -1,
     149,   150,   151,    -1,    -1,    -1,   155,    -1,    -1,   158,
     159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     179,   180,   181,    -1,    -1,    -1,   185,    -1,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,    -1,    -1,
     209,   210,    -1,    -1,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,    -1,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    -1,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,   147,    -1,   149,
     150,   151,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,
     180,   181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,   209,
     210,    -1,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    -1,    40,
      41,    42,    43,    -1,    -1,    46,    47,    -1,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    -1,    60,
      -1,    -1,    63,    64,    65,    66,    67,    -1,    69,    -1,
      71,    -1,    -1,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    -1,    -1,    99,   100,
     101,    -1,    -1,   104,   105,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,   130,
      -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   146,   147,    -1,   149,   150,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,    -1,
      -1,    -1,    -1,   164,   165,   166,   167,   168,   169,   170,
     171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,
     181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,    -1,    -1,    -1,   210,
      -1,    -1,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    -1,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
      -1,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,   257,   258,   259,    -1,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312
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
      95,    96,    97,    98,    99,   100,   101,   104,   105,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     123,   125,   126,   127,   128,   130,   134,   135,   136,   137,
     138,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     155,   156,   157,   158,   159,   164,   165,   166,   167,   168,
     169,   170,   171,   173,   175,   176,   179,   180,   181,   185,
     187,   188,   190,   191,   192,   194,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   209,   210,   211,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   257,   258,   259,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   328,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   349,   350,   351,
     352,   353,   354,   358,   359,   360,   364,   366,   367,   369,
     376,   378,   381,   382,   383,   385,   386,   387,   388,   389,
     391,   392,   394,   395,   396,   397,   398,   399,   401,   402,
     405,   406,   407,   408,   413,   415,   417,   418,   423,   442,
     445,   449,   452,   453,   458,   459,   460,   461,   463,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   499,
     500,   501,   502,   503,   504,   505,   506,   507,   509,   510,
     511,   525,   526,   528,   529,   530,   531,   532,   533,   534,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     554,   555,   556,   557,   562,   563,   564,   565,   566,   567,
     570,   628,   629,   630,   631,   632,   633,   643,   644,   645,
      33,    34,    49,   213,   384,   385,   386,   384,   384,   155,
     155,    37,    38,    40,    41,    47,    56,    57,    74,    79,
     110,   111,   112,   159,   218,   259,   285,   293,   301,   365,
     366,   370,   371,   372,   159,   152,   155,   152,   155,   152,
     155,    66,    71,   117,   410,   155,   373,   155,    24,    34,
      60,   117,   271,   422,   424,   425,   152,   155,   155,   155,
     117,   152,   155,   155,   155,    76,   152,   219,   220,   121,
     121,   121,   152,   155,    39,    43,    45,    46,    47,    48,
      51,    59,    67,    70,    72,    73,    75,    90,    91,    97,
     104,   111,   113,   114,   134,   137,   138,   168,   171,   179,
     180,   188,   200,   222,   224,   226,   227,   234,   236,   237,
     238,   241,   242,   309,   311,   312,   493,   643,   644,   121,
     117,   393,   121,   121,    39,    44,    45,    59,    61,    62,
      70,    97,   223,   643,   117,   121,   121,   183,   384,   386,
     406,   634,   635,    48,    72,    73,   117,   152,   184,   242,
     405,   407,   417,   186,   405,   643,   152,   121,    16,   642,
     643,    18,    19,   643,   121,   121,   121,   485,   152,    30,
     212,   214,   223,   225,   155,   223,   225,   223,   223,   228,
     117,   239,   239,   240,   155,   152,   388,   152,   152,   152,
     330,     0,   332,   333,    33,    49,   335,   352,     1,   189,
     329,   189,   329,   111,   367,   387,   405,   106,   189,   106,
     189,    42,    46,    51,    69,   167,   170,   185,   210,   400,
     409,   414,   415,   416,   430,   431,   435,   166,    92,   131,
     139,   140,   142,   150,   154,   156,   161,   178,   201,   202,
     203,   204,   205,   206,   477,   478,   247,   157,   175,   197,
     116,   145,   158,   192,   199,   208,   135,   149,    50,   198,
     100,   101,   157,   175,   476,   152,   482,   485,   190,   191,
     153,   497,   498,   493,   497,   493,   155,   497,   144,   155,
     183,   183,   183,   368,   500,   368,    29,   641,   181,   194,
     181,   194,   165,   181,   644,   643,   168,   200,    47,   643,
     151,   117,    45,    47,    79,   105,   167,   642,   219,   220,
     221,   244,   601,   643,   643,   302,   136,   141,   111,   285,
     293,   370,   642,   385,   386,   186,   385,    45,    62,   186,
     550,   551,   405,   186,   192,   643,   282,   282,   419,   420,
     643,   117,   426,   117,   186,   374,   375,   152,   390,   405,
       1,   159,   641,   112,   159,   348,   641,   643,   117,   141,
     106,   405,    29,   186,   642,   643,   643,   443,   444,   643,
     385,   186,   405,   405,   552,   643,   385,   152,   152,   405,
     186,   192,   643,   643,   141,   443,   183,   183,   120,   106,
     183,   155,   155,   155,   643,   152,   184,   185,   186,    35,
     513,   514,   515,   405,     8,   174,    17,   405,   212,    29,
     406,   406,   186,   406,   406,   406,   406,   229,   568,   569,
     643,   189,   189,   406,   405,   386,   405,   243,   403,   404,
     183,   405,   183,   405,   634,   406,   189,   329,   189,   329,
       3,   336,   352,   382,   336,   352,   382,    33,   353,   382,
     353,   382,   393,   393,   406,   117,   167,   169,   169,   387,
     406,   406,   460,   461,   463,   463,   463,   463,   462,   463,
     463,   463,    70,   467,   467,   466,   468,   468,   468,   468,
     469,   469,   470,   470,   229,    94,    94,    94,   183,   405,
     485,   485,   405,   498,   186,   406,   508,   148,   186,   508,
     106,   186,   186,   106,   106,   373,    29,   644,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,   355,   356,
     357,    94,   136,   141,   361,   362,   363,   643,   159,   159,
     355,   641,   126,   131,    54,    56,    99,   249,   262,   264,
     275,   276,   277,   279,   281,   602,   603,   604,   605,   606,
     607,   614,   620,   621,   244,    94,   297,   643,   141,   406,
     117,   643,   643,   131,   183,   183,   186,   186,   183,   106,
     186,   106,   186,   106,    36,    94,    96,   146,   421,   422,
     536,   643,    55,   215,   252,   411,   412,   643,    94,   106,
     186,   384,   186,   642,    96,    45,   642,   641,    96,   141,
     536,   643,   406,   425,   183,   186,   186,   186,   186,   106,
     187,   146,   536,   183,   186,   186,   152,   183,   385,   385,
     183,   106,   186,   106,   186,   141,   536,   406,   187,   406,
     406,   635,   405,   405,   405,   643,   514,   515,   129,   195,
     183,   183,   130,   189,    94,   216,   217,   231,    94,   216,
     217,   231,    94,   235,   223,   106,   233,   141,   189,   186,
      48,    72,    73,   242,   407,   417,   183,   494,   574,   404,
     183,   183,   183,   120,   352,    33,    33,   189,   329,   189,
     112,   643,   169,   406,   436,   437,   117,   432,   433,   463,
     152,   155,   257,   481,   500,   575,   578,   579,   580,   581,
     582,   586,   588,   590,   591,    47,   151,   155,   209,   308,
     309,   310,   311,   312,   537,   539,   541,   542,   558,   559,
     560,   561,   636,   637,   638,   639,   640,   643,   537,   535,
     541,   535,   183,   184,   106,   186,   186,   500,   147,   164,
     147,   164,   136,   390,   373,   356,   131,   539,   363,   406,
     536,   641,   641,   127,   128,   641,   275,   276,   277,   281,
     643,   261,   272,   261,   272,    29,   284,    96,   112,   155,
     608,   611,   602,    39,    44,    59,    61,    70,    97,   223,
     377,   542,   225,   297,   306,   406,   643,    94,   297,   641,
     152,   552,   553,   643,   552,   553,   117,   126,   537,   117,
     406,   146,   422,   146,    36,   146,   421,   422,   146,   536,
     252,    53,    58,    77,   117,   421,   427,   428,   429,   412,
     536,   537,   375,    94,   183,   196,   131,   347,   641,   159,
     131,    96,   347,   406,   141,   422,   152,   117,   406,   406,
     146,    99,   446,   447,   448,   450,   451,    99,   454,   455,
     456,   457,   385,   183,   183,   152,   552,   552,   406,   141,
     189,   406,   186,   186,   186,    35,   515,   129,   195,     9,
      10,   102,   122,   124,   152,   193,   510,   512,   523,   524,
     527,    29,   230,   232,   406,   406,   406,   230,   232,   406,
     406,   406,   406,   406,   406,   117,   406,   406,   387,   155,
     155,   155,   152,   185,   243,   571,   572,   208,   388,   406,
     189,   112,   382,   382,   382,   436,    95,   105,   115,   126,
     438,   439,   440,   441,   106,   643,   106,   405,   575,   582,
     152,   283,   464,   627,    96,   168,   250,   251,   253,   260,
     270,   282,   576,   577,   596,   597,   598,   599,   622,   625,
     256,   258,   583,   601,   265,   587,   623,   245,   246,   268,
     592,   593,   155,   155,   539,   155,   155,   155,   155,   155,
     155,   143,   175,   192,   538,   143,   406,   136,   390,   554,
     362,   284,    29,    96,   112,   155,   615,    29,   608,   538,
     483,   285,   304,   536,   377,   225,   189,   384,   186,   186,
     143,   186,   186,   420,   146,   421,   643,   406,   146,   406,
     126,   406,   146,   422,   146,   406,   146,   117,   117,   406,
     643,   429,    77,   537,   387,   406,   641,   106,   347,   406,
     141,   384,   444,   406,   406,   112,   447,   448,    99,   185,
     112,   448,   451,   117,   537,    99,   112,   455,    99,   112,
     457,   183,   384,   186,   186,   406,   196,   454,   131,   193,
     512,     7,   385,   643,   193,   523,   189,   231,   231,   231,
     231,   235,   569,   185,   405,   405,   405,   574,   572,   494,
     183,   641,   127,   128,   440,   441,   441,   437,   105,   434,
     433,   183,   186,   575,   589,   248,   215,   252,   266,   273,
     626,    96,   254,   255,   624,   248,   579,   626,   466,   596,
     580,   146,   280,   584,   585,   624,   284,   595,    78,   594,
     186,   192,   537,   540,   186,   186,   186,   186,   186,   186,
     186,   186,    29,   135,   199,   617,   618,   619,    29,   616,
     617,   269,   612,   106,   609,   169,   643,   255,   483,   183,
     406,   146,   406,   146,   421,   406,   146,   406,   406,   643,
     643,   428,   406,   125,   125,    96,   641,   406,   183,   185,
     185,   406,   387,   406,   185,   185,   643,   185,   117,   537,
     117,   185,   117,   537,   185,   183,   112,   515,   643,   193,
     183,   515,   643,   406,   406,   406,   406,   406,   406,   186,
     186,   186,   152,   573,   441,   641,   183,   468,    52,   128,
     466,   466,   267,   274,   284,   600,   600,   581,   152,   278,
      94,   186,   106,   186,   615,   615,   619,   106,   186,    29,
     613,   624,   610,   611,   186,   379,   380,   483,   117,   223,
     305,   285,   169,   406,   406,   146,   406,    53,   387,   406,
     347,   406,   387,    94,   387,   406,   643,   185,   643,   406,
     643,   185,   387,   117,    93,   182,   516,   515,   643,   195,
     515,   196,   454,   405,   466,   466,   197,   405,   537,   537,
      94,    29,   263,   106,   106,   441,   536,   643,   117,   223,
     643,   379,   406,   117,   537,    94,   185,    94,   643,     5,
     132,   519,   520,   522,   524,    28,   133,   517,   518,   521,
     524,   195,   515,   195,   112,   183,   466,   183,   537,   611,
     380,   441,   303,   643,   117,   223,   643,   185,   537,   387,
     406,   537,   185,    93,   132,   522,   182,   133,   521,   195,
     117,   406,   303,   643,   117,   387,   406,   185,   185,   643,
     291,   303,   643,   185,   304,   406,   304,   483,   483,   197,
     285,   643,   223,   117,   643,   304,   483
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
     575,   576,   577,   578,   579,   580,   581
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   327,   328,   328,   329,   330,   330,   330,   330,   331,
     331,   332,   332,   332,   332,   332,   332,   332,   332,   333,
     333,   333,   333,   334,   335,   335,   335,   336,   336,   336,
     336,   336,   337,   337,   337,   337,   337,   337,   337,   337,
     338,   338,   339,   340,   341,   341,   342,   342,   343,   343,
     344,   344,   344,   344,   345,   345,   345,   346,   346,   346,
     346,   347,   347,   348,   348,   349,   349,   349,   349,   350,
     351,   351,   352,   352,   352,   353,   353,   353,   353,   353,
     353,   353,   353,   354,   354,   355,   355,   356,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   358,   359,
     360,   361,   361,   362,   362,   362,   363,   364,   364,   364,
     365,   365,   365,   365,   366,   366,   367,   367,   367,   367,
     368,   368,   369,   369,   370,   370,   371,   371,   372,   372,
     373,   373,   373,   373,   374,   374,   375,   375,   376,   376,
     376,   376,   377,   377,   378,   378,   379,   379,   380,   380,
     380,   380,   381,   381,   381,   381,   382,   383,   383,   383,
     384,   384,   384,   385,   385,   386,   386,   387,   387,   387,
     387,   387,   387,   387,   387,   387,   387,   387,   387,   388,
     388,   389,   390,   391,   392,   392,   392,   393,   393,   393,
     393,   394,   395,   396,   397,   398,   398,   399,   400,   401,
     402,   403,   403,   404,   405,   405,   406,   406,   406,   406,
     406,   406,   407,   407,   407,   407,   407,   407,   407,   408,
     409,   410,   410,   411,   411,   411,   412,   412,   413,   413,
     414,   415,   415,   415,   416,   416,   416,   416,   416,   417,
     417,   418,   419,   419,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   421,   422,   423,   424,
     424,   425,   425,   425,   425,   426,   426,   427,   427,   427,
     428,   428,   428,   429,   429,   429,   430,   431,   432,   432,
     433,   433,   434,   435,   435,   436,   436,   437,   437,   438,
     438,   438,   438,   438,   438,   438,   439,   439,   440,   440,
     441,   442,   442,   443,   443,   444,   444,   445,   446,   446,
     447,   448,   448,   449,   450,   450,   451,   452,   452,   453,
     453,   454,   454,   455,   455,   456,   456,   457,   457,   458,
     459,   459,   460,   460,   461,   461,   461,   461,   461,   462,
     461,   461,   461,   461,   463,   463,   464,   464,   465,   465,
     466,   466,   466,   467,   467,   467,   467,   467,   468,   468,
     468,   469,   469,   469,   470,   470,   471,   471,   472,   472,
     473,   473,   474,   474,   475,   475,   475,   475,   476,   476,
     476,   477,   477,   477,   477,   477,   477,   478,   478,   478,
     479,   479,   479,   479,   480,   480,   481,   481,   482,   482,
     482,   483,   483,   483,   483,   484,   485,   485,   485,   486,
     486,   487,   487,   487,   487,   488,   488,   489,   489,   489,
     489,   489,   489,   489,   490,   490,   491,   491,   492,   492,
     492,   492,   492,   493,   493,   494,   494,   495,   495,   495,
     495,   496,   496,   496,   496,   497,   497,   498,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   500,
     500,   501,   501,   501,   502,   503,   503,   504,   505,   506,
     507,   507,   508,   508,   509,   509,   510,   510,   510,   511,
     511,   511,   511,   511,   511,   512,   512,   513,   513,   514,
     515,   515,   516,   516,   517,   517,   518,   518,   518,   518,
     519,   519,   520,   520,   520,   520,   521,   521,   522,   522,
     523,   523,   523,   523,   524,   524,   524,   524,   525,   525,
     526,   526,   527,   528,   528,   528,   528,   528,   528,   529,
     530,   530,   531,   531,   532,   533,   534,   534,   535,   535,
     536,   537,   537,   537,   538,   538,   538,   539,   539,   539,
     539,   539,   539,   539,   540,   540,   541,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   543,   544,   544,   544,
     545,   546,   547,   547,   547,   548,   548,   548,   548,   548,
     549,   550,   550,   550,   550,   550,   550,   550,   551,   552,
     553,   554,   555,   555,   556,   557,   558,   558,   559,   560,
     560,   561,   562,   562,   562,   563,   563,   563,   563,   563,
     563,   563,   563,   563,   563,   564,   564,   565,   565,   566,
     567,   568,   568,   569,   570,   571,   571,   572,   573,   574,
     574,   575,   576,   576,   577,   577,   578,   578,   579,   579,
     580,   580,   581,   581,   582,   583,   583,   584,   584,   585,
     586,   586,   586,   587,   587,   588,   589,   589,   590,   591,
     591,   592,   592,   593,   593,   593,   594,   594,   595,   595,
     596,   596,   596,   596,   596,   597,   598,   599,   600,   600,
     600,   601,   601,   602,   602,   602,   602,   602,   602,   602,
     602,   603,   603,   603,   603,   604,   604,   605,   606,   606,
     607,   607,   607,   608,   608,   609,   609,   610,   610,   611,
     612,   612,   613,   613,   614,   614,   614,   615,   615,   616,
     616,   617,   617,   618,   618,   619,   619,   620,   621,   621,
     622,   622,   622,   623,   624,   624,   624,   624,   625,   625,
     626,   626,   627,   628,   628,   628,   628,   628,   629,   630,
     630,   630,   631,   631,   632,   632,   633,   634,   634,   635,
     636,   636,   636,   636,   637,   638,   639,   640,   641,   642,
     642,   643,   643,   643,   643,   643,   643,   643,   643,   643,
     643,   643,   643,   643,   643,   643,   643,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   645
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
       2,     3,     2,     3,     4,     1,     3,     1,     2,     1,
       1,     1,     2,     2,     2,     3,     1,     1,     2,     2,
       2,     5,     5,     1,     4,     3,     4,     8,     1,     2,
       3,     2,     3,     8,     1,     2,     3,     8,    10,     8,
      10,     1,     2,     4,     7,     1,     2,     4,     7,     8,
       1,     3,     1,     3,     1,     3,     3,     3,     3,     0,
       4,     3,     3,     3,     1,     5,     0,     1,     1,     3,
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
       1,     1,     1,     1,     2,     2,     3,     1,     4,     4,
       3,     4,     1,     3,     1,     1,     1,     1,     1,     4,
       5,     8,     9,     9,    10,     1,     2,     1,     2,     6,
       0,     1,     3,     3,     0,     1,     1,     1,     2,     2,
       0,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     2,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     4,
       3,     7,     3,     7,     4,     4,     3,     7,     1,     2,
       2,     1,     2,     3,     1,     1,     1,     1,     1,     3,
       3,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     4,     4,
       3,     3,     3,     4,     4,     3,     4,     6,     4,     6,
       4,     3,     4,     6,     6,     4,     6,     6,     4,     1,
       2,     1,     1,     1,     3,     3,     1,     1,     4,     5,
       6,     3,     3,     3,     3,     5,     7,     7,     5,     5,
       5,     7,     7,     5,     5,     3,     3,     5,     7,     5,
       7,     1,     4,     3,     5,     1,     2,     3,     3,     1,
       3,     2,     0,     1,     1,     2,     1,     3,     1,     3,
       1,     4,     1,     2,     3,     0,     1,     0,     1,     4,
       2,     3,     1,     0,     1,     4,     0,     1,     2,     1,
       3,     0,     1,     2,     2,     1,     0,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     2,     2,     3,     1,     2,
       2,     5,     2,     1,     1,     0,     2,     1,     3,     4,
       0,     2,     0,     2,     4,     4,     3,     2,     3,     1,
       3,     0,     1,     1,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     3,     2,     3,     3,     4,     2,     2,
       1,     1,     3,     1,     1,     1,     1,     1,     6,     4,
       4,     3,     3,     4,     2,     3,     3,     1,     3,     3,
       1,     1,     1,     1,     3,     3,     3,     3,     1,     1,
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
       1,     1
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
  "\"'ascending'\"", "\"'at'\"", "\"'attribute'\"", "\"'@'\"",
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
  "\"'keys'\"", "\"'structured-item'\"", "\"'array'\"", "\"'json-item'\"",
  "\"'object'\"", "\"'pair'\"", "\"'BOM_UTF8'\"", "RANGE_REDUCE",
  "SEQUENCE_TYPE_REDUCE", "ADDITIVE_REDUCE", "UNION_REDUCE",
  "INTERSECT_EXCEPT_REDUCE", "QVARINDECLLIST_REDUCE", "COMMA_DOLLAR",
  "UNARY_PREC", "OCCURS_STAR", "OCCURS_PLUS", "OCCURS_HOOK", "STEP_REDUCE",
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
  "opt_FTIgnoreOption", "RangeExpr", "AdditiveExpr", "MultiplicativeExpr",
  "UnionExpr", "IntersectExceptExpr", "InstanceofExpr", "TreatExpr",
  "CastableExpr", "CastExpr", "UnaryExpr", "SignList", "ValueExpr",
  "ValueComp", "NodeComp", "ValidateExpr", "ExtensionExpr", "Pragma_list",
  "Pragma", "PathExpr", "LeadingSlash", "RelativePathExpr", "StepExpr",
  "AxisStep", "ForwardStep", "ForwardAxis", "AbbrevForwardStep",
  "ReverseStep", "ReverseAxis", "NodeTest", "NameTest", "Wildcard",
  "FilterExpr", "PredicateList", "Predicate", "PrimaryExpr", "Literal",
  "NumericLiteral", "VarRef", "ParenthesizedExpr", "ContextItemExpr",
  "OrderedExpr", "UnorderedExpr", "FunctionCall", "ArgList", "Constructor",
  "DirectConstructor", "DirElemConstructor", "DirElemContentList",
  "DirAttributeList", "DirAttr", "OptionalBlank", "DirAttributeValue",
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
  "FTIgnoreOption", "JSONConstructor", "JSONComputedPairConstructor",
  "JSONComputedObjectConstructor", "JSONComputedArrayConstructor",
  "JSONDirectArrayConstructor", "JSONDirectObjectConstructor",
  "JSONDirectObjectContent", "JSONDirectPairConstructor", "JSONTest",
  "JSONItemTest", "JSONObjectTest", "JSONArrayTest", "JSONPairTest",
  "URI_LITERAL", "NCNAME", "QNAME", "FUNCTION_NAME", "EQNAME", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       328,     0,    -1,   330,    -1,   313,   330,    -1,     1,     3,
      -1,   332,    -1,   331,   332,    -1,   333,    -1,   331,   333,
      -1,   213,   214,    29,   189,    -1,   213,   214,    29,   130,
      29,   189,    -1,   335,   189,   382,    -1,   352,   189,   382,
      -1,   335,   189,   352,   189,   382,    -1,   382,    -1,   335,
     329,   382,    -1,   352,   329,   382,    -1,   335,   189,   352,
     329,   382,    -1,   335,   329,   352,   189,   382,    -1,   334,
      -1,   334,   335,   189,    -1,   334,   352,   189,    -1,   334,
     335,   189,   352,   189,    -1,    34,   159,   642,   131,   641,
     189,    -1,   336,    -1,   335,   189,   336,    -1,   335,   329,
     336,    -1,   337,    -1,   345,    -1,   350,    -1,   351,    -1,
     359,    -1,   338,    -1,   339,    -1,   340,    -1,   341,    -1,
     342,    -1,   343,    -1,   344,    -1,   562,    -1,    33,    38,
     181,    -1,    33,    38,   194,    -1,    33,   112,   105,   641,
      -1,    33,    37,   641,    -1,    33,    40,   181,    -1,    33,
      40,   194,    -1,    33,    57,   168,    -1,    33,    57,   200,
      -1,    33,   112,   167,   126,   127,    -1,    33,   112,   167,
     126,   128,    -1,    33,    41,   181,   106,   147,    -1,    33,
      41,   181,   106,   164,    -1,    33,    41,   165,   106,   147,
      -1,    33,    41,   165,   106,   164,    -1,   346,    -1,   349,
      -1,    49,    24,     1,    -1,    49,    60,   641,    -1,    49,
      60,   348,   641,    -1,    49,    60,   641,    96,   347,    -1,
      49,    60,   348,   641,    96,   347,    -1,   641,    -1,   347,
     106,   641,    -1,   159,   642,   131,    -1,   112,    45,   159,
      -1,    49,    34,   641,    -1,    49,    34,   159,   642,   131,
     641,    -1,    49,    34,   641,    96,   347,    -1,    49,    34,
     159,   642,   131,   641,    96,   347,    -1,    33,   159,   642,
     131,   641,    -1,    33,   112,    45,   159,   641,    -1,    33,
     112,    47,   159,   641,    -1,   353,    -1,   352,   189,   353,
      -1,   352,   329,   353,    -1,   354,    -1,   358,    -1,   360,
      -1,   364,    -1,   369,    -1,   376,    -1,   378,    -1,   381,
      -1,    33,   112,    79,   355,    -1,    33,    79,   643,   355,
      -1,   356,    -1,   355,   356,    -1,   357,   131,   554,    -1,
      80,    -1,    88,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    89,    -1,    85,    -1,    86,    -1,    87,    -1,
      33,    56,   643,    29,    -1,    33,   259,   601,    -1,    33,
     110,   151,   361,    -1,    94,   539,   362,    -1,   362,    -1,
     363,    -1,   136,    -1,   136,   363,    -1,   141,   406,    -1,
      33,   365,   141,   406,    -1,    33,   365,   136,    -1,    33,
     365,   136,   141,   406,    -1,   111,   117,   643,    -1,   111,
     117,   643,   536,    -1,   366,   111,   117,   643,    -1,   366,
     111,   117,   643,   536,    -1,   367,    -1,   366,   367,    -1,
      26,    -1,    26,   155,   368,   186,    -1,    27,    -1,    27,
     155,   368,   186,    -1,   500,    -1,   368,   106,   500,    -1,
      33,   370,    -1,    33,   366,   370,    -1,   371,    -1,   372,
      -1,    47,   644,   373,   390,    -1,    47,   644,   373,   136,
      -1,    74,    47,   644,   373,   390,    -1,    74,    47,   644,
     373,   136,    -1,   155,   186,    -1,   155,   374,   186,    -1,
     155,   186,    94,   537,    -1,   155,   374,   186,    94,   537,
      -1,   375,    -1,   374,   106,   375,    -1,   117,   643,    -1,
     117,   643,   536,    -1,    33,   285,   643,    -1,    33,   285,
     643,    94,   377,    -1,    33,   366,   285,   643,    -1,    33,
     366,   285,   643,    94,   377,    -1,   542,    -1,   542,   538,
      -1,    33,   293,   643,   297,   225,   483,   169,   379,    -1,
      33,   366,   293,   643,   297,   225,   483,   169,   379,    -1,
     380,    -1,   379,   106,   380,    -1,   483,    -1,   483,   536,
      -1,   483,   441,    -1,   483,   536,   441,    -1,    33,   301,
     302,   643,   297,   285,   643,   117,   643,   303,   406,    -1,
      33,   301,   302,   643,   297,   285,   643,   223,   117,   643,
     303,   291,   304,   483,    -1,    33,   301,   302,   643,   297,
     285,   643,   305,   223,   117,   643,   303,   406,    -1,    33,
     301,   302,   643,   306,   304,   255,   285,   643,   223,   117,
     643,   304,   483,   197,   285,   643,   223,   117,   643,   304,
     483,    -1,   383,    -1,   385,    -1,   386,    -1,    -1,   385,
      -1,   386,    -1,    -1,   405,    -1,   386,   405,    -1,   387,
      -1,   386,   387,    -1,   388,    -1,   391,    -1,   394,    -1,
     395,    -1,   396,    -1,   397,    -1,   398,    -1,   399,    -1,
     401,    -1,   453,    -1,   449,    -1,   402,    -1,   152,   386,
     183,    -1,   152,   183,    -1,   152,   384,   183,    -1,   152,
     384,   183,    -1,   392,   189,    -1,   392,   106,   393,    -1,
     111,   393,    -1,   366,   111,   393,    -1,   117,   643,    -1,
     117,   643,   536,    -1,   117,   643,   141,   406,    -1,   117,
     643,   536,   141,   406,    -1,   117,   643,   141,   406,   189,
      -1,   407,   189,    -1,   238,   240,   406,   189,    -1,   241,
     155,   405,   186,   387,    -1,   236,   239,   189,    -1,   237,
     239,   189,    -1,   417,   400,    -1,   185,   387,    -1,    48,
     155,   405,   186,   196,   387,   125,   387,    -1,   242,   388,
     403,    -1,   404,    -1,   403,   404,    -1,   243,   574,   388,
      -1,   406,    -1,   405,   106,   406,    -1,   408,    -1,   445,
      -1,   452,    -1,   458,    -1,   570,    -1,   407,    -1,   459,
      -1,   442,    -1,   563,    -1,   564,    -1,   566,    -1,   565,
      -1,   567,    -1,   417,   409,    -1,   185,   406,    -1,    66,
     282,    -1,    71,   282,    -1,   215,    -1,   252,    -1,    55,
     252,    -1,   411,   427,    77,   406,    -1,   411,    77,   406,
      -1,    46,   410,   426,   412,   412,    -1,    46,   410,   426,
     412,    -1,    42,   117,   643,    -1,   418,    -1,   423,    -1,
     413,    -1,   415,    -1,   430,    -1,   435,    -1,   431,    -1,
     414,    -1,   415,    -1,   417,   416,    -1,    46,   117,   419,
      -1,   420,    -1,   419,   106,   117,   420,    -1,   643,   146,
     406,    -1,   643,    36,   126,   146,   406,    -1,   643,   536,
     146,   406,    -1,   643,   536,    36,   126,   146,   406,    -1,
     643,   421,   146,   406,    -1,   643,    36,   126,   421,   146,
     406,    -1,   643,   536,   421,   146,   406,    -1,   643,   536,
      36,   126,   421,   146,   406,    -1,   643,   422,   146,   406,
      -1,   643,   536,   422,   146,   406,    -1,   643,   421,   422,
     146,   406,    -1,   643,   536,   421,   422,   146,   406,    -1,
      96,   117,   643,    -1,   271,   117,   643,    -1,    51,   424,
      -1,   425,    -1,   424,   106,   425,    -1,   117,   643,   141,
     406,    -1,   117,   643,   536,   141,   406,    -1,   422,   141,
     406,    -1,   117,   643,   536,   422,   141,   406,    -1,   117,
     643,   146,   406,    -1,   117,   643,   536,   146,   406,    -1,
     428,    -1,   117,   643,    -1,   117,   643,   428,    -1,   421,
      -1,   421,   429,    -1,   429,    -1,    58,   117,   643,    53,
     117,   643,    -1,    53,   117,   643,    -1,    58,   117,   643,
      -1,   210,   406,    -1,   170,   169,   432,    -1,   433,    -1,
     432,   106,   433,    -1,   117,   643,    -1,   117,   643,   434,
      -1,   105,   641,    -1,   167,   169,   436,    -1,    69,   167,
     169,   436,    -1,   437,    -1,   436,   106,   437,    -1,   406,
      -1,   406,   438,    -1,   439,    -1,   440,    -1,   441,    -1,
     439,   440,    -1,   439,   441,    -1,   440,   441,    -1,   439,
     440,   441,    -1,    95,    -1,   115,    -1,   126,   127,    -1,
     126,   128,    -1,   105,   641,    -1,    67,   117,   443,   187,
     406,    -1,   134,   117,   443,   187,   406,    -1,   444,    -1,
     443,   106,   117,   444,    -1,   643,   146,   406,    -1,   643,
     536,   146,   406,    -1,    72,   155,   405,   186,   446,   112,
     185,   406,    -1,   447,    -1,   446,   447,    -1,   448,   185,
     406,    -1,    99,   406,    -1,   448,    99,   406,    -1,    72,
     155,   405,   186,   450,   112,   185,   387,    -1,   451,    -1,
     450,   451,    -1,   448,   185,   387,    -1,    73,   155,   405,
     186,   454,   112,   185,   406,    -1,    73,   155,   405,   186,
     454,   112,   117,   643,   185,   406,    -1,    73,   155,   405,
     186,   456,   112,   185,   387,    -1,    73,   155,   405,   186,
     454,   112,   117,   643,   185,   387,    -1,   455,    -1,   454,
     455,    -1,    99,   537,   185,   406,    -1,    99,   117,   643,
      94,   537,   185,   406,    -1,   457,    -1,   456,   457,    -1,
      99,   537,   185,   387,    -1,    99,   117,   643,    94,   537,
     185,   387,    -1,    48,   155,   405,   186,   196,   406,   125,
     406,    -1,   460,    -1,   459,   166,   460,    -1,   461,    -1,
     460,    92,   461,    -1,   463,    -1,   463,   477,   463,    -1,
     463,   478,   463,    -1,   463,   131,   463,    -1,   463,   161,
     463,    -1,    -1,   463,   156,   462,   463,    -1,   463,   154,
     463,    -1,   463,   142,   463,    -1,   463,   140,   463,    -1,
     465,    -1,   465,   247,    70,   575,   464,    -1,    -1,   627,
      -1,   466,    -1,   466,   197,   466,    -1,   467,    -1,   466,
     175,   467,    -1,   466,   157,   467,    -1,   468,    -1,   467,
     192,   468,    -1,   467,   116,   468,    -1,   467,   145,   468,
      -1,   467,   158,   468,    -1,   469,    -1,   468,   199,   469,
      -1,   468,   208,   469,    -1,   470,    -1,   469,   149,   470,
      -1,   469,   135,   470,    -1,   471,    -1,   471,    50,   229,
     537,    -1,   472,    -1,   472,   198,    94,   537,    -1,   473,
      -1,   473,   100,    94,   535,    -1,   474,    -1,   474,   101,
      94,   535,    -1,   476,    -1,   475,   476,    -1,   175,    -1,
     157,    -1,   475,   175,    -1,   475,   157,    -1,   479,    -1,
     483,    -1,   480,    -1,   201,    -1,   206,    -1,   205,    -1,
     204,    -1,   203,    -1,   202,    -1,   150,    -1,   178,    -1,
     139,    -1,    75,   152,   385,   183,    -1,    75,   220,   152,
     385,   183,    -1,    75,   219,   152,   385,   183,    -1,    75,
      76,   552,   152,   385,   183,    -1,   481,   152,   183,    -1,
     481,   152,   405,   183,    -1,   482,    -1,   481,   482,    -1,
     176,   643,    17,    -1,   176,    18,    -1,   176,    19,    -1,
     484,    -1,   484,   485,    -1,   191,   485,    -1,   485,    -1,
     190,    -1,   486,    -1,   486,   190,   485,    -1,   486,   191,
     485,    -1,   487,    -1,   496,    -1,   488,    -1,   488,   497,
      -1,   491,    -1,   491,   497,    -1,   489,   493,    -1,   490,
      -1,   104,   121,    -1,   113,   121,    -1,    97,   121,    -1,
     188,   121,    -1,   114,   121,    -1,   138,   121,    -1,   137,
     121,    -1,   493,    -1,    98,   493,    -1,   492,   493,    -1,
     119,    -1,   171,   121,    -1,    90,   121,    -1,   180,   121,
      -1,   179,   121,    -1,    91,   121,    -1,   542,    -1,   494,
      -1,   643,    -1,   495,    -1,   192,    -1,    11,    -1,    12,
      -1,    20,    -1,   499,    -1,   496,   497,    -1,   496,   155,
     186,    -1,   496,   155,   508,   186,    -1,   498,    -1,   497,
     498,    -1,   153,   405,   184,    -1,   500,    -1,   502,    -1,
     503,    -1,   504,    -1,   507,    -1,   509,    -1,   505,    -1,
     506,    -1,   555,    -1,   389,    -1,   628,    -1,   501,    -1,
     554,    -1,   109,    -1,   148,    -1,   123,    -1,   117,   643,
      -1,   155,   186,    -1,   155,   405,   186,    -1,   118,    -1,
     168,   152,   405,   183,    -1,   200,   152,   405,   183,    -1,
     644,   155,   186,    -1,   644,   155,   508,   186,    -1,   406,
      -1,   508,   106,   406,    -1,   510,    -1,   528,    -1,   511,
      -1,   525,    -1,   526,    -1,   156,   643,   515,   129,    -1,
     156,   643,   513,   515,   129,    -1,   156,   643,   515,   195,
     193,   643,   515,   195,    -1,   156,   643,   515,   195,   512,
     193,   643,   515,   195,    -1,   156,   643,   513,   515,   195,
     193,   643,   515,   195,    -1,   156,   643,   513,   515,   195,
     512,   193,   643,   515,   195,    -1,   523,    -1,   512,   523,
      -1,   514,    -1,   513,   514,    -1,    35,   643,   515,   131,
     515,   516,    -1,    -1,    35,    -1,   182,   517,   182,    -1,
      93,   519,    93,    -1,    -1,   518,    -1,   133,    -1,   521,
      -1,   518,   133,    -1,   518,   521,    -1,    -1,   520,    -1,
     132,    -1,   522,    -1,   520,   132,    -1,   520,   522,    -1,
      28,    -1,   524,    -1,     5,    -1,   524,    -1,   510,    -1,
      10,    -1,   527,    -1,   524,    -1,     9,    -1,   122,    -1,
     124,    -1,   152,   385,   183,    -1,   211,    30,   212,    -1,
     211,   212,    -1,   173,   642,   174,    -1,   173,   642,     8,
      -1,   102,     7,    -1,   529,    -1,   530,    -1,   531,    -1,
     532,    -1,   533,    -1,   534,    -1,    43,   152,   385,   183,
      -1,    21,   384,   183,    -1,    45,   152,   405,   183,   152,
     384,   183,    -1,    22,   384,   183,    -1,    97,   152,   405,
     183,   152,   384,   183,    -1,    70,   152,   385,   183,    -1,
      39,   152,   385,   183,    -1,    23,   384,   183,    -1,    59,
     152,   405,   183,   152,   384,   183,    -1,   541,    -1,   541,
     143,    -1,    94,   537,    -1,   539,    -1,   539,   538,    -1,
     209,   155,   186,    -1,   143,    -1,   192,    -1,   175,    -1,
     541,    -1,   542,    -1,   151,   155,   186,    -1,   308,   155,
     186,    -1,   558,    -1,   561,    -1,   636,    -1,   537,    -1,
     540,   106,   537,    -1,   643,    -1,   544,    -1,   550,    -1,
     548,    -1,   551,    -1,   549,    -1,   547,    -1,   546,    -1,
     545,    -1,   543,    -1,   223,   155,   186,    -1,    44,   155,
     186,    -1,    44,   155,   550,   186,    -1,    44,   155,   551,
     186,    -1,    70,   155,   186,    -1,    39,   155,   186,    -1,
      59,   155,   186,    -1,    59,   155,   642,   186,    -1,    59,
     155,    29,   186,    -1,    97,   155,   186,    -1,    97,   155,
     643,   186,    -1,    97,   155,   643,   106,   552,   186,    -1,
      97,   155,   192,   186,    -1,    97,   155,   192,   106,   552,
     186,    -1,    61,   155,   643,   186,    -1,    45,   155,   186,
      -1,    45,   155,   643,   186,    -1,    45,   155,   643,   106,
     552,   186,    -1,    45,   155,   643,   106,   553,   186,    -1,
      45,   155,   192,   186,    -1,    45,   155,   192,   106,   552,
     186,    -1,    45,   155,   192,   106,   553,   186,    -1,    62,
     155,   643,   186,    -1,   643,    -1,   643,   143,    -1,    29,
      -1,   556,    -1,   557,    -1,   643,   144,   148,    -1,    47,
     373,   390,    -1,   559,    -1,   560,    -1,    47,   155,   192,
     186,    -1,    47,   155,   186,    94,   537,    -1,    47,   155,
     540,   186,    94,   537,    -1,   155,   539,   186,    -1,    33,
     218,   219,    -1,    33,   218,   220,    -1,    33,   218,   221,
      -1,   224,   223,   406,   231,   406,    -1,   224,   223,   406,
      94,   230,   231,   406,    -1,   224,   223,   406,    94,   232,
     231,   406,    -1,   224,   223,   406,   216,   406,    -1,   224,
     223,   406,   217,   406,    -1,   224,   225,   406,   231,   406,
      -1,   224,   225,   406,    94,   230,   231,   406,    -1,   224,
     225,   406,    94,   232,   231,   406,    -1,   224,   225,   406,
     216,   406,    -1,   224,   225,   406,   217,   406,    -1,   222,
     223,   406,    -1,   222,   225,   406,    -1,   227,   223,   406,
     235,   406,    -1,   227,   228,   229,   223,   406,   235,   406,
      -1,   226,   223,   406,    94,   406,    -1,   234,   117,   568,
     233,   406,   185,   406,    -1,   569,    -1,   568,   106,   117,
     569,    -1,   643,   141,   406,    -1,   242,   152,   405,   183,
     571,    -1,   572,    -1,   571,   572,    -1,   243,   574,   573,
      -1,   152,   405,   183,    -1,   494,    -1,   574,   208,   494,
      -1,   578,   576,    -1,    -1,   577,    -1,   596,    -1,   577,
     596,    -1,   579,    -1,   578,   260,   579,    -1,   580,    -1,
     579,   256,   580,    -1,   581,    -1,   580,   258,   146,   581,
      -1,   582,    -1,   257,   582,    -1,   586,   583,   584,    -1,
      -1,   601,    -1,    -1,   585,    -1,   280,   152,   405,   183,
      -1,   590,   587,    -1,   155,   575,   186,    -1,   588,    -1,
      -1,   623,    -1,   481,   152,   589,   183,    -1,    -1,   575,
      -1,   591,   592,    -1,   500,    -1,   152,   405,   183,    -1,
      -1,   593,    -1,   246,   594,    -1,   245,   595,    -1,   268,
      -1,    -1,    78,    -1,    -1,   284,    -1,   597,    -1,   598,
      -1,   599,    -1,   625,    -1,   622,    -1,   168,    -1,   282,
     466,   600,    -1,   251,   624,   600,    -1,   284,    -1,   274,
      -1,   267,    -1,   244,   602,    -1,   601,   244,   602,    -1,
     603,    -1,   604,    -1,   605,    -1,   620,    -1,   606,    -1,
     614,    -1,   607,    -1,   621,    -1,    99,   272,    -1,    99,
     261,    -1,   264,    -1,   279,    -1,   249,   272,    -1,   249,
     261,    -1,    56,   643,    29,    -1,   275,    -1,    54,   275,
      -1,   277,   608,    -1,   277,   155,   608,   609,   186,    -1,
      54,   277,    -1,   611,    -1,   112,    -1,    -1,   106,   610,
      -1,   611,    -1,   610,   106,   611,    -1,    96,    29,   612,
     613,    -1,    -1,   269,    29,    -1,    -1,   624,   263,    -1,
     276,   284,   615,   617,    -1,   276,   284,   112,   617,    -1,
      54,   276,   284,    -1,    96,    29,    -1,   155,   616,   186,
      -1,    29,    -1,   616,   106,    29,    -1,    -1,   618,    -1,
     619,    -1,   618,   619,    -1,   199,   615,    -1,   135,   615,
      -1,   262,    29,    -1,   281,    -1,    54,   281,    -1,    96,
     215,    -1,    96,   252,    -1,   253,   248,    -1,   265,   624,
     278,    -1,   254,   466,    -1,    96,   128,   466,    -1,    96,
      52,   466,    -1,   255,   466,   197,   466,    -1,   270,   626,
      -1,   250,   626,    -1,   273,    -1,   266,    -1,   283,   248,
     468,    -1,   632,    -1,   633,    -1,   630,    -1,   631,    -1,
     629,    -1,   312,   152,   406,   120,   406,   183,    -1,   311,
     152,   405,   183,    -1,   311,   152,   634,   183,    -1,   311,
     152,   183,    -1,   309,   152,   183,    -1,   309,   152,   405,
     183,    -1,   153,   184,    -1,   153,   405,   184,    -1,   152,
     634,   183,    -1,   635,    -1,   634,   106,   635,    -1,   406,
     120,   406,    -1,   637,    -1,   638,    -1,   639,    -1,   640,
      -1,   310,   155,   186,    -1,   311,   155,   186,    -1,   309,
     155,   186,    -1,   312,   155,   186,    -1,    29,    -1,    16,
      -1,   643,    -1,   644,    -1,    97,    -1,    39,    -1,    44,
      -1,    45,    -1,   151,    -1,    48,    -1,   223,    -1,    59,
      -1,    61,    -1,    62,    -1,    70,    -1,    73,    -1,    72,
      -1,   209,    -1,   241,    -1,   645,    -1,    24,    -1,   213,
      -1,   126,    -1,    38,    -1,   259,    -1,    37,    -1,   220,
      -1,   219,    -1,   145,    -1,    43,    -1,   257,    -1,   258,
      -1,   272,    -1,   261,    -1,   249,    -1,   283,    -1,   275,
      -1,   277,    -1,   276,    -1,   281,    -1,   253,    -1,   248,
      -1,    78,    -1,   215,    -1,   252,    -1,    52,    -1,   221,
      -1,   234,    -1,   300,    -1,   228,    -1,   201,    -1,   206,
      -1,   205,    -1,   204,    -1,   203,    -1,   202,    -1,    96,
      -1,   110,    -1,   111,    -1,   185,    -1,    46,    -1,    36,
      -1,    66,    -1,    71,    -1,    58,    -1,    53,    -1,    55,
      -1,    77,    -1,    42,    -1,   146,    -1,    51,    -1,   210,
      -1,   169,    -1,   170,    -1,   167,    -1,    69,    -1,    95,
      -1,   115,    -1,   127,    -1,   128,    -1,   105,    -1,    67,
      -1,   134,    -1,   187,    -1,    99,    -1,    94,    -1,   196,
      -1,   125,    -1,   166,    -1,    92,    -1,    50,    -1,   229,
      -1,   100,    -1,   197,    -1,   116,    -1,   158,    -1,   199,
      -1,   149,    -1,   135,    -1,    75,    -1,    76,    -1,   101,
      -1,   198,    -1,   150,    -1,   181,    -1,   194,    -1,   159,
      -1,   136,    -1,   130,    -1,   165,    -1,   147,    -1,   164,
      -1,    33,    -1,    40,    -1,    57,    -1,   112,    -1,    41,
      -1,    56,    -1,   214,    -1,    49,    -1,    60,    -1,    34,
      -1,    47,    -1,   271,    -1,   247,    -1,   280,    -1,   282,
      -1,   251,    -1,   265,    -1,   278,    -1,   270,    -1,   250,
      -1,   264,    -1,   279,    -1,   269,    -1,   263,    -1,   262,
      -1,   246,    -1,   245,    -1,   254,    -1,   255,    -1,   284,
      -1,   274,    -1,   273,    -1,   268,    -1,   266,    -1,   267,
      -1,   227,    -1,   233,    -1,   230,    -1,   224,    -1,   217,
      -1,   216,    -1,   218,    -1,   235,    -1,   225,    -1,   226,
      -1,   232,    -1,   222,    -1,   231,    -1,    65,    -1,    63,
      -1,    74,    -1,   168,    -1,   200,    -1,   240,    -1,   238,
      -1,   239,    -1,   236,    -1,   237,    -1,   242,    -1,   243,
      -1,   244,    -1,    64,    -1,   293,    -1,   291,    -1,   292,
      -1,   297,    -1,   298,    -1,   299,    -1,   294,    -1,   295,
      -1,   296,    -1,    79,    -1,    80,    -1,    81,    -1,    82,
      -1,    83,    -1,    84,    -1,    85,    -1,    86,    -1,    87,
      -1,    88,    -1,    89,    -1,   285,    -1,   286,    -1,   287,
      -1,   288,    -1,   289,    -1,   290,    -1,   301,    -1,   302,
      -1,   303,    -1,   304,    -1,   305,    -1,   306,    -1,   307,
      -1,    90,    -1,   104,    -1,   113,    -1,   171,    -1,   179,
      -1,   188,    -1,   137,    -1,    91,    -1,   114,    -1,   138,
      -1,   180,    -1,   311,    -1,   309,    -1,   312,    -1,   310,
      -1,   308,    -1,    25,    -1
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
    1054,  1057,  1061,  1064,  1068,  1073,  1075,  1079,  1081,  1084,
    1086,  1088,  1090,  1093,  1096,  1099,  1103,  1105,  1107,  1110,
    1113,  1116,  1122,  1128,  1130,  1135,  1139,  1144,  1153,  1155,
    1158,  1162,  1165,  1169,  1178,  1180,  1183,  1187,  1196,  1207,
    1216,  1227,  1229,  1232,  1237,  1245,  1247,  1250,  1255,  1263,
    1272,  1274,  1278,  1280,  1284,  1286,  1290,  1294,  1298,  1302,
    1303,  1308,  1312,  1316,  1320,  1322,  1328,  1329,  1331,  1333,
    1337,  1339,  1343,  1347,  1349,  1353,  1357,  1361,  1365,  1367,
    1371,  1375,  1377,  1381,  1385,  1387,  1392,  1394,  1399,  1401,
    1406,  1408,  1413,  1415,  1418,  1420,  1422,  1425,  1428,  1430,
    1432,  1434,  1436,  1438,  1440,  1442,  1444,  1446,  1448,  1450,
    1452,  1457,  1463,  1469,  1476,  1480,  1485,  1487,  1490,  1494,
    1497,  1500,  1502,  1505,  1508,  1510,  1512,  1514,  1518,  1522,
    1524,  1526,  1528,  1531,  1533,  1536,  1539,  1541,  1544,  1547,
    1550,  1553,  1556,  1559,  1562,  1564,  1567,  1570,  1572,  1575,
    1578,  1581,  1584,  1587,  1589,  1591,  1593,  1595,  1597,  1599,
    1601,  1603,  1605,  1608,  1612,  1617,  1619,  1622,  1626,  1628,
    1630,  1632,  1634,  1636,  1638,  1640,  1642,  1644,  1646,  1648,
    1650,  1652,  1654,  1656,  1658,  1661,  1664,  1668,  1670,  1675,
    1680,  1684,  1689,  1691,  1695,  1697,  1699,  1701,  1703,  1705,
    1710,  1716,  1725,  1735,  1745,  1756,  1758,  1761,  1763,  1766,
    1773,  1774,  1776,  1780,  1784,  1785,  1787,  1789,  1791,  1794,
    1797,  1798,  1800,  1802,  1804,  1807,  1810,  1812,  1814,  1816,
    1818,  1820,  1822,  1824,  1826,  1828,  1830,  1832,  1836,  1840,
    1843,  1847,  1851,  1854,  1856,  1858,  1860,  1862,  1864,  1866,
    1871,  1875,  1883,  1887,  1895,  1900,  1905,  1909,  1917,  1919,
    1922,  1925,  1927,  1930,  1934,  1936,  1938,  1940,  1942,  1944,
    1948,  1952,  1954,  1956,  1958,  1960,  1964,  1966,  1968,  1970,
    1972,  1974,  1976,  1978,  1980,  1982,  1984,  1988,  1992,  1997,
    2002,  2006,  2010,  2014,  2019,  2024,  2028,  2033,  2040,  2045,
    2052,  2057,  2061,  2066,  2073,  2080,  2085,  2092,  2099,  2104,
    2106,  2109,  2111,  2113,  2115,  2119,  2123,  2125,  2127,  2132,
    2138,  2145,  2149,  2153,  2157,  2161,  2167,  2175,  2183,  2189,
    2195,  2201,  2209,  2217,  2223,  2229,  2233,  2237,  2243,  2251,
    2257,  2265,  2267,  2272,  2276,  2282,  2284,  2287,  2291,  2295,
    2297,  2301,  2304,  2305,  2307,  2309,  2312,  2314,  2318,  2320,
    2324,  2326,  2331,  2333,  2336,  2340,  2341,  2343,  2344,  2346,
    2351,  2354,  2358,  2360,  2361,  2363,  2368,  2369,  2371,  2374,
    2376,  2380,  2381,  2383,  2386,  2389,  2391,  2392,  2394,  2395,
    2397,  2399,  2401,  2403,  2405,  2407,  2409,  2413,  2417,  2419,
    2421,  2423,  2426,  2430,  2432,  2434,  2436,  2438,  2440,  2442,
    2444,  2446,  2449,  2452,  2454,  2456,  2459,  2462,  2466,  2468,
    2471,  2474,  2480,  2483,  2485,  2487,  2488,  2491,  2493,  2497,
    2502,  2503,  2506,  2507,  2510,  2515,  2520,  2524,  2527,  2531,
    2533,  2537,  2538,  2540,  2542,  2545,  2548,  2551,  2554,  2556,
    2559,  2562,  2565,  2568,  2572,  2575,  2579,  2583,  2588,  2591,
    2594,  2596,  2598,  2602,  2604,  2606,  2608,  2610,  2612,  2619,
    2624,  2629,  2633,  2637,  2642,  2645,  2649,  2653,  2655,  2659,
    2663,  2665,  2667,  2669,  2671,  2675,  2679,  2683,  2687,  2689,
    2691,  2693,  2695,  2697,  2699,  2701,  2703,  2705,  2707,  2709,
    2711,  2713,  2715,  2717,  2719,  2721,  2723,  2725,  2727,  2729,
    2731,  2733,  2735,  2737,  2739,  2741,  2743,  2745,  2747,  2749,
    2751,  2753,  2755,  2757,  2759,  2761,  2763,  2765,  2767,  2769,
    2771,  2773,  2775,  2777,  2779,  2781,  2783,  2785,  2787,  2789,
    2791,  2793,  2795,  2797,  2799,  2801,  2803,  2805,  2807,  2809,
    2811,  2813,  2815,  2817,  2819,  2821,  2823,  2825,  2827,  2829,
    2831,  2833,  2835,  2837,  2839,  2841,  2843,  2845,  2847,  2849,
    2851,  2853,  2855,  2857,  2859,  2861,  2863,  2865,  2867,  2869,
    2871,  2873,  2875,  2877,  2879,  2881,  2883,  2885,  2887,  2889,
    2891,  2893,  2895,  2897,  2899,  2901,  2903,  2905,  2907,  2909,
    2911,  2913,  2915,  2917,  2919,  2921,  2923,  2925,  2927,  2929,
    2931,  2933,  2935,  2937,  2939,  2941,  2943,  2945,  2947,  2949,
    2951,  2953,  2955,  2957,  2959,  2961,  2963,  2965,  2967,  2969,
    2971,  2973,  2975,  2977,  2979,  2981,  2983,  2985,  2987,  2989,
    2991,  2993,  2995,  2997,  2999,  3001,  3003,  3005,  3007,  3009,
    3011,  3013,  3015,  3017,  3019,  3021,  3023,  3025,  3027,  3029,
    3031,  3033,  3035,  3037,  3039,  3041,  3043,  3045,  3047,  3049,
    3051,  3053,  3055,  3057,  3059,  3061,  3063,  3065,  3067,  3069,
    3071,  3073,  3075,  3077,  3079,  3081,  3083,  3085,  3087,  3089,
    3091,  3093,  3095,  3097,  3099,  3101,  3103,  3105,  3107,  3109,
    3111,  3113,  3115,  3117,  3119,  3121,  3123,  3125,  3127,  3129,
    3131,  3133
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1040,  1040,  1041,  1050,  1059,  1065,  1073,  1079,  1090,
    1095,  1103,  1110,  1117,  1126,  1133,  1141,  1149,  1157,  1168,
    1173,  1180,  1187,  1199,  1209,  1216,  1223,  1235,  1236,  1237,
    1238,  1239,  1244,  1245,  1246,  1247,  1248,  1249,  1250,  1253,
    1258,  1263,  1271,  1279,  1287,  1292,  1300,  1305,  1313,  1318,
    1326,  1333,  1340,  1347,  1357,  1359,  1362,  1372,  1377,  1385,
    1393,  1404,  1411,  1422,  1427,  1435,  1442,  1449,  1458,  1471,
    1479,  1486,  1496,  1503,  1510,  1521,  1522,  1523,  1524,  1525,
    1526,  1527,  1528,  1533,  1539,  1548,  1555,  1565,  1575,  1576,
    1577,  1578,  1579,  1580,  1581,  1582,  1583,  1584,  1589,  1597,
    1605,  1613,  1620,  1628,  1635,  1640,  1648,  1656,  1671,  1686,
    1704,  1709,  1717,  1725,  1736,  1741,  1750,  1755,  1762,  1767,
    1777,  1782,  1791,  1797,  1810,  1815,  1823,  1834,  1849,  1861,
    1876,  1881,  1886,  1891,  1899,  1906,  1917,  1922,  1932,  1939,
    1946,  1953,  1963,  1967,  1977,  1985,  1996,  2002,  2011,  2016,
    2023,  2030,  2041,  2051,  2061,  2071,  2089,  2109,  2113,  2118,
    2125,  2129,  2134,  2141,  2146,  2158,  2165,  2177,  2178,  2179,
    2180,  2181,  2182,  2183,  2185,  2186,  2187,  2188,  2189,  2194,
    2199,  2207,  2224,  2232,  2240,  2247,  2254,  2264,  2276,  2289,
    2301,  2317,  2325,  2333,  2341,  2356,  2361,  2369,  2383,  2400,
    2425,  2433,  2440,  2451,  2461,  2466,  2481,  2482,  2483,  2484,
    2485,  2486,  2491,  2492,  2495,  2496,  2497,  2498,  2499,  2504,
    2518,  2526,  2531,  2539,  2544,  2549,  2557,  2566,  2578,  2588,
    2601,  2609,  2610,  2611,  2616,  2617,  2618,  2619,  2620,  2625,
    2632,  2642,  2650,  2657,  2667,  2677,  2687,  2697,  2707,  2717,
    2727,  2737,  2748,  2757,  2767,  2777,  2793,  2802,  2811,  2819,
    2825,  2837,  2845,  2855,  2863,  2875,  2881,  2892,  2894,  2898,
    2906,  2910,  2915,  2919,  2923,  2927,  2937,  2945,  2952,  2958,
    2969,  2973,  2982,  2990,  2996,  3006,  3012,  3022,  3026,  3036,
    3042,  3048,  3054,  3063,  3072,  3081,  3094,  3098,  3106,  3112,
    3122,  3130,  3139,  3152,  3159,  3171,  3175,  3187,  3194,  3200,
    3209,  3216,  3222,  3233,  3240,  3246,  3255,  3264,  3271,  3282,
    3289,  3301,  3307,  3319,  3325,  3336,  3342,  3353,  3359,  3370,
    3379,  3383,  3392,  3396,  3404,  3408,  3418,  3425,  3434,  3444,
    3443,  3457,  3466,  3475,  3488,  3492,  3505,  3508,  3515,  3519,
    3527,  3531,  3535,  3543,  3547,  3553,  3559,  3565,  3575,  3579,
    3583,  3591,  3595,  3601,  3611,  3615,  3625,  3629,  3639,  3643,
    3653,  3657,  3667,  3671,  3679,  3683,  3687,  3691,  3701,  3705,
    3709,  3717,  3721,  3725,  3729,  3733,  3737,  3745,  3749,  3753,
    3761,  3765,  3769,  3773,  3784,  3790,  3800,  3806,  3816,  3820,
    3824,  3862,  3866,  3876,  3886,  3899,  3908,  3918,  3922,  3931,
    3935,  3944,  3950,  3958,  3964,  3976,  3982,  3992,  3996,  4000,
    4004,  4008,  4014,  4020,  4028,  4032,  4040,  4044,  4055,  4059,
    4063,  4069,  4073,  4087,  4091,  4099,  4103,  4113,  4117,  4121,
    4125,  4134,  4138,  4142,  4146,  4154,  4160,  4170,  4178,  4182,
    4186,  4190,  4194,  4198,  4202,  4206,  4210,  4214,  4218,  4226,
    4230,  4238,  4245,  4252,  4263,  4271,  4275,  4283,  4291,  4299,
    4353,  4357,  4370,  4376,  4386,  4390,  4398,  4402,  4406,  4414,
    4424,  4434,  4444,  4454,  4464,  4479,  4485,  4496,  4502,  4513,
    4524,  4526,  4530,  4535,  4545,  4548,  4555,  4561,  4567,  4575,
    4588,  4591,  4598,  4604,  4610,  4617,  4628,  4632,  4642,  4646,
    4656,  4660,  4664,  4669,  4678,  4684,  4690,  4696,  4704,  4709,
    4717,  4722,  4730,  4738,  4743,  4748,  4753,  4758,  4763,  4772,
    4780,  4784,  4801,  4805,  4813,  4821,  4829,  4833,  4841,  4847,
    4857,  4865,  4869,  4873,  4908,  4914,  4920,  4930,  4934,  4938,
    4942,  4946,  4950,  4954,  4961,  4967,  4977,  4985,  4989,  4993,
    4997,  5001,  5005,  5009,  5013,  5017,  5025,  5033,  5037,  5041,
    5051,  5059,  5067,  5071,  5075,  5083,  5087,  5093,  5099,  5103,
    5113,  5121,  5125,  5131,  5140,  5149,  5155,  5161,  5171,  5188,
    5195,  5210,  5246,  5250,  5258,  5266,  5278,  5282,  5290,  5298,
    5302,  5313,  5330,  5336,  5342,  5352,  5356,  5362,  5368,  5372,
    5378,  5382,  5388,  5394,  5401,  5411,  5416,  5424,  5430,  5440,
    5462,  5471,  5477,  5490,  5504,  5511,  5517,  5527,  5536,  5544,
    5550,  5568,  5577,  5580,  5587,  5592,  5600,  5604,  5611,  5615,
    5622,  5626,  5633,  5637,  5646,  5659,  5662,  5670,  5673,  5681,
    5689,  5697,  5701,  5709,  5712,  5720,  5732,  5735,  5743,  5755,
    5761,  5771,  5774,  5782,  5786,  5790,  5798,  5801,  5809,  5812,
    5820,  5824,  5828,  5832,  5836,  5844,  5852,  5864,  5876,  5880,
    5884,  5892,  5898,  5908,  5912,  5916,  5920,  5924,  5928,  5932,
    5936,  5944,  5948,  5952,  5956,  5964,  5970,  5980,  5990,  5994,
    6002,  6012,  6023,  6030,  6034,  6042,  6045,  6052,  6057,  6066,
    6076,  6079,  6086,  6090,  6098,  6107,  6114,  6124,  6128,  6135,
    6141,  6151,  6154,  6161,  6166,  6178,  6186,  6198,  6206,  6210,
    6218,  6222,  6226,  6234,  6242,  6246,  6250,  6254,  6262,  6270,
    6282,  6286,  6294,  6303,  6307,  6311,  6315,  6319,  6327,  6335,
    6339,  6343,  6351,  6355,  6363,  6367,  6375,  6383,  6389,  6397,
    6405,  6410,  6415,  6420,  6428,  6435,  6442,  6450,  6463,  6467,
    6468,  6481,  6482,  6483,  6484,  6485,  6486,  6487,  6488,  6489,
    6490,  6491,  6492,  6493,  6494,  6495,  6496,  6500,  6501,  6502,
    6503,  6504,  6505,  6506,  6507,  6508,  6509,  6510,  6511,  6512,
    6513,  6514,  6515,  6516,  6517,  6518,  6519,  6520,  6521,  6522,
    6523,  6524,  6525,  6526,  6527,  6528,  6529,  6530,  6531,  6532,
    6533,  6534,  6535,  6536,  6537,  6538,  6539,  6540,  6541,  6542,
    6543,  6544,  6545,  6546,  6547,  6548,  6549,  6550,  6551,  6552,
    6553,  6554,  6555,  6556,  6557,  6558,  6559,  6560,  6561,  6562,
    6563,  6564,  6565,  6566,  6567,  6568,  6569,  6570,  6571,  6572,
    6573,  6574,  6575,  6576,  6577,  6578,  6579,  6580,  6581,  6582,
    6583,  6584,  6585,  6586,  6587,  6588,  6589,  6590,  6591,  6592,
    6593,  6594,  6595,  6596,  6597,  6598,  6599,  6600,  6601,  6602,
    6603,  6604,  6605,  6606,  6607,  6608,  6609,  6610,  6611,  6612,
    6613,  6614,  6615,  6616,  6617,  6618,  6619,  6620,  6621,  6622,
    6623,  6624,  6625,  6626,  6627,  6628,  6629,  6630,  6631,  6632,
    6633,  6634,  6635,  6636,  6637,  6638,  6639,  6640,  6641,  6642,
    6643,  6644,  6645,  6646,  6647,  6648,  6649,  6650,  6651,  6652,
    6653,  6654,  6655,  6656,  6657,  6658,  6659,  6660,  6661,  6662,
    6663,  6664,  6665,  6666,  6667,  6668,  6669,  6670,  6671,  6672,
    6673,  6674,  6675,  6676,  6677,  6678,  6679,  6680,  6681,  6682,
    6683,  6684,  6685,  6686,  6687,  6688,  6689,  6690,  6691,  6692,
    6693,  6694,  6695,  6696,  6697,  6698,  6699,  6700,  6701,  6702,
    6703,  6708
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
     325,   326
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 14601;
  const int xquery_parser::yynnts_ = 319;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 591;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 327;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 581;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 16720 "/home/mbrantner/zorba/jbuild/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6712 "/home/mbrantner/zorba/jsandbox/src/compiler/parser/xquery_parser.y"


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

