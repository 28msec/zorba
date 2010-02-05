
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
#line 68 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"


#include "common/common.h"

#ifdef _WIN32
#pragma warning(disable: 4786)
#endif

#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/api/compilercb.h"
#include "store/api/update_consts.h"

#define SYMTAB( n ) driver.symtab.get( (off_t)n )
#define SYMTAB_PUT( s ) driver.symtab.put( s )
#define LOC( p ) driver.createQueryLoc( p )

using namespace std;

namespace zorba
{
namespace parser
{
  extern const char *the_tumbling, *the_sliding, *the_start, *the_end, *the_only_end, *the_ofor, *the_declare, *the_create;
}
}

#define YYDEBUG 1

using namespace zorba;



/* Line 311 of lalr1.cc  */
#line 77 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 824 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 949 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc  */
#line 106 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"

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
#line 175 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
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
#line 820 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 282 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 114: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 291 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 138: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 818 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 300 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 309 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 318 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 327 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 336 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "Prolog" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 345 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 354 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 363 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 372 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 381 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 390 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 845 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 399 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 845 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 408 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 417 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 426 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 435 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 444 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 453 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 462 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 471 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 480 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 489 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 498 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 507 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 516 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 525 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 534 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 543 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 552 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 561 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 570 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 579 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 588 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 845 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 597 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 606 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "DeclPropertyList" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 615 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "DeclProperty" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 624 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 633 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 642 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 651 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 660 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 669 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 678 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 687 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 845 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 696 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 705 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 714 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 723 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 732 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 741 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 750 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 759 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 768 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 777 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 786 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 795 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "FunctionDecl3" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 804 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 813 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FunctionDecl4" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 822 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 831 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 840 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 849 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 858 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 867 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 885 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 894 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 903 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 912 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 921 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 930 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 939 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 948 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 957 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 966 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 975 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 984 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 993 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1002 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1011 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1020 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1029 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1038 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1047 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1056 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1065 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1074 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1083 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1092 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1101 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1110 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1119 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1128 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1137 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1146 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1155 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1164 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1173 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1182 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1191 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1200 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1209 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1218 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1227 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1236 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1245 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1254 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1263 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1272 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1281 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1290 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1299 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1308 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1317 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1326 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1335 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1344 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1353 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1362 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1371 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1380 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1389 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1398 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1407 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1416 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1425 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1434 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1443 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1452 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1461 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1470 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1479 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1488 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1497 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1506 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1515 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1524 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1533 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1542 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1551 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1560 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1569 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1578 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1587 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1596 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1605 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1614 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1623 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1632 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1641 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1650 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1659 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1668 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1677 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1686 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1695 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1704 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1713 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1722 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1731 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1740 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1749 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1758 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1767 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1776 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1785 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1794 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1803 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1812 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1821 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1830 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1839 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1848 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1857 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1866 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1875 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1884 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1893 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1902 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1911 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1920 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1929 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1938 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1947 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1956 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1965 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1974 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1983 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1992 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2001 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2010 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2019 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2028 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2037 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2046 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2055 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2064 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2073 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2082 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2091 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2100 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2109 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2118 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2127 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2136 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2145 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2154 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2163 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2172 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2181 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 845 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2190 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2199 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2208 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2217 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2226 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2235 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2244 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2253 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2262 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2271 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2280 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2289 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2298 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2307 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2316 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2325 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2334 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2343 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2352 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2361 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2370 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2379 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2388 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2397 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2406 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2415 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2424 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2433 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2442 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2451 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2460 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2469 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2478 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2487 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2496 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2505 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2514 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2523 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2532 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2541 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2550 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
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
#line 119 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}

/* Line 553 of lalr1.cc  */
#line 2635 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"

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
#line 966 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 975 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 980 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            MainModule *mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
            mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 987 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 992 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            LibraryModule *lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
            lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1003 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            std::string encoding = "utf-8";
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), encoding );
        }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1008 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
        }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1016 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new MainModule(
                LOC((yyloc)),
                static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
                static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node))
            );
        }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1024 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
        }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1032 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LibraryModule(
                LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1038 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LibraryModule(
                LOC((yyloc)),
                static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
                static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1050 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
            dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
        }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1059 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog( LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)), NULL );
        }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1063 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog( LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)) );
        }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1067 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog(
                LOC((yyloc)),
                static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
                static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1079 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
            sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = sdl;
        }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1085 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( SIND_DeclList *sdl = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                sdl->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1095 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
            vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = vdl;
        }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1101 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( VFO_DeclList *vdl = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vdl->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 1132 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DecimalFormatNode( LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair) );
            delete (yysemantic_stack_[(4) - (4)].vstrpair);
        }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1137 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DecimalFormatNode(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr))->get_qname(), (yysemantic_stack_[(4) - (4)].vstrpair)
            );
            delete (yysemantic_stack_[(4) - (3)].expr);
            delete (yysemantic_stack_[(4) - (4)].vstrpair);
        }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1148 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.vstrpair) = new vector<string_pair_t>();
            (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
            delete (yysemantic_stack_[(1) - (1)].strpair);
        }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1154 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
            delete (yysemantic_stack_[(2) - (2)].strpair);
            (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
        }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1163 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
            (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval() );
            delete sl;
        }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1171 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1172 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1173 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1174 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1175 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1176 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1177 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1178 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1179 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1180 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1211 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
        }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1220 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::preserve_space
            );
        }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1226 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::strip_space
            );
        }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1236 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_element_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1242 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_function_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1252 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OptionDecl(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval))
            );
        }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1262 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOptionDecl( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1270 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::ordered
            );
        }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1276 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::unordered
            );
        }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1287 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_greatest);
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1292 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_least);
        }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1302 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1308 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1314 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1320 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1337 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
        }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1345 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1353 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
        }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1357 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                NULL
            );
        }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1366 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                NULL,
                SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1375 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1388 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            URILiteralList *ull = new URILiteralList( LOC((yyloc)));
            ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.node) = ull;
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1394 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
                ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1405 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1409 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
        }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1417 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleImport(
                LOC((yyloc)), false, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL
            );
            dynamic_cast<ModuleImport*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1424 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleImport(
                LOC((yyloc)), false, SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL
            );
            dynamic_cast<ModuleImport*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (2)].sval)) );
        }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1431 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleImport(
                LOC((yyloc)), false, SYMTAB((yysemantic_stack_[(5) - (3)].sval)), dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node))
            );
            dynamic_cast<ModuleImport*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(5) - (2)].sval)) );
        }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1438 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleImport(
                LOC((yyloc)), false, SYMTAB((yysemantic_stack_[(8) - (4)].sval)), SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node))
            );
            dynamic_cast<ModuleImport*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(8) - (2)].sval)) );
        }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1451 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
        }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1458 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
            d->type = (yysemantic_stack_[(3) - (2)].node);
            (yyval.node) = d;
        }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1464 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1471 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
            d->ext = false;
            (yyval.node) = d;
        }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1477 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), NULL );
        }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1481 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1488 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1499 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.varnametype) = new VarNameAndType(
                static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), NULL
            );
            delete (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1506 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.varnametype) = new VarNameAndType(
                static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
                dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node))
            );
            delete (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1517 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType*>((yysemantic_stack_[(5) - (3)].varnametype)));
            (yyval.node) = new VarDecl( LOC((yyloc)), nt->name, nt->type, (yysemantic_stack_[(5) - (5)].expr) );
            dynamic_cast<VarDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(5) - (1)].sval)) );
        }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1523 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType*>((yysemantic_stack_[(4) - (3)].varnametype)));
            (yyval.node) = new VarDecl( LOC((yyloc)), nt->name, nt->type, NULL, true );
            dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)) );
        }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1529 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType*>((yysemantic_stack_[(6) - (3)].varnametype)));
            (yyval.node) = new VarDecl( LOC((yyloc)), nt->name, nt->type, (yysemantic_stack_[(6) - (6)].expr), true );
            dynamic_cast<VarDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
        }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1538 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
            dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = dpl;
        }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1544 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
        dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
        (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1553 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1557 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1563 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1567 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1571 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1575 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1581 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1587 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1593 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1597 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1603 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1609 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1616 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              0,
                              0,
                              0);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1624 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              0,
                              static_cast<NodeModifier*>((yysemantic_stack_[(4) - (4)].node)),
                              0);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1632 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1640 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                              0,
                              static_cast<NodeModifier*>((yysemantic_stack_[(6) - (6)].node)),
                              static_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)));
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1648 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(4) - (2)].node)), 0, 0);
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1654 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(5) - (2)].node)),
                               static_cast<NodeModifier*>((yysemantic_stack_[(5) - (5)].node)),
                               0);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1662 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(6) - (2)].node)),
                               0,
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1670 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(7) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(7) - (2)].node)),
                               static_cast<NodeModifier*>((yysemantic_stack_[(7) - (7)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)));
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1681 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = static_cast<parsenode*>(
           new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1686 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = static_cast<parsenode*>(
           new SequenceType( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1694 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier( LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1698 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier( LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1705 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl( LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                         (yysemantic_stack_[(8) - (6)].expr),
                         dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                         new DeclPropertyList( LOC((yyloc))));
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1713 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl( LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                         (yysemantic_stack_[(9) - (7)].expr),
                         dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                         dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(9) - (2)].node)));
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1724 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList( LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1730 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1738 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec( LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<AtomicType*>((yysemantic_stack_[(3) - (3)].node)),
                            NULL);
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1745 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec( LOC((yyloc)),
                            (yysemantic_stack_[(4) - (1)].expr),
                            dynamic_cast<AtomicType*>((yysemantic_stack_[(4) - (3)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1756 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck( LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1766 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck( LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1776 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode( LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1787 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 137:

/* Line 678 of lalr1.cc  */
#line 1802 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_preserve
            );
        }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_strip
            );
        }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1819 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL );
        }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1823 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1827 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)) );
        }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1831 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig(
                dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1840 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( !(yysemantic_stack_[(4) - (2)].node) ) {
                (yyval.expr) = (yysemantic_stack_[(4) - (3)].expr);
            } else {
                BlockBody *bb = dynamic_cast<BlockBody*>((yysemantic_stack_[(4) - (3)].expr));
                VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (2)].node));
                if ( !bb ) {
                    bb = new BlockBody( (yysemantic_stack_[(4) - (3)].expr)->get_location(), vfo );
                    bb->add( (yysemantic_stack_[(4) - (3)].expr) );
                } else {
                    bb->set_decls( vfo );
                }
                (yyval.expr) = bb;
            }
        }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1866 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            std::auto_ptr<VFO_DeclList> vfo2( dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)) );
            if ( !(yysemantic_stack_[(3) - (1)].node) )
                vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back( *vfo2.get() );
            (yyval.node) = vfo;
        }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1875 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1882 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            vfo->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = vfo;
        }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1888 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back((yysemantic_stack_[(2) - (2)].node));
            (yyval.node) = vfo;
        }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1897 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType*>((yysemantic_stack_[(1) - (1)].varnametype)));
            VarDecl *vd = new VarDecl( LOC((yyloc)), nt->name, nt->type, NULL );
            vd->set_global( false );
            (yyval.node) = vd;
        }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1904 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType*>((yysemantic_stack_[(3) - (1)].varnametype)));
            VarDecl *vd = new VarDecl( LOC((yyloc)), nt->name, nt->type, (yysemantic_stack_[(3) - (3)].expr) );
            vd->set_global( false );
            (yyval.node) = vd;
        }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1914 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AssignExpr(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr))->get_qname(), (yysemantic_stack_[(5) - (5)].expr)
            );
            delete (yysemantic_stack_[(5) - (3)].expr);
        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1924 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExitExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1931 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody *>((yysemantic_stack_[(5) - (5)].expr));
            if ( !bb ) {
                bb = new BlockBody( (yysemantic_stack_[(5) - (5)].expr)->get_location() );
                bb->add((yysemantic_stack_[(5) - (5)].expr));
            }
            (yyval.expr) = new WhileExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), bb );
        }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1943 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::BREAK );
        }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1947 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
        }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1954 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            dynamic_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1959 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FunctionDecl *fd = dynamic_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));
            fd->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            fd->deterministic = false;
            (yyval.node) = fd;
        }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1966 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            dynamic_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node))->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
        }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1974 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1978 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1982 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FunctionDecl *fd = dynamic_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node));
            fd->type = fd->type == ParseConstants::fn_extern ?
                ParseConstants::fn_extern_update :
                ParseConstants::fn_update;
            (yyval.node) = fd;
        }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 1990 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 1997 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FunctionDecl(
                LOC((yyloc)),
                    static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                    &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
                    (yysemantic_stack_[(4) - (4)].expr),
                    ParseConstants::fn_read
                );
            delete (yysemantic_stack_[(4) - (3)].fnsig);
        }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2008 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FunctionDecl(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
                NULL,
                ParseConstants::fn_extern
            );
            delete (yysemantic_stack_[(4) - (3)].fnsig);
        }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2022 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FunctionDecl(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                &* (yysemantic_stack_[(6) - (3)].fnsig)->param, &* (yysemantic_stack_[(6) - (3)].fnsig)->ret,
                (yysemantic_stack_[(6) - (5)].expr),
                ParseConstants::fn_read
            );
            delete (yysemantic_stack_[(6) - (3)].fnsig);
        }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2033 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FunctionDecl(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
                NULL,
                ParseConstants::fn_extern
            );
            delete (yysemantic_stack_[(4) - (3)].fnsig);
        }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2047 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FunctionDecl(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
                (yysemantic_stack_[(4) - (4)].expr),
                ParseConstants::fn_sequential
            );
            delete (yysemantic_stack_[(4) - (3)].fnsig);
        }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2058 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FunctionDecl(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
                NULL,
                ParseConstants::fn_extern_sequential
            );
            delete (yysemantic_stack_[(4) - (3)].fnsig);
        }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2073 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            ParamList *pl = new ParamList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2079 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
                pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2089 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Param(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), NULL
            );
        delete (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2096 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Param(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
                dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node))
            );
            delete (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2109 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EnclosedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 2116 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 2124 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QueryBody( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 2139 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2143 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            std::auto_ptr<BlockBody> blk( dynamic_cast<BlockBody*>((yysemantic_stack_[(2) - (2)].expr)) );
            BlockBody *blk2 = new BlockBody( LOC((yyloc)) );
            blk2->add( (yysemantic_stack_[(2) - (1)].expr) );

            for ( int i = 0; i < blk->size(); ++i )
                blk2->add( (*blk)[i] );

            (yyval.expr) = blk2;
        }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 2157 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new BlockBody( LOC((yyloc)) );
        }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2161 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (1)].expr));
            bb->add( (yysemantic_stack_[(3) - (2)].expr) );
            (yyval.expr) = bb;
        }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2170 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2174 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            Expr *expr = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
            if ( !expr ) {
                expr = new Expr( LOC((yyloc)) );
                expr->push_back( (yysemantic_stack_[(3) - (1)].expr) );
            }
            expr->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.expr) = expr;
        }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 2214 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            ReturnExpr *re = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
            (yyval.expr) = new FLWORExpr(
                LOC((yyloc)),
                dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)),
                re->get_return_val(),
                re->get_location(),
                driver.theCompilerCB->theConfig.force_gflwor
            );
            delete (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 2229 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2236 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_sliding;
        }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2240 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_tumbling;
        }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2247 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_start;
        }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2251 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_end;
        }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2255 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_only_end;
        }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2262 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)),
                dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr),
                (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 2270 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr),
                (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 2280 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new WindowClause(
                LOC((yyloc)),
                ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ?
                    WindowClause::tumbling_window :
                    WindowClause::sliding_window,
                dynamic_cast<WindowVarDecl*>((yysemantic_stack_[(5) - (3)].node)),
                dynamic_cast<FLWORWinCond*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FLWORWinCond*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 2292 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new WindowClause(
                LOC((yyloc)),
                ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ?
                    WindowClause::tumbling_window :
                    WindowClause::sliding_window,
                dynamic_cast<WindowVarDecl*>((yysemantic_stack_[(4) - (3)].node)),
                dynamic_cast<FLWORWinCond*>((yysemantic_stack_[(4) - (4)].node)),
                NULL
            );
        }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 2307 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CountClause(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname()
            );
            delete (yysemantic_stack_[(3) - (3)].expr);
        }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 2331 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 2337 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2346 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = NULL;
        }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 2350 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_ofor;
        }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2358 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForClause(
                LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL
            );
        }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2368 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
            vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vdl;
        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2374 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2384 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VarInDecl(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr)
            );
            delete (yysemantic_stack_[(3) - (1)].expr);
        }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2392 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VarInDecl(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
                dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                NULL, NULL,
                (yysemantic_stack_[(4) - (4)].expr)
            );
            delete (yysemantic_stack_[(4) - (1)].expr);
        }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2403 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VarInDecl(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
                NULL,
                dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
                NULL,
                (yysemantic_stack_[(4) - (4)].expr)
            );
            delete (yysemantic_stack_[(4) - (1)].expr);
        }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 2415 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VarInDecl(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr))->get_qname(),
                dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
                NULL,
                (yysemantic_stack_[(5) - (5)].expr)
            );
            delete (yysemantic_stack_[(5) - (1)].expr);
        }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2428 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VarInDecl(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
                NULL, NULL,
                dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                (yysemantic_stack_[(4) - (4)].expr)
            );
            delete (yysemantic_stack_[(4) - (1)].expr);
        }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 2439 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VarInDecl(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr))->get_qname(),
                dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                NULL,
                dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        delete (yysemantic_stack_[(5) - (1)].expr);
        }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2451 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VarInDecl(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr))->get_qname(),
                NULL,
                dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
                dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        delete (yysemantic_stack_[(5) - (1)].expr);
        }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2463 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VarInDecl(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr))->get_qname(),
                dynamic_cast<SequenceType*>((yysemantic_stack_[(6) - (2)].node)),
                dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
                dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                (yysemantic_stack_[(6) - (6)].expr)
            );
            delete (yysemantic_stack_[(6) - (1)].expr);
        }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2479 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PositionalVar(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname()
            );
            delete (yysemantic_stack_[(3) - (3)].expr);
        }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2490 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScoreVar(
                LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname()
            );
            delete (yysemantic_stack_[(3) - (3)].expr);
        }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2501 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2509 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2515 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2524 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2530 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2540 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VarGetsDecl(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
                NULL,
                NULL,
                (yysemantic_stack_[(3) - (3)].expr)
            );
            delete (yysemantic_stack_[(3) - (1)].expr);
        }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2551 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VarGetsDecl(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
                dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                NULL,
                (yysemantic_stack_[(4) - (4)].expr)
            );
            delete (yysemantic_stack_[(4) - (1)].expr);
        }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2563 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VarGetsDecl(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
                NULL,
                dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                (yysemantic_stack_[(4) - (4)].expr)
            );
            delete (yysemantic_stack_[(4) - (1)].expr);
        }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2574 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VarGetsDecl(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr))->get_qname(),
                dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
            delete (yysemantic_stack_[(5) - (1)].expr);
        }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2588 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new WindowVarDecl(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr))->get_qname(), NULL, (yysemantic_stack_[(4) - (4)].expr)
            );
            delete (yysemantic_stack_[(4) - (2)].expr);
        }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2595 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new WindowVarDecl(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr))->get_qname(),
                dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
            delete (yysemantic_stack_[(5) - (2)].expr);
        }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2609 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new WindowVars(
                LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), "", ""
            );
            delete (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2616 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            WindowVars *wv = dynamic_cast<WindowVars*>((yysemantic_stack_[(3) - (3)].node));
            wv->set_curr( static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname() );
            (yyval.node) = wv;
            delete (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2626 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new WindowVars(
                LOC((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", ""
            );
        }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2632 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            PositionalVar *pv = dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node));
            WindowVars *wv = dynamic_cast<WindowVars*>((yysemantic_stack_[(2) - (2)].node));
            wv->set_posvar( pv );
            (yyval.node) = wv;
        }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2643 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new WindowVars(
                LOC((yyloc)),
                NULL, "",
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr))->get_qname(),
                static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr))->get_qname()
            );
            delete (yysemantic_stack_[(6) - (3)].expr);
            delete (yysemantic_stack_[(6) - (6)].expr);
        }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2654 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new WindowVars(
                LOC((yyloc)), NULL, "", "",
                static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname()
            );
        delete (yysemantic_stack_[(3) - (3)].expr);
        }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2662 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new WindowVars(
                LOC((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname(), ""
            );
            delete (yysemantic_stack_[(3) - (3)].expr);
        }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2672 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            std::string name = static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))->get_qname();
            (yyval.node) = new VarGetsDecl(
                LOC((yyloc)),
                name, NULL, NULL,
                new VarRef( LOC((yyloc)), name ),
                VarGetsDecl::eval_var
            );
            delete (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2687 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new WhereClause( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2694 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupByClause( LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2701 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2707 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2717 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupSpec(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), NULL
            );
            delete (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2724 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupSpec(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
                dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
            delete (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2736 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2744 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2750 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2760 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2766 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2776 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2780 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2790 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2796 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2802 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2817 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2826 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2835 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2848 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2852 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2860 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2866 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2876 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2884 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2893 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2906 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
            qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qvidl;

        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2913 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2924 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QVarInDecl(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(), (yysemantic_stack_[(3) - (3)].expr)
            );
            delete (yysemantic_stack_[(3) - (1)].expr);
        }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2931 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QVarInDecl(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
                dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                (yysemantic_stack_[(4) - (4)].expr)
            );
            delete (yysemantic_stack_[(4) - (1)].expr);
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2945 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TypeswitchExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(8) - (3)].expr),
                dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                (yysemantic_stack_[(8) - (8)].expr)
            );
        }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2954 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TypeswitchExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(10) - (3)].expr),
                dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname(),
                (yysemantic_stack_[(10) - (10)].expr)
            );
            delete (yysemantic_stack_[(10) - (8)].expr);
        }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2969 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CaseClauseList *ccl = new CaseClauseList( LOC((yyloc)));
            ccl->push_back( dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = ccl;
        }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2975 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CaseClauseList *ccl = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
            ccl->push_back( dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2986 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CaseClause(
                LOC((yyloc)), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 2992 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CaseClause(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr))->get_qname(),
                dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                (yysemantic_stack_[(7) - (7)].expr)
            );
            delete (yysemantic_stack_[(7) - (3)].expr);
        }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 3007 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IfExpr( LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr) );
        }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3016 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3020 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3028 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3032 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3040 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3044 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 301:

