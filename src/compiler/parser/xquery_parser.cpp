
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
#line 68 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"


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
#line 77 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc  */
#line 106 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"

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
#line 175 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
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
#line 832 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 282 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 115: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 831 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 291 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 140: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 830 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 300 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 309 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 318 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 327 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 336 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "Prolog" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 345 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 354 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 363 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 372 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 381 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 390 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 857 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 399 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 857 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 408 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 417 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 426 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 435 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 444 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 453 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 462 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 471 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 480 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 489 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 498 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 507 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 516 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 525 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 534 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 543 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 552 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 561 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 570 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 579 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 588 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 857 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 597 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 606 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "DeclPropertyList" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 615 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "DeclProperty" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 624 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 633 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 642 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 651 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 660 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 669 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 678 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 687 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 857 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 696 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 705 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 714 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 723 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 732 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 741 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 750 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 759 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 768 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 777 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 786 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 795 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FunctionDecl3" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 804 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDecl4" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 813 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 822 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 831 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 840 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 849 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 858 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 867 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 885 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 894 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 903 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 912 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 921 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 930 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 939 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 948 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 957 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 966 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 975 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 984 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 993 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1002 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1011 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1020 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1029 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1038 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1047 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1056 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1065 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1074 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1083 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1092 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1101 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1110 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1119 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1128 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1137 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1146 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1155 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1164 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1173 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1182 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1191 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1200 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1209 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1218 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1227 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1236 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1245 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1254 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1263 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1272 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1281 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1290 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1299 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1308 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1317 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1326 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1335 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1344 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1353 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1362 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1371 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1380 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1389 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1398 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1407 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1416 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1425 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1434 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1443 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1452 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1461 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1470 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1479 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1488 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1497 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1506 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1515 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1524 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1533 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1542 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1551 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1560 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1569 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1578 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1587 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1596 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1605 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1614 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1623 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1632 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1641 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1650 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1659 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1668 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1677 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1686 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1695 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1704 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1713 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1722 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1731 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1740 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1749 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1758 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1767 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1776 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1785 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1794 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1803 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1812 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1821 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1830 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1839 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1848 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1857 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1866 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1875 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1884 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1893 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1902 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1911 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1920 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1929 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1938 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1947 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1956 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1965 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1974 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1983 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1992 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2001 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2010 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2019 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2028 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2037 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2046 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2055 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2064 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2073 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2082 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2091 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2100 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2109 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 848 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2118 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2127 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2136 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2145 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2154 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2163 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2172 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2181 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2190 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2199 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2208 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 857 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2217 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2226 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2235 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2244 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2253 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2262 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2271 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2280 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2289 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2298 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2307 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2316 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2325 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2334 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2343 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2352 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2361 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2370 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2379 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2388 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2397 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2406 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2415 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2424 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2433 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2442 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2451 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2460 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2469 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2478 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2487 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2496 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2505 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2514 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2523 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2532 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2541 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2550 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2559 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2568 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2577 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
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
#line 119 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}

/* Line 553 of lalr1.cc  */
#line 2662 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"

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
#line 970 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 979 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 984 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            MainModule *mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
            mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 991 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 996 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            LibraryModule *lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
            lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1007 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            std::string encoding = "utf-8";
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), encoding );
        }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1012 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
        }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1020 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 1028 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
        }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1036 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LibraryModule(
                LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1042 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 1054 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
            dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
        }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1063 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog( LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)), NULL );
        }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1067 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog( LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)) );
        }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1071 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 1083 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
            sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = sdl;
        }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1089 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            if ( SIND_DeclList *sdl = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                sdl->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1099 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
            vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = vdl;
        }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1105 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            if ( VFO_DeclList *vdl = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vdl->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 1137 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
         (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
         delete (yysemantic_stack_[(4) - (4)].vstrpair);
       }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1142 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
         (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
         delete (yysemantic_stack_[(4) - (4)].vstrpair);
       }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1151 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          (yyval.vstrpair) = new vector<string_pair_t>();
          (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
          delete (yysemantic_stack_[(1) - (1)].strpair);
        }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1157 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
          delete (yysemantic_stack_[(2) - (2)].strpair);
          (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
        }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1166 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
            (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval() );
            delete sl;
        }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1174 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1175 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1176 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1177 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1178 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1179 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1180 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1181 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1182 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1183 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1214 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
        }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1223 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::preserve_space
            );
        }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1229 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::strip_space
            );
        }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1239 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_element_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1245 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_function_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1255 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OptionDecl(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval))
            );
        }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1265 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1273 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::ordered
            );
        }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1279 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::unordered
            );
        }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1290 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_greatest);
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1295 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_least);
        }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1305 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1311 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1317 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1323 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1340 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
        }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1348 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1356 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
        }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1360 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 1369 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 1378 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 1391 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            URILiteralList *ull = new URILiteralList( LOC((yyloc)));
            ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.node) = ull;
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1397 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
                ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1408 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1412 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
        }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1420 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1425 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1430 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), 
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1437 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 1450 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
        }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1457 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
            d->type = (yysemantic_stack_[(3) - (2)].node);
            (yyval.node) = d;
        }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1463 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1470 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
            d->ext = false;
            (yyval.node) = d;
        }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1476 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), NULL );
        }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1480 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1487 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1498 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1502 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1510 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(5) - (5)].expr));
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1516 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1522 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1531 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
            dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = dpl;
        }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1537 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
        DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
        dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
        (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1546 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1550 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1556 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1560 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1564 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1568 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1574 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1580 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1586 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1590 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1596 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1602 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1609 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 1617 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 1625 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 1633 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 1641 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(4) - (2)].node)), 0, 0);
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1647 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 1655 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 1663 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 1674 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = static_cast<parsenode*>(
           new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1679 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = static_cast<parsenode*>(
           new SequenceType( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1687 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier( LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1691 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier( LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1698 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 1706 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 1717 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList( LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1723 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1731 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec( LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<AtomicType*>((yysemantic_stack_[(3) - (3)].node)),
                            NULL);
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1738 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec( LOC((yyloc)),
                            (yysemantic_stack_[(4) - (1)].expr),
                            dynamic_cast<AtomicType*>((yysemantic_stack_[(4) - (3)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1749 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 1759 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 1769 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 1780 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 1795 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_preserve
            );
        }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1801 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_strip
            );
        }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1812 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL );
        }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1816 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1820 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)) );
        }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1824 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig(
                dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1833 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1840 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 1859 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 1868 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1875 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            vfo->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = vfo;
        }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1881 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back((yysemantic_stack_[(2) - (2)].node));
            (yyval.node) = vfo;
        }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1891 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(1) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1898 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(3) - (3)].expr));
      vd->set_global(false);
      (yyval.node) = vd;
        }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1909 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1916 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExitExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1923 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 1935 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::BREAK );
        }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1939 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
        }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1946 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            dynamic_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1951 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            FunctionDecl *fd = dynamic_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));
            fd->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            fd->deterministic = false;
            (yyval.node) = fd;
        }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1958 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            dynamic_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node))->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
        }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1966 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1970 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1974 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 1982 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 1990 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2000 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2014 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2024 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2038 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2047 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2062 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            ParamList *pl = new ParamList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2068 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
                pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2080 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2084 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2095 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EnclosedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 2102 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 2110 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QueryBody( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 2125 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2129 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2143 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new BlockBody( LOC((yyloc)) );
        }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2147 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (1)].expr));
            bb->add( (yysemantic_stack_[(3) - (2)].expr) );
            (yyval.expr) = bb;
        }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2156 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2160 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2200 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2215 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2222 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_sliding;
        }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2226 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_tumbling;
        }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2233 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_start;
        }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2237 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_end;
        }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2241 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_only_end;
        }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2248 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2256 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr),
                (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 2267 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2277 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2290 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 2312 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 2318 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2327 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = NULL;
        }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 2331 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_ofor;
        }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2339 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForClause(
                LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL
            );
        }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2349 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
            vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vdl;
        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2355 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2367 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2371 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2379 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2388 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2398 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2406 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2415 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2424 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2439 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2448 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2458 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2466 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2472 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2481 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2487 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            if ( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2499 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2507 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2517 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2525 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2537 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2543 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2556 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2560 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2568 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2572 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2581 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2585 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2589 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2597 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2611 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2619 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2626 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2632 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2643 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2647 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2656 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2664 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2670 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2680 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2686 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2696 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2700 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2710 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2716 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2722 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2728 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2737 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2746 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2755 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2768 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2772 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2780 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2786 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2796 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2804 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2813 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2826 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
            qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qvidl;

        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2833 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2845 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2849 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2862 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2869 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2882 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2888 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2900 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 2906 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 2918 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 2927 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 2931 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 2940 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 2944 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 2952 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 2956 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2966 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 2973 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2982 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 2991 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 2996 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 3005 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 3014 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 3023 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 3036 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3040 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3052 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3056 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3063 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3067 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3076 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3080 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3084 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3093 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3097 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3103 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3109 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3115 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3126 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3130 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3134 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3142 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3146 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3152 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3162 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3166 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3176 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3180 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3190 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3194 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3204 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3208 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3218 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3222 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3230 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3234 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3238 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3242 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3252 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3256 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3260 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3268 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3272 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3276 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3280 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3284 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3288 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3296 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3300 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3304 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3312 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3316 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3320 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3324 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3334 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3340 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3350 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3356 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3366 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3370 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3408 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL
            );
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3414 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3420 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3426 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = !rpe ?
                (yysemantic_stack_[(1) - (1)].expr) : new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3437 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NULL;
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3445 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 3456 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3462 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3472 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3476 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3484 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3490 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 3498 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3504 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 3516 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3522 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3532 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3536 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3540 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3544 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3548 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3554 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3560 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3568 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3572 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3580 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3584 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3595 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3599 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3603 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3609 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3613 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3627 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3631 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3639 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3643 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3653 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3657 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3661 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3670 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3674 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FilterExpr(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3680 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3684 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3692 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3698 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3708 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3716 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3720 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3724 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3728 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3732 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3736 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3740 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3744 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3748 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3756 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3760 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3768 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3775 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3782 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3793 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3801 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3805 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3813 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 3821 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 3829 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 3883 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 3887 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 3899 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 3905 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 3915 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 3919 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 3927 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 3931 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 3935 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 3943 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 3953 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 3963 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 3973 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 3983 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 3993 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 4008 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4014 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4025 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4031 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4042 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 4059 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4064 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4073 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4077 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4084 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 4092 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4098 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 4108 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 4120 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4124 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4131 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4137 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4143 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4150 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4161 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4165 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4175 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4179 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4189 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4193 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4197 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4202 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4211 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4217 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4223 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4229 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4239 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4243 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4255 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4259 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4271 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4283 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4287 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4291 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4295 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4299 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4303 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4311 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4319 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL
            );
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4325 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr)
            );
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4331 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4335 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4352 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (2)].expr), NULL );
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4356 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4360 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4364 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4372 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4380 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4388 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), NULL );
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4392 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (2)].sval)), (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4396 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4400 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4408 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4414 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4424 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4432 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4436 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4442 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4477 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4483 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4489 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4499 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4503 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4507 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4511 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4515 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4522 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back((yysemantic_stack_[(1) - (1)].node));
          (yyval.node) = aTypeList;
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4528 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          if (aTypeList) aTypeList->push_back((yysemantic_stack_[(3) - (3)].node));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4538 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4546 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4550 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4554 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4558 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4562 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4566 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4570 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4574 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4578 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4586 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4594 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4598 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4602 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4612 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4620 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4628 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4632 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4636 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4644 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4648 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4654 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4660 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4664 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4674 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4682 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4686 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4692 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 4701 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 4710 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4716 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4722 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4732 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4749 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4756 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4771 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4807 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4811 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4820 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), *(yysemantic_stack_[(3) - (3)].ival));
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4829 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new InlineFunction(LOC ((yyloc)), &*(yysemantic_stack_[(3) - (2)].fnsig)->param, &*(yysemantic_stack_[(3) - (2)].fnsig)->ret, dynamic_cast<EnclosedExpr *>((yysemantic_stack_[(3) - (3)].expr)));
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4838 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 4842 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 4851 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 4860 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 4864 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)), dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 4873 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 4890 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 4896 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 4902 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 4912 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 4916 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 4922 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 4928 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 4932 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 4938 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 4942 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 4948 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 4954 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 4961 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 4971 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 4976 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 4984 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 4990 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5000 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5022 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5031 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5037 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5050 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5064 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5071 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5077 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5087 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5092 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5098 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 5108 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 5121 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5127 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5148 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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
#line 5166 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5170 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5183 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EvalExpr(
                LOC((yyloc)), dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)), (yysemantic_stack_[(7) - (6)].expr)
            );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5189 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EvalExpr( LOC((yyloc)), new VarGetsDeclList( LOC((yyloc)) ), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5195 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("xquery"); }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5196 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("empty"); }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5197 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("attribute"); }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5198 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("comment"); }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5199 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("document-node"); }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5200 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("element"); }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5201 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("item"); }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5202 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("if"); }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5203 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("node"); }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5204 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("processing-instruction"); }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5205 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema-attribute"); }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5206 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema-element"); }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5207 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("text"); }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5208 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("typeswitch"); }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5209 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("empty-sequence"); }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5210 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("boundary-space"); }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5211 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ft-option"); }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5212 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("base-uri"); }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5213 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lax"); }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5214 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("strict"); }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5215 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("idiv"); }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5216 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("document"); }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5217 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("not"); }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5218 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ftnot"); }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5219 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("not"); }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5220 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sensitive"); }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5221 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("insensitive"); }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5222 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("diacritics"); }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5223 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("without"); }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5224 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stemming"); }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5225 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("thesaurus"); }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5226 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stop"); }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5227 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("wildcards"); }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5228 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("entire"); }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5229 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("content"); }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5230 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("word"); }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5231 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("start"); }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5232 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("end"); }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5233 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("most"); }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5234 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("skip"); }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5235 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("copy"); }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5236 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("value"); }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5237 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("eq"); }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5238 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ne"); }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5239 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lt"); }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5240 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("le"); }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5241 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("gt"); }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5242 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ge"); }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5243 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("at"); }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5244 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("context"); }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5245 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("variable"); }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5246 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("return"); }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5247 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("for"); }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5248 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("outer"); }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5249 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sliding"); }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5250 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("tumbling"); }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5251 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("previous"); }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5252 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("next"); }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5253 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("only"); }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5254 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("when"); }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5255 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("count"); }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5256 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("in"); }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5257 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("let"); }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5258 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("where"); }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5259 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("by"); }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5260 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("group"); }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5261 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("order"); }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5262 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stable"); }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5263 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ascending"); }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5264 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("descending"); }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5265 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("greatest"); }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5266 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("least"); }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5267 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("collation"); }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5268 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("some"); }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5269 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("every"); }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5270 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("satisfies"); }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5271 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("case"); }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5272 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("as"); }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5273 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("then"); }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5274 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("else"); }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5275 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("or"); }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5276 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("and"); }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5277 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("instance"); }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5278 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("of"); }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5279 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("castable"); }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5280 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("to"); }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5281 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("div"); }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5282 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("mod"); }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5283 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("union"); }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5284 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("intersect"); }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5285 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("except"); }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5286 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("validate"); }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5287 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("cast"); }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5288 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("treat"); }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5289 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("is"); }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5290 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("preserve"); }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5291 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("strip"); }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5292 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("namespace"); }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5293 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("external"); }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5294 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("encoding"); }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5295 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("no-preserve"); }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5296 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("inherit"); }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5297 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("no-inherit"); }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5298 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("declare"); }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5299 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("construction"); }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5300 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ordering"); }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 5301 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("default"); }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 5302 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("copy-namespaces"); }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 5303 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("option"); }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 5304 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("version"); }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 5305 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("import"); }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 5306 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema"); }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 5307 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("module"); }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 5308 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("function"); }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 5309 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("score"); }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 5310 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("contains"); }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 5311 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("weight"); }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 5312 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("window"); }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 5313 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("distance"); }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 5314 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("occurs"); }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 5315 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("times"); }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 5316 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("same"); }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 5317 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("different"); }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 5318 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lowercase"); }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 5319 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("uppercase"); }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 5320 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("relationship"); }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 5321 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("levels"); }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 5322 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("language"); }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 5323 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("any"); }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 5324 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("all"); }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 5325 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("phrase"); }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 5326 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("exactly"); }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 5327 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("from"); }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 5328 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("words"); }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 5329 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sentences"); }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 5330 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sentence"); }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 5331 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("paragraph"); }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 5332 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("replace"); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 5333 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("modify"); }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 5334 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("first"); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 5335 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("insert"); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 5336 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("before"); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 5337 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("after"); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 5338 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("revalidation"); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 5339 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("with"); }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 5340 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("nodes"); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 5341 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("rename"); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 5342 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("last"); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 5343 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("delete"); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 5344 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("into"); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 5345 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("simple"); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 5346 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sequential"); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 5347 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("updating"); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 5348 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("deterministic"); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 5349 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("nondeterministic"); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 5350 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ordered"); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 5351 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("unordered"); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 5352 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("returning"); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 5353 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("block"); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 5354 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("exit"); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 5355 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("loop"); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 5356 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("while"); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 5357 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("break"); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 5358 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("continue"); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 5359 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("try"); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 5360 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("catch"); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 5361 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("eval"); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 5362 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("using"); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 5363 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("set"); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 5364 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("index"); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 5365 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("unique"); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 5366 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("non"); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 5367 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("on"); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 5368 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("range"); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 5369 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("equality"); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 5370 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("manually"); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 5371 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("automatically"); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 5372 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("maintained"); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 5373 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("decimal-format"); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 5374 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("decimal-separator"); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 5375 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("grouping-separator"); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 5376 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("infinity"); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 5377 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("minus-sign"); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 5378 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("NaN"); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 5379 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("percent"); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 5380 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("per-mille"); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 5381 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("zero-digit"); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 5382 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("digit"); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 5383 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("pattern-separator"); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 5384 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("collection"); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 5385 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("const"); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 5386 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("append-only"); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 5387 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("queue"); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 5388 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("mutable"); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 5389 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("read-only"); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 5390 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("integrity"); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 5391 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("constraint"); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 5392 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("check"); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 5393 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("key"); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 5394 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("foreach"); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 5395 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("foreign"); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 5396 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("keys"); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 5408 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 5416 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 5420 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 5427 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 5432 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 5440 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 5444 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 5451 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 5455 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 5462 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 5466 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 5473 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 5477 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 5486 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 5498 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 5502 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 5509 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 5513 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 5521 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 5529 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 5537 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 5541 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 5548 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 5552 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 5560 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 5571 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 5575 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 5583 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 5595 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 5601 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 5610 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 5614 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 5622 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 5626 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 5630 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 5637 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 5641 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 5648 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 5652 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 5660 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 5664 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 5668 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 5672 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 5676 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 5684 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 5692 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 5704 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 5716 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 5720 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 5724 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 5732 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 5738 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 5748 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 5752 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 5756 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 5760 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 5764 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 5768 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 5772 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 5776 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 5784 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 5788 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 5792 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 5796 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 5804 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::senstive
            );
        }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 5810 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 5820 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 5830 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 5834 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 5842 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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

  case 877:

