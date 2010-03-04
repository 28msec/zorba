
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
#line 835 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 960 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"

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
        case 103: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
#line 831 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 282 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 115: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 830 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 291 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 140: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 829 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 300 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 309 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 318 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 327 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 336 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "Prolog" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 345 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 354 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 363 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 372 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 381 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 390 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 856 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 399 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 856 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 408 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 417 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 426 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 435 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 444 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 453 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 462 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 471 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 480 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 489 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 498 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 507 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 516 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 525 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 534 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 543 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 552 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 561 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 570 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 579 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 588 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 856 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 597 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 606 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "DeclPropertyList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 615 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "DeclProperty" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 624 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 633 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 642 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 651 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 660 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 669 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 678 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 687 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 856 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 696 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 705 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 714 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 723 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 732 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 741 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 750 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 759 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 768 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 777 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 786 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 795 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FunctionDecl3" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 804 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDecl4" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 813 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 822 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 831 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 840 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 849 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 858 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 867 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 885 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 894 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 903 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 912 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 921 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 930 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 939 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 948 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 957 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 966 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 975 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 984 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 993 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1002 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1011 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1020 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1029 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1038 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1047 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1056 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1065 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1074 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1083 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1092 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1101 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1110 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1119 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1128 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1137 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1146 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1155 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1164 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1173 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1182 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1191 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1200 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1209 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1218 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1227 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1236 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1245 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1254 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1263 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1272 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1281 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1290 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1299 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1308 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1317 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1326 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1335 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1344 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1353 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1362 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1371 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1380 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1389 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1398 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1407 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1416 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1425 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1434 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1443 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1452 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1461 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1470 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1479 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1488 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1497 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1506 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1515 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1524 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1533 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1542 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1551 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1560 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1569 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1578 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1587 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1596 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1605 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1614 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1623 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1632 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1641 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1650 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1659 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1668 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1677 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1686 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1695 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1704 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1713 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1722 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1731 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1740 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1749 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1758 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1767 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1776 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1785 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1794 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1803 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1812 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1821 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1830 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1839 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1848 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1857 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1866 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1875 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1884 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1893 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1902 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1911 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1920 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1929 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1938 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1947 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1956 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1965 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1974 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1983 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1992 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2001 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2010 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2019 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2028 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2037 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2046 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2055 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2064 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2073 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2082 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2091 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2100 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2109 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2118 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2127 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2136 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2145 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2154 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2163 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2172 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2181 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2190 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2199 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2208 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 856 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2217 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2226 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2235 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2244 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2253 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2262 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2271 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2280 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2289 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2298 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2307 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2316 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2325 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2334 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2343 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2352 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2361 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2370 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2379 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2388 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2397 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2406 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2415 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2424 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2433 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2442 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2451 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2460 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2469 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2478 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2487 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2496 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2505 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2514 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2523 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2532 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2541 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2550 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2559 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2568 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2577 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
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
#line 2662 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"

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
#line 977 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 986 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 991 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            MainModule *mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
            mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 998 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1003 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            LibraryModule *lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
            lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1014 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            std::string encoding = "utf-8";
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), encoding );
        }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1019 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
        }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1027 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1035 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
        }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1043 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LibraryModule(
                LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1049 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1061 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
            dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
        }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1070 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog( LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)), NULL );
        }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1074 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog( LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)) );
        }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1078 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1090 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
            sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = sdl;
        }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1096 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( SIND_DeclList *sdl = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                sdl->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1106 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
            vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = vdl;
        }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1112 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( VFO_DeclList *vdl = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vdl->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 1144 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
         (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
         delete (yysemantic_stack_[(4) - (4)].vstrpair);
       }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1149 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
         (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
         delete (yysemantic_stack_[(4) - (4)].vstrpair);
       }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1158 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.vstrpair) = new vector<string_pair_t>();
          (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
          delete (yysemantic_stack_[(1) - (1)].strpair);
        }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1164 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
          delete (yysemantic_stack_[(2) - (2)].strpair);
          (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
        }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1173 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
            (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval() );
            delete sl;
        }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1181 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1182 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1183 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1184 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1185 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1186 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1187 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1188 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1189 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1190 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1221 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
        }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1230 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::preserve_space
            );
        }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1236 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::strip_space
            );
        }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1246 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_element_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1252 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_function_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1262 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OptionDecl(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval))
            );
        }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1272 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTOptionDecl( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1280 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::ordered
            );
        }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1286 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::unordered
            );
        }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1297 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_greatest);
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1302 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_least);
        }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1312 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1318 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1324 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1330 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1347 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
        }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1355 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1363 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
        }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1367 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1376 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1385 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1398 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            URILiteralList *ull = new URILiteralList( LOC((yyloc)));
            ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.node) = ull;
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1404 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
                ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1415 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1419 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
        }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1427 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1432 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1437 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), 
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1444 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1457 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
        }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1464 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
            d->type = (yysemantic_stack_[(3) - (2)].node);
            (yyval.node) = d;
        }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1470 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1477 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
            d->ext = false;
            (yyval.node) = d;
        }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1483 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), NULL );
        }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1487 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1494 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1505 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1509 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1517 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(5) - (5)].expr));
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1523 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1529 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
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
#line 1898 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(1) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1905 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(3) - (3)].expr));
      vd->set_global(false);
      (yyval.node) = vd;
        }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1916 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AssignExpr(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr))->get_qname(), (yysemantic_stack_[(5) - (5)].expr)
            );
            delete (yysemantic_stack_[(5) - (3)].expr);
        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1926 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExitExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1933 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1945 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::BREAK );
        }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1949 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
        }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1956 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            dynamic_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1961 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FunctionDecl *fd = dynamic_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));
            fd->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            fd->deterministic = false;
            (yyval.node) = fd;
        }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1968 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            dynamic_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node))->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
        }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1976 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1980 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1984 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *fd = dynamic_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node));
      fd->type = (fd->type == ParseConstants::fn_extern ?
                  ParseConstants::fn_extern_update :
                  ParseConstants::fn_update);
      (yyval.node) = fd;
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 1992 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2000 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->param,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
                            (yysemantic_stack_[(4) - (4)].expr),
                            ParseConstants::fn_read);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2010 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->param,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
                            NULL,
                            ParseConstants::fn_extern);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2024 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->param,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
                            (yysemantic_stack_[(4) - (4)].expr),
                            ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2034 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->param,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
                            NULL,
                            ParseConstants::fn_extern_sequential);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2048 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                            &* (yysemantic_stack_[(6) - (3)].fnsig)->param, &* (yysemantic_stack_[(6) - (3)].fnsig)->ret,
                            (yysemantic_stack_[(6) - (5)].expr),
                            ParseConstants::fn_read);
      delete (yysemantic_stack_[(6) - (3)].fnsig);
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2057 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->param,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
                            NULL,
                            ParseConstants::fn_extern);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2072 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            ParamList *pl = new ParamList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2078 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
                pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2090 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2094 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2105 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EnclosedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 2112 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 2120 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QueryBody( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 2135 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2139 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2153 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new BlockBody( LOC((yyloc)) );
        }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2157 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (1)].expr));
            bb->add( (yysemantic_stack_[(3) - (2)].expr) );
            (yyval.expr) = bb;
        }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2166 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2170 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2210 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2225 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2232 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_sliding;
        }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2236 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_tumbling;
        }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2243 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_start;
        }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2247 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_end;
        }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2251 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_only_end;
        }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2258 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2266 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr),
                (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 2277 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 209:

/* Line 678 of lalr1.cc  */
#line 2287 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 2300 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 2322 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 2328 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2337 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = NULL;
        }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 2341 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_ofor;
        }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2349 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForClause(
                LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL
            );
        }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2359 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
            vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vdl;
        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2365 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2377 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2381 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,NULL,
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2389 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 2398 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
                         NULL,
                         (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2408 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 2416 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2425 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2434 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                         (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2449 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2458 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2468 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2476 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2482 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2491 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2497 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2509 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2517 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2527 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                           (yysemantic_stack_[(4) - (4)].expr));
     }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2535 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                           (yysemantic_stack_[(5) - (5)].expr));
     }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2547 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2553 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2566 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2570 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2578 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2582 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2591 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2595 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2599 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2607 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::string name = static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))->get_qname();
      (yyval.node) = new VarGetsDecl(LOC((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)),
                           NULL, NULL,
                           new VarRef(LOC((yyloc)), name),
                           VarGetsDecl::eval_var);
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2622 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2630 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2637 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2643 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2654 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2658 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2667 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2675 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2681 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2691 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2697 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2707 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2711 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2721 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2727 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2733 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2739 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2748 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2757 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2766 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2779 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2783 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2791 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2797 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2807 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2815 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2824 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2837 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
            qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qvidl;

        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2844 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2856 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2860 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2873 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2880 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2893 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2899 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2911 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 2917 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 2929 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 2938 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 2942 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 2951 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 2955 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 2963 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 2967 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2977 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 2984 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2993 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 3002 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3007 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 3016 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 3025 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 3034 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 3047 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3051 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3063 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3067 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3075 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3079 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3088 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3092 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3096 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3105 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3109 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3115 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3121 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3127 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3138 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3142 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3146 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3154 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3158 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3164 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3174 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3178 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3188 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3192 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3202 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3206 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3216 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3220 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3230 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3234 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3242 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3246 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3250 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3254 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3264 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3268 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3272 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3280 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3284 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3288 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3292 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3296 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3300 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3308 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3312 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3316 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3324 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3328 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3332 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3336 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3346 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3352 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3362 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3368 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3378 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3382 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3420 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL
            );
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3426 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3432 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3438 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = !rpe ?
                (yysemantic_stack_[(1) - (1)].expr) : new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3449 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NULL;
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3457 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 3468 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3474 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3484 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3488 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3496 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3502 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 3510 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3516 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 3528 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3534 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3544 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3548 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3552 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3556 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3560 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3566 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3572 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3580 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3584 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3592 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3596 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3607 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3611 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3615 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3621 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3625 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3639 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3643 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3651 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3655 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3665 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3669 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3673 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3682 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3686 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FilterExpr(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3692 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3696 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3704 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3710 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3720 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3728 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3732 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3736 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3740 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3744 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3748 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3752 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3756 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3760 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3768 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3772 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3780 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3787 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3794 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3805 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname() );
            delete (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3814 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3818 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3826 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 3834 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 3842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 3896 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 3900 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 3912 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 3918 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 3928 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 3932 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 3940 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 3944 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 3948 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 3956 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 441:

/* Line 678 of lalr1.cc  */
#line 3966 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 442:

/* Line 678 of lalr1.cc  */
#line 3976 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 443:

/* Line 678 of lalr1.cc  */
#line 3986 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 444:

/* Line 678 of lalr1.cc  */
#line 3996 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 445:

/* Line 678 of lalr1.cc  */
#line 4006 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 446:

/* Line 678 of lalr1.cc  */
#line 4021 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4027 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4038 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4044 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4055 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4072 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4077 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4086 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4090 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4097 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back(
                new QuoteAttrValueContent( LOC((yyloc)),std::string("\"") )
            );
            (yyval.node) = qacl;
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4105 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4111 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 460:

/* Line 678 of lalr1.cc  */
#line 4121 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4133 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4137 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4144 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4150 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4156 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4163 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4174 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4178 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4188 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4192 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4202 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4206 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4210 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4215 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4224 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4230 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4236 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4242 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4252 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4256 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4268 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4272 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4284 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4296 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4300 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4304 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4308 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4312 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4316 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4324 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4332 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL
            );
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4338 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr)
            );
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4344 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4348 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4365 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (2)].expr), NULL );
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4369 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4373 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4377 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4385 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4393 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4401 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), NULL );
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4405 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (2)].sval)), (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4409 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4413 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4421 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4427 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4437 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4445 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4449 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4455 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4490 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4496 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4502 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4512 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4516 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4520 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4524 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4528 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4535 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back((yysemantic_stack_[(1) - (1)].node));
          (yyval.node) = aTypeList;
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4541 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          if (aTypeList) aTypeList->push_back((yysemantic_stack_[(3) - (3)].node));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4551 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4559 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4563 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4567 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4571 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4575 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4579 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4583 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4587 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4591 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4599 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4607 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4611 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4615 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4625 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4633 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4641 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4645 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4649 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4657 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4661 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4667 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4673 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4677 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4687 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4695 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4699 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4705 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4714 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4723 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4729 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4735 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4745 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4762 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4769 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4784 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4820 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4824 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4833 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), *(yysemantic_stack_[(3) - (3)].ival));
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new InlineFunction(LOC ((yyloc)), &*(yysemantic_stack_[(3) - (2)].fnsig)->param, &*(yysemantic_stack_[(3) - (2)].fnsig)->ret, dynamic_cast<EnclosedExpr *>((yysemantic_stack_[(3) - (3)].expr)));
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4851 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 4855 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 4864 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 4873 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 4877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)), dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 4886 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 4903 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 4909 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 4915 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 4925 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 4929 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 4935 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 4941 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 4945 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 4951 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 4955 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 4961 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 4967 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 4974 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 4984 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 4989 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 4997 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5003 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5013 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5035 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5044 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5050 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5063 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5077 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5084 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5090 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5100 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5105 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5111 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)),
                          *(yysemantic_stack_[(10) - (2)].name_test_list),
                          static_cast<QName*>((yysemantic_stack_[(10) - (5)].expr)),
                          static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                          NULL,
                          (yysemantic_stack_[(10) - (10)].expr));
       delete (yysemantic_stack_[(10) - (2)].name_test_list);
    }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5121 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(13) - (2)].name_test_list),
                          static_cast<QName*>((yysemantic_stack_[(13) - (5)].expr)),
                          static_cast<QName*>((yysemantic_stack_[(13) - (8)].expr)),
                          static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                          (yysemantic_stack_[(13) - (13)].expr));
       delete (yysemantic_stack_[(13) - (2)].name_test_list);
    }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5134 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5140 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5161 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 601:

/* Line 678 of lalr1.cc  */
#line 5179 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5183 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5196 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EvalExpr(
                LOC((yyloc)), dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)), (yysemantic_stack_[(7) - (6)].expr)
            );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5202 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EvalExpr( LOC((yyloc)), new VarGetsDeclList( LOC((yyloc)) ), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5208 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("xquery"); }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5209 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("empty"); }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5210 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("attribute"); }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5211 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("comment"); }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5212 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("document-node"); }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5213 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("element"); }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5214 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("item"); }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5215 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("if"); }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5216 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("node"); }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5217 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("processing-instruction"); }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5218 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema-attribute"); }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5219 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema-element"); }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5220 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("text"); }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5221 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("typeswitch"); }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5222 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("empty-sequence"); }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5223 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("boundary-space"); }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5224 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ft-option"); }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5225 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("base-uri"); }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5226 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lax"); }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5227 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("strict"); }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5228 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("idiv"); }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5229 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("document"); }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5230 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("not"); }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5231 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sensitive"); }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5232 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("insensitive"); }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5233 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("diacritics"); }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5234 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("without"); }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5235 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stemming"); }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5236 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("thesaurus"); }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5237 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stop"); }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5238 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("wildcards"); }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5239 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("entire"); }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5240 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("content"); }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5241 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("word"); }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5242 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("start"); }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5243 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("end"); }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5244 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("most"); }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5245 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("skip"); }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5246 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("copy"); }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5247 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("value"); }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5248 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("eq"); }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5249 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ne"); }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5250 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lt"); }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5251 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("le"); }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5252 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("gt"); }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5253 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ge"); }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5254 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("at"); }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5255 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("context"); }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5256 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("variable"); }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5257 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("return"); }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5258 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("for"); }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5259 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("outer"); }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5260 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sliding"); }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5261 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("tumbling"); }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5262 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("previous"); }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5263 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("next"); }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5264 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("only"); }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5265 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("when"); }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5266 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("count"); }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5267 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("in"); }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5268 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("let"); }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5269 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("where"); }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5270 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("by"); }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5271 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("group"); }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5272 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("order"); }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5273 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stable"); }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5274 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ascending"); }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5275 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("descending"); }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5276 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("greatest"); }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5277 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("least"); }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5278 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("collation"); }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5279 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("some"); }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5280 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("every"); }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5281 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("satisfies"); }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5282 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("case"); }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5283 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("as"); }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5284 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("then"); }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5285 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("else"); }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5286 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("or"); }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5287 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("and"); }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5288 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("instance"); }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5289 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("of"); }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5290 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("castable"); }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5291 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("to"); }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5292 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("div"); }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5293 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("mod"); }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5294 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("union"); }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5295 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("intersect"); }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5296 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("except"); }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5297 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("validate"); }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5298 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("cast"); }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5299 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("treat"); }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5300 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("is"); }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5301 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("preserve"); }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5302 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("strip"); }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5303 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("namespace"); }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5304 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("external"); }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5305 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("encoding"); }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5306 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("no-preserve"); }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5307 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("inherit"); }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5308 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("no-inherit"); }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5309 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("declare"); }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5310 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("construction"); }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5311 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ordering"); }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5312 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("default"); }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5313 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("copy-namespaces"); }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 5314 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("option"); }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 5315 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("version"); }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 5316 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("import"); }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 5317 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema"); }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 5318 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("module"); }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 5319 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("function"); }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 5320 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("score"); }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 5321 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ftcontains"); }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 5322 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("weight"); }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 5323 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("window"); }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 5324 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("distance"); }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 5325 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("occurs"); }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 5326 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("times"); }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 5327 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("same"); }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 5328 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("different"); }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 5329 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lowercase"); }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 5330 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("uppercase"); }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 5331 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("relationship"); }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 5332 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("levels"); }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 5333 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("language"); }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 5334 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("any"); }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 5335 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("all"); }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 5336 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("phrase"); }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 5337 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("exactly"); }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 5338 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("from"); }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 5339 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("words"); }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 5340 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sentences"); }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 5341 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sentence"); }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 5342 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("paragraph"); }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 5343 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("replace"); }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 5344 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("modify"); }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 5345 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("first"); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 5346 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("insert"); }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 5347 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("before"); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 5348 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("after"); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 5349 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("revalidation"); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 5350 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("with"); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 5351 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("nodes"); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 5352 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("rename"); }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 5353 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("last"); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 5354 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("delete"); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 5355 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("into"); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 5356 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("simple"); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 5357 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sequential"); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 5358 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("updating"); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 5359 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("deterministic"); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 5360 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("nondeterministic"); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 5361 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ordered"); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 5362 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("unordered"); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 5363 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("returning"); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 5364 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("block"); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 5365 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("exit"); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 5366 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("loop"); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 5367 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("while"); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 5368 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("break"); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 5369 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("continue"); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 5370 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("try"); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 5371 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("catch"); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 5372 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("eval"); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 5373 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("using"); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 5374 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("set"); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 5375 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("index"); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 5376 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("unique"); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 5377 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("non"); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 5378 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("on"); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 5379 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("range"); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 5380 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("equality"); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 5381 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("manually"); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 5382 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("automatically"); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 5383 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("maintained"); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 5384 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("decimal-format"); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 5385 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("decimal-separator"); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 5386 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("grouping-separator"); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 5387 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("infinity"); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 5388 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("minus-sign"); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 5389 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("NaN"); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 5390 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("percent"); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 5391 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("per-mille"); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 5392 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("zero-digit"); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 5393 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("digit"); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 5394 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("pattern-separator"); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 5395 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("collection"); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 5396 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("const"); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 5397 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("append-only"); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 5398 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("queue"); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 5399 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("mutable"); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 5400 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("read-only"); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 5401 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("integrity"); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 5402 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("constraint"); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 5403 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("check"); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 5404 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("key"); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 5405 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("foreach"); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 5406 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("foreign"); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 5407 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("keys"); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 5420 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), dynamic_cast<FTOr*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 5428 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 5432 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 5439 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 5444 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 5453 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 5457 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr(
                LOC((yyloc)), dynamic_cast<FTOr*>((yysemantic_stack_[(3) - (1)].node)), dynamic_cast<FTAnd*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 5467 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 5471 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd(
                LOC((yyloc)), dynamic_cast<FTAnd*>((yysemantic_stack_[(3) - (1)].node)), dynamic_cast<FTMildNot*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 5481 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 5485 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot(
                LOC((yyloc)),
                dynamic_cast<FTMildNot*>((yysemantic_stack_[(4) - (1)].node)), dynamic_cast<FTUnaryNot*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 5496 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 5500 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 5510 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 5522 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 5526 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 5533 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 5537 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 5545 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 5553 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 5561 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 5565 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 5572 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 5576 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 5584 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 5595 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 5599 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 5607 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 5619 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 5625 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 5634 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 5638 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 5646 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 5650 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 5654 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 5661 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 5665 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 5672 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 5676 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 5684 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 5688 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 5692 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 5696 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 5700 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 5708 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 5716 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 5728 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 5740 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 5744 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 5748 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 5756 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 5762 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 5772 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 5776 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 5780 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 5784 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 5788 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 5792 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 5796 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 5800 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 5808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 5812 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 5816 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 5820 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 5828 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::senstive
            );
        }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 5834 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 5844 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 5854 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 5858 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 5866 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 875:

