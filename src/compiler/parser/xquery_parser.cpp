
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
#line 68 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"


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
#line 77 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 835 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 960 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc  */
#line 106 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"

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
#line 175 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
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
#line 831 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 282 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 115: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 830 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 291 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 140: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 829 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 300 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 309 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 318 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 327 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 336 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "Prolog" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 345 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 354 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 363 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 372 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 381 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 390 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 856 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 399 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 856 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 408 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 417 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 426 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 435 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 444 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 453 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 462 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 471 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 480 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 489 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 498 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 507 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 516 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 525 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 534 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 543 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 552 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 561 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 570 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 579 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 588 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 856 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 597 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 606 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "DeclPropertyList" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 615 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "DeclProperty" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 624 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 633 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 642 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 651 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 660 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 669 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 678 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 687 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 856 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 696 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 705 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 714 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 723 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 732 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 741 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 750 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 759 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 768 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 777 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 786 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 795 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FunctionDecl3" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 804 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDecl4" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 813 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 822 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 831 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 840 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 858 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 867 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 894 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 903 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 912 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 939 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 948 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 957 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 966 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 975 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 984 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 993 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1002 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1011 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1020 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1029 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1038 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1047 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1056 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1065 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1074 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1083 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1092 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1101 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1110 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1119 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1128 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1137 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1146 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1155 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1164 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1173 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1182 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1191 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1200 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1209 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1218 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1227 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1236 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1245 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1254 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1263 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1272 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1281 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1290 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1299 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1308 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1317 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1326 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1335 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1344 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1353 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1362 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1371 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1380 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1389 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1398 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1407 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1416 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1425 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1434 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1443 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1452 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1461 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1470 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1479 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1488 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1497 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1506 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1515 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1524 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1533 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1542 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1551 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1560 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1569 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1578 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1587 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1596 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1605 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1614 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1623 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1632 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1641 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1650 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1659 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1668 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1677 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1686 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1695 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1704 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1713 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1722 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1731 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1740 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1749 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1758 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1767 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1776 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1785 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1794 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1803 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1812 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1821 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1830 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1839 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1848 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1857 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1866 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1875 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1884 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1893 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1902 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1911 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1920 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1929 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1938 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1947 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1956 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1965 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1974 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1983 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1992 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2001 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2010 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2019 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2028 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2037 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2046 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2055 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2064 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2073 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2082 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2091 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2100 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2109 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2118 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2127 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2136 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2145 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2154 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2163 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2172 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2181 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2190 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2199 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2208 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 856 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2217 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2226 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2235 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2244 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2253 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2262 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2271 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2280 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2289 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2298 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2307 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2316 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2325 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2334 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2343 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2352 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2361 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2370 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2379 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2388 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2397 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2406 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2415 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2424 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2433 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2442 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2451 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2460 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2469 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2478 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2487 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2496 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2505 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2514 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2523 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2532 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2541 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2550 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2559 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2568 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2577 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
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
#line 119 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}

