/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2010 Free Software Foundation, Inc.
   
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

/* Line 310 of lalr1.cc  */
#line 69 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"


#ifdef _WIN32
  // Include the NOMINMAX definition before windwows.h is included,
  // so that min and max macros are not defined, and std::max and std::min
  // uses do not generate errors on Windows.
#define NOMINMAX
#endif

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


namespace zorba
{
namespace parser
{
  extern const char *the_tumbling, *the_sliding, *the_start, *the_end, *the_only_end, *the_ofor, *the_declare, *the_create;
}
}

#define YYDEBUG 1

using namespace std;
using namespace zorba;



/* Line 310 of lalr1.cc  */
#line 82 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 316 of lalr1.cc  */
#line 849 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 316 of lalr1.cc  */
#line 965 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex

/*
 *  Functions to validate lists of properties
 */
// Returns false if validation fails and the parser should call YYERROR, true otherwise
bool validate_collection_properties(parsenode* props, location& loc, parsenode* qname, xquery_driver& driver)
{
  XQUERY_ERROR err = CollectionDecl::validatePropertyList(static_cast<DeclPropertyList*>(props));
  if (err != XQ_NO_ERROR) {
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc), err, static_cast<QName*>(qname)->get_qname(), true));
    return false;
  }
  return true;
}

// Returns false if validation fails and the parser should call YYERROR, true otherwise
bool validate_index_properties(parsenode* props, location& loc, parsenode* qname, xquery_driver& driver)
{
  XQUERY_ERROR err = IndexDecl::validatePropertyList(static_cast<DeclPropertyList*>(props));
  if (err != XQ_NO_ERROR) {
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc), err, static_cast<QName*>(qname)->get_qname(), true));
    return false;
  }
  return true;
}



/* Line 316 of lalr1.cc  */
#line 138 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
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


namespace zorba {

/* Line 379 of lalr1.cc  */
#line 204 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
        case 104: /* "\"'DECIMAL'\"" */

/* Line 479 of lalr1.cc  */
#line 845 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 479 of lalr1.cc  */
#line 311 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 116: /* "\"'DOUBLE'\"" */

/* Line 479 of lalr1.cc  */
#line 844 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 479 of lalr1.cc  */
#line 320 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 141: /* "\"'INTEGER'\"" */

/* Line 479 of lalr1.cc  */
#line 843 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 479 of lalr1.cc  */
#line 329 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "VersionDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 338 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "MainModule" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 347 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "LibraryModule" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 356 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "ModuleDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 365 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "Prolog" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 374 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "SIND_DeclList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 383 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "VFO_DeclList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 392 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "SIND_Decl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 401 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "VFO_Decl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 410 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "DecimalFormatDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 419 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "DecimalFormatParamList" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 479 of lalr1.cc  */
#line 428 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "DecimalFormatParam" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 479 of lalr1.cc  */
#line 437 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "Setter" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 446 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "Import" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 455 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "NamespaceDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 464 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "BoundarySpaceDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 473 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "DefaultNamespaceDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 482 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "OptionDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 491 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "FTOptionDecl" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 500 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "OrderingModeDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 509 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "EmptyOrderDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 518 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "CopyNamespacesDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 527 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "DefaultCollationDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 536 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "BaseURIDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 545 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "SchemaImport" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 554 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "URILiteralList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 563 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "SchemaPrefix" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 572 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "ModuleImport" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 581 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "CtxItemDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 590 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "CtxItemDecl2" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 599 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "CtxItemDecl3" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 608 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "CtxItemDecl4" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 617 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "VarNameAndType" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 479 of lalr1.cc  */
#line 626 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "VarDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 635 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "DeclPropertyList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 644 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "DeclProperty" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 653 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "CollectionDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 662 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "NodeModifier" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 671 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "IndexDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 680 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "IndexKeyList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 689 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "IndexKeySpec" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 698 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "IntegrityConstraintDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 707 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "ConstructionDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 716 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "FunctionSig" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 479 of lalr1.cc  */
#line 725 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "BlockExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 734 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "Block" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 743 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "BlockDecls" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 752 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "BlockVarDeclList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 761 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "BlockVarDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 770 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "AssignExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 779 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "ExitExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 788 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "WhileExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 797 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "FlowCtlStatement" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 806 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FunctionDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 815 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDecl2" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 824 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDecl3" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 833 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDecl4" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 842 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FunctionDeclUpdating" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 851 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "ParamList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 860 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "Param" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "EnclosedExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 878 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "BracedExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 887 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "QueryBody" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 896 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "Expr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "ApplyExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 914 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "ConcatExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 923 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "ExprSingle" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 932 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "FLWORExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 941 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "ReturnExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 950 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "FLWORWinCond" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 959 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "WindowClause" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 968 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "CountClause" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 977 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ForLetWinClause" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 986 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "FLWORClauseList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 995 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "ForClause" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1004 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "VarInDeclList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1013 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "VarInDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1022 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "PositionalVar" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1031 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "FTScoreVar" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1040 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "LetClause" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1049 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "VarGetsDeclList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1058 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "EvalVarDeclList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1067 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "VarGetsDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1076 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "WindowVarDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1085 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "WindowVars" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1094 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "WindowVars3" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1103 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "WindowVars2" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1112 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "EvalVarDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1121 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "WhereClause" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1130 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "GroupByClause" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1139 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "GroupSpecList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1148 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "GroupSpec" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1157 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "GroupCollationSpec" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1166 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "OrderByClause" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1175 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "OrderSpecList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1184 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "OrderSpec" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1193 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "OrderModifier" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1202 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "OrderDirSpec" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1211 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "OrderEmptySpec" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1220 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "OrderCollationSpec" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1229 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "QuantifiedExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1238 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "QVarInDeclList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1247 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "QVarInDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1256 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "SwitchExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1265 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "SwitchCaseClauseList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1274 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "SwitchCaseOperandList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1283 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "TypeswitchExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1292 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "CaseClauseList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1301 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "CaseClause" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1310 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "IfExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1319 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "OrExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1328 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "AndExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1337 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "ComparisonExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1346 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "FTContainsExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1355 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "opt_FTIgnoreOption" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1364 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "RangeExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1373 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "AdditiveExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1382 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "MultiplicativeExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1391 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "UnionExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1400 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "IntersectExceptExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1409 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "InstanceofExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1418 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "TreatExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1427 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "CastableExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1436 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "CastExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1445 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "UnaryExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1454 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "SignList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1463 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "ValueExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1472 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "ValueComp" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1481 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "NodeComp" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1490 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "ValidateExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1499 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "ExtensionExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1508 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "Pragma_list" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1517 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "Pragma" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1526 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "PathExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1535 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "RelativePathExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1544 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "StepExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1553 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "AxisStep" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1562 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "ForwardStep" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1571 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "ForwardAxis" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1580 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "AbbrevForwardStep" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1589 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "ReverseStep" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1598 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "ReverseAxis" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1607 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "NodeTest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1616 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "NameTest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1625 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "Wildcard" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1634 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "FilterExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1643 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "PredicateList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1652 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "Predicate" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1661 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "PrimaryExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1670 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "Literal" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1679 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "NumericLiteral" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1688 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "VarRef" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1697 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "ParenthesizedExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1706 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "ContextItemExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1715 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "OrderedExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1724 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "UnorderedExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1733 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "FunctionCall" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1742 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "ArgList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1751 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "Constructor" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1760 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "DirectConstructor" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1769 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "DirElemConstructor" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1778 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "DirElemContentList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1787 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "DirAttributeList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1796 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "DirAttr" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1805 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "DirAttributeValue" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1814 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "opt_QuoteAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1823 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "QuoteAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1832 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "opt_AposAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1841 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "AposAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1850 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "QuoteAttrValueContent" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1859 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "AposAttrValueContent" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1868 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "DirElemContent" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1877 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "CommonContent" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1886 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "DirCommentConstructor" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1895 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "DirPIConstructor" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1904 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "CDataSection" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1913 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "ComputedConstructor" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1922 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "CompDocConstructor" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1931 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "CompElemConstructor" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1940 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "CompAttrConstructor" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1949 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "CompTextConstructor" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1958 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "CompCommentConstructor" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1967 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "CompPIConstructor" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1976 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "SingleType" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1985 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "TypeDeclaration" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1994 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "SequenceType" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2003 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "OccurrenceIndicator" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2012 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "ItemType" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2021 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "TypeList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2030 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "AtomicType" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2039 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "KindTest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2048 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "AnyKindTest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2057 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "DocumentTest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2066 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "TextTest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2075 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "CommentTest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2084 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "PITest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2093 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "AttributeTest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2102 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "SchemaAttributeTest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2111 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "ElementTest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2120 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "SchemaElementTest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2129 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "TypeName" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2138 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "TypeName_WITH_HOOK" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2147 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "StringLiteral" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2156 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "AnyFunctionTest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2165 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "TypedFunctionTest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2174 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "InsertExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2183 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "DeleteExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2192 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "ReplaceExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2201 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "RenameExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2210 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "TransformExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2219 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "VarNameList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2228 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "VarNameDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2237 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "TryExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2246 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "CatchListExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2255 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "CatchExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2264 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "NameTestList" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 479 of lalr1.cc  */
#line 2273 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "QNAME" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2282 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "EvalExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2291 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "FTSelection" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2300 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "FTOr" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2309 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "FTAnd" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2318 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "FTMildNot" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2327 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "FTUnaryNot" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2336 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "FTPrimaryWithOptions" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2345 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "opt_FTMatchOptions" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2354 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "FTWeight" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2363 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "FTPrimary" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2372 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "opt_FTTimes" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2381 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "FTExtensionSelection" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2390 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "FTWords" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2399 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "FTWordsValue" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2408 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "FTAnyallOption" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2417 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTPosFilter" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2426 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTOrder" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2435 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTWindow" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2444 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTDistance" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2453 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTUnit" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2462 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTMatchOptions" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2471 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTMatchOption" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2480 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTCaseOption" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2489 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTDiacriticsOption" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2498 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTExtensionOption" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2507 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTStemOption" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2516 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTThesaurusOption" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2525 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTThesaurusID" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2534 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTStopWordOption" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2543 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTStopWords" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2552 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTStopWordsInclExcl" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2561 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTLanguageOption" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2570 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTWildCardOption" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2579 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTContent" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2588 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTTimes" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2597 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTRange" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2606 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTScope" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2615 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTBigUnit" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2624 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTIgnoreOption" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2633 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
    
/* Line 552 of lalr1.cc  */
#line 127 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}

/* Line 552 of lalr1.cc  */
#line 2718 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"

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

/* Line 677 of lalr1.cc  */
#line 1009 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 4:

/* Line 677 of lalr1.cc  */
#line 1018 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 5:

/* Line 677 of lalr1.cc  */
#line 1023 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            MainModule *mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
            mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 6:

/* Line 677 of lalr1.cc  */
#line 1030 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 7:

/* Line 677 of lalr1.cc  */
#line 1035 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            LibraryModule *lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
            lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 8:

/* Line 677 of lalr1.cc  */
#line 1046 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            std::string encoding = "utf-8";
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), encoding );
        }
    break;

  case 9:

/* Line 677 of lalr1.cc  */
#line 1051 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
        }
    break;

  case 10:

/* Line 677 of lalr1.cc  */
#line 1059 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new MainModule(
                LOC((yyloc)),
                static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
                static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node))
            );
        }
    break;

  case 11:

/* Line 677 of lalr1.cc  */
#line 1067 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
        }
    break;

  case 12:

/* Line 677 of lalr1.cc  */
#line 1075 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LibraryModule(
                LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 13:

/* Line 677 of lalr1.cc  */
#line 1081 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LibraryModule(
                LOC((yyloc)),
                static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
                static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 14:

/* Line 677 of lalr1.cc  */
#line 1093 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
            dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
        }
    break;

  case 15:

/* Line 677 of lalr1.cc  */
#line 1102 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog( LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)), NULL );
        }
    break;

  case 16:

/* Line 677 of lalr1.cc  */
#line 1106 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog( LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)) );
        }
    break;

  case 17:

/* Line 677 of lalr1.cc  */
#line 1110 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog(
                LOC((yyloc)),
                static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
                static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 18:

/* Line 677 of lalr1.cc  */
#line 1122 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
            sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = sdl;
        }
    break;

  case 19:

/* Line 677 of lalr1.cc  */
#line 1128 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( SIND_DeclList *sdl = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                sdl->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 20:

/* Line 677 of lalr1.cc  */
#line 1138 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
            vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = vdl;
        }
    break;

  case 21:

/* Line 677 of lalr1.cc  */
#line 1144 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( VFO_DeclList *vdl = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vdl->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 35:

/* Line 677 of lalr1.cc  */
#line 1176 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
         (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
         delete (yysemantic_stack_[(4) - (4)].vstrpair);
       }
    break;

  case 36:

/* Line 677 of lalr1.cc  */
#line 1181 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
         (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
         delete (yysemantic_stack_[(4) - (4)].vstrpair);
       }
    break;

  case 37:

/* Line 677 of lalr1.cc  */
#line 1190 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.vstrpair) = new vector<string_pair_t>();
          (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
          delete (yysemantic_stack_[(1) - (1)].strpair);
        }
    break;

  case 38:

/* Line 677 of lalr1.cc  */
#line 1196 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
          delete (yysemantic_stack_[(2) - (2)].strpair);
          (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
        }
    break;

  case 39:

/* Line 677 of lalr1.cc  */
#line 1205 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
            (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval() );
            delete sl;
        }
    break;

  case 40:

/* Line 677 of lalr1.cc  */
#line 1213 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 41:

/* Line 677 of lalr1.cc  */
#line 1214 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 42:

/* Line 677 of lalr1.cc  */
#line 1215 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 43:

/* Line 677 of lalr1.cc  */
#line 1216 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 44:

/* Line 677 of lalr1.cc  */
#line 1217 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 45:

/* Line 677 of lalr1.cc  */
#line 1218 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 46:

/* Line 677 of lalr1.cc  */
#line 1219 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 47:

/* Line 677 of lalr1.cc  */
#line 1220 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 48:

/* Line 677 of lalr1.cc  */
#line 1221 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 49:

/* Line 677 of lalr1.cc  */
#line 1222 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 60:

/* Line 677 of lalr1.cc  */
#line 1253 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
        }
    break;

  case 61:

/* Line 677 of lalr1.cc  */
#line 1262 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::preserve_space
            );
        }
    break;

  case 62:

/* Line 677 of lalr1.cc  */
#line 1268 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::strip_space
            );
        }
    break;

  case 63:

/* Line 677 of lalr1.cc  */
#line 1278 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_element_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 64:

/* Line 677 of lalr1.cc  */
#line 1284 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_function_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 65:

/* Line 677 of lalr1.cc  */
#line 1294 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OptionDecl(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval))
            );
        }
    break;

  case 66:

/* Line 677 of lalr1.cc  */
#line 1304 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 67:

/* Line 677 of lalr1.cc  */
#line 1312 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::ordered
            );
        }
    break;

  case 68:

/* Line 677 of lalr1.cc  */
#line 1318 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::unordered
            );
        }
    break;

  case 69:

/* Line 677 of lalr1.cc  */
#line 1329 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_greatest);
        }
    break;

  case 70:

/* Line 677 of lalr1.cc  */
#line 1334 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_least);
        }
    break;

  case 71:

/* Line 677 of lalr1.cc  */
#line 1344 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 72:

/* Line 677 of lalr1.cc  */
#line 1350 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 73:

/* Line 677 of lalr1.cc  */
#line 1356 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 74:

/* Line 677 of lalr1.cc  */
#line 1362 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 75:

/* Line 677 of lalr1.cc  */
#line 1379 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
        }
    break;

  case 76:

/* Line 677 of lalr1.cc  */
#line 1387 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 77:

/* Line 677 of lalr1.cc  */
#line 1395 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
        }
    break;

  case 78:

/* Line 677 of lalr1.cc  */
#line 1399 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 677 of lalr1.cc  */
#line 1408 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 677 of lalr1.cc  */
#line 1417 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 677 of lalr1.cc  */
#line 1430 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            URILiteralList *ull = new URILiteralList( LOC((yyloc)));
            ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.node) = ull;
        }
    break;

  case 82:

/* Line 677 of lalr1.cc  */
#line 1436 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
                ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 83:

/* Line 677 of lalr1.cc  */
#line 1447 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 84:

/* Line 677 of lalr1.cc  */
#line 1451 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
        }
    break;

  case 85:

/* Line 677 of lalr1.cc  */
#line 1459 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 86:

/* Line 677 of lalr1.cc  */
#line 1464 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 87:

/* Line 677 of lalr1.cc  */
#line 1469 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 88:

/* Line 677 of lalr1.cc  */
#line 1476 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 89:

/* Line 677 of lalr1.cc  */
#line 1489 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
        }
    break;

  case 90:

/* Line 677 of lalr1.cc  */
#line 1496 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
            d->type = (yysemantic_stack_[(3) - (2)].node);
            (yyval.node) = d;
        }
    break;

  case 91:

/* Line 677 of lalr1.cc  */
#line 1502 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 92:

/* Line 677 of lalr1.cc  */
#line 1509 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
            d->ext = false;
            (yyval.node) = d;
        }
    break;

  case 93:

/* Line 677 of lalr1.cc  */
#line 1515 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), NULL );
        }
    break;

  case 94:

/* Line 677 of lalr1.cc  */
#line 1519 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 95:

/* Line 677 of lalr1.cc  */
#line 1526 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 96:

/* Line 677 of lalr1.cc  */
#line 1537 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 97:

/* Line 677 of lalr1.cc  */
#line 1541 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 98:

/* Line 677 of lalr1.cc  */
#line 1549 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(5) - (5)].expr));
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 99:

/* Line 677 of lalr1.cc  */
#line 1555 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 100:

/* Line 677 of lalr1.cc  */
#line 1561 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 101:

/* Line 677 of lalr1.cc  */
#line 1570 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
            dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = dpl;
        }
    break;

  case 102:

/* Line 677 of lalr1.cc  */
#line 1576 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
        DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
        dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
        (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 103:

/* Line 677 of lalr1.cc  */
#line 1585 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 104:

/* Line 677 of lalr1.cc  */
#line 1589 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 105:

/* Line 677 of lalr1.cc  */
#line 1595 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 106:

/* Line 677 of lalr1.cc  */
#line 1599 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 107:

/* Line 677 of lalr1.cc  */
#line 1603 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 108:

/* Line 677 of lalr1.cc  */
#line 1607 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 109:

/* Line 677 of lalr1.cc  */
#line 1613 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 110:

/* Line 677 of lalr1.cc  */
#line 1619 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 111:

/* Line 677 of lalr1.cc  */
#line 1625 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_equality
            );
        }
    break;

  case 112:

/* Line 677 of lalr1.cc  */
#line 1631 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_range
            );
        }
    break;

  case 113:

/* Line 677 of lalr1.cc  */
#line 1637 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 114:

/* Line 677 of lalr1.cc  */
#line 1641 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 115:

/* Line 677 of lalr1.cc  */
#line 1647 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 116:

/* Line 677 of lalr1.cc  */
#line 1653 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 117:

/* Line 677 of lalr1.cc  */
#line 1660 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL,
                              NULL);
    }
    break;

  case 118:

/* Line 677 of lalr1.cc  */
#line 1668 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 119:

/* Line 677 of lalr1.cc  */
#line 1676 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              NULL,
                              NULL,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 120:

/* Line 677 of lalr1.cc  */
#line 1684 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(6) - (6)].node)),
                              static_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)));
    }
    break;

  case 121:

/* Line 677 of lalr1.cc  */
#line 1692 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      if (!validate_collection_properties((yysemantic_stack_[(4) - (2)].node), (yyloc), (yysemantic_stack_[(4) - (4)].expr), driver)) {
        delete (yysemantic_stack_[(4) - (2)].node); delete (yysemantic_stack_[(4) - (4)].expr); // these need to be deleted explicitly, as bison does not free them
        YYERROR;
      }

      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(4) - (2)].node)), 0, 0);
      delete (yysemantic_stack_[(4) - (2)].node);
    }
    break;

  case 122:

/* Line 677 of lalr1.cc  */
#line 1704 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      if (!validate_collection_properties((yysemantic_stack_[(5) - (2)].node), (yyloc), (yysemantic_stack_[(5) - (4)].expr), driver )) {
        delete (yysemantic_stack_[(5) - (2)].node); delete (yysemantic_stack_[(5) - (4)].expr);  delete (yysemantic_stack_[(5) - (5)].node); // these need to be deleted explicitly, as bison does not free them
        YYERROR;
      }

      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(5) - (2)].node)),
                               static_cast<NodeModifier*>((yysemantic_stack_[(5) - (5)].node)),
                               NULL);
      delete (yysemantic_stack_[(5) - (2)].node);
    }
    break;

  case 123:

/* Line 677 of lalr1.cc  */
#line 1718 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      if (!validate_collection_properties((yysemantic_stack_[(6) - (2)].node), (yyloc), (yysemantic_stack_[(6) - (4)].expr), driver)) {
        delete (yysemantic_stack_[(6) - (2)].node); delete (yysemantic_stack_[(6) - (4)].expr); delete (yysemantic_stack_[(6) - (6)].node); // these need to be deleted explicitly, as bison does not free them
        YYERROR;
      }

      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(6) - (2)].node)),
                               NULL,
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
      delete (yysemantic_stack_[(6) - (2)].node);
    }
    break;

  case 124:

/* Line 677 of lalr1.cc  */
#line 1732 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      if (!validate_collection_properties((yysemantic_stack_[(7) - (2)].node), (yyloc), (yysemantic_stack_[(7) - (4)].expr), driver)) {
        delete (yysemantic_stack_[(7) - (2)].node); delete (yysemantic_stack_[(7) - (4)].expr); delete (yysemantic_stack_[(7) - (6)].node); delete (yysemantic_stack_[(7) - (7)].node); // these need to be deleted explicitly, as bison does not free them
        YYERROR;
      }

      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(7) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(7) - (2)].node)),
                               static_cast<NodeModifier*>((yysemantic_stack_[(7) - (7)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)));
      delete (yysemantic_stack_[(7) - (2)].node);
    }
    break;

  case 125:

/* Line 677 of lalr1.cc  */
#line 1749 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 126:

/* Line 677 of lalr1.cc  */
#line 1753 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 127:

/* Line 677 of lalr1.cc  */
#line 1760 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier( LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 128:

/* Line 677 of lalr1.cc  */
#line 1764 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier( LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 129:

/* Line 677 of lalr1.cc  */
#line 1771 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl( LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                         (yysemantic_stack_[(8) - (6)].expr),
                         dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                         NULL);
    }
    break;

  case 130:

/* Line 677 of lalr1.cc  */
#line 1779 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      if (!validate_index_properties((yysemantic_stack_[(9) - (2)].node), (yyloc), (yysemantic_stack_[(9) - (4)].expr), driver)) {
        delete (yysemantic_stack_[(9) - (2)].node); delete (yysemantic_stack_[(9) - (4)].expr); delete (yysemantic_stack_[(9) - (7)].expr); delete (yysemantic_stack_[(9) - (9)].node); // these need to be deleted explicitly, as bison does not free them
        YYERROR;
      }

      (yyval.node) = new IndexDecl( LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                         (yysemantic_stack_[(9) - (7)].expr),
                         dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                         dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(9) - (2)].node)));
      delete (yysemantic_stack_[(9) - (2)].node);
    }
    break;

  case 131:

/* Line 677 of lalr1.cc  */
#line 1796 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList( LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 132:

/* Line 677 of lalr1.cc  */
#line 1802 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 133:

/* Line 677 of lalr1.cc  */
#line 1810 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec( LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<AtomicType*>((yysemantic_stack_[(3) - (3)].node)),
                            NULL);
    }
    break;

  case 134:

/* Line 677 of lalr1.cc  */
#line 1817 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec( LOC((yyloc)),
                            (yysemantic_stack_[(4) - (1)].expr),
                            dynamic_cast<AtomicType*>((yysemantic_stack_[(4) - (3)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 135:

/* Line 677 of lalr1.cc  */
#line 1828 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck( LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 136:

/* Line 677 of lalr1.cc  */
#line 1838 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck( LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 137:

/* Line 677 of lalr1.cc  */
#line 1848 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode( LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 138:

/* Line 677 of lalr1.cc  */
#line 1859 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 139:

/* Line 677 of lalr1.cc  */
#line 1874 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_preserve
            );
        }
    break;

  case 140:

/* Line 677 of lalr1.cc  */
#line 1880 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_strip
            );
        }
    break;

  case 141:

/* Line 677 of lalr1.cc  */
#line 1891 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL );
        }
    break;

  case 142:

/* Line 677 of lalr1.cc  */
#line 1895 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 143:

/* Line 677 of lalr1.cc  */
#line 1899 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)) );
        }
    break;

  case 144:

/* Line 677 of lalr1.cc  */
#line 1903 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig(
                dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 145:

/* Line 677 of lalr1.cc  */
#line 1912 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 146:

/* Line 677 of lalr1.cc  */
#line 1919 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 147:

/* Line 677 of lalr1.cc  */
#line 1938 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            std::auto_ptr<VFO_DeclList> vfo2( dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)) );
            if ( !(yysemantic_stack_[(3) - (1)].node) )
                vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back( *vfo2.get() );
            (yyval.node) = vfo;
        }
    break;

  case 148:

/* Line 677 of lalr1.cc  */
#line 1947 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 149:

/* Line 677 of lalr1.cc  */
#line 1954 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            vfo->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = vfo;
        }
    break;

  case 150:

/* Line 677 of lalr1.cc  */
#line 1960 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back((yysemantic_stack_[(2) - (2)].node));
            (yyval.node) = vfo;
        }
    break;

  case 151:

/* Line 677 of lalr1.cc  */
#line 1970 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(1) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 152:

/* Line 677 of lalr1.cc  */
#line 1977 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(3) - (3)].expr));
      vd->set_global(false);
      (yyval.node) = vd;
        }
    break;

  case 153:

/* Line 677 of lalr1.cc  */
#line 1988 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 154:

/* Line 677 of lalr1.cc  */
#line 1995 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExitExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 155:

/* Line 677 of lalr1.cc  */
#line 2002 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody *>((yysemantic_stack_[(5) - (5)].expr));
            if ( !bb ) {
                bb = new BlockBody( (yysemantic_stack_[(5) - (5)].expr)->get_location() );
                bb->add((yysemantic_stack_[(5) - (5)].expr));
            }
            (yyval.expr) = new WhileExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), bb );
        }
    break;

  case 156:

/* Line 677 of lalr1.cc  */
#line 2014 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::BREAK );
        }
    break;

  case 157:

/* Line 677 of lalr1.cc  */
#line 2018 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
        }
    break;

  case 158:

/* Line 677 of lalr1.cc  */
#line 2025 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            dynamic_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 159:

/* Line 677 of lalr1.cc  */
#line 2030 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FunctionDecl *fd = dynamic_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));
            fd->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            fd->deterministic = false;
            (yyval.node) = fd;
        }
    break;

  case 160:

/* Line 677 of lalr1.cc  */
#line 2037 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            dynamic_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node))->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
        }
    break;

  case 161:

/* Line 677 of lalr1.cc  */
#line 2045 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 162:

/* Line 677 of lalr1.cc  */
#line 2049 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 163:

/* Line 677 of lalr1.cc  */
#line 2053 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *fd = dynamic_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node));
      fd->type = (fd->type == ParseConstants::fn_extern ?
                  ParseConstants::fn_extern_update :
                  ParseConstants::fn_update);
      (yyval.node) = fd;
    }
    break;

  case 164:

/* Line 677 of lalr1.cc  */
#line 2061 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 165:

/* Line 677 of lalr1.cc  */
#line 2069 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 166:

/* Line 677 of lalr1.cc  */
#line 2079 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 167:

/* Line 677 of lalr1.cc  */
#line 2093 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 168:

/* Line 677 of lalr1.cc  */
#line 2103 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 169:

/* Line 677 of lalr1.cc  */
#line 2117 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                            &* (yysemantic_stack_[(6) - (3)].fnsig)->param, &* (yysemantic_stack_[(6) - (3)].fnsig)->ret,
                            (yysemantic_stack_[(6) - (5)].expr),
                            ParseConstants::fn_read);
      delete (yysemantic_stack_[(6) - (3)].fnsig);
    }
    break;

  case 170:

/* Line 677 of lalr1.cc  */
#line 2126 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 171:

/* Line 677 of lalr1.cc  */
#line 2141 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            ParamList *pl = new ParamList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 172:

/* Line 677 of lalr1.cc  */
#line 2147 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
                pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 173:

/* Line 677 of lalr1.cc  */
#line 2159 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 174:

/* Line 677 of lalr1.cc  */
#line 2163 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 175:

/* Line 677 of lalr1.cc  */
#line 2174 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EnclosedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 176:

/* Line 677 of lalr1.cc  */
#line 2181 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 177:

/* Line 677 of lalr1.cc  */
#line 2189 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QueryBody( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 178:

/* Line 677 of lalr1.cc  */
#line 2204 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 179:

/* Line 677 of lalr1.cc  */
#line 2208 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            std::auto_ptr<BlockBody> blk( dynamic_cast<BlockBody*>((yysemantic_stack_[(2) - (2)].expr)) );
            BlockBody *blk2 = new BlockBody( LOC((yyloc)) );
            blk2->add( (yysemantic_stack_[(2) - (1)].expr) );

            for ( int i = 0; i < blk->size(); ++i )
                blk2->add( (*blk)[i] );

            (yyval.expr) = blk2;
        }
    break;

  case 180:

/* Line 677 of lalr1.cc  */
#line 2222 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new BlockBody( LOC((yyloc)) );
        }
    break;

  case 181:

/* Line 677 of lalr1.cc  */
#line 2226 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (1)].expr));
            bb->add( (yysemantic_stack_[(3) - (2)].expr) );
            (yyval.expr) = bb;
        }
    break;

  case 182:

/* Line 677 of lalr1.cc  */
#line 2235 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 183:

/* Line 677 of lalr1.cc  */
#line 2239 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 202:

/* Line 677 of lalr1.cc  */
#line 2280 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 203:

/* Line 677 of lalr1.cc  */
#line 2295 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 204:

/* Line 677 of lalr1.cc  */
#line 2302 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_sliding;
        }
    break;

  case 205:

/* Line 677 of lalr1.cc  */
#line 2306 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_tumbling;
        }
    break;

  case 206:

/* Line 677 of lalr1.cc  */
#line 2313 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_start;
        }
    break;

  case 207:

/* Line 677 of lalr1.cc  */
#line 2317 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_end;
        }
    break;

  case 208:

/* Line 677 of lalr1.cc  */
#line 2321 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_only_end;
        }
    break;

  case 209:

/* Line 677 of lalr1.cc  */
#line 2328 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)),
                dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr),
                (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 210:

/* Line 677 of lalr1.cc  */
#line 2336 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr),
                (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 211:

/* Line 677 of lalr1.cc  */
#line 2347 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 212:

/* Line 677 of lalr1.cc  */
#line 2357 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 213:

/* Line 677 of lalr1.cc  */
#line 2370 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 222:

/* Line 677 of lalr1.cc  */
#line 2392 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 223:

/* Line 677 of lalr1.cc  */
#line 2398 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 224:

/* Line 677 of lalr1.cc  */
#line 2407 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = NULL;
        }
    break;

  case 225:

/* Line 677 of lalr1.cc  */
#line 2411 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_ofor;
        }
    break;

  case 226:

/* Line 677 of lalr1.cc  */
#line 2419 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForClause(
                LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL
            );
        }
    break;

  case 227:

/* Line 677 of lalr1.cc  */
#line 2429 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
            vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vdl;
        }
    break;

  case 228:

/* Line 677 of lalr1.cc  */
#line 2435 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 229:

/* Line 677 of lalr1.cc  */
#line 2447 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 230:

/* Line 677 of lalr1.cc  */
#line 2451 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,NULL,
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 231:

/* Line 677 of lalr1.cc  */
#line 2459 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 232:

