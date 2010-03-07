
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
#line 952 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"

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
      case 317: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 309 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 318 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 327 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 336 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "Prolog" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 345 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 354 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 363 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 372 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 381 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 390 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 856 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 399 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 856 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 408 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 417 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 426 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 435 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 444 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 453 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 462 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 471 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 480 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 489 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 498 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 507 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 516 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 525 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 534 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 543 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 552 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 561 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 570 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 579 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 588 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 856 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 597 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 606 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "DeclPropertyList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 615 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "DeclProperty" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 624 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 633 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 642 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 651 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 660 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 669 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 678 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 687 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 856 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 696 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 705 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 714 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 723 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 732 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 741 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 750 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 759 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 768 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 777 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 786 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 795 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "FunctionDecl3" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 804 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FunctionDecl4" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 813 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 822 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 831 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 840 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 849 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 858 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 867 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 885 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 894 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 903 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 912 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 921 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 930 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 939 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 948 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 957 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 966 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 975 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 984 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 993 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1002 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1011 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1020 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1029 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1038 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1047 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1056 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1065 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1074 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1083 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1092 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1101 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1110 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1119 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1128 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1137 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1146 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1155 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1164 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1173 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1182 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1191 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1200 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1209 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1218 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1227 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1236 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1245 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1254 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1263 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1272 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1281 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1290 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1299 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1308 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1317 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1326 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1335 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1344 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1353 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1362 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1371 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1380 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1389 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1398 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1407 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1416 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1425 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1434 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1443 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1452 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1461 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1470 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1479 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1488 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1497 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1506 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1515 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1524 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1533 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1542 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1551 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1560 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1569 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1578 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1587 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1596 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1605 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1614 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1623 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1632 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1641 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1650 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1659 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1668 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1677 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1686 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1695 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1704 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1713 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1722 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1731 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1740 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1749 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1758 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1767 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1776 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1785 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1794 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1803 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1812 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1821 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1830 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1839 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1848 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1857 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1866 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1875 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1884 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1893 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1902 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1911 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1920 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1929 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1938 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1947 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1956 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1965 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1974 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1983 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1992 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2001 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2010 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2019 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2028 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2037 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2046 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2055 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2064 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2073 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2082 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2091 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2100 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2109 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2118 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2127 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2136 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2145 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2154 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2163 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2172 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2181 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2190 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2199 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2208 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 856 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2217 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2226 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2235 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2244 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2253 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2262 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2271 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2280 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2289 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2298 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2307 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2316 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2325 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2334 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2343 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2352 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2361 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2370 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2379 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2388 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2397 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2406 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2415 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2424 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2433 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2442 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2451 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2460 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2469 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2478 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2487 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2496 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2505 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2514 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2523 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2532 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2541 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2550 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2559 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2568 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTIgnoreOption" */

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
#line 969 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 978 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 983 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            MainModule *mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
            mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 990 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 995 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            LibraryModule *lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
            lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1006 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            std::string encoding = "utf-8";
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), encoding );
        }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1011 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
        }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1019 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1027 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
        }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1035 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LibraryModule(
                LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1041 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1053 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
            dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
        }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1062 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog( LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)), NULL );
        }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1066 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog( LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)) );
        }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1070 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1082 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
            sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = sdl;
        }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1088 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( SIND_DeclList *sdl = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                sdl->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1098 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
            vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = vdl;
        }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1104 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( VFO_DeclList *vdl = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vdl->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 1136 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
         (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
         delete (yysemantic_stack_[(4) - (4)].vstrpair);
       }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1141 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
         (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
         delete (yysemantic_stack_[(4) - (4)].vstrpair);
       }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1150 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.vstrpair) = new vector<string_pair_t>();
          (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
          delete (yysemantic_stack_[(1) - (1)].strpair);
        }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1156 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
          delete (yysemantic_stack_[(2) - (2)].strpair);
          (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
        }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1165 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
            (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval() );
            delete sl;
        }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1173 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1174 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1175 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1176 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1177 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1178 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1179 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1180 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1181 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1182 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1213 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
        }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1222 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::preserve_space
            );
        }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1228 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::strip_space
            );
        }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1238 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_element_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1244 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_function_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1254 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OptionDecl(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval))
            );
        }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1264 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1272 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::ordered
            );
        }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1278 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::unordered
            );
        }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1289 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_greatest);
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1294 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_least);
        }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1304 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1310 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1316 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1322 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1339 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
        }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1347 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1355 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
        }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1359 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1368 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1377 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1390 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            URILiteralList *ull = new URILiteralList( LOC((yyloc)));
            ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.node) = ull;
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1396 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
                ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1407 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1411 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
        }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1419 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1424 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1429 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), 
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1436 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1449 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
        }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1456 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
            d->type = (yysemantic_stack_[(3) - (2)].node);
            (yyval.node) = d;
        }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1462 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1469 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
            d->ext = false;
            (yyval.node) = d;
        }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1475 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), NULL );
        }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1479 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1486 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1497 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1501 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1509 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(5) - (5)].expr));
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1515 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1521 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1530 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
            dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = dpl;
        }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1536 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
        dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
        (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1545 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1549 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1555 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1559 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1563 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1567 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1573 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1579 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1585 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1589 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1595 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1601 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1608 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1616 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1624 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1632 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1640 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(4) - (2)].node)), 0, 0);
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1646 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1654 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1662 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1673 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = static_cast<parsenode*>(
           new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1678 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = static_cast<parsenode*>(
           new SequenceType( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1686 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier( LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1690 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier( LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1697 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1705 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1716 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList( LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1722 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1730 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec( LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<AtomicType*>((yysemantic_stack_[(3) - (3)].node)),
                            NULL);
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1737 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec( LOC((yyloc)),
                            (yysemantic_stack_[(4) - (1)].expr),
                            dynamic_cast<AtomicType*>((yysemantic_stack_[(4) - (3)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1748 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1758 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1768 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1779 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1794 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_preserve
            );
        }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1800 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_strip
            );
        }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1811 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL );
        }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1815 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1819 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)) );
        }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1823 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig(
                dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1832 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1858 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1867 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            vfo->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = vfo;
        }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1880 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back((yysemantic_stack_[(2) - (2)].node));
            (yyval.node) = vfo;
        }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1890 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(1) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1897 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(3) - (3)].expr));
      vd->set_global(false);
      (yyval.node) = vd;
        }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1908 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1915 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExitExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1922 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1934 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::BREAK );
        }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1938 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
        }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1945 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            dynamic_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1950 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FunctionDecl *fd = dynamic_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));
            fd->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            fd->deterministic = false;
            (yyval.node) = fd;
        }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1957 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            dynamic_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node))->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
        }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1965 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1969 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1973 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1981 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 1989 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1999 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2013 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2023 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2037 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2046 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2061 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            ParamList *pl = new ParamList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2067 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
                pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2079 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2083 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2094 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EnclosedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 2101 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 2109 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QueryBody( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 2124 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2128 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2142 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new BlockBody( LOC((yyloc)) );
        }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2146 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (1)].expr));
            bb->add( (yysemantic_stack_[(3) - (2)].expr) );
            (yyval.expr) = bb;
        }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2155 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2159 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2199 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2214 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2221 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_sliding;
        }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2225 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_tumbling;
        }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2232 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_start;
        }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2236 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_end;
        }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2240 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_only_end;
        }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2247 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2255 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr),
                (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 2266 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2276 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2289 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 2311 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 2317 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2326 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = NULL;
        }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 2330 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_ofor;
        }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2338 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForClause(
                LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL
            );
        }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2348 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
            vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vdl;
        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2354 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2366 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2370 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2378 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2387 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2397 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2405 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2414 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2423 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2438 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2447 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2457 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2465 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2471 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2480 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2486 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2498 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2506 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2516 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2524 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2536 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2542 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2555 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2559 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2567 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2571 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2580 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2584 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2588 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2596 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)),
                           NULL, NULL,
                           new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))),
                           VarGetsDecl::eval_var);
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2610 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2618 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2625 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2631 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2642 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2646 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2655 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2663 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2669 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2679 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2685 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2695 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2699 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2709 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2715 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2721 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2727 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2736 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2745 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2754 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2767 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2771 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2779 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2785 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2795 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2803 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2812 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2825 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
            qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qvidl;

        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2832 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2844 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2848 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2861 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2868 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2881 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2887 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2899 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 2905 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 2917 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 2926 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 2930 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 2939 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 2943 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 2951 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 2955 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2965 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 2972 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2981 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 2990 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 2995 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 3004 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 3013 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 3022 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 3035 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3039 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(5) - (1)].expr)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3051 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3055 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3063 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3067 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3076 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3080 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3084 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3093 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3097 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3103 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3109 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3115 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3126 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3130 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3134 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3142 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3146 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3152 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3162 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3166 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3176 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3180 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3190 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3194 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3204 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3208 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3218 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3222 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3230 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3234 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3238 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3242 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3252 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3256 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3260 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3268 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3272 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3276 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3280 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3284 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3288 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3296 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3300 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3304 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3312 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3316 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3320 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3324 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3334 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3340 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3350 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3356 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3366 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3370 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3408 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL
            );
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3414 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3420 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3426 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = !rpe ?
                (yysemantic_stack_[(1) - (1)].expr) : new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3437 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NULL;
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3445 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 3456 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3462 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3472 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3476 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3484 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3490 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 3498 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3504 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 3516 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3522 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3532 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3536 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3540 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3544 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3548 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3554 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3560 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3568 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3572 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3580 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3584 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3595 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3599 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3603 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3609 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3613 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3627 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3631 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3639 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3643 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3653 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3657 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3661 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3670 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3674 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FilterExpr(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3680 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3684 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3692 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3698 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3708 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3716 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3720 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3724 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3728 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3732 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3736 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3740 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3744 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3748 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3756 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3760 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3768 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3775 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3782 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3793 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3801 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3805 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3813 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 3821 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 3829 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 3883 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 3887 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 3899 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 3905 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 3915 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 3919 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 3927 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 3931 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 3935 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 3943 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 3953 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 3963 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 3973 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 3983 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 3993 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 4008 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4014 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4025 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4031 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4042 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 4059 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4064 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4073 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4077 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4084 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 4092 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4098 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 4108 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 4120 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4124 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4131 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4137 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4143 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4150 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4161 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4165 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4175 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4179 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4189 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4193 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4197 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4202 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4211 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4217 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4223 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4229 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4239 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4243 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4255 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4259 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4271 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4283 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4287 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4291 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4295 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4299 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4303 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4311 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4319 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL
            );
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4325 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr)
            );
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4331 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4335 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4352 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (2)].expr), NULL );
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4356 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4360 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4364 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4372 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4380 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4388 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), NULL );
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4392 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (2)].sval)), (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4396 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4400 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4408 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4414 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4424 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4432 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4436 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4442 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4477 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4483 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4489 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4499 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4503 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4507 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4511 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4515 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4522 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back((yysemantic_stack_[(1) - (1)].node));
          (yyval.node) = aTypeList;
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4528 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          if (aTypeList) aTypeList->push_back((yysemantic_stack_[(3) - (3)].node));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4538 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4546 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4550 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4554 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4558 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4562 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4566 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4570 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4574 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4578 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4586 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4594 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4598 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4602 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4612 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4620 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4628 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4632 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4636 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4644 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4648 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4654 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4660 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4664 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4674 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4682 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4686 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4692 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 4701 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 4710 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4716 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4722 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4732 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4749 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4756 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4771 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4807 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4811 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4820 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), *(yysemantic_stack_[(3) - (3)].ival));
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4829 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new InlineFunction(LOC ((yyloc)), &*(yysemantic_stack_[(3) - (2)].fnsig)->param, &*(yysemantic_stack_[(3) - (2)].fnsig)->ret, dynamic_cast<EnclosedExpr *>((yysemantic_stack_[(3) - (3)].expr)));
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4838 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 4842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 4851 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 4860 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 4864 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)), dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 4873 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 4890 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 4896 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 4902 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 4912 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 4916 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 4922 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 4928 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 4932 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 4938 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 4942 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 4948 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 4954 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 4961 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 4971 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 4976 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 4984 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 4990 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5000 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5022 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5031 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5037 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5050 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5064 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5071 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5077 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5087 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5092 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5098 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 5108 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 5121 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5127 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5148 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 5166 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5170 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5183 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EvalExpr(
                LOC((yyloc)), dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)), (yysemantic_stack_[(7) - (6)].expr)
            );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5189 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EvalExpr( LOC((yyloc)), new VarGetsDeclList( LOC((yyloc)) ), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5195 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("xquery"); }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5196 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("empty"); }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5197 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("attribute"); }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5198 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("comment"); }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5199 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("document-node"); }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5200 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("element"); }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5201 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("item"); }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5202 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("if"); }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5203 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("node"); }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5204 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("processing-instruction"); }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5205 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema-attribute"); }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5206 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema-element"); }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5207 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("text"); }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5208 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("typeswitch"); }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5209 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("empty-sequence"); }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5210 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("boundary-space"); }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5211 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ft-option"); }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5212 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("base-uri"); }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5213 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lax"); }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5214 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("strict"); }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5215 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("idiv"); }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5216 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("document"); }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5217 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("not"); }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5218 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sensitive"); }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5219 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("insensitive"); }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5220 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("diacritics"); }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5221 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("without"); }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5222 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stemming"); }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5223 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("thesaurus"); }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5224 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stop"); }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5225 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("wildcards"); }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5226 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("entire"); }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5227 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("content"); }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5228 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("word"); }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5229 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("start"); }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5230 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("end"); }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5231 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("most"); }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5232 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("skip"); }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5233 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("copy"); }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5234 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("value"); }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5235 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("eq"); }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5236 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ne"); }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5237 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lt"); }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5238 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("le"); }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5239 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("gt"); }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5240 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ge"); }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5241 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("at"); }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5242 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("context"); }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5243 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("variable"); }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5244 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("return"); }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5245 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("for"); }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5246 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("outer"); }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5247 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sliding"); }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5248 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("tumbling"); }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5249 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("previous"); }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5250 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("next"); }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5251 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("only"); }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5252 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("when"); }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5253 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("count"); }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5254 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("in"); }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5255 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("let"); }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5256 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("where"); }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5257 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("by"); }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5258 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("group"); }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5259 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("order"); }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5260 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stable"); }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5261 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ascending"); }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5262 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("descending"); }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5263 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("greatest"); }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5264 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("least"); }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5265 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("collation"); }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5266 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("some"); }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5267 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("every"); }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5268 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("satisfies"); }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5269 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("case"); }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5270 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("as"); }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5271 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("then"); }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5272 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("else"); }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5273 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("or"); }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5274 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("and"); }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5275 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("instance"); }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5276 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("of"); }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5277 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("castable"); }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5278 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("to"); }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5279 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("div"); }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5280 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("mod"); }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5281 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("union"); }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5282 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("intersect"); }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5283 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("except"); }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5284 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("validate"); }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5285 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("cast"); }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5286 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("treat"); }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5287 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("is"); }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5288 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("preserve"); }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5289 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("strip"); }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5290 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("namespace"); }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5291 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("external"); }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5292 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("encoding"); }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5293 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("no-preserve"); }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5294 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("inherit"); }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5295 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("no-inherit"); }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5296 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("declare"); }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5297 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("construction"); }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5298 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ordering"); }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5299 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("default"); }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5300 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("copy-namespaces"); }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 5301 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("option"); }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 5302 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("version"); }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 5303 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("import"); }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 5304 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema"); }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 5305 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("module"); }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 5306 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("function"); }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 5307 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("score"); }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 5308 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("contains"); }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 5309 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("weight"); }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 5310 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("window"); }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 5311 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("distance"); }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 5312 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("occurs"); }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 5313 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("times"); }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 5314 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("same"); }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 5315 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("different"); }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 5316 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lowercase"); }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 5317 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("uppercase"); }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 5318 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("relationship"); }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 5319 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("levels"); }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 5320 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("language"); }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 5321 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("any"); }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 5322 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("all"); }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 5323 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("phrase"); }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 5324 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("exactly"); }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 5325 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("from"); }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 5326 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("words"); }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 5327 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sentences"); }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 5328 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sentence"); }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 5329 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("paragraph"); }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 5330 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("replace"); }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 5331 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("modify"); }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 5332 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("first"); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 5333 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("insert"); }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 5334 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("before"); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 5335 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("after"); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 5336 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("revalidation"); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 5337 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("with"); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 5338 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("nodes"); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 5339 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("rename"); }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 5340 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("last"); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 5341 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("delete"); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 5342 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("into"); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 5343 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("simple"); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 5344 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sequential"); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 5345 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("updating"); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 5346 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("deterministic"); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 5347 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("nondeterministic"); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 5348 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ordered"); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 5349 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("unordered"); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 5350 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("returning"); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 5351 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("block"); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 5352 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("exit"); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 5353 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("loop"); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 5354 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("while"); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 5355 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("break"); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 5356 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("continue"); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 5357 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("try"); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 5358 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("catch"); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 5359 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("eval"); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 5360 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("using"); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 5361 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("set"); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 5362 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("index"); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 5363 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("unique"); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 5364 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("non"); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 5365 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("on"); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 5366 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("range"); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 5367 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("equality"); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 5368 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("manually"); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 5369 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("automatically"); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 5370 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("maintained"); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 5371 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("decimal-format"); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 5372 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("decimal-separator"); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 5373 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("grouping-separator"); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 5374 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("infinity"); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 5375 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("minus-sign"); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 5376 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("NaN"); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 5377 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("percent"); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 5378 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("per-mille"); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 5379 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("zero-digit"); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 5380 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("digit"); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 5381 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("pattern-separator"); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 5382 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("collection"); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 5383 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("const"); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 5384 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("append-only"); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 5385 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("queue"); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 5386 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("mutable"); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 5387 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("read-only"); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 5388 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("integrity"); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 5389 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("constraint"); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 5390 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("check"); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 5391 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("key"); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 5392 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("foreach"); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 5393 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("foreign"); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 5394 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("keys"); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 5407 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), dynamic_cast<FTOr*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 5415 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 5419 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 5426 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 5431 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 5440 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 5444 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr(
                LOC((yyloc)), dynamic_cast<FTOr*>((yysemantic_stack_[(3) - (1)].node)), dynamic_cast<FTAnd*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 5454 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 5458 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd(
                LOC((yyloc)), dynamic_cast<FTAnd*>((yysemantic_stack_[(3) - (1)].node)), dynamic_cast<FTMildNot*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 5468 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 5472 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot(
                LOC((yyloc)),
                dynamic_cast<FTMildNot*>((yysemantic_stack_[(4) - (1)].node)), dynamic_cast<FTUnaryNot*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 5483 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 5487 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 5497 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 5509 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 5513 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 5520 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 5524 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 5532 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 5540 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 5548 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 5552 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 5559 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 5563 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 5571 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 5582 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 5586 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 5594 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 5606 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 5612 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 5621 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 5625 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 5633 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 5637 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 5641 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 5648 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 5652 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 5659 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 5663 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 5671 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 5675 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 5679 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 5683 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 5687 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 5695 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 5703 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 5715 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 5727 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 5731 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 5735 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 5743 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 5749 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 5759 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 5763 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 5767 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 5771 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 5775 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 5779 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 5783 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 5787 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 5795 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 5799 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 5803 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 5807 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 5815 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::senstive
            );
        }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 5821 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 5831 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 5841 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 5845 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 5853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 5863 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 5874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 5881 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 5885 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 5892 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 5896 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(1) - (1)].thesaurus_id_list);
        }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 5903 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 5908 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 5917 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 5926 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 5930 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 5937 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 5941 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 5949 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 5958 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 5965 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 5975 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 5979 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 5986 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 5992 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6001 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6005 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6012 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6017 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 6029 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 6037 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 6049 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6057 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6061 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6069 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6073 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6077 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6085 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6093 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange(
                LOC((yyloc)),
                ft_range_mode::exactly,
                dynamic_cast<AdditiveExpr*>((yysemantic_stack_[(2) - (2)].expr))
            );
        }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6101 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange(
                LOC((yyloc)),
                ft_range_mode::at_least,
                dynamic_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (3)].expr))
            );
        }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6109 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange(
                LOC((yyloc)),
                ft_range_mode::at_most,
                dynamic_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (3)].expr))
            );
        }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6117 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange(
                LOC((yyloc)),
                ft_range_mode::from_to,
                dynamic_cast<AdditiveExpr*>((yysemantic_stack_[(4) - (2)].expr)),
                dynamic_cast<AdditiveExpr*>((yysemantic_stack_[(4) - (4)].expr))
            );
        }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6130 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 6138 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 6150 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6154 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6162 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;