/* Line 678 of lalr1.cc  */
#line 5852 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
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

  case 878:

/* Line 678 of lalr1.cc  */
#line 5863 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 5870 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 5874 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 5881 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 5885 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(1) - (1)].thesaurus_id_list);
        }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 5892 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 5897 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 5906 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 5915 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 5919 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 5926 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 5930 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 5938 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 5947 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 5954 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 5964 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 5968 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 5975 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 5981 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 5990 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 5994 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6001 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6006 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6018 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6026 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6038 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6046 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6050 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6058 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6062 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6066 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6074 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6082 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange(
                LOC((yyloc)),
                ft_range_mode::exactly,
                dynamic_cast<AdditiveExpr*>((yysemantic_stack_[(2) - (2)].expr))
            );
        }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6090 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange(
                LOC((yyloc)),
                ft_range_mode::at_least,
                dynamic_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (3)].expr))
            );
        }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6098 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange(
                LOC((yyloc)),
                ft_range_mode::at_most,
                dynamic_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (3)].expr))
            );
        }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6106 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange(
                LOC((yyloc)),
                ft_range_mode::from_to,
                dynamic_cast<AdditiveExpr*>((yysemantic_stack_[(4) - (2)].expr)),
                dynamic_cast<AdditiveExpr*>((yysemantic_stack_[(4) - (4)].expr))
            );
        }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6119 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6127 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6139 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6143 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6151 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;