/* Line 678 of lalr1.cc  */
#line 3054 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3061 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3070 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3079 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3084 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3093 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3102 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3111 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3124 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3128 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3139 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3143 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3151 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3155 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3164 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3168 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3172 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3181 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3185 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3191 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3197 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3203 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3214 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3218 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3222 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3230 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3234 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3240 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3250 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3254 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3264 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3268 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3278 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3282 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3292 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3296 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3306 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3310 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3318 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3322 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3326 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3330 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3340 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3344 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3348 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3356 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3360 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3364 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3368 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3372 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3376 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3384 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3388 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3392 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3400 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3404 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3408 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3412 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3422 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3428 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3438 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3444 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3454 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3458 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3496 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL
            );
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3502 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3508 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3514 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = !rpe ?
                (yysemantic_stack_[(1) - (1)].expr) : new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3525 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NULL;
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3533 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            AxisStep *as = dynamic_cast<AxisStep*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = as ?
                new RelativePathExpr(
                    LOC((yyloc)), ParseConstants::st_slash,
                    new ContextItemExpr( LOC((yyloc)), true ), (yysemantic_stack_[(1) - (1)].expr)
                )
            :
                (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3544 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3550 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3560 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3564 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3572 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3578 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3586 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3592 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3604 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3610 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3620 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3624 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3628 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3632 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3636 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3642 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3648 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3656 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3660 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3668 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3672 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3683 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3687 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3691 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3697 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3701 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3715 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3719 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3727 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3731 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3739 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Wildcard( LOC((yyloc)), "", "", ParseConstants::wild_all );
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3743 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Wildcard(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem
            );
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3749 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Wildcard(
                LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix
            );
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3759 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3763 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FilterExpr(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3773 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3779 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3789 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3797 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3801 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3805 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3809 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3813 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3817 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3821 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3825 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3833 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3837 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3845 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3852 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3859 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3870 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname() );
            delete (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3879 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3883 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3891 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3899 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3907 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3961 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 3965 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 3977 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 3983 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 3993 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 3997 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4005 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4009 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4013 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4021 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 438:

/* Line 678 of lalr1.cc  */
#line 4031 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 439:

/* Line 678 of lalr1.cc  */
#line 4041 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 440:

/* Line 678 of lalr1.cc  */
#line 4051 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 441:

/* Line 678 of lalr1.cc  */
#line 4061 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 442:

/* Line 678 of lalr1.cc  */
#line 4071 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 443:

/* Line 678 of lalr1.cc  */
#line 4086 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4092 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4103 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4109 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4120 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4137 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4142 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4151 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4155 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4162 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back(
                new QuoteAttrValueContent( LOC((yyloc)),std::string("\"") )
            );
            (yyval.node) = qacl;
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4170 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4176 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back(
                    new QuoteAttrValueContent( LOC((yyloc)),std::string("\"") )
                );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4186 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4198 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4202 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4209 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4215 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4221 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4228 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4239 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4243 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4253 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4257 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4267 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4271 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4275 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4280 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4289 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4295 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4301 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4307 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4317 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4321 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4333 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4337 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4349 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4361 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4365 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4369 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4373 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4377 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4381 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4389 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4397 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL
            );
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4403 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr)
            );
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4409 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4413 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4430 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (2)].expr), NULL );
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4434 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4438 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4442 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4450 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4458 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4466 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), NULL );
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4470 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (2)].sval)), (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4474 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4478 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4486 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4492 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4502 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4510 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4514 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4520 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4555 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4561 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4567 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4577 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4581 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4585 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4593 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4601 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4605 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4609 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4613 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4617 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4621 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4625 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4629 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4633 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4641 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4649 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4653 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4657 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4667 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4675 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4683 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4687 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4691 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4699 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4703 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4709 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4715 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4719 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4729 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4737 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4741 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4747 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4756 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4765 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4771 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4777 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4787 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4804 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4811 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4826 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4863 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4869 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4875 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4885 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4889 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4895 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4901 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4905 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4911 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4915 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4921 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4927 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 4934 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 4944 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 4949 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 4957 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 4963 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 4973 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 4993 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
            (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5002 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CopyVarList *cvl = new CopyVarList( LOC((yyloc)) );
            cvl->push_back( dynamic_cast<VarBinding*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cvl;
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5008 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
            VarBinding *vb = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
            cvl->push_back( vb );
            (yyval.expr) = cvl;
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5019 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarBinding(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(), (yysemantic_stack_[(3) - (3)].expr)
            );
            delete (yysemantic_stack_[(3) - (1)].expr);
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5036 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5043 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5049 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5059 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CatchExpr( LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr) );
            delete (yysemantic_stack_[(3) - (2)].name_test_list);
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5064 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CatchExpr(
                LOC((yyloc)), *(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr))->get_qname(), (yysemantic_stack_[(7) - (7)].expr)
            );
            delete (yysemantic_stack_[(7) - (5)].expr);
            delete (yysemantic_stack_[(7) - (2)].name_test_list);
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5072 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CatchExpr(
                LOC((yyloc)), *(yysemantic_stack_[(10) - (2)].name_test_list),
                static_cast<QName*>((yysemantic_stack_[(10) - (5)].expr))->get_qname(),
                static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname(),
                (yysemantic_stack_[(10) - (10)].expr)
            );
            delete (yysemantic_stack_[(10) - (5)].expr);
            delete (yysemantic_stack_[(10) - (8)].expr);
            delete (yysemantic_stack_[(10) - (2)].name_test_list);
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5084 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CatchExpr(
                LOC((yyloc)), *(yysemantic_stack_[(13) - (2)].name_test_list),
                static_cast<QName*>((yysemantic_stack_[(13) - (5)].expr))->get_qname(),
                static_cast<QName*>((yysemantic_stack_[(13) - (8)].expr))->get_qname(),
                static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr))->get_qname(),
                (yysemantic_stack_[(13) - (13)].expr)
            );
            delete (yysemantic_stack_[(13) - (5)].expr);
            delete (yysemantic_stack_[(13) - (8)].expr);
            delete (yysemantic_stack_[(13) - (11)].expr);
            delete (yysemantic_stack_[(13) - (2)].name_test_list);
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5101 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5107 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5128 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            std::auto_ptr<QName> lQName( static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
            std::string tmp = lQName->get_qname();
            if ( tmp.find (':') != std::string::npos ) {
                error((yylocation_stack_[(1) - (1)]), "A NCName is expected, found a QName");
                YYERROR;
            }
            (yyval.sval) = SYMTAB_PUT(tmp.c_str());
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5146 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5150 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5163 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EvalExpr(
                LOC((yyloc)), dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)), (yysemantic_stack_[(7) - (6)].expr)
            );
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5169 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EvalExpr( LOC((yyloc)), new VarGetsDeclList( LOC((yyloc)) ), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5175 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("xquery"); }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5176 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("empty"); }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5177 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("attribute"); }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5178 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("comment"); }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5179 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("document-node"); }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5180 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("element"); }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5181 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("item"); }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5182 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("if"); }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5183 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("node"); }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5184 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("processing-instruction"); }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5185 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema-attribute"); }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5186 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema-element"); }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5187 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("text"); }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5188 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("typeswitch"); }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5189 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("empty-sequence"); }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5190 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("boundary-space"); }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5191 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ft-option"); }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5192 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("base-uri"); }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5193 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lax"); }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5194 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("strict"); }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5195 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("idiv"); }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5196 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("document"); }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5197 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("not"); }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5198 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sensitive"); }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5199 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("insensitive"); }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5200 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("diacritics"); }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5201 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("without"); }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5202 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stemming"); }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5203 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("thesaurus"); }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5204 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stop"); }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5205 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("wildcards"); }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5206 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("entire"); }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5207 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("content"); }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5208 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("word"); }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5209 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("start"); }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5210 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("end"); }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5211 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("most"); }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5212 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("skip"); }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5213 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("copy"); }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5214 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("value"); }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5215 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("eq"); }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5216 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ne"); }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5217 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lt"); }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5218 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("le"); }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5219 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("gt"); }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5220 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ge"); }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5221 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("at"); }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5222 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("context"); }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5223 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("variable"); }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5224 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("return"); }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5225 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("for"); }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5226 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("outer"); }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5227 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sliding"); }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5228 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("tumbling"); }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5229 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("previous"); }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5230 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("next"); }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5231 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("only"); }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5232 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("when"); }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5233 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("count"); }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5234 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("in"); }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5235 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("let"); }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5236 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("where"); }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5237 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("by"); }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5238 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("group"); }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5239 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("order"); }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5240 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stable"); }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5241 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ascending"); }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5242 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("descending"); }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5243 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("greatest"); }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5244 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("least"); }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5245 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("collation"); }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5246 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("some"); }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5247 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("every"); }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5248 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("satisfies"); }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5249 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("case"); }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5250 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("as"); }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5251 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("then"); }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5252 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("else"); }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5253 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("or"); }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5254 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("and"); }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5255 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("instance"); }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5256 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("of"); }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5257 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("castable"); }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5258 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("to"); }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5259 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("div"); }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5260 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("mod"); }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5261 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("union"); }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5262 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("intersect"); }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5263 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("except"); }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5264 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("validate"); }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5265 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("cast"); }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5266 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("treat"); }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5267 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("is"); }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5268 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("preserve"); }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5269 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("strip"); }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5270 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("namespace"); }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5271 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("external"); }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5272 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("encoding"); }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5273 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("no-preserve"); }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5274 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("inherit"); }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5275 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("no-inherit"); }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5276 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("declare"); }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5277 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("construction"); }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5278 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ordering"); }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5279 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("default"); }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5280 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("copy-namespaces"); }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5281 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("option"); }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5282 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("version"); }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5283 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("import"); }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5284 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema"); }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5285 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("module"); }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5286 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("function"); }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5287 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("score"); }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5288 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ftcontains"); }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5289 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("weight"); }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5290 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("window"); }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5291 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("distance"); }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5292 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("occurs"); }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5293 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("times"); }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5294 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("same"); }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5295 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("different"); }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5296 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lowercase"); }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5297 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("uppercase"); }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 5298 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("relationship"); }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 5299 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("levels"); }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 5300 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("language"); }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 5301 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("any"); }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 5302 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("all"); }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 5303 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("phrase"); }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 5304 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("exactly"); }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 5305 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("from"); }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 5306 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("words"); }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 5307 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sentences"); }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 5308 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sentence"); }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 5309 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("paragraph"); }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 5310 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("replace"); }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 5311 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("modify"); }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 5312 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("first"); }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 5313 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("insert"); }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 5314 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("before"); }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 5315 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("after"); }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 5316 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("revalidation"); }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 5317 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("with"); }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 5318 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("nodes"); }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 5319 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("rename"); }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 5320 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("last"); }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 5321 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("delete"); }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 5322 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("into"); }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 5323 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("simple"); }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 5324 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sequential"); }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 5325 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("updating"); }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 5326 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("deterministic"); }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 5327 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("nondeterministic"); }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 5328 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ordered"); }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 5329 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("unordered"); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 5330 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("returning"); }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 5331 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("block"); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 5332 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("exit"); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 5333 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("loop"); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 5334 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("while"); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 5335 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("break"); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 5336 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("continue"); }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 5337 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("try"); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 5338 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("catch"); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 5339 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("eval"); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 5340 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("using"); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 5341 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("set"); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 5342 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("index"); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 5343 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("unique"); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 5344 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("non"); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 5345 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("on"); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 5346 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("range"); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 5347 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("equality"); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 5348 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("manually"); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 5349 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("automatically"); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 5350 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("maintained"); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 5351 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("decimal-format"); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 5352 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("decimal-separator"); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 5353 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("grouping-separator"); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 5354 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("infinity"); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 5355 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("minus-sign"); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 5356 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("NaN"); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 5357 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("percent"); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 5358 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("per-mille"); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 5359 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("zero-digit"); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 5360 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("digit"); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 5361 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("pattern-separator"); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 5362 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("collection"); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 5363 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("const"); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 5364 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("append-only"); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 5365 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("queue"); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 5366 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("mutable"); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 5367 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("read-only"); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 5368 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("integrity"); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 5369 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("constraint"); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 5370 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("check"); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 5371 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("key"); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 5372 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("foreach"); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 5373 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("foreign"); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 5374 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("keys"); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 5387 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), dynamic_cast<FTOr*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 5395 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 5399 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 5406 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 5411 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 5420 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 5424 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr(
                LOC((yyloc)), dynamic_cast<FTOr*>((yysemantic_stack_[(3) - (1)].node)), dynamic_cast<FTAnd*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 5434 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 5438 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd(
                LOC((yyloc)), dynamic_cast<FTAnd*>((yysemantic_stack_[(3) - (1)].node)), dynamic_cast<FTMildNot*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 5448 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 5452 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot(
                LOC((yyloc)),
                dynamic_cast<FTMildNot*>((yysemantic_stack_[(4) - (1)].node)), dynamic_cast<FTUnaryNot*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 5463 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 5467 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 5477 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 5489 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 5493 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 5500 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 5504 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 5512 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<RangeExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
        }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 5520 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimary(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 5528 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 5532 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 5539 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 5543 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 5551 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 5559 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 5571 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 5577 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue( LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr)) );
        }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 5584 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ParseConstants::ft_opt_any );
        }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 5588 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 5596 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_option) );
        }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 5600 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_option) );
        }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 5604 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ParseConstants::ft_opt_phrase );
        }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 5611 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_option) = ParseConstants::ft_opt_any;
        }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 5615 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_option) = ParseConstants::ft_opt_any_word;
        }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 5622 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_option) = ParseConstants::ft_opt_all;
        }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 5626 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_option) = ParseConstants::ft_opt_all_words;
        }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 5634 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 5638 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 5642 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 5646 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 5650 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 5658 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 5666 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<UnionExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 5678 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 5690 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ParseConstants::ft_unit_words );
        }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 5694 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ParseConstants::ft_unit_sentences );
        }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 5698 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ParseConstants::ft_unit_paragraphs );
        }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 5706 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 5712 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(2) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 5722 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 5726 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 5730 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 5734 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 5738 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 5742 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 5746 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 5750 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 5758 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption(
                LOC((yyloc)), ParseConstants::ft_case_sensitive
            );
        }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 5764 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption(
                LOC((yyloc)), ParseConstants::ft_case_insensitive
            );
        }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 5770 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ParseConstants::ft_case_lower );
        }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 5774 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ParseConstants::ft_case_upper );
        }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 5782 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ParseConstants::ft_diacritics_senstive
            );
        }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 5788 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ParseConstants::ft_diacritics_insensitive
            );
        }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 5798 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 5808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption(
                LOC((yyloc)), ParseConstants::ft_stemmode_with
            );
        }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 5814 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption(
                LOC((yyloc)), ParseConstants::ft_stemmode_without
            );
        }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 5824 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FTThesaurusOption::thesaurus_id_list_t *til = NULL;
            if ( (yysemantic_stack_[(3) - (3)].node) ) {
                til = new FTThesaurusOption::thesaurus_id_list_t;
                til->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            }
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), til, !til );
            delete til;
        }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 5834 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FTThesaurusOption::thesaurus_id_list_t *til = (yysemantic_stack_[(6) - (5)].thesaurus_id_list);
            if ( (yysemantic_stack_[(6) - (4)].node) ) {
                if ( !til )
                    til = new FTThesaurusOption::thesaurus_id_list_t;
                til->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(6) - (4)].node)) );
            }
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), til, !(yysemantic_stack_[(6) - (4)].node) );
            delete til;
        }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 5845 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 5852 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 5856 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 5863 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 5867 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(1) - (1)].thesaurus_id_list);
        }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 5874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 5879 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 5888 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 5897 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 5901 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 5908 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 5912 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 5920 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(5) - (4)].node)), (yysemantic_stack_[(5) - (5)].incl_excl_list),
                ParseConstants::ft_stop_words_with
            );
            delete (yysemantic_stack_[(5) - (5)].incl_excl_list);
        }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 5929 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(5) - (5)].incl_excl_list), ParseConstants::ft_stop_words_with_default
            );
            delete (yysemantic_stack_[(5) - (5)].incl_excl_list);
        }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 5936 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ParseConstants::ft_stop_words_without
            );
        }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 5946 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 5950 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 5957 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 5963 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 5972 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 5976 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 5983 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 5988 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6000 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ParseConstants::ft_stop_words_union
            );
        }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6008 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ParseConstants::ft_stop_words_except
            );
        }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6020 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6028 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), true );
        }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6032 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), false );
        }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6040 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent(
                LOC((yyloc)), ParseConstants::ft_contentmode_at_start
            );
        }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6046 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent(
                LOC((yyloc)), ParseConstants::ft_contentmode_at_end
            );
        }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6052 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent(
                LOC((yyloc)), ParseConstants::ft_contentmode_entire
            );
        }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6062 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6070 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6074 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6078 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6082 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6090 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ParseConstants::ft_scope_same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6098 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ParseConstants::ft_scope_different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6110 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ParseConstants::ft_bigunit_sentence );
        }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6114 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ParseConstants::ft_bigunit_paragraph );
        }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6122 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;