/* Line 678 of lalr1.cc  */
#line 11044 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1286;
  const short int
  xquery_parser::yypact_[] =
  {
      1521, -1286, -1286, -1286, -1286,   762,    27, -1286, -1286,   429,
   -1286, -1286, -1286, -1286,   144,   153,  9310,   217,   329,   161,
     273,   119, -1286,   334, -1286, -1286, -1286, -1286, -1286, -1286,
     432, -1286,  7608, -1286, -1286,   343, -1286,   417, -1286, -1286,
     449, -1286,   481, -1286,   391, -1286,    80, -1286, -1286, -1286,
   -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286, -1286, -1286, -1286, -1286,  9592, -1286,  7032, -1286,
   -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286, 11002, -1286, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286,   463, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286, -1286,  1812, 11002, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286,   446, -1286, -1286, -1286,  8180, -1286,  8464, -1286,
   -1286, -1286, -1286, -1286, 11002, -1286, -1286,  6742, -1286, -1286,
   -1286, -1286, -1286, -1286,   462, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286, -1286,    23,   406, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286, -1286,   318,   450,   370, -1286,   384,   -77, -1286,
   -1286, -1286, -1286, -1286, -1286,   515, -1286,   491,   409,   416,
     423, -1286, -1286,   504,   516, -1286,   562, -1286, -1286, -1286,
   -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286, -1286, -1286, -1286,  4712,   663, -1286,  5002, -1286,
   -1286,   262,  5292,   494,   502, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286, -1286, -1286, -1286, -1286,   -28, -1286, -1286, -1286,
   -1286,   622, 11002, -1286, -1286, -1286, -1286, -1286,   532,   607,
   -1286,   738,   452,   300,   291,   305,   292, -1286,   654,   509,
     611,   614,  5582, -1286, -1286, -1286,   127, -1286, -1286,  6742,
   -1286,   201, -1286,   565,  7032, -1286,   565,  7032, -1286, -1286,
   -1286,   371, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286, -1286, -1286,     7, -1286, -1286,   695,   309,   351,
     -26,   453, 11002,   453, 11002,   189,   676,   677,   678, 11002,
     576,   613,   339,  8180, -1286, -1286,   456,   362,   484, 11002,
   -1286, -1286, -1286, -1286, -1286,   439, 11002,   436,   438,   435,
     464, -1286, -1286, -1286,  8180,  5292,   554,  5292,    40, -1286,
   -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286,  5292,  9874, -1286, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286,   588,
    5292,   458,   459, -1286,   624,    11,   592,  5292,    34,    62,
   11002,   629, -1286,  5292,  7894,   597, -1286, 11002, 11002, 11002,
    5292,   570,  5292, 11002,  5292,   609,   615,  5292, 10156,   617,
     608,   610,   616,   618,   625, -1286, -1286, -1286, 11002, -1286,
     581,   735,  5292,    39, -1286,   749,   596, -1286,  5292,   571,
   -1286,   759,  5292,  5292,   603,  5292,  5292,  5292,  5292,   560,
   11002, -1286, -1286, -1286, -1286,  5292,  5292,  5292, 11002, -1286,
   -1286, -1286, -1286,   762,   119, -1286, -1286,   262,   758,  5292,
   -1286,  5292,   675,   329,   334,   432,   628,   627,   631,  5292,
    5292, -1286, -1286, -1286, -1286, -1286, -1286, -1286,   689, -1286,
     -13,  5872,  5872,  5872, -1286,  5872,  5872, -1286,  5872, -1286,
    5872, -1286, -1286, -1286, -1286, -1286, -1286, -1286,  5872,  5872,
     730,  5872,  5872,  5872,  5872,  5872,  5872,  5872,  5872,  5872,
    5872,  5872,   577,   717,   719,   720, -1286, -1286, -1286,  2102,
   -1286, -1286,  6742,  6742,  5292,   565, -1286, -1286,   565, -1286,
    2392,   565,   668,  2682, -1286, -1286, -1286, -1286, -1286, -1286,
     709,   711, -1286,   161, -1286,   796, -1286, -1286, 11002, -1286,
   -1286, 11002, -1286,   763,   208, 11002,   468,   667,   670,   763,
     695,   701,   702, -1286, -1286, -1286, -1286, -1286,    -9,   589,
     -30, -1286,   536, -1286, -1286, 11002, 11002, 11002, -1286,   705,
     655, -1286,   657,   610,   343, -1286,   656,   658,   672, -1286,
     -25,   -17,  2972,   673, -1286, -1286, 11002,   -15, 11002,   745,
     -14, -1286,  5292, -1286,   671,  8180,   760,   814,  8180,   695,
     764,   754, -1286,   -38, -1286,   681,   679, -1286,   682,  3262,
     683,   729,    -8, -1286,   210,   691, -1286,   686,   727, -1286,
     699,  5292,  5292,   700, -1286,    -6,    10,  3552,    -2, -1286,
   11002,   735, -1286,     3,   704, -1286, -1286, -1286, -1286,   707,
   -1286,   164, -1286, -1286, -1286,    46,    75,   788,   648,   666,
     -20, -1286,   746,  6162, -1286,   708,   713,   242, -1286, -1286,
     712, -1286,    31, -1286, -1286,   -22, 11002,   728,  5292,   777,
   -1286, -1286,   779, 10438,   783,  5292,   784,   -34,   765,   -27,
     607, -1286, -1286, -1286, -1286, -1286,  5872, -1286, -1286, -1286,
      17,   291,   291,   276,   305,   305,   305,   305,   292,   292,
   -1286, -1286, 10438, 10438, 11002, 11002, -1286,   722, -1286, -1286,
     723, -1286, -1286, -1286,    15, -1286, -1286,    30,   400,   427,
     299, -1286,   161,   161, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286, -1286, -1286,   763, -1286,   778, 10720,   769,  5292,
   -1286, -1286, -1286,   817,   772,  5292,   695,   695,   763, -1286,
     552,   695,   364, 11002,   314,   316,   886, -1286, -1286,   633,
     251, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286,    -9,   112,   394, -1286,   690,   114,   -23,   621,
     695, -1286, -1286, -1286, -1286,   768, 11002, -1286, 11002, -1286,
   -1286,   750, -1286,   256,   680, -1286, -1286,   236,   -15,   817,
   10438,   808,   838,   753,   740,   806,   695,   786,   815,   850,
     695,   829,  5292,   810,   -63,   797, -1286, -1286, -1286,   770,
   -1286,  5292,   835,  5292,  5292,   811, -1286,   857,  5292, -1286,
     781,   782,   807, 11002, -1286, 11002, -1286, -1286,   789,  5292,
     925, -1286,   136, -1286,   321, -1286, -1286,   933, -1286,   357,
    5292,  5292,  5292,   390,  5292,  5292,  5292,  5292,  5292,  5292,
     846,  5292,  5292,   613,     1,   790,   491,   721,   816,   851,
     758,   893, -1286, -1286,  5292,   392,   866, -1286, 11002,   867,
   -1286, 11002,   821,   822, 10720,   823, -1286,   234, -1286, -1286,
   -1286, -1286, -1286, -1286, -1286, 11002, -1286, 11002,  5292,   834,
    5292,  5292,   -10,   836, -1286,  5292,    17,   259,   170, -1286,
     703,   107,   725,   726, -1286, -1286,   484, -1286,   718,   293,
   -1286, -1286, -1286,   843, -1286, -1286, -1286,  5292, -1286, -1286,
   -1286, -1286, -1286, -1286, -1286,  5292, -1286,   340,   348, -1286,
     960,   511, -1286, -1286, -1286,  5292, -1286, -1286, -1286, -1286,
   -1286, -1286, -1286,   710, -1286, -1286,   962, -1286, -1286, -1286,
   -1286, -1286,   308,   964, -1286,   478, -1286, -1286, -1286,   608,
     153,   616,   618,   625,   450,   757,   234,   771,   773,  6452,
     714,   692,   112, -1286,   775,   805,  3842,   813,   818,   859,
     819,   820, -1286,  5292,   860, -1286,   888,   889,  5292, 11002,
     393,   931, -1286, -1286, -1286, -1286, -1286, -1286, 10438, -1286,
    5292,   695,   902, -1286, -1286, -1286,   695,   902, 11002, -1286,
    5292,  5292,   870,  4132, -1286, -1286, 11002, -1286, -1286,  5292,
    9028,    28, -1286,   830, -1286, -1286,  4422,   831,   832, -1286,
   -1286, -1286,   883, -1286,   455, -1286, -1286,  1001, -1286, -1286,
   11002, -1286, -1286,   479, -1286, -1286, -1286,   839,   791,   792,
   -1286, -1286, -1286,   793,   795, -1286, -1286, -1286, -1286, -1286,
     794, 11002,   845, -1286,   877, -1286,   613, -1286, -1286, -1286,
    7322,   721, -1286,  5292, 11002,   866, -1286,   695, -1286,   559,
   -1286,   297,   913, -1286,  5292,   924,   777, -1286,  8746,   847,
     848,   849, -1286, -1286, -1286, -1286, -1286, -1286, -1286,  5292,
   -1286, -1286,  5292,   890,  5292,   853,   852, -1286,    17,   803,
   -1286, -1286,   163, -1286,   319,   -54,   809,    17,   319,  5872,
   -1286,    58, -1286, -1286, -1286, -1286, -1286, -1286,    17,   892,
     761,   589,   -54, -1286, -1286,   755,   965, -1286, -1286, -1286,
   -1286, -1286,   861, -1286, -1286, -1286,  5292, -1286, -1286, -1286,
   -1286, -1286,  1013,   105,  1017,   105,   776,   950, -1286, -1286,
   -1286, -1286,   891, 11002,   804,   757,  6452, -1286, -1286,   880,
   -1286, -1286, -1286, -1286, -1286, -1286,  5292, 11002, 11002, -1286,
     433, -1286,  5292, -1286,   939,   968,   695,   902, -1286, -1286,
   -1286,  5292, -1286,   884, -1286, -1286, 11002,   885,    69, -1286,
   -1286, -1286,   894, -1286, -1286,   925, 11002,   612, -1286,   925,
   11002, -1286, -1286,  5292,  5292,  5292,  5292,  5292, -1286,  5292,
    5292, -1286, -1286,   261, -1286,   895, -1286, -1286, -1286, -1286,
     913, -1286, -1286, -1286,   695, -1286, -1286,   972,   887, -1286,
      38, -1286, -1286, -1286, -1286, -1286,  5292, -1286, -1286, -1286,
   -1286,   896,  5872, -1286, -1286, -1286, -1286, -1286,    45,  5872,
    5872,   295, -1286,   725, -1286,    67, -1286,   726,    17,   916,
   -1286, -1286,   800, -1286, -1286, -1286, -1286, -1286,    12, -1286,
     218,   218, -1286,   105, -1286, -1286,    97, -1286,  1042,   -54,
     897,   966, -1286,  6452,   -75,   787, -1286,   906, -1286, -1286,
   -1286,  1027, -1286, -1286,  5292,   695, -1286, -1286, -1286,   988,
    5292, 11002,  5292, -1286,   -18,   925, 11002,   898,   925, -1286,
   -1286, -1286, -1286, -1286, -1286, -1286,   967,  7322, -1286, -1286,
   -1286, -1286, 10438, -1286, 10438,   989, -1286, -1286,   305,  5872,
    5872,   276,   311, -1286, -1286, -1286, -1286, -1286, -1286,  5292,
   -1286, -1286, -1286, -1286, -1286,  1057, -1286, -1286, -1286,   824,
   -1286,   950,   979, -1286,   994, 11002,   973,   871, 11002,  6452,
     975, -1286,   902, 10438, -1286,   907, -1286,    59,   383, -1286,
     901,   925, -1286,   904, 11002, -1286, -1286, -1286, 10438,   276,
     276,  5872,   915, -1286, -1286, -1286,  6452, 11002,   798, 11002,
     981,   879,   979, 11002,   920,  5292, -1286, -1286,  1011,    65,
   -1286, -1286, -1286, -1286,   926,   415, -1286, -1286, -1286,   911,
   -1286,   158, -1286,   276, -1286, -1286,   913,  5292,   812, 11002,
     990, -1286,  5292, -1286, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286,   991,   956, -1286, -1286,   825,   826, 11002, -1286, 11002,
   -1286,   827,  5292,   828,   162,  6452, -1286,  6452,   992,   956,
   -1286,   919, 11002, -1286,   833,   927, 11002,   956,   899, -1286,
     999, 11002,   840,  6452, -1286
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
     762,   763,   760,   764,   767,   768,   770,   732,   731,   718,
     637,   630,   725,   721,   640,   636,   734,   735,   627,   621,
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
       0,   317,   316,   314,   320,   321,   322,   319,   324,   325,
     328,   327,     0,     0,     0,     0,   359,     0,   371,   372,
       0,   409,   406,   433,     0,   559,   431,     0,     0,     0,
       0,    65,     0,     0,    40,    42,    43,    44,    45,    47,
      48,    49,    41,    46,    36,    37,     0,     0,    93,     0,
      89,    91,    92,    96,    99,     0,     0,     0,    35,    75,
       0,     0,     0,     0,     0,     0,     0,   867,   872,     0,
       0,   868,   902,   855,   857,   858,   859,   861,   863,   862,
     860,   864,     0,     0,     0,   116,     0,     0,   119,     0,
       0,   500,   490,   533,   534,     0,     0,   550,     0,   547,
     491,     0,   604,     0,     0,   203,   204,     0,   209,   171,
       0,     0,   140,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,     0,     0,     0,   539,   538,   501,     0,
     553,     0,     0,     0,     0,     0,   499,     0,     0,   355,
       0,     0,     0,     0,   543,     0,   541,   495,     0,     0,
     451,   449,     0,   440,     0,   429,   430,     0,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   706,     0,     0,     0,     0,     0,     0,
      17,     0,   179,   210,     0,   268,   264,   266,     0,   258,
     259,     0,   716,   611,     0,   619,   507,   508,   514,   515,
     517,   561,   562,   518,   521,     0,   226,     0,     0,     0,
       0,     0,     0,     0,   305,     0,     0,     0,     0,   833,
     311,   806,   810,   812,   814,   816,   819,   826,   827,   835,
     330,   332,   334,   505,   336,   360,   410,     0,   407,   432,
      73,    74,    71,    72,   164,     0,   163,     0,     0,    38,
       0,     0,    94,    95,    97,     0,    98,    63,    64,    69,
      70,    60,   873,     0,   876,   903,     0,   866,   865,   870,
     869,   901,     0,     0,   878,     0,   874,   877,   856,     0,
       0,     0,     0,     0,     0,   117,   123,     0,     0,     0,
       0,     0,     0,   120,     0,     0,     0,     0,     0,   554,
       0,     0,   492,     0,     0,   205,     0,     0,     0,     0,
     250,     0,   247,   252,   208,   172,   141,   170,     0,   173,
       0,     0,    87,    81,    84,    83,     0,    79,     0,   241,
       0,     0,     0,     0,   502,   151,     0,   282,   286,     0,
       0,     0,   290,     0,   357,   356,     0,     0,     0,   496,
     283,   452,     0,   441,     0,   475,   472,     0,   476,   477,
       0,   478,   471,     0,   446,   474,   473,     0,     0,     0,
     573,   574,   570,     0,     0,   578,   579,   575,   584,   582,
       0,     0,     0,   588,   149,   148,     0,   145,   144,   153,
       0,   589,   590,     0,     0,   265,   277,     0,   278,     0,
     269,   270,   271,   272,     0,   261,     0,   225,     0,     0,
       0,     0,   511,   513,   512,   509,   234,   235,   228,     0,
     230,   227,     0,     0,     0,     0,     0,   817,   830,     0,
     310,   312,     0,   849,     0,     0,     0,     0,     0,     0,
     805,   807,   808,   844,   845,   846,   848,   847,     0,     0,
     821,   820,     0,   824,   828,   842,   840,   839,   832,   836,
     506,   434,     0,   166,   165,   168,     0,    39,    90,   100,
     890,   871,     0,   895,     0,   895,   884,   879,   118,   124,
     126,   125,     0,     0,     0,   121,     0,    14,   493,     0,
     551,   552,   555,   548,   549,   245,     0,     0,     0,   207,
     248,   251,     0,   142,     0,    86,     0,    80,   238,   243,
     242,     0,   503,     0,   285,   287,     0,     0,     0,   291,
     358,   497,     0,   544,   542,   451,     0,     0,   483,   451,
       0,   447,     9,     0,     0,     0,     0,     0,   587,     0,
       0,   147,   596,     0,   591,     0,   240,   281,   279,   280,
     273,   274,   275,   267,     0,   262,   260,     0,     0,   519,
       0,   516,   566,   510,   232,   229,     0,   231,   834,   825,
     831,     0,     0,   904,   905,   915,   914,   913,     0,     0,
       0,     0,   906,   811,   912,     0,   809,   813,     0,     0,
     818,   822,     0,   843,   838,   841,   837,   174,     0,   891,
       0,     0,   889,   896,   897,   893,     0,   888,     0,   886,
       0,   880,   881,     0,     0,     0,   122,     0,   494,   246,
     254,   255,   249,   206,     0,     0,    82,   244,   504,     0,
       0,     0,     0,   498,     0,   451,     0,     0,   451,   571,
     572,   576,   577,   583,   585,   150,     0,     0,   592,   603,
     276,   263,     0,   563,     0,     0,   233,   829,   916,     0,
       0,   908,     0,   854,   853,   852,   851,   850,   815,     0,
     907,   167,   900,   899,   898,     0,   892,   885,   883,     0,
     875,     0,   127,   129,     0,     0,     0,     0,     0,     0,
       0,   294,    88,     0,   292,     0,   288,   461,   455,   450,
       0,   451,   442,     0,     0,   597,   564,   520,     0,   910,
     909,     0,     0,   894,   887,   882,     0,     0,     0,     0,
       0,     0,   128,     0,     0,     0,   469,   463,     0,   462,
     464,   470,   467,   457,     0,   456,   458,   468,   444,     0,
     443,     0,   565,   911,   823,   130,   131,     0,     0,     0,
       0,   253,     0,   289,   454,   465,   466,   453,   459,   460,
     445,     0,     0,   132,   133,     0,     0,     0,   293,     0,
     593,     0,     0,     0,     0,     0,   135,     0,     0,     0,
     134,     0,     0,   594,     0,     0,     0,     0,     0,   595,
       0,     0,     0,     0,   136
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1286, -1286,   878, -1286,   874,   881, -1286,   864, -1286,   590,
     591,  -521, -1286,   487,  -270, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286,  -875,
   -1286, -1286, -1286, -1286,    99,   304,   744, -1286, -1286,   731,
   -1286,    64,  -845, -1286,  -332,  -357, -1286, -1286,  -553, -1286,
    -859, -1286, -1286,   -24, -1286, -1286, -1286, -1286, -1286,   274,
     766, -1286, -1286, -1286,   249,   684, -1285,   900,   -85, -1286,
    -523,  -389, -1286, -1286, -1286, -1286,   260, -1286, -1286,   856,
   -1286, -1286, -1286, -1286, -1286,   173,  -518,  -650, -1286, -1286,
   -1286,    41, -1286, -1286,  -129,    66,   -19, -1286, -1286, -1286,
     -29, -1286, -1286,   195,   -11, -1286, -1286,   -21, -1148, -1286,
     664,    48, -1286, -1286,    44, -1286, -1286,   600,   604, -1286,
    -513, -1286, -1286,  -572,   109,  -571,   117,   122, -1286, -1286,
   -1286, -1286, -1286,   855, -1286, -1286, -1286, -1286,  -751,  -297,
   -1028, -1286,  -110, -1286, -1286, -1286, -1286, -1286, -1286, -1286,
     -41, -1139, -1286, -1286,   325,    13, -1286,  -748, -1286, -1286,
   -1286, -1286, -1286, -1286, -1286,   555, -1286,  -904, -1286,    35,
   -1286,   454,  -701, -1286, -1286, -1286, -1286, -1286,  -345,  -338,
   -1085,  -942, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286,   379,  -598,  -757,   110,  -764, -1286,  -773,  -724,
   -1286, -1286, -1286, -1286, -1286, -1286, -1286,   767,   774,  -491,
     301,   147, -1286, -1286, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286, -1286, -1286, -1286, -1286,    19, -1286, -1286,    16,
   -1286,  -353,  -114,   -16, -1286, -1286,  -956, -1286, -1286, -1286,
     -39,   -47,  -186,   186, -1286, -1286, -1286, -1286, -1286, -1286,
   -1286, -1286, -1286, -1286, -1286, -1286, -1286,   -37, -1286, -1286,
   -1286,  -179,   182,   327, -1286, -1286, -1286, -1286, -1286,   135,
   -1286, -1286, -1208, -1286, -1286, -1286,  -683, -1286,   -64, -1286,
    -190, -1286, -1286, -1286, -1286, -1171, -1286,   -12, -1286
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   814,   815,   816,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,  1092,
     679,   261,   262,   820,   821,   822,  1154,   263,   400,   401,
     264,  1055,   855,   265,  1452,  1453,   266,   267,   456,   268,
     512,   733,   944,  1155,   269,   270,   271,   272,   273,   402,
     403,   619,   622,   670,   671,  1131,  1016,   274,   275,   531,
     276,   277,   278,   541,   454,   877,   878,   279,   542,   280,
     544,   281,   282,   283,   548,   549,  1080,   758,   284,   681,
     737,   682,   667,  1081,  1082,  1083,   738,   545,   546,   959,
     960,  1325,   547,   956,   957,  1170,  1171,  1172,  1173,   285,
     692,   693,   286,  1111,  1112,   287,   288,   289,   290,   766,
     291,  1200,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   568,   569,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   595,   596,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   794,   331,   332,   333,  1133,
     711,   712,   713,  1469,  1504,  1505,  1498,  1499,  1506,  1500,
    1134,  1135,   334,   335,  1136,   336,   337,   338,   339,   340,
     341,   342,  1002,   759,   966,  1185,   967,  1330,   968,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   698,
    1068,   353,   354,   355,   356,   970,   971,   972,   973,   357,
     358,   359,   360,   361,   362,   730,   731,   363,  1161,  1162,
    1313,  1093,   465,   364,   365,   366,   990,  1210,  1211,   991,
     992,   993,   994,   995,  1220,  1360,  1361,   996,  1223,   997,
    1341,   998,   999,  1228,  1229,  1366,  1364,  1212,  1213,  1214,
    1215,  1436,   639,   843,   844,   845,   846,   847,   848,  1046,
    1380,  1381,  1047,  1379,  1448,   849,  1245,  1376,  1372,  1373,
    1374,   850,   851,  1216,  1224,  1351,  1217,  1347,  1201
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       449,   773,   493,   774,   775,   776,   777,   743,   745,   590,
     922,  1003,  1003,  1063,   605,  1097,   466,   497,   490,   988,
    1132,  1312,   989,  1321,  1322,  1000,  1001,   485,  1418,   969,
    1196,  1252,   757,   893,   874,  1348,  1455,     4,   832,  1382,
     762,   833,   763,   764,   499,   765,   715,   767,  1301,   753,
     479,  1362,   486,  1021,   604,   768,   769,   853,   969,   969,
     800,   663,   754,  1496,  1062,   371,   487,  1125,  1467,  1496,
    1101,   372,   529,  1125,   753,   866,   754,   653,   529,   373,
     940,   374,   604,   868,   834,   894,   881,  1159,   491,   376,
    1429,   377,   902,   969,   913,   892,   905,   654,   902,   378,
     466,  1156,   495,   379,   978,   676,   680,   979,   496,   983,
     915,   981,   529,   722,   723,  1007,   725,   726,   727,   728,
      74,  1110,   668,  1086,   923,   755,   734,   735,  1192,  1056,
    1007,   610,    85,   929,  1288,   380,   381,   951,  1424,   508,
     744,  1456,  1049,   602,   509,   458,   611,  1202,  1050,   653,
     750,   751,   867,   530,   603,  1468,   969,    99,  1234,   952,
     869,   985,   933,   882,   986,  1430,  1051,   473,   677,   654,
     903,   914,  1420,  1128,   459,  1129,   919,  1052,   404,  1128,
    1401,  1129,  1157,  1497,   118,   675,  1441,   916,   669,  1525,
     924,   384,  1008,   875,  1349,  1350,  1202,  1445,   854,   591,
    1180,   756,  1053,   672,   716,   854,   941,  1009,  1449,   672,
    1248,   793,  1301,   678,   793,  1425,   571,   655,  1203,  1122,
    1132,  1277,  1457,   385,   474,  1024,   756,   500,  1387,  1132,
     756,   876,  1370,   572,   835,   988,   988,   756,   989,   989,
     969,   982,  1340,  1485,  1102,  1402,   836,  1540,   837,  1017,
    1018,   756,   387,   984,   756,   930,   931,  1123,  1531,   838,
     839,   840,  1548,   841,  1553,   842,   550,  1203,   987,   632,
     932,   589,  1559,   597,  1446,  1074,   599,   829,  1475,     4,
     948,  1085,  1076,   388,   934,   935,   927,   523,   407,  1077,
     649,   124,   475,   476,   118,   817,  1371,   753,   486,   936,
     408,   486,  1204,  1205,   524,  1206,  1078,  1242,   455,   389,
     390,   391,   392,   393,  1198,   394,   395,   396,   397,   398,
     650,  1208,   652,  1124,   399,   754,   889,  1433,  1054,  1125,
    1126,  1273,  1193,  1209,  1434,  1532,   818,   118,  1056,  1549,
    1043,   819,   949,   753,  1435,   928,   658,  1079,   904,   616,
     688,  1204,  1205,  1287,  1206,  1454,   613,  1044,   615,   955,
    1207,   450,    74,   623,   969,  1244,   976,   466,  1533,  1182,
    1208,  1343,   674,   640,    85,  1067,   627,  1070,   685,   628,
     642,   617,  1209,   592,   593,   695,   969,   697,   466,   700,
     451,  1125,   703,  1132,  1073,   452,  1167,  1242,  1045,    99,
    1183,   574,  1502,   985,  1060,  1015,   986,   714,  1416,  1344,
    1386,   629,  1061,   719,  1243,  1169,   661,  1127,  1184,   580,
     457,  1329,  1117,  1125,  1118,   571,   118,  1014,   575,   743,
    1023,  1454,   736,   581,  1502,  1128,  1026,  1129,   630,  1076,
     453,   576,   572,  1015,   683,   460,  1077,   988,   466,   571,
     989,   690,   691,   694,   969,  1244,   988,   699,  1454,   989,
     571,  1417,   706,  1125,  1126,   672,   572,   988,  1233,   104,
     989,   461,   694,  1027,  1028,   577,  1235,   572,  1031,  1076,
    1166,   606,   788,   789,   511,   116,  1077,  1125,  1126,   573,
     467,  1167,  1236,   372,   732,   607,   578,  1128,   631,  1129,
    1481,  1168,   739,  1099,   787,   579,  1130,  1065,  1503,   790,
    1169,   376,  1105,   377,  1107,  1108,   594,  1550,   600,  1551,
    1462,   378,   754,   608,   143,  1501,  1507,   672,   468,  1128,
    1120,  1129,  1225,  1226,   502,  1564,   503,   609,   472,  1010,
    1528,  1140,  1141,  1142,  1019,  1145,  1146,  1147,  1148,  1149,
    1150,  1127,  1152,  1153,  1227,  1433,  1011,  1501,  1019,   672,
     469,   885,  1434,  1507,   888,   955,  1012,  1043,  1037,  1128,
    1039,  1129,  1435,   405,   488,  1127,   406,   871,  1345,  1038,
    1138,  1040,  1139,  1013,  1044,  1346,   505,   883,   506,  1188,
     492,  1190,  1191,  1128,  1404,  1129,   824,   504,  1407,   672,
     507,   825,   802,   104,   899,   803,   498,   988,   791,   823,
     989,   791,   501,  1143,   791,  1144,   910,   911,  1231,   116,
    1125,  1126,   918,   672,   384,   470,   510,   104,   471,   857,
     858,   859,  1032,  1033,  1034,   511,  1239,  1355,  1035,   818,
    1296,   598,   513,   116,   819,   612,   601,   614,   945,   514,
     873,   516,   879,   636,   637,   532,   385,   515,   143,   466,
     517,   533,   466,   520,  1300,  1476,   534,  1477,   633,   634,
     635,  1029,  1030,   518,   535,   527,  1057,  1058,  1318,  1319,
     771,   772,   143,   528,  1265,   387,   536,  1442,  1443,  1269,
     551,   590,   552,   570,   920,   778,   779,   582,   969,   583,
     969,  1274,   780,   781,  1470,   584,  1494,  1473,  1127,   585,
     594,  1279,  1280,  1368,  1516,   604,   618,   372,   621,   624,
    1285,  1512,   638,   641,   625,   643,  1128,   644,  1129,   645,
     953,   651,   662,   664,   665,   666,   672,   974,  1275,   969,
     684,   689,   646,   390,   391,   392,   393,   696,   394,   395,
     647,   397,   398,   701,   969,   406,   672,   432,   709,   702,
     104,   707,   710,   464,   717,   471,   974,   974,   974,   974,
    1509,  1428,   478,   718,  1315,   720,   116,  1431,  1432,   721,
     724,   537,   729,   742,   538,   955,   746,   747,   748,   752,
     367,   368,   749,   369,   370,   770,   371,  1406,   539,   782,
    1334,   974,   372,  1335,   783,  1337,   784,   785,   795,   798,
     373,   799,   374,   375,  1317,   143,   801,  1036,   826,   830,
     376,   827,   377,  1113,   540,   831,   856,   852,   860,   861,
     378,   862,   880,   863,   379,   864,   804,   805,   806,   807,
     808,   809,   810,   811,   812,   813,   865,   872,   884,   886,
    1069,   887,  1069,   890,   891,   895,   896,  1479,  1480,   897,
     900,   553,   901,   907,   974,   906,   380,   381,   382,   554,
     555,   908,   556,   909,   912,   937,   938,  1389,   925,   942,
     557,   926,   939,  1393,   558,   946,   559,   947,   958,   954,
     961,   560,  1397,   950,   975,   977,  1005,   699,  1006,   699,
    1195,  1020,   819,   980,   753,  1025,  1041,   561,  1059,  1513,
    1042,  1064,  1066,   383,  1409,  1410,  1411,  1412,  1413,   668,
    1414,  1415,   384,  1396,  1072,  1088,  1075,  1089,  1090,  1091,
    1232,   562,   563,   564,   565,   566,   567,  1094,  1095,  1096,
    1098,  1103,  1175,  1100,  1104,   550,  1106,  1426,   974,  1109,
    1110,  1116,  1121,  1137,   385,  1114,  1115,  1151,  1160,  1186,
    1163,  1187,  1164,  1119,  1158,   629,  1174,  1176,  1178,  1179,
    1181,  1421,  1189,   386,  1194,  1218,  1222,  1219,  1230,  1199,
       4,  1259,  1241,   387,  1246,   854,  1257,  1240,  1254,  1250,
    1260,  1251,  1253,  1256,  1262,  1261,  1263,  1264,  1266,  1267,
    1268,  1272,  1276,  1281,  1290,  1461,  1295,  1298,  1293,  1294,
    1310,  1464,  1167,  1466,   388,  1303,  1304,  1305,  1283,  1306,
    1302,  1309,  1307,  1324,  1331,  1332,  1333,  1338,  1336,  1339,
    1358,  1292,  1363,  1369,  1359,  1367,  1365,  1375,  1378,  1043,
     389,   390,   391,   392,   393,  1342,   394,   395,   396,   397,
     398,  1352,  1383,  1385,  1388,   399,  1394,  1395,  1398,  1422,
    1439,  1400,  1447,  1270,  1423,  1458,  1451,  1459,  1403,  1419,
    1427,  1440,   974,  1460,  1450,  1463,  1478,  1483,  1474,  1486,
    1484,  1487,   683,  1495,  1489,  1472,  1493,  1490,  1508,  1514,
     694,  1510,  1519,  1517,   974,  1520,  1522,  1524,  1530,  1527,
    1015,  1537,  1539,  1552,  1557,   525,  1523,  1535,  1554,  1541,
    1561,  1556,   521,   519,  1299,  1560,   828,   740,   741,   522,
    1238,  1542,  1022,  1545,  1547,   626,  1255,  1492,  1534,  1515,
    1087,   648,  1311,  1538,  1177,   732,  1563,   543,  1084,  1278,
     673,  1392,   526,   620,   486,  1316,  1271,  1326,   739,  1165,
    1320,   760,   708,  1546,  1284,  1289,   761,   588,   797,  1297,
    1529,  1526,   974,  1323,  1004,   921,  1249,  1237,  1353,  1071,
    1308,  1357,  1438,  1197,  1356,   656,  1437,  1314,  1221,  1048,
    1247,  1377,   657,  1444,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1354,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1384,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1390,  1391,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1399,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1405,     0,     0,     0,  1408,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1482,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1465,     0,     0,     0,     0,
    1471,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   486,     0,     0,     0,     0,   974,     0,   974,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1488,
       0,     0,  1491,     0,     0,     0,     0,   974,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1511,     0,
       0,     0,   974,     0,     0,     0,     0,     0,     0,     0,
       0,   974,     0,  1518,     0,     0,     0,  1521,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1536,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1543,     0,  1544,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     0,     0,  1555,     0,     2,     3,
    1558,     4,     0,     0,     0,  1562,     5,     6,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,     0,    72,
      73,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,    85,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,    91,    92,    93,
      94,    95,     0,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,   103,   104,
     105,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,   117,   118,     0,
       0,   119,   120,   121,     0,     0,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   144,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,     0,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   409,   410,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   419,    22,    23,    24,    25,     0,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   105,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   117,   118,
       0,     0,   119,   120,   121,     0,     0,     0,   122,   489,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   435,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   409,   410,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   419,    22,    23,    24,    25,     0,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   105,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   117,   118,
       0,     0,   119,   120,   121,     0,   786,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   435,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   409,   410,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   419,    22,    23,    24,    25,     0,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   105,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   117,   118,
       0,     0,   119,   120,   121,     0,     0,     0,   122,   792,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   435,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   409,   410,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   419,    22,    23,    24,    25,     0,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   105,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   117,   118,
       0,     0,   119,   120,   121,     0,     0,     0,   122,   796,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   435,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   409,   410,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   419,    22,    23,    24,    25,     0,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   105,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   117,   118,
       0,     0,   119,   120,   121,     0,   870,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   435,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   409,   410,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   419,    22,    23,    24,    25,     0,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   105,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   117,   118,
       0,     0,   119,   120,   121,     0,   898,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   435,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   409,   410,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   419,    22,    23,    24,    25,     0,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   105,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   117,   118,
       0,     0,   119,   120,   121,     0,   917,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   435,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   409,   410,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   419,    22,    23,    24,    25,     0,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   105,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   117,   118,
       0,     0,   119,   120,   121,     0,  1258,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   435,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   409,   410,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   419,    22,    23,    24,    25,     0,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   105,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   117,   118,
       0,     0,   119,   120,   121,     0,  1282,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   435,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   409,   410,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   419,    22,    23,    24,    25,     0,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   105,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   117,   118,
       0,     0,   119,   120,   121,     0,  1291,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   435,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,     5,     6,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   105,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   117,   118,
       0,     0,   119,   120,   121,     0,     0,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   144,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,     5,     6,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   105,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   117,   118,
       0,     0,   119,   120,   121,     0,     0,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   435,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   409,   410,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   419,    22,    23,    24,    25,     0,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   105,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   117,   118,
       0,     0,   119,   120,   121,     0,     0,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   435,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   409,   410,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
     415,   416,    19,   418,   419,    22,   420,    24,    25,     0,
      26,    27,    28,    29,   421,    31,    32,    33,    34,    35,
      36,   424,    38,    39,   425,     0,    41,    42,    43,   427,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   430,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   586,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   587,   118,
       0,     0,   119,   120,   121,     0,     0,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   435,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   436,   154,   438,
     156,   439,   440,   159,   160,   161,   162,   163,   164,   441,
     166,   442,   443,   444,   445,   171,   172,   446,   447,   175,
     448,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   409,   410,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
     415,   416,    19,   418,   419,    22,   420,    24,    25,     0,
      26,    27,    28,    29,   421,    31,    32,    33,    34,    35,
      36,   424,    38,    39,   425,     0,    41,    42,    43,   427,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   430,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   105,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   117,   118,
       0,     0,   119,   120,   121,     0,     0,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   435,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   436,   154,   438,
     156,   439,   440,   159,   160,   161,   162,   163,   164,   441,
     166,   442,   443,   444,   445,   171,   172,   446,   447,   175,
     448,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   943,   410,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   419,    22,    23,    24,    25,     0,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   105,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   117,   118,
       0,     0,   119,   120,   121,     0,     0,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   435,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   409,   410,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
     415,   416,    19,   418,   419,    22,   420,    24,    25,     0,
      26,    27,    28,    29,   421,    31,    32,    33,    34,    35,
      36,   424,    38,    39,   425,     0,    41,    42,    43,   427,
      45,   428,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   430,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,     0,     0,
       0,     0,   119,   120,   121,     0,     0,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   435,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   436,   154,   438,
     156,   439,   440,   159,   160,   161,   162,   163,   164,   441,
     166,   442,   443,   444,   445,   171,   172,   446,   447,   175,
     448,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   409,   410,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
     415,   416,    19,   418,   419,    22,   420,    24,    25,     0,
      26,    27,    28,    29,   421,    31,    32,    33,    34,    35,
      36,   424,    38,    39,   425,     0,    41,    42,    43,   427,
      45,   428,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   430,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,     0,     0,
       0,     0,   119,   120,   121,     0,     0,     0,   122,     0,
     123,   124,   125,     0,     0,     0,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   435,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   436,   154,   438,
     156,   439,   440,   159,   160,   161,   162,   163,   164,   441,
     166,   442,   443,   444,   445,   171,   172,   446,   447,   175,
     448,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     0,     0,     0,     0,     0,   409,   410,     0,
       7,     8,   480,    10,    11,    12,    13,   412,    15,   481,
     415,   416,   417,   418,   419,    22,   420,    24,    25,     0,
      26,    27,    28,    29,   421,    31,   482,    33,    34,    35,
      36,   424,    38,    39,   425,     0,    41,   483,    43,   427,
      45,   428,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    62,     0,    63,
      64,    65,   484,     0,     0,    69,    70,    71,     0,     0,
       0,    73,     0,     0,     0,     0,    75,    76,    77,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   430,    92,
      93,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   433,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,     0,
     123,   124,     0,     0,     0,     0,   128,     0,   129,     0,
     130,   131,   132,   133,   434,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   435,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   436,   154,   438,
     156,   439,   440,   159,   160,   161,   162,   163,   164,   441,
     166,   442,   443,   444,   445,   171,   172,   446,   447,   175,
     448,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     0,     0,     0,     0,     0,   409,   410,     0,
       7,     8,   411,    10,    11,    12,    13,   412,   413,   414,
     415,   416,   417,   418,   419,    22,   420,    24,    25,     0,
      26,    27,    28,    29,   421,    31,   422,    33,    34,   423,
      36,   424,    38,    39,   425,     0,    41,   426,    43,   427,
      45,   428,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    62,     0,    63,
      64,    65,   429,     0,     0,    69,    70,    71,     0,     0,
       0,    73,     0,     0,     0,     0,    75,    76,    77,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   430,    92,
      93,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   433,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,     0,
     123,     0,     0,     0,     0,     0,   128,     0,   129,     0,
     130,   131,   132,   133,   434,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   435,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   436,   437,   438,
     156,   439,   440,   159,   160,   161,   162,   163,   164,   441,
     166,   442,   443,   444,   445,   171,   172,   446,   447,   175,
     448,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   462,     0,     0,     0,     3,     0,     0,     0,
       0,     0,     0,   409,   410,     0,     7,     8,   411,    10,
      11,    12,    13,   412,   413,   414,   415,   416,   417,   418,
     419,    22,   420,    24,    25,     0,    26,    27,    28,    29,
     421,    31,   422,    33,    34,   423,    36,   424,    38,    39,
     425,     0,    41,   426,    43,   427,    45,   428,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    62,     0,    63,    64,    65,   429,     0,
       0,    69,    70,    71,     0,     0,     0,    73,     0,     0,
       0,     0,    75,    76,    77,     0,     0,    80,    81,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,     0,
      90,     0,     0,     0,   430,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,   100,
     101,   102,   463,     0,     0,   464,     0,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   111,   433,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   122,     0,   123,     0,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     434,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   435,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   436,   437,   438,   156,   439,   440,   159,
     160,   161,   162,   163,   164,   441,   166,   442,   443,   444,
     445,   171,   172,   446,   447,   175,   448,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,     0,   188,
     189,     0,   190,   191,   192,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   462,     0,
       0,     0,     3,     0,   686,     0,     0,     0,     0,   409,
     410,     0,     7,     8,   411,    10,    11,    12,    13,   412,
     413,   414,   415,   416,   417,   418,   419,    22,   420,    24,
      25,     0,    26,    27,    28,    29,   421,    31,   422,    33,
      34,   423,    36,   424,    38,    39,   425,     0,    41,   426,
      43,   427,    45,   428,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    62,
       0,    63,    64,    65,   429,     0,     0,    69,    70,    71,
       0,     0,     0,    73,     0,     0,     0,     0,    75,    76,
      77,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,     0,    90,     0,     0,     0,
     430,    92,    93,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   433,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,   687,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   434,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   435,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   436,
     437,   438,   156,   439,   440,   159,   160,   161,   162,   163,
     164,   441,   166,   442,   443,   444,   445,   171,   172,   446,
     447,   175,   448,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,     0,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   462,     0,     0,     0,     3,     0,
       0,     0,     0,     0,     0,   409,   410,     0,     7,     8,
     411,    10,    11,    12,    13,   412,   413,   414,   415,   416,
     417,   418,   419,    22,   420,    24,    25,     0,    26,    27,
      28,    29,   421,    31,   422,    33,    34,   423,    36,   424,
      38,    39,   425,     0,    41,   426,    43,   427,    45,   428,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    62,     0,    63,    64,    65,
     429,     0,     0,    69,    70,    71,     0,     0,     0,    73,
       0,     0,     0,     0,    75,    76,    77,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   430,    92,    93,     0,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,   100,   101,   102,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   111,
     433,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   122,     0,   123,     0,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   434,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,     0,     0,   435,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   436,   437,   438,   156,   439,
     440,   159,   160,   161,   162,   163,   164,   441,   166,   442,
     443,   444,   445,   171,   172,   446,   447,   175,   448,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
       0,   188,   189,     0,   190,   191,   192,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     494,     0,     3,     0,     0,     0,     0,     0,     0,   409,
     410,     0,     7,     8,   411,    10,    11,    12,    13,   412,
     413,   414,   415,   416,   417,   418,   419,    22,   420,    24,
      25,     0,    26,    27,    28,    29,   421,    31,   422,    33,
      34,   423,    36,   424,    38,    39,   425,     0,    41,   426,
      43,   427,    45,   428,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    62,
       0,    63,    64,    65,   429,     0,     0,    69,    70,    71,
       0,     0,     0,    73,     0,     0,     0,     0,    75,    76,
      77,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,     0,    90,     0,     0,     0,
     430,    92,    93,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   433,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   434,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   435,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   436,
     437,   438,   156,   439,   440,   159,   160,   161,   162,   163,
     164,   441,   166,   442,   443,   444,   445,   171,   172,   446,
     447,   175,   448,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,     0,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     3,     0,     0,     0,     0,     0,
       0,   409,   410,     0,     7,     8,   480,    10,    11,    12,
      13,   412,    15,   481,   415,   416,   962,   418,   419,    22,
     420,    24,    25,     0,    26,    27,    28,    29,   421,    31,
     482,    33,    34,    35,    36,   424,    38,    39,   425,     0,
      41,   483,    43,   427,    45,   428,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    62,     0,    63,    64,    65,   484,     0,     0,    69,
      70,    71,     0,     0,     0,    73,     0,     0,     0,     0,
      75,    76,    77,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,   430,    92,    93,     0,     0,     0,     0,     0,
       0,     0,     0,    96,    97,    98,     0,   100,   101,   963,
       0,     0,     0,   964,     0,     0,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   111,   433,   113,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,     0,
       0,     0,   122,  1327,   123,   124,     0,     0,     0,     0,
    1328,     0,   129,     0,   130,   131,   132,   133,   434,   135,
     136,   137,   138,   139,   140,     0,     0,   965,   142,     0,
       0,   435,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   436,   154,   438,   156,   439,   440,   159,   160,   161,
     162,   163,   164,   441,   166,   442,   443,   444,   445,   171,
     172,   446,   447,   175,   448,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,     0,   188,   189,     0,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,     3,     0,     0,     0,
       0,     0,     0,   409,   410,     0,     7,     8,   480,    10,
      11,    12,    13,   412,    15,   481,   415,   416,   962,   418,
     419,    22,   420,    24,    25,     0,    26,    27,    28,    29,
     421,    31,   482,    33,    34,    35,    36,   424,    38,    39,
     425,     0,    41,   483,    43,   427,    45,   428,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    62,     0,    63,    64,    65,   484,     0,
       0,    69,    70,    71,     0,     0,     0,    73,     0,     0,
       0,     0,    75,    76,    77,     0,     0,    80,    81,  1286,
       0,     0,     0,     0,     0,    86,    87,    88,    89,     0,
      90,     0,     0,     0,   430,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,   100,
     101,   963,     0,     0,     0,   964,     0,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   111,   433,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   122,     0,   123,   124,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     434,   135,   136,   137,   138,   139,   140,     0,     0,   965,
     142,     0,     0,   435,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   436,   154,   438,   156,   439,   440,   159,
     160,   161,   162,   163,   164,   441,   166,   442,   443,   444,
     445,   171,   172,   446,   447,   175,   448,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,     0,   188,
     189,     0,   190,   191,   192,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,     3,     0,
       0,     0,     0,     0,     0,   409,   410,     0,     7,     8,
     411,    10,    11,    12,    13,   412,   413,   414,   415,   416,
     417,   418,   419,    22,   420,    24,    25,     0,    26,    27,
      28,    29,   421,    31,   422,    33,    34,   423,    36,   424,
      38,    39,   425,     0,    41,   426,    43,   427,    45,   428,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    62,     0,    63,    64,    65,
     429,     0,     0,    69,    70,    71,     0,     0,     0,    73,
       0,     0,     0,     0,    75,    76,    77,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   430,    92,    93,     0,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,   100,   101,   102,   431,     0,     0,   432,     0,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   111,
     433,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   122,     0,   123,     0,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   434,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,     0,     0,   435,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   436,   437,   438,   156,   439,
     440,   159,   160,   161,   162,   163,   164,   441,   166,   442,
     443,   444,   445,   171,   172,   446,   447,   175,   448,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
       0,   188,   189,     0,   190,   191,   192,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
       3,     0,     0,     0,     0,     0,     0,   409,   410,     0,
       7,     8,   411,    10,    11,    12,    13,   412,   413,   414,
     415,   416,   417,   418,   419,    22,   420,    24,    25,     0,
      26,    27,    28,    29,   421,    31,   422,    33,    34,   423,
      36,   424,    38,    39,   425,     0,    41,   426,    43,   427,
      45,   428,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    62,     0,    63,
      64,    65,   429,     0,     0,    69,    70,    71,     0,     0,
       0,    73,     0,     0,     0,     0,    75,    76,    77,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   430,    92,
      93,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,   100,   101,   102,   477,     0,     0,   478,
       0,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   433,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,     0,
     123,     0,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   434,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   435,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   436,   437,   438,
     156,   439,   440,   159,   160,   161,   162,   163,   164,   441,
     166,   442,   443,   444,   445,   171,   172,   446,   447,   175,
     448,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     3,     0,     0,     0,     0,     0,     0,   409,
     410,     0,     7,     8,   411,    10,    11,    12,    13,   412,
     413,   414,   415,   416,   417,   418,   419,    22,   420,    24,
      25,     0,    26,    27,    28,    29,   421,    31,   422,    33,
      34,   423,    36,   424,    38,    39,   425,     0,    41,   426,
      43,   427,    45,   428,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    62,
       0,    63,    64,    65,   429,     0,     0,    69,    70,    71,
       0,     0,     0,    73,     0,     0,     0,     0,    75,    76,
      77,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,     0,    90,     0,     0,     0,
     430,    92,    93,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   433,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,   659,   123,     0,     0,     0,     0,     0,   660,     0,
     129,     0,   130,   131,   132,   133,   434,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   435,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   436,
     437,   438,   156,   439,   440,   159,   160,   161,   162,   163,
     164,   441,   166,   442,   443,   444,   445,   171,   172,   446,
     447,   175,   448,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,     0,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     3,     0,     0,     0,     0,     0,
       0,   409,   410,     0,     7,     8,   411,    10,    11,    12,
      13,   412,   413,   414,   415,   416,   417,   418,   419,    22,
     420,    24,    25,     0,    26,    27,    28,    29,   421,    31,
     422,    33,    34,   423,    36,   424,    38,    39,   425,     0,
      41,   426,    43,   427,    45,   428,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    62,     0,    63,    64,    65,   429,     0,     0,    69,
      70,    71,     0,     0,     0,    73,     0,     0,     0,     0,
      75,    76,    77,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,   430,    92,    93,     0,     0,     0,     0,     0,
       0,     0,     0,    96,    97,    98,     0,   100,   101,   102,
       0,     0,     0,     0,     0,     0,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   111,   433,   113,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,     0,
       0,     0,   122,   704,   123,     0,     0,     0,     0,     0,
     705,     0,   129,     0,   130,   131,   132,   133,   434,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,     0,
       0,   435,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   436,   437,   438,   156,   439,   440,   159,   160,   161,
     162,   163,   164,   441,   166,   442,   443,   444,   445,   171,
     172,   446,   447,   175,   448,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,     0,   188,   189,     0,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,     3,     0,     0,     0,
       0,     0,     0,   409,   410,     0,     7,     8,   480,    10,
      11,    12,    13,   412,    15,   481,   415,   416,   962,   418,
     419,    22,   420,    24,    25,     0,    26,    27,    28,    29,
     421,    31,   482,    33,    34,    35,    36,   424,    38,    39,
     425,     0,    41,   483,    43,   427,    45,   428,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    62,     0,    63,    64,    65,   484,     0,
       0,    69,    70,    71,     0,     0,     0,    73,     0,     0,
       0,     0,    75,    76,    77,     0,     0,    80,    81,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,     0,
      90,     0,     0,     0,   430,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,   100,
     101,   963,     0,     0,     0,   964,     0,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   111,   433,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   122,     0,   123,   124,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     434,   135,   136,   137,   138,   139,   140,     0,     0,   965,
     142,     0,     0,   435,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   436,   154,   438,   156,   439,   440,   159,
     160,   161,   162,   163,   164,   441,   166,   442,   443,   444,
     445,   171,   172,   446,   447,   175,   448,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,     0,   188,
     189,     0,   190,   191,   192,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,     3,     0,
       0,     0,     0,     0,     0,   409,   410,     0,     7,     8,
     480,    10,    11,    12,    13,   412,    15,   481,   415,   416,
     962,   418,   419,    22,   420,    24,    25,     0,    26,    27,
      28,    29,   421,    31,   482,    33,    34,    35,    36,   424,
      38,    39,   425,     0,    41,   483,    43,   427,    45,   428,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    62,     0,    63,    64,    65,
     484,     0,     0,    69,    70,    71,     0,     0,     0,    73,
       0,     0,     0,     0,    75,    76,    77,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   430,    92,    93,     0,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,   100,   101,   963,     0,     0,     0,   964,     0,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   111,
     433,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   122,     0,   123,   124,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   434,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,     0,     0,   435,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   436,   154,   438,   156,   439,
     440,   159,   160,   161,   162,   163,   164,   441,   166,   442,
     443,   444,   445,   171,   172,   446,   447,   175,   448,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
       0,   188,   189,     0,   190,   191,   192,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
       3,     0,     0,     0,     0,     0,     0,   409,   410,     0,
       7,     8,   411,    10,    11,    12,    13,   412,   413,   414,
     415,   416,   417,   418,   419,    22,   420,    24,    25,     0,
      26,    27,    28,    29,   421,    31,   422,    33,    34,   423,
      36,   424,    38,    39,   425,     0,    41,   426,    43,   427,
      45,   428,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    62,     0,    63,
      64,    65,   429,     0,     0,    69,    70,    71,     0,     0,
       0,    73,     0,     0,     0,     0,    75,    76,    77,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   430,    92,
      93,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   433,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,     0,
     123,     0,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   434,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   435,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   436,   437,   438,
     156,   439,   440,   159,   160,   161,   162,   163,   164,   441,
     166,   442,   443,   444,   445,   171,   172,   446,   447,   175,
     448,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        16,   573,   116,   574,   575,   576,   577,   528,   531,   306,
     711,   784,   785,   858,   367,   890,    32,   127,   103,   770,
     924,  1160,   770,  1171,  1172,   782,   783,    68,  1313,   753,
     986,  1059,   550,   683,    49,    89,   111,    20,    47,  1247,
     553,    50,   555,   556,    21,   558,     7,   560,  1133,    87,
      66,  1222,    68,   817,    20,   568,   569,    87,   782,   783,
     613,   450,    89,     4,    87,    34,    82,     8,    86,     4,
     133,    40,   100,     8,    87,   100,    89,    37,   100,    48,
     100,    50,    20,   100,    93,   683,   100,   946,   104,    58,
      45,    60,   100,   817,   100,   133,   694,    57,   100,    68,
     116,   100,   118,    72,   138,   458,   459,   757,   124,   759,
     100,   138,   100,   502,   503,   100,   505,   506,   507,   508,
     103,    93,   111,   880,   121,   138,   515,   516,   138,   853,
     100,   157,   115,    87,   106,   104,   105,   106,   100,   216,
     529,   216,    30,   136,   221,    26,   172,    89,    36,    37,
     539,   540,   177,   181,   147,   173,   880,   140,  1017,   181,
     177,   144,    87,   177,   147,   120,    54,    87,   106,    57,
     178,   177,  1320,   114,    55,   116,   178,    65,   151,   114,
     111,   116,   181,   124,   167,   151,   174,   177,   177,   124,
     187,   160,   177,   208,   248,   249,    89,   100,   228,   309,
     964,   264,    90,   144,   165,   228,   226,   177,  1379,   144,
    1055,   600,  1297,   151,   603,   177,   149,   177,   160,   920,
    1124,  1096,   297,   192,   144,   823,   264,   204,  1256,  1133,
     264,   246,   127,   166,   243,   986,   987,   264,   986,   987,
     964,   759,  1198,  1451,   894,   176,   255,  1532,   257,   802,
     803,   264,   221,   766,   264,   209,   210,   121,   100,   268,
     269,   270,   100,   272,  1549,   274,   282,   160,   251,   383,
     224,   144,  1557,   314,   177,   873,   317,   630,  1417,    20,
      38,   879,    46,   252,   209,   210,   122,    25,   144,    53,
     404,   179,   212,   213,   167,    87,   191,    87,   314,   224,
     147,   317,   244,   245,    42,   247,    70,    89,   147,   278,
     279,   280,   281,   282,   144,   284,   285,   286,   287,   288,
     405,   263,   407,   187,   293,    89,   679,   260,   216,     8,
       9,  1088,   982,   275,   267,   177,   128,   167,  1062,   177,
      89,   133,   100,    87,   277,   181,   431,   111,   138,   160,
     464,   244,   245,  1110,   247,  1383,   372,   106,   374,   748,
     253,   144,   103,   379,  1088,   147,   755,   383,  1516,   135,
     263,   208,   457,   389,   115,   866,    37,   868,   463,    40,
     396,   192,   275,   182,   183,   470,  1110,   472,   404,   474,
      61,     8,   477,  1297,   138,    66,    99,    89,   147,   140,
     166,   110,    19,   144,   290,   144,   147,   492,   147,   246,
    1255,    72,   298,   498,   106,   118,   432,    96,   184,   127,
     147,  1178,   913,     8,   915,   149,   167,   128,   137,   950,
     819,  1459,   517,   141,    19,   114,   825,   116,    99,    46,
     111,   150,   166,   144,   460,   111,    53,  1198,   464,   149,
    1198,   467,   468,   469,  1178,   147,  1207,   473,  1486,  1207,
     149,   200,   478,     8,     9,   144,   166,  1218,   128,   148,
    1218,    39,   488,   826,   827,   184,   128,   166,   831,    46,
      88,   172,   592,   593,   144,   164,    53,     8,     9,   189,
     147,    99,   144,    40,   510,   186,   191,   114,   159,   116,
     189,   109,   518,   892,   589,   200,   185,   860,   125,   594,
     118,    58,   901,    60,   903,   904,   145,  1545,   147,  1547,
    1395,    68,    89,   172,   203,  1467,  1468,   144,   111,   114,
     919,   116,   239,   240,   216,  1563,   218,   186,   147,   139,
     125,   930,   931,   932,   814,   934,   935,   936,   937,   938,
     939,    96,   941,   942,   261,   260,   156,  1499,   828,   144,
     111,   675,   267,  1505,   678,   954,   139,    89,   254,   114,
     254,   116,   277,   144,   111,    96,   147,   662,   259,   265,
     223,   265,   225,   156,   106,   266,   216,   672,   218,   978,
     144,   980,   981,   114,  1295,   116,   128,   147,  1299,   144,
     216,   133,   618,   148,   689,   621,   144,  1358,   595,   625,
    1358,   598,   206,   223,   601,   225,   701,   702,  1007,   164,
       8,     9,   707,   144,   160,   144,   111,   148,   147,   645,
     646,   647,   268,   269,   270,   144,  1025,  1209,   274,   128,
     185,   316,   233,   164,   133,   371,   321,   373,   733,   233,
     666,   147,   668,   291,   292,    33,   192,   234,   203,   675,
     144,    39,   678,     0,   185,  1422,    44,  1424,   212,   213,
     214,   119,   120,   111,    52,   181,   282,   283,   119,   120,
     571,   572,   203,   181,  1073,   221,    64,  1370,  1371,  1078,
     158,   988,    85,   241,   710,   578,   579,    43,  1422,   190,
    1424,  1090,   580,   581,  1405,    94,  1463,  1408,    96,    95,
     145,  1100,  1101,  1236,  1487,    20,    40,    40,    40,   143,
    1109,  1478,   238,   284,   111,   289,   114,   289,   116,   294,
     746,   177,   144,   275,   275,   111,   144,   753,  1091,  1463,
     111,   144,   278,   279,   280,   281,   282,   177,   284,   285,
     286,   287,   288,   144,  1478,   147,   144,   147,   177,   144,
     148,   144,    27,   147,    15,   147,   782,   783,   784,   785,
    1471,  1342,   147,   177,  1163,   204,   164,  1349,  1350,    20,
     177,   159,   222,    25,   162,  1174,   111,   159,   161,   100,
      28,    29,   161,    31,    32,    65,    34,   185,   176,   222,
    1189,   817,    40,  1192,    87,  1194,    87,    87,   140,   100,
      48,   100,    50,    51,  1167,   203,    20,   833,   151,   118,
      58,   151,    60,   908,   202,   123,   290,   238,   123,   174,
      68,   174,    87,   177,    72,   177,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,   174,   174,   177,    89,
     866,    37,   868,    89,   100,   174,   177,  1429,  1430,   177,
     177,   123,   133,   177,   880,   174,   104,   105,   106,   131,
     132,   144,   134,   174,   174,    87,   228,  1266,   174,   133,
     142,   174,   216,  1272,   146,   177,   148,   174,   111,   161,
     111,   153,  1281,   181,   111,   111,   174,   913,   175,   915,
     985,   123,   133,   138,    87,   133,    20,   169,   218,  1481,
     277,   290,   144,   151,  1303,  1304,  1305,  1306,  1307,   111,
    1309,  1310,   160,  1276,   174,    87,   246,   174,   188,   123,
    1015,   193,   194,   195,   196,   197,   198,   151,   123,    89,
     111,   144,   958,   133,   174,   961,   111,  1336,   964,   138,
      93,   144,    27,    20,   192,   174,   174,   111,   237,   975,
     144,   977,   111,   174,   174,    72,   100,   100,   147,   147,
     147,  1324,   138,   211,   138,   250,   258,   251,   135,   276,
      20,  1066,    20,   221,    20,   228,   181,   277,   296,   218,
     177,   218,   278,   218,   135,   177,   177,   177,   138,   111,
     111,    70,   100,   133,   174,  1394,   123,     6,   177,   177,
     133,  1400,    99,  1402,   252,   224,   224,   224,  1103,   224,
     181,   176,   228,    99,   177,   177,   177,   174,   138,   177,
     138,  1116,   277,    20,   273,   174,    71,    20,   262,    89,
     278,   279,   280,   281,   282,   242,   284,   285,   286,   287,
     288,   242,   161,   249,   174,   293,   117,    89,   174,    87,
     144,   176,    20,  1079,   177,   278,   100,   161,   174,   174,
     174,   271,  1088,    46,   177,    87,    87,    20,   111,   100,
     256,    87,  1098,   176,   111,   187,   111,   216,   187,   174,
    1106,   187,   111,   295,  1110,   216,   176,    86,   187,   173,
     144,   111,   111,   111,   177,   241,  1495,   295,   189,   284,
     111,   278,   238,   235,  1130,   216,   629,   527,   527,   238,
    1021,   295,   818,   296,   296,   381,  1062,  1459,  1517,  1486,
     881,   400,  1156,  1522,   961,  1151,   296,   281,   878,  1098,
     456,  1270,   242,   377,  1160,  1164,  1080,  1176,  1164,   954,
    1171,   551,   488,  1542,  1106,  1111,   552,   302,   603,  1124,
    1505,  1499,  1178,  1174,   785,   711,  1056,  1020,  1207,   868,
    1151,  1218,  1358,   987,  1211,   408,  1355,  1161,   996,   852,
    1045,  1245,   408,  1373,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1208,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1253,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1267,  1268,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1286,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1296,    -1,    -1,    -1,  1300,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1439,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1401,    -1,    -1,    -1,    -1,
    1406,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1417,    -1,    -1,    -1,    -1,  1422,    -1,  1424,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1455,
      -1,    -1,  1458,    -1,    -1,    -1,    -1,  1463,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1474,    -1,
      -1,    -1,  1478,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1487,    -1,  1489,    -1,    -1,    -1,  1493,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1519,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1537,    -1,  1539,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    -1,    -1,    -1,    -1,  1552,    -1,    17,    18,
    1556,    20,    -1,    -1,    -1,  1561,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    -1,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    -1,    -1,    98,
      99,    -1,    -1,    -1,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    -1,   115,    -1,   117,   118,
     119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,   166,   167,    -1,
      -1,   170,   171,   172,    -1,    -1,    -1,   176,    -1,   178,
     179,   180,    -1,   182,   183,   184,    -1,   186,    -1,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
      -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,   115,    -1,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,   166,   167,
      -1,    -1,   170,   171,   172,    -1,    -1,    -1,   176,   177,
     178,   179,   180,    -1,   182,   183,   184,    -1,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,    -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,   115,    -1,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,   166,   167,
      -1,    -1,   170,   171,   172,    -1,   174,    -1,   176,    -1,
     178,   179,   180,    -1,   182,   183,   184,    -1,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,    -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,   115,    -1,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,   166,   167,
      -1,    -1,   170,   171,   172,    -1,    -1,    -1,   176,   177,
     178,   179,   180,    -1,   182,   183,   184,    -1,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,    -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,   115,    -1,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,   166,   167,
      -1,    -1,   170,   171,   172,    -1,    -1,    -1,   176,   177,
     178,   179,   180,    -1,   182,   183,   184,    -1,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,    -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,   115,    -1,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,   166,   167,
      -1,    -1,   170,   171,   172,    -1,   174,    -1,   176,    -1,
     178,   179,   180,    -1,   182,   183,   184,    -1,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,    -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,   115,    -1,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,   166,   167,
      -1,    -1,   170,   171,   172,    -1,   174,    -1,   176,    -1,
     178,   179,   180,    -1,   182,   183,   184,    -1,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,    -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,   115,    -1,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,   166,   167,
      -1,    -1,   170,   171,   172,    -1,   174,    -1,   176,    -1,
     178,   179,   180,    -1,   182,   183,   184,    -1,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,    -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,   115,    -1,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,   166,   167,
      -1,    -1,   170,   171,   172,    -1,   174,    -1,   176,    -1,
     178,   179,   180,    -1,   182,   183,   184,    -1,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,    -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,   115,    -1,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,   166,   167,
      -1,    -1,   170,   171,   172,    -1,   174,    -1,   176,    -1,
     178,   179,   180,    -1,   182,   183,   184,    -1,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,    -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,   115,    -1,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,   166,   167,
      -1,    -1,   170,   171,   172,    -1,   174,    -1,   176,    -1,
     178,   179,   180,    -1,   182,   183,   184,    -1,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,    -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,   115,    -1,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,   166,   167,
      -1,    -1,   170,   171,   172,    -1,    -1,    -1,   176,    -1,
     178,   179,   180,    -1,   182,   183,   184,    -1,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,    -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,   115,    -1,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,   166,   167,
      -1,    -1,   170,   171,   172,    -1,    -1,    -1,   176,    -1,
     178,   179,   180,    -1,   182,   183,   184,    -1,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,    -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,   115,    -1,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,   166,   167,
      -1,    -1,   170,   171,   172,    -1,    -1,    -1,   176,    -1,
     178,   179,   180,    -1,   182,   183,   184,    -1,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,    -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,   115,    -1,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,   166,   167,
      -1,    -1,   170,   171,   172,    -1,    -1,    -1,   176,    -1,
     178,   179,   180,    -1,   182,   183,   184,    -1,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,    -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,   115,    -1,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,   166,   167,
      -1,    -1,   170,   171,   172,    -1,    -1,    -1,   176,    -1,
     178,   179,   180,    -1,   182,   183,   184,    -1,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,    -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,   115,    -1,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,   166,   167,
      -1,    -1,   170,   171,   172,    -1,    -1,    -1,   176,    -1,
     178,   179,   180,    -1,   182,   183,   184,    -1,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,    -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,   115,    -1,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,   147,
     148,    -1,   150,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,    -1,   170,   171,   172,    -1,    -1,    -1,   176,    -1,
     178,   179,   180,    -1,   182,   183,   184,    -1,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,    -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,   115,    -1,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,   147,
     148,    -1,   150,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,    -1,   170,   171,   172,    -1,    -1,    -1,   176,    -1,
     178,   179,   180,    -1,    -1,    -1,   184,    -1,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,    -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    -1,    -1,    85,    -1,    87,
      88,    89,    90,    -1,    -1,    93,    94,    95,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,   104,   105,   106,    -1,
      -1,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,    -1,   141,   142,   143,    -1,    -1,    -1,    -1,
      -1,    -1,   150,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,   176,    -1,
     178,   179,    -1,    -1,    -1,    -1,   184,    -1,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,    -1,    -1,   201,   202,    -1,    -1,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    -1,    -1,    85,    -1,    87,
      88,    89,    90,    -1,    -1,    93,    94,    95,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,   104,   105,   106,    -1,
      -1,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,    -1,   141,   142,   143,    -1,    -1,    -1,    -1,
      -1,    -1,   150,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,   176,    -1,
     178,    -1,    -1,    -1,    -1,    -1,   184,    -1,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,    -1,    -1,   201,   202,    -1,    -1,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    -1,    -1,    85,    -1,    87,    88,    89,    90,    -1,
      -1,    93,    94,    95,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,   104,   105,   106,    -1,    -1,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,    -1,
     122,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   137,   138,   139,    -1,   141,
     142,   143,   144,    -1,    -1,   147,    -1,    -1,   150,   151,
      -1,    -1,    -1,    -1,   156,   157,   158,   159,   160,   161,
     162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,    -1,    -1,    -1,   176,    -1,   178,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   186,    -1,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,    -1,    -1,   201,
     202,    -1,    -1,   205,   206,    -1,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,    14,    -1,
      -1,    -1,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    -1,    -1,    85,
      -1,    87,    88,    89,    90,    -1,    -1,    93,    94,    95,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,   104,   105,
     106,    -1,    -1,   109,   110,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,
     126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   137,   138,   139,    -1,   141,   142,   143,    -1,    -1,
      -1,    -1,    -1,    -1,   150,   151,    -1,    -1,    -1,    -1,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,
     176,   177,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,    -1,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,    -1,    -1,   201,   202,    -1,    -1,   205,
     206,    -1,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,    -1,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,    14,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    -1,    -1,    85,    -1,    87,    88,    89,
      90,    -1,    -1,    93,    94,    95,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,   104,   105,   106,    -1,    -1,   109,
     110,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,
     120,    -1,   122,    -1,    -1,    -1,   126,   127,   128,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,
      -1,   141,   142,   143,    -1,    -1,    -1,    -1,    -1,    -1,
     150,   151,    -1,    -1,    -1,    -1,   156,   157,   158,   159,
     160,   161,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   172,    -1,    -1,    -1,   176,    -1,   178,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,    -1,
      -1,   201,   202,    -1,    -1,   205,   206,    -1,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
      16,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    -1,    -1,    85,
      -1,    87,    88,    89,    90,    -1,    -1,    93,    94,    95,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,   104,   105,
     106,    -1,    -1,   109,   110,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,
     126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   137,   138,   139,    -1,   141,   142,   143,    -1,    -1,
      -1,    -1,    -1,    -1,   150,   151,    -1,    -1,    -1,    -1,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,
     176,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,    -1,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,    -1,    -1,   201,   202,    -1,    -1,   205,
     206,    -1,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,    -1,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    -1,
      -1,    85,    -1,    87,    88,    89,    90,    -1,    -1,    93,
      94,    95,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
     104,   105,   106,    -1,    -1,   109,   110,    -1,    -1,    -1,
      -1,    -1,    -1,   117,   118,   119,   120,    -1,   122,    -1,
      -1,    -1,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   138,   139,    -1,   141,   142,   143,
      -1,    -1,    -1,   147,    -1,    -1,   150,   151,    -1,    -1,
      -1,    -1,   156,   157,   158,   159,   160,   161,   162,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,    -1,
      -1,    -1,   176,   177,   178,   179,    -1,    -1,    -1,    -1,
     184,    -1,   186,    -1,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,    -1,    -1,   201,   202,    -1,
      -1,   205,   206,    -1,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,    -1,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    -1,    -1,    85,    -1,    87,    88,    89,    90,    -1,
      -1,    93,    94,    95,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,   104,   105,   106,    -1,    -1,   109,   110,   111,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,    -1,
     122,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   137,   138,   139,    -1,   141,
     142,   143,    -1,    -1,    -1,   147,    -1,    -1,   150,   151,
      -1,    -1,    -1,    -1,   156,   157,   158,   159,   160,   161,
     162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,    -1,    -1,    -1,   176,    -1,   178,   179,    -1,    -1,
      -1,    -1,    -1,    -1,   186,    -1,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,    -1,    -1,   201,
     202,    -1,    -1,   205,   206,    -1,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    -1,    -1,    85,    -1,    87,    88,    89,
      90,    -1,    -1,    93,    94,    95,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,   104,   105,   106,    -1,    -1,   109,
     110,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,
     120,    -1,   122,    -1,    -1,    -1,   126,   127,   128,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,
      -1,   141,   142,   143,   144,    -1,    -1,   147,    -1,    -1,
     150,   151,    -1,    -1,    -1,    -1,   156,   157,   158,   159,
     160,   161,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   172,    -1,    -1,    -1,   176,    -1,   178,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,    -1,
      -1,   201,   202,    -1,    -1,   205,   206,    -1,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    -1,    -1,    85,    -1,    87,
      88,    89,    90,    -1,    -1,    93,    94,    95,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,   104,   105,   106,    -1,
      -1,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,    -1,   141,   142,   143,   144,    -1,    -1,   147,
      -1,    -1,   150,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,   176,    -1,
     178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,    -1,    -1,   201,   202,    -1,    -1,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    -1,    -1,    85,
      -1,    87,    88,    89,    90,    -1,    -1,    93,    94,    95,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,   104,   105,
     106,    -1,    -1,   109,   110,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,
     126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   137,   138,   139,    -1,   141,   142,   143,    -1,    -1,
      -1,    -1,    -1,    -1,   150,   151,    -1,    -1,    -1,    -1,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,
     176,   177,   178,    -1,    -1,    -1,    -1,    -1,   184,    -1,
     186,    -1,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,    -1,    -1,   201,   202,    -1,    -1,   205,
     206,    -1,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,    -1,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    -1,
      -1,    85,    -1,    87,    88,    89,    90,    -1,    -1,    93,
      94,    95,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
     104,   105,   106,    -1,    -1,   109,   110,    -1,    -1,    -1,
      -1,    -1,    -1,   117,   118,   119,   120,    -1,   122,    -1,
      -1,    -1,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   138,   139,    -1,   141,   142,   143,
      -1,    -1,    -1,    -1,    -1,    -1,   150,   151,    -1,    -1,
      -1,    -1,   156,   157,   158,   159,   160,   161,   162,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,    -1,
      -1,    -1,   176,   177,   178,    -1,    -1,    -1,    -1,    -1,
     184,    -1,   186,    -1,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,    -1,    -1,   201,   202,    -1,
      -1,   205,   206,    -1,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,    -1,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    -1,    -1,    85,    -1,    87,    88,    89,    90,    -1,
      -1,    93,    94,    95,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,   104,   105,   106,    -1,    -1,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,    -1,
     122,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   137,   138,   139,    -1,   141,
     142,   143,    -1,    -1,    -1,   147,    -1,    -1,   150,   151,
      -1,    -1,    -1,    -1,   156,   157,   158,   159,   160,   161,
     162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,    -1,    -1,    -1,   176,    -1,   178,   179,    -1,    -1,
      -1,    -1,    -1,    -1,   186,    -1,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,    -1,    -1,   201,
     202,    -1,    -1,   205,   206,    -1,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    -1,    -1,    85,    -1,    87,    88,    89,
      90,    -1,    -1,    93,    94,    95,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,   104,   105,   106,    -1,    -1,   109,
     110,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,
     120,    -1,   122,    -1,    -1,    -1,   126,   127,   128,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,
      -1,   141,   142,   143,    -1,    -1,    -1,   147,    -1,    -1,
     150,   151,    -1,    -1,    -1,    -1,   156,   157,   158,   159,
     160,   161,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   172,    -1,    -1,    -1,   176,    -1,   178,   179,
      -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,    -1,
      -1,   201,   202,    -1,    -1,   205,   206,    -1,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    -1,    -1,    85,    -1,    87,
      88,    89,    90,    -1,    -1,    93,    94,    95,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,   104,   105,   106,    -1,
      -1,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,    -1,   141,   142,   143,    -1,    -1,    -1,    -1,
      -1,    -1,   150,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,   176,    -1,
     178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,    -1,    -1,   201,   202,    -1,    -1,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299
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
     242,   243,   244,   245,   246,   247,   248,   249,   251,   252,
     254,   255,   256,   257,   258,   259,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   345,   346,   351,   354,   357,   360,   361,   363,   368,
     369,   370,   371,   372,   381,   382,   384,   385,   386,   391,
     393,   395,   396,   397,   402,   423,   426,   429,   430,   431,
     432,   434,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   480,   481,   482,   496,   497,   499,   500,   501,   502,
     503,   504,   505,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   525,   526,   527,   528,   533,   534,   535,
     536,   537,   538,   541,   547,   548,   549,    28,    29,    31,
      32,    34,    40,    48,    50,    51,    58,    60,    68,    72,
     104,   105,   106,   151,   160,   192,   211,   221,   252,   278,
     279,   280,   281,   282,   284,   285,   286,   287,   288,   293,
     352,   353,   373,   374,   151,   144,   147,   144,   147,    25,
      26,    30,    35,    36,    37,    38,    39,    40,    41,    42,
      44,    52,    54,    57,    59,    62,    65,    67,    69,    90,
     126,   144,   147,   160,   192,   205,   215,   216,   217,   219,
     220,   227,   229,   230,   231,   232,   235,   236,   238,   547,
     144,    61,    66,   111,   388,   147,   362,   147,    26,    55,
     111,    39,    14,   144,   147,   546,   547,   147,   111,   111,
     144,   147,   147,    87,   144,   212,   213,   144,   147,   547,
      30,    37,    54,    65,    90,   464,   547,   547,   111,   177,
     382,   547,   144,   546,    16,   547,   547,   456,   144,    21,
     204,   206,   216,   218,   147,   216,   218,   216,   216,   221,
     111,   144,   364,   233,   233,   234,   147,   144,   111,   316,
       0,   318,   319,    25,    42,   321,   381,   181,   181,   100,
     181,   383,    33,    39,    44,    52,    64,   159,   162,   176,
     202,   387,   392,   393,   394,   411,   412,   416,   398,   399,
     547,   158,    85,   123,   131,   132,   134,   142,   146,   148,
     153,   169,   193,   194,   195,   196,   197,   198,   448,   449,
     241,   149,   166,   189,   110,   137,   150,   184,   191,   200,
     127,   141,    43,   190,    94,    95,   149,   166,   447,   144,
     453,   456,   182,   183,   145,   468,   469,   464,   468,   464,
     147,   468,   136,   147,    20,   545,   172,   186,   172,   186,
     157,   172,   373,   547,   373,   547,   160,   192,    40,   375,
     374,    40,   376,   547,   143,   111,   350,    37,    40,    72,
      99,   159,   546,   212,   213,   214,   291,   292,   238,   576,
     547,   284,   547,   289,   289,   294,   278,   286,   353,   546,
     382,   177,   382,    37,    57,   177,   521,   522,   382,   177,
     184,   547,   144,   385,   275,   275,   111,   406,   111,   177,
     377,   378,   144,   379,   382,   151,   545,   106,   151,   344,
     545,   403,   405,   547,   111,   382,    20,   177,   546,   144,
     547,   547,   424,   425,   547,   382,   177,   382,   523,   547,
     382,   144,   144,   382,   177,   184,   547,   144,   424,   177,
      27,   484,   485,   486,   382,     7,   165,    15,   177,   382,
     204,    20,   385,   385,   177,   385,   385,   385,   385,   222,
     539,   540,   547,   365,   385,   385,   382,   404,   410,   547,
     323,   324,    25,   325,   385,   384,   111,   159,   161,   161,
     385,   385,   100,    87,    89,   138,   264,   400,   401,   507,
     431,   432,   434,   434,   434,   434,   433,   434,   434,   434,
      65,   438,   438,   437,   439,   439,   439,   439,   440,   440,
     441,   441,   222,    87,    87,    87,   174,   382,   456,   456,
     382,   469,   177,   385,   479,   140,   177,   479,   100,   100,
     362,    20,   547,   547,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,   327,   328,   329,    87,   128,   133,
     347,   348,   349,   547,   128,   133,   151,   151,   327,   545,
     118,   123,    47,    50,    93,   243,   255,   257,   268,   269,
     270,   272,   274,   577,   578,   579,   580,   581,   582,   589,
     595,   596,   238,    87,   228,   356,   290,   547,   547,   547,
     123,   174,   174,   177,   177,   174,   100,   177,   100,   177,
     174,   382,   174,   547,    49,   208,   246,   389,   390,   547,
      87,   100,   177,   382,   177,   546,    89,    37,   546,   545,
      89,   100,   133,   401,   507,   174,   177,   177,   174,   382,
     177,   133,   100,   178,   138,   507,   174,   177,   144,   174,
     382,   382,   174,   100,   177,   100,   177,   174,   382,   178,
     547,   485,   486,   121,   187,   174,   174,   122,   181,    87,
     209,   210,   224,    87,   209,   210,   224,    87,   228,   216,
     100,   226,   133,    25,   366,   382,   177,   174,    38,   100,
     181,   106,   181,   547,   161,   385,   417,   418,   111,   413,
     414,   111,    40,   143,   147,   201,   508,   510,   512,   513,
     529,   530,   531,   532,   547,   111,   385,   111,   138,   401,
     138,   138,   400,   401,   434,   144,   147,   251,   452,   471,
     550,   553,   554,   555,   556,   557,   561,   563,   565,   566,
     508,   508,   506,   512,   506,   174,   175,   100,   177,   177,
     139,   156,   139,   156,   128,   144,   380,   362,   362,   328,
     123,   510,   349,   385,   507,   133,   385,   545,   545,   119,
     120,   545,   268,   269,   270,   274,   547,   254,   265,   254,
     265,    20,   277,    89,   106,   147,   583,   586,   577,    30,
      36,    54,    65,    90,   216,   355,   513,   282,   283,   218,
     290,   298,    87,   356,   290,   545,   144,   523,   524,   547,
     523,   524,   174,   138,   507,   246,    46,    53,    70,   111,
     400,   407,   408,   409,   390,   507,   508,   378,    87,   174,
     188,   123,   343,   545,   151,   123,    89,   343,   111,   385,
     133,   133,   401,   144,   174,   385,   111,   385,   385,   138,
      93,   427,   428,   382,   174,   174,   144,   523,   523,   174,
     385,    27,   486,   121,   187,     8,     9,    96,   114,   116,
     185,   379,   481,   483,   494,   495,   498,    20,   223,   225,
     385,   385,   385,   223,   225,   385,   385,   385,   385,   385,
     385,   111,   385,   385,   350,   367,   100,   181,   174,   364,
     237,   542,   543,   144,   111,   417,    88,    99,   109,   118,
     419,   420,   421,   422,   100,   547,   100,   399,   147,   147,
     510,   147,   135,   166,   184,   509,   547,   547,   385,   138,
     385,   385,   138,   401,   138,   382,   550,   557,   144,   276,
     435,   602,    89,   160,   244,   245,   247,   253,   263,   275,
     551,   552,   571,   572,   573,   574,   597,   600,   250,   251,
     558,   576,   258,   562,   598,   239,   240,   261,   567,   568,
     135,   385,   382,   128,   364,   128,   144,   525,   348,   385,
     277,    20,    89,   106,   147,   590,    20,   583,   356,   509,
     218,   218,   454,   278,   296,   355,   218,   181,   174,   382,
     177,   177,   135,   177,   177,   385,   138,   111,   111,   385,
     547,   409,    70,   508,   385,   545,   100,   343,   405,   385,
     385,   133,   174,   382,   425,   385,   111,   508,   106,   428,
     174,   174,   382,   177,   177,   123,   185,   483,     6,   547,
     185,   494,   181,   224,   224,   224,   224,   228,   540,   176,
     133,   367,   465,   544,   543,   385,   410,   545,   119,   120,
     421,   422,   422,   418,    99,   415,   414,   177,   184,   508,
     511,   177,   177,   177,   385,   385,   138,   385,   174,   177,
     550,   564,   242,   208,   246,   259,   266,   601,    89,   248,
     249,   599,   242,   554,   601,   437,   571,   555,   138,   273,
     559,   560,   599,   277,   570,    71,   569,   174,   384,    20,
     127,   191,   592,   593,   594,    20,   591,   592,   262,   587,
     584,   585,   586,   161,   547,   249,   356,   454,   174,   385,
     547,   547,   408,   385,   117,    89,   545,   385,   174,   547,
     176,   111,   176,   174,   486,   547,   185,   486,   547,   385,
     385,   385,   385,   385,   385,   385,   147,   200,   380,   174,
     422,   545,    87,   177,   100,   177,   385,   174,   439,    45,
     120,   437,   437,   260,   267,   277,   575,   575,   556,   144,
     271,   174,   590,   590,   594,   100,   177,    20,   588,   599,
     177,   100,   358,   359,   454,   111,   216,   297,   278,   161,
      46,   385,   343,    87,   385,   547,   385,    86,   173,   487,
     486,   547,   187,   486,   111,   465,   508,   508,    87,   437,
     437,   189,   382,    20,   256,   586,   100,    87,   547,   111,
     216,   547,   358,   111,   508,   176,     4,   124,   490,   491,
     493,   495,    19,   125,   488,   489,   492,   495,   187,   486,
     187,   547,   508,   437,   174,   359,   512,   295,   547,   111,
     216,   547,   176,   385,    86,   124,   493,   173,   125,   492,
     187,   100,   177,   422,   385,   295,   547,   111,   385,   111,
     380,   284,   295,   547,   547,   296,   385,   296,   100,   177,
     454,   454,   111,   380,   189,   547,   278,   177,   547,   380,
     216,   111,   547,   296,   454
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
     565,   566,   567,   568
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   314,   315,   315,   316,   316,   316,   316,   317,   317,
     318,   318,   319,   319,   320,   321,   321,   321,   322,   322,
     323,   323,   324,   324,   324,   324,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   326,   326,   327,   327,   328,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     330,   330,   330,   330,   330,   330,   330,   330,   331,   331,
     332,   333,   333,   334,   334,   335,   336,   337,   337,   338,
     338,   339,   339,   339,   339,   340,   341,   342,   342,   342,
     342,   343,   343,   344,   344,   345,   345,   345,   345,   346,
     347,   347,   348,   348,   348,   349,   350,   350,   351,   351,
     351,   352,   352,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   354,   354,   354,   354,   354,
     354,   354,   354,   355,   355,   356,   356,   357,   357,   358,
     358,   359,   359,   360,   360,   360,   360,   361,   361,   362,
     362,   362,   362,   363,   364,   365,   365,   366,   366,   367,
     367,   368,   369,   370,   371,   371,   372,   372,   372,   373,
     373,   373,   373,   374,   374,   375,   375,   376,   376,   377,
     377,   378,   378,   379,   380,   381,   382,   382,   383,   383,
     384,   384,   385,   385,   385,   385,   385,   385,   385,   385,
     385,   385,   385,   385,   385,   385,   385,   385,   385,   386,
     387,   388,   388,   389,   389,   389,   390,   390,   391,   391,
     392,   393,   393,   393,   394,   394,   394,   394,   394,   395,
     395,   396,   396,   397,   398,   398,   399,   399,   399,   399,
     399,   399,   399,   399,   400,   401,   402,   403,   403,   404,
     404,   405,   405,   405,   405,   406,   406,   407,   407,   407,
     408,   408,   408,   409,   409,   409,   410,   411,   412,   413,
     413,   414,   414,   415,   416,   416,   417,   417,   418,   418,
     419,   419,   419,   419,   419,   419,   419,   420,   420,   421,
     421,   422,   423,   423,   424,   424,   425,   425,   426,   426,
     427,   427,   428,   428,   429,   430,   430,   431,   431,   432,
     432,   432,   432,   432,   433,   432,   432,   432,   432,   434,
     434,   435,   435,   436,   436,   437,   437,   437,   438,   438,
     438,   438,   438,   439,   439,   439,   440,   440,   440,   441,
     441,   442,   442,   443,   443,   444,   444,   445,   445,   446,
     446,   446,   446,   447,   447,   447,   448,   448,   448,   448,
     448,   448,   449,   449,   449,   450,   450,   450,   450,   451,
     451,   452,   452,   453,   453,   454,   454,   454,   454,   455,
     456,   456,   456,   457,   457,   458,   458,   458,   458,   459,
     459,   460,   460,   460,   460,   460,   460,   460,   461,   461,
     462,   462,   463,   463,   463,   463,   463,   464,   464,   465,
     465,   466,   466,   466,   467,   467,   467,   467,   468,   468,
     469,   470,   470,   470,   470,   470,   470,   470,   470,   470,
     471,   471,   472,   472,   472,   473,   474,   474,   475,   476,
     477,   478,   478,   479,   479,   480,   480,   481,   481,   481,
     482,   482,   482,   482,   482,   482,   483,   483,   484,   484,
     485,   486,   486,   487,   487,   488,   488,   489,   489,   489,
     489,   490,   490,   491,   491,   491,   491,   492,   492,   493,
     493,   494,   494,   494,   494,   495,   495,   495,   495,   496,
     496,   497,   497,   498,   499,   499,   499,   499,   499,   499,
     500,   501,   501,   501,   501,   502,   502,   502,   502,   503,
     504,   505,   505,   505,   505,   506,   506,   507,   508,   508,
     508,   509,   509,   509,   510,   510,   510,   510,   510,   511,
     511,   512,   513,   513,   513,   513,   513,   513,   513,   513,
     513,   514,   515,   515,   515,   516,   517,   518,   518,   518,
     519,   519,   519,   519,   519,   520,   521,   521,   521,   521,
     521,   521,   521,   522,   523,   524,   525,   526,   526,   527,
     528,   529,   529,   530,   531,   531,   532,   533,   533,   533,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     535,   535,   536,   536,   537,   538,   539,   539,   540,   541,
     542,   542,   543,   543,   543,   543,   544,   544,   545,   546,
     546,   547,   547,   548,   548,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   550,   551,   551,   552,   552,
     553,   553,   554,   554,   555,   555,   556,   556,   557,   558,
     558,   559,   559,   560,   561,   561,   561,   562,   562,   563,
     564,   564,   565,   566,   566,   567,   567,   568,   568,   568,
     569,   569,   570,   570,   571,   571,   571,   571,   571,   572,
     573,   574,   575,   575,   575,   576,   576,   577,   577,   577,
     577,   577,   577,   577,   577,   578,   578,   578,   578,   579,
     579,   580,   581,   581,   582,   582,   582,   583,   583,   584,
     584,   585,   585,   586,   587,   587,   588,   588,   589,   589,
     589,   590,   590,   591,   591,   592,   592,   593,   593,   594,
     594,   595,   596,   596,   597,   597,   597,   598,   599,   599,
     599,   599,   600,   600,   601,   601,   602
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
       5,     0,     1,     1,     3,     1,     3,     3,     1,     3,
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
       1,     1,     3,     4,     0,     2,     0,     2,     4,     4,
       3,     2,     3,     1,     3,     0,     1,     1,     2,     2,
       2,     2,     1,     2,     2,     2,     2,     3,     2,     3,
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
  "\"'any'\"", "\"'contains'\"", "\"'content'\"", "\"'diacritics'\"",
  "\"'different'\"", "\"'distance'\"", "\"'end'\"", "\"'entire'\"",
  "\"'exactly'\"", "\"'from'\"", "\"'ftand'\"", "\"'not'\"",
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
  "\"'BOM_UTF8'\"", "RANGE_REDUCE", "ADDITIVE_REDUCE",
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
       315,     0,    -1,   316,    -1,   300,   316,    -1,   318,    -1,
     317,   318,    -1,   319,    -1,   317,   319,    -1,   205,   206,
      20,   181,    -1,   205,   206,    20,   122,    20,   181,    -1,
     321,   381,    -1,   381,    -1,   320,    -1,   320,   321,    -1,
      26,   151,   546,   123,   545,   181,    -1,   322,   181,    -1,
     323,   181,    -1,   322,   181,   323,   181,    -1,   324,    -1,
     322,   181,   324,    -1,   325,    -1,   323,   181,   325,    -1,
     330,    -1,   331,    -1,   332,    -1,   334,    -1,   351,    -1,
     354,    -1,   346,    -1,   326,    -1,   336,    -1,   372,    -1,
     357,    -1,   360,    -1,   335,    -1,    25,   106,    72,   327,
      -1,    25,    72,   547,   327,    -1,   328,    -1,   327,   328,
      -1,   329,   123,   525,    -1,    73,    -1,    81,    -1,    74,
      -1,    75,    -1,    76,    -1,    77,    -1,    82,    -1,    78,
      -1,    79,    -1,    80,    -1,   333,    -1,   340,    -1,   341,
      -1,   361,    -1,   337,    -1,   338,    -1,   339,    -1,   533,
      -1,   342,    -1,   345,    -1,    25,   151,   546,   123,   545,
      -1,    25,    29,   172,    -1,    25,    29,   186,    -1,    25,
     106,    37,   151,   545,    -1,    25,   106,    40,   151,   545,
      -1,    25,    50,   547,    20,    -1,    25,   252,   576,    -1,
      25,    51,   160,    -1,    25,    51,   192,    -1,    25,   106,
     159,   118,   119,    -1,    25,   106,   159,   118,   120,    -1,
      25,    32,   172,   100,   139,    -1,    25,    32,   172,   100,
     156,    -1,    25,    32,   157,   100,   139,    -1,    25,    32,
     157,   100,   156,    -1,    25,   106,    99,   545,    -1,    25,
      28,   545,    -1,    42,    55,   545,    -1,    42,    55,   344,
     545,    -1,    42,    55,   545,    89,   343,    -1,    42,    55,
     344,   545,    89,   343,    -1,   545,    -1,   343,   100,   545,
      -1,   151,   546,   123,    -1,   106,    37,   151,    -1,    42,
      26,   545,    -1,    42,    26,   151,   546,   123,   545,    -1,
      42,    26,   545,    89,   343,    -1,    42,    26,   151,   546,
     123,   545,    89,   343,    -1,    25,   104,   143,   347,    -1,
      87,   510,   348,    -1,   348,    -1,   349,    -1,   128,    -1,
     128,   349,    -1,   133,   385,    -1,   111,   547,    -1,   111,
     547,   507,    -1,    25,   105,   350,   133,   385,    -1,    25,
     105,   350,   128,    -1,    25,   105,   350,   128,   133,   385,
      -1,   353,    -1,   352,   353,    -1,   279,    -1,   280,    -1,
     281,    -1,   282,    -1,   160,    -1,   192,    -1,   221,   292,
      -1,   221,   291,    -1,   284,    -1,   285,   284,    -1,   288,
     289,    -1,   287,   289,    -1,    25,   278,   547,    -1,    25,
     278,   547,   356,    -1,    25,   278,   547,    87,   355,    -1,
      25,   278,   547,    87,   355,   356,    -1,    25,   352,   278,
     547,    -1,    25,   352,   278,   547,   356,    -1,    25,   352,
     278,   547,    87,   355,    -1,    25,   352,   278,   547,    87,
     355,   356,    -1,   513,    -1,   513,   509,    -1,   228,   283,
     218,    -1,   228,   282,   218,    -1,    25,   286,   547,   290,
     218,   454,   161,   358,    -1,    25,   352,   286,   547,   290,
     218,   454,   161,   358,    -1,   359,    -1,   358,   100,   359,
      -1,   454,    87,   512,    -1,   454,    87,   512,   422,    -1,
      25,   293,   294,   547,   290,   278,   547,   111,   547,   295,
     385,    -1,    25,   293,   294,   547,   290,   278,   547,   216,
     111,   547,   295,   284,   296,   454,    -1,    25,   293,   294,
     547,   290,   278,   547,   297,   216,   111,   547,   295,   385,
      -1,    25,   293,   294,   547,   298,   296,   249,   278,   547,
     216,   111,   547,   296,   454,   189,   278,   547,   216,   111,
     547,   296,   454,    -1,    25,    31,   172,    -1,    25,    31,
     186,    -1,   147,   177,    -1,   147,   377,   177,    -1,   147,
     177,    87,   508,    -1,   147,   377,   177,    87,   508,    -1,
     229,   364,    -1,   144,   365,   382,   174,    -1,   365,   366,
     181,    -1,    -1,   366,   100,   367,    -1,    25,   367,    -1,
     350,    -1,   350,   133,   385,    -1,    59,   111,   547,   133,
     385,    -1,   232,   234,   385,    -1,   235,   147,   385,   177,
     364,    -1,   230,   233,    -1,   231,   233,    -1,    25,   373,
      -1,    25,    48,   373,    -1,    25,    34,   373,    -1,   374,
      -1,    60,   374,    -1,    68,   376,    -1,    58,   375,    -1,
      40,   547,   362,   380,    -1,    40,   547,   362,   128,    -1,
      40,   547,   362,   364,    -1,    40,   547,   362,   128,    -1,
      40,   547,   362,   144,   384,   174,    -1,    40,   547,   362,
     128,    -1,   378,    -1,   377,   100,   378,    -1,   111,   547,
      -1,   111,   547,   507,    -1,   144,   382,   174,    -1,   144,
     382,   174,    -1,   382,    -1,   384,    -1,   384,   383,    -1,
     181,    -1,   383,   384,   181,    -1,   385,    -1,   384,   100,
     385,    -1,   386,    -1,   423,    -1,   426,    -1,   429,    -1,
     430,    -1,   534,    -1,   535,    -1,   537,    -1,   536,    -1,
     538,    -1,   541,    -1,   548,    -1,   369,    -1,   370,    -1,
     371,    -1,   368,    -1,   363,    -1,   395,   387,    -1,   176,
     385,    -1,    61,   275,    -1,    66,   275,    -1,   208,    -1,
     246,    -1,    49,   246,    -1,   389,   407,    70,   385,    -1,
     389,    70,   385,    -1,    39,   388,   406,   390,   390,    -1,
      39,   388,   406,   390,    -1,    33,   111,   547,    -1,   397,
      -1,   402,    -1,   391,    -1,   393,    -1,   411,    -1,   416,
      -1,   412,    -1,   392,    -1,   393,    -1,   395,   394,    -1,
      39,   111,    -1,    52,    39,   111,    -1,   396,   398,    -1,
     399,    -1,   398,   100,   111,   399,    -1,   547,   138,   385,
      -1,   547,   507,   138,   385,    -1,   547,   400,   138,   385,
      -1,   547,   507,   400,   138,   385,    -1,   547,   401,   138,
     385,    -1,   547,   507,   401,   138,   385,    -1,   547,   400,
     401,   138,   385,    -1,   547,   507,   400,   401,   138,   385,
      -1,    89,   111,   547,    -1,   264,   111,   547,    -1,    44,
     111,   403,    -1,   405,    -1,   403,   100,   111,   405,    -1,
     410,    -1,   404,   100,   111,   410,    -1,   547,   133,   385,
      -1,   547,   507,   133,   385,    -1,   547,   401,   133,   385,
      -1,   547,   507,   401,   133,   385,    -1,   111,   547,   138,
     385,    -1,   111,   547,   507,   138,   385,    -1,   408,    -1,
     111,   547,    -1,   111,   547,   408,    -1,   400,    -1,   400,
     409,    -1,   409,    -1,    53,   111,   547,    46,   111,   547,
      -1,    46,   111,   547,    -1,    53,   111,   547,    -1,   547,
      -1,   202,   385,    -1,   162,   161,   413,    -1,   414,    -1,
     413,   100,   414,    -1,   111,   547,    -1,   111,   547,   415,
      -1,    99,   545,    -1,   159,   161,   417,    -1,    64,   159,
     161,   417,    -1,   418,    -1,   417,   100,   418,    -1,   385,
      -1,   385,   419,    -1,   420,    -1,   421,    -1,   422,    -1,
     420,   421,    -1,   420,   422,    -1,   421,   422,    -1,   420,
     421,   422,    -1,    88,    -1,   109,    -1,   118,   119,    -1,
     118,   120,    -1,    99,   545,    -1,    62,   111,   424,   178,
     385,    -1,   126,   111,   424,   178,   385,    -1,   425,    -1,
     424,   100,   111,   425,    -1,   547,   138,   385,    -1,   547,
     507,   138,   385,    -1,    67,   147,   382,   177,   427,   106,
     176,   385,    -1,    67,   147,   382,   177,   427,   106,   111,
     547,   176,   385,    -1,   428,    -1,   427,   428,    -1,    93,
     508,   176,   385,    -1,    93,   111,   547,    87,   508,   176,
     385,    -1,    41,   147,   382,   177,   188,   385,   117,   385,
      -1,   431,    -1,   430,   158,   431,    -1,   432,    -1,   431,
      85,   432,    -1,   434,    -1,   434,   448,   434,    -1,   434,
     449,   434,    -1,   434,   123,   434,    -1,   434,   153,   434,
      -1,    -1,   434,   148,   433,   434,    -1,   434,   146,   434,
      -1,   434,   134,   434,    -1,   434,   132,   434,    -1,   436,
      -1,   436,   241,    65,   550,   435,    -1,    -1,   602,    -1,
     437,    -1,   437,   189,   437,    -1,   438,    -1,   437,   166,
     438,    -1,   437,   149,   438,    -1,   439,    -1,   438,   184,
     439,    -1,   438,   110,   439,    -1,   438,   137,   439,    -1,
     438,   150,   439,    -1,   440,    -1,   439,   191,   440,    -1,
     439,   200,   440,    -1,   441,    -1,   440,   141,   441,    -1,
     440,   127,   441,    -1,   442,    -1,   442,    43,   222,   508,
      -1,   443,    -1,   443,   190,    87,   508,    -1,   444,    -1,
     444,    94,    87,   506,    -1,   445,    -1,   445,    95,    87,
     506,    -1,   447,    -1,   446,   447,    -1,   166,    -1,   149,
      -1,   446,   166,    -1,   446,   149,    -1,   450,    -1,   454,
      -1,   451,    -1,   193,    -1,   198,    -1,   197,    -1,   196,
      -1,   195,    -1,   194,    -1,   142,    -1,   169,    -1,   131,
      -1,    69,   144,   382,   174,    -1,    69,   213,   144,   382,
     174,    -1,    69,   212,   144,   382,   174,    -1,    69,    87,
     523,   144,   382,   174,    -1,   452,   144,   174,    -1,   452,
     144,   382,   174,    -1,   453,    -1,   452,   453,    -1,   167,
     547,    15,    -1,   167,    16,    -1,   455,    -1,   455,   456,
      -1,   183,   456,    -1,   456,    -1,   182,    -1,   457,    -1,
     457,   182,   456,    -1,   457,   183,   456,    -1,   458,    -1,
     467,    -1,   459,    -1,   459,   468,    -1,   462,    -1,   462,
     468,    -1,   460,   464,    -1,   461,    -1,    98,    -1,   107,
      -1,    91,    -1,   180,    -1,   108,    -1,   130,    -1,   129,
      -1,   464,    -1,    92,   464,    -1,   463,   464,    -1,   113,
      -1,   163,    -1,    83,    -1,   171,    -1,   170,    -1,    84,
      -1,   513,    -1,   465,    -1,   547,    -1,   466,    -1,   184,
      -1,    10,    -1,    17,    -1,   470,    -1,   467,   468,    -1,
     467,   147,   177,    -1,   467,   147,   479,   177,    -1,   469,
      -1,   468,   469,    -1,   145,   382,   175,    -1,   471,    -1,
     473,    -1,   474,    -1,   475,    -1,   478,    -1,   480,    -1,
     476,    -1,   477,    -1,   526,    -1,   472,    -1,   525,    -1,
     103,    -1,   140,    -1,   115,    -1,   111,   547,    -1,   147,
     177,    -1,   147,   382,   177,    -1,   112,    -1,   160,   144,
     382,   174,    -1,   192,   144,   382,   174,    -1,   547,   147,
     177,    -1,   547,   147,   479,   177,    -1,   385,    -1,   479,
     100,   385,    -1,   481,    -1,   499,    -1,   482,    -1,   496,
      -1,   497,    -1,   148,   547,   486,   121,    -1,   148,   547,
     484,   486,   121,    -1,   148,   547,   486,   187,   185,   547,
     486,   187,    -1,   148,   547,   486,   187,   483,   185,   547,
     486,   187,    -1,   148,   547,   484,   486,   187,   185,   547,
     486,   187,    -1,   148,   547,   484,   486,   187,   483,   185,
     547,   486,   187,    -1,   494,    -1,   483,   494,    -1,   485,
      -1,   484,   485,    -1,    27,   547,   486,   123,   486,   487,
      -1,    -1,    27,    -1,   173,   488,   173,    -1,    86,   490,
      86,    -1,    -1,   489,    -1,   125,    -1,   492,    -1,   489,
     125,    -1,   489,   492,    -1,    -1,   491,    -1,   124,    -1,
     493,    -1,   491,   124,    -1,   491,   493,    -1,    19,    -1,
     495,    -1,     4,    -1,   495,    -1,   481,    -1,     9,    -1,
     498,    -1,   495,    -1,     8,    -1,   114,    -1,   116,    -1,
     379,    -1,   203,    21,   204,    -1,   203,   204,    -1,   164,
     546,   165,    -1,   164,   546,     7,    -1,    96,     6,    -1,
     500,    -1,   501,    -1,   502,    -1,   503,    -1,   504,    -1,
     505,    -1,    35,   144,   382,   174,    -1,    37,   547,   144,
     174,    -1,    37,   547,   144,   382,   174,    -1,    37,   144,
     382,   174,   144,   174,    -1,    37,   144,   382,   174,   144,
     382,   174,    -1,    90,   547,   144,   174,    -1,    90,   547,
     144,   382,   174,    -1,    90,   144,   382,   174,   144,   174,
      -1,    90,   144,   382,   174,   144,   382,   174,    -1,    65,
     144,   382,   174,    -1,    30,   144,   382,   174,    -1,    54,
     546,   144,   174,    -1,    54,   546,   144,   382,   174,    -1,
      54,   144,   382,   174,   144,   174,    -1,    54,   144,   382,
     174,   144,   382,   174,    -1,   512,    -1,   512,   135,    -1,
      87,   508,    -1,   510,    -1,   510,   509,    -1,   201,   147,
     177,    -1,   135,    -1,   184,    -1,   166,    -1,   512,    -1,
     513,    -1,   143,   147,   177,    -1,   529,    -1,   532,    -1,
     508,    -1,   511,   100,   508,    -1,   547,    -1,   515,    -1,
     521,    -1,   519,    -1,   522,    -1,   520,    -1,   518,    -1,
     517,    -1,   516,    -1,   514,    -1,   216,   147,   177,    -1,
      36,   147,   177,    -1,    36,   147,   521,   177,    -1,    36,
     147,   522,   177,    -1,    65,   147,   177,    -1,    30,   147,
     177,    -1,    54,   147,   177,    -1,    54,   147,   546,   177,
      -1,    54,   147,    20,   177,    -1,    90,   147,   177,    -1,
      90,   147,   547,   177,    -1,    90,   147,   547,   100,   523,
     177,    -1,    90,   147,   184,   177,    -1,    90,   147,   184,
     100,   523,   177,    -1,   179,   547,   177,    -1,    37,   147,
     177,    -1,    37,   147,   547,   177,    -1,    37,   147,   547,
     100,   523,   177,    -1,    37,   147,   547,   100,   524,   177,
      -1,    37,   147,   184,   177,    -1,    37,   147,   184,   100,
     523,   177,    -1,    37,   147,   184,   100,   524,   177,    -1,
      57,   147,   547,   177,    -1,   547,    -1,   547,   135,    -1,
      20,    -1,   527,    -1,   528,    -1,   547,   136,   140,    -1,
      40,   362,   379,    -1,   530,    -1,   531,    -1,    40,   147,
     184,   177,    -1,    40,   147,   177,    87,   508,    -1,    40,
     147,   511,   177,    87,   508,    -1,   147,   510,   177,    -1,
      25,   211,   212,    -1,    25,   211,   213,    -1,    25,   211,
     214,    -1,   217,   216,   385,   224,   385,    -1,   217,   216,
     385,    87,   223,   224,   385,    -1,   217,   216,   385,    87,
     225,   224,   385,    -1,   217,   216,   385,   209,   385,    -1,
     217,   216,   385,   210,   385,    -1,   217,   218,   385,   224,
     385,    -1,   217,   218,   385,    87,   223,   224,   385,    -1,
     217,   218,   385,    87,   225,   224,   385,    -1,   217,   218,
     385,   209,   385,    -1,   217,   218,   385,   210,   385,    -1,
     215,   216,   385,    -1,   215,   218,   385,    -1,   220,   216,
     385,   228,   385,    -1,   220,   221,   222,   216,   385,   228,
     385,    -1,   219,   216,   385,    87,   385,    -1,   227,   111,
     539,   226,   385,   176,   385,    -1,   540,    -1,   539,   100,
     111,   540,    -1,   547,   133,   385,    -1,   236,   144,   382,
     174,   542,    -1,   543,    -1,   542,   543,    -1,   237,   544,
     380,    -1,   237,   544,   147,   111,   547,   177,   380,    -1,
     237,   544,   147,   111,   547,   100,   111,   547,   177,   380,
      -1,   237,   544,   147,   111,   547,   100,   111,   547,   100,
     111,   547,   177,   380,    -1,   465,    -1,   544,   200,   465,
      -1,    20,    -1,    14,    -1,   547,    -1,    18,    -1,   549,
      -1,   238,   111,   404,    38,   144,   385,   174,    -1,    38,
     144,   385,   174,    -1,   205,    -1,   118,    -1,    90,    -1,
      30,    -1,    36,    -1,    37,    -1,   143,    -1,    41,    -1,
     216,    -1,    54,    -1,    56,    -1,    57,    -1,    65,    -1,
      67,    -1,   201,    -1,    29,    -1,   252,    -1,    28,    -1,
     213,    -1,   212,    -1,   137,    -1,    35,    -1,   251,    -1,
     265,    -1,   254,    -1,   243,    -1,   276,    -1,   268,    -1,
     270,    -1,   269,    -1,   274,    -1,   247,    -1,   242,    -1,
      71,    -1,   208,    -1,   246,    -1,    45,    -1,   214,    -1,
     227,    -1,   221,    -1,   193,    -1,   198,    -1,   197,    -1,
     196,    -1,   195,    -1,   194,    -1,    89,    -1,   104,    -1,
     105,    -1,   176,    -1,    39,    -1,    52,    -1,    61,    -1,
      66,    -1,    53,    -1,    46,    -1,    49,    -1,    70,    -1,
      33,    -1,   138,    -1,    44,    -1,   202,    -1,   161,    -1,
     162,    -1,   159,    -1,    64,    -1,    88,    -1,   109,    -1,
     119,    -1,   120,    -1,    99,    -1,    62,    -1,   126,    -1,
     178,    -1,    93,    -1,    87,    -1,   188,    -1,   117,    -1,
     158,    -1,    85,    -1,    43,    -1,   222,    -1,    94,    -1,
     189,    -1,   110,    -1,   150,    -1,   191,    -1,   141,    -1,
     127,    -1,    69,    -1,    95,    -1,   190,    -1,   142,    -1,
     172,    -1,   186,    -1,   151,    -1,   128,    -1,   122,    -1,
     157,    -1,   139,    -1,   156,    -1,    25,    -1,    31,    -1,
      51,    -1,   106,    -1,    32,    -1,    50,    -1,   206,    -1,
      42,    -1,    55,    -1,    26,    -1,    40,    -1,   264,    -1,
     241,    -1,   273,    -1,   275,    -1,   245,    -1,   258,    -1,
     271,    -1,   263,    -1,   244,    -1,   257,    -1,   272,    -1,
     262,    -1,   256,    -1,   255,    -1,   240,    -1,   239,    -1,
     261,    -1,   248,    -1,   249,    -1,   277,    -1,   267,    -1,
     266,    -1,   259,    -1,   220,    -1,   226,    -1,   223,    -1,
     217,    -1,   210,    -1,   209,    -1,   211,    -1,   228,    -1,
     218,    -1,   219,    -1,   225,    -1,   215,    -1,   224,    -1,
      60,    -1,    58,    -1,    68,    -1,    34,    -1,    48,    -1,
     160,    -1,   192,    -1,   234,    -1,   229,    -1,   232,    -1,
     233,    -1,   235,    -1,   230,    -1,   231,    -1,   236,    -1,
     237,    -1,    38,    -1,   238,    -1,    59,    -1,   286,    -1,
     284,    -1,   285,    -1,   290,    -1,   291,    -1,   292,    -1,
     287,    -1,   288,    -1,   289,    -1,    72,    -1,    73,    -1,
      74,    -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,
      79,    -1,    80,    -1,    81,    -1,    82,    -1,   278,    -1,
     279,    -1,   280,    -1,   281,    -1,   282,    -1,   283,    -1,
     293,    -1,   294,    -1,   295,    -1,   296,    -1,   297,    -1,
     298,    -1,   299,    -1,   553,   551,    -1,    -1,   552,    -1,
     571,    -1,   552,   571,    -1,   554,    -1,   553,   253,   554,
      -1,   555,    -1,   554,   250,   555,    -1,   556,    -1,   555,
     251,   138,   556,    -1,   557,    -1,   251,   557,    -1,   561,
     558,   559,    -1,    -1,   576,    -1,    -1,   560,    -1,   273,
     144,   382,   174,    -1,   565,   562,    -1,   147,   550,   177,
      -1,   563,    -1,    -1,   598,    -1,   452,   144,   564,   174,
      -1,    -1,   550,    -1,   566,   567,    -1,   471,    -1,   144,
     382,   174,    -1,    -1,   568,    -1,   240,   569,    -1,   239,
     570,    -1,   261,    -1,    -1,    71,    -1,    -1,   277,    -1,
     572,    -1,   573,    -1,   574,    -1,   600,    -1,   597,    -1,
     160,    -1,   275,   437,   575,    -1,   245,   599,   575,    -1,
     277,    -1,   267,    -1,   260,    -1,   238,   577,    -1,   576,
     238,   577,    -1,   578,    -1,   579,    -1,   580,    -1,   595,
      -1,   581,    -1,   589,    -1,   582,    -1,   596,    -1,    93,
     265,    -1,    93,   254,    -1,   257,    -1,   272,    -1,   243,
     265,    -1,   243,   254,    -1,    50,   547,    20,    -1,   268,
      -1,    47,   268,    -1,   270,   583,    -1,   270,   147,   583,
     584,   177,    -1,    47,   270,    -1,   586,    -1,   106,    -1,
      -1,   585,    -1,   586,    -1,   585,   100,   586,    -1,    89,
      20,   587,   588,    -1,    -1,   262,    20,    -1,    -1,   599,
     256,    -1,   269,   277,   590,   592,    -1,   269,   277,   106,
     592,    -1,    47,   269,   277,    -1,    89,    20,    -1,   147,
     591,   177,    -1,    20,    -1,   591,   100,    20,    -1,    -1,
     593,    -1,   594,    -1,   593,   594,    -1,   191,   590,    -1,
     127,   590,    -1,   255,    20,    -1,   274,    -1,    47,   274,
      -1,    89,   208,    -1,    89,   246,    -1,   247,   242,    -1,
     258,   599,   271,    -1,   248,   437,    -1,    89,   120,   437,
      -1,    89,    45,   437,    -1,   249,   437,   189,   437,    -1,
     263,   601,    -1,   244,   601,    -1,   266,    -1,   259,    -1,
     276,   242,   439,    -1
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
    1161,  1167,  1168,  1170,  1172,  1176,  1178,  1182,  1186,  1188,
    1192,  1196,  1200,  1204,  1206,  1210,  1214,  1216,  1220,  1224,
    1226,  1231,  1233,  1238,  1240,  1245,  1247,  1252,  1254,  1257,
    1259,  1261,  1264,  1267,  1269,  1271,  1273,  1275,  1277,  1279,
    1281,  1283,  1285,  1287,  1289,  1291,  1296,  1302,  1308,  1315,
    1319,  1324,  1326,  1329,  1333,  1336,  1338,  1341,  1344,  1346,
    1348,  1350,  1354,  1358,  1360,  1362,  1364,  1367,  1369,  1372,
    1375,  1377,  1379,  1381,  1383,  1385,  1387,  1389,  1391,  1393,
    1396,  1399,  1401,  1403,  1405,  1407,  1409,  1411,  1413,  1415,
    1417,  1419,  1421,  1423,  1425,  1427,  1430,  1434,  1439,  1441,
    1444,  1448,  1450,  1452,  1454,  1456,  1458,  1460,  1462,  1464,
    1466,  1468,  1470,  1472,  1474,  1476,  1479,  1482,  1486,  1488,
    1493,  1498,  1502,  1507,  1509,  1513,  1515,  1517,  1519,  1521,
    1523,  1528,  1534,  1543,  1553,  1563,  1574,  1576,  1579,  1581,
    1584,  1591,  1592,  1594,  1598,  1602,  1603,  1605,  1607,  1609,
    1612,  1615,  1616,  1618,  1620,  1622,  1625,  1628,  1630,  1632,
    1634,  1636,  1638,  1640,  1642,  1644,  1646,  1648,  1650,  1652,
    1656,  1659,  1663,  1667,  1670,  1672,  1674,  1676,  1678,  1680,
    1682,  1687,  1692,  1698,  1705,  1713,  1718,  1724,  1731,  1739,
    1744,  1749,  1754,  1760,  1767,  1775,  1777,  1780,  1783,  1785,
    1788,  1792,  1794,  1796,  1798,  1800,  1802,  1806,  1808,  1810,
    1812,  1816,  1818,  1820,  1822,  1824,  1826,  1828,  1830,  1832,
    1834,  1836,  1840,  1844,  1849,  1854,  1858,  1862,  1866,  1871,
    1876,  1880,  1885,  1892,  1897,  1904,  1908,  1912,  1917,  1924,
    1931,  1936,  1943,  1950,  1955,  1957,  1960,  1962,  1964,  1966,
    1970,  1974,  1976,  1978,  1983,  1989,  1996,  2000,  2004,  2008,
    2012,  2018,  2026,  2034,  2040,  2046,  2052,  2060,  2068,  2074,
    2080,  2084,  2088,  2094,  2102,  2108,  2116,  2118,  2123,  2127,
    2133,  2135,  2138,  2142,  2150,  2161,  2175,  2177,  2181,  2183,
    2185,  2187,  2189,  2191,  2199,  2204,  2206,  2208,  2210,  2212,
    2214,  2216,  2218,  2220,  2222,  2224,  2226,  2228,  2230,  2232,
    2234,  2236,  2238,  2240,  2242,  2244,  2246,  2248,  2250,  2252,
    2254,  2256,  2258,  2260,  2262,  2264,  2266,  2268,  2270,  2272,
    2274,  2276,  2278,  2280,  2282,  2284,  2286,  2288,  2290,  2292,
    2294,  2296,  2298,  2300,  2302,  2304,  2306,  2308,  2310,  2312,
    2314,  2316,  2318,  2320,  2322,  2324,  2326,  2328,  2330,  2332,
    2334,  2336,  2338,  2340,  2342,  2344,  2346,  2348,  2350,  2352,
    2354,  2356,  2358,  2360,  2362,  2364,  2366,  2368,  2370,  2372,
    2374,  2376,  2378,  2380,  2382,  2384,  2386,  2388,  2390,  2392,
    2394,  2396,  2398,  2400,  2402,  2404,  2406,  2408,  2410,  2412,
    2414,  2416,  2418,  2420,  2422,  2424,  2426,  2428,  2430,  2432,
    2434,  2436,  2438,  2440,  2442,  2444,  2446,  2448,  2450,  2452,
    2454,  2456,  2458,  2460,  2462,  2464,  2466,  2468,  2470,  2472,
    2474,  2476,  2478,  2480,  2482,  2484,  2486,  2488,  2490,  2492,
    2494,  2496,  2498,  2500,  2502,  2504,  2506,  2508,  2510,  2512,
    2514,  2516,  2518,  2520,  2522,  2524,  2526,  2528,  2530,  2532,
    2534,  2536,  2538,  2540,  2542,  2544,  2546,  2548,  2550,  2552,
    2554,  2556,  2558,  2560,  2562,  2564,  2566,  2568,  2570,  2572,
    2574,  2576,  2578,  2580,  2582,  2584,  2586,  2588,  2590,  2592,
    2594,  2596,  2598,  2600,  2602,  2604,  2607,  2608,  2610,  2612,
    2615,  2617,  2621,  2623,  2627,  2629,  2634,  2636,  2639,  2643,
    2644,  2646,  2647,  2649,  2654,  2657,  2661,  2663,  2664,  2666,
    2671,  2672,  2674,  2677,  2679,  2683,  2684,  2686,  2689,  2692,
    2694,  2695,  2697,  2698,  2700,  2702,  2704,  2706,  2708,  2710,
    2712,  2716,  2720,  2722,  2724,  2726,  2729,  2733,  2735,  2737,
    2739,  2741,  2743,  2745,  2747,  2749,  2752,  2755,  2757,  2759,
    2762,  2765,  2769,  2771,  2774,  2777,  2783,  2786,  2788,  2790,
    2791,  2793,  2795,  2799,  2804,  2805,  2808,  2809,  2812,  2817,
    2822,  2826,  2829,  2833,  2835,  2839,  2840,  2842,  2844,  2847,
    2850,  2853,  2856,  2858,  2861,  2864,  2867,  2870,  2874,  2877,
    2881,  2885,  2890,  2893,  2896,  2898,  2900
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   967,   967,   968,   977,   982,   989,   994,  1005,  1010,
    1018,  1026,  1034,  1040,  1052,  1061,  1065,  1069,  1081,  1087,
    1097,  1103,  1113,  1114,  1115,  1116,  1121,  1122,  1123,  1124,
    1125,  1126,  1127,  1128,  1129,  1135,  1140,  1149,  1155,  1164,
    1173,  1174,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,
    1187,  1188,  1189,  1190,  1191,  1192,  1193,  1196,  1201,  1202,
    1212,  1221,  1227,  1237,  1243,  1253,  1263,  1271,  1277,  1288,
    1293,  1303,  1309,  1315,  1321,  1338,  1346,  1354,  1358,  1367,
    1376,  1389,  1395,  1406,  1410,  1418,  1423,  1428,  1435,  1448,
    1455,  1461,  1468,  1474,  1478,  1485,  1496,  1500,  1508,  1514,
    1520,  1529,  1535,  1544,  1548,  1554,  1558,  1562,  1566,  1572,
    1578,  1584,  1588,  1594,  1600,  1607,  1615,  1623,  1631,  1639,
    1645,  1653,  1661,  1672,  1677,  1685,  1689,  1696,  1704,  1715,
    1721,  1729,  1736,  1746,  1756,  1766,  1776,  1793,  1799,  1810,
    1814,  1818,  1822,  1831,  1838,  1857,  1867,  1873,  1879,  1889,
    1896,  1907,  1914,  1921,  1933,  1937,  1944,  1949,  1956,  1964,
    1968,  1972,  1980,  1988,  1998,  2012,  2022,  2036,  2045,  2060,
    2066,  2078,  2082,  2093,  2100,  2108,  2123,  2127,  2141,  2145,
    2154,  2158,  2172,  2173,  2174,  2175,  2176,  2179,  2180,  2181,
    2182,  2183,  2185,  2186,  2189,  2190,  2191,  2192,  2193,  2198,
    2213,  2220,  2224,  2231,  2235,  2239,  2246,  2254,  2265,  2275,
    2288,  2297,  2298,  2299,  2303,  2304,  2305,  2306,  2307,  2310,
    2316,  2325,  2329,  2337,  2347,  2353,  2365,  2369,  2377,  2386,
    2396,  2404,  2413,  2422,  2437,  2446,  2456,  2464,  2470,  2479,
    2485,  2497,  2505,  2515,  2523,  2535,  2541,  2552,  2554,  2558,
    2566,  2570,  2575,  2579,  2583,  2587,  2595,  2609,  2617,  2624,
    2630,  2641,  2645,  2654,  2662,  2668,  2678,  2684,  2694,  2698,
    2708,  2714,  2720,  2726,  2735,  2744,  2753,  2766,  2770,  2778,
    2784,  2794,  2802,  2811,  2824,  2831,  2843,  2847,  2860,  2867,
    2880,  2886,  2898,  2904,  2916,  2925,  2929,  2938,  2942,  2950,
    2954,  2964,  2971,  2980,  2990,  2989,  3003,  3012,  3021,  3034,
    3038,  3051,  3054,  3062,  3066,  3075,  3079,  3083,  3092,  3096,
    3102,  3108,  3114,  3125,  3129,  3133,  3141,  3145,  3151,  3161,
    3165,  3175,  3179,  3189,  3193,  3203,  3207,  3217,  3221,  3229,
    3233,  3237,  3241,  3251,  3255,  3259,  3267,  3271,  3275,  3279,
    3283,  3287,  3295,  3299,  3303,  3311,  3315,  3319,  3323,  3333,
    3339,  3349,  3355,  3365,  3369,  3407,  3413,  3419,  3425,  3436,
    3444,  3455,  3461,  3471,  3475,  3483,  3489,  3497,  3503,  3515,
    3521,  3531,  3535,  3539,  3543,  3547,  3553,  3559,  3567,  3571,
    3579,  3583,  3594,  3598,  3602,  3608,  3612,  3626,  3630,  3638,
    3642,  3652,  3656,  3660,  3669,  3673,  3679,  3683,  3691,  3697,
    3707,  3715,  3719,  3723,  3727,  3731,  3735,  3739,  3743,  3747,
    3755,  3759,  3767,  3774,  3781,  3792,  3800,  3804,  3812,  3820,
    3828,  3882,  3886,  3898,  3904,  3914,  3918,  3926,  3930,  3934,
    3942,  3952,  3962,  3972,  3982,  3992,  4007,  4013,  4024,  4030,
    4041,  4052,  4054,  4058,  4063,  4073,  4076,  4083,  4091,  4097,
    4107,  4120,  4123,  4130,  4136,  4142,  4149,  4160,  4164,  4174,
    4178,  4188,  4192,  4196,  4201,  4210,  4216,  4222,  4228,  4238,
    4242,  4254,  4258,  4270,  4282,  4286,  4290,  4294,  4298,  4302,
    4310,  4318,  4324,  4330,  4334,  4351,  4355,  4359,  4363,  4371,
    4379,  4387,  4391,  4395,  4399,  4407,  4413,  4423,  4431,  4435,
    4441,  4476,  4482,  4488,  4498,  4502,  4506,  4510,  4514,  4521,
    4527,  4537,  4545,  4549,  4553,  4557,  4561,  4565,  4569,  4573,
    4577,  4585,  4593,  4597,  4601,  4611,  4619,  4627,  4631,  4635,
    4643,  4647,  4653,  4659,  4663,  4673,  4681,  4685,  4691,  4700,
    4709,  4715,  4721,  4731,  4748,  4755,  4770,  4806,  4810,  4819,
    4828,  4837,  4841,  4850,  4859,  4863,  4872,  4889,  4895,  4901,
    4911,  4915,  4921,  4927,  4931,  4937,  4941,  4947,  4953,  4960,
    4970,  4975,  4983,  4989,  4999,  5021,  5030,  5036,  5049,  5063,
    5070,  5076,  5086,  5091,  5097,  5107,  5120,  5126,  5136,  5146,
    5147,  5165,  5169,  5182,  5188,  5195,  5196,  5197,  5198,  5199,
    5200,  5201,  5202,  5203,  5204,  5205,  5206,  5207,  5208,  5209,
    5210,  5211,  5212,  5213,  5214,  5215,  5216,  5217,  5218,  5219,
    5220,  5221,  5222,  5223,  5224,  5225,  5226,  5227,  5228,  5229,
    5230,  5231,  5232,  5233,  5234,  5235,  5236,  5237,  5238,  5239,
    5240,  5241,  5242,  5243,  5244,  5245,  5246,  5247,  5248,  5249,
    5250,  5251,  5252,  5253,  5254,  5255,  5256,  5257,  5258,  5259,
    5260,  5261,  5262,  5263,  5264,  5265,  5266,  5267,  5268,  5269,
    5270,  5271,  5272,  5273,  5274,  5275,  5276,  5277,  5278,  5279,
    5280,  5281,  5282,  5283,  5284,  5285,  5286,  5287,  5288,  5289,
    5290,  5291,  5292,  5293,  5294,  5295,  5296,  5297,  5298,  5299,
    5300,  5301,  5302,  5303,  5304,  5305,  5306,  5307,  5308,  5309,
    5310,  5311,  5312,  5313,  5314,  5315,  5316,  5317,  5318,  5319,
    5320,  5321,  5322,  5323,  5324,  5325,  5326,  5327,  5328,  5329,
    5330,  5331,  5332,  5333,  5334,  5335,  5336,  5337,  5338,  5339,
    5340,  5341,  5342,  5343,  5344,  5345,  5346,  5347,  5348,  5349,
    5350,  5351,  5352,  5353,  5354,  5355,  5356,  5357,  5358,  5359,
    5360,  5361,  5362,  5363,  5364,  5365,  5366,  5367,  5368,  5369,
    5370,  5371,  5372,  5373,  5374,  5375,  5376,  5377,  5378,  5379,
    5380,  5381,  5382,  5383,  5384,  5385,  5386,  5387,  5388,  5389,
    5390,  5391,  5392,  5393,  5394,  5406,  5415,  5418,  5425,  5430,
    5439,  5443,  5453,  5457,  5467,  5471,  5482,  5486,  5496,  5509,
    5512,  5520,  5523,  5531,  5539,  5547,  5551,  5559,  5562,  5570,
    5582,  5585,  5593,  5605,  5611,  5621,  5624,  5632,  5636,  5640,
    5648,  5651,  5659,  5662,  5670,  5674,  5678,  5682,  5686,  5694,
    5702,  5714,  5726,  5730,  5734,  5742,  5748,  5758,  5762,  5766,
    5770,  5774,  5778,  5782,  5786,  5794,  5798,  5802,  5806,  5814,
    5820,  5830,  5840,  5844,  5852,  5862,  5873,  5880,  5884,  5892,
    5895,  5902,  5907,  5916,  5926,  5929,  5937,  5940,  5948,  5957,
    5964,  5974,  5978,  5985,  5991,  6001,  6004,  6011,  6016,  6028,
    6036,  6048,  6056,  6060,  6068,  6072,  6076,  6084,  6092,  6100,
    6108,  6116,  6129,  6137,  6149,  6153,  6161
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
     305,   306,   307,   308,   309,   310,   311,   312,   313
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 11301;
  const int xquery_parser::yynnts_ = 289;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 520;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 314;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 568;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 15101 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6167 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"


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