/* Line 678 of lalr1.cc  */
#line 11051 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1295;
  const short int
  xquery_parser::yypact_[] =
  {
      1522, -1295, -1295, -1295, -1295,   763,   -42, -1295, -1295,   -63,
   -1295, -1295, -1295, -1295,   141,    97,  9338,   159,   252,   183,
     191,   409, -1295,    23, -1295, -1295, -1295, -1295, -1295, -1295,
     365, -1295,  7630, -1295, -1295,   282, -1295,   340, -1295, -1295,
     346, -1295,   481, -1295,   331, -1295,   -22, -1295, -1295, -1295,
   -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295, -1295, -1295, -1295, -1295,  9621, -1295,  7052, -1295,
   -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295, 11036, -1295, -1295, -1295, -1295, -1295, -1295, -1295,
   -1295,   400, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295, -1295,  1814, 11036, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295,   322, -1295, -1295, -1295,  8204, -1295,  8489, -1295,
   -1295, -1295, -1295, -1295, 11036, -1295, -1295,  6761, -1295, -1295,
   -1295, -1295, -1295, -1295,   438, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295, -1295,    33,   406, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295, -1295,   154,   477,   283, -1295,   426,   399, -1295,
   -1295, -1295, -1295, -1295, -1295,   539, -1295,   518,   425,   437,
     442, -1295, -1295,   547,   521, -1295,   587, -1295, -1295, -1295,
   -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295, -1295, -1295, -1295, -1295,  4724,   700, -1295,  5015,
   -1295, -1295,   455,  5306,   537,   542, -1295, -1295, -1295, -1295,
   -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295, -1295, -1295, -1295, -1295, -1295,   -18, -1295, -1295,
   -1295, -1295,   432, 11036, -1295, -1295, -1295, -1295, -1295,   570,
     647, -1295,   694,   493,   328,   427,   323,   150, -1295,   690,
     545,   642,   656,  5597, -1295, -1295, -1295,    -8, -1295, -1295,
    6761, -1295,   514, -1295,   592,  7052, -1295,   592,  7052, -1295,
   -1295, -1295,   413, -1295, -1295, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295, -1295, -1295, -1295,   453, -1295, -1295,   732,   210,
     219,   266,   505, 11036,   505, 11036,   -31,   713,   714,   716,
   11036,   614,   648,   256,  8204, -1295, -1295,   470,   411,   520,
   11036, -1295, -1295, -1295, -1295, -1295,   475, 11036,   471,   472,
     468,   392, -1295, -1295, -1295,  8204,  5306,   588,  5306,    68,
   -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295,  5306,  9904, -1295, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295,
     620,  5306,   490,   497, -1295,   663,   -37,   632,  5306,    63,
      41, 11036,   666, -1295,  5306,  7917,   636, -1295, 11036, 11036,
   11036,  5306,   604,  5306, 11036,  5306,   638,   639,  5306, 10187,
     640,   641,   643,   646,   649,   651, -1295, -1295, -1295, 11036,
   -1295,   608,   760,  5306,    51, -1295,   774,   622, -1295,  5306,
     596, -1295,   785,  5306,  5306,   630,  5306,  5306,  5306,  5306,
     586, 11036, -1295, -1295, -1295, -1295,  5306,  5306,  5306, 11036,
   -1295, -1295, -1295, -1295,   763,   409, -1295, -1295,   455,   784,
    5306, -1295,  5306,   699,   252,    23,   365,   653,   655,   658,
    5306,  5306, -1295, -1295, -1295, -1295, -1295, -1295, -1295,   720,
   -1295,   -43,  5888,  5888,  5888, -1295,  5888,  5888, -1295,  5888,
   -1295,  5888, -1295, -1295, -1295, -1295, -1295, -1295, -1295,  5888,
    5888,   757,  5888,  5888,  5888,  5888,  5888,  5888,  5888,  5888,
    5888,  5888,  5888,   605,   742,   743,   745, -1295, -1295, -1295,
    2105, -1295, -1295,  6761,  6761,  5306,   592, -1295, -1295,   592,
   -1295,  2396,   592,   693,  2687, -1295, -1295, -1295, -1295, -1295,
   -1295,   734,   737, -1295,   183, -1295,   818, -1295, -1295, 11036,
   -1295, -1295, 11036, -1295,   668,   355, 11036,   511,   688,   692,
     668,   732,   723,   721, -1295, -1295, -1295, -1295, -1295,   155,
     607,   -24, -1295,   555, -1295, -1295, 11036, 11036, 11036, -1295,
     725,   675, -1295,   676,   643,   282, -1295,   677,   678,   682,
   -1295,   -32,     1,  2978,   683, -1295, -1295, 11036,   -14, 11036,
     765,     4, -1295,  5306, -1295,   684,  8204,   771,   825,  8204,
     732,   775,   766, -1295,   -48, -1295,   696,   695, -1295,   697,
    3269,   698,   738,   -30, -1295,   178,   702, -1295,   703,   729,
   -1295,   705,  5306,  5306,   707, -1295,    11,    12,  3560,   -25,
   -1295, 11036,   760, -1295,   -45,   708, -1295, -1295, -1295, -1295,
     709, -1295,   -44, -1295, -1295, -1295,    48,   100,   790,   657,
     670,   -28, -1295,   761,  6179, -1295,   718,   722,    39, -1295,
   -1295,   724, -1295,   247, -1295, -1295,   -10, 11036,   736,  5306,
     788, -1295, -1295,   791, 10470,   792,  5306,   793,   -15,   768,
     -52,   647, -1295, -1295, -1295, -1295, -1295,  5888, -1295, -1295,
   -1295,    18,   427,   427,   408,   323,   323,   323,   323,   150,
     150, -1295, -1295, 10470, 10470, 11036, 11036, -1295,   733, -1295,
   -1295,   750, -1295, -1295, -1295,   166, -1295, -1295,   173,   429,
     430,   439, -1295,   183,   183, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295, -1295, -1295, -1295,   668, -1295,   786, 10753,   778,
    5306, -1295, -1295, -1295,   821,   779,  5306,   732,   732,   668,
   -1295,   590,   732,   386, 11036,   137,   361,   893, -1295, -1295,
     650,   186, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295, -1295,   155,   119,   431, -1295,   711,  -212,   -20,
     629,   732, -1295, -1295, -1295, -1295,   782, 11036, -1295, 11036,
   -1295, -1295,   753, -1295,   262,   686, -1295, -1295,   556,   -14,
     821, 10470,   819,   846,   762,   746,   812,   732,   787,   814,
     850,   732,   829,  5306,   808,   -62,   798, -1295, -1295, -1295,
     770, -1295,  5306,   834,  5306,  5306,   809, -1295,   857,  5306,
   -1295,   777,   780,   813, 11036, -1295, 11036, -1295, -1295,   789,
    5306,   925, -1295,    -5, -1295,    83, -1295, -1295,   933, -1295,
     463,  5306,  5306,  5306,   464,  5306,  5306,  5306,  5306,  5306,
    5306,   845,  5306,  5306,   648,    -7,   794,   518,   727,   815,
     847,   784,   889, -1295, -1295,  5306,   534,   865, -1295, 11036,
     866, -1295, 11036,   820,   822, 10753,   823, -1295,   243, -1295,
   -1295, -1295, -1295, -1295, -1295, -1295, 11036, -1295, 11036,  5306,
     833,  5306,  5306,    -6,   835, -1295,  5306,    18,    28,   167,
   -1295,   701,     7,   726,   728, -1295, -1295,   520, -1295,   730,
     220, -1295, -1295, -1295,   840, -1295, -1295, -1295,  5306, -1295,
   -1295, -1295, -1295, -1295, -1295, -1295,  5306, -1295,   443,   452,
   -1295,   957,   526, -1295, -1295, -1295,  5306, -1295, -1295, -1295,
   -1295, -1295, -1295, -1295,   710, -1295, -1295,   959, -1295, -1295,
   -1295, -1295, -1295,   269,   961, -1295,   492, -1295, -1295, -1295,
     641,    97,   646,   649,   651,   477,   755,   243,   767,   769,
    6470,   712,   689,   119, -1295,   772,   811,  3851,   816,   817,
     860,   824,   826, -1295,  5306,   858, -1295,   886,   887,  5306,
   11036,   594,   929, -1295, -1295, -1295, -1295, -1295, -1295, 10470,
   -1295,  5306,   732,   900, -1295, -1295, -1295,   732,   900, 11036,
   -1295,  5306,  5306,   869,  4142, -1295, -1295, 11036, -1295, -1295,
    5306,  9055,    77, -1295,   830, -1295, -1295,  4433,   828,   831,
   -1295, -1295, -1295,   884, -1295,   192, -1295, -1295,  1003, -1295,
   -1295, 11036, -1295, -1295,   198, -1295, -1295, -1295,   832,   796,
     797, -1295, -1295, -1295,   799,   800, -1295, -1295, -1295, -1295,
   -1295,   783, 11036,   839, -1295,   877, -1295,   648, -1295, -1295,
   -1295,  7343,   727, -1295,  5306, 11036,   865, -1295,   732, -1295,
     597, -1295,   226,   918, -1295,  5306,   919,   788, -1295,  8772,
     848,   849,   851, -1295, -1295, -1295, -1295, -1295, -1295, -1295,
    5306, -1295, -1295,  5306,   891,  5306,   853,   854, -1295,    18,
     795, -1295, -1295,   -82, -1295,   381,   -38,   805,    18,   381,
    5888, -1295,   242, -1295, -1295, -1295, -1295, -1295, -1295,    18,
     892,   748,   607,   -38, -1295, -1295,   756,   962, -1295, -1295,
   -1295, -1295, -1295,   861, -1295, -1295, -1295,  5306, -1295, -1295,
   -1295, -1295, -1295,  1016,   157,  1018,   157,   776,   951, -1295,
   -1295, -1295, -1295,   880, 11036,   804,   755,  6470, -1295, -1295,
     881, -1295, -1295, -1295, -1295, -1295, -1295,  5306, 11036, 11036,
   -1295,   466, -1295,  5306, -1295,   937,   967,   732,   900, -1295,
   -1295, -1295,  5306, -1295,   885, -1295, -1295, 11036,   882,   144,
   -1295, -1295, -1295,   888, -1295, -1295,   925, 11036,   376, -1295,
     925, 11036, -1295, -1295,  5306,  5306,  5306,  5306,  5306, -1295,
    5306,  5306, -1295, -1295,   -34, -1295,   894, -1295, -1295, -1295,
   -1295,   918, -1295, -1295, -1295,   732, -1295, -1295,   973,   890,
   -1295,   189, -1295, -1295, -1295, -1295, -1295,  5306, -1295, -1295,
   -1295, -1295,   895,  5888, -1295, -1295, -1295, -1295, -1295,    24,
    5888,  5888,   368, -1295,   726, -1295,   336, -1295,   728,    18,
     917, -1295, -1295,   802, -1295, -1295, -1295, -1295, -1295,     3,
   -1295,    -9,    -9, -1295,   157, -1295, -1295,   217, -1295,  1043,
     -38,   898,   965, -1295,  6470,   -70,   801, -1295,   905, -1295,
   -1295, -1295,  1024, -1295, -1295,  5306,   732, -1295, -1295, -1295,
     984,  5306, 11036,  5306, -1295,   -13,   925, 11036,   897,   925,
   -1295, -1295, -1295, -1295, -1295, -1295, -1295,   966,  7343, -1295,
   -1295, -1295, -1295, 10470, -1295, 10470,   985, -1295, -1295,   323,
    5888,  5888,   408,   332, -1295, -1295, -1295, -1295, -1295, -1295,
    5306, -1295, -1295, -1295, -1295, -1295,  1056, -1295, -1295, -1295,
     836, -1295,   951,   978, -1295,   992, 11036,   970,   870, 11036,
    6470,   971, -1295,   900, 10470, -1295,   909, -1295,   146,   255,
   -1295,   901,   925, -1295,   902, 11036, -1295, -1295, -1295, 10470,
     408,   408,  5888,   913, -1295, -1295, -1295,  6470, 11036,   803,
   11036,   979,   876,   978, 11036,   920,  5306, -1295, -1295,  1008,
     296, -1295, -1295, -1295, -1295,   924,   318, -1295, -1295, -1295,
     911, -1295,   229, -1295,   408, -1295, -1295,   918,  5306,   806,
   11036,   989, -1295,  5306, -1295, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295,   990,   960, -1295, -1295,   827,   807, 11036, -1295,
   11036, -1295,   838,  5306,   841,   241,  6470, -1295,  6470,   994,
     960, -1295,   921, 11036, -1295,   837,   931, 11036,   960,   903,
   -1295,   995, 11036,   842,  6470, -1295
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   402,   403,   601,   556,   708,   717,   622,   620,   608,
     709,   712,   665,   758,   626,   609,   610,   771,   657,   718,
     612,   715,   687,   667,   643,   662,   759,   663,   713,   710,
     658,   661,   614,   716,   615,   616,   756,   773,   755,   659,
     678,   672,   617,   660,   618,   757,   696,   664,   640,   783,
     784,   785,   786,   787,   788,   789,   790,   791,   792,   793,
     393,   396,   686,   682,   673,   653,   607,   383,     0,   681,
     689,   697,   381,   677,   422,   654,   655,   711,   382,   385,
     674,   691,     0,   428,   391,   424,   684,   606,   675,   676,
     704,   679,   695,   703,   387,   386,   625,   666,   706,   423,
     694,   699,   611,     0,     0,   340,   692,   702,   707,   705,
     685,   671,   760,   669,   670,   392,     0,   339,     0,   395,
     394,   700,   656,   680,     0,   384,   369,     0,   401,   701,
     683,   690,   698,   693,   761,   647,   652,   651,   650,   649,
     648,   619,   668,     0,   605,   714,   641,   747,   746,   748,
     624,   623,   644,   753,   613,   745,   750,   751,   742,   646,
     688,   744,   754,   752,   743,   645,   749,   763,   767,   768,
     764,   765,   762,   766,   769,   770,   772,   734,   733,   720,
     639,   632,   727,   723,   642,   638,   736,   737,   628,   627,
     621,   631,   732,   731,   728,   724,   741,   735,   730,   726,
     719,   630,   740,   739,   634,   636,   635,   725,   729,   721,
     637,   722,   633,   738,   794,   795,   796,   797,   798,   799,
     775,   776,   774,   780,   781,   782,   777,   778,   779,   800,
     801,   802,   803,   804,   805,   806,     0,     0,     2,     0,
       4,     6,    12,     0,     0,     0,    18,    20,    29,    22,
      23,    24,    50,    25,    34,    30,    54,    55,    56,    51,
      52,    58,    59,    28,    26,    27,    32,    33,    53,   198,
     197,   194,   195,   196,    31,    11,   175,   176,   180,   182,
     213,   219,     0,     0,   211,   212,   183,   184,   185,   186,
     295,   297,   299,   309,   313,   315,   318,   323,   326,   329,
     331,   333,   335,     0,   337,   343,   345,     0,   361,   344,
     365,   368,   370,   373,   375,     0,   380,   377,     0,   388,
     398,   400,   374,   404,   411,   420,   412,   413,   414,   417,
     418,   415,   416,   435,   437,   438,   439,   436,   484,   485,
     486,   487,   488,   489,   397,   530,   522,   529,   528,   527,
     524,   526,   523,   525,   421,   419,   557,   558,    57,   187,
     188,   190,   189,   191,   192,   399,   193,   602,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   107,   108,     0,     0,     0,
       0,   103,   104,   105,   106,   111,     0,     0,     0,     0,
       0,     0,   101,   156,   159,     0,     0,     0,     0,     0,
     708,   717,   608,   626,   609,   610,   771,   657,   718,   612,
     715,   667,   658,   614,   616,   773,   678,   617,   618,   696,
     607,   679,     0,     0,   760,   761,   605,   753,   613,   745,
     751,   742,   645,   763,   767,   768,   764,   766,   769,   772,
       0,     0,     0,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,   599,     0,     0,     0,   600,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   608,   610,   614,   617,   607,   389,   399,   425,     0,
     426,     0,   451,     0,     0,   364,     0,     0,   367,     0,
       0,   480,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   146,   143,   154,   155,     0,     0,     0,     0,
       3,     1,     5,     7,     0,     0,    13,    10,    15,    16,
       0,   178,   177,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   199,   218,   214,   220,   215,   217,   216,   223,
     224,     0,     0,     0,     0,   354,     0,     0,   352,     0,
     304,     0,   353,   346,   351,   350,   349,   348,   347,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   342,   341,   338,
       0,   362,   366,     0,     0,     0,   376,   408,   379,   378,
     390,     0,   405,     0,     0,   598,    76,    61,    62,   137,
     138,     0,     0,   158,     0,   157,     0,    67,    68,     0,
     162,   160,     0,   161,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   567,   568,   569,   110,   109,     0,
      66,   115,   112,     0,   114,   113,     0,     0,     0,   102,
       0,     0,   536,     0,     0,     0,   532,     0,     0,     0,
     546,     0,     0,     0,     0,   201,   202,     0,     0,     0,
     139,     0,   169,     0,   560,     0,     0,    85,     0,     0,
       0,    77,   236,   237,     0,   222,     0,     0,   537,     0,
       0,     0,     0,     0,   284,     0,     0,   535,     0,     0,
     554,     0,     0,     0,     0,   540,     0,     0,     0,     0,
     427,   452,   451,   448,     0,     0,   482,   481,   363,   545,
       0,   479,     0,   580,   581,   531,     0,     0,     0,     0,
       0,     0,   586,     0,     0,   152,     0,     0,     0,   239,
     256,     0,    19,     0,    21,   181,     0,     0,     0,     0,
       0,   200,   257,     0,     0,     0,     0,     0,     0,     0,
       0,   296,   298,   302,   308,   307,   306,     0,   303,   300,
     301,     0,   317,   316,   314,   320,   321,   322,   319,   324,
     325,   328,   327,     0,     0,     0,     0,   359,     0,   371,
     372,     0,   409,   406,   433,     0,   559,   431,     0,     0,
       0,     0,    65,     0,     0,    40,    42,    43,    44,    45,
      47,    48,    49,    41,    46,    36,    37,     0,     0,    93,
       0,    89,    91,    92,    96,    99,     0,     0,     0,    35,
      75,     0,     0,     0,     0,     0,     0,     0,   869,   874,
       0,     0,   870,   904,   857,   859,   860,   861,   863,   865,
     864,   862,   866,     0,     0,     0,   116,     0,     0,   119,
       0,     0,   500,   490,   533,   534,     0,     0,   550,     0,
     547,   491,     0,   604,     0,     0,   203,   204,     0,   209,
     171,     0,     0,   140,     0,     0,     0,     0,     0,     0,
      78,     0,     0,     0,     0,     0,     0,   539,   538,   501,
       0,   553,     0,     0,     0,     0,     0,   499,     0,     0,
     355,     0,     0,     0,     0,   543,     0,   541,   495,     0,
       0,   451,   449,     0,   440,     0,   429,   430,     0,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   708,     0,     0,     0,     0,     0,
       0,    17,     0,   179,   210,     0,   268,   264,   266,     0,
     258,   259,     0,   718,   611,     0,   619,   507,   508,   514,
     515,   517,   561,   562,   518,   521,     0,   226,     0,     0,
       0,     0,     0,     0,     0,   305,     0,     0,     0,     0,
     835,   311,   808,   812,   814,   816,   818,   821,   828,   829,
     837,   330,   332,   334,   505,   336,   360,   410,     0,   407,
     432,    73,    74,    71,    72,   164,     0,   163,     0,     0,
      38,     0,     0,    94,    95,    97,     0,    98,    63,    64,
      69,    70,    60,   875,     0,   878,   905,     0,   868,   867,
     872,   871,   903,     0,     0,   880,     0,   876,   879,   858,
       0,     0,     0,     0,     0,     0,   117,   123,     0,     0,
       0,     0,     0,     0,   120,     0,     0,     0,     0,     0,
     554,     0,     0,   492,     0,     0,   205,     0,     0,     0,
       0,   250,     0,   247,   252,   208,   172,   141,   170,     0,
     173,     0,     0,    87,    81,    84,    83,     0,    79,     0,
     241,     0,     0,     0,     0,   502,   151,     0,   282,   286,
       0,     0,     0,   290,     0,   357,   356,     0,     0,     0,
     496,   283,   452,     0,   441,     0,   475,   472,     0,   476,
     477,     0,   478,   471,     0,   446,   474,   473,     0,     0,
       0,   573,   574,   570,     0,     0,   578,   579,   575,   584,
     582,     0,     0,     0,   588,   149,   148,     0,   145,   144,
     153,     0,   589,   590,     0,     0,   265,   277,     0,   278,
       0,   269,   270,   271,   272,     0,   261,     0,   225,     0,
       0,     0,     0,   511,   513,   512,   509,   234,   235,   228,
       0,   230,   227,     0,     0,     0,     0,     0,   819,   832,
       0,   310,   312,     0,   851,     0,     0,     0,     0,     0,
       0,   807,   809,   810,   846,   847,   848,   850,   849,     0,
       0,   823,   822,     0,   826,   830,   844,   842,   841,   834,
     838,   506,   434,     0,   166,   165,   168,     0,    39,    90,
     100,   892,   873,     0,   897,     0,   897,   886,   881,   118,
     124,   126,   125,     0,     0,     0,   121,     0,    14,   493,
       0,   551,   552,   555,   548,   549,   245,     0,     0,     0,
     207,   248,   251,     0,   142,     0,    86,     0,    80,   238,
     243,   242,     0,   503,     0,   285,   287,     0,     0,     0,
     291,   358,   497,     0,   544,   542,   451,     0,     0,   483,
     451,     0,   447,     9,     0,     0,     0,     0,     0,   587,
       0,     0,   147,   596,     0,   591,     0,   240,   281,   279,
     280,   273,   274,   275,   267,     0,   262,   260,     0,     0,
     519,     0,   516,   566,   510,   232,   229,     0,   231,   836,
     827,   833,     0,     0,   906,   907,   917,   916,   915,     0,
       0,     0,     0,   908,   813,   914,     0,   811,   815,     0,
       0,   820,   824,     0,   845,   840,   843,   839,   174,     0,
     893,     0,     0,   891,   898,   899,   895,     0,   890,     0,
     888,     0,   882,   883,     0,     0,     0,   122,     0,   494,
     246,   254,   255,   249,   206,     0,     0,    82,   244,   504,
       0,     0,     0,     0,   498,     0,   451,     0,     0,   451,
     571,   572,   576,   577,   583,   585,   150,     0,     0,   592,
     603,   276,   263,     0,   563,     0,     0,   233,   831,   918,
       0,     0,   910,     0,   856,   855,   854,   853,   852,   817,
       0,   909,   167,   902,   901,   900,     0,   894,   887,   885,
       0,   877,     0,   127,   129,     0,     0,     0,     0,     0,
       0,     0,   294,    88,     0,   292,     0,   288,   461,   455,
     450,     0,   451,   442,     0,     0,   597,   564,   520,     0,
     912,   911,     0,     0,   896,   889,   884,     0,     0,     0,
       0,     0,     0,   128,     0,     0,     0,   469,   463,     0,
     462,   464,   470,   467,   457,     0,   456,   458,   468,   444,
       0,   443,     0,   565,   913,   825,   130,   131,     0,     0,
       0,     0,   253,     0,   289,   454,   465,   466,   453,   459,
     460,   445,     0,     0,   132,   133,     0,     0,     0,   293,
       0,   593,     0,     0,     0,     0,     0,   135,     0,     0,
       0,   134,     0,     0,   594,     0,     0,     0,     0,     0,
     595,     0,     0,     0,     0,   136
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1295, -1295,   873, -1295,   872,   874, -1295,   875, -1295,   593,
     595,  -515, -1295,   484,  -194, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295,  -874,
   -1295, -1295, -1295, -1295,    96,   301,   740, -1295, -1295,   731,
   -1295,    61,  -837, -1295,  -335,  -361, -1295, -1295,  -578, -1295,
    -849, -1295, -1295,   -29, -1295, -1295, -1295, -1295, -1295,   319,
     749, -1295, -1295, -1295,   248,   674, -1294,   899,   -85, -1295,
    -531,  -389, -1295, -1295, -1295, -1295,   254, -1295, -1295,   855,
   -1295, -1295, -1295, -1295, -1295,   179,  -518,  -661, -1295, -1295,
   -1295,    44, -1295, -1295,  -131,    65,   -21, -1295, -1295, -1295,
     -27, -1295, -1295,   193,   -23, -1295, -1295,   -19, -1141, -1295,
     662,    40, -1295, -1295,    43, -1295, -1295,   606,   603, -1295,
    -514, -1295, -1295,  -572,   147,  -571,   145,   148, -1295, -1295,
   -1295, -1295, -1295,   856, -1295, -1295, -1295, -1295,  -758,  -297,
   -1039, -1295,  -124, -1295, -1295, -1295, -1295, -1295, -1295, -1295,
     -39, -1136, -1295, -1295,   347,   -40, -1295,  -752, -1295, -1295,
   -1295, -1295, -1295, -1295, -1295,   553, -1295,  -901, -1295,    35,
   -1295,   449,  -701, -1295, -1295, -1295, -1295, -1295,  -344,  -336,
   -1077,  -930, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295,   379,  -631,  -757,   109,  -769, -1295,  -777,  -724,
   -1295, -1295, -1295, -1295, -1295, -1295, -1295,   758,   759,  -423,
     300,   149, -1295, -1295, -1295, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295, -1295, -1295, -1295, -1295,    19, -1295, -1295,    10,
   -1295,  -353,  -104,   -16, -1295, -1295,  -959, -1295, -1295, -1295,
     -35,   -41,  -185,   187, -1295, -1295, -1295, -1295, -1295, -1295,
   -1295, -1295, -1295, -1295, -1295, -1295, -1295,   -36, -1295, -1295,
   -1295,  -179,   182,   327, -1295, -1295, -1295, -1295, -1295,   135,
   -1295, -1295, -1214, -1295, -1295, -1295,  -645, -1295,   -64, -1295,
    -191, -1295, -1295, -1295, -1295, -1134, -1295,   -17, -1295
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   815,   816,   817,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,  1093,
     680,   262,   263,   821,   822,   823,  1155,   264,   401,   402,
     265,  1056,   856,   266,  1453,  1454,   267,   268,   457,   269,
     513,   734,   945,  1156,   270,   271,   272,   273,   274,   403,
     404,   620,   623,   671,   672,  1132,  1017,   275,   276,   532,
     277,   278,   279,   542,   455,   878,   879,   280,   543,   281,
     545,   282,   283,   284,   549,   550,  1081,   759,   285,   682,
     738,   683,   668,  1082,  1083,  1084,   739,   546,   547,   960,
     961,  1326,   548,   957,   958,  1171,  1172,  1173,  1174,   286,
     693,   694,   287,  1112,  1113,   288,   289,   290,   291,   767,
     292,  1201,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   569,   570,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   596,   597,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   795,   332,   333,   334,  1134,
     712,   713,   714,  1470,  1505,  1506,  1499,  1500,  1507,  1501,
    1135,  1136,   335,   336,  1137,   337,   338,   339,   340,   341,
     342,   343,  1003,   760,   967,  1186,   968,  1331,   969,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   699,
    1069,   354,   355,   356,   357,   971,   972,   973,   974,   358,
     359,   360,   361,   362,   363,   731,   732,   364,  1162,  1163,
    1314,  1094,   466,   365,   366,   367,   991,  1211,  1212,   992,
     993,   994,   995,   996,  1221,  1361,  1362,   997,  1224,   998,
    1342,   999,  1000,  1229,  1230,  1367,  1365,  1213,  1214,  1215,
    1216,  1437,   640,   844,   845,   846,   847,   848,   849,  1047,
    1381,  1382,  1048,  1380,  1449,   850,  1246,  1377,  1373,  1374,
    1375,   851,   852,  1217,  1225,  1352,  1218,  1348,  1202
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       450,   746,   774,   498,   775,   776,   777,   778,  1004,  1004,
     591,   923,   494,   989,   744,   606,   467,  1098,   491,   990,
    1419,  1253,  1064,   894,  1133,  1313,  1001,  1002,  1197,   486,
     970,  1322,  1323,   758,  1383,   875,   801,   755,     4,   754,
     763,  1456,   764,   765,   754,   766,   755,   768,     4,  1022,
     480,  1349,   487,   895,   500,   769,   770,  1302,   716,   970,
     970,   605,   664,   854,   906,   474,   488,  1063,   867,  1430,
     903,  1102,   941,  1468,   669,   903,   924,   949,   928,  1061,
    1243,   406,   530,   605,   407,   893,   982,  1062,   492,  1363,
     530,  1126,  1127,  1157,   970,   756,  1203,   980,  1160,   984,
     467,   869,   496,   530,   882,   654,   677,   681,   497,   405,
    1016,   914,   916,  1417,   723,   724,  1124,   726,   727,   728,
     729,    74,   475,   979,  1087,   655,  1344,   735,   736,   617,
    1057,    74,  1193,    85,   461,   930,   590,   929,  1245,   950,
     670,   745,   925,    85,  1431,   868,  1457,   678,   904,  1050,
    1497,   751,   752,   920,  1126,  1051,   654,   970,    99,   118,
    1469,   618,   986,   531,  1345,   987,  1418,  1204,    99,  1235,
    1111,   953,   986,  1052,  1158,   987,   655,  1442,   870,  1128,
    1421,   883,  1125,  1289,  1053,   118,   592,   934,   915,   917,
     476,   477,   679,  1025,   876,   118,  1181,  1129,   942,  1130,
    1126,  1127,   833,   757,   855,   834,  1126,  1127,   855,  1054,
    1350,  1351,   794,   757,   676,   794,   717,   757,  1388,  1249,
    1123,  1302,   757,  1278,  1133,  1018,  1019,   673,  1458,   989,
     989,   104,   877,  1133,  1103,   990,   990,   501,  1486,  1541,
    1341,   970,   983,  1075,   409,   656,  1450,   116,   835,  1086,
     757,  1205,  1206,   985,  1207,  1402,  1554,   931,   932,   757,
    1129,  1208,  1130,  1126,  1560,   754,  1008,   551,  1131,   988,
    1498,  1209,   933,  1008,  1503,  1044,   598,   581,   830,   600,
     633,   372,  1476,  1210,  1371,   408,   143,   373,  1128,  1425,
     673,   582,  1045,   628,  1128,   374,   629,   375,   124,   487,
    1497,   650,   487,   451,  1126,   377,  1129,   378,  1130,   935,
     936,  1199,  1129,   452,  1130,   379,   905,  1446,   453,   380,
    1403,   651,  1194,   653,   937,  1168,  1126,   890,   630,  1532,
     456,  1203,  1274,  1046,   118,  1055,   673,  1503,   458,  1057,
     104,  1549,   673,  1009,  1170,  1455,   104,   659,  1372,   754,
    1010,   381,   382,   952,  1288,   631,   116,   614,  1243,   616,
     956,   689,   116,   454,   624,   970,  1426,   977,   467,  1129,
     503,  1130,   504,   675,   641,  1244,  1534,  1297,  1183,   686,
    1504,   643,   607,  1301,  1126,  1127,   696,   970,   698,   467,
     701,   609,  1038,   704,  1447,   143,   608,  1133,   836,   673,
    1074,   143,  1204,  1039,   462,   610,  1533,   385,   715,  1184,
    1129,   837,  1130,   838,   720,   632,  1245,   662,  1550,  1387,
    1526,  1455,  1330,   611,   839,   840,   841,  1185,   842,   468,
     843,  1024,  1129,   737,  1130,   459,   744,  1027,   612,   386,
     673,   989,   818,  1529,  1068,   684,  1071,   990,  1455,   467,
     989,   469,   691,   692,   695,   970,   990,   470,   700,  1226,
    1227,   989,   673,   707,   460,   533,   493,   990,   388,   789,
     790,   534,  1128,   695,  1028,  1029,   535,   572,   473,  1032,
     524,   572,  1228,   819,   536,   572,  1205,  1206,   820,  1207,
    1129,  1118,  1130,  1119,   573,   733,   537,   525,   573,   506,
     389,   507,   573,   740,  1100,   788,  1209,  1551,  1066,  1552,
     791,   489,  1077,  1106,   579,  1108,  1109,   574,  1210,  1078,
     673,  1482,  1463,   580,   104,  1565,   390,   391,   392,   393,
     394,  1121,   395,   396,   397,   398,   399,   575,  1502,  1508,
     116,   400,  1141,  1142,  1143,   373,  1146,  1147,  1148,  1149,
    1150,  1151,   385,  1153,  1154,   755,   792,   572,   595,   792,
     601,  1407,   792,   377,   576,   378,   956,  1015,  1011,  1013,
    1502,  1234,   886,   379,   573,   889,  1508,   577,   872,   143,
    1236,  1044,   499,  1016,   386,  1012,  1014,   512,   884,   603,
    1189,   538,  1191,  1192,   539,  1405,  1237,  1434,  1045,  1408,
     604,   989,  1077,   803,  1435,   900,   804,   990,   540,  1078,
     824,   578,   502,   388,  1436,   509,  1040,   911,   912,  1232,
     510,  1020,  1167,   919,   505,   471,  1079,  1041,   472,  1434,
     858,   859,   860,  1168,   541,  1020,  1435,  1240,  1356,   825,
    1077,  1346,   508,  1169,   826,   755,  1436,  1078,  1347,   946,
     511,   874,  1170,   880,   819,  1033,  1034,  1035,   514,   820,
     467,  1036,   512,   467,   599,   518,  1477,  1080,  1478,   602,
     515,   647,   391,   392,   393,   394,   516,   395,   396,   648,
     398,   399,   634,   635,   636,  1266,  1139,  1144,  1140,  1145,
    1270,   613,   591,   615,   517,   921,   593,   594,   519,   970,
     521,   970,  1275,   637,   638,  1471,  1369,  1495,  1474,  1030,
    1031,  1517,  1280,  1281,  1058,  1059,  1319,  1320,   528,   772,
     773,  1286,  1513,   529,   779,   780,  1443,  1444,   552,   781,
     782,   954,   553,   583,   571,   584,   585,   595,   975,  1276,
     970,   805,   806,   807,   808,   809,   810,   811,   812,   813,
     814,   586,   605,   619,   373,   970,   622,   625,   639,   626,
     642,   644,   645,   646,   663,   652,   665,   975,   975,   975,
     975,  1510,  1429,   666,   667,  1316,   673,   685,  1432,  1433,
     690,   697,   702,   703,   708,   710,   956,   711,   407,   718,
     433,   368,   369,   465,   370,   371,   472,   372,   479,   719,
     721,  1335,   975,   373,  1336,   722,  1338,   725,   730,   743,
     747,   374,   748,   375,   376,  1318,   749,   554,  1037,   750,
     753,   377,   771,   378,  1114,   555,   556,   783,   557,   784,
     785,   379,   786,   796,   799,   380,   558,   800,   802,   827,
     559,   831,   560,   828,   832,   853,   857,   561,   861,   862,
     863,  1070,   881,  1070,   864,   865,   866,   873,  1480,  1481,
     887,   885,   888,   562,   891,   975,   892,   381,   382,   383,
     896,   902,   897,   909,   898,   901,   907,   938,  1390,   910,
     908,   913,   926,   927,  1394,   939,   940,   563,   564,   565,
     566,   567,   568,  1398,   943,   947,   948,   955,   700,   959,
     700,  1196,   962,   976,   978,   951,   981,  1006,   754,  1021,
    1514,   820,  1026,  1042,   384,  1410,  1411,  1412,  1413,  1414,
    1065,  1415,  1416,   385,  1397,  1007,  1067,  1073,  1043,  1060,
     669,  1233,  1076,  1089,  1091,  1092,  1090,  1096,  1095,  1097,
    1099,  1101,  1104,  1176,  1105,  1107,   551,  1110,  1427,   975,
    1111,  1115,  1122,  1138,  1116,   386,  1152,  1117,  1165,  1164,
    1187,   630,  1188,  1120,  1161,  1175,  1177,  1179,  1159,  1180,
    1182,  1190,  1422,  1195,   387,  1231,  1219,     4,  1200,  1242,
    1220,  1247,  1260,   855,   388,  1251,  1255,  1252,  1241,  1223,
    1257,  1254,  1258,  1261,  1262,  1263,  1267,  1268,  1269,  1273,
    1277,  1264,  1282,  1265,  1291,  1294,  1462,  1296,  1295,  1299,
    1311,  1308,  1465,  1303,  1467,  1310,   389,  1168,  1325,  1284,
    1304,  1305,  1360,  1306,  1307,  1332,  1333,  1339,  1334,  1337,
    1359,  1340,  1293,  1366,  1364,  1368,  1370,  1343,  1376,  1379,
    1044,  1384,   390,   391,   392,   393,   394,  1353,   395,   396,
     397,   398,   399,  1386,  1395,  1389,  1396,   400,  1401,  1399,
    1423,  1440,  1404,  1448,  1271,  1452,  1460,  1424,  1420,  1428,
    1461,  1464,  1479,   975,  1441,  1451,  1484,  1475,  1487,  1488,
    1459,  1490,  1494,   684,  1473,  1496,  1491,  1515,  1509,  1511,
    1520,   695,  1521,  1485,  1525,   975,  1523,  1528,  1531,  1518,
    1538,  1540,  1536,  1543,  1016,  1553,  1562,  1524,  1558,   520,
    1555,   522,  1542,   523,   829,  1300,  1557,   526,  1239,  1561,
    1023,   741,   627,   742,  1256,  1493,  1516,   621,  1312,  1535,
    1088,   674,   649,  1085,  1539,  1546,   733,   544,  1548,  1564,
    1393,  1178,   527,  1279,  1317,   487,  1272,  1285,  1166,   740,
    1327,   709,  1324,  1321,  1547,  1290,   762,   798,   761,   589,
    1298,   922,  1530,   975,  1527,  1005,  1250,   657,   658,  1072,
    1238,  1309,  1315,  1354,  1439,  1198,  1357,  1438,  1358,  1222,
    1049,  1248,  1378,  1445,     0,     0,     0,     0,     0,     0,
       0,     0,  1355,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1385,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1391,  1392,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1400,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1406,     0,     0,     0,  1409,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1483,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1466,     0,     0,     0,
       0,  1472,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   487,     0,     0,     0,     0,   975,     0,   975,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1489,     0,     0,  1492,     0,     0,     0,     0,   975,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1512,
       0,     0,     0,   975,     0,     0,     0,     0,     0,     0,
       0,     0,   975,     0,  1519,     0,     0,     0,  1522,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1537,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1544,     0,  1545,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,  1556,     0,     2,
       3,  1559,     4,     0,     0,     0,  1563,     5,     6,     0,
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
     186,   187,     0,   188,   189,   190,     0,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   410,
     411,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,   420,    22,    23,    24,
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
     122,   490,   123,   124,   125,     0,   126,   127,   128,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   436,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,     0,   188,   189,   190,     0,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     410,   411,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   420,    22,    23,
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
       0,   117,   118,     0,     0,   119,   120,   121,     0,   787,
       0,   122,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     436,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,     0,   188,   189,   190,     0,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,   410,   411,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,   420,    22,
      23,    24,    25,     0,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     0,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,     0,    72,    73,     0,     0,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,    85,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,   103,   104,   105,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   111,   112,   113,   114,   115,
     116,     0,   117,   118,     0,     0,   119,   120,   121,     0,
       0,     0,   122,   793,   123,   124,   125,     0,   126,   127,
     128,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   436,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,     0,   188,   189,   190,
       0,   191,   192,   193,   194,   195,   196,     0,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,   410,   411,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,   420,
      22,    23,    24,    25,     0,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,     0,    72,    73,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,    85,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,    91,    92,    93,    94,    95,     0,     0,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
     102,     0,     0,     0,   103,   104,   105,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,     0,   117,   118,     0,     0,   119,   120,   121,
       0,     0,     0,   122,   797,   123,   124,   125,     0,   126,
     127,   128,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   436,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,     0,   188,   189,
     190,     0,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,   410,   411,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
     420,    22,    23,    24,    25,     0,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     0,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,     0,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,     0,    72,    73,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,     0,    85,     0,    86,    87,    88,    89,     0,
      90,     0,     0,     0,    91,    92,    93,    94,    95,     0,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,   103,   104,   105,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,     0,   117,   118,     0,     0,   119,   120,
     121,     0,   871,     0,   122,     0,   123,   124,   125,     0,
     126,   127,   128,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   436,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,     0,   188,
     189,   190,     0,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,   410,   411,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,   420,    22,    23,    24,    25,     0,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     0,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,     0,    72,    73,     0,
       0,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,    85,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,   102,     0,     0,     0,   103,   104,   105,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,   117,   118,     0,     0,   119,
     120,   121,     0,   899,     0,   122,     0,   123,   124,   125,
       0,   126,   127,   128,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   436,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,     0,
     188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,   410,   411,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,   420,    22,    23,    24,    25,     0,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     0,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,     0,    72,    73,
       0,     0,     0,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     0,    85,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,    91,    92,    93,    94,
      95,     0,     0,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,   103,   104,   105,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,     0,   117,   118,     0,     0,
     119,   120,   121,     0,   918,     0,   122,     0,   123,   124,
     125,     0,   126,   127,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   436,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
       0,   188,   189,   190,     0,   191,   192,   193,   194,   195,
     196,     0,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   410,   411,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   420,    22,    23,    24,    25,     0,    26,
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
       0,   119,   120,   121,     0,  1259,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   436,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,     0,   188,   189,   190,     0,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   410,   411,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   420,    22,    23,    24,    25,     0,
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
       0,     0,   119,   120,   121,     0,  1283,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   436,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,   190,     0,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   410,   411,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,   420,    22,    23,    24,    25,
       0,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
       0,    72,    73,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,    85,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,    91,
      92,    93,    94,    95,     0,     0,     0,     0,     0,     0,
      96,    97,    98,    99,   100,   101,   102,     0,     0,     0,
     103,   104,   105,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,   116,     0,   117,
     118,     0,     0,   119,   120,   121,     0,  1292,     0,   122,
       0,   123,   124,   125,     0,   126,   127,   128,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   436,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,     0,   188,   189,   190,     0,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,     5,
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
     184,   185,   186,   187,     0,   188,   189,   190,     0,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,     1,     0,     0,     0,     0,
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
     436,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,     0,   188,   189,   190,     0,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,   410,   411,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,   420,    22,
      23,    24,    25,     0,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     0,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,     0,    72,    73,     0,     0,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,    85,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,   103,   104,   105,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   111,   112,   113,   114,   115,
     116,     0,   117,   118,     0,     0,   119,   120,   121,     0,
       0,     0,   122,     0,   123,   124,   125,     0,   126,   127,
     128,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   436,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,     0,   188,   189,   190,
       0,   191,   192,   193,   194,   195,   196,     0,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,   410,   411,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   416,   417,    19,   419,   420,
      22,   421,    24,    25,     0,    26,    27,    28,    29,   422,
      31,    32,    33,    34,    35,    36,   425,    38,    39,   426,
       0,    41,    42,    43,   428,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,     0,    72,    73,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,    85,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   431,    92,    93,    94,    95,     0,     0,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
     102,     0,     0,     0,   103,   104,   587,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,     0,   588,   118,     0,     0,   119,   120,   121,
       0,     0,     0,   122,     0,   123,   124,   125,     0,   126,
     127,   128,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   436,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   437,   154,   439,   156,   440,   441,   159,   160,
     161,   162,   163,   164,   442,   166,   443,   444,   445,   446,
     171,   172,   447,   448,   175,   449,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,     0,   188,   189,
     190,     0,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,   410,   411,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,   416,   417,    19,   419,
     420,    22,   421,    24,    25,     0,    26,    27,    28,    29,
     422,    31,    32,    33,    34,    35,    36,   425,    38,    39,
     426,     0,    41,    42,    43,   428,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,     0,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,     0,    72,    73,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,     0,    85,     0,    86,    87,    88,    89,     0,
      90,     0,     0,     0,   431,    92,    93,    94,    95,     0,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,   103,   104,   105,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,     0,   117,   118,     0,     0,   119,   120,
     121,     0,     0,     0,   122,     0,   123,   124,   125,     0,
     126,   127,   128,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   436,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   437,   154,   439,   156,   440,   441,   159,
     160,   161,   162,   163,   164,   442,   166,   443,   444,   445,
     446,   171,   172,   447,   448,   175,   449,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,     0,   188,
     189,   190,     0,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,   944,   411,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,   420,    22,    23,    24,    25,     0,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     0,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,     0,    72,    73,     0,
       0,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,    85,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,   102,     0,     0,     0,   103,   104,   105,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,   117,   118,     0,     0,   119,
     120,   121,     0,     0,     0,   122,     0,   123,   124,   125,
       0,   126,   127,   128,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   436,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,     0,
     188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,   410,   411,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,   416,   417,
      19,   419,   420,    22,   421,    24,    25,     0,    26,    27,
      28,    29,   422,    31,    32,    33,    34,    35,    36,   425,
      38,    39,   426,     0,    41,    42,    43,   428,    45,   429,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,     0,    72,    73,
       0,     0,     0,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     0,    85,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   431,    92,    93,    94,
      95,     0,     0,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,   103,   104,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,     0,     0,     0,     0,     0,
     119,   120,   121,     0,     0,     0,   122,     0,   123,   124,
     125,     0,   126,   127,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   436,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   437,   154,   439,   156,   440,
     441,   159,   160,   161,   162,   163,   164,   442,   166,   443,
     444,   445,   446,   171,   172,   447,   448,   175,   449,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
       0,   188,   189,   190,     0,   191,   192,   193,   194,   195,
     196,     0,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   410,   411,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,   416,
     417,    19,   419,   420,    22,   421,    24,    25,     0,    26,
      27,    28,    29,   422,    31,    32,    33,    34,    35,    36,
     425,    38,    39,   426,     0,    41,    42,    43,   428,    45,
     429,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,     0,    72,
      73,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,    85,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   431,    92,    93,
      94,    95,     0,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,   103,   104,
       0,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,     0,     0,     0,
       0,   119,   120,   121,     0,     0,     0,   122,     0,   123,
     124,   125,     0,     0,     0,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   436,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   437,   154,   439,   156,
     440,   441,   159,   160,   161,   162,   163,   164,   442,   166,
     443,   444,   445,   446,   171,   172,   447,   448,   175,   449,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,     0,   188,   189,   190,     0,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     0,     0,     0,     0,     0,   410,   411,     0,
       7,     8,   481,    10,    11,    12,    13,   413,    15,   482,
     416,   417,   418,   419,   420,    22,   421,    24,    25,     0,
      26,    27,    28,    29,   422,    31,   483,    33,    34,    35,
      36,   425,    38,    39,   426,     0,    41,   484,    43,   428,
      45,   429,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    62,     0,    63,
      64,    65,   485,     0,     0,    69,    70,    71,     0,     0,
       0,    73,     0,     0,     0,     0,    75,    76,    77,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   431,    92,
      93,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   434,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,     0,
     123,   124,     0,     0,     0,     0,   128,     0,   129,     0,
     130,   131,   132,   133,   435,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   436,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   437,   154,   439,
     156,   440,   441,   159,   160,   161,   162,   163,   164,   442,
     166,   443,   444,   445,   446,   171,   172,   447,   448,   175,
     449,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,   190,     0,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     0,     0,     0,     0,     0,   410,   411,
       0,     7,     8,   412,    10,    11,    12,    13,   413,   414,
     415,   416,   417,   418,   419,   420,    22,   421,    24,    25,
       0,    26,    27,    28,    29,   422,    31,   423,    33,    34,
     424,    36,   425,    38,    39,   426,     0,    41,   427,    43,
     428,    45,   429,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    62,     0,
      63,    64,    65,   430,     0,     0,    69,    70,    71,     0,
       0,     0,    73,     0,     0,     0,     0,    75,    76,    77,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   431,
      92,    93,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,   100,   101,   102,     0,     0,     0,
       0,     0,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   111,   434,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   122,
       0,   123,     0,     0,     0,     0,     0,   128,     0,   129,
       0,   130,   131,   132,   133,   435,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   436,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   437,   438,
     439,   156,   440,   441,   159,   160,   161,   162,   163,   164,
     442,   166,   443,   444,   445,   446,   171,   172,   447,   448,
     175,   449,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,     0,   188,   189,   190,     0,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   463,     0,     0,     0,     3,     0,
       0,     0,     0,     0,     0,   410,   411,     0,     7,     8,
     412,    10,    11,    12,    13,   413,   414,   415,   416,   417,
     418,   419,   420,    22,   421,    24,    25,     0,    26,    27,
      28,    29,   422,    31,   423,    33,    34,   424,    36,   425,
      38,    39,   426,     0,    41,   427,    43,   428,    45,   429,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    62,     0,    63,    64,    65,
     430,     0,     0,    69,    70,    71,     0,     0,     0,    73,
       0,     0,     0,     0,    75,    76,    77,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   431,    92,    93,     0,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,   100,   101,   102,   464,     0,     0,   465,     0,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   111,
     434,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   122,     0,   123,     0,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   435,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,     0,     0,   436,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   437,   438,   439,   156,   440,
     441,   159,   160,   161,   162,   163,   164,   442,   166,   443,
     444,   445,   446,   171,   172,   447,   448,   175,   449,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
       0,   188,   189,   190,     0,   191,   192,   193,   194,   195,
     196,     0,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   463,     0,     0,     0,     3,     0,   687,     0,     0,
       0,     0,   410,   411,     0,     7,     8,   412,    10,    11,
      12,    13,   413,   414,   415,   416,   417,   418,   419,   420,
      22,   421,    24,    25,     0,    26,    27,    28,    29,   422,
      31,   423,    33,    34,   424,    36,   425,    38,    39,   426,
       0,    41,   427,    43,   428,    45,   429,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    62,     0,    63,    64,    65,   430,     0,     0,
      69,    70,    71,     0,     0,     0,    73,     0,     0,     0,
       0,    75,    76,    77,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   431,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,   100,   101,
     102,     0,     0,     0,     0,     0,     0,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   111,   434,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,   122,   688,   123,     0,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   435,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   436,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   437,   438,   439,   156,   440,   441,   159,   160,
     161,   162,   163,   164,   442,   166,   443,   444,   445,   446,
     171,   172,   447,   448,   175,   449,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,     0,   188,   189,
     190,     0,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   463,     0,
       0,     0,     3,     0,     0,     0,     0,     0,     0,   410,
     411,     0,     7,     8,   412,    10,    11,    12,    13,   413,
     414,   415,   416,   417,   418,   419,   420,    22,   421,    24,
      25,     0,    26,    27,    28,    29,   422,    31,   423,    33,
      34,   424,    36,   425,    38,    39,   426,     0,    41,   427,
      43,   428,    45,   429,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    62,
       0,    63,    64,    65,   430,     0,     0,    69,    70,    71,
       0,     0,     0,    73,     0,     0,     0,     0,    75,    76,
      77,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,     0,    90,     0,     0,     0,
     431,    92,    93,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   434,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   435,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   436,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   437,
     438,   439,   156,   440,   441,   159,   160,   161,   162,   163,
     164,   442,   166,   443,   444,   445,   446,   171,   172,   447,
     448,   175,   449,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,     0,   188,   189,   190,     0,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   495,     0,     3,     0,     0,
       0,     0,     0,     0,   410,   411,     0,     7,     8,   412,
      10,    11,    12,    13,   413,   414,   415,   416,   417,   418,
     419,   420,    22,   421,    24,    25,     0,    26,    27,    28,
      29,   422,    31,   423,    33,    34,   424,    36,   425,    38,
      39,   426,     0,    41,   427,    43,   428,    45,   429,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    62,     0,    63,    64,    65,   430,
       0,     0,    69,    70,    71,     0,     0,     0,    73,     0,
       0,     0,     0,    75,    76,    77,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   431,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     0,
     100,   101,   102,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   111,   434,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   122,     0,   123,     0,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   435,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   436,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   437,   438,   439,   156,   440,   441,
     159,   160,   161,   162,   163,   164,   442,   166,   443,   444,
     445,   446,   171,   172,   447,   448,   175,   449,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,     0,
     188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
       3,     0,     0,     0,     0,     0,     0,   410,   411,     0,
       7,     8,   481,    10,    11,    12,    13,   413,    15,   482,
     416,   417,   963,   419,   420,    22,   421,    24,    25,     0,
      26,    27,    28,    29,   422,    31,   483,    33,    34,    35,
      36,   425,    38,    39,   426,     0,    41,   484,    43,   428,
      45,   429,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    62,     0,    63,
      64,    65,   485,     0,     0,    69,    70,    71,     0,     0,
       0,    73,     0,     0,     0,     0,    75,    76,    77,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   431,    92,
      93,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,   100,   101,   964,     0,     0,     0,   965,
       0,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   434,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,  1328,
     123,   124,     0,     0,     0,     0,  1329,     0,   129,     0,
     130,   131,   132,   133,   435,   135,   136,   137,   138,   139,
     140,     0,     0,   966,   142,     0,     0,   436,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   437,   154,   439,
     156,   440,   441,   159,   160,   161,   162,   163,   164,   442,
     166,   443,   444,   445,   446,   171,   172,   447,   448,   175,
     449,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,   190,     0,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,     3,     0,     0,     0,     0,     0,     0,
     410,   411,     0,     7,     8,   481,    10,    11,    12,    13,
     413,    15,   482,   416,   417,   963,   419,   420,    22,   421,
      24,    25,     0,    26,    27,    28,    29,   422,    31,   483,
      33,    34,    35,    36,   425,    38,    39,   426,     0,    41,
     484,    43,   428,    45,   429,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   485,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,  1287,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   431,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   100,   101,   964,     0,
       0,     0,   965,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   434,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,     0,   123,   124,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   435,   135,   136,
     137,   138,   139,   140,     0,     0,   966,   142,     0,     0,
     436,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     437,   154,   439,   156,   440,   441,   159,   160,   161,   162,
     163,   164,   442,   166,   443,   444,   445,   446,   171,   172,
     447,   448,   175,   449,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,     0,   188,   189,   190,     0,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,     3,     0,     0,     0,
       0,     0,     0,   410,   411,     0,     7,     8,   412,    10,
      11,    12,    13,   413,   414,   415,   416,   417,   418,   419,
     420,    22,   421,    24,    25,     0,    26,    27,    28,    29,
     422,    31,   423,    33,    34,   424,    36,   425,    38,    39,
     426,     0,    41,   427,    43,   428,    45,   429,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    62,     0,    63,    64,    65,   430,     0,
       0,    69,    70,    71,     0,     0,     0,    73,     0,     0,
       0,     0,    75,    76,    77,     0,     0,    80,    81,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,     0,
      90,     0,     0,     0,   431,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,   100,
     101,   102,   432,     0,     0,   433,     0,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   111,   434,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   122,     0,   123,     0,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     435,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   436,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   437,   438,   439,   156,   440,   441,   159,
     160,   161,   162,   163,   164,   442,   166,   443,   444,   445,
     446,   171,   172,   447,   448,   175,   449,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,     0,   188,
     189,   190,     0,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,     3,
       0,     0,     0,     0,     0,     0,   410,   411,     0,     7,
       8,   412,    10,    11,    12,    13,   413,   414,   415,   416,
     417,   418,   419,   420,    22,   421,    24,    25,     0,    26,
      27,    28,    29,   422,    31,   423,    33,    34,   424,    36,
     425,    38,    39,   426,     0,    41,   427,    43,   428,    45,
     429,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   430,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   431,    92,    93,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,     0,   100,   101,   102,   478,     0,     0,   479,     0,
       0,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   434,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,     0,     0,     0,   122,     0,   123,
       0,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   435,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,     0,     0,   436,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   437,   438,   439,   156,
     440,   441,   159,   160,   161,   162,   163,   164,   442,   166,
     443,   444,   445,   446,   171,   172,   447,   448,   175,   449,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,     0,   188,   189,   190,     0,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,     3,     0,     0,     0,     0,     0,     0,   410,
     411,     0,     7,     8,   412,    10,    11,    12,    13,   413,
     414,   415,   416,   417,   418,   419,   420,    22,   421,    24,
      25,     0,    26,    27,    28,    29,   422,    31,   423,    33,
      34,   424,    36,   425,    38,    39,   426,     0,    41,   427,
      43,   428,    45,   429,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    62,
       0,    63,    64,    65,   430,     0,     0,    69,    70,    71,
       0,     0,     0,    73,     0,     0,     0,     0,    75,    76,
      77,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,     0,    90,     0,     0,     0,
     431,    92,    93,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   434,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,   660,   123,     0,     0,     0,     0,     0,   661,     0,
     129,     0,   130,   131,   132,   133,   435,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   436,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   437,
     438,   439,   156,   440,   441,   159,   160,   161,   162,   163,
     164,   442,   166,   443,   444,   445,   446,   171,   172,   447,
     448,   175,   449,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,     0,   188,   189,   190,     0,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,     3,     0,     0,     0,     0,
       0,     0,   410,   411,     0,     7,     8,   412,    10,    11,
      12,    13,   413,   414,   415,   416,   417,   418,   419,   420,
      22,   421,    24,    25,     0,    26,    27,    28,    29,   422,
      31,   423,    33,    34,   424,    36,   425,    38,    39,   426,
       0,    41,   427,    43,   428,    45,   429,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    62,     0,    63,    64,    65,   430,     0,     0,
      69,    70,    71,     0,     0,     0,    73,     0,     0,     0,
       0,    75,    76,    77,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   431,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,   100,   101,
     102,     0,     0,     0,     0,     0,     0,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   111,   434,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,   122,   705,   123,     0,     0,     0,     0,
       0,   706,     0,   129,     0,   130,   131,   132,   133,   435,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   436,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   437,   438,   439,   156,   440,   441,   159,   160,
     161,   162,   163,   164,   442,   166,   443,   444,   445,   446,
     171,   172,   447,   448,   175,   449,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,     0,   188,   189,
     190,     0,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,     3,     0,
       0,     0,     0,     0,     0,   410,   411,     0,     7,     8,
     481,    10,    11,    12,    13,   413,    15,   482,   416,   417,
     963,   419,   420,    22,   421,    24,    25,     0,    26,    27,
      28,    29,   422,    31,   483,    33,    34,    35,    36,   425,
      38,    39,   426,     0,    41,   484,    43,   428,    45,   429,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    62,     0,    63,    64,    65,
     485,     0,     0,    69,    70,    71,     0,     0,     0,    73,
       0,     0,     0,     0,    75,    76,    77,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   431,    92,    93,     0,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,   100,   101,   964,     0,     0,     0,   965,     0,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   111,
     434,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   122,     0,   123,   124,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   435,   135,   136,   137,   138,   139,   140,     0,
       0,   966,   142,     0,     0,   436,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   437,   154,   439,   156,   440,
     441,   159,   160,   161,   162,   163,   164,   442,   166,   443,
     444,   445,   446,   171,   172,   447,   448,   175,   449,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
       0,   188,   189,   190,     0,   191,   192,   193,   194,   195,
     196,     0,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,     3,     0,     0,     0,     0,     0,     0,   410,   411,
       0,     7,     8,   481,    10,    11,    12,    13,   413,    15,
     482,   416,   417,   963,   419,   420,    22,   421,    24,    25,
       0,    26,    27,    28,    29,   422,    31,   483,    33,    34,
      35,    36,   425,    38,    39,   426,     0,    41,   484,    43,
     428,    45,   429,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    62,     0,
      63,    64,    65,   485,     0,     0,    69,    70,    71,     0,
       0,     0,    73,     0,     0,     0,     0,    75,    76,    77,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   431,
      92,    93,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,   100,   101,   964,     0,     0,     0,
     965,     0,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   111,   434,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   122,
       0,   123,   124,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   435,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   436,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   437,   154,
     439,   156,   440,   441,   159,   160,   161,   162,   163,   164,
     442,   166,   443,   444,   445,   446,   171,   172,   447,   448,
     175,   449,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,     0,   188,   189,   190,     0,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,     3,     0,     0,     0,     0,     0,
       0,   410,   411,     0,     7,     8,   412,    10,    11,    12,
      13,   413,   414,   415,   416,   417,   418,   419,   420,    22,
     421,    24,    25,     0,    26,    27,    28,    29,   422,    31,
     423,    33,    34,   424,    36,   425,    38,    39,   426,     0,
      41,   427,    43,   428,    45,   429,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    62,     0,    63,    64,    65,   430,     0,     0,    69,
      70,    71,     0,     0,     0,    73,     0,     0,     0,     0,
      75,    76,    77,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,   431,    92,    93,     0,     0,     0,     0,     0,
       0,     0,     0,    96,    97,    98,     0,   100,   101,   102,
       0,     0,     0,     0,     0,     0,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   111,   434,   113,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,     0,
       0,     0,   122,     0,   123,     0,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   435,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,     0,
       0,   436,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   437,   438,   439,   156,   440,   441,   159,   160,   161,
     162,   163,   164,   442,   166,   443,   444,   445,   446,   171,
     172,   447,   448,   175,   449,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,     0,   188,   189,   190,
       0,   191,   192,   193,   194,   195,   196,     0,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        16,   532,   574,   127,   575,   576,   577,   578,   785,   786,
     307,   712,   116,   771,   529,   368,    32,   891,   103,   771,
    1314,  1060,   859,   684,   925,  1161,   783,   784,   987,    68,
     754,  1172,  1173,   551,  1248,    49,   614,    89,    20,    87,
     554,   111,   556,   557,    87,   559,    89,   561,    20,   818,
      66,    89,    68,   684,    21,   569,   570,  1134,     7,   783,
     784,    20,   451,    87,   695,    87,    82,    87,   100,    45,
     100,   133,   100,    86,   111,   100,   121,    38,   122,   291,
      89,   144,   100,    20,   147,   133,   138,   299,   104,  1223,
     100,     8,     9,   100,   818,   138,    89,   758,   947,   760,
     116,   100,   118,   100,   100,    37,   459,   460,   124,   151,
     144,   100,   100,   147,   503,   504,   121,   506,   507,   508,
     509,   103,   144,   138,   881,    57,   208,   516,   517,   160,
     854,   103,   138,   115,   111,    87,   144,   181,   147,   100,
     177,   530,   187,   115,   120,   177,   216,   106,   178,    30,
       4,   540,   541,   178,     8,    36,    37,   881,   140,   167,
     173,   192,   144,   181,   246,   147,   200,   160,   140,  1018,
      93,   181,   144,    54,   181,   147,    57,   174,   177,    96,
    1321,   177,   187,   106,    65,   167,   310,    87,   177,   177,
     212,   213,   151,   824,   208,   167,   965,   114,   226,   116,
       8,     9,    47,   265,   228,    50,     8,     9,   228,    90,
     248,   249,   601,   265,   151,   604,   165,   265,  1257,  1056,
     921,  1298,   265,  1097,  1125,   803,   804,   144,   298,   987,
     988,   148,   246,  1134,   895,   987,   988,   204,  1452,  1533,
    1199,   965,   760,   874,   147,   177,  1380,   164,    93,   880,
     265,   244,   245,   767,   247,   111,  1550,   209,   210,   265,
     114,   254,   116,     8,  1558,    87,   100,   283,   185,   251,
     124,   264,   224,   100,    19,    89,   315,   127,   631,   318,
     384,    34,  1418,   276,   127,   144,   203,    40,    96,   100,
     144,   141,   106,    37,    96,    48,    40,    50,   179,   315,
       4,   405,   318,   144,     8,    58,   114,    60,   116,   209,
     210,   144,   114,    61,   116,    68,   138,   100,    66,    72,
     176,   406,   983,   408,   224,    99,     8,   680,    72,   100,
     147,    89,  1089,   147,   167,   216,   144,    19,   147,  1063,
     148,   100,   144,   177,   118,  1384,   148,   432,   191,    87,
     177,   104,   105,   106,  1111,    99,   164,   373,    89,   375,
     749,   465,   164,   111,   380,  1089,   177,   756,   384,   114,
     216,   116,   218,   458,   390,   106,  1517,   185,   135,   464,
     125,   397,   172,   185,     8,     9,   471,  1111,   473,   405,
     475,   172,   255,   478,   177,   203,   186,  1298,   243,   144,
     138,   203,   160,   266,    39,   186,   177,   160,   493,   166,
     114,   256,   116,   258,   499,   159,   147,   433,   177,  1256,
     124,  1460,  1179,   157,   269,   270,   271,   184,   273,   147,
     275,   820,   114,   518,   116,    26,   951,   826,   172,   192,
     144,  1199,    87,   125,   867,   461,   869,  1199,  1487,   465,
    1208,   111,   468,   469,   470,  1179,  1208,   111,   474,   239,
     240,  1219,   144,   479,    55,    33,   144,  1219,   221,   593,
     594,    39,    96,   489,   827,   828,    44,   149,   147,   832,
      25,   149,   262,   128,    52,   149,   244,   245,   133,   247,
     114,   914,   116,   916,   166,   511,    64,    42,   166,   216,
     253,   218,   166,   519,   893,   590,   264,  1546,   861,  1548,
     595,   111,    46,   902,   191,   904,   905,   189,   276,    53,
     144,   189,  1396,   200,   148,  1564,   279,   280,   281,   282,
     283,   920,   285,   286,   287,   288,   289,   110,  1468,  1469,
     164,   294,   931,   932,   933,    40,   935,   936,   937,   938,
     939,   940,   160,   942,   943,    89,   596,   149,   145,   599,
     147,   185,   602,    58,   137,    60,   955,   128,   139,   139,
    1500,   128,   676,    68,   166,   679,  1506,   150,   663,   203,
     128,    89,   144,   144,   192,   156,   156,   144,   673,   136,
     979,   159,   981,   982,   162,  1296,   144,   261,   106,  1300,
     147,  1359,    46,   619,   268,   690,   622,  1359,   176,    53,
     626,   184,   206,   221,   278,   216,   255,   702,   703,  1008,
     221,   815,    88,   708,   147,   144,    70,   266,   147,   261,
     646,   647,   648,    99,   202,   829,   268,  1026,  1210,   128,
      46,   260,   216,   109,   133,    89,   278,    53,   267,   734,
     111,   667,   118,   669,   128,   269,   270,   271,   233,   133,
     676,   275,   144,   679,   317,   144,  1423,   111,  1425,   322,
     233,   279,   280,   281,   282,   283,   234,   285,   286,   287,
     288,   289,   212,   213,   214,  1074,   223,   223,   225,   225,
    1079,   372,   989,   374,   147,   711,   182,   183,   111,  1423,
       0,  1425,  1091,   292,   293,  1406,  1237,  1464,  1409,   119,
     120,  1488,  1101,  1102,   283,   284,   119,   120,   181,   572,
     573,  1110,  1479,   181,   579,   580,  1371,  1372,   158,   581,
     582,   747,    85,    43,   241,   190,    94,   145,   754,  1092,
    1464,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    95,    20,    40,    40,  1479,    40,   143,   238,   111,
     285,   290,   290,   295,   144,   177,   276,   783,   784,   785,
     786,  1472,  1343,   276,   111,  1164,   144,   111,  1350,  1351,
     144,   177,   144,   144,   144,   177,  1175,    27,   147,    15,
     147,    28,    29,   147,    31,    32,   147,    34,   147,   177,
     204,  1190,   818,    40,  1193,    20,  1195,   177,   222,    25,
     111,    48,   159,    50,    51,  1168,   161,   123,   834,   161,
     100,    58,    65,    60,   909,   131,   132,   222,   134,    87,
      87,    68,    87,   140,   100,    72,   142,   100,    20,   151,
     146,   118,   148,   151,   123,   238,   291,   153,   123,   174,
     174,   867,    87,   869,   177,   177,   174,   174,  1430,  1431,
      89,   177,    37,   169,    89,   881,   100,   104,   105,   106,
     174,   133,   177,   144,   177,   177,   174,    87,  1267,   174,
     177,   174,   174,   174,  1273,   228,   216,   193,   194,   195,
     196,   197,   198,  1282,   133,   177,   174,   161,   914,   111,
     916,   986,   111,   111,   111,   181,   138,   174,    87,   123,
    1482,   133,   133,    20,   151,  1304,  1305,  1306,  1307,  1308,
     291,  1310,  1311,   160,  1277,   175,   144,   174,   278,   218,
     111,  1016,   246,    87,   188,   123,   174,   123,   151,    89,
     111,   133,   144,   959,   174,   111,   962,   138,  1337,   965,
      93,   174,    27,    20,   174,   192,   111,   144,   111,   144,
     976,    72,   978,   174,   237,   100,   100,   147,   174,   147,
     147,   138,  1325,   138,   211,   135,   250,    20,   277,    20,
     252,    20,  1067,   228,   221,   218,   297,   218,   278,   259,
     218,   279,   181,   177,   177,   135,   138,   111,   111,    70,
     100,   177,   133,   177,   174,   177,  1395,   123,   177,     6,
     133,   228,  1401,   181,  1403,   176,   253,    99,    99,  1104,
     224,   224,   274,   224,   224,   177,   177,   174,   177,   138,
     138,   177,  1117,    71,   278,   174,    20,   242,    20,   263,
      89,   161,   279,   280,   281,   282,   283,   242,   285,   286,
     287,   288,   289,   249,   117,   174,    89,   294,   176,   174,
      87,   144,   174,    20,  1080,   100,   161,   177,   174,   174,
      46,    87,    87,  1089,   272,   177,    20,   111,   100,    87,
     279,   111,   111,  1099,   187,   176,   216,   174,   187,   187,
     111,  1107,   216,   257,    86,  1111,   176,   173,   187,   296,
     111,   111,   296,   296,   144,   111,   111,  1496,   177,   236,
     189,   239,   285,   239,   630,  1131,   279,   242,  1022,   216,
     819,   528,   382,   528,  1063,  1460,  1487,   378,  1157,  1518,
     882,   457,   401,   879,  1523,   297,  1152,   282,   297,   297,
    1271,   962,   243,  1099,  1165,  1161,  1081,  1107,   955,  1165,
    1177,   489,  1175,  1172,  1543,  1112,   553,   604,   552,   303,
    1125,   712,  1506,  1179,  1500,   786,  1057,   409,   409,   869,
    1021,  1152,  1162,  1208,  1359,   988,  1212,  1356,  1219,   997,
     853,  1046,  1246,  1374,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1254,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1268,  1269,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1297,    -1,    -1,    -1,  1301,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1440,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1402,    -1,    -1,    -1,
      -1,  1407,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1418,    -1,    -1,    -1,    -1,  1423,    -1,  1425,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1456,    -1,    -1,  1459,    -1,    -1,    -1,    -1,  1464,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1475,
      -1,    -1,    -1,  1479,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1488,    -1,  1490,    -1,    -1,    -1,  1494,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1520,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1538,    -1,  1540,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    -1,    -1,    -1,    -1,  1553,    -1,    17,
      18,  1557,    20,    -1,    -1,    -1,  1562,    25,    26,    -1,
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
     248,   249,    -1,   251,   252,   253,    -1,   255,   256,   257,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,
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
     176,   177,   178,   179,   180,    -1,   182,   183,   184,    -1,
     186,    -1,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,    -1,    -1,   201,   202,   203,    -1,   205,
     206,    -1,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,   251,   252,   253,    -1,   255,
     256,   257,   258,   259,   260,    -1,   262,   263,   264,   265,
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
      -1,   166,   167,    -1,    -1,   170,   171,   172,    -1,   174,
      -1,   176,    -1,   178,   179,   180,    -1,   182,   183,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,   203,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,   253,    -1,
     255,   256,   257,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    -1,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      -1,   115,    -1,   117,   118,   119,   120,    -1,   122,    -1,
      -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,   147,   148,   149,   150,   151,    -1,    -1,
      -1,    -1,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,   166,   167,    -1,    -1,   170,   171,   172,    -1,
      -1,    -1,   176,   177,   178,   179,   180,    -1,   182,   183,
     184,    -1,   186,    -1,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,    -1,    -1,   201,   202,   203,
      -1,   205,   206,    -1,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,   251,   252,   253,
      -1,   255,   256,   257,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    -1,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,   115,    -1,   117,   118,   119,   120,    -1,   122,
      -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,   156,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,   166,   167,    -1,    -1,   170,   171,   172,
      -1,    -1,    -1,   176,   177,   178,   179,   180,    -1,   182,
     183,   184,    -1,   186,    -1,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,    -1,    -1,   201,   202,
     203,    -1,   205,   206,    -1,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   251,   252,
     253,    -1,   255,   256,   257,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    -1,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,
      -1,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    -1,   115,    -1,   117,   118,   119,   120,    -1,
     122,    -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,    -1,    -1,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,   147,   148,   149,   150,   151,
      -1,    -1,    -1,    -1,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,   166,   167,    -1,    -1,   170,   171,
     172,    -1,   174,    -1,   176,    -1,   178,   179,   180,    -1,
     182,   183,   184,    -1,   186,    -1,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,    -1,    -1,   201,
     202,   203,    -1,   205,   206,    -1,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,   251,
     252,   253,    -1,   255,   256,   257,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    -1,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    -1,    -1,    98,    99,    -1,
      -1,    -1,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    -1,   115,    -1,   117,   118,   119,   120,
      -1,   122,    -1,    -1,    -1,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,   156,   157,   158,   159,   160,
     161,   162,   163,   164,    -1,   166,   167,    -1,    -1,   170,
     171,   172,    -1,   174,    -1,   176,    -1,   178,   179,   180,
      -1,   182,   183,   184,    -1,   186,    -1,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,    -1,    -1,
     201,   202,   203,    -1,   205,   206,    -1,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
     251,   252,   253,    -1,   255,   256,   257,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    -1,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    -1,    -1,    98,    99,
      -1,    -1,    -1,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    -1,   115,    -1,   117,   118,   119,
     120,    -1,   122,    -1,    -1,    -1,   126,   127,   128,   129,
     130,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,   147,   148,   149,
     150,   151,    -1,    -1,    -1,    -1,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,   166,   167,    -1,    -1,
     170,   171,   172,    -1,   174,    -1,   176,    -1,   178,   179,
     180,    -1,   182,   183,   184,    -1,   186,    -1,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,    -1,
      -1,   201,   202,   203,    -1,   205,   206,    -1,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,   251,   252,   253,    -1,   255,   256,   257,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
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
      -1,   170,   171,   172,    -1,   174,    -1,   176,    -1,   178,
     179,   180,    -1,   182,   183,   184,    -1,   186,    -1,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
      -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,   252,   253,    -1,   255,   256,   257,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
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
      -1,    -1,   170,   171,   172,    -1,   174,    -1,   176,    -1,
     178,   179,   180,    -1,   182,   183,   184,    -1,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,    -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,   253,    -1,   255,   256,   257,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    -1,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    -1,
      -1,    98,    99,    -1,    -1,    -1,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,   115,    -1,
     117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,   166,
     167,    -1,    -1,   170,   171,   172,    -1,   174,    -1,   176,
      -1,   178,   179,   180,    -1,   182,   183,   184,    -1,   186,
      -1,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,    -1,    -1,   201,   202,   203,    -1,   205,   206,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,   252,   253,    -1,   255,   256,
     257,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,
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
     246,   247,   248,   249,    -1,   251,   252,   253,    -1,   255,
     256,   257,   258,   259,   260,    -1,   262,   263,   264,   265,
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
      -1,   176,    -1,   178,   179,   180,    -1,   182,   183,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,   203,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,   253,    -1,
     255,   256,   257,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    -1,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      -1,   115,    -1,   117,   118,   119,   120,    -1,   122,    -1,
      -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,   147,   148,   149,   150,   151,    -1,    -1,
      -1,    -1,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,   166,   167,    -1,    -1,   170,   171,   172,    -1,
      -1,    -1,   176,    -1,   178,   179,   180,    -1,   182,   183,
     184,    -1,   186,    -1,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,    -1,    -1,   201,   202,   203,
      -1,   205,   206,    -1,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,   251,   252,   253,
      -1,   255,   256,   257,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    -1,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,   115,    -1,   117,   118,   119,   120,    -1,   122,
      -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,   156,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,   166,   167,    -1,    -1,   170,   171,   172,
      -1,    -1,    -1,   176,    -1,   178,   179,   180,    -1,   182,
     183,   184,    -1,   186,    -1,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,    -1,    -1,   201,   202,
     203,    -1,   205,   206,    -1,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   251,   252,
     253,    -1,   255,   256,   257,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    -1,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,
      -1,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    -1,   115,    -1,   117,   118,   119,   120,    -1,
     122,    -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,    -1,    -1,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,   147,   148,   149,   150,   151,
      -1,    -1,    -1,    -1,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,   166,   167,    -1,    -1,   170,   171,
     172,    -1,    -1,    -1,   176,    -1,   178,   179,   180,    -1,
     182,   183,   184,    -1,   186,    -1,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,    -1,    -1,   201,
     202,   203,    -1,   205,   206,    -1,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,   251,
     252,   253,    -1,   255,   256,   257,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    -1,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    -1,    -1,    98,    99,    -1,
      -1,    -1,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    -1,   115,    -1,   117,   118,   119,   120,
      -1,   122,    -1,    -1,    -1,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,   156,   157,   158,   159,   160,
     161,   162,   163,   164,    -1,   166,   167,    -1,    -1,   170,
     171,   172,    -1,    -1,    -1,   176,    -1,   178,   179,   180,
      -1,   182,   183,   184,    -1,   186,    -1,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,    -1,    -1,
     201,   202,   203,    -1,   205,   206,    -1,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
     251,   252,   253,    -1,   255,   256,   257,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    -1,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    -1,    -1,    98,    99,
      -1,    -1,    -1,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    -1,   115,    -1,   117,   118,   119,
     120,    -1,   122,    -1,    -1,    -1,   126,   127,   128,   129,
     130,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,   147,   148,    -1,
     150,   151,    -1,    -1,    -1,    -1,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,
     170,   171,   172,    -1,    -1,    -1,   176,    -1,   178,   179,
     180,    -1,   182,   183,   184,    -1,   186,    -1,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,    -1,
      -1,   201,   202,   203,    -1,   205,   206,    -1,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,   251,   252,   253,    -1,   255,   256,   257,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
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
      -1,   150,   151,    -1,    -1,    -1,    -1,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,
      -1,   170,   171,   172,    -1,    -1,    -1,   176,    -1,   178,
     179,   180,    -1,    -1,    -1,   184,    -1,   186,    -1,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
      -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,   252,   253,    -1,   255,   256,   257,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
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
     248,   249,    -1,   251,   252,   253,    -1,   255,   256,   257,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
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
      -1,   178,    -1,    -1,    -1,    -1,    -1,   184,    -1,   186,
      -1,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,    -1,    -1,   201,   202,    -1,    -1,   205,   206,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,   252,   253,    -1,   255,   256,
     257,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,    14,    -1,    -1,    -1,    18,    -1,
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
      -1,   251,   252,   253,    -1,   255,   256,   257,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,    14,    -1,    -1,    -1,    18,    -1,    20,    -1,    -1,
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
     243,   244,   245,   246,   247,   248,   249,    -1,   251,   252,
     253,    -1,   255,   256,   257,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,    14,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,
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
     246,   247,   248,   249,    -1,   251,   252,   253,    -1,   255,
     256,   257,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,    16,    -1,    18,    -1,    -1,
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
      -1,   172,    -1,    -1,    -1,   176,    -1,   178,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,    -1,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,    -1,    -1,
     201,   202,    -1,    -1,   205,   206,    -1,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
     251,   252,   253,    -1,   255,   256,   257,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
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
     138,   139,    -1,   141,   142,   143,    -1,    -1,    -1,   147,
      -1,    -1,   150,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,   176,   177,
     178,   179,    -1,    -1,    -1,    -1,   184,    -1,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,    -1,    -1,   201,   202,    -1,    -1,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,   253,    -1,   255,   256,   257,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    -1,    -1,
      85,    -1,    87,    88,    89,    90,    -1,    -1,    93,    94,
      95,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,   104,
     105,   106,    -1,    -1,   109,   110,   111,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,    -1,   141,   142,   143,    -1,
      -1,    -1,   147,    -1,    -1,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,
      -1,   176,    -1,   178,   179,    -1,    -1,    -1,    -1,    -1,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,    -1,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,   253,    -1,
     255,   256,   257,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    18,    -1,    -1,    -1,
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
     252,   253,    -1,   255,   256,   257,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,    18,
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
     249,    -1,   251,   252,   253,    -1,   255,   256,   257,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,
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
     246,   247,   248,   249,    -1,   251,   252,   253,    -1,   255,
     256,   257,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,    18,    -1,    -1,    -1,    -1,
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
     243,   244,   245,   246,   247,   248,   249,    -1,   251,   252,
     253,    -1,   255,   256,   257,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,    18,    -1,
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
      -1,   251,   252,   253,    -1,   255,   256,   257,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
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
     247,   248,   249,    -1,   251,   252,   253,    -1,   255,   256,
     257,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,    18,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,   176,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,    -1,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,    -1,    -1,   201,   202,    -1,
      -1,   205,   206,    -1,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,   251,   252,   253,
      -1,   255,   256,   257,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300
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
     253,   255,   256,   257,   258,   259,   260,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   346,   347,   352,   355,   358,   361,   362,   364,
     369,   370,   371,   372,   373,   382,   383,   385,   386,   387,
     392,   394,   396,   397,   398,   403,   424,   427,   430,   431,
     432,   433,   435,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   481,   482,   483,   497,   498,   500,   501,   502,
     503,   504,   505,   506,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   526,   527,   528,   529,   534,   535,
     536,   537,   538,   539,   542,   548,   549,   550,    28,    29,
      31,    32,    34,    40,    48,    50,    51,    58,    60,    68,
      72,   104,   105,   106,   151,   160,   192,   211,   221,   253,
     279,   280,   281,   282,   283,   285,   286,   287,   288,   289,
     294,   353,   354,   374,   375,   151,   144,   147,   144,   147,
      25,    26,    30,    35,    36,    37,    38,    39,    40,    41,
      42,    44,    52,    54,    57,    59,    62,    65,    67,    69,
      90,   126,   144,   147,   160,   192,   205,   215,   216,   217,
     219,   220,   227,   229,   230,   231,   232,   235,   236,   238,
     548,   144,    61,    66,   111,   389,   147,   363,   147,    26,
      55,   111,    39,    14,   144,   147,   547,   548,   147,   111,
     111,   144,   147,   147,    87,   144,   212,   213,   144,   147,
     548,    30,    37,    54,    65,    90,   465,   548,   548,   111,
     177,   383,   548,   144,   547,    16,   548,   548,   457,   144,
      21,   204,   206,   216,   218,   147,   216,   218,   216,   216,
     221,   111,   144,   365,   233,   233,   234,   147,   144,   111,
     317,     0,   319,   320,    25,    42,   322,   382,   181,   181,
     100,   181,   384,    33,    39,    44,    52,    64,   159,   162,
     176,   202,   388,   393,   394,   395,   412,   413,   417,   399,
     400,   548,   158,    85,   123,   131,   132,   134,   142,   146,
     148,   153,   169,   193,   194,   195,   196,   197,   198,   449,
     450,   241,   149,   166,   189,   110,   137,   150,   184,   191,
     200,   127,   141,    43,   190,    94,    95,   149,   166,   448,
     144,   454,   457,   182,   183,   145,   469,   470,   465,   469,
     465,   147,   469,   136,   147,    20,   546,   172,   186,   172,
     186,   157,   172,   374,   548,   374,   548,   160,   192,    40,
     376,   375,    40,   377,   548,   143,   111,   351,    37,    40,
      72,    99,   159,   547,   212,   213,   214,   292,   293,   238,
     577,   548,   285,   548,   290,   290,   295,   279,   287,   354,
     547,   383,   177,   383,    37,    57,   177,   522,   523,   383,
     177,   184,   548,   144,   386,   276,   276,   111,   407,   111,
     177,   378,   379,   144,   380,   383,   151,   546,   106,   151,
     345,   546,   404,   406,   548,   111,   383,    20,   177,   547,
     144,   548,   548,   425,   426,   548,   383,   177,   383,   524,
     548,   383,   144,   144,   383,   177,   184,   548,   144,   425,
     177,    27,   485,   486,   487,   383,     7,   165,    15,   177,
     383,   204,    20,   386,   386,   177,   386,   386,   386,   386,
     222,   540,   541,   548,   366,   386,   386,   383,   405,   411,
     548,   324,   325,    25,   326,   386,   385,   111,   159,   161,
     161,   386,   386,   100,    87,    89,   138,   265,   401,   402,
     508,   432,   433,   435,   435,   435,   435,   434,   435,   435,
     435,    65,   439,   439,   438,   440,   440,   440,   440,   441,
     441,   442,   442,   222,    87,    87,    87,   174,   383,   457,
     457,   383,   470,   177,   386,   480,   140,   177,   480,   100,
     100,   363,    20,   548,   548,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,   328,   329,   330,    87,   128,
     133,   348,   349,   350,   548,   128,   133,   151,   151,   328,
     546,   118,   123,    47,    50,    93,   243,   256,   258,   269,
     270,   271,   273,   275,   578,   579,   580,   581,   582,   583,
     590,   596,   597,   238,    87,   228,   357,   291,   548,   548,
     548,   123,   174,   174,   177,   177,   174,   100,   177,   100,
     177,   174,   383,   174,   548,    49,   208,   246,   390,   391,
     548,    87,   100,   177,   383,   177,   547,    89,    37,   547,
     546,    89,   100,   133,   402,   508,   174,   177,   177,   174,
     383,   177,   133,   100,   178,   138,   508,   174,   177,   144,
     174,   383,   383,   174,   100,   177,   100,   177,   174,   383,
     178,   548,   486,   487,   121,   187,   174,   174,   122,   181,
      87,   209,   210,   224,    87,   209,   210,   224,    87,   228,
     216,   100,   226,   133,    25,   367,   383,   177,   174,    38,
     100,   181,   106,   181,   548,   161,   386,   418,   419,   111,
     414,   415,   111,    40,   143,   147,   201,   509,   511,   513,
     514,   530,   531,   532,   533,   548,   111,   386,   111,   138,
     402,   138,   138,   401,   402,   435,   144,   147,   251,   453,
     472,   551,   554,   555,   556,   557,   558,   562,   564,   566,
     567,   509,   509,   507,   513,   507,   174,   175,   100,   177,
     177,   139,   156,   139,   156,   128,   144,   381,   363,   363,
     329,   123,   511,   350,   386,   508,   133,   386,   546,   546,
     119,   120,   546,   269,   270,   271,   275,   548,   255,   266,
     255,   266,    20,   278,    89,   106,   147,   584,   587,   578,
      30,    36,    54,    65,    90,   216,   356,   514,   283,   284,
     218,   291,   299,    87,   357,   291,   546,   144,   524,   525,
     548,   524,   525,   174,   138,   508,   246,    46,    53,    70,
     111,   401,   408,   409,   410,   391,   508,   509,   379,    87,
     174,   188,   123,   344,   546,   151,   123,    89,   344,   111,
     386,   133,   133,   402,   144,   174,   386,   111,   386,   386,
     138,    93,   428,   429,   383,   174,   174,   144,   524,   524,
     174,   386,    27,   487,   121,   187,     8,     9,    96,   114,
     116,   185,   380,   482,   484,   495,   496,   499,    20,   223,
     225,   386,   386,   386,   223,   225,   386,   386,   386,   386,
     386,   386,   111,   386,   386,   351,   368,   100,   181,   174,
     365,   237,   543,   544,   144,   111,   418,    88,    99,   109,
     118,   420,   421,   422,   423,   100,   548,   100,   400,   147,
     147,   511,   147,   135,   166,   184,   510,   548,   548,   386,
     138,   386,   386,   138,   402,   138,   383,   551,   558,   144,
     277,   436,   603,    89,   160,   244,   245,   247,   254,   264,
     276,   552,   553,   572,   573,   574,   575,   598,   601,   250,
     252,   559,   577,   259,   563,   599,   239,   240,   262,   568,
     569,   135,   386,   383,   128,   365,   128,   144,   526,   349,
     386,   278,    20,    89,   106,   147,   591,    20,   584,   357,
     510,   218,   218,   455,   279,   297,   356,   218,   181,   174,
     383,   177,   177,   135,   177,   177,   386,   138,   111,   111,
     386,   548,   410,    70,   509,   386,   546,   100,   344,   406,
     386,   386,   133,   174,   383,   426,   386,   111,   509,   106,
     429,   174,   174,   383,   177,   177,   123,   185,   484,     6,
     548,   185,   495,   181,   224,   224,   224,   224,   228,   541,
     176,   133,   368,   466,   545,   544,   386,   411,   546,   119,
     120,   422,   423,   423,   419,    99,   416,   415,   177,   184,
     509,   512,   177,   177,   177,   386,   386,   138,   386,   174,
     177,   551,   565,   242,   208,   246,   260,   267,   602,    89,
     248,   249,   600,   242,   555,   602,   438,   572,   556,   138,
     274,   560,   561,   600,   278,   571,    71,   570,   174,   385,
      20,   127,   191,   593,   594,   595,    20,   592,   593,   263,
     588,   585,   586,   587,   161,   548,   249,   357,   455,   174,
     386,   548,   548,   409,   386,   117,    89,   546,   386,   174,
     548,   176,   111,   176,   174,   487,   548,   185,   487,   548,
     386,   386,   386,   386,   386,   386,   386,   147,   200,   381,
     174,   423,   546,    87,   177,   100,   177,   386,   174,   440,
      45,   120,   438,   438,   261,   268,   278,   576,   576,   557,
     144,   272,   174,   591,   591,   595,   100,   177,    20,   589,
     600,   177,   100,   359,   360,   455,   111,   216,   298,   279,
     161,    46,   386,   344,    87,   386,   548,   386,    86,   173,
     488,   487,   548,   187,   487,   111,   466,   509,   509,    87,
     438,   438,   189,   383,    20,   257,   587,   100,    87,   548,
     111,   216,   548,   359,   111,   509,   176,     4,   124,   491,
     492,   494,   496,    19,   125,   489,   490,   493,   496,   187,
     487,   187,   548,   509,   438,   174,   360,   513,   296,   548,
     111,   216,   548,   176,   386,    86,   124,   494,   173,   125,
     493,   187,   100,   177,   423,   386,   296,   548,   111,   386,
     111,   381,   285,   296,   548,   548,   297,   386,   297,   100,
     177,   455,   455,   111,   381,   189,   548,   279,   177,   548,
     381,   216,   111,   548,   297,   455
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
     550,   550,   550,   550,   550,   550,   550,   551,   552,   552,
     553,   553,   554,   554,   555,   555,   556,   556,   557,   557,
     558,   559,   559,   560,   560,   561,   562,   562,   562,   563,
     563,   564,   565,   565,   566,   567,   567,   568,   568,   569,
     569,   569,   570,   570,   571,   571,   572,   572,   572,   572,
     572,   573,   574,   575,   576,   576,   576,   577,   577,   578,
     578,   578,   578,   578,   578,   578,   578,   579,   579,   579,
     579,   580,   580,   581,   582,   582,   583,   583,   583,   584,
     584,   585,   585,   586,   586,   587,   588,   588,   589,   589,
     590,   590,   590,   591,   591,   592,   592,   593,   593,   594,
     594,   595,   595,   596,   597,   597,   598,   598,   598,   599,
     600,   600,   600,   600,   601,   601,   602,   602,   603
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
       1,     1,     1,     1,     1,     1,     1,     2,     0,     1,
       1,     2,     1,     3,     1,     3,     1,     4,     1,     2,
       3,     0,     1,     0,     1,     4,     2,     3,     1,     0,
       1,     4,     0,     1,     2,     1,     3,     0,     1,     2,
       2,     1,     0,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     1,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     2,     2,     3,     1,     2,     2,     5,     2,     1,
       1,     0,     1,     1,     3,     4,     0,     2,     0,     2,
       4,     4,     3,     2,     3,     1,     3,     0,     1,     1,
       2,     2,     2,     2,     1,     2,     2,     2,     2,     3,
       2,     3,     3,     4,     2,     2,     1,     1,     3
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
  "\"'exactly'\"", "\"'from'\"", "\"'ftand'\"", "\"'ftnot'\"", "\"'not'\"",
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
       316,     0,    -1,   317,    -1,   301,   317,    -1,   319,    -1,
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
      -1,    25,    50,   548,    20,    -1,    25,   253,   577,    -1,
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
      -1,   354,    -1,   353,   354,    -1,   280,    -1,   281,    -1,
     282,    -1,   283,    -1,   160,    -1,   192,    -1,   221,   293,
      -1,   221,   292,    -1,   285,    -1,   286,   285,    -1,   289,
     290,    -1,   288,   290,    -1,    25,   279,   548,    -1,    25,
     279,   548,   357,    -1,    25,   279,   548,    87,   356,    -1,
      25,   279,   548,    87,   356,   357,    -1,    25,   353,   279,
     548,    -1,    25,   353,   279,   548,   357,    -1,    25,   353,
     279,   548,    87,   356,    -1,    25,   353,   279,   548,    87,
     356,   357,    -1,   514,    -1,   514,   510,    -1,   228,   284,
     218,    -1,   228,   283,   218,    -1,    25,   287,   548,   291,
     218,   455,   161,   359,    -1,    25,   353,   287,   548,   291,
     218,   455,   161,   359,    -1,   360,    -1,   359,   100,   360,
      -1,   455,    87,   513,    -1,   455,    87,   513,   423,    -1,
      25,   294,   295,   548,   291,   279,   548,   111,   548,   296,
     386,    -1,    25,   294,   295,   548,   291,   279,   548,   216,
     111,   548,   296,   285,   297,   455,    -1,    25,   294,   295,
     548,   291,   279,   548,   298,   216,   111,   548,   296,   386,
      -1,    25,   294,   295,   548,   299,   297,   249,   279,   548,
     216,   111,   548,   297,   455,   189,   279,   548,   216,   111,
     548,   297,   455,    -1,    25,    31,   172,    -1,    25,    31,
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
     386,    -1,    61,   276,    -1,    66,   276,    -1,   208,    -1,
     246,    -1,    49,   246,    -1,   390,   408,    70,   386,    -1,
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
      -1,    89,   111,   548,    -1,   265,   111,   548,    -1,    44,
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
      -1,   437,   241,    65,   551,   436,    -1,    -1,   603,    -1,
     438,    -1,   438,   189,   438,    -1,   439,    -1,   438,   166,
     439,    -1,   438,   149,   439,    -1,   440,    -1,   439,   184,
     440,    -1,   439,   110,   440,    -1,   439,   137,   440,    -1,
     439,   150,   440,    -1,   441,    -1,   440,   191,   441,    -1,
     440,   200,   441,    -1,   442,    -1,   441,   141,   442,    -1,
     441,   127,   442,    -1,   443,    -1,   443,    43,   222,   509,
      -1,   444,    -1,   444,   190,    87,   509,    -1,   445,    -1,
     445,    94,    87,   507,    -1,   446,    -1,   446,    95,    87,
     507,    -1,   448,    -1,   447,   448,    -1,   166,    -1,   149,
      -1,   447,   166,    -1,   447,   149,    -1,   451,    -1,   455,
      -1,   452,    -1,   193,    -1,   198,    -1,   197,    -1,   196,
      -1,   195,    -1,   194,    -1,   142,    -1,   169,    -1,   131,
      -1,    69,   144,   383,   174,    -1,    69,   213,   144,   383,
     174,    -1,    69,   212,   144,   383,   174,    -1,    69,    87,
     524,   144,   383,   174,    -1,   453,   144,   174,    -1,   453,
     144,   383,   174,    -1,   454,    -1,   453,   454,    -1,   167,
     548,    15,    -1,   167,    16,    -1,   456,    -1,   456,   457,
      -1,   183,   457,    -1,   457,    -1,   182,    -1,   458,    -1,
     458,   182,   457,    -1,   458,   183,   457,    -1,   459,    -1,
     468,    -1,   460,    -1,   460,   469,    -1,   463,    -1,   463,
     469,    -1,   461,   465,    -1,   462,    -1,    98,    -1,   107,
      -1,    91,    -1,   180,    -1,   108,    -1,   130,    -1,   129,
      -1,   465,    -1,    92,   465,    -1,   464,   465,    -1,   113,
      -1,   163,    -1,    83,    -1,   171,    -1,   170,    -1,    84,
      -1,   514,    -1,   466,    -1,   548,    -1,   467,    -1,   184,
      -1,    10,    -1,    17,    -1,   471,    -1,   468,   469,    -1,
     468,   147,   177,    -1,   468,   147,   480,   177,    -1,   470,
      -1,   469,   470,    -1,   145,   383,   175,    -1,   472,    -1,
     474,    -1,   475,    -1,   476,    -1,   479,    -1,   481,    -1,
     477,    -1,   478,    -1,   527,    -1,   473,    -1,   526,    -1,
     103,    -1,   140,    -1,   115,    -1,   111,   548,    -1,   147,
     177,    -1,   147,   383,   177,    -1,   112,    -1,   160,   144,
     383,   174,    -1,   192,   144,   383,   174,    -1,   548,   147,
     177,    -1,   548,   147,   480,   177,    -1,   386,    -1,   480,
     100,   386,    -1,   482,    -1,   500,    -1,   483,    -1,   497,
      -1,   498,    -1,   148,   548,   487,   121,    -1,   148,   548,
     485,   487,   121,    -1,   148,   548,   487,   187,   185,   548,
     487,   187,    -1,   148,   548,   487,   187,   484,   185,   548,
     487,   187,    -1,   148,   548,   485,   487,   187,   185,   548,
     487,   187,    -1,   148,   548,   485,   487,   187,   484,   185,
     548,   487,   187,    -1,   495,    -1,   484,   495,    -1,   486,
      -1,   485,   486,    -1,    27,   548,   487,   123,   487,   488,
      -1,    -1,    27,    -1,   173,   489,   173,    -1,    86,   491,
      86,    -1,    -1,   490,    -1,   125,    -1,   493,    -1,   490,
     125,    -1,   490,   493,    -1,    -1,   492,    -1,   124,    -1,
     494,    -1,   492,   124,    -1,   492,   494,    -1,    19,    -1,
     496,    -1,     4,    -1,   496,    -1,   482,    -1,     9,    -1,
     499,    -1,   496,    -1,     8,    -1,   114,    -1,   116,    -1,
     380,    -1,   203,    21,   204,    -1,   203,   204,    -1,   164,
     547,   165,    -1,   164,   547,     7,    -1,    96,     6,    -1,
     501,    -1,   502,    -1,   503,    -1,   504,    -1,   505,    -1,
     506,    -1,    35,   144,   383,   174,    -1,    37,   548,   144,
     174,    -1,    37,   548,   144,   383,   174,    -1,    37,   144,
     383,   174,   144,   174,    -1,    37,   144,   383,   174,   144,
     383,   174,    -1,    90,   548,   144,   174,    -1,    90,   548,
     144,   383,   174,    -1,    90,   144,   383,   174,   144,   174,
      -1,    90,   144,   383,   174,   144,   383,   174,    -1,    65,
     144,   383,   174,    -1,    30,   144,   383,   174,    -1,    54,
     547,   144,   174,    -1,    54,   547,   144,   383,   174,    -1,
      54,   144,   383,   174,   144,   174,    -1,    54,   144,   383,
     174,   144,   383,   174,    -1,   513,    -1,   513,   135,    -1,
      87,   509,    -1,   511,    -1,   511,   510,    -1,   201,   147,
     177,    -1,   135,    -1,   184,    -1,   166,    -1,   513,    -1,
     514,    -1,   143,   147,   177,    -1,   530,    -1,   533,    -1,
     509,    -1,   512,   100,   509,    -1,   548,    -1,   516,    -1,
     522,    -1,   520,    -1,   523,    -1,   521,    -1,   519,    -1,
     518,    -1,   517,    -1,   515,    -1,   216,   147,   177,    -1,
      36,   147,   177,    -1,    36,   147,   522,   177,    -1,    36,
     147,   523,   177,    -1,    65,   147,   177,    -1,    30,   147,
     177,    -1,    54,   147,   177,    -1,    54,   147,   547,   177,
      -1,    54,   147,    20,   177,    -1,    90,   147,   177,    -1,
      90,   147,   548,   177,    -1,    90,   147,   548,   100,   524,
     177,    -1,    90,   147,   184,   177,    -1,    90,   147,   184,
     100,   524,   177,    -1,   179,   548,   177,    -1,    37,   147,
     177,    -1,    37,   147,   548,   177,    -1,    37,   147,   548,
     100,   524,   177,    -1,    37,   147,   548,   100,   525,   177,
      -1,    37,   147,   184,   177,    -1,    37,   147,   184,   100,
     524,   177,    -1,    37,   147,   184,   100,   525,   177,    -1,
      57,   147,   548,   177,    -1,   548,    -1,   548,   135,    -1,
      20,    -1,   528,    -1,   529,    -1,   548,   136,   140,    -1,
      40,   363,   380,    -1,   531,    -1,   532,    -1,    40,   147,
     184,   177,    -1,    40,   147,   177,    87,   509,    -1,    40,
     147,   512,   177,    87,   509,    -1,   147,   511,   177,    -1,
      25,   211,   212,    -1,    25,   211,   213,    -1,    25,   211,
     214,    -1,   217,   216,   386,   224,   386,    -1,   217,   216,
     386,    87,   223,   224,   386,    -1,   217,   216,   386,    87,
     225,   224,   386,    -1,   217,   216,   386,   209,   386,    -1,
     217,   216,   386,   210,   386,    -1,   217,   218,   386,   224,
     386,    -1,   217,   218,   386,    87,   223,   224,   386,    -1,
     217,   218,   386,    87,   225,   224,   386,    -1,   217,   218,
     386,   209,   386,    -1,   217,   218,   386,   210,   386,    -1,
     215,   216,   386,    -1,   215,   218,   386,    -1,   220,   216,
     386,   228,   386,    -1,   220,   221,   222,   216,   386,   228,
     386,    -1,   219,   216,   386,    87,   386,    -1,   227,   111,
     540,   226,   386,   176,   386,    -1,   541,    -1,   540,   100,
     111,   541,    -1,   548,   133,   386,    -1,   236,   144,   383,
     174,   543,    -1,   544,    -1,   543,   544,    -1,   237,   545,
     381,    -1,   237,   545,   147,   111,   548,   177,   381,    -1,
     237,   545,   147,   111,   548,   100,   111,   548,   177,   381,
      -1,   237,   545,   147,   111,   548,   100,   111,   548,   100,
     111,   548,   177,   381,    -1,   466,    -1,   545,   200,   466,
      -1,    20,    -1,    14,    -1,   548,    -1,    18,    -1,   550,
      -1,   238,   111,   405,    38,   144,   386,   174,    -1,    38,
     144,   386,   174,    -1,   205,    -1,   118,    -1,    90,    -1,
      30,    -1,    36,    -1,    37,    -1,   143,    -1,    41,    -1,
     216,    -1,    54,    -1,    56,    -1,    57,    -1,    65,    -1,
      67,    -1,   201,    -1,    29,    -1,   253,    -1,    28,    -1,
     213,    -1,   212,    -1,   137,    -1,    35,    -1,   252,    -1,
     251,    -1,   252,    -1,   266,    -1,   255,    -1,   243,    -1,
     277,    -1,   269,    -1,   271,    -1,   270,    -1,   275,    -1,
     247,    -1,   242,    -1,    71,    -1,   208,    -1,   246,    -1,
      45,    -1,   214,    -1,   227,    -1,   221,    -1,   193,    -1,
     198,    -1,   197,    -1,   196,    -1,   195,    -1,   194,    -1,
      89,    -1,   104,    -1,   105,    -1,   176,    -1,    39,    -1,
      52,    -1,    61,    -1,    66,    -1,    53,    -1,    46,    -1,
      49,    -1,    70,    -1,    33,    -1,   138,    -1,    44,    -1,
     202,    -1,   161,    -1,   162,    -1,   159,    -1,    64,    -1,
      88,    -1,   109,    -1,   119,    -1,   120,    -1,    99,    -1,
      62,    -1,   126,    -1,   178,    -1,    93,    -1,    87,    -1,
     188,    -1,   117,    -1,   158,    -1,    85,    -1,    43,    -1,
     222,    -1,    94,    -1,   189,    -1,   110,    -1,   150,    -1,
     191,    -1,   141,    -1,   127,    -1,    69,    -1,    95,    -1,
     190,    -1,   142,    -1,   172,    -1,   186,    -1,   151,    -1,
     128,    -1,   122,    -1,   157,    -1,   139,    -1,   156,    -1,
      25,    -1,    31,    -1,    51,    -1,   106,    -1,    32,    -1,
      50,    -1,   206,    -1,    42,    -1,    55,    -1,    26,    -1,
      40,    -1,   265,    -1,   241,    -1,   274,    -1,   276,    -1,
     245,    -1,   259,    -1,   272,    -1,   264,    -1,   244,    -1,
     258,    -1,   273,    -1,   263,    -1,   257,    -1,   256,    -1,
     240,    -1,   239,    -1,   262,    -1,   248,    -1,   249,    -1,
     278,    -1,   268,    -1,   267,    -1,   260,    -1,   220,    -1,
     226,    -1,   223,    -1,   217,    -1,   210,    -1,   209,    -1,
     211,    -1,   228,    -1,   218,    -1,   219,    -1,   225,    -1,
     215,    -1,   224,    -1,    60,    -1,    58,    -1,    68,    -1,
      34,    -1,    48,    -1,   160,    -1,   192,    -1,   234,    -1,
     229,    -1,   232,    -1,   233,    -1,   235,    -1,   230,    -1,
     231,    -1,   236,    -1,   237,    -1,    38,    -1,   238,    -1,
      59,    -1,   287,    -1,   285,    -1,   286,    -1,   291,    -1,
     292,    -1,   293,    -1,   288,    -1,   289,    -1,   290,    -1,
      72,    -1,    73,    -1,    74,    -1,    75,    -1,    76,    -1,
      77,    -1,    78,    -1,    79,    -1,    80,    -1,    81,    -1,
      82,    -1,   279,    -1,   280,    -1,   281,    -1,   282,    -1,
     283,    -1,   284,    -1,   294,    -1,   295,    -1,   296,    -1,
     297,    -1,   298,    -1,   299,    -1,   300,    -1,   554,   552,
      -1,    -1,   553,    -1,   572,    -1,   553,   572,    -1,   555,
      -1,   554,   254,   555,    -1,   556,    -1,   555,   250,   556,
      -1,   557,    -1,   556,   252,   138,   557,    -1,   558,    -1,
     251,   558,    -1,   562,   559,   560,    -1,    -1,   577,    -1,
      -1,   561,    -1,   274,   144,   383,   174,    -1,   566,   563,
      -1,   147,   551,   177,    -1,   564,    -1,    -1,   599,    -1,
     453,   144,   565,   174,    -1,    -1,   551,    -1,   567,   568,
      -1,   472,    -1,   144,   383,   174,    -1,    -1,   569,    -1,
     240,   570,    -1,   239,   571,    -1,   262,    -1,    -1,    71,
      -1,    -1,   278,    -1,   573,    -1,   574,    -1,   575,    -1,
     601,    -1,   598,    -1,   160,    -1,   276,   438,   576,    -1,
     245,   600,   576,    -1,   278,    -1,   268,    -1,   261,    -1,
     238,   578,    -1,   577,   238,   578,    -1,   579,    -1,   580,
      -1,   581,    -1,   596,    -1,   582,    -1,   590,    -1,   583,
      -1,   597,    -1,    93,   266,    -1,    93,   255,    -1,   258,
      -1,   273,    -1,   243,   266,    -1,   243,   255,    -1,    50,
     548,    20,    -1,   269,    -1,    47,   269,    -1,   271,   584,
      -1,   271,   147,   584,   585,   177,    -1,    47,   271,    -1,
     587,    -1,   106,    -1,    -1,   586,    -1,   587,    -1,   586,
     100,   587,    -1,    89,    20,   588,   589,    -1,    -1,   263,
      20,    -1,    -1,   600,   257,    -1,   270,   278,   591,   593,
      -1,   270,   278,   106,   593,    -1,    47,   270,   278,    -1,
      89,    20,    -1,   147,   592,   177,    -1,    20,    -1,   592,
     100,    20,    -1,    -1,   594,    -1,   595,    -1,   594,   595,
      -1,   191,   591,    -1,   127,   591,    -1,   256,    20,    -1,
     275,    -1,    47,   275,    -1,    89,   208,    -1,    89,   246,
      -1,   247,   242,    -1,   259,   600,   272,    -1,   248,   438,
      -1,    89,   120,   438,    -1,    89,    45,   438,    -1,   249,
     438,   189,   438,    -1,   264,   602,    -1,   244,   602,    -1,
     267,    -1,   260,    -1,   277,   242,   440,    -1
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
    2594,  2596,  2598,  2600,  2602,  2604,  2606,  2608,  2611,  2612,
    2614,  2616,  2619,  2621,  2625,  2627,  2631,  2633,  2638,  2640,
    2643,  2647,  2648,  2650,  2651,  2653,  2658,  2661,  2665,  2667,
    2668,  2670,  2675,  2676,  2678,  2681,  2683,  2687,  2688,  2690,
    2693,  2696,  2698,  2699,  2701,  2702,  2704,  2706,  2708,  2710,
    2712,  2714,  2716,  2720,  2724,  2726,  2728,  2730,  2733,  2737,
    2739,  2741,  2743,  2745,  2747,  2749,  2751,  2753,  2756,  2759,
    2761,  2763,  2766,  2769,  2773,  2775,  2778,  2781,  2787,  2790,
    2792,  2794,  2795,  2797,  2799,  2803,  2808,  2809,  2812,  2813,
    2816,  2821,  2826,  2830,  2833,  2837,  2839,  2843,  2844,  2846,
    2848,  2851,  2854,  2857,  2860,  2862,  2865,  2868,  2871,  2874,
    2878,  2881,  2885,  2889,  2894,  2897,  2900,  2902,  2904
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   968,   968,   969,   978,   983,   990,   995,  1006,  1011,
    1019,  1027,  1035,  1041,  1053,  1062,  1066,  1070,  1082,  1088,
    1098,  1104,  1114,  1115,  1116,  1117,  1122,  1123,  1124,  1125,
    1126,  1127,  1128,  1129,  1130,  1136,  1141,  1150,  1156,  1165,
    1174,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,
    1188,  1189,  1190,  1191,  1192,  1193,  1194,  1197,  1202,  1203,
    1213,  1222,  1228,  1238,  1244,  1254,  1264,  1272,  1278,  1289,
    1294,  1304,  1310,  1316,  1322,  1339,  1347,  1355,  1359,  1368,
    1377,  1390,  1396,  1407,  1411,  1419,  1424,  1429,  1436,  1449,
    1456,  1462,  1469,  1475,  1479,  1486,  1497,  1501,  1509,  1515,
    1521,  1530,  1536,  1545,  1549,  1555,  1559,  1563,  1567,  1573,
    1579,  1585,  1589,  1595,  1601,  1608,  1616,  1624,  1632,  1640,
    1646,  1654,  1662,  1673,  1678,  1686,  1690,  1697,  1705,  1716,
    1722,  1730,  1737,  1747,  1757,  1767,  1777,  1794,  1800,  1811,
    1815,  1819,  1823,  1832,  1839,  1858,  1868,  1874,  1880,  1890,
    1897,  1908,  1915,  1922,  1934,  1938,  1945,  1950,  1957,  1965,
    1969,  1973,  1981,  1989,  1999,  2013,  2023,  2037,  2046,  2061,
    2067,  2079,  2083,  2094,  2101,  2109,  2124,  2128,  2142,  2146,
    2155,  2159,  2173,  2174,  2175,  2176,  2177,  2180,  2181,  2182,
    2183,  2184,  2186,  2187,  2190,  2191,  2192,  2193,  2194,  2199,
    2214,  2221,  2225,  2232,  2236,  2240,  2247,  2255,  2266,  2276,
    2289,  2298,  2299,  2300,  2304,  2305,  2306,  2307,  2308,  2311,
    2317,  2326,  2330,  2338,  2348,  2354,  2366,  2370,  2378,  2387,
    2397,  2405,  2414,  2423,  2438,  2447,  2457,  2465,  2471,  2480,
    2486,  2498,  2506,  2516,  2524,  2536,  2542,  2553,  2555,  2559,
    2567,  2571,  2576,  2580,  2584,  2588,  2596,  2610,  2618,  2625,
    2631,  2642,  2646,  2655,  2663,  2669,  2679,  2685,  2695,  2699,
    2709,  2715,  2721,  2727,  2736,  2745,  2754,  2767,  2771,  2779,
    2785,  2795,  2803,  2812,  2825,  2832,  2844,  2848,  2861,  2868,
    2881,  2887,  2899,  2905,  2917,  2926,  2930,  2939,  2943,  2951,
    2955,  2965,  2972,  2981,  2991,  2990,  3004,  3013,  3022,  3035,
    3039,  3052,  3055,  3062,  3066,  3075,  3079,  3083,  3092,  3096,
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
    5390,  5391,  5392,  5393,  5394,  5395,  5396,  5407,  5416,  5419,
    5426,  5431,  5439,  5443,  5450,  5454,  5461,  5465,  5472,  5476,
    5485,  5498,  5501,  5509,  5512,  5520,  5528,  5536,  5540,  5548,
    5551,  5559,  5571,  5574,  5582,  5594,  5600,  5610,  5613,  5621,
    5625,  5629,  5637,  5640,  5648,  5651,  5659,  5663,  5667,  5671,
    5675,  5683,  5691,  5703,  5715,  5719,  5723,  5731,  5737,  5747,
    5751,  5755,  5759,  5763,  5767,  5771,  5775,  5783,  5787,  5791,
    5795,  5803,  5809,  5819,  5829,  5833,  5841,  5851,  5862,  5869,
    5873,  5881,  5884,  5891,  5896,  5905,  5915,  5918,  5926,  5929,
    5937,  5946,  5953,  5963,  5967,  5974,  5980,  5990,  5993,  6000,
    6005,  6017,  6025,  6037,  6045,  6049,  6057,  6061,  6065,  6073,
    6081,  6089,  6097,  6105,  6118,  6126,  6138,  6142,  6150
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
  const int xquery_parser::yylast_ = 11336;
  const int xquery_parser::yynnts_ = 289;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 521;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 315;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 569;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 15114 "/Users/pjl/src/flwor/zorba/trunk-2/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6156 "/Users/pjl/src/flwor/zorba/trunk-2/src/compiler/parser/xquery_parser.y"


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