/* Line 677 of lalr1.cc  */
#line 2468 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
                         NULL,
                         (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 233:

/* Line 677 of lalr1.cc  */
#line 2478 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 234:

/* Line 677 of lalr1.cc  */
#line 2486 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 235:

/* Line 677 of lalr1.cc  */
#line 2495 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 236:

/* Line 677 of lalr1.cc  */
#line 2504 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                         (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 237:

/* Line 677 of lalr1.cc  */
#line 2519 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 238:

/* Line 677 of lalr1.cc  */
#line 2528 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 239:

/* Line 677 of lalr1.cc  */
#line 2538 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 240:

/* Line 677 of lalr1.cc  */
#line 2546 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 241:

/* Line 677 of lalr1.cc  */
#line 2552 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 242:

/* Line 677 of lalr1.cc  */
#line 2561 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 243:

/* Line 677 of lalr1.cc  */
#line 2567 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 244:

/* Line 677 of lalr1.cc  */
#line 2579 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 245:

/* Line 677 of lalr1.cc  */
#line 2587 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 246:

/* Line 677 of lalr1.cc  */
#line 2597 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                           (yysemantic_stack_[(4) - (4)].expr));
     }
    break;

  case 247:

/* Line 677 of lalr1.cc  */
#line 2605 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                           (yysemantic_stack_[(5) - (5)].expr));
     }
    break;

  case 248:

/* Line 677 of lalr1.cc  */
#line 2617 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 249:

/* Line 677 of lalr1.cc  */
#line 2623 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 251:

/* Line 677 of lalr1.cc  */
#line 2636 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 252:

/* Line 677 of lalr1.cc  */
#line 2640 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 253:

/* Line 677 of lalr1.cc  */
#line 2648 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 254:

/* Line 677 of lalr1.cc  */
#line 2652 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 256:

/* Line 677 of lalr1.cc  */
#line 2661 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 257:

/* Line 677 of lalr1.cc  */
#line 2665 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 258:

/* Line 677 of lalr1.cc  */
#line 2669 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 259:

/* Line 677 of lalr1.cc  */
#line 2677 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)),
                           NULL, NULL,
                           new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))),
                           VarGetsDecl::eval_var);
    }
    break;

  case 260:

/* Line 677 of lalr1.cc  */
#line 2691 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 261:

/* Line 677 of lalr1.cc  */
#line 2699 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 262:

/* Line 677 of lalr1.cc  */
#line 2706 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 263:

/* Line 677 of lalr1.cc  */
#line 2712 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 264:

/* Line 677 of lalr1.cc  */
#line 2723 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 265:

/* Line 677 of lalr1.cc  */
#line 2727 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 266:

/* Line 677 of lalr1.cc  */
#line 2736 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 267:

/* Line 677 of lalr1.cc  */
#line 2744 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 268:

/* Line 677 of lalr1.cc  */
#line 2750 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 269:

/* Line 677 of lalr1.cc  */
#line 2760 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 270:

/* Line 677 of lalr1.cc  */
#line 2766 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 271:

/* Line 677 of lalr1.cc  */
#line 2776 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 272:

/* Line 677 of lalr1.cc  */
#line 2780 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 273:

/* Line 677 of lalr1.cc  */
#line 2790 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 274:

/* Line 677 of lalr1.cc  */
#line 2796 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 275:

/* Line 677 of lalr1.cc  */
#line 2802 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 276:

/* Line 677 of lalr1.cc  */
#line 2808 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 277:

/* Line 677 of lalr1.cc  */
#line 2817 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 278:

/* Line 677 of lalr1.cc  */
#line 2826 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 279:

/* Line 677 of lalr1.cc  */
#line 2835 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 280:

/* Line 677 of lalr1.cc  */
#line 2848 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 281:

/* Line 677 of lalr1.cc  */
#line 2852 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 282:

/* Line 677 of lalr1.cc  */
#line 2860 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 283:

/* Line 677 of lalr1.cc  */
#line 2866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 284:

/* Line 677 of lalr1.cc  */
#line 2876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 285:

/* Line 677 of lalr1.cc  */
#line 2884 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 286:

/* Line 677 of lalr1.cc  */
#line 2893 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 287:

/* Line 677 of lalr1.cc  */
#line 2906 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 288:

/* Line 677 of lalr1.cc  */
#line 2913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 289:

/* Line 677 of lalr1.cc  */
#line 2925 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 290:

/* Line 677 of lalr1.cc  */
#line 2929 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 291:

/* Line 677 of lalr1.cc  */
#line 2941 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 292:

/* Line 677 of lalr1.cc  */
#line 2948 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 293:

/* Line 677 of lalr1.cc  */
#line 2954 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 294:

/* Line 677 of lalr1.cc  */
#line 2963 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 295:

/* Line 677 of lalr1.cc  */
#line 2970 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 296:

/* Line 677 of lalr1.cc  */
#line 2976 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 297:

/* Line 677 of lalr1.cc  */
#line 2988 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 298:

/* Line 677 of lalr1.cc  */
#line 2995 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 299:

/* Line 677 of lalr1.cc  */
#line 3008 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 300:

/* Line 677 of lalr1.cc  */
#line 3014 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 301:

/* Line 677 of lalr1.cc  */
#line 3026 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 302:

/* Line 677 of lalr1.cc  */
#line 3032 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 303:

/* Line 677 of lalr1.cc  */
#line 3044 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 304:

/* Line 677 of lalr1.cc  */
#line 3053 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 305:

/* Line 677 of lalr1.cc  */
#line 3057 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 306:

/* Line 677 of lalr1.cc  */
#line 3066 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 307:

/* Line 677 of lalr1.cc  */
#line 3070 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 308:

/* Line 677 of lalr1.cc  */
#line 3078 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 309:

/* Line 677 of lalr1.cc  */
#line 3082 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 310:

/* Line 677 of lalr1.cc  */
#line 3092 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 311:

/* Line 677 of lalr1.cc  */
#line 3099 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 312:

/* Line 677 of lalr1.cc  */
#line 3108 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 313:

/* Line 677 of lalr1.cc  */
#line 3117 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 314:

/* Line 677 of lalr1.cc  */
#line 3122 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 315:

/* Line 677 of lalr1.cc  */
#line 3131 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 316:

/* Line 677 of lalr1.cc  */
#line 3140 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 317:

/* Line 677 of lalr1.cc  */
#line 3149 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 318:

/* Line 677 of lalr1.cc  */
#line 3162 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 319:

/* Line 677 of lalr1.cc  */
#line 3166 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 320:

/* Line 677 of lalr1.cc  */
#line 3178 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 321:

/* Line 677 of lalr1.cc  */
#line 3182 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 322:

/* Line 677 of lalr1.cc  */
#line 3189 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 323:

/* Line 677 of lalr1.cc  */
#line 3193 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 324:

/* Line 677 of lalr1.cc  */
#line 3202 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 325:

/* Line 677 of lalr1.cc  */
#line 3206 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 326:

/* Line 677 of lalr1.cc  */
#line 3210 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 327:

/* Line 677 of lalr1.cc  */
#line 3219 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 328:

/* Line 677 of lalr1.cc  */
#line 3223 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 329:

/* Line 677 of lalr1.cc  */
#line 3229 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 330:

/* Line 677 of lalr1.cc  */
#line 3235 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 331:

/* Line 677 of lalr1.cc  */
#line 3241 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 332:

/* Line 677 of lalr1.cc  */
#line 3252 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 333:

/* Line 677 of lalr1.cc  */
#line 3256 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 334:

/* Line 677 of lalr1.cc  */
#line 3260 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 335:

/* Line 677 of lalr1.cc  */
#line 3268 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 336:

/* Line 677 of lalr1.cc  */
#line 3272 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 337:

/* Line 677 of lalr1.cc  */
#line 3278 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 338:

/* Line 677 of lalr1.cc  */
#line 3288 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 339:

/* Line 677 of lalr1.cc  */
#line 3292 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 340:

/* Line 677 of lalr1.cc  */
#line 3302 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 341:

/* Line 677 of lalr1.cc  */
#line 3306 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 342:

/* Line 677 of lalr1.cc  */
#line 3316 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 343:

/* Line 677 of lalr1.cc  */
#line 3320 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 344:

/* Line 677 of lalr1.cc  */
#line 3330 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 345:

/* Line 677 of lalr1.cc  */
#line 3334 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 346:

/* Line 677 of lalr1.cc  */
#line 3344 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 347:

/* Line 677 of lalr1.cc  */
#line 3348 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 348:

/* Line 677 of lalr1.cc  */
#line 3356 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 349:

/* Line 677 of lalr1.cc  */
#line 3360 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 350:

/* Line 677 of lalr1.cc  */
#line 3364 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 351:

/* Line 677 of lalr1.cc  */
#line 3368 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 352:

/* Line 677 of lalr1.cc  */
#line 3378 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 353:

/* Line 677 of lalr1.cc  */
#line 3382 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 354:

/* Line 677 of lalr1.cc  */
#line 3386 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 355:

/* Line 677 of lalr1.cc  */
#line 3394 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 356:

/* Line 677 of lalr1.cc  */
#line 3398 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 357:

/* Line 677 of lalr1.cc  */
#line 3402 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 358:

/* Line 677 of lalr1.cc  */
#line 3406 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 359:

/* Line 677 of lalr1.cc  */
#line 3410 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 360:

/* Line 677 of lalr1.cc  */
#line 3414 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 361:

/* Line 677 of lalr1.cc  */
#line 3422 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 362:

/* Line 677 of lalr1.cc  */
#line 3426 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 363:

/* Line 677 of lalr1.cc  */
#line 3430 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 364:

/* Line 677 of lalr1.cc  */
#line 3438 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 365:

/* Line 677 of lalr1.cc  */
#line 3442 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 366:

/* Line 677 of lalr1.cc  */
#line 3446 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 367:

/* Line 677 of lalr1.cc  */
#line 3450 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 368:

/* Line 677 of lalr1.cc  */
#line 3461 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 369:

/* Line 677 of lalr1.cc  */
#line 3467 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 370:

/* Line 677 of lalr1.cc  */
#line 3477 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 371:

/* Line 677 of lalr1.cc  */
#line 3483 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 372:

/* Line 677 of lalr1.cc  */
#line 3493 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 373:

/* Line 677 of lalr1.cc  */
#line 3497 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 374:

/* Line 677 of lalr1.cc  */
#line 3535 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL
            );
        }
    break;

  case 375:

/* Line 677 of lalr1.cc  */
#line 3541 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 376:

/* Line 677 of lalr1.cc  */
#line 3547 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 377:

/* Line 677 of lalr1.cc  */
#line 3553 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = !rpe ?
                (yysemantic_stack_[(1) - (1)].expr) : new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 378:

/* Line 677 of lalr1.cc  */
#line 3564 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NULL;
        }
    break;

  case 379:

/* Line 677 of lalr1.cc  */
#line 3572 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 380:

/* Line 677 of lalr1.cc  */
#line 3583 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:

/* Line 677 of lalr1.cc  */
#line 3589 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 382:

/* Line 677 of lalr1.cc  */
#line 3599 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:

/* Line 677 of lalr1.cc  */
#line 3603 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 384:

/* Line 677 of lalr1.cc  */
#line 3611 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 385:

/* Line 677 of lalr1.cc  */
#line 3617 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 386:

/* Line 677 of lalr1.cc  */
#line 3625 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 387:

/* Line 677 of lalr1.cc  */
#line 3631 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 388:

/* Line 677 of lalr1.cc  */
#line 3643 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 389:

/* Line 677 of lalr1.cc  */
#line 3649 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 390:

/* Line 677 of lalr1.cc  */
#line 3659 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 391:

/* Line 677 of lalr1.cc  */
#line 3663 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 392:

/* Line 677 of lalr1.cc  */
#line 3667 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 393:

/* Line 677 of lalr1.cc  */
#line 3671 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 394:

/* Line 677 of lalr1.cc  */
#line 3675 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 395:

/* Line 677 of lalr1.cc  */
#line 3681 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 396:

/* Line 677 of lalr1.cc  */
#line 3687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 397:

/* Line 677 of lalr1.cc  */
#line 3695 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 398:

/* Line 677 of lalr1.cc  */
#line 3699 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 399:

/* Line 677 of lalr1.cc  */
#line 3707 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 400:

/* Line 677 of lalr1.cc  */
#line 3711 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 401:

/* Line 677 of lalr1.cc  */
#line 3722 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 402:

/* Line 677 of lalr1.cc  */
#line 3726 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 403:

/* Line 677 of lalr1.cc  */
#line 3730 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 404:

/* Line 677 of lalr1.cc  */
#line 3736 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 405:

/* Line 677 of lalr1.cc  */
#line 3740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 406:

/* Line 677 of lalr1.cc  */
#line 3754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 407:

/* Line 677 of lalr1.cc  */
#line 3758 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 408:

/* Line 677 of lalr1.cc  */
#line 3766 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 409:

/* Line 677 of lalr1.cc  */
#line 3770 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 410:

/* Line 677 of lalr1.cc  */
#line 3780 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 411:

/* Line 677 of lalr1.cc  */
#line 3784 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 412:

/* Line 677 of lalr1.cc  */
#line 3788 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 413:

/* Line 677 of lalr1.cc  */
#line 3797 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 414:

/* Line 677 of lalr1.cc  */
#line 3801 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FilterExpr(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 415:

/* Line 677 of lalr1.cc  */
#line 3807 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
        }
    break;

  case 416:

/* Line 677 of lalr1.cc  */
#line 3811 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
        }
    break;

  case 417:

/* Line 677 of lalr1.cc  */
#line 3819 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 418:

/* Line 677 of lalr1.cc  */
#line 3825 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 419:

/* Line 677 of lalr1.cc  */
#line 3835 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 420:

/* Line 677 of lalr1.cc  */
#line 3843 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 421:

/* Line 677 of lalr1.cc  */
#line 3847 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 422:

/* Line 677 of lalr1.cc  */
#line 3851 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 423:

/* Line 677 of lalr1.cc  */
#line 3855 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 424:

/* Line 677 of lalr1.cc  */
#line 3859 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 425:

/* Line 677 of lalr1.cc  */
#line 3863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 426:

/* Line 677 of lalr1.cc  */
#line 3867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 427:

/* Line 677 of lalr1.cc  */
#line 3871 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 428:

/* Line 677 of lalr1.cc  */
#line 3875 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 429:

/* Line 677 of lalr1.cc  */
#line 3883 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 430:

/* Line 677 of lalr1.cc  */
#line 3887 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 431:

/* Line 677 of lalr1.cc  */
#line 3895 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 432:

/* Line 677 of lalr1.cc  */
#line 3902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 433:

/* Line 677 of lalr1.cc  */
#line 3909 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 434:

/* Line 677 of lalr1.cc  */
#line 3920 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 435:

/* Line 677 of lalr1.cc  */
#line 3928 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 436:

/* Line 677 of lalr1.cc  */
#line 3932 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 437:

/* Line 677 of lalr1.cc  */
#line 3940 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 438:

/* Line 677 of lalr1.cc  */
#line 3948 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 439:

/* Line 677 of lalr1.cc  */
#line 3956 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 440:

/* Line 677 of lalr1.cc  */
#line 4010 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 441:

/* Line 677 of lalr1.cc  */
#line 4014 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 442:

/* Line 677 of lalr1.cc  */
#line 4026 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 443:

/* Line 677 of lalr1.cc  */
#line 4032 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 444:

/* Line 677 of lalr1.cc  */
#line 4042 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 445:

/* Line 677 of lalr1.cc  */
#line 4046 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 446:

/* Line 677 of lalr1.cc  */
#line 4054 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 447:

/* Line 677 of lalr1.cc  */
#line 4058 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 448:

/* Line 677 of lalr1.cc  */
#line 4062 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 449:

/* Line 677 of lalr1.cc  */
#line 4070 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 450:

/* Line 677 of lalr1.cc  */
#line 4080 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 451:

/* Line 677 of lalr1.cc  */
#line 4090 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 452:

/* Line 677 of lalr1.cc  */
#line 4100 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 453:

/* Line 677 of lalr1.cc  */
#line 4110 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 454:

/* Line 677 of lalr1.cc  */
#line 4120 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 455:

/* Line 677 of lalr1.cc  */
#line 4135 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 456:

/* Line 677 of lalr1.cc  */
#line 4141 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 457:

/* Line 677 of lalr1.cc  */
#line 4152 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 458:

/* Line 677 of lalr1.cc  */
#line 4158 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 459:

/* Line 677 of lalr1.cc  */
#line 4169 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 462:

/* Line 677 of lalr1.cc  */
#line 4186 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 463:

/* Line 677 of lalr1.cc  */
#line 4191 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 464:

/* Line 677 of lalr1.cc  */
#line 4200 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 465:

/* Line 677 of lalr1.cc  */
#line 4204 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 466:

/* Line 677 of lalr1.cc  */
#line 4211 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back(
                new QuoteAttrValueContent( LOC((yyloc)),std::string("\"") )
            );
            (yyval.node) = qacl;
        }
    break;

  case 467:

/* Line 677 of lalr1.cc  */
#line 4219 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 468:

/* Line 677 of lalr1.cc  */
#line 4225 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 469:

/* Line 677 of lalr1.cc  */
#line 4235 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 470:

/* Line 677 of lalr1.cc  */
#line 4247 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 471:

/* Line 677 of lalr1.cc  */
#line 4251 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 472:

/* Line 677 of lalr1.cc  */
#line 4258 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 473:

/* Line 677 of lalr1.cc  */
#line 4264 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 474:

/* Line 677 of lalr1.cc  */
#line 4270 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 475:

/* Line 677 of lalr1.cc  */
#line 4277 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 476:

/* Line 677 of lalr1.cc  */
#line 4288 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 477:

/* Line 677 of lalr1.cc  */
#line 4292 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 478:

/* Line 677 of lalr1.cc  */
#line 4302 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 479:

/* Line 677 of lalr1.cc  */
#line 4306 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 480:

/* Line 677 of lalr1.cc  */
#line 4316 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 481:

/* Line 677 of lalr1.cc  */
#line 4320 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 482:

/* Line 677 of lalr1.cc  */
#line 4324 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 483:

/* Line 677 of lalr1.cc  */
#line 4329 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 484:

/* Line 677 of lalr1.cc  */
#line 4338 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 485:

/* Line 677 of lalr1.cc  */
#line 4344 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 486:

/* Line 677 of lalr1.cc  */
#line 4350 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 487:

/* Line 677 of lalr1.cc  */
#line 4356 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 488:

/* Line 677 of lalr1.cc  */
#line 4366 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 489:

/* Line 677 of lalr1.cc  */
#line 4370 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
        }
    break;

  case 490:

/* Line 677 of lalr1.cc  */
#line 4382 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 491:

/* Line 677 of lalr1.cc  */
#line 4386 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 492:

/* Line 677 of lalr1.cc  */
#line 4398 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 493:

/* Line 677 of lalr1.cc  */
#line 4410 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 494:

/* Line 677 of lalr1.cc  */
#line 4414 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 495:

/* Line 677 of lalr1.cc  */
#line 4418 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 496:

/* Line 677 of lalr1.cc  */
#line 4422 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 497:

/* Line 677 of lalr1.cc  */
#line 4426 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 498:

/* Line 677 of lalr1.cc  */
#line 4430 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 499:

/* Line 677 of lalr1.cc  */
#line 4438 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 500:

/* Line 677 of lalr1.cc  */
#line 4446 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL
            );
        }
    break;

  case 501:

/* Line 677 of lalr1.cc  */
#line 4452 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr)
            );
        }
    break;

  case 502:

/* Line 677 of lalr1.cc  */
#line 4458 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 503:

/* Line 677 of lalr1.cc  */
#line 4462 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 504:

/* Line 677 of lalr1.cc  */
#line 4479 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (2)].expr), NULL );
        }
    break;

  case 505:

/* Line 677 of lalr1.cc  */
#line 4483 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 506:

/* Line 677 of lalr1.cc  */
#line 4487 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 507:

/* Line 677 of lalr1.cc  */
#line 4491 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 508:

/* Line 677 of lalr1.cc  */
#line 4499 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 509:

/* Line 677 of lalr1.cc  */
#line 4507 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 510:

/* Line 677 of lalr1.cc  */
#line 4515 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), NULL );
        }
    break;

  case 511:

/* Line 677 of lalr1.cc  */
#line 4519 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (2)].sval)), (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 512:

/* Line 677 of lalr1.cc  */
#line 4523 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 513:

/* Line 677 of lalr1.cc  */
#line 4527 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 514:

/* Line 677 of lalr1.cc  */
#line 4535 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 515:

/* Line 677 of lalr1.cc  */
#line 4541 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 516:

/* Line 677 of lalr1.cc  */
#line 4551 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 517:

/* Line 677 of lalr1.cc  */
#line 4559 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 518:

/* Line 677 of lalr1.cc  */
#line 4563 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 519:

/* Line 677 of lalr1.cc  */
#line 4569 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 520:

/* Line 677 of lalr1.cc  */
#line 4604 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 521:

/* Line 677 of lalr1.cc  */
#line 4610 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 522:

/* Line 677 of lalr1.cc  */
#line 4616 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 523:

/* Line 677 of lalr1.cc  */
#line 4626 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 524:

/* Line 677 of lalr1.cc  */
#line 4630 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 525:

/* Line 677 of lalr1.cc  */
#line 4634 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 526:

/* Line 677 of lalr1.cc  */
#line 4638 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 527:

/* Line 677 of lalr1.cc  */
#line 4642 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 528:

/* Line 677 of lalr1.cc  */
#line 4649 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 529:

/* Line 677 of lalr1.cc  */
#line 4655 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 530:

/* Line 677 of lalr1.cc  */
#line 4665 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 531:

/* Line 677 of lalr1.cc  */
#line 4673 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 532:

/* Line 677 of lalr1.cc  */
#line 4677 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 533:

/* Line 677 of lalr1.cc  */
#line 4681 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 534:

/* Line 677 of lalr1.cc  */
#line 4685 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 535:

/* Line 677 of lalr1.cc  */
#line 4689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 536:

/* Line 677 of lalr1.cc  */
#line 4693 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 537:

/* Line 677 of lalr1.cc  */
#line 4697 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 538:

/* Line 677 of lalr1.cc  */
#line 4701 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 539:

/* Line 677 of lalr1.cc  */
#line 4705 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 540:

/* Line 677 of lalr1.cc  */
#line 4713 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 541:

/* Line 677 of lalr1.cc  */
#line 4721 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 542:

/* Line 677 of lalr1.cc  */
#line 4725 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 543:

/* Line 677 of lalr1.cc  */
#line 4729 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 544:

/* Line 677 of lalr1.cc  */
#line 4739 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 545:

/* Line 677 of lalr1.cc  */
#line 4747 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 546:

/* Line 677 of lalr1.cc  */
#line 4755 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 547:

/* Line 677 of lalr1.cc  */
#line 4759 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 548:

/* Line 677 of lalr1.cc  */
#line 4763 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 549:

/* Line 677 of lalr1.cc  */
#line 4771 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 550:

/* Line 677 of lalr1.cc  */
#line 4775 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 551:

/* Line 677 of lalr1.cc  */
#line 4781 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 552:

/* Line 677 of lalr1.cc  */
#line 4787 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 553:

/* Line 677 of lalr1.cc  */
#line 4791 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 554:

/* Line 677 of lalr1.cc  */
#line 4801 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
        }
    break;

  case 555:

/* Line 677 of lalr1.cc  */
#line 4809 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 556:

/* Line 677 of lalr1.cc  */
#line 4813 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 557:

/* Line 677 of lalr1.cc  */
#line 4819 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 558:

/* Line 677 of lalr1.cc  */
#line 4828 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 559:

/* Line 677 of lalr1.cc  */
#line 4837 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 560:

/* Line 677 of lalr1.cc  */
#line 4843 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 561:

/* Line 677 of lalr1.cc  */
#line 4849 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 562:

/* Line 677 of lalr1.cc  */
#line 4859 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 563:

/* Line 677 of lalr1.cc  */
#line 4876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 564:

/* Line 677 of lalr1.cc  */
#line 4883 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 565:

/* Line 677 of lalr1.cc  */
#line 4898 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 566:

/* Line 677 of lalr1.cc  */
#line 4934 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 567:

/* Line 677 of lalr1.cc  */
#line 4938 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 568:

/* Line 677 of lalr1.cc  */
#line 4947 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
        }
    break;

  case 569:

/* Line 677 of lalr1.cc  */
#line 4956 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new InlineFunction(LOC ((yyloc)), &*(yysemantic_stack_[(3) - (2)].fnsig)->param, &*(yysemantic_stack_[(3) - (2)].fnsig)->ret, dynamic_cast<EnclosedExpr *>((yysemantic_stack_[(3) - (3)].expr)));
          delete (yysemantic_stack_[(3) - (2)].fnsig);
        }
    break;

  case 570:

/* Line 677 of lalr1.cc  */
#line 4966 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 571:

/* Line 677 of lalr1.cc  */
#line 4970 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 572:

/* Line 677 of lalr1.cc  */
#line 4979 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
        }
    break;

  case 573:

/* Line 677 of lalr1.cc  */
#line 4988 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 574:

/* Line 677 of lalr1.cc  */
#line 4992 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 575:

/* Line 677 of lalr1.cc  */
#line 5003 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 576:

/* Line 677 of lalr1.cc  */
#line 5020 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 577:

/* Line 677 of lalr1.cc  */
#line 5026 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 578:

/* Line 677 of lalr1.cc  */
#line 5032 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 579:

/* Line 677 of lalr1.cc  */
#line 5042 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 580:

/* Line 677 of lalr1.cc  */
#line 5046 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 581:

/* Line 677 of lalr1.cc  */
#line 5052 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 582:

/* Line 677 of lalr1.cc  */
#line 5058 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 583:

/* Line 677 of lalr1.cc  */
#line 5062 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 584:

/* Line 677 of lalr1.cc  */
#line 5068 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 585:

/* Line 677 of lalr1.cc  */
#line 5072 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 586:

/* Line 677 of lalr1.cc  */
#line 5078 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 587:

/* Line 677 of lalr1.cc  */
#line 5084 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 588:

/* Line 677 of lalr1.cc  */
#line 5091 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 589:

/* Line 677 of lalr1.cc  */
#line 5101 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 590:

/* Line 677 of lalr1.cc  */
#line 5106 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 591:

/* Line 677 of lalr1.cc  */
#line 5114 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 592:

/* Line 677 of lalr1.cc  */
#line 5120 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 593:

/* Line 677 of lalr1.cc  */
#line 5130 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 594:

/* Line 677 of lalr1.cc  */
#line 5152 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 595:

/* Line 677 of lalr1.cc  */
#line 5161 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 596:

/* Line 677 of lalr1.cc  */
#line 5167 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 597:

/* Line 677 of lalr1.cc  */
#line 5180 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 598:

/* Line 677 of lalr1.cc  */
#line 5194 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 599:

/* Line 677 of lalr1.cc  */
#line 5201 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 600:

/* Line 677 of lalr1.cc  */
#line 5207 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 601:

/* Line 677 of lalr1.cc  */
#line 5217 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 602:

/* Line 677 of lalr1.cc  */
#line 5222 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 603:

/* Line 677 of lalr1.cc  */
#line 5228 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 604:

/* Line 677 of lalr1.cc  */
#line 5238 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 605:

/* Line 677 of lalr1.cc  */
#line 5251 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 606:

/* Line 677 of lalr1.cc  */
#line 5257 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 609:

/* Line 677 of lalr1.cc  */
#line 5278 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 610:

/* Line 677 of lalr1.cc  */
#line 5296 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 611:

/* Line 677 of lalr1.cc  */
#line 5300 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 612:

/* Line 677 of lalr1.cc  */
#line 5313 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EvalExpr(
                LOC((yyloc)), dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)), (yysemantic_stack_[(7) - (6)].expr)
            );
        }
    break;

  case 613:

/* Line 677 of lalr1.cc  */
#line 5319 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EvalExpr( LOC((yyloc)), new VarGetsDeclList( LOC((yyloc)) ), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 614:

/* Line 677 of lalr1.cc  */
#line 5325 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("xquery"); }
    break;

  case 615:

/* Line 677 of lalr1.cc  */
#line 5326 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("empty"); }
    break;

  case 616:

/* Line 677 of lalr1.cc  */
#line 5327 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("attribute"); }
    break;

  case 617:

/* Line 677 of lalr1.cc  */
#line 5328 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("comment"); }
    break;

  case 618:

/* Line 677 of lalr1.cc  */
#line 5329 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("document-node"); }
    break;

  case 619:

/* Line 677 of lalr1.cc  */
#line 5330 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("element"); }
    break;

  case 620:

/* Line 677 of lalr1.cc  */
#line 5331 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("item"); }
    break;

  case 621:

/* Line 677 of lalr1.cc  */
#line 5332 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("if"); }
    break;

  case 622:

/* Line 677 of lalr1.cc  */
#line 5333 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("node"); }
    break;

  case 623:

/* Line 677 of lalr1.cc  */
#line 5334 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("processing-instruction"); }
    break;

  case 624:

/* Line 677 of lalr1.cc  */
#line 5335 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema-attribute"); }
    break;

  case 625:

/* Line 677 of lalr1.cc  */
#line 5336 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema-element"); }
    break;

  case 626:

/* Line 677 of lalr1.cc  */
#line 5337 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("text"); }
    break;

  case 627:

/* Line 677 of lalr1.cc  */
#line 5338 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("typeswitch"); }
    break;

  case 628:

/* Line 677 of lalr1.cc  */
#line 5339 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("empty-sequence"); }
    break;

  case 629:

/* Line 677 of lalr1.cc  */
#line 5340 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("boundary-space"); }
    break;

  case 630:

/* Line 677 of lalr1.cc  */
#line 5341 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ft-option"); }
    break;

  case 631:

/* Line 677 of lalr1.cc  */
#line 5342 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("base-uri"); }
    break;

  case 632:

/* Line 677 of lalr1.cc  */
#line 5343 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lax"); }
    break;

  case 633:

/* Line 677 of lalr1.cc  */
#line 5344 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("strict"); }
    break;

  case 634:

/* Line 677 of lalr1.cc  */
#line 5345 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("idiv"); }
    break;

  case 635:

/* Line 677 of lalr1.cc  */
#line 5346 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("document"); }
    break;

  case 636:

/* Line 677 of lalr1.cc  */
#line 5347 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ftnot"); }
    break;

  case 637:

/* Line 677 of lalr1.cc  */
#line 5348 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("not"); }
    break;

  case 638:

/* Line 677 of lalr1.cc  */
#line 5349 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sensitive"); }
    break;

  case 639:

/* Line 677 of lalr1.cc  */
#line 5350 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("insensitive"); }
    break;

  case 640:

/* Line 677 of lalr1.cc  */
#line 5351 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("diacritics"); }
    break;

  case 641:

/* Line 677 of lalr1.cc  */
#line 5352 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("without"); }
    break;

  case 642:

/* Line 677 of lalr1.cc  */
#line 5353 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stemming"); }
    break;

  case 643:

/* Line 677 of lalr1.cc  */
#line 5354 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("thesaurus"); }
    break;

  case 644:

/* Line 677 of lalr1.cc  */
#line 5355 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stop"); }
    break;

  case 645:

/* Line 677 of lalr1.cc  */
#line 5356 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("wildcards"); }
    break;

  case 646:

/* Line 677 of lalr1.cc  */
#line 5357 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("entire"); }
    break;

  case 647:

/* Line 677 of lalr1.cc  */
#line 5358 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("content"); }
    break;

  case 648:

/* Line 677 of lalr1.cc  */
#line 5359 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("word"); }
    break;

  case 649:

/* Line 677 of lalr1.cc  */
#line 5360 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("start"); }
    break;

  case 650:

/* Line 677 of lalr1.cc  */
#line 5361 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("end"); }
    break;

  case 651:

/* Line 677 of lalr1.cc  */
#line 5362 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("most"); }
    break;

  case 652:

/* Line 677 of lalr1.cc  */
#line 5363 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("skip"); }
    break;

  case 653:

/* Line 677 of lalr1.cc  */
#line 5364 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("copy"); }
    break;

  case 654:

/* Line 677 of lalr1.cc  */
#line 5365 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("general"); }
    break;

  case 655:

/* Line 677 of lalr1.cc  */
#line 5366 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("value"); }
    break;

  case 656:

/* Line 677 of lalr1.cc  */
#line 5367 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("eq"); }
    break;

  case 657:

/* Line 677 of lalr1.cc  */
#line 5368 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ne"); }
    break;

  case 658:

/* Line 677 of lalr1.cc  */
#line 5369 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lt"); }
    break;

  case 659:

/* Line 677 of lalr1.cc  */
#line 5370 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("le"); }
    break;

  case 660:

/* Line 677 of lalr1.cc  */
#line 5371 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("gt"); }
    break;

  case 661:

/* Line 677 of lalr1.cc  */
#line 5372 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ge"); }
    break;

  case 662:

/* Line 677 of lalr1.cc  */
#line 5373 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("at"); }
    break;

  case 663:

/* Line 677 of lalr1.cc  */
#line 5374 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("context"); }
    break;

  case 664:

/* Line 677 of lalr1.cc  */
#line 5375 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("variable"); }
    break;

  case 665:

/* Line 677 of lalr1.cc  */
#line 5376 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("return"); }
    break;

  case 666:

/* Line 677 of lalr1.cc  */
#line 5377 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("for"); }
    break;

  case 667:

/* Line 677 of lalr1.cc  */
#line 5378 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("outer"); }
    break;

  case 668:

/* Line 677 of lalr1.cc  */
#line 5379 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sliding"); }
    break;

  case 669:

/* Line 677 of lalr1.cc  */
#line 5380 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("tumbling"); }
    break;

  case 670:

/* Line 677 of lalr1.cc  */
#line 5381 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("previous"); }
    break;

  case 671:

/* Line 677 of lalr1.cc  */
#line 5382 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("next"); }
    break;

  case 672:

/* Line 677 of lalr1.cc  */
#line 5383 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("only"); }
    break;

  case 673:

/* Line 677 of lalr1.cc  */
#line 5384 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("when"); }
    break;

  case 674:

/* Line 677 of lalr1.cc  */
#line 5385 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("count"); }
    break;

  case 675:

/* Line 677 of lalr1.cc  */
#line 5386 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("in"); }
    break;

  case 676:

/* Line 677 of lalr1.cc  */
#line 5387 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("let"); }
    break;

  case 677:

/* Line 677 of lalr1.cc  */
#line 5388 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("where"); }
    break;

  case 678:

/* Line 677 of lalr1.cc  */
#line 5389 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("by"); }
    break;

  case 679:

/* Line 677 of lalr1.cc  */
#line 5390 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("group"); }
    break;

  case 680:

/* Line 677 of lalr1.cc  */
#line 5391 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("order"); }
    break;

  case 681:

/* Line 677 of lalr1.cc  */
#line 5392 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stable"); }
    break;

  case 682:

/* Line 677 of lalr1.cc  */
#line 5393 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ascending"); }
    break;

  case 683:

/* Line 677 of lalr1.cc  */
#line 5394 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("descending"); }
    break;

  case 684:

/* Line 677 of lalr1.cc  */
#line 5395 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("greatest"); }
    break;

  case 685:

/* Line 677 of lalr1.cc  */
#line 5396 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("least"); }
    break;

  case 686:

/* Line 677 of lalr1.cc  */
#line 5397 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("collation"); }
    break;

  case 687:

/* Line 677 of lalr1.cc  */
#line 5398 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("some"); }
    break;

  case 688:

/* Line 677 of lalr1.cc  */
#line 5399 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("every"); }
    break;

  case 689:

/* Line 677 of lalr1.cc  */
#line 5400 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("satisfies"); }
    break;

  case 690:

/* Line 677 of lalr1.cc  */
#line 5401 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("case"); }
    break;

  case 691:

/* Line 677 of lalr1.cc  */
#line 5402 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("as"); }
    break;

  case 692:

/* Line 677 of lalr1.cc  */
#line 5403 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("then"); }
    break;

  case 693:

/* Line 677 of lalr1.cc  */
#line 5404 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("else"); }
    break;

  case 694:

/* Line 677 of lalr1.cc  */
#line 5405 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("or"); }
    break;

  case 695:

/* Line 677 of lalr1.cc  */
#line 5406 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("and"); }
    break;

  case 696:

/* Line 677 of lalr1.cc  */
#line 5407 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("instance"); }
    break;

  case 697:

/* Line 677 of lalr1.cc  */
#line 5408 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("of"); }
    break;

  case 698:

/* Line 677 of lalr1.cc  */
#line 5409 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("castable"); }
    break;

  case 699:

/* Line 677 of lalr1.cc  */
#line 5410 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("to"); }
    break;

  case 700:

/* Line 677 of lalr1.cc  */
#line 5411 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("div"); }
    break;

  case 701:

/* Line 677 of lalr1.cc  */
#line 5412 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("mod"); }
    break;

  case 702:

/* Line 677 of lalr1.cc  */
#line 5413 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("union"); }
    break;

  case 703:

/* Line 677 of lalr1.cc  */
#line 5414 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("intersect"); }
    break;

  case 704:

/* Line 677 of lalr1.cc  */
#line 5415 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("except"); }
    break;

  case 705:

/* Line 677 of lalr1.cc  */
#line 5416 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("validate"); }
    break;

  case 706:

/* Line 677 of lalr1.cc  */
#line 5417 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("cast"); }
    break;

  case 707:

/* Line 677 of lalr1.cc  */
#line 5418 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("treat"); }
    break;

  case 708:

/* Line 677 of lalr1.cc  */
#line 5419 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("is"); }
    break;

  case 709:

/* Line 677 of lalr1.cc  */
#line 5420 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("preserve"); }
    break;

  case 710:

/* Line 677 of lalr1.cc  */
#line 5421 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("strip"); }
    break;

  case 711:

/* Line 677 of lalr1.cc  */
#line 5422 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("namespace"); }
    break;

  case 712:

/* Line 677 of lalr1.cc  */
#line 5423 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("external"); }
    break;

  case 713:

/* Line 677 of lalr1.cc  */
#line 5424 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("encoding"); }
    break;

  case 714:

/* Line 677 of lalr1.cc  */
#line 5425 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("no-preserve"); }
    break;

  case 715:

/* Line 677 of lalr1.cc  */
#line 5426 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("inherit"); }
    break;

  case 716:

/* Line 677 of lalr1.cc  */
#line 5427 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("no-inherit"); }
    break;

  case 717:

/* Line 677 of lalr1.cc  */
#line 5428 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("declare"); }
    break;

  case 718:

/* Line 677 of lalr1.cc  */
#line 5429 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("construction"); }
    break;

  case 719:

/* Line 677 of lalr1.cc  */
#line 5430 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ordering"); }
    break;

  case 720:

/* Line 677 of lalr1.cc  */
#line 5431 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("default"); }
    break;

  case 721:

/* Line 677 of lalr1.cc  */
#line 5432 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("copy-namespaces"); }
    break;

  case 722:

/* Line 677 of lalr1.cc  */
#line 5433 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("option"); }
    break;

  case 723:

/* Line 677 of lalr1.cc  */
#line 5434 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("version"); }
    break;

  case 724:

/* Line 677 of lalr1.cc  */
#line 5435 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("import"); }
    break;

  case 725:

/* Line 677 of lalr1.cc  */
#line 5436 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema"); }
    break;

  case 726:

/* Line 677 of lalr1.cc  */
#line 5437 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("module"); }
    break;

  case 727:

/* Line 677 of lalr1.cc  */
#line 5438 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("function"); }
    break;

  case 728:

/* Line 677 of lalr1.cc  */
#line 5439 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("score"); }
    break;

  case 729:

/* Line 677 of lalr1.cc  */
#line 5440 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("contains"); }
    break;

  case 730:

/* Line 677 of lalr1.cc  */
#line 5441 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("weight"); }
    break;

  case 731:

/* Line 677 of lalr1.cc  */
#line 5442 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("window"); }
    break;

  case 732:

/* Line 677 of lalr1.cc  */
#line 5443 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("distance"); }
    break;

  case 733:

/* Line 677 of lalr1.cc  */
#line 5444 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("occurs"); }
    break;

  case 734:

/* Line 677 of lalr1.cc  */
#line 5445 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("times"); }
    break;

  case 735:

/* Line 677 of lalr1.cc  */
#line 5446 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("same"); }
    break;

  case 736:

/* Line 677 of lalr1.cc  */
#line 5447 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("different"); }
    break;

  case 737:

/* Line 677 of lalr1.cc  */
#line 5448 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lowercase"); }
    break;

  case 738:

/* Line 677 of lalr1.cc  */
#line 5449 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("uppercase"); }
    break;

  case 739:

/* Line 677 of lalr1.cc  */
#line 5450 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("relationship"); }
    break;

  case 740:

/* Line 677 of lalr1.cc  */
#line 5451 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("levels"); }
    break;

  case 741:

/* Line 677 of lalr1.cc  */
#line 5452 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("language"); }
    break;

  case 742:

/* Line 677 of lalr1.cc  */
#line 5453 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("any"); }
    break;

  case 743:

/* Line 677 of lalr1.cc  */
#line 5454 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("all"); }
    break;

  case 744:

/* Line 677 of lalr1.cc  */
#line 5455 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("phrase"); }
    break;

  case 745:

/* Line 677 of lalr1.cc  */
#line 5456 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("exactly"); }
    break;

  case 746:

/* Line 677 of lalr1.cc  */
#line 5457 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("from"); }
    break;

  case 747:

/* Line 677 of lalr1.cc  */
#line 5458 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("words"); }
    break;

  case 748:

/* Line 677 of lalr1.cc  */
#line 5459 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sentences"); }
    break;

  case 749:

/* Line 677 of lalr1.cc  */
#line 5460 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sentence"); }
    break;

  case 750:

/* Line 677 of lalr1.cc  */
#line 5461 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("paragraph"); }
    break;

  case 751:

/* Line 677 of lalr1.cc  */
#line 5462 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("replace"); }
    break;

  case 752:

/* Line 677 of lalr1.cc  */
#line 5463 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("modify"); }
    break;

  case 753:

/* Line 677 of lalr1.cc  */
#line 5464 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("first"); }
    break;

  case 754:

/* Line 677 of lalr1.cc  */
#line 5465 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("insert"); }
    break;

  case 755:

/* Line 677 of lalr1.cc  */
#line 5466 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("before"); }
    break;

  case 756:

/* Line 677 of lalr1.cc  */
#line 5467 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("after"); }
    break;

  case 757:

/* Line 677 of lalr1.cc  */
#line 5468 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("revalidation"); }
    break;

  case 758:

/* Line 677 of lalr1.cc  */
#line 5469 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("with"); }
    break;

  case 759:

/* Line 677 of lalr1.cc  */
#line 5470 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("nodes"); }
    break;

  case 760:

/* Line 677 of lalr1.cc  */
#line 5471 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("rename"); }
    break;

  case 761:

/* Line 677 of lalr1.cc  */
#line 5472 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("last"); }
    break;

  case 762:

/* Line 677 of lalr1.cc  */
#line 5473 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("delete"); }
    break;

  case 763:

/* Line 677 of lalr1.cc  */
#line 5474 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("into"); }
    break;

  case 764:

/* Line 677 of lalr1.cc  */
#line 5475 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("simple"); }
    break;

  case 765:

/* Line 677 of lalr1.cc  */
#line 5476 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sequential"); }
    break;

  case 766:

/* Line 677 of lalr1.cc  */
#line 5477 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("updating"); }
    break;

  case 767:

/* Line 677 of lalr1.cc  */
#line 5478 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("deterministic"); }
    break;

  case 768:

/* Line 677 of lalr1.cc  */
#line 5479 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("nondeterministic"); }
    break;

  case 769:

/* Line 677 of lalr1.cc  */
#line 5480 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ordered"); }
    break;

  case 770:

/* Line 677 of lalr1.cc  */
#line 5481 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("unordered"); }
    break;

  case 771:

/* Line 677 of lalr1.cc  */
#line 5482 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("returning"); }
    break;

  case 772:

/* Line 677 of lalr1.cc  */
#line 5483 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("block"); }
    break;

  case 773:

/* Line 677 of lalr1.cc  */
#line 5484 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("exit"); }
    break;

  case 774:

/* Line 677 of lalr1.cc  */
#line 5485 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("loop"); }
    break;

  case 775:

/* Line 677 of lalr1.cc  */
#line 5486 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("while"); }
    break;

  case 776:

/* Line 677 of lalr1.cc  */
#line 5487 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("break"); }
    break;

  case 777:

/* Line 677 of lalr1.cc  */
#line 5488 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("continue"); }
    break;

  case 778:

/* Line 677 of lalr1.cc  */
#line 5489 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("try"); }
    break;

  case 779:

/* Line 677 of lalr1.cc  */
#line 5490 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("catch"); }
    break;

  case 780:

/* Line 677 of lalr1.cc  */
#line 5491 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("eval"); }
    break;

  case 781:

/* Line 677 of lalr1.cc  */
#line 5492 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("using"); }
    break;

  case 782:

/* Line 677 of lalr1.cc  */
#line 5493 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("set"); }
    break;

  case 783:

/* Line 677 of lalr1.cc  */
#line 5494 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("index"); }
    break;

  case 784:

/* Line 677 of lalr1.cc  */
#line 5495 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("unique"); }
    break;

  case 785:

/* Line 677 of lalr1.cc  */
#line 5496 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("non"); }
    break;

  case 786:

/* Line 677 of lalr1.cc  */
#line 5497 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("on"); }
    break;

  case 787:

/* Line 677 of lalr1.cc  */
#line 5498 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("range"); }
    break;

  case 788:

/* Line 677 of lalr1.cc  */
#line 5499 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("equality"); }
    break;

  case 789:

/* Line 677 of lalr1.cc  */
#line 5500 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("manually"); }
    break;

  case 790:

/* Line 677 of lalr1.cc  */
#line 5501 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("automatically"); }
    break;

  case 791:

/* Line 677 of lalr1.cc  */
#line 5502 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("maintained"); }
    break;

  case 792:

/* Line 677 of lalr1.cc  */
#line 5503 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("decimal-format"); }
    break;

  case 793:

/* Line 677 of lalr1.cc  */
#line 5504 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("decimal-separator"); }
    break;

  case 794:

/* Line 677 of lalr1.cc  */
#line 5505 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("grouping-separator"); }
    break;

  case 795:

/* Line 677 of lalr1.cc  */
#line 5506 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("infinity"); }
    break;

  case 796:

/* Line 677 of lalr1.cc  */
#line 5507 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("minus-sign"); }
    break;

  case 797:

/* Line 677 of lalr1.cc  */
#line 5508 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("NaN"); }
    break;

  case 798:

/* Line 677 of lalr1.cc  */
#line 5509 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("percent"); }
    break;

  case 799:

/* Line 677 of lalr1.cc  */
#line 5510 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("per-mille"); }
    break;

  case 800:

/* Line 677 of lalr1.cc  */
#line 5511 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("zero-digit"); }
    break;

  case 801:

/* Line 677 of lalr1.cc  */
#line 5512 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("digit"); }
    break;

  case 802:

/* Line 677 of lalr1.cc  */
#line 5513 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("pattern-separator"); }
    break;

  case 803:

/* Line 677 of lalr1.cc  */
#line 5514 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("collection"); }
    break;

  case 804:

/* Line 677 of lalr1.cc  */
#line 5515 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("const"); }
    break;

  case 805:

/* Line 677 of lalr1.cc  */
#line 5516 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("append-only"); }
    break;

  case 806:

/* Line 677 of lalr1.cc  */
#line 5517 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("queue"); }
    break;

  case 807:

/* Line 677 of lalr1.cc  */
#line 5518 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("mutable"); }
    break;

  case 808:

/* Line 677 of lalr1.cc  */
#line 5519 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("read-only"); }
    break;

  case 809:

/* Line 677 of lalr1.cc  */
#line 5520 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("integrity"); }
    break;

  case 810:

/* Line 677 of lalr1.cc  */
#line 5521 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("constraint"); }
    break;

  case 811:

/* Line 677 of lalr1.cc  */
#line 5522 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("check"); }
    break;

  case 812:

/* Line 677 of lalr1.cc  */
#line 5523 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("key"); }
    break;

  case 813:

/* Line 677 of lalr1.cc  */
#line 5524 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("foreach"); }
    break;

  case 814:

/* Line 677 of lalr1.cc  */
#line 5525 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("foreign"); }
    break;

  case 815:

/* Line 677 of lalr1.cc  */
#line 5526 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("keys"); }
    break;

  case 816:

/* Line 677 of lalr1.cc  */
#line 5538 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 817:

/* Line 677 of lalr1.cc  */
#line 5546 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 818:

/* Line 677 of lalr1.cc  */
#line 5550 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 819:

/* Line 677 of lalr1.cc  */
#line 5557 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 820:

/* Line 677 of lalr1.cc  */
#line 5562 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 821:

/* Line 677 of lalr1.cc  */
#line 5570 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 822:

/* Line 677 of lalr1.cc  */
#line 5574 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 823:

/* Line 677 of lalr1.cc  */
#line 5581 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 824:

/* Line 677 of lalr1.cc  */
#line 5585 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 825:

/* Line 677 of lalr1.cc  */
#line 5592 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 826:

/* Line 677 of lalr1.cc  */
#line 5596 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 827:

/* Line 677 of lalr1.cc  */
#line 5603 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 828:

/* Line 677 of lalr1.cc  */
#line 5607 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 829:

/* Line 677 of lalr1.cc  */
#line 5616 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 830:

/* Line 677 of lalr1.cc  */
#line 5628 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 831:

/* Line 677 of lalr1.cc  */
#line 5632 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 832:

/* Line 677 of lalr1.cc  */
#line 5639 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 833:

/* Line 677 of lalr1.cc  */
#line 5643 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 834:

/* Line 677 of lalr1.cc  */
#line 5651 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 835:

/* Line 677 of lalr1.cc  */
#line 5659 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 836:

/* Line 677 of lalr1.cc  */
#line 5667 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 837:

/* Line 677 of lalr1.cc  */
#line 5671 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 838:

/* Line 677 of lalr1.cc  */
#line 5678 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 839:

/* Line 677 of lalr1.cc  */
#line 5682 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 840:

/* Line 677 of lalr1.cc  */
#line 5690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 841:

/* Line 677 of lalr1.cc  */
#line 5701 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 842:

/* Line 677 of lalr1.cc  */
#line 5705 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 843:

/* Line 677 of lalr1.cc  */
#line 5713 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 844:

/* Line 677 of lalr1.cc  */
#line 5725 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 845:

/* Line 677 of lalr1.cc  */
#line 5731 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 846:

/* Line 677 of lalr1.cc  */
#line 5740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 847:

/* Line 677 of lalr1.cc  */
#line 5744 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 848:

/* Line 677 of lalr1.cc  */
#line 5752 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 849:

/* Line 677 of lalr1.cc  */
#line 5756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 850:

/* Line 677 of lalr1.cc  */
#line 5760 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 851:

/* Line 677 of lalr1.cc  */
#line 5767 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 852:

/* Line 677 of lalr1.cc  */
#line 5771 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 853:

/* Line 677 of lalr1.cc  */
#line 5778 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 854:

/* Line 677 of lalr1.cc  */
#line 5782 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 855:

/* Line 677 of lalr1.cc  */
#line 5790 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 856:

/* Line 677 of lalr1.cc  */
#line 5794 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 857:

/* Line 677 of lalr1.cc  */
#line 5798 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 858:

/* Line 677 of lalr1.cc  */
#line 5802 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 859:

/* Line 677 of lalr1.cc  */
#line 5806 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 860:

/* Line 677 of lalr1.cc  */
#line 5814 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 861:

/* Line 677 of lalr1.cc  */
#line 5822 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 862:

/* Line 677 of lalr1.cc  */
#line 5834 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 863:

/* Line 677 of lalr1.cc  */
#line 5846 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 864:

/* Line 677 of lalr1.cc  */
#line 5850 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 865:

/* Line 677 of lalr1.cc  */
#line 5854 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 866:

/* Line 677 of lalr1.cc  */
#line 5862 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 867:

/* Line 677 of lalr1.cc  */
#line 5868 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 868:

/* Line 677 of lalr1.cc  */
#line 5878 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 869:

/* Line 677 of lalr1.cc  */
#line 5882 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 870:

/* Line 677 of lalr1.cc  */
#line 5886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 871:

/* Line 677 of lalr1.cc  */
#line 5890 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 872:

/* Line 677 of lalr1.cc  */
#line 5894 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 873:

/* Line 677 of lalr1.cc  */
#line 5898 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 874:

/* Line 677 of lalr1.cc  */
#line 5902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 875:

/* Line 677 of lalr1.cc  */
#line 5906 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 876:

/* Line 677 of lalr1.cc  */
#line 5914 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 877:

/* Line 677 of lalr1.cc  */
#line 5918 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 878:

/* Line 677 of lalr1.cc  */
#line 5922 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 879:

/* Line 677 of lalr1.cc  */
#line 5926 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 880:

/* Line 677 of lalr1.cc  */
#line 5934 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 881:

/* Line 677 of lalr1.cc  */
#line 5940 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 882:

/* Line 677 of lalr1.cc  */
#line 5950 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 883:

/* Line 677 of lalr1.cc  */
#line 5960 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 884:

/* Line 677 of lalr1.cc  */
#line 5964 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 885:

/* Line 677 of lalr1.cc  */
#line 5972 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 886:

/* Line 677 of lalr1.cc  */
#line 5982 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 887:

/* Line 677 of lalr1.cc  */
#line 5993 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 888:

/* Line 677 of lalr1.cc  */
#line 6000 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 889:

/* Line 677 of lalr1.cc  */
#line 6004 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 890:

/* Line 677 of lalr1.cc  */
#line 6011 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 891:

/* Line 677 of lalr1.cc  */
#line 6015 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(1) - (1)].thesaurus_id_list);
        }
    break;

  case 892:

/* Line 677 of lalr1.cc  */
#line 6022 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 893:

/* Line 677 of lalr1.cc  */
#line 6027 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 894:

/* Line 677 of lalr1.cc  */
#line 6036 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 895:

/* Line 677 of lalr1.cc  */
#line 6045 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 896:

/* Line 677 of lalr1.cc  */
#line 6049 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 897:

/* Line 677 of lalr1.cc  */
#line 6056 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 898:

/* Line 677 of lalr1.cc  */
#line 6060 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 899:

/* Line 677 of lalr1.cc  */
#line 6068 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 900:

/* Line 677 of lalr1.cc  */
#line 6077 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 901:

/* Line 677 of lalr1.cc  */
#line 6084 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 902:

/* Line 677 of lalr1.cc  */
#line 6094 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 903:

/* Line 677 of lalr1.cc  */
#line 6098 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 904:

/* Line 677 of lalr1.cc  */
#line 6105 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 905:

/* Line 677 of lalr1.cc  */
#line 6111 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 906:

/* Line 677 of lalr1.cc  */
#line 6120 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 907:

/* Line 677 of lalr1.cc  */
#line 6124 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 908:

/* Line 677 of lalr1.cc  */
#line 6131 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 909:

/* Line 677 of lalr1.cc  */
#line 6136 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 910:

/* Line 677 of lalr1.cc  */
#line 6148 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 911:

/* Line 677 of lalr1.cc  */
#line 6156 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 912:

/* Line 677 of lalr1.cc  */
#line 6168 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 913:

/* Line 677 of lalr1.cc  */
#line 6176 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 914:

/* Line 677 of lalr1.cc  */
#line 6180 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 915:

/* Line 677 of lalr1.cc  */
#line 6188 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 916:

/* Line 677 of lalr1.cc  */
#line 6192 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 917:

/* Line 677 of lalr1.cc  */
#line 6196 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 918:

/* Line 677 of lalr1.cc  */
#line 6204 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 919:

/* Line 677 of lalr1.cc  */
#line 6212 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange(
                LOC((yyloc)),
                ft_range_mode::exactly,
                (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 920:

/* Line 677 of lalr1.cc  */
#line 6220 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange(
                LOC((yyloc)),
                ft_range_mode::at_least,
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 921:

/* Line 677 of lalr1.cc  */
#line 6228 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange(
                LOC((yyloc)),
                ft_range_mode::at_most,
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 922:

/* Line 677 of lalr1.cc  */
#line 6236 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange(
                LOC((yyloc)),
                ft_range_mode::from_to,
                (yysemantic_stack_[(4) - (2)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 923:

/* Line 677 of lalr1.cc  */
#line 6249 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 924:

/* Line 677 of lalr1.cc  */
#line 6257 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 925:

/* Line 677 of lalr1.cc  */
#line 6269 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 926:

/* Line 677 of lalr1.cc  */
#line 6273 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 927:

/* Line 677 of lalr1.cc  */
#line 6281 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;



/* Line 677 of lalr1.cc  */
#line 11223 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1298;
  const short int
  xquery_parser::yypact_[] =
  {
      1544, -1298, -1298, -1298, -1298,   855,   -30, -1298, -1298,   416,
   -1298, -1298, -1298, -1298,    15,   -11,  9414,    88,   260,   169,
     211,   184, -1298,   253, -1298, -1298, -1298, -1298, -1298, -1298,
     361, -1298,  7694, -1298, -1298,   291, -1298,   357, -1298, -1298,
     395, -1298,   430, -1298,   377,   389, -1298,    54, -1298, -1298,
   -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298, -1298, -1298, -1298, -1298,  9699, -1298,  7112,
   -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298, 11124, -1298, -1298, -1298, -1298, -1298, -1298,
   -1298, -1298,   432, -1298, -1298, -1298, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298, -1298,  1838, 11124, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298,   403, -1298, -1298, -1298,  8272, -1298,  8559,
   -1298, -1298, -1298, -1298, -1298, 11124, -1298, -1298,  6819, -1298,
   -1298, -1298, -1298, -1298, -1298,   420, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298, -1298,    26,   345, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298, -1298,   221,   437,   407, -1298,   374,   375,
   -1298, -1298, -1298, -1298, -1298, -1298,   492, -1298,   489,   425,
     440,   422, -1298, -1298,   530,   540, -1298,   578, -1298, -1298,
   -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298,  4768,   691,
   -1298,  5061, -1298, -1298,   265,  5354,   510,   512, -1298, -1298,
   -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298,   -32,
   -1298, -1298, -1298, -1298,   346, 11124, -1298, -1298, -1298, -1298,
   -1298, -1298,   536,   611, -1298,   423,   458,   -22,   391,   379,
     415, -1298,   659,   513,   610,   612,  5940, -1298, -1298, -1298,
     133, -1298, -1298,  6819, -1298,   398, -1298,   560,  7112, -1298,
     560,  7112, -1298, -1298, -1298,   477, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298,   129, -1298,
   -1298,   687,   380,   386,   -48,   481, 11124,   481, 11124,   -38,
     669,   670,   671, 11124,   568,   603,    57,  8272, -1298, -1298,
     399,   334,   478, 11124, -1298, -1298, -1298, -1298, -1298,   433,
   11124,   431,   436,   356,   419,   479, -1298, -1298, -1298,  8272,
    5354,   546,  5354,    17, -1298, -1298, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298, -1298, -1298, -1298,  5354,  9984, -1298, -1298,
   -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298, -1298,   584,  5354,   453,   454, -1298,   620,
       0,   588,  5354,    37,    56, 11124,   622, -1298,  5354,  7983,
     590, -1298, 11124, 11124, 11124,  5354,   559,  5354,  5354, 11124,
    5354,   595,   596,  5354, 10269,   597,   599,   600,   601,   602,
     606, -1298, -1298, -1298, 11124, -1298,   565,   717,  5354,    41,
   -1298,   730,   573, -1298,  5354,   550, -1298,   736,  5354,  5354,
     579,  5354,  5354,  5354,  5354,   541, 11124, -1298, -1298, -1298,
   -1298,  5354,  5354,  5354, 11124, -1298, -1298, -1298, -1298,   855,
     184, -1298, -1298,   265,   733,  5354, -1298,  5354,   660,   260,
     253,   361,   613,   609,   617,  5354,  5354, -1298, -1298, -1298,
   -1298, -1298, -1298, -1298,   679, -1298,    -6,  6233,  6233,  6233,
   -1298,  6233,  6233, -1298,  6233, -1298,  6233, -1298, -1298, -1298,
   -1298, -1298, -1298, -1298,  6233,  6233,   716,  6233,  6233,  6233,
    6233,  6233,  6233,  6233,  6233,  6233,  6233,  6233,   561,   694,
     695,   698, -1298, -1298, -1298,  2131, -1298, -1298,  6819,  6819,
    5354,   560, -1298, -1298,   560, -1298,  2424,   560,   646,  2717,
   -1298, -1298, -1298, -1298, -1298, -1298,   688,   689, -1298,   169,
   -1298,   783, -1298, -1298, 11124, -1298, -1298, 11124, -1298,   719,
     364, 11124,   469,   652,   653,   719,   687,   690,   682, -1298,
   -1298, -1298, -1298, -1298,    40,   569,   -36, -1298,   515, -1298,
   -1298, -1298, -1298, 11124, 11124, 11124, -1298,   693,   636, -1298,
     637,   600,   291, -1298,   635,   641,   639, -1298,   -20,     4,
    3010,   640, -1298, -1298, 11124,   -13, 11124,   732,     6, -1298,
    5354, -1298,   643,  8272,   734,   785,  8272,   687,   735,   726,
   -1298,   -51, -1298,   654,   650, -1298,   655,  3303,   656,   696,
     -10, -1298,    36,   657, -1298,   658,   661,   686, -1298,   663,
    5354,  5354,   665, -1298,     7,    38,  3596,    -9, -1298, 11124,
     717, -1298,   -34,   666, -1298, -1298, -1298, -1298,   667, -1298,
     109, -1298, -1298, -1298,   -23,    63,   755,   615,   630,   -33,
   -1298,   714,  5647, -1298,   672,   674,   238, -1298, -1298,   675,
   -1298,  1151, -1298, -1298,   -21, 11124,   700,  5354,   739, -1298,
   -1298,   740, 10554,   741,  5354,   744,   -90,   721,   -26,   611,
   -1298, -1298, -1298, -1298, -1298,  6233, -1298, -1298, -1298,    11,
     391,   391,   274,   379,   379,   379,   379,   415,   415, -1298,
   -1298, 10554, 10554, 11124, 11124, -1298,   683, -1298, -1298,   692,
   -1298, -1298, -1298,    64, -1298, -1298,   164,   320,   339,   283,
   -1298,   169,   169, -1298, -1298, -1298, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298,   719, -1298,   742, 10839,   729,  5354, -1298,
   -1298, -1298,   776,   731,  5354,   687,   687,   719, -1298,   531,
     687,   324, 11124,  -135,   245,   847, -1298, -1298,   591,   268,
   -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298,
   -1298,    40,    81,   369, -1298,   662,   287,   -28,   577,   687,
   -1298, -1298, -1298, -1298,   727, 11124, -1298, 11124, -1298, -1298,
     701, -1298,   147,   624, -1298, -1298,   442,   -13,   776, 10554,
     765,   790,   704,   699,   756,   687,   738,   758,   795,   687,
     779,  5354,   759,   -57,   747, -1298, -1298, -1298,   722, -1298,
    5354,   782,  5354,  5354,   757, -1298,   804,   805,  5354, -1298,
     725,   743,   763, 11124, -1298, 11124, -1298, -1298,   745,  5354,
     874, -1298,    -2, -1298,    32, -1298, -1298,   882, -1298,   417,
    5354,  5354,  5354,   418,  5354,  5354,  5354,  5354,  5354,  5354,
     792,  5354,  5354,   603,     1,   746,   489,   673,   771,   798,
     733,   844, -1298, -1298,  5354,   426,   818, -1298, 11124,   821,
   -1298, 11124,   778,   781, 10839,   784, -1298,   197, -1298, -1298,
   -1298, -1298, -1298, -1298, -1298, 11124, -1298, 11124,  5354,   791,
    5354,  5354,   -53,   794, -1298,  5354,    11,   314,   140, -1298,
     664,    58,   680,   681, -1298, -1298,   478, -1298,   676,   174,
   -1298, -1298, -1298,   799, -1298, -1298, -1298,  5354, -1298, -1298,
   -1298, -1298, -1298, -1298, -1298,  5354, -1298,   360,   406, -1298,
     917,   472, -1298, -1298, -1298,  5354, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298,   668, -1298, -1298,   919, -1298, -1298, -1298,
   -1298, -1298,   336,   920, -1298,   390, -1298, -1298, -1298,   599,
     -11,   601,   602,   606,   437,   720,   197,   737,   748,  6526,
     677,   647,    81, -1298,   749,   766,  3889,   767,   772,   815,
     775,   786, -1298,  5354,   820, -1298,   842,   851,  5354, 11124,
     457,   894, -1298, -1298, -1298, -1298, -1298, -1298, 10554, -1298,
    5354,   687,   865, -1298, -1298, -1298,   687,   865, 11124, -1298,
    5354,  5354,   836,  4182, -1298, -1298, 11124, -1298, -1298,  5354,
    5354,   225, -1298,   -24,  9129,   340, -1298,   797, -1298, -1298,
    4475,   796,   801, -1298, -1298, -1298,   849, -1298,   203, -1298,
   -1298,   969, -1298, -1298, 11124, -1298, -1298,   246, -1298, -1298,
   -1298,   800,   751,   752, -1298, -1298, -1298,   760,   761, -1298,
   -1298, -1298, -1298, -1298,   754, 11124,   803, -1298,   850, -1298,
     603, -1298, -1298, -1298,  7405,   673, -1298,  5354, 11124,   818,
   -1298,   687, -1298,   535, -1298,   237,   881, -1298,  5354,   887,
     739, -1298,  8844,   810,   811,   812, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298,  5354, -1298, -1298,  5354,   852,  5354,   817,
     816, -1298,    11,   750, -1298, -1298,  -116, -1298,   272,   -44,
     753,    11,   272,  6233, -1298,   101, -1298, -1298, -1298, -1298,
   -1298, -1298,    11,   858,   723,   569,   -44, -1298, -1298,   724,
     927, -1298, -1298, -1298, -1298, -1298,   825, -1298, -1298, -1298,
    5354, -1298, -1298, -1298, -1298, -1298,   981,   136,   982,   136,
     762,   914, -1298, -1298, -1298, -1298,   843, 11124,   764,   720,
    6526, -1298, -1298,   831, -1298, -1298, -1298, -1298, -1298, -1298,
    5354, 11124, 11124, -1298,   383, -1298,  5354, -1298,   890,   921,
     687,   865, -1298, -1298, -1298,  5354, -1298,   834, -1298, -1298,
   -1298,   833, -1298,  5354,  5354, 11124,   835,   -37, -1298, -1298,
   -1298,   838, -1298, -1298,   874, 11124,   286, -1298,   874, 11124,
   -1298, -1298,  5354,  5354,  5354,  5354,  5354, -1298,  5354,  5354,
   -1298, -1298,   144, -1298,   845, -1298, -1298, -1298, -1298,   881,
   -1298, -1298, -1298,   687, -1298, -1298,   929,   840, -1298,   195,
   -1298, -1298, -1298, -1298, -1298,  5354, -1298, -1298, -1298, -1298,
     848,  6233, -1298, -1298, -1298, -1298, -1298,    50,  6233,  6233,
    -143, -1298,   680, -1298,   255, -1298,   681,    11,   877, -1298,
   -1298,   768, -1298, -1298, -1298, -1298, -1298,    -1, -1298,    -5,
      -5, -1298,   136, -1298, -1298,   214, -1298,   999,   -44,   846,
     924, -1298,  6526,   -73,   770, -1298,   866, -1298, -1298, -1298,
     983, -1298, -1298,  5354,   687, -1298, -1298, -1298,  5354, -1298,
   -1298,   939,  5354, 11124,  5354, -1298,    -8,   874, 11124,   854,
     874, -1298, -1298, -1298, -1298, -1298, -1298, -1298,   922,  7405,
   -1298, -1298, -1298, -1298, 10554, -1298, 10554,   943, -1298, -1298,
     379,  6233,  6233,   274,   258, -1298, -1298, -1298, -1298, -1298,
   -1298,  5354, -1298, -1298, -1298, -1298, -1298,  1013, -1298, -1298,
   -1298,   777, -1298,   914,   935, -1298,   949, 11124,   928,   826,
   11124,  6526,   932, -1298,   865, -1298, 10554, -1298,   868, -1298,
     349,    47, -1298,   859,   874, -1298,   863, 11124, -1298, -1298,
   -1298, 10554,   274,   274,  6233,   871, -1298, -1298, -1298,  6526,
   11124,   773, 11124,   940,   837,   935, 11124,   876,  5354, -1298,
   -1298,   968,   366, -1298, -1298, -1298, -1298,   888,   401, -1298,
   -1298, -1298,   878, -1298,   226, -1298,   274, -1298, -1298,   881,
    5354,   774, 11124,   944, -1298,  5354, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298, -1298,   953,   923, -1298, -1298,   788,   780,
   11124, -1298, 11124, -1298,   787,  5354,   789,   235,  6526, -1298,
    6526,   957,   923, -1298,   880, 11124, -1298,   807,   897, 11124,
     923,   862, -1298,   964, 11124,   802,  6526, -1298
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   411,   412,   610,   565,   717,   726,   631,   629,   617,
     718,   721,   674,   767,   635,   618,   619,   780,   666,   727,
     621,   724,   696,   676,   651,   671,   768,   672,   722,   719,
     667,   670,   623,   725,   624,   625,   765,   782,   764,   668,
     687,   681,   626,   669,     0,   627,   766,   705,   673,   648,
     792,   793,   794,   795,   796,   797,   798,   799,   800,   801,
     802,   402,   405,   695,   691,   682,   662,   616,   392,     0,
     690,   698,   706,   390,   686,   431,   663,   664,   720,   391,
     394,   683,   700,     0,   437,   400,   433,   693,   615,   684,
     685,   713,   688,   704,   712,   396,   395,   634,   675,   715,
     432,   703,   708,   620,     0,     0,   349,   701,   711,   716,
     714,   694,   680,   769,   678,   679,   401,     0,   348,     0,
     404,   403,   709,   665,   689,     0,   393,   378,     0,   410,
     710,   692,   699,   707,   702,   770,   656,   661,   660,   659,
     658,   657,   628,   677,     0,   614,   723,   649,   756,   755,
     757,   633,   632,   652,   762,   622,   754,   759,   760,   751,
     655,   697,   753,   763,   761,   752,   653,   758,   772,   776,
     777,   773,   774,   771,   775,   778,   779,   781,   743,   742,
     729,   647,   640,   736,   732,   650,   646,   745,   746,   636,
     637,   630,   639,   741,   740,   737,   733,   750,   744,   739,
     735,   728,   638,   749,   748,   642,   644,   643,   734,   738,
     730,   645,   731,   641,   747,   803,   804,   805,   806,   807,
     808,   784,   785,   783,   789,   790,   791,   786,   787,   788,
     654,   809,   810,   811,   812,   813,   814,   815,     0,     0,
       2,     0,     4,     6,    12,     0,     0,     0,    18,    20,
      29,    22,    23,    24,    50,    25,    34,    30,    54,    55,
      56,    51,    52,    58,    59,    28,    26,    27,    32,    33,
      53,   201,   200,   197,   198,   199,    31,    11,   177,   178,
     182,   184,   216,   222,     0,     0,   214,   215,   185,   186,
     187,   188,   189,   304,   306,   308,   318,   322,   324,   327,
     332,   335,   338,   340,   342,   344,     0,   346,   352,   354,
       0,   370,   353,   374,   377,   379,   382,   384,     0,   389,
     386,     0,   397,   407,   409,   383,   413,   420,   429,   421,
     422,   423,   426,   427,   424,   425,   444,   446,   447,   448,
     445,   493,   494,   495,   496,   497,   498,   406,   539,   531,
     538,   537,   536,   533,   535,   532,   534,   430,   428,   566,
     567,    57,   190,   191,   193,   192,   194,   195,   408,   196,
     611,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,   108,
       0,     0,     0,     0,   103,   104,   105,   106,   113,     0,
       0,     0,     0,     0,     0,     0,   101,   158,   161,     0,
       0,     0,     0,     0,   717,   726,   617,   635,   618,   619,
     780,   666,   727,   621,   724,   676,   667,   623,   625,   782,
     687,   626,   627,   705,   616,   688,     0,     0,   769,   770,
     614,   762,   622,   754,   760,   751,   653,   772,   776,   777,
     773,   775,   778,   781,     0,     0,     0,     0,   224,     0,
       0,     0,     0,     0,     0,     0,     0,   608,     0,     0,
       0,   609,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   617,   619,   623,   626,
     616,   398,   408,   434,     0,   435,     0,   460,     0,     0,
     373,     0,     0,   376,     0,     0,   489,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   148,   145,   156,
     157,     0,     0,     0,     0,     3,     1,     5,     7,     0,
       0,    13,    10,    15,    16,     0,   180,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   202,   221,   217,
     223,   218,   220,   219,   226,   227,     0,     0,     0,     0,
     363,     0,     0,   361,     0,   313,     0,   362,   355,   360,
     359,   358,   357,   356,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   351,   350,   347,     0,   371,   375,     0,     0,
       0,   385,   417,   388,   387,   399,     0,   414,     0,     0,
     607,    76,    61,    62,   139,   140,     0,     0,   160,     0,
     159,     0,    67,    68,     0,   164,   162,     0,   163,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   576,
     577,   578,   110,   109,     0,    66,   117,   114,     0,   116,
     115,   112,   111,     0,     0,     0,   102,     0,     0,   545,
       0,     0,     0,   541,     0,     0,     0,   555,     0,     0,
       0,     0,   204,   205,     0,     0,     0,   141,     0,   171,
       0,   569,     0,     0,    85,     0,     0,     0,    77,   239,
     240,     0,   225,     0,     0,   546,     0,     0,     0,     0,
       0,   287,     0,     0,   544,     0,     0,     0,   563,     0,
       0,     0,     0,   549,     0,     0,     0,     0,   436,   461,
     460,   457,     0,     0,   491,   490,   372,   554,     0,   488,
       0,   589,   590,   540,     0,     0,     0,     0,     0,     0,
     595,     0,     0,   154,     0,     0,     0,   242,   259,     0,
      19,     0,    21,   183,     0,     0,     0,     0,     0,   203,
     260,     0,     0,     0,     0,     0,     0,     0,     0,   305,
     307,   311,   317,   316,   315,     0,   312,   309,   310,     0,
     326,   325,   323,   329,   330,   331,   328,   333,   334,   337,
     336,     0,     0,     0,     0,   368,     0,   380,   381,     0,
     418,   415,   442,     0,   568,   440,     0,     0,     0,     0,
      65,     0,     0,    40,    42,    43,    44,    45,    47,    48,
      49,    41,    46,    36,    37,     0,     0,    93,     0,    89,
      91,    92,    96,    99,     0,     0,     0,    35,    75,     0,
       0,     0,     0,     0,     0,     0,   878,   883,     0,     0,
     879,   913,   866,   868,   869,   870,   872,   874,   873,   871,
     875,     0,     0,     0,   118,     0,     0,   121,     0,     0,
     509,   499,   542,   543,     0,     0,   559,     0,   556,   500,
       0,   613,     0,     0,   206,   207,     0,   212,   173,     0,
       0,   142,     0,     0,     0,     0,     0,     0,    78,     0,
       0,     0,     0,     0,     0,   548,   547,   510,     0,   562,
       0,     0,     0,     0,     0,   508,     0,     0,     0,   364,
       0,     0,     0,     0,   552,     0,   550,   504,     0,     0,
     460,   458,     0,   449,     0,   438,   439,     0,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   717,     0,     0,     0,     0,     0,     0,
      17,     0,   181,   213,     0,   271,   267,   269,     0,   261,
     262,     0,   727,   620,     0,   628,   516,   517,   523,   524,
     526,   570,   571,   527,   530,     0,   229,     0,     0,     0,
       0,     0,     0,     0,   314,     0,     0,     0,     0,   844,
     320,   817,   821,   823,   825,   827,   830,   837,   838,   846,
     339,   341,   343,   514,   345,   369,   419,     0,   416,   441,
      73,    74,    71,    72,   166,     0,   165,     0,     0,    38,
       0,     0,    94,    95,    97,     0,    98,    63,    64,    69,
      70,    60,   884,     0,   887,   914,     0,   877,   876,   881,
     880,   912,     0,     0,   889,     0,   885,   888,   867,     0,
       0,     0,     0,     0,     0,   119,   125,     0,     0,     0,
       0,     0,     0,   122,     0,     0,     0,     0,     0,   563,
       0,     0,   501,     0,     0,   208,     0,     0,     0,     0,
     253,     0,   250,   255,   211,   174,   143,   172,     0,   175,
       0,     0,    87,    81,    84,    83,     0,    79,     0,   244,
       0,     0,     0,     0,   511,   153,     0,   285,   289,     0,
       0,     0,   292,     0,     0,     0,   299,     0,   366,   365,
       0,     0,     0,   505,   286,   461,     0,   450,     0,   484,
     481,     0,   485,   486,     0,   487,   480,     0,   455,   483,
     482,     0,     0,     0,   582,   583,   579,     0,     0,   587,
     588,   584,   593,   591,     0,     0,     0,   597,   151,   150,
       0,   147,   146,   155,     0,   598,   599,     0,     0,   268,
     280,     0,   281,     0,   272,   273,   274,   275,     0,   264,
       0,   228,     0,     0,     0,     0,   520,   522,   521,   518,
     237,   238,   231,     0,   233,   230,     0,     0,     0,     0,
       0,   828,   841,     0,   319,   321,     0,   860,     0,     0,
       0,     0,     0,     0,   816,   818,   819,   855,   856,   857,
     859,   858,     0,     0,   832,   831,     0,   835,   839,   853,
     851,   850,   843,   847,   515,   443,     0,   168,   167,   170,
       0,    39,    90,   100,   901,   882,     0,   906,     0,   906,
     895,   890,   120,   126,   128,   127,     0,     0,     0,   123,
       0,    14,   502,     0,   560,   561,   564,   557,   558,   248,
       0,     0,     0,   210,   251,   254,     0,   144,     0,    86,
       0,    80,   241,   246,   245,     0,   512,     0,   288,   290,
     295,     0,   293,     0,     0,     0,     0,     0,   300,   367,
     506,     0,   553,   551,   460,     0,     0,   492,   460,     0,
     456,     9,     0,     0,     0,     0,     0,   596,     0,     0,
     149,   605,     0,   600,     0,   243,   284,   282,   283,   276,
     277,   278,   270,     0,   265,   263,     0,     0,   528,     0,
     525,   575,   519,   235,   232,     0,   234,   845,   836,   842,
       0,     0,   915,   916,   926,   925,   924,     0,     0,     0,
       0,   917,   822,   923,     0,   820,   824,     0,     0,   829,
     833,     0,   854,   849,   852,   848,   176,     0,   902,     0,
       0,   900,   907,   908,   904,     0,   899,     0,   897,     0,
     891,   892,     0,     0,     0,   124,     0,   503,   249,   257,
     258,   252,   209,     0,     0,    82,   247,   513,     0,   296,
     294,     0,     0,     0,     0,   507,     0,   460,     0,     0,
     460,   580,   581,   585,   586,   592,   594,   152,     0,     0,
     601,   612,   279,   266,     0,   572,     0,     0,   236,   840,
     927,     0,     0,   919,     0,   865,   864,   863,   862,   861,
     826,     0,   918,   169,   911,   910,   909,     0,   903,   896,
     894,     0,   886,     0,   129,   131,     0,     0,     0,     0,
       0,     0,     0,   303,    88,   291,     0,   301,     0,   297,
     470,   464,   459,     0,   460,   451,     0,     0,   606,   573,
     529,     0,   921,   920,     0,     0,   905,   898,   893,     0,
       0,     0,     0,     0,     0,   130,     0,     0,     0,   478,
     472,     0,   471,   473,   479,   476,   466,     0,   465,   467,
     477,   453,     0,   452,     0,   574,   922,   834,   132,   133,
       0,     0,     0,     0,   256,     0,   298,   463,   474,   475,
     462,   468,   469,   454,     0,     0,   134,   135,     0,     0,
       0,   302,     0,   602,     0,     0,     0,     0,     0,   137,
       0,     0,     0,   136,     0,     0,   603,     0,     0,     0,
       0,     0,   604,     0,     0,     0,     0,   138
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1298, -1298,   853, -1298,   839,   856, -1298,   841, -1298,   548,
     551,  -514, -1298,   448,  -263, -1298, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298,  -886,
   -1298, -1298, -1298, -1298,    62,   262,   709, -1298, -1298,   697,
   -1298,    23,  -842, -1298,  -385,  -411, -1298, -1298,  -587, -1298,
    -860, -1298, -1298,   -71, -1298, -1298, -1298, -1298, -1298,   256,
     793, -1298, -1298, -1298,   213,   644, -1297,   861,   -81, -1298,
    -536,  -265, -1298, -1298, -1298, -1298,   217, -1298, -1298,   823,
   -1298, -1298, -1298, -1298, -1298,   139,  -523,  -662, -1298, -1298,
   -1298,     3, -1298, -1298,  -172,    24,   -65, -1298, -1298, -1298,
     -75, -1298, -1298,   152,   -70, -1298, -1298,   -68, -1159, -1298,
     625,     5, -1298, -1298,     2, -1298, -1298, -1298,    -3, -1298,
   -1298,   563,   566, -1298,  -503, -1298, -1298,  -577,    85,  -573,
      84,    79, -1298, -1298, -1298, -1298, -1298,   819, -1298, -1298,
   -1298, -1298,  -767,  -305, -1048, -1298,  -113, -1298, -1298, -1298,
   -1298, -1298, -1298, -1298,   -39, -1146, -1298, -1298,   282,   -17,
   -1298,  -745, -1298, -1298, -1298, -1298, -1298, -1298, -1298,   517,
   -1298,  -910, -1298,    -7, -1298,   409,  -709, -1298, -1298, -1298,
   -1298, -1298,  -401,  -392, -1102,  -960, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298, -1298, -1298, -1298,   338,  -629,  -773,    67,
    -776, -1298,  -790,  -748, -1298, -1298, -1298, -1298, -1298, -1298,
   -1298,   769,   806,  -537,   257,   110, -1298, -1298, -1298, -1298,
   -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298,
     -19, -1298, -1298,   -15, -1298,  -365,  -100,   -16, -1298, -1298,
    -974, -1298, -1298, -1298,   -74,   -80,  -223,   158, -1298, -1298,
   -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298, -1298,
   -1298,   -69, -1298, -1298, -1298,  -213,   157,   303, -1298, -1298,
   -1298, -1298, -1298,   111, -1298, -1298, -1223, -1298, -1298, -1298,
    -701, -1298,   -94, -1298,  -225, -1298, -1298, -1298, -1298, -1194,
   -1298,   -54, -1298
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   823,   824,   825,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,  1102,
     687,   264,   265,   829,   830,   831,  1168,   266,   405,   406,
     267,  1065,   864,   268,  1474,  1475,   269,   270,   461,   271,
     518,   742,   954,  1169,   272,   273,   274,   275,   276,   407,
     408,   625,   628,   678,   679,  1145,  1026,   277,   278,   537,
     279,   280,   281,   547,   459,   886,   887,   282,   548,   283,
     550,   284,   285,   286,   554,   555,  1090,   767,   287,   689,
     746,   690,   675,  1091,  1092,  1093,   747,   551,   552,   969,
     970,  1344,   553,   966,   967,  1184,  1185,  1186,  1187,   288,
     700,   701,   289,  1121,  1122,  1123,   290,  1125,  1126,   291,
     292,   293,   294,   775,   295,  1214,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   574,   575,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   601,   602,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   803,
     335,   336,   337,  1147,   720,   721,   722,  1492,  1527,  1528,
    1521,  1522,  1529,  1523,  1148,  1149,   338,   339,  1150,   340,
     341,   342,   343,   344,   345,   346,  1012,   768,   976,  1199,
     977,  1349,   978,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   707,  1078,   357,   358,   359,   360,   980,
     981,   982,   983,   361,   362,   363,   364,   365,   366,   739,
     740,   367,  1175,  1176,  1332,  1103,   470,   368,   369,   370,
    1000,  1224,  1225,  1001,  1002,  1003,  1004,  1005,  1234,  1379,
    1380,  1006,  1237,  1007,  1360,  1008,  1009,  1242,  1243,  1385,
    1383,  1226,  1227,  1228,  1229,  1458,   645,   852,   853,   854,
     855,   856,   857,  1056,  1399,  1400,  1057,  1398,  1470,   858,
    1259,  1395,  1391,  1392,  1393,   859,   860,  1230,  1238,  1370,
    1231,  1366,  1215
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       454,   754,   782,  1013,  1013,   596,   611,   783,   784,   785,
     786,   932,   998,  1107,   979,   503,   471,   499,  1010,  1011,
     752,  1266,  1210,   496,  1146,  1073,  1340,  1341,  1331,   902,
     491,     4,   809,   766,   999,  1440,   883,   762,  1401,  1477,
    1139,  1140,  1381,   979,   979,  1320,  1367,   505,   724,   988,
    1031,   485,   862,   492,   661,  1139,   771,   610,   772,   773,
    1072,   774,   903,   776,   763,   939,  1525,   493,   950,   535,
    1303,   777,   778,   914,   662,  1423,   610,  1111,   979,  1490,
     535,   875,   762,   901,   763,  1256,  1206,   841,   933,   497,
     842,   911,   911,  1362,   633,  1451,  1173,   634,   684,   688,
     535,   471,  1170,   501,   989,   877,   993,   890,   923,   502,
     616,  1059,   676,   991,  1066,    75,  1096,  1060,   661,  1455,
    1137,  1047,   409,   622,   762,   617,  1456,    86,   577,  1141,
     635,  1363,  1048,   764,   843,  1061,  1457,   413,   662,   925,
    1424,   979,   479,  1258,  1478,   578,  1062,  1142,  1216,  1143,
     536,   943,   100,  1304,   934,   623,   995,   636,   876,   996,
     412,   962,  1142,   685,  1143,  1017,  1491,  1248,   579,   912,
     929,  1452,  1063,  1526,  1463,   913,   765,   680,   677,   119,
    1442,   105,   878,  1171,   891,   924,  1138,   940,   941,   683,
     671,  1216,   680,   863,   951,   663,   884,   117,  1194,   480,
     597,   863,   942,  1034,  1471,  1368,  1369,   725,   686,   765,
     463,  1139,  1140,   765,  1320,   765,   926,   637,  1144,  1217,
    1291,  1136,  1406,  1262,  1027,  1028,   979,  1479,  1146,   998,
     998,   506,   937,   455,   885,   762,   144,  1146,  1359,   464,
     765,  1112,  1018,   731,   732,   992,   734,   735,   736,   737,
    1508,   999,   999,  1084,  1139,  1140,   743,   744,  1563,  1095,
     765,   125,  1217,   997,  1389,  1017,   608,   481,   482,   556,
     753,   838,   994,   944,   945,  1576,   958,   609,   595,   603,
     759,   760,   605,  1582,   844,  1212,  1083,   638,   946,  1025,
     529,   938,  1438,  1498,  1139,  1140,  1446,   845,  1064,   846,
    1141,   119,   492,  1218,  1219,   492,  1220,   530,   119,   657,
     847,   848,   849,  1221,   850,  1467,   851,   460,  1142,  1120,
    1143,   456,   898,  1222,  1066,  1287,   457,  1554,  1390,   658,
    1207,   660,  1301,  1196,     4,  1223,  1571,  1181,  1077,   959,
    1080,   802,  1019,  1141,   802,  1439,  1218,  1219,   680,  1220,
     979,  1306,   105,  1519,  1476,   666,  1183,  1139,  1053,   462,
     619,  1142,   621,  1143,  1197,   465,  1222,   629,   117,   696,
    1519,   471,   458,  1447,  1139,  1054,   979,   646,  1223,   538,
    1556,   682,  1198,  1141,   648,   539,  1131,   693,  1132,  1315,
     540,   680,  1468,   471,   703,   105,   705,   706,   541,   709,
     466,  1142,   712,  1143,  1555,   577,  1146,   144,   577,  1139,
     542,   117,  1024,  1572,  1239,  1240,  1055,   723,    75,  1348,
    1525,   669,   578,   728,   577,   578,  1256,  1405,  1025,  1086,
      86,   680,  1319,  1476,  1124,   105,  1087,  1241,   508,   472,
     509,   578,   745,  1257,   979,   998,   752,  1307,  1504,   691,
     144,   117,   826,   471,   998,   100,   698,   699,   702,   995,
    1020,  1476,   996,   708,  1142,   998,  1143,   999,   715,   473,
    1037,  1038,  1428,   763,  1520,  1041,   999,  1021,   702,  1022,
    1053,  1142,   119,  1143,  1258,   797,   798,   999,  1086,  1247,
     144,  1548,   965,   827,   680,  1087,  1023,  1054,   828,   986,
     741,  1049,   580,  1086,  1075,   517,   543,   474,   748,   544,
    1087,   680,  1050,  1088,   796,  1180,  1142,  1455,  1143,   799,
    1573,   376,  1574,   545,  1456,   477,  1181,  1551,  1484,   581,
    1524,  1530,   763,  1364,  1457,  1249,  1182,   478,  1587,   380,
    1365,   381,   582,   586,   494,  1183,   680,   559,   498,   546,
     382,  1250,   507,   612,  1089,   560,   561,   587,   562,   614,
    1029,   410,  1524,  1033,   411,   504,   563,   613,  1530,  1036,
     564,   584,   565,   615,  1029,   475,   583,   566,   476,  1070,
     585,   598,   599,   894,   800,   510,   897,   800,  1071,   880,
     800,   513,   514,   567,  1042,  1043,  1044,   515,   833,   892,
    1045,   827,   604,   834,   516,  1426,   828,   607,   811,  1429,
     998,   812,   639,   640,   641,   832,   908,   568,   569,   570,
     571,   572,   573,   600,   511,   606,   512,   642,   643,   920,
     921,   618,   999,   620,   517,   928,  1109,   866,   867,   868,
     388,  1152,  1157,  1153,  1158,  1115,  1374,  1117,  1118,   651,
     652,  1039,  1040,  1067,  1068,  1337,  1338,   521,   882,   519,
     888,   955,   780,   781,  1134,   789,   790,   471,   787,   788,
     471,  1499,   389,  1500,   520,  1154,  1155,  1156,   522,  1159,
    1160,  1161,  1162,  1163,  1164,   523,  1166,  1167,  1464,  1465,
     524,   526,   533,   596,   534,   557,   979,   558,   979,   965,
     576,   391,   588,   930,   589,   590,   600,   610,   591,   624,
     376,   627,   630,  1517,  1387,   631,   653,   644,  1493,   647,
    1539,  1496,   649,  1202,   659,  1204,  1205,   650,  1535,   670,
     672,   673,   674,   680,   692,   697,  1289,   704,   979,   963,
     710,   711,   716,   718,   719,   726,   984,   411,   437,   469,
     476,   727,  1245,   979,   484,   729,   730,   733,   751,   654,
     394,   395,   396,   397,   738,   398,   399,   655,   401,   402,
    1253,   757,   755,   756,   403,   984,   984,   984,   984,   758,
     761,   779,   792,   793,   791,  1532,   794,   804,  1450,   807,
     808,  1453,  1454,   813,   814,   815,   816,   817,   818,   819,
     820,   821,   822,   810,   835,   836,   840,   865,   861,   839,
     984,   870,   871,   872,   874,   881,  1336,   869,  1279,   873,
     889,   893,   896,  1283,   895,   899,  1046,   900,   905,   904,
     910,   918,   915,   906,   909,  1288,   916,  1127,   919,   917,
     922,   935,   936,   947,   948,  1293,  1294,   949,   952,   957,
     956,   968,   971,   985,  1299,  1300,   987,   960,  1015,  1079,
     990,  1079,   964,   828,   762,  1035,  1030,  1051,  1016,  1074,
    1052,  1085,  1076,   984,  1502,  1503,  1082,   676,  1098,  1099,
    1101,  1069,  1105,   371,   372,  1106,   373,   374,  1100,   375,
    1104,  1108,  1113,  1110,  1116,   376,  1119,  1114,  1120,  1124,
    1128,  1135,  1151,   377,  1165,   378,   379,   708,  1130,   708,
    1178,  1174,  1334,   380,  1209,   381,  1177,   635,  1129,  1188,
    1133,  1172,  1190,   965,   382,  1415,  1192,  1536,   383,  1193,
    1203,  1232,  1195,  1208,  1233,  1244,  1236,     4,  1353,  1255,
    1260,  1354,  1213,  1356,  1246,  1274,  1268,  1254,  1271,   863,
    1275,  1276,  1189,  1277,  1281,   556,  1264,  1267,   984,  1280,
     384,   385,   386,  1282,  1278,  1286,  1290,  1265,  1270,  1200,
    1295,  1201,  1309,  1314,  1312,  1317,  1322,  1323,  1443,  1313,
    1328,  1181,  1321,  1326,  1329,  1324,  1325,  1343,  1350,  1351,
    1352,  1355,  1357,  1361,  1358,  1273,  1371,  1377,  1378,  1384,
    1386,  1388,  1394,  1382,  1053,  1402,  1407,   387,  1413,  1417,
    1418,  1414,  1422,  1425,  1404,  1408,   388,  1444,  1445,  1469,
    1441,  1412,  1461,  1449,  1472,  1473,  1397,  1486,  1481,  1482,
    1416,  1501,  1297,  1506,  1497,  1507,  1509,  1510,  1419,  1420,
    1512,  1462,  1495,  1513,  1516,  1518,  1537,  1531,   389,  1311,
    1480,  1533,  1542,  1545,  1543,  1547,  1560,  1431,  1432,  1433,
    1434,  1435,  1550,  1436,  1437,  1562,  1553,   390,  1025,  1575,
    1577,  1540,  1558,  1284,  1564,  1580,  1584,   391,  1565,  1583,
     527,   749,   984,   837,   750,   531,  1568,  1579,  1570,  1032,
    1448,   525,   691,  1252,   632,  1269,  1515,   528,  1538,  1330,
     702,  1586,   656,  1097,  1094,   681,   532,   549,   984,   392,
    1191,  1292,  1411,  1335,  1285,  1345,  1179,  1339,  1342,   717,
     769,  1298,  1308,  1302,   770,   594,   806,  1552,  1318,   931,
    1549,  1316,  1014,  1263,  1081,   393,   394,   395,   396,   397,
    1251,   398,   399,   400,   401,   402,  1327,  1372,  1483,   741,
     403,   404,  1376,  1485,  1460,  1211,  1375,  1487,   492,  1489,
    1333,  1459,   748,  1235,  1058,  1396,  1261,  1466,  1373,     0,
       0,     0,     0,     0,   626,     0,   984,     0,     0,     0,
       0,     0,   664,     0,     0,   375,     0,     0,     0,     0,
       0,   376,     0,     0,     0,     0,     0,     0,     0,   377,
       0,   378,     0,     0,     0,     0,     0,     0,     0,   380,
       0,   381,     0,     0,     0,     0,     0,     0,     0,   665,
     382,     0,     0,     0,   383,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1403,     0,  1546,     0,     0,   384,   385,   961,     0,
       0,     0,     0,     0,     0,  1409,  1410,     0,     0,     0,
       0,     0,     0,     0,     0,  1557,     0,     0,     0,     0,
    1561,     0,     0,     0,     0,     0,     0,     0,     0,  1421,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1427,
    1569,     0,     0,  1430,     0,     0,     0,     0,     0,     0,
       0,     0,   388,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   389,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   391,     0,     0,     0,     0,     0,     0,
    1505,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   392,     0,  1488,     0,     0,
       0,     0,  1494,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   492,     0,     0,     0,     0,   984,     0,
     984,   393,   394,   395,   396,   397,     0,   398,   399,   400,
     401,   402,     0,     0,     0,     0,   403,   404,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1511,     0,     0,  1514,     0,     0,     0,     0,     0,
     984,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1534,     0,     0,     0,   984,     0,     0,     0,     0,
       0,     0,     0,     0,   984,     0,  1541,     0,     0,     0,
    1544,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1559,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1566,     0,  1567,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,     0,     0,  1578,
       0,     2,     3,  1581,     4,     0,     0,     0,  1585,     5,
       6,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     0,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,     0,    64,    65,    66,    67,    68,    69,    70,    71,
      72,     0,     0,    73,    74,     0,     0,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,     0,
      86,     0,    87,    88,    89,    90,     0,    91,     0,     0,
       0,    92,    93,    94,    95,    96,     0,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   103,     0,
       0,     0,   104,   105,   106,   107,   108,     0,     0,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
       0,   118,   119,     0,     0,   120,   121,   122,     0,     0,
       0,   123,     0,   124,   125,   126,     0,   127,   128,   129,
       0,   130,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,   142,   143,   144,     0,
     145,   146,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   189,   190,   191,     0,
     192,   193,   194,   195,   196,   197,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,   414,   415,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
     424,    22,    23,    24,    25,     0,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     0,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,     0,    64,    65,    66,    67,
      68,    69,    70,    71,    72,     0,     0,    73,    74,     0,
       0,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,     0,    86,     0,    87,    88,    89,    90,
       0,    91,     0,     0,     0,    92,    93,    94,    95,    96,
       0,     0,     0,     0,     0,     0,    97,    98,    99,   100,
     101,   102,   103,     0,     0,     0,   104,   105,   106,   107,
     108,     0,     0,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,     0,   118,   119,     0,     0,   120,
     121,   122,     0,     0,     0,   123,   495,   124,   125,   126,
       0,   127,   128,   129,     0,   130,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
     142,   143,   144,     0,   440,   146,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,   191,     0,   192,   193,   194,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   414,   415,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   424,    22,    23,    24,    25,     0,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,     0,    64,
      65,    66,    67,    68,    69,    70,    71,    72,     0,     0,
      73,    74,     0,     0,     0,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     0,    86,     0,    87,
      88,    89,    90,     0,    91,     0,     0,     0,    92,    93,
      94,    95,    96,     0,     0,     0,     0,     0,     0,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,   104,
     105,   106,   107,   108,     0,     0,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     0,   118,   119,
       0,     0,   120,   121,   122,     0,   795,     0,   123,     0,
     124,   125,   126,     0,   127,   128,   129,     0,   130,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,   144,     0,   440,   146,     0,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,   190,   191,     0,   192,   193,   194,
     195,   196,   197,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   414,
     415,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,   424,    22,    23,    24,
      25,     0,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     0,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,     0,    64,    65,    66,    67,    68,    69,    70,    71,
      72,     0,     0,    73,    74,     0,     0,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,     0,
      86,     0,    87,    88,    89,    90,     0,    91,     0,     0,
       0,    92,    93,    94,    95,    96,     0,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   103,     0,
       0,     0,   104,   105,   106,   107,   108,     0,     0,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
       0,   118,   119,     0,     0,   120,   121,   122,     0,     0,
       0,   123,   801,   124,   125,   126,     0,   127,   128,   129,
       0,   130,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,   142,   143,   144,     0,
     440,   146,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   189,   190,   191,     0,
     192,   193,   194,   195,   196,   197,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,   414,   415,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,   424,
      22,    23,    24,    25,     0,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     0,     0,    73,    74,     0,     0,
       0,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     0,    86,     0,    87,    88,    89,    90,     0,
      91,     0,     0,     0,    92,    93,    94,    95,    96,     0,
       0,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   103,     0,     0,     0,   104,   105,   106,   107,   108,
       0,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,     0,   118,   119,     0,     0,   120,   121,
     122,     0,     0,     0,   123,   805,   124,   125,   126,     0,
     127,   128,   129,     0,   130,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,   144,     0,   440,   146,     0,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,   191,     0,   192,   193,   194,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,   414,   415,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,   424,    22,    23,    24,    25,     0,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     0,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,     0,    64,    65,
      66,    67,    68,    69,    70,    71,    72,     0,     0,    73,
      74,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     0,    86,     0,    87,    88,
      89,    90,     0,    91,     0,     0,     0,    92,    93,    94,
      95,    96,     0,     0,     0,     0,     0,     0,    97,    98,
      99,   100,   101,   102,   103,     0,     0,     0,   104,   105,
     106,   107,   108,     0,     0,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,     0,   118,   119,     0,
       0,   120,   121,   122,     0,   879,     0,   123,     0,   124,
     125,   126,     0,   127,   128,   129,     0,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,   142,   143,   144,     0,   440,   146,     0,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,     0,   189,   190,   191,     0,   192,   193,   194,   195,
     196,   197,     0,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   414,   415,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,   424,    22,    23,    24,    25,
       0,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
       0,    64,    65,    66,    67,    68,    69,    70,    71,    72,
       0,     0,    73,    74,     0,     0,     0,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     0,    86,
       0,    87,    88,    89,    90,     0,    91,     0,     0,     0,
      92,    93,    94,    95,    96,     0,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   103,     0,     0,
       0,   104,   105,   106,   107,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,     0,
     118,   119,     0,     0,   120,   121,   122,     0,   907,     0,
     123,     0,   124,   125,   126,     0,   127,   128,   129,     0,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,   144,     0,   440,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,   191,     0,   192,
     193,   194,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,   414,   415,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,   424,    22,
      23,    24,    25,     0,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     0,    64,    65,    66,    67,    68,    69,
      70,    71,    72,     0,     0,    73,    74,     0,     0,     0,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,     0,    86,     0,    87,    88,    89,    90,     0,    91,
       0,     0,     0,    92,    93,    94,    95,    96,     0,     0,
       0,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,     0,     0,     0,   104,   105,   106,   107,   108,     0,
       0,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,     0,   118,   119,     0,     0,   120,   121,   122,
       0,   927,     0,   123,     0,   124,   125,   126,     0,   127,
     128,   129,     0,   130,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,     0,   142,   143,
     144,     0,   440,   146,     0,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,     0,   189,   190,
     191,     0,   192,   193,   194,   195,   196,   197,     0,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,   414,   415,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,   424,    22,    23,    24,    25,     0,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     0,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,     0,    64,    65,    66,
      67,    68,    69,    70,    71,    72,     0,     0,    73,    74,
       0,     0,     0,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     0,    86,     0,    87,    88,    89,
      90,     0,    91,     0,     0,     0,    92,    93,    94,    95,
      96,     0,     0,     0,     0,     0,     0,    97,    98,    99,
     100,   101,   102,   103,     0,     0,     0,   104,   105,   106,
     107,   108,     0,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,     0,   118,   119,     0,     0,
     120,   121,   122,     0,  1272,     0,   123,     0,   124,   125,
     126,     0,   127,   128,   129,     0,   130,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,   144,     0,   440,   146,     0,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,   191,     0,   192,   193,   194,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   414,   415,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   424,    22,    23,    24,    25,     0,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,     0,
      64,    65,    66,    67,    68,    69,    70,    71,    72,     0,
       0,    73,    74,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     0,    86,     0,
      87,    88,    89,    90,     0,    91,     0,     0,     0,    92,
      93,    94,    95,    96,     0,     0,     0,     0,     0,     0,
      97,    98,    99,   100,   101,   102,   103,     0,     0,     0,
     104,   105,   106,   107,   108,     0,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,     0,   118,
     119,     0,     0,   120,   121,   122,     0,  1296,     0,   123,
       0,   124,   125,   126,     0,   127,   128,   129,     0,   130,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,   142,   143,   144,     0,   440,   146,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     0,   189,   190,   191,     0,   192,   193,
     194,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     414,   415,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   424,    22,    23,
      24,    25,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,     0,     0,    73,    74,     0,     0,     0,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       0,    86,     0,    87,    88,    89,    90,     0,    91,     0,
       0,     0,    92,    93,    94,    95,    96,     0,     0,     0,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   103,
       0,     0,     0,   104,   105,   106,   107,   108,     0,     0,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,     0,   118,   119,     0,     0,   120,   121,   122,     0,
    1310,     0,   123,     0,   124,   125,   126,     0,   127,   128,
     129,     0,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,   144,
       0,   440,   146,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,   189,   190,   191,
       0,   192,   193,   194,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,     5,     6,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     0,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,     0,    64,    65,    66,    67,
      68,    69,    70,    71,    72,     0,     0,    73,    74,     0,
       0,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,     0,    86,     0,    87,    88,    89,    90,
       0,    91,     0,     0,     0,    92,    93,    94,    95,    96,
       0,     0,     0,     0,     0,     0,    97,    98,    99,   100,
     101,   102,   103,     0,     0,     0,   104,   105,   106,   107,
     108,     0,     0,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,     0,   118,   119,     0,     0,   120,
     121,   122,     0,     0,     0,   123,     0,   124,   125,   126,
       0,   127,   128,   129,     0,   130,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
     142,   143,   144,     0,   145,   146,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,   191,     0,   192,   193,   194,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,     5,     6,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,     0,    64,
      65,    66,    67,    68,    69,    70,    71,    72,     0,     0,
      73,    74,     0,     0,     0,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     0,    86,     0,    87,
      88,    89,    90,     0,    91,     0,     0,     0,    92,    93,
      94,    95,    96,     0,     0,     0,     0,     0,     0,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,   104,
     105,   106,   107,   108,     0,     0,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     0,   118,   119,
       0,     0,   120,   121,   122,     0,     0,     0,   123,     0,
     124,   125,   126,     0,   127,   128,   129,     0,   130,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,   144,     0,   440,   146,     0,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,   190,   191,     0,   192,   193,   194,
     195,   196,   197,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   414,
     415,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,   424,    22,    23,    24,
      25,     0,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     0,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,     0,    64,    65,    66,    67,    68,    69,    70,    71,
      72,     0,     0,    73,    74,     0,     0,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,     0,
      86,     0,    87,    88,    89,    90,     0,    91,     0,     0,
       0,    92,    93,    94,    95,    96,     0,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   103,     0,
       0,     0,   104,   105,   106,   107,   108,     0,     0,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
       0,   118,   119,     0,     0,   120,   121,   122,     0,     0,
       0,   123,     0,   124,   125,   126,     0,   127,   128,   129,
       0,   130,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,   142,   143,   144,     0,
     440,   146,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   189,   190,   191,     0,
     192,   193,   194,   195,   196,   197,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,   953,   415,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,   424,
      22,    23,    24,    25,     0,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     0,     0,    73,    74,     0,     0,
       0,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     0,    86,     0,    87,    88,    89,    90,     0,
      91,     0,     0,     0,    92,    93,    94,    95,    96,     0,
       0,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   103,     0,     0,     0,   104,   105,   106,   107,   108,
       0,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,     0,   118,   119,     0,     0,   120,   121,
     122,     0,     0,     0,   123,     0,   124,   125,   126,     0,
     127,   128,   129,     0,   130,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,   144,     0,   440,   146,     0,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,   191,     0,   192,   193,   194,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,   414,   415,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,   420,   421,
      19,   423,   424,    22,   425,    24,    25,     0,    26,    27,
      28,    29,   426,    31,    32,    33,    34,    35,    36,   429,
      38,    39,   430,     0,    41,    42,    43,     0,   432,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,     0,    64,    65,
      66,    67,    68,    69,    70,    71,    72,     0,     0,    73,
      74,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     0,    86,     0,    87,    88,
      89,    90,     0,    91,     0,     0,     0,   435,    93,    94,
      95,    96,     0,     0,     0,     0,     0,     0,    97,    98,
      99,   100,   101,   102,   103,     0,     0,     0,   104,   105,
     592,   107,   108,     0,     0,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,     0,   593,   119,     0,
       0,   120,   121,   122,     0,     0,     0,   123,     0,   124,
     125,   126,     0,   127,   128,   129,     0,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,   142,   143,   144,     0,   440,   146,     0,   147,
     148,   149,   150,   151,   152,   153,   441,   155,   443,   157,
     444,   445,   160,   161,   162,   163,   164,   165,   446,   167,
     447,   448,   449,   450,   172,   173,   451,   452,   176,   453,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,     0,   189,   190,   191,     0,   192,   193,   194,   195,
     196,   197,     0,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   414,   415,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,   420,   421,    19,   423,   424,    22,   425,    24,    25,
       0,    26,    27,    28,    29,   426,    31,    32,    33,    34,
      35,    36,   429,    38,    39,   430,     0,    41,    42,    43,
       0,   432,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
       0,    64,    65,    66,    67,    68,    69,    70,    71,    72,
       0,     0,    73,    74,     0,     0,     0,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     0,    86,
       0,    87,    88,    89,    90,     0,    91,     0,     0,     0,
     435,    93,    94,    95,    96,     0,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   103,     0,     0,
       0,   104,   105,   106,   107,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,     0,
     118,   119,     0,     0,   120,   121,   122,     0,     0,     0,
     123,     0,   124,   125,   126,     0,   127,   128,   129,     0,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,   144,     0,   440,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   441,
     155,   443,   157,   444,   445,   160,   161,   162,   163,   164,
     165,   446,   167,   447,   448,   449,   450,   172,   173,   451,
     452,   176,   453,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,   191,     0,   192,
     193,   194,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,   414,   415,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,   420,   421,    19,   423,   424,    22,
     425,    24,    25,     0,    26,    27,    28,    29,   426,    31,
      32,    33,    34,    35,    36,   429,    38,    39,   430,     0,
      41,    42,    43,     0,   432,    46,   433,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     0,    64,    65,    66,    67,    68,    69,
      70,    71,    72,     0,     0,    73,    74,     0,     0,     0,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,     0,    86,     0,    87,    88,    89,    90,     0,    91,
       0,     0,     0,   435,    93,    94,    95,    96,     0,     0,
       0,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,     0,     0,     0,   104,   105,     0,   107,   108,     0,
       0,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,     0,     0,     0,     0,     0,   120,   121,   122,
       0,     0,     0,   123,     0,   124,   125,   126,     0,   127,
     128,   129,     0,   130,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,     0,   142,   143,
     144,     0,   440,   146,     0,   147,   148,   149,   150,   151,
     152,   153,   441,   155,   443,   157,   444,   445,   160,   161,
     162,   163,   164,   165,   446,   167,   447,   448,   449,   450,
     172,   173,   451,   452,   176,   453,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,     0,   189,   190,
     191,     0,   192,   193,   194,   195,   196,   197,     0,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,   414,   415,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,   420,   421,    19,
     423,   424,    22,   425,    24,    25,     0,    26,    27,    28,
      29,   426,    31,    32,    33,    34,    35,    36,   429,    38,
      39,   430,     0,    41,    42,    43,     0,   432,    46,   433,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,     0,    64,    65,    66,
      67,    68,    69,    70,    71,    72,     0,     0,    73,    74,
       0,     0,     0,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     0,    86,     0,    87,    88,    89,
      90,     0,    91,     0,     0,     0,   435,    93,    94,    95,
      96,     0,     0,     0,     0,     0,     0,    97,    98,    99,
     100,   101,   102,   103,     0,     0,     0,   104,   105,     0,
     107,   108,     0,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,     0,     0,     0,     0,     0,
     120,   121,   122,     0,     0,     0,   123,     0,   124,   125,
     126,     0,     0,     0,   129,     0,   130,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,   144,     0,   440,   146,     0,   147,   148,
     149,   150,   151,   152,   153,   441,   155,   443,   157,   444,
     445,   160,   161,   162,   163,   164,   165,   446,   167,   447,
     448,   449,   450,   172,   173,   451,   452,   176,   453,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,   191,     0,   192,   193,   194,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     0,     0,     0,     0,     0,   414,   415,     0,
       7,     8,   486,    10,    11,    12,    13,   417,    15,   487,
     420,   421,   422,   423,   424,    22,   425,    24,    25,     0,
      26,    27,    28,    29,   426,    31,   488,    33,    34,    35,
      36,   429,    38,    39,   430,     0,    41,   489,    43,     0,
     432,    46,   433,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,     0,     0,    63,     0,
      64,    65,    66,   490,     0,     0,    70,    71,    72,     0,
       0,     0,    74,     0,     0,     0,     0,    76,    77,    78,
       0,     0,    81,    82,     0,     0,     0,     0,     0,     0,
      87,    88,    89,    90,     0,    91,     0,     0,     0,   435,
      93,    94,     0,     0,     0,     0,     0,     0,     0,     0,
      97,    98,    99,     0,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   107,   108,     0,     0,     0,     0,   109,
     110,   111,   112,   438,   114,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   122,     0,     0,     0,   123,
       0,   124,   125,     0,     0,     0,     0,   129,     0,   130,
       0,   131,   132,   133,   134,   439,   136,   137,   138,   139,
     140,   141,     0,     0,   142,   143,     0,     0,   440,   146,
       0,   147,   148,   149,   150,   151,   152,   153,   441,   155,
     443,   157,   444,   445,   160,   161,   162,   163,   164,   165,
     446,   167,   447,   448,   449,   450,   172,   173,   451,   452,
     176,   453,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     0,   189,   190,   191,     0,   192,   193,
     194,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     0,     0,     0,     0,     0,
     414,   415,     0,     7,     8,   416,    10,    11,    12,    13,
     417,   418,   419,   420,   421,   422,   423,   424,    22,   425,
      24,    25,     0,    26,    27,    28,    29,   426,    31,   427,
      33,    34,   428,    36,   429,    38,    39,   430,     0,    41,
     431,    43,     0,   432,    46,   433,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,     0,
       0,    63,     0,    64,    65,    66,   434,     0,     0,    70,
      71,    72,     0,     0,     0,    74,     0,     0,     0,     0,
      76,    77,    78,     0,     0,    81,    82,     0,     0,     0,
       0,     0,     0,    87,    88,    89,    90,     0,    91,     0,
       0,     0,   435,    93,    94,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    98,    99,     0,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   107,   108,     0,     0,
       0,     0,   109,   110,   111,   112,   438,   114,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   122,     0,
       0,     0,   123,     0,   124,     0,     0,     0,     0,     0,
     129,     0,   130,     0,   131,   132,   133,   134,   439,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,     0,
       0,   440,   146,     0,   147,   148,   149,   150,   151,   152,
     153,   441,   442,   443,   157,   444,   445,   160,   161,   162,
     163,   164,   165,   446,   167,   447,   448,   449,   450,   172,
     173,   451,   452,   176,   453,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,   189,   190,   191,
       0,   192,   193,   194,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   467,     0,
       0,     0,     3,     0,     0,     0,     0,     0,     0,   414,
     415,     0,     7,     8,   416,    10,    11,    12,    13,   417,
     418,   419,   420,   421,   422,   423,   424,    22,   425,    24,
      25,     0,    26,    27,    28,    29,   426,    31,   427,    33,
      34,   428,    36,   429,    38,    39,   430,     0,    41,   431,
      43,     0,   432,    46,   433,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,     0,     0,
      63,     0,    64,    65,    66,   434,     0,     0,    70,    71,
      72,     0,     0,     0,    74,     0,     0,     0,     0,    76,
      77,    78,     0,     0,    81,    82,     0,     0,     0,     0,
       0,     0,    87,    88,    89,    90,     0,    91,     0,     0,
       0,   435,    93,    94,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,    99,     0,   101,   102,   103,   468,
       0,     0,   469,     0,     0,   107,   108,     0,     0,     0,
       0,   109,   110,   111,   112,   438,   114,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   122,     0,     0,
       0,   123,     0,   124,     0,     0,     0,     0,     0,     0,
       0,   130,     0,   131,   132,   133,   134,   439,   136,   137,
     138,   139,   140,   141,     0,     0,   142,   143,     0,     0,
     440,   146,     0,   147,   148,   149,   150,   151,   152,   153,
     441,   442,   443,   157,   444,   445,   160,   161,   162,   163,
     164,   165,   446,   167,   447,   448,   449,   450,   172,   173,
     451,   452,   176,   453,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   189,   190,   191,     0,
     192,   193,   194,   195,   196,   197,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   467,     0,     0,
       0,     3,     0,   694,     0,     0,     0,     0,   414,   415,
       0,     7,     8,   416,    10,    11,    12,    13,   417,   418,
     419,   420,   421,   422,   423,   424,    22,   425,    24,    25,
       0,    26,    27,    28,    29,   426,    31,   427,    33,    34,
     428,    36,   429,    38,    39,   430,     0,    41,   431,    43,
       0,   432,    46,   433,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,     0,     0,    63,
       0,    64,    65,    66,   434,     0,     0,    70,    71,    72,
       0,     0,     0,    74,     0,     0,     0,     0,    76,    77,
      78,     0,     0,    81,    82,     0,     0,     0,     0,     0,
       0,    87,    88,    89,    90,     0,    91,     0,     0,     0,
     435,    93,    94,     0,     0,     0,     0,     0,     0,     0,
       0,    97,    98,    99,     0,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   107,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   438,   114,   115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   122,     0,     0,     0,
     123,   695,   124,     0,     0,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   439,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,     0,     0,   440,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   441,
     442,   443,   157,   444,   445,   160,   161,   162,   163,   164,
     165,   446,   167,   447,   448,   449,   450,   172,   173,   451,
     452,   176,   453,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,   191,     0,   192,
     193,   194,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   467,     0,     0,     0,
       3,     0,     0,     0,     0,     0,     0,   414,   415,     0,
       7,     8,   416,    10,    11,    12,    13,   417,   418,   419,
     420,   421,   422,   423,   424,    22,   425,    24,    25,     0,
      26,    27,    28,    29,   426,    31,   427,    33,    34,   428,
      36,   429,    38,    39,   430,     0,    41,   431,    43,     0,
     432,    46,   433,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,     0,     0,    63,     0,
      64,    65,    66,   434,     0,     0,    70,    71,    72,     0,
       0,     0,    74,     0,     0,     0,     0,    76,    77,    78,
       0,     0,    81,    82,     0,     0,     0,     0,     0,     0,
      87,    88,    89,    90,     0,    91,     0,     0,     0,   435,
      93,    94,     0,     0,     0,     0,     0,     0,     0,     0,
      97,    98,    99,     0,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   107,   108,     0,     0,     0,     0,   109,
     110,   111,   112,   438,   114,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   122,     0,     0,     0,   123,
       0,   124,     0,     0,     0,     0,     0,     0,     0,   130,
       0,   131,   132,   133,   134,   439,   136,   137,   138,   139,
     140,   141,     0,     0,   142,   143,     0,     0,   440,   146,
       0,   147,   148,   149,   150,   151,   152,   153,   441,   442,
     443,   157,   444,   445,   160,   161,   162,   163,   164,   165,
     446,   167,   447,   448,   449,   450,   172,   173,   451,   452,
     176,   453,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     0,   189,   190,   191,     0,   192,   193,
     194,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   500,     0,     3,     0,     0,
       0,     0,     0,     0,   414,   415,     0,     7,     8,   416,
      10,    11,    12,    13,   417,   418,   419,   420,   421,   422,
     423,   424,    22,   425,    24,    25,     0,    26,    27,    28,
      29,   426,    31,   427,    33,    34,   428,    36,   429,    38,
      39,   430,     0,    41,   431,    43,     0,   432,    46,   433,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,     0,     0,    63,     0,    64,    65,    66,
     434,     0,     0,    70,    71,    72,     0,     0,     0,    74,
       0,     0,     0,     0,    76,    77,    78,     0,     0,    81,
      82,     0,     0,     0,     0,     0,     0,    87,    88,    89,
      90,     0,    91,     0,     0,     0,   435,    93,    94,     0,
       0,     0,     0,     0,     0,     0,     0,    97,    98,    99,
       0,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     107,   108,     0,     0,     0,     0,   109,   110,   111,   112,
     438,   114,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   122,     0,     0,     0,   123,     0,   124,     0,
       0,     0,     0,     0,     0,     0,   130,     0,   131,   132,
     133,   134,   439,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,     0,     0,   440,   146,     0,   147,   148,
     149,   150,   151,   152,   153,   441,   442,   443,   157,   444,
     445,   160,   161,   162,   163,   164,   165,   446,   167,   447,
     448,   449,   450,   172,   173,   451,   452,   176,   453,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,   191,     0,   192,   193,   194,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     3,     0,     0,     0,     0,     0,     0,   414,
     415,     0,     7,     8,   486,    10,    11,    12,    13,   417,
      15,   487,   420,   421,   972,   423,   424,    22,   425,    24,
      25,     0,    26,    27,    28,    29,   426,    31,   488,    33,
      34,    35,    36,   429,    38,    39,   430,     0,    41,   489,
      43,     0,   432,    46,   433,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,     0,     0,
      63,     0,    64,    65,    66,   490,     0,     0,    70,    71,
      72,     0,     0,     0,    74,     0,     0,     0,     0,    76,
      77,    78,     0,     0,    81,    82,     0,     0,     0,     0,
       0,     0,    87,    88,    89,    90,     0,    91,     0,     0,
       0,   435,    93,    94,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,    99,     0,   101,   102,   973,     0,
       0,     0,   974,     0,     0,   107,   108,     0,     0,     0,
       0,   109,   110,   111,   112,   438,   114,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   122,     0,     0,
       0,   123,  1346,   124,   125,     0,     0,     0,     0,  1347,
       0,   130,     0,   131,   132,   133,   134,   439,   136,   137,
     138,   139,   140,   141,     0,     0,   975,   143,     0,     0,
     440,   146,     0,   147,   148,   149,   150,   151,   152,   153,
     441,   155,   443,   157,   444,   445,   160,   161,   162,   163,
     164,   165,   446,   167,   447,   448,   449,   450,   172,   173,
     451,   452,   176,   453,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   189,   190,   191,     0,
     192,   193,   194,   195,   196,   197,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,     3,     0,     0,
       0,     0,     0,     0,   414,   415,     0,     7,     8,   486,
      10,    11,    12,    13,   417,    15,   487,   420,   421,   972,
     423,   424,    22,   425,    24,    25,     0,    26,    27,    28,
      29,   426,    31,   488,    33,    34,    35,    36,   429,    38,
      39,   430,     0,    41,   489,    43,     0,   432,    46,   433,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,     0,     0,    63,     0,    64,    65,    66,
     490,     0,     0,    70,    71,    72,     0,     0,     0,    74,
       0,     0,     0,     0,    76,    77,    78,     0,     0,    81,
      82,  1305,     0,     0,     0,     0,     0,    87,    88,    89,
      90,     0,    91,     0,     0,     0,   435,    93,    94,     0,
       0,     0,     0,     0,     0,     0,     0,    97,    98,    99,
       0,   101,   102,   973,     0,     0,     0,   974,     0,     0,
     107,   108,     0,     0,     0,     0,   109,   110,   111,   112,
     438,   114,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   122,     0,     0,     0,   123,     0,   124,   125,
       0,     0,     0,     0,     0,     0,   130,     0,   131,   132,
     133,   134,   439,   136,   137,   138,   139,   140,   141,     0,
       0,   975,   143,     0,     0,   440,   146,     0,   147,   148,
     149,   150,   151,   152,   153,   441,   155,   443,   157,   444,
     445,   160,   161,   162,   163,   164,   165,   446,   167,   447,
     448,   449,   450,   172,   173,   451,   452,   176,   453,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,   191,     0,   192,   193,   194,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     3,     0,     0,     0,     0,     0,     0,   414,
     415,     0,     7,     8,   416,    10,    11,    12,    13,   417,
     418,   419,   420,   421,   422,   423,   424,    22,   425,    24,
      25,     0,    26,    27,    28,    29,   426,    31,   427,    33,
      34,   428,    36,   429,    38,    39,   430,     0,    41,   431,
      43,     0,   432,    46,   433,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,     0,     0,
      63,     0,    64,    65,    66,   434,     0,     0,    70,    71,
      72,     0,     0,     0,    74,     0,     0,     0,     0,    76,
      77,    78,     0,     0,    81,    82,     0,     0,     0,     0,
       0,     0,    87,    88,    89,    90,     0,    91,     0,     0,
       0,   435,    93,    94,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,    99,     0,   101,   102,   103,   436,
       0,     0,   437,     0,     0,   107,   108,     0,     0,     0,
       0,   109,   110,   111,   112,   438,   114,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   122,     0,     0,
       0,   123,     0,   124,     0,     0,     0,     0,     0,     0,
       0,   130,     0,   131,   132,   133,   134,   439,   136,   137,
     138,   139,   140,   141,     0,     0,   142,   143,     0,     0,
     440,   146,     0,   147,   148,   149,   150,   151,   152,   153,
     441,   442,   443,   157,   444,   445,   160,   161,   162,   163,
     164,   165,   446,   167,   447,   448,   449,   450,   172,   173,
     451,   452,   176,   453,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   189,   190,   191,     0,
     192,   193,   194,   195,   196,   197,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,     3,     0,     0,
       0,     0,     0,     0,   414,   415,     0,     7,     8,   416,
      10,    11,    12,    13,   417,   418,   419,   420,   421,   422,
     423,   424,    22,   425,    24,    25,     0,    26,    27,    28,
      29,   426,    31,   427,    33,    34,   428,    36,   429,    38,
      39,   430,     0,    41,   431,    43,     0,   432,    46,   433,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,     0,     0,    63,     0,    64,    65,    66,
     434,     0,     0,    70,    71,    72,     0,     0,     0,    74,
       0,     0,     0,     0,    76,    77,    78,     0,     0,    81,
      82,     0,     0,     0,     0,     0,     0,    87,    88,    89,
      90,     0,    91,     0,     0,     0,   435,    93,    94,     0,
       0,     0,     0,     0,     0,     0,     0,    97,    98,    99,
       0,   101,   102,   103,   483,     0,     0,   484,     0,     0,
     107,   108,     0,     0,     0,     0,   109,   110,   111,   112,
     438,   114,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   122,     0,     0,     0,   123,     0,   124,     0,
       0,     0,     0,     0,     0,     0,   130,     0,   131,   132,
     133,   134,   439,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,     0,     0,   440,   146,     0,   147,   148,
     149,   150,   151,   152,   153,   441,   442,   443,   157,   444,
     445,   160,   161,   162,   163,   164,   165,   446,   167,   447,
     448,   449,   450,   172,   173,   451,   452,   176,   453,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,   191,     0,   192,   193,   194,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     3,     0,     0,     0,     0,     0,     0,   414,
     415,     0,     7,     8,   416,    10,    11,    12,    13,   417,
     418,   419,   420,   421,   422,   423,   424,    22,   425,    24,
      25,     0,    26,    27,    28,    29,   426,    31,   427,    33,
      34,   428,    36,   429,    38,    39,   430,     0,    41,   431,
      43,     0,   432,    46,   433,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,     0,     0,
      63,     0,    64,    65,    66,   434,     0,     0,    70,    71,
      72,     0,     0,     0,    74,     0,     0,     0,     0,    76,
      77,    78,     0,     0,    81,    82,     0,     0,     0,     0,
       0,     0,    87,    88,    89,    90,     0,    91,     0,     0,
       0,   435,    93,    94,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,    99,     0,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   107,   108,     0,     0,     0,
       0,   109,   110,   111,   112,   438,   114,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   122,     0,     0,
       0,   123,   667,   124,     0,     0,     0,     0,     0,   668,
       0,   130,     0,   131,   132,   133,   134,   439,   136,   137,
     138,   139,   140,   141,     0,     0,   142,   143,     0,     0,
     440,   146,     0,   147,   148,   149,   150,   151,   152,   153,
     441,   442,   443,   157,   444,   445,   160,   161,   162,   163,
     164,   165,   446,   167,   447,   448,   449,   450,   172,   173,
     451,   452,   176,   453,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   189,   190,   191,     0,
     192,   193,   194,   195,   196,   197,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,     3,     0,     0,
       0,     0,     0,     0,   414,   415,     0,     7,     8,   416,
      10,    11,    12,    13,   417,   418,   419,   420,   421,   422,
     423,   424,    22,   425,    24,    25,     0,    26,    27,    28,
      29,   426,    31,   427,    33,    34,   428,    36,   429,    38,
      39,   430,     0,    41,   431,    43,     0,   432,    46,   433,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,     0,     0,    63,     0,    64,    65,    66,
     434,     0,     0,    70,    71,    72,     0,     0,     0,    74,
       0,     0,     0,     0,    76,    77,    78,     0,     0,    81,
      82,     0,     0,     0,     0,     0,     0,    87,    88,    89,
      90,     0,    91,     0,     0,     0,   435,    93,    94,     0,
       0,     0,     0,     0,     0,     0,     0,    97,    98,    99,
       0,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     107,   108,     0,     0,     0,     0,   109,   110,   111,   112,
     438,   114,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   122,     0,     0,     0,   123,   713,   124,     0,
       0,     0,     0,     0,   714,     0,   130,     0,   131,   132,
     133,   134,   439,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,     0,     0,   440,   146,     0,   147,   148,
     149,   150,   151,   152,   153,   441,   442,   443,   157,   444,
     445,   160,   161,   162,   163,   164,   165,   446,   167,   447,
     448,   449,   450,   172,   173,   451,   452,   176,   453,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,   191,     0,   192,   193,   194,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     3,     0,     0,     0,     0,     0,     0,   414,
     415,     0,     7,     8,   486,    10,    11,    12,    13,   417,
      15,   487,   420,   421,   972,   423,   424,    22,   425,    24,
      25,     0,    26,    27,    28,    29,   426,    31,   488,    33,
      34,    35,    36,   429,    38,    39,   430,     0,    41,   489,
      43,     0,   432,    46,   433,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,     0,     0,
      63,     0,    64,    65,    66,   490,     0,     0,    70,    71,
      72,     0,     0,     0,    74,     0,     0,     0,     0,    76,
      77,    78,     0,     0,    81,    82,     0,     0,     0,     0,
       0,     0,    87,    88,    89,    90,     0,    91,     0,     0,
       0,   435,    93,    94,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,    99,     0,   101,   102,   973,     0,
       0,     0,   974,     0,     0,   107,   108,     0,     0,     0,
       0,   109,   110,   111,   112,   438,   114,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   122,     0,     0,
       0,   123,     0,   124,   125,     0,     0,     0,     0,     0,
       0,   130,     0,   131,   132,   133,   134,   439,   136,   137,
     138,   139,   140,   141,     0,     0,   975,   143,     0,     0,
     440,   146,     0,   147,   148,   149,   150,   151,   152,   153,
     441,   155,   443,   157,   444,   445,   160,   161,   162,   163,
     164,   165,   446,   167,   447,   448,   449,   450,   172,   173,
     451,   452,   176,   453,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   189,   190,   191,     0,
     192,   193,   194,   195,   196,   197,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,     3,     0,     0,
       0,     0,     0,     0,   414,   415,     0,     7,     8,   486,
      10,    11,    12,    13,   417,    15,   487,   420,   421,   972,
     423,   424,    22,   425,    24,    25,     0,    26,    27,    28,
      29,   426,    31,   488,    33,    34,    35,    36,   429,    38,
      39,   430,     0,    41,   489,    43,     0,   432,    46,   433,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,     0,     0,    63,     0,    64,    65,    66,
     490,     0,     0,    70,    71,    72,     0,     0,     0,    74,
       0,     0,     0,     0,    76,    77,    78,     0,     0,    81,
      82,     0,     0,     0,     0,     0,     0,    87,    88,    89,
      90,     0,    91,     0,     0,     0,   435,    93,    94,     0,
       0,     0,     0,     0,     0,     0,     0,    97,    98,    99,
       0,   101,   102,   973,     0,     0,     0,   974,     0,     0,
     107,   108,     0,     0,     0,     0,   109,   110,   111,   112,
     438,   114,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   122,     0,     0,     0,   123,     0,   124,   125,
       0,     0,     0,     0,     0,     0,   130,     0,   131,   132,
     133,   134,   439,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,     0,     0,   440,   146,     0,   147,   148,
     149,   150,   151,   152,   153,   441,   155,   443,   157,   444,
     445,   160,   161,   162,   163,   164,   165,   446,   167,   447,
     448,   449,   450,   172,   173,   451,   452,   176,   453,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,   191,     0,   192,   193,   194,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     3,     0,     0,     0,     0,     0,     0,   414,
     415,     0,     7,     8,   416,    10,    11,    12,    13,   417,
     418,   419,   420,   421,   422,   423,   424,    22,   425,    24,
      25,     0,    26,    27,    28,    29,   426,    31,   427,    33,
      34,   428,    36,   429,    38,    39,   430,     0,    41,   431,
      43,     0,   432,    46,   433,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,     0,     0,
      63,     0,    64,    65,    66,   434,     0,     0,    70,    71,
      72,     0,     0,     0,    74,     0,     0,     0,     0,    76,
      77,    78,     0,     0,    81,    82,     0,     0,     0,     0,
       0,     0,    87,    88,    89,    90,     0,    91,     0,     0,
       0,   435,    93,    94,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,    99,     0,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   107,   108,     0,     0,     0,
       0,   109,   110,   111,   112,   438,   114,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   122,     0,     0,
       0,   123,     0,   124,     0,     0,     0,     0,     0,     0,
       0,   130,     0,   131,   132,   133,   134,   439,   136,   137,
     138,   139,   140,   141,     0,     0,   142,   143,     0,     0,
     440,   146,     0,   147,   148,   149,   150,   151,   152,   153,
     441,   442,   443,   157,   444,   445,   160,   161,   162,   163,
     164,   165,   446,   167,   447,   448,   449,   450,   172,   173,
     451,   452,   176,   453,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   189,   190,   191,     0,
     192,   193,   194,   195,   196,   197,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        16,   537,   579,   793,   794,   310,   371,   580,   581,   582,
     583,   720,   779,   899,   762,   128,    32,   117,   791,   792,
     534,  1069,   996,   104,   934,   867,  1185,  1186,  1174,   691,
      69,    20,   619,   556,   779,  1332,    49,    88,  1261,   112,
       8,     9,  1236,   791,   792,  1147,    90,    21,     7,   139,
     826,    67,    88,    69,    37,     8,   559,    20,   561,   562,
      88,   564,   691,   566,    90,    88,    19,    83,   101,   101,
      94,   574,   575,   702,    57,   112,    20,   134,   826,    87,
     101,   101,    88,   134,    90,    90,   139,    47,   122,   105,
      50,   101,   101,   209,    37,    45,   956,    40,   463,   464,
     101,   117,   101,   119,   766,   101,   768,   101,   101,   125,
     158,    30,   112,   139,   862,   104,   889,    36,    37,   262,
     122,   256,   152,   161,    88,   173,   269,   116,   150,    97,
      73,   247,   267,   139,    94,    54,   279,   148,    57,   101,
     177,   889,    88,   148,   217,   167,    65,   115,    90,   117,
     182,    88,   141,   177,   188,   193,   145,   100,   178,   148,
     145,   182,   115,   107,   117,   101,   174,  1027,   190,   179,
     179,   121,    91,   126,   175,   139,   266,   145,   178,   168,
    1339,   149,   178,   182,   178,   178,   188,   210,   211,   152,
     455,    90,   145,   229,   227,   178,   209,   165,   974,   145,
     313,   229,   225,   832,  1398,   249,   250,   166,   152,   266,
      26,     8,     9,   266,  1316,   266,   178,   160,   186,   161,
    1106,   930,  1270,  1065,   811,   812,   974,   300,  1138,   996,
     997,   205,   123,   145,   247,    88,   204,  1147,  1212,    55,
     266,   903,   178,   508,   509,   768,   511,   512,   513,   514,
    1473,   996,   997,   882,     8,     9,   521,   522,  1555,   888,
     266,   180,   161,   252,   128,   101,   137,   213,   214,   285,
     535,   636,   775,   210,   211,  1572,    38,   148,   145,   318,
     545,   546,   321,  1580,   244,   145,   139,   387,   225,   145,
      25,   182,   148,  1439,     8,     9,   101,   257,   217,   259,
      97,   168,   318,   245,   246,   321,   248,    42,   168,   409,
     270,   271,   272,   255,   274,   101,   276,   148,   115,    94,
     117,    61,   687,   265,  1072,  1098,    66,   101,   192,   410,
     992,   412,   107,   136,    20,   277,   101,   100,   875,   101,
     877,   606,   178,    97,   609,   201,   245,   246,   145,   248,
    1098,  1124,   149,     4,  1402,   436,   119,     8,    90,   148,
     376,   115,   378,   117,   167,   112,   265,   383,   165,   469,
       4,   387,   112,   178,     8,   107,  1124,   393,   277,    33,
    1539,   462,   185,    97,   400,    39,   923,   468,   925,   186,
      44,   145,   178,   409,   475,   149,   477,   478,    52,   480,
      39,   115,   483,   117,   178,   150,  1316,   204,   150,     8,
      64,   165,   129,   178,   240,   241,   148,   498,   104,  1192,
      19,   437,   167,   504,   150,   167,    90,  1269,   145,    46,
     116,   145,   186,  1481,    94,   149,    53,   263,   217,   148,
     219,   167,   523,   107,  1192,  1212,   960,   107,   190,   465,
     204,   165,    88,   469,  1221,   141,   472,   473,   474,   145,
     140,  1509,   148,   479,   115,  1232,   117,  1212,   484,   112,
     835,   836,   186,    90,   125,   840,  1221,   157,   494,   140,
      90,   115,   168,   117,   148,   598,   599,  1232,    46,   129,
     204,   125,   757,   129,   145,    53,   157,   107,   134,   764,
     516,   256,   111,    46,   869,   145,   160,   112,   524,   163,
      53,   145,   267,    71,   595,    89,   115,   262,   117,   600,
    1568,    40,  1570,   177,   269,   148,   100,   126,  1414,   138,
    1490,  1491,    90,   261,   279,   129,   110,   148,  1586,    58,
     268,    60,   151,   128,   112,   119,   145,   124,   145,   203,
      69,   145,   207,   173,   112,   132,   133,   142,   135,   173,
     823,   145,  1522,   828,   148,   145,   143,   187,  1528,   834,
     147,   192,   149,   187,   837,   145,   185,   154,   148,   292,
     201,   183,   184,   683,   601,   148,   686,   604,   301,   670,
     607,   217,   217,   170,   270,   271,   272,   222,   129,   680,
     276,   129,   320,   134,   112,  1314,   134,   325,   624,  1318,
    1377,   627,   213,   214,   215,   631,   697,   194,   195,   196,
     197,   198,   199,   146,   217,   148,   219,   293,   294,   710,
     711,   375,  1377,   377,   145,   716,   901,   653,   654,   655,
     161,   224,   224,   226,   226,   910,  1223,   912,   913,   293,
     294,   120,   121,   284,   285,   120,   121,   235,   674,   234,
     676,   742,   577,   578,   929,   586,   587,   683,   584,   585,
     686,  1444,   193,  1446,   234,   940,   941,   942,   148,   944,
     945,   946,   947,   948,   949,   145,   951,   952,  1389,  1390,
     112,     0,   182,   998,   182,   159,  1444,    86,  1446,   964,
     242,   222,    43,   719,   191,    95,   146,    20,    96,    40,
      40,    40,   144,  1486,  1250,   112,   297,   239,  1427,   286,
    1510,  1430,   291,   988,   178,   990,   991,   291,  1501,   145,
     277,   277,   112,   145,   112,   145,  1101,   178,  1486,   755,
     145,   145,   145,   178,    27,    15,   762,   148,   148,   148,
     148,   178,  1017,  1501,   148,   205,    20,   178,    25,   280,
     281,   282,   283,   284,   223,   286,   287,   288,   289,   290,
    1035,   162,   112,   160,   295,   791,   792,   793,   794,   162,
     101,    65,    88,    88,   223,  1494,    88,   141,  1361,   101,
     101,  1368,  1369,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    20,   152,   152,   124,   292,   239,   119,
     826,   175,   175,   178,   175,   175,  1181,   124,  1083,   178,
      88,   178,    37,  1088,    90,    90,   842,   101,   178,   175,
     134,   145,   175,   178,   178,  1100,   178,   918,   175,   178,
     175,   175,   175,    88,   229,  1110,  1111,   217,   134,   175,
     178,   112,   112,   112,  1119,  1120,   112,   182,   175,   875,
     139,   877,   162,   134,    88,   134,   124,    20,   176,   292,
     279,   247,   145,   889,  1451,  1452,   175,   112,    88,   175,
     124,   219,   124,    28,    29,    90,    31,    32,   189,    34,
     152,   112,   145,   134,   112,    40,   139,   175,    94,    94,
     175,    27,    20,    48,   112,    50,    51,   923,   145,   925,
     112,   238,  1177,    58,   995,    60,   145,    73,   175,   101,
     175,   175,   101,  1188,    69,  1290,   148,  1504,    73,   148,
     139,   251,   148,   139,   253,   136,   260,    20,  1203,    20,
      20,  1206,   278,  1208,  1025,   178,   299,   279,   182,   229,
     178,   136,   968,   178,   112,   971,   219,   280,   974,   139,
     105,   106,   107,   112,   178,    71,   101,   219,   219,   985,
     134,   987,   175,   124,   178,     6,   225,   225,  1343,   178,
     177,   100,   182,   229,   134,   225,   225,   100,   178,   178,
     178,   139,   175,   243,   178,  1076,   243,   139,   275,    72,
     175,    20,    20,   279,    90,   162,   175,   152,   118,   175,
     177,    90,   177,   175,   250,  1280,   161,    88,   178,    20,
     175,  1286,   145,   175,   178,   101,   264,    88,   162,    46,
    1295,    88,  1113,    20,   112,   258,   101,    88,  1303,  1304,
     112,   273,   188,   217,   112,   177,   175,   188,   193,  1130,
     280,   188,   112,   177,   217,    87,   112,  1322,  1323,  1324,
    1325,  1326,   174,  1328,  1329,   112,   188,   212,   145,   112,
     190,   298,   298,  1089,   286,   178,   112,   222,   298,   217,
     241,   533,  1098,   635,   533,   244,   299,   280,   299,   827,
    1355,   238,  1108,  1031,   385,  1072,  1481,   241,  1509,  1170,
    1116,   299,   405,   890,   887,   461,   245,   284,  1124,   254,
     971,  1108,  1284,  1178,  1090,  1190,   964,  1185,  1188,   494,
     557,  1116,  1125,  1121,   558,   306,   609,  1528,  1144,   720,
    1522,  1138,   794,  1066,   877,   280,   281,   282,   283,   284,
    1030,   286,   287,   288,   289,   290,  1165,  1221,  1413,  1165,
     295,   296,  1232,  1418,  1377,   997,  1225,  1422,  1174,  1424,
    1175,  1374,  1178,  1006,   861,  1259,  1055,  1392,  1222,    -1,
      -1,    -1,    -1,    -1,   381,    -1,  1192,    -1,    -1,    -1,
      -1,    -1,   413,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   413,
      69,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1267,    -1,  1518,    -1,    -1,   105,   106,   107,    -1,
      -1,    -1,    -1,    -1,    -1,  1281,  1282,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1540,    -1,    -1,    -1,    -1,
    1545,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1305,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1315,
    1565,    -1,    -1,  1319,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,
    1461,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,    -1,  1423,    -1,    -1,
      -1,    -1,  1428,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1439,    -1,    -1,    -1,    -1,  1444,    -1,
    1446,   280,   281,   282,   283,   284,    -1,   286,   287,   288,
     289,   290,    -1,    -1,    -1,    -1,   295,   296,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1477,    -1,    -1,  1480,    -1,    -1,    -1,    -1,    -1,
    1486,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1497,    -1,    -1,    -1,  1501,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1510,    -1,  1512,    -1,    -1,    -1,
    1516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1542,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1560,    -1,  1562,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,  1575,
      -1,    17,    18,  1579,    20,    -1,    -1,    -1,  1584,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    -1,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    -1,    99,   100,    -1,    -1,    -1,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    -1,
     116,    -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,
      -1,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
      -1,    -1,   138,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,   148,   149,   150,   151,   152,    -1,    -1,    -1,
      -1,   157,   158,   159,   160,   161,   162,   163,   164,   165,
      -1,   167,   168,    -1,    -1,   171,   172,   173,    -1,    -1,
      -1,   177,    -1,   179,   180,   181,    -1,   183,   184,   185,
      -1,   187,    -1,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,    -1,   202,   203,   204,    -1,
     206,   207,    -1,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    -1,   252,   253,   254,    -1,
     256,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    -1,    99,   100,    -1,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    -1,   116,    -1,   118,   119,   120,   121,
      -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,
     142,   143,   144,    -1,    -1,    -1,   148,   149,   150,   151,
     152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,   167,   168,    -1,    -1,   171,
     172,   173,    -1,    -1,    -1,   177,   178,   179,   180,   181,
      -1,   183,   184,   185,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
     202,   203,   204,    -1,   206,   207,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
     252,   253,   254,    -1,   256,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    -1,    -1,
      99,   100,    -1,    -1,    -1,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    -1,   116,    -1,   118,
     119,   120,   121,    -1,   123,    -1,    -1,    -1,   127,   128,
     129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,   167,   168,
      -1,    -1,   171,   172,   173,    -1,   175,    -1,   177,    -1,
     179,   180,   181,    -1,   183,   184,   185,    -1,   187,    -1,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    -1,    -1,   202,   203,   204,    -1,   206,   207,    -1,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,    -1,   252,   253,   254,    -1,   256,   257,   258,
     259,   260,   261,    -1,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    -1,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    -1,    99,   100,    -1,    -1,    -1,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    -1,
     116,    -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,
      -1,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
      -1,    -1,   138,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,   148,   149,   150,   151,   152,    -1,    -1,    -1,
      -1,   157,   158,   159,   160,   161,   162,   163,   164,   165,
      -1,   167,   168,    -1,    -1,   171,   172,   173,    -1,    -1,
      -1,   177,   178,   179,   180,   181,    -1,   183,   184,   185,
      -1,   187,    -1,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,    -1,   202,   203,   204,    -1,
     206,   207,    -1,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    -1,   252,   253,   254,    -1,
     256,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    -1,    -1,    99,   100,    -1,    -1,
      -1,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    -1,   116,    -1,   118,   119,   120,   121,    -1,
     123,    -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,   167,   168,    -1,    -1,   171,   172,
     173,    -1,    -1,    -1,   177,   178,   179,   180,   181,    -1,
     183,   184,   185,    -1,   187,    -1,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,    -1,   202,
     203,   204,    -1,   206,   207,    -1,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,   252,
     253,   254,    -1,   256,   257,   258,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    -1,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    99,
     100,    -1,    -1,    -1,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,   116,    -1,   118,   119,
     120,   121,    -1,   123,    -1,    -1,    -1,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,   148,   149,
     150,   151,   152,    -1,    -1,    -1,    -1,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,   167,   168,    -1,
      -1,   171,   172,   173,    -1,   175,    -1,   177,    -1,   179,
     180,   181,    -1,   183,   184,   185,    -1,   187,    -1,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
      -1,    -1,   202,   203,   204,    -1,   206,   207,    -1,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,    -1,   252,   253,   254,    -1,   256,   257,   258,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      -1,    -1,    99,   100,    -1,    -1,    -1,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,   116,
      -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
     167,   168,    -1,    -1,   171,   172,   173,    -1,   175,    -1,
     177,    -1,   179,   180,   181,    -1,   183,   184,   185,    -1,
     187,    -1,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,   202,   203,   204,    -1,   206,
     207,    -1,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,   252,   253,   254,    -1,   256,
     257,   258,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    -1,    -1,    99,   100,    -1,    -1,    -1,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    -1,   116,    -1,   118,   119,   120,   121,    -1,   123,
      -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,   143,
     144,    -1,    -1,    -1,   148,   149,   150,   151,   152,    -1,
      -1,    -1,    -1,   157,   158,   159,   160,   161,   162,   163,
     164,   165,    -1,   167,   168,    -1,    -1,   171,   172,   173,
      -1,   175,    -1,   177,    -1,   179,   180,   181,    -1,   183,
     184,   185,    -1,   187,    -1,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,    -1,    -1,   202,   203,
     204,    -1,   206,   207,    -1,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,    -1,   252,   253,
     254,    -1,   256,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    -1,    -1,    99,   100,
      -1,    -1,    -1,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    -1,   116,    -1,   118,   119,   120,
     121,    -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,
     131,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,   167,   168,    -1,    -1,
     171,   172,   173,    -1,   175,    -1,   177,    -1,   179,   180,
     181,    -1,   183,   184,   185,    -1,   187,    -1,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,   202,   203,   204,    -1,   206,   207,    -1,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,   252,   253,   254,    -1,   256,   257,   258,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    -1,
      -1,    99,   100,    -1,    -1,    -1,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    -1,   116,    -1,
     118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   139,   140,   141,   142,   143,   144,    -1,    -1,    -1,
     148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,   167,
     168,    -1,    -1,   171,   172,   173,    -1,   175,    -1,   177,
      -1,   179,   180,   181,    -1,   183,   184,   185,    -1,   187,
      -1,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,    -1,    -1,   202,   203,   204,    -1,   206,   207,
      -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    -1,   252,   253,   254,    -1,   256,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    -1,    -1,    99,   100,    -1,    -1,    -1,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      -1,   116,    -1,   118,   119,   120,   121,    -1,   123,    -1,
      -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,   167,   168,    -1,    -1,   171,   172,   173,    -1,
     175,    -1,   177,    -1,   179,   180,   181,    -1,   183,   184,
     185,    -1,   187,    -1,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,    -1,   202,   203,   204,
      -1,   206,   207,    -1,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,   252,   253,   254,
      -1,   256,   257,   258,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    -1,    99,   100,    -1,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    -1,   116,    -1,   118,   119,   120,   121,
      -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,
     142,   143,   144,    -1,    -1,    -1,   148,   149,   150,   151,
     152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,   167,   168,    -1,    -1,   171,
     172,   173,    -1,    -1,    -1,   177,    -1,   179,   180,   181,
      -1,   183,   184,   185,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
     202,   203,   204,    -1,   206,   207,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
     252,   253,   254,    -1,   256,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    -1,    -1,
      99,   100,    -1,    -1,    -1,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    -1,   116,    -1,   118,
     119,   120,   121,    -1,   123,    -1,    -1,    -1,   127,   128,
     129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,   167,   168,
      -1,    -1,   171,   172,   173,    -1,    -1,    -1,   177,    -1,
     179,   180,   181,    -1,   183,   184,   185,    -1,   187,    -1,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    -1,    -1,   202,   203,   204,    -1,   206,   207,    -1,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,    -1,   252,   253,   254,    -1,   256,   257,   258,
     259,   260,   261,    -1,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    -1,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    -1,    99,   100,    -1,    -1,    -1,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    -1,
     116,    -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,
      -1,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
      -1,    -1,   138,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,   148,   149,   150,   151,   152,    -1,    -1,    -1,
      -1,   157,   158,   159,   160,   161,   162,   163,   164,   165,
      -1,   167,   168,    -1,    -1,   171,   172,   173,    -1,    -1,
      -1,   177,    -1,   179,   180,   181,    -1,   183,   184,   185,
      -1,   187,    -1,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,    -1,   202,   203,   204,    -1,
     206,   207,    -1,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    -1,   252,   253,   254,    -1,
     256,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    -1,    -1,    99,   100,    -1,    -1,
      -1,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    -1,   116,    -1,   118,   119,   120,   121,    -1,
     123,    -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,   167,   168,    -1,    -1,   171,   172,
     173,    -1,    -1,    -1,   177,    -1,   179,   180,   181,    -1,
     183,   184,   185,    -1,   187,    -1,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,    -1,   202,
     203,   204,    -1,   206,   207,    -1,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,   252,
     253,   254,    -1,   256,   257,   258,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    -1,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    99,
     100,    -1,    -1,    -1,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,   116,    -1,   118,   119,
     120,   121,    -1,   123,    -1,    -1,    -1,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,   148,   149,
     150,   151,   152,    -1,    -1,    -1,    -1,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,   167,   168,    -1,
      -1,   171,   172,   173,    -1,    -1,    -1,   177,    -1,   179,
     180,   181,    -1,   183,   184,   185,    -1,   187,    -1,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
      -1,    -1,   202,   203,   204,    -1,   206,   207,    -1,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,    -1,   252,   253,   254,    -1,   256,   257,   258,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      -1,    -1,    99,   100,    -1,    -1,    -1,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,   116,
      -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
     167,   168,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,
     177,    -1,   179,   180,   181,    -1,   183,   184,   185,    -1,
     187,    -1,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,   202,   203,   204,    -1,   206,
     207,    -1,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,   252,   253,   254,    -1,   256,
     257,   258,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    -1,    -1,    99,   100,    -1,    -1,    -1,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    -1,   116,    -1,   118,   119,   120,   121,    -1,   123,
      -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,   143,
     144,    -1,    -1,    -1,   148,   149,    -1,   151,   152,    -1,
      -1,    -1,    -1,   157,   158,   159,   160,   161,   162,   163,
     164,   165,    -1,    -1,    -1,    -1,    -1,   171,   172,   173,
      -1,    -1,    -1,   177,    -1,   179,   180,   181,    -1,   183,
     184,   185,    -1,   187,    -1,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,    -1,    -1,   202,   203,
     204,    -1,   206,   207,    -1,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,    -1,   252,   253,
     254,    -1,   256,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    -1,    -1,    99,   100,
      -1,    -1,    -1,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    -1,   116,    -1,   118,   119,   120,
     121,    -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,
     131,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,   148,   149,    -1,
     151,   152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,    -1,
     171,   172,   173,    -1,    -1,    -1,   177,    -1,   179,   180,
     181,    -1,    -1,    -1,   185,    -1,   187,    -1,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,   202,   203,   204,    -1,   206,   207,    -1,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,   252,   253,   254,    -1,   256,   257,   258,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    86,    -1,
      88,    89,    90,    91,    -1,    -1,    94,    95,    96,    -1,
      -1,    -1,   100,    -1,    -1,    -1,    -1,   105,   106,   107,
      -1,    -1,   110,   111,    -1,    -1,    -1,    -1,    -1,    -1,
     118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,   127,
     128,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   139,   140,    -1,   142,   143,   144,    -1,    -1,    -1,
      -1,    -1,    -1,   151,   152,    -1,    -1,    -1,    -1,   157,
     158,   159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   177,
      -1,   179,   180,    -1,    -1,    -1,    -1,   185,    -1,   187,
      -1,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,    -1,    -1,   202,   203,    -1,    -1,   206,   207,
      -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    -1,   252,   253,   254,    -1,   256,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    -1,
      -1,    86,    -1,    88,    89,    90,    91,    -1,    -1,    94,
      95,    96,    -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,
     105,   106,   107,    -1,    -1,   110,   111,    -1,    -1,    -1,
      -1,    -1,    -1,   118,   119,   120,   121,    -1,   123,    -1,
      -1,    -1,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,    -1,   142,   143,   144,
      -1,    -1,    -1,    -1,    -1,    -1,   151,   152,    -1,    -1,
      -1,    -1,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,   177,    -1,   179,    -1,    -1,    -1,    -1,    -1,
     185,    -1,   187,    -1,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,    -1,   202,   203,    -1,
      -1,   206,   207,    -1,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,   252,   253,   254,
      -1,   256,   257,   258,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    14,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      86,    -1,    88,    89,    90,    91,    -1,    -1,    94,    95,
      96,    -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,   105,
     106,   107,    -1,    -1,   110,   111,    -1,    -1,    -1,    -1,
      -1,    -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,
      -1,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,   139,   140,    -1,   142,   143,   144,   145,
      -1,    -1,   148,    -1,    -1,   151,   152,    -1,    -1,    -1,
      -1,   157,   158,   159,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,   177,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,    -1,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,    -1,   202,   203,    -1,    -1,
     206,   207,    -1,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    -1,   252,   253,   254,    -1,
     256,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,    14,    -1,    -1,
      -1,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    -1,    -1,    86,
      -1,    88,    89,    90,    91,    -1,    -1,    94,    95,    96,
      -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,   105,   106,
     107,    -1,    -1,   110,   111,    -1,    -1,    -1,    -1,    -1,
      -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,
     127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,    -1,   142,   143,   144,    -1,    -1,
      -1,    -1,    -1,    -1,   151,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,
     177,   178,   179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,    -1,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,   202,   203,    -1,    -1,   206,
     207,    -1,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,   252,   253,   254,    -1,   256,
     257,   258,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,    14,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    86,    -1,
      88,    89,    90,    91,    -1,    -1,    94,    95,    96,    -1,
      -1,    -1,   100,    -1,    -1,    -1,    -1,   105,   106,   107,
      -1,    -1,   110,   111,    -1,    -1,    -1,    -1,    -1,    -1,
     118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,   127,
     128,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   139,   140,    -1,   142,   143,   144,    -1,    -1,    -1,
      -1,    -1,    -1,   151,   152,    -1,    -1,    -1,    -1,   157,
     158,   159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   177,
      -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
      -1,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,    -1,    -1,   202,   203,    -1,    -1,   206,   207,
      -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    -1,   252,   253,   254,    -1,   256,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,    16,    -1,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    -1,    -1,    86,    -1,    88,    89,    90,
      91,    -1,    -1,    94,    95,    96,    -1,    -1,    -1,   100,
      -1,    -1,    -1,    -1,   105,   106,   107,    -1,    -1,   110,
     111,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,
     121,    -1,   123,    -1,    -1,    -1,   127,   128,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
      -1,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,
     151,   152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   177,    -1,   179,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,    -1,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,   202,   203,    -1,    -1,   206,   207,    -1,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,   252,   253,   254,    -1,   256,   257,   258,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      86,    -1,    88,    89,    90,    91,    -1,    -1,    94,    95,
      96,    -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,   105,
     106,   107,    -1,    -1,   110,   111,    -1,    -1,    -1,    -1,
      -1,    -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,
      -1,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,   139,   140,    -1,   142,   143,   144,    -1,
      -1,    -1,   148,    -1,    -1,   151,   152,    -1,    -1,    -1,
      -1,   157,   158,   159,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,   177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,
      -1,   187,    -1,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,    -1,   202,   203,    -1,    -1,
     206,   207,    -1,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    -1,   252,   253,   254,    -1,
     256,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    -1,    -1,    86,    -1,    88,    89,    90,
      91,    -1,    -1,    94,    95,    96,    -1,    -1,    -1,   100,
      -1,    -1,    -1,    -1,   105,   106,   107,    -1,    -1,   110,
     111,   112,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,
     121,    -1,   123,    -1,    -1,    -1,   127,   128,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
      -1,   142,   143,   144,    -1,    -1,    -1,   148,    -1,    -1,
     151,   152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   177,    -1,   179,   180,
      -1,    -1,    -1,    -1,    -1,    -1,   187,    -1,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,   202,   203,    -1,    -1,   206,   207,    -1,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,   252,   253,   254,    -1,   256,   257,   258,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      86,    -1,    88,    89,    90,    91,    -1,    -1,    94,    95,
      96,    -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,   105,
     106,   107,    -1,    -1,   110,   111,    -1,    -1,    -1,    -1,
      -1,    -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,
      -1,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,   139,   140,    -1,   142,   143,   144,   145,
      -1,    -1,   148,    -1,    -1,   151,   152,    -1,    -1,    -1,
      -1,   157,   158,   159,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,   177,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,    -1,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,    -1,   202,   203,    -1,    -1,
     206,   207,    -1,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    -1,   252,   253,   254,    -1,
     256,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    -1,    -1,    86,    -1,    88,    89,    90,
      91,    -1,    -1,    94,    95,    96,    -1,    -1,    -1,   100,
      -1,    -1,    -1,    -1,   105,   106,   107,    -1,    -1,   110,
     111,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,
     121,    -1,   123,    -1,    -1,    -1,   127,   128,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
      -1,   142,   143,   144,   145,    -1,    -1,   148,    -1,    -1,
     151,   152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   177,    -1,   179,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,    -1,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,   202,   203,    -1,    -1,   206,   207,    -1,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,   252,   253,   254,    -1,   256,   257,   258,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      86,    -1,    88,    89,    90,    91,    -1,    -1,    94,    95,
      96,    -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,   105,
     106,   107,    -1,    -1,   110,   111,    -1,    -1,    -1,    -1,
      -1,    -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,
      -1,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,   139,   140,    -1,   142,   143,   144,    -1,
      -1,    -1,    -1,    -1,    -1,   151,   152,    -1,    -1,    -1,
      -1,   157,   158,   159,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,   177,   178,   179,    -1,    -1,    -1,    -1,    -1,   185,
      -1,   187,    -1,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,    -1,   202,   203,    -1,    -1,
     206,   207,    -1,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    -1,   252,   253,   254,    -1,
     256,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    -1,    -1,    86,    -1,    88,    89,    90,
      91,    -1,    -1,    94,    95,    96,    -1,    -1,    -1,   100,
      -1,    -1,    -1,    -1,   105,   106,   107,    -1,    -1,   110,
     111,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,
     121,    -1,   123,    -1,    -1,    -1,   127,   128,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
      -1,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,
     151,   152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   177,   178,   179,    -1,
      -1,    -1,    -1,    -1,   185,    -1,   187,    -1,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,   202,   203,    -1,    -1,   206,   207,    -1,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,   252,   253,   254,    -1,   256,   257,   258,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      86,    -1,    88,    89,    90,    91,    -1,    -1,    94,    95,
      96,    -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,   105,
     106,   107,    -1,    -1,   110,   111,    -1,    -1,    -1,    -1,
      -1,    -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,
      -1,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,   139,   140,    -1,   142,   143,   144,    -1,
      -1,    -1,   148,    -1,    -1,   151,   152,    -1,    -1,    -1,
      -1,   157,   158,   159,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,   177,    -1,   179,   180,    -1,    -1,    -1,    -1,    -1,
      -1,   187,    -1,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,    -1,   202,   203,    -1,    -1,
     206,   207,    -1,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    -1,   252,   253,   254,    -1,
     256,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    -1,    -1,    86,    -1,    88,    89,    90,
      91,    -1,    -1,    94,    95,    96,    -1,    -1,    -1,   100,
      -1,    -1,    -1,    -1,   105,   106,   107,    -1,    -1,   110,
     111,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,
     121,    -1,   123,    -1,    -1,    -1,   127,   128,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
      -1,   142,   143,   144,    -1,    -1,    -1,   148,    -1,    -1,
     151,   152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   177,    -1,   179,   180,
      -1,    -1,    -1,    -1,    -1,    -1,   187,    -1,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,   202,   203,    -1,    -1,   206,   207,    -1,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,   252,   253,   254,    -1,   256,   257,   258,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      86,    -1,    88,    89,    90,    91,    -1,    -1,    94,    95,
      96,    -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,   105,
     106,   107,    -1,    -1,   110,   111,    -1,    -1,    -1,    -1,
      -1,    -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,
      -1,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,   139,   140,    -1,   142,   143,   144,    -1,
      -1,    -1,    -1,    -1,    -1,   151,   152,    -1,    -1,    -1,
      -1,   157,   158,   159,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,   177,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,    -1,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,    -1,   202,   203,    -1,    -1,
     206,   207,    -1,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    -1,   252,   253,   254,    -1,
     256,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302
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
      83,    84,    85,    86,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    99,   100,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   116,   118,   119,   120,
     121,   123,   127,   128,   129,   130,   131,   138,   139,   140,
     141,   142,   143,   144,   148,   149,   150,   151,   152,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   167,   168,
     171,   172,   173,   177,   179,   180,   181,   183,   184,   185,
     187,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   202,   203,   204,   206,   207,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   252,
     253,   254,   256,   257,   258,   259,   260,   261,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   348,   349,   354,   357,   360,   363,
     364,   366,   371,   372,   373,   374,   375,   384,   385,   387,
     388,   389,   394,   396,   398,   399,   400,   405,   426,   429,
     433,   436,   437,   438,   439,   441,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   487,   488,   489,   503,   504,
     506,   507,   508,   509,   510,   511,   512,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   532,   533,   534,
     535,   540,   541,   542,   543,   544,   545,   548,   554,   555,
     556,    28,    29,    31,    32,    34,    40,    48,    50,    51,
      58,    60,    69,    73,   105,   106,   107,   152,   161,   193,
     212,   222,   254,   280,   281,   282,   283,   284,   286,   287,
     288,   289,   290,   295,   296,   355,   356,   376,   377,   152,
     145,   148,   145,   148,    25,    26,    30,    35,    36,    37,
      38,    39,    40,    41,    42,    44,    52,    54,    57,    59,
      62,    65,    68,    70,    91,   127,   145,   148,   161,   193,
     206,   216,   217,   218,   220,   221,   228,   230,   231,   232,
     233,   236,   237,   239,   554,   145,    61,    66,   112,   391,
     148,   365,   148,    26,    55,   112,    39,    14,   145,   148,
     553,   554,   148,   112,   112,   145,   148,   148,   148,    88,
     145,   213,   214,   145,   148,   554,    30,    37,    54,    65,
      91,   471,   554,   554,   112,   178,   385,   554,   145,   553,
      16,   554,   554,   463,   145,    21,   205,   207,   217,   219,
     148,   217,   219,   217,   217,   222,   112,   145,   367,   234,
     234,   235,   148,   145,   112,   319,     0,   321,   322,    25,
      42,   324,   384,   182,   182,   101,   182,   386,    33,    39,
      44,    52,    64,   160,   163,   177,   203,   390,   395,   396,
     397,   414,   415,   419,   401,   402,   554,   159,    86,   124,
     132,   133,   135,   143,   147,   149,   154,   170,   194,   195,
     196,   197,   198,   199,   455,   456,   242,   150,   167,   190,
     111,   138,   151,   185,   192,   201,   128,   142,    43,   191,
      95,    96,   150,   167,   454,   145,   460,   463,   183,   184,
     146,   475,   476,   471,   475,   471,   148,   475,   137,   148,
      20,   552,   173,   187,   173,   187,   158,   173,   376,   554,
     376,   554,   161,   193,    40,   378,   377,    40,   379,   554,
     144,   112,   353,    37,    40,    73,   100,   160,   553,   213,
     214,   215,   293,   294,   239,   583,   554,   286,   554,   291,
     291,   293,   294,   297,   280,   288,   356,   553,   385,   178,
     385,    37,    57,   178,   528,   529,   385,   178,   185,   554,
     145,   388,   277,   277,   112,   409,   112,   178,   380,   381,
     145,   382,   385,   152,   552,   107,   152,   347,   552,   406,
     408,   554,   112,   385,    20,   178,   553,   145,   554,   554,
     427,   428,   554,   385,   178,   385,   385,   530,   554,   385,
     145,   145,   385,   178,   185,   554,   145,   427,   178,    27,
     491,   492,   493,   385,     7,   166,    15,   178,   385,   205,
      20,   388,   388,   178,   388,   388,   388,   388,   223,   546,
     547,   554,   368,   388,   388,   385,   407,   413,   554,   326,
     327,    25,   328,   388,   387,   112,   160,   162,   162,   388,
     388,   101,    88,    90,   139,   266,   403,   404,   514,   438,
     439,   441,   441,   441,   441,   440,   441,   441,   441,    65,
     445,   445,   444,   446,   446,   446,   446,   447,   447,   448,
     448,   223,    88,    88,    88,   175,   385,   463,   463,   385,
     476,   178,   388,   486,   141,   178,   486,   101,   101,   365,
      20,   554,   554,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,   330,   331,   332,    88,   129,   134,   350,
     351,   352,   554,   129,   134,   152,   152,   330,   552,   119,
     124,    47,    50,    94,   244,   257,   259,   270,   271,   272,
     274,   276,   584,   585,   586,   587,   588,   589,   596,   602,
     603,   239,    88,   229,   359,   292,   554,   554,   554,   124,
     175,   175,   178,   178,   175,   101,   178,   101,   178,   175,
     385,   175,   554,    49,   209,   247,   392,   393,   554,    88,
     101,   178,   385,   178,   553,    90,    37,   553,   552,    90,
     101,   134,   404,   514,   175,   178,   178,   175,   385,   178,
     134,   101,   179,   139,   514,   175,   178,   178,   145,   175,
     385,   385,   175,   101,   178,   101,   178,   175,   385,   179,
     554,   492,   493,   122,   188,   175,   175,   123,   182,    88,
     210,   211,   225,    88,   210,   211,   225,    88,   229,   217,
     101,   227,   134,    25,   369,   385,   178,   175,    38,   101,
     182,   107,   182,   554,   162,   388,   420,   421,   112,   416,
     417,   112,    40,   144,   148,   202,   515,   517,   519,   520,
     536,   537,   538,   539,   554,   112,   388,   112,   139,   404,
     139,   139,   403,   404,   441,   145,   148,   252,   459,   478,
     557,   560,   561,   562,   563,   564,   568,   570,   572,   573,
     515,   515,   513,   519,   513,   175,   176,   101,   178,   178,
     140,   157,   140,   157,   129,   145,   383,   365,   365,   331,
     124,   517,   352,   388,   514,   134,   388,   552,   552,   120,
     121,   552,   270,   271,   272,   276,   554,   256,   267,   256,
     267,    20,   279,    90,   107,   148,   590,   593,   584,    30,
      36,    54,    65,    91,   217,   358,   520,   284,   285,   219,
     292,   301,    88,   359,   292,   552,   145,   530,   531,   554,
     530,   531,   175,   139,   514,   247,    46,    53,    71,   112,
     403,   410,   411,   412,   393,   514,   515,   381,    88,   175,
     189,   124,   346,   552,   152,   124,    90,   346,   112,   388,
     134,   134,   404,   145,   175,   388,   112,   388,   388,   139,
      94,   430,   431,   432,    94,   434,   435,   385,   175,   175,
     145,   530,   530,   175,   388,    27,   493,   122,   188,     8,
       9,    97,   115,   117,   186,   382,   488,   490,   501,   502,
     505,    20,   224,   226,   388,   388,   388,   224,   226,   388,
     388,   388,   388,   388,   388,   112,   388,   388,   353,   370,
     101,   182,   175,   367,   238,   549,   550,   145,   112,   420,
      89,   100,   110,   119,   422,   423,   424,   425,   101,   554,
     101,   402,   148,   148,   517,   148,   136,   167,   185,   516,
     554,   554,   388,   139,   388,   388,   139,   404,   139,   385,
     557,   564,   145,   278,   442,   609,    90,   161,   245,   246,
     248,   255,   265,   277,   558,   559,   578,   579,   580,   581,
     604,   607,   251,   253,   565,   583,   260,   569,   605,   240,
     241,   263,   574,   575,   136,   388,   385,   129,   367,   129,
     145,   532,   351,   388,   279,    20,    90,   107,   148,   597,
      20,   590,   359,   516,   219,   219,   461,   280,   299,   358,
     219,   182,   175,   385,   178,   178,   136,   178,   178,   388,
     139,   112,   112,   388,   554,   412,    71,   515,   388,   552,
     101,   346,   408,   388,   388,   134,   175,   385,   428,   388,
     388,   107,   431,    94,   177,   112,   515,   107,   435,   175,
     175,   385,   178,   178,   124,   186,   490,     6,   554,   186,
     501,   182,   225,   225,   225,   225,   229,   547,   177,   134,
     370,   472,   551,   550,   388,   413,   552,   120,   121,   424,
     425,   425,   421,   100,   418,   417,   178,   185,   515,   518,
     178,   178,   178,   388,   388,   139,   388,   175,   178,   557,
     571,   243,   209,   247,   261,   268,   608,    90,   249,   250,
     606,   243,   561,   608,   444,   578,   562,   139,   275,   566,
     567,   606,   279,   577,    72,   576,   175,   387,    20,   128,
     192,   599,   600,   601,    20,   598,   599,   264,   594,   591,
     592,   593,   162,   554,   250,   359,   461,   175,   388,   554,
     554,   411,   388,   118,    90,   552,   388,   175,   177,   388,
     388,   554,   177,   112,   177,   175,   493,   554,   186,   493,
     554,   388,   388,   388,   388,   388,   388,   388,   148,   201,
     383,   175,   425,   552,    88,   178,   101,   178,   388,   175,
     446,    45,   121,   444,   444,   262,   269,   279,   582,   582,
     563,   145,   273,   175,   597,   597,   601,   101,   178,    20,
     595,   606,   178,   101,   361,   362,   461,   112,   217,   300,
     280,   162,    46,   388,   346,   388,    88,   388,   554,   388,
      87,   174,   494,   493,   554,   188,   493,   112,   472,   515,
     515,    88,   444,   444,   190,   385,    20,   258,   593,   101,
      88,   554,   112,   217,   554,   361,   112,   515,   177,     4,
     125,   497,   498,   500,   502,    19,   126,   495,   496,   499,
     502,   188,   493,   188,   554,   515,   444,   175,   362,   519,
     298,   554,   112,   217,   554,   177,   388,    87,   125,   500,
     174,   126,   499,   188,   101,   178,   425,   388,   298,   554,
     112,   388,   112,   383,   286,   298,   554,   554,   299,   388,
     299,   101,   178,   461,   461,   112,   383,   190,   554,   280,
     178,   554,   383,   217,   112,   554,   299,   461
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
     565,   566,   567,   568,   569,   570,   571
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   317,   318,   318,   319,   319,   319,   319,   320,   320,
     321,   321,   322,   322,   323,   324,   324,   324,   325,   325,
     326,   326,   327,   327,   327,   327,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   329,   329,   330,   330,   331,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     333,   333,   333,   333,   333,   333,   333,   333,   334,   334,
     335,   336,   336,   337,   337,   338,   339,   340,   340,   341,
     341,   342,   342,   342,   342,   343,   344,   345,   345,   345,
     345,   346,   346,   347,   347,   348,   348,   348,   348,   349,
     350,   350,   351,   351,   351,   352,   353,   353,   354,   354,
     354,   355,   355,   356,   356,   356,   356,   356,   356,   356,
     356,   356,   356,   356,   356,   356,   356,   357,   357,   357,
     357,   357,   357,   357,   357,   358,   358,   359,   359,   360,
     360,   361,   361,   362,   362,   363,   363,   363,   363,   364,
     364,   365,   365,   365,   365,   366,   367,   368,   368,   369,
     369,   370,   370,   371,   372,   373,   374,   374,   375,   375,
     375,   376,   376,   376,   376,   377,   377,   378,   378,   379,
     379,   380,   380,   381,   381,   382,   383,   384,   385,   385,
     386,   386,   387,   387,   388,   388,   388,   388,   388,   388,
     388,   388,   388,   388,   388,   388,   388,   388,   388,   388,
     388,   388,   389,   390,   391,   391,   392,   392,   392,   393,
     393,   394,   394,   395,   396,   396,   396,   397,   397,   397,
     397,   397,   398,   398,   399,   399,   400,   401,   401,   402,
     402,   402,   402,   402,   402,   402,   402,   403,   404,   405,
     406,   406,   407,   407,   408,   408,   408,   408,   409,   409,
     410,   410,   410,   411,   411,   411,   412,   412,   412,   413,
     414,   415,   416,   416,   417,   417,   418,   419,   419,   420,
     420,   421,   421,   422,   422,   422,   422,   422,   422,   422,
     423,   423,   424,   424,   425,   426,   426,   427,   427,   428,
     428,   429,   430,   430,   431,   432,   432,   433,   433,   434,
     434,   435,   435,   436,   437,   437,   438,   438,   439,   439,
     439,   439,   439,   440,   439,   439,   439,   439,   441,   441,
     442,   442,   443,   443,   444,   444,   444,   445,   445,   445,
     445,   445,   446,   446,   446,   447,   447,   447,   448,   448,
     449,   449,   450,   450,   451,   451,   452,   452,   453,   453,
     453,   453,   454,   454,   454,   455,   455,   455,   455,   455,
     455,   456,   456,   456,   457,   457,   457,   457,   458,   458,
     459,   459,   460,   460,   461,   461,   461,   461,   462,   463,
     463,   463,   464,   464,   465,   465,   465,   465,   466,   466,
     467,   467,   467,   467,   467,   467,   467,   468,   468,   469,
     469,   470,   470,   470,   470,   470,   471,   471,   472,   472,
     473,   473,   473,   474,   474,   474,   474,   475,   475,   476,
     477,   477,   477,   477,   477,   477,   477,   477,   477,   478,
     478,   479,   479,   479,   480,   481,   481,   482,   483,   484,
     485,   485,   486,   486,   487,   487,   488,   488,   488,   489,
     489,   489,   489,   489,   489,   490,   490,   491,   491,   492,
     493,   493,   494,   494,   495,   495,   496,   496,   496,   496,
     497,   497,   498,   498,   498,   498,   499,   499,   500,   500,
     501,   501,   501,   501,   502,   502,   502,   502,   503,   503,
     504,   504,   505,   506,   506,   506,   506,   506,   506,   507,
     508,   508,   508,   508,   509,   509,   509,   509,   510,   511,
     512,   512,   512,   512,   513,   513,   514,   515,   515,   515,
     516,   516,   516,   517,   517,   517,   517,   517,   518,   518,
     519,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     521,   522,   522,   522,   523,   524,   525,   525,   525,   526,
     526,   526,   526,   526,   527,   528,   528,   528,   528,   528,
     528,   528,   529,   530,   531,   532,   533,   533,   534,   535,
     536,   536,   537,   538,   538,   539,   540,   540,   540,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   542,
     542,   543,   543,   544,   545,   546,   546,   547,   548,   549,
     549,   550,   550,   550,   550,   551,   551,   552,   553,   553,
     554,   554,   555,   555,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   557,   558,   558,   559,
     559,   560,   560,   561,   561,   562,   562,   563,   563,   564,
     565,   565,   566,   566,   567,   568,   568,   568,   569,   569,
     570,   571,   571,   572,   573,   573,   574,   574,   575,   575,
     575,   576,   576,   577,   577,   578,   578,   578,   578,   578,
     579,   580,   581,   582,   582,   582,   583,   583,   584,   584,
     584,   584,   584,   584,   584,   584,   585,   585,   585,   585,
     586,   586,   587,   588,   588,   589,   589,   589,   590,   590,
     591,   591,   592,   592,   593,   594,   594,   595,   595,   596,
     596,   596,   597,   597,   598,   598,   599,   599,   600,   600,
     601,   601,   602,   603,   603,   604,   604,   604,   605,   606,
     606,   606,   606,   607,   607,   608,   608,   609
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
       2,     2,     2,     1,     2,     2,     2,     3,     4,     5,
       6,     4,     5,     6,     7,     1,     2,     3,     3,     8,
       9,     1,     3,     3,     4,    11,    14,    13,    22,     3,
       3,     2,     3,     4,     5,     2,     4,     3,     0,     3,
       2,     1,     3,     5,     3,     5,     2,     2,     2,     3,
       3,     1,     2,     2,     2,     4,     4,     4,     4,     6,
       4,     1,     3,     2,     3,     3,     3,     1,     1,     2,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     1,     1,     2,     4,
       3,     5,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     2,     1,     4,     3,
       4,     4,     5,     4,     5,     5,     6,     3,     3,     3,
       1,     4,     1,     4,     3,     4,     4,     5,     4,     5,
       1,     2,     3,     1,     2,     1,     6,     3,     3,     1,
       2,     3,     1,     3,     2,     3,     2,     3,     4,     1,
       3,     1,     2,     1,     1,     1,     2,     2,     2,     3,
       1,     1,     2,     2,     2,     5,     5,     1,     4,     3,
       4,     8,     1,     2,     3,     2,     3,     8,    10,     1,
       2,     4,     7,     8,     1,     3,     1,     3,     1,     3,
       3,     3,     3,     0,     4,     3,     3,     3,     1,     5,
       0,     1,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     4,
       1,     4,     1,     4,     1,     4,     1,     2,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     5,     5,     6,     3,     4,
       1,     2,     3,     2,     1,     2,     2,     1,     1,     1,
       3,     3,     1,     1,     1,     2,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     4,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     3,     1,     4,     4,
       3,     4,     1,     3,     1,     1,     1,     1,     1,     4,
       5,     8,     9,     9,    10,     1,     2,     1,     2,     6,
       0,     1,     3,     3,     0,     1,     1,     1,     2,     2,
       0,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     4,
       4,     5,     6,     7,     4,     5,     6,     7,     4,     4,
       4,     5,     6,     7,     1,     2,     2,     1,     2,     3,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     4,     4,     3,     3,     3,     4,     4,     3,
       4,     6,     4,     6,     3,     3,     4,     6,     6,     4,
       6,     6,     4,     1,     2,     1,     1,     1,     3,     3,
       1,     1,     4,     5,     6,     3,     3,     3,     3,     5,
       7,     7,     5,     5,     5,     7,     7,     5,     5,     3,
       3,     5,     7,     5,     7,     1,     4,     3,     5,     1,
       2,     3,     7,    10,    13,     1,     3,     1,     1,     1,
       1,     1,     7,     4,     1,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     2,     0,     1,     1,
       2,     1,     3,     1,     3,     1,     4,     1,     2,     3,
       0,     1,     0,     1,     4,     2,     3,     1,     0,     1,
       4,     0,     1,     2,     1,     3,     0,     1,     2,     2,
       1,     0,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     1,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       2,     2,     3,     1,     2,     2,     5,     2,     1,     1,
       0,     1,     1,     3,     4,     0,     2,     0,     2,     4,
       4,     3,     2,     3,     1,     3,     0,     1,     1,     2,
       2,     2,     2,     1,     2,     2,     2,     2,     3,     2,
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
  "\"'*:QName'\"", "\"'qualified name'\"", "\"'quote attribute content'\"",
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
  "\"'text'\"", "\"'tumbling'\"", "\"'switch'\"", "\"'typeswitch'\"",
  "\"'updating'\"", "\"'validate'\"", "\"'when'\"", "\"'word'\"",
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
  "\"'equality'\"", "\"'general'\"", "\"'integrity'\"", "\"'constraint'\"",
  "\"'check'\"", "\"'key'\"", "\"'foreach'\"", "\"'foreign'\"",
  "\"'keys'\"", "\"'BOM_UTF8'\"", "RANGE_REDUCE", "ADDITIVE_REDUCE",
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
  "SwitchExpr", "SwitchCaseClauseList", "SwitchCaseClause",
  "SwitchCaseOperandList", "TypeswitchExpr", "CaseClauseList",
  "CaseClause", "IfExpr", "OrExpr", "AndExpr", "ComparisonExpr", "$@1",
  "FTContainsExpr", "opt_FTIgnoreOption", "RangeExpr", "AdditiveExpr",
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
       318,     0,    -1,   319,    -1,   303,   319,    -1,   321,    -1,
     320,   321,    -1,   322,    -1,   320,   322,    -1,   206,   207,
      20,   182,    -1,   206,   207,    20,   123,    20,   182,    -1,
     324,   384,    -1,   384,    -1,   323,    -1,   323,   324,    -1,
      26,   152,   553,   124,   552,   182,    -1,   325,   182,    -1,
     326,   182,    -1,   325,   182,   326,   182,    -1,   327,    -1,
     325,   182,   327,    -1,   328,    -1,   326,   182,   328,    -1,
     333,    -1,   334,    -1,   335,    -1,   337,    -1,   354,    -1,
     357,    -1,   349,    -1,   329,    -1,   339,    -1,   375,    -1,
     360,    -1,   363,    -1,   338,    -1,    25,   107,    73,   330,
      -1,    25,    73,   554,   330,    -1,   331,    -1,   330,   331,
      -1,   332,   124,   532,    -1,    74,    -1,    82,    -1,    75,
      -1,    76,    -1,    77,    -1,    78,    -1,    83,    -1,    79,
      -1,    80,    -1,    81,    -1,   336,    -1,   343,    -1,   344,
      -1,   364,    -1,   340,    -1,   341,    -1,   342,    -1,   540,
      -1,   345,    -1,   348,    -1,    25,   152,   553,   124,   552,
      -1,    25,    29,   173,    -1,    25,    29,   187,    -1,    25,
     107,    37,   152,   552,    -1,    25,   107,    40,   152,   552,
      -1,    25,    50,   554,    20,    -1,    25,   254,   583,    -1,
      25,    51,   161,    -1,    25,    51,   193,    -1,    25,   107,
     160,   119,   120,    -1,    25,   107,   160,   119,   121,    -1,
      25,    32,   173,   101,   140,    -1,    25,    32,   173,   101,
     157,    -1,    25,    32,   158,   101,   140,    -1,    25,    32,
     158,   101,   157,    -1,    25,   107,   100,   552,    -1,    25,
      28,   552,    -1,    42,    55,   552,    -1,    42,    55,   347,
     552,    -1,    42,    55,   552,    90,   346,    -1,    42,    55,
     347,   552,    90,   346,    -1,   552,    -1,   346,   101,   552,
      -1,   152,   553,   124,    -1,   107,    37,   152,    -1,    42,
      26,   552,    -1,    42,    26,   152,   553,   124,   552,    -1,
      42,    26,   552,    90,   346,    -1,    42,    26,   152,   553,
     124,   552,    90,   346,    -1,    25,   105,   144,   350,    -1,
      88,   517,   351,    -1,   351,    -1,   352,    -1,   129,    -1,
     129,   352,    -1,   134,   388,    -1,   112,   554,    -1,   112,
     554,   514,    -1,    25,   106,   353,   134,   388,    -1,    25,
     106,   353,   129,    -1,    25,   106,   353,   129,   134,   388,
      -1,   356,    -1,   355,   356,    -1,   281,    -1,   282,    -1,
     283,    -1,   284,    -1,   161,    -1,   193,    -1,   222,   294,
      -1,   222,   293,    -1,   295,   294,    -1,   295,   293,    -1,
     286,    -1,   287,   286,    -1,   290,   291,    -1,   289,   291,
      -1,    25,   280,   554,    -1,    25,   280,   554,   359,    -1,
      25,   280,   554,    88,   358,    -1,    25,   280,   554,    88,
     358,   359,    -1,    25,   355,   280,   554,    -1,    25,   355,
     280,   554,   359,    -1,    25,   355,   280,   554,    88,   358,
      -1,    25,   355,   280,   554,    88,   358,   359,    -1,   520,
      -1,   520,   516,    -1,   229,   285,   219,    -1,   229,   284,
     219,    -1,    25,   288,   554,   292,   219,   461,   162,   361,
      -1,    25,   355,   288,   554,   292,   219,   461,   162,   361,
      -1,   362,    -1,   361,   101,   362,    -1,   461,    88,   519,
      -1,   461,    88,   519,   425,    -1,    25,   296,   297,   554,
     292,   280,   554,   112,   554,   298,   388,    -1,    25,   296,
     297,   554,   292,   280,   554,   217,   112,   554,   298,   286,
     299,   461,    -1,    25,   296,   297,   554,   292,   280,   554,
     300,   217,   112,   554,   298,   388,    -1,    25,   296,   297,
     554,   301,   299,   250,   280,   554,   217,   112,   554,   299,
     461,   190,   280,   554,   217,   112,   554,   299,   461,    -1,
      25,    31,   173,    -1,    25,    31,   187,    -1,   148,   178,
      -1,   148,   380,   178,    -1,   148,   178,    88,   515,    -1,
     148,   380,   178,    88,   515,    -1,   230,   367,    -1,   145,
     368,   385,   175,    -1,   368,   369,   182,    -1,    -1,   369,
     101,   370,    -1,    25,   370,    -1,   353,    -1,   353,   134,
     388,    -1,    59,   112,   554,   134,   388,    -1,   233,   235,
     388,    -1,   236,   148,   388,   178,   367,    -1,   231,   234,
      -1,   232,   234,    -1,    25,   376,    -1,    25,    48,   376,
      -1,    25,    34,   376,    -1,   377,    -1,    60,   377,    -1,
      69,   379,    -1,    58,   378,    -1,    40,   554,   365,   383,
      -1,    40,   554,   365,   129,    -1,    40,   554,   365,   367,
      -1,    40,   554,   365,   129,    -1,    40,   554,   365,   145,
     387,   175,    -1,    40,   554,   365,   129,    -1,   381,    -1,
     380,   101,   381,    -1,   112,   554,    -1,   112,   554,   514,
      -1,   145,   385,   175,    -1,   145,   385,   175,    -1,   385,
      -1,   387,    -1,   387,   386,    -1,   182,    -1,   386,   387,
     182,    -1,   388,    -1,   387,   101,   388,    -1,   389,    -1,
     426,    -1,   429,    -1,   433,    -1,   436,    -1,   437,    -1,
     541,    -1,   542,    -1,   544,    -1,   543,    -1,   545,    -1,
     548,    -1,   555,    -1,   372,    -1,   373,    -1,   374,    -1,
     371,    -1,   366,    -1,   398,   390,    -1,   177,   388,    -1,
      61,   277,    -1,    66,   277,    -1,   209,    -1,   247,    -1,
      49,   247,    -1,   392,   410,    71,   388,    -1,   392,    71,
     388,    -1,    39,   391,   409,   393,   393,    -1,    39,   391,
     409,   393,    -1,    33,   112,   554,    -1,   400,    -1,   405,
      -1,   394,    -1,   396,    -1,   414,    -1,   419,    -1,   415,
      -1,   395,    -1,   396,    -1,   398,   397,    -1,    39,   112,
      -1,    52,    39,   112,    -1,   399,   401,    -1,   402,    -1,
     401,   101,   112,   402,    -1,   554,   139,   388,    -1,   554,
     514,   139,   388,    -1,   554,   403,   139,   388,    -1,   554,
     514,   403,   139,   388,    -1,   554,   404,   139,   388,    -1,
     554,   514,   404,   139,   388,    -1,   554,   403,   404,   139,
     388,    -1,   554,   514,   403,   404,   139,   388,    -1,    90,
     112,   554,    -1,   266,   112,   554,    -1,    44,   112,   406,
      -1,   408,    -1,   406,   101,   112,   408,    -1,   413,    -1,
     407,   101,   112,   413,    -1,   554,   134,   388,    -1,   554,
     514,   134,   388,    -1,   554,   404,   134,   388,    -1,   554,
     514,   404,   134,   388,    -1,   112,   554,   139,   388,    -1,
     112,   554,   514,   139,   388,    -1,   411,    -1,   112,   554,
      -1,   112,   554,   411,    -1,   403,    -1,   403,   412,    -1,
     412,    -1,    53,   112,   554,    46,   112,   554,    -1,    46,
     112,   554,    -1,    53,   112,   554,    -1,   554,    -1,   203,
     388,    -1,   163,   162,   416,    -1,   417,    -1,   416,   101,
     417,    -1,   112,   554,    -1,   112,   554,   418,    -1,   100,
     552,    -1,   160,   162,   420,    -1,    64,   160,   162,   420,
      -1,   421,    -1,   420,   101,   421,    -1,   388,    -1,   388,
     422,    -1,   423,    -1,   424,    -1,   425,    -1,   423,   424,
      -1,   423,   425,    -1,   424,   425,    -1,   423,   424,   425,
      -1,    89,    -1,   110,    -1,   119,   120,    -1,   119,   121,
      -1,   100,   552,    -1,    62,   112,   427,   179,   388,    -1,
     127,   112,   427,   179,   388,    -1,   428,    -1,   427,   101,
     112,   428,    -1,   554,   139,   388,    -1,   554,   514,   139,
     388,    -1,    67,   148,   385,   178,   430,   107,   177,   388,
      -1,   431,    -1,   430,   431,    -1,   432,   177,   388,    -1,
      94,   388,    -1,   432,    94,   388,    -1,    68,   148,   385,
     178,   434,   107,   177,   388,    -1,    68,   148,   385,   178,
     434,   107,   112,   554,   177,   388,    -1,   435,    -1,   434,
     435,    -1,    94,   515,   177,   388,    -1,    94,   112,   554,
      88,   515,   177,   388,    -1,    41,   148,   385,   178,   189,
     388,   118,   388,    -1,   438,    -1,   437,   159,   438,    -1,
     439,    -1,   438,    86,   439,    -1,   441,    -1,   441,   455,
     441,    -1,   441,   456,   441,    -1,   441,   124,   441,    -1,
     441,   154,   441,    -1,    -1,   441,   149,   440,   441,    -1,
     441,   147,   441,    -1,   441,   135,   441,    -1,   441,   133,
     441,    -1,   443,    -1,   443,   242,    65,   557,   442,    -1,
      -1,   609,    -1,   444,    -1,   444,   190,   444,    -1,   445,
      -1,   444,   167,   445,    -1,   444,   150,   445,    -1,   446,
      -1,   445,   185,   446,    -1,   445,   111,   446,    -1,   445,
     138,   446,    -1,   445,   151,   446,    -1,   447,    -1,   446,
     192,   447,    -1,   446,   201,   447,    -1,   448,    -1,   447,
     142,   448,    -1,   447,   128,   448,    -1,   449,    -1,   449,
      43,   223,   515,    -1,   450,    -1,   450,   191,    88,   515,
      -1,   451,    -1,   451,    95,    88,   513,    -1,   452,    -1,
     452,    96,    88,   513,    -1,   454,    -1,   453,   454,    -1,
     167,    -1,   150,    -1,   453,   167,    -1,   453,   150,    -1,
     457,    -1,   461,    -1,   458,    -1,   194,    -1,   199,    -1,
     198,    -1,   197,    -1,   196,    -1,   195,    -1,   143,    -1,
     170,    -1,   132,    -1,    70,   145,   385,   175,    -1,    70,
     214,   145,   385,   175,    -1,    70,   213,   145,   385,   175,
      -1,    70,    88,   530,   145,   385,   175,    -1,   459,   145,
     175,    -1,   459,   145,   385,   175,    -1,   460,    -1,   459,
     460,    -1,   168,   554,    15,    -1,   168,    16,    -1,   462,
      -1,   462,   463,    -1,   184,   463,    -1,   463,    -1,   183,
      -1,   464,    -1,   464,   183,   463,    -1,   464,   184,   463,
      -1,   465,    -1,   474,    -1,   466,    -1,   466,   475,    -1,
     469,    -1,   469,   475,    -1,   467,   471,    -1,   468,    -1,
      99,    -1,   108,    -1,    92,    -1,   181,    -1,   109,    -1,
     131,    -1,   130,    -1,   471,    -1,    93,   471,    -1,   470,
     471,    -1,   114,    -1,   164,    -1,    84,    -1,   172,    -1,
     171,    -1,    85,    -1,   520,    -1,   472,    -1,   554,    -1,
     473,    -1,   185,    -1,    10,    -1,    17,    -1,   477,    -1,
     474,   475,    -1,   474,   148,   178,    -1,   474,   148,   486,
     178,    -1,   476,    -1,   475,   476,    -1,   146,   385,   176,
      -1,   478,    -1,   480,    -1,   481,    -1,   482,    -1,   485,
      -1,   487,    -1,   483,    -1,   484,    -1,   533,    -1,   479,
      -1,   532,    -1,   104,    -1,   141,    -1,   116,    -1,   112,
     554,    -1,   148,   178,    -1,   148,   385,   178,    -1,   113,
      -1,   161,   145,   385,   175,    -1,   193,   145,   385,   175,
      -1,   554,   148,   178,    -1,   554,   148,   486,   178,    -1,
     388,    -1,   486,   101,   388,    -1,   488,    -1,   506,    -1,
     489,    -1,   503,    -1,   504,    -1,   149,   554,   493,   122,
      -1,   149,   554,   491,   493,   122,    -1,   149,   554,   493,
     188,   186,   554,   493,   188,    -1,   149,   554,   493,   188,
     490,   186,   554,   493,   188,    -1,   149,   554,   491,   493,
     188,   186,   554,   493,   188,    -1,   149,   554,   491,   493,
     188,   490,   186,   554,   493,   188,    -1,   501,    -1,   490,
     501,    -1,   492,    -1,   491,   492,    -1,    27,   554,   493,
     124,   493,   494,    -1,    -1,    27,    -1,   174,   495,   174,
      -1,    87,   497,    87,    -1,    -1,   496,    -1,   126,    -1,
     499,    -1,   496,   126,    -1,   496,   499,    -1,    -1,   498,
      -1,   125,    -1,   500,    -1,   498,   125,    -1,   498,   500,
      -1,    19,    -1,   502,    -1,     4,    -1,   502,    -1,   488,
      -1,     9,    -1,   505,    -1,   502,    -1,     8,    -1,   115,
      -1,   117,    -1,   382,    -1,   204,    21,   205,    -1,   204,
     205,    -1,   165,   553,   166,    -1,   165,   553,     7,    -1,
      97,     6,    -1,   507,    -1,   508,    -1,   509,    -1,   510,
      -1,   511,    -1,   512,    -1,    35,   145,   385,   175,    -1,
      37,   554,   145,   175,    -1,    37,   554,   145,   385,   175,
      -1,    37,   145,   385,   175,   145,   175,    -1,    37,   145,
     385,   175,   145,   385,   175,    -1,    91,   554,   145,   175,
      -1,    91,   554,   145,   385,   175,    -1,    91,   145,   385,
     175,   145,   175,    -1,    91,   145,   385,   175,   145,   385,
     175,    -1,    65,   145,   385,   175,    -1,    30,   145,   385,
     175,    -1,    54,   553,   145,   175,    -1,    54,   553,   145,
     385,   175,    -1,    54,   145,   385,   175,   145,   175,    -1,
      54,   145,   385,   175,   145,   385,   175,    -1,   519,    -1,
     519,   136,    -1,    88,   515,    -1,   517,    -1,   517,   516,
      -1,   202,   148,   178,    -1,   136,    -1,   185,    -1,   167,
      -1,   519,    -1,   520,    -1,   144,   148,   178,    -1,   536,
      -1,   539,    -1,   515,    -1,   518,   101,   515,    -1,   554,
      -1,   522,    -1,   528,    -1,   526,    -1,   529,    -1,   527,
      -1,   525,    -1,   524,    -1,   523,    -1,   521,    -1,   217,
     148,   178,    -1,    36,   148,   178,    -1,    36,   148,   528,
     178,    -1,    36,   148,   529,   178,    -1,    65,   148,   178,
      -1,    30,   148,   178,    -1,    54,   148,   178,    -1,    54,
     148,   553,   178,    -1,    54,   148,    20,   178,    -1,    91,
     148,   178,    -1,    91,   148,   554,   178,    -1,    91,   148,
     554,   101,   530,   178,    -1,    91,   148,   185,   178,    -1,
      91,   148,   185,   101,   530,   178,    -1,   180,   554,   178,
      -1,    37,   148,   178,    -1,    37,   148,   554,   178,    -1,
      37,   148,   554,   101,   530,   178,    -1,    37,   148,   554,
     101,   531,   178,    -1,    37,   148,   185,   178,    -1,    37,
     148,   185,   101,   530,   178,    -1,    37,   148,   185,   101,
     531,   178,    -1,    57,   148,   554,   178,    -1,   554,    -1,
     554,   136,    -1,    20,    -1,   534,    -1,   535,    -1,   554,
     137,   141,    -1,    40,   365,   382,    -1,   537,    -1,   538,
      -1,    40,   148,   185,   178,    -1,    40,   148,   178,    88,
     515,    -1,    40,   148,   518,   178,    88,   515,    -1,   148,
     517,   178,    -1,    25,   212,   213,    -1,    25,   212,   214,
      -1,    25,   212,   215,    -1,   218,   217,   388,   225,   388,
      -1,   218,   217,   388,    88,   224,   225,   388,    -1,   218,
     217,   388,    88,   226,   225,   388,    -1,   218,   217,   388,
     210,   388,    -1,   218,   217,   388,   211,   388,    -1,   218,
     219,   388,   225,   388,    -1,   218,   219,   388,    88,   224,
     225,   388,    -1,   218,   219,   388,    88,   226,   225,   388,
      -1,   218,   219,   388,   210,   388,    -1,   218,   219,   388,
     211,   388,    -1,   216,   217,   388,    -1,   216,   219,   388,
      -1,   221,   217,   388,   229,   388,    -1,   221,   222,   223,
     217,   388,   229,   388,    -1,   220,   217,   388,    88,   388,
      -1,   228,   112,   546,   227,   388,   177,   388,    -1,   547,
      -1,   546,   101,   112,   547,    -1,   554,   134,   388,    -1,
     237,   145,   385,   175,   549,    -1,   550,    -1,   549,   550,
      -1,   238,   551,   383,    -1,   238,   551,   148,   112,   554,
     178,   383,    -1,   238,   551,   148,   112,   554,   101,   112,
     554,   178,   383,    -1,   238,   551,   148,   112,   554,   101,
     112,   554,   101,   112,   554,   178,   383,    -1,   472,    -1,
     551,   201,   472,    -1,    20,    -1,    14,    -1,   554,    -1,
      18,    -1,   556,    -1,   239,   112,   407,    38,   145,   388,
     175,    -1,    38,   145,   388,   175,    -1,   206,    -1,   119,
      -1,    91,    -1,    30,    -1,    36,    -1,    37,    -1,   144,
      -1,    41,    -1,   217,    -1,    54,    -1,    56,    -1,    57,
      -1,    65,    -1,    68,    -1,   202,    -1,    29,    -1,   254,
      -1,    28,    -1,   214,    -1,   213,    -1,   138,    -1,    35,
      -1,   252,    -1,   253,    -1,   267,    -1,   256,    -1,   244,
      -1,   278,    -1,   270,    -1,   272,    -1,   271,    -1,   276,
      -1,   248,    -1,   243,    -1,    72,    -1,   209,    -1,   247,
      -1,    45,    -1,   215,    -1,   228,    -1,   295,    -1,   222,
      -1,   194,    -1,   199,    -1,   198,    -1,   197,    -1,   196,
      -1,   195,    -1,    90,    -1,   105,    -1,   106,    -1,   177,
      -1,    39,    -1,    52,    -1,    61,    -1,    66,    -1,    53,
      -1,    46,    -1,    49,    -1,    71,    -1,    33,    -1,   139,
      -1,    44,    -1,   203,    -1,   162,    -1,   163,    -1,   160,
      -1,    64,    -1,    89,    -1,   110,    -1,   120,    -1,   121,
      -1,   100,    -1,    62,    -1,   127,    -1,   179,    -1,    94,
      -1,    88,    -1,   189,    -1,   118,    -1,   159,    -1,    86,
      -1,    43,    -1,   223,    -1,    95,    -1,   190,    -1,   111,
      -1,   151,    -1,   192,    -1,   142,    -1,   128,    -1,    70,
      -1,    96,    -1,   191,    -1,   143,    -1,   173,    -1,   187,
      -1,   152,    -1,   129,    -1,   123,    -1,   158,    -1,   140,
      -1,   157,    -1,    25,    -1,    31,    -1,    51,    -1,   107,
      -1,    32,    -1,    50,    -1,   207,    -1,    42,    -1,    55,
      -1,    26,    -1,    40,    -1,   266,    -1,   242,    -1,   275,
      -1,   277,    -1,   246,    -1,   260,    -1,   273,    -1,   265,
      -1,   245,    -1,   259,    -1,   274,    -1,   264,    -1,   258,
      -1,   257,    -1,   241,    -1,   240,    -1,   263,    -1,   249,
      -1,   250,    -1,   279,    -1,   269,    -1,   268,    -1,   261,
      -1,   221,    -1,   227,    -1,   224,    -1,   218,    -1,   211,
      -1,   210,    -1,   212,    -1,   229,    -1,   219,    -1,   220,
      -1,   226,    -1,   216,    -1,   225,    -1,    60,    -1,    58,
      -1,    69,    -1,    34,    -1,    48,    -1,   161,    -1,   193,
      -1,   235,    -1,   230,    -1,   233,    -1,   234,    -1,   236,
      -1,   231,    -1,   232,    -1,   237,    -1,   238,    -1,    38,
      -1,   239,    -1,    59,    -1,   288,    -1,   286,    -1,   287,
      -1,   292,    -1,   293,    -1,   294,    -1,   289,    -1,   290,
      -1,   291,    -1,    73,    -1,    74,    -1,    75,    -1,    76,
      -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,    81,
      -1,    82,    -1,    83,    -1,   280,    -1,   281,    -1,   282,
      -1,   283,    -1,   284,    -1,   285,    -1,   296,    -1,   297,
      -1,   298,    -1,   299,    -1,   300,    -1,   301,    -1,   302,
      -1,   560,   558,    -1,    -1,   559,    -1,   578,    -1,   559,
     578,    -1,   561,    -1,   560,   255,   561,    -1,   562,    -1,
     561,   251,   562,    -1,   563,    -1,   562,   253,   139,   563,
      -1,   564,    -1,   252,   564,    -1,   568,   565,   566,    -1,
      -1,   583,    -1,    -1,   567,    -1,   275,   145,   385,   175,
      -1,   572,   569,    -1,   148,   557,   178,    -1,   570,    -1,
      -1,   605,    -1,   459,   145,   571,   175,    -1,    -1,   557,
      -1,   573,   574,    -1,   478,    -1,   145,   385,   175,    -1,
      -1,   575,    -1,   241,   576,    -1,   240,   577,    -1,   263,
      -1,    -1,    72,    -1,    -1,   279,    -1,   579,    -1,   580,
      -1,   581,    -1,   607,    -1,   604,    -1,   161,    -1,   277,
     444,   582,    -1,   246,   606,   582,    -1,   279,    -1,   269,
      -1,   262,    -1,   239,   584,    -1,   583,   239,   584,    -1,
     585,    -1,   586,    -1,   587,    -1,   602,    -1,   588,    -1,
     596,    -1,   589,    -1,   603,    -1,    94,   267,    -1,    94,
     256,    -1,   259,    -1,   274,    -1,   244,   267,    -1,   244,
     256,    -1,    50,   554,    20,    -1,   270,    -1,    47,   270,
      -1,   272,   590,    -1,   272,   148,   590,   591,   178,    -1,
      47,   272,    -1,   593,    -1,   107,    -1,    -1,   592,    -1,
     593,    -1,   592,   101,   593,    -1,    90,    20,   594,   595,
      -1,    -1,   264,    20,    -1,    -1,   606,   258,    -1,   271,
     279,   597,   599,    -1,   271,   279,   107,   599,    -1,    47,
     271,   279,    -1,    90,    20,    -1,   148,   598,   178,    -1,
      20,    -1,   598,   101,    20,    -1,    -1,   600,    -1,   601,
      -1,   600,   601,    -1,   192,   597,    -1,   128,   597,    -1,
     257,    20,    -1,   276,    -1,    47,   276,    -1,    90,   209,
      -1,    90,   247,    -1,   248,   243,    -1,   260,   606,   273,
      -1,   249,   444,    -1,    90,   121,   444,    -1,    90,    45,
     444,    -1,   250,   444,   190,   444,    -1,   265,   608,    -1,
     245,   608,    -1,   268,    -1,   261,    -1,   278,   243,   446,
      -1
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
     371,   374,   377,   380,   382,   385,   388,   391,   395,   400,
     406,   413,   418,   424,   431,   439,   441,   444,   448,   452,
     461,   471,   473,   477,   481,   486,   498,   513,   527,   550,
     554,   558,   561,   565,   570,   576,   579,   584,   588,   589,
     593,   596,   598,   602,   608,   612,   618,   621,   624,   627,
     631,   635,   637,   640,   643,   646,   651,   656,   661,   666,
     673,   678,   680,   684,   687,   691,   695,   699,   701,   703,
     706,   708,   712,   714,   718,   720,   722,   724,   726,   728,
     730,   732,   734,   736,   738,   740,   742,   744,   746,   748,
     750,   752,   754,   757,   760,   763,   766,   768,   770,   773,
     778,   782,   788,   793,   797,   799,   801,   803,   805,   807,
     809,   811,   813,   815,   818,   821,   825,   828,   830,   835,
     839,   844,   849,   855,   860,   866,   872,   879,   883,   887,
     891,   893,   898,   900,   905,   909,   914,   919,   925,   930,
     936,   938,   941,   945,   947,   950,   952,   959,   963,   967,
     969,   972,   976,   978,   982,   985,   989,   992,   996,  1001,
    1003,  1007,  1009,  1012,  1014,  1016,  1018,  1021,  1024,  1027,
    1031,  1033,  1035,  1038,  1041,  1044,  1050,  1056,  1058,  1063,
    1067,  1072,  1081,  1083,  1086,  1090,  1093,  1097,  1106,  1117,
    1119,  1122,  1127,  1135,  1144,  1146,  1150,  1152,  1156,  1158,
    1162,  1166,  1170,  1174,  1175,  1180,  1184,  1188,  1192,  1194,
    1200,  1201,  1203,  1205,  1209,  1211,  1215,  1219,  1221,  1225,
    1229,  1233,  1237,  1239,  1243,  1247,  1249,  1253,  1257,  1259,
    1264,  1266,  1271,  1273,  1278,  1280,  1285,  1287,  1290,  1292,
    1294,  1297,  1300,  1302,  1304,  1306,  1308,  1310,  1312,  1314,
    1316,  1318,  1320,  1322,  1324,  1329,  1335,  1341,  1348,  1352,
    1357,  1359,  1362,  1366,  1369,  1371,  1374,  1377,  1379,  1381,
    1383,  1387,  1391,  1393,  1395,  1397,  1400,  1402,  1405,  1408,
    1410,  1412,  1414,  1416,  1418,  1420,  1422,  1424,  1426,  1429,
    1432,  1434,  1436,  1438,  1440,  1442,  1444,  1446,  1448,  1450,
    1452,  1454,  1456,  1458,  1460,  1463,  1467,  1472,  1474,  1477,
    1481,  1483,  1485,  1487,  1489,  1491,  1493,  1495,  1497,  1499,
    1501,  1503,  1505,  1507,  1509,  1512,  1515,  1519,  1521,  1526,
    1531,  1535,  1540,  1542,  1546,  1548,  1550,  1552,  1554,  1556,
    1561,  1567,  1576,  1586,  1596,  1607,  1609,  1612,  1614,  1617,
    1624,  1625,  1627,  1631,  1635,  1636,  1638,  1640,  1642,  1645,
    1648,  1649,  1651,  1653,  1655,  1658,  1661,  1663,  1665,  1667,
    1669,  1671,  1673,  1675,  1677,  1679,  1681,  1683,  1685,  1689,
    1692,  1696,  1700,  1703,  1705,  1707,  1709,  1711,  1713,  1715,
    1720,  1725,  1731,  1738,  1746,  1751,  1757,  1764,  1772,  1777,
    1782,  1787,  1793,  1800,  1808,  1810,  1813,  1816,  1818,  1821,
    1825,  1827,  1829,  1831,  1833,  1835,  1839,  1841,  1843,  1845,
    1849,  1851,  1853,  1855,  1857,  1859,  1861,  1863,  1865,  1867,
    1869,  1873,  1877,  1882,  1887,  1891,  1895,  1899,  1904,  1909,
    1913,  1918,  1925,  1930,  1937,  1941,  1945,  1950,  1957,  1964,
    1969,  1976,  1983,  1988,  1990,  1993,  1995,  1997,  1999,  2003,
    2007,  2009,  2011,  2016,  2022,  2029,  2033,  2037,  2041,  2045,
    2051,  2059,  2067,  2073,  2079,  2085,  2093,  2101,  2107,  2113,
    2117,  2121,  2127,  2135,  2141,  2149,  2151,  2156,  2160,  2166,
    2168,  2171,  2175,  2183,  2194,  2208,  2210,  2214,  2216,  2218,
    2220,  2222,  2224,  2232,  2237,  2239,  2241,  2243,  2245,  2247,
    2249,  2251,  2253,  2255,  2257,  2259,  2261,  2263,  2265,  2267,
    2269,  2271,  2273,  2275,  2277,  2279,  2281,  2283,  2285,  2287,
    2289,  2291,  2293,  2295,  2297,  2299,  2301,  2303,  2305,  2307,
    2309,  2311,  2313,  2315,  2317,  2319,  2321,  2323,  2325,  2327,
    2329,  2331,  2333,  2335,  2337,  2339,  2341,  2343,  2345,  2347,
    2349,  2351,  2353,  2355,  2357,  2359,  2361,  2363,  2365,  2367,
    2369,  2371,  2373,  2375,  2377,  2379,  2381,  2383,  2385,  2387,
    2389,  2391,  2393,  2395,  2397,  2399,  2401,  2403,  2405,  2407,
    2409,  2411,  2413,  2415,  2417,  2419,  2421,  2423,  2425,  2427,
    2429,  2431,  2433,  2435,  2437,  2439,  2441,  2443,  2445,  2447,
    2449,  2451,  2453,  2455,  2457,  2459,  2461,  2463,  2465,  2467,
    2469,  2471,  2473,  2475,  2477,  2479,  2481,  2483,  2485,  2487,
    2489,  2491,  2493,  2495,  2497,  2499,  2501,  2503,  2505,  2507,
    2509,  2511,  2513,  2515,  2517,  2519,  2521,  2523,  2525,  2527,
    2529,  2531,  2533,  2535,  2537,  2539,  2541,  2543,  2545,  2547,
    2549,  2551,  2553,  2555,  2557,  2559,  2561,  2563,  2565,  2567,
    2569,  2571,  2573,  2575,  2577,  2579,  2581,  2583,  2585,  2587,
    2589,  2591,  2593,  2595,  2597,  2599,  2601,  2603,  2605,  2607,
    2609,  2611,  2613,  2615,  2617,  2619,  2621,  2623,  2625,  2627,
    2629,  2631,  2633,  2635,  2637,  2639,  2641,  2644,  2645,  2647,
    2649,  2652,  2654,  2658,  2660,  2664,  2666,  2671,  2673,  2676,
    2680,  2681,  2683,  2684,  2686,  2691,  2694,  2698,  2700,  2701,
    2703,  2708,  2709,  2711,  2714,  2716,  2720,  2721,  2723,  2726,
    2729,  2731,  2732,  2734,  2735,  2737,  2739,  2741,  2743,  2745,
    2747,  2749,  2753,  2757,  2759,  2761,  2763,  2766,  2770,  2772,
    2774,  2776,  2778,  2780,  2782,  2784,  2786,  2789,  2792,  2794,
    2796,  2799,  2802,  2806,  2808,  2811,  2814,  2820,  2823,  2825,
    2827,  2828,  2830,  2832,  2836,  2841,  2842,  2845,  2846,  2849,
    2854,  2859,  2863,  2866,  2870,  2872,  2876,  2877,  2879,  2881,
    2884,  2887,  2890,  2893,  2895,  2898,  2901,  2904,  2907,  2911,
    2914,  2918,  2922,  2927,  2930,  2933,  2935,  2937
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1007,  1007,  1008,  1017,  1022,  1029,  1034,  1045,  1050,
    1058,  1066,  1074,  1080,  1092,  1101,  1105,  1109,  1121,  1127,
    1137,  1143,  1153,  1154,  1155,  1156,  1161,  1162,  1163,  1164,
    1165,  1166,  1167,  1168,  1169,  1175,  1180,  1189,  1195,  1204,
    1213,  1214,  1215,  1216,  1217,  1218,  1219,  1220,  1221,  1222,
    1227,  1228,  1229,  1230,  1231,  1232,  1233,  1236,  1241,  1242,
    1252,  1261,  1267,  1277,  1283,  1293,  1303,  1311,  1317,  1328,
    1333,  1343,  1349,  1355,  1361,  1378,  1386,  1394,  1398,  1407,
    1416,  1429,  1435,  1446,  1450,  1458,  1463,  1468,  1475,  1488,
    1495,  1501,  1508,  1514,  1518,  1525,  1536,  1540,  1548,  1554,
    1560,  1569,  1575,  1584,  1588,  1594,  1598,  1602,  1606,  1612,
    1618,  1624,  1630,  1636,  1640,  1646,  1652,  1659,  1667,  1675,
    1683,  1691,  1703,  1717,  1731,  1748,  1752,  1759,  1763,  1770,
    1778,  1795,  1801,  1809,  1816,  1826,  1836,  1846,  1856,  1873,
    1879,  1890,  1894,  1898,  1902,  1911,  1918,  1937,  1947,  1953,
    1959,  1969,  1976,  1987,  1994,  2001,  2013,  2017,  2024,  2029,
    2036,  2044,  2048,  2052,  2060,  2068,  2078,  2092,  2102,  2116,
    2125,  2140,  2146,  2158,  2162,  2173,  2180,  2188,  2203,  2207,
    2221,  2225,  2234,  2238,  2252,  2253,  2254,  2255,  2256,  2257,
    2260,  2261,  2262,  2263,  2264,  2266,  2267,  2270,  2271,  2272,
    2273,  2274,  2279,  2294,  2301,  2305,  2312,  2316,  2320,  2327,
    2335,  2346,  2356,  2369,  2378,  2379,  2380,  2384,  2385,  2386,
    2387,  2388,  2391,  2397,  2406,  2410,  2418,  2428,  2434,  2446,
    2450,  2458,  2467,  2477,  2485,  2494,  2503,  2518,  2527,  2537,
    2545,  2551,  2560,  2566,  2578,  2586,  2596,  2604,  2616,  2622,
    2633,  2635,  2639,  2647,  2651,  2656,  2660,  2664,  2668,  2676,
    2690,  2698,  2705,  2711,  2722,  2726,  2735,  2743,  2749,  2759,
    2765,  2775,  2779,  2789,  2795,  2801,  2807,  2816,  2825,  2834,
    2847,  2851,  2859,  2865,  2875,  2883,  2892,  2905,  2912,  2924,
    2928,  2940,  2947,  2953,  2962,  2969,  2975,  2987,  2994,  3007,
    3013,  3025,  3031,  3043,  3052,  3056,  3065,  3069,  3077,  3081,
    3091,  3098,  3107,  3117,  3116,  3130,  3139,  3148,  3161,  3165,
    3178,  3181,  3188,  3192,  3201,  3205,  3209,  3218,  3222,  3228,
    3234,  3240,  3251,  3255,  3259,  3267,  3271,  3277,  3287,  3291,
    3301,  3305,  3315,  3319,  3329,  3333,  3343,  3347,  3355,  3359,
    3363,  3367,  3377,  3381,  3385,  3393,  3397,  3401,  3405,  3409,
    3413,  3421,  3425,  3429,  3437,  3441,  3445,  3449,  3460,  3466,
    3476,  3482,  3492,  3496,  3534,  3540,  3546,  3552,  3563,  3571,
    3582,  3588,  3598,  3602,  3610,  3616,  3624,  3630,  3642,  3648,
    3658,  3662,  3666,  3670,  3674,  3680,  3686,  3694,  3698,  3706,
    3710,  3721,  3725,  3729,  3735,  3739,  3753,  3757,  3765,  3769,
    3779,  3783,  3787,  3796,  3800,  3806,  3810,  3818,  3824,  3834,
    3842,  3846,  3850,  3854,  3858,  3862,  3866,  3870,  3874,  3882,
    3886,  3894,  3901,  3908,  3919,  3927,  3931,  3939,  3947,  3955,
    4009,  4013,  4025,  4031,  4041,  4045,  4053,  4057,  4061,  4069,
    4079,  4089,  4099,  4109,  4119,  4134,  4140,  4151,  4157,  4168,
    4179,  4181,  4185,  4190,  4200,  4203,  4210,  4218,  4224,  4234,
    4247,  4250,  4257,  4263,  4269,  4276,  4287,  4291,  4301,  4305,
    4315,  4319,  4323,  4328,  4337,  4343,  4349,  4355,  4365,  4369,
    4381,  4385,  4397,  4409,  4413,  4417,  4421,  4425,  4429,  4437,
    4445,  4451,  4457,  4461,  4478,  4482,  4486,  4490,  4498,  4506,
    4514,  4518,  4522,  4526,  4534,  4540,  4550,  4558,  4562,  4568,
    4603,  4609,  4615,  4625,  4629,  4633,  4637,  4641,  4648,  4654,
    4664,  4672,  4676,  4680,  4684,  4688,  4692,  4696,  4700,  4704,
    4712,  4720,  4724,  4728,  4738,  4746,  4754,  4758,  4762,  4770,
    4774,  4780,  4786,  4790,  4800,  4808,  4812,  4818,  4827,  4836,
    4842,  4848,  4858,  4875,  4882,  4897,  4933,  4937,  4946,  4955,
    4965,  4969,  4978,  4987,  4991,  5002,  5019,  5025,  5031,  5041,
    5045,  5051,  5057,  5061,  5067,  5071,  5077,  5083,  5090,  5100,
    5105,  5113,  5119,  5129,  5151,  5160,  5166,  5179,  5193,  5200,
    5206,  5216,  5221,  5227,  5237,  5250,  5256,  5266,  5276,  5277,
    5295,  5299,  5312,  5318,  5325,  5326,  5327,  5328,  5329,  5330,
    5331,  5332,  5333,  5334,  5335,  5336,  5337,  5338,  5339,  5340,
    5341,  5342,  5343,  5344,  5345,  5346,  5347,  5348,  5349,  5350,
    5351,  5352,  5353,  5354,  5355,  5356,  5357,  5358,  5359,  5360,
    5361,  5362,  5363,  5364,  5365,  5366,  5367,  5368,  5369,  5370,
    5371,  5372,  5373,  5374,  5375,  5376,  5377,  5378,  5379,  5380,
    5381,  5382,  5383,  5384,  5385,  5386,  5387,  5388,  5389,  5390,
    5391,  5392,  5393,  5394,  5395,  5396,  5397,  5398,  5399,  5400,
    5401,  5402,  5403,  5404,  5405,  5406,  5407,  5408,  5409,  5410,
    5411,  5412,  5413,  5414,  5415,  5416,  5417,  5418,  5419,  5420,
    5421,  5422,  5423,  5424,  5425,  5426,  5427,  5428,  5429,  5430,
    5431,  5432,  5433,  5434,  5435,  5436,  5437,  5438,  5439,  5440,
    5441,  5442,  5443,  5444,  5445,  5446,  5447,  5448,  5449,  5450,
    5451,  5452,  5453,  5454,  5455,  5456,  5457,  5458,  5459,  5460,
    5461,  5462,  5463,  5464,  5465,  5466,  5467,  5468,  5469,  5470,
    5471,  5472,  5473,  5474,  5475,  5476,  5477,  5478,  5479,  5480,
    5481,  5482,  5483,  5484,  5485,  5486,  5487,  5488,  5489,  5490,
    5491,  5492,  5493,  5494,  5495,  5496,  5497,  5498,  5499,  5500,
    5501,  5502,  5503,  5504,  5505,  5506,  5507,  5508,  5509,  5510,
    5511,  5512,  5513,  5514,  5515,  5516,  5517,  5518,  5519,  5520,
    5521,  5522,  5523,  5524,  5525,  5526,  5537,  5546,  5549,  5556,
    5561,  5569,  5573,  5580,  5584,  5591,  5595,  5602,  5606,  5615,
    5628,  5631,  5639,  5642,  5650,  5658,  5666,  5670,  5678,  5681,
    5689,  5701,  5704,  5712,  5724,  5730,  5740,  5743,  5751,  5755,
    5759,  5767,  5770,  5778,  5781,  5789,  5793,  5797,  5801,  5805,
    5813,  5821,  5833,  5845,  5849,  5853,  5861,  5867,  5877,  5881,
    5885,  5889,  5893,  5897,  5901,  5905,  5913,  5917,  5921,  5925,
    5933,  5939,  5949,  5959,  5963,  5971,  5981,  5992,  5999,  6003,
    6011,  6014,  6021,  6026,  6035,  6045,  6048,  6056,  6059,  6067,
    6076,  6083,  6093,  6097,  6104,  6110,  6120,  6123,  6130,  6135,
    6147,  6155,  6167,  6175,  6179,  6187,  6191,  6195,  6203,  6211,
    6219,  6227,  6235,  6248,  6256,  6268,  6272,  6280
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
     315,   316
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 11426;
  const int xquery_parser::yynnts_ = 293;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 526;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 317;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 571;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1053 of lalr1.cc  */
#line 15321 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1055 of lalr1.cc  */
#line 6286 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"


namespace zorba {

namespace parser {

const char *the_tumbling = "tumbling", *the_sliding = "sliding",
  *the_start = "start", *the_end = "end", *the_only_end = "only end",
  *the_ofor = "ofor", *the_declare = "declare", *the_create = "create";

} // namespace parser

/*
 *  The error member function registers the errors to the driver.
 */
void xquery_parser::error(zorba::xquery_parser::location_type const& loc, std::string const& msg)
{
  // std::cout << "--> yytext: " << yytext << std::endl;
  // std::cout << "--> yytoken: " << yytoken << std::endl;
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