/* Line 678 of lalr1.cc  */
#line 10978 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1272;
  const short int
  xquery_parser::yypact_[] =
  {
      1489, -1272, -1272, -1272, -1272,   905,   102,   116,   -45,  8376,
      26,   461,   468, -1272, -1272, -1272, -1272, -1272, -1272,    -1,
     346,  7246, -1272,   178, -1272, -1272, -1272, -1272,   204,   233,
   -1272,   118,   294,   341, -1272, -1272, -1272, -1272, -1272, -1272,
   -1272, -1272, -1272,   370,   396, -1272, -1272, -1272, -1272, -1272,
   -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272,
   -1272, -1272, -1272, -1272, -1272, -1272,  8656, -1272,  6674, -1272,
   -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272,
   -1272, -1272, 10336, -1272, -1272, -1272, -1272, -1272, -1272, -1272,
   -1272,   464, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272,
   -1272, -1272, -1272,  1778, 10336, -1272, -1272, -1272, -1272, -1272,
   -1272, -1272,   453, -1272, -1272, -1272,  7814, -1272,  8096, -1272,
   -1272, -1272, -1272, -1272, 10336, -1272, -1272,  6386, -1272, -1272,
   -1272, -1272, -1272, -1272,   475, -1272, -1272, -1272, -1272, -1272,
   -1272, -1272, -1272,    41,   416, -1272, -1272, -1272, -1272, -1272,
   -1272, -1272, -1272,   425,   491,   426, -1272,   437,   325, -1272,
   -1272, -1272, -1272, -1272, -1272,   557, -1272,   528,   446,   450,
     452, -1272, -1272,   541,   548, -1272,   586, -1272, -1272, -1272,
   -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272,
   -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272,
   -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272,
   -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272,
   -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272,
   -1272, -1272, -1272, -1272, -1272,  4370,   702, -1272,  4658, -1272,
   -1272,   333,  4946,   525,   530, -1272, -1272, -1272, -1272, -1272,
   -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272,
   -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272,
   -1272, -1272, -1272, -1272, -1272, -1272,   -30, -1272, -1272, -1272,
   -1272,   371, 10336, -1272, -1272, -1272, -1272, -1272,   554,   627,
   -1272,   619,   467,   132,   186,   378,   417, -1272,   644,   529,
     623,   624,  5234, -1272, -1272, -1272,   205, -1272, -1272,  6386,
   -1272,   403, -1272,   576,  6674, -1272,   576,  6674, -1272, -1272,
   -1272, -1272,   576, -1272, -1272, -1272, -1272, -1272, -1272, -1272,
   -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272,
   -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272,
   -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272,
   -1272,   575, -1272, -1272, 10336,   687,   690,   580,   580,   691,
   10336,   179,   -62,   706,   -49,   261, 10336,   587,   620,    83,
    7814, -1272, -1272,   343,   364,     6, 10336, -1272, -1272, -1272,
   -1272, -1272,   451, 10336,   448,   449,   445,   415, -1272, -1272,
   -1272,  7814, 10336,  4946,   596,   600,  4946, -1272, -1272, -1272,
   -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272,
   -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272,  4946,  8936,
   -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272,
   -1272, -1272, -1272, -1272, -1272, -1272,   601,  4946,  4946,   569,
    4946,   570,  4946,    43,    46, -1272,  4946,  7530,   605, -1272,
   10336, 10336, 10336,  4946,   478,   480, -1272,   638,   645, 10336,
      61,  4946,  9216,   612,   611,   613,   615,   616,   617, -1272,
   -1272, -1272, 10336, -1272,   582,   737,  4946,    31, -1272,   751,
     592, -1272,  4946,   566, -1272,   749,  4946,  4946,   599,  4946,
    4946,  4946,  4946,   551, 10336, -1272, -1272, -1272, -1272,  4946,
    4946,  4946, 10336, -1272, -1272, -1272, -1272,   905,   346, -1272,
   -1272,   333,   750,  4946, -1272,  4946,   621,   233,   294,   341,
     666,   618,   622,  4946,  4946, -1272, -1272, -1272, -1272, -1272,
   -1272, -1272,   680, -1272,    -5,  5522,  5522,  5522, -1272,  5522,
    5522, -1272,  5522, -1272,  5522, -1272, -1272, -1272, -1272, -1272,
   -1272, -1272,  5522,  5522,    34,  5522,  5522,  5522,  5522,  5522,
    5522,  5522,  5522,  5522,  5522,  5522,   560,   696,   697,   698,
   -1272, -1272, -1272,  2066, -1272, -1272,  6386,  6386,  4946,   576,
   -1272, -1272,   576, -1272,   576,  2354,   640, 10336, -1272, 10336,
   -1272, -1272, -1272, -1272,   767, -1272, -1272, -1272, -1272, -1272,
   -1272,   689,   694, -1272, -1272,   550,   303, 10336,   505,   646,
     647,   550,   706,   681,   675, -1272, -1272, -1272, -1272, -1272,
   10336,   187,    73,   234,   779, -1272, -1272,   326,     6, -1272,
   -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272,   -41, -1272,
     512, -1272, -1272, 10336, 10336, 10336, -1272,   679,   660, -1272,
     631,  4946,  4946,   629,   635, -1272,   -12,     0,  2642,   636,
     637, -1272,   652, -1272,   641,  7814,   729,   789,  7814,   706,
     738,   653,   654, -1272,   655,  2930,   -11, -1272,     4,   695,
     732, -1272,   -35,   656, -1272, -1272, 10336,   -20, -1272,   657,
     611,   370, -1272,   658,   659,   663, -1272,     9,    12,  3218,
     -10, -1272, 10336,   737, -1272,   -46,   664, -1272, -1272, -1272,
   -1272,   665, -1272,   181, -1272, -1272, -1272,    78,   130,   752,
     614,   625,    30, -1272,   709,  5810, -1272,   667,   671,    81,
   -1272, -1272,   669, -1272,   228, -1272, -1272,   -27,   685, 10336,
    4946,   735, -1272, -1272,   736,  9776,   739,  4946,   740,   -71,
     715,    -6,   627, -1272, -1272, -1272, -1272, -1272,  5522, -1272,
   -1272, -1272,  4946,    34,   385,   688, -1272,   578,   -44,   607,
     606, -1272, -1272,     6, -1272,   602,   237,   186,   186,   268,
     378,   378,   378,   378,   417,   417, -1272, -1272,  9776,  9776,
   10336, 10336, -1272,   684, -1272, -1272,   686, -1272, -1272, -1272,
      13,   -34,   316,   640,   640, -1272,   348,   355, -1272, -1272,
   -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272,   550, -1272,
     741, 10056,   725,  4946, -1272, -1272, -1272,   774,   730,  4946,
     706,   706,   550, -1272,   537,   706,   841, -1272, -1272,   597,
   -1272,   590,   274, -1272, -1272, -1272, -1272, -1272,   591, -1272,
   -1272, -1272,    38,   380, -1272,   661,   290,   -22,   583,   706,
    4946, -1272,   700,   701,   776,   728, 10336, -1272, 10336, -1272,
   -1272,   703, -1272, -1272, -1272,   692,   754,   706,   731,   757,
     786,   706,   742, -1272, -1272, -1272,   710,   771,  4946,  4946,
     747,  4946,   775,  4946,   755,   -72, -1272,     7,   643, -1272,
   -1272,   379,   -20, -1272, -1272, -1272,   746, 10336, -1272, 10336,
   -1272, -1272,   717,  4946,   863, -1272,   -15, -1272,    47, -1272,
   -1272,   871, -1272,   267,  4946,  4946,  4946,   429,  4946,  4946,
    4946,  4946,  4946,  4946,   782,  4946,  4946,   620,   -21,   721,
     528,   662,   753,   784,   750,   825, -1272,  4946, -1272,   483,
     799, -1272, 10336,   800, -1272, 10336,   756,   760, -1272,   247,
   -1272, -1272, -1272, 10336, -1272, 10336,  4946,   764,  4946,  4946,
     -61,   766, -1272,   743,   734, -1272,   668, -1272, -1272,   -88,
   -1272,   332,   -40,   672,    34,   332,  5522, -1272,    62, -1272,
   -1272, -1272, -1272, -1272, -1272,    34,   777,   648,     6,   -40,
   -1272, -1272,   639,   869, -1272, -1272, -1272, -1272, -1272, -1272,
     783, -1272, -1272, -1272,  4946, -1272, 10336,   832,    70, -1272,
   -1272,  4946, -1272,   328,   398, -1272, -1272, -1272, -1272, -1272,
     900,   506, -1272, -1272, -1272,  4946, -1272, -1272, -1272, -1272,
   -1272, -1272, -1272,   649,    14,   901, -1272,   447, -1272, -1272,
   -1272,   613,   615,   616,   396,   617,   491,   699,   247,   707,
     718,  6098,   670,   628,    38, -1272,   719,   758,   759, -1272,
   -1272,  9496,   444, -1272,  3506,   761,   763,   811,   772,   773,
   -1272,  4946,   706,   850, -1272, -1272, -1272,   706,   850,  3794,
   -1272, 10336, -1272, -1272,  4946, -1272, 10336, -1272,  4946,  4946,
     818,  4946,   816, -1272,   848,   849,  4946, 10336,   604,   899,
   -1272, -1272, -1272,  4082,   787,   788, -1272, -1272, -1272,   839,
   -1272,   129, -1272, -1272,   959, -1272, -1272,  4946, 10336, -1272,
   -1272,   174, -1272, -1272, -1272,   791,   745,   762, -1272, -1272,
   -1272,   765,   768, -1272, -1272, -1272, -1272, -1272,   748, 10336,
     797, -1272,   845, -1272,   620, -1272, -1272, -1272,  6962,   662,
   -1272,  4946, 10336,   799, -1272,   706, -1272,   546, -1272,    18,
     875, -1272,  4946,   880,   735, -1272,   804,   805, -1272, -1272,
   -1272, -1272, -1272, -1272, -1272,  4946, -1272, -1272,  4946,   846,
    4946, -1272, -1272,  5522, -1272, -1272, -1272, -1272, -1272,   153,
    5522,  5522,   152, -1272,   607, -1272,   219, -1272,   606,    34,
    5522, -1272, -1272,   714, -1272, -1272, -1272, -1272, -1272, -1272,
     774,  9776,   876,   902,   813, -1272,  4946, -1272, -1272, -1272,
   -1272, -1272,    19,   969,   971,    19,   733,   904, -1272, -1272,
   -1272, -1272,   835, 10336,   769,   699,  6098, -1272, -1272, 10336,
     822,   191, -1272, -1272,   826, -1272, -1272, -1272, -1272, -1272,
     884,   913,   706,   850, -1272,   830, -1272, -1272, -1272, -1272,
   -1272,  4946, -1272,  4946, 10336, 10336, -1272,   410, -1272,  4946,
   -1272,   831, -1272, -1272,   863, 10336,   202, -1272,   833,   863,
   10336, -1272, -1272,  4946,  4946,  4946,  4946,  4946, -1272,  4946,
    4946, -1272, -1272,   246, -1272,   834, -1272, -1272, -1272, -1272,
     875, -1272, -1272, -1272,   706, -1272, -1272, -1272, -1272, -1272,
   -1272,  4946, -1272,   378,  5522,  5522,   268,   195, -1272, -1272,
   -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272,  9776,
   -1272,     2,    14,    14, -1272,    19, -1272, -1272, -1272,   150,
   -1272,   984,   -40,   836,   908, -1272,  6098,   -67,   744, -1272,
     853,   927,  4946, 10336,  4946, -1272,  4946,   706, -1272, -1272,
   -1272, -1272,   955, -1272, -1272, -1272, -1272,   -18,   863, 10336,
   -1272,   837,   863, -1272, -1272, -1272, -1272, -1272, -1272, -1272,
     906,  6962, -1272, -1272, -1272, -1272, -1272,   268,   268,  5522,
   -1272, -1272, -1272, -1272, -1272,   998, -1272, -1272, -1272,   770,
   -1272,   904,   920, -1272,   935, 10336,   915,   809, 10336,  6098,
    9776, -1272,   852, -1272, -1272,   850,   917,   169,   299, -1272,
     843,   863, -1272,   844, 10336, -1272,   268, -1272, -1272, -1272,
    6098, 10336,   778, 10336,   921,   819,   920,   856,  4946, 10336,
   -1272, -1272,   947,   286, -1272, -1272, -1272, -1272,   864,   405,
   -1272, -1272, -1272,   851, -1272,   171, -1272,   875,  4946,   781,
   10336,   928,  4946, -1272, -1272, -1272, -1272, -1272, -1272, -1272,
   -1272, -1272,   929,   895, -1272, -1272,   780,   785, 10336, -1272,
   10336, -1272,   790,  4946,   792,   194,  6098, -1272,  6098,   930,
     895, -1272,   854, 10336, -1272,   793,   867, 10336,   895,   829,
   -1272,   934, 10336,   794,  6098, -1272
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   402,   403,   584,   549,   689,   698,   677,   601,   593,
     609,   600,   591,   699,   738,   737,   739,   740,   736,   595,
     696,   597,   624,   659,   653,   694,   621,   697,   754,   648,
     690,   752,   638,   639,   640,   641,   642,   643,   644,   645,
     646,   691,   605,   599,   592,   693,   668,   598,   603,   764,
     765,   766,   767,   768,   769,   770,   771,   772,   773,   774,
     393,   396,   667,   663,   654,   634,   590,   383,     0,   662,
     670,   678,   381,   658,   419,   635,   636,   692,   382,   385,
     655,   672,     0,   425,   391,   421,   665,   589,   656,   657,
     685,   660,   676,   684,   387,   386,   608,   647,   687,   420,
     675,   680,   594,     0,     0,   340,   673,   683,   688,   686,
     666,   652,   741,   650,   651,   392,     0,   339,     0,   395,
     394,   681,   637,   661,     0,   384,   369,     0,   401,   682,
     664,   671,   679,   674,   742,   628,   633,   632,   631,   630,
     629,   602,   649,     0,   588,   695,   622,   728,   727,   729,
     607,   606,   625,   734,   596,   726,   731,   732,   723,   627,
     669,   725,   735,   733,   724,   626,   730,   744,   748,   749,
     745,   746,   743,   747,   750,   751,   753,   715,   714,   620,
     613,   708,   704,   623,   619,   717,   718,   701,   610,   604,
     612,   713,   712,   709,   705,   722,   716,   711,   707,   700,
     611,   721,   720,   615,   617,   616,   706,   710,   702,   618,
     703,   614,   719,   775,   776,   777,   778,   779,   780,   756,
     757,   755,   761,   762,   763,   758,   759,   760,   781,   782,
     783,   784,   785,   786,   787,     0,     0,     2,     0,     4,
       6,    12,     0,     0,     0,    18,    20,    29,    22,    23,
      24,    50,    25,    34,    30,    54,    55,    56,    51,    52,
      58,    59,    28,    26,    27,    32,    33,    53,   198,   197,
     194,   195,   196,    31,    11,   175,   176,   180,   182,   213,
     219,     0,     0,   211,   212,   183,   184,   185,   186,   295,
     297,   299,   309,   313,   315,   318,   323,   326,   329,   331,
     333,   335,     0,   337,   343,   345,     0,   361,   344,   365,
     368,   370,   373,   375,     0,   380,   377,     0,   388,   398,
     400,   374,   404,   409,   417,   410,   411,   412,   415,   416,
     413,   414,   432,   434,   435,   436,   433,   481,   482,   483,
     484,   485,   486,   397,   523,   515,   522,   521,   520,   517,
     519,   516,   518,   418,    57,   187,   188,   190,   189,   191,
     192,   399,   193,   585,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,   108,     0,     0,     0,     0,   103,   104,   105,
     106,   111,     0,     0,     0,     0,     0,     0,   101,   156,
     159,     0,     0,     0,     0,     0,     0,   689,   698,   677,
     601,   593,   609,   600,   591,   595,   696,   597,   659,   754,
     648,   752,   638,   639,   599,   592,   590,   660,     0,     0,
     741,   742,   588,   734,   596,   726,   732,   723,   626,   744,
     748,   749,   745,   747,   750,   753,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   582,     0,     0,     0,   583,
       0,     0,     0,     0,     0,     0,   221,     0,     0,     0,
       0,     0,     0,     0,   593,   600,   591,   597,   590,   389,
     399,   422,     0,   423,     0,   448,     0,     0,   364,     0,
       0,   367,     0,     0,   477,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   146,   143,   154,   155,     0,
       0,     0,     0,     3,     1,     5,     7,     0,     0,    13,
      10,    15,    16,     0,   178,   177,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   199,   218,   214,   220,   215,
     217,   216,   223,   224,     0,     0,     0,     0,   354,     0,
       0,   352,     0,   304,     0,   353,   346,   351,   350,   349,
     348,   347,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     342,   341,   338,     0,   362,   366,     0,     0,     0,   376,
     406,   379,   378,   390,   405,     0,     0,     0,   161,     0,
     162,   158,   157,   160,     0,   137,   138,    67,    68,   581,
      76,     0,     0,    61,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   550,   551,   552,   110,   109,
       0,     0,     0,     0,     0,   848,   849,     0,    66,   836,
     838,   839,   840,   842,   844,   843,   841,   845,   115,   112,
       0,   114,   113,     0,     0,     0,   102,     0,     0,   547,
       0,     0,     0,     0,     0,   539,     0,     0,     0,     0,
       0,   528,     0,   529,     0,     0,    85,     0,     0,     0,
      77,     0,     0,   530,     0,     0,     0,   284,     0,     0,
     236,   237,     0,     0,   201,   202,     0,     0,   222,     0,
       0,     0,   525,     0,     0,     0,   533,     0,     0,     0,
       0,   424,   449,   448,   445,     0,     0,   479,   478,   363,
     538,     0,   476,     0,   563,   564,   524,     0,     0,     0,
       0,     0,     0,   569,     0,     0,   152,     0,     0,     0,
     239,   256,     0,    19,     0,    21,   181,     0,     0,     0,
       0,     0,   200,   257,     0,     0,     0,     0,     0,     0,
       0,     0,   296,   298,   302,   308,   307,   306,     0,   303,
     300,   301,     0,     0,     0,   812,   814,   311,   789,   793,
     795,   797,   799,   802,   809,   810,   816,   317,   316,   314,
     320,   321,   322,   319,   324,   325,   328,   327,     0,     0,
       0,     0,   359,     0,   371,   372,     0,   407,   428,   430,
       0,     0,     0,     0,     0,    65,     0,     0,    40,    42,
      43,    44,    45,    47,    48,    49,    41,    46,    36,    37,
       0,     0,    93,     0,    89,    91,    92,    96,    99,     0,
       0,     0,    35,    75,     0,     0,     0,   847,   846,     0,
     853,     0,     0,   883,   851,   850,   882,   854,     0,   857,
     884,   837,     0,     0,   116,     0,     0,   119,     0,     0,
       0,   355,     0,     0,     0,     0,     0,   543,     0,   540,
     488,     0,   487,   496,   497,     0,     0,     0,     0,     0,
      78,     0,     0,   532,   531,   498,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   587,     0,     0,   203,
     204,     0,   209,   546,   526,   527,     0,     0,   536,     0,
     534,   492,     0,     0,   448,   446,     0,   437,     0,   426,
     427,     0,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   689,     0,     0,
       0,     0,     0,     0,    17,     0,   179,     0,   210,   268,
     264,   266,     0,   258,   259,     0,   594,   602,   504,   505,
     511,   512,   514,     0,   226,     0,     0,     0,     0,     0,
       0,     0,   305,     0,     0,   800,     0,   310,   312,     0,
     830,     0,     0,     0,     0,     0,     0,   788,   790,   791,
     825,   826,   827,   829,   828,     0,     0,   804,   803,     0,
     807,   811,   823,   821,   820,   813,   817,   330,   332,   334,
     502,   336,   360,   408,     0,   429,     0,   139,     0,   169,
     164,     0,   163,     0,     0,    73,    74,    71,    72,    38,
       0,     0,    94,    95,    97,     0,    98,    63,    64,    69,
      70,    60,   852,     0,     0,     0,   859,     0,   855,   858,
     871,     0,     0,     0,     0,     0,     0,   117,   123,     0,
       0,     0,     0,     0,     0,   120,     0,     0,     0,   357,
     356,     0,     0,   290,     0,     0,     0,   547,     0,     0,
     489,     0,     0,    87,    81,    84,    83,     0,    79,     0,
     499,     0,   282,   286,     0,   151,     0,   241,     0,     0,
       0,     0,     0,   205,     0,     0,     0,     0,   250,     0,
     247,   252,   208,     0,     0,     0,   493,   283,   449,     0,
     438,     0,   472,   469,     0,   473,   474,     0,     0,   475,
     468,     0,   443,   471,   470,     0,     0,     0,   556,   557,
     553,     0,     0,   561,   562,   558,   567,   565,     0,     0,
       0,   571,   149,   148,     0,   145,   144,   153,     0,   572,
     573,     0,     0,   265,   277,     0,   278,     0,   269,   270,
     271,   272,     0,   261,     0,   225,     0,     0,   508,   510,
     509,   506,   234,   235,   228,     0,   230,   227,     0,     0,
       0,   815,   808,     0,   885,   886,   896,   895,   894,     0,
       0,     0,     0,   887,   794,   893,     0,   792,   796,     0,
       0,   801,   805,     0,   824,   819,   822,   818,   503,   431,
     171,     0,     0,   140,     0,   166,     0,   168,   167,    39,
      90,   100,   876,     0,     0,   876,   865,   860,   118,   124,
     126,   125,     0,     0,     0,   121,     0,    14,   358,     0,
       0,     0,   291,   490,     0,   544,   545,   548,   541,   542,
       0,    86,     0,    80,   500,     0,   285,   287,   238,   243,
     242,     0,   245,     0,     0,     0,   207,   248,   251,     0,
     494,     0,   537,   535,   448,     0,     0,   480,     0,   448,
       0,   444,     9,     0,     0,     0,     0,     0,   570,     0,
       0,   147,   579,     0,   574,     0,   240,   281,   279,   280,
     273,   274,   275,   267,     0,   262,   260,   513,   507,   232,
     229,     0,   231,   897,     0,     0,   889,     0,   835,   834,
     833,   832,   831,   798,   806,   888,   172,   141,   170,     0,
     174,     0,     0,     0,   870,   877,   878,   872,   874,     0,
     869,     0,   867,     0,   861,   862,     0,     0,     0,   122,
       0,     0,     0,     0,     0,   491,     0,     0,    82,   501,
     244,   246,   255,   254,   249,   206,   495,     0,   448,     0,
     173,     0,   448,   554,   555,   559,   560,   566,   568,   150,
       0,     0,   575,   586,   276,   263,   233,   891,   890,     0,
     142,   165,   881,   880,   879,     0,   873,   866,   864,     0,
     856,     0,   127,   129,     0,     0,     0,     0,     0,     0,
       0,   292,     0,   288,   294,    88,     0,   458,   452,   447,
       0,   448,   439,     0,     0,   580,   892,   875,   868,   863,
       0,     0,     0,     0,     0,     0,   128,     0,     0,     0,
     466,   460,     0,   459,   461,   467,   464,   454,     0,   453,
     455,   465,   441,     0,   440,     0,   130,   131,     0,     0,
       0,     0,     0,   289,   253,   451,   462,   463,   450,   456,
     457,   442,     0,     0,   132,   133,     0,     0,     0,   293,
       0,   576,     0,     0,     0,     0,     0,   135,     0,     0,
       0,   134,     0,     0,   577,     0,     0,     0,     0,     0,
     578,     0,     0,     0,     0,   136
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1272, -1272,   810, -1272,   808,   812, -1272,   806, -1272,   527,
     531,  -505, -1272,   430,  -291, -1272, -1272, -1272, -1272, -1272,
   -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272,  -876,
   -1272, -1272, -1272, -1272,    16,   221,   677, -1272, -1272,   673,
   -1272,   -16,  -848, -1272,  -373,  -391, -1272, -1272,  -141, -1272,
    -873, -1272, -1272,  -104, -1272, -1272, -1272, -1272, -1272,   307,
     708, -1272, -1272, -1272,  -171, -1272, -1271,   823,   -50, -1272,
    -523,  -377, -1272, -1272, -1272, -1272,   154, -1272, -1272,   795,
   -1272, -1272, -1272, -1272, -1272,    99,  -511,  -667, -1272, -1272,
   -1272,   -39, -1272, -1272,  -219,   -43,   -93, -1272, -1272, -1272,
    -102, -1272, -1272,   123,   -99, -1272, -1272,   -94, -1149, -1272,
     608,    -8, -1272, -1272,    17, -1272, -1272,   544,   545, -1272,
    -513, -1272,  -126,  -562,   117,  -560,   133,   114, -1272, -1272,
   -1272, -1272, -1272,   796, -1272, -1272, -1272, -1272,  -548,  -292,
   -1042, -1272,  -106, -1272, -1272, -1272, -1272, -1272, -1272, -1272,
     -36, -1133, -1272, -1272,   263,    15, -1272,  -540, -1272, -1272,
   -1272, -1272, -1272, -1272, -1272, -1272, -1272,  -900, -1272,   -31,
   -1272,   383,  -712, -1272, -1272, -1272, -1272, -1272,  -367,  -360,
   -1083,  -921, -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272,
   -1272, -1272,   305,  -670,  -772,    36,   276,  -794,  -752, -1272,
   -1272, -1272, -1272, -1272, -1272, -1272,   642,   650,  -385,   231,
      71, -1272, -1272, -1272, -1272, -1272, -1272, -1272,   -42, -1272,
   -1272,   -59, -1272,  -369,  -103,    -9, -1272, -1272,   340, -1272,
   -1272, -1272,   121,   111,  -101,   345, -1272, -1272, -1272, -1272,
   -1272, -1272, -1272, -1272, -1272, -1272, -1272, -1272,   124, -1272,
   -1272, -1272,   -95,   342,  -618, -1272, -1272, -1272, -1272, -1272,
      66, -1272, -1272, -1186, -1272, -1272, -1272,  -645, -1272,  -118,
   -1272,  -227, -1272, -1272, -1272, -1272,  -986, -1272,   135, -1272
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   828,   829,   830,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,  1093,
     679,   261,   262,   834,   835,   836,  1162,   263,   397,   398,
     264,  1067,   864,   265,  1422,  1423,   266,   267,   812,   268,
     506,   735,   948,  1163,   269,   270,   271,   272,   273,   399,
     400,   598,   600,  1028,  1029,  1139,  1032,   274,   275,   525,
     276,   277,   278,   535,   467,   911,   912,   279,   536,   280,
     538,   281,   282,   283,   542,   543,  1118,   760,   284,   690,
     739,   691,   697,  1119,  1120,  1121,   740,   539,   540,   963,
     964,  1325,   541,   960,   961,  1178,  1179,  1180,  1181,   285,
     686,   687,   286,  1082,  1083,   287,   288,   289,   290,   768,
     291,   987,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   562,   563,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   589,   590,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   810,   331,   332,   333,  1141,
     713,   714,   715,  1439,  1468,  1469,  1462,  1463,  1470,  1464,
    1142,  1143,   334,   335,  1144,   336,   337,   338,   339,   340,
     341,   342,  1019,   761,   968,  1191,   969,   970,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   658,  1086,
     353,   354,   355,   356,   357,   358,   359,   732,   733,   360,
    1169,  1170,  1313,  1094,   458,   361,   362,   363,   777,   997,
     998,   778,   779,   780,   781,   782,  1007,  1221,  1222,   783,
    1010,   784,   785,   786,  1015,  1016,  1227,  1225,   999,  1000,
    1001,  1002,  1341,   638,   639,   640,   641,   642,   643,   644,
    1058,  1363,  1364,  1059,  1362,  1418,   645,  1245,  1359,  1354,
    1355,  1356,   646,   647,  1003,  1011,  1212,  1004,  1208,   988
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       446,   926,   747,   971,   610,   789,  1020,  1020,   790,   791,
     792,   793,   459,   487,   584,  1098,   775,   745,   900,  1075,
     861,   491,   905,  1223,   776,   904,  1017,  1018,  1140,  1252,
    1321,  1322,   479,   759,   764,  1312,   765,   766,   717,   767,
     908,   769,  1402,  1425,   989,   862,   971,   971,  1209,   770,
     771,   755,   630,   484,     4,  1132,  1133,   473,  1301,   480,
    1109,  1365,   493,   609,  1074,   976,   609,  1437,   700,   523,
    1061,  1062,   523,   481,   927,  1198,  1026,  1167,  1164,   971,
    1063,   755,   756,   756,   676,   680,   693,   876,   897,   897,
     755,   700,   977,   755,   981,   485,   607,   903,   631,   878,
     406,   523,  1243,   701,  1064,  1130,   611,   459,   917,   489,
    1068,   919,  1024,   619,   990,   490,  1175,   620,  1204,   724,
     725,   612,   727,   728,   729,   730,   701,  1065,   608,   944,
     979,   757,   736,   737,   952,  1177,    74,  1132,  1133,   928,
     899,  1027,  1134,  1111,   452,  1352,   746,  1426,    85,   524,
     989,   677,   956,  1438,   621,  1205,   752,   753,  1165,  1244,
    1135,  1238,  1136,   877,   933,   898,   923,  1044,   447,  1232,
    1131,  1404,    99,  1460,  1411,   879,   772,  1132,   849,   773,
     953,   622,  1132,  1133,   918,   863,   909,   920,  1025,  1137,
     758,   758,   675,   104,   718,   678,  1334,   991,   992,   118,
     993,   758,   402,   585,   863,  1210,  1211,   994,  1353,   116,
    1132,  1133,  1129,  1301,  1370,   124,   937,   995,   809,  1248,
     990,  1273,  1501,   910,  1134,   775,   775,   758,  1427,   996,
    1138,  1140,   632,   776,   776,  1449,   702,  1112,  1110,  1514,
     623,  1140,  1135,   494,  1136,  1233,   633,  1520,   143,  1415,
     980,   401,  1066,   843,   945,   982,   758,   758,   403,   634,
     463,   635,   364,   365,   366,   367,   368,   369,  1445,  1134,
    1492,  1137,  1335,   544,   370,   104,   636,   624,   591,   565,
     637,   593,  1135,   774,  1136,   934,   935,  1135,   460,  1136,
    1460,   116,  1461,  1509,  1132,   568,   566,  1134,   657,   376,
     936,  1373,   931,   991,   992,   480,   993,  1132,   480,  1260,
     890,  1137,  1295,  1199,   461,  1135,  1137,  1136,  1466,   567,
     104,   569,  1068,   995,  1424,  1416,   404,   405,  1494,   971,
     143,   377,   378,   955,   570,   996,   116,   938,   939,   850,
     851,   852,   565,   462,  1137,   853,  1493,   583,   104,   605,
     464,   465,   940,   660,   684,   596,   663,  1300,   517,   566,
     932,   604,  1055,   606,   116,  1374,   565,   615,   571,  1510,
     118,   459,   453,   959,   518,   143,  1419,   648,   664,  1056,
     974,  1188,  1409,   566,   650,  1389,   381,  1424,  1031,   831,
     861,  1400,   459,   659,   454,   468,  1140,   669,   670,  1135,
     672,  1136,   674,   143,   466,     4,   681,  1369,  1424,  1486,
    1338,  1189,  1135,  1132,  1136,   565,   526,  1339,   382,  1057,
     667,   705,   527,  1467,  1466,   528,   529,  1340,  1137,  1190,
     832,   613,   566,   530,  1216,   833,   716,  1114,  1115,   847,
    1116,  1137,   721,  1030,  1401,   614,   775,   384,   459,   745,
     848,   688,   689,   692,   776,  1235,  1043,   775,  1031,  1347,
     699,   738,  1046,   708,  1511,   776,  1512,   756,  1114,  1115,
    1236,  1047,  1048,   688,  1012,  1013,  1051,  1338,   385,   971,
     804,   805,  1525,   584,  1339,  1035,   854,    74,  1146,  1117,
    1147,  1085,  1037,  1088,  1340,   734,  1014,   855,   756,    85,
    1077,  1435,  1036,   741,   386,   387,   388,   389,   390,  1038,
     391,   392,   393,   394,   395,   469,  1465,  1471,  1135,   396,
    1136,  1102,  1103,    99,  1105,  1237,  1107,   772,   531,  1489,
     773,   532,  1124,   803,  1125,  1055,  1081,  1039,   806,   502,
     505,   470,  1465,   574,   503,   533,  1127,  1137,  1471,  1261,
     118,  1039,  1056,   625,   626,   627,   575,  1148,  1149,  1150,
    1346,  1153,  1154,  1155,  1156,  1157,  1158,   572,  1160,  1161,
    1174,   534,   886,   381,   482,   889,   573,  1410,  1072,   592,
     959,  1175,  1387,   586,   587,   594,  1073,  1391,   813,  1206,
     814,  1176,   857,   858,   859,   486,  1207,   971,   860,  1194,
    1177,  1196,  1197,   448,   807,   382,   449,   807,   837,   807,
     450,   872,   873,   451,   364,   365,   366,   492,   881,   369,
     495,   846,   818,   819,   820,   821,   822,   823,   824,   825,
     826,   827,   838,   832,   384,   896,   498,   839,   833,   496,
     499,   497,   500,  1333,   866,   867,   868,  1229,  1336,  1337,
    1151,   501,  1152,   628,   629,  1049,  1050,  1477,  1457,   922,
    1069,  1070,  1114,  1115,  1318,  1319,   459,   504,  1241,   459,
     505,   775,  1033,  1034,   601,   602,  1440,   507,   971,   776,
    1443,   508,   787,   788,   509,   949,   510,   907,   796,   797,
     511,   654,   387,   388,   389,   390,   512,   391,   392,   655,
     394,   395,   514,   924,   521,   794,   795,  1412,  1413,   522,
     545,   546,   576,  1351,  1270,   564,   578,   577,   579,   588,
     595,   597,   983,  1271,   599,   364,   609,  1277,   616,  1473,
     617,  1279,  1280,   649,  1282,   651,   652,   653,   661,  1286,
     958,   547,   662,   668,   671,   673,   972,   685,   696,   548,
     549,   694,   550,   695,   709,   698,   429,   711,   449,   551,
     451,   457,   472,   552,   712,   553,   719,   720,   722,   723,
     554,   731,  1407,  1408,   726,   744,   749,   750,   748,   754,
     798,   751,   799,   800,   801,   811,   555,   815,   816,   972,
     972,   972,   972,   817,  1315,   840,   841,   845,   844,   856,
     865,   869,   870,   871,   874,   959,  1317,   875,   882,   883,
     556,   557,   558,   559,   560,   561,   885,   887,  1329,   888,
    1078,  1330,   972,  1332,   884,   892,   891,   901,   906,   893,
     894,   902,   913,   914,   915,   916,   929,   930,   941,   943,
     942,   946,   950,   951,   957,   962,   965,  1446,   954,   973,
     975,   978,   986,   118,  1005,  1006,  1022,   833,  1009,  1023,
     755,  1052,  1045,  1040,  1053,  1054,  1060,  1087,  1081,  1087,
    1084,  1076,  1079,  1080,  1097,  1090,  1092,  1071,  1091,  1096,
    1095,  1101,  1100,  1104,  1099,  1106,  1113,  1108,  1123,  1126,
    1128,  1145,  1159,  1166,  1172,  1171,   621,  1168,  1182,  1184,
    1195,  1186,  1200,  1378,  1380,  1187,  1381,  1203,   659,  1202,
     659,  1213,  1385,  1219,  1224,  1201,  1226,  1228,  1231,  1220,
       4,  1246,  1254,  1250,  1242,   863,  1393,  1394,  1395,  1396,
    1397,  1258,  1398,  1399,  1251,  1256,  1265,  1257,  1266,   364,
     365,   366,   367,   368,   369,  1267,  1253,  1268,  1269,  1272,
    1281,   370,  1283,  1183,  1406,  1405,   544,   371,  1284,  1285,
    1289,  1294,  1292,  1293,  1192,  1297,  1193,  1303,   372,   373,
    1302,  1309,   374,  1175,  1307,   375,   376,  1310,  1324,  1327,
    1328,  1234,  1331,  1345,  1304,  1350,  1026,  1305,  1349,  1357,
    1306,  1358,  1055,  1361,  1366,  1431,  1372,  1433,  1375,  1434,
    1376,  1377,  1379,  1386,  1417,  1390,  1403,  1421,   377,   378,
     379,  1420,  1429,  1430,  1436,  1368,  1444,  1230,  1447,  1450,
    1428,  1451,  1442,  1454,  1448,  1453,  1458,  1459,  1472,  1474,
    1482,  1480,  1485,  1481,  1264,  1488,  1491,  1031,  1498,  1500,
    1513,  1515,  1518,  1521,  1522,   513,   515,   519,   742,  1275,
     516,   842,   743,  1042,   380,   618,  1456,  1240,  1255,  1476,
    1311,  1348,  1502,   381,  1185,   520,  1122,  1278,  1384,  1517,
     656,  1478,   972,  1291,  1496,  1288,   537,   603,  1503,  1316,
    1173,  1483,  1326,  1323,  1506,  1320,  1508,  1298,  1524,   762,
     710,   763,   688,  1276,  1344,   382,   925,   692,   582,  1262,
    1296,  1495,  1490,  1487,  1249,  1499,  1021,  1041,  1287,  1089,
    1314,  1239,   703,   984,   383,  1214,  1218,  1308,  1343,   985,
     704,  1342,  1217,  1247,   384,  1008,  1507,  1360,  1414,  1299,
    1215,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     734,     0,     0,     0,     0,   385,     0,     0,     0,   480,
       0,     0,     0,   741,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   386,   387,   388,   389,   390,     0,   391,   392,   393,
     394,   395,     0,     0,     0,     0,   396,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   972,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1367,     0,     0,     0,     0,     0,
    1371,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1382,  1383,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1388,     0,     0,     0,
       0,  1392,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     972,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1432,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1441,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   480,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1452,     0,     0,  1455,
       0,   972,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1475,     0,     0,     0,     0,
       0,     0,   972,     0,  1479,     0,     0,     0,     0,     0,
    1484,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1497,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1504,
       0,  1505,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     0,     0,     0,  1516,     0,     2,     3,  1519,     4,
       0,     0,     0,  1523,     5,     6,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
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
       0,     0,     0,   122,     0,   123,   124,   125,     0,   126,
     127,   128,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   144,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,     0,   187,   188,   189,
       0,   190,   191,   192,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,   407,   408,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,   416,
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
       0,     0,   122,   483,   123,   124,   125,     0,   126,   127,
     128,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   432,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,   407,   408,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,   416,    21,    22,
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
     117,   118,     0,     0,   119,   120,   121,     0,   802,     0,
     122,     0,   123,   124,   125,     0,   126,   127,   128,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   407,
     408,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   416,    21,    22,    23,    24,
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
       0,     0,   119,   120,   121,     0,     0,     0,   122,   808,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   432,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   407,   408,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   416,    21,    22,    23,    24,    25,    26,
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
     119,   120,   121,     0,   880,     0,   122,     0,   123,   124,
     125,     0,   126,   127,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   432,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     0,
     187,   188,   189,     0,   190,   191,   192,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,   407,   408,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,   416,    21,    22,    23,    24,    25,    26,    27,     0,
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
     121,     0,   895,     0,   122,     0,   123,   124,   125,     0,
     126,   127,   128,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   432,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,   407,   408,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,   416,
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
     921,     0,   122,     0,   123,   124,   125,     0,   126,   127,
     128,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   432,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,   407,   408,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,   416,    21,    22,
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
     117,   118,     0,     0,   119,   120,   121,     0,  1263,     0,
     122,     0,   123,   124,   125,     0,   126,   127,   128,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   407,
     408,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   416,    21,    22,    23,    24,
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
       0,     0,   119,   120,   121,     0,  1274,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   432,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   407,   408,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   416,    21,    22,    23,    24,    25,    26,
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
     119,   120,   121,     0,  1290,     0,   122,     0,   123,   124,
     125,     0,   126,   127,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   432,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     0,
     187,   188,   189,     0,   190,   191,   192,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,     5,     6,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
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
     121,     0,     0,     0,   122,     0,   123,   124,   125,     0,
     126,   127,   128,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   144,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,     1,     0,
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
       0,   432,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,   407,   408,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,   416,    21,    22,
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
     117,   118,     0,     0,   119,   120,   121,     0,     0,     0,
     122,     0,   123,   124,   125,     0,   126,   127,   128,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   407,
     408,     0,     7,   410,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,   415,   416,    21,    22,   418,    24,
      25,    26,    27,     0,   419,   420,    30,   421,   422,   423,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
       0,    72,    73,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,    85,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   427,
      92,    93,    94,    95,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   580,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   581,   118,
       0,     0,   119,   120,   121,     0,     0,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   432,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   433,   154,   435,
     156,   436,   437,   159,   160,   161,   162,   163,   164,   438,
     166,   439,   440,   441,   442,   171,   172,   443,   444,   175,
     445,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   407,   408,     0,
       7,   410,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,   415,   416,    21,    22,   418,    24,    25,    26,
      27,     0,   419,   420,    30,   421,   422,   423,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,     0,    72,
      73,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,    85,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   427,    92,    93,
      94,    95,     0,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,   103,   104,   105,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,     0,   117,   118,     0,     0,
     119,   120,   121,     0,     0,     0,   122,     0,   123,   124,
     125,     0,   126,   127,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   432,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   433,   154,   435,   156,   436,
     437,   159,   160,   161,   162,   163,   164,   438,   166,   439,
     440,   441,   442,   171,   172,   443,   444,   175,   445,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     0,
     187,   188,   189,     0,   190,   191,   192,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,   947,   408,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,   416,    21,    22,    23,    24,    25,    26,    27,     0,
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
     121,     0,     0,     0,   122,     0,   123,   124,   125,     0,
     126,   127,   128,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   432,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,   407,   408,     0,   409,   410,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,   415,   416,
      21,    22,   418,    24,    25,    26,    27,     0,   419,   420,
      30,   421,   422,   423,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,     0,    72,    73,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,    85,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   427,    92,    93,    94,    95,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,   103,   104,     0,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   111,   112,   113,   114,   115,
     116,     0,     0,     0,     0,     0,   119,   120,   121,     0,
       0,     0,   122,     0,   123,   124,   125,     0,   126,   127,
     128,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   432,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   433,   154,   435,   156,   436,   437,   159,   160,   161,
     162,   163,   164,   438,   166,   439,   440,   441,   442,   171,
     172,   443,   444,   175,   445,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,   407,   408,     0,   409,   410,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,   415,   416,    21,    22,
     418,    24,    25,    26,    27,     0,   419,   420,    30,   421,
     422,   423,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   427,    92,    93,    94,    95,     0,     0,     0,     0,
       0,    96,    97,    98,    99,   100,   101,   102,     0,     0,
       0,   103,   104,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,     0,
       0,     0,     0,     0,   119,   120,   121,     0,     0,     0,
     122,     0,   123,   124,   125,     0,     0,     0,   128,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   433,
     154,   435,   156,   436,   437,   159,   160,   161,   162,   163,
     164,   438,   166,   439,   440,   441,   442,   171,   172,   443,
     444,   175,   445,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     0,     0,     0,     0,     0,   407,
     408,     0,   409,   410,   474,   412,   475,   476,    13,    14,
      15,    16,    17,    18,   415,   416,   477,    22,   418,    24,
      25,    26,    27,     0,   419,   420,    30,   421,   422,   423,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    62,     0,
      63,    64,    65,   478,     0,     0,    69,    70,    71,     0,
       0,     0,    73,     0,     0,     0,     0,    75,    76,    77,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   427,
      92,    93,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   430,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,     0,
     123,   124,     0,     0,     0,     0,   128,     0,   129,     0,
     130,   131,   132,   133,   431,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   432,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   433,   154,   435,
     156,   436,   437,   159,   160,   161,   162,   163,   164,   438,
     166,   439,   440,   441,   442,   171,   172,   443,   444,   175,
     445,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     0,     0,     0,     0,     0,   407,   408,     0,
     409,   410,   411,   412,   413,   414,    13,    14,    15,    16,
      17,    18,   415,   416,   417,    22,   418,    24,    25,    26,
      27,     0,   419,   420,    30,   421,   422,   423,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   424,   425,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   426,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   427,    92,    93,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,   100,   101,   102,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   111,
     430,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   122,     0,   123,     0,
       0,     0,     0,     0,   128,     0,   129,     0,   130,   131,
     132,   133,   431,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,     0,     0,   432,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   433,   434,   435,   156,   436,
     437,   159,   160,   161,   162,   163,   164,   438,   166,   439,
     440,   441,   442,   171,   172,   443,   444,   175,   445,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     0,
     187,   188,   189,     0,   190,   191,   192,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     455,     0,     0,     0,     3,     0,     0,     0,     0,     0,
       0,   407,   408,     0,   409,   410,   411,   412,   413,   414,
      13,    14,    15,    16,    17,    18,   415,   416,   417,    22,
     418,    24,    25,    26,    27,     0,   419,   420,    30,   421,
     422,   423,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   424,   425,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   426,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   427,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,   456,     0,
       0,   457,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   430,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   431,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   433,
     434,   435,   156,   436,   437,   159,   160,   161,   162,   163,
     164,   438,   166,   439,   440,   441,   442,   171,   172,   443,
     444,   175,   445,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   455,     0,     0,     0,     3,     0,
     682,     0,     0,     0,     0,   407,   408,     0,   409,   410,
     411,   412,   413,   414,    13,    14,    15,    16,    17,    18,
     415,   416,   417,    22,   418,    24,    25,    26,    27,     0,
     419,   420,    30,   421,   422,   423,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   424,   425,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    62,     0,    63,    64,    65,   426,
       0,     0,    69,    70,    71,     0,     0,     0,    73,     0,
       0,     0,     0,    75,    76,    77,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   427,    92,    93,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,   100,
     101,   102,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   111,   430,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   122,   683,   123,     0,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     431,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   432,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   433,   434,   435,   156,   436,   437,   159,
     160,   161,   162,   163,   164,   438,   166,   439,   440,   441,
     442,   171,   172,   443,   444,   175,   445,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   455,     0,
       0,     0,     3,     0,     0,     0,     0,     0,     0,   407,
     408,     0,   409,   410,   411,   412,   413,   414,    13,    14,
      15,    16,    17,    18,   415,   416,   417,    22,   418,    24,
      25,    26,    27,     0,   419,   420,    30,   421,   422,   423,
      34,    35,    36,    37,    38,    39,    40,    41,    42,   424,
     425,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    62,     0,
      63,    64,    65,   426,     0,     0,    69,    70,    71,     0,
       0,     0,    73,     0,     0,     0,     0,    75,    76,    77,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   427,
      92,    93,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   430,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,     0,
     123,     0,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   431,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   432,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   433,   434,   435,
     156,   436,   437,   159,   160,   161,   162,   163,   164,   438,
     166,   439,   440,   441,   442,   171,   172,   443,   444,   175,
     445,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   488,     0,     3,     0,     0,     0,     0,     0,
       0,   407,   408,     0,   409,   410,   411,   412,   413,   414,
      13,    14,    15,    16,    17,    18,   415,   416,   417,    22,
     418,    24,    25,    26,    27,     0,   419,   420,    30,   421,
     422,   423,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   424,   425,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   426,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   427,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   430,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   431,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   433,
     434,   435,   156,   436,   437,   159,   160,   161,   162,   163,
     164,   438,   166,   439,   440,   441,   442,   171,   172,   443,
     444,   175,   445,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     3,     0,     0,     0,     0,     0,
       0,   407,   408,     0,   409,   410,   411,   412,   413,   414,
      13,    14,    15,    16,    17,    18,   415,   416,   417,    22,
     418,    24,    25,    26,    27,     0,   419,   420,    30,   421,
     422,   423,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   424,   425,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   426,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   427,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,   428,     0,
       0,   429,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   430,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   431,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   433,
     434,   435,   156,   436,   437,   159,   160,   161,   162,   163,
     164,   438,   166,   439,   440,   441,   442,   171,   172,   443,
     444,   175,   445,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     3,     0,     0,     0,     0,     0,
       0,   407,   408,     0,   409,   410,   411,   412,   413,   414,
      13,    14,    15,    16,    17,    18,   415,   416,   417,    22,
     418,    24,    25,    26,    27,     0,   419,   420,    30,   421,
     422,   423,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   424,   425,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   426,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   427,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,   471,     0,
       0,   472,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   430,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   431,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   433,
     434,   435,   156,   436,   437,   159,   160,   161,   162,   163,
     164,   438,   166,   439,   440,   441,   442,   171,   172,   443,
     444,   175,   445,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     3,     0,     0,     0,     0,     0,
       0,   407,   408,     0,   409,   410,   411,   412,   413,   414,
      13,    14,    15,    16,    17,    18,   415,   416,   417,    22,
     418,    24,    25,    26,    27,     0,   419,   420,    30,   421,
     422,   423,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   424,   425,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   426,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   427,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   430,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,   665,   123,     0,     0,     0,     0,     0,   666,     0,
     129,     0,   130,   131,   132,   133,   431,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   433,
     434,   435,   156,   436,   437,   159,   160,   161,   162,   163,
     164,   438,   166,   439,   440,   441,   442,   171,   172,   443,
     444,   175,   445,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     3,     0,     0,     0,     0,     0,
       0,   407,   408,     0,   409,   410,   411,   412,   413,   414,
      13,    14,    15,    16,    17,    18,   415,   416,   417,    22,
     418,    24,    25,    26,    27,     0,   419,   420,    30,   421,
     422,   423,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   424,   425,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   426,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   427,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   430,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,   706,   123,     0,     0,     0,     0,     0,   707,     0,
     129,     0,   130,   131,   132,   133,   431,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   433,
     434,   435,   156,   436,   437,   159,   160,   161,   162,   163,
     164,   438,   166,   439,   440,   441,   442,   171,   172,   443,
     444,   175,   445,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     3,     0,     0,     0,     0,     0,
       0,   407,   408,     0,   409,   410,   474,   412,   475,   476,
      13,    14,    15,    16,    17,    18,   415,   416,   477,    22,
     418,    24,    25,    26,    27,     0,   419,   420,    30,   421,
     422,   423,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   478,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,  1259,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   427,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   966,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   430,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,   124,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   431,   135,   136,   137,
     138,   139,   140,     0,     0,   967,   142,     0,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   433,
     154,   435,   156,   436,   437,   159,   160,   161,   162,   163,
     164,   438,   166,   439,   440,   441,   442,   171,   172,   443,
     444,   175,   445,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     3,     0,     0,     0,     0,     0,
       0,   407,   408,     0,   409,   410,   474,   412,   475,   476,
      13,    14,    15,    16,    17,    18,   415,   416,   477,    22,
     418,    24,    25,    26,    27,     0,   419,   420,    30,   421,
     422,   423,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   478,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   427,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   966,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   430,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,   124,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   431,   135,   136,   137,
     138,   139,   140,     0,     0,   967,   142,     0,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   433,
     154,   435,   156,   436,   437,   159,   160,   161,   162,   163,
     164,   438,   166,   439,   440,   441,   442,   171,   172,   443,
     444,   175,   445,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     3,     0,     0,     0,     0,     0,
       0,   407,   408,     0,   409,   410,   474,   412,   475,   476,
      13,    14,    15,    16,    17,    18,   415,   416,   477,    22,
     418,    24,    25,    26,    27,     0,   419,   420,    30,   421,
     422,   423,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   478,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   427,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   966,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   430,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,   124,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   431,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   433,
     154,   435,   156,   436,   437,   159,   160,   161,   162,   163,
     164,   438,   166,   439,   440,   441,   442,   171,   172,   443,
     444,   175,   445,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     3,     0,     0,     0,     0,     0,
       0,   407,   408,     0,   409,   410,   411,   412,   413,   414,
      13,    14,    15,    16,    17,    18,   415,   416,   417,    22,
     418,    24,    25,    26,    27,     0,   419,   420,    30,   421,
     422,   423,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   424,   425,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   426,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   427,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   430,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   431,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   433,
     434,   435,   156,   436,   437,   159,   160,   161,   162,   163,
     164,   438,   166,   439,   440,   441,   442,   171,   172,   443,
     444,   175,   445,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         9,   713,   525,   755,   373,   567,   800,   801,   568,   569,
     570,   571,    21,   116,   306,   891,   564,   522,   688,   867,
     638,   127,   692,  1009,   564,   692,   798,   799,   928,  1071,
    1179,  1180,    68,   544,   547,  1168,   549,   550,     7,   552,
      60,   554,  1313,   110,    88,    86,   798,   799,    88,   562,
     563,    86,    46,   103,    20,     8,     9,    66,  1141,    68,
     132,  1247,    21,    20,    86,   136,    20,    85,    30,    99,
      32,    33,    99,    82,   120,   136,   110,   950,    99,   831,
      42,    86,    88,    88,   453,   454,   463,    99,    99,    99,
      86,    30,   759,    86,   761,   104,   158,   132,    92,    99,
     145,    99,    88,    65,    66,   120,   155,   116,    99,   118,
     862,    99,    99,    30,   158,   124,    98,    34,   206,   496,
     497,   170,   499,   500,   501,   502,    65,    89,   190,    99,
     136,   136,   509,   510,    53,   117,   102,     8,     9,   185,
     136,   175,    95,   136,   145,   126,   523,   214,   114,   179,
      88,   105,   179,   171,    71,   243,   533,   534,   179,   145,
     113,  1034,   115,   175,    86,   176,   176,   837,   142,    99,
     185,  1320,   138,     4,   172,   175,   142,     8,   105,   145,
      99,    98,     8,     9,   175,   226,   206,   175,   175,   142,
     262,   262,   149,   146,   163,   149,    43,   241,   242,   165,
     244,   262,    86,   309,   226,   245,   246,   251,   189,   162,
       8,     9,   924,  1296,  1256,   177,    86,   261,   595,  1067,
     158,  1097,  1493,   243,    95,   773,   774,   262,   295,   273,
     183,  1131,   226,   773,   774,  1421,   175,   907,   905,  1510,
     157,  1141,   113,   202,   115,   175,   240,  1518,   201,    99,
     761,   149,   214,   622,   224,   768,   262,   262,   142,   253,
     142,   255,    34,    35,    36,    37,    38,    39,  1401,    95,
      99,   142,   119,   282,    46,   146,   270,   380,   314,   147,
     274,   317,   113,   249,   115,   207,   208,   113,   110,   115,
       4,   162,   123,    99,     8,   109,   164,    95,   401,    71,
     222,   110,   121,   241,   242,   314,   244,     8,   317,  1081,
     679,   142,   183,   980,   110,   113,   142,   115,    19,   187,
     146,   135,  1074,   261,  1366,   175,   210,   211,  1477,  1081,
     201,   103,   104,   105,   148,   273,   162,   207,   208,   266,
     267,   268,   147,   110,   142,   272,   175,   142,   146,   170,
      56,    57,   222,   403,   457,   364,   406,   183,    25,   164,
     179,   370,    88,   184,   162,   174,   147,   376,   182,   175,
     165,   380,    26,   750,    41,   201,  1362,   386,   428,   105,
     757,   134,   187,   164,   393,   183,   158,  1429,   142,    86,
    1008,   145,   401,   402,    48,    54,  1296,   447,   448,   113,
     450,   115,   452,   201,   110,    20,   456,  1255,  1450,   123,
     258,   164,   113,     8,   115,   147,    45,   265,   190,   145,
     429,   471,    51,   124,    19,    54,    55,   275,   142,   182,
     127,   170,   164,    62,   996,   132,   486,    58,    59,   252,
      61,   142,   492,   127,   198,   184,   994,   219,   457,   954,
     263,   460,   461,   462,   994,   127,   833,  1005,   142,  1231,
     469,   511,   839,   472,  1506,  1005,  1508,    88,    58,    59,
     142,   840,   841,   482,   237,   238,   845,   258,   250,  1231,
     586,   587,  1524,   775,   265,   137,   252,   102,   221,   110,
     223,   876,   137,   878,   275,   504,   259,   263,    88,   114,
     869,  1377,   154,   512,   276,   277,   278,   279,   280,   154,
     282,   283,   284,   285,   286,   145,  1437,  1438,   113,   291,
     115,   898,   899,   138,   901,   127,   903,   142,   157,   124,
     145,   160,   917,   583,   919,    88,    92,   828,   588,   214,
     142,   145,  1463,   126,   219,   174,   923,   142,  1469,   105,
     165,   842,   105,   210,   211,   212,   139,   934,   935,   936,
    1230,   938,   939,   940,   941,   942,   943,   189,   945,   946,
      87,   200,   675,   158,   110,   678,   198,  1349,   288,   316,
     957,    98,  1294,   180,   181,   322,   296,  1299,   597,   257,
     599,   108,   266,   267,   268,   142,   264,  1349,   272,   976,
     117,   978,   979,   142,   589,   190,   145,   592,   617,   594,
     142,   661,   662,   145,    34,    35,    36,   142,   668,    39,
     204,   630,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,   127,   127,   219,   685,   145,   132,   132,   214,
     214,   216,   216,  1203,   653,   654,   655,  1024,  1210,  1211,
     221,   214,   223,   289,   290,   118,   119,  1451,  1430,   709,
     280,   281,    58,    59,   118,   119,   675,   110,  1045,   678,
     142,  1219,   813,   814,   367,   368,  1388,   231,  1430,  1219,
    1392,   231,   565,   566,   232,   735,   145,   696,   574,   575,
     142,   276,   277,   278,   279,   280,   110,   282,   283,   284,
     285,   286,     0,   712,   179,   572,   573,  1352,  1353,   179,
     156,    84,    68,  1236,  1091,   248,    93,   188,    94,   143,
     145,    34,   772,  1092,    34,    34,    20,  1104,   141,  1441,
     110,  1108,  1109,   282,  1111,   287,   287,   292,   142,  1116,
     749,   122,   142,   142,   175,   175,   755,   142,   110,   130,
     131,   273,   133,   273,   142,   110,   145,   175,   145,   140,
     145,   145,   145,   144,    27,   146,    15,   175,   202,    20,
     151,   220,  1334,  1335,   175,    25,   110,   159,   157,    99,
     220,   159,    86,    86,    86,   145,   167,    20,    99,   798,
     799,   800,   801,    99,  1171,   149,   149,   122,   117,    20,
     288,   122,   142,   172,   175,  1182,  1175,   172,   172,   172,
     191,   192,   193,   194,   195,   196,   175,    88,  1195,    30,
     870,  1198,   831,  1200,   172,   172,    88,   132,   172,   175,
     175,    99,   175,   175,   175,   172,   172,   172,    86,   214,
     226,   132,   175,   172,   159,   110,   110,  1409,   179,   110,
     110,   136,   274,   165,   247,   249,   172,   132,   256,   173,
      86,    20,   132,   122,   267,   275,   275,   876,    92,   878,
     142,   288,   172,   172,    88,   172,   122,   216,   186,   122,
     149,   110,   172,   136,   142,   110,   243,   132,   142,   172,
      27,    20,   110,   172,   110,   142,    71,   235,    99,    99,
     136,   145,   136,  1272,  1281,   145,  1283,   239,   917,   175,
     919,   239,  1289,   136,   275,   172,    47,   134,    86,   271,
      20,    20,   294,   216,   275,   226,  1303,  1304,  1305,  1306,
    1307,   172,  1309,  1310,   216,   216,   175,   179,   175,    34,
      35,    36,    37,    38,    39,   134,   276,   175,   175,    99,
     132,    46,   136,   962,  1331,  1324,   965,    52,   110,   110,
      61,   122,   175,   175,   973,     6,   975,   222,    63,    64,
     179,   174,    67,    98,   226,    70,    71,   132,    98,   175,
     175,  1031,   136,   269,   222,   172,   110,   222,    86,    20,
     222,    20,    88,   260,   159,  1372,   174,  1374,   172,  1376,
     116,    88,   172,   172,    20,   172,   172,    99,   103,   104,
     105,   175,   159,    86,    59,   246,   110,  1026,    20,    99,
     276,    86,   185,   214,   254,   110,   174,   110,   185,   185,
     174,   110,    85,   214,  1084,   171,   185,   142,   110,   110,
     110,   187,   175,   214,   110,   235,   238,   241,   521,  1099,
     238,   621,   521,   832,   149,   378,  1429,  1041,  1074,  1450,
    1164,  1232,   282,   158,   965,   242,   912,  1106,  1287,   276,
     397,   293,  1081,  1123,   293,  1118,   281,   369,   293,  1172,
     957,  1458,  1184,  1182,   294,  1179,   294,  1137,   294,   545,
     482,   546,  1101,  1101,  1220,   190,   713,  1106,   302,  1082,
    1131,  1478,  1469,  1463,  1068,  1482,   801,   831,  1117,   878,
    1169,  1040,   470,   773,   209,   994,  1005,  1159,  1219,   774,
     470,  1216,   998,  1057,   219,   783,  1503,  1245,  1355,  1138,
     995,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1159,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,  1168,
      -1,    -1,    -1,  1172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   276,   277,   278,   279,   280,    -1,   282,   283,   284,
     285,   286,    -1,    -1,    -1,    -1,   291,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1253,    -1,    -1,    -1,    -1,    -1,
    1259,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1284,  1285,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1295,    -1,    -1,    -1,
      -1,  1300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1373,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1389,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1401,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1425,    -1,    -1,  1428,
      -1,  1430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1444,    -1,    -1,    -1,    -1,
      -1,    -1,  1451,    -1,  1453,    -1,    -1,    -1,    -1,    -1,
    1459,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1498,
      -1,  1500,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,  1513,    -1,    17,    18,  1517,    20,
      -1,    -1,    -1,  1522,    25,    26,    -1,    28,    29,    30,
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
      -1,    -1,    -1,   174,    -1,   176,   177,   178,    -1,   180,
     181,   182,    -1,   184,    -1,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,   199,   200,
     201,    -1,   203,   204,    -1,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,    -1,   248,   249,   250,
      -1,   252,   253,   254,   255,   256,   257,    -1,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,    10,    -1,
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
      -1,    -1,   174,   175,   176,   177,   178,    -1,   180,   181,
     182,    -1,   184,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,   199,   200,   201,
      -1,   203,   204,    -1,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,    -1,   248,   249,   250,    -1,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,    10,    -1,    -1,    -1,
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
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    10,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,   168,   169,   170,    -1,    -1,    -1,   174,   175,
     176,   177,   178,    -1,   180,   181,   182,    -1,   184,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,   199,   200,   201,    -1,   203,   204,    -1,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,    -1,   248,   249,   250,    -1,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
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
     238,   239,   240,   241,   242,   243,   244,   245,   246,    -1,
     248,   249,   250,    -1,   252,   253,   254,   255,   256,   257,
      -1,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
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
     240,   241,   242,   243,   244,   245,   246,    -1,   248,   249,
     250,    -1,   252,   253,   254,   255,   256,   257,    -1,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,    10,    -1,
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
     172,    -1,   174,    -1,   176,   177,   178,    -1,   180,   181,
     182,    -1,   184,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,   199,   200,   201,
      -1,   203,   204,    -1,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,    -1,   248,   249,   250,    -1,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,    10,    -1,    -1,    -1,
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
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    10,    -1,    -1,    -1,    -1,    -1,
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
     246,    -1,   248,   249,   250,    -1,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
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
     238,   239,   240,   241,   242,   243,   244,   245,   246,    -1,
     248,   249,   250,    -1,   252,   253,   254,   255,   256,   257,
      -1,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
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
     240,   241,   242,   243,   244,   245,   246,    -1,   248,   249,
     250,    -1,   252,   253,   254,   255,   256,   257,    -1,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,    10,    -1,
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
     242,   243,   244,   245,   246,    -1,   248,   249,   250,    -1,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,    10,    -1,    -1,    -1,
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
     164,   165,    -1,    -1,   168,   169,   170,    -1,    -1,    -1,
     174,    -1,   176,   177,   178,    -1,   180,   181,   182,    -1,
     184,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,   199,   200,   201,    -1,   203,
     204,    -1,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    10,    -1,    -1,    -1,    -1,    -1,
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
     246,    -1,   248,   249,   250,    -1,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
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
     168,   169,   170,    -1,    -1,    -1,   174,    -1,   176,   177,
     178,    -1,   180,   181,   182,    -1,   184,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,   199,   200,   201,    -1,   203,   204,    -1,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,    -1,
     248,   249,   250,    -1,   252,   253,   254,   255,   256,   257,
      -1,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
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
     240,   241,   242,   243,   244,   245,   246,    -1,   248,   249,
     250,    -1,   252,   253,   254,   255,   256,   257,    -1,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,    10,    -1,
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
      -1,    -1,    -1,   145,   146,    -1,   148,   149,    -1,    -1,
      -1,    -1,   154,   155,   156,   157,   158,   159,   160,   161,
     162,    -1,    -1,    -1,    -1,    -1,   168,   169,   170,    -1,
      -1,    -1,   174,    -1,   176,   177,   178,    -1,   180,   181,
     182,    -1,   184,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,   199,   200,   201,
      -1,   203,   204,    -1,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,    -1,   248,   249,   250,    -1,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,    10,    -1,    -1,    -1,
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
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    -1,    -1,    84,    -1,
      86,    87,    88,    89,    -1,    -1,    92,    93,    94,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,   103,   104,   105,
      -1,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,    -1,   121,    -1,    -1,    -1,   125,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,
     136,   137,    -1,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,   174,    -1,
     176,   177,    -1,    -1,    -1,    -1,   182,    -1,   184,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,   199,   200,    -1,    -1,   203,   204,    -1,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,    -1,   248,   249,   250,    -1,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
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
     238,   239,   240,   241,   242,   243,   244,   245,   246,    -1,
     248,   249,   250,    -1,   252,   253,   254,   255,   256,   257,
      -1,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
      14,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,
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
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    14,    -1,    -1,    -1,    18,    -1,
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
     240,   241,   242,   243,   244,   245,   246,    -1,   248,   249,
     250,    -1,   252,   253,   254,   255,   256,   257,    -1,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,    14,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    -1,    -1,    84,    -1,
      86,    87,    88,    89,    -1,    -1,    92,    93,    94,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,   103,   104,   105,
      -1,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,    -1,   121,    -1,    -1,    -1,   125,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,
     136,   137,    -1,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,   174,    -1,
     176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,   199,   200,    -1,    -1,   203,   204,    -1,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,    -1,   248,   249,   250,    -1,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,    16,    -1,    18,    -1,    -1,    -1,    -1,    -1,
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
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    18,    -1,    -1,    -1,    -1,    -1,
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
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    18,    -1,    -1,    -1,    -1,    -1,
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
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    18,    -1,    -1,    -1,    -1,    -1,
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
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    18,    -1,    -1,    -1,    -1,    -1,
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
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    -1,
      84,    -1,    86,    87,    88,    89,    -1,    -1,    92,    93,
      94,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,   103,
     104,   105,    -1,    -1,   108,   109,   110,    -1,    -1,    -1,
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
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    18,    -1,    -1,    -1,    -1,    -1,
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
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    18,    -1,    -1,    -1,    -1,    -1,
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
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    18,    -1,    -1,    -1,    -1,    -1,
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
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297
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
     240,   241,   242,   243,   244,   245,   246,   248,   249,   250,
     252,   253,   254,   255,   256,   257,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   344,   345,   350,   353,   356,   359,   360,   362,   367,
     368,   369,   370,   371,   380,   381,   383,   384,   385,   390,
     392,   394,   395,   396,   401,   422,   425,   428,   429,   430,
     431,   433,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   479,   480,   481,   495,   496,   498,   499,   500,   501,
     502,   503,   504,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   523,   524,   525,   526,   527,   528,   529,
     532,   538,   539,   540,    34,    35,    36,    37,    38,    39,
      46,    52,    63,    64,    67,    70,    71,   103,   104,   105,
     149,   158,   190,   209,   219,   250,   276,   277,   278,   279,
     280,   282,   283,   284,   285,   286,   291,   351,   352,   372,
     373,   149,    86,   142,   210,   211,   145,    25,    26,    28,
      29,    30,    31,    32,    33,    40,    41,    42,    44,    50,
      51,    53,    54,    55,    65,    66,    89,   125,   142,   145,
     158,   190,   203,   213,   214,   215,   217,   218,   225,   227,
     228,   229,   230,   233,   234,   236,   538,   142,   142,   145,
     142,   145,   145,    26,    48,    14,   142,   145,   537,   538,
     110,   110,   110,   142,    56,    57,   110,   387,    54,   145,
     145,   142,   145,   538,    30,    32,    33,    42,    89,   463,
     538,   538,   110,   175,   381,   538,   142,   537,    16,   538,
     538,   455,   142,    21,   202,   204,   214,   216,   145,   214,
     216,   214,   214,   219,   110,   142,   363,   231,   231,   232,
     145,   142,   110,   315,     0,   317,   318,    25,    41,   320,
     380,   179,   179,    99,   179,   382,    45,    51,    54,    55,
      62,   157,   160,   174,   200,   386,   391,   392,   393,   410,
     411,   415,   397,   398,   538,   156,    84,   122,   130,   131,
     133,   140,   144,   146,   151,   167,   191,   192,   193,   194,
     195,   196,   447,   448,   248,   147,   164,   187,   109,   135,
     148,   182,   189,   198,   126,   139,    68,   188,    93,    94,
     147,   164,   446,   142,   452,   455,   180,   181,   143,   467,
     468,   463,   467,   463,   467,   145,   538,    34,   374,    34,
     375,   372,   372,   373,   538,   170,   184,   158,   190,    20,
     536,   155,   170,   170,   184,   538,   141,   110,   349,    30,
      34,    71,    98,   157,   537,   210,   211,   212,   289,   290,
      46,    92,   226,   240,   253,   255,   270,   274,   566,   567,
     568,   569,   570,   571,   572,   579,   585,   586,   538,   282,
     538,   287,   287,   292,   276,   284,   352,   537,   521,   538,
     381,   142,   142,   381,   381,   175,   182,   538,   142,   381,
     381,   175,   381,   175,   381,   149,   536,   105,   149,   343,
     536,   381,    20,   175,   537,   142,   423,   424,   538,   538,
     402,   404,   538,   384,   273,   273,   110,   405,   110,   538,
      30,    65,   175,   519,   520,   381,   175,   182,   538,   142,
     423,   175,    27,   483,   484,   485,   381,     7,   163,    15,
     175,   381,   202,    20,   384,   384,   175,   384,   384,   384,
     384,   220,   530,   531,   538,   364,   384,   384,   381,   403,
     409,   538,   322,   323,    25,   324,   384,   383,   157,   110,
     159,   159,   384,   384,    99,    86,    88,   136,   262,   399,
     400,   506,   430,   431,   433,   433,   433,   433,   432,   433,
     433,   433,   142,   145,   249,   451,   470,   541,   544,   545,
     546,   547,   548,   552,   554,   555,   556,   437,   437,   436,
     438,   438,   438,   438,   439,   439,   440,   440,   220,    86,
      86,    86,   172,   381,   455,   455,   381,   468,   175,   384,
     478,   145,   361,   538,   538,    20,    99,    99,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,   326,   327,
     328,    86,   127,   132,   346,   347,   348,   538,   127,   132,
     149,   149,   326,   536,   117,   122,   538,   252,   263,   105,
     266,   267,   268,   272,   252,   263,    20,   266,   267,   268,
     272,   567,    86,   226,   355,   288,   538,   538,   538,   122,
     142,   172,   381,   381,   175,   172,    99,   175,    99,   175,
     172,   381,   172,   172,   172,   175,   537,    88,    30,   537,
     536,    88,   172,   175,   175,   172,   381,    99,   176,   136,
     506,   132,    99,   132,   400,   506,   172,   538,    60,   206,
     243,   388,   389,   175,   175,   175,   172,    99,   175,    99,
     175,   172,   381,   176,   538,   484,   485,   120,   185,   172,
     172,   121,   179,    86,   207,   208,   222,    86,   207,   208,
     222,    86,   226,   214,    99,   224,   132,    25,   365,   381,
     175,   172,    53,    99,   179,   105,   179,   159,   538,   384,
     416,   417,   110,   412,   413,   110,   141,   199,   507,   509,
     510,   511,   538,   110,   384,   110,   136,   400,   136,   136,
     399,   400,   433,   381,   541,   548,   274,   434,   592,    88,
     158,   241,   242,   244,   251,   261,   273,   542,   543,   561,
     562,   563,   564,   587,   590,   247,   249,   549,   566,   256,
     553,   588,   237,   238,   259,   557,   558,   507,   507,   505,
     510,   505,   172,   173,    99,   175,   110,   175,   376,   377,
     127,   142,   379,   361,   361,   137,   154,   137,   154,   327,
     122,   509,   348,   384,   506,   132,   384,   536,   536,   118,
     119,   536,    20,   267,   275,    88,   105,   145,   573,   576,
     275,    32,    33,    42,    66,    89,   214,   354,   511,   280,
     281,   216,   288,   296,    86,   355,   288,   536,   381,   172,
     172,    92,   426,   427,   142,   521,   522,   538,   521,   522,
     172,   186,   122,   342,   536,   149,   122,    88,   342,   142,
     172,   110,   384,   384,   136,   384,   110,   384,   132,   132,
     400,   136,   506,   243,    58,    59,    61,   110,   399,   406,
     407,   408,   389,   142,   521,   521,   172,   384,    27,   485,
     120,   185,     8,     9,    95,   113,   115,   142,   183,   378,
     480,   482,   493,   494,   497,    20,   221,   223,   384,   384,
     384,   221,   223,   384,   384,   384,   384,   384,   384,   110,
     384,   384,   349,   366,    99,   179,   172,   363,   235,   533,
     534,   142,   110,   416,    87,    98,   108,   117,   418,   419,
     420,   421,    99,   538,    99,   398,   145,   145,   134,   164,
     182,   508,   538,   538,   384,   136,   384,   384,   136,   400,
     136,   172,   175,   239,   206,   243,   257,   264,   591,    88,
     245,   246,   589,   239,   545,   591,   436,   561,   546,   136,
     271,   550,   551,   589,   275,   560,    47,   559,   134,   384,
     538,    86,    99,   175,   381,   127,   142,   127,   363,   523,
     347,   384,   275,    88,   145,   580,    20,   573,   355,   508,
     216,   216,   453,   276,   294,   354,   216,   179,   172,   110,
     507,   105,   427,   172,   381,   175,   175,   134,   175,   175,
     384,   536,    99,   342,   172,   381,   424,   384,   404,   384,
     384,   132,   384,   136,   110,   110,   384,   538,   408,    61,
     172,   381,   175,   175,   122,   183,   482,     6,   381,   538,
     183,   493,   179,   222,   222,   222,   222,   226,   531,   174,
     132,   366,   464,   535,   534,   384,   409,   536,   118,   119,
     420,   421,   421,   417,    98,   414,   413,   175,   175,   384,
     384,   136,   384,   438,    43,   119,   436,   436,   258,   265,
     275,   565,   565,   547,   435,   269,   506,   507,   377,    86,
     172,   383,   126,   189,   582,   583,   584,    20,    20,   581,
     582,   260,   577,   574,   575,   576,   159,   538,   246,   355,
     453,   538,   174,   110,   174,   172,   116,    88,   536,   172,
     384,   384,   538,   538,   407,   384,   172,   485,   538,   183,
     172,   485,   538,   384,   384,   384,   384,   384,   384,   384,
     145,   198,   379,   172,   421,   536,   384,   436,   436,   187,
     507,   172,   580,   580,   584,    99,   175,    20,   578,   589,
     175,    99,   357,   358,   453,   110,   214,   295,   276,   159,
      86,   384,   538,   384,   384,   342,    59,    85,   171,   486,
     485,   538,   185,   485,   110,   464,   436,    20,   254,   576,
      99,    86,   538,   110,   214,   538,   357,   507,   174,   110,
       4,   123,   489,   490,   492,   494,    19,   124,   487,   488,
     491,   494,   185,   485,   185,   538,   358,   510,   293,   538,
     110,   214,   174,   384,   538,    85,   123,   492,   171,   124,
     491,   185,    99,   175,   421,   384,   293,   538,   110,   384,
     110,   379,   282,   293,   538,   538,   294,   384,   294,    99,
     175,   453,   453,   110,   379,   187,   538,   276,   175,   538,
     379,   214,   110,   538,   294,   453
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
     565,   566,   567
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   313,   314,   314,   315,   315,   315,   315,   316,   316,
     317,   317,   318,   318,   319,   320,   320,   320,   321,   321,
     322,   322,   323,   323,   323,   323,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   325,   325,   326,   326,   327,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     329,   329,   329,   329,   329,   329,   329,   329,   330,   330,
     331,   332,   332,   333,   333,   334,   335,   336,   336,   337,
     337,   338,   338,   338,   338,   339,   340,   341,   341,   341,
     341,   342,   342,   343,   343,   344,   344,   344,   344,   345,
     346,   346,   347,   347,   347,   348,   349,   349,   350,   350,
     350,   351,   351,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   353,   353,   353,   353,   353,
     353,   353,   353,   354,   354,   355,   355,   356,   356,   357,
     357,   358,   358,   359,   359,   359,   359,   360,   360,   361,
     361,   361,   361,   362,   363,   364,   364,   365,   365,   366,
     366,   367,   368,   369,   370,   370,   371,   371,   371,   372,
     372,   372,   372,   373,   373,   374,   374,   375,   375,   376,
     376,   377,   377,   378,   379,   380,   381,   381,   382,   382,
     383,   383,   384,   384,   384,   384,   384,   384,   384,   384,
     384,   384,   384,   384,   384,   384,   384,   384,   384,   385,
     386,   387,   387,   388,   388,   388,   389,   389,   390,   390,
     391,   392,   392,   392,   393,   393,   393,   393,   393,   394,
     394,   395,   395,   396,   397,   397,   398,   398,   398,   398,
     398,   398,   398,   398,   399,   400,   401,   402,   402,   403,
     403,   404,   404,   404,   404,   405,   405,   406,   406,   406,
     407,   407,   407,   408,   408,   408,   409,   410,   411,   412,
     412,   413,   413,   414,   415,   415,   416,   416,   417,   417,
     418,   418,   418,   418,   418,   418,   418,   419,   419,   420,
     420,   421,   422,   422,   423,   423,   424,   424,   425,   425,
     426,   426,   427,   427,   428,   429,   429,   430,   430,   431,
     431,   431,   431,   431,   432,   431,   431,   431,   431,   433,
     433,   434,   434,   435,   435,   436,   436,   436,   437,   437,
     437,   437,   437,   438,   438,   438,   439,   439,   439,   440,
     440,   441,   441,   442,   442,   443,   443,   444,   444,   445,
     445,   445,   445,   446,   446,   446,   447,   447,   447,   447,
     447,   447,   448,   448,   448,   449,   449,   449,   449,   450,
     450,   451,   451,   452,   452,   453,   453,   453,   453,   454,
     455,   455,   455,   456,   456,   457,   457,   457,   457,   458,
     458,   459,   459,   459,   459,   459,   459,   459,   460,   460,
     461,   461,   462,   462,   462,   462,   462,   463,   463,   464,
     464,   465,   465,   465,   466,   466,   467,   467,   468,   469,
     469,   469,   469,   469,   469,   469,   469,   470,   470,   471,
     471,   471,   472,   473,   473,   474,   475,   476,   477,   477,
     478,   478,   479,   479,   480,   480,   480,   481,   481,   481,
     481,   481,   481,   482,   482,   483,   483,   484,   485,   485,
     486,   486,   487,   487,   488,   488,   488,   488,   489,   489,
     490,   490,   490,   490,   491,   491,   492,   492,   493,   493,
     493,   493,   494,   494,   494,   494,   495,   495,   496,   496,
     497,   498,   498,   498,   498,   498,   498,   499,   500,   500,
     500,   500,   501,   501,   501,   501,   502,   503,   504,   504,
     504,   504,   505,   505,   506,   507,   507,   507,   508,   508,
     508,   509,   509,   509,   510,   511,   511,   511,   511,   511,
     511,   511,   511,   511,   512,   513,   513,   513,   514,   515,
     516,   516,   516,   517,   517,   517,   517,   517,   518,   519,
     519,   519,   519,   519,   519,   519,   520,   521,   522,   523,
     524,   524,   524,   525,   525,   525,   525,   525,   525,   525,
     525,   525,   525,   526,   526,   527,   527,   528,   529,   530,
     530,   531,   532,   533,   533,   534,   534,   534,   534,   535,
     535,   536,   537,   537,   538,   538,   539,   539,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   541,   542,
     542,   543,   543,   544,   544,   545,   545,   546,   546,   547,
     547,   548,   549,   549,   550,   550,   551,   552,   552,   552,
     553,   553,   554,   555,   556,   556,   557,   557,   558,   558,
     558,   559,   559,   560,   560,   561,   561,   561,   561,   561,
     562,   563,   564,   565,   565,   565,   566,   566,   567,   567,
     567,   567,   567,   567,   567,   567,   568,   568,   568,   568,
     569,   569,   570,   571,   571,   572,   572,   572,   573,   573,
     574,   574,   575,   575,   576,   577,   577,   578,   578,   579,
     579,   579,   580,   580,   581,   581,   582,   582,   583,   583,
     584,   584,   585,   586,   586,   587,   587,   587,   588,   589,
     589,   589,   589,   590,   590,   591,   591,   592
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     1,     2,     1,     2,     4,     6,
       2,     1,     1,     2,     6,     2,     2,     4,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     3,     3,     5,     5,     4,     3,     3,     3,     5,
       5,     5,     5,     5,     5,     4,     3,     3,     4,     5,
       6,     1,     3,     3,     3,     3,     6,     5,     8,     4,
       3,     1,     1,     1,     2,     2,     2,     3,     5,     4,
       6,     1,     2,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     2,     2,     2,     3,     4,     5,     6,     4,
       5,     6,     7,     1,     2,     3,     3,     8,     9,     1,
       3,     3,     4,    11,    14,    13,    22,     3,     3,     2,
       3,     4,     5,     2,     4,     3,     0,     3,     2,     1,
       3,     5,     3,     5,     2,     2,     2,     3,     3,     1,
       2,     2,     2,     4,     4,     6,     4,     4,     4,     1,
       3,     2,     3,     3,     3,     1,     1,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     1,     1,     2,     4,     3,     5,     4,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     2,     1,     4,     3,     4,     4,     5,
       4,     5,     5,     6,     3,     3,     3,     1,     4,     1,
       4,     3,     4,     4,     5,     4,     5,     1,     2,     3,
       1,     2,     1,     6,     3,     3,     1,     2,     3,     1,
       3,     2,     3,     2,     3,     4,     1,     3,     1,     2,
       1,     1,     1,     2,     2,     2,     3,     1,     1,     2,
       2,     2,     5,     5,     1,     4,     3,     4,     8,    10,
       1,     2,     4,     7,     8,     1,     3,     1,     3,     1,
       3,     3,     3,     3,     0,     4,     3,     3,     3,     1,
       4,     0,     1,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       4,     1,     4,     1,     4,     1,     4,     1,     2,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     5,     5,     6,     3,
       4,     1,     2,     3,     2,     1,     2,     2,     1,     1,
       1,     3,     3,     1,     1,     1,     2,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     1,     4,     4,     3,     4,
       1,     3,     1,     1,     1,     1,     1,     4,     5,     8,
       9,     9,    10,     1,     2,     1,     2,     6,     0,     1,
       3,     3,     0,     1,     1,     1,     2,     2,     0,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     3,     3,
       2,     1,     1,     1,     1,     1,     1,     4,     4,     5,
       6,     7,     4,     5,     6,     7,     4,     4,     4,     5,
       6,     7,     1,     2,     2,     1,     2,     3,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     4,     4,     3,     3,
       3,     4,     4,     3,     4,     6,     4,     6,     3,     3,
       4,     6,     6,     4,     6,     6,     4,     1,     2,     1,
       3,     3,     3,     5,     7,     7,     5,     5,     5,     7,
       7,     5,     5,     3,     3,     5,     7,     5,     7,     1,
       4,     3,     5,     1,     2,     3,     7,    10,    13,     1,
       3,     1,     1,     1,     1,     1,     7,     4,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     2,     0,
       1,     1,     2,     1,     3,     1,     3,     1,     4,     1,
       2,     3,     0,     1,     0,     1,     2,     2,     3,     1,
       0,     1,     1,     2,     1,     3,     0,     1,     2,     2,
       1,     0,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       2,     2,     3,     2,     2,     3,     6,     2,     1,     1,
       0,     1,     1,     3,     4,     0,     2,     0,     2,     5,
       5,     3,     2,     3,     1,     3,     0,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     3,     2,
       3,     3,     4,     2,     2,     1,     1,     3
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
  "\"'order'\"", "\"'ordered'\"", "\"'by'\"", "\"'group'\"",
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
  "\"'copy'\"", "\"'with'\"", "\"'block'\"", "\"'break'\"",
  "\"'continue'\"", "\"'exit'\"", "\"'loop'\"", "\"'returning'\"",
  "\"'while'\"", "\"'try'\"", "\"'catch'\"", "\"'using'\"", "\"'all'\"",
  "\"'any'\"", "\"'content'\"", "\"'diacritics'\"", "\"'different'\"",
  "\"'distance'\"", "\"'end'\"", "\"'entire'\"", "\"'exactly'\"",
  "\"'from'\"", "\"'ftand'\"", "\"'ftcontains'\"", "\"'not'\"",
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
  "\"'equality'\"", "\"'integrity'\"", "\"'constraint'\"", "\"'check'\"",
  "\"'key'\"", "\"'foreach'\"", "\"'foreign'\"", "\"'keys'\"",
  "\"'BOM_UTF8'\"", "FTCONTAINS_REDUCE", "RANGE_REDUCE", "ADDITIVE_REDUCE",
  "MULTIPLICATIVE_REDUCE", "UNION_REDUCE", "INTERSECT_EXCEPT_REDUCE",
  "QVARINDECLLIST_REDUCE", "COMMA_DOLLAR", "UNARY_PREC",
  "SEQUENCE_TYPE_REDUCE", "OCCURS_STAR", "OCCURS_PLUS", "OCCURS_HOOK",
  "STEP_REDUCE", "$accept", "Module", "ModuleWithoutBOM", "VersionDecl",
  "MainModule", "LibraryModule", "ModuleDecl", "Prolog", "SIND_DeclList",
  "VFO_DeclList", "SIND_Decl", "VFO_Decl", "DecimalFormatDecl",
  "DecimalFormatParamList", "DecimalFormatParam", "DecimalFormatParamName",
  "Setter", "Import", "NamespaceDecl", "BoundarySpaceDecl",
  "DefaultNamespaceDecl", "OptionDecl", "FTOptionDecl", "OrderingModeDecl",
  "EmptyOrderDecl", "CopyNamespacesDecl", "DefaultCollationDecl",
  "BaseURIDecl", "SchemaImport", "URILiteralList", "SchemaPrefix",
  "ModuleImport", "CtxItemDecl", "CtxItemDecl2", "CtxItemDecl3",
  "CtxItemDecl4", "VarNameAndType", "VarDecl", "DeclPropertyList",
  "DeclProperty", "CollectionDecl", "CollectionTypeDecl", "NodeModifier",
  "IndexDecl", "IndexKeyList", "IndexKeySpec", "IntegrityConstraintDecl",
  "ConstructionDecl", "FunctionSig", "BlockExpr", "Block", "BlockDecls",
  "BlockVarDeclList", "BlockVarDecl", "AssignExpr", "ExitExpr",
  "WhileExpr", "FlowCtlStatement", "FunctionDecl", "FunctionDecl2",
  "FunctionDecl3", "FunctionDeclUpdating", "FunctionDecl4", "ParamList",
  "Param", "EnclosedExpr", "BracedExpr", "QueryBody", "Expr", "ApplyExpr",
  "ConcatExpr", "ExprSingle", "FLWORExpr", "ReturnExpr", "WindowType",
  "FLWORWinCondType", "FLWORWinCond", "WindowClause", "CountClause",
  "ForLetWinClause", "FLWORClause", "FLWORClauseList", "ForDollar",
  "ForClause", "VarInDeclList", "VarInDecl", "PositionalVar", "FTScoreVar",
  "LetClause", "VarGetsDeclList", "EvalVarDeclList", "VarGetsDecl",
  "WindowVarDecl", "WindowVars", "WindowVars3", "WindowVars2",
  "EvalVarDecl", "WhereClause", "GroupByClause", "GroupSpecList",
  "GroupSpec", "GroupCollationSpec", "OrderByClause", "OrderSpecList",
  "OrderSpec", "OrderModifier", "OrderDirSpec", "OrderEmptySpec",
  "OrderCollationSpec", "QuantifiedExpr", "QVarInDeclList", "QVarInDecl",
  "TypeswitchExpr", "CaseClauseList", "CaseClause", "IfExpr", "OrExpr",
  "AndExpr", "ComparisonExpr", "$@1", "FTContainsExpr",
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
  "AtomicType", "KindTest", "AnyKindTest", "DocumentTest", "TextTest",
  "CommentTest", "PITest", "AttributeTest", "SchemaAttributeTest",
  "ElementTest", "SchemaElementTest", "TypeName", "TypeName_WITH_HOOK",
  "StringLiteral", "RevalidationDecl", "InsertExpr", "DeleteExpr",
  "ReplaceExpr", "RenameExpr", "TransformExpr", "VarNameList",
  "VarNameDecl", "TryExpr", "CatchListExpr", "CatchExpr", "NameTestList",
  "URI_LITERAL", "NCNAME", "QNAME", "EvalExpr", "KEYWORD", "FTSelection",
  "opt_FTPosFilter_list", "FTPosFilter_list", "FTOr", "FTAnd", "FTMildNot",
  "FTUnaryNot", "FTPrimaryWithOptions", "opt_FTMatchOptions",
  "opt_FTWeight", "FTWeight", "FTPrimary", "opt_FTTimes",
  "FTExtensionSelection", "FTWords", "FTWordsValue", "opt_FTAnyallOption",
  "FTAnyallOption", "opt_word", "opt_words", "FTPosFilter", "FTOrder",
  "FTWindow", "FTDistance", "FTUnit", "FTMatchOptions", "FTMatchOption",
  "FTCaseOption", "FTDiacriticsOption", "FTExtensionOption",
  "FTStemOption", "FTThesaurusOption", "FTThesaurusID_or_default",
  "opt_FTThesaurus_list", "FTThesaurus_list", "FTThesaurusID",
  "opt_relationship", "opt_levels", "FTStopWordOption", "FTStopWords",
  "STRING_LITERAL_list", "opt_FTStopWordsInclExcl_list",
  "FTStopWordsInclExcl_list", "FTStopWordsInclExcl", "FTLanguageOption",
  "FTWildCardOption", "FTContent", "FTTimes", "FTRange", "FTScope",
  "FTBigUnit", "FTIgnoreOption", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       314,     0,    -1,   315,    -1,   298,   315,    -1,   317,    -1,
     316,   317,    -1,   318,    -1,   316,   318,    -1,   203,   204,
      20,   179,    -1,   203,   204,    20,   121,    20,   179,    -1,
     320,   380,    -1,   380,    -1,   319,    -1,   319,   320,    -1,
      26,   149,   537,   122,   536,   179,    -1,   321,   179,    -1,
     322,   179,    -1,   321,   179,   322,   179,    -1,   323,    -1,
     321,   179,   323,    -1,   324,    -1,   322,   179,   324,    -1,
     329,    -1,   330,    -1,   331,    -1,   333,    -1,   350,    -1,
     353,    -1,   345,    -1,   325,    -1,   335,    -1,   371,    -1,
     356,    -1,   359,    -1,   334,    -1,    25,   105,    71,   326,
      -1,    25,    71,   538,   326,    -1,   327,    -1,   326,   327,
      -1,   328,   122,   523,    -1,    72,    -1,    80,    -1,    73,
      -1,    74,    -1,    75,    -1,    76,    -1,    81,    -1,    77,
      -1,    78,    -1,    79,    -1,   332,    -1,   339,    -1,   340,
      -1,   360,    -1,   336,    -1,   337,    -1,   338,    -1,   524,
      -1,   341,    -1,   344,    -1,    25,   149,   537,   122,   536,
      -1,    25,    70,   170,    -1,    25,    70,   184,    -1,    25,
     105,    30,   149,   536,    -1,    25,   105,    34,   149,   536,
      -1,    25,    46,   538,    20,    -1,    25,   250,   566,    -1,
      25,    63,   158,    -1,    25,    63,   190,    -1,    25,   105,
     157,   117,   118,    -1,    25,   105,   157,   117,   119,    -1,
      25,    67,   170,    99,   137,    -1,    25,    67,   170,    99,
     154,    -1,    25,    67,   155,    99,   137,    -1,    25,    67,
     155,    99,   154,    -1,    25,   105,    98,   536,    -1,    25,
      64,   536,    -1,    41,    48,   536,    -1,    41,    48,   343,
     536,    -1,    41,    48,   536,    88,   342,    -1,    41,    48,
     343,   536,    88,   342,    -1,   536,    -1,   342,    99,   536,
      -1,   149,   537,   122,    -1,   105,    30,   149,    -1,    41,
      26,   536,    -1,    41,    26,   149,   537,   122,   536,    -1,
      41,    26,   536,    88,   342,    -1,    41,    26,   149,   537,
     122,   536,    88,   342,    -1,    25,   103,   141,   346,    -1,
      86,   509,   347,    -1,   347,    -1,   348,    -1,   127,    -1,
     127,   348,    -1,   132,   384,    -1,   110,   538,    -1,   110,
     538,   506,    -1,    25,   104,   349,   132,   384,    -1,    25,
     104,   349,   127,    -1,    25,   104,   349,   127,   132,   384,
      -1,   352,    -1,   351,   352,    -1,   277,    -1,   278,    -1,
     279,    -1,   280,    -1,   158,    -1,   190,    -1,   219,   290,
      -1,   219,   289,    -1,   282,    -1,   283,   282,    -1,   286,
     287,    -1,   285,   287,    -1,    25,   276,   538,    -1,    25,
     276,   538,   355,    -1,    25,   276,   538,    86,   354,    -1,
      25,   276,   538,    86,   354,   355,    -1,    25,   351,   276,
     538,    -1,    25,   351,   276,   538,   355,    -1,    25,   351,
     276,   538,    86,   354,    -1,    25,   351,   276,   538,    86,
     354,   355,    -1,   511,    -1,   511,   508,    -1,   226,   281,
     216,    -1,   226,   280,   216,    -1,    25,   284,   538,   288,
     216,   453,   159,   357,    -1,    25,   351,   284,   538,   288,
     216,   453,   159,   357,    -1,   358,    -1,   357,    99,   358,
      -1,   453,    86,   510,    -1,   453,    86,   510,   421,    -1,
      25,   291,   292,   538,   288,   276,   538,   110,   538,   293,
     384,    -1,    25,   291,   292,   538,   288,   276,   538,   214,
     110,   538,   293,   282,   294,   453,    -1,    25,   291,   292,
     538,   288,   276,   538,   295,   214,   110,   538,   293,   384,
      -1,    25,   291,   292,   538,   296,   294,   246,   276,   538,
     214,   110,   538,   294,   453,   187,   276,   538,   214,   110,
     538,   294,   453,    -1,    25,    52,   170,    -1,    25,    52,
     184,    -1,   145,   175,    -1,   145,   376,   175,    -1,   145,
     175,    86,   507,    -1,   145,   376,   175,    86,   507,    -1,
     227,   363,    -1,   142,   364,   381,   172,    -1,   364,   365,
     179,    -1,    -1,   365,    99,   366,    -1,    25,   366,    -1,
     349,    -1,   349,   132,   384,    -1,    50,   110,   538,   132,
     384,    -1,   230,   232,   384,    -1,   233,   145,   384,   175,
     363,    -1,   228,   231,    -1,   229,   231,    -1,    25,   372,
      -1,    25,    38,   372,    -1,    25,    37,   372,    -1,   373,
      -1,    39,   373,    -1,    35,   374,    -1,    36,   375,    -1,
      34,   538,   361,   379,    -1,    34,   538,   361,   127,    -1,
      34,   538,   361,   142,   383,   172,    -1,    34,   538,   361,
     127,    -1,    34,   538,   361,   363,    -1,    34,   538,   361,
     127,    -1,   377,    -1,   376,    99,   377,    -1,   110,   538,
      -1,   110,   538,   506,    -1,   142,   381,   172,    -1,   142,
     381,   172,    -1,   381,    -1,   383,    -1,   383,   382,    -1,
     179,    -1,   382,   383,   179,    -1,   384,    -1,   383,    99,
     384,    -1,   385,    -1,   422,    -1,   425,    -1,   428,    -1,
     429,    -1,   525,    -1,   526,    -1,   528,    -1,   527,    -1,
     529,    -1,   532,    -1,   539,    -1,   368,    -1,   369,    -1,
     370,    -1,   367,    -1,   362,    -1,   394,   386,    -1,   174,
     384,    -1,    56,   273,    -1,    57,   273,    -1,   206,    -1,
     243,    -1,    60,   243,    -1,   388,   406,    61,   384,    -1,
     388,    61,   384,    -1,    54,   387,   405,   389,   389,    -1,
      54,   387,   405,   389,    -1,    62,   110,   538,    -1,   396,
      -1,   401,    -1,   390,    -1,   392,    -1,   410,    -1,   415,
      -1,   411,    -1,   391,    -1,   392,    -1,   394,   393,    -1,
      54,   110,    -1,    55,    54,   110,    -1,   395,   397,    -1,
     398,    -1,   397,    99,   110,   398,    -1,   538,   136,   384,
      -1,   538,   506,   136,   384,    -1,   538,   399,   136,   384,
      -1,   538,   506,   399,   136,   384,    -1,   538,   400,   136,
     384,    -1,   538,   506,   400,   136,   384,    -1,   538,   399,
     400,   136,   384,    -1,   538,   506,   399,   400,   136,   384,
      -1,    88,   110,   538,    -1,   262,   110,   538,    -1,    51,
     110,   402,    -1,   404,    -1,   402,    99,   110,   404,    -1,
     409,    -1,   403,    99,   110,   409,    -1,   538,   132,   384,
      -1,   538,   506,   132,   384,    -1,   538,   400,   132,   384,
      -1,   538,   506,   400,   132,   384,    -1,   110,   538,   136,
     384,    -1,   110,   538,   506,   136,   384,    -1,   407,    -1,
     110,   538,    -1,   110,   538,   407,    -1,   399,    -1,   399,
     408,    -1,   408,    -1,    58,   110,   538,    59,   110,   538,
      -1,    59,   110,   538,    -1,    58,   110,   538,    -1,   538,
      -1,   200,   384,    -1,   160,   159,   412,    -1,   413,    -1,
     412,    99,   413,    -1,   110,   538,    -1,   110,   538,   414,
      -1,    98,   536,    -1,   157,   159,   416,    -1,    45,   157,
     159,   416,    -1,   417,    -1,   416,    99,   417,    -1,   384,
      -1,   384,   418,    -1,   419,    -1,   420,    -1,   421,    -1,
     419,   420,    -1,   419,   421,    -1,   420,   421,    -1,   419,
     420,   421,    -1,    87,    -1,   108,    -1,   117,   118,    -1,
     117,   119,    -1,    98,   536,    -1,    44,   110,   423,   176,
     384,    -1,   125,   110,   423,   176,   384,    -1,   424,    -1,
     423,    99,   110,   424,    -1,   538,   136,   384,    -1,   538,
     506,   136,   384,    -1,    29,   145,   381,   175,   426,   105,
     174,   384,    -1,    29,   145,   381,   175,   426,   105,   110,
     538,   174,   384,    -1,   427,    -1,   426,   427,    -1,    92,
     507,   174,   384,    -1,    92,   110,   538,    86,   507,   174,
     384,    -1,    40,   145,   381,   175,   186,   384,   116,   384,
      -1,   430,    -1,   429,   156,   430,    -1,   431,    -1,   430,
      84,   431,    -1,   433,    -1,   433,   447,   433,    -1,   433,
     448,   433,    -1,   433,   122,   433,    -1,   433,   151,   433,
      -1,    -1,   433,   146,   432,   433,    -1,   433,   144,   433,
      -1,   433,   133,   433,    -1,   433,   131,   433,    -1,   435,
      -1,   435,   248,   541,   434,    -1,    -1,   592,    -1,   436,
      -1,   436,   187,   436,    -1,   437,    -1,   436,   164,   437,
      -1,   436,   147,   437,    -1,   438,    -1,   437,   182,   438,
      -1,   437,   109,   438,    -1,   437,   135,   438,    -1,   437,
     148,   438,    -1,   439,    -1,   438,   189,   439,    -1,   438,
     198,   439,    -1,   440,    -1,   439,   139,   440,    -1,   439,
     126,   440,    -1,   441,    -1,   441,    68,   220,   507,    -1,
     442,    -1,   442,   188,    86,   507,    -1,   443,    -1,   443,
      93,    86,   505,    -1,   444,    -1,   444,    94,    86,   505,
      -1,   446,    -1,   445,   446,    -1,   164,    -1,   147,    -1,
     445,   164,    -1,   445,   147,    -1,   449,    -1,   453,    -1,
     450,    -1,   191,    -1,   196,    -1,   195,    -1,   194,    -1,
     193,    -1,   192,    -1,   140,    -1,   167,    -1,   130,    -1,
      28,   142,   381,   172,    -1,    28,   211,   142,   381,   172,
      -1,    28,   210,   142,   381,   172,    -1,    28,    86,   521,
     142,   381,   172,    -1,   451,   142,   172,    -1,   451,   142,
     381,   172,    -1,   452,    -1,   451,   452,    -1,   165,   538,
      15,    -1,   165,    16,    -1,   454,    -1,   454,   455,    -1,
     181,   455,    -1,   455,    -1,   180,    -1,   456,    -1,   456,
     180,   455,    -1,   456,   181,   455,    -1,   457,    -1,   466,
      -1,   458,    -1,   458,   467,    -1,   461,    -1,   461,   467,
      -1,   459,   463,    -1,   460,    -1,    97,    -1,   106,    -1,
      90,    -1,   178,    -1,   107,    -1,   129,    -1,   128,    -1,
     463,    -1,    91,   463,    -1,   462,   463,    -1,   112,    -1,
     161,    -1,    82,    -1,   169,    -1,   168,    -1,    83,    -1,
     511,    -1,   464,    -1,   538,    -1,   465,    -1,   182,    -1,
      10,    -1,    17,    -1,   469,    -1,   469,   467,    -1,   468,
      -1,   467,   468,    -1,   143,   381,   173,    -1,   470,    -1,
     472,    -1,   473,    -1,   474,    -1,   477,    -1,   479,    -1,
     475,    -1,   476,    -1,   471,    -1,   523,    -1,   102,    -1,
     138,    -1,   114,    -1,   110,   538,    -1,   145,   175,    -1,
     145,   381,   175,    -1,   111,    -1,   158,   142,   381,   172,
      -1,   190,   142,   381,   172,    -1,   538,   145,   175,    -1,
     538,   145,   478,   175,    -1,   384,    -1,   478,    99,   384,
      -1,   480,    -1,   498,    -1,   481,    -1,   495,    -1,   496,
      -1,   146,   538,   485,   120,    -1,   146,   538,   483,   485,
     120,    -1,   146,   538,   485,   185,   183,   538,   485,   185,
      -1,   146,   538,   485,   185,   482,   183,   538,   485,   185,
      -1,   146,   538,   483,   485,   185,   183,   538,   485,   185,
      -1,   146,   538,   483,   485,   185,   482,   183,   538,   485,
     185,    -1,   493,    -1,   482,   493,    -1,   484,    -1,   483,
     484,    -1,    27,   538,   485,   122,   485,   486,    -1,    -1,
      27,    -1,   171,   487,   171,    -1,    85,   489,    85,    -1,
      -1,   488,    -1,   124,    -1,   491,    -1,   488,   124,    -1,
     488,   491,    -1,    -1,   490,    -1,   123,    -1,   492,    -1,
     490,   123,    -1,   490,   492,    -1,    19,    -1,   494,    -1,
       4,    -1,   494,    -1,   480,    -1,     9,    -1,   497,    -1,
     494,    -1,     8,    -1,   113,    -1,   115,    -1,   378,    -1,
     201,    21,   202,    -1,   201,   202,    -1,   162,   537,   163,
      -1,   162,   537,     7,    -1,    95,     6,    -1,   499,    -1,
     500,    -1,   501,    -1,   502,    -1,   503,    -1,   504,    -1,
      31,   142,   381,   172,    -1,    30,   538,   142,   172,    -1,
      30,   538,   142,   381,   172,    -1,    30,   142,   381,   172,
     142,   172,    -1,    30,   142,   381,   172,   142,   381,   172,
      -1,    89,   538,   142,   172,    -1,    89,   538,   142,   381,
     172,    -1,    89,   142,   381,   172,   142,   172,    -1,    89,
     142,   381,   172,   142,   381,   172,    -1,    32,   142,   381,
     172,    -1,    33,   142,   381,   172,    -1,    42,   537,   142,
     172,    -1,    42,   537,   142,   381,   172,    -1,    42,   142,
     381,   172,   142,   172,    -1,    42,   142,   381,   172,   142,
     381,   172,    -1,   510,    -1,   510,   134,    -1,    86,   507,
      -1,   509,    -1,   509,   508,    -1,   199,   145,   175,    -1,
     134,    -1,   182,    -1,   164,    -1,   510,    -1,   511,    -1,
     141,   145,   175,    -1,   538,    -1,   513,    -1,   519,    -1,
     517,    -1,   520,    -1,   518,    -1,   516,    -1,   515,    -1,
     514,    -1,   512,    -1,   214,   145,   175,    -1,    66,   145,
     175,    -1,    66,   145,   519,   175,    -1,    66,   145,   520,
     175,    -1,    32,   145,   175,    -1,    33,   145,   175,    -1,
      42,   145,   175,    -1,    42,   145,   537,   175,    -1,    42,
     145,    20,   175,    -1,    89,   145,   175,    -1,    89,   145,
     538,   175,    -1,    89,   145,   538,    99,   521,   175,    -1,
      89,   145,   182,   175,    -1,    89,   145,   182,    99,   521,
     175,    -1,   177,   538,   175,    -1,    30,   145,   175,    -1,
      30,   145,   538,   175,    -1,    30,   145,   538,    99,   521,
     175,    -1,    30,   145,   538,    99,   522,   175,    -1,    30,
     145,   182,   175,    -1,    30,   145,   182,    99,   521,   175,
      -1,    30,   145,   182,    99,   522,   175,    -1,    65,   145,
     538,   175,    -1,   538,    -1,   538,   134,    -1,    20,    -1,
      25,   209,   210,    -1,    25,   209,   211,    -1,    25,   209,
     212,    -1,   215,   214,   384,   222,   384,    -1,   215,   214,
     384,    86,   221,   222,   384,    -1,   215,   214,   384,    86,
     223,   222,   384,    -1,   215,   214,   384,   207,   384,    -1,
     215,   214,   384,   208,   384,    -1,   215,   216,   384,   222,
     384,    -1,   215,   216,   384,    86,   221,   222,   384,    -1,
     215,   216,   384,    86,   223,   222,   384,    -1,   215,   216,
     384,   207,   384,    -1,   215,   216,   384,   208,   384,    -1,
     213,   214,   384,    -1,   213,   216,   384,    -1,   218,   214,
     384,   226,   384,    -1,   218,   219,   220,   214,   384,   226,
     384,    -1,   217,   214,   384,    86,   384,    -1,   225,   110,
     530,   224,   384,   174,   384,    -1,   531,    -1,   530,    99,
     110,   531,    -1,   538,   132,   384,    -1,   234,   142,   381,
     172,   533,    -1,   534,    -1,   533,   534,    -1,   235,   535,
     379,    -1,   235,   535,   145,   110,   538,   175,   379,    -1,
     235,   535,   145,   110,   538,    99,   110,   538,   175,   379,
      -1,   235,   535,   145,   110,   538,    99,   110,   538,    99,
     110,   538,   175,   379,    -1,   464,    -1,   535,   198,   464,
      -1,    20,    -1,    14,    -1,   538,    -1,    18,    -1,   540,
      -1,   236,   110,   403,    53,   142,   384,   172,    -1,    53,
     142,   384,   172,    -1,   203,    -1,   117,    -1,    89,    -1,
      33,    -1,    66,    -1,    30,    -1,   141,    -1,    40,    -1,
     214,    -1,    42,    -1,    69,    -1,    65,    -1,    32,    -1,
      29,    -1,   199,    -1,    70,    -1,   250,    -1,    64,    -1,
     211,    -1,   210,    -1,   135,    -1,    31,    -1,   249,    -1,
     263,    -1,   252,    -1,   240,    -1,   274,    -1,   266,    -1,
     268,    -1,   267,    -1,   272,    -1,   244,    -1,   239,    -1,
      47,    -1,   206,    -1,   243,    -1,    43,    -1,   212,    -1,
     225,    -1,   219,    -1,   191,    -1,   196,    -1,   195,    -1,
     194,    -1,   193,    -1,   192,    -1,    88,    -1,   103,    -1,
     104,    -1,   174,    -1,    54,    -1,    55,    -1,    56,    -1,
      57,    -1,    58,    -1,    59,    -1,    60,    -1,    61,    -1,
      62,    -1,   136,    -1,    51,    -1,   200,    -1,   159,    -1,
     160,    -1,   157,    -1,    45,    -1,    87,    -1,   108,    -1,
     118,    -1,   119,    -1,    98,    -1,    44,    -1,   125,    -1,
     176,    -1,    92,    -1,    86,    -1,   186,    -1,   116,    -1,
     156,    -1,    84,    -1,    68,    -1,   220,    -1,    93,    -1,
     187,    -1,   109,    -1,   148,    -1,   189,    -1,   139,    -1,
     126,    -1,    28,    -1,    94,    -1,   188,    -1,   140,    -1,
     170,    -1,   184,    -1,   149,    -1,   127,    -1,   121,    -1,
     155,    -1,   137,    -1,   154,    -1,    25,    -1,    52,    -1,
      63,    -1,   105,    -1,    67,    -1,    46,    -1,   204,    -1,
      41,    -1,    48,    -1,    26,    -1,    34,    -1,   262,    -1,
     248,    -1,   271,    -1,   273,    -1,   242,    -1,   256,    -1,
     269,    -1,   261,    -1,   241,    -1,   255,    -1,   270,    -1,
     260,    -1,   254,    -1,   253,    -1,   238,    -1,   237,    -1,
     259,    -1,   245,    -1,   246,    -1,   275,    -1,   265,    -1,
     264,    -1,   257,    -1,   218,    -1,   224,    -1,   221,    -1,
     215,    -1,   208,    -1,   207,    -1,   209,    -1,   226,    -1,
     216,    -1,   217,    -1,   223,    -1,   213,    -1,   222,    -1,
      39,    -1,    36,    -1,    35,    -1,    37,    -1,    38,    -1,
     158,    -1,   190,    -1,   232,    -1,   227,    -1,   230,    -1,
     231,    -1,   233,    -1,   228,    -1,   229,    -1,   234,    -1,
     235,    -1,    53,    -1,   236,    -1,    50,    -1,   284,    -1,
     282,    -1,   283,    -1,   288,    -1,   289,    -1,   290,    -1,
     285,    -1,   286,    -1,   287,    -1,    71,    -1,    72,    -1,
      73,    -1,    74,    -1,    75,    -1,    76,    -1,    77,    -1,
      78,    -1,    79,    -1,    80,    -1,    81,    -1,   276,    -1,
     277,    -1,   278,    -1,   279,    -1,   280,    -1,   281,    -1,
     291,    -1,   292,    -1,   293,    -1,   294,    -1,   295,    -1,
     296,    -1,   297,    -1,   544,   542,    -1,    -1,   543,    -1,
     561,    -1,   543,   561,    -1,   545,    -1,   544,   251,   545,
      -1,   546,    -1,   545,   247,   546,    -1,   547,    -1,   546,
     249,   136,   547,    -1,   548,    -1,   249,   548,    -1,   552,
     549,   550,    -1,    -1,   566,    -1,    -1,   551,    -1,   271,
     435,    -1,   555,   553,    -1,   145,   541,   175,    -1,   554,
      -1,    -1,   588,    -1,   451,    -1,   556,   557,    -1,   470,
      -1,   142,   381,   172,    -1,    -1,   558,    -1,   238,   559,
      -1,   237,   560,    -1,   259,    -1,    -1,    47,    -1,    -1,
     275,    -1,   562,    -1,   563,    -1,   564,    -1,   590,    -1,
     587,    -1,   158,    -1,   273,   436,   565,    -1,   242,   589,
     565,    -1,   275,    -1,   265,    -1,   258,    -1,   567,    -1,
     566,   567,    -1,   568,    -1,   569,    -1,   570,    -1,   585,
      -1,   571,    -1,   579,    -1,   572,    -1,   586,    -1,    92,
     263,    -1,    92,   252,    -1,   255,    -1,   270,    -1,   240,
     263,    -1,   240,   252,    -1,    46,   538,    20,    -1,   226,
     266,    -1,   274,   266,    -1,   226,   268,   573,    -1,   226,
     268,   145,   573,   574,   175,    -1,   274,   268,    -1,   576,
      -1,   105,    -1,    -1,   575,    -1,   576,    -1,   575,    99,
     576,    -1,    88,    20,   577,   578,    -1,    -1,   260,    20,
      -1,    -1,   589,   254,    -1,   226,   267,   275,   580,   582,
      -1,   226,   105,   267,   275,   582,    -1,   274,   267,   275,
      -1,    88,    20,    -1,   145,   581,   175,    -1,    20,    -1,
     581,    99,    20,    -1,    -1,   583,    -1,   584,    -1,   583,
     584,    -1,   189,   580,    -1,   126,   580,    -1,   253,    20,
      -1,   226,   272,    -1,   274,   272,    -1,    88,   206,    -1,
      88,   243,    -1,   244,   239,    -1,   256,   589,   269,    -1,
     245,   436,    -1,    88,   119,   436,    -1,    88,    43,   436,
      -1,   246,   436,   187,   436,    -1,   261,   591,    -1,   241,
     591,    -1,   264,    -1,   257,    -1,   274,   239,   438,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    10,    13,    15,    18,    23,
      30,    33,    35,    37,    40,    47,    50,    53,    58,    60,
      64,    66,    70,    72,    74,    76,    78,    80,    82,    84,
      86,    88,    90,    92,    94,    96,   101,   106,   108,   111,
     115,   117,   119,   121,   123,   125,   127,   129,   131,   133,
     135,   137,   139,   141,   143,   145,   147,   149,   151,   153,
     155,   161,   165,   169,   175,   181,   186,   190,   194,   198,
     204,   210,   216,   222,   228,   234,   239,   243,   247,   252,
     258,   265,   267,   271,   275,   279,   283,   290,   296,   305,
     310,   314,   316,   318,   320,   323,   326,   329,   333,   339,
     344,   351,   353,   356,   358,   360,   362,   364,   366,   368,
     371,   374,   376,   379,   382,   385,   389,   394,   400,   407,
     412,   418,   425,   433,   435,   438,   442,   446,   455,   465,
     467,   471,   475,   480,   492,   507,   521,   544,   548,   552,
     555,   559,   564,   570,   573,   578,   582,   583,   587,   590,
     592,   596,   602,   606,   612,   615,   618,   621,   625,   629,
     631,   634,   637,   640,   645,   650,   657,   662,   667,   672,
     674,   678,   681,   685,   689,   693,   695,   697,   700,   702,
     706,   708,   712,   714,   716,   718,   720,   722,   724,   726,
     728,   730,   732,   734,   736,   738,   740,   742,   744,   746,
     749,   752,   755,   758,   760,   762,   765,   770,   774,   780,
     785,   789,   791,   793,   795,   797,   799,   801,   803,   805,
     807,   810,   813,   817,   820,   822,   827,   831,   836,   841,
     847,   852,   858,   864,   871,   875,   879,   883,   885,   890,
     892,   897,   901,   906,   911,   917,   922,   928,   930,   933,
     937,   939,   942,   944,   951,   955,   959,   961,   964,   968,
     970,   974,   977,   981,   984,   988,   993,   995,   999,  1001,
    1004,  1006,  1008,  1010,  1013,  1016,  1019,  1023,  1025,  1027,
    1030,  1033,  1036,  1042,  1048,  1050,  1055,  1059,  1064,  1073,
    1084,  1086,  1089,  1094,  1102,  1111,  1113,  1117,  1119,  1123,
    1125,  1129,  1133,  1137,  1141,  1142,  1147,  1151,  1155,  1159,
    1161,  1166,  1167,  1169,  1171,  1175,  1177,  1181,  1185,  1187,
    1191,  1195,  1199,  1203,  1205,  1209,  1213,  1215,  1219,  1223,
    1225,  1230,  1232,  1237,  1239,  1244,  1246,  1251,  1253,  1256,
    1258,  1260,  1263,  1266,  1268,  1270,  1272,  1274,  1276,  1278,
    1280,  1282,  1284,  1286,  1288,  1290,  1295,  1301,  1307,  1314,
    1318,  1323,  1325,  1328,  1332,  1335,  1337,  1340,  1343,  1345,
    1347,  1349,  1353,  1357,  1359,  1361,  1363,  1366,  1368,  1371,
    1374,  1376,  1378,  1380,  1382,  1384,  1386,  1388,  1390,  1392,
    1395,  1398,  1400,  1402,  1404,  1406,  1408,  1410,  1412,  1414,
    1416,  1418,  1420,  1422,  1424,  1426,  1429,  1431,  1434,  1438,
    1440,  1442,  1444,  1446,  1448,  1450,  1452,  1454,  1456,  1458,
    1460,  1462,  1464,  1467,  1470,  1474,  1476,  1481,  1486,  1490,
    1495,  1497,  1501,  1503,  1505,  1507,  1509,  1511,  1516,  1522,
    1531,  1541,  1551,  1562,  1564,  1567,  1569,  1572,  1579,  1580,
    1582,  1586,  1590,  1591,  1593,  1595,  1597,  1600,  1603,  1604,
    1606,  1608,  1610,  1613,  1616,  1618,  1620,  1622,  1624,  1626,
    1628,  1630,  1632,  1634,  1636,  1638,  1640,  1644,  1647,  1651,
    1655,  1658,  1660,  1662,  1664,  1666,  1668,  1670,  1675,  1680,
    1686,  1693,  1701,  1706,  1712,  1719,  1727,  1732,  1737,  1742,
    1748,  1755,  1763,  1765,  1768,  1771,  1773,  1776,  1780,  1782,
    1784,  1786,  1788,  1790,  1794,  1796,  1798,  1800,  1802,  1804,
    1806,  1808,  1810,  1812,  1814,  1818,  1822,  1827,  1832,  1836,
    1840,  1844,  1849,  1854,  1858,  1863,  1870,  1875,  1882,  1886,
    1890,  1895,  1902,  1909,  1914,  1921,  1928,  1933,  1935,  1938,
    1940,  1944,  1948,  1952,  1958,  1966,  1974,  1980,  1986,  1992,
    2000,  2008,  2014,  2020,  2024,  2028,  2034,  2042,  2048,  2056,
    2058,  2063,  2067,  2073,  2075,  2078,  2082,  2090,  2101,  2115,
    2117,  2121,  2123,  2125,  2127,  2129,  2131,  2139,  2144,  2146,
    2148,  2150,  2152,  2154,  2156,  2158,  2160,  2162,  2164,  2166,
    2168,  2170,  2172,  2174,  2176,  2178,  2180,  2182,  2184,  2186,
    2188,  2190,  2192,  2194,  2196,  2198,  2200,  2202,  2204,  2206,
    2208,  2210,  2212,  2214,  2216,  2218,  2220,  2222,  2224,  2226,
    2228,  2230,  2232,  2234,  2236,  2238,  2240,  2242,  2244,  2246,
    2248,  2250,  2252,  2254,  2256,  2258,  2260,  2262,  2264,  2266,
    2268,  2270,  2272,  2274,  2276,  2278,  2280,  2282,  2284,  2286,
    2288,  2290,  2292,  2294,  2296,  2298,  2300,  2302,  2304,  2306,
    2308,  2310,  2312,  2314,  2316,  2318,  2320,  2322,  2324,  2326,
    2328,  2330,  2332,  2334,  2336,  2338,  2340,  2342,  2344,  2346,
    2348,  2350,  2352,  2354,  2356,  2358,  2360,  2362,  2364,  2366,
    2368,  2370,  2372,  2374,  2376,  2378,  2380,  2382,  2384,  2386,
    2388,  2390,  2392,  2394,  2396,  2398,  2400,  2402,  2404,  2406,
    2408,  2410,  2412,  2414,  2416,  2418,  2420,  2422,  2424,  2426,
    2428,  2430,  2432,  2434,  2436,  2438,  2440,  2442,  2444,  2446,
    2448,  2450,  2452,  2454,  2456,  2458,  2460,  2462,  2464,  2466,
    2468,  2470,  2472,  2474,  2476,  2478,  2480,  2482,  2484,  2486,
    2488,  2490,  2492,  2494,  2496,  2498,  2500,  2502,  2504,  2506,
    2508,  2510,  2512,  2514,  2516,  2518,  2520,  2522,  2524,  2526,
    2528,  2530,  2532,  2534,  2536,  2538,  2540,  2542,  2544,  2547,
    2548,  2550,  2552,  2555,  2557,  2561,  2563,  2567,  2569,  2574,
    2576,  2579,  2583,  2584,  2586,  2587,  2589,  2592,  2595,  2599,
    2601,  2602,  2604,  2606,  2609,  2611,  2615,  2616,  2618,  2621,
    2624,  2626,  2627,  2629,  2630,  2632,  2634,  2636,  2638,  2640,
    2642,  2644,  2648,  2652,  2654,  2656,  2658,  2660,  2663,  2665,
    2667,  2669,  2671,  2673,  2675,  2677,  2679,  2682,  2685,  2687,
    2689,  2692,  2695,  2699,  2702,  2705,  2709,  2716,  2719,  2721,
    2723,  2724,  2726,  2728,  2732,  2737,  2738,  2741,  2742,  2745,
    2751,  2757,  2761,  2764,  2768,  2770,  2774,  2775,  2777,  2779,
    2782,  2785,  2788,  2791,  2794,  2797,  2800,  2803,  2806,  2810,
    2813,  2817,  2821,  2826,  2829,  2832,  2834,  2836
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   964,   964,   965,   974,   979,   986,   991,  1002,  1007,
    1015,  1023,  1031,  1037,  1049,  1058,  1062,  1066,  1078,  1084,
    1094,  1100,  1110,  1111,  1112,  1113,  1118,  1119,  1120,  1121,
    1122,  1123,  1124,  1125,  1126,  1131,  1136,  1147,  1153,  1162,
    1171,  1172,  1173,  1174,  1175,  1176,  1177,  1178,  1179,  1180,
    1185,  1186,  1187,  1188,  1189,  1190,  1191,  1194,  1199,  1200,
    1210,  1219,  1225,  1235,  1241,  1251,  1261,  1269,  1275,  1286,
    1291,  1301,  1307,  1313,  1319,  1336,  1344,  1352,  1356,  1365,
    1374,  1387,  1393,  1404,  1408,  1416,  1423,  1430,  1437,  1450,
    1457,  1463,  1470,  1476,  1480,  1487,  1498,  1505,  1516,  1522,
    1528,  1537,  1543,  1552,  1556,  1562,  1566,  1570,  1574,  1580,
    1586,  1592,  1596,  1602,  1608,  1615,  1623,  1631,  1639,  1647,
    1653,  1661,  1669,  1680,  1685,  1693,  1697,  1704,  1712,  1723,
    1729,  1737,  1744,  1754,  1764,  1774,  1784,  1801,  1807,  1818,
    1822,  1826,  1830,  1839,  1846,  1865,  1875,  1881,  1887,  1896,
    1903,  1913,  1923,  1930,  1942,  1946,  1953,  1958,  1965,  1973,
    1977,  1981,  1989,  1996,  2007,  2021,  2032,  2046,  2057,  2072,
    2078,  2088,  2095,  2108,  2115,  2123,  2138,  2142,  2156,  2160,
    2169,  2173,  2187,  2188,  2189,  2190,  2191,  2194,  2195,  2196,
    2197,  2198,  2200,  2201,  2204,  2205,  2206,  2207,  2208,  2213,
    2228,  2235,  2239,  2246,  2250,  2254,  2261,  2269,  2279,  2291,
    2306,  2317,  2318,  2319,  2323,  2324,  2325,  2326,  2327,  2330,
    2336,  2345,  2349,  2357,  2367,  2373,  2383,  2391,  2402,  2414,
    2427,  2438,  2450,  2462,  2478,  2489,  2500,  2508,  2514,  2523,
    2529,  2539,  2550,  2562,  2573,  2587,  2594,  2607,  2608,  2615,
    2625,  2631,  2638,  2642,  2653,  2661,  2671,  2686,  2693,  2700,
    2706,  2716,  2723,  2735,  2743,  2749,  2759,  2765,  2775,  2779,
    2789,  2795,  2801,  2807,  2816,  2825,  2834,  2847,  2851,  2859,
    2865,  2875,  2883,  2892,  2905,  2912,  2923,  2930,  2944,  2953,
    2968,  2974,  2985,  2991,  3006,  3015,  3019,  3027,  3031,  3039,
    3043,  3053,  3060,  3069,  3079,  3078,  3092,  3101,  3110,  3123,
    3127,  3139,  3142,  3150,  3154,  3163,  3167,  3171,  3180,  3184,
    3190,  3196,  3202,  3213,  3217,  3221,  3229,  3233,  3239,  3249,
    3253,  3263,  3267,  3277,  3281,  3291,  3295,  3305,  3309,  3317,
    3321,  3325,  3329,  3339,  3343,  3347,  3355,  3359,  3363,  3367,
    3371,  3375,  3383,  3387,  3391,  3399,  3403,  3407,  3411,  3421,
    3427,  3437,  3443,  3453,  3457,  3495,  3501,  3507,  3513,  3524,
    3532,  3543,  3549,  3559,  3563,  3571,  3577,  3585,  3591,  3603,
    3609,  3619,  3623,  3627,  3631,  3635,  3641,  3647,  3655,  3659,
    3667,  3671,  3682,  3686,  3690,  3696,  3700,  3714,  3718,  3726,
    3730,  3738,  3742,  3748,  3758,  3762,  3772,  3778,  3788,  3796,
    3800,  3804,  3808,  3812,  3816,  3820,  3824,  3832,  3836,  3844,
    3851,  3858,  3869,  3878,  3882,  3890,  3898,  3906,  3960,  3964,
    3976,  3982,  3992,  3996,  4004,  4008,  4012,  4020,  4030,  4040,
    4050,  4060,  4070,  4085,  4091,  4102,  4108,  4119,  4130,  4132,
    4136,  4141,  4151,  4154,  4161,  4169,  4175,  4185,  4198,  4201,
    4208,  4214,  4220,  4227,  4238,  4242,  4252,  4256,  4266,  4270,
    4274,  4279,  4288,  4294,  4300,  4306,  4316,  4320,  4332,  4336,
    4348,  4360,  4364,  4368,  4372,  4376,  4380,  4388,  4396,  4402,
    4408,  4412,  4429,  4433,  4437,  4441,  4449,  4457,  4465,  4469,
    4473,  4477,  4485,  4491,  4501,  4509,  4513,  4519,  4554,  4560,
    4566,  4576,  4580,  4584,  4592,  4600,  4604,  4608,  4612,  4616,
    4620,  4624,  4628,  4632,  4640,  4648,  4652,  4656,  4666,  4674,
    4682,  4686,  4690,  4698,  4702,  4708,  4714,  4718,  4728,  4736,
    4740,  4746,  4755,  4764,  4770,  4776,  4786,  4803,  4810,  4825,
    4862,  4868,  4874,  4884,  4888,  4894,  4900,  4904,  4910,  4914,
    4920,  4926,  4933,  4943,  4948,  4956,  4962,  4972,  4992,  5001,
    5007,  5018,  5035,  5042,  5048,  5058,  5063,  5071,  5083,  5100,
    5106,  5116,  5126,  5127,  5145,  5149,  5162,  5168,  5175,  5176,
    5177,  5178,  5179,  5180,  5181,  5182,  5183,  5184,  5185,  5186,
    5187,  5188,  5189,  5190,  5191,  5192,  5193,  5194,  5195,  5196,
    5197,  5198,  5199,  5200,  5201,  5202,  5203,  5204,  5205,  5206,
    5207,  5208,  5209,  5210,  5211,  5212,  5213,  5214,  5215,  5216,
    5217,  5218,  5219,  5220,  5221,  5222,  5223,  5224,  5225,  5226,
    5227,  5228,  5229,  5230,  5231,  5232,  5233,  5234,  5235,  5236,
    5237,  5238,  5239,  5240,  5241,  5242,  5243,  5244,  5245,  5246,
    5247,  5248,  5249,  5250,  5251,  5252,  5253,  5254,  5255,  5256,
    5257,  5258,  5259,  5260,  5261,  5262,  5263,  5264,  5265,  5266,
    5267,  5268,  5269,  5270,  5271,  5272,  5273,  5274,  5275,  5276,
    5277,  5278,  5279,  5280,  5281,  5282,  5283,  5284,  5285,  5286,
    5287,  5288,  5289,  5290,  5291,  5292,  5293,  5294,  5295,  5296,
    5297,  5298,  5299,  5300,  5301,  5302,  5303,  5304,  5305,  5306,
    5307,  5308,  5309,  5310,  5311,  5312,  5313,  5314,  5315,  5316,
    5317,  5318,  5319,  5320,  5321,  5322,  5323,  5324,  5325,  5326,
    5327,  5328,  5329,  5330,  5331,  5332,  5333,  5334,  5335,  5336,
    5337,  5338,  5339,  5340,  5341,  5342,  5343,  5344,  5345,  5346,
    5347,  5348,  5349,  5350,  5351,  5352,  5353,  5354,  5355,  5356,
    5357,  5358,  5359,  5360,  5361,  5362,  5363,  5364,  5365,  5366,
    5367,  5368,  5369,  5370,  5371,  5372,  5373,  5374,  5386,  5395,
    5398,  5405,  5410,  5419,  5423,  5433,  5437,  5447,  5451,  5462,
    5466,  5476,  5489,  5492,  5500,  5503,  5511,  5519,  5527,  5531,
    5539,  5542,  5550,  5558,  5570,  5576,  5584,  5587,  5595,  5599,
    5603,  5611,  5614,  5622,  5625,  5633,  5637,  5641,  5645,  5649,
    5657,  5665,  5677,  5689,  5693,  5697,  5705,  5711,  5721,  5725,
    5729,  5733,  5737,  5741,  5745,  5749,  5757,  5763,  5769,  5773,
    5781,  5787,  5797,  5807,  5813,  5823,  5833,  5844,  5851,  5855,
    5863,  5866,  5873,  5878,  5887,  5897,  5900,  5908,  5911,  5919,
    5928,  5935,  5945,  5949,  5956,  5962,  5972,  5975,  5982,  5987,
    5999,  6007,  6019,  6027,  6031,  6039,  6045,  6051,  6061,  6069,
    6073,  6077,  6081,  6089,  6097,  6109,  6113,  6121
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
     305,   306,   307,   308,   309,   310,   311,   312
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 10633;
  const int xquery_parser::yynnts_ = 280;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 514;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 313;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 567;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 14870 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6127 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"


namespace zorba {

namespace parser {

const char *the_tumbling = "tumbling", *the_sliding = "sliding",
  *the_start = "start", *the_end = "end", *the_only_end = "only end",
  *the_ofor = "ofor", *the_declare = "declare", *the_create = "create";

} // namespace parser

/*
    The error member function registers the errors to the driver.
*/

void xquery_parser::error(zorba::xquery_parser::location_type const& loc, std::string const& msg)
{
    driver.set_expr(
        new ParseErrorNode (driver.createQueryLoc (loc), XPST0003, msg)
    );
}

} // namespace zorba


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
/* vim:set et sw=4 ts=4: */

