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
#line 69 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"


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
#line 82 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 316 of lalr1.cc  */
#line 849 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 316 of lalr1.cc  */
#line 965 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"

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
#line 138 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"

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
#line 204 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
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
        case 105: /* "\"'DECIMAL'\"" */

/* Line 479 of lalr1.cc  */
#line 845 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 479 of lalr1.cc  */
#line 311 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 117: /* "\"'DOUBLE'\"" */

/* Line 479 of lalr1.cc  */
#line 844 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 479 of lalr1.cc  */
#line 320 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 142: /* "\"'INTEGER'\"" */

/* Line 479 of lalr1.cc  */
#line 843 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 479 of lalr1.cc  */
#line 329 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "VersionDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 338 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "MainModule" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 347 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "LibraryModule" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 356 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "ModuleDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 365 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "Prolog" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 374 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "SIND_DeclList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 383 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "VFO_DeclList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 392 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "SIND_Decl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 401 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "VFO_Decl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 410 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "DecimalFormatDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 419 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "DecimalFormatParamList" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 479 of lalr1.cc  */
#line 428 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "DecimalFormatParam" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 479 of lalr1.cc  */
#line 437 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "Setter" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 446 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "Import" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 455 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "NamespaceDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 464 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "BoundarySpaceDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 473 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "DefaultNamespaceDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 482 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "OptionDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 491 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "FTOptionDecl" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 500 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "OrderingModeDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 509 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "EmptyOrderDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 518 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "CopyNamespacesDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 527 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "DefaultCollationDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 536 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "BaseURIDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 545 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "SchemaImport" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 554 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "URILiteralList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 563 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "SchemaPrefix" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 572 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "ModuleImport" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 581 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "CtxItemDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 590 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "CtxItemDecl2" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 599 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "CtxItemDecl3" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 608 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "CtxItemDecl4" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 617 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "VarNameAndType" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 479 of lalr1.cc  */
#line 626 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "VarDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 635 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "DeclPropertyList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 644 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "DeclProperty" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 653 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "CollectionDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 662 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "NodeModifier" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 671 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "IndexDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 680 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "IndexKeyList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 689 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "IndexKeySpec" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 698 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "IntegrityConstraintDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 707 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "ConstructionDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 716 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FunctionSig" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 479 of lalr1.cc  */
#line 725 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "BlockExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 734 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "Block" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 743 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "BlockDecls" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 752 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "BlockVarDeclList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 761 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "BlockVarDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 770 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "AssignExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 779 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "ExitExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 788 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "WhileExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 797 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FlowCtlStatement" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 806 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 815 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDecl2" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 824 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDeclSimple" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 833 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FunctionDeclSequential" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 842 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "FunctionDeclUpdating" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 851 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "ParamList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 860 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Param" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "EnclosedExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 878 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "BracedExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 887 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "QueryBody" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 896 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "Expr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "ApplyExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 914 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "ConcatExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 923 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "ExprSingle" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 932 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "FLWORExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 941 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "ReturnExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 950 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "FLWORWinCond" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 959 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "WindowClause" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 968 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "CountClause" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 977 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "ForLetWinClause" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 986 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "FLWORClauseList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 995 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "ForClause" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1004 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "VarInDeclList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1013 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "VarInDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1022 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "PositionalVar" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1031 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "FTScoreVar" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1040 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "LetClause" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1049 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "VarGetsDeclList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1058 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "EvalVarDeclList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1067 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "VarGetsDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1076 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "WindowVarDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1085 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "WindowVars" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1094 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "WindowVars3" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1103 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "WindowVars2" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1112 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "EvalVarDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1121 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "WhereClause" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1130 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "GroupByClause" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1139 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "GroupSpecList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1148 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "GroupSpec" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1157 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "GroupCollationSpec" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1166 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "OrderByClause" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1175 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "OrderSpecList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1184 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "OrderSpec" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1193 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "OrderModifier" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1202 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "OrderDirSpec" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1211 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "OrderEmptySpec" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1220 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "OrderCollationSpec" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1229 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "QuantifiedExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1238 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "QVarInDeclList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1247 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "QVarInDecl" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1256 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "SwitchExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1265 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "SwitchCaseClauseList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1274 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "SwitchCaseClause" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1283 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "SwitchCaseOperandList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1292 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "TypeswitchExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1301 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "CaseClauseList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1310 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "CaseClause" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1319 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "IfExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1328 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "OrExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1337 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "AndExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1346 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "ComparisonExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1355 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "FTContainsExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1364 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "opt_FTIgnoreOption" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1373 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "RangeExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1382 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "AdditiveExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1391 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "MultiplicativeExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1400 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "UnionExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1409 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "IntersectExceptExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1418 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "InstanceofExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1427 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "TreatExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1436 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "CastableExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1445 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "CastExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1454 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "UnaryExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1463 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "SignList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1472 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "ValueExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1481 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "ValueComp" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1490 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "NodeComp" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1499 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "ValidateExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1508 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "ExtensionExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1517 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "Pragma_list" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1526 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "Pragma" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1535 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "PathExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1544 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "RelativePathExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1553 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "StepExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1562 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "AxisStep" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1571 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "ForwardStep" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1580 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "ForwardAxis" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1589 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "AbbrevForwardStep" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1598 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "ReverseStep" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1607 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "ReverseAxis" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1616 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "NodeTest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1625 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "NameTest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1634 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "Wildcard" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1643 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "FilterExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1652 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "PredicateList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1661 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "Predicate" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1670 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "PrimaryExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1679 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "Literal" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1688 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "NumericLiteral" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1697 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "VarRef" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1706 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "ParenthesizedExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1715 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "ContextItemExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1724 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "OrderedExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1733 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "UnorderedExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1742 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "FunctionCall" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1751 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "ArgList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1760 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "Constructor" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1769 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "DirectConstructor" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1778 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "DirElemConstructor" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1787 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "DirElemContentList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1796 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "DirAttributeList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1805 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "DirAttr" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1814 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "DirAttributeValue" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1823 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "opt_QuoteAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1832 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "QuoteAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1841 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "opt_AposAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1850 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "AposAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1859 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "QuoteAttrValueContent" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1868 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "AposAttrValueContent" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1877 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "DirElemContent" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1886 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "CommonContent" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1895 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "DirCommentConstructor" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1904 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "DirPIConstructor" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1913 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "CDataSection" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1922 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "ComputedConstructor" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1931 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "CompDocConstructor" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1940 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "CompElemConstructor" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1949 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "CompAttrConstructor" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1958 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "CompTextConstructor" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1967 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "CompCommentConstructor" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1976 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "CompPIConstructor" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1985 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "SingleType" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1994 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "TypeDeclaration" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2003 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "SequenceType" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2012 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "OccurrenceIndicator" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2021 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "ItemType" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2030 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "TypeList" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2039 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "AtomicType" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2048 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "KindTest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2057 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "AnyKindTest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2066 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "DocumentTest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2075 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "TextTest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2084 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "CommentTest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2093 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "PITest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2102 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "AttributeTest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2111 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "SchemaAttributeTest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2120 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "ElementTest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2129 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "SchemaElementTest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2138 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "TypeName" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2147 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "TypeName_WITH_HOOK" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2156 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "StringLiteral" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2165 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "AnyFunctionTest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2174 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "TypedFunctionTest" */

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2183 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "InsertExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2192 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "DeleteExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2201 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "ReplaceExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2210 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "RenameExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2219 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "TransformExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2228 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "VarNameList" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2237 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "VarNameDecl" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2246 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "TryExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2255 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "CatchListExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2264 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "CatchExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2273 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "NameTestList" */

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 479 of lalr1.cc  */
#line 2282 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "EvalExpr" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2291 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "QNAME" */

/* Line 479 of lalr1.cc  */
#line 867 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2300 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "FTSelection" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2309 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "FTOr" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2318 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "FTAnd" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2327 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "FTMildNot" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2336 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "FTUnaryNot" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2345 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "FTPrimaryWithOptions" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2354 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "opt_FTMatchOptions" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2363 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "FTWeight" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2372 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "FTPrimary" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2381 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "opt_FTTimes" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2390 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "FTExtensionSelection" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2399 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "FTWords" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2408 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "FTWordsValue" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2417 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTAnyallOption" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2426 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTPosFilter" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2435 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTOrder" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2444 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTWindow" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2453 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTDistance" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2462 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTUnit" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2471 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTMatchOptions" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2480 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTMatchOption" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2489 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTCaseOption" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2498 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTDiacriticsOption" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2507 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTExtensionOption" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2516 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTStemOption" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2525 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTThesaurusOption" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2534 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTThesaurusID" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2543 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTStopWordOption" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2552 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTStopWords" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2561 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTStopWordsInclExcl" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2570 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTLanguageOption" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2579 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTWildCardOption" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2588 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTContent" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2597 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTTimes" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2606 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTRange" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2615 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTScope" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2624 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTBigUnit" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2633 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTIgnoreOption" */

/* Line 479 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2642 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
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
#line 127 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}

/* Line 552 of lalr1.cc  */
#line 2727 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"

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
#line 1009 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 4:

/* Line 677 of lalr1.cc  */
#line 1018 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 5:

/* Line 677 of lalr1.cc  */
#line 1023 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            MainModule *mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
            mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 6:

/* Line 677 of lalr1.cc  */
#line 1030 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 7:

/* Line 677 of lalr1.cc  */
#line 1035 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            LibraryModule *lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
            lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 8:

/* Line 677 of lalr1.cc  */
#line 1046 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            std::string encoding = "utf-8";
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), encoding );
        }
    break;

  case 9:

/* Line 677 of lalr1.cc  */
#line 1051 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
        }
    break;

  case 10:

/* Line 677 of lalr1.cc  */
#line 1059 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1067 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
        }
    break;

  case 12:

/* Line 677 of lalr1.cc  */
#line 1075 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LibraryModule(
                LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 13:

/* Line 677 of lalr1.cc  */
#line 1081 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1093 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
            dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
        }
    break;

  case 15:

/* Line 677 of lalr1.cc  */
#line 1102 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog( LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)), NULL );
        }
    break;

  case 16:

/* Line 677 of lalr1.cc  */
#line 1106 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog( LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)) );
        }
    break;

  case 17:

/* Line 677 of lalr1.cc  */
#line 1110 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1122 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
            sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = sdl;
        }
    break;

  case 19:

/* Line 677 of lalr1.cc  */
#line 1128 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( SIND_DeclList *sdl = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                sdl->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 20:

/* Line 677 of lalr1.cc  */
#line 1138 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
            vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = vdl;
        }
    break;

  case 21:

/* Line 677 of lalr1.cc  */
#line 1144 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( VFO_DeclList *vdl = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vdl->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 35:

/* Line 677 of lalr1.cc  */
#line 1176 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
         (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
         delete (yysemantic_stack_[(4) - (4)].vstrpair);
       }
    break;

  case 36:

/* Line 677 of lalr1.cc  */
#line 1181 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
         (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
         delete (yysemantic_stack_[(4) - (4)].vstrpair);
       }
    break;

  case 37:

/* Line 677 of lalr1.cc  */
#line 1190 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.vstrpair) = new vector<string_pair_t>();
          (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
          delete (yysemantic_stack_[(1) - (1)].strpair);
        }
    break;

  case 38:

/* Line 677 of lalr1.cc  */
#line 1196 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
          delete (yysemantic_stack_[(2) - (2)].strpair);
          (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
        }
    break;

  case 39:

/* Line 677 of lalr1.cc  */
#line 1205 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
            (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval() );
            delete sl;
        }
    break;

  case 40:

/* Line 677 of lalr1.cc  */
#line 1213 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 41:

/* Line 677 of lalr1.cc  */
#line 1214 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 42:

/* Line 677 of lalr1.cc  */
#line 1215 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 43:

/* Line 677 of lalr1.cc  */
#line 1216 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 44:

/* Line 677 of lalr1.cc  */
#line 1217 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 45:

/* Line 677 of lalr1.cc  */
#line 1218 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 46:

/* Line 677 of lalr1.cc  */
#line 1219 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 47:

/* Line 677 of lalr1.cc  */
#line 1220 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 48:

/* Line 677 of lalr1.cc  */
#line 1221 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 49:

/* Line 677 of lalr1.cc  */
#line 1222 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 60:

/* Line 677 of lalr1.cc  */
#line 1253 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
        }
    break;

  case 61:

/* Line 677 of lalr1.cc  */
#line 1262 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::preserve_space
            );
        }
    break;

  case 62:

/* Line 677 of lalr1.cc  */
#line 1268 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::strip_space
            );
        }
    break;

  case 63:

/* Line 677 of lalr1.cc  */
#line 1278 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_element_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 64:

/* Line 677 of lalr1.cc  */
#line 1284 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_function_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 65:

/* Line 677 of lalr1.cc  */
#line 1294 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OptionDecl(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval))
            );
        }
    break;

  case 66:

/* Line 677 of lalr1.cc  */
#line 1304 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 67:

/* Line 677 of lalr1.cc  */
#line 1312 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::ordered
            );
        }
    break;

  case 68:

/* Line 677 of lalr1.cc  */
#line 1318 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::unordered
            );
        }
    break;

  case 69:

/* Line 677 of lalr1.cc  */
#line 1329 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_greatest);
        }
    break;

  case 70:

/* Line 677 of lalr1.cc  */
#line 1334 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_least);
        }
    break;

  case 71:

/* Line 677 of lalr1.cc  */
#line 1344 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 72:

/* Line 677 of lalr1.cc  */
#line 1350 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 73:

/* Line 677 of lalr1.cc  */
#line 1356 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 74:

/* Line 677 of lalr1.cc  */
#line 1362 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 75:

/* Line 677 of lalr1.cc  */
#line 1379 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
        }
    break;

  case 76:

/* Line 677 of lalr1.cc  */
#line 1387 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 77:

/* Line 677 of lalr1.cc  */
#line 1395 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
        }
    break;

  case 78:

/* Line 677 of lalr1.cc  */
#line 1399 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1408 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1417 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1430 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            URILiteralList *ull = new URILiteralList( LOC((yyloc)));
            ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.node) = ull;
        }
    break;

  case 82:

/* Line 677 of lalr1.cc  */
#line 1436 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
                ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 83:

/* Line 677 of lalr1.cc  */
#line 1447 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 84:

/* Line 677 of lalr1.cc  */
#line 1451 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
        }
    break;

  case 85:

/* Line 677 of lalr1.cc  */
#line 1459 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 86:

/* Line 677 of lalr1.cc  */
#line 1464 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 87:

/* Line 677 of lalr1.cc  */
#line 1469 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 88:

/* Line 677 of lalr1.cc  */
#line 1476 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1489 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
        }
    break;

  case 90:

/* Line 677 of lalr1.cc  */
#line 1496 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
            d->type = (yysemantic_stack_[(3) - (2)].node);
            (yyval.node) = d;
        }
    break;

  case 91:

/* Line 677 of lalr1.cc  */
#line 1502 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 92:

/* Line 677 of lalr1.cc  */
#line 1509 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
            d->ext = false;
            (yyval.node) = d;
        }
    break;

  case 93:

/* Line 677 of lalr1.cc  */
#line 1515 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), NULL );
        }
    break;

  case 94:

/* Line 677 of lalr1.cc  */
#line 1519 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 95:

/* Line 677 of lalr1.cc  */
#line 1526 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 96:

/* Line 677 of lalr1.cc  */
#line 1537 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 97:

/* Line 677 of lalr1.cc  */
#line 1541 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 98:

/* Line 677 of lalr1.cc  */
#line 1549 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(5) - (5)].expr));
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 99:

/* Line 677 of lalr1.cc  */
#line 1555 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 100:

/* Line 677 of lalr1.cc  */
#line 1561 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 101:

/* Line 677 of lalr1.cc  */
#line 1570 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
            dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = dpl;
        }
    break;

  case 102:

/* Line 677 of lalr1.cc  */
#line 1576 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
        dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
        (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 103:

/* Line 677 of lalr1.cc  */
#line 1585 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 104:

/* Line 677 of lalr1.cc  */
#line 1589 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 105:

/* Line 677 of lalr1.cc  */
#line 1595 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 106:

/* Line 677 of lalr1.cc  */
#line 1599 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 107:

/* Line 677 of lalr1.cc  */
#line 1603 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 108:

/* Line 677 of lalr1.cc  */
#line 1607 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 109:

/* Line 677 of lalr1.cc  */
#line 1613 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 110:

/* Line 677 of lalr1.cc  */
#line 1619 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 111:

/* Line 677 of lalr1.cc  */
#line 1625 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_equality
            );
        }
    break;

  case 112:

/* Line 677 of lalr1.cc  */
#line 1631 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_range
            );
        }
    break;

  case 113:

/* Line 677 of lalr1.cc  */
#line 1637 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 114:

/* Line 677 of lalr1.cc  */
#line 1641 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 115:

/* Line 677 of lalr1.cc  */
#line 1647 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 116:

/* Line 677 of lalr1.cc  */
#line 1653 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 117:

/* Line 677 of lalr1.cc  */
#line 1660 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1668 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1676 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1684 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1692 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1704 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1718 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1732 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1749 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 126:

/* Line 677 of lalr1.cc  */
#line 1753 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 127:

/* Line 677 of lalr1.cc  */
#line 1760 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier( LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 128:

/* Line 677 of lalr1.cc  */
#line 1764 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier( LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 129:

/* Line 677 of lalr1.cc  */
#line 1771 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1779 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1796 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList( LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 132:

/* Line 677 of lalr1.cc  */
#line 1802 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 133:

/* Line 677 of lalr1.cc  */
#line 1810 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec( LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<AtomicType*>((yysemantic_stack_[(3) - (3)].node)),
                            NULL);
    }
    break;

  case 134:

/* Line 677 of lalr1.cc  */
#line 1817 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec( LOC((yyloc)),
                            (yysemantic_stack_[(4) - (1)].expr),
                            dynamic_cast<AtomicType*>((yysemantic_stack_[(4) - (3)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 135:

/* Line 677 of lalr1.cc  */
#line 1828 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1838 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1848 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1859 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1874 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_preserve
            );
        }
    break;

  case 140:

/* Line 677 of lalr1.cc  */
#line 1880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_strip
            );
        }
    break;

  case 141:

/* Line 677 of lalr1.cc  */
#line 1891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL );
        }
    break;

  case 142:

/* Line 677 of lalr1.cc  */
#line 1895 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 143:

/* Line 677 of lalr1.cc  */
#line 1899 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)) );
        }
    break;

  case 144:

/* Line 677 of lalr1.cc  */
#line 1903 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig(
                dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 145:

/* Line 677 of lalr1.cc  */
#line 1912 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 146:

/* Line 677 of lalr1.cc  */
#line 1919 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1938 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1947 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 149:

/* Line 677 of lalr1.cc  */
#line 1954 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            vfo->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = vfo;
        }
    break;

  case 150:

/* Line 677 of lalr1.cc  */
#line 1960 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back((yysemantic_stack_[(2) - (2)].node));
            (yyval.node) = vfo;
        }
    break;

  case 151:

/* Line 677 of lalr1.cc  */
#line 1970 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(1) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 152:

/* Line 677 of lalr1.cc  */
#line 1977 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(3) - (3)].expr));
      vd->set_global(false);
      (yyval.node) = vd;
        }
    break;

  case 153:

/* Line 677 of lalr1.cc  */
#line 1988 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 154:

/* Line 677 of lalr1.cc  */
#line 1995 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExitExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 155:

/* Line 677 of lalr1.cc  */
#line 2002 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2014 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::BREAK );
        }
    break;

  case 157:

/* Line 677 of lalr1.cc  */
#line 2018 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
        }
    break;

  case 158:

/* Line 677 of lalr1.cc  */
#line 2025 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            dynamic_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 159:

/* Line 677 of lalr1.cc  */
#line 2030 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FunctionDecl *fd = dynamic_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));
            if (fd->type != ParseConstants::fn_extern && fd->type != ParseConstants::fn_extern_sequential && fd->type != ParseConstants::fn_extern_update)
            {
              delete (yysemantic_stack_[(3) - (3)].node);
              error((yyloc), "Only external functions may be declared nondeterministic");
              YYERROR;
            }
            fd->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            fd->deterministic = false;
            (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
        }
    break;

  case 160:

/* Line 677 of lalr1.cc  */
#line 2043 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FunctionDecl *fd = dynamic_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));
            if (fd->type != ParseConstants::fn_extern && fd->type != ParseConstants::fn_extern_sequential && fd->type != ParseConstants::fn_extern_update)
            {
              delete (yysemantic_stack_[(3) - (3)].node);
              error((yyloc), "Only external functions may be declared deterministic");
              YYERROR;
            }
            fd->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
        }
    break;

  case 161:

/* Line 677 of lalr1.cc  */
#line 2058 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 162:

/* Line 677 of lalr1.cc  */
#line 2062 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 163:

/* Line 677 of lalr1.cc  */
#line 2066 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 164:

/* Line 677 of lalr1.cc  */
#line 2070 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 165:

/* Line 677 of lalr1.cc  */
#line 2078 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2088 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2102 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->param,
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->ret,
                            (yysemantic_stack_[(5) - (5)].expr),
                            ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 168:

/* Line 677 of lalr1.cc  */
#line 2112 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->param,
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->ret,
                            NULL,
                            ParseConstants::fn_extern_sequential);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 169:

/* Line 677 of lalr1.cc  */
#line 2126 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                            &* (yysemantic_stack_[(7) - (4)].fnsig)->param,
                            &* (yysemantic_stack_[(7) - (4)].fnsig)->ret,
                            (yysemantic_stack_[(7) - (6)].expr),
                            ParseConstants::fn_update);
      delete (yysemantic_stack_[(7) - (4)].fnsig);
    }
    break;

  case 170:

/* Line 677 of lalr1.cc  */
#line 2136 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->param,
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->ret,
                            NULL,
                            ParseConstants::fn_extern_update);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 171:

/* Line 677 of lalr1.cc  */
#line 2151 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            ParamList *pl = new ParamList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 172:

/* Line 677 of lalr1.cc  */
#line 2157 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
                pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 173:

/* Line 677 of lalr1.cc  */
#line 2169 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 174:

/* Line 677 of lalr1.cc  */
#line 2173 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 175:

/* Line 677 of lalr1.cc  */
#line 2184 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EnclosedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 176:

/* Line 677 of lalr1.cc  */
#line 2191 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 177:

/* Line 677 of lalr1.cc  */
#line 2199 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QueryBody( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 178:

/* Line 677 of lalr1.cc  */
#line 2214 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 179:

/* Line 677 of lalr1.cc  */
#line 2218 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2232 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new BlockBody( LOC((yyloc)) );
        }
    break;

  case 181:

/* Line 677 of lalr1.cc  */
#line 2236 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (1)].expr));
            bb->add( (yysemantic_stack_[(3) - (2)].expr) );
            (yyval.expr) = bb;
        }
    break;

  case 182:

/* Line 677 of lalr1.cc  */
#line 2245 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 183:

/* Line 677 of lalr1.cc  */
#line 2249 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2290 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2305 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 204:

/* Line 677 of lalr1.cc  */
#line 2312 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_sliding;
        }
    break;

  case 205:

/* Line 677 of lalr1.cc  */
#line 2316 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_tumbling;
        }
    break;

  case 206:

/* Line 677 of lalr1.cc  */
#line 2323 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_start;
        }
    break;

  case 207:

/* Line 677 of lalr1.cc  */
#line 2327 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_end;
        }
    break;

  case 208:

/* Line 677 of lalr1.cc  */
#line 2331 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_only_end;
        }
    break;

  case 209:

/* Line 677 of lalr1.cc  */
#line 2338 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2346 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr),
                (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 211:

/* Line 677 of lalr1.cc  */
#line 2357 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2367 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2380 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 222:

/* Line 677 of lalr1.cc  */
#line 2402 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 223:

/* Line 677 of lalr1.cc  */
#line 2408 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 224:

/* Line 677 of lalr1.cc  */
#line 2417 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = NULL;
        }
    break;

  case 225:

/* Line 677 of lalr1.cc  */
#line 2421 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_ofor;
        }
    break;

  case 226:

/* Line 677 of lalr1.cc  */
#line 2429 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForClause(
                LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL
            );
        }
    break;

  case 227:

/* Line 677 of lalr1.cc  */
#line 2439 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
            vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vdl;
        }
    break;

  case 228:

/* Line 677 of lalr1.cc  */
#line 2445 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 229:

/* Line 677 of lalr1.cc  */
#line 2457 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 230:

/* Line 677 of lalr1.cc  */
#line 2461 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2469 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2478 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2488 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2496 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2505 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2514 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2529 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 238:

/* Line 677 of lalr1.cc  */
#line 2538 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 239:

/* Line 677 of lalr1.cc  */
#line 2548 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 240:

/* Line 677 of lalr1.cc  */
#line 2556 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 241:

/* Line 677 of lalr1.cc  */
#line 2562 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 242:

/* Line 677 of lalr1.cc  */
#line 2571 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 243:

/* Line 677 of lalr1.cc  */
#line 2577 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 244:

/* Line 677 of lalr1.cc  */
#line 2589 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2597 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2607 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2615 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2627 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 249:

/* Line 677 of lalr1.cc  */
#line 2633 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 251:

/* Line 677 of lalr1.cc  */
#line 2646 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 252:

/* Line 677 of lalr1.cc  */
#line 2650 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 253:

/* Line 677 of lalr1.cc  */
#line 2658 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 254:

/* Line 677 of lalr1.cc  */
#line 2662 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 256:

/* Line 677 of lalr1.cc  */
#line 2671 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 257:

/* Line 677 of lalr1.cc  */
#line 2675 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 258:

/* Line 677 of lalr1.cc  */
#line 2679 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 259:

/* Line 677 of lalr1.cc  */
#line 2687 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2701 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 261:

/* Line 677 of lalr1.cc  */
#line 2709 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 262:

/* Line 677 of lalr1.cc  */
#line 2716 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 263:

/* Line 677 of lalr1.cc  */
#line 2722 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 264:

/* Line 677 of lalr1.cc  */
#line 2733 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 265:

/* Line 677 of lalr1.cc  */
#line 2737 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 266:

/* Line 677 of lalr1.cc  */
#line 2746 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 267:

/* Line 677 of lalr1.cc  */
#line 2754 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 268:

/* Line 677 of lalr1.cc  */
#line 2760 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 269:

/* Line 677 of lalr1.cc  */
#line 2770 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 270:

/* Line 677 of lalr1.cc  */
#line 2776 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 271:

/* Line 677 of lalr1.cc  */
#line 2786 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 272:

/* Line 677 of lalr1.cc  */
#line 2790 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 273:

/* Line 677 of lalr1.cc  */
#line 2800 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 274:

/* Line 677 of lalr1.cc  */
#line 2806 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 275:

/* Line 677 of lalr1.cc  */
#line 2812 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 276:

/* Line 677 of lalr1.cc  */
#line 2818 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2827 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2836 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2845 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2858 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 281:

/* Line 677 of lalr1.cc  */
#line 2862 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 282:

/* Line 677 of lalr1.cc  */
#line 2870 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 283:

/* Line 677 of lalr1.cc  */
#line 2876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 284:

/* Line 677 of lalr1.cc  */
#line 2886 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 285:

/* Line 677 of lalr1.cc  */
#line 2894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2903 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 2916 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 288:

/* Line 677 of lalr1.cc  */
#line 2923 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 289:

/* Line 677 of lalr1.cc  */
#line 2935 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 290:

/* Line 677 of lalr1.cc  */
#line 2939 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 291:

/* Line 677 of lalr1.cc  */
#line 2951 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 292:

/* Line 677 of lalr1.cc  */
#line 2958 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 293:

/* Line 677 of lalr1.cc  */
#line 2964 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 294:

/* Line 677 of lalr1.cc  */
#line 2973 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 295:

/* Line 677 of lalr1.cc  */
#line 2980 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 296:

/* Line 677 of lalr1.cc  */
#line 2986 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 297:

/* Line 677 of lalr1.cc  */
#line 2998 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 298:

/* Line 677 of lalr1.cc  */
#line 3005 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 3018 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 300:

/* Line 677 of lalr1.cc  */
#line 3024 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 301:

/* Line 677 of lalr1.cc  */
#line 3036 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 302:

/* Line 677 of lalr1.cc  */
#line 3042 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 303:

/* Line 677 of lalr1.cc  */
#line 3054 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 304:

/* Line 677 of lalr1.cc  */
#line 3063 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 305:

/* Line 677 of lalr1.cc  */
#line 3067 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 306:

/* Line 677 of lalr1.cc  */
#line 3076 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 307:

/* Line 677 of lalr1.cc  */
#line 3080 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 308:

/* Line 677 of lalr1.cc  */
#line 3088 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 309:

/* Line 677 of lalr1.cc  */
#line 3092 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 3102 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 311:

/* Line 677 of lalr1.cc  */
#line 3109 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 3118 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 3127 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 314:

/* Line 677 of lalr1.cc  */
#line 3132 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 3141 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 3150 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 3159 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 3172 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 319:

/* Line 677 of lalr1.cc  */
#line 3176 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 3188 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 321:

/* Line 677 of lalr1.cc  */
#line 3192 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 322:

/* Line 677 of lalr1.cc  */
#line 3199 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 323:

/* Line 677 of lalr1.cc  */
#line 3203 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 324:

/* Line 677 of lalr1.cc  */
#line 3212 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 325:

/* Line 677 of lalr1.cc  */
#line 3216 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 326:

/* Line 677 of lalr1.cc  */
#line 3220 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 327:

/* Line 677 of lalr1.cc  */
#line 3229 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 328:

/* Line 677 of lalr1.cc  */
#line 3233 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 329:

/* Line 677 of lalr1.cc  */
#line 3239 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 330:

/* Line 677 of lalr1.cc  */
#line 3245 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 331:

/* Line 677 of lalr1.cc  */
#line 3251 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 332:

/* Line 677 of lalr1.cc  */
#line 3262 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 333:

/* Line 677 of lalr1.cc  */
#line 3266 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 334:

/* Line 677 of lalr1.cc  */
#line 3270 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 335:

/* Line 677 of lalr1.cc  */
#line 3278 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 336:

/* Line 677 of lalr1.cc  */
#line 3282 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 337:

/* Line 677 of lalr1.cc  */
#line 3288 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 338:

/* Line 677 of lalr1.cc  */
#line 3298 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 339:

/* Line 677 of lalr1.cc  */
#line 3302 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 340:

/* Line 677 of lalr1.cc  */
#line 3312 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 341:

/* Line 677 of lalr1.cc  */
#line 3316 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 342:

/* Line 677 of lalr1.cc  */
#line 3326 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 343:

/* Line 677 of lalr1.cc  */
#line 3330 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 344:

/* Line 677 of lalr1.cc  */
#line 3340 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 345:

/* Line 677 of lalr1.cc  */
#line 3344 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 346:

/* Line 677 of lalr1.cc  */
#line 3354 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 347:

/* Line 677 of lalr1.cc  */
#line 3358 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 348:

/* Line 677 of lalr1.cc  */
#line 3366 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 349:

/* Line 677 of lalr1.cc  */
#line 3370 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 350:

/* Line 677 of lalr1.cc  */
#line 3374 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 351:

/* Line 677 of lalr1.cc  */
#line 3378 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 352:

/* Line 677 of lalr1.cc  */
#line 3388 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 353:

/* Line 677 of lalr1.cc  */
#line 3392 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 354:

/* Line 677 of lalr1.cc  */
#line 3396 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 355:

/* Line 677 of lalr1.cc  */
#line 3404 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 356:

/* Line 677 of lalr1.cc  */
#line 3408 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 357:

/* Line 677 of lalr1.cc  */
#line 3412 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 358:

/* Line 677 of lalr1.cc  */
#line 3416 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 359:

/* Line 677 of lalr1.cc  */
#line 3420 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 360:

/* Line 677 of lalr1.cc  */
#line 3424 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 361:

/* Line 677 of lalr1.cc  */
#line 3432 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 362:

/* Line 677 of lalr1.cc  */
#line 3436 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 363:

/* Line 677 of lalr1.cc  */
#line 3440 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 364:

/* Line 677 of lalr1.cc  */
#line 3448 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 365:

/* Line 677 of lalr1.cc  */
#line 3452 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 366:

/* Line 677 of lalr1.cc  */
#line 3456 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 367:

/* Line 677 of lalr1.cc  */
#line 3460 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 368:

/* Line 677 of lalr1.cc  */
#line 3471 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 369:

/* Line 677 of lalr1.cc  */
#line 3477 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 370:

/* Line 677 of lalr1.cc  */
#line 3487 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 371:

/* Line 677 of lalr1.cc  */
#line 3493 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 372:

/* Line 677 of lalr1.cc  */
#line 3503 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 373:

/* Line 677 of lalr1.cc  */
#line 3507 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 374:

/* Line 677 of lalr1.cc  */
#line 3545 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL
            );
        }
    break;

  case 375:

/* Line 677 of lalr1.cc  */
#line 3551 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 376:

/* Line 677 of lalr1.cc  */
#line 3557 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 377:

/* Line 677 of lalr1.cc  */
#line 3563 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = !rpe ?
                (yysemantic_stack_[(1) - (1)].expr) : new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 378:

/* Line 677 of lalr1.cc  */
#line 3574 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NULL;
        }
    break;

  case 379:

/* Line 677 of lalr1.cc  */
#line 3582 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 3593 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:

/* Line 677 of lalr1.cc  */
#line 3599 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 382:

/* Line 677 of lalr1.cc  */
#line 3609 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:

/* Line 677 of lalr1.cc  */
#line 3613 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 384:

/* Line 677 of lalr1.cc  */
#line 3621 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 385:

/* Line 677 of lalr1.cc  */
#line 3627 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 3635 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 387:

/* Line 677 of lalr1.cc  */
#line 3641 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 3653 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 389:

/* Line 677 of lalr1.cc  */
#line 3659 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 390:

/* Line 677 of lalr1.cc  */
#line 3669 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 391:

/* Line 677 of lalr1.cc  */
#line 3673 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 392:

/* Line 677 of lalr1.cc  */
#line 3677 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 393:

/* Line 677 of lalr1.cc  */
#line 3681 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 394:

/* Line 677 of lalr1.cc  */
#line 3685 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 395:

/* Line 677 of lalr1.cc  */
#line 3691 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 396:

/* Line 677 of lalr1.cc  */
#line 3697 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 397:

/* Line 677 of lalr1.cc  */
#line 3705 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 398:

/* Line 677 of lalr1.cc  */
#line 3709 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 399:

/* Line 677 of lalr1.cc  */
#line 3717 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 400:

/* Line 677 of lalr1.cc  */
#line 3721 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 401:

/* Line 677 of lalr1.cc  */
#line 3732 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 402:

/* Line 677 of lalr1.cc  */
#line 3736 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 403:

/* Line 677 of lalr1.cc  */
#line 3740 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 404:

/* Line 677 of lalr1.cc  */
#line 3746 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 405:

/* Line 677 of lalr1.cc  */
#line 3750 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 406:

/* Line 677 of lalr1.cc  */
#line 3764 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 407:

/* Line 677 of lalr1.cc  */
#line 3768 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 408:

/* Line 677 of lalr1.cc  */
#line 3776 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 409:

/* Line 677 of lalr1.cc  */
#line 3780 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 410:

/* Line 677 of lalr1.cc  */
#line 3790 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 411:

/* Line 677 of lalr1.cc  */
#line 3794 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 412:

/* Line 677 of lalr1.cc  */
#line 3798 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 413:

/* Line 677 of lalr1.cc  */
#line 3807 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 414:

/* Line 677 of lalr1.cc  */
#line 3811 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FilterExpr(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 415:

/* Line 677 of lalr1.cc  */
#line 3817 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
        }
    break;

  case 416:

/* Line 677 of lalr1.cc  */
#line 3821 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
        }
    break;

  case 417:

/* Line 677 of lalr1.cc  */
#line 3829 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 418:

/* Line 677 of lalr1.cc  */
#line 3835 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 419:

/* Line 677 of lalr1.cc  */
#line 3845 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 420:

/* Line 677 of lalr1.cc  */
#line 3853 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 421:

/* Line 677 of lalr1.cc  */
#line 3857 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 422:

/* Line 677 of lalr1.cc  */
#line 3861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 423:

/* Line 677 of lalr1.cc  */
#line 3865 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 424:

/* Line 677 of lalr1.cc  */
#line 3869 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 425:

/* Line 677 of lalr1.cc  */
#line 3873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 426:

/* Line 677 of lalr1.cc  */
#line 3877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 427:

/* Line 677 of lalr1.cc  */
#line 3881 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 428:

/* Line 677 of lalr1.cc  */
#line 3885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 429:

/* Line 677 of lalr1.cc  */
#line 3893 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 430:

/* Line 677 of lalr1.cc  */
#line 3897 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 431:

/* Line 677 of lalr1.cc  */
#line 3905 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 432:

/* Line 677 of lalr1.cc  */
#line 3912 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 433:

/* Line 677 of lalr1.cc  */
#line 3919 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 434:

/* Line 677 of lalr1.cc  */
#line 3930 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 435:

/* Line 677 of lalr1.cc  */
#line 3938 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 436:

/* Line 677 of lalr1.cc  */
#line 3942 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 437:

/* Line 677 of lalr1.cc  */
#line 3950 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 438:

/* Line 677 of lalr1.cc  */
#line 3958 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 439:

/* Line 677 of lalr1.cc  */
#line 3966 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 440:

/* Line 677 of lalr1.cc  */
#line 4020 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 441:

/* Line 677 of lalr1.cc  */
#line 4024 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 4036 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 443:

/* Line 677 of lalr1.cc  */
#line 4042 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 444:

/* Line 677 of lalr1.cc  */
#line 4052 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 445:

/* Line 677 of lalr1.cc  */
#line 4056 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 446:

/* Line 677 of lalr1.cc  */
#line 4064 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 447:

/* Line 677 of lalr1.cc  */
#line 4068 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 448:

/* Line 677 of lalr1.cc  */
#line 4072 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 449:

/* Line 677 of lalr1.cc  */
#line 4080 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 4090 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 4100 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 4110 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 4120 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 4130 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 4145 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 456:

/* Line 677 of lalr1.cc  */
#line 4151 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 457:

/* Line 677 of lalr1.cc  */
#line 4162 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 458:

/* Line 677 of lalr1.cc  */
#line 4168 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 459:

/* Line 677 of lalr1.cc  */
#line 4179 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 4196 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 463:

/* Line 677 of lalr1.cc  */
#line 4201 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 464:

/* Line 677 of lalr1.cc  */
#line 4210 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 465:

/* Line 677 of lalr1.cc  */
#line 4214 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 466:

/* Line 677 of lalr1.cc  */
#line 4221 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 4229 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 468:

/* Line 677 of lalr1.cc  */
#line 4235 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 4245 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 4257 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 471:

/* Line 677 of lalr1.cc  */
#line 4261 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 472:

/* Line 677 of lalr1.cc  */
#line 4268 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 473:

/* Line 677 of lalr1.cc  */
#line 4274 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 474:

/* Line 677 of lalr1.cc  */
#line 4280 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 475:

/* Line 677 of lalr1.cc  */
#line 4287 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 476:

/* Line 677 of lalr1.cc  */
#line 4298 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 477:

/* Line 677 of lalr1.cc  */
#line 4302 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 478:

/* Line 677 of lalr1.cc  */
#line 4312 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 479:

/* Line 677 of lalr1.cc  */
#line 4316 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 480:

/* Line 677 of lalr1.cc  */
#line 4326 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 481:

/* Line 677 of lalr1.cc  */
#line 4330 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 482:

/* Line 677 of lalr1.cc  */
#line 4334 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 483:

/* Line 677 of lalr1.cc  */
#line 4339 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 484:

/* Line 677 of lalr1.cc  */
#line 4348 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 485:

/* Line 677 of lalr1.cc  */
#line 4354 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 486:

/* Line 677 of lalr1.cc  */
#line 4360 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 487:

/* Line 677 of lalr1.cc  */
#line 4366 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 488:

/* Line 677 of lalr1.cc  */
#line 4376 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 489:

/* Line 677 of lalr1.cc  */
#line 4380 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
        }
    break;

  case 490:

/* Line 677 of lalr1.cc  */
#line 4392 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 491:

/* Line 677 of lalr1.cc  */
#line 4396 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 492:

/* Line 677 of lalr1.cc  */
#line 4408 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 493:

/* Line 677 of lalr1.cc  */
#line 4420 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 494:

/* Line 677 of lalr1.cc  */
#line 4424 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 495:

/* Line 677 of lalr1.cc  */
#line 4428 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 496:

/* Line 677 of lalr1.cc  */
#line 4432 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 497:

/* Line 677 of lalr1.cc  */
#line 4436 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 498:

/* Line 677 of lalr1.cc  */
#line 4440 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 499:

/* Line 677 of lalr1.cc  */
#line 4448 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 500:

/* Line 677 of lalr1.cc  */
#line 4456 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL
            );
        }
    break;

  case 501:

/* Line 677 of lalr1.cc  */
#line 4462 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr)
            );
        }
    break;

  case 502:

/* Line 677 of lalr1.cc  */
#line 4468 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 503:

/* Line 677 of lalr1.cc  */
#line 4472 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 504:

/* Line 677 of lalr1.cc  */
#line 4489 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (2)].expr), NULL );
        }
    break;

  case 505:

/* Line 677 of lalr1.cc  */
#line 4493 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 506:

/* Line 677 of lalr1.cc  */
#line 4497 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 507:

/* Line 677 of lalr1.cc  */
#line 4501 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 508:

/* Line 677 of lalr1.cc  */
#line 4509 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 509:

/* Line 677 of lalr1.cc  */
#line 4517 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 510:

/* Line 677 of lalr1.cc  */
#line 4525 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), NULL );
        }
    break;

  case 511:

/* Line 677 of lalr1.cc  */
#line 4529 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (2)].sval)), (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 512:

/* Line 677 of lalr1.cc  */
#line 4533 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 513:

/* Line 677 of lalr1.cc  */
#line 4537 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 514:

/* Line 677 of lalr1.cc  */
#line 4545 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 515:

/* Line 677 of lalr1.cc  */
#line 4551 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 516:

/* Line 677 of lalr1.cc  */
#line 4561 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 517:

/* Line 677 of lalr1.cc  */
#line 4569 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 518:

/* Line 677 of lalr1.cc  */
#line 4573 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 519:

/* Line 677 of lalr1.cc  */
#line 4579 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 520:

/* Line 677 of lalr1.cc  */
#line 4614 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 521:

/* Line 677 of lalr1.cc  */
#line 4620 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 522:

/* Line 677 of lalr1.cc  */
#line 4626 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 523:

/* Line 677 of lalr1.cc  */
#line 4636 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 524:

/* Line 677 of lalr1.cc  */
#line 4640 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 525:

/* Line 677 of lalr1.cc  */
#line 4644 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 526:

/* Line 677 of lalr1.cc  */
#line 4648 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 527:

/* Line 677 of lalr1.cc  */
#line 4652 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 528:

/* Line 677 of lalr1.cc  */
#line 4659 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 529:

/* Line 677 of lalr1.cc  */
#line 4665 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 530:

/* Line 677 of lalr1.cc  */
#line 4675 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 531:

/* Line 677 of lalr1.cc  */
#line 4683 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 532:

/* Line 677 of lalr1.cc  */
#line 4687 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 533:

/* Line 677 of lalr1.cc  */
#line 4691 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 534:

/* Line 677 of lalr1.cc  */
#line 4695 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 535:

/* Line 677 of lalr1.cc  */
#line 4699 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 536:

/* Line 677 of lalr1.cc  */
#line 4703 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 537:

/* Line 677 of lalr1.cc  */
#line 4707 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 538:

/* Line 677 of lalr1.cc  */
#line 4711 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 539:

/* Line 677 of lalr1.cc  */
#line 4715 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 540:

/* Line 677 of lalr1.cc  */
#line 4723 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 541:

/* Line 677 of lalr1.cc  */
#line 4731 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 542:

/* Line 677 of lalr1.cc  */
#line 4735 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 543:

/* Line 677 of lalr1.cc  */
#line 4739 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 544:

/* Line 677 of lalr1.cc  */
#line 4749 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 545:

/* Line 677 of lalr1.cc  */
#line 4757 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 546:

/* Line 677 of lalr1.cc  */
#line 4765 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 547:

/* Line 677 of lalr1.cc  */
#line 4769 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 548:

/* Line 677 of lalr1.cc  */
#line 4773 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 549:

/* Line 677 of lalr1.cc  */
#line 4781 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 550:

/* Line 677 of lalr1.cc  */
#line 4785 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 551:

/* Line 677 of lalr1.cc  */
#line 4791 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 552:

/* Line 677 of lalr1.cc  */
#line 4797 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 553:

/* Line 677 of lalr1.cc  */
#line 4801 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 554:

/* Line 677 of lalr1.cc  */
#line 4811 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
        }
    break;

  case 555:

/* Line 677 of lalr1.cc  */
#line 4819 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 556:

/* Line 677 of lalr1.cc  */
#line 4823 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 557:

/* Line 677 of lalr1.cc  */
#line 4829 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 4838 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 4847 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 560:

/* Line 677 of lalr1.cc  */
#line 4853 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 561:

/* Line 677 of lalr1.cc  */
#line 4859 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 562:

/* Line 677 of lalr1.cc  */
#line 4869 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 563:

/* Line 677 of lalr1.cc  */
#line 4886 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 564:

/* Line 677 of lalr1.cc  */
#line 4893 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 565:

/* Line 677 of lalr1.cc  */
#line 4908 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 566:

/* Line 677 of lalr1.cc  */
#line 4944 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 567:

/* Line 677 of lalr1.cc  */
#line 4948 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 568:

/* Line 677 of lalr1.cc  */
#line 4957 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
        }
    break;

  case 569:

/* Line 677 of lalr1.cc  */
#line 4966 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new InlineFunction(LOC ((yyloc)), &*(yysemantic_stack_[(3) - (2)].fnsig)->param, &*(yysemantic_stack_[(3) - (2)].fnsig)->ret, dynamic_cast<EnclosedExpr *>((yysemantic_stack_[(3) - (3)].expr)));
          delete (yysemantic_stack_[(3) - (2)].fnsig);
        }
    break;

  case 570:

/* Line 677 of lalr1.cc  */
#line 4976 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 571:

/* Line 677 of lalr1.cc  */
#line 4980 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 572:

/* Line 677 of lalr1.cc  */
#line 4989 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
        }
    break;

  case 573:

/* Line 677 of lalr1.cc  */
#line 4998 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 574:

/* Line 677 of lalr1.cc  */
#line 5002 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 575:

/* Line 677 of lalr1.cc  */
#line 5013 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 576:

/* Line 677 of lalr1.cc  */
#line 5030 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 577:

/* Line 677 of lalr1.cc  */
#line 5036 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 578:

/* Line 677 of lalr1.cc  */
#line 5042 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 579:

/* Line 677 of lalr1.cc  */
#line 5052 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 580:

/* Line 677 of lalr1.cc  */
#line 5056 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 581:

/* Line 677 of lalr1.cc  */
#line 5062 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 582:

/* Line 677 of lalr1.cc  */
#line 5068 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 583:

/* Line 677 of lalr1.cc  */
#line 5072 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 584:

/* Line 677 of lalr1.cc  */
#line 5078 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 585:

/* Line 677 of lalr1.cc  */
#line 5082 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 586:

/* Line 677 of lalr1.cc  */
#line 5088 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 587:

/* Line 677 of lalr1.cc  */
#line 5094 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 588:

/* Line 677 of lalr1.cc  */
#line 5101 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 589:

/* Line 677 of lalr1.cc  */
#line 5111 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 590:

/* Line 677 of lalr1.cc  */
#line 5116 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 591:

/* Line 677 of lalr1.cc  */
#line 5124 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 592:

/* Line 677 of lalr1.cc  */
#line 5130 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 593:

/* Line 677 of lalr1.cc  */
#line 5140 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 594:

/* Line 677 of lalr1.cc  */
#line 5162 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 595:

/* Line 677 of lalr1.cc  */
#line 5171 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 596:

/* Line 677 of lalr1.cc  */
#line 5177 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 597:

/* Line 677 of lalr1.cc  */
#line 5190 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 598:

/* Line 677 of lalr1.cc  */
#line 5204 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 599:

/* Line 677 of lalr1.cc  */
#line 5211 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 600:

/* Line 677 of lalr1.cc  */
#line 5217 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 601:

/* Line 677 of lalr1.cc  */
#line 5227 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 602:

/* Line 677 of lalr1.cc  */
#line 5232 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 603:

/* Line 677 of lalr1.cc  */
#line 5238 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 5248 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 5261 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 606:

/* Line 677 of lalr1.cc  */
#line 5267 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 609:

/* Line 677 of lalr1.cc  */
#line 5288 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 5307 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr(
        LOC((yyloc)), dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)), (yysemantic_stack_[(7) - (6)].expr)
        );
    }
    break;

  case 611:

/* Line 677 of lalr1.cc  */
#line 5313 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr( LOC((yyloc)), new VarGetsDeclList( LOC((yyloc)) ), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 612:

/* Line 677 of lalr1.cc  */
#line 5325 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 613:

/* Line 677 of lalr1.cc  */
#line 5329 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 614:

/* Line 677 of lalr1.cc  */
#line 5335 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("xquery"); }
    break;

  case 615:

/* Line 677 of lalr1.cc  */
#line 5336 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("empty"); }
    break;

  case 616:

/* Line 677 of lalr1.cc  */
#line 5337 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("attribute"); }
    break;

  case 617:

/* Line 677 of lalr1.cc  */
#line 5338 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("comment"); }
    break;

  case 618:

/* Line 677 of lalr1.cc  */
#line 5339 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("document-node"); }
    break;

  case 619:

/* Line 677 of lalr1.cc  */
#line 5340 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("element"); }
    break;

  case 620:

/* Line 677 of lalr1.cc  */
#line 5341 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("item"); }
    break;

  case 621:

/* Line 677 of lalr1.cc  */
#line 5342 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("if"); }
    break;

  case 622:

/* Line 677 of lalr1.cc  */
#line 5343 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("node"); }
    break;

  case 623:

/* Line 677 of lalr1.cc  */
#line 5344 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("processing-instruction"); }
    break;

  case 624:

/* Line 677 of lalr1.cc  */
#line 5345 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema-attribute"); }
    break;

  case 625:

/* Line 677 of lalr1.cc  */
#line 5346 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema-element"); }
    break;

  case 626:

/* Line 677 of lalr1.cc  */
#line 5347 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("text"); }
    break;

  case 627:

/* Line 677 of lalr1.cc  */
#line 5348 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("typeswitch"); }
    break;

  case 628:

/* Line 677 of lalr1.cc  */
#line 5349 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("empty-sequence"); }
    break;

  case 629:

/* Line 677 of lalr1.cc  */
#line 5350 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("boundary-space"); }
    break;

  case 630:

/* Line 677 of lalr1.cc  */
#line 5351 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ft-option"); }
    break;

  case 631:

/* Line 677 of lalr1.cc  */
#line 5352 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("base-uri"); }
    break;

  case 632:

/* Line 677 of lalr1.cc  */
#line 5353 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lax"); }
    break;

  case 633:

/* Line 677 of lalr1.cc  */
#line 5354 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("strict"); }
    break;

  case 634:

/* Line 677 of lalr1.cc  */
#line 5355 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("idiv"); }
    break;

  case 635:

/* Line 677 of lalr1.cc  */
#line 5356 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("document"); }
    break;

  case 636:

/* Line 677 of lalr1.cc  */
#line 5357 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ftnot"); }
    break;

  case 637:

/* Line 677 of lalr1.cc  */
#line 5358 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("not"); }
    break;

  case 638:

/* Line 677 of lalr1.cc  */
#line 5359 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sensitive"); }
    break;

  case 639:

/* Line 677 of lalr1.cc  */
#line 5360 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("insensitive"); }
    break;

  case 640:

/* Line 677 of lalr1.cc  */
#line 5361 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("diacritics"); }
    break;

  case 641:

/* Line 677 of lalr1.cc  */
#line 5362 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("without"); }
    break;

  case 642:

/* Line 677 of lalr1.cc  */
#line 5363 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stemming"); }
    break;

  case 643:

/* Line 677 of lalr1.cc  */
#line 5364 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("thesaurus"); }
    break;

  case 644:

/* Line 677 of lalr1.cc  */
#line 5365 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stop"); }
    break;

  case 645:

/* Line 677 of lalr1.cc  */
#line 5366 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("wildcards"); }
    break;

  case 646:

/* Line 677 of lalr1.cc  */
#line 5367 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("entire"); }
    break;

  case 647:

/* Line 677 of lalr1.cc  */
#line 5368 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("content"); }
    break;

  case 648:

/* Line 677 of lalr1.cc  */
#line 5369 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("word"); }
    break;

  case 649:

/* Line 677 of lalr1.cc  */
#line 5370 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("start"); }
    break;

  case 650:

/* Line 677 of lalr1.cc  */
#line 5371 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("end"); }
    break;

  case 651:

/* Line 677 of lalr1.cc  */
#line 5372 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("most"); }
    break;

  case 652:

/* Line 677 of lalr1.cc  */
#line 5373 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("skip"); }
    break;

  case 653:

/* Line 677 of lalr1.cc  */
#line 5374 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("copy"); }
    break;

  case 654:

/* Line 677 of lalr1.cc  */
#line 5375 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("general"); }
    break;

  case 655:

/* Line 677 of lalr1.cc  */
#line 5376 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("value"); }
    break;

  case 656:

/* Line 677 of lalr1.cc  */
#line 5377 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("eq"); }
    break;

  case 657:

/* Line 677 of lalr1.cc  */
#line 5378 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ne"); }
    break;

  case 658:

/* Line 677 of lalr1.cc  */
#line 5379 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lt"); }
    break;

  case 659:

/* Line 677 of lalr1.cc  */
#line 5380 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("le"); }
    break;

  case 660:

/* Line 677 of lalr1.cc  */
#line 5381 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("gt"); }
    break;

  case 661:

/* Line 677 of lalr1.cc  */
#line 5382 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ge"); }
    break;

  case 662:

/* Line 677 of lalr1.cc  */
#line 5383 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("at"); }
    break;

  case 663:

/* Line 677 of lalr1.cc  */
#line 5384 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("context"); }
    break;

  case 664:

/* Line 677 of lalr1.cc  */
#line 5385 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("variable"); }
    break;

  case 665:

/* Line 677 of lalr1.cc  */
#line 5386 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("return"); }
    break;

  case 666:

/* Line 677 of lalr1.cc  */
#line 5387 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("for"); }
    break;

  case 667:

/* Line 677 of lalr1.cc  */
#line 5388 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("outer"); }
    break;

  case 668:

/* Line 677 of lalr1.cc  */
#line 5389 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sliding"); }
    break;

  case 669:

/* Line 677 of lalr1.cc  */
#line 5390 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("tumbling"); }
    break;

  case 670:

/* Line 677 of lalr1.cc  */
#line 5391 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("previous"); }
    break;

  case 671:

/* Line 677 of lalr1.cc  */
#line 5392 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("next"); }
    break;

  case 672:

/* Line 677 of lalr1.cc  */
#line 5393 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("only"); }
    break;

  case 673:

/* Line 677 of lalr1.cc  */
#line 5394 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("when"); }
    break;

  case 674:

/* Line 677 of lalr1.cc  */
#line 5395 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("count"); }
    break;

  case 675:

/* Line 677 of lalr1.cc  */
#line 5396 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("in"); }
    break;

  case 676:

/* Line 677 of lalr1.cc  */
#line 5397 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("let"); }
    break;

  case 677:

/* Line 677 of lalr1.cc  */
#line 5398 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("where"); }
    break;

  case 678:

/* Line 677 of lalr1.cc  */
#line 5399 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("by"); }
    break;

  case 679:

/* Line 677 of lalr1.cc  */
#line 5400 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("group"); }
    break;

  case 680:

/* Line 677 of lalr1.cc  */
#line 5401 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("order"); }
    break;

  case 681:

/* Line 677 of lalr1.cc  */
#line 5402 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stable"); }
    break;

  case 682:

/* Line 677 of lalr1.cc  */
#line 5403 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ascending"); }
    break;

  case 683:

/* Line 677 of lalr1.cc  */
#line 5404 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("descending"); }
    break;

  case 684:

/* Line 677 of lalr1.cc  */
#line 5405 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("greatest"); }
    break;

  case 685:

/* Line 677 of lalr1.cc  */
#line 5406 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("least"); }
    break;

  case 686:

/* Line 677 of lalr1.cc  */
#line 5407 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("collation"); }
    break;

  case 687:

/* Line 677 of lalr1.cc  */
#line 5408 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("some"); }
    break;

  case 688:

/* Line 677 of lalr1.cc  */
#line 5409 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("every"); }
    break;

  case 689:

/* Line 677 of lalr1.cc  */
#line 5410 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("satisfies"); }
    break;

  case 690:

/* Line 677 of lalr1.cc  */
#line 5411 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("case"); }
    break;

  case 691:

/* Line 677 of lalr1.cc  */
#line 5412 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("as"); }
    break;

  case 692:

/* Line 677 of lalr1.cc  */
#line 5413 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("then"); }
    break;

  case 693:

/* Line 677 of lalr1.cc  */
#line 5414 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("else"); }
    break;

  case 694:

/* Line 677 of lalr1.cc  */
#line 5415 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("or"); }
    break;

  case 695:

/* Line 677 of lalr1.cc  */
#line 5416 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("and"); }
    break;

  case 696:

/* Line 677 of lalr1.cc  */
#line 5417 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("instance"); }
    break;

  case 697:

/* Line 677 of lalr1.cc  */
#line 5418 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("of"); }
    break;

  case 698:

/* Line 677 of lalr1.cc  */
#line 5419 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("castable"); }
    break;

  case 699:

/* Line 677 of lalr1.cc  */
#line 5420 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("to"); }
    break;

  case 700:

/* Line 677 of lalr1.cc  */
#line 5421 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("div"); }
    break;

  case 701:

/* Line 677 of lalr1.cc  */
#line 5422 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("mod"); }
    break;

  case 702:

/* Line 677 of lalr1.cc  */
#line 5423 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("union"); }
    break;

  case 703:

/* Line 677 of lalr1.cc  */
#line 5424 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("intersect"); }
    break;

  case 704:

/* Line 677 of lalr1.cc  */
#line 5425 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("except"); }
    break;

  case 705:

/* Line 677 of lalr1.cc  */
#line 5426 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("validate"); }
    break;

  case 706:

/* Line 677 of lalr1.cc  */
#line 5427 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("cast"); }
    break;

  case 707:

/* Line 677 of lalr1.cc  */
#line 5428 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("treat"); }
    break;

  case 708:

/* Line 677 of lalr1.cc  */
#line 5429 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("is"); }
    break;

  case 709:

/* Line 677 of lalr1.cc  */
#line 5430 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("preserve"); }
    break;

  case 710:

/* Line 677 of lalr1.cc  */
#line 5431 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("strip"); }
    break;

  case 711:

/* Line 677 of lalr1.cc  */
#line 5432 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("namespace"); }
    break;

  case 712:

/* Line 677 of lalr1.cc  */
#line 5433 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("external"); }
    break;

  case 713:

/* Line 677 of lalr1.cc  */
#line 5434 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("encoding"); }
    break;

  case 714:

/* Line 677 of lalr1.cc  */
#line 5435 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("no-preserve"); }
    break;

  case 715:

/* Line 677 of lalr1.cc  */
#line 5436 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("inherit"); }
    break;

  case 716:

/* Line 677 of lalr1.cc  */
#line 5437 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("no-inherit"); }
    break;

  case 717:

/* Line 677 of lalr1.cc  */
#line 5438 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("declare"); }
    break;

  case 718:

/* Line 677 of lalr1.cc  */
#line 5439 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("construction"); }
    break;

  case 719:

/* Line 677 of lalr1.cc  */
#line 5440 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ordering"); }
    break;

  case 720:

/* Line 677 of lalr1.cc  */
#line 5441 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("default"); }
    break;

  case 721:

/* Line 677 of lalr1.cc  */
#line 5442 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("copy-namespaces"); }
    break;

  case 722:

/* Line 677 of lalr1.cc  */
#line 5443 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("option"); }
    break;

  case 723:

/* Line 677 of lalr1.cc  */
#line 5444 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("version"); }
    break;

  case 724:

/* Line 677 of lalr1.cc  */
#line 5445 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("import"); }
    break;

  case 725:

/* Line 677 of lalr1.cc  */
#line 5446 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema"); }
    break;

  case 726:

/* Line 677 of lalr1.cc  */
#line 5447 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("module"); }
    break;

  case 727:

/* Line 677 of lalr1.cc  */
#line 5448 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("function"); }
    break;

  case 728:

/* Line 677 of lalr1.cc  */
#line 5449 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("score"); }
    break;

  case 729:

/* Line 677 of lalr1.cc  */
#line 5450 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("contains"); }
    break;

  case 730:

/* Line 677 of lalr1.cc  */
#line 5451 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("weight"); }
    break;

  case 731:

/* Line 677 of lalr1.cc  */
#line 5452 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("window"); }
    break;

  case 732:

/* Line 677 of lalr1.cc  */
#line 5453 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("distance"); }
    break;

  case 733:

/* Line 677 of lalr1.cc  */
#line 5454 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("occurs"); }
    break;

  case 734:

/* Line 677 of lalr1.cc  */
#line 5455 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("times"); }
    break;

  case 735:

/* Line 677 of lalr1.cc  */
#line 5456 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("same"); }
    break;

  case 736:

/* Line 677 of lalr1.cc  */
#line 5457 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("different"); }
    break;

  case 737:

/* Line 677 of lalr1.cc  */
#line 5458 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lowercase"); }
    break;

  case 738:

/* Line 677 of lalr1.cc  */
#line 5459 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("uppercase"); }
    break;

  case 739:

/* Line 677 of lalr1.cc  */
#line 5460 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("relationship"); }
    break;

  case 740:

/* Line 677 of lalr1.cc  */
#line 5461 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("levels"); }
    break;

  case 741:

/* Line 677 of lalr1.cc  */
#line 5462 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("language"); }
    break;

  case 742:

/* Line 677 of lalr1.cc  */
#line 5463 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("any"); }
    break;

  case 743:

/* Line 677 of lalr1.cc  */
#line 5464 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("all"); }
    break;

  case 744:

/* Line 677 of lalr1.cc  */
#line 5465 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("phrase"); }
    break;

  case 745:

/* Line 677 of lalr1.cc  */
#line 5466 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("exactly"); }
    break;

  case 746:

/* Line 677 of lalr1.cc  */
#line 5467 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("from"); }
    break;

  case 747:

/* Line 677 of lalr1.cc  */
#line 5468 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("words"); }
    break;

  case 748:

/* Line 677 of lalr1.cc  */
#line 5469 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sentences"); }
    break;

  case 749:

/* Line 677 of lalr1.cc  */
#line 5470 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sentence"); }
    break;

  case 750:

/* Line 677 of lalr1.cc  */
#line 5471 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("paragraph"); }
    break;

  case 751:

/* Line 677 of lalr1.cc  */
#line 5472 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("replace"); }
    break;

  case 752:

/* Line 677 of lalr1.cc  */
#line 5473 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("modify"); }
    break;

  case 753:

/* Line 677 of lalr1.cc  */
#line 5474 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("first"); }
    break;

  case 754:

/* Line 677 of lalr1.cc  */
#line 5475 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("insert"); }
    break;

  case 755:

/* Line 677 of lalr1.cc  */
#line 5476 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("before"); }
    break;

  case 756:

/* Line 677 of lalr1.cc  */
#line 5477 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("after"); }
    break;

  case 757:

/* Line 677 of lalr1.cc  */
#line 5478 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("revalidation"); }
    break;

  case 758:

/* Line 677 of lalr1.cc  */
#line 5479 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("with"); }
    break;

  case 759:

/* Line 677 of lalr1.cc  */
#line 5480 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("nodes"); }
    break;

  case 760:

/* Line 677 of lalr1.cc  */
#line 5481 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("rename"); }
    break;

  case 761:

/* Line 677 of lalr1.cc  */
#line 5482 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("last"); }
    break;

  case 762:

/* Line 677 of lalr1.cc  */
#line 5483 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("delete"); }
    break;

  case 763:

/* Line 677 of lalr1.cc  */
#line 5484 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("into"); }
    break;

  case 764:

/* Line 677 of lalr1.cc  */
#line 5485 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("simple"); }
    break;

  case 765:

/* Line 677 of lalr1.cc  */
#line 5486 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sequential"); }
    break;

  case 766:

/* Line 677 of lalr1.cc  */
#line 5487 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("updating"); }
    break;

  case 767:

/* Line 677 of lalr1.cc  */
#line 5488 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("deterministic"); }
    break;

  case 768:

/* Line 677 of lalr1.cc  */
#line 5489 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("nondeterministic"); }
    break;

  case 769:

/* Line 677 of lalr1.cc  */
#line 5490 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ordered"); }
    break;

  case 770:

/* Line 677 of lalr1.cc  */
#line 5491 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("unordered"); }
    break;

  case 771:

/* Line 677 of lalr1.cc  */
#line 5492 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("returning"); }
    break;

  case 772:

/* Line 677 of lalr1.cc  */
#line 5493 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("block"); }
    break;

  case 773:

/* Line 677 of lalr1.cc  */
#line 5494 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("exit"); }
    break;

  case 774:

/* Line 677 of lalr1.cc  */
#line 5495 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("loop"); }
    break;

  case 775:

/* Line 677 of lalr1.cc  */
#line 5496 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("while"); }
    break;

  case 776:

/* Line 677 of lalr1.cc  */
#line 5497 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("break"); }
    break;

  case 777:

/* Line 677 of lalr1.cc  */
#line 5498 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("continue"); }
    break;

  case 778:

/* Line 677 of lalr1.cc  */
#line 5499 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("try"); }
    break;

  case 779:

/* Line 677 of lalr1.cc  */
#line 5500 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("catch"); }
    break;

  case 780:

/* Line 677 of lalr1.cc  */
#line 5501 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("eval"); }
    break;

  case 781:

/* Line 677 of lalr1.cc  */
#line 5502 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("using"); }
    break;

  case 782:

/* Line 677 of lalr1.cc  */
#line 5503 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("set"); }
    break;

  case 783:

/* Line 677 of lalr1.cc  */
#line 5504 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("index"); }
    break;

  case 784:

/* Line 677 of lalr1.cc  */
#line 5505 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("unique"); }
    break;

  case 785:

/* Line 677 of lalr1.cc  */
#line 5506 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("non"); }
    break;

  case 786:

/* Line 677 of lalr1.cc  */
#line 5507 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("on"); }
    break;

  case 787:

/* Line 677 of lalr1.cc  */
#line 5508 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("range"); }
    break;

  case 788:

/* Line 677 of lalr1.cc  */
#line 5509 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("equality"); }
    break;

  case 789:

/* Line 677 of lalr1.cc  */
#line 5510 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("manually"); }
    break;

  case 790:

/* Line 677 of lalr1.cc  */
#line 5511 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("automatically"); }
    break;

  case 791:

/* Line 677 of lalr1.cc  */
#line 5512 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("maintained"); }
    break;

  case 792:

/* Line 677 of lalr1.cc  */
#line 5513 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("decimal-format"); }
    break;

  case 793:

/* Line 677 of lalr1.cc  */
#line 5514 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("decimal-separator"); }
    break;

  case 794:

/* Line 677 of lalr1.cc  */
#line 5515 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("grouping-separator"); }
    break;

  case 795:

/* Line 677 of lalr1.cc  */
#line 5516 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("infinity"); }
    break;

  case 796:

/* Line 677 of lalr1.cc  */
#line 5517 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("minus-sign"); }
    break;

  case 797:

/* Line 677 of lalr1.cc  */
#line 5518 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("NaN"); }
    break;

  case 798:

/* Line 677 of lalr1.cc  */
#line 5519 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("percent"); }
    break;

  case 799:

/* Line 677 of lalr1.cc  */
#line 5520 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("per-mille"); }
    break;

  case 800:

/* Line 677 of lalr1.cc  */
#line 5521 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("zero-digit"); }
    break;

  case 801:

/* Line 677 of lalr1.cc  */
#line 5522 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("digit"); }
    break;

  case 802:

/* Line 677 of lalr1.cc  */
#line 5523 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("pattern-separator"); }
    break;

  case 803:

/* Line 677 of lalr1.cc  */
#line 5524 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("collection"); }
    break;

  case 804:

/* Line 677 of lalr1.cc  */
#line 5525 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("const"); }
    break;

  case 805:

/* Line 677 of lalr1.cc  */
#line 5526 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("append-only"); }
    break;

  case 806:

/* Line 677 of lalr1.cc  */
#line 5527 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("queue"); }
    break;

  case 807:

/* Line 677 of lalr1.cc  */
#line 5528 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("mutable"); }
    break;

  case 808:

/* Line 677 of lalr1.cc  */
#line 5529 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("read-only"); }
    break;

  case 809:

/* Line 677 of lalr1.cc  */
#line 5530 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("integrity"); }
    break;

  case 810:

/* Line 677 of lalr1.cc  */
#line 5531 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("constraint"); }
    break;

  case 811:

/* Line 677 of lalr1.cc  */
#line 5532 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("check"); }
    break;

  case 812:

/* Line 677 of lalr1.cc  */
#line 5533 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("key"); }
    break;

  case 813:

/* Line 677 of lalr1.cc  */
#line 5534 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("foreach"); }
    break;

  case 814:

/* Line 677 of lalr1.cc  */
#line 5535 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("foreign"); }
    break;

  case 815:

/* Line 677 of lalr1.cc  */
#line 5536 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("keys"); }
    break;

  case 816:

/* Line 677 of lalr1.cc  */
#line 5548 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 817:

/* Line 677 of lalr1.cc  */
#line 5556 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 818:

/* Line 677 of lalr1.cc  */
#line 5560 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 819:

/* Line 677 of lalr1.cc  */
#line 5567 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 820:

/* Line 677 of lalr1.cc  */
#line 5572 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 821:

/* Line 677 of lalr1.cc  */
#line 5580 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 822:

/* Line 677 of lalr1.cc  */
#line 5584 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 823:

/* Line 677 of lalr1.cc  */
#line 5591 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 824:

/* Line 677 of lalr1.cc  */
#line 5595 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 825:

/* Line 677 of lalr1.cc  */
#line 5602 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 826:

/* Line 677 of lalr1.cc  */
#line 5606 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 827:

/* Line 677 of lalr1.cc  */
#line 5613 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 828:

/* Line 677 of lalr1.cc  */
#line 5617 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 829:

/* Line 677 of lalr1.cc  */
#line 5626 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 5638 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 831:

/* Line 677 of lalr1.cc  */
#line 5642 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 832:

/* Line 677 of lalr1.cc  */
#line 5649 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 833:

/* Line 677 of lalr1.cc  */
#line 5653 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 834:

/* Line 677 of lalr1.cc  */
#line 5661 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 835:

/* Line 677 of lalr1.cc  */
#line 5669 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 5677 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 837:

/* Line 677 of lalr1.cc  */
#line 5681 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 838:

/* Line 677 of lalr1.cc  */
#line 5688 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 839:

/* Line 677 of lalr1.cc  */
#line 5692 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 840:

/* Line 677 of lalr1.cc  */
#line 5700 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 5711 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 842:

/* Line 677 of lalr1.cc  */
#line 5715 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 843:

/* Line 677 of lalr1.cc  */
#line 5723 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 5735 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 845:

/* Line 677 of lalr1.cc  */
#line 5741 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 846:

/* Line 677 of lalr1.cc  */
#line 5750 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 847:

/* Line 677 of lalr1.cc  */
#line 5754 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 848:

/* Line 677 of lalr1.cc  */
#line 5762 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 849:

/* Line 677 of lalr1.cc  */
#line 5766 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 850:

/* Line 677 of lalr1.cc  */
#line 5770 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 851:

/* Line 677 of lalr1.cc  */
#line 5777 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 852:

/* Line 677 of lalr1.cc  */
#line 5781 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 853:

/* Line 677 of lalr1.cc  */
#line 5788 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 854:

/* Line 677 of lalr1.cc  */
#line 5792 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 855:

/* Line 677 of lalr1.cc  */
#line 5800 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 856:

/* Line 677 of lalr1.cc  */
#line 5804 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 857:

/* Line 677 of lalr1.cc  */
#line 5808 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 858:

/* Line 677 of lalr1.cc  */
#line 5812 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 859:

/* Line 677 of lalr1.cc  */
#line 5816 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 860:

/* Line 677 of lalr1.cc  */
#line 5824 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 861:

/* Line 677 of lalr1.cc  */
#line 5832 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 5844 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 5856 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 864:

/* Line 677 of lalr1.cc  */
#line 5860 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 865:

/* Line 677 of lalr1.cc  */
#line 5864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 866:

/* Line 677 of lalr1.cc  */
#line 5872 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 867:

/* Line 677 of lalr1.cc  */
#line 5878 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 868:

/* Line 677 of lalr1.cc  */
#line 5888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 869:

/* Line 677 of lalr1.cc  */
#line 5892 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 870:

/* Line 677 of lalr1.cc  */
#line 5896 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 871:

/* Line 677 of lalr1.cc  */
#line 5900 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 872:

/* Line 677 of lalr1.cc  */
#line 5904 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 873:

/* Line 677 of lalr1.cc  */
#line 5908 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 874:

/* Line 677 of lalr1.cc  */
#line 5912 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 875:

/* Line 677 of lalr1.cc  */
#line 5916 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 876:

/* Line 677 of lalr1.cc  */
#line 5924 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 877:

/* Line 677 of lalr1.cc  */
#line 5928 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 878:

/* Line 677 of lalr1.cc  */
#line 5932 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 879:

/* Line 677 of lalr1.cc  */
#line 5936 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 880:

/* Line 677 of lalr1.cc  */
#line 5944 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 881:

/* Line 677 of lalr1.cc  */
#line 5950 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 882:

/* Line 677 of lalr1.cc  */
#line 5960 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 883:

/* Line 677 of lalr1.cc  */
#line 5970 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 884:

/* Line 677 of lalr1.cc  */
#line 5974 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 885:

/* Line 677 of lalr1.cc  */
#line 5982 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 5992 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 6003 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 888:

/* Line 677 of lalr1.cc  */
#line 6010 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 889:

/* Line 677 of lalr1.cc  */
#line 6014 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 890:

/* Line 677 of lalr1.cc  */
#line 6021 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 891:

/* Line 677 of lalr1.cc  */
#line 6025 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(1) - (1)].thesaurus_id_list);
        }
    break;

  case 892:

/* Line 677 of lalr1.cc  */
#line 6032 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 893:

/* Line 677 of lalr1.cc  */
#line 6037 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 894:

/* Line 677 of lalr1.cc  */
#line 6046 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 895:

/* Line 677 of lalr1.cc  */
#line 6055 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 896:

/* Line 677 of lalr1.cc  */
#line 6059 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 897:

/* Line 677 of lalr1.cc  */
#line 6066 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 898:

/* Line 677 of lalr1.cc  */
#line 6070 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 899:

/* Line 677 of lalr1.cc  */
#line 6078 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 6087 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 901:

/* Line 677 of lalr1.cc  */
#line 6094 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 902:

/* Line 677 of lalr1.cc  */
#line 6104 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 903:

/* Line 677 of lalr1.cc  */
#line 6108 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 904:

/* Line 677 of lalr1.cc  */
#line 6115 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 905:

/* Line 677 of lalr1.cc  */
#line 6121 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 906:

/* Line 677 of lalr1.cc  */
#line 6130 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 907:

/* Line 677 of lalr1.cc  */
#line 6134 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 908:

/* Line 677 of lalr1.cc  */
#line 6141 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 909:

/* Line 677 of lalr1.cc  */
#line 6146 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 6158 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 6166 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 6178 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 913:

/* Line 677 of lalr1.cc  */
#line 6186 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 914:

/* Line 677 of lalr1.cc  */
#line 6190 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 915:

/* Line 677 of lalr1.cc  */
#line 6198 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 916:

/* Line 677 of lalr1.cc  */
#line 6202 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 917:

/* Line 677 of lalr1.cc  */
#line 6206 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 918:

/* Line 677 of lalr1.cc  */
#line 6214 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 919:

/* Line 677 of lalr1.cc  */
#line 6222 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 920:

/* Line 677 of lalr1.cc  */
#line 6226 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 921:

/* Line 677 of lalr1.cc  */
#line 6230 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 922:

/* Line 677 of lalr1.cc  */
#line 6234 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 923:

/* Line 677 of lalr1.cc  */
#line 6242 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 6250 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 6262 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 926:

/* Line 677 of lalr1.cc  */
#line 6266 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 927:

/* Line 677 of lalr1.cc  */
#line 6274 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;