/* Line 553 of lalr1.cc  */
#line 2662 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"

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
#line 977 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 986 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 991 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            MainModule *mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
            mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 998 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1003 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            LibraryModule *lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
            lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1014 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            std::string encoding = "utf-8";
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), encoding );
        }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1019 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
        }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1027 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1035 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
        }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1043 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LibraryModule(
                LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1049 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1061 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
            dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
        }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1070 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog( LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)), NULL );
        }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1074 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog( LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)) );
        }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1078 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1090 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
            sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = sdl;
        }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1096 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( SIND_DeclList *sdl = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                sdl->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1106 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
            vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = vdl;
        }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1112 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( VFO_DeclList *vdl = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vdl->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 1144 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
         (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
         delete (yysemantic_stack_[(4) - (4)].vstrpair);
       }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1149 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
         (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
         delete (yysemantic_stack_[(4) - (4)].vstrpair);
       }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1158 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.vstrpair) = new vector<string_pair_t>();
          (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
          delete (yysemantic_stack_[(1) - (1)].strpair);
        }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1164 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
          delete (yysemantic_stack_[(2) - (2)].strpair);
          (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
        }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1173 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
            (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval() );
            delete sl;
        }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1181 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1182 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1183 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1184 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1185 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1186 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1187 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1188 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1189 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1190 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1221 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
        }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1230 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::preserve_space
            );
        }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1236 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::strip_space
            );
        }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1246 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_element_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1252 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_function_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1262 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OptionDecl(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval))
            );
        }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1272 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTOptionDecl( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1280 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::ordered
            );
        }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1286 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::unordered
            );
        }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1297 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_greatest);
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1302 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_least);
        }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1312 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1318 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1324 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1330 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1347 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
        }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1355 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1363 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
        }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1367 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1376 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1385 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1398 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            URILiteralList *ull = new URILiteralList( LOC((yyloc)));
            ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.node) = ull;
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1404 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
                ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1415 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1419 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
        }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1427 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1432 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1437 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), 
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1444 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1457 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
        }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1464 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
            d->type = (yysemantic_stack_[(3) - (2)].node);
            (yyval.node) = d;
        }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1470 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1477 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
            d->ext = false;
            (yyval.node) = d;
        }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1483 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), NULL );
        }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1487 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1494 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1505 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1509 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1517 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(5) - (5)].expr));
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1523 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1529 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1538 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
            dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = dpl;
        }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1544 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
        DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
        dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
        (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1553 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1557 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1563 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1567 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1571 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1575 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1581 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1587 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1593 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1597 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1603 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1609 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1616 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1624 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1632 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1640 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1648 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(4) - (2)].node)), 0, 0);
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1654 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1662 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1670 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1681 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = static_cast<parsenode*>(
           new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1686 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = static_cast<parsenode*>(
           new SequenceType( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1694 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier( LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1698 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier( LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1705 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1713 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1724 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList( LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1730 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1738 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec( LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<AtomicType*>((yysemantic_stack_[(3) - (3)].node)),
                            NULL);
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1745 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec( LOC((yyloc)),
                            (yysemantic_stack_[(4) - (1)].expr),
                            dynamic_cast<AtomicType*>((yysemantic_stack_[(4) - (3)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1756 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1776 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1787 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1802 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_preserve
            );
        }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1808 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_strip
            );
        }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1819 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL );
        }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1823 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1827 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)) );
        }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1831 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig(
                dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1840 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1866 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1875 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1882 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            vfo->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = vfo;
        }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back((yysemantic_stack_[(2) - (2)].node));
            (yyval.node) = vfo;
        }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1898 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(1) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1905 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(3) - (3)].expr));
      vd->set_global(false);
      (yyval.node) = vd;
        }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1916 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1923 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExitExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1930 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1942 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::BREAK );
        }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1946 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
        }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1953 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            dynamic_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1958 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            FunctionDecl *fd = dynamic_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));
            fd->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            fd->deterministic = false;
            (yyval.node) = fd;
        }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1965 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            dynamic_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node))->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
        }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1973 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1977 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1981 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1989 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 1997 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2007 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2021 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2031 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2045 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2054 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2069 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            ParamList *pl = new ParamList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2075 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
                pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2087 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2091 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2102 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EnclosedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 2109 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 2117 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QueryBody( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 2132 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2136 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2150 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new BlockBody( LOC((yyloc)) );
        }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2154 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (1)].expr));
            bb->add( (yysemantic_stack_[(3) - (2)].expr) );
            (yyval.expr) = bb;
        }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2163 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2167 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2207 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2222 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2229 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_sliding;
        }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2233 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_tumbling;
        }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2240 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_start;
        }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2244 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_end;
        }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2248 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_only_end;
        }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2255 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2263 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr),
                (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 2274 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2284 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2297 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 2319 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 2325 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2334 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = NULL;
        }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 2338 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_ofor;
        }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2346 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForClause(
                LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL
            );
        }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2356 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
            vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vdl;
        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2362 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2374 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2378 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2386 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2395 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2405 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2413 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2422 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2431 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2446 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2455 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2465 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2473 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2479 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2488 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2494 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2506 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2514 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2524 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2532 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2544 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2550 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2563 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2567 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2575 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2579 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2588 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2592 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2596 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2604 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2618 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2626 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2633 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2639 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2650 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2654 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2663 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2671 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2677 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2687 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2693 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2703 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2707 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2717 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2723 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2729 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2735 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2744 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2753 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2762 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2775 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2779 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2787 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2793 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2803 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2811 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2820 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2833 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
            qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qvidl;

        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2840 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2856 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2869 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2889 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2895 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2907 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 2913 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 2925 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 2934 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 2938 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 2947 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 2951 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 2959 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 2963 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2973 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 2980 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2989 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2998 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3003 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3012 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3021 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3030 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3043 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3047 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3059 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3063 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3071 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3075 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3084 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3088 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3092 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3101 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3105 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3111 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3117 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3123 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3134 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3138 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3142 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3150 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3154 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3160 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3170 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3174 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3184 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3188 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3198 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3202 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3212 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3216 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3226 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3230 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3238 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3242 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3246 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3250 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3260 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3264 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3268 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3276 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3280 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3284 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3288 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3292 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3296 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3304 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3308 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3312 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3320 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3324 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3328 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3332 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3342 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3348 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3358 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3364 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3374 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3378 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3416 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL
            );
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3422 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3428 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3434 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = !rpe ?
                (yysemantic_stack_[(1) - (1)].expr) : new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3445 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NULL;
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3453 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3464 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3470 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3480 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3484 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3492 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3498 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3506 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3512 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3524 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3530 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3540 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3544 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3548 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3552 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3556 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3562 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3568 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3576 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3580 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3588 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3592 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3603 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3607 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3611 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3617 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3621 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3635 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3639 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3647 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3651 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3661 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3665 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3669 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3678 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3682 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FilterExpr(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3688 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3692 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3700 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3706 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3716 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3724 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3728 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3732 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3736 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3740 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3744 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3748 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3752 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3756 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3768 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3776 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3783 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3790 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3801 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3809 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3813 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3821 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 3829 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 3837 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 3891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 3895 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3907 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 3913 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 3923 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 3927 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 3935 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 3939 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 3943 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 3951 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3961 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3971 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3981 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3991 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4001 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4016 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4022 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4033 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4039 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4050 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4067 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4072 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4081 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4085 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4092 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4100 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4106 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4116 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4128 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4132 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4139 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4145 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4151 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4158 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4169 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4173 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4183 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4187 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4197 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4201 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4205 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4210 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4219 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4225 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4231 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4237 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4247 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4251 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4263 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4267 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4279 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4291 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4295 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4299 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4303 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4307 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4311 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4319 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4327 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL
            );
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4333 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr)
            );
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4339 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4343 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4360 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (2)].expr), NULL );
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4364 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4368 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4372 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4380 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4388 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4396 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), NULL );
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4400 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (2)].sval)), (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4404 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4408 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4416 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4422 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4432 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4440 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4444 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4450 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4485 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4491 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4497 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4507 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4511 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4515 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4519 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4523 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4530 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back((yysemantic_stack_[(1) - (1)].node));
          (yyval.node) = aTypeList;
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4536 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          if (aTypeList) aTypeList->push_back((yysemantic_stack_[(3) - (3)].node));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4546 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4554 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4558 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4562 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4566 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4570 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4574 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4578 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4582 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4586 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4594 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4602 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4606 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4610 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4620 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4628 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4636 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4640 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4644 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4652 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4656 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4662 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4668 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4672 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4682 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4690 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4694 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4700 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4709 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4718 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4724 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4730 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4740 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4757 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4779 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4815 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4819 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4828 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), *(yysemantic_stack_[(3) - (3)].ival));
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4837 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new InlineFunction(LOC ((yyloc)), &*(yysemantic_stack_[(3) - (2)].fnsig)->param, &*(yysemantic_stack_[(3) - (2)].fnsig)->ret, dynamic_cast<EnclosedExpr *>((yysemantic_stack_[(3) - (3)].expr)));
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4846 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 4850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 4859 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 4868 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 4872 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)), dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 4881 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 4898 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 4904 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 4910 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 4920 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 4924 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 4930 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 4936 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 4940 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 4946 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 4950 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 4956 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 4962 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 4969 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 4979 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 4984 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 4992 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 4998 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5008 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5030 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5039 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5045 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5058 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5072 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5079 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5085 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5095 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5100 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5106 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5116 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5129 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5135 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5156 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5174 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5178 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5191 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EvalExpr(
                LOC((yyloc)), dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)), (yysemantic_stack_[(7) - (6)].expr)
            );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5197 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EvalExpr( LOC((yyloc)), new VarGetsDeclList( LOC((yyloc)) ), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5203 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("xquery"); }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5204 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("empty"); }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5205 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("attribute"); }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5206 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("comment"); }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5207 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("document-node"); }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5208 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("element"); }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5209 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("item"); }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5210 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("if"); }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5211 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("node"); }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5212 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("processing-instruction"); }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5213 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema-attribute"); }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5214 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema-element"); }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5215 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("text"); }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5216 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("typeswitch"); }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5217 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("empty-sequence"); }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5218 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("boundary-space"); }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5219 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ft-option"); }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5220 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("base-uri"); }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5221 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lax"); }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5222 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("strict"); }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5223 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("idiv"); }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5224 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("document"); }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5225 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("not"); }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5226 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sensitive"); }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5227 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("insensitive"); }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5228 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("diacritics"); }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5229 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("without"); }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5230 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stemming"); }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5231 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("thesaurus"); }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5232 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stop"); }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5233 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("wildcards"); }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5234 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("entire"); }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5235 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("content"); }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5236 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("word"); }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5237 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("start"); }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5238 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("end"); }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5239 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("most"); }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5240 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("skip"); }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5241 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("copy"); }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5242 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("value"); }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5243 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("eq"); }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5244 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ne"); }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5245 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lt"); }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5246 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("le"); }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5247 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("gt"); }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5248 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ge"); }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5249 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("at"); }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5250 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("context"); }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5251 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("variable"); }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5252 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("return"); }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5253 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("for"); }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5254 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("outer"); }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5255 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sliding"); }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5256 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("tumbling"); }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5257 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("previous"); }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5258 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("next"); }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5259 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("only"); }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5260 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("when"); }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5261 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("count"); }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5262 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("in"); }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5263 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("let"); }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5264 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("where"); }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5265 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("by"); }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5266 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("group"); }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5267 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("order"); }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5268 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stable"); }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5269 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ascending"); }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5270 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("descending"); }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5271 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("greatest"); }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5272 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("least"); }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5273 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("collation"); }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5274 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("some"); }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5275 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("every"); }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5276 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("satisfies"); }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5277 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("case"); }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5278 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("as"); }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5279 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("then"); }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5280 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("else"); }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5281 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("or"); }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5282 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("and"); }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5283 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("instance"); }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5284 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("of"); }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5285 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("castable"); }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5286 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("to"); }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5287 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("div"); }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5288 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("mod"); }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5289 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("union"); }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5290 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("intersect"); }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5291 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("except"); }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5292 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("validate"); }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5293 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("cast"); }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5294 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("treat"); }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5295 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("is"); }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5296 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("preserve"); }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5297 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("strip"); }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5298 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("namespace"); }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5299 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("external"); }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5300 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("encoding"); }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5301 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("no-preserve"); }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5302 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("inherit"); }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5303 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("no-inherit"); }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5304 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("declare"); }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5305 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("construction"); }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5306 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ordering"); }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5307 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("default"); }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5308 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("copy-namespaces"); }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 5309 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("option"); }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 5310 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("version"); }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 5311 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("import"); }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 5312 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema"); }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 5313 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("module"); }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 5314 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("function"); }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 5315 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("score"); }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 5316 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ftcontains"); }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 5317 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("weight"); }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 5318 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("window"); }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 5319 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("distance"); }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 5320 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("occurs"); }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 5321 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("times"); }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 5322 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("same"); }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 5323 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("different"); }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 5324 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lowercase"); }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 5325 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("uppercase"); }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 5326 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("relationship"); }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 5327 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("levels"); }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 5328 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("language"); }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 5329 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("any"); }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 5330 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("all"); }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 5331 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("phrase"); }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 5332 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("exactly"); }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 5333 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("from"); }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 5334 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("words"); }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 5335 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sentences"); }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 5336 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sentence"); }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 5337 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("paragraph"); }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 5338 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("replace"); }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 5339 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("modify"); }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 5340 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("first"); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 5341 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("insert"); }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 5342 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("before"); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 5343 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("after"); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 5344 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("revalidation"); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 5345 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("with"); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 5346 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("nodes"); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 5347 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("rename"); }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 5348 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("last"); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 5349 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("delete"); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 5350 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("into"); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 5351 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("simple"); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 5352 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sequential"); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 5353 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("updating"); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 5354 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("deterministic"); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 5355 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("nondeterministic"); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 5356 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ordered"); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 5357 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("unordered"); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 5358 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("returning"); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 5359 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("block"); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 5360 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("exit"); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 5361 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("loop"); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 5362 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("while"); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 5363 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("break"); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 5364 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("continue"); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 5365 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("try"); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 5366 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("catch"); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 5367 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("eval"); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 5368 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("using"); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 5369 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("set"); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 5370 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("index"); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 5371 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("unique"); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 5372 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("non"); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 5373 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("on"); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 5374 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("range"); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 5375 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("equality"); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 5376 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("manually"); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 5377 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("automatically"); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 5378 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("maintained"); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 5379 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("decimal-format"); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 5380 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("decimal-separator"); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 5381 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("grouping-separator"); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 5382 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("infinity"); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 5383 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("minus-sign"); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 5384 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("NaN"); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 5385 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("percent"); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 5386 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("per-mille"); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 5387 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("zero-digit"); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 5388 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("digit"); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 5389 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("pattern-separator"); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 5390 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("collection"); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 5391 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("const"); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 5392 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("append-only"); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 5393 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("queue"); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 5394 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("mutable"); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 5395 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("read-only"); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 5396 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("integrity"); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 5397 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("constraint"); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 5398 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("check"); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 5399 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("key"); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 5400 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("foreach"); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 5401 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("foreign"); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 5402 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("keys"); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 5415 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), dynamic_cast<FTOr*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 5423 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 5427 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 5434 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 5439 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 5448 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 5452 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr(
                LOC((yyloc)), dynamic_cast<FTOr*>((yysemantic_stack_[(3) - (1)].node)), dynamic_cast<FTAnd*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 5462 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 5466 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd(
                LOC((yyloc)), dynamic_cast<FTAnd*>((yysemantic_stack_[(3) - (1)].node)), dynamic_cast<FTMildNot*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 5476 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 5480 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot(
                LOC((yyloc)),
                dynamic_cast<FTMildNot*>((yysemantic_stack_[(4) - (1)].node)), dynamic_cast<FTUnaryNot*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 5491 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 5495 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 5505 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5517 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 5521 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 5528 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 5532 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 5540 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 5548 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5556 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 5560 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 5567 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 5571 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 5579 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5590 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 5594 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 5602 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5614 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 5620 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 5629 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 5633 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 5641 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 5645 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 5649 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 5656 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 5660 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 5667 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 5671 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 5679 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 5683 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 5687 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 5691 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 5695 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 5703 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 5711 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5723 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5735 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 5739 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 5743 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 5751 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 5757 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 5767 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 5771 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 5775 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 5779 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 5783 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 5787 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 5791 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 5795 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 5803 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 5807 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 5811 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 5815 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 5823 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::senstive
            );
        }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 5829 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 5839 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 5849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 5853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 5861 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5871 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5882 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 5889 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 5893 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 5900 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 5904 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(1) - (1)].thesaurus_id_list);
        }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 5911 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 5916 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 5925 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 5934 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 5938 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 5945 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 5949 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 5957 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5966 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 5973 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 5983 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 5987 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 5994 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6000 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6009 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6013 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6020 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6025 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 6037 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 6045 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 6057 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6065 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6069 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6077 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6081 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6085 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6093 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6101 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6105 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6109 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6113 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6121 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 6129 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 6141 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6145 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6153 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;



