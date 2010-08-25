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
#line 861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 961 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"

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
#line 859 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 329 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 119: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 858 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 338 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 144: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 857 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 347 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 356 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 365 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 374 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 383 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 392 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 401 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 410 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 419 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 428 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 882 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 437 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 882 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 446 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 455 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 464 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 473 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 482 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 491 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 500 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 509 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 518 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 527 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 536 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 545 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 554 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 563 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 572 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 581 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 590 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 599 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 608 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 617 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 626 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 882 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 635 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 644 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "DeclPropertyList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 653 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "DeclProperty" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 662 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 671 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 680 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 689 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 698 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 707 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 716 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 725 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 882 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 734 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 743 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 752 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 761 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 770 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 779 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 788 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 815 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 824 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 833 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 842 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FunctionDeclSequential" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 851 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 860 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 869 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 878 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 887 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 896 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 905 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 914 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 941 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 950 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 959 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 968 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 977 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 986 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 995 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1004 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1013 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1022 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1031 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1040 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1049 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1058 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1067 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1076 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1085 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1094 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1103 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1112 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1121 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1130 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1139 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1148 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1157 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1166 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1175 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1184 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1193 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1202 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1211 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1220 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1229 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1238 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1247 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1256 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1265 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1274 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1283 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1292 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1301 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1310 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1319 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1328 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1337 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1346 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1355 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1364 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1373 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1382 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1391 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1400 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1409 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1418 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1427 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1436 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1445 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1454 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1463 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1472 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1481 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1490 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1499 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1508 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1517 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1526 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1535 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1544 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1553 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1562 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1571 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1580 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1589 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1598 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1607 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1616 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1625 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1634 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1643 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1652 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1661 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1670 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1679 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1688 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1697 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1706 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1715 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1724 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1733 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1742 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1751 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1760 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1769 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1778 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1787 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1796 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1805 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1814 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1823 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1832 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1841 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1850 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1859 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1868 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1877 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1886 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1895 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1904 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1913 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1922 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1931 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1940 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1949 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1958 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1967 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1976 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1985 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1994 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2003 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2012 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2021 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2030 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2039 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2048 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2057 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2066 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2075 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2084 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2093 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2102 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2111 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2120 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2129 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2138 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2147 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2156 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2165 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2174 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2183 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2192 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2201 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2210 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2219 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2228 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2237 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2246 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2255 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2264 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2273 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2282 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 882 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2291 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2300 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2309 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2318 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2327 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2336 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2345 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2354 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2363 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2372 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2381 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2390 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2399 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2408 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2417 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2426 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2435 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2444 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2453 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2462 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2471 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2480 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2489 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2498 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2507 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2516 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2525 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2534 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2543 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2552 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2561 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2570 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2579 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2588 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2597 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2606 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2615 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2624 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2633 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2642 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2651 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2660 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
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
#line 2745 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1020 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 1053 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL; YYABORT;
        }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 1062 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1067 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            MainModule *mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
            mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1074 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1079 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            LibraryModule *lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
            lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1090 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            std::string encoding = "utf-8";
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), encoding );
        }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1095 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
        }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1103 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
        }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1108 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
        }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1113 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)), static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
        }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1118 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
        }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1123 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1131 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1139 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1147 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1159 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
        }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1163 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
        }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1168 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
        }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1173 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)), static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
        }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1182 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
            dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
        }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1191 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
            sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = sdl;
        }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1197 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1203 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1216 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
            vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = vdl;
        }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 1222 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 1228 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1262 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
          delete (yysemantic_stack_[(4) - (4)].vstrpair);
        }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1267 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
          delete (yysemantic_stack_[(4) - (4)].vstrpair);
        }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1276 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.vstrpair) = new vector<string_pair_t>();
          (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
          delete (yysemantic_stack_[(1) - (1)].strpair);
        }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1282 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
          delete (yysemantic_stack_[(2) - (2)].strpair);
          (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
        }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1291 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
            (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval() );
            delete sl;
        }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1299 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1300 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1301 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1302 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1303 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1304 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 1305 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 1306 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1307 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1308 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1334 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
        }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1342 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::preserve_space
            );
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1348 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::strip_space
            );
        }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1358 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_element_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1364 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_function_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1374 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OptionDecl(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval))
            );
        }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1384 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1392 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::ordered
            );
        }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1398 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::unordered
            );
        }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1409 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_greatest);
        }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1414 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_least);
        }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1424 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1430 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1436 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1442 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1459 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
        }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1467 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1475 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
        }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1479 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1488 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1497 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1510 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            URILiteralList *ull = new URILiteralList( LOC((yyloc)));
            ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.node) = ull;
        }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1516 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
                ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1527 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1531 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
        }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1539 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1544 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1549 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1556 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1569 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
        }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1576 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
            d->type = (yysemantic_stack_[(3) - (2)].node);
            (yyval.node) = d;
        }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1582 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1589 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
            d->ext = false;
            (yyval.node) = d;
        }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1595 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), NULL );
        }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1599 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1606 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1617 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1621 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1629 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(5) - (5)].expr));
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1635 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1641 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1650 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
            dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = dpl;
        }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1656 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
        dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
        (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1665 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1669 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1675 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1679 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1683 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1687 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1693 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1699 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1705 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_equality
            );
        }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1711 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_range
            );
        }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1717 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1721 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1727 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1733 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1740 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL,
                              NULL);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1748 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1756 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              NULL,
                              NULL,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1764 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(6) - (6)].node)),
                              static_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)));
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1772 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 130:

/* Line 678 of lalr1.cc  */
#line 1784 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 131:

/* Line 678 of lalr1.cc  */
#line 1798 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 132:

/* Line 678 of lalr1.cc  */
#line 1812 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 133:

/* Line 678 of lalr1.cc  */
#line 1829 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1833 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1842 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1846 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1853 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 139:

/* Line 678 of lalr1.cc  */
#line 1879 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1893 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1898 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1905 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1912 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1923 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1933 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1943 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1954 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 149:

/* Line 678 of lalr1.cc  */
#line 1969 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_preserve
            );
        }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1975 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_strip
            );
        }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1986 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL );
        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1990 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1994 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)) );
        }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1998 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 2005 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 2012 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 157:

/* Line 678 of lalr1.cc  */
#line 2031 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            std::auto_ptr<VFO_DeclList> vfo2( dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)) );
            if ( !(yysemantic_stack_[(3) - (1)].node) )
                vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back( *vfo2.get() );
            (yyval.node) = vfo;
        }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2040 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 2047 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            vfo->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = vfo;
        }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 2053 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back((yysemantic_stack_[(2) - (2)].node));
            (yyval.node) = vfo;
        }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2063 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(1) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2070 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(3) - (3)].expr));
      vd->set_global(false);
      (yyval.node) = vd;
        }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2081 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2088 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExitExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2095 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody *>((yysemantic_stack_[(5) - (5)].expr));
            if ( !bb ) {
                bb = new BlockBody( (yysemantic_stack_[(5) - (5)].expr)->get_location() );
                bb->add((yysemantic_stack_[(5) - (5)].expr));
            }
            (yyval.expr) = new WhileExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), bb );
        }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2107 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::BREAK );
        }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2111 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
        }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2118 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            dynamic_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2123 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FunctionDecl* fd = dynamic_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));
            if (fd->get_kind() != ParseConstants::fn_extern &&
                fd->get_kind() != ParseConstants::fn_extern_sequential &&
                fd->get_kind() != ParseConstants::fn_extern_update)
            {
              delete (yysemantic_stack_[(3) - (3)].node);
              error((yyloc), "Only external functions may be declared nondeterministic");
              YYERROR;
            }
            fd->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            fd->set_deterministic(false);
            (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
        }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2138 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FunctionDecl* fd = dynamic_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));
            if (fd->get_kind() != ParseConstants::fn_extern &&
                fd->get_kind() != ParseConstants::fn_extern_sequential &&
                fd->get_kind() != ParseConstants::fn_extern_update)
            {
              delete (yysemantic_stack_[(3) - (3)].node);
              error((yyloc), "Only external functions may be declared deterministic");
              YYERROR;
            }
            fd->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
        }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2155 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2159 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2163 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 2167 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 2175 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->param,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
                            (yysemantic_stack_[(4) - (4)].expr),
                            ParseConstants::fn_read,
                            true);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 2186 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->param,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
                            NULL,
                            ParseConstants::fn_extern,
                            true);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2201 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->param,
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->ret,
                            (yysemantic_stack_[(5) - (5)].expr),
                            ParseConstants::fn_sequential,
                            true);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 2212 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->param,
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->ret,
                            NULL,
                            ParseConstants::fn_extern_sequential,
                            true);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2227 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                            &* (yysemantic_stack_[(7) - (4)].fnsig)->param,
                            &* (yysemantic_stack_[(7) - (4)].fnsig)->ret,
                            (yysemantic_stack_[(7) - (6)].expr),
                            ParseConstants::fn_update,
                            true);
      delete (yysemantic_stack_[(7) - (4)].fnsig);
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2238 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->param,
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->ret,
                            NULL,
                            ParseConstants::fn_extern_update,
                            true);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2254 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            ParamList *pl = new ParamList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 2260 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
                pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2272 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2276 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2287 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EnclosedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2294 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2302 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QueryBody( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 2317 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 2321 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            std::auto_ptr<BlockBody> blk( dynamic_cast<BlockBody*>((yysemantic_stack_[(2) - (2)].expr)) );
            BlockBody *blk2 = new BlockBody( LOC((yyloc)) );
            blk2->add( (yysemantic_stack_[(2) - (1)].expr) );

            for ( int i = 0; i < blk->size(); ++i )
                blk2->add( (*blk)[i] );

            (yyval.expr) = blk2;
        }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 2335 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new BlockBody( LOC((yyloc)) );
        }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 2339 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (1)].expr));
            bb->add( (yysemantic_stack_[(3) - (2)].expr) );
            (yyval.expr) = bb;
        }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 2348 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 2352 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 212:

/* Line 678 of lalr1.cc  */
#line 2407 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 213:

/* Line 678 of lalr1.cc  */
#line 2422 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 2429 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_sliding;
        }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 2433 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_tumbling;
        }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 2440 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_start;
        }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 2444 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_end;
        }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 2448 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_only_end;
        }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 2455 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)),
                dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr),
                (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 2463 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr),
                (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2474 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 222:

/* Line 678 of lalr1.cc  */
#line 2484 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2497 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2519 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2525 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2535 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
        }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2543 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
            vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vdl;
        }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2549 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2561 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2565 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(5) - (5)].expr), true);
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2569 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)), NULL, NULL, (yysemantic_stack_[(4) - (4)].expr), false);
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2573 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)), NULL, NULL, (yysemantic_stack_[(6) - (6)].expr), true);
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2577 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)), NULL, dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)), NULL, (yysemantic_stack_[(4) - (4)].expr), false);
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2581 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)), NULL, dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (4)].node)), NULL, (yysemantic_stack_[(6) - (6)].expr), true);
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2585 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)), NULL, (yysemantic_stack_[(5) - (5)].expr), false);
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2590 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(7) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(7) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(7) - (5)].node)), NULL, (yysemantic_stack_[(7) - (7)].expr), true);
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2596 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2605 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 247:

/* Line 678 of lalr1.cc  */
#line 2615 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 248:

/* Line 678 of lalr1.cc  */
#line 2625 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 249:

/* Line 678 of lalr1.cc  */
#line 2641 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2650 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2660 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2668 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2674 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2683 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2689 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2701 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2709 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2719 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                           (yysemantic_stack_[(4) - (4)].expr));
     }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2727 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                           (yysemantic_stack_[(5) - (5)].expr));
     }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2739 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2745 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2758 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2762 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2770 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2774 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2783 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2787 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2791 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2799 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)),
                           NULL, NULL,
                           new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))),
                           VarGetsDecl::eval_var);
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2813 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2821 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2828 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2834 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2845 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2849 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2858 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2866 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2872 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2882 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2898 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2902 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2912 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2918 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2924 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2930 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2939 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2948 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2957 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2970 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 2974 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 2982 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 2988 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 2998 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3006 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3015 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3028 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3035 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3047 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3051 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3063 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3070 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3076 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3085 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3092 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3098 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3110 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3117 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3130 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3136 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3148 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3154 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3166 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3175 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3179 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3188 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3192 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3200 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3204 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 322:

/* Line 678 of lalr1.cc  */
#line 3214 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3221 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3230 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3239 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3244 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3253 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3262 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3271 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3284 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3288 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3300 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3304 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3311 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3315 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3324 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3328 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3332 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3341 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3345 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3351 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3357 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3363 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3374 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3378 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3382 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3390 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3394 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3400 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3410 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3414 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3424 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3428 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3438 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3442 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3452 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3456 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3466 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3470 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3478 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3482 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3486 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3490 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3500 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3504 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3508 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3516 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3520 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3524 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3528 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3532 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3536 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3544 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3548 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3552 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3560 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3564 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3568 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3572 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3583 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3589 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3599 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3605 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3615 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3619 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3657 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3661 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3667 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3673 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = !rpe ?
                (yysemantic_stack_[(1) - (1)].expr) : new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3684 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NULL;
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3692 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 392:

/* Line 678 of lalr1.cc  */
#line 3703 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3709 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3719 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3723 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3731 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3737 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3745 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3751 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3763 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3769 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3779 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3783 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3787 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3791 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3795 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3801 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3807 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3830 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3834 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3842 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3846 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3857 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3865 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3871 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3875 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3889 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3893 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3901 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3905 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3915 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3919 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3923 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3932 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3936 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FilterExpr(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3942 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3946 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 3954 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 3960 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 3970 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 3978 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 3982 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 3986 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 3990 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 3994 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 3998 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4002 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4006 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4010 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4018 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4022 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4030 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4037 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4044 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4055 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4063 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4067 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4075 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4083 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4091 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4145 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4149 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4162 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4168 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4178 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4182 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4190 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4194 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4198 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4206 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 462:

/* Line 678 of lalr1.cc  */
#line 4216 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 463:

/* Line 678 of lalr1.cc  */
#line 4226 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 464:

/* Line 678 of lalr1.cc  */
#line 4236 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 465:

/* Line 678 of lalr1.cc  */
#line 4246 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 466:

/* Line 678 of lalr1.cc  */
#line 4256 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 467:

/* Line 678 of lalr1.cc  */
#line 4271 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4277 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4288 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4294 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4305 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4322 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4327 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4336 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4340 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4347 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back(
                new QuoteAttrValueContent( LOC((yyloc)),std::string("\"") )
            );
            (yyval.node) = qacl;
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4355 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4361 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 481:

/* Line 678 of lalr1.cc  */
#line 4371 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4383 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4387 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4394 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4400 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4406 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4413 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4424 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4428 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4438 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4442 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4452 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4456 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4460 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4465 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4474 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4480 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4486 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4492 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4502 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4506 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4518 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4522 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4534 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4546 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4550 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4554 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4558 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4562 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4566 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4574 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4582 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval))), NULL);
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4586 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4590 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4594 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4611 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval))), NULL );
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4615 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4619 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4623 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4631 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4639 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4647 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval)), NULL );
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4651 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4655 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4659 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4667 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4673 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4683 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4691 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4695 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4699 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4734 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4740 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4746 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4756 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4760 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4764 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4768 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4772 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4779 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4785 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4795 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4803 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4807 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4811 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4815 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4819 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4823 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4827 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4831 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4835 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4843 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4851 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4855 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4859 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4869 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4889 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4893 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4901 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 4905 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 4911 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 4917 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 4921 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 4931 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 4939 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 4943 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 4949 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 4958 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 4967 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 4973 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 4979 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 4989 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5006 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5013 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5028 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5064 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5068 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5077 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5086 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new InlineFunction(LOC ((yyloc)), &*(yysemantic_stack_[(3) - (2)].fnsig)->param, &*(yysemantic_stack_[(3) - (2)].fnsig)->ret, dynamic_cast<EnclosedExpr *>((yysemantic_stack_[(3) - (3)].expr)));
          delete (yysemantic_stack_[(3) - (2)].fnsig);
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5096 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5100 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5109 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5118 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5122 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5133 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5150 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5156 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5162 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5172 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5176 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5182 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5188 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5192 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5198 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5202 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5208 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5214 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5221 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5231 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5236 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5244 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5250 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5260 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5282 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5291 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5297 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5310 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5324 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5331 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5337 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5347 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5352 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5357 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 616:

/* Line 678 of lalr1.cc  */
#line 5367 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 617:

/* Line 678 of lalr1.cc  */
#line 5380 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5386 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5403 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new EvalExpr(LOC((yyloc)), dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)), (yysemantic_stack_[(7) - (6)].expr));
        }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5407 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new EvalExpr( LOC((yyloc)), new VarGetsDeclList( LOC((yyloc)) ), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5422 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5430 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5434 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5441 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5446 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5454 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5458 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5465 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5469 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5476 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5480 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5487 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5491 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5500 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5512 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5516 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5523 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5527 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5535 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5543 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5551 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5555 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5562 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5566 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5574 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5585 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5589 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5597 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5609 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5615 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5624 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5628 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5636 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5640 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5644 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5651 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5655 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5662 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5666 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5674 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5678 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5682 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5686 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5690 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5698 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5706 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5718 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5730 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5734 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5738 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5746 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5752 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5762 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5766 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5770 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5774 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5778 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5782 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5786 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5790 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5798 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5802 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5806 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5810 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5818 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5824 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5834 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5844 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5848 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5856 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 691:

/* Line 678 of lalr1.cc  */
#line 5866 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 692:

/* Line 678 of lalr1.cc  */
#line 5877 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5884 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5895 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5899 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(1) - (1)].thesaurus_id_list);
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5906 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5911 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5920 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5929 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5933 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5940 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5944 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5952 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5961 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5968 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5978 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5982 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5989 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5995 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 6004 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 6008 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 6015 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 6020 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 6032 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 6040 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6052 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6060 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6064 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 6072 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6076 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6080 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 6088 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 6096 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 6100 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 6104 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 6108 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 6116 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 6124 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6136 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6140 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 6148 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6166 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 737:

/* Line 678 of lalr1.cc  */
#line 6179 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 6180 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 6181 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6182 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 6183 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 6184 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 6185 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6186 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 6187 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 6188 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6189 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6190 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 6191 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6192 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6193 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6197 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6198 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6199 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6200 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6201 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6202 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6203 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6204 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6205 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 6206 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6207 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6208 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6209 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 6210 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6211 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 6212 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 6213 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6214 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 6215 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 6216 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6217 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6218 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 6219 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 6220 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6221 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 6222 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 6223 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 6224 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 6225 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 6226 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6227 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 6228 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 6229 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6230 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 6231 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 6232 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 6233 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6234 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6235 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 6236 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6237 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6238 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6239 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 6240 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6241 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6242 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6243 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6244 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6245 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6246 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6247 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6248 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6249 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6250 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6251 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6252 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6253 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6254 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6255 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6256 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6257 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6258 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6259 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6260 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6261 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6262 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6263 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6264 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6265 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6266 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6267 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6268 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6269 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6270 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6271 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6272 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6273 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6274 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6275 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6276 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6277 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6278 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6279 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6280 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6281 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6282 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6283 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6284 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6285 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6286 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6287 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6288 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6289 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6290 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6291 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6292 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6293 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6294 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6295 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6296 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6297 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6298 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6299 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6300 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6301 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6302 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6303 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6304 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6305 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6306 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6307 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6308 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6309 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6310 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6311 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6312 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6313 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6314 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6315 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6316 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6317 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6318 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6319 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6320 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6321 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6322 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6323 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6324 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6325 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6326 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6327 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6328 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6329 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6330 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6331 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6332 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6333 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6334 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6335 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6336 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6337 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6338 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("deterministic"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6339 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nondeterministic"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6340 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6341 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6342 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6343 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("block"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6344 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6345 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6346 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6347 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6348 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6349 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6350 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eval"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6351 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6352 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6353 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6354 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6355 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6356 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6357 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6358 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6359 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6360 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6361 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6362 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6363 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6364 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6365 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6366 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6367 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6368 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6369 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6370 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6371 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6372 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6373 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6374 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6375 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6376 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6377 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6378 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6379 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6380 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6381 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6382 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6383 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6384 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6385 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6386 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6387 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6388 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6389 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6390 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6391 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6392 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 948:

/* Line 678 of lalr1.cc  */
#line 6393 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 949:

/* Line 678 of lalr1.cc  */
#line 6394 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 950:

/* Line 678 of lalr1.cc  */
#line 6395 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 951:

/* Line 678 of lalr1.cc  */
#line 6396 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;



/* Line 678 of lalr1.cc  */
#line 11433 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1352;
  const short int
  xquery_parser::yypact_[] =
  {
      1967, -1352, -1352,  2261,  2554,  2847, -1352, -1352,   982,   -27,
   -1352, -1352, -1352,   510, -1352, -1352, -1352, -1352,    47,   160,
     555,   167,   413,   240,   252,   103, -1352,    52, -1352, -1352,
   -1352, -1352, -1352, -1352, -1352,   556, -1352,   284,   357, -1352,
     253, -1352, -1352,   285, -1352,   566, -1352,   405,   458, -1352,
     196, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352,   450,   520, -1352, -1352, -1352, -1352,
     441,  8121, -1352, -1352, -1352,   529, -1352, -1352, -1352, -1352,
   -1352,   611,   623, -1352, -1352, 11253, -1352, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352,   419, -1352, -1352,   631,   648, -1352,
   -1352, -1352, -1352, -1352, -1352, -1352,  3140, 11253, -1352, -1352,
   -1352, -1352, -1352, -1352, -1352,   470, -1352, -1352,   653,  8992,
   -1352,  9279,   658,   660, -1352, -1352, -1352,   664, -1352,  7828,
   -1352, -1352, -1352, -1352, -1352, -1352,   636, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352, -1352,    53,   321, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352, -1352,   -55,   638,   266, -1352,   572,
     475, -1352, -1352, -1352, -1352, -1352, -1352,   677, -1352,   644,
     558,   560,   561, -1352, -1352,   643,   650, -1352,   682, -1352,
   -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352,  5191,
     799, -1352,  5484, -1352, -1352,   112,    60,    72, -1352, -1352,
   -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352,   -15,
   -1352, -1352, -1352, -1352,   138, -1352, -1352, -1352, -1352, -1352,
   -1352,   641,   717, -1352,   628,   568,   154,    -4,   354,   211,
   -1352,   762,   619,   716,   718,  5777, -1352, -1352, -1352,   -29,
   -1352, -1352,  7828, -1352,   534, -1352,   665,  8121, -1352,   665,
    8121, -1352, -1352, -1352,   526, -1352, -1352, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352,   675,   667,
   -1352, -1352, -1352, -1352, -1352,   642, -1352,   645, -1352,   652,
     795,   387,   467,   -25,   453, 11535,   453, 11253,   -43,   777,
     778,   787, 11253,   685,   719,   316,  8992, -1352, -1352,   511,
     438,   594, 11253, -1352, -1352, -1352, -1352, -1352,   549, 11253,
     546,   547,   440,   542,   382, -1352, -1352, -1352, -1352, -1352,
    8992,  6070,   662,  6070,    26,  6070,  9843,  6070,   563,   567,
   11253,   730,   -34,   698,  6070,    46,   272, 11253,  6070,  8703,
   11253, 11253, 11253, 11253,  6070,   666,  6070,  6070, 11253,  6070,
     700,   701, -1352, -1352, -1352,  6070, 10125,   699, -1352,   702,
   -1352, -1352, -1352, -1352, -1352,   704, -1352, -1352,   707, -1352,
   -1352, -1352, -1352, -1352,   708, -1352, -1352, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352, -1352, 11253, -1352, -1352, -1352,   670,
     822,  6070, -1352, -1352,    58, -1352, -1352,   844, -1352, -1352,
   -1352, -1352,  6070,   654, -1352,   838,  6070,  6070,   683,  6070,
    6070,  6070,  6070,   639, 11253, -1352, -1352, -1352, -1352,  6070,
    6070,  6070, 11253, -1352, -1352, -1352, -1352,   982,   103,    74,
      90,   862,  6363,  6363,  6656,  6656,  6070, -1352,  6070,   752,
     413,    52,   705,   706,   709,  6070,  6070, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352,  6949,  6949,  6949, -1352,  6949,  6949,
   -1352,  6949, -1352,  6949, -1352, -1352, -1352, -1352, -1352, -1352,
   -1352,  6949,  6949,   801,  6949,  6949,  6949,  6949,  6949,  6949,
    6949,  6949,  6949,  6949,  6949,   646,   776,   781,   782, -1352,
   -1352, -1352,  3433, -1352, -1352,  7828,  7828,  6070,   665, -1352,
   -1352,   665, -1352,  3726,   665,   731,  4019, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352, -1352, -1352,   773,   774, -1352,   240,
   -1352,   854, -1352, -1352, 11535, -1352, 11535,   606,   389, 11253,
     565,   724,   725,   606,   795,   759,   755, -1352, -1352, -1352,
   -1352, -1352,    18,   655,   -20, -1352,   590, -1352, -1352, -1352,
   -1352, 11253, 11253, 11253, -1352,   757,   712, -1352,   714,   702,
     357, -1352,   713,   715,   721, -1352,   203,   232,   722, -1352,
   -1352,   790, -1352,    13, 11253,     7, 11253,   810,   236, -1352,
    6070, -1352,   723,  8992,   809,   864,  8992,   795,   813,   800,
   -1352,     8,   729,   727, -1352,   735,   736,   737,   784,    17,
   -1352,    50,   733, -1352,   738,   743,   779, -1352,   747,  6070,
    6070,   748, -1352,   245,   247,   216, -1352, 11253,   822, -1352,
     -14,   750, -1352, -1352, -1352,   751, -1352,   -16, -1352, -1352,
   -1352,   -23,   182,   839,   703,   720,    -8, -1352,   794,  7242,
   -1352,   753,   754,    76, -1352, -1352,   112,   295,   907,   907,
   -1352,   102, -1352, -1352,   114, -1352, -1352,  1511, -1352, -1352,
   -1352, -1352, -1352,    -6, 11253,   775,  6070,   827, -1352, -1352,
     717, -1352, -1352, -1352, -1352, -1352,  6949, -1352, -1352, -1352,
      16,    -4,    -4,   369,   354,   354,   354,   354,   211,   211,
   -1352, -1352, 10689, 10689, 11253, 11253, -1352,   764, -1352, -1352,
     765, -1352, -1352, -1352,   248, -1352, -1352,   249,   394,   427,
     472, -1352,   240,   240, -1352, -1352, -1352, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352,   606, -1352,   816, 10971,   808,  6070,
   -1352, -1352, -1352,   855,   814,  6070,   795,   795,   606, -1352,
     613,   795,   423, 11253,    79,   384,   923, -1352, -1352,   672,
      45, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352,
   -1352, -1352,    18,   355,   457, -1352,   739,   289,     1,   657,
     795, -1352, -1352, -1352, -1352,   805, 11253, -1352, 11253, -1352,
   -1352,   842,   835, 10689,   846,  6070,   847,   -44,   820,    15,
      55,   726, -1352, -1352,   545,     7,   855, 10689,   849,   873,
     789,   786,   841,   795,   815,   845,   872,   795,   859,  6070,
     843,   -82,   830, -1352, -1352, -1352, -1352,  6070,   861,  6070,
    6070,   837, -1352,   885,   886,  6070, -1352,   806,   807,   840,
   11253, -1352, 11253, -1352,  6070,   953, -1352,   -13, -1352,    91,
   -1352, -1352,   962, -1352,   435,  6070,  6070,  6070,   454,  6070,
    6070,  6070,  6070,  6070,  6070,   875,  6070,  6070,   719,   180,
     817,   644,   758,   848,   877,   116,   277,  1511,  6656,  6656,
    6656,   911, -1352, -1352,  6070,   501,   889, -1352, 11253,   890,
   -1352, -1352,  6070,    16,   446,   -22, -1352,   728,   -31,   742,
     744, -1352, -1352,   594, -1352,   740,   386,   851,   852, 10971,
     853, -1352,   368, -1352, -1352, -1352, -1352, -1352, -1352, -1352,
   -1352, -1352,   860, -1352, -1352, -1352,  6070, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352,  6070, -1352,   492,   499, -1352,   976,
     581, -1352, -1352, -1352,  6070, -1352, -1352, -1352, -1352, -1352,
   -1352, -1352,   732, -1352, -1352,   981, -1352, -1352, -1352, -1352,
   -1352,   224,   984, -1352,   539, -1352, -1352, -1352,   699,   160,
     704,   284,   707,   708,   638,   780,   368,   793,   796,  7535,
     741,   749,   355, -1352,   804,   856,  4312,   850,   857,   882,
     858,   866, 11253,    32, -1352, 11253, -1352, 11253,  6070,   887,
    6070,   905,  6070,    -3,   888,  6070,   891, -1352,   914,   918,
    6070, 11253,   624,   961, -1352, -1352, -1352, -1352, -1352, -1352,
   10689, -1352,  6070,   795,   939, -1352, -1352, -1352,   795,   939,
   11253, -1352,  6070,  6070,   913,  4605, -1352, 11253, -1352, -1352,
    6070,  6070,   548, -1352,    -9, 10407,   559, -1352,   870, -1352,
   -1352,  4898,   871,   874, -1352, -1352,   924, -1352,   120, -1352,
   -1352,  1049, -1352, -1352, 11253, -1352, -1352,   392, -1352, -1352,
   -1352,   878,   831,   833, -1352, -1352, -1352,   867,   869, -1352,
   -1352, -1352, -1352, -1352,   834, 11253,   881, -1352,   926, -1352,
     719, -1352, -1352, -1352,  8414,   758, -1352,  6070, 11253,   907,
     338, -1352, -1352, -1352,   889, -1352,   795, -1352,   633, -1352,
      22,   963, -1352,  6070,   964,   827,   892,   893, -1352,    16,
     823, -1352, -1352,   199, -1352,   337,   -37,   824,    16,   337,
    6949, -1352,   141, -1352, -1352, -1352, -1352, -1352, -1352,    16,
     930,   797,   655,   -37, -1352, -1352,   798,  1000, -1352, -1352,
   -1352,  9561,   895,   896,   899, -1352, -1352, -1352, -1352, -1352,
   -1352,   903, -1352, -1352, -1352,  6070, -1352, -1352, -1352, -1352,
   -1352,  1058,   168,  1059,   168,   819,   992, -1352, -1352, -1352,
   -1352,   922, 11253,   863,   780,  7535, -1352, -1352,   910, -1352,
   -1352, -1352, -1352, -1352, -1352,  6070,   954, -1352, -1352, -1352,
    6070, -1352,    38, -1352,  6070,   955,  6070, -1352,  6070, 11253,
   11253, -1352,   479, -1352,  6070, -1352,   977,  1006,   795,   939,
   -1352, -1352, -1352,  6070, -1352,   925, -1352, -1352, -1352,   920,
   -1352,  6070,  6070, 11253,   921,    -7, -1352, -1352, -1352,   928,
   -1352, -1352,   953, 11253,   448, -1352,   953, 11253, -1352, -1352,
    6070,  6070,  6070,  6070,  6070, -1352,  6070,  6070, -1352, -1352,
       5, -1352,   929, -1352, -1352, -1352, -1352,   963, -1352, -1352,
   -1352,   795, -1352, -1352, -1352, -1352, -1352,   931,  6949, -1352,
   -1352, -1352, -1352, -1352,   281,  6949,  6949,   359, -1352,   742,
   -1352,   299, -1352,   744,    16,   956, -1352, -1352,   828, -1352,
   -1352, -1352, -1352,  1017,   934, -1352,   250, -1352, -1352, -1352,
   -1352,    20, -1352,   358,   358, -1352,   168, -1352, -1352,   260,
   -1352,  1086,   -37,   935,  1008, -1352,  7535,   -56,   836, -1352,
     947, -1352, -1352,  6070, -1352,  6070,   978, -1352,  6070, -1352,
   -1352, -1352,  1068, -1352, -1352,  6070,   795, -1352, -1352, -1352,
    6070, -1352, -1352,  1028,  6070, 11253,  6070, -1352,    -5,   953,
   11253,   932,   953, -1352, -1352, -1352, -1352, -1352, -1352, -1352,
    1007,  8414, -1352, -1352, -1352, -1352, -1352,   354,  6949,  6949,
     369,   379, -1352, -1352, -1352, -1352, -1352, -1352,  6070, -1352,
   10689, -1352, 10689,  1032, -1352, -1352, -1352, -1352,  1100, -1352,
   -1352, -1352,   868, -1352,   992,  1022, -1352,   362, 11253,  1012,
     912, 11253,  7535, -1352, -1352,  6070, -1352,  1014, -1352,   939,
   -1352, 10689, -1352,   949, -1352,   395,    73, -1352,   941,   953,
   -1352,   942, 11253, -1352,   369,   369,  6949,   957, -1352, -1352,
   10689, -1352, -1352, -1352,  7535, -1352,   963,   865, 11253,  1019,
     927,  1022, -1352, 11253,   958,  6070, -1352, -1352,  1046,   433,
   -1352, -1352, -1352, -1352,   965,   416, -1352, -1352, -1352,   950,
   -1352,   275,   369, -1352, -1352, -1352, -1352,  6070,   880, 11253,
    1025, -1352,  6070, -1352, -1352, -1352, -1352, -1352, -1352, -1352,
   -1352,  1027,   996, -1352,   876,   883, 11253, -1352, 11253, -1352,
     884,  6070,   897,   294,  7535, -1352,  7535,  1034,   996, -1352,
     959, 11253, -1352,   879,   968, 11253,   996,   937, -1352,  1036,
   11253,   898,  7535, -1352
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   423,   424,     0,     0,     0,   752,   577,   843,   852,
     793,   757,   755,   738,   844,   847,   800,   893,   761,   739,
     740,   905,   792,   853,   742,   850,   822,   802,   777,   797,
     894,   798,   848,   845,   796,   744,   851,   745,   746,   891,
     907,   890,   794,   813,   807,   747,   795,   749,   748,   892,
     831,   799,   774,   917,   918,   919,   920,   921,   922,   923,
     924,   925,   926,   927,   941,   948,   821,   817,   808,   788,
     737,     0,   816,   824,   832,   942,   812,   443,   789,   790,
     846,   943,   949,   809,   826,     0,   449,   412,   445,   819,
     754,   810,   811,   839,   814,   830,   838,   947,   950,   760,
     801,   841,   444,   829,   834,   741,     0,     0,   361,   827,
     837,   842,   840,   820,   806,   895,   804,   805,   944,     0,
     360,     0,   945,   951,   835,   791,   815,   946,   390,     0,
     422,   836,   818,   825,   833,   828,   896,   782,   787,   786,
     785,   784,   783,   750,   803,     0,   753,   849,   775,   882,
     881,   883,   759,   758,   778,   888,   743,   880,   885,   886,
     877,   781,   823,   879,   889,   887,   878,   779,   884,   898,
     901,   902,   899,   900,   897,   751,   903,   904,   906,   869,
     868,   855,   773,   766,   862,   858,   776,   772,   871,   872,
     762,   763,   756,   765,   867,   866,   863,   859,   876,   870,
     865,   861,   854,   764,   875,   874,   768,   770,   769,   860,
     864,   856,   771,   857,   767,   873,   928,   929,   930,   931,
     932,   933,   909,   910,   908,   914,   915,   916,   911,   912,
     913,   780,   934,   935,   936,   937,   938,   939,   940,     0,
       0,     2,     0,     5,     7,    19,     0,     0,    24,    27,
      37,    30,    31,    32,    58,    33,    42,    38,    62,    63,
      64,    59,    60,    66,    67,    36,    34,    35,    40,    41,
      61,   211,   210,   207,   208,   209,    39,    14,   187,   188,
     192,   194,   226,   232,     0,   224,   225,   195,   196,   197,
     198,   199,   316,   318,   320,   330,   334,   336,   339,   344,
     347,   350,   352,   354,   356,     0,   358,   364,   366,     0,
     382,   365,   386,   389,   391,   394,   396,     0,   401,   398,
       0,   409,   419,   421,   395,   425,   432,   441,   433,   434,
     435,   438,   439,   436,   437,   456,   458,   459,   460,   457,
     505,   506,   507,   508,   509,   510,   418,   551,   543,   550,
     549,   548,   545,   547,   544,   546,   442,   440,   578,   579,
      65,   200,   201,   203,   202,   204,   205,   206,   420,   736,
     843,   852,   850,   512,   753,     0,   516,     0,   522,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   115,   116,     0,
       0,     0,     0,   111,   112,   113,   114,   121,     0,     0,
       0,     0,     0,     0,     0,   109,   168,   171,   174,   173,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   414,   417,   404,     0,     0,   738,   761,   740,
     905,   792,   853,   742,   802,   744,   907,   813,   747,   749,
     748,   831,   941,   948,   737,   942,   943,   949,   814,   947,
     950,   895,   944,   945,   951,   946,   896,   888,   880,   886,
     877,   779,   898,   901,   902,   899,   751,   903,   906,   410,
     420,   736,   402,   403,   406,   738,   739,   740,   744,   745,
     746,   747,   737,   743,   446,     0,   408,   407,   447,     0,
     472,     0,   413,   734,     0,   735,   385,     0,   416,   415,
     405,   388,     0,     0,   501,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   158,   155,   166,   167,     0,
       0,     0,     0,     3,     1,     6,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   190,   189,     0,
       0,     0,     0,     0,     0,     0,     0,   212,   231,   227,
     233,   228,   230,   229,     0,     0,     0,   375,     0,     0,
     373,     0,   325,     0,   374,   367,   372,   371,   370,   369,
     368,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   363,
     362,   359,     0,   383,   387,     0,     0,     0,   397,   429,
     400,   399,   411,     0,   426,     0,     0,   513,   517,   523,
     733,    84,    69,    70,   149,   150,     0,     0,   170,     0,
     169,     0,    75,    76,     0,   172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   588,   589,   590,
     118,   117,     0,    74,   125,   122,     0,   124,   123,   120,
     119,     0,     0,     0,   110,     0,     0,   557,     0,     0,
       0,   553,     0,     0,     0,   567,     0,     0,     0,   214,
     215,   234,   235,     0,     0,     0,     0,   151,     0,   181,
       0,   581,     0,     0,    93,     0,     0,     0,    85,   251,
     252,     0,     0,     0,   558,     0,     0,     0,     0,     0,
     299,     0,     0,   556,     0,     0,     0,   575,     0,     0,
       0,     0,   561,     0,     0,     0,   448,   473,   472,   469,
       0,     0,   503,   502,   384,     0,   500,     0,   601,   602,
     552,     0,     0,     0,     0,     0,     0,   607,     0,     0,
     164,     0,     0,     0,   254,   271,    20,     0,    21,     0,
       4,     0,    25,    11,     0,    26,    15,   843,    28,    12,
      29,    16,   193,     0,     0,     0,     0,     0,   213,   272,
     317,   319,   323,   329,   328,   327,     0,   324,   321,   322,
       0,   338,   337,   335,   341,   342,   343,   340,   345,   346,
     349,   348,     0,     0,     0,     0,   380,     0,   392,   393,
       0,   430,   427,   454,     0,   580,   452,     0,     0,     0,
       0,    73,     0,     0,    48,    50,    51,    52,    53,    55,
      56,    57,    49,    54,    44,    45,     0,     0,   101,     0,
      97,    99,   100,   104,   107,     0,     0,     0,    43,    83,
       0,     0,     0,     0,     0,     0,     0,   683,   688,     0,
       0,   684,   718,   671,   673,   674,   675,   677,   679,   678,
     676,   680,     0,     0,     0,   126,     0,     0,   129,     0,
       0,   521,   511,   554,   555,     0,     0,   571,     0,   568,
     620,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   216,   217,     0,   222,   183,     0,     0,   152,
       0,     0,     0,     0,     0,     0,    86,     0,     0,     0,
       0,     0,     0,   560,   559,   566,   574,     0,     0,     0,
       0,     0,   520,     0,     0,     0,   376,     0,     0,     0,
       0,   564,     0,   562,     0,   472,   470,     0,   461,     0,
     450,   451,     0,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   843,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   191,   223,     0,   283,   279,   281,     0,   273,
     274,   326,     0,     0,     0,     0,   649,   332,   622,   626,
     628,   630,   632,   635,   642,   643,   651,   853,   741,     0,
     750,   351,   529,   535,   536,   538,   582,   583,   539,   542,
     353,   355,   526,   357,   381,   431,     0,   428,   453,    81,
      82,    79,    80,   176,     0,   175,     0,     0,    46,     0,
       0,   102,   103,   105,     0,   106,    71,    72,    77,    78,
      68,   689,     0,   692,   719,     0,   682,   681,   686,   685,
     717,     0,     0,   694,     0,   690,   693,   672,     0,     0,
       0,     0,     0,     0,     0,   127,   133,     0,     0,     0,
       0,     0,     0,   130,     0,     0,     0,     0,     0,   575,
       0,     0,     0,     0,   528,     0,   237,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   218,     0,     0,
       0,     0,   265,     0,   262,   267,   221,   184,   153,   182,
       0,   185,     0,     0,    95,    89,    92,    91,     0,    87,
       0,   256,     0,     0,     0,     0,   163,     0,   297,   301,
       0,     0,     0,   304,     0,     0,     0,   311,     0,   378,
     377,     0,     0,     0,   298,   473,     0,   462,     0,   496,
     493,     0,   497,   498,     0,   499,   492,     0,   467,   495,
     494,     0,     0,     0,   594,   595,   591,     0,     0,   599,
     600,   596,   605,   603,     0,     0,     0,   609,   161,   160,
       0,   157,   156,   165,     0,   610,   611,     0,     0,    22,
       0,    13,    17,    18,   280,   292,     0,   293,     0,   284,
     285,   286,   287,     0,   276,     0,     0,     0,   633,   646,
       0,   331,   333,     0,   665,     0,     0,     0,     0,     0,
       0,   621,   623,   624,   660,   661,   662,   664,   663,     0,
       0,   637,   636,     0,   640,   644,   658,   656,   655,   648,
     652,     0,     0,     0,     0,   532,   534,   533,   530,   527,
     455,     0,   178,   177,   180,     0,    47,    98,   108,   706,
     687,     0,   711,     0,   711,   700,   695,   128,   134,   136,
     135,     0,     0,     0,   131,     0,    23,   514,     0,   572,
     573,   576,   569,   570,   236,     0,     0,   249,   250,   241,
       0,   245,     0,   239,     0,     0,     0,   260,     0,     0,
       0,   220,   263,   266,     0,   154,     0,    94,     0,    88,
     253,   258,   257,     0,   524,     0,   300,   302,   307,     0,
     305,     0,     0,     0,     0,     0,   312,   379,   518,     0,
     565,   563,   472,     0,     0,   504,   472,     0,   468,    10,
       0,     0,     0,     0,     0,   608,     0,     0,   159,   617,
       0,   612,     0,   255,   296,   294,   295,   288,   289,   290,
     282,     0,   277,   275,   650,   641,   647,     0,     0,   720,
     721,   731,   730,   729,     0,     0,     0,     0,   722,   627,
     728,     0,   625,   629,     0,     0,   634,   638,     0,   659,
     654,   657,   653,     0,     0,   540,     0,   537,   587,   531,
     186,     0,   707,     0,     0,   705,   712,   713,   709,     0,
     704,     0,   702,     0,   696,   697,     0,     0,     0,   132,
       0,   515,   238,     0,   247,     0,     0,   243,     0,   246,
     261,   269,   270,   264,   219,     0,     0,    90,   259,   525,
       0,   308,   306,     0,     0,     0,     0,   519,     0,   472,
       0,     0,   472,   592,   593,   597,   598,   604,   606,   162,
       0,     0,   613,   619,   291,   278,   645,   732,     0,     0,
     724,     0,   670,   669,   668,   667,   666,   631,     0,   723,
       0,   584,     0,     0,   179,   716,   715,   714,     0,   708,
     701,   699,     0,   691,     0,   137,   139,   141,     0,     0,
       0,     0,     0,   242,   240,     0,   248,     0,   315,    96,
     303,     0,   313,     0,   309,   482,   476,   471,     0,   472,
     463,     0,     0,   618,   726,   725,     0,     0,   585,   541,
       0,   710,   703,   698,     0,   143,   142,     0,     0,     0,
       0,   138,   244,     0,     0,     0,   490,   484,     0,   483,
     485,   491,   488,   478,     0,   477,   479,   489,   465,     0,
     464,     0,   727,   639,   586,   140,   144,     0,     0,     0,
       0,   268,     0,   310,   475,   486,   487,   474,   480,   481,
     466,     0,     0,   145,     0,     0,     0,   314,     0,   614,
       0,     0,     0,     0,     0,   147,     0,     0,     0,   146,
       0,     0,   615,     0,     0,     0,     0,     0,   616,     0,
       0,     0,     0,   148
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1352, -1352,  -222,   917, -1352,   915,   916, -1352,   908,  -235,
    -510,  -537, -1352,   489,  -380, -1352, -1352, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352,  -924,
   -1352, -1352, -1352, -1352,    99,   303,   768, -1352, -1352,   760,
   -1352,    64,  -883, -1352,  -367,  -397, -1352, -1352,  -606, -1352,
    -897, -1352, -1352,   -39, -1352, -1352, -1352, -1352, -1352,   345,
     783, -1352, -1352, -1352,   244,   756, -1351,  -532,    -1, -1352,
    -561,   373, -1352, -1352, -1352, -1352,   243, -1352, -1352,   901,
   -1352, -1352, -1352, -1352,    69,  -697,  -687, -1352, -1352, -1352,
      33, -1352, -1352,  -156,    54,   -30, -1352, -1352, -1352,   -48,
   -1352, -1352,   186,   -41, -1352, -1352,   -28, -1193, -1352,   676,
      36, -1352, -1352,    34, -1352, -1352, -1352,    35, -1352, -1352,
     615,   621, -1352,  -512, -1352, -1352,  -601,   157,  -590,   147,
     159, -1352, -1352, -1352, -1352, -1352,   902, -1352, -1352, -1352,
   -1352,  -763,  -300, -1040, -1352,  -108, -1352, -1352, -1352, -1352,
   -1352, -1352, -1352,   -36, -1188, -1352, -1352,   397,    77, -1352,
    -761, -1352, -1352, -1352, -1352, -1352, -1352, -1352,   573, -1352,
    -930, -1352,    30, -1352,   456,  -732, -1352, -1352, -1352, -1352,
   -1352,  -375,  -368, -1136,  -971, -1352, -1352, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352, -1352,   390,  -720,  -811,   118,  -803,
   -1352,   -42,  -800, -1352, -1352, -1352, -1352, -1352, -1352, -1352,
     788,   792,  -586,   309,   162, -1352, -1352, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352, -1352,    14,
   -1352, -1352,     3, -1352, -1352,  -968, -1352, -1352, -1352,   -26,
     -35,  -191,   212, -1352, -1352, -1352, -1352, -1352, -1352, -1352,
   -1352, -1352, -1352, -1352, -1352, -1352,   -19, -1352, -1352, -1352,
    -186,   204,   342, -1352, -1352, -1352, -1352, -1352,   145, -1352,
   -1352, -1254, -1352, -1352, -1352,  -646, -1352,   -64, -1352,  -201,
   -1352, -1352, -1352, -1352, -1180, -1352,   -10, -1352,  -372,  -355,
      63,   -71
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   240,   779,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   854,   855,   856,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,  1144,
     717,   264,   265,   860,   861,   862,  1208,   266,   414,   415,
     267,  1095,   895,   268,  1525,  1526,   269,   270,   433,   271,
     546,   769,   989,  1209,   272,   273,   274,   275,   276,   416,
     417,   418,   419,   708,   709,  1185,  1055,   277,   278,   568,
     279,   280,   281,   577,   431,   924,   925,   282,   578,   283,
     580,   284,   285,   701,   702,  1132,   918,   286,   719,   773,
     720,   705,  1133,  1134,  1135,   774,   581,   582,  1009,  1010,
    1392,   583,  1006,  1007,  1229,  1230,  1231,  1232,   287,   729,
     730,   288,  1162,  1163,  1164,   289,  1166,  1167,   290,   291,
     292,   293,   806,   294,  1241,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   601,   602,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   628,   629,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   834,   334,
     335,   336,  1187,   748,   749,   750,  1547,  1584,  1585,  1578,
    1579,  1586,  1580,  1188,  1189,   337,   338,  1190,   339,   340,
     341,   342,   343,   344,   345,  1041,   919,  1031,  1278,  1032,
    1426,  1033,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   736,  1108,   356,   357,   358,   359,  1035,  1036,
    1037,  1038,   360,   361,   362,   363,   364,   365,   766,   767,
     366,  1215,  1216,  1380,   367,  1017,  1251,  1252,  1018,  1019,
    1020,  1021,  1022,  1261,  1416,  1417,  1023,  1264,  1024,  1397,
    1025,  1026,  1269,  1270,  1422,  1420,  1253,  1254,  1255,  1256,
    1505,   673,   883,   884,   885,   886,   887,   888,  1085,  1443,
    1444,  1086,  1442,  1521,   889,  1294,  1439,  1435,  1436,  1437,
     890,   891,  1257,  1265,  1407,  1258,  1403,  1242,  1145,   524,
     368,   369
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       501,   941,   375,   377,   379,   813,   917,   793,   641,   623,
     560,   951,  1040,  1149,   501,  1103,   967,   814,   815,   816,
     817,   531,  1034,  1034,   563,   565,  1379,   788,   790,  1492,
     783,   786,   789,   791,   940,   499,   501,  1388,  1389,  1186,
       7,   666,  1445,   840,   912,  1237,  1121,  1015,   501,  1016,
     501,  1368,   782,   785,  1060,  1153,  1404,  1034,  1528,  1301,
     921,   561,  1243,   714,   718,   685,   752,   689,   974,   872,
     640,   893,   873,   561,   802,   561,   803,   804,   533,   805,
     706,   807,  1179,  1418,   725,  1545,   690,  1351,   566,   808,
     809,   561,  1102,  1096,  1213,   985,  1582,   566,  1118,   913,
    1179,  1180,  1114,   561,   913,   519,   914,  1475,   914,   607,
     972,   968,  1177,  1034,   874,   561,  1138,   561,   993,   622,
     948,   652,    77,   566,  1226,   914,  1239,  1034,   420,  1179,
    1180,   914,   435,  1244,   500,    88,   646,   608,  1082,  1324,
     557,   913,   121,  1063,  1228,   939,   913,   707,   514,   121,
     609,   647,   653,  1054,  1083,   915,  1490,  1122,   558,  1283,
     102,   436,  1529,   536,  1012,   537,   437,  1013,   973,   567,
     520,  1352,  1546,  1476,  1315,   569,   969,  1178,  1002,   994,
    1455,   570,   525,   610,   527,   916,   571,   121,   975,   976,
    1181,  1182,   950,  1183,  1494,   423,  1084,  1125,  1514,   949,
    1126,   713,  1583,   977,   624,   572,  1137,   691,  1491,  1182,
     894,  1183,  1297,  1405,  1406,  1245,  1246,   922,  1247,  1181,
     986,   710,  1123,   916,  1339,  1248,  1273,   753,  1368,  1034,
    1119,   894,  1124,  1176,  1243,  1249,  1056,  1057,  1182,   710,
    1183,   788,   790,   107,   562,  1530,   501,  1250,  1186,   501,
    1015,  1015,  1016,  1016,  1154,   923,   564,  1186,   776,   119,
     534,  1619,  1522,   875,   916,  1450,   782,   785,   710,  1014,
    1563,  1396,   107,   978,   778,   916,   876,  1632,   877,  1184,
     916,   630,   916,  1210,   632,  1638,   998,   448,   119,   878,
     879,   880,   869,   881,  1011,   882,   640,   145,  1000,  1433,
    1219,   573,  1096,  1553,   574,  1244,   906,   604,  1363,   380,
     381,   424,   382,   383,   649,   427,   501,  1291,   575,   948,
    1107,   501,  1110,   996,   605,   501,   145,   781,   784,  1335,
    1498,   501,   388,  1292,  1565,   908,  1076,   777,   501,   928,
    1034,   558,   613,   576,   449,   936,   606,  1077,   960,   501,
     962,  1046,  1046,  1512,  1354,   501,   614,   661,   932,   501,
     662,   935,  1434,  1518,  1211,  1034,   501,   442,   501,   501,
     501,   501,   501,  1596,  1172,  1293,  1173,   501,  1611,   661,
     500,   715,   662,   500,   907,   501,  1220,  1245,  1246,  1088,
    1247,   432,   663,   979,   980,  1089,   689,  1627,   964,   443,
    1576,  1179,  1180,   434,  1179,  1499,  1527,  1249,   981,  1399,
     450,   451,  1090,   909,  1091,   690,  1316,   929,   664,  1250,
     686,  1449,   688,  1092,   694,  1179,   961,   716,   963,  1047,
    1048,  1513,   396,   712,  1186,   440,  1325,   722,  1576,  1582,
     664,  1519,  1179,   732,   501,   734,   735,  1400,   738,  1093,
     651,  1291,   604,   913,   741,   657,  1612,  1179,  1180,   525,
    1425,   788,   790,   788,  1226,   674,  1221,  1222,  1223,   605,
       7,  1034,   676,   501,  1058,  1628,  1015,   428,  1016,   665,
     857,   501,   429,   525,   539,  1015,   540,  1016,  1058,   697,
     399,  1181,  1527,   703,  1066,  1067,  1015,   385,  1016,  1070,
     721,   665,   525,   726,   727,   728,   731,  1275,   441,  1293,
    1182,   737,  1183,  1182,   389,  1183,   390,   828,   829,   744,
     751,   858,   604,  1577,  1527,   391,   859,   430,  1105,  1128,
     535,   755,   604,   515,  1182,  1129,  1183,  1049,  1276,   605,
     710,   995,  1539,   710,   107,  1608,   397,  1181,   611,   605,
     772,  1182,    77,  1183,  1050,  1277,   446,   612,   454,   999,
     119,  1605,  1502,   642,   710,    88,  1182,   452,  1183,  1503,
    1051,  1556,   914,  1094,  1581,  1587,   643,   398,   731,  1504,
    1367,   710,  1100,   842,  1629,   843,  1630,  1052,   501,   455,
     102,  1101,   456,  1225,  1012,  1128,   710,  1013,   145,  1401,
     107,  1129,  1643,  1226,  1053,   400,  1402,   768,  1581,   447,
     501,   501,   501,  1227,  1587,   775,   119,   121,   521,  1130,
    1054,   827,  1502,  1228,  1282,  1456,   830,  1266,  1267,  1503,
    1478,  1284,  1082,   501,  1481,   501,  1480,   453,   914,  1504,
     545,  1078,   501,   644,  1161,   501,   502,  1285,  1083,  1411,
    1268,  1015,  1079,  1016,   145,  1165,   645,  1349,   421,  1131,
    1192,   422,  1193,   682,   403,   404,   405,   406,  1355,   407,
     408,   683,   410,   411,  1128,   627,   501,   633,   412,  1197,
    1129,  1198,   788,   844,   845,   846,   847,   848,   849,   850,
     851,   852,   853,   542,  1071,  1072,  1073,   864,   543,  1558,
    1074,  1559,   865,   425,   438,   831,   426,   439,   831,   930,
    1034,   831,  1034,   858,   444,   623,   631,   445,   859,   625,
     626,   634,   863,   501,  1431,   667,   668,   669,   503,   648,
    1574,   650,   670,   671,   679,   680,  1068,  1069,   957,   958,
     504,  1034,  1097,  1098,   897,   898,   899,  1548,   516,  1594,
    1551,   501,   501,   501,   501,   586,  1385,  1386,   818,   819,
    1034,   811,   812,   587,   588,   517,   589,   920,   990,   926,
     522,  1337,   820,   821,   590,   528,   525,   529,   591,   525,
     592,   530,  1042,  1042,   532,   593,   501,  1515,  1516,   538,
     541,   544,   545,   547,   550,   548,   552,   549,   551,   554,
     698,   594,   501,   584,  1500,  1501,   585,  1566,  1497,   615,
     965,   603,   616,   617,   627,   635,   618,  1589,   636,   640,
     637,   654,   385,   638,   595,   596,   597,   598,   599,   600,
     639,   656,   658,   659,   672,   501,   675,   501,   677,   678,
     681,   699,   501,   687,   704,   700,   710,   733,   739,   740,
     422,   746,   747,   426,  1384,   439,   501,  1003,   445,   456,
     754,   756,   757,   765,   760,   780,   794,   823,   795,   810,
     822,   796,   824,   825,   797,   835,   838,   839,   841,   866,
     867,   870,   871,   896,   900,  1039,  1039,  1039,  1039,   501,
     901,   501,   902,   911,   903,   892,   904,  1554,  1555,   905,
     910,   927,   933,   938,   931,   934,   937,   942,   943,   758,
     759,   952,   761,   762,   763,   764,   944,   945,   946,   953,
    1039,   947,   770,   771,   954,   956,   959,   955,   970,   971,
     982,   987,   992,   983,   991,   997,  1075,   501,   984,   792,
    1004,  1008,  1044,  1059,  1045,   859,   913,  1080,   798,   799,
    1104,  1064,  1081,  1106,  1168,  1592,  1112,  1113,   501,  1099,
    1115,  1117,  1120,   706,  1140,  1148,  1467,  1141,  1143,  1109,
    1146,  1109,  1147,  1150,  1127,  1157,  1039,  1142,  1155,  1160,
    1152,  1161,  1165,  1175,  1169,  1170,  1191,   663,  1171,  1205,
    1039,  1218,  1233,  1235,  1259,  1212,  1217,  1214,  1260,  1279,
       7,  1263,  1271,  1272,  1274,  1290,   833,  1240,  1295,   833,
     894,  1236,  1289,  1299,   380,   381,  1300,   382,   383,  1495,
     384,  1311,  1302,   737,  1305,   737,   385,  1322,  1329,  1320,
    1326,  1309,  1330,  1328,   386,  1334,   387,   388,  1310,  1312,
    1306,   501,  1338,   389,   501,   390,   501,  1313,  1357,  1303,
    1343,  1362,  1360,  1281,   391,  1361,  1365,  1370,   392,  1371,
     501,  1376,  1369,  1377,  1374,  1226,  1391,  1398,  1408,   501,
    1394,  1234,  1414,  1415,  1395,  1421,  1427,  1428,  1419,   501,
    1429,  1430,  1432,  1438,  1441,  1082,   501,  1446,  1451,   393,
     394,   395,  1039,  1372,   501,  1373,  1453,  1458,  1465,  1466,
    1470,  1474,  1509,  1469,  1508,  1308,  1477,  1493,  1510,  1496,
    1520,  1524,  1532,   501,  1448,  1511,  1523,  1531,  1537,  1541,
    1535,  1552,  1550,  1560,  1561,  1564,  1568,  1562,  1573,  1575,
    1569,  1588,  1590,  1599,   501,  1593,  1604,   396,  1602,  1616,
    1610,  1618,  1607,   501,  1054,  1600,   397,   501,  1631,  1636,
    1640,  1633,   868,   559,  1345,  1639,   553,   555,   556,  1287,
    1635,  1061,   660,  1620,  1597,  1571,  1304,  1595,  1136,  1005,
    1359,  1378,  1139,   655,   684,   703,  1463,   398,  1317,  1614,
    1318,  1314,  1621,  1340,  1624,   579,  1333,  1393,  1383,   711,
    1224,   745,  1390,  1346,  1332,   399,  1350,  1626,  1642,   800,
     501,  1356,  1387,  1039,   966,   400,   801,   621,  1364,   837,
    1609,  1606,   692,   721,  1298,  1043,   693,  1111,  1381,  1375,
     731,  1286,  1409,  1507,  1413,  1506,  1238,  1262,  1039,  1296,
    1440,   501,  1062,  1412,  1087,  1517,     0,   401,  1065,  1410,
       0,     0,     0,     0,     0,     0,     0,  1366,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   501,   501,
       0,     0,     0,   402,   403,   404,   405,   406,   768,   407,
     408,   409,   410,   411,     0,     0,     0,   500,   412,   413,
       0,   775,   501,     0,     0,     0,     0,     0,  1116,     0,
       0,     0,   501,     0,     0,     0,   501,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1151,     0,     0,     0,     0,     0,     0,     0,
    1156,     0,  1158,  1159,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1039,     0,     0,  1174,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1194,  1195,
    1196,     0,  1199,  1200,  1201,  1202,  1203,  1204,     0,  1206,
    1207,     0,     0,     0,     0,  1447,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1005,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1461,  1462,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   501,     0,     0,     0,     0,   501,
       0,     0,     0,     0,     0,     0,  1473,     0,     0,  1280,
     501,     0,     0,     0,     0,     0,  1479,     0,     0,     0,
    1482,     0,     0,     0,     0,     0,     0,  1288,     0,   501,
       0,   501,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   501,     0,     0,
     501,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     501,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   501,     0,     0,     0,     0,     0,     0,     0,   501,
       0,  1319,     0,  1321,     0,  1323,     0,   501,  1327,     0,
       0,     0,   501,  1331,     0,     0,     0,  1557,     0,     0,
       0,     0,     0,     0,     0,  1336,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1341,  1342,     0,   501,     0,
       0,     0,     0,  1347,  1348,     0,     0,     0,  1543,     0,
       0,     0,     0,  1549,     0,   501,     0,   501,     0,   384,
       0,     0,     0,     0,   500,   385,     0,     0,     0,     0,
     501,     0,     0,   386,   501,   387,     0,     0,     0,   501,
       0,     0,   389,  1039,   390,  1039,     0,     0,     0,     0,
       0,     0,     0,   391,     0,     0,     0,   392,     0,     0,
    1382,  1567,     0,     0,  1570,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1039,     0,  1005,     0,     0,     0,
       0,     0,     0,     0,     0,  1591,     0,     0,   393,   394,
    1001,     0,     0,  1039,     0,     0,     0,     0,     0,     0,
       0,  1598,     0,     0,     0,     0,  1601,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1615,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   397,     0,     0,     0,  1622,
       0,  1623,     0,     0,     0,     0,     0,     0,  1452,     0,
       0,     0,     0,  1454,  1634,     0,     0,  1457,  1637,  1459,
       0,  1460,     0,  1641,     0,     0,   398,  1464,     0,     0,
       0,     0,     0,     0,     0,     0,  1468,     0,     0,     0,
       0,     0,     0,     0,  1471,  1472,     0,     0,     0,     0,
       0,     0,     0,     0,   400,     0,     0,     0,     0,     0,
       0,     0,     0,  1483,  1484,  1485,  1486,  1487,     0,  1488,
    1489,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   401,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   402,   403,   404,   405,   406,     0,   407,   408,
     409,   410,   411,     0,     0,     0,     0,   412,   413,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1533,     0,  1534,     0,
       0,  1536,     0,     0,     0,     0,     0,     0,  1538,     0,
       0,     0,     0,  1540,     0,     0,     0,  1542,     0,  1544,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1572,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1603,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1613,     0,     0,     0,     0,  1617,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       0,     7,     0,     0,  1625,     8,     9,     0,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,     0,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,     0,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,    67,    68,
      69,    70,    71,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,     0,     0,    88,     0,    89,    90,
      91,    92,     0,    93,     0,     0,     0,    94,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,   105,     0,     0,     0,   106,   107,
     108,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,   121,     0,
       0,   122,   123,   124,     0,     0,     0,   125,     0,   126,
     127,     0,   128,   129,   130,     0,   131,     0,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,     0,
       0,   143,   144,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,   192,     0,   193,   194,   195,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     0,     7,     0,     0,     0,   370,
     371,     0,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,   372,    26,    27,
      28,    29,     0,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,     0,    67,    68,    69,    70,    71,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     0,     0,
      88,     0,    89,    90,    91,    92,     0,    93,     0,     0,
       0,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,   105,     0,
       0,     0,   106,   107,   108,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,   121,     0,     0,   122,   123,   124,     0,   373,
       0,   125,     0,   126,   127,     0,   128,   129,   130,     0,
     131,     0,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,     0,     0,   143,   144,   145,     0,   374,
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
       0,     0,   370,   371,     0,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
     372,    26,    27,    28,    29,     0,    30,    31,    32,    33,
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
     117,   118,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,   376,     0,   125,     0,   126,   127,     0,   128,
     129,   130,     0,   131,     0,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
     145,     0,   374,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       0,     7,     0,     0,     0,   370,   371,     0,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,   372,    26,    27,    28,    29,     0,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,     0,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,    67,    68,
      69,    70,    71,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,     0,     0,    88,     0,    89,    90,
      91,    92,     0,    93,     0,     0,     0,    94,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,   105,     0,     0,     0,   106,   107,
     108,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,   121,     0,
       0,   122,   123,   124,     0,   378,     0,   125,     0,   126,
     127,     0,   128,   129,   130,     0,   131,     0,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,     0,
       0,   143,   144,   145,     0,   374,   147,   148,   149,   150,
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
       4,     5,     6,     0,     7,     0,     0,     0,   370,   371,
       0,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,   372,    26,    27,    28,
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
     111,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     120,   121,     0,     0,   122,   123,   124,     0,     0,     0,
     125,   518,   126,   127,     0,   128,   129,   130,     0,   131,
       0,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,     0,     0,   143,   144,   145,     0,   374,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     0,     7,     0,     0,
       0,   370,   371,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,   372,
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
     118,   119,     0,   120,   121,     0,     0,   122,   123,   124,
       0,   826,     0,   125,     0,   126,   127,     0,   128,   129,
     130,     0,   131,     0,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,     0,     0,   143,   144,   145,
       0,   374,   147,   148,   149,   150,   151,   152,   153,   154,
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
       7,     0,     0,     0,   370,   371,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,   372,    26,    27,    28,    29,     0,    30,    31,
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
     115,   116,   117,   118,   119,     0,   120,   121,     0,     0,
     122,   123,   124,     0,     0,     0,   125,   832,   126,   127,
       0,   128,   129,   130,     0,   131,     0,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,     0,     0,
     143,   144,   145,     0,   374,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     0,     7,     0,     0,     0,   370,   371,     0,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,   372,    26,    27,    28,    29,
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,     0,
      67,    68,    69,    70,    71,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     0,     0,    88,     0,
      89,    90,    91,    92,     0,    93,     0,     0,     0,    94,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,   104,   105,     0,     0,     0,
     106,   107,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
     121,     0,     0,   122,   123,   124,     0,     0,     0,   125,
     836,   126,   127,     0,   128,   129,   130,     0,   131,     0,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,   145,     0,   374,   147,   148,
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
     370,   371,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   372,    26,
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
     119,     0,   120,   121,     0,     0,   122,   123,   124,     0,
    1307,     0,   125,     0,   126,   127,     0,   128,   129,   130,
       0,   131,     0,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,     0,     0,   143,   144,   145,     0,
     374,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,     0,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     0,     7,
       0,     0,     0,   370,   371,     0,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,   372,    26,    27,    28,    29,     0,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     0,    67,    68,    69,    70,
      71,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,     0,     0,    88,     0,    89,    90,    91,    92,
       0,    93,     0,     0,     0,    94,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     103,   104,   105,     0,     0,     0,   106,   107,   108,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,   119,     0,   120,   121,     0,     0,   122,
     123,   124,     0,  1344,     0,   125,     0,   126,   127,     0,
     128,   129,   130,     0,   131,     0,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,     0,     0,   143,
     144,   145,     0,   374,   147,   148,   149,   150,   151,   152,
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
       6,     0,     7,     0,     0,     0,   370,   371,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   372,    26,    27,    28,    29,     0,
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
     113,   114,   115,   116,   117,   118,   119,     0,   120,   121,
       0,     0,   122,   123,   124,     0,  1358,     0,   125,     0,
     126,   127,     0,   128,   129,   130,     0,   131,     0,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
       0,     0,   143,   144,   145,     0,   374,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     0,     7,     0,     0,     0,     8,
       9,     0,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,     0,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,     0,    67,    68,    69,    70,    71,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     0,     0,
      88,     0,    89,    90,    91,    92,     0,    93,     0,     0,
       0,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,   105,     0,
       0,     0,   106,   107,   108,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,   121,     0,     0,   122,   123,   124,     0,     0,
       0,   125,     0,   126,   127,     0,   128,   129,   130,     0,
     131,     0,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,     0,     0,   143,   144,   145,     0,   146,
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
       0,     0,     8,     9,     0,    10,    11,    12,    13,    14,
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
     117,   118,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,   128,
     129,   130,     0,   131,     0,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
     145,     0,   374,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       0,     7,     0,     0,     0,   370,   371,     0,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,   460,
     461,    23,   463,   372,    26,   464,    28,    29,     0,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,   466,
      41,    42,   467,     0,    44,    45,    46,   469,   470,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,    67,    68,
      69,    70,    71,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,     0,     0,    88,     0,    89,    90,
      91,    92,     0,    93,     0,     0,     0,   478,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,   105,     0,     0,     0,   106,   107,
     619,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   620,   121,     0,
       0,   122,   123,   124,     0,     0,     0,   125,     0,   126,
     127,     0,   128,   129,   130,     0,   131,     0,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,     0,
       0,   143,   144,   145,     0,   374,   147,   148,   149,   150,
     151,   152,   153,   154,   487,   156,   488,   158,   489,   490,
     161,   162,   163,   164,   165,   166,   491,   168,   492,   493,
     494,   495,   173,   174,   496,   497,   177,   498,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,   192,     0,   193,   194,   195,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     0,     7,     0,     0,     0,   370,   371,
       0,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,   372,    26,    27,    28,
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
     111,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     120,   121,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,     0,   128,   129,   130,     0,   131,
       0,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,     0,     0,   143,   144,   145,     0,   374,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     0,     7,     0,     0,
       0,     8,   371,     0,    10,    11,    12,    13,    14,    15,
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
     118,   119,     0,   120,   121,     0,     0,   122,   123,   124,
       0,     0,     0,   125,     0,   126,   127,     0,   128,   129,
     130,     0,   131,     0,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,     0,     0,   143,   144,   145,
       0,   374,   147,   148,   149,   150,   151,   152,   153,   154,
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
       7,     0,     0,     0,   787,   371,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,   372,    26,    27,    28,    29,     0,    30,    31,
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
     115,   116,   117,   118,   119,     0,   120,   121,     0,     0,
     122,   123,   124,     0,     0,     0,   125,     0,   126,   127,
       0,   128,   129,   130,     0,   131,     0,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,     0,     0,
     143,   144,   145,     0,   374,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     0,     7,     0,     0,     0,   370,   371,     0,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,   460,   461,    23,   463,   372,    26,   464,    28,    29,
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,   466,    41,    42,   467,     0,    44,    45,    46,   469,
     470,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,     0,
      67,    68,    69,    70,    71,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     0,     0,    88,     0,
      89,    90,    91,    92,     0,    93,     0,     0,     0,   478,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,   104,   105,     0,     0,     0,
     106,   107,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
     121,     0,     0,   122,   123,   124,     0,     0,     0,   125,
       0,   126,   127,     0,   128,   129,   130,     0,   131,     0,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,   145,     0,   374,   147,   148,
     149,   150,   151,   152,   153,   154,   487,   156,   488,   158,
     489,   490,   161,   162,   163,   164,   165,   166,   491,   168,
     492,   493,   494,   495,   173,   174,   496,   497,   177,   498,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     0,     7,     0,     0,     0,
     988,   371,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   372,    26,
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
     119,     0,   120,   121,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,     0,   128,   129,   130,
       0,   131,     0,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,     0,     0,   143,   144,   145,     0,
     374,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,     0,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     0,     7,
       0,     0,     0,   370,   371,     0,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   460,   461,    23,
     463,   372,    26,   464,    28,    29,     0,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,   466,    41,    42,
     467,     0,    44,    45,    46,   469,   470,    49,   471,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     0,    67,    68,    69,    70,
      71,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,     0,     0,    88,     0,    89,    90,    91,    92,
       0,    93,     0,     0,     0,   478,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     103,   104,   105,     0,     0,     0,   106,   107,     0,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,   119,     0,     0,     0,     0,     0,   122,
     123,   124,     0,     0,     0,   125,     0,   126,   127,     0,
     128,   129,   130,     0,   131,     0,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,     0,     0,   143,
     144,   145,     0,   374,   147,   148,   149,   150,   151,   152,
     153,   154,   487,   156,   488,   158,   489,   490,   161,   162,
     163,   164,   165,   166,   491,   168,   492,   493,   494,   495,
     173,   174,   496,   497,   177,   498,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
     192,     0,   193,   194,   195,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     0,     7,     0,     0,     0,   370,   371,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
     460,   461,    23,   463,   372,    26,   464,    28,    29,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
     466,    41,    42,   467,     0,    44,    45,    46,   469,   470,
      49,   471,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,    88,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,   478,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,   106,
     107,     0,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,   119,     0,     0,     0,
       0,     0,   122,   123,   124,     0,     0,     0,   125,     0,
     126,   127,     0,     0,     0,   130,     0,   131,     0,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
       0,     0,   143,   144,   145,     0,   374,   147,   148,   149,
     150,   151,   152,   153,   154,   487,   156,   488,   158,   489,
     490,   161,   162,   163,   164,   165,   166,   491,   168,   492,
     493,   494,   495,   173,   174,   496,   497,   177,   498,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     1,     0,     0,     0,     0,     0,     0,     2,
       0,     0,     0,     6,     0,     0,     0,     0,     0,   370,
     371,     0,    10,    11,    12,   457,    14,    15,    16,    17,
     458,    19,   459,   460,   461,   462,   463,   372,    26,   464,
      28,    29,     0,    30,    31,    32,    33,    34,   465,    36,
      37,    38,    39,   466,    41,    42,   467,     0,    44,   468,
      46,   469,   470,    49,   471,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,   472,   473,
      66,     0,    67,    68,    69,   474,     0,    72,    73,    74,
       0,     0,   475,    76,     0,     0,     0,     0,    78,    79,
      80,   476,   477,    83,    84,     0,     0,     0,     0,     0,
       0,     0,    89,    90,    91,    92,     0,    93,     0,     0,
       0,   478,    95,    96,   479,   480,     0,     0,     0,     0,
       0,     0,    99,   100,   101,     0,   103,   104,   105,     0,
       0,     0,     0,     0,     0,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   481,   116,   117,   482,     0,
       0,     0,     0,     0,     0,   483,   484,   124,     0,     0,
       0,   125,     0,   126,   485,     0,     0,     0,   130,     0,
     131,     0,   132,   133,   134,   135,   486,   137,   138,   139,
     140,   141,   142,     0,     0,   143,   144,     0,     0,   374,
     147,   148,   149,   150,   151,   152,   153,   154,   487,   156,
     488,   158,   489,   490,   161,   162,   163,   164,   165,   166,
     491,   168,   492,   493,   494,   495,   173,   174,   496,   497,
     177,   498,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,     1,     0,     0,     0,     0,
       0,     0,     2,     0,     0,     0,     6,     0,     0,     0,
       0,     0,   370,   371,     0,    10,    11,    12,   505,    14,
      15,    16,    17,   458,   506,   507,   460,   461,   462,   463,
     372,    26,   464,    28,    29,     0,    30,    31,    32,    33,
      34,   508,    36,   509,   510,    39,   466,    41,    42,   467,
       0,    44,   511,    46,   469,   470,    49,   471,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,   472,   473,    66,     0,    67,    68,    69,   512,     0,
      72,    73,    74,     0,     0,   475,    76,     0,     0,     0,
       0,    78,    79,    80,   476,   477,    83,    84,     0,     0,
       0,     0,     0,     0,     0,    89,    90,    91,    92,     0,
      93,     0,     0,     0,   478,    95,    96,   479,   480,     0,
       0,     0,     0,     0,     0,    99,   100,   101,     0,   103,
     104,   105,     0,     0,     0,     0,     0,     0,   109,   110,
       0,     0,     0,     0,   111,   112,   113,   114,   481,   116,
     117,   482,     0,     0,     0,     0,     0,     0,   483,   484,
     124,     0,     0,     0,   125,     0,   126,   485,     0,     0,
       0,   130,     0,   131,     0,   132,   133,   134,   135,   486,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
       0,     0,   374,   147,   148,   149,   150,   151,   152,   153,
     154,   487,   513,   488,   158,   489,   490,   161,   162,   163,
     164,   165,   166,   491,   168,   492,   493,   494,   495,   173,
     174,   496,   497,   177,   498,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   523,     0,
       0,     0,     0,     0,     0,     6,     0,   723,     0,     0,
       0,   370,   371,     0,    10,    11,    12,   505,    14,    15,
      16,    17,   458,   506,   507,   460,   461,   462,   463,   372,
      26,   464,    28,    29,     0,    30,    31,    32,    33,    34,
     508,    36,   509,   510,    39,   466,    41,    42,   467,     0,
      44,   511,    46,   469,   470,    49,   471,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
     472,   473,    66,     0,    67,    68,    69,   512,     0,    72,
      73,    74,     0,     0,   475,    76,     0,     0,     0,     0,
      78,    79,    80,   476,   477,    83,    84,     0,     0,     0,
       0,     0,     0,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,   478,    95,    96,   479,   480,     0,     0,
       0,     0,     0,     0,    99,   100,   101,     0,   103,   104,
     105,     0,     0,     0,     0,     0,     0,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   481,   116,   117,
     482,     0,     0,     0,     0,     0,     0,   483,   484,   124,
       0,     0,     0,   125,   724,   126,   485,     0,     0,     0,
       0,     0,   131,     0,   132,   133,   134,   135,   486,   137,
     138,   139,   140,   141,   142,     0,     0,   143,   144,     0,
       0,   374,   147,   148,   149,   150,   151,   152,   153,   154,
     487,   513,   488,   158,   489,   490,   161,   162,   163,   164,
     165,   166,   491,   168,   492,   493,   494,   495,   173,   174,
     496,   497,   177,   498,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   523,     0,     0,
       0,     0,     0,     0,     6,     0,     0,     0,     0,     0,
     370,   371,     0,    10,    11,    12,   505,    14,    15,    16,
      17,   458,   506,   507,   460,   461,   462,   463,   372,    26,
     464,    28,    29,     0,    30,    31,    32,    33,    34,   508,
      36,   509,   510,    39,   466,    41,    42,   467,     0,    44,
     511,    46,   469,   470,    49,   471,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,   472,
     473,    66,     0,    67,    68,    69,   512,     0,    72,    73,
      74,     0,     0,   475,    76,     0,     0,     0,     0,    78,
      79,    80,   476,   477,    83,    84,     0,     0,     0,     0,
       0,     0,     0,    89,    90,    91,    92,     0,    93,     0,
       0,     0,   478,    95,    96,   479,   480,     0,     0,     0,
       0,     0,     0,    99,   100,   101,     0,   103,   104,   105,
       0,     0,     0,     0,     0,     0,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   481,   116,   117,   482,
       0,     0,     0,     0,     0,     0,   483,   484,   124,     0,
       0,     0,   125,     0,   126,   485,     0,     0,     0,     0,
       0,   131,     0,   132,   133,   134,   135,   486,   137,   138,
     139,   140,   141,   142,     0,     0,   143,   144,     0,     0,
     374,   147,   148,   149,   150,   151,   152,   153,   154,   487,
     513,   488,   158,   489,   490,   161,   162,   163,   164,   165,
     166,   491,   168,   492,   493,   494,   495,   173,   174,   496,
     497,   177,   498,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,     0,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   526,     0,     0,     0,
       0,     6,     0,     0,     0,     0,     0,   370,   371,     0,
      10,    11,    12,   505,    14,    15,    16,    17,   458,   506,
     507,   460,   461,   462,   463,   372,    26,   464,    28,    29,
       0,    30,    31,    32,    33,    34,   508,    36,   509,   510,
      39,   466,    41,    42,   467,     0,    44,   511,    46,   469,
     470,    49,   471,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,   472,   473,    66,     0,
      67,    68,    69,   512,     0,    72,    73,    74,     0,     0,
     475,    76,     0,     0,     0,     0,    78,    79,    80,   476,
     477,    83,    84,     0,     0,     0,     0,     0,     0,     0,
      89,    90,    91,    92,     0,    93,     0,     0,     0,   478,
      95,    96,   479,   480,     0,     0,     0,     0,     0,     0,
      99,   100,   101,     0,   103,   104,   105,     0,     0,     0,
       0,     0,     0,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   481,   116,   117,   482,     0,     0,     0,
       0,     0,     0,   483,   484,   124,     0,     0,     0,   125,
       0,   126,   485,     0,     0,     0,     0,     0,   131,     0,
     132,   133,   134,   135,   486,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,     0,     0,   374,   147,   148,
     149,   150,   151,   152,   153,   154,   487,   513,   488,   158,
     489,   490,   161,   162,   163,   164,   165,   166,   491,   168,
     492,   493,   494,   495,   173,   174,   496,   497,   177,   498,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     6,     0,     0,     0,     0,     0,   370,
     371,     0,    10,    11,    12,   457,    14,    15,    16,    17,
     458,    19,   459,   460,   461,  1027,   463,   372,    26,   464,
      28,    29,     0,    30,    31,    32,    33,    34,   465,    36,
      37,    38,    39,   466,    41,    42,   467,     0,    44,   468,
      46,   469,   470,    49,   471,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,   472,   473,
      66,     0,    67,    68,    69,   474,     0,    72,    73,    74,
       0,     0,   475,    76,     0,     0,     0,     0,    78,    79,
      80,   476,   477,    83,    84,     0,     0,     0,     0,     0,
       0,     0,    89,    90,    91,    92,     0,    93,     0,     0,
       0,   478,    95,    96,   479,   480,     0,     0,     0,     0,
       0,     0,    99,   100,   101,     0,   103,   104,  1028,     0,
       0,     0,  1029,     0,     0,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   481,   116,   117,   482,     0,
       0,     0,     0,     0,     0,   483,   484,   124,     0,     0,
       0,   125,  1423,   126,   485,     0,     0,     0,  1424,     0,
     131,     0,   132,   133,   134,   135,   486,   137,   138,   139,
     140,   141,   142,     0,     0,  1030,   144,     0,     0,   374,
     147,   148,   149,   150,   151,   152,   153,   154,   487,   156,
     488,   158,   489,   490,   161,   162,   163,   164,   165,   166,
     491,   168,   492,   493,   494,   495,   173,   174,   496,   497,
     177,   498,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,     6,     0,     0,     0,     0,
       0,   370,   371,     0,    10,    11,    12,   505,    14,    15,
      16,    17,   458,   506,   507,   460,   461,   462,   463,   372,
      26,   464,    28,    29,     0,    30,    31,    32,    33,    34,
     508,    36,   509,   510,    39,   466,    41,    42,   467,     0,
      44,   511,    46,   469,   470,    49,   471,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
     472,   473,    66,     0,    67,    68,    69,   512,     0,    72,
      73,    74,     0,     0,   475,    76,     0,     0,     0,     0,
      78,    79,    80,   476,   477,    83,    84,     0,     0,     0,
       0,     0,     0,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,   478,    95,    96,   479,   480,     0,     0,
       0,     0,     0,     0,    99,   100,   101,     0,   103,   104,
     105,     0,     0,     0,     0,     0,     0,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   481,   116,   117,
     482,     0,     0,     0,     0,     0,     0,   483,   484,   124,
       0,     0,     0,   125,   695,   126,   485,     0,     0,     0,
     696,     0,   131,     0,   132,   133,   134,   135,   486,   137,
     138,   139,   140,   141,   142,     0,     0,   143,   144,     0,
       0,   374,   147,   148,   149,   150,   151,   152,   153,   154,
     487,   513,   488,   158,   489,   490,   161,   162,   163,   164,
     165,   166,   491,   168,   492,   493,   494,   495,   173,   174,
     496,   497,   177,   498,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     6,     0,     0,
       0,     0,     0,   370,   371,     0,    10,    11,    12,   505,
      14,    15,    16,    17,   458,   506,   507,   460,   461,   462,
     463,   372,    26,   464,    28,    29,     0,    30,    31,    32,
      33,    34,   508,    36,   509,   510,    39,   466,    41,    42,
     467,     0,    44,   511,    46,   469,   470,    49,   471,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,   472,   473,    66,     0,    67,    68,    69,   512,
       0,    72,    73,    74,     0,     0,   475,    76,     0,     0,
       0,     0,    78,    79,    80,   476,   477,    83,    84,     0,
       0,     0,     0,     0,     0,     0,    89,    90,    91,    92,
       0,    93,     0,     0,     0,   478,    95,    96,   479,   480,
       0,     0,     0,     0,     0,     0,    99,   100,   101,     0,
     103,   104,   105,     0,     0,     0,     0,     0,     0,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   481,
     116,   117,   482,     0,     0,     0,     0,     0,     0,   483,
     484,   124,     0,     0,     0,   125,   742,   126,   485,     0,
       0,     0,   743,     0,   131,     0,   132,   133,   134,   135,
     486,   137,   138,   139,   140,   141,   142,     0,     0,   143,
     144,     0,     0,   374,   147,   148,   149,   150,   151,   152,
     153,   154,   487,   513,   488,   158,   489,   490,   161,   162,
     163,   164,   165,   166,   491,   168,   492,   493,   494,   495,
     173,   174,   496,   497,   177,   498,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
     192,     0,   193,   194,   195,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,     6,
       0,     0,     0,     0,     0,   370,   371,     0,    10,    11,
      12,   457,    14,    15,    16,    17,   458,    19,   459,   460,
     461,  1027,   463,   372,    26,   464,    28,    29,     0,    30,
      31,    32,    33,    34,   465,    36,    37,    38,    39,   466,
      41,    42,   467,     0,    44,   468,    46,   469,   470,    49,
     471,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,   472,   473,    66,     0,    67,    68,
      69,   474,     0,    72,    73,    74,     0,     0,   475,    76,
       0,     0,     0,     0,    78,    79,    80,   476,   477,    83,
      84,  1353,     0,     0,     0,     0,     0,     0,    89,    90,
      91,    92,     0,    93,     0,     0,     0,   478,    95,    96,
     479,   480,     0,     0,     0,     0,     0,     0,    99,   100,
     101,     0,   103,   104,  1028,     0,     0,     0,  1029,     0,
       0,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   481,   116,   117,   482,     0,     0,     0,     0,     0,
       0,   483,   484,   124,     0,     0,     0,   125,     0,   126,
     485,     0,     0,     0,     0,     0,   131,     0,   132,   133,
     134,   135,   486,   137,   138,   139,   140,   141,   142,     0,
       0,  1030,   144,     0,     0,   374,   147,   148,   149,   150,
     151,   152,   153,   154,   487,   156,   488,   158,   489,   490,
     161,   162,   163,   164,   165,   166,   491,   168,   492,   493,
     494,   495,   173,   174,   496,   497,   177,   498,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,   192,     0,   193,   194,   195,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,     6,     0,     0,     0,     0,     0,   370,   371,     0,
      10,    11,    12,   457,    14,    15,    16,    17,   458,    19,
     459,   460,   461,  1027,   463,   372,    26,   464,    28,    29,
       0,    30,    31,    32,    33,    34,   465,    36,    37,    38,
      39,   466,    41,    42,   467,     0,    44,   468,    46,   469,
     470,    49,   471,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,   472,   473,    66,     0,
      67,    68,    69,   474,     0,    72,    73,    74,     0,     0,
     475,    76,     0,     0,     0,     0,    78,    79,    80,   476,
     477,    83,    84,     0,     0,     0,     0,     0,     0,     0,
      89,    90,    91,    92,     0,    93,     0,     0,     0,   478,
      95,    96,   479,   480,     0,     0,     0,     0,     0,     0,
      99,   100,   101,     0,   103,   104,  1028,     0,     0,     0,
    1029,     0,     0,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   481,   116,   117,   482,     0,     0,     0,
       0,     0,     0,   483,   484,   124,     0,     0,     0,   125,
       0,   126,   485,     0,     0,     0,     0,     0,   131,     0,
     132,   133,   134,   135,   486,   137,   138,   139,   140,   141,
     142,     0,     0,  1030,   144,     0,     0,   374,   147,   148,
     149,   150,   151,   152,   153,   154,   487,   156,   488,   158,
     489,   490,   161,   162,   163,   164,   165,   166,   491,   168,
     492,   493,   494,   495,   173,   174,   496,   497,   177,   498,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     6,     0,     0,     0,     0,     0,   370,
     371,     0,    10,    11,    12,   457,    14,    15,    16,    17,
     458,    19,   459,   460,   461,  1027,   463,   372,    26,   464,
      28,    29,     0,    30,    31,    32,    33,    34,   465,    36,
      37,    38,    39,   466,    41,    42,   467,     0,    44,   468,
      46,   469,   470,    49,   471,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,   472,   473,
      66,     0,    67,    68,    69,   474,     0,    72,    73,    74,
       0,     0,   475,    76,     0,     0,     0,     0,    78,    79,
      80,   476,   477,    83,    84,     0,     0,     0,     0,     0,
       0,     0,    89,    90,    91,    92,     0,    93,     0,     0,
       0,   478,    95,    96,   479,   480,     0,     0,     0,     0,
       0,     0,    99,   100,   101,     0,   103,   104,  1028,     0,
       0,     0,  1029,     0,     0,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   481,   116,   117,   482,     0,
       0,     0,     0,     0,     0,   483,   484,   124,     0,     0,
       0,   125,     0,   126,   485,     0,     0,     0,     0,     0,
     131,     0,   132,   133,   134,   135,   486,   137,   138,   139,
     140,   141,   142,     0,     0,   143,   144,     0,     0,   374,
     147,   148,   149,   150,   151,   152,   153,   154,   487,   156,
     488,   158,   489,   490,   161,   162,   163,   164,   165,   166,
     491,   168,   492,   493,   494,   495,   173,   174,   496,   497,
     177,   498,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,     6,     0,     0,     0,     0,
       0,   370,   371,     0,    10,    11,    12,   505,    14,    15,
      16,    17,   458,   506,   507,   460,   461,   462,   463,   372,
      26,   464,    28,    29,     0,    30,    31,    32,    33,    34,
     508,    36,   509,   510,    39,   466,    41,    42,   467,     0,
      44,   511,    46,   469,   470,    49,   471,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
     472,   473,    66,     0,    67,    68,    69,   512,     0,    72,
      73,    74,     0,     0,   475,    76,     0,     0,     0,     0,
      78,    79,    80,   476,   477,    83,    84,     0,     0,     0,
       0,     0,     0,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,   478,    95,    96,   479,   480,     0,     0,
       0,     0,     0,     0,    99,   100,   101,     0,   103,   104,
     105,     0,     0,     0,     0,     0,     0,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   481,   116,   117,
     482,     0,     0,     0,     0,     0,     0,   483,   484,   124,
       0,     0,     0,   125,     0,   126,   485,     0,     0,     0,
       0,     0,   131,     0,   132,   133,   134,   135,   486,   137,
     138,   139,   140,   141,   142,     0,     0,   143,   144,     0,
       0,   374,   147,   148,   149,   150,   151,   152,   153,   154,
     487,   513,   488,   158,   489,   490,   161,   162,   163,   164,
     165,   166,   491,   168,   492,   493,   494,   495,   173,   174,
     496,   497,   177,   498,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     6,     0,     0,
       0,     0,     0,   370,   371,     0,    10,    11,    12,     0,
      14,    15,    16,    17,   458,     0,     0,   460,   461,   462,
       0,   372,    26,   464,    28,    29,     0,    30,    31,    32,
      33,    34,     0,    36,     0,     0,    39,   466,    41,    42,
     467,     0,    44,     0,    46,     0,     0,    49,   471,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,   472,   473,    66,     0,    67,    68,    69,     0,
       0,    72,    73,    74,     0,     0,   475,    76,     0,     0,
       0,     0,    78,    79,    80,   476,   477,    83,    84,     0,
       0,     0,     0,     0,     0,     0,    89,    90,    91,    92,
       0,    93,     0,     0,     0,   478,    95,    96,   479,   480,
       0,     0,     0,     0,     0,     0,    99,   100,   101,     0,
     103,   104,     0,     0,     0,     0,     0,     0,     0,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   481,
     116,   117,   482,     0,     0,     0,     0,     0,     0,   483,
     484,   124,     0,     0,     0,   125,     0,   126,   485,     0,
       0,     0,     0,     0,   131,     0,   132,   133,   134,   135,
     486,   137,   138,   139,   140,   141,   142,     0,     0,     0,
     144,     0,     0,   374,   147,   148,   149,   150,   151,   152,
     153,   154,   487,     0,   488,   158,   489,   490,   161,   162,
     163,   164,   165,   166,   491,   168,   492,   493,   494,   495,
     173,   174,     0,   497,   177,   498,   179,   180,   181,   182,
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
        71,   721,     3,     4,     5,   606,   703,   568,   380,   309,
     245,   731,   823,   937,    85,   898,   748,   607,   608,   609,
     610,   129,   822,   823,   246,   247,  1214,   564,   565,  1380,
     562,   563,   564,   565,   721,    71,   107,  1230,  1231,   969,
      24,   396,  1296,   649,    31,  1013,    31,   810,   119,   810,
     121,  1187,   562,   563,   857,   137,    93,   857,   114,  1099,
      53,     1,    93,   435,   436,   420,     8,    41,    91,    51,
      24,    91,    54,     1,   586,     1,   588,   589,    25,   591,
     114,   593,     9,  1263,   439,    90,    60,    96,   103,   601,
     602,     1,    91,   893,   991,   103,    23,   103,   142,    91,
       9,    10,   913,     1,    91,   106,    93,   114,    93,   113,
     126,   125,   125,   913,    96,     1,   927,     1,    42,   148,
     103,   164,   106,   103,   102,    93,   148,   927,   155,     9,
      10,    93,    29,   164,    71,   119,   161,   141,    93,   142,
      28,    91,   171,   863,   122,   137,    91,   181,    85,   171,
     154,   176,   195,   148,   109,   142,   151,   142,    46,  1056,
     144,    58,   218,   218,   148,   220,   114,   151,   184,   184,
     107,   180,   177,   180,   142,    37,   190,   190,   184,   103,
     142,    43,   119,   187,   121,   267,    48,   171,   211,   212,
      99,   118,   142,   120,  1387,   148,   151,   142,   178,   182,
     920,   155,   129,   226,   312,    67,   926,   181,   203,   118,
     230,   120,  1095,   250,   251,   246,   247,   210,   249,    99,
     228,   148,   919,   267,  1148,   256,  1029,   169,  1364,  1029,
     917,   230,   919,   965,    93,   266,   842,   843,   118,   148,
     120,   778,   779,   152,   184,   301,   317,   278,  1178,   320,
    1013,  1014,  1013,  1014,   941,   248,   184,  1187,   184,   168,
     207,  1612,  1442,   245,   267,  1305,   776,   777,   148,   253,
    1524,  1239,   152,    91,   184,   267,   258,  1628,   260,   188,
     267,   317,   267,   103,   320,  1636,   184,    91,   168,   271,
     272,   273,   664,   275,   806,   277,    24,   206,   184,   131,
     184,   163,  1102,  1491,   166,   164,   103,   153,   188,    32,
      33,   151,    35,    36,   385,   148,   387,    93,   180,   103,
     906,   392,   908,    28,   170,   396,   206,   562,   563,  1140,
      49,   402,    55,   109,  1527,   103,   257,   559,   409,   103,
    1140,    46,   131,   205,   148,   717,   192,   268,   103,   420,
     103,   103,   103,   103,  1165,   426,   145,    41,   713,   430,
      44,   716,   194,   103,   184,  1165,   437,   114,   439,   440,
     441,   442,   443,  1566,   960,   151,   962,   448,   103,    41,
     317,   109,    44,   320,   181,   456,   109,   246,   247,    34,
     249,   151,    76,   211,   212,    40,    41,   103,   182,   114,
       5,     9,    10,   151,     9,   124,  1446,   266,   226,   210,
     214,   215,    57,   181,    59,    60,  1113,   181,   102,   278,
     421,  1304,   423,    68,   425,     9,   181,   155,   181,   181,
     181,   181,   155,   434,  1364,   151,  1123,   438,     5,    23,
     102,   181,     9,   444,   515,   446,   447,   248,   449,    94,
     387,    93,   153,    91,   455,   392,   181,     9,    10,   396,
    1271,   998,   999,  1000,   102,   402,   998,   999,  1000,   170,
      24,  1271,   409,   544,   854,   181,  1239,    64,  1239,   163,
      91,   552,    69,   420,   218,  1248,   220,  1248,   868,   426,
     213,    99,  1532,   430,   866,   867,  1259,    44,  1259,   871,
     437,   163,   439,   440,   441,   442,   443,   139,   151,   151,
     118,   448,   120,   118,    61,   120,    63,   625,   626,   456,
     521,   132,   153,   128,  1564,    72,   137,   114,   900,    50,
     209,   532,   153,   114,   118,    56,   120,   143,   170,   170,
     148,   776,  1466,   148,   152,   129,   164,    99,   194,   170,
     551,   118,   106,   120,   160,   187,   151,   203,   117,   781,
     168,   128,   263,   176,   148,   119,   118,   117,   120,   270,
     143,   192,    93,   218,  1545,  1546,   189,   195,   515,   280,
     188,   148,   293,   654,  1624,   656,  1626,   160,   659,   148,
     144,   302,   151,    92,   148,    50,   148,   151,   206,   262,
     152,    56,  1642,   102,   132,   223,   269,   544,  1579,   151,
     681,   682,   683,   112,  1585,   552,   168,   171,   148,    74,
     148,   622,   263,   122,   132,  1322,   627,   241,   242,   270,
    1362,   132,    93,   704,  1366,   706,   188,   117,    93,   280,
     148,   257,   713,   176,    96,   716,   117,   148,   109,  1250,
     264,  1414,   268,  1414,   206,    96,   189,   109,   148,   114,
     225,   151,   227,   281,   282,   283,   284,   285,   109,   287,
     288,   289,   290,   291,    50,   149,   747,   151,   296,   225,
      56,   227,  1219,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,   218,   271,   272,   273,   132,   223,  1510,
     277,  1512,   137,   148,   148,   628,   151,   151,   631,   710,
    1510,   634,  1512,   132,   148,  1015,   319,   151,   137,   185,
     186,   324,   659,   794,  1285,   214,   215,   216,   117,   384,
    1541,   386,   294,   295,   294,   295,   123,   124,   739,   740,
     117,  1541,   285,   286,   681,   682,   683,  1479,   117,  1560,
    1482,   822,   823,   824,   825,   127,   123,   124,   611,   612,
    1560,   604,   605,   135,   136,   117,   138,   704,   769,   706,
     117,  1143,   613,   614,   146,   117,   713,   117,   150,   716,
     152,   117,   824,   825,   148,   157,   857,  1433,  1434,   151,
     218,   114,   148,   235,   151,   235,   114,   236,   148,     0,
     427,   173,   873,   162,  1405,  1406,    89,  1527,  1398,    47,
     747,   243,   193,    97,   149,   140,    98,  1549,   151,    24,
     178,    44,    44,   178,   196,   197,   198,   199,   200,   201,
     178,    44,   147,   114,   240,   906,   287,   908,   292,   292,
     298,   278,   913,   181,   114,   278,   148,   181,   148,   148,
     151,   181,    30,   151,  1226,   151,   927,   794,   151,   151,
      16,   207,    24,   224,   181,     3,   114,    91,   163,    68,
     224,   165,    91,    91,   165,   144,   103,   103,    24,   155,
     155,   122,   127,   293,   127,   822,   823,   824,   825,   960,
     178,   962,   178,   103,   181,   240,   181,  1498,  1499,   178,
     178,    91,    93,   103,   181,    41,    93,   178,   181,   536,
     537,   178,   539,   540,   541,   542,   181,   181,   181,   181,
     857,   137,   549,   550,   181,   178,   178,   148,   178,   178,
      91,   137,   178,   230,   181,    28,   873,  1008,   218,   566,
     165,   114,   178,   127,   179,   137,    91,    24,   575,   576,
     293,   137,   280,   148,   955,  1556,   114,   122,  1029,   220,
     114,   114,   142,   114,    91,    93,  1338,   178,   127,   906,
     155,   908,   127,   114,   248,   114,   913,   191,   148,   142,
     137,    96,    96,    30,   178,   178,    24,    76,   148,   114,
     927,   114,   103,   103,   252,   178,   148,   239,   254,   139,
      24,   261,   151,   151,   151,    24,   633,   279,    24,   636,
     230,  1012,   280,   220,    32,    33,   220,    35,    36,  1391,
      38,   139,   281,   960,   220,   962,    44,   122,   114,   142,
     142,   181,   114,   142,    52,    74,    54,    55,   181,   181,
     184,  1112,   103,    61,  1115,    63,  1117,   181,   178,   300,
     137,   127,   181,  1054,    72,   181,     7,   226,    76,   226,
    1131,   180,   184,   137,   230,   102,   102,   244,   244,  1140,
     178,  1008,   142,   276,   181,    75,   181,   181,   280,  1150,
     181,   178,    24,    24,   265,    93,  1157,   165,   178,   107,
     108,   109,  1029,   226,  1165,   226,   142,   142,   121,    93,
     180,   180,   274,   178,   148,  1106,   178,   178,    91,   178,
      24,   103,   165,  1184,   251,   181,   181,   281,    50,    91,
     142,   114,   190,    91,    24,   103,   114,   259,   114,   180,
     218,   190,   190,   114,  1205,   178,    90,   155,   180,   114,
     190,   114,   177,  1214,   148,   218,   164,  1218,   114,   181,
     114,   192,   663,   245,  1155,   218,   239,   242,   242,  1060,
     281,   858,   394,   287,   299,  1532,  1102,  1564,   925,   796,
    1171,  1210,   928,   390,   414,  1112,  1332,   195,  1115,   299,
    1117,  1112,   299,  1150,   300,   284,  1132,  1235,  1218,   433,
    1004,   515,  1233,  1157,  1131,   213,  1162,   300,   300,   584,
    1271,  1166,  1230,  1140,   748,   223,   585,   305,  1178,   636,
    1585,  1579,   424,  1150,  1096,   825,   424,   908,  1215,  1205,
    1157,  1059,  1248,  1414,  1259,  1411,  1014,  1023,  1165,  1084,
    1294,  1302,   859,  1252,   892,  1436,    -1,   255,   865,  1249,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1184,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1329,  1330,
      -1,    -1,    -1,   281,   282,   283,   284,   285,  1205,   287,
     288,   289,   290,   291,    -1,    -1,    -1,  1214,   296,   297,
      -1,  1218,  1353,    -1,    -1,    -1,    -1,    -1,   915,    -1,
      -1,    -1,  1363,    -1,    -1,    -1,  1367,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   939,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     947,    -1,   949,   950,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1271,    -1,    -1,   964,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   975,   976,
     977,    -1,   979,   980,   981,   982,   983,   984,    -1,   986,
     987,    -1,    -1,    -1,    -1,  1302,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1004,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1329,  1330,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1475,    -1,    -1,    -1,    -1,  1480,
      -1,    -1,    -1,    -1,    -1,    -1,  1353,    -1,    -1,  1046,
    1491,    -1,    -1,    -1,    -1,    -1,  1363,    -1,    -1,    -1,
    1367,    -1,    -1,    -1,    -1,    -1,    -1,  1064,    -1,  1510,
      -1,  1512,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1528,    -1,    -1,
    1531,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1541,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1552,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1560,
      -1,  1118,    -1,  1120,    -1,  1122,    -1,  1568,  1125,    -1,
      -1,    -1,  1573,  1130,    -1,    -1,    -1,  1508,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1142,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1152,  1153,    -1,  1599,    -1,
      -1,    -1,    -1,  1160,  1161,    -1,    -1,    -1,  1475,    -1,
      -1,    -1,    -1,  1480,    -1,  1616,    -1,  1618,    -1,    38,
      -1,    -1,    -1,    -1,  1491,    44,    -1,    -1,    -1,    -1,
    1631,    -1,    -1,    52,  1635,    54,    -1,    -1,    -1,  1640,
      -1,    -1,    61,  1510,    63,  1512,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,
    1217,  1528,    -1,    -1,  1531,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1541,    -1,  1233,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1552,    -1,    -1,   107,   108,
     109,    -1,    -1,  1560,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1568,    -1,    -1,    -1,    -1,  1573,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1599,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   164,    -1,    -1,    -1,  1616,
      -1,  1618,    -1,    -1,    -1,    -1,    -1,    -1,  1315,    -1,
      -1,    -1,    -1,  1320,  1631,    -1,    -1,  1324,  1635,  1326,
      -1,  1328,    -1,  1640,    -1,    -1,   195,  1334,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1343,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1351,  1352,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1370,  1371,  1372,  1373,  1374,    -1,  1376,
    1377,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   281,   282,   283,   284,   285,    -1,   287,   288,
     289,   290,   291,    -1,    -1,    -1,    -1,   296,   297,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1453,    -1,  1455,    -1,
      -1,  1458,    -1,    -1,    -1,    -1,    -1,    -1,  1465,    -1,
      -1,    -1,    -1,  1470,    -1,    -1,    -1,  1474,    -1,  1476,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1535,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1575,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1597,    -1,    -1,    -1,    -1,  1602,    -1,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    24,    -1,    -1,  1621,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    -1,    -1,   101,   102,
      -1,    -1,    -1,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    -1,    -1,   119,    -1,   121,   122,
     123,   124,    -1,   126,    -1,    -1,    -1,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,    -1,    -1,   141,   142,
     143,   144,   145,   146,   147,    -1,    -1,    -1,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,   170,   171,    -1,
      -1,   174,   175,   176,    -1,    -1,    -1,   180,    -1,   182,
     183,    -1,   185,   186,   187,    -1,   189,    -1,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,    -1,
      -1,   204,   205,   206,    -1,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,    -1,
     253,   254,   255,    -1,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    -1,    24,    -1,    -1,    -1,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    91,    92,    93,    94,    95,    96,    97,    98,
      -1,    -1,   101,   102,    -1,    -1,    -1,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,    -1,    -1,
     119,    -1,   121,   122,   123,   124,    -1,   126,    -1,    -1,
      -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
      -1,    -1,   141,   142,   143,   144,   145,   146,   147,    -1,
      -1,    -1,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,   170,   171,    -1,    -1,   174,   175,   176,    -1,   178,
      -1,   180,    -1,   182,   183,    -1,   185,   186,   187,    -1,
     189,    -1,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,    -1,    -1,   204,   205,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,    -1,   253,   254,   255,    -1,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,    11,    -1,    -1,    -1,    -1,
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
     166,   167,   168,    -1,   170,   171,    -1,    -1,   174,   175,
     176,    -1,   178,    -1,   180,    -1,   182,   183,    -1,   185,
     186,   187,    -1,   189,    -1,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,    -1,    -1,   204,   205,
     206,    -1,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,   253,   254,   255,
      -1,   257,   258,   259,   260,   261,   262,    -1,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    24,    -1,    -1,    -1,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    -1,    -1,   101,   102,
      -1,    -1,    -1,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    -1,    -1,   119,    -1,   121,   122,
     123,   124,    -1,   126,    -1,    -1,    -1,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,    -1,    -1,   141,   142,
     143,   144,   145,   146,   147,    -1,    -1,    -1,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,   170,   171,    -1,
      -1,   174,   175,   176,    -1,   178,    -1,   180,    -1,   182,
     183,    -1,   185,   186,   187,    -1,   189,    -1,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,    -1,
      -1,   204,   205,   206,    -1,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,    -1,
     253,   254,   255,    -1,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
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
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
     170,   171,    -1,    -1,   174,   175,   176,    -1,    -1,    -1,
     180,   181,   182,   183,    -1,   185,   186,   187,    -1,   189,
      -1,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,    -1,    -1,   204,   205,   206,    -1,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,   253,   254,   255,    -1,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    19,    20,    21,    22,    -1,    24,    -1,    -1,
      -1,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
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
     167,   168,    -1,   170,   171,    -1,    -1,   174,   175,   176,
      -1,   178,    -1,   180,    -1,   182,   183,    -1,   185,   186,
     187,    -1,   189,    -1,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,    -1,    -1,   204,   205,   206,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,    -1,   253,   254,   255,    -1,
     257,   258,   259,   260,   261,   262,    -1,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,    11,    -1,    -1,
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
     164,   165,   166,   167,   168,    -1,   170,   171,    -1,    -1,
     174,   175,   176,    -1,    -1,    -1,   180,   181,   182,   183,
      -1,   185,   186,   187,    -1,   189,    -1,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,    -1,    -1,
     204,   205,   206,    -1,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,    -1,   253,
     254,   255,    -1,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      21,    22,    -1,    24,    -1,    -1,    -1,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      91,    92,    93,    94,    95,    96,    97,    98,    -1,    -1,
     101,   102,    -1,    -1,    -1,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    -1,    -1,   119,    -1,
     121,   122,   123,   124,    -1,   126,    -1,    -1,    -1,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,    -1,    -1,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,    -1,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,   170,
     171,    -1,    -1,   174,   175,   176,    -1,    -1,    -1,   180,
     181,   182,   183,    -1,   185,   186,   187,    -1,   189,    -1,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,    -1,    -1,   204,   205,   206,    -1,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,   253,   254,   255,    -1,   257,   258,   259,   260,
     261,   262,    -1,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,    11,    -1,    -1,    -1,    -1,    -1,    -1,
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
     168,    -1,   170,   171,    -1,    -1,   174,   175,   176,    -1,
     178,    -1,   180,    -1,   182,   183,    -1,   185,   186,   187,
      -1,   189,    -1,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,    -1,    -1,   204,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,    -1,   253,   254,   255,    -1,   257,
     258,   259,   260,   261,   262,    -1,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    -1,    24,
      -1,    -1,    -1,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    91,    92,    93,    94,
      95,    96,    97,    98,    -1,    -1,   101,   102,    -1,    -1,
      -1,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,    -1,    -1,   119,    -1,   121,   122,   123,   124,
      -1,   126,    -1,    -1,    -1,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,   144,
     145,   146,   147,    -1,    -1,    -1,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,   170,   171,    -1,    -1,   174,
     175,   176,    -1,   178,    -1,   180,    -1,   182,   183,    -1,
     185,   186,   187,    -1,   189,    -1,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,    -1,    -1,   204,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,   253,   254,
     255,    -1,   257,   258,   259,   260,   261,   262,    -1,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,    11,
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
     162,   163,   164,   165,   166,   167,   168,    -1,   170,   171,
      -1,    -1,   174,   175,   176,    -1,   178,    -1,   180,    -1,
     182,   183,    -1,   185,   186,   187,    -1,   189,    -1,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
      -1,    -1,   204,   205,   206,    -1,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
      -1,   253,   254,   255,    -1,   257,   258,   259,   260,   261,
     262,    -1,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    -1,    24,    -1,    -1,    -1,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    91,    92,    93,    94,    95,    96,    97,    98,
      -1,    -1,   101,   102,    -1,    -1,    -1,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,    -1,    -1,
     119,    -1,   121,   122,   123,   124,    -1,   126,    -1,    -1,
      -1,   130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,
      -1,    -1,   141,   142,   143,   144,   145,   146,   147,    -1,
      -1,    -1,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,   170,   171,    -1,    -1,   174,   175,   176,    -1,    -1,
      -1,   180,    -1,   182,   183,    -1,   185,   186,   187,    -1,
     189,    -1,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,    -1,    -1,   204,   205,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,    -1,   253,   254,   255,    -1,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,    11,    -1,    -1,    -1,    -1,
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
     166,   167,   168,    -1,   170,   171,    -1,    -1,   174,   175,
     176,    -1,    -1,    -1,   180,    -1,   182,   183,    -1,   185,
     186,   187,    -1,   189,    -1,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,    -1,    -1,   204,   205,
     206,    -1,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,   253,   254,   255,
      -1,   257,   258,   259,   260,   261,   262,    -1,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    24,    -1,    -1,    -1,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    -1,    -1,   101,   102,
      -1,    -1,    -1,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    -1,    -1,   119,    -1,   121,   122,
     123,   124,    -1,   126,    -1,    -1,    -1,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,    -1,    -1,   141,   142,
     143,   144,   145,   146,   147,    -1,    -1,    -1,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,   170,   171,    -1,
      -1,   174,   175,   176,    -1,    -1,    -1,   180,    -1,   182,
     183,    -1,   185,   186,   187,    -1,   189,    -1,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,    -1,
      -1,   204,   205,   206,    -1,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,    -1,
     253,   254,   255,    -1,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
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
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
     170,   171,    -1,    -1,   174,   175,   176,    -1,    -1,    -1,
     180,    -1,   182,   183,    -1,   185,   186,   187,    -1,   189,
      -1,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,    -1,    -1,   204,   205,   206,    -1,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,   253,   254,   255,    -1,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    19,    20,    21,    22,    -1,    24,    -1,    -1,
      -1,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
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
     167,   168,    -1,   170,   171,    -1,    -1,   174,   175,   176,
      -1,    -1,    -1,   180,    -1,   182,   183,    -1,   185,   186,
     187,    -1,   189,    -1,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,    -1,    -1,   204,   205,   206,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,    -1,   253,   254,   255,    -1,
     257,   258,   259,   260,   261,   262,    -1,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,    11,    -1,    -1,
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
     164,   165,   166,   167,   168,    -1,   170,   171,    -1,    -1,
     174,   175,   176,    -1,    -1,    -1,   180,    -1,   182,   183,
      -1,   185,   186,   187,    -1,   189,    -1,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,    -1,    -1,
     204,   205,   206,    -1,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,    -1,   253,
     254,   255,    -1,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      21,    22,    -1,    24,    -1,    -1,    -1,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      91,    92,    93,    94,    95,    96,    97,    98,    -1,    -1,
     101,   102,    -1,    -1,    -1,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    -1,    -1,   119,    -1,
     121,   122,   123,   124,    -1,   126,    -1,    -1,    -1,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,    -1,    -1,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,    -1,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,   170,
     171,    -1,    -1,   174,   175,   176,    -1,    -1,    -1,   180,
      -1,   182,   183,    -1,   185,   186,   187,    -1,   189,    -1,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,    -1,    -1,   204,   205,   206,    -1,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,   253,   254,   255,    -1,   257,   258,   259,   260,
     261,   262,    -1,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,    11,    -1,    -1,    -1,    -1,    -1,    -1,
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
     168,    -1,   170,   171,    -1,    -1,   174,   175,   176,    -1,
      -1,    -1,   180,    -1,   182,   183,    -1,   185,   186,   187,
      -1,   189,    -1,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,    -1,    -1,   204,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,    -1,   253,   254,   255,    -1,   257,
     258,   259,   260,   261,   262,    -1,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    -1,    24,
      -1,    -1,    -1,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    91,    92,    93,    94,
      95,    96,    97,    98,    -1,    -1,   101,   102,    -1,    -1,
      -1,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,    -1,    -1,   119,    -1,   121,   122,   123,   124,
      -1,   126,    -1,    -1,    -1,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,   144,
     145,   146,   147,    -1,    -1,    -1,   151,   152,    -1,   154,
     155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,    -1,   174,
     175,   176,    -1,    -1,    -1,   180,    -1,   182,   183,    -1,
     185,   186,   187,    -1,   189,    -1,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,    -1,    -1,   204,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,   253,   254,
     255,    -1,   257,   258,   259,   260,   261,   262,    -1,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,    11,
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
     152,    -1,   154,   155,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,   164,   165,   166,   167,   168,    -1,    -1,    -1,
      -1,    -1,   174,   175,   176,    -1,    -1,    -1,   180,    -1,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,    -1,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
      -1,    -1,   204,   205,   206,    -1,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
      -1,   253,   254,   255,    -1,   257,   258,   259,   260,   261,
     262,    -1,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    28,
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
      -1,    -1,    -1,    -1,    -1,   174,   175,   176,    -1,    -1,
      -1,   180,    -1,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,    -1,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,    -1,    -1,   204,   205,    -1,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,    -1,   253,   254,   255,    -1,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    -1,    91,    92,    93,    94,    -1,
      96,    97,    98,    -1,    -1,   101,   102,    -1,    -1,    -1,
      -1,   107,   108,   109,   110,   111,   112,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,    -1,
     126,    -1,    -1,    -1,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,    -1,    -1,   141,   142,   143,    -1,   145,
     146,   147,    -1,    -1,    -1,    -1,    -1,    -1,   154,   155,
      -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,    -1,   174,   175,
     176,    -1,    -1,    -1,   180,    -1,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,    -1,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,    -1,    -1,   204,   205,
      -1,    -1,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,   253,   254,   255,
      -1,   257,   258,   259,   260,   261,   262,    -1,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    -1,    24,    -1,    -1,
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
     147,    -1,    -1,    -1,    -1,    -1,    -1,   154,   155,    -1,
      -1,    -1,    -1,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,    -1,   174,   175,   176,
      -1,    -1,    -1,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,    -1,   189,    -1,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,    -1,    -1,   204,   205,    -1,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,    -1,   253,   254,   255,    -1,
     257,   258,   259,   260,   261,   262,    -1,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,    15,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,   174,   175,   176,    -1,
      -1,    -1,   180,    -1,   182,   183,    -1,    -1,    -1,    -1,
      -1,   189,    -1,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,    -1,    -1,   204,   205,    -1,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,    -1,   253,   254,   255,    -1,   257,
     258,   259,   260,   261,   262,    -1,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,    17,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
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
      -1,    -1,    -1,   174,   175,   176,    -1,    -1,    -1,   180,
      -1,   182,   183,    -1,    -1,    -1,    -1,    -1,   189,    -1,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,    -1,    -1,   204,   205,    -1,    -1,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,   253,   254,   255,    -1,   257,   258,   259,   260,
     261,   262,    -1,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,    22,    -1,    -1,    -1,    -1,    -1,    28,
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
      -1,    -1,   151,    -1,    -1,   154,   155,    -1,    -1,    -1,
      -1,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,    -1,   174,   175,   176,    -1,    -1,
      -1,   180,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,    -1,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,    -1,    -1,   204,   205,    -1,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,    -1,   253,   254,   255,    -1,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,    22,    -1,    -1,    -1,    -1,
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
     147,    -1,    -1,    -1,    -1,    -1,    -1,   154,   155,    -1,
      -1,    -1,    -1,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,    -1,   174,   175,   176,
      -1,    -1,    -1,   180,   181,   182,   183,    -1,    -1,    -1,
     187,    -1,   189,    -1,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,    -1,    -1,   204,   205,    -1,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,    -1,   253,   254,   255,    -1,
     257,   258,   259,   260,   261,   262,    -1,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,    22,    -1,    -1,
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
     145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,   154,
     155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,   174,
     175,   176,    -1,    -1,    -1,   180,   181,   182,   183,    -1,
      -1,    -1,   187,    -1,   189,    -1,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,    -1,    -1,   204,
     205,    -1,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,   253,   254,
     255,    -1,   257,   258,   259,   260,   261,   262,    -1,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,    22,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    91,    92,
      93,    94,    -1,    96,    97,    98,    -1,    -1,   101,   102,
      -1,    -1,    -1,    -1,   107,   108,   109,   110,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
     123,   124,    -1,   126,    -1,    -1,    -1,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,    -1,    -1,   141,   142,
     143,    -1,   145,   146,   147,    -1,    -1,    -1,   151,    -1,
      -1,   154,   155,    -1,    -1,    -1,    -1,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
      -1,   174,   175,   176,    -1,    -1,    -1,   180,    -1,   182,
     183,    -1,    -1,    -1,    -1,    -1,   189,    -1,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,    -1,
      -1,   204,   205,    -1,    -1,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,    -1,
     253,   254,   255,    -1,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,    22,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
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
     151,    -1,    -1,   154,   155,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,    -1,   174,   175,   176,    -1,    -1,    -1,   180,
      -1,   182,   183,    -1,    -1,    -1,    -1,    -1,   189,    -1,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,    -1,    -1,   204,   205,    -1,    -1,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,   253,   254,   255,    -1,   257,   258,   259,   260,
     261,   262,    -1,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,    22,    -1,    -1,    -1,    -1,    -1,    28,
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
      -1,    -1,   151,    -1,    -1,   154,   155,    -1,    -1,    -1,
      -1,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,    -1,   174,   175,   176,    -1,    -1,
      -1,   180,    -1,   182,   183,    -1,    -1,    -1,    -1,    -1,
     189,    -1,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,    -1,    -1,   204,   205,    -1,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,    -1,   253,   254,   255,    -1,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,    22,    -1,    -1,    -1,    -1,
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
     147,    -1,    -1,    -1,    -1,    -1,    -1,   154,   155,    -1,
      -1,    -1,    -1,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,    -1,   174,   175,   176,
      -1,    -1,    -1,   180,    -1,   182,   183,    -1,    -1,    -1,
      -1,    -1,   189,    -1,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,    -1,    -1,   204,   205,    -1,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,    -1,   253,   254,   255,    -1,
     257,   258,   259,   260,   261,   262,    -1,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,    22,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    31,    32,    33,    -1,
      35,    36,    37,    38,    39,    -1,    -1,    42,    43,    44,
      -1,    46,    47,    48,    49,    50,    -1,    52,    53,    54,
      55,    56,    -1,    58,    -1,    -1,    61,    62,    63,    64,
      65,    -1,    67,    -1,    69,    -1,    -1,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    91,    92,    93,    -1,
      -1,    96,    97,    98,    -1,    -1,   101,   102,    -1,    -1,
      -1,    -1,   107,   108,   109,   110,   111,   112,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,
      -1,   126,    -1,    -1,    -1,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,    -1,
     145,   146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,
     155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,   174,
     175,   176,    -1,    -1,    -1,   180,    -1,   182,   183,    -1,
      -1,    -1,    -1,    -1,   189,    -1,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,    -1,    -1,    -1,
     205,    -1,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,   253,   254,
     255,    -1,   257,   258,   259,   260,   261,   262,    -1,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
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
     155,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     170,   171,   174,   175,   176,   180,   182,   183,   185,   186,
     187,   189,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   204,   205,   206,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     253,   254,   255,   257,   258,   259,   260,   261,   262,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     319,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   349,   350,   355,   358,   361,   364,
     365,   367,   372,   373,   374,   375,   376,   385,   386,   388,
     389,   390,   395,   397,   399,   400,   405,   426,   429,   433,
     436,   437,   438,   439,   441,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   487,   488,   489,   503,   504,   506,
     507,   508,   509,   510,   511,   512,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   532,   533,   534,   535,
     540,   541,   542,   543,   544,   545,   548,   552,   608,   609,
      28,    29,    46,   178,   208,   386,   178,   386,   178,   386,
      32,    33,    35,    36,    38,    44,    52,    54,    55,    61,
      63,    72,    76,   107,   108,   109,   155,   164,   195,   213,
     223,   255,   281,   282,   283,   284,   285,   287,   288,   289,
     290,   291,   296,   297,   356,   357,   377,   378,   379,   380,
     155,   148,   151,   148,   151,   148,   151,   148,    64,    69,
     114,   392,   151,   366,   151,    29,    58,   114,   148,   151,
     151,   151,   114,   114,   148,   151,   151,   151,    91,   148,
     214,   215,   117,   117,   117,   148,   151,    34,    39,    41,
      42,    43,    44,    45,    48,    57,    62,    65,    68,    70,
      71,    73,    87,    88,    94,   101,   110,   111,   130,   133,
     134,   164,   167,   174,   175,   183,   195,   217,   219,   221,
     222,   229,   231,   232,   233,   234,   237,   238,   240,   471,
     608,   609,   117,   117,   117,    34,    40,    41,    57,    59,
      60,    68,    94,   218,   608,   114,   117,   117,   181,   386,
     608,   148,   117,    15,   607,   608,    17,   608,   117,   117,
     117,   463,   148,    25,   207,   209,   218,   220,   151,   218,
     220,   218,   218,   223,   114,   148,   368,   235,   235,   236,
     151,   148,   114,   321,     0,   323,   324,    28,    46,   326,
     327,     1,   184,   320,   184,   320,   103,   184,   387,    37,
      43,    48,    67,   163,   166,   180,   205,   391,   396,   397,
     398,   414,   415,   419,   162,    89,   127,   135,   136,   138,
     146,   150,   152,   157,   173,   196,   197,   198,   199,   200,
     201,   455,   456,   243,   153,   170,   192,   113,   141,   154,
     187,   194,   203,   131,   145,    47,   193,    97,    98,   153,
     170,   454,   148,   460,   463,   185,   186,   149,   475,   476,
     471,   475,   471,   151,   475,   140,   151,   178,   178,   178,
      24,   606,   176,   189,   176,   189,   161,   176,   377,   609,
     377,   608,   164,   195,    44,   378,    44,   608,   147,   114,
     354,    41,    44,    76,   102,   163,   607,   214,   215,   216,
     294,   295,   240,   579,   608,   287,   608,   292,   292,   294,
     295,   298,   281,   289,   357,   607,   386,   181,   386,    41,
      60,   181,   528,   529,   386,   181,   187,   608,   389,   278,
     278,   401,   402,   608,   114,   409,   114,   181,   381,   382,
     148,   383,   386,   155,   606,   109,   155,   348,   606,   406,
     408,   608,   386,    24,   181,   607,   608,   608,   608,   427,
     428,   608,   386,   181,   386,   386,   530,   608,   386,   148,
     148,   386,   181,   187,   608,   427,   181,    30,   491,   492,
     493,   386,     8,   169,    16,   386,   207,    24,   389,   389,
     181,   389,   389,   389,   389,   224,   546,   547,   608,   369,
     389,   389,   386,   407,   413,   608,   184,   320,   184,   320,
       3,   327,   328,   385,   327,   328,   385,    28,   329,   385,
     329,   385,   389,   388,   114,   163,   165,   165,   389,   389,
     438,   439,   441,   441,   441,   441,   440,   441,   441,   441,
      68,   445,   445,   444,   446,   446,   446,   446,   447,   447,
     448,   448,   224,    91,    91,    91,   178,   386,   463,   463,
     386,   476,   181,   389,   486,   144,   181,   486,   103,   103,
     366,    24,   609,   609,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,   331,   332,   333,    91,   132,   137,
     351,   352,   353,   608,   132,   137,   155,   155,   331,   606,
     122,   127,    51,    54,    96,   245,   258,   260,   271,   272,
     273,   275,   277,   580,   581,   582,   583,   584,   585,   592,
     598,   599,   240,    91,   230,   360,   293,   608,   608,   608,
     127,   178,   178,   181,   181,   178,   103,   181,   103,   181,
     178,   103,    31,    91,    93,   142,   267,   403,   404,   514,
     608,    53,   210,   248,   393,   394,   608,    91,   103,   181,
     386,   181,   607,    93,    41,   607,   606,    93,   103,   137,
     404,   514,   178,   181,   181,   181,   181,   137,   103,   182,
     142,   514,   178,   181,   181,   148,   178,   386,   386,   178,
     103,   181,   103,   181,   182,   608,   492,   493,   125,   190,
     178,   178,   126,   184,    91,   211,   212,   226,    91,   211,
     212,   226,    91,   230,   218,   103,   228,   137,    28,   370,
     386,   181,   178,    42,   103,   327,    28,    28,   184,   320,
     184,   109,   184,   608,   165,   389,   420,   421,   114,   416,
     417,   441,   148,   151,   253,   459,   478,   553,   556,   557,
     558,   559,   560,   564,   566,   568,   569,    44,   147,   151,
     204,   515,   517,   519,   520,   536,   537,   538,   539,   608,
     515,   513,   519,   513,   178,   179,   103,   181,   181,   143,
     160,   143,   160,   132,   148,   384,   366,   366,   332,   127,
     517,   353,   389,   514,   137,   389,   606,   606,   123,   124,
     606,   271,   272,   273,   277,   608,   257,   268,   257,   268,
      24,   280,    93,   109,   151,   586,   589,   580,    34,    40,
      57,    59,    68,    94,   218,   359,   520,   285,   286,   220,
     293,   302,    91,   360,   293,   606,   148,   530,   531,   608,
     530,   531,   114,   122,   515,   114,   389,   114,   142,   404,
     142,    31,   142,   403,   404,   142,   514,   248,    50,    56,
      74,   114,   403,   410,   411,   412,   394,   514,   515,   382,
      91,   178,   191,   127,   347,   606,   155,   127,    93,   347,
     114,   389,   137,   137,   404,   148,   389,   114,   389,   389,
     142,    96,   430,   431,   432,    96,   434,   435,   386,   178,
     178,   148,   530,   530,   389,    30,   493,   125,   190,     9,
      10,    99,   118,   120,   188,   383,   488,   490,   501,   502,
     505,    24,   225,   227,   389,   389,   389,   225,   227,   389,
     389,   389,   389,   389,   389,   114,   389,   389,   354,   371,
     103,   184,   178,   368,   239,   549,   550,   148,   114,   184,
     109,   385,   385,   385,   420,    92,   102,   112,   122,   422,
     423,   424,   425,   103,   608,   103,   386,   553,   560,   148,
     279,   442,   605,    93,   164,   246,   247,   249,   256,   266,
     278,   554,   555,   574,   575,   576,   577,   600,   603,   252,
     254,   561,   579,   261,   565,   601,   241,   242,   264,   570,
     571,   151,   151,   517,   151,   139,   170,   187,   516,   139,
     389,   386,   132,   368,   132,   148,   532,   352,   389,   280,
      24,    93,   109,   151,   593,    24,   586,   360,   516,   220,
     220,   461,   281,   300,   359,   220,   184,   178,   386,   181,
     181,   139,   181,   181,   402,   142,   403,   608,   608,   389,
     142,   389,   122,   389,   142,   404,   142,   389,   142,   114,
     114,   389,   608,   412,    74,   515,   389,   606,   103,   347,
     408,   389,   389,   137,   178,   386,   428,   389,   389,   109,
     431,    96,   180,   114,   515,   109,   435,   178,   178,   386,
     181,   181,   127,   188,   490,     7,   608,   188,   501,   184,
     226,   226,   226,   226,   230,   547,   180,   137,   371,   472,
     551,   550,   389,   413,   606,   123,   124,   424,   425,   425,
     421,   102,   418,   417,   178,   181,   553,   567,   244,   210,
     248,   262,   269,   604,    93,   250,   251,   602,   244,   557,
     604,   444,   574,   558,   142,   276,   562,   563,   602,   280,
     573,    75,   572,   181,   187,   515,   518,   181,   181,   181,
     178,   388,    24,   131,   194,   595,   596,   597,    24,   594,
     595,   265,   590,   587,   588,   589,   165,   608,   251,   360,
     461,   178,   389,   142,   389,   142,   403,   389,   142,   389,
     389,   608,   608,   411,   389,   121,    93,   606,   389,   178,
     180,   389,   389,   608,   180,   114,   180,   178,   493,   608,
     188,   493,   608,   389,   389,   389,   389,   389,   389,   389,
     151,   203,   384,   178,   425,   606,   178,   446,    49,   124,
     444,   444,   263,   270,   280,   578,   578,   559,   148,   274,
      91,   181,   103,   181,   178,   593,   593,   597,   103,   181,
      24,   591,   602,   181,   103,   362,   363,   461,   114,   218,
     301,   281,   165,   389,   389,   142,   389,    50,   389,   347,
     389,    91,   389,   608,   389,    90,   177,   494,   493,   608,
     190,   493,   114,   472,   444,   444,   192,   386,   515,   515,
      91,    24,   259,   589,   103,   425,   514,   608,   114,   218,
     608,   362,   389,   114,   515,   180,     5,   128,   497,   498,
     500,   502,    23,   129,   495,   496,   499,   502,   190,   493,
     190,   608,   444,   178,   515,   363,   425,   299,   608,   114,
     218,   608,   180,   389,    90,   128,   500,   177,   129,   499,
     190,   103,   181,   389,   299,   608,   114,   389,   114,   384,
     287,   299,   608,   608,   300,   389,   300,   103,   181,   461,
     461,   114,   384,   192,   608,   281,   181,   608,   384,   218,
     114,   608,   300,   461
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
     565,   566,   567,   568,   569,   570,   571,   572
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   318,   319,   319,   320,   321,   321,   321,   321,   322,
     322,   323,   323,   323,   323,   323,   323,   323,   323,   324,
     324,   324,   324,   325,   326,   326,   326,   327,   327,   327,
     328,   328,   328,   328,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   330,   330,   331,   331,   332,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   334,   334,
     334,   334,   334,   334,   334,   334,   335,   335,   336,   337,
     337,   338,   338,   339,   340,   341,   341,   342,   342,   343,
     343,   343,   343,   344,   345,   346,   346,   346,   346,   347,
     347,   348,   348,   349,   349,   349,   349,   350,   351,   351,
     352,   352,   352,   353,   354,   354,   355,   355,   355,   356,
     356,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   358,   358,   358,   358,   358,
     358,   358,   358,   359,   359,   360,   360,   361,   361,   362,
     362,   363,   363,   363,   363,   364,   364,   364,   364,   365,
     365,   366,   366,   366,   366,   367,   368,   369,   369,   370,
     370,   371,   371,   372,   373,   374,   375,   375,   376,   376,
     376,   377,   377,   377,   377,   378,   378,   379,   379,   380,
     380,   381,   381,   382,   382,   383,   384,   385,   386,   386,
     387,   387,   388,   388,   389,   389,   389,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   389,   390,   391,   392,   392,   393,   393,   393,   394,
     394,   395,   395,   396,   397,   397,   397,   398,   398,   398,
     398,   398,   399,   399,   400,   401,   401,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   402,   402,   403,
     404,   405,   406,   406,   407,   407,   408,   408,   408,   408,
     409,   409,   410,   410,   410,   411,   411,   411,   412,   412,
     412,   413,   414,   415,   416,   416,   417,   417,   418,   419,
     419,   420,   420,   421,   421,   422,   422,   422,   422,   422,
     422,   422,   423,   423,   424,   424,   425,   426,   426,   427,
     427,   428,   428,   429,   430,   430,   431,   432,   432,   433,
     433,   434,   434,   435,   435,   436,   437,   437,   438,   438,
     439,   439,   439,   439,   439,   440,   439,   439,   439,   439,
     441,   441,   442,   442,   443,   443,   444,   444,   444,   445,
     445,   445,   445,   445,   446,   446,   446,   447,   447,   447,
     448,   448,   449,   449,   450,   450,   451,   451,   452,   452,
     453,   453,   453,   453,   454,   454,   454,   455,   455,   455,
     455,   455,   455,   456,   456,   456,   457,   457,   457,   457,
     458,   458,   459,   459,   460,   460,   461,   461,   461,   461,
     462,   463,   463,   463,   464,   464,   465,   465,   465,   465,
     466,   466,   467,   467,   467,   467,   467,   467,   467,   468,
     468,   469,   469,   470,   470,   470,   470,   470,   471,   471,
     472,   472,   473,   473,   473,   474,   474,   474,   474,   475,
     475,   476,   477,   477,   477,   477,   477,   477,   477,   477,
     477,   478,   478,   479,   479,   479,   480,   481,   481,   482,
     483,   484,   485,   485,   486,   486,   487,   487,   488,   488,
     488,   489,   489,   489,   489,   489,   489,   490,   490,   491,
     491,   492,   493,   493,   494,   494,   495,   495,   496,   496,
     496,   496,   497,   497,   498,   498,   498,   498,   499,   499,
     500,   500,   501,   501,   501,   501,   502,   502,   502,   502,
     503,   503,   504,   504,   505,   506,   506,   506,   506,   506,
     506,   507,   508,   508,   508,   508,   509,   509,   509,   509,
     510,   511,   512,   512,   512,   512,   513,   513,   514,   515,
     515,   515,   516,   516,   516,   517,   517,   517,   517,   517,
     518,   518,   519,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   521,   522,   522,   522,   523,   524,   525,   525,
     525,   526,   526,   526,   526,   526,   527,   528,   528,   528,
     528,   528,   528,   528,   529,   530,   531,   532,   533,   533,
     534,   535,   536,   536,   537,   538,   538,   539,   540,   540,
     540,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   542,   542,   543,   543,   544,   545,   546,   546,   547,
     548,   549,   549,   550,   550,   550,   550,   551,   551,   552,
     552,   553,   554,   554,   555,   555,   556,   556,   557,   557,
     558,   558,   559,   559,   560,   561,   561,   562,   562,   563,
     564,   564,   564,   565,   565,   566,   567,   567,   568,   569,
     569,   570,   570,   571,   571,   571,   572,   572,   573,   573,
     574,   574,   574,   574,   574,   575,   576,   577,   578,   578,
     578,   579,   579,   580,   580,   580,   580,   580,   580,   580,
     580,   581,   581,   581,   581,   582,   582,   583,   584,   584,
     585,   585,   585,   586,   586,   587,   587,   588,   588,   589,
     590,   590,   591,   591,   592,   592,   592,   593,   593,   594,
     594,   595,   595,   596,   596,   597,   597,   598,   599,   599,
     600,   600,   600,   601,   602,   602,   602,   602,   603,   603,
     604,   604,   605,   606,   607,   607,   608,   608,   608,   608,
     608,   608,   608,   608,   608,   608,   608,   608,   608,   608,
     608,   608,   609,   609,   609,   609,   609,   609,   609,   609,
     609,   609,   609,   609,   609,   609,   609,   609,   609,   609,
     609,   609,   609,   609,   609,   609,   609,   609,   609,   609,
     609,   609,   609,   609,   609,   609,   609,   609,   609,   609,
     609,   609,   609,   609,   609,   609,   609,   609,   609,   609,
     609,   609,   609,   609,   609,   609,   609,   609,   609,   609,
     609,   609,   609,   609,   609,   609,   609,   609,   609,   609,
     609,   609,   609,   609,   609,   609,   609,   609,   609,   609,
     609,   609,   609,   609,   609,   609,   609,   609,   609,   609,
     609,   609,   609,   609,   609,   609,   609,   609,   609,   609,
     609,   609,   609,   609,   609,   609,   609,   609,   609,   609,
     609,   609,   609,   609,   609,   609,   609,   609,   609,   609,
     609,   609,   609,   609,   609,   609,   609,   609,   609,   609,
     609,   609,   609,   609,   609,   609,   609,   609,   609,   609,
     609,   609,   609,   609,   609,   609,   609,   609,   609,   609,
     609,   609,   609,   609,   609,   609,   609,   609,   609,   609,
     609,   609,   609,   609,   609,   609,   609,   609,   609,   609,
     609,   609,   609,   609,   609,   609,   609,   609,   609,   609,
     609,   609,   609,   609,   609,   609,   609,   609,   609,   609,
     609,   609,   609,   609,   609,   609,   609,   609,   609,   609,
     609,   609
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
       1,     1,     2,     2,     2,     3,     5,     4,     6,     1,
       2,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     1,     2,     2,     2,     3,     4,     5,     6,     4,
       5,     6,     7,     1,     2,     3,     3,     8,     9,     1,
       3,     1,     2,     2,     3,    11,    14,    13,    22,     3,
       3,     2,     3,     4,     5,     2,     4,     3,     0,     3,
       2,     1,     3,     5,     3,     5,     2,     2,     2,     3,
       3,     1,     2,     1,     1,     4,     4,     5,     5,     7,
       5,     1,     3,     2,     3,     3,     3,     1,     1,     2,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     1,     1,     2,     4,
       3,     5,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     1,     4,     3,     5,     4,
       6,     4,     6,     5,     7,     4,     5,     5,     6,     3,
       3,     3,     1,     4,     1,     4,     3,     4,     4,     5,
       4,     5,     1,     2,     3,     1,     2,     1,     6,     3,
       3,     1,     2,     3,     1,     3,     2,     3,     2,     3,
       4,     1,     3,     1,     2,     1,     1,     1,     2,     2,
       2,     3,     1,     1,     2,     2,     2,     5,     5,     1,
       4,     3,     4,     8,     1,     2,     3,     2,     3,     8,
      10,     1,     2,     4,     7,     8,     1,     3,     1,     3,
       1,     3,     3,     3,     3,     0,     4,     3,     3,     3,
       1,     5,     0,     1,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     4,     1,     4,     1,     4,     1,     4,     1,     2,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     5,     5,     6,
       3,     4,     1,     2,     3,     2,     1,     2,     2,     1,
       1,     1,     3,     3,     1,     1,     1,     2,     1,     2,
       2,     1,     2,     2,     2,     2,     2,     2,     2,     1,
       2,     2,     1,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     4,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     3,     1,
       4,     4,     3,     4,     1,     3,     1,     1,     1,     1,
       1,     4,     5,     8,     9,     9,    10,     1,     2,     1,
       2,     6,     0,     1,     3,     3,     0,     1,     1,     1,
       2,     2,     0,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     3,     3,     2,     1,     1,     1,     1,     1,
       1,     4,     2,     3,     6,     7,     2,     3,     6,     7,
       4,     4,     2,     3,     6,     7,     1,     2,     2,     1,
       2,     3,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     4,     4,     3,     3,     3,     4,
       4,     3,     4,     6,     4,     6,     4,     3,     4,     6,
       6,     4,     6,     6,     4,     1,     2,     1,     1,     1,
       3,     3,     1,     1,     4,     5,     6,     3,     3,     3,
       3,     5,     7,     7,     5,     5,     5,     7,     7,     5,
       5,     3,     3,     5,     7,     5,     7,     1,     4,     3,
       5,     1,     2,     3,     7,    10,    13,     1,     3,     7,
       4,     2,     0,     1,     1,     2,     1,     3,     1,     3,
       1,     4,     1,     2,     3,     0,     1,     0,     1,     4,
       2,     3,     1,     0,     1,     4,     0,     1,     2,     1,
       3,     0,     1,     2,     2,     1,     0,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     2,     2,     3,     1,     2,
       2,     5,     2,     1,     1,     0,     1,     1,     3,     4,
       0,     2,     0,     2,     4,     4,     3,     2,     3,     1,
       3,     0,     1,     1,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     3,     2,     3,     3,     4,     2,     2,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
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
  "\"'by'\"", "\"'group'\"", "\"'parent'\"", "\"'<?'\"", "\"'?>'\"",
  "\"'+'\"", "\"'(#'\"", "\"'#)'\"", "\"'<<'\"", "\"'preceding'\"",
  "\"'preceding-sibling'\"", "\"'preserve'\"", "\"'\\\"'\"", "\"'}'\"",
  "\"']'\"", "\"'return'\"", "\"')'\"", "\"'satisfies'\"", "\"'self'\"",
  "\"';'\"", "\"'/'\"", "\"'//'\"", "\"'*'\"", "\"'</ (start tag end)'\"",
  "\"'strip'\"", "\"'> (tag end)'\"", "\"'then'\"", "\"'to'\"",
  "\"'treat'\"", "\"'union'\"", "\"'unordered'\"", "\"'eq'\"", "\"'ge'\"",
  "\"'gt'\"", "\"'le'\"", "\"'lt'\"", "\"'ne'\"", "\"'VALUECOMP'\"",
  "\"'|'\"", "\"'empty-sequence'\"", "\"'where'\"", "\"'<!--'\"",
  "\"'-->'\"", "\"'xquery'\"", "\"'version'\"", "\"'start'\"",
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
  "WhileExpr", "FlowCtlStatement", "FunctionDecl", "FunctionDecl2",
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
       319,     0,    -1,   321,    -1,   304,   321,    -1,     1,     3,
      -1,   323,    -1,   322,   323,    -1,   324,    -1,   322,   324,
      -1,   208,   209,    24,   184,    -1,   208,   209,    24,   126,
      24,   184,    -1,   326,   184,   385,    -1,   327,   184,   385,
      -1,   326,   184,   327,   184,   385,    -1,   385,    -1,   326,
     320,   385,    -1,   327,   320,   385,    -1,   326,   184,   327,
     320,   385,    -1,   326,   320,   327,   184,   385,    -1,   325,
      -1,   325,   326,   184,    -1,   325,   327,   184,    -1,   325,
     326,   184,   327,   184,    -1,    29,   155,   607,   127,   606,
     184,    -1,   328,    -1,   326,   184,   328,    -1,   326,   320,
     328,    -1,   329,    -1,   327,   184,   329,    -1,   327,   320,
     329,    -1,   334,    -1,   335,    -1,   336,    -1,   338,    -1,
     355,    -1,   358,    -1,   350,    -1,   330,    -1,   340,    -1,
     376,    -1,   361,    -1,   364,    -1,   339,    -1,    28,   109,
      76,   331,    -1,    28,    76,   608,   331,    -1,   332,    -1,
     331,   332,    -1,   333,   127,   532,    -1,    77,    -1,    85,
      -1,    78,    -1,    79,    -1,    80,    -1,    81,    -1,    86,
      -1,    82,    -1,    83,    -1,    84,    -1,   337,    -1,   344,
      -1,   345,    -1,   365,    -1,   341,    -1,   342,    -1,   343,
      -1,   540,    -1,   346,    -1,   349,    -1,    28,   155,   607,
     127,   606,    -1,    28,    33,   176,    -1,    28,    33,   189,
      -1,    28,   109,    41,   155,   606,    -1,    28,   109,    44,
     155,   606,    -1,    28,    54,   608,    24,    -1,    28,   255,
     579,    -1,    28,    55,   164,    -1,    28,    55,   195,    -1,
      28,   109,   163,   122,   123,    -1,    28,   109,   163,   122,
     124,    -1,    28,    36,   176,   103,   143,    -1,    28,    36,
     176,   103,   160,    -1,    28,    36,   161,   103,   143,    -1,
      28,    36,   161,   103,   160,    -1,    28,   109,   102,   606,
      -1,    28,    32,   606,    -1,    46,    58,   606,    -1,    46,
      58,   348,   606,    -1,    46,    58,   606,    93,   347,    -1,
      46,    58,   348,   606,    93,   347,    -1,   606,    -1,   347,
     103,   606,    -1,   155,   607,   127,    -1,   109,    41,   155,
      -1,    46,    29,   606,    -1,    46,    29,   155,   607,   127,
     606,    -1,    46,    29,   606,    93,   347,    -1,    46,    29,
     155,   607,   127,   606,    93,   347,    -1,    28,   107,   147,
     351,    -1,    91,   517,   352,    -1,   352,    -1,   353,    -1,
     132,    -1,   132,   353,    -1,   137,   389,    -1,   114,   608,
      -1,   114,   608,   514,    -1,    28,   108,   354,   137,   389,
      -1,    28,   108,   354,   132,    -1,    28,   108,   354,   132,
     137,   389,    -1,   357,    -1,   356,   357,    -1,   282,    -1,
     283,    -1,   284,    -1,   285,    -1,   164,    -1,   195,    -1,
     223,   295,    -1,   223,   294,    -1,   296,   295,    -1,   296,
     294,    -1,   287,    -1,   288,   287,    -1,   291,   292,    -1,
     290,   292,    -1,    28,   281,   608,    -1,    28,   281,   608,
     360,    -1,    28,   281,   608,    91,   359,    -1,    28,   281,
     608,    91,   359,   360,    -1,    28,   356,   281,   608,    -1,
      28,   356,   281,   608,   360,    -1,    28,   356,   281,   608,
      91,   359,    -1,    28,   356,   281,   608,    91,   359,   360,
      -1,   520,    -1,   520,   516,    -1,   230,   286,   220,    -1,
     230,   285,   220,    -1,    28,   289,   608,   293,   220,   461,
     165,   362,    -1,    28,   356,   289,   608,   293,   220,   461,
     165,   362,    -1,   363,    -1,   362,   103,   363,    -1,   461,
      -1,   461,   514,    -1,   461,   425,    -1,   461,   514,   425,
      -1,    28,   297,   298,   608,   293,   281,   608,   114,   608,
     299,   389,    -1,    28,   297,   298,   608,   293,   281,   608,
     218,   114,   608,   299,   287,   300,   461,    -1,    28,   297,
     298,   608,   293,   281,   608,   301,   218,   114,   608,   299,
     389,    -1,    28,   297,   298,   608,   302,   300,   251,   281,
     608,   218,   114,   608,   300,   461,   192,   281,   608,   218,
     114,   608,   300,   461,    -1,    28,    35,   176,    -1,    28,
      35,   189,    -1,   151,   181,    -1,   151,   381,   181,    -1,
     151,   181,    91,   515,    -1,   151,   381,   181,    91,   515,
      -1,   231,   368,    -1,   148,   369,   386,   178,    -1,   369,
     370,   184,    -1,    -1,   370,   103,   371,    -1,    28,   371,
      -1,   354,    -1,   354,   137,   389,    -1,    62,   114,   608,
     137,   389,    -1,   234,   236,   389,    -1,   237,   151,   389,
     181,   368,    -1,   232,   235,    -1,   233,   235,    -1,    28,
     377,    -1,    28,    52,   377,    -1,    28,    38,   377,    -1,
     378,    -1,    63,   378,    -1,   380,    -1,   379,    -1,    44,
     609,   366,   384,    -1,    44,   609,   366,   132,    -1,    61,
      44,   609,   366,   368,    -1,    61,    44,   609,   366,   132,
      -1,    72,    44,   609,   366,   148,   388,   178,    -1,    72,
      44,   609,   366,   132,    -1,   382,    -1,   381,   103,   382,
      -1,   114,   608,    -1,   114,   608,   514,    -1,   148,   386,
     178,    -1,   148,   386,   178,    -1,   386,    -1,   388,    -1,
     388,   387,    -1,   184,    -1,   387,   388,   184,    -1,   389,
      -1,   388,   103,   389,    -1,   390,    -1,   426,    -1,   429,
      -1,   433,    -1,   436,    -1,   437,    -1,   541,    -1,   542,
      -1,   544,    -1,   543,    -1,   545,    -1,   548,    -1,   552,
      -1,   373,    -1,   374,    -1,   375,    -1,   372,    -1,   367,
      -1,   399,   391,    -1,   180,   389,    -1,    64,   278,    -1,
      69,   278,    -1,   210,    -1,   248,    -1,    53,   248,    -1,
     393,   410,    74,   389,    -1,   393,    74,   389,    -1,    43,
     392,   409,   394,   394,    -1,    43,   392,   409,   394,    -1,
      37,   114,   608,    -1,   400,    -1,   405,    -1,   395,    -1,
     397,    -1,   414,    -1,   419,    -1,   415,    -1,   396,    -1,
     397,    -1,   399,   398,    -1,    43,   114,   401,    -1,   402,
      -1,   401,   103,   114,   402,    -1,   608,   142,   389,    -1,
     608,    31,   122,   142,   389,    -1,   608,   514,   142,   389,
      -1,   608,   514,    31,   122,   142,   389,    -1,   608,   403,
     142,   389,    -1,   608,    31,   122,   403,   142,   389,    -1,
     608,   514,   403,   142,   389,    -1,   608,   514,    31,   122,
     403,   142,   389,    -1,   608,   404,   142,   389,    -1,   608,
     514,   404,   142,   389,    -1,   608,   403,   404,   142,   389,
      -1,   608,   514,   403,   404,   142,   389,    -1,    93,   114,
     608,    -1,   267,   114,   608,    -1,    48,   114,   406,    -1,
     408,    -1,   406,   103,   114,   408,    -1,   413,    -1,   407,
     103,   114,   413,    -1,   608,   137,   389,    -1,   608,   514,
     137,   389,    -1,   608,   404,   137,   389,    -1,   608,   514,
     404,   137,   389,    -1,   114,   608,   142,   389,    -1,   114,
     608,   514,   142,   389,    -1,   411,    -1,   114,   608,    -1,
     114,   608,   411,    -1,   403,    -1,   403,   412,    -1,   412,
      -1,    56,   114,   608,    50,   114,   608,    -1,    50,   114,
     608,    -1,    56,   114,   608,    -1,   608,    -1,   205,   389,
      -1,   166,   165,   416,    -1,   417,    -1,   416,   103,   417,
      -1,   114,   608,    -1,   114,   608,   418,    -1,   102,   606,
      -1,   163,   165,   420,    -1,    67,   163,   165,   420,    -1,
     421,    -1,   420,   103,   421,    -1,   389,    -1,   389,   422,
      -1,   423,    -1,   424,    -1,   425,    -1,   423,   424,    -1,
     423,   425,    -1,   424,   425,    -1,   423,   424,   425,    -1,
      92,    -1,   112,    -1,   122,   123,    -1,   122,   124,    -1,
     102,   606,    -1,    65,   114,   427,   182,   389,    -1,   130,
     114,   427,   182,   389,    -1,   428,    -1,   427,   103,   114,
     428,    -1,   608,   142,   389,    -1,   608,   514,   142,   389,
      -1,    70,   151,   386,   181,   430,   109,   180,   389,    -1,
     431,    -1,   430,   431,    -1,   432,   180,   389,    -1,    96,
     389,    -1,   432,    96,   389,    -1,    71,   151,   386,   181,
     434,   109,   180,   389,    -1,    71,   151,   386,   181,   434,
     109,   114,   608,   180,   389,    -1,   435,    -1,   434,   435,
      -1,    96,   515,   180,   389,    -1,    96,   114,   608,    91,
     515,   180,   389,    -1,    45,   151,   386,   181,   191,   389,
     121,   389,    -1,   438,    -1,   437,   162,   438,    -1,   439,
      -1,   438,    89,   439,    -1,   441,    -1,   441,   455,   441,
      -1,   441,   456,   441,    -1,   441,   127,   441,    -1,   441,
     157,   441,    -1,    -1,   441,   152,   440,   441,    -1,   441,
     150,   441,    -1,   441,   138,   441,    -1,   441,   136,   441,
      -1,   443,    -1,   443,   243,    68,   553,   442,    -1,    -1,
     605,    -1,   444,    -1,   444,   192,   444,    -1,   445,    -1,
     444,   170,   445,    -1,   444,   153,   445,    -1,   446,    -1,
     445,   187,   446,    -1,   445,   113,   446,    -1,   445,   141,
     446,    -1,   445,   154,   446,    -1,   447,    -1,   446,   194,
     447,    -1,   446,   203,   447,    -1,   448,    -1,   447,   145,
     448,    -1,   447,   131,   448,    -1,   449,    -1,   449,    47,
     224,   515,    -1,   450,    -1,   450,   193,    91,   515,    -1,
     451,    -1,   451,    97,    91,   513,    -1,   452,    -1,   452,
      98,    91,   513,    -1,   454,    -1,   453,   454,    -1,   170,
      -1,   153,    -1,   453,   170,    -1,   453,   153,    -1,   457,
      -1,   461,    -1,   458,    -1,   196,    -1,   201,    -1,   200,
      -1,   199,    -1,   198,    -1,   197,    -1,   146,    -1,   173,
      -1,   135,    -1,    73,   148,   386,   178,    -1,    73,   215,
     148,   386,   178,    -1,    73,   214,   148,   386,   178,    -1,
      73,    91,   530,   148,   386,   178,    -1,   459,   148,   178,
      -1,   459,   148,   386,   178,    -1,   460,    -1,   459,   460,
      -1,   171,   608,    16,    -1,   171,    17,    -1,   462,    -1,
     462,   463,    -1,   186,   463,    -1,   463,    -1,   185,    -1,
     464,    -1,   464,   185,   463,    -1,   464,   186,   463,    -1,
     465,    -1,   474,    -1,   466,    -1,   466,   475,    -1,   469,
      -1,   469,   475,    -1,   467,   471,    -1,   468,    -1,   101,
     117,    -1,   110,   117,    -1,    94,   117,    -1,   183,   117,
      -1,   111,   117,    -1,   134,   117,    -1,   133,   117,    -1,
     471,    -1,    95,   471,    -1,   470,   471,    -1,   116,    -1,
     167,   117,    -1,    87,   117,    -1,   175,   117,    -1,   174,
     117,    -1,    88,   117,    -1,   520,    -1,   472,    -1,   608,
      -1,   473,    -1,   187,    -1,    11,    -1,    18,    -1,   477,
      -1,   474,   475,    -1,   474,   151,   181,    -1,   474,   151,
     486,   181,    -1,   476,    -1,   475,   476,    -1,   149,   386,
     179,    -1,   478,    -1,   480,    -1,   481,    -1,   482,    -1,
     485,    -1,   487,    -1,   483,    -1,   484,    -1,   533,    -1,
     479,    -1,   532,    -1,   106,    -1,   144,    -1,   119,    -1,
     114,   608,    -1,   151,   181,    -1,   151,   386,   181,    -1,
     115,    -1,   164,   148,   386,   178,    -1,   195,   148,   386,
     178,    -1,   609,   151,   181,    -1,   609,   151,   486,   181,
      -1,   389,    -1,   486,   103,   389,    -1,   488,    -1,   506,
      -1,   489,    -1,   503,    -1,   504,    -1,   152,   608,   493,
     125,    -1,   152,   608,   491,   493,   125,    -1,   152,   608,
     493,   190,   188,   608,   493,   190,    -1,   152,   608,   493,
     190,   490,   188,   608,   493,   190,    -1,   152,   608,   491,
     493,   190,   188,   608,   493,   190,    -1,   152,   608,   491,
     493,   190,   490,   188,   608,   493,   190,    -1,   501,    -1,
     490,   501,    -1,   492,    -1,   491,   492,    -1,    30,   608,
     493,   127,   493,   494,    -1,    -1,    30,    -1,   177,   495,
     177,    -1,    90,   497,    90,    -1,    -1,   496,    -1,   129,
      -1,   499,    -1,   496,   129,    -1,   496,   499,    -1,    -1,
     498,    -1,   128,    -1,   500,    -1,   498,   128,    -1,   498,
     500,    -1,    23,    -1,   502,    -1,     5,    -1,   502,    -1,
     488,    -1,    10,    -1,   505,    -1,   502,    -1,     9,    -1,
     118,    -1,   120,    -1,   383,    -1,   206,    25,   207,    -1,
     206,   207,    -1,   168,   607,   169,    -1,   168,   607,     8,
      -1,    99,     7,    -1,   507,    -1,   508,    -1,   509,    -1,
     510,    -1,   511,    -1,   512,    -1,    39,   148,   386,   178,
      -1,    19,   178,    -1,    19,   386,   178,    -1,    41,   148,
     386,   178,   148,   178,    -1,    41,   148,   386,   178,   148,
     386,   178,    -1,    20,   178,    -1,    20,   386,   178,    -1,
      94,   148,   386,   178,   148,   178,    -1,    94,   148,   386,
     178,   148,   386,   178,    -1,    68,   148,   386,   178,    -1,
      34,   148,   386,   178,    -1,    21,   178,    -1,    21,   386,
     178,    -1,    57,   148,   386,   178,   148,   178,    -1,    57,
     148,   386,   178,   148,   386,   178,    -1,   519,    -1,   519,
     139,    -1,    91,   515,    -1,   517,    -1,   517,   516,    -1,
     204,   151,   181,    -1,   139,    -1,   187,    -1,   170,    -1,
     519,    -1,   520,    -1,   147,   151,   181,    -1,   536,    -1,
     539,    -1,   515,    -1,   518,   103,   515,    -1,   608,    -1,
     522,    -1,   528,    -1,   526,    -1,   529,    -1,   527,    -1,
     525,    -1,   524,    -1,   523,    -1,   521,    -1,   218,   151,
     181,    -1,    40,   151,   181,    -1,    40,   151,   528,   181,
      -1,    40,   151,   529,   181,    -1,    68,   151,   181,    -1,
      34,   151,   181,    -1,    57,   151,   181,    -1,    57,   151,
     607,   181,    -1,    57,   151,    24,   181,    -1,    94,   151,
     181,    -1,    94,   151,   608,   181,    -1,    94,   151,   608,
     103,   530,   181,    -1,    94,   151,   187,   181,    -1,    94,
     151,   187,   103,   530,   181,    -1,    59,   151,   608,   181,
      -1,    41,   151,   181,    -1,    41,   151,   608,   181,    -1,
      41,   151,   608,   103,   530,   181,    -1,    41,   151,   608,
     103,   531,   181,    -1,    41,   151,   187,   181,    -1,    41,
     151,   187,   103,   530,   181,    -1,    41,   151,   187,   103,
     531,   181,    -1,    60,   151,   608,   181,    -1,   608,    -1,
     608,   139,    -1,    24,    -1,   534,    -1,   535,    -1,   608,
     140,   144,    -1,    44,   366,   383,    -1,   537,    -1,   538,
      -1,    44,   151,   187,   181,    -1,    44,   151,   181,    91,
     515,    -1,    44,   151,   518,   181,    91,   515,    -1,   151,
     517,   181,    -1,    28,   213,   214,    -1,    28,   213,   215,
      -1,    28,   213,   216,    -1,   219,   218,   389,   226,   389,
      -1,   219,   218,   389,    91,   225,   226,   389,    -1,   219,
     218,   389,    91,   227,   226,   389,    -1,   219,   218,   389,
     211,   389,    -1,   219,   218,   389,   212,   389,    -1,   219,
     220,   389,   226,   389,    -1,   219,   220,   389,    91,   225,
     226,   389,    -1,   219,   220,   389,    91,   227,   226,   389,
      -1,   219,   220,   389,   211,   389,    -1,   219,   220,   389,
     212,   389,    -1,   217,   218,   389,    -1,   217,   220,   389,
      -1,   222,   218,   389,   230,   389,    -1,   222,   223,   224,
     218,   389,   230,   389,    -1,   221,   218,   389,    91,   389,
      -1,   229,   114,   546,   228,   389,   180,   389,    -1,   547,
      -1,   546,   103,   114,   547,    -1,   608,   137,   389,    -1,
     238,   148,   386,   178,   549,    -1,   550,    -1,   549,   550,
      -1,   239,   551,   384,    -1,   239,   551,   151,   114,   608,
     181,   384,    -1,   239,   551,   151,   114,   608,   103,   114,
     608,   181,   384,    -1,   239,   551,   151,   114,   608,   103,
     114,   608,   103,   114,   608,   181,   384,    -1,   472,    -1,
     551,   203,   472,    -1,   240,   114,   407,    42,   148,   389,
     178,    -1,    42,   148,   389,   178,    -1,   556,   554,    -1,
      -1,   555,    -1,   574,    -1,   555,   574,    -1,   557,    -1,
     556,   256,   557,    -1,   558,    -1,   557,   252,   558,    -1,
     559,    -1,   558,   254,   142,   559,    -1,   560,    -1,   253,
     560,    -1,   564,   561,   562,    -1,    -1,   579,    -1,    -1,
     563,    -1,   276,   148,   386,   178,    -1,   568,   565,    -1,
     151,   553,   181,    -1,   566,    -1,    -1,   601,    -1,   459,
     148,   567,   178,    -1,    -1,   553,    -1,   569,   570,    -1,
     478,    -1,   148,   386,   178,    -1,    -1,   571,    -1,   242,
     572,    -1,   241,   573,    -1,   264,    -1,    -1,    75,    -1,
      -1,   280,    -1,   575,    -1,   576,    -1,   577,    -1,   603,
      -1,   600,    -1,   164,    -1,   278,   444,   578,    -1,   247,
     602,   578,    -1,   280,    -1,   270,    -1,   263,    -1,   240,
     580,    -1,   579,   240,   580,    -1,   581,    -1,   582,    -1,
     583,    -1,   598,    -1,   584,    -1,   592,    -1,   585,    -1,
     599,    -1,    96,   268,    -1,    96,   257,    -1,   260,    -1,
     275,    -1,   245,   268,    -1,   245,   257,    -1,    54,   608,
      24,    -1,   271,    -1,    51,   271,    -1,   273,   586,    -1,
     273,   151,   586,   587,   181,    -1,    51,   273,    -1,   589,
      -1,   109,    -1,    -1,   588,    -1,   589,    -1,   588,   103,
     589,    -1,    93,    24,   590,   591,    -1,    -1,   265,    24,
      -1,    -1,   602,   259,    -1,   272,   280,   593,   595,    -1,
     272,   280,   109,   595,    -1,    51,   272,   280,    -1,    93,
      24,    -1,   151,   594,   181,    -1,    24,    -1,   594,   103,
      24,    -1,    -1,   596,    -1,   597,    -1,   596,   597,    -1,
     194,   593,    -1,   131,   593,    -1,   258,    24,    -1,   277,
      -1,    51,   277,    -1,    93,   210,    -1,    93,   248,    -1,
     249,   244,    -1,   261,   602,   274,    -1,   250,   444,    -1,
      93,   124,   444,    -1,    93,    49,   444,    -1,   251,   444,
     192,   444,    -1,   266,   604,    -1,   246,   604,    -1,   269,
      -1,   262,    -1,   279,   244,   446,    -1,    24,    -1,    15,
      -1,   608,    -1,   609,    -1,    94,    -1,    34,    -1,    40,
      -1,    41,    -1,   147,    -1,    45,    -1,   218,    -1,    57,
      -1,    59,    -1,    60,    -1,    68,    -1,    71,    -1,    70,
      -1,   204,    -1,   237,    -1,    22,    -1,   208,    -1,   122,
      -1,    33,    -1,   255,    -1,    32,    -1,   215,    -1,   214,
      -1,   141,    -1,    39,    -1,   253,    -1,   254,    -1,   268,
      -1,   257,    -1,   245,    -1,   279,    -1,   271,    -1,   273,
      -1,   272,    -1,   277,    -1,   249,    -1,   244,    -1,    75,
      -1,   210,    -1,   248,    -1,    49,    -1,   216,    -1,   229,
      -1,   296,    -1,   223,    -1,   196,    -1,   201,    -1,   200,
      -1,   199,    -1,   198,    -1,   197,    -1,    93,    -1,   107,
      -1,   108,    -1,   180,    -1,    43,    -1,    31,    -1,    64,
      -1,    69,    -1,    56,    -1,    50,    -1,    53,    -1,    74,
      -1,    37,    -1,   142,    -1,    48,    -1,   205,    -1,   165,
      -1,   166,    -1,   163,    -1,    67,    -1,    92,    -1,   112,
      -1,   123,    -1,   124,    -1,   102,    -1,    65,    -1,   130,
      -1,   182,    -1,    96,    -1,    91,    -1,   191,    -1,   121,
      -1,   162,    -1,    89,    -1,    47,    -1,   224,    -1,    97,
      -1,   192,    -1,   113,    -1,   154,    -1,   194,    -1,   145,
      -1,   131,    -1,    73,    -1,    98,    -1,   193,    -1,   146,
      -1,   176,    -1,   189,    -1,   155,    -1,   132,    -1,   126,
      -1,   161,    -1,   143,    -1,   160,    -1,    28,    -1,    35,
      -1,    55,    -1,   109,    -1,    36,    -1,    54,    -1,   209,
      -1,    46,    -1,    58,    -1,    29,    -1,    44,    -1,   267,
      -1,   243,    -1,   276,    -1,   278,    -1,   247,    -1,   261,
      -1,   274,    -1,   266,    -1,   246,    -1,   260,    -1,   275,
      -1,   265,    -1,   259,    -1,   258,    -1,   242,    -1,   241,
      -1,   264,    -1,   250,    -1,   251,    -1,   280,    -1,   270,
      -1,   269,    -1,   262,    -1,   222,    -1,   228,    -1,   225,
      -1,   219,    -1,   212,    -1,   211,    -1,   213,    -1,   230,
      -1,   220,    -1,   221,    -1,   227,    -1,   217,    -1,   226,
      -1,    63,    -1,    61,    -1,    72,    -1,    38,    -1,    52,
      -1,   164,    -1,   195,    -1,   236,    -1,   231,    -1,   234,
      -1,   235,    -1,   232,    -1,   233,    -1,   238,    -1,   239,
      -1,    42,    -1,   240,    -1,    62,    -1,   289,    -1,   287,
      -1,   288,    -1,   293,    -1,   294,    -1,   295,    -1,   290,
      -1,   291,    -1,   292,    -1,    76,    -1,    77,    -1,    78,
      -1,    79,    -1,    80,    -1,    81,    -1,    82,    -1,    83,
      -1,    84,    -1,    85,    -1,    86,    -1,   281,    -1,   282,
      -1,   283,    -1,   284,    -1,   285,    -1,   286,    -1,   297,
      -1,   298,    -1,   299,    -1,   300,    -1,   301,    -1,   302,
      -1,   303,    -1,    87,    -1,   101,    -1,   110,    -1,   167,
      -1,   174,    -1,   183,    -1,   133,    -1,    88,    -1,   111,
      -1,   134,    -1,   175,    -1
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
     358,   360,   362,   365,   368,   371,   375,   381,   386,   393,
     395,   398,   400,   402,   404,   406,   408,   410,   413,   416,
     419,   422,   424,   427,   430,   433,   437,   442,   448,   455,
     460,   466,   473,   481,   483,   486,   490,   494,   503,   513,
     515,   519,   521,   524,   527,   531,   543,   558,   572,   595,
     599,   603,   606,   610,   615,   621,   624,   629,   633,   634,
     638,   641,   643,   647,   653,   657,   663,   666,   669,   672,
     676,   680,   682,   685,   687,   689,   694,   699,   705,   711,
     719,   725,   727,   731,   734,   738,   742,   746,   748,   750,
     753,   755,   759,   761,   765,   767,   769,   771,   773,   775,
     777,   779,   781,   783,   785,   787,   789,   791,   793,   795,
     797,   799,   801,   804,   807,   810,   813,   815,   817,   820,
     825,   829,   835,   840,   844,   846,   848,   850,   852,   854,
     856,   858,   860,   862,   865,   869,   871,   876,   880,   886,
     891,   898,   903,   910,   916,   924,   929,   935,   941,   948,
     952,   956,   960,   962,   967,   969,   974,   978,   983,   988,
     994,   999,  1005,  1007,  1010,  1014,  1016,  1019,  1021,  1028,
    1032,  1036,  1038,  1041,  1045,  1047,  1051,  1054,  1058,  1061,
    1065,  1070,  1072,  1076,  1078,  1081,  1083,  1085,  1087,  1090,
    1093,  1096,  1100,  1102,  1104,  1107,  1110,  1113,  1119,  1125,
    1127,  1132,  1136,  1141,  1150,  1152,  1155,  1159,  1162,  1166,
    1175,  1186,  1188,  1191,  1196,  1204,  1213,  1215,  1219,  1221,
    1225,  1227,  1231,  1235,  1239,  1243,  1244,  1249,  1253,  1257,
    1261,  1263,  1269,  1270,  1272,  1274,  1278,  1280,  1284,  1288,
    1290,  1294,  1298,  1302,  1306,  1308,  1312,  1316,  1318,  1322,
    1326,  1328,  1333,  1335,  1340,  1342,  1347,  1349,  1354,  1356,
    1359,  1361,  1363,  1366,  1369,  1371,  1373,  1375,  1377,  1379,
    1381,  1383,  1385,  1387,  1389,  1391,  1393,  1398,  1404,  1410,
    1417,  1421,  1426,  1428,  1431,  1435,  1438,  1440,  1443,  1446,
    1448,  1450,  1452,  1456,  1460,  1462,  1464,  1466,  1469,  1471,
    1474,  1477,  1479,  1482,  1485,  1488,  1491,  1494,  1497,  1500,
    1502,  1505,  1508,  1510,  1513,  1516,  1519,  1522,  1525,  1527,
    1529,  1531,  1533,  1535,  1537,  1539,  1541,  1544,  1548,  1553,
    1555,  1558,  1562,  1564,  1566,  1568,  1570,  1572,  1574,  1576,
    1578,  1580,  1582,  1584,  1586,  1588,  1590,  1593,  1596,  1600,
    1602,  1607,  1612,  1616,  1621,  1623,  1627,  1629,  1631,  1633,
    1635,  1637,  1642,  1648,  1657,  1667,  1677,  1688,  1690,  1693,
    1695,  1698,  1705,  1706,  1708,  1712,  1716,  1717,  1719,  1721,
    1723,  1726,  1729,  1730,  1732,  1734,  1736,  1739,  1742,  1744,
    1746,  1748,  1750,  1752,  1754,  1756,  1758,  1760,  1762,  1764,
    1766,  1770,  1773,  1777,  1781,  1784,  1786,  1788,  1790,  1792,
    1794,  1796,  1801,  1804,  1808,  1815,  1823,  1826,  1830,  1837,
    1845,  1850,  1855,  1858,  1862,  1869,  1877,  1879,  1882,  1885,
    1887,  1890,  1894,  1896,  1898,  1900,  1902,  1904,  1908,  1910,
    1912,  1914,  1918,  1920,  1922,  1924,  1926,  1928,  1930,  1932,
    1934,  1936,  1938,  1942,  1946,  1951,  1956,  1960,  1964,  1968,
    1973,  1978,  1982,  1987,  1994,  1999,  2006,  2011,  2015,  2020,
    2027,  2034,  2039,  2046,  2053,  2058,  2060,  2063,  2065,  2067,
    2069,  2073,  2077,  2079,  2081,  2086,  2092,  2099,  2103,  2107,
    2111,  2115,  2121,  2129,  2137,  2143,  2149,  2155,  2163,  2171,
    2177,  2183,  2187,  2191,  2197,  2205,  2211,  2219,  2221,  2226,
    2230,  2236,  2238,  2241,  2245,  2253,  2264,  2278,  2280,  2284,
    2292,  2297,  2300,  2301,  2303,  2305,  2308,  2310,  2314,  2316,
    2320,  2322,  2327,  2329,  2332,  2336,  2337,  2339,  2340,  2342,
    2347,  2350,  2354,  2356,  2357,  2359,  2364,  2365,  2367,  2370,
    2372,  2376,  2377,  2379,  2382,  2385,  2387,  2388,  2390,  2391,
    2393,  2395,  2397,  2399,  2401,  2403,  2405,  2409,  2413,  2415,
    2417,  2419,  2422,  2426,  2428,  2430,  2432,  2434,  2436,  2438,
    2440,  2442,  2445,  2448,  2450,  2452,  2455,  2458,  2462,  2464,
    2467,  2470,  2476,  2479,  2481,  2483,  2484,  2486,  2488,  2492,
    2497,  2498,  2501,  2502,  2505,  2510,  2515,  2519,  2522,  2526,
    2528,  2532,  2533,  2535,  2537,  2540,  2543,  2546,  2549,  2551,
    2554,  2557,  2560,  2563,  2567,  2570,  2574,  2578,  2583,  2586,
    2589,  2591,  2593,  2597,  2599,  2601,  2603,  2605,  2607,  2609,
    2611,  2613,  2615,  2617,  2619,  2621,  2623,  2625,  2627,  2629,
    2631,  2633,  2635,  2637,  2639,  2641,  2643,  2645,  2647,  2649,
    2651,  2653,  2655,  2657,  2659,  2661,  2663,  2665,  2667,  2669,
    2671,  2673,  2675,  2677,  2679,  2681,  2683,  2685,  2687,  2689,
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
    3031,  3033
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1018,  1018,  1019,  1052,  1061,  1066,  1073,  1078,  1089,
    1094,  1102,  1107,  1112,  1117,  1122,  1130,  1138,  1146,  1158,
    1162,  1167,  1172,  1181,  1190,  1196,  1202,  1215,  1221,  1227,
    1239,  1240,  1241,  1242,  1247,  1248,  1249,  1250,  1251,  1252,
    1253,  1254,  1255,  1261,  1266,  1275,  1281,  1290,  1299,  1300,
    1301,  1302,  1303,  1304,  1305,  1306,  1307,  1308,  1313,  1314,
    1315,  1316,  1317,  1318,  1319,  1322,  1327,  1328,  1333,  1341,
    1347,  1357,  1363,  1373,  1383,  1391,  1397,  1408,  1413,  1423,
    1429,  1435,  1441,  1458,  1466,  1474,  1478,  1487,  1496,  1509,
    1515,  1526,  1530,  1538,  1543,  1548,  1555,  1568,  1575,  1581,
    1588,  1594,  1598,  1605,  1616,  1620,  1628,  1634,  1640,  1649,
    1655,  1664,  1668,  1674,  1678,  1682,  1686,  1692,  1698,  1704,
    1710,  1716,  1720,  1726,  1732,  1739,  1747,  1755,  1763,  1771,
    1783,  1797,  1811,  1828,  1832,  1841,  1845,  1852,  1860,  1878,
    1884,  1892,  1897,  1904,  1911,  1921,  1931,  1941,  1951,  1968,
    1974,  1985,  1989,  1993,  1997,  2004,  2011,  2030,  2040,  2046,
    2052,  2062,  2069,  2080,  2087,  2094,  2106,  2110,  2117,  2122,
    2137,  2154,  2158,  2162,  2166,  2174,  2185,  2200,  2211,  2226,
    2237,  2253,  2259,  2271,  2275,  2286,  2293,  2301,  2316,  2320,
    2334,  2338,  2347,  2351,  2379,  2380,  2381,  2382,  2383,  2384,
    2387,  2388,  2389,  2390,  2391,  2393,  2394,  2397,  2398,  2399,
    2400,  2401,  2406,  2421,  2428,  2432,  2439,  2443,  2447,  2454,
    2462,  2473,  2483,  2496,  2505,  2506,  2507,  2511,  2512,  2513,
    2514,  2515,  2518,  2524,  2534,  2542,  2548,  2560,  2564,  2568,
    2572,  2576,  2580,  2584,  2589,  2595,  2604,  2614,  2624,  2640,
    2649,  2659,  2667,  2673,  2682,  2688,  2700,  2708,  2718,  2726,
    2738,  2744,  2755,  2757,  2761,  2769,  2773,  2778,  2782,  2786,
    2790,  2798,  2812,  2820,  2827,  2833,  2844,  2848,  2857,  2865,
    2871,  2881,  2887,  2897,  2901,  2911,  2917,  2923,  2929,  2938,
    2947,  2956,  2969,  2973,  2981,  2987,  2997,  3005,  3014,  3027,
    3034,  3046,  3050,  3062,  3069,  3075,  3084,  3091,  3097,  3109,
    3116,  3129,  3135,  3147,  3153,  3165,  3174,  3178,  3187,  3191,
    3199,  3203,  3213,  3220,  3229,  3239,  3238,  3252,  3261,  3270,
    3283,  3287,  3300,  3303,  3310,  3314,  3323,  3327,  3331,  3340,
    3344,  3350,  3356,  3362,  3373,  3377,  3381,  3389,  3393,  3399,
    3409,  3413,  3423,  3427,  3437,  3441,  3451,  3455,  3465,  3469,
    3477,  3481,  3485,  3489,  3499,  3503,  3507,  3515,  3519,  3523,
    3527,  3531,  3535,  3543,  3547,  3551,  3559,  3563,  3567,  3571,
    3582,  3588,  3598,  3604,  3614,  3618,  3656,  3660,  3666,  3672,
    3683,  3691,  3702,  3708,  3718,  3722,  3730,  3736,  3744,  3750,
    3762,  3768,  3778,  3782,  3786,  3790,  3794,  3800,  3806,  3829,
    3833,  3841,  3845,  3856,  3860,  3864,  3870,  3874,  3888,  3892,
    3900,  3904,  3914,  3918,  3922,  3931,  3935,  3941,  3945,  3953,
    3959,  3969,  3977,  3981,  3985,  3989,  3993,  3997,  4001,  4005,
    4009,  4017,  4021,  4029,  4036,  4043,  4054,  4062,  4066,  4074,
    4082,  4090,  4144,  4148,  4161,  4167,  4177,  4181,  4189,  4193,
    4197,  4205,  4215,  4225,  4235,  4245,  4255,  4270,  4276,  4287,
    4293,  4304,  4315,  4317,  4321,  4326,  4336,  4339,  4346,  4354,
    4360,  4370,  4383,  4386,  4393,  4399,  4405,  4412,  4423,  4427,
    4437,  4441,  4451,  4455,  4459,  4464,  4473,  4479,  4485,  4491,
    4501,  4505,  4517,  4521,  4533,  4545,  4549,  4553,  4557,  4561,
    4565,  4573,  4581,  4585,  4589,  4593,  4610,  4614,  4618,  4622,
    4630,  4638,  4646,  4650,  4654,  4658,  4666,  4672,  4682,  4690,
    4694,  4698,  4733,  4739,  4745,  4755,  4759,  4763,  4767,  4771,
    4778,  4784,  4794,  4802,  4806,  4810,  4814,  4818,  4822,  4826,
    4830,  4834,  4842,  4850,  4854,  4858,  4868,  4876,  4884,  4888,
    4892,  4900,  4904,  4910,  4916,  4920,  4930,  4938,  4942,  4948,
    4957,  4966,  4972,  4978,  4988,  5005,  5012,  5027,  5063,  5067,
    5076,  5085,  5095,  5099,  5108,  5117,  5121,  5132,  5149,  5155,
    5161,  5171,  5175,  5181,  5187,  5191,  5197,  5201,  5207,  5213,
    5220,  5230,  5235,  5243,  5249,  5259,  5281,  5290,  5296,  5309,
    5323,  5330,  5336,  5346,  5351,  5356,  5366,  5379,  5385,  5402,
    5406,  5421,  5430,  5433,  5440,  5445,  5453,  5457,  5464,  5468,
    5475,  5479,  5486,  5490,  5499,  5512,  5515,  5523,  5526,  5534,
    5542,  5550,  5554,  5562,  5565,  5573,  5585,  5588,  5596,  5608,
    5614,  5624,  5627,  5635,  5639,  5643,  5651,  5654,  5662,  5665,
    5673,  5677,  5681,  5685,  5689,  5697,  5705,  5717,  5729,  5733,
    5737,  5745,  5751,  5761,  5765,  5769,  5773,  5777,  5781,  5785,
    5789,  5797,  5801,  5805,  5809,  5817,  5823,  5833,  5843,  5847,
    5855,  5865,  5876,  5883,  5887,  5895,  5898,  5905,  5910,  5919,
    5929,  5932,  5940,  5943,  5951,  5960,  5967,  5977,  5981,  5988,
    5994,  6004,  6007,  6014,  6019,  6031,  6039,  6051,  6059,  6063,
    6071,  6075,  6079,  6087,  6095,  6099,  6103,  6107,  6115,  6123,
    6135,  6139,  6147,  6160,  6164,  6165,  6178,  6179,  6180,  6181,
    6182,  6183,  6184,  6185,  6186,  6187,  6188,  6189,  6190,  6191,
    6192,  6193,  6197,  6198,  6199,  6200,  6201,  6202,  6203,  6204,
    6205,  6206,  6207,  6208,  6209,  6210,  6211,  6212,  6213,  6214,
    6215,  6216,  6217,  6218,  6219,  6220,  6221,  6222,  6223,  6224,
    6225,  6226,  6227,  6228,  6229,  6230,  6231,  6232,  6233,  6234,
    6235,  6236,  6237,  6238,  6239,  6240,  6241,  6242,  6243,  6244,
    6245,  6246,  6247,  6248,  6249,  6250,  6251,  6252,  6253,  6254,
    6255,  6256,  6257,  6258,  6259,  6260,  6261,  6262,  6263,  6264,
    6265,  6266,  6267,  6268,  6269,  6270,  6271,  6272,  6273,  6274,
    6275,  6276,  6277,  6278,  6279,  6280,  6281,  6282,  6283,  6284,
    6285,  6286,  6287,  6288,  6289,  6290,  6291,  6292,  6293,  6294,
    6295,  6296,  6297,  6298,  6299,  6300,  6301,  6302,  6303,  6304,
    6305,  6306,  6307,  6308,  6309,  6310,  6311,  6312,  6313,  6314,
    6315,  6316,  6317,  6318,  6319,  6320,  6321,  6322,  6323,  6324,
    6325,  6326,  6327,  6328,  6329,  6330,  6331,  6332,  6333,  6334,
    6335,  6336,  6337,  6338,  6339,  6340,  6341,  6342,  6343,  6344,
    6345,  6346,  6347,  6348,  6349,  6350,  6351,  6352,  6353,  6354,
    6355,  6356,  6357,  6358,  6359,  6360,  6361,  6362,  6363,  6364,
    6365,  6366,  6367,  6368,  6369,  6370,  6371,  6372,  6373,  6374,
    6375,  6376,  6377,  6378,  6379,  6380,  6381,  6382,  6383,  6384,
    6385,  6386,  6387,  6388,  6389,  6390,  6391,  6392,  6393,  6394,
    6395,  6396
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
     315,   316,   317
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 11838;
  const int xquery_parser::yynnts_ = 292;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 554;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 318;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 572;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1054 of lalr1.cc  */
#line 15653 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6400 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"


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

