/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010 Free
   Software Foundation, Inc.
   
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
#line 71 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"


#ifdef WIN32
  // Include the NOMINMAX definition before windwows.h is included,
  // so that min and max macros are not defined, and std::max and std::min
  // uses do not generate errors on Windows.
#define NOMINMAX
#endif

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
#line 85 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 865 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 965 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex

/*
 *  Functions to validate lists of properties
 */
// Returns false if validation fails and the parser should call YYERROR, true otherwise
bool validate_collection_properties(
    parsenode* props,
    location& loc,
    parsenode* qname,
    xquery_driver& driver)
{
  XQUERY_ERROR err = CollectionDecl::validatePropertyList(static_cast<DeclPropertyList*>(props));
  if (err != XQ_NO_ERROR)
  {
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc),
                                       err,
                                       static_cast<QName*>(qname)->get_qname(),
                                       true));
    return false;
  }
  return true;
}

// Returns false if validation fails and the parser should call YYERROR, true otherwise
bool validate_index_properties(
    parsenode* props,
    location& loc,
    parsenode* qname,
    xquery_driver& driver)
{
  XQUERY_ERROR err = AST_IndexDecl::validatePropertyList(static_cast<DeclPropertyList*>(props));
  if (err != XQ_NO_ERROR)
  {
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc),
                                       err,
                                       static_cast<QName*>(qname)->get_qname(),
                                       true));
    return false;
  }
  return true;
}



/* Line 317 of lalr1.cc  */
#line 156 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"

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

/* Line 380 of lalr1.cc  */
#line 222 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
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
        case 106: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
#line 863 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 329 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 119: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 862 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 338 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 144: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 347 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 356 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 365 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 374 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 383 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 392 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 401 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 410 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 419 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 428 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 437 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 446 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 455 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 464 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 473 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 482 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 491 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 500 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 509 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 518 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 527 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 536 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 545 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 554 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 563 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 572 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 581 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 590 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 599 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 608 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 617 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 626 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 635 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 644 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "DeclPropertyList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 653 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "DeclProperty" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 662 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 671 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 680 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 689 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 698 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 707 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 716 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 725 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 734 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 743 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 752 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 761 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 770 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 779 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 788 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 824 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 833 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 842 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 851 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 860 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 869 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "FunctionDeclSequential" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 878 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 887 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 896 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 905 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 914 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 941 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 950 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 959 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 968 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 977 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 986 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 995 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1004 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1013 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1022 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1031 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1040 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1049 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1058 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1067 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1076 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1085 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1094 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1103 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1112 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1121 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1130 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1139 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1148 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1157 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1166 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1175 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1184 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1193 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1202 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1211 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1220 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1229 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1238 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1247 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1256 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1265 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1274 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1283 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1292 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1301 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1310 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1319 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1328 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1337 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1346 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1355 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1364 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1373 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1382 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1391 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1400 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1409 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1418 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1427 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1436 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1445 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1454 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1463 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1472 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1481 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1490 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1499 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1508 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1517 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1526 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1535 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1544 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1553 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1562 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1571 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1580 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1589 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1598 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1607 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1616 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1625 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1634 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1643 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1652 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1661 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1670 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1679 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1688 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1697 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1706 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1715 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1724 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1733 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1742 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1751 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1760 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1769 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1778 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1787 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1796 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1805 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1814 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1823 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1832 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1841 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1850 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1859 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1868 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1877 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1886 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1895 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1904 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1913 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1922 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1931 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1940 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1949 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1958 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1967 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1976 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1985 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1994 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2003 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2012 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2021 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2030 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2039 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2048 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2057 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2066 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2075 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2084 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2093 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2102 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2111 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2120 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2129 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2138 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2147 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2156 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2165 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2174 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2183 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2192 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2201 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2210 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2219 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2228 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2237 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2246 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2255 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2264 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2273 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2282 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2291 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2300 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2309 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 886 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2318 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2327 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2336 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2345 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2354 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2363 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2372 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2381 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2390 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2399 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2408 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2417 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2426 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2435 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2444 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2453 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2462 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2471 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2480 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2489 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2498 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2507 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2516 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2525 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2534 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2543 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2552 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2561 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2570 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2579 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2588 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2597 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2606 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2615 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2624 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2633 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2642 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2651 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2660 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2669 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2678 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2687 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
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
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 553 of lalr1.cc  */
#line 131 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename.getStore()->str());
}

/* Line 553 of lalr1.cc  */
#line 2772 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1024 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 1057 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL; YYABORT;
        }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 1066 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1071 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            MainModule *mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
            mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1078 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1083 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            LibraryModule *lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
            lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1094 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            std::string encoding = "utf-8";
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), encoding );
        }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1099 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
        }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1107 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
        }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1112 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
        }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1117 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)), static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
        }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1122 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
        }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1127 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
          (yylocation_stack_[(3) - (1)]).step();
          driver.parserErr("syntax error, missing semicolon \";\" after statement", (yylocation_stack_[(3) - (1)]));
          error((yyloc), ""); // The error message will be taken from the driver
          YYERROR;
        }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1135 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
          (yylocation_stack_[(3) - (1)]).step();
          driver.parserErr("syntax error, missing semicolon \";\" after declaration", (yylocation_stack_[(3) - (1)]));
          error((yyloc), ""); // The error message will be taken from the driver
          YYERROR;
        }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1143 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
          (yylocation_stack_[(5) - (3)]).step();
          driver.parserErr("syntax error, missing semicolon \";\" after declaration", (yylocation_stack_[(5) - (3)]));
          error((yyloc), ""); // The error message will be taken from the driver
          YYERROR;
        }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1151 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
          (yylocation_stack_[(5) - (1)]).step();
          driver.parserErr("syntax error, missing semicolon \";\" after statement", (yylocation_stack_[(5) - (1)]));
          error((yyloc), ""); // The error message will be taken from the driver
          YYERROR;
        }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1163 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
        }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1167 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
        }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1172 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
        }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1177 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)), static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
        }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1186 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
            dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
        }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1195 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
            sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = sdl;
        }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1201 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1207 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            // error
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
            (yylocation_stack_[(3) - (1)]).step();
            driver.parserErr("syntax error, missing semicolon \";\" after declaration", (yylocation_stack_[(3) - (1)]));
            error((yyloc), ""); // The error message will be taken from the driver
            YYERROR;
        }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 1220 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
            vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = vdl;
        }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 1226 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 1232 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
            (yylocation_stack_[(3) - (1)]).step();
            driver.parserErr("syntax error, missing semicolon \";\" after declaration", (yylocation_stack_[(3) - (1)]));
            error((yyloc), ""); // The error message will be taken from the driver
            YYERROR;
        }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1266 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
          delete (yysemantic_stack_[(4) - (4)].vstrpair);
        }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1271 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
          delete (yysemantic_stack_[(4) - (4)].vstrpair);
        }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1280 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.vstrpair) = new vector<string_pair_t>();
          (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
          delete (yysemantic_stack_[(1) - (1)].strpair);
        }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1286 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
          delete (yysemantic_stack_[(2) - (2)].strpair);
          (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
        }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1295 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
            (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval() );
            delete sl;
        }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1303 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1304 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1305 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1306 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1307 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1308 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 1309 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 1310 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1311 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1312 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1338 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
        }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1346 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::preserve_space
            );
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1352 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::strip_space
            );
        }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1362 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_element_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1368 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_function_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1378 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OptionDecl(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval))
            );
        }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1388 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1396 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::ordered
            );
        }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1402 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::unordered
            );
        }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1413 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_greatest);
        }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1418 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_least);
        }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1428 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1434 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1440 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1446 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1463 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
        }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1471 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1479 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
        }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1483 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                NULL
            );
        }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1492 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                NULL,
                SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1501 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1514 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            URILiteralList *ull = new URILiteralList( LOC((yyloc)));
            ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.node) = ull;
        }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1520 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
                ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1531 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1535 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
        }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1543 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1548 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1553 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1560 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1573 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
        }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1580 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
            d->type = (yysemantic_stack_[(3) - (2)].node);
            (yyval.node) = d;
        }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1586 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1593 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
            d->ext = false;
            (yyval.node) = d;
        }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1599 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), NULL );
        }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1603 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1610 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1621 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)), NULL, NULL);
      dynamic_cast<VarNameAndType*>((yyval.varnametype))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1626 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)), NULL);
      dynamic_cast<VarNameAndType*>((yyval.varnametype))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1631 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (5)].expr)), NULL, static_cast<AnnotationList*>((yysemantic_stack_[(5) - (2)].node)));
      dynamic_cast<VarNameAndType*>((yyval.varnametype))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1636 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (5)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)), static_cast<AnnotationList*>((yysemantic_stack_[(6) - (2)].node)));
      dynamic_cast<VarNameAndType*>((yyval.varnametype))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1645 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (1)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(3) - (3)].expr), nt->get_annotations());
      dynamic_cast<VarDecl*>((yyval.node))->setComment(nt->getCommentString());
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1651 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(2) - (1)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL, nt->get_annotations(), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(nt->getCommentString());
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1657 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (1)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(4) - (4)].expr), nt->get_annotations(), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(nt->getCommentString());
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1666 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
            dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = dpl;
        }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1672 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
        dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
        (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1681 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1685 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1691 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1695 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1699 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1703 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1709 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1715 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1721 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_equality
            );
        }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1727 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_range
            );
        }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1733 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1737 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1743 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1749 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1756 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL,
                              NULL);
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1764 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1772 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              NULL,
                              NULL,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1780 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(6) - (6)].node)),
                              static_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)));
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1788 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 132:

/* Line 678 of lalr1.cc  */
#line 1800 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 133:

/* Line 678 of lalr1.cc  */
#line 1814 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 134:

/* Line 678 of lalr1.cc  */
#line 1828 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 135:

/* Line 678 of lalr1.cc  */
#line 1845 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1849 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1858 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1862 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1869 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      if (!validate_index_properties((yysemantic_stack_[(9) - (2)].node), (yyloc), (yysemantic_stack_[(9) - (4)].expr), driver))
      {
        delete (yysemantic_stack_[(9) - (2)].node); delete (yysemantic_stack_[(9) - (4)].expr); delete (yysemantic_stack_[(9) - (7)].expr); delete (yysemantic_stack_[(9) - (9)].node); // these need to be deleted explicitly, as bison does not free them
        YYERROR;
      }

      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                             (yysemantic_stack_[(9) - (7)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                             dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(9) - (2)].node)));
      delete (yysemantic_stack_[(9) - (2)].node);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1895 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1901 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1909 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1914 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1921 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1928 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1939 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1949 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1959 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1970 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 151:

/* Line 678 of lalr1.cc  */
#line 1985 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_preserve
            );
        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1991 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_strip
            );
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 2002 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL );
        }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 2006 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 2010 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)) );
        }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 2014 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 2021 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2028 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 159:

/* Line 678 of lalr1.cc  */
#line 2047 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            std::auto_ptr<VFO_DeclList> vfo2( dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)) );
            if ( !(yysemantic_stack_[(3) - (1)].node) )
                vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back( *vfo2.get() );
            (yyval.node) = vfo;
        }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 2056 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2063 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            vfo->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = vfo;
        }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2069 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back((yysemantic_stack_[(2) - (2)].node));
            (yyval.node) = vfo;
        }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2079 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2085 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)), NULL, NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2091 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2097 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)), (yysemantic_stack_[(5) - (5)].expr), NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2107 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2114 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExitExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2121 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody *>((yysemantic_stack_[(5) - (5)].expr));
            if ( !bb ) {
                bb = new BlockBody( (yysemantic_stack_[(5) - (5)].expr)->get_location() );
                bb->add((yysemantic_stack_[(5) - (5)].expr));
            }
            (yyval.expr) = new WhileExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), bb );
        }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2133 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::BREAK );
        }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2137 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
        }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2145 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnnotationList( LOC((yyloc)), static_cast<Annotation*>((yysemantic_stack_[(1) - (1)].node)));
        }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2149 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            static_cast<AnnotationList*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<Annotation*>((yysemantic_stack_[(2) - (2)].node)));
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 2157 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Annotation( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
        }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 2161 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Annotation( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), static_cast<AnnotationLiteralList*>((yysemantic_stack_[(5) - (4)].node)));
        }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 2168 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnnotationLiteralList( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
        }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2172 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            static_cast<AnnotationLiteralList*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 2180 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2185 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node))->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node))->set_annotations(static_cast<AnnotationList*>((yysemantic_stack_[(3) - (2)].node)));
            (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
        }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2225 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2229 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 2233 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2237 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2245 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->param,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
                            (yysemantic_stack_[(4) - (4)].expr),
                            ParseConstants::fn_read,
                            NULL);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2256 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->param,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
                            NULL,
                            ParseConstants::fn_extern,
                            NULL);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2271 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->param,
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->ret,
                            (yysemantic_stack_[(5) - (5)].expr),
                            ParseConstants::fn_sequential,
                            NULL);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2282 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->param,
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->ret,
                            NULL,
                            ParseConstants::fn_extern_sequential,
                            NULL);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 2297 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                            &* (yysemantic_stack_[(7) - (4)].fnsig)->param,
                            &* (yysemantic_stack_[(7) - (4)].fnsig)->ret,
                            (yysemantic_stack_[(7) - (6)].expr),
                            ParseConstants::fn_update,
                            NULL);
      delete (yysemantic_stack_[(7) - (4)].fnsig);
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 2308 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->param,
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->ret,
                            NULL,
                            ParseConstants::fn_extern_update,
                            NULL);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 2324 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            ParamList *pl = new ParamList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 2330 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
                pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 2342 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 2346 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 2357 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EnclosedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 2364 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 2372 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QueryBody( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 2387 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 2391 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            std::auto_ptr<BlockBody> blk( dynamic_cast<BlockBody*>((yysemantic_stack_[(2) - (2)].expr)) );
            BlockBody *blk2 = new BlockBody( LOC((yyloc)) );
            blk2->add( (yysemantic_stack_[(2) - (1)].expr) );

            for ( int i = 0; i < blk->size(); ++i )
                blk2->add( (*blk)[i] );

            (yyval.expr) = blk2;
        }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 2405 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new BlockBody( LOC((yyloc)) );
        }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 2409 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (1)].expr));
            bb->add( (yysemantic_stack_[(3) - (2)].expr) );
            (yyval.expr) = bb;
        }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2418 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2422 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 221:

/* Line 678 of lalr1.cc  */
#line 2477 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 222:

/* Line 678 of lalr1.cc  */
#line 2492 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2499 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_sliding;
        }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2503 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_tumbling;
        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2510 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_start;
        }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2514 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_end;
        }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2518 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_only_end;
        }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2525 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)),
                dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr),
                (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 2533 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr),
                (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2544 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 231:

/* Line 678 of lalr1.cc  */
#line 2554 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2567 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2589 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2595 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2605 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
        }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2613 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
            vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vdl;
        }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2619 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2631 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2635 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(5) - (5)].expr), true);
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2639 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)), NULL, NULL, (yysemantic_stack_[(4) - (4)].expr), false);
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2643 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)), NULL, NULL, (yysemantic_stack_[(6) - (6)].expr), true);
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2647 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)), NULL, dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)), NULL, (yysemantic_stack_[(4) - (4)].expr), false);
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2651 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)), NULL, dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (4)].node)), NULL, (yysemantic_stack_[(6) - (6)].expr), true);
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2655 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)), NULL, (yysemantic_stack_[(5) - (5)].expr), false);
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2660 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(7) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(7) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(7) - (5)].node)), NULL, (yysemantic_stack_[(7) - (7)].expr), true);
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2666 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2675 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 256:

/* Line 678 of lalr1.cc  */
#line 2685 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 257:

/* Line 678 of lalr1.cc  */
#line 2695 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 258:

/* Line 678 of lalr1.cc  */
#line 2711 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2720 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2730 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2738 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2744 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2753 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2759 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2771 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2779 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2789 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                           (yysemantic_stack_[(4) - (4)].expr));
     }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2797 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                           (yysemantic_stack_[(5) - (5)].expr));
     }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2809 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2815 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2828 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2832 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2840 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2844 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2853 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2857 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2869 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)),
                           NULL, NULL,
                           new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))),
                           VarGetsDecl::eval_var);
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2883 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2898 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2904 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2915 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2919 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2928 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2936 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2942 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2952 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2958 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2968 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 2972 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 2982 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 2988 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 2994 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3000 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3009 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3018 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3027 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3040 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3044 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3052 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3058 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3068 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3076 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3085 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3098 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3105 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3117 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3121 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3133 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3140 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3146 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3155 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3162 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3168 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3180 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3187 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3200 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3206 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3218 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3224 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3236 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3245 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3249 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3258 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3262 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3270 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3274 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 331:

/* Line 678 of lalr1.cc  */
#line 3284 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3291 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3300 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3309 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3314 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3323 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3332 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3341 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3354 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3358 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3370 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3374 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3381 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3385 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3394 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3398 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3402 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3411 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3415 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3421 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3427 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3433 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3444 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3448 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3452 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3460 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3464 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3470 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3480 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3484 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3494 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3498 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3508 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3512 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3522 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3526 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3536 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3540 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3548 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3552 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3556 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3560 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3570 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3574 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3578 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3586 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3590 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3594 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3598 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3602 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3606 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3614 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3618 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3622 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3630 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3634 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3638 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3642 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3653 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3659 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3669 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3675 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3685 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3689 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3727 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3731 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3737 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3743 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = !rpe ?
                (yysemantic_stack_[(1) - (1)].expr) : new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3754 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NULL;
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3762 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 401:

/* Line 678 of lalr1.cc  */
#line 3773 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3779 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3789 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3793 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3801 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3807 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3815 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3821 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3833 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3839 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3849 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3853 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3857 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3865 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3871 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3900 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3904 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3912 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3916 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3927 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3931 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3935 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3941 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3945 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3959 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3963 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 3971 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 3975 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 3985 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 3989 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 3993 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4002 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4006 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FilterExpr(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4012 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4016 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4024 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4030 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4040 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4048 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4052 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4056 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4060 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4064 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4068 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4072 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4076 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4080 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4088 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4092 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4100 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4107 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4114 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4125 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4133 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4137 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4145 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4153 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4161 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4215 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4219 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4232 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4238 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4248 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4252 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4260 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4264 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4268 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4276 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 471:

/* Line 678 of lalr1.cc  */
#line 4286 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 472:

/* Line 678 of lalr1.cc  */
#line 4296 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 473:

/* Line 678 of lalr1.cc  */
#line 4306 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 474:

/* Line 678 of lalr1.cc  */
#line 4316 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 475:

/* Line 678 of lalr1.cc  */
#line 4326 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 476:

/* Line 678 of lalr1.cc  */
#line 4341 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4347 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4358 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4364 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4375 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4392 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4397 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4406 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4410 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4417 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back(
                new QuoteAttrValueContent( LOC((yyloc)),std::string("\"") )
            );
            (yyval.node) = qacl;
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4425 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4431 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 490:

/* Line 678 of lalr1.cc  */
#line 4441 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4453 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4457 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4464 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4470 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4476 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4483 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4494 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4498 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4508 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4512 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4522 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4526 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4530 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4535 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4544 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4550 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4556 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4562 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4572 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4576 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4588 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4592 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4604 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4616 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4620 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4624 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4628 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4632 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4636 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4644 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4652 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval))), NULL);
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4656 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4660 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4664 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4681 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval))), NULL );
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4685 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4689 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4693 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4701 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4709 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4717 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval)), NULL );
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4721 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4725 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4729 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4737 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4743 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4753 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4761 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4765 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4769 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4804 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4810 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4816 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4826 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4830 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4834 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4838 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4842 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4849 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4855 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4865 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4881 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4889 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4893 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4897 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4901 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4905 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4913 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 4921 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 4925 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 4929 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 4939 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 4947 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 4955 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 4959 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 4963 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 4971 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 4975 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 4981 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 4987 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 4991 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5001 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5009 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5013 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5019 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5028 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5037 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5043 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5049 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5059 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5076 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5083 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5098 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5134 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5138 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5147 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5156 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new InlineFunction(LOC ((yyloc)), &*(yysemantic_stack_[(3) - (2)].fnsig)->param, &*(yysemantic_stack_[(3) - (2)].fnsig)->ret, dynamic_cast<EnclosedExpr *>((yysemantic_stack_[(3) - (3)].expr)));
          delete (yysemantic_stack_[(3) - (2)].fnsig);
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5166 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5170 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5179 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
        }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5188 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5192 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5203 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5220 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5226 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5232 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5242 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5246 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5252 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5258 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5262 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5268 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5272 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5278 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5284 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5291 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5301 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5306 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5314 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5320 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5330 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5352 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5361 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5367 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5380 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5394 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5401 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5407 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5417 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5422 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5427 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 625:

/* Line 678 of lalr1.cc  */
#line 5437 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 626:

/* Line 678 of lalr1.cc  */
#line 5450 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5456 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5473 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new EvalExpr(LOC((yyloc)), dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)), (yysemantic_stack_[(7) - (6)].expr));
        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5477 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new EvalExpr( LOC((yyloc)), new VarGetsDeclList( LOC((yyloc)) ), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5492 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5500 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5504 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5511 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5516 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5524 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5528 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5535 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5539 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5546 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5550 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5557 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5561 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5570 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5582 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5586 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5593 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5597 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5605 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5613 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5621 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5625 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5632 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5636 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5644 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5655 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5659 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5667 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5679 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5685 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5694 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5698 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5706 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5710 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5714 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5721 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5725 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5732 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5736 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5744 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5748 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5752 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5756 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5760 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5768 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5776 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5788 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5800 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5804 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5808 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5816 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5822 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5832 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5836 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5840 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5844 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5848 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5852 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5856 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5860 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5868 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5872 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5904 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5914 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5918 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5926 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 700:

/* Line 678 of lalr1.cc  */
#line 5936 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 701:

/* Line 678 of lalr1.cc  */
#line 5947 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5954 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5958 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5965 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5969 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(1) - (1)].thesaurus_id_list);
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5976 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5981 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5990 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5999 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 6003 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 6010 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 6014 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 6022 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 6031 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 6038 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 6048 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6052 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6059 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6065 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 6074 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6078 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6085 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 6090 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 6102 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 6110 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 6122 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 6130 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 6134 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 6142 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6146 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6150 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 6158 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 6166 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 6170 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6174 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6178 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6186 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 6194 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 6206 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6210 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 6218 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6236 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 746:

/* Line 678 of lalr1.cc  */
#line 6249 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6250 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6251 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 6252 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6253 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6254 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6255 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6256 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6257 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6258 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6259 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6260 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6261 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6262 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6263 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 6267 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6268 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6269 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6270 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 6271 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6272 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 6273 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 6274 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6275 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 6276 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 6277 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6278 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6279 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 6280 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 6281 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6282 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 6283 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 6284 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 6285 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 6286 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 6287 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6288 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 6289 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 6290 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6291 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 6292 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 6293 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 6294 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6295 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6296 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 6297 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6298 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6299 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6300 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 6301 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6302 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6303 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6304 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6305 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6306 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6307 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6308 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6309 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6310 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6311 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6312 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6313 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6314 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6315 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6316 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6317 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6318 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6319 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6320 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6321 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6322 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6323 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6324 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6325 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6326 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6327 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6328 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6329 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6330 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6331 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6332 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6333 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6334 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6335 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6336 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6337 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6338 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6339 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6340 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6341 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6342 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6343 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6344 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6345 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6346 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6347 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6348 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6349 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6350 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6351 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6352 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6353 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6354 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6355 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6356 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6357 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6358 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6359 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6360 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6361 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6362 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6363 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6364 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6365 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6366 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6367 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6368 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6369 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6370 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6371 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6372 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6373 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6374 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6375 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6376 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6377 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6378 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6379 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6380 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6381 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6382 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6383 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6384 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6385 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6386 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6387 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6388 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6389 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6390 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6391 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6392 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6393 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6394 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6395 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6396 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6397 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6398 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6399 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6400 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6401 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6402 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6403 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6404 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6405 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6406 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6407 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6408 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("deterministic"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6409 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nondeterministic"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6410 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6411 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6412 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6413 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("block"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6414 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6415 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6416 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6417 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6418 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6419 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6420 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eval"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6421 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6422 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6423 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6424 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6425 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6426 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6427 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6428 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6429 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6430 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6431 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6432 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6433 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6434 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6435 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6436 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6437 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6438 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6439 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6440 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6441 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6442 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6443 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6444 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6445 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6446 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6447 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6448 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6449 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6450 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6451 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6452 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6453 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 948:

/* Line 678 of lalr1.cc  */
#line 6454 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 949:

/* Line 678 of lalr1.cc  */
#line 6455 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 950:

/* Line 678 of lalr1.cc  */
#line 6456 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 951:

/* Line 678 of lalr1.cc  */
#line 6457 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 952:

/* Line 678 of lalr1.cc  */
#line 6458 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 953:

/* Line 678 of lalr1.cc  */
#line 6459 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 954:

/* Line 678 of lalr1.cc  */
#line 6460 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 955:

/* Line 678 of lalr1.cc  */
#line 6461 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 956:

/* Line 678 of lalr1.cc  */
#line 6462 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 957:

/* Line 678 of lalr1.cc  */
#line 6463 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 958:

/* Line 678 of lalr1.cc  */
#line 6464 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 959:

/* Line 678 of lalr1.cc  */
#line 6465 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 960:

/* Line 678 of lalr1.cc  */
#line 6466 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;



/* Line 678 of lalr1.cc  */
#line 11529 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
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

    yyerror_range[1] = yylloc;
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

    yyerror_range[1] = yylocation_stack_[yylen - 1];
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

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
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
  const short int xquery_parser::yypact_ninf_ = -1368;
  const short int
  xquery_parser::yypact_[] =
  {
      1943, -1368, -1368,  2238,  2532,  2826, -1368, -1368,  1350,    -8,
   -1368, -1368, -1368,   525, -1368, -1368, -1368, -1368,   191,   270,
     531,   354,   371,   428,   457,   327, -1368,    47, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368,   543, -1368,   478,   502, -1368,
     458, -1368, -1368,   490, -1368,   545, -1368,   506,   529, -1368,
     312, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368,   578,   584, -1368, -1368, -1368, -1368,
     383,  8118, -1368, -1368, -1368,   586, -1368, -1368, -1368, -1368,
   -1368,   588,   594, -1368, -1368, 11261, -1368, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368,   601, -1368, -1368,   605,   620, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368,  3120, 11261, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368,   591, -1368, -1368,   624,  8992,
   -1368,  9280,   629,   632, -1368, -1368, -1368,   636, -1368,  7824,
   -1368, -1368, -1368, -1368, -1368, -1368,   607, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368,    70,   547, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368,   329,   613,   468, -1368,   548,
     381, -1368, -1368, -1368, -1368, -1368, -1368,   642, -1368,   617,
     530,   534,   532, -1368, -1368,   622,   623, -1368,   660, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,  5178,
     775, -1368,  5472, -1368, -1368,   336,    45,    68, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368,   517, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,
       1, -1368, -1368, -1368, -1368,   358, -1368, -1368, -1368, -1368,
   -1368, -1368,   614,   688, -1368,   885,   535,   -20,   427,   -38,
      25, -1368,   731,   589,   683,   684,  5766, -1368, -1368, -1368,
     165, -1368, -1368,  7824, -1368,   162, -1368,   638,  8118, -1368,
     638,  8118, -1368, -1368, -1368,   296, -1368, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,   645,
     637, -1368, -1368, -1368, -1368, -1368,   610, -1368,   611, -1368,
     612,   768,   380,   454,   442, 11544, 11261,   -25,   750,   751,
     753, 11261,   651,   685,   302,  8992, -1368, 11261, -1368,   469,
     411,   559, 11261, -1368, -1368, -1368, -1368, -1368,   516, 11261,
     512,   513,   421,   508,   719, -1368,   491, -1368, -1368, -1368,
   -1368, -1368,  8992,  6060,   630,  6060,   112,  6060,  9846,  6060,
     549,   550, 11261,   697,    32,   666,  6060,    55,    60, 11261,
    6060,  8702, 11261, 11261, 11261, 11261,  6060,   644,  6060,  6060,
   11261,  6060,   679,   686, -1368, -1368, -1368,  6060, 10129,   681,
   -1368,   682, -1368, -1368, -1368, -1368, -1368,   687, -1368, -1368,
     689, -1368, -1368, -1368, -1368, -1368,   690, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368, -1368, 11261, -1368, -1368,
   -1368,   654,   807,  6060, -1368, -1368,   111, -1368, -1368,   823,
   -1368, -1368, -1368, -1368,  6060,   635, -1368,   821,  6060,  6060,
     664,  6060,  6060,  6060,  6060,   625, 11261, -1368, -1368, -1368,
   -1368,  6060,  6060,  6060, 11261, -1368, -1368, -1368, -1368,  1350,
     327,    69,    73,   844,  6354,  6354,  6648,  6648,   711,  6060,
    6060, -1368,  6060,   737,   371,    47,   691,   692,   699,  6060,
    6060, -1368, -1368, -1368, -1368, -1368, -1368, -1368,  6942,  6942,
    6942, -1368,  6942,  6942, -1368,  6942, -1368,  6942, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368,  6942,  6942,   784,  6942,  6942,
    6942,  6942,  6942,  6942,  6942,  6942,  6942,  6942,  6942,   628,
     764,   765,   771, -1368, -1368, -1368,  3414, -1368, -1368,  7824,
    7824,  6060,   638, -1368, -1368,   638, -1368,  3708,   638,   721,
    4002, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,
     763,   766,   428,   843, -1368, -1368, 11544, -1368, 11544,   739,
     410, 11261,   713,   715,   739,   768,   756,   746,   729, -1368,
   -1368, -1368, -1368, -1368,    14,   640,   -11, -1368,   592, -1368,
   -1368, -1368, -1368, 11261, 11261, 11261, -1368,   773, -1368, -1368,
     755,   709, -1368,   710,   682,   502, -1368,   708,   712,   716,
   -1368,     8,    21,   718, -1368, -1368,   788, -1368,    -1, 11261,
     -12, 11261,   801,    22, -1368,  6060, -1368,   717,  8992,   808,
     859,  8992,   768,   813,   804, -1368,    12,   730,   728, -1368,
     732,   734,   735,   774,     4, -1368,    36,   740, -1368,   736,
     741,   776, -1368,   742,  6060,  6060,   743, -1368,    23,    31,
      17, -1368, 11261,   807, -1368,   -10,   747, -1368, -1368, -1368,
     748, -1368,   233, -1368, -1368, -1368,    85,   128,   834,   698,
     714,   -17, -1368,   791,  7236, -1368,   749,   757,   310, -1368,
   -1368,   336,   420,   904,   904, -1368,    84, -1368, -1368,    86,
   -1368, -1368,   876, -1368, -1368, -1368, -1368,  6060, -1368, -1368,
       9, 11261,   769,  6060,   824, -1368, -1368,   688, -1368, -1368,
   -1368, -1368, -1368,  6942, -1368, -1368, -1368,    16,   427,   427,
     440,   -38,   -38,   -38,   -38,    25,    25, -1368, -1368, 10695,
   10695, 11261, 11261, -1368,   761, -1368, -1368,   767, -1368, -1368,
   -1368,    49, -1368, -1368,   202,   293,   402,   474, -1368,   428,
     428, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,
   -1368,   739, -1368,   814, 10978,   809,  6060, -1368, -1368, -1368,
     860,   768,   768,   739, -1368,   585,   768,   385,   388, 11261,
     209,   253,   926, -1368, -1368,   672,   272, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,    14,    37,
     432, -1368,   733,   271,    -2,   661, 11261,   768, -1368, -1368,
   -1368, -1368,   810, 11261, -1368, 11261, -1368, -1368,   842,   835,
   10695,   845,  6060,   846,   -40,   819,     0,    53,   720, -1368,
   -1368,   542,   -12,   860, 10695,   848,   874,   789,   779,   840,
     768,   817,   847,   882,   768,   862,  6060,   841,   -46,   829,
   -1368, -1368, -1368, -1368,  6060,   865,  6060,  6060,   838, -1368,
     886,   890,  6060, -1368,   802,   811,   839, 11261, -1368, 11261,
   -1368,  6060,   958, -1368,    30, -1368,   173, -1368, -1368,   965,
   -1368,   413,  6060,  6060,  6060,   472,  6060,  6060,  6060,  6060,
    6060,  6060,   877,  6060,  6060,   878,    13,   815,   617,   759,
     849,   881,    97,   267,   876,  6648,  6648,  6648,   924, -1368,
   -1368, -1368,  6060,   505,   903, -1368, 11261,   910, -1368, -1368,
    6060,    16,   286,   221, -1368,   738,    -5,   762,   770, -1368,
   -1368,   559, -1368,   752,   301,   866,   871, 10978,   873, -1368,
      -9, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,
     887, -1368, -1368, -1368,  6060, -1368, -1368, -1368, -1368, -1368,
   -1368, -1368,  6060, -1368,   477,   486, -1368,  1003,   538, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368, -1368,   208, -1368, -1368,
     758, -1368, -1368,  1004, -1368, -1368, -1368, -1368, -1368,   335,
    1005, -1368,   533, -1368, -1368, -1368,   681,   270,   687,   478,
     689,   690,   613,   799,    -9,   812,   820,  7530,   754,   760,
      37, -1368,   822,   860,   853,  4296,   850,   852,   908,   867,
     869, 11261,    35, -1368, 11261, -1368, 11261,  6060,   906,  6060,
     930,  6060,   -24,   912,  6060,   914, -1368,   943,   944,  6060,
   11261,   608,   986, -1368, -1368, -1368, -1368, -1368, -1368, 10695,
   -1368,  6060,   768,   959, -1368, -1368, -1368,   768,   959, 11261,
   -1368,  6060,  6060,   927,  4590, -1368, 11261, -1368, -1368,  6060,
    6060,   536, -1368,    10, 10412,   537, -1368,   884, -1368, -1368,
    4884,   883,   888, -1368, -1368,   940, -1368,   389, -1368, -1368,
    1061, -1368, -1368, 11261, -1368, -1368,   503, -1368, -1368, -1368,
     889,   854,   863, -1368, -1368, -1368,   864,   870, -1368, -1368,
   -1368, -1368, -1368,   858, 11261,   892, -1368, 11261, -1368,   878,
   -1368, -1368, -1368,  8412,   759, -1368,  6060, 11261,   904,   375,
   -1368, -1368, -1368,   903, -1368,   768, -1368,   597, -1368,    52,
     969, -1368,  6060,   973,   824,   897,   898, -1368,    16,   851,
   -1368, -1368,   200, -1368,   306,    44,   856,    16,   306,  6942,
   -1368,   -41, -1368, -1368, -1368, -1368, -1368, -1368,    16,   937,
     816,   640,    44, -1368, -1368,   818,  1017, -1368, -1368, -1368,
    9563,   916,   920,   922, -1368, -1368, -1368, -1368, -1368, -1368,
     915, -1368, -1368, -1368,  6060, -1368, -1368,   385, -1368, -1368,
   -1368,  1081,   196,  1082,   196,   855,  1014, -1368, -1368, -1368,
   -1368,   945, 11261,   857,   799,  7530, -1368, -1368, -1368,   929,
   -1368, -1368, -1368, -1368, -1368, -1368,  6060,   970, -1368, -1368,
   -1368,  6060, -1368,   252, -1368,  6060,   971,  6060, -1368,  6060,
   11261, 11261, -1368,    82, -1368,  6060, -1368,   990,  1021,   768,
     959, -1368, -1368, -1368,  6060, -1368,   936, -1368, -1368, -1368,
     935, -1368,  6060,  6060, 11261,   939,     3, -1368, -1368, -1368,
     938, -1368, -1368,   958, 11261,   579, -1368,   958, 11261, -1368,
   -1368,  6060,  6060,  6060,  6060,  6060, -1368,  6060,    74, -1368,
   -1368,   238, -1368,   946, -1368, -1368, -1368, -1368,   969, -1368,
   -1368, -1368,   768, -1368, -1368, -1368, -1368, -1368,   947,  6942,
   -1368, -1368, -1368, -1368, -1368,    72,  6942,  6942,   255, -1368,
     762, -1368,   136, -1368,   770,    16,   975, -1368, -1368,   872,
   -1368, -1368, -1368, -1368,  1027,   942, -1368,   214, -1368, -1368,
   -1368, -1368,     6, -1368, -1368,   261,   261, -1368,   196, -1368,
   -1368,   215, -1368,  1103,    44,   949,  1025, -1368,  7530,   -51,
     875, -1368,   964, -1368, -1368,  6060, -1368,  6060,   991, -1368,
    6060, -1368, -1368, -1368,  1084, -1368, -1368,  6060,   768, -1368,
   -1368, -1368,  6060, -1368, -1368,  1044,  6060, 11261,  6060, -1368,
      11,   958, 11261,   948,   958, -1368, -1368, -1368, -1368, -1368,
   -1368,  6060,  1000,  1024,  8412, -1368, -1368, -1368, -1368, -1368,
     -38,  6942,  6942,   440,   -13, -1368, -1368, -1368, -1368, -1368,
   -1368,  6060, -1368, 10695, -1368, 10695,  1049, -1368, -1368, -1368,
   -1368,  1117, -1368, -1368, -1368,   891, -1368,  1014,  1039, -1368,
     546, 11261,  1030,   951, 11261,  7530, -1368, -1368,  6060, -1368,
    1031, -1368,   959, -1368, 10695, -1368,   967, -1368,   188,   321,
   -1368,   963,   958, -1368,   972, -1368,  6060, 11261, -1368,   440,
     440,  6942,   992, -1368, -1368, 10695, -1368, -1368, -1368,  7530,
   -1368,   969,   879, 11261,  1035,   956,  1039, -1368, 11261,   995,
    6060, -1368, -1368,  1087,   405, -1368, -1368, -1368, -1368,  1002,
     453, -1368, -1368, -1368,   993, -1368, -1368,   220,   440, -1368,
   -1368, -1368, -1368,  6060,   893, 11261,  1067, -1368,  6060, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368, -1368,  1068,  1037, -1368,
     895,   894, 11261, -1368, 11261, -1368,   896,  6060,   899,   226,
    7530, -1368,  7530,  1072,  1037, -1368,   994, 11261, -1368,   907,
    1008, 11261,  1037,   977, -1368,  1077, 11261,   900,  7530, -1368
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   432,   433,     0,     0,     0,   761,   586,   852,   861,
     802,   766,   764,   747,   853,   856,   809,   902,   770,   748,
     749,   914,   801,   862,   751,   859,   831,   811,   786,   806,
     903,   807,   857,   854,   805,   753,   860,   754,   755,   900,
     916,   899,   803,   822,   816,   756,   804,   758,   757,   901,
     840,   808,   783,   926,   927,   928,   929,   930,   931,   932,
     933,   934,   935,   936,   950,   957,   830,   826,   817,   797,
     746,     0,   825,   833,   841,   951,   821,   452,   798,   799,
     855,   952,   958,   818,   835,     0,   458,   421,   454,   828,
     763,   819,   820,   848,   823,   839,   847,   956,   959,   769,
     810,   850,   453,   838,   843,   750,     0,     0,   370,   836,
     846,   851,   849,   829,   815,   904,   813,   814,   953,     0,
     369,     0,   954,   960,   844,   800,   824,   955,   399,     0,
     431,   845,   827,   834,   842,   837,   905,   791,   796,   795,
     794,   793,   792,   759,   812,     0,   762,   858,   784,   891,
     890,   892,   768,   767,   787,   897,   752,   889,   894,   895,
     886,   790,   832,   888,   898,   896,   887,   788,   893,   907,
     910,   911,   908,   909,   906,   760,   912,   913,   915,   878,
     877,   864,   782,   775,   871,   867,   785,   781,   880,   881,
     771,   772,   765,   774,   876,   875,   872,   868,   885,   879,
     874,   870,   863,   773,   884,   883,   777,   779,   778,   869,
     873,   865,   780,   866,   776,   882,   937,   938,   939,   940,
     941,   942,   918,   919,   917,   923,   924,   925,   920,   921,
     922,   789,   943,   944,   945,   946,   947,   948,   949,     0,
       0,     2,     0,     5,     7,    19,     0,     0,    24,    27,
      37,    30,    31,    32,    58,    33,    42,    38,    62,    63,
      64,    59,    60,    66,    67,    36,     0,    34,    35,    40,
      41,    61,   220,   219,   216,   217,   218,    39,    14,   196,
     197,   201,   203,   235,   241,     0,   233,   234,   204,   205,
     206,   207,   208,   325,   327,   329,   339,   343,   345,   348,
     353,   356,   359,   361,   363,   365,     0,   367,   373,   375,
       0,   391,   374,   395,   398,   400,   403,   405,     0,   410,
     407,     0,   418,   428,   430,   404,   434,   441,   450,   442,
     443,   444,   447,   448,   445,   446,   465,   467,   468,   469,
     466,   514,   515,   516,   517,   518,   519,   427,   560,   552,
     559,   558,   557,   554,   556,   553,   555,   451,   449,   587,
     588,    65,   209,   210,   212,   211,   213,   214,   215,   429,
     745,   852,   861,   859,   521,   762,     0,   525,     0,   531,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   117,     0,   118,     0,
       0,     0,     0,   113,   114,   115,   116,   123,     0,     0,
       0,     0,     0,     0,     0,   111,     0,   172,   178,   180,
     183,   182,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   423,   426,   413,     0,     0,   747,
     770,   749,   914,   801,   862,   751,   811,   753,   916,   822,
     756,   758,   757,   840,   950,   957,   746,   951,   952,   958,
     823,   956,   959,   904,   953,   954,   960,   955,   905,   897,
     889,   895,   886,   788,   907,   910,   911,   908,   760,   912,
     915,   419,   429,   745,   411,   412,   415,   747,   748,   749,
     753,   754,   755,   756,   746,   752,   455,     0,   417,   416,
     456,     0,   481,     0,   422,   743,     0,   744,   394,     0,
     425,   424,   414,   397,     0,     0,   510,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   160,   157,   170,
     171,     0,     0,     0,     0,     3,     1,     6,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,     0,
       0,   199,   198,     0,     0,     0,     0,     0,     0,     0,
       0,   221,   240,   236,   242,   237,   239,   238,     0,     0,
       0,   384,     0,     0,   382,     0,   334,     0,   383,   376,
     381,   380,   379,   378,   377,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   372,   371,   368,     0,   392,   396,     0,
       0,     0,   406,   438,   409,   408,   420,     0,   435,     0,
       0,   522,   526,   532,   742,    84,    69,    70,   151,   152,
       0,     0,     0,     0,    75,    76,     0,   181,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   174,   597,
     598,   599,   120,   119,     0,    74,   127,   124,     0,   126,
     125,   122,   121,     0,     0,     0,   112,     0,   173,   179,
       0,     0,   566,     0,     0,     0,   562,     0,     0,     0,
     576,     0,     0,     0,   223,   224,   243,   244,     0,     0,
       0,     0,   153,     0,   190,     0,   590,     0,     0,    93,
       0,     0,     0,    85,   260,   261,     0,     0,     0,   567,
       0,     0,     0,     0,     0,   308,     0,     0,   565,     0,
       0,     0,   584,     0,     0,     0,     0,   570,     0,     0,
       0,   457,   482,   481,   478,     0,     0,   512,   511,   393,
       0,   509,     0,   610,   611,   561,     0,     0,     0,     0,
       0,     0,   616,     0,     0,   168,     0,     0,     0,   263,
     280,    20,     0,    21,     0,     4,     0,    25,    11,     0,
      26,    15,   852,    28,    12,    29,    16,     0,   108,   202,
       0,     0,     0,     0,     0,   222,   281,   326,   328,   332,
     338,   337,   336,     0,   333,   330,   331,     0,   347,   346,
     344,   350,   351,   352,   349,   354,   355,   358,   357,     0,
       0,     0,     0,   389,     0,   401,   402,     0,   439,   436,
     463,     0,   589,   461,     0,     0,     0,     0,    73,     0,
       0,    48,    50,    51,    52,    53,    55,    56,    57,    49,
      54,    44,    45,     0,     0,   101,     0,    97,    99,   100,
     104,     0,     0,    43,    83,     0,     0,     0,     0,     0,
       0,     0,     0,   692,   697,     0,     0,   693,   727,   680,
     682,   683,   684,   686,   688,   687,   685,   689,     0,     0,
       0,   128,     0,     0,   131,     0,     0,     0,   530,   520,
     563,   564,     0,     0,   580,     0,   577,   629,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   225,
     226,     0,   231,   192,     0,     0,   154,     0,     0,     0,
       0,     0,     0,    86,     0,     0,     0,     0,     0,     0,
     569,   568,   575,   583,     0,     0,     0,     0,     0,   529,
       0,     0,     0,   385,     0,     0,     0,     0,   573,     0,
     571,     0,   481,   479,     0,   470,     0,   459,   460,     0,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   852,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
     200,   232,     0,   292,   288,   290,     0,   282,   283,   335,
       0,     0,     0,     0,   658,   341,   631,   635,   637,   639,
     641,   644,   651,   652,   660,   862,   750,     0,   759,   360,
     538,   544,   545,   547,   591,   592,   548,   551,   362,   364,
     535,   366,   390,   440,     0,   437,   462,    81,    82,    79,
      80,   185,     0,   184,     0,     0,    46,     0,     0,   102,
     103,   105,    71,    72,    77,    78,    68,     0,   176,   698,
       0,   701,   728,     0,   691,   690,   695,   694,   726,     0,
       0,   703,     0,   699,   702,   681,     0,     0,     0,     0,
       0,     0,     0,   129,   135,     0,     0,     0,     0,     0,
       0,   132,     0,   106,     0,     0,     0,     0,   584,     0,
       0,     0,     0,   537,     0,   246,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   227,     0,     0,     0,
       0,   274,     0,   271,   276,   230,   193,   155,   191,     0,
     194,     0,     0,    95,    89,    92,    91,     0,    87,     0,
     265,     0,     0,     0,     0,   167,     0,   306,   310,     0,
       0,     0,   313,     0,     0,     0,   320,     0,   387,   386,
       0,     0,     0,   307,   482,     0,   471,     0,   505,   502,
       0,   506,   507,     0,   508,   501,     0,   476,   504,   503,
       0,     0,     0,   603,   604,   600,     0,     0,   608,   609,
     605,   614,   612,     0,     0,     0,   618,     0,   162,     0,
     159,   158,   169,     0,   619,   620,     0,     0,    22,     0,
      13,    17,    18,   289,   301,     0,   302,     0,   293,   294,
     295,   296,     0,   285,     0,     0,     0,   642,   655,     0,
     340,   342,     0,   674,     0,     0,     0,     0,     0,     0,
     630,   632,   633,   669,   670,   671,   673,   672,     0,     0,
     646,   645,     0,   649,   653,   667,   665,   664,   657,   661,
       0,     0,     0,     0,   541,   543,   542,   539,   536,   464,
       0,   187,   186,   189,     0,    47,    98,     0,   175,   715,
     696,     0,   720,     0,   720,   709,   704,   130,   136,   138,
     137,     0,     0,     0,   133,     0,   107,    23,   523,     0,
     581,   582,   585,   578,   579,   245,     0,     0,   258,   259,
     250,     0,   254,     0,   248,     0,     0,     0,   269,     0,
       0,     0,   229,   272,   275,     0,   156,     0,    94,     0,
      88,   262,   267,   266,     0,   533,     0,   309,   311,   316,
       0,   314,     0,     0,     0,     0,     0,   321,   388,   527,
       0,   574,   572,   481,     0,     0,   513,   481,     0,   477,
      10,     0,     0,     0,     0,     0,   617,     0,   163,   161,
     626,     0,   621,     0,   264,   305,   303,   304,   297,   298,
     299,   291,     0,   286,   284,   659,   650,   656,     0,     0,
     729,   730,   740,   739,   738,     0,     0,     0,     0,   731,
     636,   737,     0,   634,   638,     0,     0,   643,   647,     0,
     668,   663,   666,   662,     0,     0,   549,     0,   546,   596,
     540,   195,     0,   177,   716,     0,     0,   714,   721,   722,
     718,     0,   713,     0,   711,     0,   705,   706,     0,     0,
       0,   134,     0,   524,   247,     0,   256,     0,     0,   252,
       0,   255,   270,   278,   279,   273,   228,     0,     0,    90,
     268,   534,     0,   317,   315,     0,     0,     0,     0,   528,
       0,   481,     0,     0,   481,   601,   602,   606,   607,   613,
     615,     0,   164,     0,     0,   622,   628,   300,   287,   654,
     741,     0,     0,   733,     0,   679,   678,   677,   676,   675,
     640,     0,   732,     0,   593,     0,     0,   188,   725,   724,
     723,     0,   717,   710,   708,     0,   700,     0,   139,   141,
     143,     0,     0,     0,     0,     0,   251,   249,     0,   257,
       0,   324,    96,   312,     0,   322,     0,   318,   491,   485,
     480,     0,   481,   472,     0,   165,     0,     0,   627,   735,
     734,     0,     0,   594,   550,     0,   719,   712,   707,     0,
     145,   144,     0,     0,     0,     0,   140,   253,     0,     0,
       0,   499,   493,     0,   492,   494,   500,   497,   487,     0,
     486,   488,   498,   474,     0,   473,   166,     0,   736,   648,
     595,   142,   146,     0,     0,     0,     0,   277,     0,   319,
     484,   495,   496,   483,   489,   490,   475,     0,     0,   147,
       0,     0,     0,   323,     0,   623,     0,     0,     0,     0,
       0,   149,     0,     0,     0,   148,     0,     0,   624,     0,
       0,     0,     0,     0,   625,     0,     0,     0,     0,   150
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1368, -1368,  -226,   953, -1368,   960,   962, -1368,   961,  -232,
    -498,  -551, -1368,   541,  -306, -1368, -1368, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,  -922,
   -1368, -1368, -1368, -1368,   130,   342, -1368, -1368, -1368,   794,
   -1368,   100,  -885, -1368,  -334,  -367, -1368, -1368,  -609, -1368,
    -697, -1368, -1368,    -6, -1368, -1368, -1368, -1368, -1368,   798,
   -1368, -1368,   800,   826, -1368, -1368, -1368,   282,   783, -1367,
    -511,    57, -1368,  -570,   333, -1368, -1368, -1368, -1368,   287,
   -1368, -1368,   941, -1368, -1368, -1368, -1368,    99,  -690,  -699,
   -1368, -1368, -1368,    64, -1368, -1368,  -119,    87,     2, -1368,
   -1368, -1368,   -19, -1368, -1368,   218,   -15, -1368, -1368,    -7,
   -1206, -1368,   722,    65, -1368, -1368,    62, -1368, -1368, -1368,
      59, -1368, -1368,   647,   649, -1368,  -548, -1368, -1368,  -607,
     117,  -606,   113,   118, -1368, -1368, -1368, -1368, -1368,   934,
   -1368, -1368, -1368, -1368,  -758,  -300, -1081, -1368,  -112, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368,   -42, -1200, -1368, -1368,
     349,    33, -1368,  -805, -1368, -1368, -1368, -1368, -1368, -1368,
   -1368,   596, -1368,  -948, -1368,    58, -1368,   489,  -749, -1368,
   -1368, -1368, -1368, -1368,  -353,  -350, -1120,  -964, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,   416,  -725,
    -821,   145,  -813, -1368,   -88,  -791, -1368, -1368, -1368, -1368,
   -1368, -1368, -1368,   825,   827,  -383,   339,   183, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,
   -1368, -1368,    43, -1368, -1368,    34, -1368, -1368,  -989, -1368,
   -1368, -1368,     5,    -4,  -166,   239, -1368, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,     7,
   -1368, -1368, -1368,  -162,   232,   367, -1368, -1368, -1368, -1368,
   -1368,   174, -1368, -1368, -1271, -1368, -1368, -1368,  -694, -1368,
     -37, -1368,  -177, -1368, -1368, -1368, -1368, -1197, -1368,    15,
   -1368,  -356,  -358,    29,   -71
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   240,   784,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   861,   862,   863,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,  1153,
     722,   264,   265,   867,   868,   869,   266,   267,   414,   415,
     268,  1103,   901,   269,  1538,  1539,   270,   271,   435,   272,
     548,   774,   996,  1218,   273,   274,   275,   276,   416,   417,
    1077,   277,   418,   419,   420,   421,   713,   714,  1194,  1063,
     278,   279,   572,   280,   281,   282,   581,   433,   931,   932,
     283,   582,   284,   584,   285,   286,   706,   707,  1141,   925,
     287,   724,   778,   725,   710,  1142,  1143,  1144,   779,   585,
     586,  1017,  1018,  1403,   587,  1014,  1015,  1238,  1239,  1240,
    1241,   288,   734,   735,   289,  1171,  1172,  1173,   290,  1175,
    1176,   291,   292,   293,   294,   813,   295,  1250,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     605,   606,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     632,   633,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   841,   335,   336,   337,  1196,   753,   754,   755,  1560,
    1599,  1600,  1593,  1594,  1601,  1595,  1197,  1198,   338,   339,
    1199,   340,   341,   342,   343,   344,   345,   346,  1049,   926,
    1039,  1287,  1040,  1437,  1041,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   741,  1117,   357,   358,   359,
     360,  1043,  1044,  1045,  1046,   361,   362,   363,   364,   365,
     366,   771,   772,   367,  1224,  1225,  1391,   368,  1025,  1260,
    1261,  1026,  1027,  1028,  1029,  1030,  1270,  1427,  1428,  1031,
    1273,  1032,  1408,  1033,  1034,  1278,  1279,  1433,  1431,  1262,
    1263,  1264,  1265,  1518,   675,   889,   890,   891,   892,   893,
     894,  1093,  1455,  1456,  1094,  1454,  1534,   895,  1304,  1451,
    1447,  1448,  1449,   896,   897,  1266,  1274,  1418,  1267,  1414,
    1251,  1154,   526,   369,   370
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       503,   948,   800,   820,   974,   821,   822,   823,   824,  1048,
     627,   958,  1024,   562,   503,   793,   795,   533,   924,  1111,
     565,   567,  1158,  1390,  1505,   645,  1311,   947,  1195,   501,
     919,  1130,  1246,  1399,  1400,  1457,   503,   667,  1042,  1042,
       7,   928,   809,   847,   810,   811,   563,   812,   503,   814,
     503,  1068,  1252,   788,   791,   794,   796,   815,   816,  1023,
     376,   378,   380,  1541,   690,   878,   787,   790,   879,   563,
     563,  1096,  1078,  1042,   563,  1429,  1379,  1097,   694,   644,
     899,   719,   723,   730,   644,   563,   992,   563,  1252,  1110,
     920,  1162,   921,   921,  1098,   535,  1099,   695,   563,  1123,
     502,  1558,  1127,   920,   570,  1100,  1362,   955,  1104,   570,
     880,   913,   570,  1147,   516,   975,  1219,  1487,  1335,   757,
     955,  1511,    77,  1253,   915,   935,   967,   920,   921,  1042,
    1284,  1101,  1137,   608,   969,    88,   522,  1415,  1138,   654,
     608,   922,  1131,  1042,   920,  1071,   711,   422,   527,   946,
     529,   609,  1054,   694,  1235,  1186,   617,   615,   609,  1253,
     102,   439,  1285,   521,  1020,   920,   616,  1021,  1542,   720,
     618,   655,   695,   610,  1237,   921,   981,  1326,   957,  1286,
    1571,   976,  1188,  1189,  1488,  1527,   571,   956,   121,  1559,
     914,  1363,  1507,  1591,  1010,  1134,  1512,  1188,  1220,   929,
     971,   628,  1135,   916,   936,   968,  1254,  1255,  1146,  1256,
     718,  1501,   993,   970,   712,   721,  1024,  1024,  1307,   985,
     900,  1187,   923,  1185,  1282,  1128,  1258,  1133,   923,   900,
     564,  1055,   793,   795,  1462,  1350,  1132,   930,  1259,  1195,
    1064,  1065,  1254,  1255,   923,  1256,  1042,   503,  1195,  1163,
     503,  1543,  1257,   566,   781,  1379,  1102,  1535,   783,  1407,
     881,  1635,  1258,  1023,  1023,  1019,  1578,   923,   923,  1005,
    1022,  1007,  1190,   882,  1259,   883,   634,  1648,   536,   636,
     923,   758,  1228,   787,   790,  1654,   884,   885,   886,   608,
     887,  1191,   888,  1192,   696,  1416,  1417,   982,   983,   381,
     382,  1222,   383,   384,  1568,  1054,  1191,   609,  1192,   874,
       7,  1297,   984,   626,   652,   503,  1592,  1525,  1531,  1104,
     503,   715,   387,  1627,   503,   107,   503,  1445,  1346,  1643,
    1188,   503,   786,   789,  1580,   782,   715,   121,   503,   425,
     986,   987,   119,   662,  1597,   921,   663,   502,   629,   630,
     502,   503,  1000,  1365,  1301,   988,   437,   503,  1042,   979,
     939,   503,  1193,   942,   559,  1090,   943,  1292,   503,  1248,
     503,   503,   503,   503,   503,  1612,  1229,  1540,   664,   503,
     145,  1091,   560,  1042,  1056,   438,  1062,   503,  1316,  1503,
    1298,  1446,    77,   121,  1467,   573,  1526,  1532,  1188,  1189,
    1515,   574,  1628,   450,   665,    88,   575,  1516,  1644,     7,
    1591,  1410,  1303,  1001,  1188,   653,   662,  1517,   980,   663,
     659,   426,   395,  1092,   527,   576,   668,  1195,  1301,  1461,
     102,   676,  1327,  1336,  1020,   430,  1057,  1021,   678,  1191,
     431,  1192,  1504,  1024,  1302,   631,   503,   637,  1003,  1411,
    1598,   527,  1024,  1058,   793,   795,   793,   702,   121,  1436,
     451,   708,  1188,  1024,  1540,   666,   560,  1084,   726,   715,
     527,   731,   732,   733,   736,   503,  1597,   665,  1085,   742,
     691,   399,   693,   503,   699,   432,  1303,   749,  1190,  1042,
    1023,    77,  1443,   717,  1230,  1231,  1232,   727,  1540,  1023,
     456,   864,   429,   737,    88,   739,   740,  1191,   743,  1192,
    1023,  1086,  1188,  1189,   746,  1072,  1073,   835,   836,  1515,
    1076,   577,  1087,  1191,   578,  1192,  1516,   452,   453,   102,
    1116,   457,  1119,  1621,   458,   385,  1517,   715,   666,   579,
     611,   107,   865,  1275,  1276,  1059,   736,   866,   538,  1002,
     539,  1114,   388,   715,   389,  1066,  1552,   646,   119,  1645,
    1006,  1646,  1060,   390,   580,  1108,  1277,  1066,   612,  1412,
     647,  1191,   444,  1192,  1109,   773,  1413,  1659,  1374,   434,
     756,   613,  1624,   780,  1181,   849,  1182,   850,  1188,  1189,
     503,   760,  1137,   608,  1596,  1602,   145,  1234,  1138,   687,
     544,   715,  1190,   650,   445,   545,  1061,  1235,   436,  1291,
     777,   609,   503,   503,   503,   614,  1139,  1236,  1293,   651,
    1024,  1191,  1062,  1192,  1490,   547,  1090,  1237,  1493,   442,
    1596,   648,  1170,  1174,  1294,   921,  1602,   920,   503,  1201,
     503,  1202,  1091,  1468,   649,  1360,  1366,   503,  1235,   568,
     503,   715,  1422,   443,   569,   107,  1140,   448,  1137,   397,
    1079,  1080,  1081,  1502,  1138,   838,  1082,  1023,   838,   635,
     865,   838,   119,   423,   638,   866,   424,   793,  1190,   427,
     449,   503,   428,   834,   669,   670,   671,   541,   837,   542,
     870,   440,  1378,   446,   441,   454,   447,  1191,  1206,  1192,
    1207,   455,  1573,   504,  1574,   505,   672,   673,  1074,  1075,
     145,   506,   903,   904,   905,   517,   681,   682,  1105,  1106,
    1396,  1397,   518,   627,  1442,   818,   819,   715,   825,   826,
     503,   107,  1042,  1589,  1042,   827,   828,   519,   927,   523,
     933,   524,  1561,  1050,  1050,  1564,   530,   527,   119,   531,
     527,  1528,  1529,   532,  1610,   534,   546,   537,   503,   503,
     503,   503,   703,  1042,   540,   547,   549,   543,  1492,   551,
     550,   553,   937,   552,   554,   556,   588,   589,   619,   607,
     621,   972,   622,   620,  1042,   639,   145,   631,   640,   641,
     642,   643,   644,   503,   656,   385,  1348,   658,   660,   661,
     674,   964,   965,  1510,   677,   679,   680,   683,   503,  1513,
    1514,   709,   692,  1604,   715,  1581,   851,   852,   853,   854,
     855,   856,   857,   858,   859,   860,   738,   744,   704,   705,
    1011,   997,   424,   428,   745,   503,   751,   752,   441,   759,
     447,   458,   503,   761,   503,   762,   765,   785,   797,   503,
     770,   801,   817,   829,   802,   830,   831,   803,  1047,  1047,
    1047,  1047,   832,   503,   804,   842,   845,   848,   871,   846,
     872,   763,   764,   876,   766,   767,   768,   769,   875,  1395,
     877,   898,   907,   396,   775,   776,   902,   906,   908,   909,
     910,   918,   934,  1047,   911,   912,   503,   917,   503,   938,
     941,   940,   798,   799,  1569,  1570,   944,   945,  1083,   949,
     950,   954,   805,   806,   951,   398,   952,   953,   960,   959,
     385,   963,   966,   961,   962,   989,   977,   978,   994,   990,
     386,   998,  1004,   991,  1012,  1113,   999,   388,  1016,   389,
    1052,  1067,  1118,   400,  1118,   503,   866,  1053,   390,  1047,
    1088,   920,   391,  1089,  1107,  1112,  1121,  1122,  1115,  1124,
    1126,  1129,   711,  1047,  1608,  1149,   503,  1152,  1150,  1136,
     840,  1151,  1155,   840,  1156,  1157,  1159,  1164,  1161,  1166,
    1169,  1178,  1170,   392,   393,  1008,  1174,  1180,  1184,  1200,
    1179,  1214,  1217,  1479,  1221,  1227,   742,  1226,   742,  1223,
     664,   684,   403,   404,   405,   406,  1242,   407,   408,   685,
     410,   411,   590,  1244,  1272,  1268,   412,  1280,  1249,  1177,
     591,   592,  1281,   593,  1283,  1269,  1288,     7,  1300,  1305,
     900,   594,  1320,  1309,  1321,   595,  1312,   596,  1317,  1299,
     396,  1310,   597,  1315,   397,  1243,  1508,  1322,  1331,  1323,
     503,  1324,  1333,   503,  1337,   503,  1339,  1340,  1341,   598,
    1345,  1313,  1349,  1368,  1354,  1371,  1047,  1373,  1376,   503,
    1372,  1235,   398,  1387,  1380,  1402,  1405,  1245,   503,  1425,
    1406,  1381,   599,   600,   601,   602,   603,   604,   503,  1385,
    1382,  1383,  1432,  1426,  1441,   503,  1409,  1384,  1438,  1430,
     400,  1419,  1439,   503,  1440,  1444,  1450,  1090,  1463,  1460,
    1458,  1477,  1465,  1470,  1478,  1481,  1482,  1489,  1523,  1290,
    1486,  1453,   503,  1521,  1524,  1506,  1509,  1533,  1537,  1545,
    1009,  1536,   401,  1548,  1550,  1554,  1013,  1566,  1567,  1563,
    1575,  1576,  1579,   503,  1583,  1588,   503,  1522,  1590,  1615,
     708,  1577,   503,  1328,  1603,  1329,   503,  1544,   402,   403,
     404,   405,   406,  1605,   407,   408,   409,   410,   411,  1343,
    1584,  1609,  1319,   412,   413,  1616,  1618,  1620,  1047,  1613,
    1623,  1632,  1634,  1636,  1626,  1062,  1647,  1649,   726,  1651,
    1652,  1656,   555,  1630,  1637,   736,  1655,  1640,  1296,  1070,
    1642,  1658,   557,  1047,   558,   873,   561,  1069,   686,   503,
    1314,  1586,  1611,  1389,   688,   657,   689,  1148,   716,  1145,
    1325,  1356,  1377,  1351,  1475,  1404,   583,  1401,  1344,  1394,
    1233,  1357,  1398,  1361,  1367,   807,   844,  1370,   808,   750,
     625,   503,   973,   773,  1622,  1375,  1388,  1625,  1051,  1308,
    1295,   697,   502,   698,  1120,  1125,   780,  1386,  1392,  1520,
    1519,  1247,  1420,  1271,  1424,  1095,  1306,  1452,  1423,   503,
     503,  1530,     0,  1421,     0,     0,     0,     0,     0,  1160,
       0,     0,     0,     0,     0,     0,     0,  1165,     0,  1167,
    1168,     0,     0,   503,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   503,  1183,     0,     0,   503,     0,  1047,
       0,     0,     0,     0,     0,  1203,  1204,  1205,     0,  1208,
    1209,  1210,  1211,  1212,  1213,     0,  1215,  1216,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1459,     0,     0,     0,  1013,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1473,
    1474,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   381,   382,     0,   383,   384,  1289,     0,     0,
       0,     0,     0,  1485,   385,     0,     0,     0,     0,     0,
       0,     0,     0,  1491,   386,   387,     0,  1494,     0,     0,
       0,   388,     0,   389,     0,     0,   503,     0,     0,     0,
       0,   503,   390,     0,     0,     0,   391,     0,     0,     0,
       0,     0,     0,   503,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   503,     0,   503,     0,     0,   392,   393,   394,
    1330,     0,  1332,     0,  1334,     0,     0,  1338,     0,     0,
     503,     0,  1342,   503,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   503,  1347,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1352,  1353,   503,     0,     0,     0,
       0,     0,  1358,  1359,   503,   395,     0,     0,     0,     0,
       0,     0,   503,     0,   396,     0,  1556,   503,   397,     0,
       0,  1562,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   502,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   503,     0,   398,     0,     0,     0,
       0,     0,  1047,     0,  1047,     0,     0,     0,     0,  1393,
       0,   503,     0,   503,   399,     0,     0,     0,     0,     0,
    1582,     0,     0,  1585,   400,  1013,   503,     0,  1572,     0,
     503,     0,     0,  1047,     0,   503,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1607,     0,     0,     0,
       0,     0,     0,     0,  1047,     0,   401,     0,     0,     0,
       0,     0,  1614,     0,     0,     0,     0,  1617,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   402,   403,   404,   405,   406,     0,   407,   408,
     409,   410,   411,     0,  1631,     0,     0,   412,   413,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1464,
       0,  1638,     0,  1639,  1466,     0,     0,     0,  1469,     0,
    1471,     0,  1472,     0,     0,     0,  1650,     0,  1476,     0,
    1653,     0,     0,     0,     0,  1657,     0,  1480,     0,     0,
       0,     0,     0,     0,     0,  1483,  1484,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1495,  1496,  1497,  1498,  1499,     0,
    1500,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1546,     0,
    1547,     0,     0,  1549,     0,     0,     0,     0,     0,     0,
    1551,     0,     0,     0,     0,  1553,     0,     0,     0,  1555,
       0,  1557,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1565,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1587,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1606,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1619,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1629,     0,     0,     0,
       0,  1633,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     0,     7,     0,     0,
    1641,     8,     9,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     0,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,     0,    67,    68,    69,    70,    71,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,    88,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,   104,
     105,     0,     0,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,   128,
     129,   130,     0,   131,     0,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     0,     7,     0,     0,     0,   371,   372,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   373,    26,    27,    28,    29,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,    88,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,   106,
     107,   108,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,     0,   119,     0,   120,
     121,     0,     0,   122,   123,   124,     0,   374,     0,   125,
       0,   126,   127,     0,   128,   129,   130,     0,   131,     0,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,   145,     0,   375,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     0,     7,     0,     0,     0,
     371,   372,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   373,    26,
      27,    28,    29,     0,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     0,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,    88,     0,    89,    90,    91,    92,     0,    93,     0,
       0,     0,    94,    95,    96,    97,    98,     0,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,   105,
       0,     0,     0,   106,   107,   108,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   115,   116,   117,   118,
       0,   119,     0,   120,   121,     0,     0,   122,   123,   124,
       0,   377,     0,   125,     0,   126,   127,     0,   128,   129,
     130,     0,   131,     0,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,     0,     0,   143,   144,   145,
       0,   375,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     0,
       7,     0,     0,     0,   371,   372,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,   373,    26,    27,    28,    29,     0,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,     0,    67,    68,    69,
      70,    71,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,    88,     0,    89,    90,    91,
      92,     0,    93,     0,     0,     0,    94,    95,    96,    97,
      98,     0,     0,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,   105,     0,     0,     0,   106,   107,   108,
     109,   110,     0,     0,     0,     0,   111,   112,   113,   114,
     115,   116,   117,   118,     0,   119,     0,   120,   121,     0,
       0,   122,   123,   124,     0,   379,     0,   125,     0,   126,
     127,     0,   128,   129,   130,     0,   131,     0,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,     0,
       0,   143,   144,   145,     0,   375,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,   192,     0,   193,   194,   195,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     0,     7,     0,     0,     0,   371,   372,
       0,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,   373,    26,    27,    28,
      29,     0,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
       0,    67,    68,    69,    70,    71,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,     0,    88,
       0,    89,    90,    91,    92,     0,    93,     0,     0,     0,
      94,    95,    96,    97,    98,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,   105,     0,     0,
       0,   106,   107,   108,   109,   110,     0,     0,     0,     0,
     111,   112,   113,   114,   115,   116,   117,   118,     0,   119,
       0,   120,   121,     0,     0,   122,   123,   124,     0,     0,
       0,   125,   520,   126,   127,     0,   128,   129,   130,     0,
     131,     0,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,     0,     0,   143,   144,   145,     0,   375,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     0,     7,     0,
       0,     0,   371,   372,     0,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
     373,    26,    27,    28,    29,     0,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,     0,    67,    68,    69,    70,    71,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,    88,     0,    89,    90,    91,    92,     0,
      93,     0,     0,     0,    94,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,   105,     0,     0,     0,   106,   107,   108,   109,   110,
       0,     0,     0,     0,   111,   112,   113,   114,   115,   116,
     117,   118,     0,   119,     0,   120,   121,     0,     0,   122,
     123,   124,     0,   833,     0,   125,     0,   126,   127,     0,
     128,   129,   130,     0,   131,     0,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,     0,     0,   143,
     144,   145,     0,   375,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
     192,     0,   193,   194,   195,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     0,     7,     0,     0,     0,   371,   372,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   373,    26,    27,    28,    29,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,    88,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,   106,
     107,   108,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,     0,   119,     0,   120,
     121,     0,     0,   122,   123,   124,     0,     0,     0,   125,
     839,   126,   127,     0,   128,   129,   130,     0,   131,     0,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,   145,     0,   375,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     0,     7,     0,     0,     0,
     371,   372,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   373,    26,
      27,    28,    29,     0,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     0,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,    88,     0,    89,    90,    91,    92,     0,    93,     0,
       0,     0,    94,    95,    96,    97,    98,     0,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,   105,
       0,     0,     0,   106,   107,   108,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   115,   116,   117,   118,
       0,   119,     0,   120,   121,     0,     0,   122,   123,   124,
       0,     0,     0,   125,   843,   126,   127,     0,   128,   129,
     130,     0,   131,     0,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,     0,     0,   143,   144,   145,
       0,   375,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     0,
       7,     0,     0,     0,   371,   372,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,   373,    26,    27,    28,    29,     0,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,     0,    67,    68,    69,
      70,    71,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,    88,     0,    89,    90,    91,
      92,     0,    93,     0,     0,     0,    94,    95,    96,    97,
      98,     0,     0,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,   105,     0,     0,     0,   106,   107,   108,
     109,   110,     0,     0,     0,     0,   111,   112,   113,   114,
     115,   116,   117,   118,     0,   119,     0,   120,   121,     0,
       0,   122,   123,   124,     0,  1318,     0,   125,     0,   126,
     127,     0,   128,   129,   130,     0,   131,     0,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,     0,
       0,   143,   144,   145,     0,   375,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,   192,     0,   193,   194,   195,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     0,     7,     0,     0,     0,   371,   372,
       0,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,   373,    26,    27,    28,
      29,     0,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
       0,    67,    68,    69,    70,    71,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,     0,    88,
       0,    89,    90,    91,    92,     0,    93,     0,     0,     0,
      94,    95,    96,    97,    98,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,   105,     0,     0,
       0,   106,   107,   108,   109,   110,     0,     0,     0,     0,
     111,   112,   113,   114,   115,   116,   117,   118,     0,   119,
       0,   120,   121,     0,     0,   122,   123,   124,     0,  1355,
       0,   125,     0,   126,   127,     0,   128,   129,   130,     0,
     131,     0,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,     0,     0,   143,   144,   145,     0,   375,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     0,     7,     0,
       0,     0,   371,   372,     0,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
     373,    26,    27,    28,    29,     0,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,     0,    67,    68,    69,    70,    71,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,    88,     0,    89,    90,    91,    92,     0,
      93,     0,     0,     0,    94,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,   105,     0,     0,     0,   106,   107,   108,   109,   110,
       0,     0,     0,     0,   111,   112,   113,   114,   115,   116,
     117,   118,     0,   119,     0,   120,   121,     0,     0,   122,
     123,   124,     0,  1369,     0,   125,     0,   126,   127,     0,
     128,   129,   130,     0,   131,     0,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,     0,     0,   143,
     144,   145,     0,   375,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
     192,     0,   193,   194,   195,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     0,     7,     0,     0,     0,     8,     9,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,    88,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,   106,
     107,   108,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,     0,   119,     0,   120,
     121,     0,     0,   122,   123,   124,     0,     0,     0,   125,
       0,   126,   127,     0,   128,   129,   130,     0,   131,     0,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     0,     7,     0,     0,     0,
       8,     9,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     0,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     0,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,    88,     0,    89,    90,    91,    92,     0,    93,     0,
       0,     0,    94,    95,    96,    97,    98,     0,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,   105,
       0,     0,     0,   106,   107,   108,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   115,   116,   117,   118,
       0,   119,     0,   120,   121,     0,     0,   122,   123,   124,
       0,     0,     0,   125,     0,   126,   127,     0,   128,   129,
     130,     0,   131,     0,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,     0,     0,   143,   144,   145,
       0,   375,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     0,
       7,     0,     0,     0,   371,   372,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,   462,   463,
      23,   465,   373,    26,   466,    28,    29,     0,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,   468,    41,
      42,   469,     0,    44,    45,    46,   471,   472,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,     0,    67,    68,    69,
      70,    71,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,    88,     0,    89,    90,    91,
      92,     0,    93,     0,     0,     0,   480,    95,    96,    97,
      98,     0,     0,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,   105,     0,     0,     0,   106,   107,   623,
     109,   110,     0,     0,     0,     0,   111,   112,   113,   114,
     115,   116,   117,   118,     0,   119,     0,   624,   121,     0,
       0,   122,   123,   124,     0,     0,     0,   125,     0,   126,
     127,     0,   128,   129,   130,     0,   131,     0,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,     0,
       0,   143,   144,   145,     0,   375,   147,   148,   149,   150,
     151,   152,   153,   154,   489,   156,   490,   158,   491,   492,
     161,   162,   163,   164,   165,   166,   493,   168,   494,   495,
     496,   497,   173,   174,   498,   499,   177,   500,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,   192,     0,   193,   194,   195,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     0,     7,     0,     0,     0,   371,   372,
       0,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,   373,    26,    27,    28,
      29,     0,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
       0,    67,    68,    69,    70,    71,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,     0,    88,
       0,    89,    90,    91,    92,     0,    93,     0,     0,     0,
      94,    95,    96,    97,    98,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,   105,     0,     0,
       0,   106,   107,   108,   109,   110,     0,     0,     0,     0,
     111,   112,   113,   114,   115,   116,   117,   118,     0,   119,
       0,   120,   121,     0,     0,   122,   123,   124,     0,     0,
       0,   125,     0,   126,   127,     0,   128,   129,   130,     0,
     131,     0,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,     0,     0,   143,   144,   145,     0,   375,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     0,     7,     0,
       0,     0,     8,   372,     0,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     0,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,     0,    67,    68,    69,    70,    71,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,    88,     0,    89,    90,    91,    92,     0,
      93,     0,     0,     0,    94,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,   105,     0,     0,     0,   106,   107,   108,   109,   110,
       0,     0,     0,     0,   111,   112,   113,   114,   115,   116,
     117,   118,     0,   119,     0,   120,   121,     0,     0,   122,
     123,   124,     0,     0,     0,   125,     0,   126,   127,     0,
     128,   129,   130,     0,   131,     0,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,     0,     0,   143,
     144,   145,     0,   375,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
     192,     0,   193,   194,   195,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     0,     7,     0,     0,     0,   792,   372,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   373,    26,    27,    28,    29,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,    88,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,   106,
     107,   108,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,     0,   119,     0,   120,
     121,     0,     0,   122,   123,   124,     0,     0,     0,   125,
       0,   126,   127,     0,   128,   129,   130,     0,   131,     0,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,   145,     0,   375,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     0,     7,     0,     0,     0,
     371,   372,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   462,   463,    23,   465,   373,    26,
     466,    28,    29,     0,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,   468,    41,    42,   469,     0,    44,
      45,    46,   471,   472,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     0,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,    88,     0,    89,    90,    91,    92,     0,    93,     0,
       0,     0,   480,    95,    96,    97,    98,     0,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,   105,
       0,     0,     0,   106,   107,   108,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   115,   116,   117,   118,
       0,   119,     0,   120,   121,     0,     0,   122,   123,   124,
       0,     0,     0,   125,     0,   126,   127,     0,   128,   129,
     130,     0,   131,     0,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,     0,     0,   143,   144,   145,
       0,   375,   147,   148,   149,   150,   151,   152,   153,   154,
     489,   156,   490,   158,   491,   492,   161,   162,   163,   164,
     165,   166,   493,   168,   494,   495,   496,   497,   173,   174,
     498,   499,   177,   500,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     0,
       7,     0,     0,     0,   995,   372,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,   373,    26,    27,    28,    29,     0,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,     0,    67,    68,    69,
      70,    71,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,    88,     0,    89,    90,    91,
      92,     0,    93,     0,     0,     0,    94,    95,    96,    97,
      98,     0,     0,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,   105,     0,     0,     0,   106,   107,   108,
     109,   110,     0,     0,     0,     0,   111,   112,   113,   114,
     115,   116,   117,   118,     0,   119,     0,   120,   121,     0,
       0,   122,   123,   124,     0,     0,     0,   125,     0,   126,
     127,     0,   128,   129,   130,     0,   131,     0,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,     0,
       0,   143,   144,   145,     0,   375,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,   192,     0,   193,   194,   195,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     0,     7,     0,     0,     0,   371,   372,
       0,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,   462,   463,    23,   465,   373,    26,   466,    28,
      29,     0,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,   468,    41,    42,   469,     0,    44,    45,    46,
     471,   472,    49,   473,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
       0,    67,    68,    69,    70,    71,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,     0,    88,
       0,    89,    90,    91,    92,     0,    93,     0,     0,     0,
     480,    95,    96,    97,    98,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,   105,     0,     0,
       0,   106,   107,     0,   109,   110,     0,     0,     0,     0,
     111,   112,   113,   114,   115,   116,   117,   118,     0,   119,
       0,     0,     0,     0,     0,   122,   123,   124,     0,     0,
       0,   125,     0,   126,   127,     0,   128,   129,   130,     0,
     131,     0,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,     0,     0,   143,   144,   145,     0,   375,
     147,   148,   149,   150,   151,   152,   153,   154,   489,   156,
     490,   158,   491,   492,   161,   162,   163,   164,   165,   166,
     493,   168,   494,   495,   496,   497,   173,   174,   498,   499,
     177,   500,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     0,     7,     0,
       0,     0,   371,   372,     0,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,   462,   463,    23,   465,
     373,    26,   466,    28,    29,     0,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,   468,    41,    42,   469,
       0,    44,    45,    46,   471,   472,    49,   473,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,     0,    67,    68,    69,    70,    71,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,    88,     0,    89,    90,    91,    92,     0,
      93,     0,     0,     0,   480,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,   105,     0,     0,     0,   106,   107,     0,   109,   110,
       0,     0,     0,     0,   111,   112,   113,   114,   115,   116,
     117,   118,     0,   119,     0,     0,     0,     0,     0,   122,
     123,   124,     0,     0,     0,   125,     0,   126,   127,     0,
       0,     0,   130,     0,   131,     0,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,     0,     0,   143,
     144,   145,     0,   375,   147,   148,   149,   150,   151,   152,
     153,   154,   489,   156,   490,   158,   491,   492,   161,   162,
     163,   164,   165,   166,   493,   168,   494,   495,   496,   497,
     173,   174,   498,   499,   177,   500,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
     192,     0,   193,   194,   195,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,     1,
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
       6,     0,     0,     0,     0,     0,   371,   372,     0,    10,
      11,    12,   459,    14,    15,    16,    17,   460,    19,   461,
     462,   463,   464,   465,   373,    26,   466,    28,    29,     0,
      30,    31,    32,    33,    34,   467,    36,    37,    38,    39,
     468,    41,    42,   469,     0,    44,   470,    46,   471,   472,
      49,   473,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,   474,   475,    66,     0,    67,
      68,    69,   476,     0,    72,    73,    74,     0,     0,   477,
      76,     0,     0,     0,     0,    78,    79,    80,   478,   479,
      83,    84,     0,     0,     0,     0,     0,     0,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,   480,    95,
      96,   481,   482,     0,     0,     0,     0,     0,     0,    99,
     100,   101,     0,   103,   104,   105,     0,     0,     0,     0,
       0,     0,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   483,   116,   117,   484,     0,     0,     0,     0,
       0,     0,     0,   485,   486,   124,     0,     0,     0,   125,
       0,   126,   487,     0,     0,     0,   130,     0,   131,     0,
     132,   133,   134,   135,   488,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,     0,     0,   375,   147,   148,
     149,   150,   151,   152,   153,   154,   489,   156,   490,   158,
     491,   492,   161,   162,   163,   164,   165,   166,   493,   168,
     494,   495,   496,   497,   173,   174,   498,   499,   177,   500,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     1,     0,     0,     0,     0,     0,     0,
       2,     0,     0,     0,     6,     0,     0,     0,     0,     0,
     371,   372,     0,    10,    11,    12,   507,    14,    15,    16,
      17,   460,   508,   509,   462,   463,   464,   465,   373,    26,
     466,    28,    29,     0,    30,    31,    32,    33,    34,   510,
      36,   511,   512,    39,   468,    41,    42,   469,     0,    44,
     513,    46,   471,   472,    49,   473,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,   474,
     475,    66,     0,    67,    68,    69,   514,     0,    72,    73,
      74,     0,     0,   477,    76,     0,     0,     0,     0,    78,
      79,    80,   478,   479,    83,    84,     0,     0,     0,     0,
       0,     0,     0,    89,    90,    91,    92,     0,    93,     0,
       0,     0,   480,    95,    96,   481,   482,     0,     0,     0,
       0,     0,     0,    99,   100,   101,     0,   103,   104,   105,
       0,     0,     0,     0,     0,     0,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   483,   116,   117,   484,
       0,     0,     0,     0,     0,     0,     0,   485,   486,   124,
       0,     0,     0,   125,     0,   126,   487,     0,     0,     0,
     130,     0,   131,     0,   132,   133,   134,   135,   488,   137,
     138,   139,   140,   141,   142,     0,     0,   143,   144,     0,
       0,   375,   147,   148,   149,   150,   151,   152,   153,   154,
     489,   515,   490,   158,   491,   492,   161,   162,   163,   164,
     165,   166,   493,   168,   494,   495,   496,   497,   173,   174,
     498,   499,   177,   500,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   525,     0,     0,
       0,     0,     0,     0,     6,     0,   728,     0,     0,     0,
     371,   372,     0,    10,    11,    12,   507,    14,    15,    16,
      17,   460,   508,   509,   462,   463,   464,   465,   373,    26,
     466,    28,    29,     0,    30,    31,    32,    33,    34,   510,
      36,   511,   512,    39,   468,    41,    42,   469,     0,    44,
     513,    46,   471,   472,    49,   473,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,   474,
     475,    66,     0,    67,    68,    69,   514,     0,    72,    73,
      74,     0,     0,   477,    76,     0,     0,     0,     0,    78,
      79,    80,   478,   479,    83,    84,     0,     0,     0,     0,
       0,     0,     0,    89,    90,    91,    92,     0,    93,     0,
       0,     0,   480,    95,    96,   481,   482,     0,     0,     0,
       0,     0,     0,    99,   100,   101,     0,   103,   104,   105,
       0,     0,     0,     0,     0,     0,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   483,   116,   117,   484,
       0,     0,     0,     0,     0,     0,     0,   485,   486,   124,
       0,     0,     0,   125,   729,   126,   487,     0,     0,     0,
       0,     0,   131,     0,   132,   133,   134,   135,   488,   137,
     138,   139,   140,   141,   142,     0,     0,   143,   144,     0,
       0,   375,   147,   148,   149,   150,   151,   152,   153,   154,
     489,   515,   490,   158,   491,   492,   161,   162,   163,   164,
     165,   166,   493,   168,   494,   495,   496,   497,   173,   174,
     498,   499,   177,   500,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   525,     0,     0,
       0,     0,     0,     0,     6,     0,     0,     0,     0,     0,
     371,   372,     0,    10,    11,    12,   507,    14,    15,    16,
      17,   460,   508,   509,   462,   463,   464,   465,   373,    26,
     466,    28,    29,     0,    30,    31,    32,    33,    34,   510,
      36,   511,   512,    39,   468,    41,    42,   469,     0,    44,
     513,    46,   471,   472,    49,   473,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,   474,
     475,    66,     0,    67,    68,    69,   514,     0,    72,    73,
      74,     0,     0,   477,    76,     0,     0,     0,     0,    78,
      79,    80,   478,   479,    83,    84,     0,     0,     0,     0,
       0,     0,     0,    89,    90,    91,    92,     0,    93,     0,
       0,     0,   480,    95,    96,   481,   482,     0,     0,     0,
       0,     0,     0,    99,   100,   101,     0,   103,   104,   105,
       0,     0,     0,     0,     0,     0,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   483,   116,   117,   484,
       0,     0,     0,     0,     0,     0,     0,   485,   486,   124,
       0,     0,     0,   125,     0,   126,   487,     0,     0,     0,
       0,     0,   131,     0,   132,   133,   134,   135,   488,   137,
     138,   139,   140,   141,   142,     0,     0,   143,   144,     0,
       0,   375,   147,   148,   149,   150,   151,   152,   153,   154,
     489,   515,   490,   158,   491,   492,   161,   162,   163,   164,
     165,   166,   493,   168,   494,   495,   496,   497,   173,   174,
     498,   499,   177,   500,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   528,     0,     0,
       0,     0,     6,     0,     0,     0,     0,     0,   371,   372,
       0,    10,    11,    12,   507,    14,    15,    16,    17,   460,
     508,   509,   462,   463,   464,   465,   373,    26,   466,    28,
      29,     0,    30,    31,    32,    33,    34,   510,    36,   511,
     512,    39,   468,    41,    42,   469,     0,    44,   513,    46,
     471,   472,    49,   473,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,   474,   475,    66,
       0,    67,    68,    69,   514,     0,    72,    73,    74,     0,
       0,   477,    76,     0,     0,     0,     0,    78,    79,    80,
     478,   479,    83,    84,     0,     0,     0,     0,     0,     0,
       0,    89,    90,    91,    92,     0,    93,     0,     0,     0,
     480,    95,    96,   481,   482,     0,     0,     0,     0,     0,
       0,    99,   100,   101,     0,   103,   104,   105,     0,     0,
       0,     0,     0,     0,   109,   110,     0,     0,     0,     0,
     111,   112,   113,   114,   483,   116,   117,   484,     0,     0,
       0,     0,     0,     0,     0,   485,   486,   124,     0,     0,
       0,   125,     0,   126,   487,     0,     0,     0,     0,     0,
     131,     0,   132,   133,   134,   135,   488,   137,   138,   139,
     140,   141,   142,     0,     0,   143,   144,     0,     0,   375,
     147,   148,   149,   150,   151,   152,   153,   154,   489,   515,
     490,   158,   491,   492,   161,   162,   163,   164,   165,   166,
     493,   168,   494,   495,   496,   497,   173,   174,   498,   499,
     177,   500,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,     6,     0,     0,     0,     0,
       0,   371,   372,     0,    10,    11,    12,   459,    14,    15,
      16,    17,   460,    19,   461,   462,   463,  1035,   465,   373,
      26,   466,    28,    29,     0,    30,    31,    32,    33,    34,
     467,    36,    37,    38,    39,   468,    41,    42,   469,     0,
      44,   470,    46,   471,   472,    49,   473,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
     474,   475,    66,     0,    67,    68,    69,   476,     0,    72,
      73,    74,     0,     0,   477,    76,     0,     0,     0,     0,
      78,    79,    80,   478,   479,    83,    84,     0,     0,     0,
       0,     0,     0,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,   480,    95,    96,   481,   482,     0,     0,
       0,     0,     0,     0,    99,   100,   101,     0,   103,   104,
    1036,     0,     0,     0,  1037,     0,     0,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   483,   116,   117,
     484,     0,     0,     0,     0,     0,     0,     0,   485,   486,
     124,     0,     0,     0,   125,  1434,   126,   487,     0,     0,
       0,  1435,     0,   131,     0,   132,   133,   134,   135,   488,
     137,   138,   139,   140,   141,   142,     0,     0,  1038,   144,
       0,     0,   375,   147,   148,   149,   150,   151,   152,   153,
     154,   489,   156,   490,   158,   491,   492,   161,   162,   163,
     164,   165,   166,   493,   168,   494,   495,   496,   497,   173,
     174,   498,   499,   177,   500,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     6,     0,
       0,     0,     0,     0,   371,   372,     0,    10,    11,    12,
     507,    14,    15,    16,    17,   460,   508,   509,   462,   463,
     464,   465,   373,    26,   466,    28,    29,     0,    30,    31,
      32,    33,    34,   510,    36,   511,   512,    39,   468,    41,
      42,   469,     0,    44,   513,    46,   471,   472,    49,   473,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,   474,   475,    66,     0,    67,    68,    69,
     514,     0,    72,    73,    74,     0,     0,   477,    76,     0,
       0,     0,     0,    78,    79,    80,   478,   479,    83,    84,
       0,     0,     0,     0,     0,     0,     0,    89,    90,    91,
      92,     0,    93,     0,     0,     0,   480,    95,    96,   481,
     482,     0,     0,     0,     0,     0,     0,    99,   100,   101,
       0,   103,   104,   105,     0,     0,     0,     0,     0,     0,
     109,   110,     0,     0,     0,     0,   111,   112,   113,   114,
     483,   116,   117,   484,     0,     0,     0,     0,     0,     0,
       0,   485,   486,   124,     0,     0,     0,   125,   700,   126,
     487,     0,     0,     0,   701,     0,   131,     0,   132,   133,
     134,   135,   488,   137,   138,   139,   140,   141,   142,     0,
       0,   143,   144,     0,     0,   375,   147,   148,   149,   150,
     151,   152,   153,   154,   489,   515,   490,   158,   491,   492,
     161,   162,   163,   164,   165,   166,   493,   168,   494,   495,
     496,   497,   173,   174,   498,   499,   177,   500,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,   192,     0,   193,   194,   195,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,     6,     0,     0,     0,     0,     0,   371,   372,     0,
      10,    11,    12,   507,    14,    15,    16,    17,   460,   508,
     509,   462,   463,   464,   465,   373,    26,   466,    28,    29,
       0,    30,    31,    32,    33,    34,   510,    36,   511,   512,
      39,   468,    41,    42,   469,     0,    44,   513,    46,   471,
     472,    49,   473,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,   474,   475,    66,     0,
      67,    68,    69,   514,     0,    72,    73,    74,     0,     0,
     477,    76,     0,     0,     0,     0,    78,    79,    80,   478,
     479,    83,    84,     0,     0,     0,     0,     0,     0,     0,
      89,    90,    91,    92,     0,    93,     0,     0,     0,   480,
      95,    96,   481,   482,     0,     0,     0,     0,     0,     0,
      99,   100,   101,     0,   103,   104,   105,     0,     0,     0,
       0,     0,     0,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   483,   116,   117,   484,     0,     0,     0,
       0,     0,     0,     0,   485,   486,   124,     0,     0,     0,
     125,   747,   126,   487,     0,     0,     0,   748,     0,   131,
       0,   132,   133,   134,   135,   488,   137,   138,   139,   140,
     141,   142,     0,     0,   143,   144,     0,     0,   375,   147,
     148,   149,   150,   151,   152,   153,   154,   489,   515,   490,
     158,   491,   492,   161,   162,   163,   164,   165,   166,   493,
     168,   494,   495,   496,   497,   173,   174,   498,   499,   177,
     500,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,     6,     0,     0,     0,     0,     0,
     371,   372,     0,    10,    11,    12,   459,    14,    15,    16,
      17,   460,    19,   461,   462,   463,  1035,   465,   373,    26,
     466,    28,    29,     0,    30,    31,    32,    33,    34,   467,
      36,    37,    38,    39,   468,    41,    42,   469,     0,    44,
     470,    46,   471,   472,    49,   473,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,   474,
     475,    66,     0,    67,    68,    69,   476,     0,    72,    73,
      74,     0,     0,   477,    76,     0,     0,     0,     0,    78,
      79,    80,   478,   479,    83,    84,  1364,     0,     0,     0,
       0,     0,     0,    89,    90,    91,    92,     0,    93,     0,
       0,     0,   480,    95,    96,   481,   482,     0,     0,     0,
       0,     0,     0,    99,   100,   101,     0,   103,   104,  1036,
       0,     0,     0,  1037,     0,     0,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   483,   116,   117,   484,
       0,     0,     0,     0,     0,     0,     0,   485,   486,   124,
       0,     0,     0,   125,     0,   126,   487,     0,     0,     0,
       0,     0,   131,     0,   132,   133,   134,   135,   488,   137,
     138,   139,   140,   141,   142,     0,     0,  1038,   144,     0,
       0,   375,   147,   148,   149,   150,   151,   152,   153,   154,
     489,   156,   490,   158,   491,   492,   161,   162,   163,   164,
     165,   166,   493,   168,   494,   495,   496,   497,   173,   174,
     498,   499,   177,   500,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     6,     0,     0,
       0,     0,     0,   371,   372,     0,    10,    11,    12,   459,
      14,    15,    16,    17,   460,    19,   461,   462,   463,  1035,
     465,   373,    26,   466,    28,    29,     0,    30,    31,    32,
      33,    34,   467,    36,    37,    38,    39,   468,    41,    42,
     469,     0,    44,   470,    46,   471,   472,    49,   473,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,   474,   475,    66,     0,    67,    68,    69,   476,
       0,    72,    73,    74,     0,     0,   477,    76,     0,     0,
       0,     0,    78,    79,    80,   478,   479,    83,    84,     0,
       0,     0,     0,     0,     0,     0,    89,    90,    91,    92,
       0,    93,     0,     0,     0,   480,    95,    96,   481,   482,
       0,     0,     0,     0,     0,     0,    99,   100,   101,     0,
     103,   104,  1036,     0,     0,     0,  1037,     0,     0,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   483,
     116,   117,   484,     0,     0,     0,     0,     0,     0,     0,
     485,   486,   124,     0,     0,     0,   125,     0,   126,   487,
       0,     0,     0,     0,     0,   131,     0,   132,   133,   134,
     135,   488,   137,   138,   139,   140,   141,   142,     0,     0,
    1038,   144,     0,     0,   375,   147,   148,   149,   150,   151,
     152,   153,   154,   489,   156,   490,   158,   491,   492,   161,
     162,   163,   164,   165,   166,   493,   168,   494,   495,   496,
     497,   173,   174,   498,   499,   177,   500,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
       6,     0,     0,     0,     0,     0,   371,   372,     0,    10,
      11,    12,   459,    14,    15,    16,    17,   460,    19,   461,
     462,   463,  1035,   465,   373,    26,   466,    28,    29,     0,
      30,    31,    32,    33,    34,   467,    36,    37,    38,    39,
     468,    41,    42,   469,     0,    44,   470,    46,   471,   472,
      49,   473,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,   474,   475,    66,     0,    67,
      68,    69,   476,     0,    72,    73,    74,     0,     0,   477,
      76,     0,     0,     0,     0,    78,    79,    80,   478,   479,
      83,    84,     0,     0,     0,     0,     0,     0,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,   480,    95,
      96,   481,   482,     0,     0,     0,     0,     0,     0,    99,
     100,   101,     0,   103,   104,  1036,     0,     0,     0,  1037,
       0,     0,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   483,   116,   117,   484,     0,     0,     0,     0,
       0,     0,     0,   485,   486,   124,     0,     0,     0,   125,
       0,   126,   487,     0,     0,     0,     0,     0,   131,     0,
     132,   133,   134,   135,   488,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,     0,     0,   375,   147,   148,
     149,   150,   151,   152,   153,   154,   489,   156,   490,   158,
     491,   492,   161,   162,   163,   164,   165,   166,   493,   168,
     494,   495,   496,   497,   173,   174,   498,   499,   177,   500,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     6,     0,     0,     0,     0,     0,   371,
     372,     0,    10,    11,    12,   507,    14,    15,    16,    17,
     460,   508,   509,   462,   463,   464,   465,   373,    26,   466,
      28,    29,     0,    30,    31,    32,    33,    34,   510,    36,
     511,   512,    39,   468,    41,    42,   469,     0,    44,   513,
      46,   471,   472,    49,   473,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,   474,   475,
      66,     0,    67,    68,    69,   514,     0,    72,    73,    74,
       0,     0,   477,    76,     0,     0,     0,     0,    78,    79,
      80,   478,   479,    83,    84,     0,     0,     0,     0,     0,
       0,     0,    89,    90,    91,    92,     0,    93,     0,     0,
       0,   480,    95,    96,   481,   482,     0,     0,     0,     0,
       0,     0,    99,   100,   101,     0,   103,   104,   105,     0,
       0,     0,     0,     0,     0,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   483,   116,   117,   484,     0,
       0,     0,     0,     0,     0,     0,   485,   486,   124,     0,
       0,     0,   125,     0,   126,   487,     0,     0,     0,     0,
       0,   131,     0,   132,   133,   134,   135,   488,   137,   138,
     139,   140,   141,   142,     0,     0,   143,   144,     0,     0,
     375,   147,   148,   149,   150,   151,   152,   153,   154,   489,
     515,   490,   158,   491,   492,   161,   162,   163,   164,   165,
     166,   493,   168,   494,   495,   496,   497,   173,   174,   498,
     499,   177,   500,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,     0,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     6,     0,     0,     0,
       0,     0,   371,   372,     0,    10,    11,    12,     0,    14,
      15,    16,    17,   460,     0,     0,   462,   463,   464,     0,
     373,    26,   466,    28,    29,     0,    30,    31,    32,    33,
      34,     0,    36,     0,     0,    39,   468,    41,    42,   469,
       0,    44,     0,    46,     0,     0,    49,   473,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,   474,   475,    66,     0,    67,    68,    69,     0,     0,
      72,    73,    74,     0,     0,   477,    76,     0,     0,     0,
       0,    78,    79,    80,   478,   479,    83,    84,     0,     0,
       0,     0,     0,     0,     0,    89,    90,    91,    92,     0,
      93,     0,     0,     0,   480,    95,    96,   481,   482,     0,
       0,     0,     0,     0,     0,    99,   100,   101,     0,   103,
     104,     0,     0,     0,     0,     0,     0,     0,   109,   110,
       0,     0,     0,     0,   111,   112,   113,   114,   483,   116,
     117,   484,     0,     0,     0,     0,     0,     0,     0,   485,
     486,   124,     0,     0,     0,   125,     0,   126,   487,     0,
       0,     0,     0,     0,   131,     0,   132,   133,   134,   135,
     488,   137,   138,   139,   140,   141,   142,     0,     0,     0,
     144,     0,     0,   375,   147,   148,   149,   150,   151,   152,
     153,   154,   489,     0,   490,   158,   491,   492,   161,   162,
     163,   164,   165,   166,   493,   168,   494,   495,   496,   497,
     173,   174,     0,   499,   177,   500,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
     192,     0,   193,   194,   195,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        71,   726,   572,   610,   753,   611,   612,   613,   614,   830,
     310,   736,   817,   245,    85,   566,   567,   129,   708,   904,
     246,   247,   944,  1223,  1391,   381,  1107,   726,   976,    71,
      31,    31,  1021,  1239,  1240,  1306,   107,   395,   829,   830,
      24,    53,   590,   652,   592,   593,     1,   595,   119,   597,
     121,   864,    93,   564,   565,   566,   567,   605,   606,   817,
       3,     4,     5,   114,   422,    51,   564,   565,    54,     1,
       1,    34,   877,   864,     1,  1272,  1196,    40,    41,    24,
      91,   437,   438,   441,    24,     1,   103,     1,    93,    91,
      91,   137,    93,    93,    57,    25,    59,    60,     1,   920,
      71,    90,   142,    91,   103,    68,    96,   103,   899,   103,
      96,   103,   103,   934,    85,   125,   103,   114,   142,     8,
     103,    49,   106,   164,   103,   103,   103,    91,    93,   920,
     139,    94,    50,   153,   103,   119,   107,    93,    56,   164,
     153,   142,   142,   934,    91,   870,   114,   155,   119,   137,
     121,   171,   103,    41,   102,   125,   131,   195,   171,   164,
     144,   114,   171,   106,   148,    91,   204,   151,   219,   109,
     145,   196,    60,   193,   122,    93,    91,   142,   142,   188,
     193,   191,     9,    10,   181,   179,   185,   183,   172,   178,
     182,   181,  1398,     5,   185,   142,   124,     9,   185,   211,
     183,   313,   927,   182,   182,   182,   247,   248,   933,   250,
     155,   137,   229,   182,   182,   155,  1021,  1022,  1103,    91,
     231,   191,   268,   972,  1037,   924,   267,   926,   268,   231,
     185,   182,   783,   784,  1315,  1157,   926,   249,   279,  1187,
     849,   850,   247,   248,   268,   250,  1037,   318,  1196,   948,
     321,   302,   257,   185,   185,  1375,   219,  1454,   185,  1248,
     246,  1628,   267,  1021,  1022,   813,  1537,   268,   268,   185,
     254,   185,    99,   259,   279,   261,   318,  1644,   208,   321,
     268,   170,   185,   781,   782,  1652,   272,   273,   274,   153,
     276,   118,   278,   120,   182,   251,   252,   212,   213,    32,
      33,   998,    35,    36,  1504,   103,   118,   171,   120,   665,
      24,   103,   227,   148,   385,   386,   128,   103,   103,  1110,
     391,   148,    55,   103,   395,   152,   397,   131,  1149,   103,
       9,   402,   564,   565,  1540,   561,   148,   172,   409,   148,
     212,   213,   169,    41,    23,    93,    44,   318,   186,   187,
     321,   422,    42,  1174,    93,   227,    29,   428,  1149,   126,
     718,   432,   189,   721,    28,    93,   722,  1064,   439,   148,
     441,   442,   443,   444,   445,  1581,   109,  1458,    76,   450,
     207,   109,    46,  1174,   182,    58,   148,   458,  1113,   151,
     182,   195,   106,   172,   142,    37,   182,   182,     9,    10,
     264,    43,   182,    91,   102,   119,    48,   271,   182,    24,
       5,   211,   151,   103,     9,   386,    41,   281,   185,    44,
     391,   151,   155,   151,   395,    67,   397,  1375,    93,  1314,
     144,   402,  1122,  1132,   148,    64,   143,   151,   409,   118,
      69,   120,   204,  1248,   109,   149,   517,   151,    28,   249,
     129,   422,  1257,   160,  1005,  1006,  1007,   428,   172,  1280,
     148,   432,     9,  1268,  1545,   163,    46,   258,   439,   148,
     441,   442,   443,   444,   445,   546,    23,   102,   269,   450,
     423,   214,   425,   554,   427,   114,   151,   458,    99,  1280,
    1248,   106,  1297,   436,  1005,  1006,  1007,   440,  1579,  1257,
     117,    91,   148,   446,   119,   448,   449,   118,   451,   120,
    1268,   258,     9,    10,   457,   871,   872,   629,   630,   264,
     876,   163,   269,   118,   166,   120,   271,   215,   216,   144,
     913,   148,   915,   128,   151,    44,   281,   148,   163,   181,
     113,   152,   132,   242,   243,   143,   517,   137,   219,   781,
     221,   907,    61,   148,    63,   861,  1478,   177,   169,  1640,
     786,  1642,   160,    72,   206,   294,   265,   873,   141,   263,
     190,   118,   114,   120,   303,   546,   270,  1658,   189,   151,
     523,   154,   129,   554,   967,   656,   969,   658,     9,    10,
     661,   534,    50,   153,  1558,  1559,   207,    92,    56,   108,
     219,   148,    99,   161,   114,   224,   132,   102,   151,   132,
     553,   171,   683,   684,   685,   188,    74,   112,   132,   177,
    1425,   118,   148,   120,  1373,   148,    93,   122,  1377,   151,
    1594,   177,    96,    96,   148,    93,  1600,    91,   709,   226,
     711,   228,   109,  1333,   190,   109,   109,   718,   102,   132,
     721,   148,  1259,   151,   137,   152,   114,   151,    50,   168,
     272,   273,   274,  1388,    56,   632,   278,  1425,   635,   320,
     132,   638,   169,   148,   325,   137,   151,  1228,    99,   148,
     151,   752,   151,   626,   215,   216,   217,   219,   631,   221,
     661,   148,   189,   148,   151,   117,   151,   118,   226,   120,
     228,   117,  1523,   117,  1525,   117,   295,   296,   123,   124,
     207,   117,   683,   684,   685,   114,   295,   296,   286,   287,
     123,   124,   117,  1023,  1294,   608,   609,   148,   615,   616,
     801,   152,  1523,  1554,  1525,   617,   618,   117,   709,   148,
     711,   117,  1491,   831,   832,  1494,   117,   718,   169,   117,
     721,  1445,  1446,   117,  1575,   148,   114,   210,   829,   830,
     831,   832,   429,  1554,   151,   148,   236,   219,   189,   237,
     236,   148,   715,   151,   114,     0,   162,    89,    47,   244,
      97,   752,    98,   194,  1575,   140,   207,   149,   151,   179,
     179,   179,    24,   864,    44,    44,  1152,    44,   147,   114,
     241,   744,   745,  1409,   288,   293,   293,   299,   879,  1416,
    1417,   114,   182,  1562,   148,  1540,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,   182,   148,   279,   279,
     801,   774,   151,   151,   148,   906,   182,    30,   151,    16,
     151,   151,   913,   208,   915,    24,   182,     3,   137,   920,
     225,   114,    68,   225,   163,    91,    91,   165,   829,   830,
     831,   832,    91,   934,   165,   144,   103,    24,   155,   103,
     155,   538,   539,   127,   541,   542,   543,   544,   122,  1235,
     151,   241,   127,   164,   551,   552,   294,   114,   179,   179,
     182,   103,    91,   864,   182,   179,   967,   179,   969,   182,
      41,    93,   569,   570,  1511,  1512,    93,   103,   879,   179,
     182,   137,   579,   580,   182,   196,   182,   182,   182,   179,
      44,   179,   179,   182,   148,    91,   179,   179,   137,   231,
      54,   182,    28,   219,   165,   906,   179,    61,   114,    63,
     179,   127,   913,   224,   915,  1016,   137,   180,    72,   920,
      24,    91,    76,   281,   221,   294,   114,   122,   148,   114,
     114,   142,   114,   934,  1571,    91,  1037,   127,   179,   249,
     637,   192,   155,   640,   127,    93,   114,   148,   137,   114,
     142,   179,    96,   107,   108,   109,    96,   148,    30,    24,
     179,   114,   114,  1349,   179,   114,   967,   148,   969,   240,
      76,   282,   283,   284,   285,   286,   103,   288,   289,   290,
     291,   292,   127,   103,   262,   253,   297,   151,   280,   962,
     135,   136,   151,   138,   151,   255,   139,    24,    24,    24,
     231,   146,   182,   221,   182,   150,   282,   152,   185,   281,
     164,   221,   157,   221,   168,  1016,  1402,   139,   142,   182,
    1121,   182,   122,  1124,   142,  1126,   142,   114,   114,   174,
      74,   301,   103,   179,   137,   182,  1037,   127,     7,  1140,
     182,   102,   196,   181,   185,   102,   179,  1020,  1149,   142,
     182,   227,   197,   198,   199,   200,   201,   202,  1159,   231,
     227,   227,    75,   277,   179,  1166,   245,   227,   182,   281,
     224,   245,   182,  1174,   182,    24,    24,    93,   179,   252,
     165,   121,   142,   142,    93,   179,   181,   179,    91,  1062,
     181,   266,  1193,   148,   182,   179,   179,    24,   103,   165,
     797,   182,   256,   142,    50,    91,   803,   137,   114,   191,
      91,    24,   103,  1214,   114,   114,  1217,   275,   181,   114,
    1121,   260,  1223,  1124,   191,  1126,  1227,   282,   282,   283,
     284,   285,   286,   191,   288,   289,   290,   291,   292,  1140,
     219,   179,  1115,   297,   298,   219,   181,    90,  1149,   300,
     178,   114,   114,   288,   191,   148,   114,   193,  1159,   282,
     182,   114,   239,   300,   300,  1166,   219,   301,  1068,   866,
     301,   301,   242,  1174,   242,   664,   245,   865,   414,  1280,
    1110,  1545,  1579,  1219,   416,   389,   416,   935,   435,   932,
    1121,  1164,  1193,  1159,  1343,  1244,   285,  1242,  1141,  1227,
    1012,  1166,  1239,  1171,  1175,   588,   640,  1180,   589,   517,
     306,  1312,   753,  1214,  1594,  1187,  1217,  1600,   832,  1104,
    1067,   426,  1223,   426,   915,   922,  1227,  1214,  1224,  1425,
    1422,  1022,  1257,  1031,  1268,   898,  1092,  1304,  1261,  1340,
    1341,  1448,    -1,  1258,    -1,    -1,    -1,    -1,    -1,   946,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   954,    -1,   956,
     957,    -1,    -1,  1364,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1374,   971,    -1,    -1,  1378,    -1,  1280,
      -1,    -1,    -1,    -1,    -1,   982,   983,   984,    -1,   986,
     987,   988,   989,   990,   991,    -1,   993,   994,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1312,    -1,    -1,    -1,  1012,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1340,
    1341,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    -1,    35,    36,  1054,    -1,    -1,
      -1,    -1,    -1,  1364,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1374,    54,    55,    -1,  1378,    -1,    -1,
      -1,    61,    -1,    63,    -1,    -1,  1487,    -1,    -1,    -1,
      -1,  1492,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,  1504,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1523,    -1,  1525,    -1,    -1,   107,   108,   109,
    1127,    -1,  1129,    -1,  1131,    -1,    -1,  1134,    -1,    -1,
    1541,    -1,  1139,  1544,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1554,  1151,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1161,  1162,  1567,    -1,    -1,    -1,
      -1,    -1,  1169,  1170,  1575,   155,    -1,    -1,    -1,    -1,
      -1,    -1,  1583,    -1,   164,    -1,  1487,  1588,   168,    -1,
      -1,  1492,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1504,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1615,    -1,   196,    -1,    -1,    -1,
      -1,    -1,  1523,    -1,  1525,    -1,    -1,    -1,    -1,  1226,
      -1,  1632,    -1,  1634,   214,    -1,    -1,    -1,    -1,    -1,
    1541,    -1,    -1,  1544,   224,  1242,  1647,    -1,  1521,    -1,
    1651,    -1,    -1,  1554,    -1,  1656,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1567,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1575,    -1,   256,    -1,    -1,    -1,
      -1,    -1,  1583,    -1,    -1,    -1,    -1,  1588,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   282,   283,   284,   285,   286,    -1,   288,   289,
     290,   291,   292,    -1,  1615,    -1,    -1,   297,   298,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1326,
      -1,  1632,    -1,  1634,  1331,    -1,    -1,    -1,  1335,    -1,
    1337,    -1,  1339,    -1,    -1,    -1,  1647,    -1,  1345,    -1,
    1651,    -1,    -1,    -1,    -1,  1656,    -1,  1354,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1362,  1363,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1381,  1382,  1383,  1384,  1385,    -1,
    1387,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1465,    -1,
    1467,    -1,    -1,  1470,    -1,    -1,    -1,    -1,    -1,    -1,
    1477,    -1,    -1,    -1,    -1,  1482,    -1,    -1,    -1,  1486,
      -1,  1488,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1501,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1548,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1566,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1590,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1613,    -1,    -1,    -1,
      -1,  1618,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    19,    20,    21,    22,    -1,    24,    -1,    -1,
    1637,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    -1,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    -1,    -1,   101,   102,    -1,    -1,    -1,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
      -1,    -1,   119,    -1,   121,   122,   123,   124,    -1,   126,
      -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,   146,
     147,    -1,    -1,    -1,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,   169,    -1,   171,   172,    -1,    -1,   175,   176,
     177,    -1,    -1,    -1,   181,    -1,   183,   184,    -1,   186,
     187,   188,    -1,   190,    -1,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,    -1,    -1,   205,   206,
     207,    -1,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,    -1,   254,   255,   256,
      -1,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    -1,    24,    -1,    -1,    -1,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    91,
      92,    93,    94,    95,    96,    97,    98,    -1,    -1,   101,
     102,    -1,    -1,    -1,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,    -1,    -1,   119,    -1,   121,
     122,   123,   124,    -1,   126,    -1,    -1,    -1,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,   151,
     152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,   169,    -1,   171,
     172,    -1,    -1,   175,   176,   177,    -1,   179,    -1,   181,
      -1,   183,   184,    -1,   186,   187,   188,    -1,   190,    -1,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,    -1,    -1,   205,   206,   207,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,    -1,   254,   255,   256,    -1,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    -1,    24,    -1,    -1,    -1,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    91,    92,    93,    94,    95,    96,    97,
      98,    -1,    -1,   101,   102,    -1,    -1,    -1,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,    -1,
      -1,   119,    -1,   121,   122,   123,   124,    -1,   126,    -1,
      -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,    -1,    -1,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,   169,    -1,   171,   172,    -1,    -1,   175,   176,   177,
      -1,   179,    -1,   181,    -1,   183,   184,    -1,   186,   187,
     188,    -1,   190,    -1,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,    -1,    -1,   205,   206,   207,
      -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,    -1,   254,   255,   256,    -1,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    -1,
      24,    -1,    -1,    -1,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    -1,    -1,   101,   102,    -1,
      -1,    -1,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,    -1,    -1,   119,    -1,   121,   122,   123,
     124,    -1,   126,    -1,    -1,    -1,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,   151,   152,   153,
     154,   155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,   169,    -1,   171,   172,    -1,
      -1,   175,   176,   177,    -1,   179,    -1,   181,    -1,   183,
     184,    -1,   186,   187,   188,    -1,   190,    -1,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,    -1,
      -1,   205,   206,   207,    -1,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,    -1,
     254,   255,   256,    -1,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    -1,    24,    -1,    -1,    -1,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    -1,
      -1,   101,   102,    -1,    -1,    -1,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,    -1,    -1,   119,
      -1,   121,   122,   123,   124,    -1,   126,    -1,    -1,    -1,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,    -1,
      -1,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,   169,
      -1,   171,   172,    -1,    -1,   175,   176,   177,    -1,    -1,
      -1,   181,   182,   183,   184,    -1,   186,   187,   188,    -1,
     190,    -1,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,    -1,    -1,   205,   206,   207,    -1,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,    -1,   254,   255,   256,    -1,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    -1,    24,    -1,
      -1,    -1,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    -1,    -1,   101,   102,    -1,    -1,    -1,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,    -1,    -1,   119,    -1,   121,   122,   123,   124,    -1,
     126,    -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,   151,   152,   153,   154,   155,
      -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,   169,    -1,   171,   172,    -1,    -1,   175,
     176,   177,    -1,   179,    -1,   181,    -1,   183,   184,    -1,
     186,   187,   188,    -1,   190,    -1,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,    -1,    -1,   205,
     206,   207,    -1,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,    -1,   254,   255,
     256,    -1,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    -1,    24,    -1,    -1,    -1,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    91,
      92,    93,    94,    95,    96,    97,    98,    -1,    -1,   101,
     102,    -1,    -1,    -1,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,    -1,    -1,   119,    -1,   121,
     122,   123,   124,    -1,   126,    -1,    -1,    -1,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,   151,
     152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,   169,    -1,   171,
     172,    -1,    -1,   175,   176,   177,    -1,    -1,    -1,   181,
     182,   183,   184,    -1,   186,   187,   188,    -1,   190,    -1,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,    -1,    -1,   205,   206,   207,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,    -1,   254,   255,   256,    -1,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    -1,    24,    -1,    -1,    -1,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    91,    92,    93,    94,    95,    96,    97,
      98,    -1,    -1,   101,   102,    -1,    -1,    -1,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,    -1,
      -1,   119,    -1,   121,   122,   123,   124,    -1,   126,    -1,
      -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,    -1,    -1,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,   169,    -1,   171,   172,    -1,    -1,   175,   176,   177,
      -1,    -1,    -1,   181,   182,   183,   184,    -1,   186,   187,
     188,    -1,   190,    -1,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,    -1,    -1,   205,   206,   207,
      -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,    -1,   254,   255,   256,    -1,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    -1,
      24,    -1,    -1,    -1,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    -1,    -1,   101,   102,    -1,
      -1,    -1,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,    -1,    -1,   119,    -1,   121,   122,   123,
     124,    -1,   126,    -1,    -1,    -1,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,   151,   152,   153,
     154,   155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,   169,    -1,   171,   172,    -1,
      -1,   175,   176,   177,    -1,   179,    -1,   181,    -1,   183,
     184,    -1,   186,   187,   188,    -1,   190,    -1,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,    -1,
      -1,   205,   206,   207,    -1,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,    -1,
     254,   255,   256,    -1,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    -1,    24,    -1,    -1,    -1,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    -1,
      -1,   101,   102,    -1,    -1,    -1,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,    -1,    -1,   119,
      -1,   121,   122,   123,   124,    -1,   126,    -1,    -1,    -1,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,    -1,
      -1,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,   169,
      -1,   171,   172,    -1,    -1,   175,   176,   177,    -1,   179,
      -1,   181,    -1,   183,   184,    -1,   186,   187,   188,    -1,
     190,    -1,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,    -1,    -1,   205,   206,   207,    -1,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,    -1,   254,   255,   256,    -1,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    -1,    24,    -1,
      -1,    -1,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    -1,    -1,   101,   102,    -1,    -1,    -1,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,    -1,    -1,   119,    -1,   121,   122,   123,   124,    -1,
     126,    -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,   151,   152,   153,   154,   155,
      -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,   169,    -1,   171,   172,    -1,    -1,   175,
     176,   177,    -1,   179,    -1,   181,    -1,   183,   184,    -1,
     186,   187,   188,    -1,   190,    -1,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,    -1,    -1,   205,
     206,   207,    -1,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,    -1,   254,   255,
     256,    -1,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    -1,    24,    -1,    -1,    -1,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    91,
      92,    93,    94,    95,    96,    97,    98,    -1,    -1,   101,
     102,    -1,    -1,    -1,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,    -1,    -1,   119,    -1,   121,
     122,   123,   124,    -1,   126,    -1,    -1,    -1,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,   151,
     152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,   169,    -1,   171,
     172,    -1,    -1,   175,   176,   177,    -1,    -1,    -1,   181,
      -1,   183,   184,    -1,   186,   187,   188,    -1,   190,    -1,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,    -1,    -1,   205,   206,   207,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,    -1,   254,   255,   256,    -1,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    -1,    24,    -1,    -1,    -1,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    91,    92,    93,    94,    95,    96,    97,
      98,    -1,    -1,   101,   102,    -1,    -1,    -1,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,    -1,
      -1,   119,    -1,   121,   122,   123,   124,    -1,   126,    -1,
      -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,    -1,    -1,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,   169,    -1,   171,   172,    -1,    -1,   175,   176,   177,
      -1,    -1,    -1,   181,    -1,   183,   184,    -1,   186,   187,
     188,    -1,   190,    -1,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,    -1,    -1,   205,   206,   207,
      -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,    -1,   254,   255,   256,    -1,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    -1,
      24,    -1,    -1,    -1,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    -1,    -1,   101,   102,    -1,
      -1,    -1,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,    -1,    -1,   119,    -1,   121,   122,   123,
     124,    -1,   126,    -1,    -1,    -1,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,   151,   152,   153,
     154,   155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,   169,    -1,   171,   172,    -1,
      -1,   175,   176,   177,    -1,    -1,    -1,   181,    -1,   183,
     184,    -1,   186,   187,   188,    -1,   190,    -1,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,    -1,
      -1,   205,   206,   207,    -1,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,    -1,
     254,   255,   256,    -1,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    -1,    24,    -1,    -1,    -1,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    -1,
      -1,   101,   102,    -1,    -1,    -1,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,    -1,    -1,   119,
      -1,   121,   122,   123,   124,    -1,   126,    -1,    -1,    -1,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,    -1,
      -1,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,   169,
      -1,   171,   172,    -1,    -1,   175,   176,   177,    -1,    -1,
      -1,   181,    -1,   183,   184,    -1,   186,   187,   188,    -1,
     190,    -1,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,    -1,    -1,   205,   206,   207,    -1,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,    -1,   254,   255,   256,    -1,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    -1,    24,    -1,
      -1,    -1,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    -1,    -1,   101,   102,    -1,    -1,    -1,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,    -1,    -1,   119,    -1,   121,   122,   123,   124,    -1,
     126,    -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,   151,   152,   153,   154,   155,
      -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,   169,    -1,   171,   172,    -1,    -1,   175,
     176,   177,    -1,    -1,    -1,   181,    -1,   183,   184,    -1,
     186,   187,   188,    -1,   190,    -1,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,    -1,    -1,   205,
     206,   207,    -1,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,    -1,   254,   255,
     256,    -1,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    -1,    24,    -1,    -1,    -1,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    91,
      92,    93,    94,    95,    96,    97,    98,    -1,    -1,   101,
     102,    -1,    -1,    -1,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,    -1,    -1,   119,    -1,   121,
     122,   123,   124,    -1,   126,    -1,    -1,    -1,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,   151,
     152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,   169,    -1,   171,
     172,    -1,    -1,   175,   176,   177,    -1,    -1,    -1,   181,
      -1,   183,   184,    -1,   186,   187,   188,    -1,   190,    -1,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,    -1,    -1,   205,   206,   207,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,    -1,   254,   255,   256,    -1,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    -1,    24,    -1,    -1,    -1,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    91,    92,    93,    94,    95,    96,    97,
      98,    -1,    -1,   101,   102,    -1,    -1,    -1,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,    -1,
      -1,   119,    -1,   121,   122,   123,   124,    -1,   126,    -1,
      -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,    -1,    -1,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,   169,    -1,   171,   172,    -1,    -1,   175,   176,   177,
      -1,    -1,    -1,   181,    -1,   183,   184,    -1,   186,   187,
     188,    -1,   190,    -1,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,    -1,    -1,   205,   206,   207,
      -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,    -1,   254,   255,   256,    -1,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    -1,
      24,    -1,    -1,    -1,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    -1,    -1,   101,   102,    -1,
      -1,    -1,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,    -1,    -1,   119,    -1,   121,   122,   123,
     124,    -1,   126,    -1,    -1,    -1,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,   151,   152,   153,
     154,   155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,   169,    -1,   171,   172,    -1,
      -1,   175,   176,   177,    -1,    -1,    -1,   181,    -1,   183,
     184,    -1,   186,   187,   188,    -1,   190,    -1,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,    -1,
      -1,   205,   206,   207,    -1,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,    -1,
     254,   255,   256,    -1,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    -1,    24,    -1,    -1,    -1,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    -1,
      -1,   101,   102,    -1,    -1,    -1,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,    -1,    -1,   119,
      -1,   121,   122,   123,   124,    -1,   126,    -1,    -1,    -1,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,    -1,
      -1,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,   151,   152,    -1,   154,   155,    -1,    -1,    -1,    -1,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,   169,
      -1,    -1,    -1,    -1,    -1,   175,   176,   177,    -1,    -1,
      -1,   181,    -1,   183,   184,    -1,   186,   187,   188,    -1,
     190,    -1,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,    -1,    -1,   205,   206,   207,    -1,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,    -1,   254,   255,   256,    -1,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    -1,    24,    -1,
      -1,    -1,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    -1,    -1,   101,   102,    -1,    -1,    -1,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,    -1,    -1,   119,    -1,   121,   122,   123,   124,    -1,
     126,    -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,   151,   152,    -1,   154,   155,
      -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,   169,    -1,    -1,    -1,    -1,    -1,   175,
     176,   177,    -1,    -1,    -1,   181,    -1,   183,   184,    -1,
      -1,    -1,   188,    -1,   190,    -1,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,    -1,    -1,   205,
     206,   207,    -1,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,    -1,   254,   255,
     256,    -1,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    91,
      92,    93,    94,    -1,    96,    97,    98,    -1,    -1,   101,
     102,    -1,    -1,    -1,    -1,   107,   108,   109,   110,   111,
     112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,   123,   124,    -1,   126,    -1,    -1,    -1,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,    -1,    -1,   141,
     142,   143,    -1,   145,   146,   147,    -1,    -1,    -1,    -1,
      -1,    -1,   154,   155,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   175,   176,   177,    -1,    -1,    -1,   181,
      -1,   183,   184,    -1,    -1,    -1,   188,    -1,   190,    -1,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,    -1,    -1,   205,   206,    -1,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,    -1,   254,   255,   256,    -1,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    91,    92,    93,    94,    -1,    96,    97,
      98,    -1,    -1,   101,   102,    -1,    -1,    -1,    -1,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,   123,   124,    -1,   126,    -1,
      -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,    -1,    -1,   141,   142,   143,    -1,   145,   146,   147,
      -1,    -1,    -1,    -1,    -1,    -1,   154,   155,    -1,    -1,
      -1,    -1,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,   176,   177,
      -1,    -1,    -1,   181,    -1,   183,   184,    -1,    -1,    -1,
     188,    -1,   190,    -1,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,    -1,    -1,   205,   206,    -1,
      -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,    -1,   254,   255,   256,    -1,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    24,    -1,    -1,    -1,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    91,    92,    93,    94,    -1,    96,    97,
      98,    -1,    -1,   101,   102,    -1,    -1,    -1,    -1,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,   123,   124,    -1,   126,    -1,
      -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,    -1,    -1,   141,   142,   143,    -1,   145,   146,   147,
      -1,    -1,    -1,    -1,    -1,    -1,   154,   155,    -1,    -1,
      -1,    -1,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,   176,   177,
      -1,    -1,    -1,   181,   182,   183,   184,    -1,    -1,    -1,
      -1,    -1,   190,    -1,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,    -1,    -1,   205,   206,    -1,
      -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,    -1,   254,   255,   256,    -1,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    91,    92,    93,    94,    -1,    96,    97,
      98,    -1,    -1,   101,   102,    -1,    -1,    -1,    -1,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,   123,   124,    -1,   126,    -1,
      -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,    -1,    -1,   141,   142,   143,    -1,   145,   146,   147,
      -1,    -1,    -1,    -1,    -1,    -1,   154,   155,    -1,    -1,
      -1,    -1,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,   176,   177,
      -1,    -1,    -1,   181,    -1,   183,   184,    -1,    -1,    -1,
      -1,    -1,   190,    -1,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,    -1,    -1,   205,   206,    -1,
      -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,    -1,   254,   255,   256,    -1,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,    17,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      -1,    91,    92,    93,    94,    -1,    96,    97,    98,    -1,
      -1,   101,   102,    -1,    -1,    -1,    -1,   107,   108,   109,
     110,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,   123,   124,    -1,   126,    -1,    -1,    -1,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,    -1,
      -1,   141,   142,   143,    -1,   145,   146,   147,    -1,    -1,
      -1,    -1,    -1,    -1,   154,   155,    -1,    -1,    -1,    -1,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   175,   176,   177,    -1,    -1,
      -1,   181,    -1,   183,   184,    -1,    -1,    -1,    -1,    -1,
     190,    -1,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,    -1,    -1,   205,   206,    -1,    -1,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,    -1,   254,   255,   256,    -1,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,    22,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    -1,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    91,    92,    93,    94,    -1,    96,
      97,    98,    -1,    -1,   101,   102,    -1,    -1,    -1,    -1,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,   122,   123,   124,    -1,   126,
      -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,    -1,    -1,   141,   142,   143,    -1,   145,   146,
     147,    -1,    -1,    -1,   151,    -1,    -1,   154,   155,    -1,
      -1,    -1,    -1,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,   176,
     177,    -1,    -1,    -1,   181,   182,   183,   184,    -1,    -1,
      -1,   188,    -1,   190,    -1,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,    -1,    -1,   205,   206,
      -1,    -1,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,    -1,   254,   255,   256,
      -1,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,    22,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,    91,    92,    93,
      94,    -1,    96,    97,    98,    -1,    -1,   101,   102,    -1,
      -1,    -1,    -1,   107,   108,   109,   110,   111,   112,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,
     124,    -1,   126,    -1,    -1,    -1,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,
      -1,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,
     154,   155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   175,   176,   177,    -1,    -1,    -1,   181,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,   190,    -1,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,    -1,
      -1,   205,   206,    -1,    -1,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,    -1,
     254,   255,   256,    -1,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,    22,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      91,    92,    93,    94,    -1,    96,    97,    98,    -1,    -1,
     101,   102,    -1,    -1,    -1,    -1,   107,   108,   109,   110,
     111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,   122,   123,   124,    -1,   126,    -1,    -1,    -1,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,    -1,    -1,
     141,   142,   143,    -1,   145,   146,   147,    -1,    -1,    -1,
      -1,    -1,    -1,   154,   155,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   175,   176,   177,    -1,    -1,    -1,
     181,   182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,
      -1,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,    -1,    -1,   205,   206,    -1,    -1,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,    -1,   254,   255,   256,    -1,   258,   259,   260,
     261,   262,   263,    -1,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,    22,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    91,    92,    93,    94,    -1,    96,    97,
      98,    -1,    -1,   101,   102,    -1,    -1,    -1,    -1,   107,
     108,   109,   110,   111,   112,   113,   114,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,   123,   124,    -1,   126,    -1,
      -1,    -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,    -1,    -1,   141,   142,   143,    -1,   145,   146,   147,
      -1,    -1,    -1,   151,    -1,    -1,   154,   155,    -1,    -1,
      -1,    -1,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,   176,   177,
      -1,    -1,    -1,   181,    -1,   183,   184,    -1,    -1,    -1,
      -1,    -1,   190,    -1,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,    -1,    -1,   205,   206,    -1,
      -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,    -1,   254,   255,   256,    -1,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,    22,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    91,    92,    93,    94,
      -1,    96,    97,    98,    -1,    -1,   101,   102,    -1,    -1,
      -1,    -1,   107,   108,   109,   110,   111,   112,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,
      -1,   126,    -1,    -1,    -1,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,    -1,
     145,   146,   147,    -1,    -1,    -1,   151,    -1,    -1,   154,
     155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     175,   176,   177,    -1,    -1,    -1,   181,    -1,   183,   184,
      -1,    -1,    -1,    -1,    -1,   190,    -1,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,    -1,    -1,
     205,   206,    -1,    -1,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,    -1,   254,
     255,   256,    -1,   258,   259,   260,   261,   262,   263,    -1,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
      22,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    91,
      92,    93,    94,    -1,    96,    97,    98,    -1,    -1,   101,
     102,    -1,    -1,    -1,    -1,   107,   108,   109,   110,   111,
     112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,   123,   124,    -1,   126,    -1,    -1,    -1,   130,   131,
     132,   133,   134,    -1,    -1,    -1,    -1,    -1,    -1,   141,
     142,   143,    -1,   145,   146,   147,    -1,    -1,    -1,   151,
      -1,    -1,   154,   155,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   175,   176,   177,    -1,    -1,    -1,   181,
      -1,   183,   184,    -1,    -1,    -1,    -1,    -1,   190,    -1,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,    -1,    -1,   205,   206,    -1,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,    -1,   254,   255,   256,    -1,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,    22,    -1,    -1,    -1,    -1,    -1,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    91,    92,    93,    94,    -1,    96,    97,    98,
      -1,    -1,   101,   102,    -1,    -1,    -1,    -1,   107,   108,
     109,   110,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,   122,   123,   124,    -1,   126,    -1,    -1,
      -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
      -1,    -1,   141,   142,   143,    -1,   145,   146,   147,    -1,
      -1,    -1,    -1,    -1,    -1,   154,   155,    -1,    -1,    -1,
      -1,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   175,   176,   177,    -1,
      -1,    -1,   181,    -1,   183,   184,    -1,    -1,    -1,    -1,
      -1,   190,    -1,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,    -1,    -1,   205,   206,    -1,    -1,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,    -1,   254,   255,   256,    -1,   258,
     259,   260,   261,   262,   263,    -1,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,    22,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    31,    32,    33,    -1,    35,
      36,    37,    38,    39,    -1,    -1,    42,    43,    44,    -1,
      46,    47,    48,    49,    50,    -1,    52,    53,    54,    55,
      56,    -1,    58,    -1,    -1,    61,    62,    63,    64,    65,
      -1,    67,    -1,    69,    -1,    -1,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    -1,    91,    92,    93,    -1,    -1,
      96,    97,    98,    -1,    -1,   101,   102,    -1,    -1,    -1,
      -1,   107,   108,   109,   110,   111,   112,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,    -1,
     126,    -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,    -1,    -1,   141,   142,   143,    -1,   145,
     146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,   155,
      -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,
     176,   177,    -1,    -1,    -1,   181,    -1,   183,   184,    -1,
      -1,    -1,    -1,    -1,   190,    -1,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,    -1,    -1,    -1,
     206,    -1,    -1,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,    -1,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,    -1,   254,   255,
     256,    -1,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    11,    18,    19,    20,    21,    22,    24,    28,    29,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    91,    92,    93,
      94,    95,    96,    97,    98,   101,   102,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   119,   121,
     122,   123,   124,   126,   130,   131,   132,   133,   134,   141,
     142,   143,   144,   145,   146,   147,   151,   152,   153,   154,
     155,   160,   161,   162,   163,   164,   165,   166,   167,   169,
     171,   172,   175,   176,   177,   181,   183,   184,   186,   187,
     188,   190,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   205,   206,   207,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     254,   255,   256,   258,   259,   260,   261,   262,   263,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     320,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   350,   351,   355,   356,   359,   362,
     365,   366,   368,   373,   374,   375,   376,   380,   389,   390,
     392,   393,   394,   399,   401,   403,   404,   409,   430,   433,
     437,   440,   441,   442,   443,   445,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   491,   492,   493,   507,   508,
     510,   511,   512,   513,   514,   515,   516,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   536,   537,   538,
     539,   544,   545,   546,   547,   548,   549,   552,   556,   612,
     613,    28,    29,    46,   179,   209,   390,   179,   390,   179,
     390,    32,    33,    35,    36,    44,    54,    55,    61,    63,
      72,    76,   107,   108,   109,   155,   164,   168,   196,   214,
     224,   256,   282,   283,   284,   285,   286,   288,   289,   290,
     291,   292,   297,   298,   357,   358,   377,   378,   381,   382,
     383,   384,   155,   148,   151,   148,   151,   148,   151,   148,
      64,    69,   114,   396,   151,   367,   151,    29,    58,   114,
     148,   151,   151,   151,   114,   114,   148,   151,   151,   151,
      91,   148,   215,   216,   117,   117,   117,   148,   151,    34,
      39,    41,    42,    43,    44,    45,    48,    57,    62,    65,
      68,    70,    71,    73,    87,    88,    94,   101,   110,   111,
     130,   133,   134,   164,   167,   175,   176,   184,   196,   218,
     220,   222,   223,   230,   232,   233,   234,   235,   238,   239,
     241,   475,   612,   613,   117,   117,   117,    34,    40,    41,
      57,    59,    60,    68,    94,   219,   612,   114,   117,   117,
     182,   390,   612,   148,   117,    15,   611,   612,    17,   612,
     117,   117,   117,   467,   148,    25,   208,   210,   219,   221,
     151,   219,   221,   219,   219,   224,   114,   148,   369,   236,
     236,   237,   151,   148,   114,   322,     0,   324,   325,    28,
      46,   327,   328,     1,   185,   321,   185,   321,   132,   137,
     103,   185,   391,    37,    43,    48,    67,   163,   166,   181,
     206,   395,   400,   401,   402,   418,   419,   423,   162,    89,
     127,   135,   136,   138,   146,   150,   152,   157,   174,   197,
     198,   199,   200,   201,   202,   459,   460,   244,   153,   171,
     193,   113,   141,   154,   188,   195,   204,   131,   145,    47,
     194,    97,    98,   153,   171,   458,   148,   464,   467,   186,
     187,   149,   479,   480,   475,   479,   475,   151,   479,   140,
     151,   179,   179,   179,    24,   610,   177,   190,   177,   190,
     161,   177,   613,   612,   164,   196,    44,   382,    44,   612,
     147,   114,    41,    44,    76,   102,   163,   611,   612,   215,
     216,   217,   295,   296,   241,   583,   612,   288,   612,   293,
     293,   295,   296,   299,   282,   290,   358,   108,   378,   381,
     611,   390,   182,   390,    41,    60,   182,   532,   533,   390,
     182,   188,   612,   393,   279,   279,   405,   406,   612,   114,
     413,   114,   182,   385,   386,   148,   387,   390,   155,   610,
     109,   155,   349,   610,   410,   412,   612,   390,    24,   182,
     611,   612,   612,   612,   431,   432,   612,   390,   182,   390,
     390,   534,   612,   390,   148,   148,   390,   182,   188,   612,
     431,   182,    30,   495,   496,   497,   390,     8,   170,    16,
     390,   208,    24,   393,   393,   182,   393,   393,   393,   393,
     225,   550,   551,   612,   370,   393,   393,   390,   411,   417,
     612,   185,   321,   185,   321,     3,   328,   329,   389,   328,
     329,   389,    28,   330,   389,   330,   389,   137,   393,   393,
     392,   114,   163,   165,   165,   393,   393,   442,   443,   445,
     445,   445,   445,   444,   445,   445,   445,    68,   449,   449,
     448,   450,   450,   450,   450,   451,   451,   452,   452,   225,
      91,    91,    91,   179,   390,   467,   467,   390,   480,   182,
     393,   490,   144,   182,   490,   103,   103,   367,    24,   613,
     613,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,   332,   333,   334,    91,   132,   137,   352,   353,   354,
     612,   155,   155,   332,   610,   122,   127,   151,    51,    54,
      96,   246,   259,   261,   272,   273,   274,   276,   278,   584,
     585,   586,   587,   588,   589,   596,   602,   603,   241,    91,
     231,   361,   294,   612,   612,   612,   114,   127,   179,   179,
     182,   182,   179,   103,   182,   103,   182,   179,   103,    31,
      91,    93,   142,   268,   407,   408,   518,   612,    53,   211,
     249,   397,   398,   612,    91,   103,   182,   390,   182,   611,
      93,    41,   611,   610,    93,   103,   137,   408,   518,   179,
     182,   182,   182,   182,   137,   103,   183,   142,   518,   179,
     182,   182,   148,   179,   390,   390,   179,   103,   182,   103,
     182,   183,   612,   496,   497,   125,   191,   179,   179,   126,
     185,    91,   212,   213,   227,    91,   212,   213,   227,    91,
     231,   219,   103,   229,   137,    28,   371,   390,   182,   179,
      42,   103,   328,    28,    28,   185,   321,   185,   109,   393,
     185,   612,   165,   393,   424,   425,   114,   420,   421,   445,
     148,   151,   254,   463,   482,   557,   560,   561,   562,   563,
     564,   568,   570,   572,   573,    44,   147,   151,   205,   519,
     521,   523,   524,   540,   541,   542,   543,   612,   519,   517,
     523,   517,   179,   180,   103,   182,   182,   143,   160,   143,
     160,   132,   148,   388,   367,   367,   333,   127,   521,   354,
     393,   518,   610,   610,   123,   124,   610,   379,   482,   272,
     273,   274,   278,   612,   258,   269,   258,   269,    24,   281,
      93,   109,   151,   590,   593,   584,    34,    40,    57,    59,
      68,    94,   219,   360,   524,   286,   287,   221,   294,   303,
      91,   361,   294,   612,   610,   148,   534,   535,   612,   534,
     535,   114,   122,   519,   114,   393,   114,   142,   408,   142,
      31,   142,   407,   408,   142,   518,   249,    50,    56,    74,
     114,   407,   414,   415,   416,   398,   518,   519,   386,    91,
     179,   192,   127,   348,   610,   155,   127,    93,   348,   114,
     393,   137,   137,   408,   148,   393,   114,   393,   393,   142,
      96,   434,   435,   436,    96,   438,   439,   390,   179,   179,
     148,   534,   534,   393,    30,   497,   125,   191,     9,    10,
      99,   118,   120,   189,   387,   492,   494,   505,   506,   509,
      24,   226,   228,   393,   393,   393,   226,   228,   393,   393,
     393,   393,   393,   393,   114,   393,   393,   114,   372,   103,
     185,   179,   369,   240,   553,   554,   148,   114,   185,   109,
     389,   389,   389,   424,    92,   102,   112,   122,   426,   427,
     428,   429,   103,   612,   103,   390,   557,   564,   148,   280,
     446,   609,    93,   164,   247,   248,   250,   257,   267,   279,
     558,   559,   578,   579,   580,   581,   604,   607,   253,   255,
     565,   583,   262,   569,   605,   242,   243,   265,   574,   575,
     151,   151,   521,   151,   139,   171,   188,   520,   139,   393,
     390,   132,   369,   132,   148,   536,   353,   103,   182,   281,
      24,    93,   109,   151,   597,    24,   590,   361,   520,   221,
     221,   465,   282,   301,   360,   221,   518,   185,   179,   390,
     182,   182,   139,   182,   182,   406,   142,   407,   612,   612,
     393,   142,   393,   122,   393,   142,   408,   142,   393,   142,
     114,   114,   393,   612,   416,    74,   519,   393,   610,   103,
     348,   412,   393,   393,   137,   179,   390,   432,   393,   393,
     109,   435,    96,   181,   114,   519,   109,   439,   179,   179,
     390,   182,   182,   127,   189,   494,     7,   612,   189,   505,
     185,   227,   227,   227,   227,   231,   551,   181,   612,   372,
     476,   555,   554,   393,   417,   610,   123,   124,   428,   429,
     429,   425,   102,   422,   421,   179,   182,   557,   571,   245,
     211,   249,   263,   270,   608,    93,   251,   252,   606,   245,
     561,   608,   448,   578,   562,   142,   277,   566,   567,   606,
     281,   577,    75,   576,   182,   188,   519,   522,   182,   182,
     182,   179,   392,   482,    24,   131,   195,   599,   600,   601,
      24,   598,   599,   266,   594,   591,   592,   593,   165,   612,
     252,   361,   465,   179,   393,   142,   393,   142,   407,   393,
     142,   393,   393,   612,   612,   415,   393,   121,    93,   610,
     393,   179,   181,   393,   393,   612,   181,   114,   181,   179,
     497,   612,   189,   497,   612,   393,   393,   393,   393,   393,
     393,   137,   518,   151,   204,   388,   179,   429,   610,   179,
     450,    49,   124,   448,   448,   264,   271,   281,   582,   582,
     563,   148,   275,    91,   182,   103,   182,   179,   597,   597,
     601,   103,   182,    24,   595,   606,   182,   103,   363,   364,
     465,   114,   219,   302,   282,   165,   393,   393,   142,   393,
      50,   393,   348,   393,    91,   393,   612,   393,    90,   178,
     498,   497,   612,   191,   497,   393,   137,   114,   476,   448,
     448,   193,   390,   519,   519,    91,    24,   260,   593,   103,
     429,   518,   612,   114,   219,   612,   363,   393,   114,   519,
     181,     5,   128,   501,   502,   504,   506,    23,   129,   499,
     500,   503,   506,   191,   497,   191,   393,   612,   448,   179,
     519,   364,   429,   300,   612,   114,   219,   612,   181,   393,
      90,   128,   504,   178,   129,   503,   191,   103,   182,   393,
     300,   612,   114,   393,   114,   388,   288,   300,   612,   612,
     301,   393,   301,   103,   182,   465,   465,   114,   388,   193,
     612,   282,   182,   612,   388,   219,   114,   612,   301,   465
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
     565,   566,   567,   568,   569,   570,   571,   572,   573
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   319,   320,   320,   321,   322,   322,   322,   322,   323,
     323,   324,   324,   324,   324,   324,   324,   324,   324,   325,
     325,   325,   325,   326,   327,   327,   327,   328,   328,   328,
     329,   329,   329,   329,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   331,   331,   332,   332,   333,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   335,   335,
     335,   335,   335,   335,   335,   335,   336,   336,   337,   338,
     338,   339,   339,   340,   341,   342,   342,   343,   343,   344,
     344,   344,   344,   345,   346,   347,   347,   347,   347,   348,
     348,   349,   349,   350,   350,   350,   350,   351,   352,   352,
     353,   353,   353,   354,   355,   355,   355,   355,   356,   356,
     356,   357,   357,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   359,   359,   359,
     359,   359,   359,   359,   359,   360,   360,   361,   361,   362,
     362,   363,   363,   364,   364,   364,   364,   365,   365,   365,
     365,   366,   366,   367,   367,   367,   367,   368,   369,   370,
     370,   371,   371,   372,   372,   372,   372,   373,   374,   375,
     376,   376,   377,   377,   378,   378,   379,   379,   380,   380,
     381,   381,   381,   381,   382,   382,   383,   383,   384,   384,
     385,   385,   386,   386,   387,   388,   389,   390,   390,   391,
     391,   392,   392,   393,   393,   393,   393,   393,   393,   393,
     393,   393,   393,   393,   393,   393,   393,   393,   393,   393,
     393,   394,   395,   396,   396,   397,   397,   397,   398,   398,
     399,   399,   400,   401,   401,   401,   402,   402,   402,   402,
     402,   403,   403,   404,   405,   405,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   407,   408,
     409,   410,   410,   411,   411,   412,   412,   412,   412,   413,
     413,   414,   414,   414,   415,   415,   415,   416,   416,   416,
     417,   418,   419,   420,   420,   421,   421,   422,   423,   423,
     424,   424,   425,   425,   426,   426,   426,   426,   426,   426,
     426,   427,   427,   428,   428,   429,   430,   430,   431,   431,
     432,   432,   433,   434,   434,   435,   436,   436,   437,   437,
     438,   438,   439,   439,   440,   441,   441,   442,   442,   443,
     443,   443,   443,   443,   444,   443,   443,   443,   443,   445,
     445,   446,   446,   447,   447,   448,   448,   448,   449,   449,
     449,   449,   449,   450,   450,   450,   451,   451,   451,   452,
     452,   453,   453,   454,   454,   455,   455,   456,   456,   457,
     457,   457,   457,   458,   458,   458,   459,   459,   459,   459,
     459,   459,   460,   460,   460,   461,   461,   461,   461,   462,
     462,   463,   463,   464,   464,   465,   465,   465,   465,   466,
     467,   467,   467,   468,   468,   469,   469,   469,   469,   470,
     470,   471,   471,   471,   471,   471,   471,   471,   472,   472,
     473,   473,   474,   474,   474,   474,   474,   475,   475,   476,
     476,   477,   477,   477,   478,   478,   478,   478,   479,   479,
     480,   481,   481,   481,   481,   481,   481,   481,   481,   481,
     482,   482,   483,   483,   483,   484,   485,   485,   486,   487,
     488,   489,   489,   490,   490,   491,   491,   492,   492,   492,
     493,   493,   493,   493,   493,   493,   494,   494,   495,   495,
     496,   497,   497,   498,   498,   499,   499,   500,   500,   500,
     500,   501,   501,   502,   502,   502,   502,   503,   503,   504,
     504,   505,   505,   505,   505,   506,   506,   506,   506,   507,
     507,   508,   508,   509,   510,   510,   510,   510,   510,   510,
     511,   512,   512,   512,   512,   513,   513,   513,   513,   514,
     515,   516,   516,   516,   516,   517,   517,   518,   519,   519,
     519,   520,   520,   520,   521,   521,   521,   521,   521,   522,
     522,   523,   524,   524,   524,   524,   524,   524,   524,   524,
     524,   525,   526,   526,   526,   527,   528,   529,   529,   529,
     530,   530,   530,   530,   530,   531,   532,   532,   532,   532,
     532,   532,   532,   533,   534,   535,   536,   537,   537,   538,
     539,   540,   540,   541,   542,   542,   543,   544,   544,   544,
     545,   545,   545,   545,   545,   545,   545,   545,   545,   545,
     546,   546,   547,   547,   548,   549,   550,   550,   551,   552,
     553,   553,   554,   554,   554,   554,   555,   555,   556,   556,
     557,   558,   558,   559,   559,   560,   560,   561,   561,   562,
     562,   563,   563,   564,   565,   565,   566,   566,   567,   568,
     568,   568,   569,   569,   570,   571,   571,   572,   573,   573,
     574,   574,   575,   575,   575,   576,   576,   577,   577,   578,
     578,   578,   578,   578,   579,   580,   581,   582,   582,   582,
     583,   583,   584,   584,   584,   584,   584,   584,   584,   584,
     585,   585,   585,   585,   586,   586,   587,   588,   588,   589,
     589,   589,   590,   590,   591,   591,   592,   592,   593,   594,
     594,   595,   595,   596,   596,   596,   597,   597,   598,   598,
     599,   599,   600,   600,   601,   601,   602,   603,   603,   604,
     604,   604,   605,   606,   606,   606,   606,   607,   607,   608,
     608,   609,   610,   611,   611,   612,   612,   612,   612,   612,
     612,   612,   612,   612,   612,   612,   612,   612,   612,   612,
     612,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     2,     1,     2,     1,     2,     4,
       6,     3,     3,     5,     1,     3,     3,     5,     5,     1,
       3,     3,     5,     6,     1,     3,     3,     1,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     3,
       3,     5,     5,     4,     3,     3,     3,     5,     5,     5,
       5,     5,     5,     4,     3,     3,     4,     5,     6,     1,
       3,     3,     3,     3,     6,     5,     8,     4,     3,     1,
       1,     1,     2,     2,     4,     5,     5,     6,     3,     2,
       4,     1,     2,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     1,     2,     2,     2,     3,     4,     5,
       6,     4,     5,     6,     7,     1,     2,     3,     3,     8,
       9,     1,     3,     1,     2,     2,     3,    11,    14,    13,
      22,     3,     3,     2,     3,     4,     5,     2,     4,     3,
       0,     3,     2,     2,     3,     4,     5,     5,     3,     5,
       2,     2,     1,     2,     2,     5,     1,     3,     2,     3,
       1,     2,     1,     1,     4,     4,     5,     5,     7,     5,
       1,     3,     2,     3,     3,     3,     1,     1,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     1,     2,     4,     3,
       5,     4,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     1,     4,     3,     5,     4,     6,
       4,     6,     5,     7,     4,     5,     5,     6,     3,     3,
       3,     1,     4,     1,     4,     3,     4,     4,     5,     4,
       5,     1,     2,     3,     1,     2,     1,     6,     3,     3,
       1,     2,     3,     1,     3,     2,     3,     2,     3,     4,
       1,     3,     1,     2,     1,     1,     1,     2,     2,     2,
       3,     1,     1,     2,     2,     2,     5,     5,     1,     4,
       3,     4,     8,     1,     2,     3,     2,     3,     8,    10,
       1,     2,     4,     7,     8,     1,     3,     1,     3,     1,
       3,     3,     3,     3,     0,     4,     3,     3,     3,     1,
       5,     0,     1,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       4,     1,     4,     1,     4,     1,     4,     1,     2,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     5,     5,     6,     3,
       4,     1,     2,     3,     2,     1,     2,     2,     1,     1,
       1,     3,     3,     1,     1,     1,     2,     1,     2,     2,
       1,     2,     2,     2,     2,     2,     2,     2,     1,     2,
       2,     1,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     4,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     3,     1,     4,
       4,     3,     4,     1,     3,     1,     1,     1,     1,     1,
       4,     5,     8,     9,     9,    10,     1,     2,     1,     2,
       6,     0,     1,     3,     3,     0,     1,     1,     1,     2,
       2,     0,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       4,     2,     3,     6,     7,     2,     3,     6,     7,     4,
       4,     2,     3,     6,     7,     1,     2,     2,     1,     2,
       3,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     4,     4,     3,     3,     3,     4,     4,
       3,     4,     6,     4,     6,     4,     3,     4,     6,     6,
       4,     6,     6,     4,     1,     2,     1,     1,     1,     3,
       3,     1,     1,     4,     5,     6,     3,     3,     3,     3,
       5,     7,     7,     5,     5,     5,     7,     7,     5,     5,
       3,     3,     5,     7,     5,     7,     1,     4,     3,     5,
       1,     2,     3,     7,    10,    13,     1,     3,     7,     4,
       2,     0,     1,     1,     2,     1,     3,     1,     3,     1,
       4,     1,     2,     3,     0,     1,     0,     1,     4,     2,
       3,     1,     0,     1,     4,     0,     1,     2,     1,     3,
       0,     1,     2,     2,     1,     0,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     1,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     2,     2,     3,     1,     2,     2,
       5,     2,     1,     1,     0,     1,     1,     3,     4,     0,
       2,     0,     2,     4,     4,     3,     2,     3,     1,     3,
       0,     1,     1,     2,     2,     2,     2,     1,     2,     2,
       2,     2,     3,     2,     3,     3,     4,     2,     2,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
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
       1
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
  "\"'&entity;'\"", "\"'comment literal'\"", "\"'pi <NCName {>'\"",
  "\"'NCName_sval'\"", "\"'pragma literal'\"", "\"'QName #)'\"",
  "\"'*:QName'\"", "\"'element QName {'\"", "\"'attribute QName {'\"",
  "\"'processing-instruction NCName {'\"", "\"'QName'\"",
  "\"'quote attribute content'\"", "\"'STRING'\"", "\"'XML comment'\"",
  "\"'URI'\"", "\"'NCName'\"", "\"'declare'\"", "\"'module'\"",
  "\"'<blank>'\"", "\"'allowing'\"", "\"'base-uri'\"",
  "\"'boundary-space'\"", "\"'comment'\"", "\"'construction'\"",
  "\"'copy-namespaces'\"", "\"'count'\"", "\"'deterministic'\"",
  "\"'document'\"", "\"'document-node'\"", "\"'element'\"", "\"'eval'\"",
  "\"'for'\"", "\"'function'\"", "\"'if'\"", "\"'import'\"",
  "\"'instance'\"", "\"'let'\"", "\"'most'\"", "\"'next'\"", "\"'no'\"",
  "\"'nondeterministic'\"", "\"'only'\"", "\"'option'\"", "\"'ordering'\"",
  "\"'previous'\"", "\"'processing-instruction'\"", "\"'schema'\"",
  "\"'schema-attribute'\"", "\"'schema-element'\"", "\"'sequential'\"",
  "\"'set'\"", "\"'simple'\"", "\"'sliding'\"", "\"'some'\"",
  "\"'space'\"", "\"'stable'\"", "\"'text'\"", "\"'tumbling'\"",
  "\"'switch'\"", "\"'typeswitch'\"", "\"'updating'\"", "\"'validate'\"",
  "\"'when'\"", "\"'word'\"", "\"'decimal-format'\"",
  "\"'decimal-separator'\"", "\"'grouping-separator'\"", "\"'infinity'\"",
  "\"'minus-sign'\"", "\"'NaN'\"", "\"'percent'\"", "\"'per-mille'\"",
  "\"'zero-digit'\"", "\"'digit'\"", "\"'pattern-separator'\"",
  "\"'ancestor'\"", "\"'ancestor-or-self'\"", "\"'and'\"", "\"'''\"",
  "\"'as'\"", "\"'ascending'\"", "\"'at'\"", "\"'attribute'\"", "\"'@'\"",
  "\"'case'\"", "\"'castable'\"", "\"'cast'\"", "\"'CDATA[['\"",
  "\"']]'\"", "\"'child'\"", "\"'collation'\"", "\"','\"", "\"'(:'\"",
  "\"':)'\"", "\"'DECIMAL'\"", "\"'context'\"", "\"'variable'\"",
  "\"'default'\"", "\"'descendant'\"", "\"'descendant-or-self'\"",
  "\"'descending'\"", "\"'div'\"", "\"'$'\"", "\"'.'\"", "\"'..'\"",
  "\"'::'\"", "\"'{{'\"", "\"'DOUBLE'\"", "\"'<double {>'\"", "\"'else'\"",
  "\"'empty'\"", "\"'greatest'\"", "\"'least'\"", "\"'/>'\"",
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
  "STEP_REDUCE", "$accept", "Module", "ERROR", "ModuleWithoutBOM",
  "VersionDecl", "MainModule", "LibraryModule", "ModuleDecl",
  "SIND_DeclList", "VFO_DeclList", "SIND_Decl", "VFO_Decl",
  "DecimalFormatDecl", "DecimalFormatParamList", "DecimalFormatParam",
  "DecimalFormatParamName", "Setter", "Import", "NamespaceDecl",
  "BoundarySpaceDecl", "DefaultNamespaceDecl", "OptionDecl",
  "FTOptionDecl", "OrderingModeDecl", "EmptyOrderDecl",
  "CopyNamespacesDecl", "DefaultCollationDecl", "BaseURIDecl",
  "SchemaImport", "URILiteralList", "SchemaPrefix", "ModuleImport",
  "CtxItemDecl", "CtxItemDecl2", "CtxItemDecl3", "CtxItemDecl4",
  "VarNameAndType", "VarDecl", "DeclPropertyList", "DeclProperty",
  "CollectionDecl", "CollectionTypeDecl", "NodeModifier", "IndexDecl",
  "IndexKeyList", "IndexKeySpec", "IntegrityConstraintDecl",
  "ConstructionDecl", "FunctionSig", "BlockExpr", "Block", "BlockDecls",
  "BlockVarDeclList", "BlockVarDecl", "AssignExpr", "ExitExpr",
  "WhileExpr", "FlowCtlStatement", "AnnotationList", "Annotation",
  "AnnotationLiteralList", "FunctionDecl", "FunctionDecl2",
  "FunctionDeclSimple", "FunctionDeclSequential", "FunctionDeclUpdating",
  "ParamList", "Param", "EnclosedExpr", "BracedExpr", "QueryBody", "Expr",
  "ApplyExpr", "ConcatExpr", "ExprSingle", "FLWORExpr", "ReturnExpr",
  "WindowType", "FLWORWinCondType", "FLWORWinCond", "WindowClause",
  "CountClause", "ForLetWinClause", "FLWORClause", "FLWORClauseList",
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
  "CatchListExpr", "CatchExpr", "NameTestList", "EvalExpr", "FTSelection",
  "opt_FTPosFilter_list", "FTPosFilter_list", "FTOr", "FTAnd", "FTMildNot",
  "FTUnaryNot", "FTPrimaryWithOptions", "opt_FTMatchOptions",
  "opt_FTWeight", "FTWeight", "FTPrimary", "opt_FTTimes",
  "FTExtensionSelection", "opt_FTSelection", "FTWords", "FTWordsValue",
  "opt_FTAnyallOption", "FTAnyallOption", "opt_word", "opt_words",
  "FTPosFilter", "FTOrder", "FTWindow", "FTDistance", "FTUnit",
  "FTMatchOptions", "FTMatchOption", "FTCaseOption", "FTDiacriticsOption",
  "FTExtensionOption", "FTStemOption", "FTThesaurusOption",
  "FTThesaurusID_or_default", "opt_FTThesaurus_list", "FTThesaurus_list",
  "FTThesaurusID", "opt_relationship", "opt_levels", "FTStopWordOption",
  "FTStopWords", "STRING_LITERAL_list", "opt_FTStopWordsInclExcl_list",
  "FTStopWordsInclExcl_list", "FTStopWordsInclExcl", "FTLanguageOption",
  "FTWildCardOption", "FTContent", "FTTimes", "FTRange", "FTScope",
  "FTBigUnit", "FTIgnoreOption", "URI_LITERAL", "NCNAME", "QNAME",
  "FUNCTION_NAME", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       320,     0,    -1,   322,    -1,   305,   322,    -1,     1,     3,
      -1,   324,    -1,   323,   324,    -1,   325,    -1,   323,   325,
      -1,   209,   210,    24,   185,    -1,   209,   210,    24,   126,
      24,   185,    -1,   327,   185,   389,    -1,   328,   185,   389,
      -1,   327,   185,   328,   185,   389,    -1,   389,    -1,   327,
     321,   389,    -1,   328,   321,   389,    -1,   327,   185,   328,
     321,   389,    -1,   327,   321,   328,   185,   389,    -1,   326,
      -1,   326,   327,   185,    -1,   326,   328,   185,    -1,   326,
     327,   185,   328,   185,    -1,    29,   155,   611,   127,   610,
     185,    -1,   329,    -1,   327,   185,   329,    -1,   327,   321,
     329,    -1,   330,    -1,   328,   185,   330,    -1,   328,   321,
     330,    -1,   335,    -1,   336,    -1,   337,    -1,   339,    -1,
     356,    -1,   359,    -1,   351,    -1,   331,    -1,   341,    -1,
     380,    -1,   362,    -1,   365,    -1,   340,    -1,    28,   109,
      76,   332,    -1,    28,    76,   612,   332,    -1,   333,    -1,
     332,   333,    -1,   334,   127,   536,    -1,    77,    -1,    85,
      -1,    78,    -1,    79,    -1,    80,    -1,    81,    -1,    86,
      -1,    82,    -1,    83,    -1,    84,    -1,   338,    -1,   345,
      -1,   346,    -1,   366,    -1,   342,    -1,   343,    -1,   344,
      -1,   544,    -1,   347,    -1,   350,    -1,    28,   155,   611,
     127,   610,    -1,    28,    33,   177,    -1,    28,    33,   190,
      -1,    28,   109,    41,   155,   610,    -1,    28,   109,    44,
     155,   610,    -1,    28,    54,   612,    24,    -1,    28,   256,
     583,    -1,    28,    55,   164,    -1,    28,    55,   196,    -1,
      28,   109,   163,   122,   123,    -1,    28,   109,   163,   122,
     124,    -1,    28,    36,   177,   103,   143,    -1,    28,    36,
     177,   103,   160,    -1,    28,    36,   161,   103,   143,    -1,
      28,    36,   161,   103,   160,    -1,    28,   109,   102,   610,
      -1,    28,    32,   610,    -1,    46,    58,   610,    -1,    46,
      58,   349,   610,    -1,    46,    58,   610,    93,   348,    -1,
      46,    58,   349,   610,    93,   348,    -1,   610,    -1,   348,
     103,   610,    -1,   155,   611,   127,    -1,   109,    41,   155,
      -1,    46,    29,   610,    -1,    46,    29,   155,   611,   127,
     610,    -1,    46,    29,   610,    93,   348,    -1,    46,    29,
     155,   611,   127,   610,    93,   348,    -1,    28,   107,   147,
     352,    -1,    91,   521,   353,    -1,   353,    -1,   354,    -1,
     132,    -1,   132,   354,    -1,   137,   393,    -1,    28,   108,
     114,   612,    -1,    28,   108,   114,   612,   518,    -1,    28,
     377,   108,   114,   612,    -1,    28,   377,   108,   114,   612,
     518,    -1,   355,   137,   393,    -1,   355,   132,    -1,   355,
     132,   137,   393,    -1,   358,    -1,   357,   358,    -1,   283,
      -1,   284,    -1,   285,    -1,   286,    -1,   164,    -1,   196,
      -1,   224,   296,    -1,   224,   295,    -1,   297,   296,    -1,
     297,   295,    -1,   288,    -1,   289,   288,    -1,   292,   293,
      -1,   291,   293,    -1,    28,   282,   612,    -1,    28,   282,
     612,   361,    -1,    28,   282,   612,    91,   360,    -1,    28,
     282,   612,    91,   360,   361,    -1,    28,   357,   282,   612,
      -1,    28,   357,   282,   612,   361,    -1,    28,   357,   282,
     612,    91,   360,    -1,    28,   357,   282,   612,    91,   360,
     361,    -1,   524,    -1,   524,   520,    -1,   231,   287,   221,
      -1,   231,   286,   221,    -1,    28,   290,   612,   294,   221,
     465,   165,   363,    -1,    28,   357,   290,   612,   294,   221,
     465,   165,   363,    -1,   364,    -1,   363,   103,   364,    -1,
     465,    -1,   465,   518,    -1,   465,   429,    -1,   465,   518,
     429,    -1,    28,   298,   299,   612,   294,   282,   612,   114,
     612,   300,   393,    -1,    28,   298,   299,   612,   294,   282,
     612,   219,   114,   612,   300,   288,   301,   465,    -1,    28,
     298,   299,   612,   294,   282,   612,   302,   219,   114,   612,
     300,   393,    -1,    28,   298,   299,   612,   303,   301,   252,
     282,   612,   219,   114,   612,   301,   465,   193,   282,   612,
     219,   114,   612,   301,   465,    -1,    28,    35,   177,    -1,
      28,    35,   190,    -1,   151,   182,    -1,   151,   385,   182,
      -1,   151,   182,    91,   519,    -1,   151,   385,   182,    91,
     519,    -1,   232,   369,    -1,   148,   370,   390,   179,    -1,
     370,   371,   185,    -1,    -1,   371,   103,   372,    -1,    28,
     372,    -1,   114,   612,    -1,   114,   612,   518,    -1,   114,
     612,   137,   393,    -1,   114,   612,   518,   137,   393,    -1,
      62,   114,   612,   137,   393,    -1,   235,   237,   393,    -1,
     238,   151,   393,   182,   369,    -1,   233,   236,    -1,   234,
     236,    -1,   378,    -1,   377,   378,    -1,   168,   612,    -1,
     168,   612,   151,   379,   182,    -1,   482,    -1,   379,   103,
     482,    -1,    28,   381,    -1,    28,   377,   381,    -1,   382,
      -1,    63,   382,    -1,   384,    -1,   383,    -1,    44,   613,
     367,   388,    -1,    44,   613,   367,   132,    -1,    61,    44,
     613,   367,   369,    -1,    61,    44,   613,   367,   132,    -1,
      72,    44,   613,   367,   148,   392,   179,    -1,    72,    44,
     613,   367,   132,    -1,   386,    -1,   385,   103,   386,    -1,
     114,   612,    -1,   114,   612,   518,    -1,   148,   390,   179,
      -1,   148,   390,   179,    -1,   390,    -1,   392,    -1,   392,
     391,    -1,   185,    -1,   391,   392,   185,    -1,   393,    -1,
     392,   103,   393,    -1,   394,    -1,   430,    -1,   433,    -1,
     437,    -1,   440,    -1,   441,    -1,   545,    -1,   546,    -1,
     548,    -1,   547,    -1,   549,    -1,   552,    -1,   556,    -1,
     374,    -1,   375,    -1,   376,    -1,   373,    -1,   368,    -1,
     403,   395,    -1,   181,   393,    -1,    64,   279,    -1,    69,
     279,    -1,   211,    -1,   249,    -1,    53,   249,    -1,   397,
     414,    74,   393,    -1,   397,    74,   393,    -1,    43,   396,
     413,   398,   398,    -1,    43,   396,   413,   398,    -1,    37,
     114,   612,    -1,   404,    -1,   409,    -1,   399,    -1,   401,
      -1,   418,    -1,   423,    -1,   419,    -1,   400,    -1,   401,
      -1,   403,   402,    -1,    43,   114,   405,    -1,   406,    -1,
     405,   103,   114,   406,    -1,   612,   142,   393,    -1,   612,
      31,   122,   142,   393,    -1,   612,   518,   142,   393,    -1,
     612,   518,    31,   122,   142,   393,    -1,   612,   407,   142,
     393,    -1,   612,    31,   122,   407,   142,   393,    -1,   612,
     518,   407,   142,   393,    -1,   612,   518,    31,   122,   407,
     142,   393,    -1,   612,   408,   142,   393,    -1,   612,   518,
     408,   142,   393,    -1,   612,   407,   408,   142,   393,    -1,
     612,   518,   407,   408,   142,   393,    -1,    93,   114,   612,
      -1,   268,   114,   612,    -1,    48,   114,   410,    -1,   412,
      -1,   410,   103,   114,   412,    -1,   417,    -1,   411,   103,
     114,   417,    -1,   612,   137,   393,    -1,   612,   518,   137,
     393,    -1,   612,   408,   137,   393,    -1,   612,   518,   408,
     137,   393,    -1,   114,   612,   142,   393,    -1,   114,   612,
     518,   142,   393,    -1,   415,    -1,   114,   612,    -1,   114,
     612,   415,    -1,   407,    -1,   407,   416,    -1,   416,    -1,
      56,   114,   612,    50,   114,   612,    -1,    50,   114,   612,
      -1,    56,   114,   612,    -1,   612,    -1,   206,   393,    -1,
     166,   165,   420,    -1,   421,    -1,   420,   103,   421,    -1,
     114,   612,    -1,   114,   612,   422,    -1,   102,   610,    -1,
     163,   165,   424,    -1,    67,   163,   165,   424,    -1,   425,
      -1,   424,   103,   425,    -1,   393,    -1,   393,   426,    -1,
     427,    -1,   428,    -1,   429,    -1,   427,   428,    -1,   427,
     429,    -1,   428,   429,    -1,   427,   428,   429,    -1,    92,
      -1,   112,    -1,   122,   123,    -1,   122,   124,    -1,   102,
     610,    -1,    65,   114,   431,   183,   393,    -1,   130,   114,
     431,   183,   393,    -1,   432,    -1,   431,   103,   114,   432,
      -1,   612,   142,   393,    -1,   612,   518,   142,   393,    -1,
      70,   151,   390,   182,   434,   109,   181,   393,    -1,   435,
      -1,   434,   435,    -1,   436,   181,   393,    -1,    96,   393,
      -1,   436,    96,   393,    -1,    71,   151,   390,   182,   438,
     109,   181,   393,    -1,    71,   151,   390,   182,   438,   109,
     114,   612,   181,   393,    -1,   439,    -1,   438,   439,    -1,
      96,   519,   181,   393,    -1,    96,   114,   612,    91,   519,
     181,   393,    -1,    45,   151,   390,   182,   192,   393,   121,
     393,    -1,   442,    -1,   441,   162,   442,    -1,   443,    -1,
     442,    89,   443,    -1,   445,    -1,   445,   459,   445,    -1,
     445,   460,   445,    -1,   445,   127,   445,    -1,   445,   157,
     445,    -1,    -1,   445,   152,   444,   445,    -1,   445,   150,
     445,    -1,   445,   138,   445,    -1,   445,   136,   445,    -1,
     447,    -1,   447,   244,    68,   557,   446,    -1,    -1,   609,
      -1,   448,    -1,   448,   193,   448,    -1,   449,    -1,   448,
     171,   449,    -1,   448,   153,   449,    -1,   450,    -1,   449,
     188,   450,    -1,   449,   113,   450,    -1,   449,   141,   450,
      -1,   449,   154,   450,    -1,   451,    -1,   450,   195,   451,
      -1,   450,   204,   451,    -1,   452,    -1,   451,   145,   452,
      -1,   451,   131,   452,    -1,   453,    -1,   453,    47,   225,
     519,    -1,   454,    -1,   454,   194,    91,   519,    -1,   455,
      -1,   455,    97,    91,   517,    -1,   456,    -1,   456,    98,
      91,   517,    -1,   458,    -1,   457,   458,    -1,   171,    -1,
     153,    -1,   457,   171,    -1,   457,   153,    -1,   461,    -1,
     465,    -1,   462,    -1,   197,    -1,   202,    -1,   201,    -1,
     200,    -1,   199,    -1,   198,    -1,   146,    -1,   174,    -1,
     135,    -1,    73,   148,   390,   179,    -1,    73,   216,   148,
     390,   179,    -1,    73,   215,   148,   390,   179,    -1,    73,
      91,   534,   148,   390,   179,    -1,   463,   148,   179,    -1,
     463,   148,   390,   179,    -1,   464,    -1,   463,   464,    -1,
     172,   612,    16,    -1,   172,    17,    -1,   466,    -1,   466,
     467,    -1,   187,   467,    -1,   467,    -1,   186,    -1,   468,
      -1,   468,   186,   467,    -1,   468,   187,   467,    -1,   469,
      -1,   478,    -1,   470,    -1,   470,   479,    -1,   473,    -1,
     473,   479,    -1,   471,   475,    -1,   472,    -1,   101,   117,
      -1,   110,   117,    -1,    94,   117,    -1,   184,   117,    -1,
     111,   117,    -1,   134,   117,    -1,   133,   117,    -1,   475,
      -1,    95,   475,    -1,   474,   475,    -1,   116,    -1,   167,
     117,    -1,    87,   117,    -1,   176,   117,    -1,   175,   117,
      -1,    88,   117,    -1,   524,    -1,   476,    -1,   612,    -1,
     477,    -1,   188,    -1,    11,    -1,    18,    -1,   481,    -1,
     478,   479,    -1,   478,   151,   182,    -1,   478,   151,   490,
     182,    -1,   480,    -1,   479,   480,    -1,   149,   390,   180,
      -1,   482,    -1,   484,    -1,   485,    -1,   486,    -1,   489,
      -1,   491,    -1,   487,    -1,   488,    -1,   537,    -1,   483,
      -1,   536,    -1,   106,    -1,   144,    -1,   119,    -1,   114,
     612,    -1,   151,   182,    -1,   151,   390,   182,    -1,   115,
      -1,   164,   148,   390,   179,    -1,   196,   148,   390,   179,
      -1,   613,   151,   182,    -1,   613,   151,   490,   182,    -1,
     393,    -1,   490,   103,   393,    -1,   492,    -1,   510,    -1,
     493,    -1,   507,    -1,   508,    -1,   152,   612,   497,   125,
      -1,   152,   612,   495,   497,   125,    -1,   152,   612,   497,
     191,   189,   612,   497,   191,    -1,   152,   612,   497,   191,
     494,   189,   612,   497,   191,    -1,   152,   612,   495,   497,
     191,   189,   612,   497,   191,    -1,   152,   612,   495,   497,
     191,   494,   189,   612,   497,   191,    -1,   505,    -1,   494,
     505,    -1,   496,    -1,   495,   496,    -1,    30,   612,   497,
     127,   497,   498,    -1,    -1,    30,    -1,   178,   499,   178,
      -1,    90,   501,    90,    -1,    -1,   500,    -1,   129,    -1,
     503,    -1,   500,   129,    -1,   500,   503,    -1,    -1,   502,
      -1,   128,    -1,   504,    -1,   502,   128,    -1,   502,   504,
      -1,    23,    -1,   506,    -1,     5,    -1,   506,    -1,   492,
      -1,    10,    -1,   509,    -1,   506,    -1,     9,    -1,   118,
      -1,   120,    -1,   387,    -1,   207,    25,   208,    -1,   207,
     208,    -1,   169,   611,   170,    -1,   169,   611,     8,    -1,
      99,     7,    -1,   511,    -1,   512,    -1,   513,    -1,   514,
      -1,   515,    -1,   516,    -1,    39,   148,   390,   179,    -1,
      19,   179,    -1,    19,   390,   179,    -1,    41,   148,   390,
     179,   148,   179,    -1,    41,   148,   390,   179,   148,   390,
     179,    -1,    20,   179,    -1,    20,   390,   179,    -1,    94,
     148,   390,   179,   148,   179,    -1,    94,   148,   390,   179,
     148,   390,   179,    -1,    68,   148,   390,   179,    -1,    34,
     148,   390,   179,    -1,    21,   179,    -1,    21,   390,   179,
      -1,    57,   148,   390,   179,   148,   179,    -1,    57,   148,
     390,   179,   148,   390,   179,    -1,   523,    -1,   523,   139,
      -1,    91,   519,    -1,   521,    -1,   521,   520,    -1,   205,
     151,   182,    -1,   139,    -1,   188,    -1,   171,    -1,   523,
      -1,   524,    -1,   147,   151,   182,    -1,   540,    -1,   543,
      -1,   519,    -1,   522,   103,   519,    -1,   612,    -1,   526,
      -1,   532,    -1,   530,    -1,   533,    -1,   531,    -1,   529,
      -1,   528,    -1,   527,    -1,   525,    -1,   219,   151,   182,
      -1,    40,   151,   182,    -1,    40,   151,   532,   182,    -1,
      40,   151,   533,   182,    -1,    68,   151,   182,    -1,    34,
     151,   182,    -1,    57,   151,   182,    -1,    57,   151,   611,
     182,    -1,    57,   151,    24,   182,    -1,    94,   151,   182,
      -1,    94,   151,   612,   182,    -1,    94,   151,   612,   103,
     534,   182,    -1,    94,   151,   188,   182,    -1,    94,   151,
     188,   103,   534,   182,    -1,    59,   151,   612,   182,    -1,
      41,   151,   182,    -1,    41,   151,   612,   182,    -1,    41,
     151,   612,   103,   534,   182,    -1,    41,   151,   612,   103,
     535,   182,    -1,    41,   151,   188,   182,    -1,    41,   151,
     188,   103,   534,   182,    -1,    41,   151,   188,   103,   535,
     182,    -1,    60,   151,   612,   182,    -1,   612,    -1,   612,
     139,    -1,    24,    -1,   538,    -1,   539,    -1,   612,   140,
     144,    -1,    44,   367,   387,    -1,   541,    -1,   542,    -1,
      44,   151,   188,   182,    -1,    44,   151,   182,    91,   519,
      -1,    44,   151,   522,   182,    91,   519,    -1,   151,   521,
     182,    -1,    28,   214,   215,    -1,    28,   214,   216,    -1,
      28,   214,   217,    -1,   220,   219,   393,   227,   393,    -1,
     220,   219,   393,    91,   226,   227,   393,    -1,   220,   219,
     393,    91,   228,   227,   393,    -1,   220,   219,   393,   212,
     393,    -1,   220,   219,   393,   213,   393,    -1,   220,   221,
     393,   227,   393,    -1,   220,   221,   393,    91,   226,   227,
     393,    -1,   220,   221,   393,    91,   228,   227,   393,    -1,
     220,   221,   393,   212,   393,    -1,   220,   221,   393,   213,
     393,    -1,   218,   219,   393,    -1,   218,   221,   393,    -1,
     223,   219,   393,   231,   393,    -1,   223,   224,   225,   219,
     393,   231,   393,    -1,   222,   219,   393,    91,   393,    -1,
     230,   114,   550,   229,   393,   181,   393,    -1,   551,    -1,
     550,   103,   114,   551,    -1,   612,   137,   393,    -1,   239,
     148,   390,   179,   553,    -1,   554,    -1,   553,   554,    -1,
     240,   555,   388,    -1,   240,   555,   151,   114,   612,   182,
     388,    -1,   240,   555,   151,   114,   612,   103,   114,   612,
     182,   388,    -1,   240,   555,   151,   114,   612,   103,   114,
     612,   103,   114,   612,   182,   388,    -1,   476,    -1,   555,
     204,   476,    -1,   241,   114,   411,    42,   148,   393,   179,
      -1,    42,   148,   393,   179,    -1,   560,   558,    -1,    -1,
     559,    -1,   578,    -1,   559,   578,    -1,   561,    -1,   560,
     257,   561,    -1,   562,    -1,   561,   253,   562,    -1,   563,
      -1,   562,   255,   142,   563,    -1,   564,    -1,   254,   564,
      -1,   568,   565,   566,    -1,    -1,   583,    -1,    -1,   567,
      -1,   277,   148,   390,   179,    -1,   572,   569,    -1,   151,
     557,   182,    -1,   570,    -1,    -1,   605,    -1,   463,   148,
     571,   179,    -1,    -1,   557,    -1,   573,   574,    -1,   482,
      -1,   148,   390,   179,    -1,    -1,   575,    -1,   243,   576,
      -1,   242,   577,    -1,   265,    -1,    -1,    75,    -1,    -1,
     281,    -1,   579,    -1,   580,    -1,   581,    -1,   607,    -1,
     604,    -1,   164,    -1,   279,   448,   582,    -1,   248,   606,
     582,    -1,   281,    -1,   271,    -1,   264,    -1,   241,   584,
      -1,   583,   241,   584,    -1,   585,    -1,   586,    -1,   587,
      -1,   602,    -1,   588,    -1,   596,    -1,   589,    -1,   603,
      -1,    96,   269,    -1,    96,   258,    -1,   261,    -1,   276,
      -1,   246,   269,    -1,   246,   258,    -1,    54,   612,    24,
      -1,   272,    -1,    51,   272,    -1,   274,   590,    -1,   274,
     151,   590,   591,   182,    -1,    51,   274,    -1,   593,    -1,
     109,    -1,    -1,   592,    -1,   593,    -1,   592,   103,   593,
      -1,    93,    24,   594,   595,    -1,    -1,   266,    24,    -1,
      -1,   606,   260,    -1,   273,   281,   597,   599,    -1,   273,
     281,   109,   599,    -1,    51,   273,   281,    -1,    93,    24,
      -1,   151,   598,   182,    -1,    24,    -1,   598,   103,    24,
      -1,    -1,   600,    -1,   601,    -1,   600,   601,    -1,   195,
     597,    -1,   131,   597,    -1,   259,    24,    -1,   278,    -1,
      51,   278,    -1,    93,   211,    -1,    93,   249,    -1,   250,
     245,    -1,   262,   606,   275,    -1,   251,   448,    -1,    93,
     124,   448,    -1,    93,    49,   448,    -1,   252,   448,   193,
     448,    -1,   267,   608,    -1,   247,   608,    -1,   270,    -1,
     263,    -1,   280,   245,   450,    -1,    24,    -1,    15,    -1,
     612,    -1,   613,    -1,    94,    -1,    34,    -1,    40,    -1,
      41,    -1,   147,    -1,    45,    -1,   219,    -1,    57,    -1,
      59,    -1,    60,    -1,    68,    -1,    71,    -1,    70,    -1,
     205,    -1,   238,    -1,    22,    -1,   209,    -1,   122,    -1,
      33,    -1,   256,    -1,    32,    -1,   216,    -1,   215,    -1,
     141,    -1,    39,    -1,   254,    -1,   255,    -1,   269,    -1,
     258,    -1,   246,    -1,   280,    -1,   272,    -1,   274,    -1,
     273,    -1,   278,    -1,   250,    -1,   245,    -1,    75,    -1,
     211,    -1,   249,    -1,    49,    -1,   217,    -1,   230,    -1,
     297,    -1,   224,    -1,   197,    -1,   202,    -1,   201,    -1,
     200,    -1,   199,    -1,   198,    -1,    93,    -1,   107,    -1,
     108,    -1,   181,    -1,    43,    -1,    31,    -1,    64,    -1,
      69,    -1,    56,    -1,    50,    -1,    53,    -1,    74,    -1,
      37,    -1,   142,    -1,    48,    -1,   206,    -1,   165,    -1,
     166,    -1,   163,    -1,    67,    -1,    92,    -1,   112,    -1,
     123,    -1,   124,    -1,   102,    -1,    65,    -1,   130,    -1,
     183,    -1,    96,    -1,    91,    -1,   192,    -1,   121,    -1,
     162,    -1,    89,    -1,    47,    -1,   225,    -1,    97,    -1,
     193,    -1,   113,    -1,   154,    -1,   195,    -1,   145,    -1,
     131,    -1,    73,    -1,    98,    -1,   194,    -1,   146,    -1,
     177,    -1,   190,    -1,   155,    -1,   132,    -1,   126,    -1,
     161,    -1,   143,    -1,   160,    -1,    28,    -1,    35,    -1,
      55,    -1,   109,    -1,    36,    -1,    54,    -1,   210,    -1,
      46,    -1,    58,    -1,    29,    -1,    44,    -1,   268,    -1,
     244,    -1,   277,    -1,   279,    -1,   248,    -1,   262,    -1,
     275,    -1,   267,    -1,   247,    -1,   261,    -1,   276,    -1,
     266,    -1,   260,    -1,   259,    -1,   243,    -1,   242,    -1,
     265,    -1,   251,    -1,   252,    -1,   281,    -1,   271,    -1,
     270,    -1,   263,    -1,   223,    -1,   229,    -1,   226,    -1,
     220,    -1,   213,    -1,   212,    -1,   214,    -1,   231,    -1,
     221,    -1,   222,    -1,   228,    -1,   218,    -1,   227,    -1,
      63,    -1,    61,    -1,    72,    -1,    38,    -1,    52,    -1,
     164,    -1,   196,    -1,   237,    -1,   232,    -1,   235,    -1,
     236,    -1,   233,    -1,   234,    -1,   239,    -1,   240,    -1,
      42,    -1,   241,    -1,    62,    -1,   290,    -1,   288,    -1,
     289,    -1,   294,    -1,   295,    -1,   296,    -1,   291,    -1,
     292,    -1,   293,    -1,    76,    -1,    77,    -1,    78,    -1,
      79,    -1,    80,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    85,    -1,    86,    -1,   282,    -1,   283,    -1,
     284,    -1,   285,    -1,   286,    -1,   287,    -1,   298,    -1,
     299,    -1,   300,    -1,   301,    -1,   302,    -1,   303,    -1,
     304,    -1,    87,    -1,   101,    -1,   110,    -1,   167,    -1,
     175,    -1,   184,    -1,   133,    -1,    88,    -1,   111,    -1,
     134,    -1,   176,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    11,    13,    16,    18,    21,
      26,    33,    37,    41,    47,    49,    53,    57,    63,    69,
      71,    75,    79,    85,    92,    94,    98,   102,   104,   108,
     112,   114,   116,   118,   120,   122,   124,   126,   128,   130,
     132,   134,   136,   138,   143,   148,   150,   153,   157,   159,
     161,   163,   165,   167,   169,   171,   173,   175,   177,   179,
     181,   183,   185,   187,   189,   191,   193,   195,   197,   203,
     207,   211,   217,   223,   228,   232,   236,   240,   246,   252,
     258,   264,   270,   276,   281,   285,   289,   294,   300,   307,
     309,   313,   317,   321,   325,   332,   338,   347,   352,   356,
     358,   360,   362,   365,   368,   373,   379,   385,   392,   396,
     399,   404,   406,   409,   411,   413,   415,   417,   419,   421,
     424,   427,   430,   433,   435,   438,   441,   444,   448,   453,
     459,   466,   471,   477,   484,   492,   494,   497,   501,   505,
     514,   524,   526,   530,   532,   535,   538,   542,   554,   569,
     583,   606,   610,   614,   617,   621,   626,   632,   635,   640,
     644,   645,   649,   652,   655,   659,   664,   670,   676,   680,
     686,   689,   692,   694,   697,   700,   706,   708,   712,   715,
     719,   721,   724,   726,   728,   733,   738,   744,   750,   758,
     764,   766,   770,   773,   777,   781,   785,   787,   789,   792,
     794,   798,   800,   804,   806,   808,   810,   812,   814,   816,
     818,   820,   822,   824,   826,   828,   830,   832,   834,   836,
     838,   840,   843,   846,   849,   852,   854,   856,   859,   864,
     868,   874,   879,   883,   885,   887,   889,   891,   893,   895,
     897,   899,   901,   904,   908,   910,   915,   919,   925,   930,
     937,   942,   949,   955,   963,   968,   974,   980,   987,   991,
     995,   999,  1001,  1006,  1008,  1013,  1017,  1022,  1027,  1033,
    1038,  1044,  1046,  1049,  1053,  1055,  1058,  1060,  1067,  1071,
    1075,  1077,  1080,  1084,  1086,  1090,  1093,  1097,  1100,  1104,
    1109,  1111,  1115,  1117,  1120,  1122,  1124,  1126,  1129,  1132,
    1135,  1139,  1141,  1143,  1146,  1149,  1152,  1158,  1164,  1166,
    1171,  1175,  1180,  1189,  1191,  1194,  1198,  1201,  1205,  1214,
    1225,  1227,  1230,  1235,  1243,  1252,  1254,  1258,  1260,  1264,
    1266,  1270,  1274,  1278,  1282,  1283,  1288,  1292,  1296,  1300,
    1302,  1308,  1309,  1311,  1313,  1317,  1319,  1323,  1327,  1329,
    1333,  1337,  1341,  1345,  1347,  1351,  1355,  1357,  1361,  1365,
    1367,  1372,  1374,  1379,  1381,  1386,  1388,  1393,  1395,  1398,
    1400,  1402,  1405,  1408,  1410,  1412,  1414,  1416,  1418,  1420,
    1422,  1424,  1426,  1428,  1430,  1432,  1437,  1443,  1449,  1456,
    1460,  1465,  1467,  1470,  1474,  1477,  1479,  1482,  1485,  1487,
    1489,  1491,  1495,  1499,  1501,  1503,  1505,  1508,  1510,  1513,
    1516,  1518,  1521,  1524,  1527,  1530,  1533,  1536,  1539,  1541,
    1544,  1547,  1549,  1552,  1555,  1558,  1561,  1564,  1566,  1568,
    1570,  1572,  1574,  1576,  1578,  1580,  1583,  1587,  1592,  1594,
    1597,  1601,  1603,  1605,  1607,  1609,  1611,  1613,  1615,  1617,
    1619,  1621,  1623,  1625,  1627,  1629,  1632,  1635,  1639,  1641,
    1646,  1651,  1655,  1660,  1662,  1666,  1668,  1670,  1672,  1674,
    1676,  1681,  1687,  1696,  1706,  1716,  1727,  1729,  1732,  1734,
    1737,  1744,  1745,  1747,  1751,  1755,  1756,  1758,  1760,  1762,
    1765,  1768,  1769,  1771,  1773,  1775,  1778,  1781,  1783,  1785,
    1787,  1789,  1791,  1793,  1795,  1797,  1799,  1801,  1803,  1805,
    1809,  1812,  1816,  1820,  1823,  1825,  1827,  1829,  1831,  1833,
    1835,  1840,  1843,  1847,  1854,  1862,  1865,  1869,  1876,  1884,
    1889,  1894,  1897,  1901,  1908,  1916,  1918,  1921,  1924,  1926,
    1929,  1933,  1935,  1937,  1939,  1941,  1943,  1947,  1949,  1951,
    1953,  1957,  1959,  1961,  1963,  1965,  1967,  1969,  1971,  1973,
    1975,  1977,  1981,  1985,  1990,  1995,  1999,  2003,  2007,  2012,
    2017,  2021,  2026,  2033,  2038,  2045,  2050,  2054,  2059,  2066,
    2073,  2078,  2085,  2092,  2097,  2099,  2102,  2104,  2106,  2108,
    2112,  2116,  2118,  2120,  2125,  2131,  2138,  2142,  2146,  2150,
    2154,  2160,  2168,  2176,  2182,  2188,  2194,  2202,  2210,  2216,
    2222,  2226,  2230,  2236,  2244,  2250,  2258,  2260,  2265,  2269,
    2275,  2277,  2280,  2284,  2292,  2303,  2317,  2319,  2323,  2331,
    2336,  2339,  2340,  2342,  2344,  2347,  2349,  2353,  2355,  2359,
    2361,  2366,  2368,  2371,  2375,  2376,  2378,  2379,  2381,  2386,
    2389,  2393,  2395,  2396,  2398,  2403,  2404,  2406,  2409,  2411,
    2415,  2416,  2418,  2421,  2424,  2426,  2427,  2429,  2430,  2432,
    2434,  2436,  2438,  2440,  2442,  2444,  2448,  2452,  2454,  2456,
    2458,  2461,  2465,  2467,  2469,  2471,  2473,  2475,  2477,  2479,
    2481,  2484,  2487,  2489,  2491,  2494,  2497,  2501,  2503,  2506,
    2509,  2515,  2518,  2520,  2522,  2523,  2525,  2527,  2531,  2536,
    2537,  2540,  2541,  2544,  2549,  2554,  2558,  2561,  2565,  2567,
    2571,  2572,  2574,  2576,  2579,  2582,  2585,  2588,  2590,  2593,
    2596,  2599,  2602,  2606,  2609,  2613,  2617,  2622,  2625,  2628,
    2630,  2632,  2636,  2638,  2640,  2642,  2644,  2646,  2648,  2650,
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
    3052,  3054,  3056,  3058,  3060,  3062,  3064,  3066,  3068,  3070,
    3072
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1022,  1022,  1023,  1056,  1065,  1070,  1077,  1082,  1093,
    1098,  1106,  1111,  1116,  1121,  1126,  1134,  1142,  1150,  1162,
    1166,  1171,  1176,  1185,  1194,  1200,  1206,  1219,  1225,  1231,
    1243,  1244,  1245,  1246,  1251,  1252,  1253,  1254,  1255,  1256,
    1257,  1258,  1259,  1265,  1270,  1279,  1285,  1294,  1303,  1304,
    1305,  1306,  1307,  1308,  1309,  1310,  1311,  1312,  1317,  1318,
    1319,  1320,  1321,  1322,  1323,  1326,  1331,  1332,  1337,  1345,
    1351,  1361,  1367,  1377,  1387,  1395,  1401,  1412,  1417,  1427,
    1433,  1439,  1445,  1462,  1470,  1478,  1482,  1491,  1500,  1513,
    1519,  1530,  1534,  1542,  1547,  1552,  1559,  1572,  1579,  1585,
    1592,  1598,  1602,  1609,  1620,  1625,  1630,  1635,  1644,  1650,
    1656,  1665,  1671,  1680,  1684,  1690,  1694,  1698,  1702,  1708,
    1714,  1720,  1726,  1732,  1736,  1742,  1748,  1755,  1763,  1771,
    1779,  1787,  1799,  1813,  1827,  1844,  1848,  1857,  1861,  1868,
    1876,  1894,  1900,  1908,  1913,  1920,  1927,  1937,  1947,  1957,
    1967,  1984,  1990,  2001,  2005,  2009,  2013,  2020,  2027,  2046,
    2056,  2062,  2068,  2078,  2084,  2090,  2096,  2106,  2113,  2120,
    2132,  2136,  2144,  2148,  2156,  2160,  2167,  2171,  2179,  2184,
    2224,  2228,  2232,  2236,  2244,  2255,  2270,  2281,  2296,  2307,
    2323,  2329,  2341,  2345,  2356,  2363,  2371,  2386,  2390,  2404,
    2408,  2417,  2421,  2449,  2450,  2451,  2452,  2453,  2454,  2457,
    2458,  2459,  2460,  2461,  2463,  2464,  2467,  2468,  2469,  2470,
    2471,  2476,  2491,  2498,  2502,  2509,  2513,  2517,  2524,  2532,
    2543,  2553,  2566,  2575,  2576,  2577,  2581,  2582,  2583,  2584,
    2585,  2588,  2594,  2604,  2612,  2618,  2630,  2634,  2638,  2642,
    2646,  2650,  2654,  2659,  2665,  2674,  2684,  2694,  2710,  2719,
    2729,  2737,  2743,  2752,  2758,  2770,  2778,  2788,  2796,  2808,
    2814,  2825,  2827,  2831,  2839,  2843,  2848,  2852,  2856,  2860,
    2868,  2882,  2890,  2897,  2903,  2914,  2918,  2927,  2935,  2941,
    2951,  2957,  2967,  2971,  2981,  2987,  2993,  2999,  3008,  3017,
    3026,  3039,  3043,  3051,  3057,  3067,  3075,  3084,  3097,  3104,
    3116,  3120,  3132,  3139,  3145,  3154,  3161,  3167,  3179,  3186,
    3199,  3205,  3217,  3223,  3235,  3244,  3248,  3257,  3261,  3269,
    3273,  3283,  3290,  3299,  3309,  3308,  3322,  3331,  3340,  3353,
    3357,  3370,  3373,  3380,  3384,  3393,  3397,  3401,  3410,  3414,
    3420,  3426,  3432,  3443,  3447,  3451,  3459,  3463,  3469,  3479,
    3483,  3493,  3497,  3507,  3511,  3521,  3525,  3535,  3539,  3547,
    3551,  3555,  3559,  3569,  3573,  3577,  3585,  3589,  3593,  3597,
    3601,  3605,  3613,  3617,  3621,  3629,  3633,  3637,  3641,  3652,
    3658,  3668,  3674,  3684,  3688,  3726,  3730,  3736,  3742,  3753,
    3761,  3772,  3778,  3788,  3792,  3800,  3806,  3814,  3820,  3832,
    3838,  3848,  3852,  3856,  3860,  3864,  3870,  3876,  3899,  3903,
    3911,  3915,  3926,  3930,  3934,  3940,  3944,  3958,  3962,  3970,
    3974,  3984,  3988,  3992,  4001,  4005,  4011,  4015,  4023,  4029,
    4039,  4047,  4051,  4055,  4059,  4063,  4067,  4071,  4075,  4079,
    4087,  4091,  4099,  4106,  4113,  4124,  4132,  4136,  4144,  4152,
    4160,  4214,  4218,  4231,  4237,  4247,  4251,  4259,  4263,  4267,
    4275,  4285,  4295,  4305,  4315,  4325,  4340,  4346,  4357,  4363,
    4374,  4385,  4387,  4391,  4396,  4406,  4409,  4416,  4424,  4430,
    4440,  4453,  4456,  4463,  4469,  4475,  4482,  4493,  4497,  4507,
    4511,  4521,  4525,  4529,  4534,  4543,  4549,  4555,  4561,  4571,
    4575,  4587,  4591,  4603,  4615,  4619,  4623,  4627,  4631,  4635,
    4643,  4651,  4655,  4659,  4663,  4680,  4684,  4688,  4692,  4700,
    4708,  4716,  4720,  4724,  4728,  4736,  4742,  4752,  4760,  4764,
    4768,  4803,  4809,  4815,  4825,  4829,  4833,  4837,  4841,  4848,
    4854,  4864,  4872,  4876,  4880,  4884,  4888,  4892,  4896,  4900,
    4904,  4912,  4920,  4924,  4928,  4938,  4946,  4954,  4958,  4962,
    4970,  4974,  4980,  4986,  4990,  5000,  5008,  5012,  5018,  5027,
    5036,  5042,  5048,  5058,  5075,  5082,  5097,  5133,  5137,  5146,
    5155,  5165,  5169,  5178,  5187,  5191,  5202,  5219,  5225,  5231,
    5241,  5245,  5251,  5257,  5261,  5267,  5271,  5277,  5283,  5290,
    5300,  5305,  5313,  5319,  5329,  5351,  5360,  5366,  5379,  5393,
    5400,  5406,  5416,  5421,  5426,  5436,  5449,  5455,  5472,  5476,
    5491,  5500,  5503,  5510,  5515,  5523,  5527,  5534,  5538,  5545,
    5549,  5556,  5560,  5569,  5582,  5585,  5593,  5596,  5604,  5612,
    5620,  5624,  5632,  5635,  5643,  5655,  5658,  5666,  5678,  5684,
    5694,  5697,  5705,  5709,  5713,  5721,  5724,  5732,  5735,  5743,
    5747,  5751,  5755,  5759,  5767,  5775,  5787,  5799,  5803,  5807,
    5815,  5821,  5831,  5835,  5839,  5843,  5847,  5851,  5855,  5859,
    5867,  5871,  5875,  5879,  5887,  5893,  5903,  5913,  5917,  5925,
    5935,  5946,  5953,  5957,  5965,  5968,  5975,  5980,  5989,  5999,
    6002,  6010,  6013,  6021,  6030,  6037,  6047,  6051,  6058,  6064,
    6074,  6077,  6084,  6089,  6101,  6109,  6121,  6129,  6133,  6141,
    6145,  6149,  6157,  6165,  6169,  6173,  6177,  6185,  6193,  6205,
    6209,  6217,  6230,  6234,  6235,  6248,  6249,  6250,  6251,  6252,
    6253,  6254,  6255,  6256,  6257,  6258,  6259,  6260,  6261,  6262,
    6263,  6267,  6268,  6269,  6270,  6271,  6272,  6273,  6274,  6275,
    6276,  6277,  6278,  6279,  6280,  6281,  6282,  6283,  6284,  6285,
    6286,  6287,  6288,  6289,  6290,  6291,  6292,  6293,  6294,  6295,
    6296,  6297,  6298,  6299,  6300,  6301,  6302,  6303,  6304,  6305,
    6306,  6307,  6308,  6309,  6310,  6311,  6312,  6313,  6314,  6315,
    6316,  6317,  6318,  6319,  6320,  6321,  6322,  6323,  6324,  6325,
    6326,  6327,  6328,  6329,  6330,  6331,  6332,  6333,  6334,  6335,
    6336,  6337,  6338,  6339,  6340,  6341,  6342,  6343,  6344,  6345,
    6346,  6347,  6348,  6349,  6350,  6351,  6352,  6353,  6354,  6355,
    6356,  6357,  6358,  6359,  6360,  6361,  6362,  6363,  6364,  6365,
    6366,  6367,  6368,  6369,  6370,  6371,  6372,  6373,  6374,  6375,
    6376,  6377,  6378,  6379,  6380,  6381,  6382,  6383,  6384,  6385,
    6386,  6387,  6388,  6389,  6390,  6391,  6392,  6393,  6394,  6395,
    6396,  6397,  6398,  6399,  6400,  6401,  6402,  6403,  6404,  6405,
    6406,  6407,  6408,  6409,  6410,  6411,  6412,  6413,  6414,  6415,
    6416,  6417,  6418,  6419,  6420,  6421,  6422,  6423,  6424,  6425,
    6426,  6427,  6428,  6429,  6430,  6431,  6432,  6433,  6434,  6435,
    6436,  6437,  6438,  6439,  6440,  6441,  6442,  6443,  6444,  6445,
    6446,  6447,  6448,  6449,  6450,  6451,  6452,  6453,  6454,  6455,
    6456,  6457,  6458,  6459,  6460,  6461,  6462,  6463,  6464,  6465,
    6466
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
     315,   316,   317,   318
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 11848;
  const int xquery_parser::yynnts_ = 295;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 556;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 319;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 573;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1054 of lalr1.cc  */
#line 15764 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6470 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"


namespace zorba {

namespace parser {

const char *the_tumbling = "tumbling", *the_sliding = "sliding",
  *the_start = "start", *the_end = "end", *the_only_end = "only end",
  *the_declare = "declare", *the_create = "create";

} // namespace parser

/*
 *  The error member function registers the errors to the driver.
 */
void xquery_parser::error(zorba::xquery_parser::location_type const& loc, std::string const& msg)
{
  if (driver.parserError != NULL)
    driver.set_expr(new ParseErrorNode(driver.parserError->loc, XPST0003, driver.parserError->msg));
  else
  {
    // remove the double quoting "''" from every token description
    std::string message = msg;
    int pos;
    while ((pos = message.find("\"'")) != -1 || (pos = message.find("'\"")) != -1)
      message.replace(pos, 2, "\"");
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc), XPST0003, message));
  }
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