/* Line 678 of lalr1.cc  */
#line 11027 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1307;
  const short int
  xquery_parser::yypact_[] =
  {
      1520, -1307, -1307, -1307, -1307,   960,    15, -1307, -1307,   435,
   -1307, -1307, -1307, -1307,   -49,   135,  9309,   190,   354,   231,
     256,   266, -1307,    22, -1307, -1307, -1307, -1307, -1307, -1307,
     121, -1307,  7607, -1307, -1307,   286, -1307,   326, -1307, -1307,
     357, -1307,   436, -1307,   341, -1307,   164, -1307, -1307, -1307,
   -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307,
   -1307, -1307, -1307, -1307, -1307, -1307,  9591, -1307,  7031, -1307,
   -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307,
   -1307, -1307, 11001, -1307, -1307, -1307, -1307, -1307, -1307, -1307,
   -1307,   423, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307,
   -1307, -1307, -1307,  1811, 11001, -1307, -1307, -1307, -1307, -1307,
   -1307, -1307,   416, -1307, -1307, -1307,  8179, -1307,  8463, -1307,
   -1307, -1307, -1307, -1307, 11001, -1307, -1307,  6741, -1307, -1307,
   -1307, -1307, -1307, -1307,   424, -1307, -1307, -1307, -1307, -1307,
   -1307, -1307, -1307,    36,   332, -1307, -1307, -1307, -1307, -1307,
   -1307, -1307, -1307,   280,   407,   394, -1307,   384,   -82, -1307,
   -1307, -1307, -1307, -1307, -1307,   493, -1307,   463,   391,   395,
     413, -1307, -1307,   497,   505, -1307,   540, -1307, -1307, -1307,
   -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307,
   -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307,
   -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307,
   -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307,
   -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307,
   -1307, -1307, -1307, -1307, -1307,  4711,   653, -1307,  5001, -1307,
   -1307,   499,  5291,   474,   476, -1307, -1307, -1307, -1307, -1307,
   -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307,
   -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307,
   -1307, -1307, -1307, -1307, -1307, -1307,    -6, -1307, -1307, -1307,
   -1307,   124, 11001, -1307, -1307, -1307, -1307, -1307,   510,   588,
   -1307,   609,   428,   225,   308,   239,   349, -1307,   637,   494,
     593,   594,  5581, -1307, -1307, -1307,   -22, -1307, -1307,  6741,
   -1307,   458, -1307,   551,  7031, -1307,   551,  7031, -1307, -1307,
   -1307,   480, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307,
   -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307,
   -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307,
   -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307,
   -1307, -1307, -1307, -1307,   224, -1307, -1307,   677,   311,   367,
     167,   469, 11001,   469, 11001,   -48,   658,   660,   664, 11001,
     564,   597,   371,  8179, -1307, -1307,   409,   305,   471, 11001,
   -1307, -1307, -1307, -1307, -1307,   431, 11001,   427,   429,   418,
     539, -1307, -1307, -1307,  8179,  5291,   543,  5291,    53, -1307,
   -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307,
   -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307,
   -1307,  5291,  9873, -1307, -1307, -1307, -1307, -1307, -1307, -1307,
   -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307,   575,
    5291,   446,   447, -1307,   612,     9,   580,  5291,    42,   248,
   11001,   614, -1307,  5291,  7893,   582, -1307, 11001, 11001, 11001,
    5291,   552,  5291, 11001,  5291,   584,   591,  5291, 10155,   595,
     599,   600,   601,   603,   605, -1307, -1307, -1307, 11001, -1307,
     561,   715,  5291,    44, -1307,   729,   576, -1307,  5291,   554,
   -1307,   736,  5291,  5291,   586,  5291,  5291,  5291,  5291,   544,
   11001, -1307, -1307, -1307, -1307,  5291,  5291,  5291, 11001, -1307,
   -1307, -1307, -1307,   960,   266, -1307, -1307,   499,   740,  5291,
   -1307,  5291,   650,   354,    22,   121,   610,   607,   613,  5291,
    5291, -1307, -1307, -1307, -1307, -1307, -1307, -1307,   670, -1307,
     -29,  5871,  5871,  5871, -1307,  5871,  5871, -1307,  5871, -1307,
    5871, -1307, -1307, -1307, -1307, -1307, -1307, -1307,  5871,  5871,
      12,  5871,  5871,  5871,  5871,  5871,  5871,  5871,  5871,  5871,
    5871,  5871,   549,   686,   689,   690, -1307, -1307, -1307,  2101,
   -1307, -1307,  6741,  6741,  5291,   551, -1307, -1307,   551, -1307,
    2391,   551,   639,  2681, -1307, -1307, -1307, -1307, -1307, -1307,
     684,   685, -1307,   231, -1307,   766, -1307, -1307, 11001, -1307,
   -1307, 11001, -1307,   512,   204, 11001,   448,   636,   638,   512,
     677,   673,   665, -1307, -1307, -1307, -1307, -1307,   -14,   556,
     -24, -1307,   502, -1307, -1307, 11001, 11001, 11001, -1307,   676,
     622, -1307,   626,   600,   286, -1307,   624,   631,   635, -1307,
      14,    18,  2971,   640, -1307, -1307, 11001,   -12, 11001,   723,
      37, -1307,  5291, -1307,   634,  8179,   724,   775,  8179,   677,
     727,   722, -1307,    -7, -1307,   654,   652, -1307,   655,  3261,
     656,   697,    -9, -1307,     2,   662, -1307,   661,   693, -1307,
     666,  5291,  5291,   667, -1307,    54,   174,  3551,     4, -1307,
   11001,   715, -1307,     0,   668, -1307, -1307, -1307, -1307,   669,
   -1307,   163, -1307, -1307, -1307,   -11,    78,   752,   616,   629,
      13, -1307,   713,  6161, -1307,   671,   675,    46, -1307, -1307,
     672, -1307,  1041, -1307, -1307,    -3, 11001,   691,  5291,   739,
   -1307, -1307,   743, 10437,   744,  5291,   745,   -67,   709,   -40,
     588, -1307, -1307, -1307, -1307, -1307,  5871, -1307, -1307, -1307,
    5291,    12,    33,   337, -1307,   581,   -41,   602,   608, -1307,
   -1307,   471, -1307,   604,   126,   308,   308,   179,   239,   239,
     239,   239,   349,   349, -1307, -1307, 10437, 10437, 11001, 11001,
   -1307,   694, -1307, -1307,   683, -1307, -1307, -1307,   175, -1307,
   -1307,   180,   386,   387,   404, -1307,   231,   231, -1307, -1307,
   -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307,   512, -1307,
     737, 10719,   730,  5291, -1307, -1307, -1307,   778,   741,  5291,
     677,   677,   512, -1307,   498,   677,   166, 11001,   292,   301,
     849, -1307, -1307,   596,   307, -1307, -1307, -1307, -1307, -1307,
   -1307, -1307, -1307, -1307, -1307, -1307,   -14,    93,   360, -1307,
     657,   205,    -2,   587,   677, -1307, -1307, -1307, -1307,   726,
   11001, -1307, 11001, -1307, -1307,   698, -1307,   243,   641, -1307,
   -1307,   283,   -12,   778, 10437,   768,   793,   707,   695,   759,
     677,   733,   762,   798,   677,   777,  5291,   756,   -56,   746,
   -1307, -1307, -1307,   717, -1307,  5291,   781,  5291,  5291,   755,
   -1307,   801,  5291, -1307,   721,   732,   753, 11001, -1307, 11001,
   -1307, -1307,   734,  5291,   869, -1307,   160, -1307,   198, -1307,
   -1307,   883, -1307,   410,  5291,  5291,  5291,   414,  5291,  5291,
    5291,  5291,  5291,  5291,   796,  5291,  5291,   597,    11,   735,
     463,   678,   770,   799,   740,   840, -1307, -1307,  5291,   422,
     816, -1307, 11001,   817, -1307, 11001,   771,   772, 10719,   773,
   -1307,   321, -1307, -1307, -1307, -1307, -1307, -1307, -1307, 11001,
   -1307, 11001,  5291,   783,  5291,  5291,     5,   784, -1307,   749,
     747, -1307,    12,   687, -1307, -1307,  -121, -1307,   297,   -30,
     688,    12,   297,  5871, -1307,    60, -1307, -1307, -1307, -1307,
   -1307, -1307,    12,   787,   659,   556,   -30, -1307, -1307,   649,
     856, -1307, -1307, -1307, -1307, -1307, -1307,   795, -1307, -1307,
   -1307,  5291, -1307, -1307, -1307, -1307, -1307, -1307, -1307,  5291,
   -1307,   405,   408, -1307,   913,   470, -1307, -1307, -1307,  5291,
   -1307, -1307, -1307, -1307, -1307, -1307, -1307,   663, -1307, -1307,
     914, -1307, -1307, -1307, -1307, -1307,   320,   915, -1307,   439,
   -1307, -1307, -1307,   599,   135,   601,   603,   605,   407,   708,
     321,   719,   725,  6451,   674,   643,    93, -1307,   728,   760,
    3841,   765,   767,   810,   774,   776, -1307,  5291,   809, -1307,
     837,   838,  5291, 11001,   518,   880, -1307, -1307, -1307, -1307,
   -1307, -1307, 10437, -1307,  5291,   677,   854, -1307, -1307, -1307,
     677,   854, 11001, -1307,  5291,  5291,   822,  4131, -1307, -1307,
   11001, -1307, -1307,  5291,  9027,    35, -1307,   786, -1307, -1307,
    4421,   780,   788, -1307, -1307, -1307,   835, -1307,   451, -1307,
   -1307,   957, -1307, -1307, 11001, -1307, -1307,   542, -1307, -1307,
   -1307,   785,   748,   754, -1307, -1307, -1307,   757,   761, -1307,
   -1307, -1307, -1307, -1307,   742, 11001,   791, -1307,   831, -1307,
     597, -1307, -1307, -1307,  7321,   678, -1307,  5291, 11001,   816,
   -1307,   677, -1307,   541, -1307,   232,   870, -1307,  5291,   872,
     739, -1307,  8745,   800,   802,   806, -1307, -1307, -1307, -1307,
   -1307, -1307, -1307,  5291, -1307, -1307,  5291,   830,  5291, -1307,
   -1307, -1307,   813,  5871, -1307, -1307, -1307, -1307, -1307,    41,
    5871,  5871,  -135, -1307,   602, -1307,   161, -1307,   608,    12,
     832, -1307, -1307,   731, -1307, -1307, -1307, -1307, -1307, -1307,
     819, -1307, -1307, -1307,  5291, -1307, -1307, -1307, -1307, -1307,
     964,   -10,   970,   -10,   751,   906, -1307, -1307, -1307, -1307,
     836, 11001,   750,   708,  6451, -1307, -1307,   825, -1307, -1307,
   -1307, -1307, -1307, -1307,  5291, 11001, 11001, -1307,    85, -1307,
    5291, -1307,   879,   912,   677,   854, -1307, -1307, -1307,  5291,
   -1307,   829, -1307, -1307, 11001,   828,    73, -1307, -1307, -1307,
     833, -1307, -1307,   869, 11001,   569, -1307,   869, 11001, -1307,
   -1307,  5291,  5291,  5291,  5291,  5291, -1307,  5291,  5291, -1307,
   -1307,   149, -1307,   841, -1307, -1307, -1307, -1307,   870, -1307,
   -1307, -1307,   677, -1307, -1307,   918,   839, -1307,   184, -1307,
   -1307, -1307, -1307, -1307,  5291, -1307, -1307,   239,  5871,  5871,
     179,   236, -1307, -1307, -1307, -1307, -1307, -1307,  5291, -1307,
   -1307,    16, -1307,   201,   201, -1307,   -10, -1307, -1307,   216,
   -1307,   986,   -30,   842,   909, -1307,  6451,   -65,   758, -1307,
     853, -1307, -1307, -1307,   971, -1307, -1307,  5291,   677, -1307,
   -1307, -1307,   934,  5291, 11001,  5291, -1307,   -18,   869, 11001,
     843,   869, -1307, -1307, -1307, -1307, -1307, -1307, -1307,   911,
    7321, -1307, -1307, -1307, -1307, 10437, -1307, 10437,   936, -1307,
     179,   179,  5871,   850, -1307, -1307, -1307, -1307,  1005, -1307,
   -1307, -1307,   779, -1307,   906,   926, -1307,   940, 11001,   920,
     818, 11001,  6451,   922, -1307,   854, 10437, -1307,   861, -1307,
     181,   145, -1307,   851,   869, -1307,   852, 11001, -1307, -1307,
   -1307, 10437,   179, -1307, -1307, -1307, -1307,  6451, 11001,   763,
   11001,   929,   826,   926, 11001,   865,  5291, -1307, -1307,   943,
     303, -1307, -1307, -1307, -1307,   871,   254, -1307, -1307, -1307,
     858, -1307,   218, -1307, -1307,   870,  5291,   764, 11001,   932,
   -1307,  5291, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307,
     935,   903, -1307, -1307,   769,   782, 11001, -1307, 11001, -1307,
     789,  5291,   790,   220,  6451, -1307,  6451,   937,   903, -1307,
     862, 11001, -1307,   792,   873, 11001,   903,   844, -1307,   941,
   11001,   794,  6451, -1307
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
       0,   867,   872,     0,     0,   868,   902,   855,   857,   858,
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
      98,    63,    64,    69,    70,    60,   873,     0,   876,   903,
       0,   866,   865,   870,   869,   901,     0,     0,   878,     0,
     874,   877,   856,     0,     0,     0,     0,     0,     0,   117,
     123,     0,     0,     0,     0,     0,     0,   120,     0,     0,
       0,     0,     0,   554,     0,     0,   492,     0,     0,   205,
       0,     0,     0,     0,   250,     0,   247,   252,   208,   172,
     141,   170,     0,   173,     0,     0,    87,    81,    84,    83,
       0,    79,     0,   241,     0,     0,     0,     0,   502,   151,
       0,   282,   286,     0,     0,     0,   290,     0,   357,   356,
       0,     0,     0,   496,   283,   452,     0,   441,     0,   475,
     472,     0,   476,   477,     0,   478,   471,     0,   446,   474,
     473,     0,     0,     0,   573,   574,   570,     0,     0,   578,
     579,   575,   584,   582,     0,     0,     0,   588,   149,   148,
       0,   145,   144,   153,     0,   589,   590,     0,     0,   265,
     277,     0,   278,     0,   269,   270,   271,   272,     0,   261,
       0,   225,     0,     0,     0,     0,   511,   513,   512,   509,
     234,   235,   228,     0,   230,   227,     0,     0,     0,   834,
     825,   831,     0,     0,   904,   905,   915,   914,   913,     0,
       0,     0,     0,   906,   811,   912,     0,   809,   813,     0,
       0,   818,   822,     0,   843,   838,   841,   837,   506,   434,
       0,   166,   165,   168,     0,    39,    90,   100,   890,   871,
       0,   895,     0,   895,   884,   879,   118,   124,   126,   125,
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
     174,     0,   891,     0,     0,   889,   896,   897,   893,     0,
     888,     0,   886,     0,   880,   881,     0,     0,     0,   122,
       0,   494,   246,   254,   255,   249,   206,     0,     0,    82,
     244,   504,     0,     0,     0,     0,   498,     0,   451,     0,
       0,   451,   571,   572,   576,   577,   583,   585,   150,     0,
       0,   592,   603,   276,   263,     0,   563,     0,     0,   233,
     910,   909,     0,     0,   167,   900,   899,   898,     0,   892,
     885,   883,     0,   875,     0,   127,   129,     0,     0,     0,
       0,     0,     0,     0,   294,    88,     0,   292,     0,   288,
     461,   455,   450,     0,   451,   442,     0,     0,   597,   564,
     520,     0,   911,   823,   894,   887,   882,     0,     0,     0,
       0,     0,     0,   128,     0,     0,     0,   469,   463,     0,
     462,   464,   470,   467,   457,     0,   456,   458,   468,   444,
       0,   443,     0,   565,   130,   131,     0,     0,     0,     0,
     253,     0,   289,   454,   465,   466,   453,   459,   460,   445,
       0,     0,   132,   133,     0,     0,     0,   293,     0,   593,
       0,     0,     0,     0,     0,   135,     0,     0,     0,   134,
       0,     0,   594,     0,     0,     0,     0,     0,   595,     0,
       0,     0,     0,   136
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1307, -1307,   820, -1307,   823,   834, -1307,   815, -1307,   527,
     530,  -515, -1307,   438,  -284, -1307, -1307, -1307, -1307, -1307,
   -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307,  -894,
   -1307, -1307, -1307, -1307,    19,   237,   692, -1307, -1307,   679,
   -1307,   -28,  -852, -1307,  -391,  -411, -1307, -1307,  -572, -1307,
    -879, -1307, -1307,  -112, -1307, -1307, -1307, -1307, -1307,   261,
     703, -1307, -1307, -1307,   187,   628, -1306,   845,   -88, -1307,
    -528,  -433, -1307, -1307, -1307, -1307,   200, -1307, -1307,   812,
   -1307, -1307, -1307, -1307, -1307,   119,  -511,  -656, -1307, -1307,
   -1307,   -37, -1307, -1307,  -202,    -4,  -100, -1307, -1307, -1307,
    -110, -1307, -1307,   134,  -104, -1307, -1307,  -102, -1177, -1307,
     617,   -33, -1307, -1307,   -31, -1307, -1307,   566,   560, -1307,
    -513, -1307, -1307,  -571,    92,  -552,    88,    91, -1307, -1307,
   -1307, -1307, -1307,   821, -1307, -1307, -1307, -1307,  -561,  -287,
   -1055, -1307,  -115, -1307, -1307, -1307, -1307, -1307, -1307, -1307,
     -38, -1163, -1307, -1307,   290,   -26, -1307,  -556, -1307, -1307,
   -1307, -1307, -1307, -1307, -1307,   515, -1307,  -920, -1307,   -43,
   -1307,   411,  -707, -1307, -1307, -1307, -1307, -1307,  -387,  -379,
   -1106, -1007, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307,
   -1307, -1307,   327,  -616,  -789,    39,  -777, -1307,  -793,  -732,
   -1307, -1307, -1307, -1307, -1307, -1307, -1307,   797,   803,  -458,
     245,    71, -1307, -1307, -1307, -1307, -1307, -1307, -1307, -1307,
   -1307, -1307, -1307, -1307, -1307, -1307,   -55, -1307, -1307,   -64,
   -1307,  -366,  -105,   -16, -1307, -1307,  -737, -1307, -1307, -1307,
     122,   110,  -114,   362, -1307, -1307, -1307, -1307, -1307, -1307,
   -1307, -1307, -1307, -1307, -1307, -1307, -1307,   123, -1307, -1307,
   -1307,  -109,   355,   273, -1307, -1307, -1307, -1307, -1307,    61,
   -1307, -1307, -1231, -1307, -1307, -1307,  -708, -1307,  -132, -1307,
    -244, -1307, -1307, -1307, -1307, -1000, -1307,   131, -1307
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   828,   829,   830,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,  1126,
     679,   261,   262,   834,   835,   836,  1188,   263,   400,   401,
     264,  1089,   869,   265,  1455,  1456,   266,   267,   456,   268,
     512,   733,   958,  1189,   269,   270,   271,   272,   273,   402,
     403,   619,   622,   670,   671,  1165,  1050,   274,   275,   531,
     276,   277,   278,   541,   454,   891,   892,   279,   542,   280,
     544,   281,   282,   283,   548,   549,  1114,   758,   284,   681,
     737,   682,   667,  1115,  1116,  1117,   738,   545,   546,   973,
     974,  1353,   547,   970,   971,  1204,  1205,  1206,  1207,   285,
     692,   693,   286,  1145,  1146,   287,   288,   289,   290,   766,
     291,  1004,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   568,   569,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   595,   596,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   808,   331,   332,   333,  1167,
     711,   712,   713,  1472,  1505,  1506,  1499,  1500,  1507,  1501,
    1168,  1169,   334,   335,  1170,   336,   337,   338,   339,   340,
     341,   342,  1036,   759,   980,  1219,   981,  1358,   982,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   698,
    1102,   353,   354,   355,   356,   984,   985,   986,   987,   357,
     358,   359,   360,   361,   362,   730,   731,   363,  1195,  1196,
    1341,  1127,   465,   364,   365,   366,   775,  1014,  1015,   776,
     777,   778,   779,   780,  1024,  1251,  1252,   781,  1027,   782,
    1232,   783,   784,  1032,  1033,  1257,  1255,  1016,  1017,  1018,
    1019,  1375,   639,   857,   858,   859,   860,   861,   862,  1080,
    1393,  1394,  1081,  1392,  1451,   863,  1273,  1389,  1385,  1386,
    1387,   864,   865,  1020,  1028,  1242,  1021,  1238,  1005
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       449,   605,   787,   745,   936,  1037,  1037,  1034,  1035,   773,
    1131,   493,   497,   743,   774,   490,   466,   663,  1166,   590,
    1097,   983,   788,   789,   790,   791,  1253,   907,  1349,  1350,
     485,  1340,     4,   846,  1000,  1431,   847,   888,  1280,   757,
     762,   814,   763,   764,  1395,   765,  1458,   767,  1006,   754,
     479,   715,   486,     4,  1055,   768,   769,   499,   753,  1239,
     754,  1329,   604,   867,   983,   983,   487,   908,  1470,   722,
     723,   992,   725,   726,   727,   728,   943,  1135,   919,   848,
     753,  1193,   734,   735,   962,  1096,  1368,  1234,   491,   753,
     653,   916,   676,   680,   529,   407,   744,   529,   995,   983,
     466,   993,   495,   997,   916,  1120,   750,   751,   496,   755,
     654,  1190,   616,   954,   880,    74,   529,  1383,   882,  1007,
     668,   937,   589,  1083,  1235,  1372,   906,    85,  1144,  1084,
     653,  1110,  1373,   460,   508,  1090,    74,   895,  1111,   509,
     918,  1316,  1374,  1226,   617,   118,   963,  1085,    85,  1006,
     654,  1459,    99,  1159,   927,  1471,   770,   532,  1086,   771,
     461,  1369,   983,   533,  1503,   947,   404,   807,   534,   917,
     807,  1433,  1262,    99,   754,   530,   535,   770,   966,   118,
     771,  1384,   933,  1087,  1414,  1497,   669,   938,   536,  1159,
    1444,   881,  1191,   675,   591,   883,   889,   756,   944,   945,
     118,  1214,  1008,  1009,   868,  1010,  1159,  1160,   756,   716,
     773,   773,  1011,   946,   896,   774,   774,  1240,  1241,  1329,
    1007,  1058,  1012,  1486,   756,  1539,   868,  1156,   849,  1400,
     655,   928,  1460,   890,  1013,   756,  1305,  1276,  1166,   955,
     500,   850,  1552,   851,  1051,  1052,   983,  1166,   996,  1415,
    1558,   473,  1136,   998,   852,   853,   854,   756,   855,  1162,
     856,  1163,  1159,   772,   843,  1231,   550,  1478,   604,   756,
    1504,  1108,   124,  1503,   929,  1041,   597,  1119,   632,   599,
    1041,  1157,   408,   537,  1437,   941,   538,   948,   949,   672,
    1270,   831,   458,  1049,  1161,  1162,  1429,  1163,   486,   649,
     539,   486,   950,  1008,  1009,  1498,  1010,  1497,   474,  1088,
     571,  1159,  1162,   903,  1163,   969,  1448,   650,  1530,   652,
    1547,   459,   990,  1012,   610,   672,   540,   572,   571,  1110,
     753,  1201,   832,  1301,   450,  1013,  1111,   833,  1532,   611,
    1227,  1457,   672,   658,   942,   572,   104,  1158,  1272,  1430,
    1203,   930,  1042,  1112,   677,  1315,   613,  1043,   615,   688,
     602,  1438,   116,   623,  1090,  1029,  1030,   466,  1162,   674,
    1163,   603,   754,   640,   571,   685,   475,   476,   455,  1527,
     642,  1107,   695,  1164,   697,   571,   700,  1031,   466,   703,
     983,   572,  1452,  1449,  1113,  1531,  1077,  1548,   672,   678,
    1057,   143,   572,   457,   714,  1166,  1060,  1457,   627,  1270,
     719,   628,   983,  1078,   573,   451,   661,  1162,   574,  1163,
     452,  1372,  1101,  1357,  1104,  1442,  1271,  1524,  1373,   736,
     578,  1399,  1457,   467,  1066,  1067,  1068,   468,  1374,   579,
    1069,   773,  1246,   629,   683,   575,   774,   672,   466,   743,
     773,   690,   691,   694,  1079,   774,  1216,   699,   576,  1159,
    1160,   773,   706,  1502,  1508,   453,   774,  1272,   469,  1151,
     630,  1152,   694,  1133,  1061,  1062,   580,   802,   803,  1065,
     983,  1002,  1139,   606,  1141,  1142,   590,  1217,   472,  1549,
     581,  1550,   577,  1502,   732,  1094,   502,   607,   503,  1508,
    1154,   801,   739,  1095,   118,  1218,   804,  1563,  1099,   372,
    1200,  1174,  1175,  1176,  1465,  1179,  1180,  1181,  1182,  1183,
    1184,  1201,  1186,  1187,   523,  1044,  1046,   376,  1077,   377,
     631,  1202,  1048,  1261,   488,   969,  1263,   378,   501,   608,
    1203,   524,  1045,  1047,  1053,  1078,  1071,  1161,  1049,   511,
    1159,  1160,  1264,   609,   504,  1073,  1236,  1072,  1053,  1222,
     492,  1224,  1225,  1237,  1110,  1162,  1074,  1163,   498,   805,
     899,  1111,   805,   902,   885,   805,   838,  1159,  1160,   405,
     470,   839,   406,   471,   897,   818,   819,   820,   821,   822,
     823,   824,   825,   826,   827,   672,   636,   637,   832,   104,
     507,   913,   816,   833,   510,   817,   598,   511,  1259,   837,
     505,   601,   506,   924,   925,   116,  1417,  1063,  1064,   932,
    1420,   633,   634,   635,   513,   594,  1267,   600,   514,   871,
     872,   873,   612,  1172,   614,  1173,  1324,  1177,  1161,  1178,
     592,   593,  1091,  1092,   516,   959,  1479,   515,  1480,   517,
     887,   518,   893,   520,   143,   527,  1162,   528,  1163,   466,
    1346,  1347,   466,   785,   786,  1161,   792,   793,   551,  1370,
    1371,   794,   795,   552,  1293,  1445,  1446,  1495,   570,  1297,
     582,  1367,   999,  1162,   583,  1163,   672,   584,   773,   585,
     104,  1302,  1513,   774,   934,  1515,   594,   604,   618,   384,
     372,  1307,  1308,   983,   621,   983,   116,   624,   625,   638,
    1313,  1473,   645,   672,  1476,   641,   643,   104,   644,   662,
     651,   664,   665,   666,   672,   684,   689,  1328,   701,   696,
     967,   385,   553,   116,   983,   702,  1381,   988,   709,   707,
     554,   555,   710,   556,   717,   143,   406,   432,   464,   983,
     471,   557,   478,   718,  1419,   558,   721,   559,   720,  1303,
     387,   746,   560,   724,  1343,   742,   729,  1510,   748,   747,
     752,   796,   143,   797,   749,   969,   798,   799,   561,   809,
     988,   988,   988,   988,   812,   813,   815,   840,   845,   841,
    1362,   844,   870,  1363,   866,  1365,   875,  1440,  1441,   874,
     876,   877,   562,   563,   564,   565,   566,   567,   878,   879,
     894,   898,   901,   900,   886,   988,   904,   646,   390,   391,
     392,   393,   905,   394,   395,   647,   397,   398,   909,   910,
     915,  1070,   911,   914,  1147,  1345,   920,   922,   921,   951,
     923,   926,   939,   940,   952,   953,   956,   994,   960,   961,
     972,  1022,   968,   964,   975,   989,   991,  1003,  1040,  1023,
    1054,  1402,  1026,   833,  1103,   753,  1103,  1406,  1039,  1075,
    1100,  1482,  1106,  1076,  1059,  1093,  1410,  1098,   988,   668,
    1122,  1123,  1125,  1124,  1128,  1129,  1109,  1130,  1132,  1134,
    1137,  1138,  1140,  1143,  1144,  1148,  1155,  1150,  1422,  1423,
    1424,  1425,  1426,  1171,  1427,  1428,  1149,  1185,  1153,  1192,
    1198,   699,   629,   699,  1197,  1194,  1208,  1210,  1212,  1213,
    1215,  1223,  1228,  1229,  1230,  1249,  1254,  1256,  1233,  1243,
    1258,  1439,  1250,     4,  1269,  1274,   868,  1278,  1409,  1282,
    1268,  1285,  1288,  1279,  1289,  1290,  1284,  1294,  1295,  1296,
    1300,  1291,  1281,  1292,  1304,  1309,  1209,  1321,  1323,   550,
    1318,  1260,   988,  1326,  1338,  1322,  1330,  1337,  1364,  1201,
    1335,  1352,  1331,  1220,  1464,  1221,  1378,  1359,  1332,  1360,
    1467,  1333,  1469,  1361,  1382,  1334,  1434,  1366,   367,   368,
    1388,   369,   370,  1380,   371,  1077,  1407,  1396,  1398,  1401,
     372,  1408,  1379,  1411,  1413,  1435,  1450,  1416,   373,  1454,
     374,   375,  1287,  1391,  1462,  1432,  1436,  1463,   376,  1453,
     377,  1466,  1477,  1481,  1483,  1484,  1487,  1488,   378,  1523,
    1475,  1490,   379,  1494,  1491,  1485,  1461,  1496,  1509,  1511,
    1518,  1521,  1519,  1536,  1526,  1529,  1538,  1049,  1551,  1311,
    1556,  1553,  1560,  1540,   740,   519,   525,   741,  1516,  1534,
    1559,   521,  1320,  1522,   380,   381,   382,   842,  1283,  1056,
    1555,  1493,   522,   626,  1266,   371,  1514,  1541,  1339,   648,
     620,   372,  1121,  1533,   673,  1544,  1546,   526,  1537,   373,
    1562,   374,  1118,   543,  1211,  1306,  1405,  1298,  1344,   376,
    1354,   377,  1199,  1348,  1351,   708,   988,  1312,  1545,   378,
    1299,   383,   761,   379,  1317,  1325,   683,   760,   811,  1528,
     384,  1525,   935,   588,   694,  1265,  1038,  1105,   988,  1277,
    1336,  1342,  1248,  1244,  1001,  1377,  1025,  1376,  1247,  1082,
    1275,  1390,  1447,  1245,     0,   380,   381,   965,  1327,     0,
       0,     0,   385,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   732,
       0,   386,     0,     0,     0,     0,     0,     0,   486,     0,
       0,   387,   739,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   988,     0,     0,     0,
       0,   384,     0,     0,     0,   656,     0,     0,     0,     0,
       0,   657,   388,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   385,     0,     0,     0,     0,   389,   390,
     391,   392,   393,     0,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,     0,     0,     0,     0,     0,     0,
       0,     0,   387,     0,     0,  1397,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1403,
    1404,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1443,     0,     0,   388,     0,     0,     0,     0,  1412,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1418,     0,
       0,     0,  1421,     0,     0,     0,     0,     0,     0,   389,
     390,   391,   392,   393,     0,   394,   395,   396,   397,   398,
       0,     0,     0,     0,   399,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1468,     0,
       0,     0,     0,  1474,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   486,     0,     0,     0,     0,   988,
       0,   988,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1489,     0,     0,  1492,     0,     0,     0,     0,
     988,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1512,     0,     0,     0,   988,     0,     0,     0,     0,
       0,     0,   988,     0,  1517,     0,     0,     0,  1520,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1535,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1542,     0,  1543,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,  1554,     0,     2,     3,  1557,
       4,     0,     0,     0,  1561,     5,     6,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,    26,    27,
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
     119,   120,   121,     0,     0,     0,   122,     0,   123,   124,
     125,     0,   126,   127,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   144,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     0,
     187,   188,   189,     0,   190,   191,   192,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   409,   410,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   419,    22,    23,    24,    25,     0,    26,
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
       0,   119,   120,   121,     0,     0,     0,   122,   489,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   435,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   409,   410,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   419,    22,    23,    24,    25,     0,    26,
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
       0,   119,   120,   121,     0,   800,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   435,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   409,   410,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   419,    22,    23,    24,    25,     0,    26,
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
       0,   119,   120,   121,     0,     0,     0,   122,   806,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   435,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   409,   410,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   419,    22,    23,    24,    25,     0,    26,
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
       0,   119,   120,   121,     0,     0,     0,   122,   810,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   435,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   409,   410,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   419,    22,    23,    24,    25,     0,    26,
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
       0,   119,   120,   121,     0,   884,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   435,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   409,   410,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   419,    22,    23,    24,    25,     0,    26,
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
       0,   119,   120,   121,     0,   912,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   435,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   409,   410,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   419,    22,    23,    24,    25,     0,    26,
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
       0,   119,   120,   121,     0,   931,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   435,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   409,   410,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   419,    22,    23,    24,    25,     0,    26,
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
       0,   119,   120,   121,     0,  1286,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   435,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   409,   410,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   419,    22,    23,    24,    25,     0,    26,
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
       0,   119,   120,   121,     0,  1310,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   435,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   409,   410,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   419,    22,    23,    24,    25,     0,    26,
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
       0,   119,   120,   121,     0,  1319,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   435,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,     5,     6,     0,     7,
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
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,     5,     6,     0,     7,
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
       0,     0,   141,   142,   143,     0,   435,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   409,   410,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   419,    22,    23,    24,    25,     0,    26,
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
       0,     0,   141,   142,   143,     0,   435,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   409,   410,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,   415,
     416,    19,   418,   419,    22,   420,    24,    25,     0,    26,
      27,    28,    29,   421,    31,    32,    33,    34,    35,    36,
     424,    38,    39,   425,     0,    41,    42,    43,   427,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,     0,    72,
      73,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,    85,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   430,    92,    93,
      94,    95,     0,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,   103,   104,
     586,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,   587,   118,     0,
       0,   119,   120,   121,     0,     0,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   435,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   436,   154,   438,   156,
     439,   440,   159,   160,   161,   162,   163,   164,   441,   166,
     442,   443,   444,   445,   171,   172,   446,   447,   175,   448,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   409,   410,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,   415,
     416,    19,   418,   419,    22,   420,    24,    25,     0,    26,
      27,    28,    29,   421,    31,    32,    33,    34,    35,    36,
     424,    38,    39,   425,     0,    41,    42,    43,   427,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,     0,    72,
      73,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,    85,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   430,    92,    93,
      94,    95,     0,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,   103,   104,
     105,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,   117,   118,     0,
       0,   119,   120,   121,     0,     0,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   435,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   436,   154,   438,   156,
     439,   440,   159,   160,   161,   162,   163,   164,   441,   166,
     442,   443,   444,   445,   171,   172,   446,   447,   175,   448,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   957,   410,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   419,    22,    23,    24,    25,     0,    26,
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
       0,     0,   141,   142,   143,     0,   435,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   409,   410,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,   415,
     416,    19,   418,   419,    22,   420,    24,    25,     0,    26,
      27,    28,    29,   421,    31,    32,    33,    34,    35,    36,
     424,    38,    39,   425,     0,    41,    42,    43,   427,    45,
     428,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,     0,    72,
      73,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,    85,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   430,    92,    93,
      94,    95,     0,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,   103,   104,
       0,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,     0,     0,     0,
       0,   119,   120,   121,     0,     0,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   435,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   436,   154,   438,   156,
     439,   440,   159,   160,   161,   162,   163,   164,   441,   166,
     442,   443,   444,   445,   171,   172,   446,   447,   175,   448,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   409,   410,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,   415,
     416,    19,   418,   419,    22,   420,    24,    25,     0,    26,
      27,    28,    29,   421,    31,    32,    33,    34,    35,    36,
     424,    38,    39,   425,     0,    41,    42,    43,   427,    45,
     428,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,     0,    72,
      73,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,    85,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   430,    92,    93,
      94,    95,     0,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,   103,   104,
       0,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,     0,     0,     0,
       0,   119,   120,   121,     0,     0,     0,   122,     0,   123,
     124,   125,     0,     0,     0,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   435,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   436,   154,   438,   156,
     439,   440,   159,   160,   161,   162,   163,   164,   441,   166,
     442,   443,   444,   445,   171,   172,   446,   447,   175,   448,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     0,     0,     0,     0,     0,   409,   410,     0,     7,
       8,   480,    10,    11,    12,    13,   412,    15,   481,   415,
     416,   417,   418,   419,    22,   420,    24,    25,     0,    26,
      27,    28,    29,   421,    31,   482,    33,    34,    35,    36,
     424,    38,    39,   425,     0,    41,   483,    43,   427,    45,
     428,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   484,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   430,    92,    93,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,     0,   100,   101,   102,     0,     0,     0,     0,     0,
       0,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   433,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,     0,     0,     0,   122,     0,   123,
     124,     0,     0,     0,     0,   128,     0,   129,     0,   130,
     131,   132,   133,   434,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,     0,     0,   435,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   436,   154,   438,   156,
     439,   440,   159,   160,   161,   162,   163,   164,   441,   166,
     442,   443,   444,   445,   171,   172,   446,   447,   175,   448,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     1,     0,     0,     0,     0,     0,     0,     2,     3,
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
      98,     0,   100,   101,   102,     0,     0,     0,     0,     0,
       0,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   433,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,     0,     0,     0,   122,     0,   123,
       0,     0,     0,     0,     0,   128,     0,   129,     0,   130,
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
     234,   462,     0,     0,     0,     3,     0,     0,     0,     0,
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
     102,   463,     0,     0,   464,     0,     0,   106,   107,     0,
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
     228,   229,   230,   231,   232,   233,   234,   462,     0,     0,
       0,     3,     0,   686,     0,     0,     0,     0,   409,   410,
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
     687,   123,     0,     0,     0,     0,     0,     0,     0,   129,
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
     232,   233,   234,   462,     0,     0,     0,     3,     0,     0,
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
       0,   121,     0,     0,     0,   122,     0,   123,     0,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
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
     226,   227,   228,   229,   230,   231,   232,   233,   234,   494,
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
     232,   233,   234,     3,     0,     0,     0,     0,     0,     0,
     409,   410,     0,     7,     8,   480,    10,    11,    12,    13,
     412,    15,   481,   415,   416,   976,   418,   419,    22,   420,
      24,    25,     0,    26,    27,    28,    29,   421,    31,   482,
      33,    34,    35,    36,   424,    38,    39,   425,     0,    41,
     483,    43,   427,    45,   428,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   484,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   430,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   100,   101,   977,     0,
       0,     0,   978,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   433,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,  1355,   123,   124,     0,     0,     0,     0,  1356,
       0,   129,     0,   130,   131,   132,   133,   434,   135,   136,
     137,   138,   139,   140,     0,     0,   979,   142,     0,     0,
     435,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     436,   154,   438,   156,   439,   440,   159,   160,   161,   162,
     163,   164,   441,   166,   442,   443,   444,   445,   171,   172,
     446,   447,   175,   448,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     3,     0,     0,     0,     0,
       0,     0,   409,   410,     0,     7,     8,   480,    10,    11,
      12,    13,   412,    15,   481,   415,   416,   976,   418,   419,
      22,   420,    24,    25,     0,    26,    27,    28,    29,   421,
      31,   482,    33,    34,    35,    36,   424,    38,    39,   425,
       0,    41,   483,    43,   427,    45,   428,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    62,     0,    63,    64,    65,   484,     0,     0,
      69,    70,    71,     0,     0,     0,    73,     0,     0,     0,
       0,    75,    76,    77,     0,     0,    80,    81,  1314,     0,
       0,     0,     0,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   430,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,   100,   101,
     977,     0,     0,     0,   978,     0,     0,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   111,   433,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,   122,     0,   123,   124,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   434,
     135,   136,   137,   138,   139,   140,     0,     0,   979,   142,
       0,     0,   435,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   436,   154,   438,   156,   439,   440,   159,   160,
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
     100,   101,   102,   431,     0,     0,   432,     0,     0,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   111,   433,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   122,     0,   123,     0,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
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
      98,     0,   100,   101,   102,   477,     0,     0,   478,     0,
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
      96,    97,    98,     0,   100,   101,   102,     0,     0,     0,
       0,     0,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   111,   433,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   122,
     659,   123,     0,     0,     0,     0,     0,   660,     0,   129,
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
       0,     0,    96,    97,    98,     0,   100,   101,   102,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   433,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,   704,   123,     0,     0,     0,     0,     0,   705,
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
       0,     0,   409,   410,     0,     7,     8,   480,    10,    11,
      12,    13,   412,    15,   481,   415,   416,   976,   418,   419,
      22,   420,    24,    25,     0,    26,    27,    28,    29,   421,
      31,   482,    33,    34,    35,    36,   424,    38,    39,   425,
       0,    41,   483,    43,   427,    45,   428,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    62,     0,    63,    64,    65,   484,     0,     0,
      69,    70,    71,     0,     0,     0,    73,     0,     0,     0,
       0,    75,    76,    77,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   430,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,   100,   101,
     977,     0,     0,     0,   978,     0,     0,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   111,   433,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,   122,     0,   123,   124,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   434,
     135,   136,   137,   138,   139,   140,     0,     0,   979,   142,
       0,     0,   435,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   436,   154,   438,   156,   439,   440,   159,   160,
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
       0,   121,     0,     0,     0,   122,     0,   123,   124,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   434,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   435,   145,     0,   146,   147,   148,
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
      98,     0,   100,   101,   102,     0,     0,     0,     0,     0,
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
     234
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        16,   367,   573,   531,   711,   798,   799,   796,   797,   570,
     904,   116,   127,   528,   570,   103,    32,   450,   938,   306,
     872,   753,   574,   575,   576,   577,  1026,   683,  1205,  1206,
      68,  1194,    20,    47,   771,  1341,    50,    49,  1093,   550,
     553,   613,   555,   556,  1275,   558,   111,   560,    89,    89,
      66,     7,    68,    20,   831,   568,   569,    21,    87,    89,
      89,  1167,    20,    87,   796,   797,    82,   683,    86,   502,
     503,   138,   505,   506,   507,   508,    87,   133,   694,    93,
      87,   960,   515,   516,    38,    87,    45,   208,   104,    87,
      37,   100,   458,   459,   100,   144,   529,   100,   138,   831,
     116,   757,   118,   759,   100,   894,   539,   540,   124,   138,
      57,   100,   160,   100,   100,   103,   100,   127,   100,   160,
     111,   121,   144,    30,   245,   260,   133,   115,    93,    36,
      37,    46,   267,   111,   216,   867,   103,   100,    53,   221,
     138,   106,   277,   138,   192,   167,   100,    54,   115,    89,
      57,   216,   140,     8,   100,   173,   144,    33,    65,   147,
      39,   120,   894,    39,    19,    87,   151,   600,    44,   178,
     603,  1348,  1051,   140,    89,   181,    52,   144,   181,   167,
     147,   191,   178,    90,   111,     4,   177,   187,    64,     8,
     174,   177,   181,   151,   309,   177,   208,   264,   209,   210,
     167,   978,   243,   244,   228,   246,     8,     9,   264,   165,
     771,   772,   253,   224,   177,   771,   772,   247,   248,  1325,
     160,   837,   263,  1454,   264,  1531,   228,   934,   242,  1284,
     177,   177,   297,   245,   275,   264,  1130,  1089,  1158,   226,
     204,   255,  1548,   257,   816,   817,   978,  1167,   759,   176,
    1556,    87,   908,   766,   268,   269,   270,   264,   272,   114,
     274,   116,     8,   251,   630,  1002,   282,  1430,    20,   264,
     125,   887,   179,    19,   100,   100,   314,   893,   383,   317,
     100,   121,   147,   159,   100,   122,   162,   209,   210,   144,
      89,    87,    26,   144,    96,   114,   147,   116,   314,   404,
     176,   317,   224,   243,   244,   124,   246,     4,   144,   216,
     149,     8,   114,   679,   116,   748,   100,   405,   100,   407,
     100,    55,   755,   263,   157,   144,   202,   166,   149,    46,
      87,    99,   128,  1122,   144,   275,    53,   133,  1515,   172,
     996,  1396,   144,   431,   181,   166,   148,   187,   147,   200,
     118,   177,   177,    70,   106,  1144,   372,   177,   374,   464,
     136,   177,   164,   379,  1096,   239,   240,   383,   114,   457,
     116,   147,    89,   389,   149,   463,   212,   213,   147,   125,
     396,   138,   470,   185,   472,   149,   474,   261,   404,   477,
    1122,   166,  1392,   177,   111,   177,    89,   177,   144,   151,
     833,   203,   166,   147,   492,  1325,   839,  1462,    37,    89,
     498,    40,  1144,   106,   189,    61,   432,   114,   110,   116,
      66,   260,   880,  1212,   882,   189,   106,   124,   267,   517,
     191,  1283,  1487,   147,   268,   269,   270,   111,   277,   200,
     274,  1002,  1013,    72,   460,   137,  1002,   144,   464,   964,
    1011,   467,   468,   469,   147,  1011,   135,   473,   150,     8,
       9,  1022,   478,  1470,  1471,   111,  1022,   147,   111,   927,
      99,   929,   488,   906,   840,   841,   127,   592,   593,   845,
    1212,   144,   915,   172,   917,   918,   773,   166,   147,  1544,
     141,  1546,   184,  1500,   510,   290,   216,   186,   218,  1506,
     933,   589,   518,   298,   167,   184,   594,  1562,   874,    40,
      88,   944,   945,   946,  1408,   948,   949,   950,   951,   952,
     953,    99,   955,   956,    25,   139,   139,    58,    89,    60,
     159,   109,   128,   128,   111,   968,   128,    68,   206,   172,
     118,    42,   156,   156,   828,   106,   254,    96,   144,   144,
       8,     9,   144,   186,   147,   254,   259,   265,   842,   992,
     144,   994,   995,   266,    46,   114,   265,   116,   144,   595,
     675,    53,   598,   678,   662,   601,   128,     8,     9,   144,
     144,   133,   147,   147,   672,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,   144,   291,   292,   128,   148,
     216,   689,   618,   133,   111,   621,   316,   144,  1041,   625,
     216,   321,   218,   701,   702,   164,  1323,   119,   120,   707,
    1327,   212,   213,   214,   233,   145,  1059,   147,   233,   645,
     646,   647,   371,   223,   373,   225,   185,   223,    96,   225,
     182,   183,   282,   283,   147,   733,  1435,   234,  1437,   144,
     666,   111,   668,     0,   203,   181,   114,   181,   116,   675,
     119,   120,   678,   571,   572,    96,   578,   579,   158,  1240,
    1241,   580,   581,    85,  1107,  1383,  1384,  1466,   250,  1112,
      43,  1233,   770,   114,   190,   116,   144,    94,  1249,    95,
     148,  1124,  1481,  1249,   710,  1488,   145,    20,    40,   160,
      40,  1134,  1135,  1435,    40,  1437,   164,   143,   111,   238,
    1143,  1418,   294,   144,  1421,   284,   289,   148,   289,   144,
     177,   275,   275,   111,   144,   111,   144,   185,   144,   177,
     746,   192,   123,   164,  1466,   144,  1264,   753,   177,   144,
     131,   132,    27,   134,    15,   203,   147,   147,   147,  1481,
     147,   142,   147,   177,   185,   146,    20,   148,   204,  1125,
     221,   111,   153,   177,  1197,    25,   222,  1474,   161,   159,
     100,   222,   203,    87,   161,  1208,    87,    87,   169,   140,
     796,   797,   798,   799,   100,   100,    20,   151,   123,   151,
    1223,   118,   290,  1226,   238,  1228,   174,  1368,  1369,   123,
     174,   177,   193,   194,   195,   196,   197,   198,   177,   174,
      87,   177,    37,    89,   174,   831,    89,   278,   279,   280,
     281,   282,   100,   284,   285,   286,   287,   288,   174,   177,
     133,   847,   177,   177,   922,  1201,   174,   144,   177,    87,
     174,   174,   174,   174,   228,   216,   133,   138,   177,   174,
     111,   249,   161,   181,   111,   111,   111,   276,   175,   251,
     123,  1294,   258,   133,   880,    87,   882,  1300,   174,    20,
     144,  1442,   174,   277,   133,   218,  1309,   290,   894,   111,
      87,   174,   123,   188,   151,   123,   245,    89,   111,   133,
     144,   174,   111,   138,    93,   174,    27,   144,  1331,  1332,
    1333,  1334,  1335,    20,  1337,  1338,   174,   111,   174,   174,
     111,   927,    72,   929,   144,   237,   100,   100,   147,   147,
     147,   138,   138,   174,   177,   138,   277,    71,   241,   241,
     135,  1364,   273,    20,    20,    20,   228,   218,  1304,   296,
     277,   181,   177,   218,   177,   135,   218,   138,   111,   111,
      70,   177,   278,   177,   100,   133,   972,   177,   123,   975,
     174,  1049,   978,     6,   133,   177,   181,   176,   138,    99,
     228,    99,   224,   989,  1407,   991,   144,   177,   224,   177,
    1413,   224,  1415,   177,    20,   224,  1352,   174,    28,    29,
      20,    31,    32,   174,    34,    89,   117,   161,   248,   174,
      40,    89,   271,   174,   176,    87,    20,   174,    48,   100,
      50,    51,  1100,   262,   161,   174,   177,    46,    58,   177,
      60,    87,   111,    87,   174,    20,   100,    87,    68,    86,
     187,   111,    72,   111,   216,   256,   278,   176,   187,   187,
     111,   176,   216,   111,   173,   187,   111,   144,   111,  1137,
     177,   189,   111,   284,   527,   235,   241,   527,   295,   295,
     216,   238,  1150,  1496,   104,   105,   106,   629,  1096,   832,
     278,  1462,   238,   381,  1055,    34,  1487,   295,  1190,   400,
     377,    40,   895,  1516,   456,   296,   296,   242,  1521,    48,
     296,    50,   892,   281,   975,  1132,  1298,  1113,  1198,    58,
    1210,    60,   968,  1205,  1208,   488,  1122,  1140,  1541,    68,
    1114,   151,   552,    72,  1145,  1158,  1132,   551,   603,  1506,
     160,  1500,   711,   302,  1140,  1054,   799,   882,  1144,  1090,
    1185,  1195,  1022,  1011,   772,  1249,   781,  1246,  1015,   866,
    1079,  1273,  1386,  1012,    -1,   104,   105,   106,  1164,    -1,
      -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1185,
      -1,   211,    -1,    -1,    -1,    -1,    -1,    -1,  1194,    -1,
      -1,   221,  1198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1212,    -1,    -1,    -1,
      -1,   160,    -1,    -1,    -1,   408,    -1,    -1,    -1,    -1,
      -1,   408,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,   278,   279,
     280,   281,   282,    -1,   284,   285,   286,   287,   288,    -1,
      -1,    -1,    -1,   293,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   221,    -1,    -1,  1281,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1295,
    1296,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1378,    -1,    -1,   252,    -1,    -1,    -1,    -1,  1314,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1324,    -1,
      -1,    -1,  1328,    -1,    -1,    -1,    -1,    -1,    -1,   278,
     279,   280,   281,   282,    -1,   284,   285,   286,   287,   288,
      -1,    -1,    -1,    -1,   293,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1414,    -1,
      -1,    -1,    -1,  1419,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1430,    -1,    -1,    -1,    -1,  1435,
      -1,  1437,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1458,    -1,    -1,  1461,    -1,    -1,    -1,    -1,
    1466,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1477,    -1,    -1,    -1,  1481,    -1,    -1,    -1,    -1,
      -1,    -1,  1488,    -1,  1490,    -1,    -1,    -1,  1494,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1518,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1536,    -1,  1538,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    -1,    -1,    -1,    -1,  1551,    -1,    17,    18,  1555,
      20,    -1,    -1,    -1,  1560,    25,    26,    -1,    28,    29,
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
     170,   171,   172,    -1,    -1,    -1,   176,    -1,   178,   179,
     180,    -1,   182,   183,   184,    -1,   186,    -1,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,    -1,
      -1,   201,   202,   203,    -1,   205,   206,    -1,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
     250,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
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
      -1,   170,   171,   172,    -1,    -1,    -1,   176,   177,   178,
     179,   180,    -1,   182,   183,   184,    -1,   186,    -1,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
      -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,   250,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
      -1,   250,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
      -1,   170,   171,   172,    -1,    -1,    -1,   176,   177,   178,
     179,   180,    -1,   182,   183,   184,    -1,   186,    -1,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
      -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,   250,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
      -1,   170,   171,   172,    -1,    -1,    -1,   176,   177,   178,
     179,   180,    -1,   182,   183,   184,    -1,   186,    -1,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
      -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,   250,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
      -1,   250,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
      -1,   250,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
      -1,   250,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
      -1,   250,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
      -1,   250,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
      -1,   250,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
      -1,   170,   171,   172,    -1,    -1,    -1,   176,    -1,   178,
     179,   180,    -1,   182,   183,   184,    -1,   186,    -1,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
      -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,   250,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
      -1,   170,   171,   172,    -1,    -1,    -1,   176,    -1,   178,
     179,   180,    -1,   182,   183,   184,    -1,   186,    -1,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
      -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,   250,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
      -1,   170,   171,   172,    -1,    -1,    -1,   176,    -1,   178,
     179,   180,    -1,   182,   183,   184,    -1,   186,    -1,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
      -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,   250,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
      -1,   170,   171,   172,    -1,    -1,    -1,   176,    -1,   178,
     179,   180,    -1,   182,   183,   184,    -1,   186,    -1,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
      -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,   250,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
      -1,   170,   171,   172,    -1,    -1,    -1,   176,    -1,   178,
     179,   180,    -1,   182,   183,   184,    -1,   186,    -1,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
      -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,   250,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
      -1,   170,   171,   172,    -1,    -1,    -1,   176,    -1,   178,
     179,   180,    -1,   182,   183,   184,    -1,   186,    -1,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
      -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,   250,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
     179,   180,    -1,   182,   183,   184,    -1,   186,    -1,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
      -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,   250,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
      -1,   250,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
     139,    -1,   141,   142,   143,    -1,    -1,    -1,    -1,    -1,
      -1,   150,   151,    -1,    -1,    -1,    -1,   156,   157,   158,
     159,   160,   161,   162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   172,    -1,    -1,    -1,   176,    -1,   178,
     179,    -1,    -1,    -1,    -1,   184,    -1,   186,    -1,   188,
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
     299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
     139,    -1,   141,   142,   143,    -1,    -1,    -1,    -1,    -1,
      -1,   150,   151,    -1,    -1,    -1,    -1,   156,   157,   158,
     159,   160,   161,   162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   172,    -1,    -1,    -1,   176,    -1,   178,
      -1,    -1,    -1,    -1,    -1,   184,    -1,   186,    -1,   188,
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
     299,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,
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
     143,   144,    -1,    -1,   147,    -1,    -1,   150,   151,    -1,
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
     293,   294,   295,   296,   297,   298,   299,    14,    -1,    -1,
      -1,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,
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
     177,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
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
     297,   298,   299,    14,    -1,    -1,    -1,    18,    -1,    -1,
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
     241,   242,   243,   244,   245,   246,   247,   248,    -1,   250,
     251,   252,    -1,   254,   255,   256,   257,   258,   259,    -1,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,    16,
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
      -1,    -1,   147,    -1,    -1,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,
      -1,   176,   177,   178,   179,    -1,    -1,    -1,    -1,   184,
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
      -1,   104,   105,   106,    -1,    -1,   109,   110,   111,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,    -1,   122,
      -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   138,   139,    -1,   141,   142,
     143,    -1,    -1,    -1,   147,    -1,    -1,   150,   151,    -1,
      -1,    -1,    -1,   156,   157,   158,   159,   160,   161,   162,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,
      -1,    -1,    -1,   176,    -1,   178,   179,    -1,    -1,    -1,
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
     141,   142,   143,   144,    -1,    -1,   147,    -1,    -1,   150,
     151,    -1,    -1,    -1,    -1,   156,   157,   158,   159,   160,
     161,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,    -1,    -1,    -1,   176,    -1,   178,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,    -1,   188,   189,   190,
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
      -1,    -1,    -1,   150,   151,    -1,    -1,    -1,    -1,   156,
     157,   158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,   176,
     177,   178,    -1,    -1,    -1,    -1,    -1,   184,    -1,   186,
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
      -1,   176,   177,   178,    -1,    -1,    -1,    -1,    -1,   184,
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
     143,    -1,    -1,    -1,   147,    -1,    -1,   150,   151,    -1,
      -1,    -1,    -1,   156,   157,   158,   159,   160,   161,   162,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,
      -1,    -1,    -1,   176,    -1,   178,   179,    -1,    -1,    -1,
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
      -1,   172,    -1,    -1,    -1,   176,    -1,   178,   179,    -1,
      -1,    -1,    -1,    -1,    -1,   186,    -1,   188,   189,   190,
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
     139,    -1,   141,   142,   143,    -1,    -1,    -1,    -1,    -1,
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
     299
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
     151,   151,   328,   546,   118,   123,    47,    50,    93,   242,
     255,   257,   268,   269,   270,   272,   274,   578,   579,   580,
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
     386,   546,   546,   119,   120,   546,   268,   269,   270,   274,
     548,   254,   265,   254,   265,    20,   277,    89,   106,   147,
     584,   587,   578,    30,    36,    54,    65,    90,   216,   356,
     514,   282,   283,   218,   290,   298,    87,   357,   290,   546,
     144,   524,   525,   548,   524,   525,   174,   138,   508,   245,
      46,    53,    70,   111,   401,   408,   409,   410,   391,   508,
     509,   379,    87,   174,   188,   123,   344,   546,   151,   123,
      89,   344,   111,   386,   133,   133,   402,   144,   174,   386,
     111,   386,   386,   138,    93,   428,   429,   383,   174,   174,
     144,   524,   524,   174,   386,    27,   487,   121,   187,     8,
       9,    96,   114,   116,   185,   380,   482,   484,   495,   496,
     499,    20,   223,   225,   386,   386,   386,   223,   225,   386,
     386,   386,   386,   386,   386,   111,   386,   386,   351,   368,
     100,   181,   174,   365,   237,   543,   544,   144,   111,   418,
      88,    99,   109,   118,   420,   421,   422,   423,   100,   548,
     100,   400,   147,   147,   511,   147,   135,   166,   184,   510,
     548,   548,   386,   138,   386,   386,   138,   402,   138,   174,
     177,   551,   565,   241,   208,   245,   259,   266,   602,    89,
     247,   248,   600,   241,   555,   602,   438,   572,   556,   138,
     273,   560,   561,   600,   277,   571,    71,   570,   135,   386,
     383,   128,   365,   128,   144,   526,   349,   386,   277,    20,
      89,   106,   147,   591,    20,   584,   357,   510,   218,   218,
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
     174,   385,    20,   127,   191,   593,   594,   595,    20,   592,
     593,   262,   588,   585,   586,   587,   161,   548,   248,   357,
     455,   174,   386,   548,   548,   409,   386,   117,    89,   546,
     386,   174,   548,   176,   111,   176,   174,   487,   548,   185,
     487,   548,   386,   386,   386,   386,   386,   386,   386,   147,
     200,   381,   174,   423,   546,    87,   177,   100,   177,   386,
     438,   438,   189,   383,   174,   591,   591,   595,   100,   177,
      20,   589,   600,   177,   100,   359,   360,   455,   111,   216,
     297,   278,   161,    46,   386,   344,    87,   386,   548,   386,
      86,   173,   488,   487,   548,   187,   487,   111,   466,   509,
     509,    87,   438,   174,    20,   256,   587,   100,    87,   548,
     111,   216,   548,   359,   111,   509,   176,     4,   124,   491,
     492,   494,   496,    19,   125,   489,   490,   493,   496,   187,
     487,   187,   548,   509,   360,   513,   295,   548,   111,   216,
     548,   176,   386,    86,   124,   494,   173,   125,   493,   187,
     100,   177,   423,   386,   295,   548,   111,   386,   111,   381,
     284,   295,   548,   548,   296,   386,   296,   100,   177,   455,
     455,   111,   381,   189,   548,   278,   177,   548,   381,   216,
     111,   548,   296,   455
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
      -1,   269,   277,   591,   593,    -1,   269,   277,   106,   593,
      -1,    47,   269,   277,    -1,    89,    20,    -1,   147,   592,
     177,    -1,    20,    -1,   592,   100,    20,    -1,    -1,   594,
      -1,   595,    -1,   594,   595,    -1,   191,   591,    -1,   127,
     591,    -1,   255,    20,    -1,   274,    -1,    47,   274,    -1,
      89,   208,    -1,    89,   245,    -1,   246,   241,    -1,   258,
     600,   271,    -1,   247,   438,    -1,    89,   120,   438,    -1,
      89,    45,   438,    -1,   248,   438,   189,   438,    -1,   263,
     602,    -1,   243,   602,    -1,   266,    -1,   259,    -1,   276,
     241,   440,    -1
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
    2790,  2792,  2794,  2798,  2803,  2804,  2807,  2808,  2811,  2816,
    2821,  2825,  2828,  2832,  2834,  2838,  2839,  2841,  2843,  2846,
    2849,  2852,  2855,  2857,  2860,  2863,  2866,  2869,  2873,  2876,
    2880,  2884,  2889,  2892,  2895,  2897,  2899
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
    1904,  1915,  1922,  1929,  1941,  1945,  1952,  1957,  1964,  1972,
    1976,  1980,  1988,  1996,  2006,  2020,  2030,  2044,  2053,  2068,
    2074,  2086,  2090,  2101,  2108,  2116,  2131,  2135,  2149,  2153,
    2162,  2166,  2180,  2181,  2182,  2183,  2184,  2187,  2188,  2189,
    2190,  2191,  2193,  2194,  2197,  2198,  2199,  2200,  2201,  2206,
    2221,  2228,  2232,  2239,  2243,  2247,  2254,  2262,  2273,  2283,
    2296,  2305,  2306,  2307,  2311,  2312,  2313,  2314,  2315,  2318,
    2324,  2333,  2337,  2345,  2355,  2361,  2373,  2377,  2385,  2394,
    2404,  2412,  2421,  2430,  2445,  2454,  2464,  2472,  2478,  2487,
    2493,  2505,  2513,  2523,  2531,  2543,  2549,  2560,  2562,  2566,
    2574,  2578,  2583,  2587,  2591,  2595,  2603,  2617,  2625,  2632,
    2638,  2649,  2653,  2662,  2670,  2676,  2686,  2692,  2702,  2706,
    2716,  2722,  2728,  2734,  2743,  2752,  2761,  2774,  2778,  2786,
    2792,  2802,  2810,  2819,  2832,  2839,  2851,  2855,  2868,  2875,
    2888,  2894,  2906,  2912,  2924,  2933,  2937,  2946,  2950,  2958,
    2962,  2972,  2979,  2988,  2998,  2997,  3011,  3020,  3029,  3042,
    3046,  3059,  3062,  3070,  3074,  3083,  3087,  3091,  3100,  3104,
    3110,  3116,  3122,  3133,  3137,  3141,  3149,  3153,  3159,  3169,
    3173,  3183,  3187,  3197,  3201,  3211,  3215,  3225,  3229,  3237,
    3241,  3245,  3249,  3259,  3263,  3267,  3275,  3279,  3283,  3287,
    3291,  3295,  3303,  3307,  3311,  3319,  3323,  3327,  3331,  3341,
    3347,  3357,  3363,  3373,  3377,  3415,  3421,  3427,  3433,  3444,
    3452,  3463,  3469,  3479,  3483,  3491,  3497,  3505,  3511,  3523,
    3529,  3539,  3543,  3547,  3551,  3555,  3561,  3567,  3575,  3579,
    3587,  3591,  3602,  3606,  3610,  3616,  3620,  3634,  3638,  3646,
    3650,  3660,  3664,  3668,  3677,  3681,  3687,  3691,  3699,  3705,
    3715,  3723,  3727,  3731,  3735,  3739,  3743,  3747,  3751,  3755,
    3763,  3767,  3775,  3782,  3789,  3800,  3808,  3812,  3820,  3828,
    3836,  3890,  3894,  3906,  3912,  3922,  3926,  3934,  3938,  3942,
    3950,  3960,  3970,  3980,  3990,  4000,  4015,  4021,  4032,  4038,
    4049,  4060,  4062,  4066,  4071,  4081,  4084,  4091,  4099,  4105,
    4115,  4128,  4131,  4138,  4144,  4150,  4157,  4168,  4172,  4182,
    4186,  4196,  4200,  4204,  4209,  4218,  4224,  4230,  4236,  4246,
    4250,  4262,  4266,  4278,  4290,  4294,  4298,  4302,  4306,  4310,
    4318,  4326,  4332,  4338,  4342,  4359,  4363,  4367,  4371,  4379,
    4387,  4395,  4399,  4403,  4407,  4415,  4421,  4431,  4439,  4443,
    4449,  4484,  4490,  4496,  4506,  4510,  4514,  4518,  4522,  4529,
    4535,  4545,  4553,  4557,  4561,  4565,  4569,  4573,  4577,  4581,
    4585,  4593,  4601,  4605,  4609,  4619,  4627,  4635,  4639,  4643,
    4651,  4655,  4661,  4667,  4671,  4681,  4689,  4693,  4699,  4708,
    4717,  4723,  4729,  4739,  4756,  4763,  4778,  4814,  4818,  4827,
    4836,  4845,  4849,  4858,  4867,  4871,  4880,  4897,  4903,  4909,
    4919,  4923,  4929,  4935,  4939,  4945,  4949,  4955,  4961,  4968,
    4978,  4983,  4991,  4997,  5007,  5029,  5038,  5044,  5057,  5071,
    5078,  5084,  5094,  5099,  5105,  5115,  5128,  5134,  5144,  5154,
    5155,  5173,  5177,  5190,  5196,  5203,  5204,  5205,  5206,  5207,
    5208,  5209,  5210,  5211,  5212,  5213,  5214,  5215,  5216,  5217,
    5218,  5219,  5220,  5221,  5222,  5223,  5224,  5225,  5226,  5227,
    5228,  5229,  5230,  5231,  5232,  5233,  5234,  5235,  5236,  5237,
    5238,  5239,  5240,  5241,  5242,  5243,  5244,  5245,  5246,  5247,
    5248,  5249,  5250,  5251,  5252,  5253,  5254,  5255,  5256,  5257,
    5258,  5259,  5260,  5261,  5262,  5263,  5264,  5265,  5266,  5267,
    5268,  5269,  5270,  5271,  5272,  5273,  5274,  5275,  5276,  5277,
    5278,  5279,  5280,  5281,  5282,  5283,  5284,  5285,  5286,  5287,
    5288,  5289,  5290,  5291,  5292,  5293,  5294,  5295,  5296,  5297,
    5298,  5299,  5300,  5301,  5302,  5303,  5304,  5305,  5306,  5307,
    5308,  5309,  5310,  5311,  5312,  5313,  5314,  5315,  5316,  5317,
    5318,  5319,  5320,  5321,  5322,  5323,  5324,  5325,  5326,  5327,
    5328,  5329,  5330,  5331,  5332,  5333,  5334,  5335,  5336,  5337,
    5338,  5339,  5340,  5341,  5342,  5343,  5344,  5345,  5346,  5347,
    5348,  5349,  5350,  5351,  5352,  5353,  5354,  5355,  5356,  5357,
    5358,  5359,  5360,  5361,  5362,  5363,  5364,  5365,  5366,  5367,
    5368,  5369,  5370,  5371,  5372,  5373,  5374,  5375,  5376,  5377,
    5378,  5379,  5380,  5381,  5382,  5383,  5384,  5385,  5386,  5387,
    5388,  5389,  5390,  5391,  5392,  5393,  5394,  5395,  5396,  5397,
    5398,  5399,  5400,  5401,  5402,  5414,  5423,  5426,  5433,  5438,
    5447,  5451,  5461,  5465,  5475,  5479,  5490,  5494,  5504,  5517,
    5520,  5528,  5531,  5539,  5547,  5555,  5559,  5567,  5570,  5578,
    5590,  5593,  5601,  5613,  5619,  5629,  5632,  5640,  5644,  5648,
    5656,  5659,  5667,  5670,  5678,  5682,  5686,  5690,  5694,  5702,
    5710,  5722,  5734,  5738,  5742,  5750,  5756,  5766,  5770,  5774,
    5778,  5782,  5786,  5790,  5794,  5802,  5806,  5810,  5814,  5822,
    5828,  5838,  5848,  5852,  5860,  5870,  5881,  5888,  5892,  5900,
    5903,  5910,  5915,  5924,  5934,  5937,  5945,  5948,  5956,  5965,
    5972,  5982,  5986,  5993,  5999,  6009,  6012,  6019,  6024,  6036,
    6044,  6056,  6064,  6068,  6076,  6080,  6084,  6092,  6100,  6104,
    6108,  6112,  6120,  6128,  6140,  6144,  6152
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
  const int xquery_parser::yylast_ = 11300;
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
#line 15084 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6158 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"


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