/* Line 677 of lalr1.cc  */
#line 11225 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1300;
  const short int
  xquery_parser::yypact_[] =
  {
      1569, -1300, -1300, -1300, -1300,  1151,   -53, -1300, -1300,   439,
   -1300, -1300, -1300, -1300,   306,   307,  9466,   369,    60,   345,
     389,    77, -1300,    12, -1300, -1300, -1300, -1300, -1300, -1300,
      91, -1300,  7740, -1300, -1300,   442, -1300,   384, -1300, -1300,
     417, -1300,   443, -1300,   445,   452, -1300,   219, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300,  9752, -1300,  7156,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, 11182, -1300, -1300, -1300, -1300, -1300, -1300,
   -1300, -1300,   428, -1300, -1300, -1300, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300,  1864, 11182, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300,   459, -1300, -1300, -1300,  8320, -1300,  8608,
   -1300, -1300, -1300, -1300, -1300, 11182, -1300, -1300,  6862, -1300,
   -1300, -1300, -1300, -1300, -1300,   463, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300,    27,   406, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300,   379,   472,   380, -1300,   410,   352,
   -1300, -1300, -1300, -1300, -1300, -1300,   513, -1300,   478,   399,
     412,   419, -1300, -1300,   507,   516, -1300,   544, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,  4804,   659,
   -1300,  5098, -1300, -1300,   396,  5392,   480,   481, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,   -19,
   -1300, -1300, -1300, -1300,    41, 11182, -1300, -1300, -1300, -1300,
   -1300, -1300,   505,   579, -1300,   672,   426,   198,   -20,   146,
     392, -1300,   624,   479,   577,   578,  5980, -1300, -1300, -1300,
     295, -1300, -1300,  6862, -1300,   157, -1300,   529,  7156, -1300,
     529,  7156, -1300, -1300, -1300,   455, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,   275,
   -1300,   656,   348,   349,   326,   458, 11182,   458, 11182,   -48,
     637,   638,   639, 11182,   536,   569,   289,  8320, -1300, -1300,
     337,   120,   447, 11182, -1300, -1300, -1300, -1300, -1300,   401,
   11182,   391,   397,   336,   387,   467, -1300, -1300, -1300, -1300,
   -1300,  8320,  5392,   512,  5392,    20, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,  5392, 10038,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300,   546,  5392,   416,   418,
   -1300,   582,    10,   551,  5392,    55,    40, 11182,   585, -1300,
    5392,  8030,   553, -1300, 11182, 11182, 11182,  5392,   521,  5392,
    5392, 11182,  5392,   555,   556,  5392, 10324,   558,   557,   559,
     560,   561,   562, -1300, -1300, -1300, 11182, -1300,   526,   679,
    5392,    45, -1300,   698,   537, -1300,  5392,   509, -1300,   696,
    5392,  5392,   539,  5392,  5392,  5392,  5392,   495, 11182, -1300,
   -1300, -1300, -1300,  5392,  5392,  5392, 11182, -1300, -1300, -1300,
   -1300,  1151,    77, -1300, -1300,   396,   695,  5392, -1300,  5392,
     609,    60,    12,    91,   563,   564,   567,  5392,  5392, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300,   623, -1300,   -12,  6274,
    6274,  6274, -1300,  6274,  6274, -1300,  6274, -1300,  6274, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300,  6274,  6274,   665,  6274,
    6274,  6274,  6274,  6274,  6274,  6274,  6274,  6274,  6274,  6274,
     508,   645,   646,   647, -1300, -1300, -1300,  2158, -1300, -1300,
    6862,  6862,  5392,   529, -1300, -1300,   529, -1300,  2452,   529,
     595,  2746, -1300, -1300, -1300, -1300, -1300, -1300,   636,   640,
   -1300,   345, -1300,   719, -1300, -1300, 11182, -1300, 11182,   484,
     224, 11182,   318,   590,   591,   484,   656,   625,   622, -1300,
   -1300, -1300, -1300, -1300,   -10,   519,   -29, -1300,   460, -1300,
   -1300, -1300, -1300, 11182, 11182, 11182, -1300,   635,   586, -1300,
     588,   559,   442, -1300,   587,   589,   593, -1300,     6,     9,
    3040,   594, -1300, -1300, 11182,   -14, 11182,   676,    34, -1300,
    5392, -1300,   592,  8320,   670,   729,  8320,   656,   681,   671,
   -1300,   -39, -1300,   598,   600, -1300,   601,  3334,   602,   648,
      -9, -1300,    -1,   606, -1300,   605,   607,   642, -1300,   614,
    5392,  5392,   617, -1300,    78,   124,  3628,    -3, -1300, 11182,
     679, -1300,   -33,   618, -1300, -1300, -1300, -1300,   619, -1300,
     210, -1300, -1300, -1300,    71,   121,   709,   570,   581,   -30,
   -1300,   666,  5686, -1300,   628,   626,    82, -1300, -1300,   620,
   -1300,   774, -1300, -1300,   -15, 11182,   641,  5392,   699, -1300,
   -1300,   701, 10610,   704,  5392,   705,     4,   688,   -27,   579,
   -1300, -1300, -1300, -1300, -1300,  6274, -1300, -1300, -1300,    13,
     -20,   -20,   310,   146,   146,   146,   146,   392,   392, -1300,
   -1300, 10610, 10610, 11182, 11182, -1300,   643, -1300, -1300,   634,
   -1300, -1300, -1300,   172, -1300, -1300,   177,   325,   351,   207,
   -1300,   345,   345, -1300, -1300, -1300, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300,   484, -1300,   706, 10896,   686,  5392, -1300,
   -1300, -1300,   740,   697,  5392,   656,   656,   484, -1300,   511,
     656,   300, 11182,  -131,   230,   809, -1300, -1300,   554,   238,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,
   -1300,   -10,   103,   350, -1300,   616,   247,   -21,   545,   656,
   -1300, -1300, -1300, -1300,   691, 11182, -1300, 11182, -1300, -1300,
     663, -1300,     2,   597, -1300, -1300,   356,   -14,   740, 10610,
     727,   752,   673,   652,   721,   656,   694,   725,   760,   656,
     739,  5392,   718,   -23,   708, -1300, -1300, -1300,   680, -1300,
    5392,   742,  5392,  5392,   717, -1300,   763,   767,  5392, -1300,
     687,   689,   730, 11182, -1300, 11182, -1300, -1300,   702,  5392,
     836, -1300,   222, -1300,    54, -1300, -1300,   856, -1300,   393,
    5392,  5392,  5392,   398,  5392,  5392,  5392,  5392,  5392,  5392,
     766,  5392,  5392,   569,    -7,   707,   478,   649,   738,   772,
     695,   812, -1300, -1300,  5392,   329,   785, -1300, 11182,   787,
   -1300, 11182,   741,   743, 10896,   744, -1300,   187, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, 11182, -1300, 11182,  5392,   751,
    5392,  5392,     5,   754, -1300,  5392,    13,    48,   335, -1300,
     621,    44,   644,   650, -1300, -1300,   447, -1300,   651,  -126,
   -1300, -1300, -1300,   758, -1300, -1300, -1300,  5392, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300,  5392, -1300,   366,   381, -1300,
     876,   448, -1300, -1300, -1300,  5392, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300,   630, -1300, -1300,   877, -1300, -1300, -1300,
   -1300, -1300,   249,   878, -1300,    59, -1300, -1300, -1300,   557,
     307,   560,   561,   562,   472,   675,   187,   682,   683,  6568,
     627,   611,   103, -1300,   693,   723,  3922,   735,   736,   779,
     745,   746, -1300,  5392,   777, -1300,   805,   806,  5392, 11182,
     314,   848, -1300, -1300, -1300, -1300, -1300, -1300, 10610, -1300,
    5392,   656,   819, -1300, -1300, -1300,   656,   819, 11182, -1300,
    5392,  5392,   788,  4216, -1300, -1300, 11182, -1300, -1300,  5392,
    5392,   425, -1300,   -24,  9180,   436, -1300,   750, -1300, -1300,
    4510,   749,   753, -1300, -1300, -1300,   804, -1300,    65, -1300,
   -1300,   924, -1300, -1300, 11182, -1300, -1300,   327, -1300, -1300,
   -1300,   755,   711,   713, -1300, -1300, -1300,   714,   715, -1300,
   -1300, -1300, -1300, -1300,   716, 11182,   756, -1300,   800, -1300,
     569, -1300, -1300, -1300,  7450,   649, -1300,  5392, 11182,   785,
   -1300,   656, -1300,   520, -1300,    23,   842, -1300,  5392,   846,
     699, -1300,  8894,   769,   770,   771, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300,  5392, -1300, -1300,  5392,   811,  5392,   778,
     780, -1300,    13,   712, -1300, -1300,   148, -1300,   288,   -26,
     720,    13,   288,  6274, -1300,    29, -1300, -1300, -1300, -1300,
   -1300, -1300,    13,   813,   684,   519,   -26, -1300, -1300,   677,
     889, -1300, -1300, -1300, -1300, -1300,   789, -1300, -1300, -1300,
    5392, -1300, -1300, -1300, -1300, -1300,   942,   185,   945,   185,
     722,   879, -1300, -1300, -1300, -1300,   822, 11182,   737,   675,
    6568, -1300, -1300,   791, -1300, -1300, -1300, -1300, -1300, -1300,
    5392, 11182, 11182, -1300,   388, -1300,  5392, -1300,   867,   898,
     656,   819, -1300, -1300, -1300,  5392, -1300,   814, -1300, -1300,
   -1300,   815, -1300,  5392,  5392, 11182,   816,   -31, -1300, -1300,
   -1300,   823, -1300, -1300,   836, 11182,   408, -1300,   836, 11182,
   -1300, -1300,  5392,  5392,  5392,  5392,  5392, -1300,  5392,  5392,
   -1300, -1300,   179, -1300,   824, -1300, -1300, -1300, -1300,   842,
   -1300, -1300, -1300,   656, -1300, -1300,   902,   825, -1300,   196,
   -1300, -1300, -1300, -1300, -1300,  5392, -1300, -1300, -1300, -1300,
     826,  6274, -1300, -1300, -1300, -1300, -1300,    64,  6274,  6274,
     225, -1300,   644, -1300,    24, -1300,   650,    13,   849, -1300,
   -1300,   724, -1300, -1300, -1300, -1300, -1300,   204, -1300,   252,
     252, -1300,   185, -1300, -1300,   213, -1300,   971,   -26,   827,
     899, -1300,  6568,   -69,   726, -1300,   840, -1300, -1300, -1300,
     958, -1300, -1300,  5392,   656, -1300, -1300, -1300,  5392, -1300,
   -1300,   919,  5392, 11182,  5392, -1300,   -18,   836, 11182,   820,
     836, -1300, -1300, -1300, -1300, -1300, -1300, -1300,   897,  7450,
   -1300, -1300, -1300, -1300, 10610, -1300, 10610,   922, -1300, -1300,
     146,  6274,  6274,   310,   253, -1300, -1300, -1300, -1300, -1300,
   -1300,  5392, -1300, -1300, -1300, -1300, -1300,   991, -1300, -1300,
   -1300,   757, -1300,   879,   911, -1300,   925, 11182,   904,   797,
   11182,  6568,   905, -1300,   819, -1300, 10610, -1300,   843, -1300,
     170,   281, -1300,   835,   836, -1300,   837, 11182, -1300, -1300,
   -1300, 10610,   310,   310,  6274,   851, -1300, -1300, -1300,  6568,
   11182,   731, 11182,   912,   810,   911, 11182,   853,  5392, -1300,
   -1300,   944,   256, -1300, -1300, -1300, -1300,   858,   291, -1300,
   -1300, -1300,   845, -1300,   215, -1300,   310, -1300, -1300,   842,
    5392,   747, 11182,   926, -1300,  5392, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300,   927,   891, -1300, -1300,   748,   761,
   11182, -1300, 11182, -1300,   768,  5392,   775,   221,  6568, -1300,
    6568,   928,   891, -1300,   847, 11182, -1300,   762,   863, 11182,
     891,   829, -1300,   931, 11182,   776,  6568, -1300
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   411,   412,   612,   565,   717,   726,   631,   629,   617,
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
     567,    57,   190,   191,   193,   192,   194,   195,   196,   408,
     613,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,   108,
       0,     0,     0,     0,   103,   104,   105,   106,   113,     0,
       0,     0,     0,     0,     0,     0,   101,   158,   161,   164,
     163,     0,     0,     0,     0,     0,   717,   726,   617,   635,
     618,   619,   780,   666,   727,   621,   724,   676,   667,   623,
     625,   782,   687,   626,   627,   705,   616,   688,     0,     0,
     769,   770,   614,   762,   622,   754,   760,   751,   653,   772,
     776,   777,   773,   775,   778,   781,     0,     0,     0,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,   608,
       0,     0,     0,   609,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   617,   619,
     623,   626,   616,   398,   408,   434,     0,   435,     0,   460,
       0,     0,   373,     0,     0,   376,     0,     0,   489,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   148,
     145,   156,   157,     0,     0,     0,     0,     3,     1,     5,
       7,     0,     0,    13,    10,    15,    16,     0,   180,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   202,
     221,   217,   223,   218,   220,   219,   226,   227,     0,     0,
       0,     0,   363,     0,     0,   361,     0,   313,     0,   362,
     355,   360,   359,   358,   357,   356,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   351,   350,   347,     0,   371,   375,
       0,     0,     0,   385,   417,   388,   387,   399,     0,   414,
       0,     0,   607,    76,    61,    62,   139,   140,     0,     0,
     160,     0,   159,     0,    67,    68,     0,   162,     0,     0,
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
       0,   611,     0,     0,   206,   207,     0,   212,   173,     0,
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
     601,   610,   279,   266,     0,   572,     0,     0,   236,   840,
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
     -1300, -1300,   807, -1300,   828,   831, -1300,   808, -1300,   515,
     518,  -514, -1300,   413,  -298, -1300, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,  -885,
   -1300, -1300, -1300, -1300,    35,   227,   692, -1300, -1300,   669,
   -1300,     7,  -843, -1300,  -430,  -431, -1300, -1300,  -582, -1300,
    -876, -1300, -1300,   -90, -1300, -1300, -1300, -1300, -1300,   231,
     700, -1300, -1300, -1300,   193,   631, -1299,   839,   -94, -1300,
    -538,    32, -1300, -1300, -1300, -1300,   199, -1300, -1300,   801,
   -1300, -1300, -1300, -1300, -1300,   116,  -510,  -661, -1300, -1300,
   -1300,   -17, -1300, -1300,  -196,     0,   -89, -1300, -1300, -1300,
     -97, -1300, -1300,   131,   -92, -1300, -1300,   -88, -1160, -1300,
     603,   -11, -1300, -1300,    -8, -1300, -1300, -1300,   -22, -1300,
   -1300,   542,   538, -1300,  -521, -1300, -1300,  -577,    70,  -576,
      58,    63, -1300, -1300, -1300, -1300, -1300,   796, -1300, -1300,
   -1300, -1300,  -758,  -305, -1052, -1300,  -110, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300,   -41, -1147, -1300, -1300,   262,   -13,
   -1300,  -750, -1300, -1300, -1300, -1300, -1300, -1300, -1300,   493,
   -1300,  -911, -1300,   -32, -1300,   390,  -707, -1300, -1300, -1300,
   -1300, -1300,  -421,  -413, -1063, -1015, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300,   317,  -645,  -772,    46,
    -767, -1300,  -782,  -760, -1300, -1300, -1300, -1300, -1300, -1300,
   -1300,   703,   710,  -439,   237,    86, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,
     -46, -1300, -1300,   -58, -1300,  -368,  -102, -1300,   -16, -1300,
    -961, -1300, -1300, -1300,  -100,  -109,  -255,   127, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,
   -1300,   -99, -1300, -1300, -1300,  -247,   123,   269, -1300, -1300,
   -1300, -1300, -1300,    76, -1300, -1300, -1224, -1300, -1300, -1300,
    -736, -1300,  -125, -1300,  -259, -1300, -1300, -1300, -1300, -1182,
   -1300,   -87, -1300
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   823,   824,   825,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,  1102,
     687,   264,   265,   829,   830,   831,  1168,   266,   405,   406,
     267,  1065,   864,   268,  1474,  1475,   269,   270,   463,   271,
     520,   742,   954,  1169,   272,   273,   274,   275,   276,   407,
     408,   409,   410,   678,   679,  1145,  1026,   277,   278,   539,
     279,   280,   281,   549,   461,   886,   887,   282,   550,   283,
     552,   284,   285,   286,   556,   557,  1090,   767,   287,   689,
     746,   690,   675,  1091,  1092,  1093,   747,   553,   554,   969,
     970,  1344,   555,   966,   967,  1184,  1185,  1186,  1187,   288,
     700,   701,   289,  1121,  1122,  1123,   290,  1125,  1126,   291,
     292,   293,   294,   775,   295,  1214,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   576,   577,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   603,   604,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   803,
     335,   336,   337,  1147,   720,   721,   722,  1492,  1527,  1528,
    1521,  1522,  1529,  1523,  1148,  1149,   338,   339,  1150,   340,
     341,   342,   343,   344,   345,   346,  1012,   768,   976,  1199,
     977,  1349,   978,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   707,  1078,   357,   358,   359,   360,   980,
     981,   982,   983,   361,   362,   363,   364,   365,   366,   739,
     740,   367,  1175,  1176,  1332,  1103,   472,   368,   369,   370,
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
       456,   754,   979,   613,   782,   598,   783,   784,   785,   786,
     498,  1013,  1013,   932,  1107,   501,   473,  1266,   505,  1010,
    1011,   998,   752,  1146,  1073,  1340,  1341,  1331,   493,   999,
     902,   979,   979,  1440,     4,  1210,   883,  1401,   841,   809,
     771,   842,   772,   773,  1477,   774,   903,   776,   766,   507,
     762,   487,   724,   494,  1381,   777,   778,   914,   661,  1031,
     862,   612,  1139,  1140,   763,  1367,   979,   495,  1072,     4,
    1490,  1303,   950,  1139,  1140,   540,   612,   762,   662,   763,
    1173,   541,  1423,   537,  1320,   843,   542,   537,   762,   499,
     933,   762,   582,   911,   543,  1170,   901,   684,   688,   911,
     411,   473,  1066,   503,   465,   989,   544,   993,   875,   504,
    1451,   877,  1111,   991,   624,  1239,  1240,  1096,    75,   583,
    1216,   958,   458,   676,  1181,   467,  1047,   459,   764,   979,
      86,   468,   584,   466,  1059,  1216,   890,  1048,  1241,   913,
    1060,   661,  1083,  1183,   988,  1206,   625,  1424,   685,  1478,
    1053,  1248,  1141,    75,  1304,   100,   934,  1491,  1061,   995,
     939,   662,   996,  1141,   538,    86,   585,  1054,   962,  1062,
    1142,   912,  1143,   460,  1519,   579,  1171,   929,  1139,  1442,
     923,  1142,   119,  1143,   959,   876,  1452,  1034,   878,   677,
     100,  1217,   580,   686,   995,  1063,   884,   996,   951,   663,
     680,   863,   545,   599,   105,   546,  1217,  1194,   683,   863,
     943,   680,   725,   891,   979,   105,  1471,   119,  1406,   547,
     117,  1291,  1262,  1136,  1368,  1369,   925,  1146,   765,  1027,
    1028,   117,  1479,   508,   885,   844,  1146,  1084,   998,   998,
     765,  1144,  1112,  1095,   765,   548,   999,   999,   845,  1508,
     846,  1359,  1315,  1320,   994,   765,  1563,   924,   992,   144,
    1519,   847,   848,   849,  1139,   850,   997,   851,   838,   558,
     144,   765,   765,  1576,  1017,  1218,  1219,   605,  1220,  1017,
     607,  1582,   940,   941,   125,   638,  1142,  1455,  1143,  1139,
    1218,  1219,  1498,  1220,  1456,  1222,  1520,   942,  1446,  1139,
    1221,  1525,   494,   926,  1457,   494,   537,  1223,   481,   657,
    1222,  1525,  1066,   826,  1389,  1467,   680,  1554,   658,   898,
     660,  1064,  1223,  1571,  1196,  1025,  1287,   633,  1438,  1053,
     634,  1207,   944,   945,   937,  1139,  1140,  1024,   979,   586,
    1256,   600,   601,  1256,   666,  1137,  1054,   946,   587,   579,
    1476,  1018,  1306,  1025,   827,  1197,  1019,  1257,  1362,   828,
     621,  1086,   623,   635,   979,   482,   580,   629,  1087,   696,
     682,   473,  1142,  1198,  1143,  1447,   693,   646,  1390,  1556,
    1463,  1439,  1548,   703,   648,   705,   706,  1055,   709,   581,
     636,   712,  1468,   938,  1555,   473,  1363,  1142,  1258,  1143,
    1572,  1258,   680,  1086,   579,  1146,   723,  1142,  1526,  1143,
    1087,  1138,   728,   610,   642,   643,  1139,  1140,  1551,  1180,
    1348,   580,   531,   669,   611,  1141,  1405,   680,  1088,  1476,
    1181,   745,   979,   483,   484,  1086,  1077,   680,  1080,   532,
    1182,   597,  1087,  1142,  1504,  1143,   752,   763,   833,  1183,
     637,   691,   414,   834,   998,   473,   415,  1476,   698,   699,
     702,   579,   999,   998,   119,   708,  1020,  1037,  1038,  1089,
     715,   999,  1041,   680,   998,  1524,  1530,   105,   580,   763,
     702,  1212,   999,  1021,  1131,   618,  1132,  1049,  1455,   671,
     797,   798,  1022,   117,   462,  1456,  1247,   475,  1050,   376,
     619,  1075,   741,   796,   119,  1457,  1141,  1524,   799,  1023,
     748,  1249,   519,  1530,  1319,   457,  1573,   380,  1574,   381,
    1120,   588,   614,   616,  1142,  1029,  1143,  1250,   382,  1484,
     476,  1124,   144,  1301,  1587,   589,   615,   617,   464,  1029,
    1070,   496,   731,   732,  1307,   734,   735,   736,   737,  1071,
    1364,   639,   640,   641,   680,   743,   744,  1365,   105,   813,
     814,   815,   816,   817,   818,   819,   820,   821,   822,   753,
     516,  1042,  1043,  1044,   117,   517,   880,  1045,   827,   759,
     760,   894,   606,   828,   897,   412,   892,   609,   413,   477,
     800,   474,   478,   800,   479,  1428,   800,   510,   513,   511,
     514,   480,   602,   908,   608,   500,   620,  1426,   622,   506,
     811,  1429,   812,   144,   509,   832,   920,   921,  1152,   998,
    1153,   512,   928,  1157,   519,  1158,   518,   999,   515,   388,
     651,   652,  1039,  1040,   521,  1067,  1068,   866,   867,   868,
     802,  1337,  1338,   802,   787,   788,  1374,   522,   955,   780,
     781,   789,   790,  1464,  1465,   523,   524,   526,   882,   528,
     888,   389,   525,   535,   536,   559,   560,   473,   590,   578,
     473,   591,  1499,   592,  1500,   593,   602,   612,   626,   376,
     628,   630,   631,   649,   979,   653,   979,   644,   647,   650,
     391,   659,   670,   598,   672,   674,   673,   680,   692,   697,
     704,   710,   711,   930,   716,   718,   413,   719,   439,   471,
     478,   486,  1387,   726,  1517,   729,   727,   730,   733,   738,
    1493,   751,   755,  1496,   756,   761,   979,   757,  1539,  1535,
     758,   779,   791,  1289,   792,   793,   794,   804,   807,   963,
     810,   979,   808,   835,   836,   839,   984,   840,   654,   394,
     395,   396,   397,   865,   398,   399,   655,   401,   402,   861,
     869,   895,   870,   403,   871,   889,   872,   896,   873,   874,
     881,   893,   899,   900,   904,   984,   984,   984,   984,   905,
     906,   909,   915,   910,   916,  1450,   917,  1532,   918,   965,
     919,  1453,  1454,   922,   935,   936,   986,   561,   947,   949,
     948,   952,   957,   960,   964,   562,   563,   956,   564,   375,
     984,  1016,   968,  1336,   971,   376,   565,   985,   987,  1015,
     566,   828,   567,   377,  1127,   378,  1046,   568,   990,   762,
    1051,  1030,  1035,   380,  1052,   381,  1069,  1076,  1074,  1082,
     676,  1098,  1100,   569,   382,  1085,  1101,  1104,   383,  1099,
    1105,  1106,  1108,  1110,  1113,  1116,  1114,  1119,  1120,  1079,
    1033,  1079,  1124,  1128,  1135,  1129,  1036,   570,   571,   572,
     573,   574,   575,   984,  1502,  1503,  1130,  1151,  1133,  1165,
     384,   385,   961,  1172,  1177,  1178,   635,  1188,  1174,  1190,
    1192,  1203,  1193,  1195,  1208,  1244,  1232,     4,  1255,  1260,
    1213,  1209,  1264,  1265,  1233,   863,  1271,   708,  1267,   708,
    1254,  1268,  1236,  1270,  1274,  1275,  1276,  1280,  1281,  1282,
    1286,  1290,  1415,  1295,  1277,  1278,  1309,  1536,  1312,  1314,
    1317,  1246,  1313,  1109,  1328,  1329,   388,  1322,  1321,  1323,
    1324,  1325,  1115,  1181,  1117,  1118,  1326,  1343,  1350,  1351,
    1352,  1355,  1189,  1377,  1357,   558,  1361,  1382,   984,  1358,
    1378,  1134,  1384,  1388,  1371,  1386,  1394,  1407,   389,  1200,
    1053,  1201,  1154,  1155,  1156,  1443,  1159,  1160,  1161,  1162,
    1163,  1164,  1273,  1166,  1167,  1402,  1413,  1397,  1404,  1414,
    1417,  1444,  1469,  1418,  1422,  1461,   965,   391,  1462,  1425,
    1441,  1473,  1449,  1481,  1445,  1482,  1472,  1480,  1486,  1495,
    1497,  1501,  1506,  1509,  1510,  1513,  1507,  1512,  1516,  1297,
    1202,  1518,  1204,  1205,  1531,  1542,  1533,  1537,  1543,   392,
    1540,  1545,  1547,  1550,  1553,  1564,  1311,  1025,  1577,  1560,
    1562,  1575,  1580,  1579,  1584,   527,  1558,  1583,   837,  1245,
     749,  1515,   533,   750,  1032,   393,   394,   395,   396,   397,
    1565,   398,   399,   400,   401,   402,  1252,  1253,  1568,   529,
     403,   404,   530,  1284,   656,  1570,  1586,   632,  1538,  1269,
    1330,   627,   984,  1097,   534,   551,  1094,  1191,  1411,  1335,
    1285,  1292,   691,  1345,   681,  1179,  1342,  1339,   770,   717,
     702,   769,   596,  1308,   806,  1298,  1316,  1552,   984,  1549,
     931,  1014,  1263,  1302,  1081,  1279,  1251,  1333,   664,  1327,
    1283,  1372,  1460,  1376,  1211,   665,  1375,  1459,  1318,  1235,
    1058,  1261,  1288,  1466,  1396,  1373,     0,     0,     0,     0,
       0,     0,  1293,  1294,     0,     0,     0,     0,     0,   741,
       0,  1299,  1300,     0,     0,     0,     0,     0,   494,     0,
       0,     0,   748,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   984,     0,     0,     0,
     371,   372,     0,   373,   374,     0,   375,     0,     0,     0,
       0,     0,   376,     0,     0,     0,     0,     0,     0,     0,
     377,     0,   378,   379,     0,     0,     0,     0,     0,  1334,
     380,     0,   381,     0,     0,     0,     0,     0,     0,     0,
     965,   382,     0,     0,     0,   383,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1353,     0,     0,  1354,     0,
    1356,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1403,     0,     0,     0,     0,     0,   384,   385,   386,
       0,     0,     0,     0,     0,  1409,  1410,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1421,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1427,
       0,     0,     0,  1430,   387,     0,     0,     0,     0,     0,
       0,     0,  1408,   388,     0,     0,     0,     0,  1412,     0,
       0,     0,     0,     0,     0,     0,     0,  1416,     0,     0,
       0,     0,     0,     0,     0,  1419,  1420,     0,     0,     0,
       0,     0,     0,     0,     0,   389,     0,     0,     0,     0,
       0,     0,     0,     0,  1431,  1432,  1433,  1434,  1435,     0,
    1436,  1437,     0,     0,   390,     0,     0,  1505,     0,     0,
       0,     0,     0,     0,   391,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1448,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   392,  1488,     0,     0,
       0,     0,  1494,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   494,     0,     0,     0,     0,   984,     0,
     984,     0,   393,   394,   395,   396,   397,     0,   398,   399,
     400,   401,   402,     0,     0,  1483,     0,   403,   404,     0,
    1485,     0,     0,     0,  1487,     0,  1489,     0,     0,     0,
       0,  1511,     0,     0,  1514,     0,     0,     0,     0,     0,
     984,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1534,     0,     0,     0,   984,     0,     0,     0,     0,
       0,     0,     0,     0,   984,     0,  1541,     0,     0,     0,
    1544,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1559,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1566,     0,  1567,     0,     0,     0,
    1546,     0,     0,     0,     0,     0,     0,     0,     0,  1578,
       0,     0,     0,  1581,     0,     0,     0,     0,  1585,     0,
       0,     0,  1557,     0,     0,     0,     0,  1561,     0,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     0,
       4,     0,     0,     0,     0,     5,     6,  1569,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,    26,    27,
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
       0,   120,   121,   122,     0,     0,     0,   123,     0,   124,
     125,   126,     0,   127,   128,   129,     0,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,   142,   143,   144,     0,   145,   146,     0,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,     0,   189,   190,   191,     0,   192,   193,   194,   195,
     196,   197,     0,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     0,     4,     0,     0,     0,     0,
     416,   417,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   426,    22,    23,
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
       0,     0,   123,   497,   124,   125,   126,     0,   127,   128,
     129,     0,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,   144,
       0,   442,   146,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,   189,   190,   191,
       0,   192,   193,   194,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     0,     4,
       0,     0,     0,     0,   416,   417,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,   426,    22,    23,    24,    25,     0,    26,    27,    28,
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
     120,   121,   122,     0,   795,     0,   123,     0,   124,   125,
     126,     0,   127,   128,   129,     0,   130,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,   144,     0,   442,   146,     0,   147,   148,
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
       3,     0,     0,     4,     0,     0,     0,     0,   416,   417,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,   426,    22,    23,    24,    25,
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
     118,   119,     0,     0,   120,   121,   122,     0,     0,     0,
     123,   801,   124,   125,   126,     0,   127,   128,   129,     0,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,   144,     0,   442,
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
       0,     0,     0,     2,     3,     0,     0,     4,     0,     0,
       0,     0,   416,   417,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,   426,
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
     143,   144,     0,   442,   146,     0,   147,   148,   149,   150,
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
       0,     4,     0,     0,     0,     0,   416,   417,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   426,    22,    23,    24,    25,     0,    26,
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
       0,     0,   120,   121,   122,     0,   879,     0,   123,     0,
     124,   125,   126,     0,   127,   128,   129,     0,   130,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,   144,     0,   442,   146,     0,
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
       0,     2,     3,     0,     0,     4,     0,     0,     0,     0,
     416,   417,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   426,    22,    23,
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
     907,     0,   123,     0,   124,   125,   126,     0,   127,   128,
     129,     0,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,   144,
       0,   442,   146,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,   189,   190,   191,
       0,   192,   193,   194,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     0,     4,
       0,     0,     0,     0,   416,   417,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,   426,    22,    23,    24,    25,     0,    26,    27,    28,
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
     120,   121,   122,     0,   927,     0,   123,     0,   124,   125,
     126,     0,   127,   128,   129,     0,   130,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,   144,     0,   442,   146,     0,   147,   148,
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
       3,     0,     0,     4,     0,     0,     0,     0,   416,   417,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,   426,    22,    23,    24,    25,
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
     118,   119,     0,     0,   120,   121,   122,     0,  1272,     0,
     123,     0,   124,   125,   126,     0,   127,   128,   129,     0,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,   144,     0,   442,
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
       0,     0,     0,     2,     3,     0,     0,     4,     0,     0,
       0,     0,   416,   417,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,   426,
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
     122,     0,  1296,     0,   123,     0,   124,   125,   126,     0,
     127,   128,   129,     0,   130,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,   144,     0,   442,   146,     0,   147,   148,   149,   150,
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
       0,     4,     0,     0,     0,     0,   416,   417,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   426,    22,    23,    24,    25,     0,    26,
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
       0,     0,   120,   121,   122,     0,  1310,     0,   123,     0,
     124,   125,   126,     0,   127,   128,   129,     0,   130,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,   144,     0,   442,   146,     0,
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
       0,     2,     3,     0,     0,     4,     0,     0,     0,     0,
       5,     6,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
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
       0,     0,   123,     0,   124,   125,   126,     0,   127,   128,
     129,     0,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,   144,
       0,   145,   146,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,   189,   190,   191,
       0,   192,   193,   194,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     0,     4,
       0,     0,     0,     0,     5,     6,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,    26,    27,    28,
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
     120,   121,   122,     0,     0,     0,   123,     0,   124,   125,
     126,     0,   127,   128,   129,     0,   130,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,   144,     0,   442,   146,     0,   147,   148,
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
       3,     0,     0,     4,     0,     0,     0,     0,   416,   417,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,   426,    22,    23,    24,    25,
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
     118,   119,     0,     0,   120,   121,   122,     0,     0,     0,
     123,     0,   124,   125,   126,     0,   127,   128,   129,     0,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,   144,     0,   442,
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
       0,     0,     0,     2,     3,     0,     0,     4,     0,     0,
       0,     0,   953,   417,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,   426,
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
     143,   144,     0,   442,   146,     0,   147,   148,   149,   150,
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
       0,     4,     0,     0,     0,     0,   416,   417,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,   422,
     423,    19,   425,   426,    22,   427,    24,    25,     0,    26,
      27,    28,    29,   428,    31,    32,    33,    34,    35,    36,
     431,    38,    39,   432,     0,    41,    42,    43,     0,   434,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,     0,    64,
      65,    66,    67,    68,    69,    70,    71,    72,     0,     0,
      73,    74,     0,     0,     0,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     0,    86,     0,    87,
      88,    89,    90,     0,    91,     0,     0,     0,   437,    93,
      94,    95,    96,     0,     0,     0,     0,     0,     0,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,   104,
     105,   594,   107,   108,     0,     0,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     0,   595,   119,
       0,     0,   120,   121,   122,     0,     0,     0,   123,     0,
     124,   125,   126,     0,   127,   128,   129,     0,   130,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,   144,     0,   442,   146,     0,
     147,   148,   149,   150,   151,   152,   153,   443,   155,   445,
     157,   446,   447,   160,   161,   162,   163,   164,   165,   448,
     167,   449,   450,   451,   452,   172,   173,   453,   454,   176,
     455,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,   190,   191,     0,   192,   193,   194,
     195,   196,   197,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     0,     4,     0,     0,     0,     0,
     416,   417,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,   422,   423,    19,   425,   426,    22,   427,
      24,    25,     0,    26,    27,    28,    29,   428,    31,    32,
      33,    34,    35,    36,   431,    38,    39,   432,     0,    41,
      42,    43,     0,   434,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,     0,     0,    73,    74,     0,     0,     0,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       0,    86,     0,    87,    88,    89,    90,     0,    91,     0,
       0,     0,   437,    93,    94,    95,    96,     0,     0,     0,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   103,
       0,     0,     0,   104,   105,   106,   107,   108,     0,     0,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,     0,   118,   119,     0,     0,   120,   121,   122,     0,
       0,     0,   123,     0,   124,   125,   126,     0,   127,   128,
     129,     0,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,   144,
       0,   442,   146,     0,   147,   148,   149,   150,   151,   152,
     153,   443,   155,   445,   157,   446,   447,   160,   161,   162,
     163,   164,   165,   448,   167,   449,   450,   451,   452,   172,
     173,   453,   454,   176,   455,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,   189,   190,   191,
       0,   192,   193,   194,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     0,     4,
       0,     0,     0,     0,   416,   417,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,   422,   423,    19,
     425,   426,    22,   427,    24,    25,     0,    26,    27,    28,
      29,   428,    31,    32,    33,    34,    35,    36,   431,    38,
      39,   432,     0,    41,    42,    43,     0,   434,    46,   435,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,     0,    64,    65,    66,
      67,    68,    69,    70,    71,    72,     0,     0,    73,    74,
       0,     0,     0,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     0,    86,     0,    87,    88,    89,
      90,     0,    91,     0,     0,     0,   437,    93,    94,    95,
      96,     0,     0,     0,     0,     0,     0,    97,    98,    99,
     100,   101,   102,   103,     0,     0,     0,   104,   105,     0,
     107,   108,     0,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,     0,     0,     0,     0,     0,
     120,   121,   122,     0,     0,     0,   123,     0,   124,   125,
     126,     0,   127,   128,   129,     0,   130,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,   144,     0,   442,   146,     0,   147,   148,
     149,   150,   151,   152,   153,   443,   155,   445,   157,   446,
     447,   160,   161,   162,   163,   164,   165,   448,   167,   449,
     450,   451,   452,   172,   173,   453,   454,   176,   455,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,   191,     0,   192,   193,   194,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     0,     4,     0,     0,     0,     0,   416,   417,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,   422,   423,    19,   425,   426,    22,   427,    24,    25,
       0,    26,    27,    28,    29,   428,    31,    32,    33,    34,
      35,    36,   431,    38,    39,   432,     0,    41,    42,    43,
       0,   434,    46,   435,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
       0,    64,    65,    66,    67,    68,    69,    70,    71,    72,
       0,     0,    73,    74,     0,     0,     0,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     0,    86,
       0,    87,    88,    89,    90,     0,    91,     0,     0,     0,
     437,    93,    94,    95,    96,     0,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   103,     0,     0,
       0,   104,   105,     0,   107,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,     0,
       0,     0,     0,     0,   120,   121,   122,     0,     0,     0,
     123,     0,   124,   125,   126,     0,     0,     0,   129,     0,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,   144,     0,   442,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   443,
     155,   445,   157,   446,   447,   160,   161,   162,   163,   164,
     165,   448,   167,   449,   450,   451,   452,   172,   173,   453,
     454,   176,   455,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,   191,     0,   192,
     193,   194,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     0,     0,     0,     0,
       0,     0,   416,   417,     0,     7,     8,   488,    10,    11,
      12,    13,   419,    15,   489,   422,   423,   424,   425,   426,
      22,   427,    24,    25,     0,    26,    27,    28,    29,   428,
      31,   490,    33,    34,    35,    36,   431,    38,    39,   432,
       0,    41,   491,    43,     0,   434,    46,   435,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,     0,     0,    63,     0,    64,    65,    66,   492,     0,
       0,    70,    71,    72,     0,     0,     0,    74,     0,     0,
       0,     0,    76,    77,    78,     0,     0,    81,    82,     0,
       0,     0,     0,     0,     0,    87,    88,    89,    90,     0,
      91,     0,     0,     0,   437,    93,    94,     0,     0,     0,
       0,     0,     0,     0,     0,    97,    98,    99,     0,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   107,   108,
       0,     0,     0,     0,   109,   110,   111,   112,   440,   114,
     115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     122,     0,     0,     0,   123,     0,   124,   125,     0,     0,
       0,     0,   129,     0,   130,     0,   131,   132,   133,   134,
     441,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,     0,     0,   442,   146,     0,   147,   148,   149,   150,
     151,   152,   153,   443,   155,   445,   157,   446,   447,   160,
     161,   162,   163,   164,   165,   448,   167,   449,   450,   451,
     452,   172,   173,   453,   454,   176,   455,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,   191,     0,   192,   193,   194,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       0,     0,     0,     0,     0,     0,   416,   417,     0,     7,
       8,   418,    10,    11,    12,    13,   419,   420,   421,   422,
     423,   424,   425,   426,    22,   427,    24,    25,     0,    26,
      27,    28,    29,   428,    31,   429,    33,    34,   430,    36,
     431,    38,    39,   432,     0,    41,   433,    43,     0,   434,
      46,   435,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,     0,     0,    63,     0,    64,
      65,    66,   436,     0,     0,    70,    71,    72,     0,     0,
       0,    74,     0,     0,     0,     0,    76,    77,    78,     0,
       0,    81,    82,     0,     0,     0,     0,     0,     0,    87,
      88,    89,    90,     0,    91,     0,     0,     0,   437,    93,
      94,     0,     0,     0,     0,     0,     0,     0,     0,    97,
      98,    99,     0,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   107,   108,     0,     0,     0,     0,   109,   110,
     111,   112,   440,   114,   115,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   122,     0,     0,     0,   123,     0,
     124,     0,     0,     0,     0,     0,   129,     0,   130,     0,
     131,   132,   133,   134,   441,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,     0,     0,   442,   146,     0,
     147,   148,   149,   150,   151,   152,   153,   443,   444,   445,
     157,   446,   447,   160,   161,   162,   163,   164,   165,   448,
     167,   449,   450,   451,   452,   172,   173,   453,   454,   176,
     455,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,   190,   191,     0,   192,   193,   194,
     195,   196,   197,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   469,     0,     0,     0,     3,     0,
       0,     0,     0,     0,     0,     0,   416,   417,     0,     7,
       8,   418,    10,    11,    12,    13,   419,   420,   421,   422,
     423,   424,   425,   426,    22,   427,    24,    25,     0,    26,
      27,    28,    29,   428,    31,   429,    33,    34,   430,    36,
     431,    38,    39,   432,     0,    41,   433,    43,     0,   434,
      46,   435,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,     0,     0,    63,     0,    64,
      65,    66,   436,     0,     0,    70,    71,    72,     0,     0,
       0,    74,     0,     0,     0,     0,    76,    77,    78,     0,
       0,    81,    82,     0,     0,     0,     0,     0,     0,    87,
      88,    89,    90,     0,    91,     0,     0,     0,   437,    93,
      94,     0,     0,     0,     0,     0,     0,     0,     0,    97,
      98,    99,     0,   101,   102,   103,   470,     0,     0,   471,
       0,     0,   107,   108,     0,     0,     0,     0,   109,   110,
     111,   112,   440,   114,   115,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   122,     0,     0,     0,   123,     0,
     124,     0,     0,     0,     0,     0,     0,     0,   130,     0,
     131,   132,   133,   134,   441,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,     0,     0,   442,   146,     0,
     147,   148,   149,   150,   151,   152,   153,   443,   444,   445,
     157,   446,   447,   160,   161,   162,   163,   164,   165,   448,
     167,   449,   450,   451,   452,   172,   173,   453,   454,   176,
     455,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,   190,   191,     0,   192,   193,   194,
     195,   196,   197,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   469,     0,     0,     0,     3,     0,
       0,   694,     0,     0,     0,     0,   416,   417,     0,     7,
       8,   418,    10,    11,    12,    13,   419,   420,   421,   422,
     423,   424,   425,   426,    22,   427,    24,    25,     0,    26,
      27,    28,    29,   428,    31,   429,    33,    34,   430,    36,
     431,    38,    39,   432,     0,    41,   433,    43,     0,   434,
      46,   435,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,     0,     0,    63,     0,    64,
      65,    66,   436,     0,     0,    70,    71,    72,     0,     0,
       0,    74,     0,     0,     0,     0,    76,    77,    78,     0,
       0,    81,    82,     0,     0,     0,     0,     0,     0,    87,
      88,    89,    90,     0,    91,     0,     0,     0,   437,    93,
      94,     0,     0,     0,     0,     0,     0,     0,     0,    97,
      98,    99,     0,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   107,   108,     0,     0,     0,     0,   109,   110,
     111,   112,   440,   114,   115,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   122,     0,     0,     0,   123,   695,
     124,     0,     0,     0,     0,     0,     0,     0,   130,     0,
     131,   132,   133,   134,   441,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,     0,     0,   442,   146,     0,
     147,   148,   149,   150,   151,   152,   153,   443,   444,   445,
     157,   446,   447,   160,   161,   162,   163,   164,   165,   448,
     167,   449,   450,   451,   452,   172,   173,   453,   454,   176,
     455,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,   190,   191,     0,   192,   193,   194,
     195,   196,   197,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   469,     0,     0,     0,     3,     0,
       0,     0,     0,     0,     0,     0,   416,   417,     0,     7,
       8,   418,    10,    11,    12,    13,   419,   420,   421,   422,
     423,   424,   425,   426,    22,   427,    24,    25,     0,    26,
      27,    28,    29,   428,    31,   429,    33,    34,   430,    36,
     431,    38,    39,   432,     0,    41,   433,    43,     0,   434,
      46,   435,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,     0,     0,    63,     0,    64,
      65,    66,   436,     0,     0,    70,    71,    72,     0,     0,
       0,    74,     0,     0,     0,     0,    76,    77,    78,     0,
       0,    81,    82,     0,     0,     0,     0,     0,     0,    87,
      88,    89,    90,     0,    91,     0,     0,     0,   437,    93,
      94,     0,     0,     0,     0,     0,     0,     0,     0,    97,
      98,    99,     0,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   107,   108,     0,     0,     0,     0,   109,   110,
     111,   112,   440,   114,   115,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   122,     0,     0,     0,   123,     0,
     124,     0,     0,     0,     0,     0,     0,     0,   130,     0,
     131,   132,   133,   134,   441,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,     0,     0,   442,   146,     0,
     147,   148,   149,   150,   151,   152,   153,   443,   444,   445,
     157,   446,   447,   160,   161,   162,   163,   164,   165,   448,
     167,   449,   450,   451,   452,   172,   173,   453,   454,   176,
     455,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,   190,   191,     0,   192,   193,   194,
     195,   196,   197,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   502,     0,     3,     0,     0,     0,
       0,     0,     0,     0,   416,   417,     0,     7,     8,   418,
      10,    11,    12,    13,   419,   420,   421,   422,   423,   424,
     425,   426,    22,   427,    24,    25,     0,    26,    27,    28,
      29,   428,    31,   429,    33,    34,   430,    36,   431,    38,
      39,   432,     0,    41,   433,    43,     0,   434,    46,   435,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,     0,     0,    63,     0,    64,    65,    66,
     436,     0,     0,    70,    71,    72,     0,     0,     0,    74,
       0,     0,     0,     0,    76,    77,    78,     0,     0,    81,
      82,     0,     0,     0,     0,     0,     0,    87,    88,    89,
      90,     0,    91,     0,     0,     0,   437,    93,    94,     0,
       0,     0,     0,     0,     0,     0,     0,    97,    98,    99,
       0,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     107,   108,     0,     0,     0,     0,   109,   110,   111,   112,
     440,   114,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   122,     0,     0,     0,   123,     0,   124,     0,
       0,     0,     0,     0,     0,     0,   130,     0,   131,   132,
     133,   134,   441,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,     0,     0,   442,   146,     0,   147,   148,
     149,   150,   151,   152,   153,   443,   444,   445,   157,   446,
     447,   160,   161,   162,   163,   164,   165,   448,   167,   449,
     450,   451,   452,   172,   173,   453,   454,   176,   455,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,   191,     0,   192,   193,   194,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     3,     0,     0,     0,     0,     0,     0,     0,
     416,   417,     0,     7,     8,   488,    10,    11,    12,    13,
     419,    15,   489,   422,   423,   972,   425,   426,    22,   427,
      24,    25,     0,    26,    27,    28,    29,   428,    31,   490,
      33,    34,    35,    36,   431,    38,    39,   432,     0,    41,
     491,    43,     0,   434,    46,   435,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,     0,
       0,    63,     0,    64,    65,    66,   492,     0,     0,    70,
      71,    72,     0,     0,     0,    74,     0,     0,     0,     0,
      76,    77,    78,     0,     0,    81,    82,     0,     0,     0,
       0,     0,     0,    87,    88,    89,    90,     0,    91,     0,
       0,     0,   437,    93,    94,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    98,    99,     0,   101,   102,   973,
       0,     0,     0,   974,     0,     0,   107,   108,     0,     0,
       0,     0,   109,   110,   111,   112,   440,   114,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   122,     0,
       0,     0,   123,  1346,   124,   125,     0,     0,     0,     0,
    1347,     0,   130,     0,   131,   132,   133,   134,   441,   136,
     137,   138,   139,   140,   141,     0,     0,   975,   143,     0,
       0,   442,   146,     0,   147,   148,   149,   150,   151,   152,
     153,   443,   155,   445,   157,   446,   447,   160,   161,   162,
     163,   164,   165,   448,   167,   449,   450,   451,   452,   172,
     173,   453,   454,   176,   455,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,   189,   190,   191,
       0,   192,   193,   194,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     3,     0,
       0,     0,     0,     0,     0,     0,   416,   417,     0,     7,
       8,   488,    10,    11,    12,    13,   419,    15,   489,   422,
     423,   972,   425,   426,    22,   427,    24,    25,     0,    26,
      27,    28,    29,   428,    31,   490,    33,    34,    35,    36,
     431,    38,    39,   432,     0,    41,   491,    43,     0,   434,
      46,   435,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,     0,     0,    63,     0,    64,
      65,    66,   492,     0,     0,    70,    71,    72,     0,     0,
       0,    74,     0,     0,     0,     0,    76,    77,    78,     0,
       0,    81,    82,  1305,     0,     0,     0,     0,     0,    87,
      88,    89,    90,     0,    91,     0,     0,     0,   437,    93,
      94,     0,     0,     0,     0,     0,     0,     0,     0,    97,
      98,    99,     0,   101,   102,   973,     0,     0,     0,   974,
       0,     0,   107,   108,     0,     0,     0,     0,   109,   110,
     111,   112,   440,   114,   115,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   122,     0,     0,     0,   123,     0,
     124,   125,     0,     0,     0,     0,     0,     0,   130,     0,
     131,   132,   133,   134,   441,   136,   137,   138,   139,   140,
     141,     0,     0,   975,   143,     0,     0,   442,   146,     0,
     147,   148,   149,   150,   151,   152,   153,   443,   155,   445,
     157,   446,   447,   160,   161,   162,   163,   164,   165,   448,
     167,   449,   450,   451,   452,   172,   173,   453,   454,   176,
     455,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,   190,   191,     0,   192,   193,   194,
     195,   196,   197,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     3,     0,     0,     0,     0,     0,
       0,     0,   416,   417,     0,     7,     8,   418,    10,    11,
      12,    13,   419,   420,   421,   422,   423,   424,   425,   426,
      22,   427,    24,    25,     0,    26,    27,    28,    29,   428,
      31,   429,    33,    34,   430,    36,   431,    38,    39,   432,
       0,    41,   433,    43,     0,   434,    46,   435,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,     0,     0,    63,     0,    64,    65,    66,   436,     0,
       0,    70,    71,    72,     0,     0,     0,    74,     0,     0,
       0,     0,    76,    77,    78,     0,     0,    81,    82,     0,
       0,     0,     0,     0,     0,    87,    88,    89,    90,     0,
      91,     0,     0,     0,   437,    93,    94,     0,     0,     0,
       0,     0,     0,     0,     0,    97,    98,    99,     0,   101,
     102,   103,   438,     0,     0,   439,     0,     0,   107,   108,
       0,     0,     0,     0,   109,   110,   111,   112,   440,   114,
     115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     122,     0,     0,     0,   123,     0,   124,     0,     0,     0,
       0,     0,     0,     0,   130,     0,   131,   132,   133,   134,
     441,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,     0,     0,   442,   146,     0,   147,   148,   149,   150,
     151,   152,   153,   443,   444,   445,   157,   446,   447,   160,
     161,   162,   163,   164,   165,   448,   167,   449,   450,   451,
     452,   172,   173,   453,   454,   176,   455,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,   191,     0,   192,   193,   194,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       3,     0,     0,     0,     0,     0,     0,     0,   416,   417,
       0,     7,     8,   418,    10,    11,    12,    13,   419,   420,
     421,   422,   423,   424,   425,   426,    22,   427,    24,    25,
       0,    26,    27,    28,    29,   428,    31,   429,    33,    34,
     430,    36,   431,    38,    39,   432,     0,    41,   433,    43,
       0,   434,    46,   435,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,     0,     0,    63,
       0,    64,    65,    66,   436,     0,     0,    70,    71,    72,
       0,     0,     0,    74,     0,     0,     0,     0,    76,    77,
      78,     0,     0,    81,    82,     0,     0,     0,     0,     0,
       0,    87,    88,    89,    90,     0,    91,     0,     0,     0,
     437,    93,    94,     0,     0,     0,     0,     0,     0,     0,
       0,    97,    98,    99,     0,   101,   102,   103,   485,     0,
       0,   486,     0,     0,   107,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   440,   114,   115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   122,     0,     0,     0,
     123,     0,   124,     0,     0,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   441,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,     0,     0,   442,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   443,
     444,   445,   157,   446,   447,   160,   161,   162,   163,   164,
     165,   448,   167,   449,   450,   451,   452,   172,   173,   453,
     454,   176,   455,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,   191,     0,   192,
     193,   194,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     3,     0,     0,     0,
       0,     0,     0,     0,   416,   417,     0,     7,     8,   418,
      10,    11,    12,    13,   419,   420,   421,   422,   423,   424,
     425,   426,    22,   427,    24,    25,     0,    26,    27,    28,
      29,   428,    31,   429,    33,    34,   430,    36,   431,    38,
      39,   432,     0,    41,   433,    43,     0,   434,    46,   435,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,     0,     0,    63,     0,    64,    65,    66,
     436,     0,     0,    70,    71,    72,     0,     0,     0,    74,
       0,     0,     0,     0,    76,    77,    78,     0,     0,    81,
      82,     0,     0,     0,     0,     0,     0,    87,    88,    89,
      90,     0,    91,     0,     0,     0,   437,    93,    94,     0,
       0,     0,     0,     0,     0,     0,     0,    97,    98,    99,
       0,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     107,   108,     0,     0,     0,     0,   109,   110,   111,   112,
     440,   114,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   122,     0,     0,     0,   123,   667,   124,     0,
       0,     0,     0,     0,   668,     0,   130,     0,   131,   132,
     133,   134,   441,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,     0,     0,   442,   146,     0,   147,   148,
     149,   150,   151,   152,   153,   443,   444,   445,   157,   446,
     447,   160,   161,   162,   163,   164,   165,   448,   167,   449,
     450,   451,   452,   172,   173,   453,   454,   176,   455,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,   191,     0,   192,   193,   194,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     3,     0,     0,     0,     0,     0,     0,     0,
     416,   417,     0,     7,     8,   418,    10,    11,    12,    13,
     419,   420,   421,   422,   423,   424,   425,   426,    22,   427,
      24,    25,     0,    26,    27,    28,    29,   428,    31,   429,
      33,    34,   430,    36,   431,    38,    39,   432,     0,    41,
     433,    43,     0,   434,    46,   435,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,     0,
       0,    63,     0,    64,    65,    66,   436,     0,     0,    70,
      71,    72,     0,     0,     0,    74,     0,     0,     0,     0,
      76,    77,    78,     0,     0,    81,    82,     0,     0,     0,
       0,     0,     0,    87,    88,    89,    90,     0,    91,     0,
       0,     0,   437,    93,    94,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    98,    99,     0,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   107,   108,     0,     0,
       0,     0,   109,   110,   111,   112,   440,   114,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   122,     0,
       0,     0,   123,   713,   124,     0,     0,     0,     0,     0,
     714,     0,   130,     0,   131,   132,   133,   134,   441,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,     0,
       0,   442,   146,     0,   147,   148,   149,   150,   151,   152,
     153,   443,   444,   445,   157,   446,   447,   160,   161,   162,
     163,   164,   165,   448,   167,   449,   450,   451,   452,   172,
     173,   453,   454,   176,   455,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,   189,   190,   191,
       0,   192,   193,   194,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     3,     0,
       0,     0,     0,     0,     0,     0,   416,   417,     0,     7,
       8,   488,    10,    11,    12,    13,   419,    15,   489,   422,
     423,   972,   425,   426,    22,   427,    24,    25,     0,    26,
      27,    28,    29,   428,    31,   490,    33,    34,    35,    36,
     431,    38,    39,   432,     0,    41,   491,    43,     0,   434,
      46,   435,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,     0,     0,    63,     0,    64,
      65,    66,   492,     0,     0,    70,    71,    72,     0,     0,
       0,    74,     0,     0,     0,     0,    76,    77,    78,     0,
       0,    81,    82,     0,     0,     0,     0,     0,     0,    87,
      88,    89,    90,     0,    91,     0,     0,     0,   437,    93,
      94,     0,     0,     0,     0,     0,     0,     0,     0,    97,
      98,    99,     0,   101,   102,   973,     0,     0,     0,   974,
       0,     0,   107,   108,     0,     0,     0,     0,   109,   110,
     111,   112,   440,   114,   115,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   122,     0,     0,     0,   123,     0,
     124,   125,     0,     0,     0,     0,     0,     0,   130,     0,
     131,   132,   133,   134,   441,   136,   137,   138,   139,   140,
     141,     0,     0,   975,   143,     0,     0,   442,   146,     0,
     147,   148,   149,   150,   151,   152,   153,   443,   155,   445,
     157,   446,   447,   160,   161,   162,   163,   164,   165,   448,
     167,   449,   450,   451,   452,   172,   173,   453,   454,   176,
     455,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,   190,   191,     0,   192,   193,   194,
     195,   196,   197,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     3,     0,     0,     0,     0,     0,
       0,     0,   416,   417,     0,     7,     8,   488,    10,    11,
      12,    13,   419,    15,   489,   422,   423,   972,   425,   426,
      22,   427,    24,    25,     0,    26,    27,    28,    29,   428,
      31,   490,    33,    34,    35,    36,   431,    38,    39,   432,
       0,    41,   491,    43,     0,   434,    46,   435,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,     0,     0,    63,     0,    64,    65,    66,   492,     0,
       0,    70,    71,    72,     0,     0,     0,    74,     0,     0,
       0,     0,    76,    77,    78,     0,     0,    81,    82,     0,
       0,     0,     0,     0,     0,    87,    88,    89,    90,     0,
      91,     0,     0,     0,   437,    93,    94,     0,     0,     0,
       0,     0,     0,     0,     0,    97,    98,    99,     0,   101,
     102,   973,     0,     0,     0,   974,     0,     0,   107,   108,
       0,     0,     0,     0,   109,   110,   111,   112,   440,   114,
     115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     122,     0,     0,     0,   123,     0,   124,   125,     0,     0,
       0,     0,     0,     0,   130,     0,   131,   132,   133,   134,
     441,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,     0,     0,   442,   146,     0,   147,   148,   149,   150,
     151,   152,   153,   443,   155,   445,   157,   446,   447,   160,
     161,   162,   163,   164,   165,   448,   167,   449,   450,   451,
     452,   172,   173,   453,   454,   176,   455,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,   191,     0,   192,   193,   194,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       3,     0,     0,     0,     0,     0,     0,     0,   416,   417,
       0,     7,     8,   418,    10,    11,    12,    13,   419,   420,
     421,   422,   423,   424,   425,   426,    22,   427,    24,    25,
       0,    26,    27,    28,    29,   428,    31,   429,    33,    34,
     430,    36,   431,    38,    39,   432,     0,    41,   433,    43,
       0,   434,    46,   435,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,     0,     0,    63,
       0,    64,    65,    66,   436,     0,     0,    70,    71,    72,
       0,     0,     0,    74,     0,     0,     0,     0,    76,    77,
      78,     0,     0,    81,    82,     0,     0,     0,     0,     0,
       0,    87,    88,    89,    90,     0,    91,     0,     0,     0,
     437,    93,    94,     0,     0,     0,     0,     0,     0,     0,
       0,    97,    98,    99,     0,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   107,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   440,   114,   115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   122,     0,     0,     0,
     123,     0,   124,     0,     0,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   441,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,     0,     0,   442,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   443,
     444,   445,   157,   446,   447,   160,   161,   162,   163,   164,
     165,   448,   167,   449,   450,   451,   452,   172,   173,   453,
     454,   176,   455,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,   191,     0,   192,
     193,   194,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        16,   539,   762,   371,   581,   310,   582,   583,   584,   585,
     104,   793,   794,   720,   899,   117,    32,  1069,   128,   791,
     792,   779,   536,   934,   867,  1185,  1186,  1174,    69,   779,
     691,   791,   792,  1332,    21,   996,    50,  1261,    48,   621,
     561,    51,   563,   564,   113,   566,   691,   568,   558,    22,
      89,    67,     7,    69,  1236,   576,   577,   702,    38,   826,
      89,    21,     8,     9,    91,    91,   826,    83,    89,    21,
      88,    95,   102,     8,     9,    34,    21,    89,    58,    91,
     956,    40,   113,   102,  1147,    95,    45,   102,    89,   105,
     123,    89,   112,   102,    53,   102,   135,   465,   466,   102,
     153,   117,   862,   119,    27,   766,    65,   768,   102,   125,
      46,   102,   135,   140,   162,   241,   242,   889,   105,   139,
      91,    39,    62,   113,   101,   113,   257,    67,   140,   889,
     117,    40,   152,    56,    31,    91,   102,   268,   264,   140,
      37,    38,   140,   120,   140,   140,   194,   178,   108,   218,
      91,  1027,    98,   105,   178,   142,   189,   175,    55,   146,
      89,    58,   149,    98,   183,   117,   186,   108,   183,    66,
     116,   180,   118,   113,     4,   151,   183,   180,     8,  1339,
     102,   116,   169,   118,   102,   179,   122,   832,   179,   179,
     142,   162,   168,   153,   146,    92,   210,   149,   228,   179,
     146,   230,   161,   313,   150,   164,   162,   974,   153,   230,
      89,   146,   167,   179,   974,   150,  1398,   169,  1270,   178,
     166,  1106,  1065,   930,   250,   251,   102,  1138,   267,   811,
     812,   166,   301,   206,   248,   245,  1147,   882,   996,   997,
     267,   187,   903,   888,   267,   204,   996,   997,   258,  1473,
     260,  1212,   187,  1316,   775,   267,  1555,   179,   768,   205,
       4,   271,   272,   273,     8,   275,   253,   277,   636,   285,
     205,   267,   267,  1572,   102,   246,   247,   318,   249,   102,
     321,  1580,   211,   212,   181,   387,   116,   263,   118,     8,
     246,   247,  1439,   249,   270,   266,   126,   226,   102,     8,
     256,    20,   318,   179,   280,   321,   102,   278,    89,   411,
     266,    20,  1072,    89,   129,   102,   146,   102,   412,   687,
     414,   218,   278,   102,   137,   146,  1098,    38,   149,    91,
      41,   992,   211,   212,   124,     8,     9,   130,  1098,   193,
      91,   184,   185,    91,   438,   123,   108,   226,   202,   151,
    1402,   179,  1124,   146,   130,   168,   179,   108,   210,   135,
     376,    47,   378,    74,  1124,   146,   168,   383,    54,   471,
     464,   387,   116,   186,   118,   179,   470,   393,   193,  1539,
     176,   202,   126,   477,   400,   479,   480,   149,   482,   191,
     101,   485,   179,   183,   179,   411,   248,   116,   149,   118,
     179,   149,   146,    47,   151,  1316,   500,   116,   127,   118,
      54,   189,   506,   138,   294,   295,     8,     9,   127,    90,
    1192,   168,    26,   439,   149,    98,  1269,   146,    72,  1481,
     101,   525,  1192,   214,   215,    47,   875,   146,   877,    43,
     111,   146,    54,   116,   191,   118,   960,    91,   130,   120,
     161,   467,   146,   135,  1212,   471,   149,  1509,   474,   475,
     476,   151,  1212,  1221,   169,   481,   141,   835,   836,   113,
     486,  1221,   840,   146,  1232,  1490,  1491,   150,   168,    91,
     496,   146,  1232,   158,   923,   159,   925,   257,   263,   457,
     600,   601,   141,   166,   149,   270,   130,   113,   268,    41,
     174,   869,   518,   597,   169,   280,    98,  1522,   602,   158,
     526,   130,   146,  1528,   187,   146,  1568,    59,  1570,    61,
      95,   129,   174,   174,   116,   823,   118,   146,    70,  1414,
     113,    95,   205,   108,  1586,   143,   188,   188,   149,   837,
     293,   113,   510,   511,   108,   513,   514,   515,   516,   302,
     262,   214,   215,   216,   146,   523,   524,   269,   150,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,   537,
     218,   271,   272,   273,   166,   223,   670,   277,   130,   547,
     548,   683,   320,   135,   686,   146,   680,   325,   149,   146,
     603,   149,   149,   606,   149,   187,   609,   218,   218,   220,
     220,   149,   147,   697,   149,   146,   375,  1314,   377,   146,
     626,  1318,   628,   205,   208,   631,   710,   711,   225,  1377,
     227,   149,   716,   225,   146,   227,   113,  1377,   218,   162,
     294,   295,   121,   122,   235,   285,   286,   653,   654,   655,
     608,   121,   122,   611,   586,   587,  1223,   235,   742,   579,
     580,   588,   589,  1389,  1390,   236,   149,   113,   674,     0,
     676,   194,   146,   183,   183,   160,    87,   683,    44,   243,
     686,   192,  1444,    96,  1446,    97,   147,    21,    41,    41,
      41,   145,   113,   292,  1444,   298,  1446,   240,   287,   292,
     223,   179,   146,   998,   278,   113,   278,   146,   113,   146,
     179,   146,   146,   719,   146,   179,   149,    28,   149,   149,
     149,   149,  1250,    15,  1486,   206,   179,    21,   179,   224,
    1427,    26,   113,  1430,   161,   102,  1486,   163,  1510,  1501,
     163,    66,   224,  1101,    89,    89,    89,   142,   102,   755,
      21,  1501,   102,   153,   153,   120,   762,   125,   281,   282,
     283,   284,   285,   293,   287,   288,   289,   290,   291,   240,
     125,    91,   176,   296,   176,    89,   179,    38,   179,   176,
     176,   179,    91,   102,   176,   791,   792,   793,   794,   179,
     179,   179,   176,   135,   179,  1361,   179,  1494,   146,   757,
     176,  1368,  1369,   176,   176,   176,   764,   125,    89,   218,
     230,   135,   176,   183,   163,   133,   134,   179,   136,    35,
     826,   177,   113,  1181,   113,    41,   144,   113,   113,   176,
     148,   135,   150,    49,   918,    51,   842,   155,   140,    89,
      21,   125,   135,    59,   280,    61,   220,   146,   293,   176,
     113,    89,   190,   171,    70,   248,   125,   153,    74,   176,
     125,    91,   113,   135,   146,   113,   176,   140,    95,   875,
     828,   877,    95,   176,    28,   176,   834,   195,   196,   197,
     198,   199,   200,   889,  1451,  1452,   146,    21,   176,   113,
     106,   107,   108,   176,   146,   113,    74,   102,   239,   102,
     149,   140,   149,   149,   140,   137,   252,    21,    21,    21,
     279,   995,   220,   220,   254,   230,   183,   923,   281,   925,
     280,   300,   261,   220,   179,   179,   137,   140,   113,   113,
      72,   102,  1290,   135,   179,   179,   176,  1504,   179,   125,
       6,  1025,   179,   901,   178,   135,   162,   226,   183,   226,
     226,   226,   910,   101,   912,   913,   230,   101,   179,   179,
     179,   140,   968,   140,   176,   971,   244,   280,   974,   179,
     276,   929,    73,    21,   244,   176,    21,   176,   194,   985,
      91,   987,   940,   941,   942,  1343,   944,   945,   946,   947,
     948,   949,  1076,   951,   952,   163,   119,   265,   251,    91,
     176,    89,    21,   178,   178,   146,   964,   223,   274,   176,
     176,   102,   176,   163,   179,    47,   179,   281,    89,   189,
     113,    89,    21,   102,    89,   218,   259,   113,   113,  1113,
     988,   178,   990,   991,   189,   113,   189,   176,   218,   255,
     299,   178,    88,   175,   189,   287,  1130,   146,   191,   113,
     113,   113,   179,   281,   113,   238,   299,   218,   635,  1017,
     535,  1481,   244,   535,   827,   281,   282,   283,   284,   285,
     299,   287,   288,   289,   290,   291,  1031,  1035,   300,   241,
     296,   297,   241,  1089,   405,   300,   300,   385,  1509,  1072,
    1170,   381,  1098,   890,   245,   284,   887,   971,  1284,  1178,
    1090,  1108,  1108,  1190,   463,   964,  1188,  1185,   560,   496,
    1116,   559,   306,  1125,   611,  1116,  1138,  1528,  1124,  1522,
     720,   794,  1066,  1121,   877,  1083,  1030,  1175,   415,  1165,
    1088,  1221,  1377,  1232,   997,   415,  1225,  1374,  1144,  1006,
     861,  1055,  1100,  1392,  1259,  1222,    -1,    -1,    -1,    -1,
      -1,    -1,  1110,  1111,    -1,    -1,    -1,    -1,    -1,  1165,
      -1,  1119,  1120,    -1,    -1,    -1,    -1,    -1,  1174,    -1,
      -1,    -1,  1178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1192,    -1,    -1,    -1,
      29,    30,    -1,    32,    33,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,  1177,
      59,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1188,    70,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1203,    -1,    -1,  1206,    -1,
    1208,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1267,    -1,    -1,    -1,    -1,    -1,   106,   107,   108,
      -1,    -1,    -1,    -1,    -1,  1281,  1282,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1305,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1315,
      -1,    -1,    -1,  1319,   153,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1280,   162,    -1,    -1,    -1,    -1,  1286,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1295,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1303,  1304,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1322,  1323,  1324,  1325,  1326,    -1,
    1328,  1329,    -1,    -1,   213,    -1,    -1,  1461,    -1,    -1,
      -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1355,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   255,  1423,    -1,    -1,
      -1,    -1,  1428,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1439,    -1,    -1,    -1,    -1,  1444,    -1,
    1446,    -1,   281,   282,   283,   284,   285,    -1,   287,   288,
     289,   290,   291,    -1,    -1,  1413,    -1,   296,   297,    -1,
    1418,    -1,    -1,    -1,  1422,    -1,  1424,    -1,    -1,    -1,
      -1,  1477,    -1,    -1,  1480,    -1,    -1,    -1,    -1,    -1,
    1486,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1497,    -1,    -1,    -1,  1501,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1510,    -1,  1512,    -1,    -1,    -1,
    1516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1542,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1560,    -1,  1562,    -1,    -1,    -1,
    1518,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1575,
      -1,    -1,    -1,  1579,    -1,    -1,    -1,    -1,  1584,    -1,
      -1,    -1,  1540,    -1,    -1,    -1,    -1,  1545,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,
      21,    -1,    -1,    -1,    -1,    26,    27,  1565,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    -1,    -1,   100,
     101,    -1,    -1,    -1,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,    -1,   117,    -1,   119,   120,
     121,   122,    -1,   124,    -1,    -1,    -1,   128,   129,   130,
     131,   132,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,   143,   144,   145,    -1,    -1,    -1,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    -1,   168,   169,    -1,
      -1,   172,   173,   174,    -1,    -1,    -1,   178,    -1,   180,
     181,   182,    -1,   184,   185,   186,    -1,   188,    -1,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
      -1,    -1,   203,   204,   205,    -1,   207,   208,    -1,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,   253,   254,   255,    -1,   257,   258,   259,   260,
     261,   262,    -1,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      26,    27,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    -1,    -1,   100,   101,    -1,    -1,    -1,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,   117,    -1,   119,   120,   121,   122,    -1,   124,    -1,
      -1,    -1,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,    -1,    -1,   139,   140,   141,   142,   143,   144,   145,
      -1,    -1,    -1,   149,   150,   151,   152,   153,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,   162,   163,   164,   165,
     166,    -1,   168,   169,    -1,    -1,   172,   173,   174,    -1,
      -1,    -1,   178,   179,   180,   181,   182,    -1,   184,   185,
     186,    -1,   188,    -1,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,   203,   204,   205,
      -1,   207,   208,    -1,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,   253,   254,   255,
      -1,   257,   258,   259,   260,   261,   262,    -1,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,
      -1,    -1,    -1,    -1,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    -1,    -1,   100,   101,
      -1,    -1,    -1,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,   117,    -1,   119,   120,   121,
     122,    -1,   124,    -1,    -1,    -1,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,
     142,   143,   144,   145,    -1,    -1,    -1,   149,   150,   151,
     152,   153,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
     162,   163,   164,   165,   166,    -1,   168,   169,    -1,    -1,
     172,   173,   174,    -1,   176,    -1,   178,    -1,   180,   181,
     182,    -1,   184,   185,   186,    -1,   188,    -1,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,   203,   204,   205,    -1,   207,   208,    -1,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
      -1,   253,   254,   255,    -1,   257,   258,   259,   260,   261,
     262,    -1,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    -1,    21,    -1,    -1,    -1,    -1,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      -1,    -1,   100,   101,    -1,    -1,    -1,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,   117,
      -1,   119,   120,   121,   122,    -1,   124,    -1,    -1,    -1,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,   149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,   162,   163,   164,   165,   166,    -1,
     168,   169,    -1,    -1,   172,   173,   174,    -1,    -1,    -1,
     178,   179,   180,   181,   182,    -1,   184,   185,   186,    -1,
     188,    -1,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,   203,   204,   205,    -1,   207,
     208,    -1,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,    -1,   253,   254,   255,    -1,   257,
     258,   259,   260,   261,   262,    -1,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    26,    27,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    -1,    -1,   100,   101,    -1,    -1,
      -1,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,   117,    -1,   119,   120,   121,   122,    -1,
     124,    -1,    -1,    -1,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,    -1,    -1,   139,   140,   141,   142,   143,
     144,   145,    -1,    -1,    -1,   149,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,   162,   163,
     164,   165,   166,    -1,   168,   169,    -1,    -1,   172,   173,
     174,    -1,    -1,    -1,   178,   179,   180,   181,   182,    -1,
     184,   185,   186,    -1,   188,    -1,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,   203,
     204,   205,    -1,   207,   208,    -1,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,    -1,   253,
     254,   255,    -1,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      -1,    21,    -1,    -1,    -1,    -1,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    -1,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    -1,    -1,
     100,   101,    -1,    -1,    -1,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,   117,    -1,   119,
     120,   121,   122,    -1,   124,    -1,    -1,    -1,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     140,   141,   142,   143,   144,   145,    -1,    -1,    -1,   149,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,   162,   163,   164,   165,   166,    -1,   168,   169,
      -1,    -1,   172,   173,   174,    -1,   176,    -1,   178,    -1,
     180,   181,   182,    -1,   184,   185,   186,    -1,   188,    -1,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,   203,   204,   205,    -1,   207,   208,    -1,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,   253,   254,   255,    -1,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      26,    27,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    -1,    -1,   100,   101,    -1,    -1,    -1,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,   117,    -1,   119,   120,   121,   122,    -1,   124,    -1,
      -1,    -1,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,    -1,    -1,   139,   140,   141,   142,   143,   144,   145,
      -1,    -1,    -1,   149,   150,   151,   152,   153,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,   162,   163,   164,   165,
     166,    -1,   168,   169,    -1,    -1,   172,   173,   174,    -1,
     176,    -1,   178,    -1,   180,   181,   182,    -1,   184,   185,
     186,    -1,   188,    -1,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,   203,   204,   205,
      -1,   207,   208,    -1,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,   253,   254,   255,
      -1,   257,   258,   259,   260,   261,   262,    -1,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,
      -1,    -1,    -1,    -1,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    -1,    -1,   100,   101,
      -1,    -1,    -1,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,   117,    -1,   119,   120,   121,
     122,    -1,   124,    -1,    -1,    -1,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,
     142,   143,   144,   145,    -1,    -1,    -1,   149,   150,   151,
     152,   153,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
     162,   163,   164,   165,   166,    -1,   168,   169,    -1,    -1,
     172,   173,   174,    -1,   176,    -1,   178,    -1,   180,   181,
     182,    -1,   184,   185,   186,    -1,   188,    -1,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,   203,   204,   205,    -1,   207,   208,    -1,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
      -1,   253,   254,   255,    -1,   257,   258,   259,   260,   261,
     262,    -1,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    -1,    21,    -1,    -1,    -1,    -1,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      -1,    -1,   100,   101,    -1,    -1,    -1,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,   117,
      -1,   119,   120,   121,   122,    -1,   124,    -1,    -1,    -1,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,   149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,   162,   163,   164,   165,   166,    -1,
     168,   169,    -1,    -1,   172,   173,   174,    -1,   176,    -1,
     178,    -1,   180,   181,   182,    -1,   184,   185,   186,    -1,
     188,    -1,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,   203,   204,   205,    -1,   207,
     208,    -1,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,    -1,   253,   254,   255,    -1,   257,
     258,   259,   260,   261,   262,    -1,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    26,    27,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    -1,    -1,   100,   101,    -1,    -1,
      -1,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,   117,    -1,   119,   120,   121,   122,    -1,
     124,    -1,    -1,    -1,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,    -1,    -1,   139,   140,   141,   142,   143,
     144,   145,    -1,    -1,    -1,   149,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,   162,   163,
     164,   165,   166,    -1,   168,   169,    -1,    -1,   172,   173,
     174,    -1,   176,    -1,   178,    -1,   180,   181,   182,    -1,
     184,   185,   186,    -1,   188,    -1,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,   203,
     204,   205,    -1,   207,   208,    -1,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,    -1,   253,
     254,   255,    -1,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      -1,    21,    -1,    -1,    -1,    -1,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    -1,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    -1,    -1,
     100,   101,    -1,    -1,    -1,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,   117,    -1,   119,
     120,   121,   122,    -1,   124,    -1,    -1,    -1,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     140,   141,   142,   143,   144,   145,    -1,    -1,    -1,   149,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,   162,   163,   164,   165,   166,    -1,   168,   169,
      -1,    -1,   172,   173,   174,    -1,   176,    -1,   178,    -1,
     180,   181,   182,    -1,   184,   185,   186,    -1,   188,    -1,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,   203,   204,   205,    -1,   207,   208,    -1,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,   253,   254,   255,    -1,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      26,    27,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    -1,    -1,   100,   101,    -1,    -1,    -1,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,   117,    -1,   119,   120,   121,   122,    -1,   124,    -1,
      -1,    -1,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,    -1,    -1,   139,   140,   141,   142,   143,   144,   145,
      -1,    -1,    -1,   149,   150,   151,   152,   153,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,   162,   163,   164,   165,
     166,    -1,   168,   169,    -1,    -1,   172,   173,   174,    -1,
      -1,    -1,   178,    -1,   180,   181,   182,    -1,   184,   185,
     186,    -1,   188,    -1,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,   203,   204,   205,
      -1,   207,   208,    -1,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,   253,   254,   255,
      -1,   257,   258,   259,   260,   261,   262,    -1,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,
      -1,    -1,    -1,    -1,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    -1,    -1,   100,   101,
      -1,    -1,    -1,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,   117,    -1,   119,   120,   121,
     122,    -1,   124,    -1,    -1,    -1,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,
     142,   143,   144,   145,    -1,    -1,    -1,   149,   150,   151,
     152,   153,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
     162,   163,   164,   165,   166,    -1,   168,   169,    -1,    -1,
     172,   173,   174,    -1,    -1,    -1,   178,    -1,   180,   181,
     182,    -1,   184,   185,   186,    -1,   188,    -1,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,   203,   204,   205,    -1,   207,   208,    -1,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
      -1,   253,   254,   255,    -1,   257,   258,   259,   260,   261,
     262,    -1,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    -1,    21,    -1,    -1,    -1,    -1,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      -1,    -1,   100,   101,    -1,    -1,    -1,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,   117,
      -1,   119,   120,   121,   122,    -1,   124,    -1,    -1,    -1,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,   149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,   162,   163,   164,   165,   166,    -1,
     168,   169,    -1,    -1,   172,   173,   174,    -1,    -1,    -1,
     178,    -1,   180,   181,   182,    -1,   184,   185,   186,    -1,
     188,    -1,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,   203,   204,   205,    -1,   207,
     208,    -1,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,    -1,   253,   254,   255,    -1,   257,
     258,   259,   260,   261,   262,    -1,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    26,    27,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    -1,    -1,   100,   101,    -1,    -1,
      -1,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,   117,    -1,   119,   120,   121,   122,    -1,
     124,    -1,    -1,    -1,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,    -1,    -1,   139,   140,   141,   142,   143,
     144,   145,    -1,    -1,    -1,   149,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,   162,   163,
     164,   165,   166,    -1,   168,   169,    -1,    -1,   172,   173,
     174,    -1,    -1,    -1,   178,    -1,   180,   181,   182,    -1,
     184,   185,   186,    -1,   188,    -1,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,   203,
     204,   205,    -1,   207,   208,    -1,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,    -1,   253,
     254,   255,    -1,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      -1,    21,    -1,    -1,    -1,    -1,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    -1,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    -1,    -1,
     100,   101,    -1,    -1,    -1,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,   117,    -1,   119,
     120,   121,   122,    -1,   124,    -1,    -1,    -1,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     140,   141,   142,   143,   144,   145,    -1,    -1,    -1,   149,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,   162,   163,   164,   165,   166,    -1,   168,   169,
      -1,    -1,   172,   173,   174,    -1,    -1,    -1,   178,    -1,
     180,   181,   182,    -1,   184,   185,   186,    -1,   188,    -1,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,   203,   204,   205,    -1,   207,   208,    -1,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,   253,   254,   255,    -1,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      26,    27,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    -1,    -1,   100,   101,    -1,    -1,    -1,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,   117,    -1,   119,   120,   121,   122,    -1,   124,    -1,
      -1,    -1,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,    -1,    -1,   139,   140,   141,   142,   143,   144,   145,
      -1,    -1,    -1,   149,   150,   151,   152,   153,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,   162,   163,   164,   165,
     166,    -1,   168,   169,    -1,    -1,   172,   173,   174,    -1,
      -1,    -1,   178,    -1,   180,   181,   182,    -1,   184,   185,
     186,    -1,   188,    -1,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,   203,   204,   205,
      -1,   207,   208,    -1,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,   253,   254,   255,
      -1,   257,   258,   259,   260,   261,   262,    -1,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,
      -1,    -1,    -1,    -1,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    -1,    -1,   100,   101,
      -1,    -1,    -1,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,   117,    -1,   119,   120,   121,
     122,    -1,   124,    -1,    -1,    -1,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,
     142,   143,   144,   145,    -1,    -1,    -1,   149,   150,    -1,
     152,   153,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
     162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,
     172,   173,   174,    -1,    -1,    -1,   178,    -1,   180,   181,
     182,    -1,   184,   185,   186,    -1,   188,    -1,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,   203,   204,   205,    -1,   207,   208,    -1,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
      -1,   253,   254,   255,    -1,   257,   258,   259,   260,   261,
     262,    -1,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    -1,    21,    -1,    -1,    -1,    -1,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      -1,    -1,   100,   101,    -1,    -1,    -1,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,   117,
      -1,   119,   120,   121,   122,    -1,   124,    -1,    -1,    -1,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,   149,   150,    -1,   152,   153,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,   162,   163,   164,   165,   166,    -1,
      -1,    -1,    -1,    -1,   172,   173,   174,    -1,    -1,    -1,
     178,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,    -1,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,   203,   204,   205,    -1,   207,
     208,    -1,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,    -1,   253,   254,   255,    -1,   257,
     258,   259,   260,   261,   262,    -1,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    -1,    87,    -1,    89,    90,    91,    92,    -1,
      -1,    95,    96,    97,    -1,    -1,    -1,   101,    -1,    -1,
      -1,    -1,   106,   107,   108,    -1,    -1,   111,   112,    -1,
      -1,    -1,    -1,    -1,    -1,   119,   120,   121,   122,    -1,
     124,    -1,    -1,    -1,   128,   129,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,   140,   141,    -1,   143,
     144,   145,    -1,    -1,    -1,    -1,    -1,    -1,   152,   153,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     174,    -1,    -1,    -1,   178,    -1,   180,   181,    -1,    -1,
      -1,    -1,   186,    -1,   188,    -1,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,   203,
     204,    -1,    -1,   207,   208,    -1,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,    -1,   253,
     254,   255,    -1,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    -1,    87,    -1,    89,
      90,    91,    92,    -1,    -1,    95,    96,    97,    -1,    -1,
      -1,   101,    -1,    -1,    -1,    -1,   106,   107,   108,    -1,
      -1,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,   119,
     120,   121,   122,    -1,   124,    -1,    -1,    -1,   128,   129,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     140,   141,    -1,   143,   144,   145,    -1,    -1,    -1,    -1,
      -1,    -1,   152,   153,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,   178,    -1,
     180,    -1,    -1,    -1,    -1,    -1,   186,    -1,   188,    -1,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,   203,   204,    -1,    -1,   207,   208,    -1,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,   253,   254,   255,    -1,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,    14,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    -1,    87,    -1,    89,
      90,    91,    92,    -1,    -1,    95,    96,    97,    -1,    -1,
      -1,   101,    -1,    -1,    -1,    -1,   106,   107,   108,    -1,
      -1,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,   119,
     120,   121,   122,    -1,   124,    -1,    -1,    -1,   128,   129,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     140,   141,    -1,   143,   144,   145,   146,    -1,    -1,   149,
      -1,    -1,   152,   153,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,   178,    -1,
     180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,   203,   204,    -1,    -1,   207,   208,    -1,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,   253,   254,   255,    -1,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,    14,    -1,    -1,    -1,    18,    -1,
      -1,    21,    -1,    -1,    -1,    -1,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    -1,    87,    -1,    89,
      90,    91,    92,    -1,    -1,    95,    96,    97,    -1,    -1,
      -1,   101,    -1,    -1,    -1,    -1,   106,   107,   108,    -1,
      -1,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,   119,
     120,   121,   122,    -1,   124,    -1,    -1,    -1,   128,   129,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     140,   141,    -1,   143,   144,   145,    -1,    -1,    -1,    -1,
      -1,    -1,   152,   153,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,   178,   179,
     180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,   203,   204,    -1,    -1,   207,   208,    -1,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,   253,   254,   255,    -1,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,    14,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    -1,    87,    -1,    89,
      90,    91,    92,    -1,    -1,    95,    96,    97,    -1,    -1,
      -1,   101,    -1,    -1,    -1,    -1,   106,   107,   108,    -1,
      -1,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,   119,
     120,   121,   122,    -1,   124,    -1,    -1,    -1,   128,   129,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     140,   141,    -1,   143,   144,   145,    -1,    -1,    -1,    -1,
      -1,    -1,   152,   153,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,   178,    -1,
     180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,   203,   204,    -1,    -1,   207,   208,    -1,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,   253,   254,   255,    -1,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,    16,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    -1,    87,    -1,    89,    90,    91,
      92,    -1,    -1,    95,    96,    97,    -1,    -1,    -1,   101,
      -1,    -1,    -1,    -1,   106,   107,   108,    -1,    -1,   111,
     112,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,   121,
     122,    -1,   124,    -1,    -1,    -1,   128,   129,   130,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,
      -1,   143,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,
     152,   153,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   174,    -1,    -1,    -1,   178,    -1,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,   203,   204,    -1,    -1,   207,   208,    -1,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
      -1,   253,   254,   255,    -1,   257,   258,   259,   260,   261,
     262,    -1,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    27,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      -1,    87,    -1,    89,    90,    91,    92,    -1,    -1,    95,
      96,    97,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,
     106,   107,   108,    -1,    -1,   111,   112,    -1,    -1,    -1,
      -1,    -1,    -1,   119,   120,   121,   122,    -1,   124,    -1,
      -1,    -1,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,   140,   141,    -1,   143,   144,   145,
      -1,    -1,    -1,   149,    -1,    -1,   152,   153,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,
      -1,    -1,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186,    -1,   188,    -1,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,   203,   204,    -1,
      -1,   207,   208,    -1,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,   253,   254,   255,
      -1,   257,   258,   259,   260,   261,   262,    -1,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    -1,    87,    -1,    89,
      90,    91,    92,    -1,    -1,    95,    96,    97,    -1,    -1,
      -1,   101,    -1,    -1,    -1,    -1,   106,   107,   108,    -1,
      -1,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,   119,
     120,   121,   122,    -1,   124,    -1,    -1,    -1,   128,   129,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     140,   141,    -1,   143,   144,   145,    -1,    -1,    -1,   149,
      -1,    -1,   152,   153,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,   178,    -1,
     180,   181,    -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,   203,   204,    -1,    -1,   207,   208,    -1,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,   253,   254,   255,    -1,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    -1,    87,    -1,    89,    90,    91,    92,    -1,
      -1,    95,    96,    97,    -1,    -1,    -1,   101,    -1,    -1,
      -1,    -1,   106,   107,   108,    -1,    -1,   111,   112,    -1,
      -1,    -1,    -1,    -1,    -1,   119,   120,   121,   122,    -1,
     124,    -1,    -1,    -1,   128,   129,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,   140,   141,    -1,   143,
     144,   145,   146,    -1,    -1,   149,    -1,    -1,   152,   153,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     174,    -1,    -1,    -1,   178,    -1,   180,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   188,    -1,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,   203,
     204,    -1,    -1,   207,   208,    -1,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,    -1,   253,
     254,   255,    -1,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    -1,    87,
      -1,    89,    90,    91,    92,    -1,    -1,    95,    96,    97,
      -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,   106,   107,
     108,    -1,    -1,   111,   112,    -1,    -1,    -1,    -1,    -1,
      -1,   119,   120,   121,   122,    -1,   124,    -1,    -1,    -1,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   140,   141,    -1,   143,   144,   145,   146,    -1,
      -1,   149,    -1,    -1,   152,   153,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,
     178,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     188,    -1,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,   203,   204,    -1,    -1,   207,
     208,    -1,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,    -1,   253,   254,   255,    -1,   257,
     258,   259,   260,   261,   262,    -1,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    -1,    87,    -1,    89,    90,    91,
      92,    -1,    -1,    95,    96,    97,    -1,    -1,    -1,   101,
      -1,    -1,    -1,    -1,   106,   107,   108,    -1,    -1,   111,
     112,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,   121,
     122,    -1,   124,    -1,    -1,    -1,   128,   129,   130,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,
      -1,   143,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,
     152,   153,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   174,    -1,    -1,    -1,   178,   179,   180,    -1,
      -1,    -1,    -1,    -1,   186,    -1,   188,    -1,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
      -1,   203,   204,    -1,    -1,   207,   208,    -1,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
      -1,   253,   254,   255,    -1,   257,   258,   259,   260,   261,
     262,    -1,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    27,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      -1,    87,    -1,    89,    90,    91,    92,    -1,    -1,    95,
      96,    97,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,
     106,   107,   108,    -1,    -1,   111,   112,    -1,    -1,    -1,
      -1,    -1,    -1,   119,   120,   121,   122,    -1,   124,    -1,
      -1,    -1,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,   140,   141,    -1,   143,   144,   145,
      -1,    -1,    -1,    -1,    -1,    -1,   152,   153,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,
      -1,    -1,   178,   179,   180,    -1,    -1,    -1,    -1,    -1,
     186,    -1,   188,    -1,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,   203,   204,    -1,
      -1,   207,   208,    -1,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,   253,   254,   255,
      -1,   257,   258,   259,   260,   261,   262,    -1,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    -1,    87,    -1,    89,
      90,    91,    92,    -1,    -1,    95,    96,    97,    -1,    -1,
      -1,   101,    -1,    -1,    -1,    -1,   106,   107,   108,    -1,
      -1,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,   119,
     120,   121,   122,    -1,   124,    -1,    -1,    -1,   128,   129,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     140,   141,    -1,   143,   144,   145,    -1,    -1,    -1,   149,
      -1,    -1,   152,   153,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,   178,    -1,
     180,   181,    -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,    -1,    -1,   203,   204,    -1,    -1,   207,   208,    -1,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,   253,   254,   255,    -1,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    -1,    87,    -1,    89,    90,    91,    92,    -1,
      -1,    95,    96,    97,    -1,    -1,    -1,   101,    -1,    -1,
      -1,    -1,   106,   107,   108,    -1,    -1,   111,   112,    -1,
      -1,    -1,    -1,    -1,    -1,   119,   120,   121,   122,    -1,
     124,    -1,    -1,    -1,   128,   129,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,   140,   141,    -1,   143,
     144,   145,    -1,    -1,    -1,   149,    -1,    -1,   152,   153,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     174,    -1,    -1,    -1,   178,    -1,   180,   181,    -1,    -1,
      -1,    -1,    -1,    -1,   188,    -1,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,   203,
     204,    -1,    -1,   207,   208,    -1,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,    -1,   253,
     254,   255,    -1,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    -1,    87,
      -1,    89,    90,    91,    92,    -1,    -1,    95,    96,    97,
      -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,   106,   107,
     108,    -1,    -1,   111,   112,    -1,    -1,    -1,    -1,    -1,
      -1,   119,   120,   121,   122,    -1,   124,    -1,    -1,    -1,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   140,   141,    -1,   143,   144,   145,    -1,    -1,
      -1,    -1,    -1,    -1,   152,   153,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,
     178,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     188,    -1,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,    -1,   203,   204,    -1,    -1,   207,
     208,    -1,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,    -1,   253,   254,   255,    -1,   257,
     258,   259,   260,   261,   262,    -1,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    10,    17,    18,    21,    26,    27,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    89,    90,    91,    92,    93,    94,
      95,    96,    97,   100,   101,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   117,   119,   120,   121,
     122,   124,   128,   129,   130,   131,   132,   139,   140,   141,
     142,   143,   144,   145,   149,   150,   151,   152,   153,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   168,   169,
     172,   173,   174,   178,   180,   181,   182,   184,   185,   186,
     188,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   203,   204,   205,   207,   208,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   253,
     254,   255,   257,   258,   259,   260,   261,   262,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   349,   350,   355,   358,   361,   364,
     365,   367,   372,   373,   374,   375,   376,   385,   386,   388,
     389,   390,   395,   397,   399,   400,   401,   406,   427,   430,
     434,   437,   438,   439,   440,   442,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   488,   489,   490,   504,   505,
     507,   508,   509,   510,   511,   512,   513,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   533,   534,   535,
     536,   541,   542,   543,   544,   545,   546,   549,   555,   556,
     557,    29,    30,    32,    33,    35,    41,    49,    51,    52,
      59,    61,    70,    74,   106,   107,   108,   153,   162,   194,
     213,   223,   255,   281,   282,   283,   284,   285,   287,   288,
     289,   290,   291,   296,   297,   356,   357,   377,   378,   379,
     380,   153,   146,   149,   146,   149,    26,    27,    31,    36,
      37,    38,    39,    40,    41,    42,    43,    45,    53,    55,
      58,    60,    63,    66,    69,    71,    92,   128,   146,   149,
     162,   194,   207,   217,   218,   219,   221,   222,   229,   231,
     232,   233,   234,   237,   238,   240,   556,   146,    62,    67,
     113,   392,   149,   366,   149,    27,    56,   113,    40,    14,
     146,   149,   554,   556,   149,   113,   113,   146,   149,   149,
     149,    89,   146,   214,   215,   146,   149,   556,    31,    38,
      55,    66,    92,   472,   556,   556,   113,   179,   386,   556,
     146,   554,    16,   556,   556,   464,   146,    22,   206,   208,
     218,   220,   149,   218,   220,   218,   218,   223,   113,   146,
     368,   235,   235,   236,   149,   146,   113,   320,     0,   322,
     323,    26,    43,   325,   385,   183,   183,   102,   183,   387,
      34,    40,    45,    53,    65,   161,   164,   178,   204,   391,
     396,   397,   398,   415,   416,   420,   402,   403,   556,   160,
      87,   125,   133,   134,   136,   144,   148,   150,   155,   171,
     195,   196,   197,   198,   199,   200,   456,   457,   243,   151,
     168,   191,   112,   139,   152,   186,   193,   202,   129,   143,
      44,   192,    96,    97,   151,   168,   455,   146,   461,   464,
     184,   185,   147,   476,   477,   472,   476,   472,   149,   476,
     138,   149,    21,   553,   174,   188,   174,   188,   159,   174,
     377,   556,   377,   556,   162,   194,    41,   378,    41,   556,
     145,   113,   354,    38,    41,    74,   101,   161,   554,   214,
     215,   216,   294,   295,   240,   584,   556,   287,   556,   292,
     292,   294,   295,   298,   281,   289,   357,   554,   386,   179,
     386,    38,    58,   179,   529,   530,   386,   179,   186,   556,
     146,   389,   278,   278,   113,   410,   113,   179,   381,   382,
     146,   383,   386,   153,   553,   108,   153,   348,   553,   407,
     409,   556,   113,   386,    21,   179,   554,   146,   556,   556,
     428,   429,   556,   386,   179,   386,   386,   531,   556,   386,
     146,   146,   386,   179,   186,   556,   146,   428,   179,    28,
     492,   493,   494,   386,     7,   167,    15,   179,   386,   206,
      21,   389,   389,   179,   389,   389,   389,   389,   224,   547,
     548,   556,   369,   389,   389,   386,   408,   414,   556,   327,
     328,    26,   329,   389,   388,   113,   161,   163,   163,   389,
     389,   102,    89,    91,   140,   267,   404,   405,   515,   439,
     440,   442,   442,   442,   442,   441,   442,   442,   442,    66,
     446,   446,   445,   447,   447,   447,   447,   448,   448,   449,
     449,   224,    89,    89,    89,   176,   386,   464,   464,   386,
     477,   179,   389,   487,   142,   179,   487,   102,   102,   366,
      21,   556,   556,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,   331,   332,   333,    89,   130,   135,   351,
     352,   353,   556,   130,   135,   153,   153,   331,   553,   120,
     125,    48,    51,    95,   245,   258,   260,   271,   272,   273,
     275,   277,   585,   586,   587,   588,   589,   590,   597,   603,
     604,   240,    89,   230,   360,   293,   556,   556,   556,   125,
     176,   176,   179,   179,   176,   102,   179,   102,   179,   176,
     386,   176,   556,    50,   210,   248,   393,   394,   556,    89,
     102,   179,   386,   179,   554,    91,    38,   554,   553,    91,
     102,   135,   405,   515,   176,   179,   179,   176,   386,   179,
     135,   102,   180,   140,   515,   176,   179,   179,   146,   176,
     386,   386,   176,   102,   179,   102,   179,   176,   386,   180,
     556,   493,   494,   123,   189,   176,   176,   124,   183,    89,
     211,   212,   226,    89,   211,   212,   226,    89,   230,   218,
     102,   228,   135,    26,   370,   386,   179,   176,    39,   102,
     183,   108,   183,   556,   163,   389,   421,   422,   113,   417,
     418,   113,    41,   145,   149,   203,   516,   518,   520,   521,
     537,   538,   539,   540,   556,   113,   389,   113,   140,   405,
     140,   140,   404,   405,   442,   146,   149,   253,   460,   479,
     558,   561,   562,   563,   564,   565,   569,   571,   573,   574,
     516,   516,   514,   520,   514,   176,   177,   102,   179,   179,
     141,   158,   141,   158,   130,   146,   384,   366,   366,   332,
     125,   518,   353,   389,   515,   135,   389,   553,   553,   121,
     122,   553,   271,   272,   273,   277,   556,   257,   268,   257,
     268,    21,   280,    91,   108,   149,   591,   594,   585,    31,
      37,    55,    66,    92,   218,   359,   521,   285,   286,   220,
     293,   302,    89,   360,   293,   553,   146,   531,   532,   556,
     531,   532,   176,   140,   515,   248,    47,    54,    72,   113,
     404,   411,   412,   413,   394,   515,   516,   382,    89,   176,
     190,   125,   347,   553,   153,   125,    91,   347,   113,   389,
     135,   135,   405,   146,   176,   389,   113,   389,   389,   140,
      95,   431,   432,   433,    95,   435,   436,   386,   176,   176,
     146,   531,   531,   176,   389,    28,   494,   123,   189,     8,
       9,    98,   116,   118,   187,   383,   489,   491,   502,   503,
     506,    21,   225,   227,   389,   389,   389,   225,   227,   389,
     389,   389,   389,   389,   389,   113,   389,   389,   354,   371,
     102,   183,   176,   368,   239,   550,   551,   146,   113,   421,
      90,   101,   111,   120,   423,   424,   425,   426,   102,   556,
     102,   403,   149,   149,   518,   149,   137,   168,   186,   517,
     556,   556,   389,   140,   389,   389,   140,   405,   140,   386,
     558,   565,   146,   279,   443,   610,    91,   162,   246,   247,
     249,   256,   266,   278,   559,   560,   579,   580,   581,   582,
     605,   608,   252,   254,   566,   584,   261,   570,   606,   241,
     242,   264,   575,   576,   137,   389,   386,   130,   368,   130,
     146,   533,   352,   389,   280,    21,    91,   108,   149,   598,
      21,   591,   360,   517,   220,   220,   462,   281,   300,   359,
     220,   183,   176,   386,   179,   179,   137,   179,   179,   389,
     140,   113,   113,   389,   556,   413,    72,   516,   389,   553,
     102,   347,   409,   389,   389,   135,   176,   386,   429,   389,
     389,   108,   432,    95,   178,   113,   516,   108,   436,   176,
     176,   386,   179,   179,   125,   187,   491,     6,   556,   187,
     502,   183,   226,   226,   226,   226,   230,   548,   178,   135,
     371,   473,   552,   551,   389,   414,   553,   121,   122,   425,
     426,   426,   422,   101,   419,   418,   179,   186,   516,   519,
     179,   179,   179,   389,   389,   140,   389,   176,   179,   558,
     572,   244,   210,   248,   262,   269,   609,    91,   250,   251,
     607,   244,   562,   609,   445,   579,   563,   140,   276,   567,
     568,   607,   280,   578,    73,   577,   176,   388,    21,   129,
     193,   600,   601,   602,    21,   599,   600,   265,   595,   592,
     593,   594,   163,   556,   251,   360,   462,   176,   389,   556,
     556,   412,   389,   119,    91,   553,   389,   176,   178,   389,
     389,   556,   178,   113,   178,   176,   494,   556,   187,   494,
     556,   389,   389,   389,   389,   389,   389,   389,   149,   202,
     384,   176,   426,   553,    89,   179,   102,   179,   389,   176,
     447,    46,   122,   445,   445,   263,   270,   280,   583,   583,
     564,   146,   274,   176,   598,   598,   602,   102,   179,    21,
     596,   607,   179,   102,   362,   363,   462,   113,   218,   301,
     281,   163,    47,   389,   347,   389,    89,   389,   556,   389,
      88,   175,   495,   494,   556,   189,   494,   113,   473,   516,
     516,    89,   445,   445,   191,   386,    21,   259,   594,   102,
      89,   556,   113,   218,   556,   362,   113,   516,   178,     4,
     126,   498,   499,   501,   503,    20,   127,   496,   497,   500,
     503,   189,   494,   189,   556,   516,   445,   176,   363,   520,
     299,   556,   113,   218,   556,   178,   389,    88,   126,   501,
     175,   127,   500,   189,   102,   179,   426,   389,   299,   556,
     113,   389,   113,   384,   287,   299,   556,   556,   300,   389,
     300,   102,   179,   462,   462,   113,   384,   191,   556,   281,
     179,   556,   384,   218,   113,   556,   300,   462
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  xquery_parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   113,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   318,   319,   319,   320,   320,   320,   320,   321,   321,
     322,   322,   323,   323,   324,   325,   325,   325,   326,   326,
     327,   327,   328,   328,   328,   328,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   330,   330,   331,   331,   332,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     334,   334,   334,   334,   334,   334,   334,   334,   335,   335,
     336,   337,   337,   338,   338,   339,   340,   341,   341,   342,
     342,   343,   343,   343,   343,   344,   345,   346,   346,   346,
     346,   347,   347,   348,   348,   349,   349,   349,   349,   350,
     351,   351,   352,   352,   352,   353,   354,   354,   355,   355,
     355,   356,   356,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   358,   358,   358,
     358,   358,   358,   358,   358,   359,   359,   360,   360,   361,
     361,   362,   362,   363,   363,   364,   364,   364,   364,   365,
     365,   366,   366,   366,   366,   367,   368,   369,   369,   370,
     370,   371,   371,   372,   373,   374,   375,   375,   376,   376,
     376,   377,   377,   377,   377,   378,   378,   379,   379,   380,
     380,   381,   381,   382,   382,   383,   384,   385,   386,   386,
     387,   387,   388,   388,   389,   389,   389,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   389,   390,   391,   392,   392,   393,   393,   393,   394,
     394,   395,   395,   396,   397,   397,   397,   398,   398,   398,
     398,   398,   399,   399,   400,   400,   401,   402,   402,   403,
     403,   403,   403,   403,   403,   403,   403,   404,   405,   406,
     407,   407,   408,   408,   409,   409,   409,   409,   410,   410,
     411,   411,   411,   412,   412,   412,   413,   413,   413,   414,
     415,   416,   417,   417,   418,   418,   419,   420,   420,   421,
     421,   422,   422,   423,   423,   423,   423,   423,   423,   423,
     424,   424,   425,   425,   426,   427,   427,   428,   428,   429,
     429,   430,   431,   431,   432,   433,   433,   434,   434,   435,
     435,   436,   436,   437,   438,   438,   439,   439,   440,   440,
     440,   440,   440,   441,   440,   440,   440,   440,   442,   442,
     443,   443,   444,   444,   445,   445,   445,   446,   446,   446,
     446,   446,   447,   447,   447,   448,   448,   448,   449,   449,
     450,   450,   451,   451,   452,   452,   453,   453,   454,   454,
     454,   454,   455,   455,   455,   456,   456,   456,   456,   456,
     456,   457,   457,   457,   458,   458,   458,   458,   459,   459,
     460,   460,   461,   461,   462,   462,   462,   462,   463,   464,
     464,   464,   465,   465,   466,   466,   466,   466,   467,   467,
     468,   468,   468,   468,   468,   468,   468,   469,   469,   470,
     470,   471,   471,   471,   471,   471,   472,   472,   473,   473,
     474,   474,   474,   475,   475,   475,   475,   476,   476,   477,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   479,
     479,   480,   480,   480,   481,   482,   482,   483,   484,   485,
     486,   486,   487,   487,   488,   488,   489,   489,   489,   490,
     490,   490,   490,   490,   490,   491,   491,   492,   492,   493,
     494,   494,   495,   495,   496,   496,   497,   497,   497,   497,
     498,   498,   499,   499,   499,   499,   500,   500,   501,   501,
     502,   502,   502,   502,   503,   503,   503,   503,   504,   504,
     505,   505,   506,   507,   507,   507,   507,   507,   507,   508,
     509,   509,   509,   509,   510,   510,   510,   510,   511,   512,
     513,   513,   513,   513,   514,   514,   515,   516,   516,   516,
     517,   517,   517,   518,   518,   518,   518,   518,   519,   519,
     520,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     522,   523,   523,   523,   524,   525,   526,   526,   526,   527,
     527,   527,   527,   527,   528,   529,   529,   529,   529,   529,
     529,   529,   530,   531,   532,   533,   534,   534,   535,   536,
     537,   537,   538,   539,   539,   540,   541,   541,   541,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   543,
     543,   544,   544,   545,   546,   547,   547,   548,   549,   550,
     550,   551,   551,   551,   551,   552,   552,   553,   554,   554,
     555,   555,   556,   556,   557,   557,   557,   557,   557,   557,
     557,   557,   557,   557,   557,   557,   557,   557,   557,   557,
     557,   557,   557,   557,   557,   557,   557,   557,   557,   557,
     557,   557,   557,   557,   557,   557,   557,   557,   557,   557,
     557,   557,   557,   557,   557,   557,   557,   557,   557,   557,
     557,   557,   557,   557,   557,   557,   557,   557,   557,   557,
     557,   557,   557,   557,   557,   557,   557,   557,   557,   557,
     557,   557,   557,   557,   557,   557,   557,   557,   557,   557,
     557,   557,   557,   557,   557,   557,   557,   557,   557,   557,
     557,   557,   557,   557,   557,   557,   557,   557,   557,   557,
     557,   557,   557,   557,   557,   557,   557,   557,   557,   557,
     557,   557,   557,   557,   557,   557,   557,   557,   557,   557,
     557,   557,   557,   557,   557,   557,   557,   557,   557,   557,
     557,   557,   557,   557,   557,   557,   557,   557,   557,   557,
     557,   557,   557,   557,   557,   557,   557,   557,   557,   557,
     557,   557,   557,   557,   557,   557,   557,   557,   557,   557,
     557,   557,   557,   557,   557,   557,   557,   557,   557,   557,
     557,   557,   557,   557,   557,   557,   557,   557,   557,   557,
     557,   557,   557,   557,   557,   557,   557,   557,   557,   557,
     557,   557,   557,   557,   557,   557,   557,   557,   557,   557,
     557,   557,   557,   557,   557,   557,   558,   559,   559,   560,
     560,   561,   561,   562,   562,   563,   563,   564,   564,   565,
     566,   566,   567,   567,   568,   569,   569,   569,   570,   570,
     571,   572,   572,   573,   574,   574,   575,   575,   576,   576,
     576,   577,   577,   578,   578,   579,   579,   579,   579,   579,
     580,   581,   582,   583,   583,   583,   584,   584,   585,   585,
     585,   585,   585,   585,   585,   585,   586,   586,   586,   586,
     587,   587,   588,   589,   589,   590,   590,   590,   591,   591,
     592,   592,   593,   593,   594,   595,   595,   596,   596,   597,
     597,   597,   598,   598,   599,   599,   600,   600,   601,   601,
     602,   602,   603,   604,   604,   605,   605,   605,   606,   607,
     607,   607,   607,   608,   608,   609,   609,   610
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
       3,     1,     2,     1,     1,     4,     4,     5,     5,     7,
       5,     1,     3,     2,     3,     3,     3,     1,     1,     2,
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
       7,     4,     1,     1,     1,     1,     1,     1,     1,     1,
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
  "\"'*:QName'\"", "QNAME_SVAL", "'q'", "\"'quote attribute content'\"",
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
  "FunctionDeclSimple", "FunctionDeclSequential", "FunctionDeclUpdating",
  "ParamList", "Param", "EnclosedExpr", "BracedExpr", "QueryBody", "Expr",
  "ApplyExpr", "ConcatExpr", "ExprSingle", "FLWORExpr", "ReturnExpr",
  "WindowType", "FLWORWinCondType", "FLWORWinCond", "WindowClause",
  "CountClause", "ForLetWinClause", "FLWORClause", "FLWORClauseList",
  "ForDollar", "ForClause", "VarInDeclList", "VarInDecl", "PositionalVar",
  "FTScoreVar", "LetClause", "VarGetsDeclList", "EvalVarDeclList",
  "VarGetsDecl", "WindowVarDecl", "WindowVars", "WindowVars3",
  "WindowVars2", "EvalVarDecl", "WhereClause", "GroupByClause",
  "GroupSpecList", "GroupSpec", "GroupCollationSpec", "OrderByClause",
  "OrderSpecList", "OrderSpec", "OrderModifier", "OrderDirSpec",
  "OrderEmptySpec", "OrderCollationSpec", "QuantifiedExpr",
  "QVarInDeclList", "QVarInDecl", "SwitchExpr", "SwitchCaseClauseList",
  "SwitchCaseClause", "SwitchCaseOperandList", "TypeswitchExpr",
  "CaseClauseList", "CaseClause", "IfExpr", "OrExpr", "AndExpr",
  "ComparisonExpr", "$@1", "FTContainsExpr", "opt_FTIgnoreOption",
  "RangeExpr", "AdditiveExpr", "MultiplicativeExpr", "UnionExpr",
  "IntersectExceptExpr", "InstanceofExpr", "TreatExpr", "CastableExpr",
  "CastExpr", "UnaryExpr", "SignList", "ValueExpr", "ValueComp",
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
  "EvalExpr", "QNAME", "KEYWORD", "FTSelection", "opt_FTPosFilter_list",
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
       319,     0,    -1,   320,    -1,   304,   320,    -1,   322,    -1,
     321,   322,    -1,   323,    -1,   321,   323,    -1,   207,   208,
      21,   183,    -1,   207,   208,    21,   124,    21,   183,    -1,
     325,   385,    -1,   385,    -1,   324,    -1,   324,   325,    -1,
      27,   153,   554,   125,   553,   183,    -1,   326,   183,    -1,
     327,   183,    -1,   326,   183,   327,   183,    -1,   328,    -1,
     326,   183,   328,    -1,   329,    -1,   327,   183,   329,    -1,
     334,    -1,   335,    -1,   336,    -1,   338,    -1,   355,    -1,
     358,    -1,   350,    -1,   330,    -1,   340,    -1,   376,    -1,
     361,    -1,   364,    -1,   339,    -1,    26,   108,    74,   331,
      -1,    26,    74,   556,   331,    -1,   332,    -1,   331,   332,
      -1,   333,   125,   533,    -1,    75,    -1,    83,    -1,    76,
      -1,    77,    -1,    78,    -1,    79,    -1,    84,    -1,    80,
      -1,    81,    -1,    82,    -1,   337,    -1,   344,    -1,   345,
      -1,   365,    -1,   341,    -1,   342,    -1,   343,    -1,   541,
      -1,   346,    -1,   349,    -1,    26,   153,   554,   125,   553,
      -1,    26,    30,   174,    -1,    26,    30,   188,    -1,    26,
     108,    38,   153,   553,    -1,    26,   108,    41,   153,   553,
      -1,    26,    51,   556,    21,    -1,    26,   255,   584,    -1,
      26,    52,   162,    -1,    26,    52,   194,    -1,    26,   108,
     161,   120,   121,    -1,    26,   108,   161,   120,   122,    -1,
      26,    33,   174,   102,   141,    -1,    26,    33,   174,   102,
     158,    -1,    26,    33,   159,   102,   141,    -1,    26,    33,
     159,   102,   158,    -1,    26,   108,   101,   553,    -1,    26,
      29,   553,    -1,    43,    56,   553,    -1,    43,    56,   348,
     553,    -1,    43,    56,   553,    91,   347,    -1,    43,    56,
     348,   553,    91,   347,    -1,   553,    -1,   347,   102,   553,
      -1,   153,   554,   125,    -1,   108,    38,   153,    -1,    43,
      27,   553,    -1,    43,    27,   153,   554,   125,   553,    -1,
      43,    27,   553,    91,   347,    -1,    43,    27,   153,   554,
     125,   553,    91,   347,    -1,    26,   106,   145,   351,    -1,
      89,   518,   352,    -1,   352,    -1,   353,    -1,   130,    -1,
     130,   353,    -1,   135,   389,    -1,   113,   556,    -1,   113,
     556,   515,    -1,    26,   107,   354,   135,   389,    -1,    26,
     107,   354,   130,    -1,    26,   107,   354,   130,   135,   389,
      -1,   357,    -1,   356,   357,    -1,   282,    -1,   283,    -1,
     284,    -1,   285,    -1,   162,    -1,   194,    -1,   223,   295,
      -1,   223,   294,    -1,   296,   295,    -1,   296,   294,    -1,
     287,    -1,   288,   287,    -1,   291,   292,    -1,   290,   292,
      -1,    26,   281,   556,    -1,    26,   281,   556,   360,    -1,
      26,   281,   556,    89,   359,    -1,    26,   281,   556,    89,
     359,   360,    -1,    26,   356,   281,   556,    -1,    26,   356,
     281,   556,   360,    -1,    26,   356,   281,   556,    89,   359,
      -1,    26,   356,   281,   556,    89,   359,   360,    -1,   521,
      -1,   521,   517,    -1,   230,   286,   220,    -1,   230,   285,
     220,    -1,    26,   289,   556,   293,   220,   462,   163,   362,
      -1,    26,   356,   289,   556,   293,   220,   462,   163,   362,
      -1,   363,    -1,   362,   102,   363,    -1,   462,    89,   520,
      -1,   462,    89,   520,   426,    -1,    26,   297,   298,   556,
     293,   281,   556,   113,   556,   299,   389,    -1,    26,   297,
     298,   556,   293,   281,   556,   218,   113,   556,   299,   287,
     300,   462,    -1,    26,   297,   298,   556,   293,   281,   556,
     301,   218,   113,   556,   299,   389,    -1,    26,   297,   298,
     556,   302,   300,   251,   281,   556,   218,   113,   556,   300,
     462,   191,   281,   556,   218,   113,   556,   300,   462,    -1,
      26,    32,   174,    -1,    26,    32,   188,    -1,   149,   179,
      -1,   149,   381,   179,    -1,   149,   179,    89,   516,    -1,
     149,   381,   179,    89,   516,    -1,   231,   368,    -1,   146,
     369,   386,   176,    -1,   369,   370,   183,    -1,    -1,   370,
     102,   371,    -1,    26,   371,    -1,   354,    -1,   354,   135,
     389,    -1,    60,   113,   556,   135,   389,    -1,   234,   236,
     389,    -1,   237,   149,   389,   179,   368,    -1,   232,   235,
      -1,   233,   235,    -1,    26,   377,    -1,    26,    49,   377,
      -1,    26,    35,   377,    -1,   378,    -1,    61,   378,    -1,
     380,    -1,   379,    -1,    41,   556,   366,   384,    -1,    41,
     556,   366,   130,    -1,    59,    41,   556,   366,   368,    -1,
      59,    41,   556,   366,   130,    -1,    70,    41,   556,   366,
     146,   388,   176,    -1,    70,    41,   556,   366,   130,    -1,
     382,    -1,   381,   102,   382,    -1,   113,   556,    -1,   113,
     556,   515,    -1,   146,   386,   176,    -1,   146,   386,   176,
      -1,   386,    -1,   388,    -1,   388,   387,    -1,   183,    -1,
     387,   388,   183,    -1,   389,    -1,   388,   102,   389,    -1,
     390,    -1,   427,    -1,   430,    -1,   434,    -1,   437,    -1,
     438,    -1,   542,    -1,   543,    -1,   545,    -1,   544,    -1,
     546,    -1,   549,    -1,   555,    -1,   373,    -1,   374,    -1,
     375,    -1,   372,    -1,   367,    -1,   399,   391,    -1,   178,
     389,    -1,    62,   278,    -1,    67,   278,    -1,   210,    -1,
     248,    -1,    50,   248,    -1,   393,   411,    72,   389,    -1,
     393,    72,   389,    -1,    40,   392,   410,   394,   394,    -1,
      40,   392,   410,   394,    -1,    34,   113,   556,    -1,   401,
      -1,   406,    -1,   395,    -1,   397,    -1,   415,    -1,   420,
      -1,   416,    -1,   396,    -1,   397,    -1,   399,   398,    -1,
      40,   113,    -1,    53,    40,   113,    -1,   400,   402,    -1,
     403,    -1,   402,   102,   113,   403,    -1,   556,   140,   389,
      -1,   556,   515,   140,   389,    -1,   556,   404,   140,   389,
      -1,   556,   515,   404,   140,   389,    -1,   556,   405,   140,
     389,    -1,   556,   515,   405,   140,   389,    -1,   556,   404,
     405,   140,   389,    -1,   556,   515,   404,   405,   140,   389,
      -1,    91,   113,   556,    -1,   267,   113,   556,    -1,    45,
     113,   407,    -1,   409,    -1,   407,   102,   113,   409,    -1,
     414,    -1,   408,   102,   113,   414,    -1,   556,   135,   389,
      -1,   556,   515,   135,   389,    -1,   556,   405,   135,   389,
      -1,   556,   515,   405,   135,   389,    -1,   113,   556,   140,
     389,    -1,   113,   556,   515,   140,   389,    -1,   412,    -1,
     113,   556,    -1,   113,   556,   412,    -1,   404,    -1,   404,
     413,    -1,   413,    -1,    54,   113,   556,    47,   113,   556,
      -1,    47,   113,   556,    -1,    54,   113,   556,    -1,   556,
      -1,   204,   389,    -1,   164,   163,   417,    -1,   418,    -1,
     417,   102,   418,    -1,   113,   556,    -1,   113,   556,   419,
      -1,   101,   553,    -1,   161,   163,   421,    -1,    65,   161,
     163,   421,    -1,   422,    -1,   421,   102,   422,    -1,   389,
      -1,   389,   423,    -1,   424,    -1,   425,    -1,   426,    -1,
     424,   425,    -1,   424,   426,    -1,   425,   426,    -1,   424,
     425,   426,    -1,    90,    -1,   111,    -1,   120,   121,    -1,
     120,   122,    -1,   101,   553,    -1,    63,   113,   428,   180,
     389,    -1,   128,   113,   428,   180,   389,    -1,   429,    -1,
     428,   102,   113,   429,    -1,   556,   140,   389,    -1,   556,
     515,   140,   389,    -1,    68,   149,   386,   179,   431,   108,
     178,   389,    -1,   432,    -1,   431,   432,    -1,   433,   178,
     389,    -1,    95,   389,    -1,   433,    95,   389,    -1,    69,
     149,   386,   179,   435,   108,   178,   389,    -1,    69,   149,
     386,   179,   435,   108,   113,   556,   178,   389,    -1,   436,
      -1,   435,   436,    -1,    95,   516,   178,   389,    -1,    95,
     113,   556,    89,   516,   178,   389,    -1,    42,   149,   386,
     179,   190,   389,   119,   389,    -1,   439,    -1,   438,   160,
     439,    -1,   440,    -1,   439,    87,   440,    -1,   442,    -1,
     442,   456,   442,    -1,   442,   457,   442,    -1,   442,   125,
     442,    -1,   442,   155,   442,    -1,    -1,   442,   150,   441,
     442,    -1,   442,   148,   442,    -1,   442,   136,   442,    -1,
     442,   134,   442,    -1,   444,    -1,   444,   243,    66,   558,
     443,    -1,    -1,   610,    -1,   445,    -1,   445,   191,   445,
      -1,   446,    -1,   445,   168,   446,    -1,   445,   151,   446,
      -1,   447,    -1,   446,   186,   447,    -1,   446,   112,   447,
      -1,   446,   139,   447,    -1,   446,   152,   447,    -1,   448,
      -1,   447,   193,   448,    -1,   447,   202,   448,    -1,   449,
      -1,   448,   143,   449,    -1,   448,   129,   449,    -1,   450,
      -1,   450,    44,   224,   516,    -1,   451,    -1,   451,   192,
      89,   516,    -1,   452,    -1,   452,    96,    89,   514,    -1,
     453,    -1,   453,    97,    89,   514,    -1,   455,    -1,   454,
     455,    -1,   168,    -1,   151,    -1,   454,   168,    -1,   454,
     151,    -1,   458,    -1,   462,    -1,   459,    -1,   195,    -1,
     200,    -1,   199,    -1,   198,    -1,   197,    -1,   196,    -1,
     144,    -1,   171,    -1,   133,    -1,    71,   146,   386,   176,
      -1,    71,   215,   146,   386,   176,    -1,    71,   214,   146,
     386,   176,    -1,    71,    89,   531,   146,   386,   176,    -1,
     460,   146,   176,    -1,   460,   146,   386,   176,    -1,   461,
      -1,   460,   461,    -1,   169,   556,    15,    -1,   169,    16,
      -1,   463,    -1,   463,   464,    -1,   185,   464,    -1,   464,
      -1,   184,    -1,   465,    -1,   465,   184,   464,    -1,   465,
     185,   464,    -1,   466,    -1,   475,    -1,   467,    -1,   467,
     476,    -1,   470,    -1,   470,   476,    -1,   468,   472,    -1,
     469,    -1,   100,    -1,   109,    -1,    93,    -1,   182,    -1,
     110,    -1,   132,    -1,   131,    -1,   472,    -1,    94,   472,
      -1,   471,   472,    -1,   115,    -1,   165,    -1,    85,    -1,
     173,    -1,   172,    -1,    86,    -1,   521,    -1,   473,    -1,
     556,    -1,   474,    -1,   186,    -1,    10,    -1,    17,    -1,
     478,    -1,   475,   476,    -1,   475,   149,   179,    -1,   475,
     149,   487,   179,    -1,   477,    -1,   476,   477,    -1,   147,
     386,   177,    -1,   479,    -1,   481,    -1,   482,    -1,   483,
      -1,   486,    -1,   488,    -1,   484,    -1,   485,    -1,   534,
      -1,   480,    -1,   533,    -1,   105,    -1,   142,    -1,   117,
      -1,   113,   556,    -1,   149,   179,    -1,   149,   386,   179,
      -1,   114,    -1,   162,   146,   386,   176,    -1,   194,   146,
     386,   176,    -1,   556,   149,   179,    -1,   556,   149,   487,
     179,    -1,   389,    -1,   487,   102,   389,    -1,   489,    -1,
     507,    -1,   490,    -1,   504,    -1,   505,    -1,   150,   556,
     494,   123,    -1,   150,   556,   492,   494,   123,    -1,   150,
     556,   494,   189,   187,   556,   494,   189,    -1,   150,   556,
     494,   189,   491,   187,   556,   494,   189,    -1,   150,   556,
     492,   494,   189,   187,   556,   494,   189,    -1,   150,   556,
     492,   494,   189,   491,   187,   556,   494,   189,    -1,   502,
      -1,   491,   502,    -1,   493,    -1,   492,   493,    -1,    28,
     556,   494,   125,   494,   495,    -1,    -1,    28,    -1,   175,
     496,   175,    -1,    88,   498,    88,    -1,    -1,   497,    -1,
     127,    -1,   500,    -1,   497,   127,    -1,   497,   500,    -1,
      -1,   499,    -1,   126,    -1,   501,    -1,   499,   126,    -1,
     499,   501,    -1,    20,    -1,   503,    -1,     4,    -1,   503,
      -1,   489,    -1,     9,    -1,   506,    -1,   503,    -1,     8,
      -1,   116,    -1,   118,    -1,   383,    -1,   205,    22,   206,
      -1,   205,   206,    -1,   166,   554,   167,    -1,   166,   554,
       7,    -1,    98,     6,    -1,   508,    -1,   509,    -1,   510,
      -1,   511,    -1,   512,    -1,   513,    -1,    36,   146,   386,
     176,    -1,    38,   556,   146,   176,    -1,    38,   556,   146,
     386,   176,    -1,    38,   146,   386,   176,   146,   176,    -1,
      38,   146,   386,   176,   146,   386,   176,    -1,    92,   556,
     146,   176,    -1,    92,   556,   146,   386,   176,    -1,    92,
     146,   386,   176,   146,   176,    -1,    92,   146,   386,   176,
     146,   386,   176,    -1,    66,   146,   386,   176,    -1,    31,
     146,   386,   176,    -1,    55,   554,   146,   176,    -1,    55,
     554,   146,   386,   176,    -1,    55,   146,   386,   176,   146,
     176,    -1,    55,   146,   386,   176,   146,   386,   176,    -1,
     520,    -1,   520,   137,    -1,    89,   516,    -1,   518,    -1,
     518,   517,    -1,   203,   149,   179,    -1,   137,    -1,   186,
      -1,   168,    -1,   520,    -1,   521,    -1,   145,   149,   179,
      -1,   537,    -1,   540,    -1,   516,    -1,   519,   102,   516,
      -1,   556,    -1,   523,    -1,   529,    -1,   527,    -1,   530,
      -1,   528,    -1,   526,    -1,   525,    -1,   524,    -1,   522,
      -1,   218,   149,   179,    -1,    37,   149,   179,    -1,    37,
     149,   529,   179,    -1,    37,   149,   530,   179,    -1,    66,
     149,   179,    -1,    31,   149,   179,    -1,    55,   149,   179,
      -1,    55,   149,   554,   179,    -1,    55,   149,    21,   179,
      -1,    92,   149,   179,    -1,    92,   149,   556,   179,    -1,
      92,   149,   556,   102,   531,   179,    -1,    92,   149,   186,
     179,    -1,    92,   149,   186,   102,   531,   179,    -1,   181,
     556,   179,    -1,    38,   149,   179,    -1,    38,   149,   556,
     179,    -1,    38,   149,   556,   102,   531,   179,    -1,    38,
     149,   556,   102,   532,   179,    -1,    38,   149,   186,   179,
      -1,    38,   149,   186,   102,   531,   179,    -1,    38,   149,
     186,   102,   532,   179,    -1,    58,   149,   556,   179,    -1,
     556,    -1,   556,   137,    -1,    21,    -1,   535,    -1,   536,
      -1,   556,   138,   142,    -1,    41,   366,   383,    -1,   538,
      -1,   539,    -1,    41,   149,   186,   179,    -1,    41,   149,
     179,    89,   516,    -1,    41,   149,   519,   179,    89,   516,
      -1,   149,   518,   179,    -1,    26,   213,   214,    -1,    26,
     213,   215,    -1,    26,   213,   216,    -1,   219,   218,   389,
     226,   389,    -1,   219,   218,   389,    89,   225,   226,   389,
      -1,   219,   218,   389,    89,   227,   226,   389,    -1,   219,
     218,   389,   211,   389,    -1,   219,   218,   389,   212,   389,
      -1,   219,   220,   389,   226,   389,    -1,   219,   220,   389,
      89,   225,   226,   389,    -1,   219,   220,   389,    89,   227,
     226,   389,    -1,   219,   220,   389,   211,   389,    -1,   219,
     220,   389,   212,   389,    -1,   217,   218,   389,    -1,   217,
     220,   389,    -1,   222,   218,   389,   230,   389,    -1,   222,
     223,   224,   218,   389,   230,   389,    -1,   221,   218,   389,
      89,   389,    -1,   229,   113,   547,   228,   389,   178,   389,
      -1,   548,    -1,   547,   102,   113,   548,    -1,   556,   135,
     389,    -1,   238,   146,   386,   176,   550,    -1,   551,    -1,
     550,   551,    -1,   239,   552,   384,    -1,   239,   552,   149,
     113,   556,   179,   384,    -1,   239,   552,   149,   113,   556,
     102,   113,   556,   179,   384,    -1,   239,   552,   149,   113,
     556,   102,   113,   556,   102,   113,   556,   179,   384,    -1,
     473,    -1,   552,   202,   473,    -1,    21,    -1,    14,    -1,
     556,    -1,   240,   113,   408,    39,   146,   389,   176,    -1,
      39,   146,   389,   176,    -1,    18,    -1,   557,    -1,   207,
      -1,   120,    -1,    92,    -1,    31,    -1,    37,    -1,    38,
      -1,   145,    -1,    42,    -1,   218,    -1,    55,    -1,    57,
      -1,    58,    -1,    66,    -1,    69,    -1,   203,    -1,    30,
      -1,   255,    -1,    29,    -1,   215,    -1,   214,    -1,   139,
      -1,    36,    -1,   253,    -1,   254,    -1,   268,    -1,   257,
      -1,   245,    -1,   279,    -1,   271,    -1,   273,    -1,   272,
      -1,   277,    -1,   249,    -1,   244,    -1,    73,    -1,   210,
      -1,   248,    -1,    46,    -1,   216,    -1,   229,    -1,   296,
      -1,   223,    -1,   195,    -1,   200,    -1,   199,    -1,   198,
      -1,   197,    -1,   196,    -1,    91,    -1,   106,    -1,   107,
      -1,   178,    -1,    40,    -1,    53,    -1,    62,    -1,    67,
      -1,    54,    -1,    47,    -1,    50,    -1,    72,    -1,    34,
      -1,   140,    -1,    45,    -1,   204,    -1,   163,    -1,   164,
      -1,   161,    -1,    65,    -1,    90,    -1,   111,    -1,   121,
      -1,   122,    -1,   101,    -1,    63,    -1,   128,    -1,   180,
      -1,    95,    -1,    89,    -1,   190,    -1,   119,    -1,   160,
      -1,    87,    -1,    44,    -1,   224,    -1,    96,    -1,   191,
      -1,   112,    -1,   152,    -1,   193,    -1,   143,    -1,   129,
      -1,    71,    -1,    97,    -1,   192,    -1,   144,    -1,   174,
      -1,   188,    -1,   153,    -1,   130,    -1,   124,    -1,   159,
      -1,   141,    -1,   158,    -1,    26,    -1,    32,    -1,    52,
      -1,   108,    -1,    33,    -1,    51,    -1,   208,    -1,    43,
      -1,    56,    -1,    27,    -1,    41,    -1,   267,    -1,   243,
      -1,   276,    -1,   278,    -1,   247,    -1,   261,    -1,   274,
      -1,   266,    -1,   246,    -1,   260,    -1,   275,    -1,   265,
      -1,   259,    -1,   258,    -1,   242,    -1,   241,    -1,   264,
      -1,   250,    -1,   251,    -1,   280,    -1,   270,    -1,   269,
      -1,   262,    -1,   222,    -1,   228,    -1,   225,    -1,   219,
      -1,   212,    -1,   211,    -1,   213,    -1,   230,    -1,   220,
      -1,   221,    -1,   227,    -1,   217,    -1,   226,    -1,    61,
      -1,    59,    -1,    70,    -1,    35,    -1,    49,    -1,   162,
      -1,   194,    -1,   236,    -1,   231,    -1,   234,    -1,   235,
      -1,   237,    -1,   232,    -1,   233,    -1,   238,    -1,   239,
      -1,    39,    -1,   240,    -1,    60,    -1,   289,    -1,   287,
      -1,   288,    -1,   293,    -1,   294,    -1,   295,    -1,   290,
      -1,   291,    -1,   292,    -1,    74,    -1,    75,    -1,    76,
      -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,    81,
      -1,    82,    -1,    83,    -1,    84,    -1,   281,    -1,   282,
      -1,   283,    -1,   284,    -1,   285,    -1,   286,    -1,   297,
      -1,   298,    -1,   299,    -1,   300,    -1,   301,    -1,   302,
      -1,   303,    -1,   561,   559,    -1,    -1,   560,    -1,   579,
      -1,   560,   579,    -1,   562,    -1,   561,   256,   562,    -1,
     563,    -1,   562,   252,   563,    -1,   564,    -1,   563,   254,
     140,   564,    -1,   565,    -1,   253,   565,    -1,   569,   566,
     567,    -1,    -1,   584,    -1,    -1,   568,    -1,   276,   146,
     386,   176,    -1,   573,   570,    -1,   149,   558,   179,    -1,
     571,    -1,    -1,   606,    -1,   460,   146,   572,   176,    -1,
      -1,   558,    -1,   574,   575,    -1,   479,    -1,   146,   386,
     176,    -1,    -1,   576,    -1,   242,   577,    -1,   241,   578,
      -1,   264,    -1,    -1,    73,    -1,    -1,   280,    -1,   580,
      -1,   581,    -1,   582,    -1,   608,    -1,   605,    -1,   162,
      -1,   278,   445,   583,    -1,   247,   607,   583,    -1,   280,
      -1,   270,    -1,   263,    -1,   240,   585,    -1,   584,   240,
     585,    -1,   586,    -1,   587,    -1,   588,    -1,   603,    -1,
     589,    -1,   597,    -1,   590,    -1,   604,    -1,    95,   268,
      -1,    95,   257,    -1,   260,    -1,   275,    -1,   245,   268,
      -1,   245,   257,    -1,    51,   556,    21,    -1,   271,    -1,
      48,   271,    -1,   273,   591,    -1,   273,   149,   591,   592,
     179,    -1,    48,   273,    -1,   594,    -1,   108,    -1,    -1,
     593,    -1,   594,    -1,   593,   102,   594,    -1,    91,    21,
     595,   596,    -1,    -1,   265,    21,    -1,    -1,   607,   259,
      -1,   272,   280,   598,   600,    -1,   272,   280,   108,   600,
      -1,    48,   272,   280,    -1,    91,    21,    -1,   149,   599,
     179,    -1,    21,    -1,   599,   102,    21,    -1,    -1,   601,
      -1,   602,    -1,   601,   602,    -1,   193,   598,    -1,   129,
     598,    -1,   258,    21,    -1,   277,    -1,    48,   277,    -1,
      91,   210,    -1,    91,   248,    -1,   249,   244,    -1,   261,
     607,   274,    -1,   250,   445,    -1,    91,   122,   445,    -1,
      91,    46,   445,    -1,   251,   445,   191,   445,    -1,   266,
     609,    -1,   246,   609,    -1,   269,    -1,   262,    -1,   279,
     244,   447,    -1
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
     631,   635,   637,   640,   642,   644,   649,   654,   660,   666,
     674,   680,   682,   686,   689,   693,   697,   701,   703,   705,
     708,   710,   714,   716,   720,   722,   724,   726,   728,   730,
     732,   734,   736,   738,   740,   742,   744,   746,   748,   750,
     752,   754,   756,   759,   762,   765,   768,   770,   772,   775,
     780,   784,   790,   795,   799,   801,   803,   805,   807,   809,
     811,   813,   815,   817,   820,   823,   827,   830,   832,   837,
     841,   846,   851,   857,   862,   868,   874,   881,   885,   889,
     893,   895,   900,   902,   907,   911,   916,   921,   927,   932,
     938,   940,   943,   947,   949,   952,   954,   961,   965,   969,
     971,   974,   978,   980,   984,   987,   991,   994,   998,  1003,
    1005,  1009,  1011,  1014,  1016,  1018,  1020,  1023,  1026,  1029,
    1033,  1035,  1037,  1040,  1043,  1046,  1052,  1058,  1060,  1065,
    1069,  1074,  1083,  1085,  1088,  1092,  1095,  1099,  1108,  1119,
    1121,  1124,  1129,  1137,  1146,  1148,  1152,  1154,  1158,  1160,
    1164,  1168,  1172,  1176,  1177,  1182,  1186,  1190,  1194,  1196,
    1202,  1203,  1205,  1207,  1211,  1213,  1217,  1221,  1223,  1227,
    1231,  1235,  1239,  1241,  1245,  1249,  1251,  1255,  1259,  1261,
    1266,  1268,  1273,  1275,  1280,  1282,  1287,  1289,  1292,  1294,
    1296,  1299,  1302,  1304,  1306,  1308,  1310,  1312,  1314,  1316,
    1318,  1320,  1322,  1324,  1326,  1331,  1337,  1343,  1350,  1354,
    1359,  1361,  1364,  1368,  1371,  1373,  1376,  1379,  1381,  1383,
    1385,  1389,  1393,  1395,  1397,  1399,  1402,  1404,  1407,  1410,
    1412,  1414,  1416,  1418,  1420,  1422,  1424,  1426,  1428,  1431,
    1434,  1436,  1438,  1440,  1442,  1444,  1446,  1448,  1450,  1452,
    1454,  1456,  1458,  1460,  1462,  1465,  1469,  1474,  1476,  1479,
    1483,  1485,  1487,  1489,  1491,  1493,  1495,  1497,  1499,  1501,
    1503,  1505,  1507,  1509,  1511,  1514,  1517,  1521,  1523,  1528,
    1533,  1537,  1542,  1544,  1548,  1550,  1552,  1554,  1556,  1558,
    1563,  1569,  1578,  1588,  1598,  1609,  1611,  1614,  1616,  1619,
    1626,  1627,  1629,  1633,  1637,  1638,  1640,  1642,  1644,  1647,
    1650,  1651,  1653,  1655,  1657,  1660,  1663,  1665,  1667,  1669,
    1671,  1673,  1675,  1677,  1679,  1681,  1683,  1685,  1687,  1691,
    1694,  1698,  1702,  1705,  1707,  1709,  1711,  1713,  1715,  1717,
    1722,  1727,  1733,  1740,  1748,  1753,  1759,  1766,  1774,  1779,
    1784,  1789,  1795,  1802,  1810,  1812,  1815,  1818,  1820,  1823,
    1827,  1829,  1831,  1833,  1835,  1837,  1841,  1843,  1845,  1847,
    1851,  1853,  1855,  1857,  1859,  1861,  1863,  1865,  1867,  1869,
    1871,  1875,  1879,  1884,  1889,  1893,  1897,  1901,  1906,  1911,
    1915,  1920,  1927,  1932,  1939,  1943,  1947,  1952,  1959,  1966,
    1971,  1978,  1985,  1990,  1992,  1995,  1997,  1999,  2001,  2005,
    2009,  2011,  2013,  2018,  2024,  2031,  2035,  2039,  2043,  2047,
    2053,  2061,  2069,  2075,  2081,  2087,  2095,  2103,  2109,  2115,
    2119,  2123,  2129,  2137,  2143,  2151,  2153,  2158,  2162,  2168,
    2170,  2173,  2177,  2185,  2196,  2210,  2212,  2216,  2218,  2220,
    2222,  2230,  2235,  2237,  2239,  2241,  2243,  2245,  2247,  2249,
    2251,  2253,  2255,  2257,  2259,  2261,  2263,  2265,  2267,  2269,
    2271,  2273,  2275,  2277,  2279,  2281,  2283,  2285,  2287,  2289,
    2291,  2293,  2295,  2297,  2299,  2301,  2303,  2305,  2307,  2309,
    2311,  2313,  2315,  2317,  2319,  2321,  2323,  2325,  2327,  2329,
    2331,  2333,  2335,  2337,  2339,  2341,  2343,  2345,  2347,  2349,
    2351,  2353,  2355,  2357,  2359,  2361,  2363,  2365,  2367,  2369,
    2371,  2373,  2375,  2377,  2379,  2381,  2383,  2385,  2387,  2389,
    2391,  2393,  2395,  2397,  2399,  2401,  2403,  2405,  2407,  2409,
    2411,  2413,  2415,  2417,  2419,  2421,  2423,  2425,  2427,  2429,
    2431,  2433,  2435,  2437,  2439,  2441,  2443,  2445,  2447,  2449,
    2451,  2453,  2455,  2457,  2459,  2461,  2463,  2465,  2467,  2469,
    2471,  2473,  2475,  2477,  2479,  2481,  2483,  2485,  2487,  2489,
    2491,  2493,  2495,  2497,  2499,  2501,  2503,  2505,  2507,  2509,
    2511,  2513,  2515,  2517,  2519,  2521,  2523,  2525,  2527,  2529,
    2531,  2533,  2535,  2537,  2539,  2541,  2543,  2545,  2547,  2549,
    2551,  2553,  2555,  2557,  2559,  2561,  2563,  2565,  2567,  2569,
    2571,  2573,  2575,  2577,  2579,  2581,  2583,  2585,  2587,  2589,
    2591,  2593,  2595,  2597,  2599,  2601,  2603,  2605,  2607,  2609,
    2611,  2613,  2615,  2617,  2619,  2621,  2623,  2625,  2627,  2629,
    2631,  2633,  2635,  2637,  2639,  2641,  2643,  2646,  2647,  2649,
    2651,  2654,  2656,  2660,  2662,  2666,  2668,  2673,  2675,  2678,
    2682,  2683,  2685,  2686,  2688,  2693,  2696,  2700,  2702,  2703,
    2705,  2710,  2711,  2713,  2716,  2718,  2722,  2723,  2725,  2728,
    2731,  2733,  2734,  2736,  2737,  2739,  2741,  2743,  2745,  2747,
    2749,  2751,  2755,  2759,  2761,  2763,  2765,  2768,  2772,  2774,
    2776,  2778,  2780,  2782,  2784,  2786,  2788,  2791,  2794,  2796,
    2798,  2801,  2804,  2808,  2810,  2813,  2816,  2822,  2825,  2827,
    2829,  2830,  2832,  2834,  2838,  2843,  2844,  2847,  2848,  2851,
    2856,  2861,  2865,  2868,  2872,  2874,  2878,  2879,  2881,  2883,
    2886,  2889,  2892,  2895,  2897,  2900,  2903,  2906,  2909,  2913,
    2916,  2920,  2924,  2929,  2932,  2935,  2937,  2939
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
    2042,  2057,  2061,  2065,  2069,  2077,  2087,  2101,  2111,  2125,
    2135,  2150,  2156,  2168,  2172,  2183,  2190,  2198,  2213,  2217,
    2231,  2235,  2244,  2248,  2262,  2263,  2264,  2265,  2266,  2267,
    2270,  2271,  2272,  2273,  2274,  2276,  2277,  2280,  2281,  2282,
    2283,  2284,  2289,  2304,  2311,  2315,  2322,  2326,  2330,  2337,
    2345,  2356,  2366,  2379,  2388,  2389,  2390,  2394,  2395,  2396,
    2397,  2398,  2401,  2407,  2416,  2420,  2428,  2438,  2444,  2456,
    2460,  2468,  2477,  2487,  2495,  2504,  2513,  2528,  2537,  2547,
    2555,  2561,  2570,  2576,  2588,  2596,  2606,  2614,  2626,  2632,
    2643,  2645,  2649,  2657,  2661,  2666,  2670,  2674,  2678,  2686,
    2700,  2708,  2715,  2721,  2732,  2736,  2745,  2753,  2759,  2769,
    2775,  2785,  2789,  2799,  2805,  2811,  2817,  2826,  2835,  2844,
    2857,  2861,  2869,  2875,  2885,  2893,  2902,  2915,  2922,  2934,
    2938,  2950,  2957,  2963,  2972,  2979,  2985,  2997,  3004,  3017,
    3023,  3035,  3041,  3053,  3062,  3066,  3075,  3079,  3087,  3091,
    3101,  3108,  3117,  3127,  3126,  3140,  3149,  3158,  3171,  3175,
    3188,  3191,  3198,  3202,  3211,  3215,  3219,  3228,  3232,  3238,
    3244,  3250,  3261,  3265,  3269,  3277,  3281,  3287,  3297,  3301,
    3311,  3315,  3325,  3329,  3339,  3343,  3353,  3357,  3365,  3369,
    3373,  3377,  3387,  3391,  3395,  3403,  3407,  3411,  3415,  3419,
    3423,  3431,  3435,  3439,  3447,  3451,  3455,  3459,  3470,  3476,
    3486,  3492,  3502,  3506,  3544,  3550,  3556,  3562,  3573,  3581,
    3592,  3598,  3608,  3612,  3620,  3626,  3634,  3640,  3652,  3658,
    3668,  3672,  3676,  3680,  3684,  3690,  3696,  3704,  3708,  3716,
    3720,  3731,  3735,  3739,  3745,  3749,  3763,  3767,  3775,  3779,
    3789,  3793,  3797,  3806,  3810,  3816,  3820,  3828,  3834,  3844,
    3852,  3856,  3860,  3864,  3868,  3872,  3876,  3880,  3884,  3892,
    3896,  3904,  3911,  3918,  3929,  3937,  3941,  3949,  3957,  3965,
    4019,  4023,  4035,  4041,  4051,  4055,  4063,  4067,  4071,  4079,
    4089,  4099,  4109,  4119,  4129,  4144,  4150,  4161,  4167,  4178,
    4189,  4191,  4195,  4200,  4210,  4213,  4220,  4228,  4234,  4244,
    4257,  4260,  4267,  4273,  4279,  4286,  4297,  4301,  4311,  4315,
    4325,  4329,  4333,  4338,  4347,  4353,  4359,  4365,  4375,  4379,
    4391,  4395,  4407,  4419,  4423,  4427,  4431,  4435,  4439,  4447,
    4455,  4461,  4467,  4471,  4488,  4492,  4496,  4500,  4508,  4516,
    4524,  4528,  4532,  4536,  4544,  4550,  4560,  4568,  4572,  4578,
    4613,  4619,  4625,  4635,  4639,  4643,  4647,  4651,  4658,  4664,
    4674,  4682,  4686,  4690,  4694,  4698,  4702,  4706,  4710,  4714,
    4722,  4730,  4734,  4738,  4748,  4756,  4764,  4768,  4772,  4780,
    4784,  4790,  4796,  4800,  4810,  4818,  4822,  4828,  4837,  4846,
    4852,  4858,  4868,  4885,  4892,  4907,  4943,  4947,  4956,  4965,
    4975,  4979,  4988,  4997,  5001,  5012,  5029,  5035,  5041,  5051,
    5055,  5061,  5067,  5071,  5077,  5081,  5087,  5093,  5100,  5110,
    5115,  5123,  5129,  5139,  5161,  5170,  5176,  5189,  5203,  5210,
    5216,  5226,  5231,  5237,  5247,  5260,  5266,  5276,  5286,  5287,
    5306,  5312,  5324,  5328,  5335,  5336,  5337,  5338,  5339,  5340,
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
    5521,  5522,  5523,  5524,  5525,  5526,  5527,  5528,  5529,  5530,
    5531,  5532,  5533,  5534,  5535,  5536,  5547,  5556,  5559,  5566,
    5571,  5579,  5583,  5590,  5594,  5601,  5605,  5612,  5616,  5625,
    5638,  5641,  5649,  5652,  5660,  5668,  5676,  5680,  5688,  5691,
    5699,  5711,  5714,  5722,  5734,  5740,  5750,  5753,  5761,  5765,
    5769,  5777,  5780,  5788,  5791,  5799,  5803,  5807,  5811,  5815,
    5823,  5831,  5843,  5855,  5859,  5863,  5871,  5877,  5887,  5891,
    5895,  5899,  5903,  5907,  5911,  5915,  5923,  5927,  5931,  5935,
    5943,  5949,  5959,  5969,  5973,  5981,  5991,  6002,  6009,  6013,
    6021,  6024,  6031,  6036,  6045,  6055,  6058,  6066,  6069,  6077,
    6086,  6093,  6103,  6107,  6114,  6120,  6130,  6133,  6140,  6145,
    6157,  6165,  6177,  6185,  6189,  6197,  6201,  6205,  6213,  6221,
    6225,  6229,  6233,  6241,  6249,  6261,  6265,  6273
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
       2,     2,     2,    19,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 11485;
  const int xquery_parser::yynnts_ = 293;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 528;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 318;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 571;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1053 of lalr1.cc  */
#line 15335 "/home/colea/work/xquery_temp1/build_fast/src/compiler/parser/xquery_parser.cpp"


/* Line 1055 of lalr1.cc  */
#line 6279 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"


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