/* Line 678 of lalr1.cc  */
#line 5876 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 876:

/* Line 678 of lalr1.cc  */
#line 5887 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 5894 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 5898 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 5905 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 5909 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(1) - (1)].thesaurus_id_list);
        }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 5916 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 5921 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 5930 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 5939 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 5943 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 5950 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 5954 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 5962 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(5) - (4)].node)), (yysemantic_stack_[(5) - (5)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(5) - (5)].incl_excl_list);
        }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 5971 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(5) - (5)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(5) - (5)].incl_excl_list);
        }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 5978 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 5988 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 5992 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 5999 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6005 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6014 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6018 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6025 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6030 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6042 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6050 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6062 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6070 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6074 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6082 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6086 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6090 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6098 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6106 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6110 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6114 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6118 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6126 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6134 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6146 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6150 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6158 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;



/* Line 678 of lalr1.cc  */
#line 11032 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1315;
  const short int
  xquery_parser::yypact_[] =
  {
      1524, -1315, -1315, -1315, -1315,   491,    46, -1315, -1315,   390,
   -1315, -1315, -1315, -1315,   139,   -12,  9313,   149,   270,   176,
     293,   104, -1315,    27, -1315, -1315, -1315, -1315, -1315, -1315,
     288, -1315,  7611, -1315, -1315,   316, -1315,   381, -1315, -1315,
     413, -1315,   418, -1315,   403, -1315,   -26, -1315, -1315, -1315,
   -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315,
   -1315, -1315, -1315, -1315, -1315, -1315,  9595, -1315,  7035, -1315,
   -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315,
   -1315, -1315, 11005, -1315, -1315, -1315, -1315, -1315, -1315, -1315,
   -1315,   417, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315,
   -1315, -1315, -1315,  1815, 11005, -1315, -1315, -1315, -1315, -1315,
   -1315, -1315,   412, -1315, -1315, -1315,  8183, -1315,  8467, -1315,
   -1315, -1315, -1315, -1315, 11005, -1315, -1315,  6745, -1315, -1315,
   -1315, -1315, -1315, -1315,   425, -1315, -1315, -1315, -1315, -1315,
   -1315, -1315, -1315,    16,   377, -1315, -1315, -1315, -1315, -1315,
   -1315, -1315, -1315,   135,   443,   161, -1315,   383,   193, -1315,
   -1315, -1315, -1315, -1315, -1315,   497, -1315,   474,   387,   399,
     388, -1315, -1315,   499,   494, -1315,   537, -1315, -1315, -1315,
   -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315,
   -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315,
   -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315,
   -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315,
   -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315,
   -1315, -1315, -1315, -1315, -1315,  4715,   649, -1315,  5005, -1315,
   -1315,    99,  5295,   472,   473, -1315, -1315, -1315, -1315, -1315,
   -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315,
   -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315,
   -1315, -1315, -1315, -1315, -1315, -1315,   -25, -1315, -1315, -1315,
   -1315,    98, 11005, -1315, -1315, -1315, -1315, -1315,   498,   573,
   -1315,   704,   411,   284,   210,   -21,   380, -1315,   617,   476,
     569,   572,  5585, -1315, -1315, -1315,   145, -1315, -1315,  6745,
   -1315,   421, -1315,   519,  7035, -1315,   519,  7035, -1315, -1315,
   -1315,   428, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315,
   -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315,
   -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315,
   -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315,
   -1315, -1315, -1315, -1315,    -7, -1315, -1315,   648,   341,   343,
     269,   486, 11005,   486, 11005,     3,   629,   631,   634, 11005,
     532,   565,   324,  8183, -1315, -1315,   367,   332,   439, 11005,
   -1315, -1315, -1315, -1315, -1315,   394, 11005,   391,   392,   385,
     703, -1315, -1315, -1315,  8183,  5295,   507,  5295,    33, -1315,
   -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315,
   -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315,
   -1315,  5295,  9877, -1315, -1315, -1315, -1315, -1315, -1315, -1315,
   -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315,   541,
    5295,   414,   416, -1315,   575,   -24,   544,  5295,    83,    38,
   11005,   581, -1315,  5295,  7897,   549, -1315, 11005, 11005, 11005,
    5295,   521,  5295, 11005,  5295,   552,   557,  5295, 10159,   559,
     561,   562,   564,   582,   584, -1315, -1315, -1315, 11005, -1315,
     527,   689,  5295,    72, -1315,   719,   558, -1315,  5295,   534,
   -1315,   716,  5295,  5295,   563,  5295,  5295,  5295,  5295,   520,
   11005, -1315, -1315, -1315, -1315,  5295,  5295,  5295, 11005, -1315,
   -1315, -1315, -1315,   491,   104, -1315, -1315,    99,   729,  5295,
   -1315,  5295,   630,   270,    27,   288,   598,   597,   599,  5295,
    5295, -1315, -1315, -1315, -1315, -1315, -1315, -1315,   659, -1315,
     -22,  5875,  5875,  5875, -1315,  5875,  5875, -1315,  5875, -1315,
    5875, -1315, -1315, -1315, -1315, -1315, -1315, -1315,  5875,  5875,
       8,  5875,  5875,  5875,  5875,  5875,  5875,  5875,  5875,  5875,
    5875,  5875,   540,   676,   677,   678, -1315, -1315, -1315,  2105,
   -1315, -1315,  6745,  6745,  5295,   519, -1315, -1315,   519, -1315,
    2395,   519,   626,  2685, -1315, -1315, -1315, -1315, -1315, -1315,
     674,   685, -1315,   176, -1315,   766, -1315, -1315, 11005, -1315,
   -1315, 11005, -1315,   646,   205, 11005,   331,   636,   637,   646,
     648,   671,   668, -1315, -1315, -1315, -1315, -1315,    54,   555,
     -28, -1315,   510, -1315, -1315, 11005, 11005, 11005, -1315,   679,
     623, -1315,   633,   562,   316, -1315,   628,   632,   638, -1315,
      -1,    14,  2975,   639, -1315, -1315, 11005,   -14, 11005,   721,
      21, -1315,  5295, -1315,   640,  8183,   714,   773,  8183,   648,
     722,   718, -1315,   -39, -1315,   651,   643, -1315,   645,  3265,
     652,   690,    10, -1315,   194,   656, -1315,   655,   682, -1315,
     665,  5295,  5295,   666, -1315,    25,    96,  3555,    12, -1315,
   11005,   689, -1315,    -6,   669, -1315, -1315, -1315, -1315,   670,
   -1315,   -38, -1315, -1315, -1315,    52,   183,   746,   614,   635,
     -53, -1315,   712,  6165, -1315,   681,   673,    67, -1315, -1315,
     667, -1315,   756, -1315, -1315,   -15, 11005,   693,  5295,   744,
   -1315, -1315,   745, 10441,   754,  5295,   757,   -11,   732,   -32,
     573, -1315, -1315, -1315, -1315, -1315,  5875, -1315, -1315, -1315,
    5295,     8,   275,   174, -1315,   595,    91,   625,   621, -1315,
   -1315,   439, -1315,   618,   195,   210,   210,   236,   -21,   -21,
     -21,   -21,   380,   380, -1315, -1315, 10441, 10441, 11005, 11005,
   -1315,   701, -1315, -1315,   702, -1315, -1315, -1315,   175, -1315,
   -1315,   180,   281,   354,   255, -1315,   176,   176, -1315, -1315,
   -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315,   646, -1315,
     758, 10723,   747,  5295, -1315, -1315, -1315,   792,   749,  5295,
     648,   648,   646, -1315,   492,   648,   319, 11005,   303,   -55,
     306,   863, -1315, -1315,   198, -1315,   261, -1315, -1315, -1315,
   -1315, -1315, -1315, -1315, -1315, -1315,    54,    32,   333, -1315,
     675,   242,   -27,   594,   648, -1315, -1315, -1315, -1315,   741,
   11005, -1315, 11005, -1315, -1315,   713, -1315,   234,   641, -1315,
   -1315,   379,   -14,   792, 10441,   777,   802,   717,   706,   769,
     648,   752,   781,   807,   648,   794,  5295,   774,   -20,   762,
   -1315, -1315, -1315,   736, -1315,  5295,   801,  5295,  5295,   779,
   -1315,   822,  5295, -1315,   748,   751,   775, 11005, -1315, 11005,
   -1315, -1315,   753,  5295,   891, -1315,    37, -1315,    69, -1315,
   -1315,   900, -1315,   368,  5295,  5295,  5295,   369,  5295,  5295,
    5295,  5295,  5295,  5295,   810,  5295,  5295,   565,    -9,   755,
     474,   686,   784,   819,   729,   859, -1315, -1315,  5295,   318,
     832, -1315, 11005,   833, -1315, 11005,   787,   788, 10723,   793,
   -1315,   144, -1315, -1315, -1315, -1315, -1315, -1315, -1315, 11005,
   -1315, 11005,  5295,   803,  5295,  5295,    13,   804, -1315,   765,
     767, -1315,     8,   708, -1315, -1315,  -113, -1315,    89,   -18,
     709,     8,    89,  5875, -1315,   -40, -1315, -1315, -1315, -1315,
   -1315, -1315,     8,   805,   680,   555,   -18, -1315, -1315,   683,
     875, -1315, -1315, -1315, -1315, -1315, -1315,   812, -1315, -1315,
   -1315,  5295, -1315, -1315, -1315, -1315, -1315, -1315, -1315,  5295,
   -1315,   277,   317, -1315,   931,   419, -1315, -1315, -1315,  5295,
   -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315,   932, -1315,
   -1315,   688,   687, -1315, -1315, -1315, -1315,   934, -1315,   410,
   -1315, -1315,   691, -1315, -1315,   561,   -12,   564,   582,   584,
     443,   727,   144,   740,   760,  6455,   692,   684,    32, -1315,
     761,   782,  3845,   789,   790,   830,   795,   797, -1315,  5295,
     831, -1315,   860,   865,  5295, 11005,   365,   922, -1315, -1315,
   -1315, -1315, -1315, -1315, 10441, -1315,  5295,   648,   893, -1315,
   -1315, -1315,   648,   893, 11005, -1315,  5295,  5295,   861,  4135,
   -1315, -1315, 11005, -1315, -1315,  5295,  9031,   398, -1315,   821,
   -1315, -1315,  4425,   820,   823, -1315, -1315, -1315,   873, -1315,
     422, -1315, -1315,   992, -1315, -1315, 11005, -1315, -1315,   462,
   -1315, -1315, -1315,   824,   778,   780, -1315, -1315, -1315,   783,
     785, -1315, -1315, -1315, -1315, -1315,   791, 11005,   825, -1315,
     870, -1315,   565, -1315, -1315, -1315,  7325,   686, -1315,  5295,
   11005,   832, -1315,   648, -1315,   508, -1315,    18,   907, -1315,
    5295,   912,   744, -1315,  8749,   835,   836,   838, -1315, -1315,
   -1315, -1315, -1315, -1315, -1315,  5295, -1315, -1315,  5295,   878,
    5295, -1315, -1315, -1315,   843,  5875, -1315, -1315, -1315, -1315,
   -1315,    29,  5875,  5875,   220, -1315,   625, -1315,    11, -1315,
     621,     8,   874, -1315, -1315,   750, -1315, -1315, -1315, -1315,
   -1315, -1315,   846, -1315, -1315, -1315,  5295, -1315, -1315, -1315,
   -1315,   768,     7,   764,   933, -1315, -1315, -1315, -1315, -1315,
     862, 11005,   776,   727,  6455, -1315, -1315,   853, -1315, -1315,
   -1315, -1315, -1315, -1315,  5295, 11005, 11005, -1315,    80, -1315,
    5295, -1315,   914,   940,   648,   893, -1315, -1315, -1315,  5295,
   -1315,   858, -1315, -1315, 11005,   857,    17, -1315, -1315, -1315,
     872, -1315, -1315,   891, 11005,   705, -1315,   891, 11005, -1315,
   -1315,  5295,  5295,  5295,  5295,  5295, -1315,  5295,  5295, -1315,
   -1315,   254, -1315,   876, -1315, -1315, -1315, -1315,   907, -1315,
   -1315, -1315,   648, -1315, -1315,   952,   871, -1315,   185, -1315,
   -1315, -1315, -1315, -1315,  5295, -1315, -1315,   -21,  5875,  5875,
     236,   320, -1315, -1315, -1315, -1315, -1315, -1315,  5295, -1315,
   -1315,   -17,   -45,  1027,  1032,   -45,  1033,   -18,   877,   955,
   -1315,  6455,   -71,   796, -1315,   895, -1315, -1315, -1315,  1011,
   -1315, -1315,  5295,   648, -1315, -1315, -1315,   971,  5295, 11005,
    5295, -1315,    -5,   891, 11005,   879,   891, -1315, -1315, -1315,
   -1315, -1315, -1315, -1315,   948,  7325, -1315, -1315, -1315, -1315,
   10441, -1315, 10441,   973, -1315,   236,   236,  5875,   887, -1315,
       7,     7, -1315,   -45, -1315, -1315, -1315,   191, -1315, -1315,
   -1315,   806, -1315,   933,   963, -1315,   978, 11005,   956,   852,
   11005,  6455,   958, -1315,   893, 10441, -1315,   894, -1315,    68,
     351, -1315,   884,   891, -1315,   885, 11005, -1315, -1315, -1315,
   10441,   236, -1315, -1315, -1315, -1315,  1053, -1315, -1315, -1315,
    6455, 11005,   786, 11005,   964,   864,   963, 11005,   901,  5295,
   -1315, -1315,   990,   170, -1315, -1315, -1315, -1315,   905,   389,
   -1315, -1315, -1315,   892, -1315,   197, -1315, -1315, -1315,   907,
    5295,   798, 11005,   972, -1315,  5295, -1315, -1315, -1315, -1315,
   -1315, -1315, -1315, -1315,   974,   938, -1315, -1315,   800,   808,
   11005, -1315, 11005, -1315,   799,  5295,   809,   199,  6455, -1315,
    6455,   975,   938, -1315,   898, 11005, -1315,   811,   911, 11005,
     938,   880, -1315,   979, 11005,   814,  6455, -1315
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   402,   403,   601,   556,   706,   715,   622,   620,   608,
     707,   710,   663,   756,   626,   609,   610,   769,   655,   716,
     612,   713,   685,   665,   641,   660,   757,   661,   711,   708,
     656,   659,   614,   714,   615,   616,   754,   771,   753,   657,
     676,   670,   617,   658,   618,   755,   694,   662,   638,   781,
     782,   783,   784,   785,   786,   787,   788,   789,   790,   791,
     393,   396,   684,   680,   671,   651,   607,   383,     0,   679,
     687,   695,   381,   675,   422,   652,   653,   709,   382,   385,
     672,   689,     0,   428,   391,   424,   682,   606,   673,   674,
     702,   677,   693,   701,   387,   386,   625,   664,   704,   423,
     692,   697,   611,     0,     0,   340,   690,   700,   705,   703,
     683,   669,   758,   667,   668,   392,     0,   339,     0,   395,
     394,   698,   654,   678,     0,   384,   369,     0,   401,   699,
     681,   688,   696,   691,   759,   645,   650,   649,   648,   647,
     646,   619,   666,     0,   605,   712,   639,   745,   744,   746,
     624,   623,   642,   751,   613,   743,   748,   749,   740,   644,
     686,   742,   752,   750,   741,   643,   747,   761,   765,   766,
     762,   763,   760,   764,   767,   768,   770,   732,   731,   637,
     630,   725,   721,   640,   636,   734,   735,   718,   627,   621,
     629,   730,   729,   726,   722,   739,   733,   728,   724,   717,
     628,   738,   737,   632,   634,   633,   723,   727,   719,   635,
     720,   631,   736,   792,   793,   794,   795,   796,   797,   773,
     774,   772,   778,   779,   780,   775,   776,   777,   798,   799,
     800,   801,   802,   803,   804,     0,     0,     2,     0,     4,
       6,    12,     0,     0,     0,    18,    20,    29,    22,    23,
      24,    50,    25,    34,    30,    54,    55,    56,    51,    52,
      58,    59,    28,    26,    27,    32,    33,    53,   198,   197,
     194,   195,   196,    31,    11,   175,   176,   180,   182,   213,
     219,     0,     0,   211,   212,   183,   184,   185,   186,   295,
     297,   299,   309,   313,   315,   318,   323,   326,   329,   331,
     333,   335,     0,   337,   343,   345,     0,   361,   344,   365,
     368,   370,   373,   375,     0,   380,   377,     0,   388,   398,
     400,   374,   404,   411,   420,   412,   413,   414,   417,   418,
     415,   416,   435,   437,   438,   439,   436,   484,   485,   486,
     487,   488,   489,   397,   530,   522,   529,   528,   527,   524,
     526,   523,   525,   421,   419,   557,   558,    57,   187,   188,
     190,   189,   191,   192,   399,   193,   602,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,   108,     0,     0,     0,     0,
     103,   104,   105,   106,   111,     0,     0,     0,     0,     0,
       0,   101,   156,   159,     0,     0,     0,     0,     0,   706,
     715,   608,   626,   609,   610,   769,   655,   716,   612,   713,
     665,   656,   614,   616,   771,   676,   617,   618,   694,   607,
     677,     0,     0,   758,   759,   605,   751,   613,   743,   749,
     740,   643,   761,   765,   766,   762,   764,   767,   770,     0,
       0,     0,     0,   221,     0,     0,     0,     0,     0,     0,
       0,     0,   599,     0,     0,     0,   600,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     608,   610,   614,   617,   607,   389,   399,   425,     0,   426,
       0,   451,     0,     0,   364,     0,     0,   367,     0,     0,
     480,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   146,   143,   154,   155,     0,     0,     0,     0,     3,
       1,     5,     7,     0,     0,    13,    10,    15,    16,     0,
     178,   177,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   199,   218,   214,   220,   215,   217,   216,   223,   224,
       0,     0,     0,     0,   354,     0,     0,   352,     0,   304,
       0,   353,   346,   351,   350,   349,   348,   347,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   342,   341,   338,     0,
     362,   366,     0,     0,     0,   376,   408,   379,   378,   390,
       0,   405,     0,     0,   598,    76,    61,    62,   137,   138,
       0,     0,   158,     0,   157,     0,    67,    68,     0,   162,
     160,     0,   161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   567,   568,   569,   110,   109,     0,    66,
     115,   112,     0,   114,   113,     0,     0,     0,   102,     0,
       0,   536,     0,     0,     0,   532,     0,     0,     0,   546,
       0,     0,     0,     0,   201,   202,     0,     0,     0,   139,
       0,   169,     0,   560,     0,     0,    85,     0,     0,     0,
      77,   236,   237,     0,   222,     0,     0,   537,     0,     0,
       0,     0,     0,   284,     0,     0,   535,     0,     0,   554,
       0,     0,     0,     0,   540,     0,     0,     0,     0,   427,
     452,   451,   448,     0,     0,   482,   481,   363,   545,     0,
     479,     0,   580,   581,   531,     0,     0,     0,     0,     0,
       0,   586,     0,     0,   152,     0,     0,     0,   239,   256,
       0,    19,     0,    21,   181,     0,     0,     0,     0,     0,
     200,   257,     0,     0,     0,     0,     0,     0,     0,     0,
     296,   298,   302,   308,   307,   306,     0,   303,   300,   301,
       0,     0,     0,     0,   833,   311,   806,   810,   812,   814,
     816,   819,   826,   827,   835,   317,   316,   314,   320,   321,
     322,   319,   324,   325,   328,   327,     0,     0,     0,     0,
     359,     0,   371,   372,     0,   409,   406,   433,     0,   559,
     431,     0,     0,     0,     0,    65,     0,     0,    40,    42,
      43,    44,    45,    47,    48,    49,    41,    46,    36,    37,
       0,     0,    93,     0,    89,    91,    92,    96,    99,     0,
       0,     0,    35,    75,     0,     0,     0,     0,     0,     0,
       0,     0,   867,   872,     0,   868,     0,   855,   857,   858,
     859,   861,   863,   862,   860,   864,     0,     0,     0,   116,
       0,     0,   119,     0,     0,   500,   490,   533,   534,     0,
       0,   550,     0,   547,   491,     0,   604,     0,     0,   203,
     204,     0,   209,   171,     0,     0,   140,     0,     0,     0,
       0,     0,     0,    78,     0,     0,     0,     0,     0,     0,
     539,   538,   501,     0,   553,     0,     0,     0,     0,     0,
     499,     0,     0,   355,     0,     0,     0,     0,   543,     0,
     541,   495,     0,     0,   451,   449,     0,   440,     0,   429,
     430,     0,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   706,     0,     0,
       0,     0,     0,     0,    17,     0,   179,   210,     0,   268,
     264,   266,     0,   258,   259,     0,   716,   611,     0,   619,
     507,   508,   514,   515,   517,   561,   562,   518,   521,     0,
     226,     0,     0,     0,     0,     0,     0,     0,   305,     0,
       0,   817,   830,     0,   310,   312,     0,   849,     0,     0,
       0,     0,     0,     0,   805,   807,   808,   844,   845,   846,
     848,   847,     0,     0,   821,   820,     0,   824,   828,   842,
     840,   839,   832,   836,   330,   332,   334,   505,   336,   360,
     410,     0,   407,   432,    73,    74,    71,    72,   164,     0,
     163,     0,     0,    38,     0,     0,    94,    95,    97,     0,
      98,    63,    64,    69,    70,    60,   873,   876,     0,   866,
     865,     0,     0,   902,   870,   869,   901,     0,   878,     0,
     874,   877,     0,   903,   856,     0,     0,     0,     0,     0,
       0,   117,   123,     0,     0,     0,     0,     0,     0,   120,
       0,     0,     0,     0,     0,   554,     0,     0,   492,     0,
       0,   205,     0,     0,     0,     0,   250,     0,   247,   252,
     208,   172,   141,   170,     0,   173,     0,     0,    87,    81,
      84,    83,     0,    79,     0,   241,     0,     0,     0,     0,
     502,   151,     0,   282,   286,     0,     0,     0,   290,     0,
     357,   356,     0,     0,     0,   496,   283,   452,     0,   441,
       0,   475,   472,     0,   476,   477,     0,   478,   471,     0,
     446,   474,   473,     0,     0,     0,   573,   574,   570,     0,
       0,   578,   579,   575,   584,   582,     0,     0,     0,   588,
     149,   148,     0,   145,   144,   153,     0,   589,   590,     0,
       0,   265,   277,     0,   278,     0,   269,   270,   271,   272,
       0,   261,     0,   225,     0,     0,     0,     0,   511,   513,
     512,   509,   234,   235,   228,     0,   230,   227,     0,     0,
       0,   834,   825,   831,     0,     0,   904,   905,   915,   914,
     913,     0,     0,     0,     0,   906,   811,   912,     0,   809,
     813,     0,     0,   818,   822,     0,   843,   838,   841,   837,
     506,   434,     0,   166,   165,   168,     0,    39,    90,   100,
     871,     0,     0,   884,   879,   890,   118,   124,   126,   125,
       0,     0,     0,   121,     0,    14,   493,     0,   551,   552,
     555,   548,   549,   245,     0,     0,     0,   207,   248,   251,
       0,   142,     0,    86,     0,    80,   238,   243,   242,     0,
     503,     0,   285,   287,     0,     0,     0,   291,   358,   497,
       0,   544,   542,   451,     0,     0,   483,   451,     0,   447,
       9,     0,     0,     0,     0,     0,   587,     0,     0,   147,
     596,     0,   591,     0,   240,   281,   279,   280,   273,   274,
     275,   267,     0,   262,   260,     0,     0,   519,     0,   516,
     566,   510,   232,   229,     0,   231,   829,   916,     0,     0,
     908,     0,   854,   853,   852,   851,   850,   815,     0,   907,
     174,     0,   895,     0,     0,   895,     0,   886,     0,   880,
     881,     0,     0,     0,   122,     0,   494,   246,   254,   255,
     249,   206,     0,     0,    82,   244,   504,     0,     0,     0,
       0,   498,     0,   451,     0,     0,   451,   571,   572,   576,
     577,   583,   585,   150,     0,     0,   592,   603,   276,   263,
       0,   563,     0,     0,   233,   910,   909,     0,     0,   167,
       0,     0,   889,   896,   897,   891,   893,     0,   888,   885,
     883,     0,   875,     0,   127,   129,     0,     0,     0,     0,
       0,     0,     0,   294,    88,     0,   292,     0,   288,   461,
     455,   450,     0,   451,   442,     0,     0,   597,   564,   520,
       0,   911,   823,   900,   899,   898,     0,   892,   887,   882,
       0,     0,     0,     0,     0,     0,   128,     0,     0,     0,
     469,   463,     0,   462,   464,   470,   467,   457,     0,   456,
     458,   468,   444,     0,   443,     0,   565,   894,   130,   131,
       0,     0,     0,     0,   253,     0,   289,   454,   465,   466,
     453,   459,   460,   445,     0,     0,   132,   133,     0,     0,
       0,   293,     0,   593,     0,     0,     0,     0,     0,   135,
       0,     0,     0,   134,     0,     0,   594,     0,     0,     0,
       0,     0,   595,     0,     0,     0,     0,   136
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1315, -1315,   856, -1315,   854,   866, -1315,   881, -1315,   570,
     571,  -504, -1315,   477,  -275, -1315, -1315, -1315, -1315, -1315,
   -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315,  -891,
   -1315, -1315, -1315, -1315,    47,   279,   720, -1315, -1315,   707,
   -1315,    15,  -855, -1315,  -349,  -376, -1315, -1315,  -577, -1315,
    -887, -1315, -1315,   -77, -1315, -1315, -1315, -1315, -1315,   227,
     739, -1315, -1315, -1315,   222,   663, -1314,   882,   -88, -1315,
    -527,  -200, -1315, -1315, -1315, -1315,   228, -1315, -1315,   840,
   -1315, -1315, -1315, -1315, -1315,   148,  -516,  -650, -1315, -1315,
   -1315,     2, -1315, -1315,  -173,    23,   -73, -1315, -1315, -1315,
     -84, -1315, -1315,   172,   -81, -1315, -1315,   -66, -1177, -1315,
     654,     1, -1315, -1315,    -3, -1315, -1315,   596,   593, -1315,
    -514, -1315, -1315,  -570,    63,  -565,    58,    60, -1315, -1315,
   -1315, -1315, -1315,   844, -1315, -1315, -1315, -1315,  -564,  -288,
   -1066, -1315,  -104, -1315, -1315, -1315, -1315, -1315, -1315, -1315,
     -49, -1158, -1315, -1315,   256,   -13, -1315,  -556, -1315, -1315,
   -1315, -1315, -1315, -1315, -1315,   545, -1315,  -913, -1315,    -8,
   -1315,   438,  -706, -1315, -1315, -1315, -1315, -1315,  -358,  -350,
   -1116,  -992, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315,
   -1315, -1315,   355,  -638,  -775,    64,  -751, -1315,  -791,  -733,
   -1315, -1315, -1315, -1315, -1315, -1315, -1315,   759,   770,  -384,
     273,   103, -1315, -1315, -1315, -1315, -1315, -1315, -1315, -1315,
   -1315, -1315, -1315, -1315, -1315, -1315,   -29, -1315, -1315,   -37,
   -1315,  -366,  -114,   -16, -1315, -1315,  -739, -1315, -1315, -1315,
     150,   137,   -89,   393, -1315, -1315, -1315, -1315, -1315, -1315,
   -1315, -1315, -1315, -1315, -1315, -1315, -1315,   151, -1315, -1315,
   -1315,   -85,   395,   302, -1315, -1315, -1315, -1315, -1315,    90,
   -1315, -1315, -1231, -1315, -1315, -1315,  -797, -1315,  -215, -1315,
    -271, -1315, -1315, -1315, -1315, -1000, -1315,   162, -1315
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   828,   829,   830,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,  1128,
     679,   261,   262,   834,   835,   836,  1190,   263,   400,   401,
     264,  1091,   869,   265,  1454,  1455,   266,   267,   456,   268,
     512,   733,   958,  1191,   269,   270,   271,   272,   273,   402,
     403,   619,   622,   670,   671,  1167,  1050,   274,   275,   531,
     276,   277,   278,   541,   454,   891,   892,   279,   542,   280,
     544,   281,   282,   283,   548,   549,  1116,   758,   284,   681,
     737,   682,   667,  1117,  1118,  1119,   738,   545,   546,   973,
     974,  1353,   547,   970,   971,  1206,  1207,  1208,  1209,   285,
     692,   693,   286,  1147,  1148,   287,   288,   289,   290,   766,
     291,  1004,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   568,   569,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   595,   596,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   808,   331,   332,   333,  1169,
     711,   712,   713,  1471,  1508,  1509,  1502,  1503,  1510,  1504,
    1170,  1171,   334,   335,  1172,   336,   337,   338,   339,   340,
     341,   342,  1036,   759,   980,  1221,   981,  1358,   982,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   698,
    1104,   353,   354,   355,   356,   984,   985,   986,   987,   357,
     358,   359,   360,   361,   362,   730,   731,   363,  1197,  1198,
    1341,  1129,   465,   364,   365,   366,   775,  1014,  1015,   776,
     777,   778,   779,   780,  1024,  1253,  1254,   781,  1027,   782,
    1234,   783,   784,  1032,  1033,  1259,  1257,  1016,  1017,  1018,
    1019,  1375,   639,   857,   858,   859,   860,   861,   862,  1080,
    1388,  1389,  1081,  1387,  1450,   863,  1385,  1447,  1442,  1443,
    1444,   864,   865,  1020,  1028,  1244,  1021,  1240,  1005
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       449,   605,   493,   787,   745,   936,   773,  1037,  1037,   788,
     789,   790,   791,  1133,   774,   490,   466,  1099,   590,   485,
     983,  1034,  1035,   497,   743,  1168,  1255,  1426,     4,  1280,
    1349,  1350,  1000,   907,   757,   888,   814,   499,  1340,   762,
    1457,   763,   764,  1390,   765,   908,   767,   954,   753,  1006,
     479,  1071,   486,  1329,   768,   769,   919,   754,   604,   867,
    1098,   473,  1085,   983,   983,   753,   487,   754,  1086,   653,
     653,  1241,  1500,  1195,  1368,   529,  1161,  1161,  1162,   715,
    1055,  1469,  1440,   529,   941,   529,  1087,   668,   491,   654,
     654,  1192,   676,   680,   906,  1236,  1383,  1088,   983,   880,
     466,   846,   495,   604,   847,   962,   995,   993,   496,   997,
     916,    74,   916,  1137,   882,   937,   755,  1203,   474,  1122,
    1007,   895,  1089,    85,   523,   927,  1112,   992,  1409,   602,
     458,   532,  1237,  1113,  1092,   408,  1205,   533,   460,   943,
     603,   524,   534,   942,   677,  1458,  1441,   848,    99,  1369,
     535,  1228,   770,   669,  1384,   771,   530,  1439,  1159,   459,
     571,   983,   536,   616,  1264,  1163,   966,   963,  1470,   754,
     578,  1428,  1193,   955,  1500,   118,   881,   572,  1161,   579,
    1006,   938,  1164,  1164,  1165,  1165,   475,   476,   917,   678,
     933,   883,  1501,  1410,   889,   617,   929,   404,   896,  1058,
     868,   868,   928,  1008,  1009,   591,  1010,   773,   773,  1329,
     655,   124,   672,   672,  1072,   774,   774,   104,  1395,  1073,
     500,  1543,  1489,  1012,  1160,   756,  1459,  1216,  1158,  1242,
    1243,   890,   756,   116,   675,  1013,  1276,   716,  1556,  1051,
    1052,  1305,   756,   996,   756,   983,  1562,  1168,  1090,  1110,
     663,  1007,   998,   756,  1166,  1121,  1168,   537,  1138,   772,
     538,   944,   945,  1233,   843,   597,   550,  1477,   599,   632,
     947,  1372,   143,   930,   539,  1041,   946,   756,  1373,  1218,
    1041,   753,   849,   407,  1164,  1432,  1165,  1077,  1374,   589,
     649,  1486,   831,   450,  1528,     4,   850,  1534,   486,  1551,
     540,   486,   722,   723,  1078,   725,   726,   727,   728,   851,
    1219,   852,   118,   903,   672,   734,   735,   650,  1002,   652,
     574,   753,   853,   455,   854,  1456,   855,   461,  1220,   744,
     856,   451,   918,   832,  1008,  1009,   452,  1010,   833,   750,
     751,   118,  1536,   658,  1011,  1079,  1229,   575,  1238,  1301,
     688,   502,  1042,   503,  1012,  1239,   613,  1043,   615,  1161,
     576,   627,  1433,   623,   628,  1092,  1013,   466,  1487,   674,
    1506,  1315,  1109,   640,  1535,   685,  1552,   505,    74,   506,
     642,   453,   695,  1048,   697,   571,   700,  1451,   466,   703,
      85,   983,   948,   949,   577,  1456,   629,  1161,  1049,  1049,
     807,  1424,   572,   807,   714,  1263,  1202,   950,  1506,   508,
     719,  1112,  1168,   983,   509,    99,   661,  1203,  1113,   770,
    1044,   511,   771,   630,  1456,  1112,   610,  1204,  1394,   736,
    1161,  1162,  1113,   571,  1029,  1030,  1205,  1045,   773,  1357,
     457,   611,   118,  1248,   683,  1265,   774,   773,   466,  1114,
     572,   690,   691,   694,  1425,   774,  1031,   699,   773,   838,
     743,  1266,   706,   467,   839,  1164,   774,  1165,   754,   571,
    1161,  1162,   694,   573,  1061,  1062,  1507,  1505,  1511,  1065,
    1372,   983,  1553,   631,  1554,   590,   572,  1373,   802,   803,
    1115,  1146,   468,  1046,   732,   672,  1103,  1374,  1106,  1077,
    1567,   801,   739,  1164,  1316,  1165,   804,   580,  1101,  1437,
    1047,  1505,  1464,   606,  1531,   608,  1078,  1511,  1163,   367,
     368,   581,   369,   370,   469,   371,   372,   607,   488,   609,
    1082,   372,  1096,   672,   405,  1083,  1164,   406,  1165,   373,
    1097,   374,   375,  1153,   376,  1154,   377,   832,   969,   376,
     472,   377,   833,  1053,   378,   990,   492,  1069,  1163,   378,
    1074,   899,   470,   379,   902,   471,   672,  1053,  1070,   498,
     104,  1075,   598,   594,   885,   600,  1164,   601,  1165,   633,
     634,   635,   805,   501,   897,   805,   116,  1066,   805,  1067,
     504,  1174,  1179,  1175,  1180,   380,   381,   382,   612,   507,
     614,   913,   816,   592,   593,   817,   672,  1324,   510,   837,
     104,  1063,  1064,   924,   925,  1093,  1094,  1412,   511,   932,
     513,  1415,   515,   636,   637,   143,   116,  1346,  1347,   871,
     872,   873,   514,  1057,   785,   786,   792,   793,   517,  1060,
     794,   795,   383,  1483,  1484,   959,   516,  1328,   518,   520,
     887,   384,   893,   527,   528,  1478,   551,  1479,   552,   466,
     582,   570,   466,   584,   594,   143,   583,   585,   604,   618,
    1367,   372,  1370,  1371,   621,   624,   625,   638,   641,   645,
     643,   644,   999,   385,   651,   662,   666,   773,   672,   664,
    1498,   665,   684,   689,   934,   774,   701,   983,   696,   983,
    1519,   702,   386,   707,   709,  1516,  1135,  1472,   406,   432,
    1475,   464,   387,  1161,  1162,  1141,   710,  1143,  1144,   818,
     819,   820,   821,   822,   823,   824,   825,   826,   827,   471,
     967,   478,   983,  1156,   717,   718,   721,   988,   720,  1381,
     724,   746,   729,   388,  1176,  1177,  1178,   983,  1181,  1182,
    1183,  1184,  1185,  1186,   742,  1188,  1189,   747,   748,   752,
     749,  1303,   796,   797,   798,   799,   809,  1513,   969,   389,
     390,   391,   392,   393,   812,   394,   395,   396,   397,   398,
     988,   988,   988,   988,   399,   813,   815,   840,   841,   844,
     371,   845,  1224,   866,  1226,  1227,   372,   875,  1435,  1436,
     870,  1163,   874,   900,   373,   877,   374,   876,   894,   878,
     901,   904,   879,   886,   376,   988,   377,   898,   905,  1164,
     910,  1165,   911,   915,   378,   909,   922,   553,   379,   914,
     920,  1068,   921,   951,  1149,   554,   555,  1345,   556,   923,
     926,  1261,   952,   939,   940,   956,   557,   961,   964,   672,
     558,   953,   559,   104,   968,   972,   975,   560,   960,  1269,
     380,   381,   965,   384,  1105,   989,  1105,  1481,   991,   116,
     994,  1003,  1023,   561,  1022,  1039,  1026,  1040,   988,   753,
     833,  1054,  1059,  1076,  1100,  1102,  1111,  1108,   668,  1124,
    1414,  1125,  1127,  1095,  1126,   385,  1132,   562,   563,   564,
     565,   566,   567,  1130,  1131,  1134,  1139,  1136,   143,  1293,
    1140,   699,  1142,   699,  1297,  1146,   384,  1145,  1157,  1152,
    1173,  1187,  1150,  1196,   387,  1151,  1302,  1155,  1199,  1194,
    1200,   629,  1210,  1212,  1214,  1215,  1307,  1308,  1404,  1231,
    1217,  1225,  1230,  1251,  1232,  1313,  1258,  1260,   385,  1235,
    1245,     4,  1270,  1252,  1273,   868,  1211,  1271,  1278,   550,
    1256,  1262,   988,  1285,  1272,  1290,  1288,  1289,  1275,  1294,
    1281,  1295,  1291,  1222,  1292,  1223,  1296,   387,  1279,  1284,
    1282,   646,   390,   391,   392,   393,  1429,   394,   395,   647,
     397,   398,  1300,  1304,  1309,  1318,  1323,  1321,  1326,  1343,
    1322,  1337,  1331,  1338,  1332,  1330,  1203,  1333,   388,  1334,
     969,  1352,  1359,  1360,  1287,  1361,  1364,  1366,  1378,  1335,
    1380,  1379,  1077,  1391,  1393,  1362,  1386,  1396,  1363,  1403,
    1365,  1402,  1406,  1408,   389,   390,   391,   392,   393,  1430,
     394,   395,   396,   397,   398,  1382,  1411,  1445,  1431,   399,
    1427,  1311,  1446,  1449,  1452,  1453,  1461,  1462,  1465,  1476,
    1480,  1482,  1488,  1490,  1320,  1491,  1474,  1493,  1494,  1497,
    1499,  1512,  1514,  1517,  1460,  1522,  1527,  1525,  1530,  1533,
    1523,  1520,  1049,  1540,  1544,  1542,  1555,  1557,  1560,  1559,
    1564,   519,   521,  1538,  1397,  1548,  1563,   740,   741,  1298,
    1401,   626,  1268,  1545,   522,  1550,   842,   648,   988,  1405,
    1566,  1056,  1496,  1283,  1518,  1339,   620,  1123,   683,   673,
    1120,   543,   525,  1213,   526,  1400,   694,  1344,  1354,  1351,
     988,  1417,  1418,  1419,  1420,  1421,  1306,  1422,  1423,  1299,
    1201,  1348,   708,  1312,  1317,   761,   588,   760,   811,   935,
    1327,  1532,  1325,  1529,  1038,  1107,  1277,  1267,  1336,  1250,
    1342,  1246,  1377,  1376,  1434,  1001,  1249,   656,  1084,  1274,
    1448,   732,  1485,     0,  1247,     0,  1025,     0,   657,     0,
     486,     0,     0,     0,   739,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   988,     0,
       0,     0,  1463,     0,     0,     0,     0,     0,  1466,     0,
    1468,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1392,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1398,
    1399,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1438,     0,     0,     0,     0,     0,     0,     0,  1407,  1526,
       0,     0,     0,     0,     0,     0,     0,     0,  1413,     0,
       0,     0,  1416,     0,     0,     0,     0,     0,     0,     0,
    1537,     0,     0,     0,     0,  1541,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1549,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1467,     0,     0,     0,     0,  1473,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   486,
       0,     0,     0,     0,   988,     0,   988,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1492,     0,     0,  1495,     0,     0,     0,     0,   988,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1515,     0,     0,     0,   988,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   988,     0,  1521,     0,     0,
       0,  1524,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1539,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1546,     0,  1547,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,     0,     0,  1558,
       0,     2,     3,  1561,     4,     0,     0,     0,  1565,     5,
       6,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     0,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,     0,    72,    73,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,    85,
       0,    86,    87,    88,    89,     0,    90,     0,     0,     0,
      91,    92,    93,    94,    95,     0,     0,     0,     0,     0,
       0,    96,    97,    98,    99,   100,   101,   102,     0,     0,
       0,   103,   104,   105,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,     0,
     117,   118,     0,     0,   119,   120,   121,     0,     0,     0,
     122,     0,   123,   124,   125,     0,   126,   127,   128,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   144,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     409,   410,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   419,    22,    23,
      24,    25,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,   105,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,   117,   118,     0,     0,   119,   120,   121,     0,     0,
       0,   122,   489,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     435,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     409,   410,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   419,    22,    23,
      24,    25,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,   105,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,   117,   118,     0,     0,   119,   120,   121,     0,   800,
       0,   122,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     435,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     409,   410,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   419,    22,    23,
      24,    25,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,   105,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,   117,   118,     0,     0,   119,   120,   121,     0,     0,
       0,   122,   806,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     435,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     409,   410,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   419,    22,    23,
      24,    25,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,   105,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,   117,   118,     0,     0,   119,   120,   121,     0,     0,
       0,   122,   810,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     435,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     409,   410,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   419,    22,    23,
      24,    25,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,   105,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,   117,   118,     0,     0,   119,   120,   121,     0,   884,
       0,   122,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     435,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     409,   410,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   419,    22,    23,
      24,    25,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,   105,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,   117,   118,     0,     0,   119,   120,   121,     0,   912,
       0,   122,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     435,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     409,   410,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   419,    22,    23,
      24,    25,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,   105,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,   117,   118,     0,     0,   119,   120,   121,     0,   931,
       0,   122,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     435,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     409,   410,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   419,    22,    23,
      24,    25,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,   105,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,   117,   118,     0,     0,   119,   120,   121,     0,  1286,
       0,   122,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     435,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     409,   410,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   419,    22,    23,
      24,    25,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,   105,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,   117,   118,     0,     0,   119,   120,   121,     0,  1310,
       0,   122,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     435,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     409,   410,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   419,    22,    23,
      24,    25,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,   105,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,   117,   118,     0,     0,   119,   120,   121,     0,  1319,
       0,   122,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     435,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
       5,     6,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
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
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
       5,     6,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,   105,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,   117,   118,     0,     0,   119,   120,   121,     0,     0,
       0,   122,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     435,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     409,   410,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   419,    22,    23,
      24,    25,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,   105,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,   117,   118,     0,     0,   119,   120,   121,     0,     0,
       0,   122,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     435,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     409,   410,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,   415,   416,    19,   418,   419,    22,   420,
      24,    25,     0,    26,    27,    28,    29,   421,    31,    32,
      33,    34,    35,    36,   424,    38,    39,   425,     0,    41,
      42,    43,   427,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   430,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,   586,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,   587,   118,     0,     0,   119,   120,   121,     0,     0,
       0,   122,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     435,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     436,   154,   438,   156,   439,   440,   159,   160,   161,   162,
     163,   164,   441,   166,   442,   443,   444,   445,   171,   172,
     446,   447,   175,   448,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     409,   410,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,   415,   416,    19,   418,   419,    22,   420,
      24,    25,     0,    26,    27,    28,    29,   421,    31,    32,
      33,    34,    35,    36,   424,    38,    39,   425,     0,    41,
      42,    43,   427,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   430,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,   105,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,   117,   118,     0,     0,   119,   120,   121,     0,     0,
       0,   122,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     435,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     436,   154,   438,   156,   439,   440,   159,   160,   161,   162,
     163,   164,   441,   166,   442,   443,   444,   445,   171,   172,
     446,   447,   175,   448,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     957,   410,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   419,    22,    23,
      24,    25,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,   105,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,   117,   118,     0,     0,   119,   120,   121,     0,     0,
       0,   122,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     435,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     409,   410,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,   415,   416,    19,   418,   419,    22,   420,
      24,    25,     0,    26,    27,    28,    29,   421,    31,    32,
      33,    34,    35,    36,   424,    38,    39,   425,     0,    41,
      42,    43,   427,    45,   428,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   430,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,     0,     0,     0,     0,   119,   120,   121,     0,     0,
       0,   122,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     435,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     436,   154,   438,   156,   439,   440,   159,   160,   161,   162,
     163,   164,   441,   166,   442,   443,   444,   445,   171,   172,
     446,   447,   175,   448,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     409,   410,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,   415,   416,    19,   418,   419,    22,   420,
      24,    25,     0,    26,    27,    28,    29,   421,    31,    32,
      33,    34,    35,    36,   424,    38,    39,   425,     0,    41,
      42,    43,   427,    45,   428,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   430,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,     0,     0,     0,     0,   119,   120,   121,     0,     0,
       0,   122,     0,   123,   124,   125,     0,     0,     0,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     435,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     436,   154,   438,   156,   439,   440,   159,   160,   161,   162,
     163,   164,   441,   166,   442,   443,   444,   445,   171,   172,
     446,   447,   175,   448,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     0,     0,     0,     0,     0,
     409,   410,     0,     7,     8,   480,    10,    11,    12,    13,
     412,    15,   481,   415,   416,   417,   418,   419,    22,   420,
      24,    25,     0,    26,    27,    28,    29,   421,    31,   482,
      33,    34,    35,    36,   424,    38,    39,   425,     0,    41,
     483,    43,   427,    45,   428,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   484,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   430,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   100,   101,   102,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   433,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,     0,   123,   124,     0,     0,     0,     0,   128,
       0,   129,     0,   130,   131,   132,   133,   434,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,     0,     0,
     435,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     436,   154,   438,   156,   439,   440,   159,   160,   161,   162,
     163,   164,   441,   166,   442,   443,   444,   445,   171,   172,
     446,   447,   175,   448,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     0,     0,     0,     0,     0,
     409,   410,     0,     7,     8,   411,    10,    11,    12,    13,
     412,   413,   414,   415,   416,   417,   418,   419,    22,   420,
      24,    25,     0,    26,    27,    28,    29,   421,    31,   422,
      33,    34,   423,    36,   424,    38,    39,   425,     0,    41,
     426,    43,   427,    45,   428,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   429,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   430,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   100,   101,   102,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   433,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,     0,   123,     0,     0,     0,     0,     0,   128,
       0,   129,     0,   130,   131,   132,   133,   434,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,     0,     0,
     435,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     436,   437,   438,   156,   439,   440,   159,   160,   161,   162,
     163,   164,   441,   166,   442,   443,   444,   445,   171,   172,
     446,   447,   175,   448,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   462,     0,     0,     0,     3,
       0,     0,     0,     0,     0,     0,   409,   410,     0,     7,
       8,   411,    10,    11,    12,    13,   412,   413,   414,   415,
     416,   417,   418,   419,    22,   420,    24,    25,     0,    26,
      27,    28,    29,   421,    31,   422,    33,    34,   423,    36,
     424,    38,    39,   425,     0,    41,   426,    43,   427,    45,
     428,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   429,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   430,    92,    93,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,     0,   100,   101,   102,   463,     0,     0,   464,     0,
       0,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   433,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,     0,     0,     0,   122,     0,   123,
       0,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   434,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,     0,     0,   435,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   436,   437,   438,   156,
     439,   440,   159,   160,   161,   162,   163,   164,   441,   166,
     442,   443,   444,   445,   171,   172,   446,   447,   175,   448,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   462,     0,     0,     0,     3,     0,   686,     0,     0,
       0,     0,   409,   410,     0,     7,     8,   411,    10,    11,
      12,    13,   412,   413,   414,   415,   416,   417,   418,   419,
      22,   420,    24,    25,     0,    26,    27,    28,    29,   421,
      31,   422,    33,    34,   423,    36,   424,    38,    39,   425,
       0,    41,   426,    43,   427,    45,   428,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    62,     0,    63,    64,    65,   429,     0,     0,
      69,    70,    71,     0,     0,     0,    73,     0,     0,     0,
       0,    75,    76,    77,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   430,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,   100,   101,
     102,     0,     0,     0,     0,     0,     0,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   111,   433,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,   122,   687,   123,     0,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   434,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   435,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   436,   437,   438,   156,   439,   440,   159,   160,
     161,   162,   163,   164,   441,   166,   442,   443,   444,   445,
     171,   172,   446,   447,   175,   448,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,     0,   187,   188,   189,
       0,   190,   191,   192,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   462,     0,     0,
       0,     3,     0,     0,     0,     0,     0,     0,   409,   410,
       0,     7,     8,   411,    10,    11,    12,    13,   412,   413,
     414,   415,   416,   417,   418,   419,    22,   420,    24,    25,
       0,    26,    27,    28,    29,   421,    31,   422,    33,    34,
     423,    36,   424,    38,    39,   425,     0,    41,   426,    43,
     427,    45,   428,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    62,     0,
      63,    64,    65,   429,     0,     0,    69,    70,    71,     0,
       0,     0,    73,     0,     0,     0,     0,    75,    76,    77,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   430,
      92,    93,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,   100,   101,   102,     0,     0,     0,
       0,     0,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   111,   433,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   122,
       0,   123,     0,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   434,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   435,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   436,   437,
     438,   156,   439,   440,   159,   160,   161,   162,   163,   164,
     441,   166,   442,   443,   444,   445,   171,   172,   446,   447,
     175,   448,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,     0,   187,   188,   189,     0,   190,   191,   192,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   494,     0,     3,     0,     0,     0,     0,
       0,     0,   409,   410,     0,     7,     8,   411,    10,    11,
      12,    13,   412,   413,   414,   415,   416,   417,   418,   419,
      22,   420,    24,    25,     0,    26,    27,    28,    29,   421,
      31,   422,    33,    34,   423,    36,   424,    38,    39,   425,
       0,    41,   426,    43,   427,    45,   428,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    62,     0,    63,    64,    65,   429,     0,     0,
      69,    70,    71,     0,     0,     0,    73,     0,     0,     0,
       0,    75,    76,    77,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   430,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,   100,   101,
     102,     0,     0,     0,     0,     0,     0,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   111,   433,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,   122,     0,   123,     0,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   434,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   435,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   436,   437,   438,   156,   439,   440,   159,   160,
     161,   162,   163,   164,   441,   166,   442,   443,   444,   445,
     171,   172,   446,   447,   175,   448,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,     0,   187,   188,   189,
       0,   190,   191,   192,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,     3,     0,     0,
       0,     0,     0,     0,   409,   410,     0,     7,     8,   480,
      10,    11,    12,    13,   412,    15,   481,   415,   416,   976,
     418,   419,    22,   420,    24,    25,     0,    26,    27,    28,
      29,   421,    31,   482,    33,    34,    35,    36,   424,    38,
      39,   425,     0,    41,   483,    43,   427,    45,   428,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    62,     0,    63,    64,    65,   484,
       0,     0,    69,    70,    71,     0,     0,     0,    73,     0,
       0,     0,     0,    75,    76,    77,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   430,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     0,
     100,   101,   977,     0,     0,     0,   978,     0,     0,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   111,   433,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   122,  1355,   123,   124,     0,
       0,     0,     0,  1356,     0,   129,     0,   130,   131,   132,
     133,   434,   135,   136,   137,   138,   139,   140,     0,     0,
     979,   142,     0,     0,   435,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   436,   154,   438,   156,   439,   440,
     159,   160,   161,   162,   163,   164,   441,   166,   442,   443,
     444,   445,   171,   172,   446,   447,   175,   448,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,     0,   187,
     188,   189,     0,   190,   191,   192,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,     3,
       0,     0,     0,     0,     0,     0,   409,   410,     0,     7,
       8,   480,    10,    11,    12,    13,   412,    15,   481,   415,
     416,   976,   418,   419,    22,   420,    24,    25,     0,    26,
      27,    28,    29,   421,    31,   482,    33,    34,    35,    36,
     424,    38,    39,   425,     0,    41,   483,    43,   427,    45,
     428,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   484,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,  1314,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   430,    92,    93,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,     0,   100,   101,   977,     0,     0,     0,   978,     0,
       0,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   433,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,     0,     0,     0,   122,     0,   123,
     124,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   434,   135,   136,   137,   138,   139,   140,
       0,     0,   979,   142,     0,     0,   435,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   436,   154,   438,   156,
     439,   440,   159,   160,   161,   162,   163,   164,   441,   166,
     442,   443,   444,   445,   171,   172,   446,   447,   175,   448,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     3,     0,     0,     0,     0,     0,     0,   409,   410,
       0,     7,     8,   411,    10,    11,    12,    13,   412,   413,
     414,   415,   416,   417,   418,   419,    22,   420,    24,    25,
       0,    26,    27,    28,    29,   421,    31,   422,    33,    34,
     423,    36,   424,    38,    39,   425,     0,    41,   426,    43,
     427,    45,   428,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    62,     0,
      63,    64,    65,   429,     0,     0,    69,    70,    71,     0,
       0,     0,    73,     0,     0,     0,     0,    75,    76,    77,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   430,
      92,    93,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,   100,   101,   102,   431,     0,     0,
     432,     0,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   111,   433,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   122,
       0,   123,     0,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   434,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   435,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   436,   437,
     438,   156,   439,   440,   159,   160,   161,   162,   163,   164,
     441,   166,   442,   443,   444,   445,   171,   172,   446,   447,
     175,   448,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,     0,   187,   188,   189,     0,   190,   191,   192,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,     3,     0,     0,     0,     0,     0,     0,
     409,   410,     0,     7,     8,   411,    10,    11,    12,    13,
     412,   413,   414,   415,   416,   417,   418,   419,    22,   420,
      24,    25,     0,    26,    27,    28,    29,   421,    31,   422,
      33,    34,   423,    36,   424,    38,    39,   425,     0,    41,
     426,    43,   427,    45,   428,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   429,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   430,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   100,   101,   102,   477,
       0,     0,   478,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   433,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,     0,   123,     0,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   434,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,     0,     0,
     435,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     436,   437,   438,   156,   439,   440,   159,   160,   161,   162,
     163,   164,   441,   166,   442,   443,   444,   445,   171,   172,
     446,   447,   175,   448,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     3,     0,     0,     0,     0,
       0,     0,   409,   410,     0,     7,     8,   411,    10,    11,
      12,    13,   412,   413,   414,   415,   416,   417,   418,   419,
      22,   420,    24,    25,     0,    26,    27,    28,    29,   421,
      31,   422,    33,    34,   423,    36,   424,    38,    39,   425,
       0,    41,   426,    43,   427,    45,   428,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    62,     0,    63,    64,    65,   429,     0,     0,
      69,    70,    71,     0,     0,     0,    73,     0,     0,     0,
       0,    75,    76,    77,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   430,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,   100,   101,
     102,     0,     0,     0,     0,     0,     0,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   111,   433,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,   122,   659,   123,     0,     0,     0,     0,
       0,   660,     0,   129,     0,   130,   131,   132,   133,   434,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   435,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   436,   437,   438,   156,   439,   440,   159,   160,
     161,   162,   163,   164,   441,   166,   442,   443,   444,   445,
     171,   172,   446,   447,   175,   448,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,     0,   187,   188,   189,
       0,   190,   191,   192,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,     3,     0,     0,
       0,     0,     0,     0,   409,   410,     0,     7,     8,   411,
      10,    11,    12,    13,   412,   413,   414,   415,   416,   417,
     418,   419,    22,   420,    24,    25,     0,    26,    27,    28,
      29,   421,    31,   422,    33,    34,   423,    36,   424,    38,
      39,   425,     0,    41,   426,    43,   427,    45,   428,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    62,     0,    63,    64,    65,   429,
       0,     0,    69,    70,    71,     0,     0,     0,    73,     0,
       0,     0,     0,    75,    76,    77,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   430,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     0,
     100,   101,   102,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   111,   433,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   122,   704,   123,     0,     0,
       0,     0,     0,   705,     0,   129,     0,   130,   131,   132,
     133,   434,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   435,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   436,   437,   438,   156,   439,   440,
     159,   160,   161,   162,   163,   164,   441,   166,   442,   443,
     444,   445,   171,   172,   446,   447,   175,   448,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,     0,   187,
     188,   189,     0,   190,   191,   192,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,     3,
       0,     0,     0,     0,     0,     0,   409,   410,     0,     7,
       8,   480,    10,    11,    12,    13,   412,    15,   481,   415,
     416,   976,   418,   419,    22,   420,    24,    25,     0,    26,
      27,    28,    29,   421,    31,   482,    33,    34,    35,    36,
     424,    38,    39,   425,     0,    41,   483,    43,   427,    45,
     428,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   484,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   430,    92,    93,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,     0,   100,   101,   977,     0,     0,     0,   978,     0,
       0,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   433,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,     0,     0,     0,   122,     0,   123,
     124,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   434,   135,   136,   137,   138,   139,   140,
       0,     0,   979,   142,     0,     0,   435,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   436,   154,   438,   156,
     439,   440,   159,   160,   161,   162,   163,   164,   441,   166,
     442,   443,   444,   445,   171,   172,   446,   447,   175,   448,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     3,     0,     0,     0,     0,     0,     0,   409,   410,
       0,     7,     8,   480,    10,    11,    12,    13,   412,    15,
     481,   415,   416,   976,   418,   419,    22,   420,    24,    25,
       0,    26,    27,    28,    29,   421,    31,   482,    33,    34,
      35,    36,   424,    38,    39,   425,     0,    41,   483,    43,
     427,    45,   428,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    62,     0,
      63,    64,    65,   484,     0,     0,    69,    70,    71,     0,
       0,     0,    73,     0,     0,     0,     0,    75,    76,    77,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   430,
      92,    93,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,   100,   101,   977,     0,     0,     0,
     978,     0,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   111,   433,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   122,
       0,   123,   124,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   434,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   435,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   436,   154,
     438,   156,   439,   440,   159,   160,   161,   162,   163,   164,
     441,   166,   442,   443,   444,   445,   171,   172,   446,   447,
     175,   448,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,     0,   187,   188,   189,     0,   190,   191,   192,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,     3,     0,     0,     0,     0,     0,     0,
     409,   410,     0,     7,     8,   411,    10,    11,    12,    13,
     412,   413,   414,   415,   416,   417,   418,   419,    22,   420,
      24,    25,     0,    26,    27,    28,    29,   421,    31,   422,
      33,    34,   423,    36,   424,    38,    39,   425,     0,    41,
     426,    43,   427,    45,   428,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   429,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   430,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   100,   101,   102,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   433,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,     0,   123,     0,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   434,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,     0,     0,
     435,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     436,   437,   438,   156,   439,   440,   159,   160,   161,   162,
     163,   164,   441,   166,   442,   443,   444,   445,   171,   172,
     446,   447,   175,   448,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        16,   367,   116,   573,   531,   711,   570,   798,   799,   574,
     575,   576,   577,   904,   570,   103,    32,   872,   306,    68,
     753,   796,   797,   127,   528,   938,  1026,  1341,    20,  1095,
    1207,  1208,   771,   683,   550,    49,   613,    21,  1196,   553,
     111,   555,   556,  1274,   558,   683,   560,   100,    87,    89,
      66,   106,    68,  1169,   568,   569,   694,    89,    20,    87,
      87,    87,    30,   796,   797,    87,    82,    89,    36,    37,
      37,    89,     4,   960,    45,   100,     8,     8,     9,     7,
     831,    86,   127,   100,   122,   100,    54,   111,   104,    57,
      57,   100,   458,   459,   133,   208,    89,    65,   831,   100,
     116,    47,   118,    20,    50,    38,   138,   757,   124,   759,
     100,   103,   100,   133,   100,   121,   138,    99,   144,   894,
     160,   100,    90,   115,    25,   100,    46,   138,   111,   136,
      26,    33,   245,    53,   867,   147,   118,    39,   111,    87,
     147,    42,    44,   181,   106,   216,   191,    93,   140,   120,
      52,   138,   144,   177,   147,   147,   181,   174,   121,    55,
     149,   894,    64,   160,  1051,    96,   181,   100,   173,    89,
     191,  1348,   181,   226,     4,   167,   177,   166,     8,   200,
      89,   187,   114,   114,   116,   116,   212,   213,   178,   151,
     178,   177,   124,   176,   208,   192,   100,   151,   177,   837,
     228,   228,   177,   243,   244,   309,   246,   771,   772,  1325,
     177,   179,   144,   144,   269,   771,   772,   148,  1284,   274,
     204,  1535,  1453,   263,   187,   264,   297,   978,   934,   247,
     248,   245,   264,   164,   151,   275,  1091,   165,  1552,   816,
     817,  1132,   264,   759,   264,   978,  1560,  1160,   216,   887,
     450,   160,   766,   264,   185,   893,  1169,   159,   908,   251,
     162,   209,   210,  1002,   630,   314,   282,  1425,   317,   383,
      87,   260,   203,   177,   176,   100,   224,   264,   267,   135,
     100,    87,   228,   144,   114,   100,   116,    89,   277,   144,
     404,   100,    87,   144,   124,    20,   242,   100,   314,   100,
     202,   317,   502,   503,   106,   505,   506,   507,   508,   255,
     166,   257,   167,   679,   144,   515,   516,   405,   144,   407,
     110,    87,   268,   147,   270,  1391,   272,    39,   184,   529,
     276,    61,   138,   128,   243,   244,    66,   246,   133,   539,
     540,   167,  1519,   431,   253,   147,   996,   137,   259,  1124,
     464,   216,   177,   218,   263,   266,   372,   177,   374,     8,
     150,    37,   177,   379,    40,  1098,   275,   383,   177,   457,
      19,  1146,   138,   389,   177,   463,   177,   216,   103,   218,
     396,   111,   470,   128,   472,   149,   474,  1387,   404,   477,
     115,  1124,   209,   210,   184,  1461,    72,     8,   144,   144,
     600,   147,   166,   603,   492,   128,    88,   224,    19,   216,
     498,    46,  1325,  1146,   221,   140,   432,    99,    53,   144,
     139,   144,   147,    99,  1490,    46,   157,   109,  1283,   517,
       8,     9,    53,   149,   239,   240,   118,   156,  1002,  1214,
     147,   172,   167,  1013,   460,   128,  1002,  1011,   464,    70,
     166,   467,   468,   469,   200,  1011,   261,   473,  1022,   128,
     964,   144,   478,   147,   133,   114,  1022,   116,    89,   149,
       8,     9,   488,   189,   840,   841,   125,  1469,  1470,   845,
     260,  1214,  1548,   159,  1550,   773,   166,   267,   592,   593,
     111,    93,   111,   139,   510,   144,   880,   277,   882,    89,
    1566,   589,   518,   114,   106,   116,   594,   127,   874,   189,
     156,  1503,  1403,   172,   125,   172,   106,  1509,    96,    28,
      29,   141,    31,    32,   111,    34,    40,   186,   111,   186,
     269,    40,   290,   144,   144,   274,   114,   147,   116,    48,
     298,    50,    51,   927,    58,   929,    60,   128,   748,    58,
     147,    60,   133,   828,    68,   755,   144,   254,    96,    68,
     254,   675,   144,    72,   678,   147,   144,   842,   265,   144,
     148,   265,   316,   145,   662,   147,   114,   321,   116,   212,
     213,   214,   595,   206,   672,   598,   164,   268,   601,   270,
     147,   223,   223,   225,   225,   104,   105,   106,   371,   216,
     373,   689,   618,   182,   183,   621,   144,   185,   111,   625,
     148,   119,   120,   701,   702,   282,   283,  1323,   144,   707,
     233,  1327,   234,   291,   292,   203,   164,   119,   120,   645,
     646,   647,   233,   833,   571,   572,   578,   579,   144,   839,
     580,   581,   151,  1440,  1441,   733,   147,   185,   111,     0,
     666,   160,   668,   181,   181,  1430,   158,  1432,    85,   675,
      43,   250,   678,    94,   145,   203,   190,    95,    20,    40,
    1235,    40,  1242,  1243,    40,   143,   111,   238,   284,   294,
     289,   289,   770,   192,   177,   144,   111,  1251,   144,   275,
    1465,   275,   111,   144,   710,  1251,   144,  1430,   177,  1432,
    1491,   144,   211,   144,   177,  1480,   906,  1413,   147,   147,
    1416,   147,   221,     8,     9,   915,    27,   917,   918,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,   147,
     746,   147,  1465,   933,    15,   177,    20,   753,   204,  1266,
     177,   111,   222,   252,   944,   945,   946,  1480,   948,   949,
     950,   951,   952,   953,    25,   955,   956,   159,   161,   100,
     161,  1127,   222,    87,    87,    87,   140,  1473,   968,   278,
     279,   280,   281,   282,   100,   284,   285,   286,   287,   288,
     796,   797,   798,   799,   293,   100,    20,   151,   151,   118,
      34,   123,   992,   238,   994,   995,    40,   174,  1368,  1369,
     290,    96,   123,    89,    48,   177,    50,   174,    87,   177,
      37,    89,   174,   174,    58,   831,    60,   177,   100,   114,
     177,   116,   177,   133,    68,   174,   144,   123,    72,   177,
     174,   847,   177,    87,   922,   131,   132,  1203,   134,   174,
     174,  1041,   228,   174,   174,   133,   142,   174,   181,   144,
     146,   216,   148,   148,   161,   111,   111,   153,   177,  1059,
     104,   105,   106,   160,   880,   111,   882,  1437,   111,   164,
     138,   276,   251,   169,   249,   174,   258,   175,   894,    87,
     133,   123,   133,    20,   290,   144,   245,   174,   111,    87,
     185,   174,   123,   218,   188,   192,    89,   193,   194,   195,
     196,   197,   198,   151,   123,   111,   144,   133,   203,  1109,
     174,   927,   111,   929,  1114,    93,   160,   138,    27,   144,
      20,   111,   174,   237,   221,   174,  1126,   174,   144,   174,
     111,    72,   100,   100,   147,   147,  1136,  1137,  1304,   174,
     147,   138,   138,   138,   177,  1145,    71,   135,   192,   241,
     241,    20,    20,   273,    20,   228,   972,   269,   218,   975,
     277,  1049,   978,   181,   277,   135,   177,   177,   277,   138,
     278,   111,   177,   989,   177,   991,   111,   221,   218,   218,
     296,   278,   279,   280,   281,   282,  1352,   284,   285,   286,
     287,   288,    70,   100,   133,   174,   123,   177,     6,  1199,
     177,   176,   224,   133,   224,   181,    99,   224,   252,   224,
    1210,    99,   177,   177,  1102,   177,   138,   174,   144,   228,
     174,   271,    89,   161,   248,  1225,   262,   174,  1228,    89,
    1230,   117,   174,   176,   278,   279,   280,   281,   282,    87,
     284,   285,   286,   287,   288,   277,   174,    20,   177,   293,
     174,  1139,    20,    20,   177,   100,   161,    46,    87,   111,
      87,   174,   256,   100,  1152,    87,   187,   111,   216,   111,
     176,   187,   187,    20,   278,   111,    86,   176,   173,   187,
     216,   295,   144,   111,   284,   111,   111,   189,   177,   278,
     111,   235,   238,   295,  1294,   296,   216,   527,   527,  1115,
    1300,   381,  1055,   295,   238,   296,   629,   400,  1124,  1309,
     296,   832,  1461,  1098,  1490,  1192,   377,   895,  1134,   456,
     892,   281,   241,   975,   242,  1298,  1142,  1200,  1212,  1210,
    1146,  1331,  1332,  1333,  1334,  1335,  1134,  1337,  1338,  1116,
     968,  1207,   488,  1142,  1147,   552,   302,   551,   603,   711,
    1166,  1509,  1160,  1503,   799,   882,  1092,  1054,  1187,  1022,
    1197,  1011,  1251,  1248,  1364,   772,  1015,   408,   866,  1079,
    1385,  1187,  1443,    -1,  1012,    -1,   781,    -1,   408,    -1,
    1196,    -1,    -1,    -1,  1200,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1214,    -1,
      -1,    -1,  1402,    -1,    -1,    -1,    -1,    -1,  1408,    -1,
    1410,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1281,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1295,
    1296,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1378,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1314,  1499,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1324,    -1,
      -1,    -1,  1328,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1520,    -1,    -1,    -1,    -1,  1525,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1545,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1409,    -1,    -1,    -1,    -1,  1414,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1425,
      -1,    -1,    -1,    -1,  1430,    -1,  1432,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1457,    -1,    -1,  1460,    -1,    -1,    -1,    -1,  1465,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1476,    -1,    -1,    -1,  1480,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1491,    -1,  1493,    -1,    -1,
      -1,  1497,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1522,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1540,    -1,  1542,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,  1555,
      -1,    17,    18,  1559,    20,    -1,    -1,    -1,  1564,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      -1,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    -1,   115,
      -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,
     126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,
      -1,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
      -1,   147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
     166,   167,    -1,    -1,   170,   171,   172,    -1,    -1,    -1,
     176,    -1,   178,   179,   180,    -1,   182,   183,   184,    -1,
     186,    -1,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,    -1,    -1,   201,   202,   203,    -1,   205,
     206,    -1,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,   250,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,    -1,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
     115,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,   166,   167,    -1,    -1,   170,   171,   172,    -1,    -1,
      -1,   176,   177,   178,   179,   180,    -1,   182,   183,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,   203,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
     115,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,   166,   167,    -1,    -1,   170,   171,   172,    -1,   174,
      -1,   176,    -1,   178,   179,   180,    -1,   182,   183,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,   203,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
     115,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,   166,   167,    -1,    -1,   170,   171,   172,    -1,    -1,
      -1,   176,   177,   178,   179,   180,    -1,   182,   183,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,   203,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
     115,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,   166,   167,    -1,    -1,   170,   171,   172,    -1,    -1,
      -1,   176,   177,   178,   179,   180,    -1,   182,   183,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,   203,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
     115,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,   166,   167,    -1,    -1,   170,   171,   172,    -1,   174,
      -1,   176,    -1,   178,   179,   180,    -1,   182,   183,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,   203,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
     115,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,   166,   167,    -1,    -1,   170,   171,   172,    -1,   174,
      -1,   176,    -1,   178,   179,   180,    -1,   182,   183,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,   203,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
     115,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,   166,   167,    -1,    -1,   170,   171,   172,    -1,   174,
      -1,   176,    -1,   178,   179,   180,    -1,   182,   183,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,   203,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
     115,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,   166,   167,    -1,    -1,   170,   171,   172,    -1,   174,
      -1,   176,    -1,   178,   179,   180,    -1,   182,   183,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,   203,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
     115,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,   166,   167,    -1,    -1,   170,   171,   172,    -1,   174,
      -1,   176,    -1,   178,   179,   180,    -1,   182,   183,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,   203,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
     115,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,   166,   167,    -1,    -1,   170,   171,   172,    -1,   174,
      -1,   176,    -1,   178,   179,   180,    -1,   182,   183,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,   203,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
     115,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,   166,   167,    -1,    -1,   170,   171,   172,    -1,    -1,
      -1,   176,    -1,   178,   179,   180,    -1,   182,   183,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,   203,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
     115,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,   166,   167,    -1,    -1,   170,   171,   172,    -1,    -1,
      -1,   176,    -1,   178,   179,   180,    -1,   182,   183,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,   203,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
     115,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,   166,   167,    -1,    -1,   170,   171,   172,    -1,    -1,
      -1,   176,    -1,   178,   179,   180,    -1,   182,   183,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,   203,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
     115,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,   166,   167,    -1,    -1,   170,   171,   172,    -1,    -1,
      -1,   176,    -1,   178,   179,   180,    -1,   182,   183,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,   203,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
     115,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,   166,   167,    -1,    -1,   170,   171,   172,    -1,    -1,
      -1,   176,    -1,   178,   179,   180,    -1,   182,   183,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,   203,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
     115,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,   166,   167,    -1,    -1,   170,   171,   172,    -1,    -1,
      -1,   176,    -1,   178,   179,   180,    -1,   182,   183,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,   203,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
     115,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,   148,    -1,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,    -1,   170,   171,   172,    -1,    -1,
      -1,   176,    -1,   178,   179,   180,    -1,   182,   183,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,   203,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
     115,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,   148,    -1,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,    -1,   170,   171,   172,    -1,    -1,
      -1,   176,    -1,   178,   179,   180,    -1,    -1,    -1,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,   203,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    -1,    -1,
      85,    -1,    87,    88,    89,    90,    -1,    -1,    93,    94,
      95,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,   104,
     105,   106,    -1,    -1,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,    -1,   141,   142,   143,    -1,
      -1,    -1,    -1,    -1,    -1,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,
      -1,   176,    -1,   178,   179,    -1,    -1,    -1,    -1,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,    -1,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    -1,    -1,
      85,    -1,    87,    88,    89,    90,    -1,    -1,    93,    94,
      95,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,   104,
     105,   106,    -1,    -1,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,    -1,   141,   142,   143,    -1,
      -1,    -1,    -1,    -1,    -1,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,
      -1,   176,    -1,   178,    -1,    -1,    -1,    -1,    -1,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,    -1,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    14,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    -1,    -1,    85,    -1,    87,    88,
      89,    90,    -1,    -1,    93,    94,    95,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,   104,   105,   106,    -1,    -1,
     109,   110,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,
     139,    -1,   141,   142,   143,   144,    -1,    -1,   147,    -1,
      -1,   150,   151,    -1,    -1,    -1,    -1,   156,   157,   158,
     159,   160,   161,   162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   172,    -1,    -1,    -1,   176,    -1,   178,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
      -1,    -1,   201,   202,    -1,    -1,   205,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,   250,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,    14,    -1,    -1,    -1,    18,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      -1,    -1,    85,    -1,    87,    88,    89,    90,    -1,    -1,
      93,    94,    95,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,   104,   105,   106,    -1,    -1,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,    -1,   122,
      -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   138,   139,    -1,   141,   142,
     143,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,    -1,
      -1,    -1,    -1,   156,   157,   158,   159,   160,   161,   162,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,
      -1,    -1,    -1,   176,   177,   178,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,    -1,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,    -1,    -1,   201,   202,
      -1,    -1,   205,   206,    -1,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,    -1,   250,   251,   252,
      -1,   254,   255,   256,   257,   258,   259,    -1,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,    14,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    -1,    -1,    85,    -1,
      87,    88,    89,    90,    -1,    -1,    93,    94,    95,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,   104,   105,   106,
      -1,    -1,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,
     127,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,    -1,   141,   142,   143,    -1,    -1,    -1,
      -1,    -1,    -1,   150,   151,    -1,    -1,    -1,    -1,   156,
     157,   158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,   176,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
      -1,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,    -1,    -1,   201,   202,    -1,    -1,   205,   206,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    -1,   250,   251,   252,    -1,   254,   255,   256,
     257,   258,   259,    -1,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,    16,    -1,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      -1,    -1,    85,    -1,    87,    88,    89,    90,    -1,    -1,
      93,    94,    95,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,   104,   105,   106,    -1,    -1,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,    -1,   122,
      -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   138,   139,    -1,   141,   142,
     143,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,    -1,
      -1,    -1,    -1,   156,   157,   158,   159,   160,   161,   162,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,
      -1,    -1,    -1,   176,    -1,   178,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,    -1,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,    -1,    -1,   201,   202,
      -1,    -1,   205,   206,    -1,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,    -1,   250,   251,   252,
      -1,   254,   255,   256,   257,   258,   259,    -1,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    -1,    -1,    85,    -1,    87,    88,    89,    90,
      -1,    -1,    93,    94,    95,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,   104,   105,   106,    -1,    -1,   109,   110,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
      -1,   122,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,    -1,
     141,   142,   143,    -1,    -1,    -1,   147,    -1,    -1,   150,
     151,    -1,    -1,    -1,    -1,   156,   157,   158,   159,   160,
     161,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,    -1,    -1,    -1,   176,   177,   178,   179,    -1,
      -1,    -1,    -1,   184,    -1,   186,    -1,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,    -1,    -1,
     201,   202,    -1,    -1,   205,   206,    -1,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,   250,
     251,   252,    -1,   254,   255,   256,   257,   258,   259,    -1,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    -1,    -1,    85,    -1,    87,    88,
      89,    90,    -1,    -1,    93,    94,    95,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,   104,   105,   106,    -1,    -1,
     109,   110,   111,    -1,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,
     139,    -1,   141,   142,   143,    -1,    -1,    -1,   147,    -1,
      -1,   150,   151,    -1,    -1,    -1,    -1,   156,   157,   158,
     159,   160,   161,   162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   172,    -1,    -1,    -1,   176,    -1,   178,
     179,    -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
      -1,    -1,   201,   202,    -1,    -1,   205,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,   250,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    -1,    -1,    85,    -1,
      87,    88,    89,    90,    -1,    -1,    93,    94,    95,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,   104,   105,   106,
      -1,    -1,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,
     127,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,    -1,   141,   142,   143,   144,    -1,    -1,
     147,    -1,    -1,   150,   151,    -1,    -1,    -1,    -1,   156,
     157,   158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,   176,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
      -1,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,    -1,    -1,   201,   202,    -1,    -1,   205,   206,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    -1,   250,   251,   252,    -1,   254,   255,   256,
     257,   258,   259,    -1,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    -1,    -1,
      85,    -1,    87,    88,    89,    90,    -1,    -1,    93,    94,
      95,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,   104,
     105,   106,    -1,    -1,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,    -1,   141,   142,   143,   144,
      -1,    -1,   147,    -1,    -1,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,
      -1,   176,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,    -1,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      -1,    -1,    85,    -1,    87,    88,    89,    90,    -1,    -1,
      93,    94,    95,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,   104,   105,   106,    -1,    -1,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,    -1,   122,
      -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   138,   139,    -1,   141,   142,
     143,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,    -1,
      -1,    -1,    -1,   156,   157,   158,   159,   160,   161,   162,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,
      -1,    -1,    -1,   176,   177,   178,    -1,    -1,    -1,    -1,
      -1,   184,    -1,   186,    -1,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,    -1,    -1,   201,   202,
      -1,    -1,   205,   206,    -1,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,    -1,   250,   251,   252,
      -1,   254,   255,   256,   257,   258,   259,    -1,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    -1,    -1,    85,    -1,    87,    88,    89,    90,
      -1,    -1,    93,    94,    95,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,   104,   105,   106,    -1,    -1,   109,   110,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
      -1,   122,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,    -1,
     141,   142,   143,    -1,    -1,    -1,    -1,    -1,    -1,   150,
     151,    -1,    -1,    -1,    -1,   156,   157,   158,   159,   160,
     161,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,    -1,    -1,    -1,   176,   177,   178,    -1,    -1,
      -1,    -1,    -1,   184,    -1,   186,    -1,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,    -1,    -1,
     201,   202,    -1,    -1,   205,   206,    -1,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,   250,
     251,   252,    -1,   254,   255,   256,   257,   258,   259,    -1,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    -1,    -1,    85,    -1,    87,    88,
      89,    90,    -1,    -1,    93,    94,    95,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,   104,   105,   106,    -1,    -1,
     109,   110,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,
     139,    -1,   141,   142,   143,    -1,    -1,    -1,   147,    -1,
      -1,   150,   151,    -1,    -1,    -1,    -1,   156,   157,   158,
     159,   160,   161,   162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   172,    -1,    -1,    -1,   176,    -1,   178,
     179,    -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
      -1,    -1,   201,   202,    -1,    -1,   205,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,   250,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    -1,    -1,    85,    -1,
      87,    88,    89,    90,    -1,    -1,    93,    94,    95,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,   104,   105,   106,
      -1,    -1,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,
     127,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,    -1,   141,   142,   143,    -1,    -1,    -1,
     147,    -1,    -1,   150,   151,    -1,    -1,    -1,    -1,   156,
     157,   158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,   176,
      -1,   178,   179,    -1,    -1,    -1,    -1,    -1,    -1,   186,
      -1,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,    -1,    -1,   201,   202,    -1,    -1,   205,   206,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    -1,   250,   251,   252,    -1,   254,   255,   256,
     257,   258,   259,    -1,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    -1,    -1,
      85,    -1,    87,    88,    89,    90,    -1,    -1,    93,    94,
      95,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,   104,
     105,   106,    -1,    -1,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,    -1,   141,   142,   143,    -1,
      -1,    -1,    -1,    -1,    -1,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,
      -1,   176,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,    -1,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    10,    17,    18,    20,    25,    26,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    98,    99,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   115,   117,   118,   119,   120,
     122,   126,   127,   128,   129,   130,   137,   138,   139,   140,
     141,   142,   143,   147,   148,   149,   150,   151,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   166,   167,   170,
     171,   172,   176,   178,   179,   180,   182,   183,   184,   186,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   201,   202,   203,   205,   206,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   250,   251,   252,
     254,   255,   256,   257,   258,   259,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   346,   347,   352,   355,   358,   361,   362,   364,   369,
     370,   371,   372,   373,   382,   383,   385,   386,   387,   392,
     394,   396,   397,   398,   403,   424,   427,   430,   431,   432,
     433,   435,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   481,   482,   483,   497,   498,   500,   501,   502,   503,
     504,   505,   506,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   526,   527,   528,   529,   534,   535,   536,
     537,   538,   539,   542,   548,   549,   550,    28,    29,    31,
      32,    34,    40,    48,    50,    51,    58,    60,    68,    72,
     104,   105,   106,   151,   160,   192,   211,   221,   252,   278,
     279,   280,   281,   282,   284,   285,   286,   287,   288,   293,
     353,   354,   374,   375,   151,   144,   147,   144,   147,    25,
      26,    30,    35,    36,    37,    38,    39,    40,    41,    42,
      44,    52,    54,    57,    59,    62,    65,    67,    69,    90,
     126,   144,   147,   160,   192,   205,   215,   216,   217,   219,
     220,   227,   229,   230,   231,   232,   235,   236,   238,   548,
     144,    61,    66,   111,   389,   147,   363,   147,    26,    55,
     111,    39,    14,   144,   147,   547,   548,   147,   111,   111,
     144,   147,   147,    87,   144,   212,   213,   144,   147,   548,
      30,    37,    54,    65,    90,   465,   548,   548,   111,   177,
     383,   548,   144,   547,    16,   548,   548,   457,   144,    21,
     204,   206,   216,   218,   147,   216,   218,   216,   216,   221,
     111,   144,   365,   233,   233,   234,   147,   144,   111,   317,
       0,   319,   320,    25,    42,   322,   382,   181,   181,   100,
     181,   384,    33,    39,    44,    52,    64,   159,   162,   176,
     202,   388,   393,   394,   395,   412,   413,   417,   399,   400,
     548,   158,    85,   123,   131,   132,   134,   142,   146,   148,
     153,   169,   193,   194,   195,   196,   197,   198,   449,   450,
     250,   149,   166,   189,   110,   137,   150,   184,   191,   200,
     127,   141,    43,   190,    94,    95,   149,   166,   448,   144,
     454,   457,   182,   183,   145,   469,   470,   465,   469,   465,
     147,   469,   136,   147,    20,   546,   172,   186,   172,   186,
     157,   172,   374,   548,   374,   548,   160,   192,    40,   376,
     375,    40,   377,   548,   143,   111,   351,    37,    40,    72,
      99,   159,   547,   212,   213,   214,   291,   292,   238,   577,
     548,   284,   548,   289,   289,   294,   278,   286,   354,   547,
     383,   177,   383,    37,    57,   177,   522,   523,   383,   177,
     184,   548,   144,   386,   275,   275,   111,   407,   111,   177,
     378,   379,   144,   380,   383,   151,   546,   106,   151,   345,
     546,   404,   406,   548,   111,   383,    20,   177,   547,   144,
     548,   548,   425,   426,   548,   383,   177,   383,   524,   548,
     383,   144,   144,   383,   177,   184,   548,   144,   425,   177,
      27,   485,   486,   487,   383,     7,   165,    15,   177,   383,
     204,    20,   386,   386,   177,   386,   386,   386,   386,   222,
     540,   541,   548,   366,   386,   386,   383,   405,   411,   548,
     324,   325,    25,   326,   386,   385,   111,   159,   161,   161,
     386,   386,   100,    87,    89,   138,   264,   401,   402,   508,
     432,   433,   435,   435,   435,   435,   434,   435,   435,   435,
     144,   147,   251,   453,   472,   551,   554,   555,   556,   557,
     558,   562,   564,   566,   567,   439,   439,   438,   440,   440,
     440,   440,   441,   441,   442,   442,   222,    87,    87,    87,
     174,   383,   457,   457,   383,   470,   177,   386,   480,   140,
     177,   480,   100,   100,   363,    20,   548,   548,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,   328,   329,
     330,    87,   128,   133,   348,   349,   350,   548,   128,   133,
     151,   151,   328,   546,   118,   123,    47,    50,    93,   228,
     242,   255,   257,   268,   270,   272,   276,   578,   579,   580,
     581,   582,   583,   590,   596,   597,   238,    87,   228,   357,
     290,   548,   548,   548,   123,   174,   174,   177,   177,   174,
     100,   177,   100,   177,   174,   383,   174,   548,    49,   208,
     245,   390,   391,   548,    87,   100,   177,   383,   177,   547,
      89,    37,   547,   546,    89,   100,   133,   402,   508,   174,
     177,   177,   174,   383,   177,   133,   100,   178,   138,   508,
     174,   177,   144,   174,   383,   383,   174,   100,   177,   100,
     177,   174,   383,   178,   548,   486,   487,   121,   187,   174,
     174,   122,   181,    87,   209,   210,   224,    87,   209,   210,
     224,    87,   228,   216,   100,   226,   133,    25,   367,   383,
     177,   174,    38,   100,   181,   106,   181,   548,   161,   386,
     418,   419,   111,   414,   415,   111,    40,   143,   147,   201,
     509,   511,   513,   514,   530,   531,   532,   533,   548,   111,
     386,   111,   138,   402,   138,   138,   401,   402,   435,   383,
     551,   558,   144,   276,   436,   603,    89,   160,   243,   244,
     246,   253,   263,   275,   552,   553,   572,   573,   574,   575,
     598,   601,   249,   251,   559,   577,   258,   563,   599,   239,
     240,   261,   568,   569,   509,   509,   507,   513,   507,   174,
     175,   100,   177,   177,   139,   156,   139,   156,   128,   144,
     381,   363,   363,   329,   123,   511,   350,   386,   508,   133,
     386,   546,   546,   119,   120,   546,   268,   270,   548,   254,
     265,   106,   269,   274,   254,   265,    20,    89,   106,   147,
     584,   587,   269,   274,   578,    30,    36,    54,    65,    90,
     216,   356,   514,   282,   283,   218,   290,   298,    87,   357,
     290,   546,   144,   524,   525,   548,   524,   525,   174,   138,
     508,   245,    46,    53,    70,   111,   401,   408,   409,   410,
     391,   508,   509,   379,    87,   174,   188,   123,   344,   546,
     151,   123,    89,   344,   111,   386,   133,   133,   402,   144,
     174,   386,   111,   386,   386,   138,    93,   428,   429,   383,
     174,   174,   144,   524,   524,   174,   386,    27,   487,   121,
     187,     8,     9,    96,   114,   116,   185,   380,   482,   484,
     495,   496,   499,    20,   223,   225,   386,   386,   386,   223,
     225,   386,   386,   386,   386,   386,   386,   111,   386,   386,
     351,   368,   100,   181,   174,   365,   237,   543,   544,   144,
     111,   418,    88,    99,   109,   118,   420,   421,   422,   423,
     100,   548,   100,   400,   147,   147,   511,   147,   135,   166,
     184,   510,   548,   548,   386,   138,   386,   386,   138,   402,
     138,   174,   177,   551,   565,   241,   208,   245,   259,   266,
     602,    89,   247,   248,   600,   241,   555,   602,   438,   572,
     556,   138,   273,   560,   561,   600,   277,   571,    71,   570,
     135,   386,   383,   128,   365,   128,   144,   526,   349,   386,
      20,   269,   277,    20,   584,   277,   357,   510,   218,   218,
     455,   278,   296,   356,   218,   181,   174,   383,   177,   177,
     135,   177,   177,   386,   138,   111,   111,   386,   548,   410,
      70,   509,   386,   546,   100,   344,   406,   386,   386,   133,
     174,   383,   426,   386,   111,   509,   106,   429,   174,   174,
     383,   177,   177,   123,   185,   484,     6,   548,   185,   495,
     181,   224,   224,   224,   224,   228,   541,   176,   133,   368,
     466,   545,   544,   386,   411,   546,   119,   120,   422,   423,
     423,   419,    99,   416,   415,   177,   184,   509,   512,   177,
     177,   177,   386,   386,   138,   386,   174,   440,    45,   120,
     438,   438,   260,   267,   277,   576,   576,   557,   144,   271,
     174,   385,   277,    89,   147,   591,   262,   588,   585,   586,
     587,   161,   548,   248,   357,   455,   174,   386,   548,   548,
     409,   386,   117,    89,   546,   386,   174,   548,   176,   111,
     176,   174,   487,   548,   185,   487,   548,   386,   386,   386,
     386,   386,   386,   386,   147,   200,   381,   174,   423,   546,
      87,   177,   100,   177,   386,   438,   438,   189,   383,   174,
     127,   191,   593,   594,   595,    20,    20,   592,   593,    20,
     589,   600,   177,   100,   359,   360,   455,   111,   216,   297,
     278,   161,    46,   386,   344,    87,   386,   548,   386,    86,
     173,   488,   487,   548,   187,   487,   111,   466,   509,   509,
      87,   438,   174,   591,   591,   595,   100,   177,   256,   587,
     100,    87,   548,   111,   216,   548,   359,   111,   509,   176,
       4,   124,   491,   492,   494,   496,    19,   125,   489,   490,
     493,   496,   187,   487,   187,   548,   509,    20,   360,   513,
     295,   548,   111,   216,   548,   176,   386,    86,   124,   494,
     173,   125,   493,   187,   100,   177,   423,   386,   295,   548,
     111,   386,   111,   381,   284,   295,   548,   548,   296,   386,
     296,   100,   177,   455,   455,   111,   381,   189,   548,   278,
     177,   548,   381,   216,   111,   548,   296,   455
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
     565,   566,   567,   568,   569
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   315,   316,   316,   317,   317,   317,   317,   318,   318,
     319,   319,   320,   320,   321,   322,   322,   322,   323,   323,
     324,   324,   325,   325,   325,   325,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   327,   327,   328,   328,   329,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     331,   331,   331,   331,   331,   331,   331,   331,   332,   332,
     333,   334,   334,   335,   335,   336,   337,   338,   338,   339,
     339,   340,   340,   340,   340,   341,   342,   343,   343,   343,
     343,   344,   344,   345,   345,   346,   346,   346,   346,   347,
     348,   348,   349,   349,   349,   350,   351,   351,   352,   352,
     352,   353,   353,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   355,   355,   355,   355,   355,
     355,   355,   355,   356,   356,   357,   357,   358,   358,   359,
     359,   360,   360,   361,   361,   361,   361,   362,   362,   363,
     363,   363,   363,   364,   365,   366,   366,   367,   367,   368,
     368,   369,   370,   371,   372,   372,   373,   373,   373,   374,
     374,   374,   374,   375,   375,   376,   376,   377,   377,   378,
     378,   379,   379,   380,   381,   382,   383,   383,   384,   384,
     385,   385,   386,   386,   386,   386,   386,   386,   386,   386,
     386,   386,   386,   386,   386,   386,   386,   386,   386,   387,
     388,   389,   389,   390,   390,   390,   391,   391,   392,   392,
     393,   394,   394,   394,   395,   395,   395,   395,   395,   396,
     396,   397,   397,   398,   399,   399,   400,   400,   400,   400,
     400,   400,   400,   400,   401,   402,   403,   404,   404,   405,
     405,   406,   406,   406,   406,   407,   407,   408,   408,   408,
     409,   409,   409,   410,   410,   410,   411,   412,   413,   414,
     414,   415,   415,   416,   417,   417,   418,   418,   419,   419,
     420,   420,   420,   420,   420,   420,   420,   421,   421,   422,
     422,   423,   424,   424,   425,   425,   426,   426,   427,   427,
     428,   428,   429,   429,   430,   431,   431,   432,   432,   433,
     433,   433,   433,   433,   434,   433,   433,   433,   433,   435,
     435,   436,   436,   437,   437,   438,   438,   438,   439,   439,
     439,   439,   439,   440,   440,   440,   441,   441,   441,   442,
     442,   443,   443,   444,   444,   445,   445,   446,   446,   447,
     447,   447,   447,   448,   448,   448,   449,   449,   449,   449,
     449,   449,   450,   450,   450,   451,   451,   451,   451,   452,
     452,   453,   453,   454,   454,   455,   455,   455,   455,   456,
     457,   457,   457,   458,   458,   459,   459,   459,   459,   460,
     460,   461,   461,   461,   461,   461,   461,   461,   462,   462,
     463,   463,   464,   464,   464,   464,   464,   465,   465,   466,
     466,   467,   467,   467,   468,   468,   468,   468,   469,   469,
     470,   471,   471,   471,   471,   471,   471,   471,   471,   471,
     472,   472,   473,   473,   473,   474,   475,   475,   476,   477,
     478,   479,   479,   480,   480,   481,   481,   482,   482,   482,
     483,   483,   483,   483,   483,   483,   484,   484,   485,   485,
     486,   487,   487,   488,   488,   489,   489,   490,   490,   490,
     490,   491,   491,   492,   492,   492,   492,   493,   493,   494,
     494,   495,   495,   495,   495,   496,   496,   496,   496,   497,
     497,   498,   498,   499,   500,   500,   500,   500,   500,   500,
     501,   502,   502,   502,   502,   503,   503,   503,   503,   504,
     505,   506,   506,   506,   506,   507,   507,   508,   509,   509,
     509,   510,   510,   510,   511,   511,   511,   511,   511,   512,
     512,   513,   514,   514,   514,   514,   514,   514,   514,   514,
     514,   515,   516,   516,   516,   517,   518,   519,   519,   519,
     520,   520,   520,   520,   520,   521,   522,   522,   522,   522,
     522,   522,   522,   523,   524,   525,   526,   527,   527,   528,
     529,   530,   530,   531,   532,   532,   533,   534,   534,   534,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     536,   536,   537,   537,   538,   539,   540,   540,   541,   542,
     543,   543,   544,   544,   544,   544,   545,   545,   546,   547,
     547,   548,   548,   549,   549,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   551,   552,   552,   553,   553,
     554,   554,   555,   555,   556,   556,   557,   557,   558,   559,
     559,   560,   560,   561,   562,   562,   562,   563,   563,   564,
     565,   565,   566,   567,   567,   568,   568,   569,   569,   569,
     570,   570,   571,   571,   572,   572,   572,   572,   572,   573,
     574,   575,   576,   576,   576,   577,   577,   578,   578,   578,
     578,   578,   578,   578,   578,   579,   579,   579,   579,   580,
     580,   581,   582,   582,   583,   583,   583,   584,   584,   585,
     585,   586,   586,   587,   588,   588,   589,   589,   590,   590,
     590,   591,   591,   592,   592,   593,   593,   594,   594,   595,
     595,   596,   597,   597,   598,   598,   598,   599,   600,   600,
     600,   600,   601,   601,   602,   602,   603
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
       2,     2,     2,     4,     4,     4,     4,     6,     4,     1,
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
       1,     1,     1,     1,     1,     2,     3,     4,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     3,     1,     4,
       4,     3,     4,     1,     3,     1,     1,     1,     1,     1,
       4,     5,     8,     9,     9,    10,     1,     2,     1,     2,
       6,     0,     1,     3,     3,     0,     1,     1,     1,     2,
       2,     0,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       4,     4,     5,     6,     7,     4,     5,     6,     7,     4,
       4,     4,     5,     6,     7,     1,     2,     2,     1,     2,
       3,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     4,     4,     3,     3,     3,     4,     4,
       3,     4,     6,     4,     6,     3,     3,     4,     6,     6,
       4,     6,     6,     4,     1,     2,     1,     1,     1,     3,
       3,     1,     1,     4,     5,     6,     3,     3,     3,     3,
       5,     7,     7,     5,     5,     5,     7,     7,     5,     5,
       3,     3,     5,     7,     5,     7,     1,     4,     3,     5,
       1,     2,     3,     7,    10,    13,     1,     3,     1,     1,
       1,     1,     1,     7,     4,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     2,     0,     1,     1,     2,
       1,     3,     1,     3,     1,     4,     1,     2,     3,     0,
       1,     0,     1,     4,     2,     3,     1,     0,     1,     4,
       0,     1,     2,     1,     3,     0,     1,     2,     2,     1,
       0,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     1,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     2,
       2,     3,     1,     2,     2,     5,     2,     1,     1,     0,
       1,     1,     3,     4,     0,     2,     0,     2,     5,     5,
       3,     2,     3,     1,     3,     0,     1,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     3,     2,     3,
       3,     4,     2,     2,     1,     1,     3
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
  "\"'base-uri'\"", "\"'boundary-space'\"", "\"'comment'\"",
  "\"'construction'\"", "\"'copy-namespaces'\"", "\"'count'\"",
  "\"'deterministic'\"", "\"'document'\"", "\"'document-node'\"",
  "\"'element'\"", "\"'eval'\"", "\"'for'\"", "\"'function'\"", "\"'if'\"",
  "\"'import'\"", "\"'instance'\"", "\"'let'\"", "\"'most'\"",
  "\"'next'\"", "\"'no'\"", "\"'nondeterministic'\"", "\"'only'\"",
  "\"'option'\"", "\"'ordering'\"", "\"'outer'\"", "\"'previous'\"",
  "\"'processing-instruction'\"", "\"'schema'\"", "\"'schema-attribute'\"",
  "\"'schema-element'\"", "\"'sequential'\"", "\"'set'\"", "\"'simple'\"",
  "\"'sliding'\"", "\"'some'\"", "\"'space'\"", "\"'stable'\"",
  "\"'text'\"", "\"'tumbling'\"", "\"'typeswitch'\"", "\"'updating'\"",
  "\"'validate'\"", "\"'when'\"", "\"'word'\"", "\"'decimal-format'\"",
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
  "\"'>'\"", "\"'?'\"", "\"'#'\"", "\"'idiv'\"", "\"'in'\"",
  "\"'inherit'\"", "\"'INTEGER'\"", "\"'intersect'\"", "\"'is'\"",
  "\"'item'\"", "\"'{'\"", "\"'['\"", "\"'<='\"", "\"'('\"", "\"'<'\"",
  "\"'-'\"", "\"'mod'\"", "\"'namespace'\"", "\"'nan'\"", "\"'!='\"",
  "\"'nodecomp'\"", "\"'?""?'\"", "\"'<no inherit>'\"",
  "\"'<no preserve>'\"", "\"'or'\"", "\"'order'\"", "\"'ordered'\"",
  "\"'by'\"", "\"'group'\"", "\"'parent::'\"", "\"'<?'\"", "\"'?>'\"",
  "\"'+'\"", "\"'PRAGMA BEGIN'\"", "\"'PRAGMA END'\"", "\"'<<'\"",
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
  "FunctionDecl3", "FunctionDecl4", "FunctionDeclUpdating", "ParamList",
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
  "TypeList", "AtomicType", "KindTest", "AnyKindTest", "DocumentTest",
  "TextTest", "CommentTest", "PITest", "AttributeTest",
  "SchemaAttributeTest", "ElementTest", "SchemaElementTest", "TypeName",
  "TypeName_WITH_HOOK", "StringLiteral", "FunctionItemExpr",
  "LiteralFunctionItem", "InlineFunction", "FunctionTest",
  "AnyFunctionTest", "TypedFunctionTest", "ParenthesizedItemType",
  "RevalidationDecl", "InsertExpr", "DeleteExpr", "ReplaceExpr",
  "RenameExpr", "TransformExpr", "VarNameList", "VarNameDecl", "TryExpr",
  "CatchListExpr", "CatchExpr", "NameTestList", "URI_LITERAL", "NCNAME",
  "QNAME", "EvalExpr", "KEYWORD", "FTSelection", "opt_FTPosFilter_list",
  "FTPosFilter_list", "FTOr", "FTAnd", "FTMildNot", "FTUnaryNot",
  "FTPrimaryWithOptions", "opt_FTMatchOptions", "opt_FTWeight", "FTWeight",
  "FTPrimary", "opt_FTTimes", "FTExtensionSelection", "opt_FTSelection",
  "FTWords", "FTWordsValue", "opt_FTAnyallOption", "FTAnyallOption",
  "opt_word", "opt_words", "FTPosFilter", "FTOrder", "FTWindow",
  "FTDistance", "FTUnit", "FTMatchOptions", "FTMatchOption",
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
       316,     0,    -1,   317,    -1,   300,   317,    -1,   319,    -1,
     318,   319,    -1,   320,    -1,   318,   320,    -1,   205,   206,
      20,   181,    -1,   205,   206,    20,   122,    20,   181,    -1,
     322,   382,    -1,   382,    -1,   321,    -1,   321,   322,    -1,
      26,   151,   547,   123,   546,   181,    -1,   323,   181,    -1,
     324,   181,    -1,   323,   181,   324,   181,    -1,   325,    -1,
     323,   181,   325,    -1,   326,    -1,   324,   181,   326,    -1,
     331,    -1,   332,    -1,   333,    -1,   335,    -1,   352,    -1,
     355,    -1,   347,    -1,   327,    -1,   337,    -1,   373,    -1,
     358,    -1,   361,    -1,   336,    -1,    25,   106,    72,   328,
      -1,    25,    72,   548,   328,    -1,   329,    -1,   328,   329,
      -1,   330,   123,   526,    -1,    73,    -1,    81,    -1,    74,
      -1,    75,    -1,    76,    -1,    77,    -1,    82,    -1,    78,
      -1,    79,    -1,    80,    -1,   334,    -1,   341,    -1,   342,
      -1,   362,    -1,   338,    -1,   339,    -1,   340,    -1,   534,
      -1,   343,    -1,   346,    -1,    25,   151,   547,   123,   546,
      -1,    25,    29,   172,    -1,    25,    29,   186,    -1,    25,
     106,    37,   151,   546,    -1,    25,   106,    40,   151,   546,
      -1,    25,    50,   548,    20,    -1,    25,   252,   577,    -1,
      25,    51,   160,    -1,    25,    51,   192,    -1,    25,   106,
     159,   118,   119,    -1,    25,   106,   159,   118,   120,    -1,
      25,    32,   172,   100,   139,    -1,    25,    32,   172,   100,
     156,    -1,    25,    32,   157,   100,   139,    -1,    25,    32,
     157,   100,   156,    -1,    25,   106,    99,   546,    -1,    25,
      28,   546,    -1,    42,    55,   546,    -1,    42,    55,   345,
     546,    -1,    42,    55,   546,    89,   344,    -1,    42,    55,
     345,   546,    89,   344,    -1,   546,    -1,   344,   100,   546,
      -1,   151,   547,   123,    -1,   106,    37,   151,    -1,    42,
      26,   546,    -1,    42,    26,   151,   547,   123,   546,    -1,
      42,    26,   546,    89,   344,    -1,    42,    26,   151,   547,
     123,   546,    89,   344,    -1,    25,   104,   143,   348,    -1,
      87,   511,   349,    -1,   349,    -1,   350,    -1,   128,    -1,
     128,   350,    -1,   133,   386,    -1,   111,   548,    -1,   111,
     548,   508,    -1,    25,   105,   351,   133,   386,    -1,    25,
     105,   351,   128,    -1,    25,   105,   351,   128,   133,   386,
      -1,   354,    -1,   353,   354,    -1,   279,    -1,   280,    -1,
     281,    -1,   282,    -1,   160,    -1,   192,    -1,   221,   292,
      -1,   221,   291,    -1,   284,    -1,   285,   284,    -1,   288,
     289,    -1,   287,   289,    -1,    25,   278,   548,    -1,    25,
     278,   548,   357,    -1,    25,   278,   548,    87,   356,    -1,
      25,   278,   548,    87,   356,   357,    -1,    25,   353,   278,
     548,    -1,    25,   353,   278,   548,   357,    -1,    25,   353,
     278,   548,    87,   356,    -1,    25,   353,   278,   548,    87,
     356,   357,    -1,   514,    -1,   514,   510,    -1,   228,   283,
     218,    -1,   228,   282,   218,    -1,    25,   286,   548,   290,
     218,   455,   161,   359,    -1,    25,   353,   286,   548,   290,
     218,   455,   161,   359,    -1,   360,    -1,   359,   100,   360,
      -1,   455,    87,   513,    -1,   455,    87,   513,   423,    -1,
      25,   293,   294,   548,   290,   278,   548,   111,   548,   295,
     386,    -1,    25,   293,   294,   548,   290,   278,   548,   216,
     111,   548,   295,   284,   296,   455,    -1,    25,   293,   294,
     548,   290,   278,   548,   297,   216,   111,   548,   295,   386,
      -1,    25,   293,   294,   548,   298,   296,   248,   278,   548,
     216,   111,   548,   296,   455,   189,   278,   548,   216,   111,
     548,   296,   455,    -1,    25,    31,   172,    -1,    25,    31,
     186,    -1,   147,   177,    -1,   147,   378,   177,    -1,   147,
     177,    87,   509,    -1,   147,   378,   177,    87,   509,    -1,
     229,   365,    -1,   144,   366,   383,   174,    -1,   366,   367,
     181,    -1,    -1,   367,   100,   368,    -1,    25,   368,    -1,
     351,    -1,   351,   133,   386,    -1,    59,   111,   548,   133,
     386,    -1,   232,   234,   386,    -1,   235,   147,   386,   177,
     365,    -1,   230,   233,    -1,   231,   233,    -1,    25,   374,
      -1,    25,    48,   374,    -1,    25,    34,   374,    -1,   375,
      -1,    60,   375,    -1,    68,   377,    -1,    58,   376,    -1,
      40,   548,   363,   381,    -1,    40,   548,   363,   128,    -1,
      40,   548,   363,   365,    -1,    40,   548,   363,   128,    -1,
      40,   548,   363,   144,   385,   174,    -1,    40,   548,   363,
     128,    -1,   379,    -1,   378,   100,   379,    -1,   111,   548,
      -1,   111,   548,   508,    -1,   144,   383,   174,    -1,   144,
     383,   174,    -1,   383,    -1,   385,    -1,   385,   384,    -1,
     181,    -1,   384,   385,   181,    -1,   386,    -1,   385,   100,
     386,    -1,   387,    -1,   424,    -1,   427,    -1,   430,    -1,
     431,    -1,   535,    -1,   536,    -1,   538,    -1,   537,    -1,
     539,    -1,   542,    -1,   549,    -1,   370,    -1,   371,    -1,
     372,    -1,   369,    -1,   364,    -1,   396,   388,    -1,   176,
     386,    -1,    61,   275,    -1,    66,   275,    -1,   208,    -1,
     245,    -1,    49,   245,    -1,   390,   408,    70,   386,    -1,
     390,    70,   386,    -1,    39,   389,   407,   391,   391,    -1,
      39,   389,   407,   391,    -1,    33,   111,   548,    -1,   398,
      -1,   403,    -1,   392,    -1,   394,    -1,   412,    -1,   417,
      -1,   413,    -1,   393,    -1,   394,    -1,   396,   395,    -1,
      39,   111,    -1,    52,    39,   111,    -1,   397,   399,    -1,
     400,    -1,   399,   100,   111,   400,    -1,   548,   138,   386,
      -1,   548,   508,   138,   386,    -1,   548,   401,   138,   386,
      -1,   548,   508,   401,   138,   386,    -1,   548,   402,   138,
     386,    -1,   548,   508,   402,   138,   386,    -1,   548,   401,
     402,   138,   386,    -1,   548,   508,   401,   402,   138,   386,
      -1,    89,   111,   548,    -1,   264,   111,   548,    -1,    44,
     111,   404,    -1,   406,    -1,   404,   100,   111,   406,    -1,
     411,    -1,   405,   100,   111,   411,    -1,   548,   133,   386,
      -1,   548,   508,   133,   386,    -1,   548,   402,   133,   386,
      -1,   548,   508,   402,   133,   386,    -1,   111,   548,   138,
     386,    -1,   111,   548,   508,   138,   386,    -1,   409,    -1,
     111,   548,    -1,   111,   548,   409,    -1,   401,    -1,   401,
     410,    -1,   410,    -1,    53,   111,   548,    46,   111,   548,
      -1,    46,   111,   548,    -1,    53,   111,   548,    -1,   548,
      -1,   202,   386,    -1,   162,   161,   414,    -1,   415,    -1,
     414,   100,   415,    -1,   111,   548,    -1,   111,   548,   416,
      -1,    99,   546,    -1,   159,   161,   418,    -1,    64,   159,
     161,   418,    -1,   419,    -1,   418,   100,   419,    -1,   386,
      -1,   386,   420,    -1,   421,    -1,   422,    -1,   423,    -1,
     421,   422,    -1,   421,   423,    -1,   422,   423,    -1,   421,
     422,   423,    -1,    88,    -1,   109,    -1,   118,   119,    -1,
     118,   120,    -1,    99,   546,    -1,    62,   111,   425,   178,
     386,    -1,   126,   111,   425,   178,   386,    -1,   426,    -1,
     425,   100,   111,   426,    -1,   548,   138,   386,    -1,   548,
     508,   138,   386,    -1,    67,   147,   383,   177,   428,   106,
     176,   386,    -1,    67,   147,   383,   177,   428,   106,   111,
     548,   176,   386,    -1,   429,    -1,   428,   429,    -1,    93,
     509,   176,   386,    -1,    93,   111,   548,    87,   509,   176,
     386,    -1,    41,   147,   383,   177,   188,   386,   117,   386,
      -1,   432,    -1,   431,   158,   432,    -1,   433,    -1,   432,
      85,   433,    -1,   435,    -1,   435,   449,   435,    -1,   435,
     450,   435,    -1,   435,   123,   435,    -1,   435,   153,   435,
      -1,    -1,   435,   148,   434,   435,    -1,   435,   146,   435,
      -1,   435,   134,   435,    -1,   435,   132,   435,    -1,   437,
      -1,   437,   250,   551,   436,    -1,    -1,   603,    -1,   438,
      -1,   438,   189,   438,    -1,   439,    -1,   438,   166,   439,
      -1,   438,   149,   439,    -1,   440,    -1,   439,   184,   440,
      -1,   439,   110,   440,    -1,   439,   137,   440,    -1,   439,
     150,   440,    -1,   441,    -1,   440,   191,   441,    -1,   440,
     200,   441,    -1,   442,    -1,   441,   141,   442,    -1,   441,
     127,   442,    -1,   443,    -1,   443,    43,   222,   509,    -1,
     444,    -1,   444,   190,    87,   509,    -1,   445,    -1,   445,
      94,    87,   507,    -1,   446,    -1,   446,    95,    87,   507,
      -1,   448,    -1,   447,   448,    -1,   166,    -1,   149,    -1,
     447,   166,    -1,   447,   149,    -1,   451,    -1,   455,    -1,
     452,    -1,   193,    -1,   198,    -1,   197,    -1,   196,    -1,
     195,    -1,   194,    -1,   142,    -1,   169,    -1,   131,    -1,
      69,   144,   383,   174,    -1,    69,   213,   144,   383,   174,
      -1,    69,   212,   144,   383,   174,    -1,    69,    87,   524,
     144,   383,   174,    -1,   453,   144,   174,    -1,   453,   144,
     383,   174,    -1,   454,    -1,   453,   454,    -1,   167,   548,
      15,    -1,   167,    16,    -1,   456,    -1,   456,   457,    -1,
     183,   457,    -1,   457,    -1,   182,    -1,   458,    -1,   458,
     182,   457,    -1,   458,   183,   457,    -1,   459,    -1,   468,
      -1,   460,    -1,   460,   469,    -1,   463,    -1,   463,   469,
      -1,   461,   465,    -1,   462,    -1,    98,    -1,   107,    -1,
      91,    -1,   180,    -1,   108,    -1,   130,    -1,   129,    -1,
     465,    -1,    92,   465,    -1,   464,   465,    -1,   113,    -1,
     163,    -1,    83,    -1,   171,    -1,   170,    -1,    84,    -1,
     514,    -1,   466,    -1,   548,    -1,   467,    -1,   184,    -1,
      10,    -1,    17,    -1,   471,    -1,   468,   469,    -1,   468,
     147,   177,    -1,   468,   147,   480,   177,    -1,   470,    -1,
     469,   470,    -1,   145,   383,   175,    -1,   472,    -1,   474,
      -1,   475,    -1,   476,    -1,   479,    -1,   481,    -1,   477,
      -1,   478,    -1,   527,    -1,   473,    -1,   526,    -1,   103,
      -1,   140,    -1,   115,    -1,   111,   548,    -1,   147,   177,
      -1,   147,   383,   177,    -1,   112,    -1,   160,   144,   383,
     174,    -1,   192,   144,   383,   174,    -1,   548,   147,   177,
      -1,   548,   147,   480,   177,    -1,   386,    -1,   480,   100,
     386,    -1,   482,    -1,   500,    -1,   483,    -1,   497,    -1,
     498,    -1,   148,   548,   487,   121,    -1,   148,   548,   485,
     487,   121,    -1,   148,   548,   487,   187,   185,   548,   487,
     187,    -1,   148,   548,   487,   187,   484,   185,   548,   487,
     187,    -1,   148,   548,   485,   487,   187,   185,   548,   487,
     187,    -1,   148,   548,   485,   487,   187,   484,   185,   548,
     487,   187,    -1,   495,    -1,   484,   495,    -1,   486,    -1,
     485,   486,    -1,    27,   548,   487,   123,   487,   488,    -1,
      -1,    27,    -1,   173,   489,   173,    -1,    86,   491,    86,
      -1,    -1,   490,    -1,   125,    -1,   493,    -1,   490,   125,
      -1,   490,   493,    -1,    -1,   492,    -1,   124,    -1,   494,
      -1,   492,   124,    -1,   492,   494,    -1,    19,    -1,   496,
      -1,     4,    -1,   496,    -1,   482,    -1,     9,    -1,   499,
      -1,   496,    -1,     8,    -1,   114,    -1,   116,    -1,   380,
      -1,   203,    21,   204,    -1,   203,   204,    -1,   164,   547,
     165,    -1,   164,   547,     7,    -1,    96,     6,    -1,   501,
      -1,   502,    -1,   503,    -1,   504,    -1,   505,    -1,   506,
      -1,    35,   144,   383,   174,    -1,    37,   548,   144,   174,
      -1,    37,   548,   144,   383,   174,    -1,    37,   144,   383,
     174,   144,   174,    -1,    37,   144,   383,   174,   144,   383,
     174,    -1,    90,   548,   144,   174,    -1,    90,   548,   144,
     383,   174,    -1,    90,   144,   383,   174,   144,   174,    -1,
      90,   144,   383,   174,   144,   383,   174,    -1,    65,   144,
     383,   174,    -1,    30,   144,   383,   174,    -1,    54,   547,
     144,   174,    -1,    54,   547,   144,   383,   174,    -1,    54,
     144,   383,   174,   144,   174,    -1,    54,   144,   383,   174,
     144,   383,   174,    -1,   513,    -1,   513,   135,    -1,    87,
     509,    -1,   511,    -1,   511,   510,    -1,   201,   147,   177,
      -1,   135,    -1,   184,    -1,   166,    -1,   513,    -1,   514,
      -1,   143,   147,   177,    -1,   530,    -1,   533,    -1,   509,
      -1,   512,   100,   509,    -1,   548,    -1,   516,    -1,   522,
      -1,   520,    -1,   523,    -1,   521,    -1,   519,    -1,   518,
      -1,   517,    -1,   515,    -1,   216,   147,   177,    -1,    36,
     147,   177,    -1,    36,   147,   522,   177,    -1,    36,   147,
     523,   177,    -1,    65,   147,   177,    -1,    30,   147,   177,
      -1,    54,   147,   177,    -1,    54,   147,   547,   177,    -1,
      54,   147,    20,   177,    -1,    90,   147,   177,    -1,    90,
     147,   548,   177,    -1,    90,   147,   548,   100,   524,   177,
      -1,    90,   147,   184,   177,    -1,    90,   147,   184,   100,
     524,   177,    -1,   179,   548,   177,    -1,    37,   147,   177,
      -1,    37,   147,   548,   177,    -1,    37,   147,   548,   100,
     524,   177,    -1,    37,   147,   548,   100,   525,   177,    -1,
      37,   147,   184,   177,    -1,    37,   147,   184,   100,   524,
     177,    -1,    37,   147,   184,   100,   525,   177,    -1,    57,
     147,   548,   177,    -1,   548,    -1,   548,   135,    -1,    20,
      -1,   528,    -1,   529,    -1,   548,   136,   140,    -1,    40,
     363,   380,    -1,   531,    -1,   532,    -1,    40,   147,   184,
     177,    -1,    40,   147,   177,    87,   509,    -1,    40,   147,
     512,   177,    87,   509,    -1,   147,   511,   177,    -1,    25,
     211,   212,    -1,    25,   211,   213,    -1,    25,   211,   214,
      -1,   217,   216,   386,   224,   386,    -1,   217,   216,   386,
      87,   223,   224,   386,    -1,   217,   216,   386,    87,   225,
     224,   386,    -1,   217,   216,   386,   209,   386,    -1,   217,
     216,   386,   210,   386,    -1,   217,   218,   386,   224,   386,
      -1,   217,   218,   386,    87,   223,   224,   386,    -1,   217,
     218,   386,    87,   225,   224,   386,    -1,   217,   218,   386,
     209,   386,    -1,   217,   218,   386,   210,   386,    -1,   215,
     216,   386,    -1,   215,   218,   386,    -1,   220,   216,   386,
     228,   386,    -1,   220,   221,   222,   216,   386,   228,   386,
      -1,   219,   216,   386,    87,   386,    -1,   227,   111,   540,
     226,   386,   176,   386,    -1,   541,    -1,   540,   100,   111,
     541,    -1,   548,   133,   386,    -1,   236,   144,   383,   174,
     543,    -1,   544,    -1,   543,   544,    -1,   237,   545,   381,
      -1,   237,   545,   147,   111,   548,   177,   381,    -1,   237,
     545,   147,   111,   548,   100,   111,   548,   177,   381,    -1,
     237,   545,   147,   111,   548,   100,   111,   548,   100,   111,
     548,   177,   381,    -1,   466,    -1,   545,   200,   466,    -1,
      20,    -1,    14,    -1,   548,    -1,    18,    -1,   550,    -1,
     238,   111,   405,    38,   144,   386,   174,    -1,    38,   144,
     386,   174,    -1,   205,    -1,   118,    -1,    90,    -1,    30,
      -1,    36,    -1,    37,    -1,   143,    -1,    41,    -1,   216,
      -1,    54,    -1,    56,    -1,    57,    -1,    65,    -1,    67,
      -1,   201,    -1,    29,    -1,   252,    -1,    28,    -1,   213,
      -1,   212,    -1,   137,    -1,    35,    -1,   251,    -1,   265,
      -1,   254,    -1,   242,    -1,   276,    -1,   268,    -1,   270,
      -1,   269,    -1,   274,    -1,   246,    -1,   241,    -1,    71,
      -1,   208,    -1,   245,    -1,    45,    -1,   214,    -1,   227,
      -1,   221,    -1,   193,    -1,   198,    -1,   197,    -1,   196,
      -1,   195,    -1,   194,    -1,    89,    -1,   104,    -1,   105,
      -1,   176,    -1,    39,    -1,    52,    -1,    61,    -1,    66,
      -1,    53,    -1,    46,    -1,    49,    -1,    70,    -1,    33,
      -1,   138,    -1,    44,    -1,   202,    -1,   161,    -1,   162,
      -1,   159,    -1,    64,    -1,    88,    -1,   109,    -1,   119,
      -1,   120,    -1,    99,    -1,    62,    -1,   126,    -1,   178,
      -1,    93,    -1,    87,    -1,   188,    -1,   117,    -1,   158,
      -1,    85,    -1,    43,    -1,   222,    -1,    94,    -1,   189,
      -1,   110,    -1,   150,    -1,   191,    -1,   141,    -1,   127,
      -1,    69,    -1,    95,    -1,   190,    -1,   142,    -1,   172,
      -1,   186,    -1,   151,    -1,   128,    -1,   122,    -1,   157,
      -1,   139,    -1,   156,    -1,    25,    -1,    31,    -1,    51,
      -1,   106,    -1,    32,    -1,    50,    -1,   206,    -1,    42,
      -1,    55,    -1,    26,    -1,    40,    -1,   264,    -1,   250,
      -1,   273,    -1,   275,    -1,   244,    -1,   258,    -1,   271,
      -1,   263,    -1,   243,    -1,   257,    -1,   272,    -1,   262,
      -1,   256,    -1,   255,    -1,   240,    -1,   239,    -1,   261,
      -1,   247,    -1,   248,    -1,   277,    -1,   267,    -1,   266,
      -1,   259,    -1,   220,    -1,   226,    -1,   223,    -1,   217,
      -1,   210,    -1,   209,    -1,   211,    -1,   228,    -1,   218,
      -1,   219,    -1,   225,    -1,   215,    -1,   224,    -1,    60,
      -1,    58,    -1,    68,    -1,    34,    -1,    48,    -1,   160,
      -1,   192,    -1,   234,    -1,   229,    -1,   232,    -1,   233,
      -1,   235,    -1,   230,    -1,   231,    -1,   236,    -1,   237,
      -1,    38,    -1,   238,    -1,    59,    -1,   286,    -1,   284,
      -1,   285,    -1,   290,    -1,   291,    -1,   292,    -1,   287,
      -1,   288,    -1,   289,    -1,    72,    -1,    73,    -1,    74,
      -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,    79,
      -1,    80,    -1,    81,    -1,    82,    -1,   278,    -1,   279,
      -1,   280,    -1,   281,    -1,   282,    -1,   283,    -1,   293,
      -1,   294,    -1,   295,    -1,   296,    -1,   297,    -1,   298,
      -1,   299,    -1,   554,   552,    -1,    -1,   553,    -1,   572,
      -1,   553,   572,    -1,   555,    -1,   554,   253,   555,    -1,
     556,    -1,   555,   249,   556,    -1,   557,    -1,   556,   251,
     138,   557,    -1,   558,    -1,   251,   558,    -1,   562,   559,
     560,    -1,    -1,   577,    -1,    -1,   561,    -1,   273,   144,
     383,   174,    -1,   566,   563,    -1,   147,   551,   177,    -1,
     564,    -1,    -1,   599,    -1,   453,   144,   565,   174,    -1,
      -1,   551,    -1,   567,   568,    -1,   472,    -1,   144,   383,
     174,    -1,    -1,   569,    -1,   240,   570,    -1,   239,   571,
      -1,   261,    -1,    -1,    71,    -1,    -1,   277,    -1,   573,
      -1,   574,    -1,   575,    -1,   601,    -1,   598,    -1,   160,
      -1,   275,   438,   576,    -1,   244,   600,   576,    -1,   277,
      -1,   267,    -1,   260,    -1,   238,   578,    -1,   577,   238,
     578,    -1,   579,    -1,   580,    -1,   581,    -1,   596,    -1,
     582,    -1,   590,    -1,   583,    -1,   597,    -1,    93,   265,
      -1,    93,   254,    -1,   257,    -1,   272,    -1,   242,   265,
      -1,   242,   254,    -1,    50,   548,    20,    -1,   268,    -1,
      47,   268,    -1,   270,   584,    -1,   270,   147,   584,   585,
     177,    -1,    47,   270,    -1,   587,    -1,   106,    -1,    -1,
     586,    -1,   587,    -1,   586,   100,   587,    -1,    89,    20,
     588,   589,    -1,    -1,   262,    20,    -1,    -1,   600,   256,
      -1,   228,   269,   277,   591,   593,    -1,   228,   106,   269,
     277,   593,    -1,   276,   269,   277,    -1,    89,    20,    -1,
     147,   592,   177,    -1,    20,    -1,   592,   100,    20,    -1,
      -1,   594,    -1,   595,    -1,   594,   595,    -1,   191,   591,
      -1,   127,   591,    -1,   255,    20,    -1,   228,   274,    -1,
     276,   274,    -1,    89,   208,    -1,    89,   245,    -1,   246,
     241,    -1,   258,   600,   271,    -1,   247,   438,    -1,    89,
     120,   438,    -1,    89,    45,   438,    -1,   248,   438,   189,
     438,    -1,   263,   602,    -1,   243,   602,    -1,   266,    -1,
     259,    -1,   276,   241,   440,    -1
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
     631,   634,   637,   640,   645,   650,   655,   660,   667,   672,
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
    1416,  1418,  1420,  1422,  1424,  1426,  1429,  1433,  1438,  1440,
    1443,  1447,  1449,  1451,  1453,  1455,  1457,  1459,  1461,  1463,
    1465,  1467,  1469,  1471,  1473,  1475,  1478,  1481,  1485,  1487,
    1492,  1497,  1501,  1506,  1508,  1512,  1514,  1516,  1518,  1520,
    1522,  1527,  1533,  1542,  1552,  1562,  1573,  1575,  1578,  1580,
    1583,  1590,  1591,  1593,  1597,  1601,  1602,  1604,  1606,  1608,
    1611,  1614,  1615,  1617,  1619,  1621,  1624,  1627,  1629,  1631,
    1633,  1635,  1637,  1639,  1641,  1643,  1645,  1647,  1649,  1651,
    1655,  1658,  1662,  1666,  1669,  1671,  1673,  1675,  1677,  1679,
    1681,  1686,  1691,  1697,  1704,  1712,  1717,  1723,  1730,  1738,
    1743,  1748,  1753,  1759,  1766,  1774,  1776,  1779,  1782,  1784,
    1787,  1791,  1793,  1795,  1797,  1799,  1801,  1805,  1807,  1809,
    1811,  1815,  1817,  1819,  1821,  1823,  1825,  1827,  1829,  1831,
    1833,  1835,  1839,  1843,  1848,  1853,  1857,  1861,  1865,  1870,
    1875,  1879,  1884,  1891,  1896,  1903,  1907,  1911,  1916,  1923,
    1930,  1935,  1942,  1949,  1954,  1956,  1959,  1961,  1963,  1965,
    1969,  1973,  1975,  1977,  1982,  1988,  1995,  1999,  2003,  2007,
    2011,  2017,  2025,  2033,  2039,  2045,  2051,  2059,  2067,  2073,
    2079,  2083,  2087,  2093,  2101,  2107,  2115,  2117,  2122,  2126,
    2132,  2134,  2137,  2141,  2149,  2160,  2174,  2176,  2180,  2182,
    2184,  2186,  2188,  2190,  2198,  2203,  2205,  2207,  2209,  2211,
    2213,  2215,  2217,  2219,  2221,  2223,  2225,  2227,  2229,  2231,
    2233,  2235,  2237,  2239,  2241,  2243,  2245,  2247,  2249,  2251,
    2253,  2255,  2257,  2259,  2261,  2263,  2265,  2267,  2269,  2271,
    2273,  2275,  2277,  2279,  2281,  2283,  2285,  2287,  2289,  2291,
    2293,  2295,  2297,  2299,  2301,  2303,  2305,  2307,  2309,  2311,
    2313,  2315,  2317,  2319,  2321,  2323,  2325,  2327,  2329,  2331,
    2333,  2335,  2337,  2339,  2341,  2343,  2345,  2347,  2349,  2351,
    2353,  2355,  2357,  2359,  2361,  2363,  2365,  2367,  2369,  2371,
    2373,  2375,  2377,  2379,  2381,  2383,  2385,  2387,  2389,  2391,
    2393,  2395,  2397,  2399,  2401,  2403,  2405,  2407,  2409,  2411,
    2413,  2415,  2417,  2419,  2421,  2423,  2425,  2427,  2429,  2431,
    2433,  2435,  2437,  2439,  2441,  2443,  2445,  2447,  2449,  2451,
    2453,  2455,  2457,  2459,  2461,  2463,  2465,  2467,  2469,  2471,
    2473,  2475,  2477,  2479,  2481,  2483,  2485,  2487,  2489,  2491,
    2493,  2495,  2497,  2499,  2501,  2503,  2505,  2507,  2509,  2511,
    2513,  2515,  2517,  2519,  2521,  2523,  2525,  2527,  2529,  2531,
    2533,  2535,  2537,  2539,  2541,  2543,  2545,  2547,  2549,  2551,
    2553,  2555,  2557,  2559,  2561,  2563,  2565,  2567,  2569,  2571,
    2573,  2575,  2577,  2579,  2581,  2583,  2585,  2587,  2589,  2591,
    2593,  2595,  2597,  2599,  2601,  2603,  2606,  2607,  2609,  2611,
    2614,  2616,  2620,  2622,  2626,  2628,  2633,  2635,  2638,  2642,
    2643,  2645,  2646,  2648,  2653,  2656,  2660,  2662,  2663,  2665,
    2670,  2671,  2673,  2676,  2678,  2682,  2683,  2685,  2688,  2691,
    2693,  2694,  2696,  2697,  2699,  2701,  2703,  2705,  2707,  2709,
    2711,  2715,  2719,  2721,  2723,  2725,  2728,  2732,  2734,  2736,
    2738,  2740,  2742,  2744,  2746,  2748,  2751,  2754,  2756,  2758,
    2761,  2764,  2768,  2770,  2773,  2776,  2782,  2785,  2787,  2789,
    2790,  2792,  2794,  2798,  2803,  2804,  2807,  2808,  2811,  2817,
    2823,  2827,  2830,  2834,  2836,  2840,  2841,  2843,  2845,  2848,
    2851,  2854,  2857,  2860,  2863,  2866,  2869,  2872,  2876,  2879,
    2883,  2887,  2892,  2895,  2898,  2900,  2902
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   975,   975,   976,   985,   990,   997,  1002,  1013,  1018,
    1026,  1034,  1042,  1048,  1060,  1069,  1073,  1077,  1089,  1095,
    1105,  1111,  1121,  1122,  1123,  1124,  1129,  1130,  1131,  1132,
    1133,  1134,  1135,  1136,  1137,  1143,  1148,  1157,  1163,  1172,
    1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,
    1195,  1196,  1197,  1198,  1199,  1200,  1201,  1204,  1209,  1210,
    1220,  1229,  1235,  1245,  1251,  1261,  1271,  1279,  1285,  1296,
    1301,  1311,  1317,  1323,  1329,  1346,  1354,  1362,  1366,  1375,
    1384,  1397,  1403,  1414,  1418,  1426,  1431,  1436,  1443,  1456,
    1463,  1469,  1476,  1482,  1486,  1493,  1504,  1508,  1516,  1522,
    1528,  1537,  1543,  1552,  1556,  1562,  1566,  1570,  1574,  1580,
    1586,  1592,  1596,  1602,  1608,  1615,  1623,  1631,  1639,  1647,
    1653,  1661,  1669,  1680,  1685,  1693,  1697,  1704,  1712,  1723,
    1729,  1737,  1744,  1754,  1764,  1774,  1784,  1801,  1807,  1818,
    1822,  1826,  1830,  1839,  1846,  1865,  1875,  1881,  1887,  1897,
    1904,  1915,  1925,  1932,  1944,  1948,  1955,  1960,  1967,  1975,
    1979,  1983,  1991,  1999,  2009,  2023,  2033,  2047,  2056,  2071,
    2077,  2089,  2093,  2104,  2111,  2119,  2134,  2138,  2152,  2156,
    2165,  2169,  2183,  2184,  2185,  2186,  2187,  2190,  2191,  2192,
    2193,  2194,  2196,  2197,  2200,  2201,  2202,  2203,  2204,  2209,
    2224,  2231,  2235,  2242,  2246,  2250,  2257,  2265,  2276,  2286,
    2299,  2308,  2309,  2310,  2314,  2315,  2316,  2317,  2318,  2321,
    2327,  2336,  2340,  2348,  2358,  2364,  2376,  2380,  2388,  2397,
    2407,  2415,  2424,  2433,  2448,  2457,  2467,  2475,  2481,  2490,
    2496,  2508,  2516,  2526,  2534,  2546,  2552,  2563,  2565,  2569,
    2577,  2581,  2586,  2590,  2594,  2598,  2606,  2621,  2629,  2636,
    2642,  2653,  2657,  2666,  2674,  2680,  2690,  2696,  2706,  2710,
    2720,  2726,  2732,  2738,  2747,  2756,  2765,  2778,  2782,  2790,
    2796,  2806,  2814,  2823,  2836,  2843,  2855,  2859,  2872,  2879,
    2892,  2898,  2910,  2916,  2928,  2937,  2941,  2950,  2954,  2962,
    2966,  2976,  2983,  2992,  3002,  3001,  3015,  3024,  3033,  3046,
    3050,  3063,  3066,  3074,  3078,  3087,  3091,  3095,  3104,  3108,
    3114,  3120,  3126,  3137,  3141,  3145,  3153,  3157,  3163,  3173,
    3177,  3187,  3191,  3201,  3205,  3215,  3219,  3229,  3233,  3241,
    3245,  3249,  3253,  3263,  3267,  3271,  3279,  3283,  3287,  3291,
    3295,  3299,  3307,  3311,  3315,  3323,  3327,  3331,  3335,  3345,
    3351,  3361,  3367,  3377,  3381,  3419,  3425,  3431,  3437,  3448,
    3456,  3467,  3473,  3483,  3487,  3495,  3501,  3509,  3515,  3527,
    3533,  3543,  3547,  3551,  3555,  3559,  3565,  3571,  3579,  3583,
    3591,  3595,  3606,  3610,  3614,  3620,  3624,  3638,  3642,  3650,
    3654,  3664,  3668,  3672,  3681,  3685,  3691,  3695,  3703,  3709,
    3719,  3727,  3731,  3735,  3739,  3743,  3747,  3751,  3755,  3759,
    3767,  3771,  3779,  3786,  3793,  3804,  3813,  3817,  3825,  3833,
    3841,  3895,  3899,  3911,  3917,  3927,  3931,  3939,  3943,  3947,
    3955,  3965,  3975,  3985,  3995,  4005,  4020,  4026,  4037,  4043,
    4054,  4065,  4067,  4071,  4076,  4086,  4089,  4096,  4104,  4110,
    4120,  4133,  4136,  4143,  4149,  4155,  4162,  4173,  4177,  4187,
    4191,  4201,  4205,  4209,  4214,  4223,  4229,  4235,  4241,  4251,
    4255,  4267,  4271,  4283,  4295,  4299,  4303,  4307,  4311,  4315,
    4323,  4331,  4337,  4343,  4347,  4364,  4368,  4372,  4376,  4384,
    4392,  4400,  4404,  4408,  4412,  4420,  4426,  4436,  4444,  4448,
    4454,  4489,  4495,  4501,  4511,  4515,  4519,  4523,  4527,  4534,
    4540,  4550,  4558,  4562,  4566,  4570,  4574,  4578,  4582,  4586,
    4590,  4598,  4606,  4610,  4614,  4624,  4632,  4640,  4644,  4648,
    4656,  4660,  4666,  4672,  4676,  4686,  4694,  4698,  4704,  4713,
    4722,  4728,  4734,  4744,  4761,  4768,  4783,  4819,  4823,  4832,
    4841,  4850,  4854,  4863,  4872,  4876,  4885,  4902,  4908,  4914,
    4924,  4928,  4934,  4940,  4944,  4950,  4954,  4960,  4966,  4973,
    4983,  4988,  4996,  5002,  5012,  5034,  5043,  5049,  5062,  5076,
    5083,  5089,  5099,  5104,  5110,  5120,  5133,  5139,  5149,  5159,
    5160,  5178,  5182,  5195,  5201,  5208,  5209,  5210,  5211,  5212,
    5213,  5214,  5215,  5216,  5217,  5218,  5219,  5220,  5221,  5222,
    5223,  5224,  5225,  5226,  5227,  5228,  5229,  5230,  5231,  5232,
    5233,  5234,  5235,  5236,  5237,  5238,  5239,  5240,  5241,  5242,
    5243,  5244,  5245,  5246,  5247,  5248,  5249,  5250,  5251,  5252,
    5253,  5254,  5255,  5256,  5257,  5258,  5259,  5260,  5261,  5262,
    5263,  5264,  5265,  5266,  5267,  5268,  5269,  5270,  5271,  5272,
    5273,  5274,  5275,  5276,  5277,  5278,  5279,  5280,  5281,  5282,
    5283,  5284,  5285,  5286,  5287,  5288,  5289,  5290,  5291,  5292,
    5293,  5294,  5295,  5296,  5297,  5298,  5299,  5300,  5301,  5302,
    5303,  5304,  5305,  5306,  5307,  5308,  5309,  5310,  5311,  5312,
    5313,  5314,  5315,  5316,  5317,  5318,  5319,  5320,  5321,  5322,
    5323,  5324,  5325,  5326,  5327,  5328,  5329,  5330,  5331,  5332,
    5333,  5334,  5335,  5336,  5337,  5338,  5339,  5340,  5341,  5342,
    5343,  5344,  5345,  5346,  5347,  5348,  5349,  5350,  5351,  5352,
    5353,  5354,  5355,  5356,  5357,  5358,  5359,  5360,  5361,  5362,
    5363,  5364,  5365,  5366,  5367,  5368,  5369,  5370,  5371,  5372,
    5373,  5374,  5375,  5376,  5377,  5378,  5379,  5380,  5381,  5382,
    5383,  5384,  5385,  5386,  5387,  5388,  5389,  5390,  5391,  5392,
    5393,  5394,  5395,  5396,  5397,  5398,  5399,  5400,  5401,  5402,
    5403,  5404,  5405,  5406,  5407,  5419,  5428,  5431,  5438,  5443,
    5452,  5456,  5466,  5470,  5480,  5484,  5495,  5499,  5509,  5522,
    5525,  5533,  5536,  5544,  5552,  5560,  5564,  5572,  5575,  5583,
    5595,  5598,  5606,  5618,  5624,  5634,  5637,  5645,  5649,  5653,
    5661,  5664,  5672,  5675,  5683,  5687,  5691,  5695,  5699,  5707,
    5715,  5727,  5739,  5743,  5747,  5755,  5761,  5771,  5775,  5779,
    5783,  5787,  5791,  5795,  5799,  5807,  5811,  5815,  5819,  5827,
    5833,  5843,  5853,  5857,  5865,  5875,  5886,  5893,  5897,  5905,
    5908,  5915,  5920,  5929,  5939,  5942,  5950,  5953,  5961,  5970,
    5977,  5987,  5991,  5998,  6004,  6014,  6017,  6024,  6029,  6041,
    6049,  6061,  6069,  6073,  6081,  6085,  6089,  6097,  6105,  6109,
    6113,  6117,  6125,  6133,  6145,  6149,  6157
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 11304;
  const int xquery_parser::yynnts_ = 289;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 520;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 315;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 569;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 15089 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6163 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"


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

