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
#line 67 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"


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
#include "compiler/parser/xquery_driver.h"

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
#line 84 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 316 of lalr1.cc  */
#line 851 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 316 of lalr1.cc  */
#line 967 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"

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



/* Line 316 of lalr1.cc  */
#line 155 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"

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
#line 221 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
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

/* Line 479 of lalr1.cc  */
#line 847 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 479 of lalr1.cc  */
#line 328 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 116: /* "\"'DOUBLE'\"" */

/* Line 479 of lalr1.cc  */
#line 846 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 479 of lalr1.cc  */
#line 337 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 141: /* "\"'INTEGER'\"" */

/* Line 479 of lalr1.cc  */
#line 845 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 479 of lalr1.cc  */
#line 346 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "VersionDecl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 355 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "MainModule" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 364 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "LibraryModule" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 373 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "ModuleDecl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 382 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "Prolog" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 391 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "SIND_DeclList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 400 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "VFO_DeclList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 409 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "SIND_Decl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 418 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "VFO_Decl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 427 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "DecimalFormatDecl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 436 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "DecimalFormatParamList" */

/* Line 479 of lalr1.cc  */
#line 872 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 479 of lalr1.cc  */
#line 445 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "DecimalFormatParam" */

/* Line 479 of lalr1.cc  */
#line 872 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 479 of lalr1.cc  */
#line 454 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "Setter" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 463 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "Import" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 472 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "NamespaceDecl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 481 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "BoundarySpaceDecl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 490 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "DefaultNamespaceDecl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 499 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "OptionDecl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 508 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "FTOptionDecl" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 517 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "OrderingModeDecl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 526 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "EmptyOrderDecl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 535 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "CopyNamespacesDecl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 544 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "DefaultCollationDecl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 553 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "BaseURIDecl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 562 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "SchemaImport" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 571 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "URILiteralList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 580 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "SchemaPrefix" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 589 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "ModuleImport" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 598 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "CtxItemDecl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 607 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "CtxItemDecl2" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 616 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "CtxItemDecl3" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 625 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "CtxItemDecl4" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 634 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "VarNameAndType" */

/* Line 479 of lalr1.cc  */
#line 872 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 479 of lalr1.cc  */
#line 643 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "VarDecl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 652 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "DeclPropertyList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 661 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "DeclProperty" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 670 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "CollectionDecl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 679 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "NodeModifier" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 688 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "IndexDecl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 697 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "IndexKeyList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 706 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "IndexKeySpec" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 715 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "IntegrityConstraintDecl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 724 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "ConstructionDecl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 733 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "FunctionSig" */

/* Line 479 of lalr1.cc  */
#line 872 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 479 of lalr1.cc  */
#line 742 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "BlockExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 751 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "Block" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 760 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "BlockDecls" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 769 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "BlockVarDeclList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 778 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "BlockVarDecl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 787 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "AssignExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 796 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "ExitExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 805 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "WhileExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 814 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "FlowCtlStatement" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 823 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FunctionDecl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 832 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDecl2" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 841 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDeclSimple" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 850 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDeclSequential" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 859 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FunctionDeclUpdating" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 868 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "ParamList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 877 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "Param" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 886 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "EnclosedExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 895 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "BracedExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 904 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "QueryBody" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "Expr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 922 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "ApplyExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 931 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "ConcatExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 940 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "ExprSingle" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 949 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "FLWORExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 958 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "ReturnExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 967 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "FLWORWinCond" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 976 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "WindowClause" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 985 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "CountClause" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 994 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ForLetWinClause" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1003 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "FLWORClauseList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1012 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "ForClause" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1021 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "VarInDeclList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1030 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "VarInDecl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1039 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "PositionalVar" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1048 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "FTScoreVar" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1057 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "LetClause" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1066 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "VarGetsDeclList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1075 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "EvalVarDeclList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1084 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "VarGetsDecl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1093 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "WindowVarDecl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1102 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "WindowVars" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1111 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "WindowVars3" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1120 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "WindowVars2" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1129 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "EvalVarDecl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1138 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "WhereClause" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1147 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "GroupByClause" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1156 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "GroupSpecList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1165 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "GroupSpec" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1174 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "GroupCollationSpec" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1183 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "OrderByClause" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1192 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "OrderSpecList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1201 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "OrderSpec" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1210 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "OrderModifier" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1219 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "OrderDirSpec" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1228 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "OrderEmptySpec" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1237 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "OrderCollationSpec" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1246 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "QuantifiedExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1255 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "QVarInDeclList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1264 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "QVarInDecl" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1273 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "SwitchExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1282 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "SwitchCaseClauseList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1291 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "SwitchCaseClause" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1300 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "SwitchCaseOperandList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1309 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "TypeswitchExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1318 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "CaseClauseList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1327 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "CaseClause" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1336 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "IfExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1345 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "OrExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1354 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "AndExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1363 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "ComparisonExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1372 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "FTContainsExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1381 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "opt_FTIgnoreOption" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1390 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "RangeExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1399 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "AdditiveExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1408 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "MultiplicativeExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1417 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "UnionExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1426 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "IntersectExceptExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1435 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "InstanceofExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1444 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "TreatExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1453 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "CastableExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1462 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "CastExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1471 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "UnaryExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1480 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "SignList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1489 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "ValueExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1498 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "ValueComp" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1507 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "NodeComp" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1516 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "ValidateExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1525 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "ExtensionExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1534 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "Pragma_list" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1543 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "Pragma" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1552 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "PathExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1561 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "RelativePathExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1570 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "StepExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1579 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "AxisStep" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1588 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "ForwardStep" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1597 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "ForwardAxis" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1606 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "AbbrevForwardStep" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1615 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "ReverseStep" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1624 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "ReverseAxis" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1633 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "NodeTest" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1642 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "NameTest" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1651 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "Wildcard" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1660 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "FilterExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1669 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "PredicateList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1678 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "Predicate" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1687 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "PrimaryExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1696 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "Literal" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1705 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "NumericLiteral" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1714 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "VarRef" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1723 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "ParenthesizedExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1732 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "ContextItemExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1741 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "OrderedExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1750 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "UnorderedExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1759 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "FunctionCall" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1768 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "ArgList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1777 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "Constructor" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1786 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "DirectConstructor" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1795 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "DirElemConstructor" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1804 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "DirElemContentList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1813 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "DirAttributeList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1822 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "DirAttr" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1831 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "DirAttributeValue" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1840 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "opt_QuoteAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1849 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "QuoteAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1858 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "opt_AposAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1867 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "AposAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1876 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "QuoteAttrValueContent" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1885 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "AposAttrValueContent" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1894 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "DirElemContent" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1903 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "CommonContent" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1912 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "DirCommentConstructor" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1921 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "DirPIConstructor" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1930 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "CDataSection" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1939 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "ComputedConstructor" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1948 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "CompDocConstructor" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1957 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "CompElemConstructor" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1966 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "CompAttrConstructor" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1975 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "CompTextConstructor" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1984 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "CompCommentConstructor" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1993 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "CompPIConstructor" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2002 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "SingleType" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2011 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "TypeDeclaration" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2020 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "SequenceType" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2029 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "OccurrenceIndicator" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2038 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "ItemType" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2047 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "TypeList" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2056 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "AtomicType" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2065 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "KindTest" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2074 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "AnyKindTest" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2083 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "DocumentTest" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2092 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "TextTest" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2101 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "CommentTest" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2110 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "PITest" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2119 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "AttributeTest" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2128 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "SchemaAttributeTest" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2137 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "ElementTest" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2146 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "SchemaElementTest" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2155 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "TypeName" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2164 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "TypeName_WITH_HOOK" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2173 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "StringLiteral" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2182 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "AnyFunctionTest" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2191 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "TypedFunctionTest" */

/* Line 479 of lalr1.cc  */
#line 863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2200 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "InsertExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2209 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "DeleteExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2218 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "ReplaceExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2227 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "RenameExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2236 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "TransformExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2245 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "VarNameList" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2254 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "VarNameDecl" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2263 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "TryExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2272 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "CatchListExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2281 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "CatchExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2290 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "NameTestList" */

/* Line 479 of lalr1.cc  */
#line 872 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 479 of lalr1.cc  */
#line 2299 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "EvalExpr" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2308 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "FTSelection" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2317 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "FTOr" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2326 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "FTAnd" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2335 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "FTMildNot" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2344 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "FTUnaryNot" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2353 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "FTPrimaryWithOptions" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2362 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "opt_FTMatchOptions" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2371 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "FTWeight" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2380 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "FTPrimary" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2389 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "opt_FTTimes" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2398 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "FTExtensionSelection" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2407 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "FTWords" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2416 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "FTWordsValue" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2425 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "FTAnyallOption" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2434 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTPosFilter" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2443 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTOrder" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2452 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTWindow" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2461 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTDistance" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2470 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTUnit" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2479 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTMatchOptions" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2488 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTMatchOption" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2497 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTCaseOption" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2506 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTDiacriticsOption" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2515 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTExtensionOption" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2524 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTStemOption" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2533 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTThesaurusOption" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2542 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTThesaurusID" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2551 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTStopWordOption" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2560 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTStopWords" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2569 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTStopWordsInclExcl" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2578 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTLanguageOption" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2587 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTWildCardOption" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2596 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTContent" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2605 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTTimes" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2614 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTRange" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2623 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTScope" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2632 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTBigUnit" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2641 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTIgnoreOption" */

/* Line 479 of lalr1.cc  */
#line 866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2650 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "QNAME" */

/* Line 479 of lalr1.cc  */
#line 869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2659 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
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
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename.getStore()->str());
}

/* Line 552 of lalr1.cc  */
#line 2744 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"

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
#line 1026 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 4:

/* Line 677 of lalr1.cc  */
#line 1030 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.node) = NULL; }
    break;

  case 5:

/* Line 677 of lalr1.cc  */
#line 1031 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.node) = NULL; }
    break;

  case 6:

/* Line 677 of lalr1.cc  */
#line 1032 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.node) = NULL; }
    break;

  case 7:

/* Line 677 of lalr1.cc  */
#line 1033 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.node) = NULL; }
    break;

  case 8:

/* Line 677 of lalr1.cc  */
#line 1038 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          // Catch unrecognized tokens and report them
          (yyval.node) = NULL;
          if ((yysemantic_stack_[(1) - (1)].err) != NULL) {
            error((yyloc), (yysemantic_stack_[(1) - (1)].err)->msg);
          } else
            error((yyloc), std::string("syntax error, unexpected character"));
          YYERROR;
        }
    break;

  case 9:

/* Line 677 of lalr1.cc  */
#line 1053 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 10:

/* Line 677 of lalr1.cc  */
#line 1058 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            MainModule *mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
            mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 11:

/* Line 677 of lalr1.cc  */
#line 1065 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 12:

/* Line 677 of lalr1.cc  */
#line 1070 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            LibraryModule *lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
            lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 13:

/* Line 677 of lalr1.cc  */
#line 1081 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            std::string encoding = "utf-8";
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), encoding );
        }
    break;

  case 14:

/* Line 677 of lalr1.cc  */
#line 1086 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
        }
    break;

  case 15:

/* Line 677 of lalr1.cc  */
#line 1094 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new MainModule(
                LOC((yyloc)),
                static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
                static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node))
            );
        }
    break;

  case 16:

/* Line 677 of lalr1.cc  */
#line 1102 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
        }
    break;

  case 17:

/* Line 677 of lalr1.cc  */
#line 1110 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LibraryModule(
                LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 18:

/* Line 677 of lalr1.cc  */
#line 1116 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LibraryModule(
                LOC((yyloc)),
                static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
                static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 19:

/* Line 677 of lalr1.cc  */
#line 1128 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
            dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
        }
    break;

  case 20:

/* Line 677 of lalr1.cc  */
#line 1137 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog( LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)), NULL );
        }
    break;

  case 21:

/* Line 677 of lalr1.cc  */
#line 1141 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog( LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)) );
        }
    break;

  case 22:

/* Line 677 of lalr1.cc  */
#line 1145 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog(
                LOC((yyloc)),
                static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
                static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 23:

/* Line 677 of lalr1.cc  */
#line 1157 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
            sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = sdl;
        }
    break;

  case 24:

/* Line 677 of lalr1.cc  */
#line 1163 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( SIND_DeclList *sdl = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                sdl->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 25:

/* Line 677 of lalr1.cc  */
#line 1173 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
            vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = vdl;
        }
    break;

  case 26:

/* Line 677 of lalr1.cc  */
#line 1179 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( VFO_DeclList *vdl = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vdl->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 40:

/* Line 677 of lalr1.cc  */
#line 1211 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
         (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
         delete (yysemantic_stack_[(4) - (4)].vstrpair);
       }
    break;

  case 41:

/* Line 677 of lalr1.cc  */
#line 1216 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
         (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
         delete (yysemantic_stack_[(4) - (4)].vstrpair);
       }
    break;

  case 42:

/* Line 677 of lalr1.cc  */
#line 1225 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.vstrpair) = new vector<string_pair_t>();
          (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
          delete (yysemantic_stack_[(1) - (1)].strpair);
        }
    break;

  case 43:

/* Line 677 of lalr1.cc  */
#line 1231 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
          delete (yysemantic_stack_[(2) - (2)].strpair);
          (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
        }
    break;

  case 44:

/* Line 677 of lalr1.cc  */
#line 1240 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
            (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval() );
            delete sl;
        }
    break;

  case 45:

/* Line 677 of lalr1.cc  */
#line 1248 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 46:

/* Line 677 of lalr1.cc  */
#line 1249 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 47:

/* Line 677 of lalr1.cc  */
#line 1250 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 48:

/* Line 677 of lalr1.cc  */
#line 1251 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 49:

/* Line 677 of lalr1.cc  */
#line 1252 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 50:

/* Line 677 of lalr1.cc  */
#line 1253 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 51:

/* Line 677 of lalr1.cc  */
#line 1254 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 52:

/* Line 677 of lalr1.cc  */
#line 1255 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 53:

/* Line 677 of lalr1.cc  */
#line 1256 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 54:

/* Line 677 of lalr1.cc  */
#line 1257 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 65:

/* Line 677 of lalr1.cc  */
#line 1288 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
        }
    break;

  case 66:

/* Line 677 of lalr1.cc  */
#line 1297 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::preserve_space
            );
        }
    break;

  case 67:

/* Line 677 of lalr1.cc  */
#line 1303 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::strip_space
            );
        }
    break;

  case 68:

/* Line 677 of lalr1.cc  */
#line 1313 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_element_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 69:

/* Line 677 of lalr1.cc  */
#line 1319 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_function_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 70:

/* Line 677 of lalr1.cc  */
#line 1329 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OptionDecl(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval))
            );
        }
    break;

  case 71:

/* Line 677 of lalr1.cc  */
#line 1339 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 72:

/* Line 677 of lalr1.cc  */
#line 1347 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::ordered
            );
        }
    break;

  case 73:

/* Line 677 of lalr1.cc  */
#line 1353 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::unordered
            );
        }
    break;

  case 74:

/* Line 677 of lalr1.cc  */
#line 1364 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_greatest);
        }
    break;

  case 75:

/* Line 677 of lalr1.cc  */
#line 1369 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_least);
        }
    break;

  case 76:

/* Line 677 of lalr1.cc  */
#line 1379 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 77:

/* Line 677 of lalr1.cc  */
#line 1385 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 78:

/* Line 677 of lalr1.cc  */
#line 1391 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 79:

/* Line 677 of lalr1.cc  */
#line 1397 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 80:

/* Line 677 of lalr1.cc  */
#line 1414 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
        }
    break;

  case 81:

/* Line 677 of lalr1.cc  */
#line 1422 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 82:

/* Line 677 of lalr1.cc  */
#line 1430 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
        }
    break;

  case 83:

/* Line 677 of lalr1.cc  */
#line 1434 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                NULL
            );
        }
    break;

  case 84:

/* Line 677 of lalr1.cc  */
#line 1443 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                NULL,
                SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 85:

/* Line 677 of lalr1.cc  */
#line 1452 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 86:

/* Line 677 of lalr1.cc  */
#line 1465 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            URILiteralList *ull = new URILiteralList( LOC((yyloc)));
            ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.node) = ull;
        }
    break;

  case 87:

/* Line 677 of lalr1.cc  */
#line 1471 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
                ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 88:

/* Line 677 of lalr1.cc  */
#line 1482 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 89:

/* Line 677 of lalr1.cc  */
#line 1486 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
        }
    break;

  case 90:

/* Line 677 of lalr1.cc  */
#line 1494 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 91:

/* Line 677 of lalr1.cc  */
#line 1499 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 92:

/* Line 677 of lalr1.cc  */
#line 1504 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 93:

/* Line 677 of lalr1.cc  */
#line 1511 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 94:

/* Line 677 of lalr1.cc  */
#line 1524 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
        }
    break;

  case 95:

/* Line 677 of lalr1.cc  */
#line 1531 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
            d->type = (yysemantic_stack_[(3) - (2)].node);
            (yyval.node) = d;
        }
    break;

  case 96:

/* Line 677 of lalr1.cc  */
#line 1537 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 97:

/* Line 677 of lalr1.cc  */
#line 1544 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
            d->ext = false;
            (yyval.node) = d;
        }
    break;

  case 98:

/* Line 677 of lalr1.cc  */
#line 1550 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), NULL );
        }
    break;

  case 99:

/* Line 677 of lalr1.cc  */
#line 1554 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 100:

/* Line 677 of lalr1.cc  */
#line 1561 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 101:

/* Line 677 of lalr1.cc  */
#line 1572 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 102:

/* Line 677 of lalr1.cc  */
#line 1576 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 103:

/* Line 677 of lalr1.cc  */
#line 1584 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(5) - (5)].expr));
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 104:

/* Line 677 of lalr1.cc  */
#line 1590 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 105:

/* Line 677 of lalr1.cc  */
#line 1596 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 106:

/* Line 677 of lalr1.cc  */
#line 1605 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
            dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = dpl;
        }
    break;

  case 107:

/* Line 677 of lalr1.cc  */
#line 1611 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
        DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
        dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
        (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 108:

/* Line 677 of lalr1.cc  */
#line 1620 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 109:

/* Line 677 of lalr1.cc  */
#line 1624 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 110:

/* Line 677 of lalr1.cc  */
#line 1630 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 111:

/* Line 677 of lalr1.cc  */
#line 1634 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 112:

/* Line 677 of lalr1.cc  */
#line 1638 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 113:

/* Line 677 of lalr1.cc  */
#line 1642 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 114:

/* Line 677 of lalr1.cc  */
#line 1648 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 115:

/* Line 677 of lalr1.cc  */
#line 1654 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 116:

/* Line 677 of lalr1.cc  */
#line 1660 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_equality
            );
        }
    break;

  case 117:

/* Line 677 of lalr1.cc  */
#line 1666 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_range
            );
        }
    break;

  case 118:

/* Line 677 of lalr1.cc  */
#line 1672 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 119:

/* Line 677 of lalr1.cc  */
#line 1676 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 120:

/* Line 677 of lalr1.cc  */
#line 1682 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 121:

/* Line 677 of lalr1.cc  */
#line 1688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 122:

/* Line 677 of lalr1.cc  */
#line 1695 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL,
                              NULL);
    }
    break;

  case 123:

/* Line 677 of lalr1.cc  */
#line 1703 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 124:

/* Line 677 of lalr1.cc  */
#line 1711 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              NULL,
                              NULL,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 125:

/* Line 677 of lalr1.cc  */
#line 1719 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(6) - (6)].node)),
                              static_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)));
    }
    break;

  case 126:

/* Line 677 of lalr1.cc  */
#line 1727 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 127:

/* Line 677 of lalr1.cc  */
#line 1739 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 128:

/* Line 677 of lalr1.cc  */
#line 1753 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 129:

/* Line 677 of lalr1.cc  */
#line 1767 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 130:

/* Line 677 of lalr1.cc  */
#line 1784 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 131:

/* Line 677 of lalr1.cc  */
#line 1788 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 132:

/* Line 677 of lalr1.cc  */
#line 1797 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 133:

/* Line 677 of lalr1.cc  */
#line 1801 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 134:

/* Line 677 of lalr1.cc  */
#line 1808 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);
    }
    break;

  case 135:

/* Line 677 of lalr1.cc  */
#line 1816 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 136:

/* Line 677 of lalr1.cc  */
#line 1834 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 137:

/* Line 677 of lalr1.cc  */
#line 1840 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 138:

/* Line 677 of lalr1.cc  */
#line 1848 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 139:

/* Line 677 of lalr1.cc  */
#line 1853 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 140:

/* Line 677 of lalr1.cc  */
#line 1860 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 141:

/* Line 677 of lalr1.cc  */
#line 1867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 142:

/* Line 677 of lalr1.cc  */
#line 1878 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 143:

/* Line 677 of lalr1.cc  */
#line 1888 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 144:

/* Line 677 of lalr1.cc  */
#line 1898 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 145:

/* Line 677 of lalr1.cc  */
#line 1909 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 146:

/* Line 677 of lalr1.cc  */
#line 1924 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_preserve
            );
        }
    break;

  case 147:

/* Line 677 of lalr1.cc  */
#line 1930 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_strip
            );
        }
    break;

  case 148:

/* Line 677 of lalr1.cc  */
#line 1941 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL );
        }
    break;

  case 149:

/* Line 677 of lalr1.cc  */
#line 1945 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 150:

/* Line 677 of lalr1.cc  */
#line 1949 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)) );
        }
    break;

  case 151:

/* Line 677 of lalr1.cc  */
#line 1953 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig(
                dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 152:

/* Line 677 of lalr1.cc  */
#line 1962 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 153:

/* Line 677 of lalr1.cc  */
#line 1969 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 154:

/* Line 677 of lalr1.cc  */
#line 1988 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            std::auto_ptr<VFO_DeclList> vfo2( dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)) );
            if ( !(yysemantic_stack_[(3) - (1)].node) )
                vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back( *vfo2.get() );
            (yyval.node) = vfo;
        }
    break;

  case 155:

/* Line 677 of lalr1.cc  */
#line 1997 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 156:

/* Line 677 of lalr1.cc  */
#line 2004 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            vfo->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = vfo;
        }
    break;

  case 157:

/* Line 677 of lalr1.cc  */
#line 2010 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back((yysemantic_stack_[(2) - (2)].node));
            (yyval.node) = vfo;
        }
    break;

  case 158:

/* Line 677 of lalr1.cc  */
#line 2020 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(1) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 159:

/* Line 677 of lalr1.cc  */
#line 2027 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(3) - (3)].expr));
      vd->set_global(false);
      (yyval.node) = vd;
        }
    break;

  case 160:

/* Line 677 of lalr1.cc  */
#line 2038 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 161:

/* Line 677 of lalr1.cc  */
#line 2045 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExitExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 162:

/* Line 677 of lalr1.cc  */
#line 2052 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody *>((yysemantic_stack_[(5) - (5)].expr));
            if ( !bb ) {
                bb = new BlockBody( (yysemantic_stack_[(5) - (5)].expr)->get_location() );
                bb->add((yysemantic_stack_[(5) - (5)].expr));
            }
            (yyval.expr) = new WhileExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), bb );
        }
    break;

  case 163:

/* Line 677 of lalr1.cc  */
#line 2064 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::BREAK );
        }
    break;

  case 164:

/* Line 677 of lalr1.cc  */
#line 2068 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
        }
    break;

  case 165:

/* Line 677 of lalr1.cc  */
#line 2075 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            dynamic_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 166:

/* Line 677 of lalr1.cc  */
#line 2080 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 167:

/* Line 677 of lalr1.cc  */
#line 2095 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 168:

/* Line 677 of lalr1.cc  */
#line 2112 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 169:

/* Line 677 of lalr1.cc  */
#line 2116 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 170:

/* Line 677 of lalr1.cc  */
#line 2120 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 171:

/* Line 677 of lalr1.cc  */
#line 2124 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 172:

/* Line 677 of lalr1.cc  */
#line 2132 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 173:

/* Line 677 of lalr1.cc  */
#line 2142 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 174:

/* Line 677 of lalr1.cc  */
#line 2156 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 175:

/* Line 677 of lalr1.cc  */
#line 2166 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 176:

/* Line 677 of lalr1.cc  */
#line 2180 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 177:

/* Line 677 of lalr1.cc  */
#line 2190 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 178:

/* Line 677 of lalr1.cc  */
#line 2205 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            ParamList *pl = new ParamList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 179:

/* Line 677 of lalr1.cc  */
#line 2211 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
                pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 180:

/* Line 677 of lalr1.cc  */
#line 2223 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 181:

/* Line 677 of lalr1.cc  */
#line 2227 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 182:

/* Line 677 of lalr1.cc  */
#line 2238 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EnclosedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 183:

/* Line 677 of lalr1.cc  */
#line 2245 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 184:

/* Line 677 of lalr1.cc  */
#line 2253 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QueryBody( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 185:

/* Line 677 of lalr1.cc  */
#line 2268 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 186:

/* Line 677 of lalr1.cc  */
#line 2272 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            std::auto_ptr<BlockBody> blk( dynamic_cast<BlockBody*>((yysemantic_stack_[(2) - (2)].expr)) );
            BlockBody *blk2 = new BlockBody( LOC((yyloc)) );
            blk2->add( (yysemantic_stack_[(2) - (1)].expr) );

            for ( int i = 0; i < blk->size(); ++i )
                blk2->add( (*blk)[i] );

            (yyval.expr) = blk2;
        }
    break;

  case 187:

/* Line 677 of lalr1.cc  */
#line 2286 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new BlockBody( LOC((yyloc)) );
        }
    break;

  case 188:

/* Line 677 of lalr1.cc  */
#line 2290 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (1)].expr));
            bb->add( (yysemantic_stack_[(3) - (2)].expr) );
            (yyval.expr) = bb;
        }
    break;

  case 189:

/* Line 677 of lalr1.cc  */
#line 2299 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 190:

/* Line 677 of lalr1.cc  */
#line 2303 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 209:

/* Line 677 of lalr1.cc  */
#line 2344 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 210:

/* Line 677 of lalr1.cc  */
#line 2359 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 211:

/* Line 677 of lalr1.cc  */
#line 2366 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_sliding;
        }
    break;

  case 212:

/* Line 677 of lalr1.cc  */
#line 2370 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_tumbling;
        }
    break;

  case 213:

/* Line 677 of lalr1.cc  */
#line 2377 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_start;
        }
    break;

  case 214:

/* Line 677 of lalr1.cc  */
#line 2381 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_end;
        }
    break;

  case 215:

/* Line 677 of lalr1.cc  */
#line 2385 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_only_end;
        }
    break;

  case 216:

/* Line 677 of lalr1.cc  */
#line 2392 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)),
                dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr),
                (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 217:

/* Line 677 of lalr1.cc  */
#line 2400 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr),
                (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 218:

/* Line 677 of lalr1.cc  */
#line 2411 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 219:

/* Line 677 of lalr1.cc  */
#line 2421 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 220:

/* Line 677 of lalr1.cc  */
#line 2434 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 229:

/* Line 677 of lalr1.cc  */
#line 2456 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 230:

/* Line 677 of lalr1.cc  */
#line 2462 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 231:

/* Line 677 of lalr1.cc  */
#line 2471 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = NULL;
        }
    break;

  case 232:

/* Line 677 of lalr1.cc  */
#line 2475 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_ofor;
        }
    break;

  case 233:

/* Line 677 of lalr1.cc  */
#line 2483 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForClause(
                LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL
            );
        }
    break;

  case 234:

/* Line 677 of lalr1.cc  */
#line 2493 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
            vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vdl;
        }
    break;

  case 235:

/* Line 677 of lalr1.cc  */
#line 2499 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 236:

/* Line 677 of lalr1.cc  */
#line 2511 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 237:

/* Line 677 of lalr1.cc  */
#line 2515 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,NULL,
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 238:

/* Line 677 of lalr1.cc  */
#line 2523 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 239:

/* Line 677 of lalr1.cc  */
#line 2532 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
                         NULL,
                         (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 240:

/* Line 677 of lalr1.cc  */
#line 2542 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 241:

/* Line 677 of lalr1.cc  */
#line 2550 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 242:

/* Line 677 of lalr1.cc  */
#line 2559 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 243:

/* Line 677 of lalr1.cc  */
#line 2568 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                         (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 244:

/* Line 677 of lalr1.cc  */
#line 2583 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 245:

/* Line 677 of lalr1.cc  */
#line 2592 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 246:

/* Line 677 of lalr1.cc  */
#line 2602 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 247:

/* Line 677 of lalr1.cc  */
#line 2610 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 248:

/* Line 677 of lalr1.cc  */
#line 2616 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 249:

/* Line 677 of lalr1.cc  */
#line 2625 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 250:

/* Line 677 of lalr1.cc  */
#line 2631 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 251:

/* Line 677 of lalr1.cc  */
#line 2643 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 252:

/* Line 677 of lalr1.cc  */
#line 2651 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 253:

/* Line 677 of lalr1.cc  */
#line 2661 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                           (yysemantic_stack_[(4) - (4)].expr));
     }
    break;

  case 254:

/* Line 677 of lalr1.cc  */
#line 2669 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                           (yysemantic_stack_[(5) - (5)].expr));
     }
    break;

  case 255:

/* Line 677 of lalr1.cc  */
#line 2681 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 256:

/* Line 677 of lalr1.cc  */
#line 2687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 258:

/* Line 677 of lalr1.cc  */
#line 2700 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 259:

/* Line 677 of lalr1.cc  */
#line 2704 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 260:

/* Line 677 of lalr1.cc  */
#line 2712 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 261:

/* Line 677 of lalr1.cc  */
#line 2716 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 263:

/* Line 677 of lalr1.cc  */
#line 2725 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 264:

/* Line 677 of lalr1.cc  */
#line 2729 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 265:

/* Line 677 of lalr1.cc  */
#line 2733 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 266:

/* Line 677 of lalr1.cc  */
#line 2741 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)),
                           NULL, NULL,
                           new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))),
                           VarGetsDecl::eval_var);
    }
    break;

  case 267:

/* Line 677 of lalr1.cc  */
#line 2755 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 268:

/* Line 677 of lalr1.cc  */
#line 2763 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 269:

/* Line 677 of lalr1.cc  */
#line 2770 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 270:

/* Line 677 of lalr1.cc  */
#line 2776 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 271:

/* Line 677 of lalr1.cc  */
#line 2787 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 272:

/* Line 677 of lalr1.cc  */
#line 2791 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 273:

/* Line 677 of lalr1.cc  */
#line 2800 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 274:

/* Line 677 of lalr1.cc  */
#line 2808 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 275:

/* Line 677 of lalr1.cc  */
#line 2814 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 276:

/* Line 677 of lalr1.cc  */
#line 2824 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 277:

/* Line 677 of lalr1.cc  */
#line 2830 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 278:

/* Line 677 of lalr1.cc  */
#line 2840 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 279:

/* Line 677 of lalr1.cc  */
#line 2844 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 280:

/* Line 677 of lalr1.cc  */
#line 2854 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 281:

/* Line 677 of lalr1.cc  */
#line 2860 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 282:

/* Line 677 of lalr1.cc  */
#line 2866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 283:

/* Line 677 of lalr1.cc  */
#line 2872 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 284:

/* Line 677 of lalr1.cc  */
#line 2881 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 285:

/* Line 677 of lalr1.cc  */
#line 2890 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 286:

/* Line 677 of lalr1.cc  */
#line 2899 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 287:

/* Line 677 of lalr1.cc  */
#line 2912 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 288:

/* Line 677 of lalr1.cc  */
#line 2916 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 289:

/* Line 677 of lalr1.cc  */
#line 2924 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 290:

/* Line 677 of lalr1.cc  */
#line 2930 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 291:

/* Line 677 of lalr1.cc  */
#line 2940 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 292:

/* Line 677 of lalr1.cc  */
#line 2948 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 293:

/* Line 677 of lalr1.cc  */
#line 2957 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 294:

/* Line 677 of lalr1.cc  */
#line 2970 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 295:

/* Line 677 of lalr1.cc  */
#line 2977 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 296:

/* Line 677 of lalr1.cc  */
#line 2989 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 297:

/* Line 677 of lalr1.cc  */
#line 2993 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 298:

/* Line 677 of lalr1.cc  */
#line 3005 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 299:

/* Line 677 of lalr1.cc  */
#line 3012 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 300:

/* Line 677 of lalr1.cc  */
#line 3018 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 301:

/* Line 677 of lalr1.cc  */
#line 3027 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 302:

/* Line 677 of lalr1.cc  */
#line 3034 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 303:

/* Line 677 of lalr1.cc  */
#line 3040 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 304:

/* Line 677 of lalr1.cc  */
#line 3052 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 305:

/* Line 677 of lalr1.cc  */
#line 3059 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 306:

/* Line 677 of lalr1.cc  */
#line 3072 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 307:

/* Line 677 of lalr1.cc  */
#line 3078 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 308:

/* Line 677 of lalr1.cc  */
#line 3090 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 309:

/* Line 677 of lalr1.cc  */
#line 3096 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 310:

/* Line 677 of lalr1.cc  */
#line 3108 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 311:

/* Line 677 of lalr1.cc  */
#line 3117 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 312:

/* Line 677 of lalr1.cc  */
#line 3121 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 313:

/* Line 677 of lalr1.cc  */
#line 3130 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 314:

/* Line 677 of lalr1.cc  */
#line 3134 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 315:

/* Line 677 of lalr1.cc  */
#line 3142 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 316:

/* Line 677 of lalr1.cc  */
#line 3146 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 317:

/* Line 677 of lalr1.cc  */
#line 3156 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 318:

/* Line 677 of lalr1.cc  */
#line 3163 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 319:

/* Line 677 of lalr1.cc  */
#line 3172 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 320:

/* Line 677 of lalr1.cc  */
#line 3181 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 321:

/* Line 677 of lalr1.cc  */
#line 3186 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 322:

/* Line 677 of lalr1.cc  */
#line 3195 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 323:

/* Line 677 of lalr1.cc  */
#line 3204 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 324:

/* Line 677 of lalr1.cc  */
#line 3213 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 325:

/* Line 677 of lalr1.cc  */
#line 3226 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 326:

/* Line 677 of lalr1.cc  */
#line 3230 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 327:

/* Line 677 of lalr1.cc  */
#line 3242 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 328:

/* Line 677 of lalr1.cc  */
#line 3246 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 329:

/* Line 677 of lalr1.cc  */
#line 3253 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 330:

/* Line 677 of lalr1.cc  */
#line 3257 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 331:

/* Line 677 of lalr1.cc  */
#line 3266 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 332:

/* Line 677 of lalr1.cc  */
#line 3270 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 333:

/* Line 677 of lalr1.cc  */
#line 3274 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 334:

/* Line 677 of lalr1.cc  */
#line 3283 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 335:

/* Line 677 of lalr1.cc  */
#line 3287 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 336:

/* Line 677 of lalr1.cc  */
#line 3293 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 337:

/* Line 677 of lalr1.cc  */
#line 3299 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 338:

/* Line 677 of lalr1.cc  */
#line 3305 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 339:

/* Line 677 of lalr1.cc  */
#line 3316 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 340:

/* Line 677 of lalr1.cc  */
#line 3320 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 341:

/* Line 677 of lalr1.cc  */
#line 3324 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 342:

/* Line 677 of lalr1.cc  */
#line 3332 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 343:

/* Line 677 of lalr1.cc  */
#line 3336 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 344:

/* Line 677 of lalr1.cc  */
#line 3342 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 345:

/* Line 677 of lalr1.cc  */
#line 3352 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 346:

/* Line 677 of lalr1.cc  */
#line 3356 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 347:

/* Line 677 of lalr1.cc  */
#line 3366 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 348:

/* Line 677 of lalr1.cc  */
#line 3370 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 349:

/* Line 677 of lalr1.cc  */
#line 3380 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 350:

/* Line 677 of lalr1.cc  */
#line 3384 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 351:

/* Line 677 of lalr1.cc  */
#line 3394 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 352:

/* Line 677 of lalr1.cc  */
#line 3398 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 353:

/* Line 677 of lalr1.cc  */
#line 3408 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 354:

/* Line 677 of lalr1.cc  */
#line 3412 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 355:

/* Line 677 of lalr1.cc  */
#line 3420 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 356:

/* Line 677 of lalr1.cc  */
#line 3424 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 357:

/* Line 677 of lalr1.cc  */
#line 3428 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 358:

/* Line 677 of lalr1.cc  */
#line 3432 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 359:

/* Line 677 of lalr1.cc  */
#line 3442 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 360:

/* Line 677 of lalr1.cc  */
#line 3446 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 361:

/* Line 677 of lalr1.cc  */
#line 3450 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 362:

/* Line 677 of lalr1.cc  */
#line 3458 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 363:

/* Line 677 of lalr1.cc  */
#line 3462 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 364:

/* Line 677 of lalr1.cc  */
#line 3466 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 365:

/* Line 677 of lalr1.cc  */
#line 3470 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 366:

/* Line 677 of lalr1.cc  */
#line 3474 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 367:

/* Line 677 of lalr1.cc  */
#line 3478 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 368:

/* Line 677 of lalr1.cc  */
#line 3486 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 369:

/* Line 677 of lalr1.cc  */
#line 3490 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 370:

/* Line 677 of lalr1.cc  */
#line 3494 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 371:

/* Line 677 of lalr1.cc  */
#line 3502 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 372:

/* Line 677 of lalr1.cc  */
#line 3506 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 373:

/* Line 677 of lalr1.cc  */
#line 3510 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 374:

/* Line 677 of lalr1.cc  */
#line 3514 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 375:

/* Line 677 of lalr1.cc  */
#line 3525 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 376:

/* Line 677 of lalr1.cc  */
#line 3531 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 377:

/* Line 677 of lalr1.cc  */
#line 3541 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 378:

/* Line 677 of lalr1.cc  */
#line 3547 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 379:

/* Line 677 of lalr1.cc  */
#line 3557 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 380:

/* Line 677 of lalr1.cc  */
#line 3561 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 381:

/* Line 677 of lalr1.cc  */
#line 3599 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL
            );
        }
    break;

  case 382:

/* Line 677 of lalr1.cc  */
#line 3605 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 383:

/* Line 677 of lalr1.cc  */
#line 3611 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 384:

/* Line 677 of lalr1.cc  */
#line 3617 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = !rpe ?
                (yysemantic_stack_[(1) - (1)].expr) : new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 385:

/* Line 677 of lalr1.cc  */
#line 3628 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NULL;
        }
    break;

  case 386:

/* Line 677 of lalr1.cc  */
#line 3636 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 387:

/* Line 677 of lalr1.cc  */
#line 3647 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 388:

/* Line 677 of lalr1.cc  */
#line 3653 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 389:

/* Line 677 of lalr1.cc  */
#line 3663 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 390:

/* Line 677 of lalr1.cc  */
#line 3667 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 677 of lalr1.cc  */
#line 3675 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 392:

/* Line 677 of lalr1.cc  */
#line 3681 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 393:

/* Line 677 of lalr1.cc  */
#line 3689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 394:

/* Line 677 of lalr1.cc  */
#line 3695 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 395:

/* Line 677 of lalr1.cc  */
#line 3707 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 396:

/* Line 677 of lalr1.cc  */
#line 3713 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 397:

/* Line 677 of lalr1.cc  */
#line 3723 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 398:

/* Line 677 of lalr1.cc  */
#line 3727 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 399:

/* Line 677 of lalr1.cc  */
#line 3731 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 400:

/* Line 677 of lalr1.cc  */
#line 3735 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 401:

/* Line 677 of lalr1.cc  */
#line 3739 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 402:

/* Line 677 of lalr1.cc  */
#line 3745 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 403:

/* Line 677 of lalr1.cc  */
#line 3751 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 404:

/* Line 677 of lalr1.cc  */
#line 3774 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 405:

/* Line 677 of lalr1.cc  */
#line 3778 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 406:

/* Line 677 of lalr1.cc  */
#line 3786 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 407:

/* Line 677 of lalr1.cc  */
#line 3790 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 408:

/* Line 677 of lalr1.cc  */
#line 3801 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 409:

/* Line 677 of lalr1.cc  */
#line 3805 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 410:

/* Line 677 of lalr1.cc  */
#line 3809 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 411:

/* Line 677 of lalr1.cc  */
#line 3815 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 412:

/* Line 677 of lalr1.cc  */
#line 3819 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 413:

/* Line 677 of lalr1.cc  */
#line 3833 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 414:

/* Line 677 of lalr1.cc  */
#line 3837 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 415:

/* Line 677 of lalr1.cc  */
#line 3845 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 416:

/* Line 677 of lalr1.cc  */
#line 3849 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 417:

/* Line 677 of lalr1.cc  */
#line 3859 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 418:

/* Line 677 of lalr1.cc  */
#line 3863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 419:

/* Line 677 of lalr1.cc  */
#line 3867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 420:

/* Line 677 of lalr1.cc  */
#line 3876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 421:

/* Line 677 of lalr1.cc  */
#line 3880 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FilterExpr(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 422:

/* Line 677 of lalr1.cc  */
#line 3886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
        }
    break;

  case 423:

/* Line 677 of lalr1.cc  */
#line 3890 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
        }
    break;

  case 424:

/* Line 677 of lalr1.cc  */
#line 3898 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 425:

/* Line 677 of lalr1.cc  */
#line 3904 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 426:

/* Line 677 of lalr1.cc  */
#line 3914 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 427:

/* Line 677 of lalr1.cc  */
#line 3922 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 428:

/* Line 677 of lalr1.cc  */
#line 3926 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 429:

/* Line 677 of lalr1.cc  */
#line 3930 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 430:

/* Line 677 of lalr1.cc  */
#line 3934 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 431:

/* Line 677 of lalr1.cc  */
#line 3938 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 432:

/* Line 677 of lalr1.cc  */
#line 3942 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 433:

/* Line 677 of lalr1.cc  */
#line 3946 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 434:

/* Line 677 of lalr1.cc  */
#line 3950 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 435:

/* Line 677 of lalr1.cc  */
#line 3954 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 436:

/* Line 677 of lalr1.cc  */
#line 3962 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 437:

/* Line 677 of lalr1.cc  */
#line 3966 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 438:

/* Line 677 of lalr1.cc  */
#line 3974 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 439:

/* Line 677 of lalr1.cc  */
#line 3981 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 440:

/* Line 677 of lalr1.cc  */
#line 3988 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 441:

/* Line 677 of lalr1.cc  */
#line 3999 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 442:

/* Line 677 of lalr1.cc  */
#line 4007 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 443:

/* Line 677 of lalr1.cc  */
#line 4011 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 444:

/* Line 677 of lalr1.cc  */
#line 4019 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 445:

/* Line 677 of lalr1.cc  */
#line 4027 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 446:

/* Line 677 of lalr1.cc  */
#line 4035 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 447:

/* Line 677 of lalr1.cc  */
#line 4089 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 448:

/* Line 677 of lalr1.cc  */
#line 4093 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 449:

/* Line 677 of lalr1.cc  */
#line 4106 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 450:

/* Line 677 of lalr1.cc  */
#line 4112 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 451:

/* Line 677 of lalr1.cc  */
#line 4122 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 452:

/* Line 677 of lalr1.cc  */
#line 4126 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 453:

/* Line 677 of lalr1.cc  */
#line 4134 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 454:

/* Line 677 of lalr1.cc  */
#line 4138 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 455:

/* Line 677 of lalr1.cc  */
#line 4142 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

/* Line 677 of lalr1.cc  */
#line 4150 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 457:

/* Line 677 of lalr1.cc  */
#line 4160 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 458:

/* Line 677 of lalr1.cc  */
#line 4170 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 459:

/* Line 677 of lalr1.cc  */
#line 4180 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 460:

/* Line 677 of lalr1.cc  */
#line 4190 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 461:

/* Line 677 of lalr1.cc  */
#line 4200 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 462:

/* Line 677 of lalr1.cc  */
#line 4215 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 463:

/* Line 677 of lalr1.cc  */
#line 4221 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 464:

/* Line 677 of lalr1.cc  */
#line 4232 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 465:

/* Line 677 of lalr1.cc  */
#line 4238 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 466:

/* Line 677 of lalr1.cc  */
#line 4249 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 469:

/* Line 677 of lalr1.cc  */
#line 4266 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 470:

/* Line 677 of lalr1.cc  */
#line 4271 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 471:

/* Line 677 of lalr1.cc  */
#line 4280 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 472:

/* Line 677 of lalr1.cc  */
#line 4284 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 473:

/* Line 677 of lalr1.cc  */
#line 4291 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back(
                new QuoteAttrValueContent( LOC((yyloc)),std::string("\"") )
            );
            (yyval.node) = qacl;
        }
    break;

  case 474:

/* Line 677 of lalr1.cc  */
#line 4299 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 475:

/* Line 677 of lalr1.cc  */
#line 4305 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 476:

/* Line 677 of lalr1.cc  */
#line 4315 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 477:

/* Line 677 of lalr1.cc  */
#line 4327 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 478:

/* Line 677 of lalr1.cc  */
#line 4331 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 479:

/* Line 677 of lalr1.cc  */
#line 4338 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 480:

/* Line 677 of lalr1.cc  */
#line 4344 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 481:

/* Line 677 of lalr1.cc  */
#line 4350 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 482:

/* Line 677 of lalr1.cc  */
#line 4357 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 483:

/* Line 677 of lalr1.cc  */
#line 4368 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 484:

/* Line 677 of lalr1.cc  */
#line 4372 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 485:

/* Line 677 of lalr1.cc  */
#line 4382 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 486:

/* Line 677 of lalr1.cc  */
#line 4386 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 487:

/* Line 677 of lalr1.cc  */
#line 4396 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 488:

/* Line 677 of lalr1.cc  */
#line 4400 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 489:

/* Line 677 of lalr1.cc  */
#line 4404 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 490:

/* Line 677 of lalr1.cc  */
#line 4409 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 491:

/* Line 677 of lalr1.cc  */
#line 4418 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 492:

/* Line 677 of lalr1.cc  */
#line 4424 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 493:

/* Line 677 of lalr1.cc  */
#line 4430 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 494:

/* Line 677 of lalr1.cc  */
#line 4436 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 495:

/* Line 677 of lalr1.cc  */
#line 4446 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 496:

/* Line 677 of lalr1.cc  */
#line 4450 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
        }
    break;

  case 497:

/* Line 677 of lalr1.cc  */
#line 4462 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 498:

/* Line 677 of lalr1.cc  */
#line 4466 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 499:

/* Line 677 of lalr1.cc  */
#line 4478 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 500:

/* Line 677 of lalr1.cc  */
#line 4490 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 501:

/* Line 677 of lalr1.cc  */
#line 4494 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 502:

/* Line 677 of lalr1.cc  */
#line 4498 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 503:

/* Line 677 of lalr1.cc  */
#line 4502 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 504:

/* Line 677 of lalr1.cc  */
#line 4506 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 505:

/* Line 677 of lalr1.cc  */
#line 4510 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 506:

/* Line 677 of lalr1.cc  */
#line 4518 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 507:

/* Line 677 of lalr1.cc  */
#line 4526 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL
            );
        }
    break;

  case 508:

/* Line 677 of lalr1.cc  */
#line 4532 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr)
            );
        }
    break;

  case 509:

/* Line 677 of lalr1.cc  */
#line 4538 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 510:

/* Line 677 of lalr1.cc  */
#line 4542 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 511:

/* Line 677 of lalr1.cc  */
#line 4559 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (2)].expr), NULL );
        }
    break;

  case 512:

/* Line 677 of lalr1.cc  */
#line 4563 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 513:

/* Line 677 of lalr1.cc  */
#line 4567 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 514:

/* Line 677 of lalr1.cc  */
#line 4571 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 515:

/* Line 677 of lalr1.cc  */
#line 4579 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 516:

/* Line 677 of lalr1.cc  */
#line 4587 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 517:

/* Line 677 of lalr1.cc  */
#line 4595 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), NULL );
        }
    break;

  case 518:

/* Line 677 of lalr1.cc  */
#line 4599 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (2)].sval)), (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 519:

/* Line 677 of lalr1.cc  */
#line 4603 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 520:

/* Line 677 of lalr1.cc  */
#line 4607 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 521:

/* Line 677 of lalr1.cc  */
#line 4615 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 522:

/* Line 677 of lalr1.cc  */
#line 4621 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 523:

/* Line 677 of lalr1.cc  */
#line 4631 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 524:

/* Line 677 of lalr1.cc  */
#line 4639 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 525:

/* Line 677 of lalr1.cc  */
#line 4643 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 526:

/* Line 677 of lalr1.cc  */
#line 4649 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 527:

/* Line 677 of lalr1.cc  */
#line 4684 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 528:

/* Line 677 of lalr1.cc  */
#line 4690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 529:

/* Line 677 of lalr1.cc  */
#line 4696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 530:

/* Line 677 of lalr1.cc  */
#line 4706 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 531:

/* Line 677 of lalr1.cc  */
#line 4710 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 532:

/* Line 677 of lalr1.cc  */
#line 4714 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 533:

/* Line 677 of lalr1.cc  */
#line 4718 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 534:

/* Line 677 of lalr1.cc  */
#line 4722 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 535:

/* Line 677 of lalr1.cc  */
#line 4729 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 536:

/* Line 677 of lalr1.cc  */
#line 4735 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 537:

/* Line 677 of lalr1.cc  */
#line 4745 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 538:

/* Line 677 of lalr1.cc  */
#line 4753 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 539:

/* Line 677 of lalr1.cc  */
#line 4757 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 540:

/* Line 677 of lalr1.cc  */
#line 4761 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 541:

/* Line 677 of lalr1.cc  */
#line 4765 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 542:

/* Line 677 of lalr1.cc  */
#line 4769 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 543:

/* Line 677 of lalr1.cc  */
#line 4773 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 544:

/* Line 677 of lalr1.cc  */
#line 4777 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 545:

/* Line 677 of lalr1.cc  */
#line 4781 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 546:

/* Line 677 of lalr1.cc  */
#line 4785 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 547:

/* Line 677 of lalr1.cc  */
#line 4793 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 548:

/* Line 677 of lalr1.cc  */
#line 4801 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 549:

/* Line 677 of lalr1.cc  */
#line 4805 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 550:

/* Line 677 of lalr1.cc  */
#line 4809 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 551:

/* Line 677 of lalr1.cc  */
#line 4819 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 552:

/* Line 677 of lalr1.cc  */
#line 4827 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 553:

/* Line 677 of lalr1.cc  */
#line 4835 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 554:

/* Line 677 of lalr1.cc  */
#line 4839 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 555:

/* Line 677 of lalr1.cc  */
#line 4843 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 556:

/* Line 677 of lalr1.cc  */
#line 4851 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 557:

/* Line 677 of lalr1.cc  */
#line 4855 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 558:

/* Line 677 of lalr1.cc  */
#line 4861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 559:

/* Line 677 of lalr1.cc  */
#line 4867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 560:

/* Line 677 of lalr1.cc  */
#line 4871 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 561:

/* Line 677 of lalr1.cc  */
#line 4881 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 562:

/* Line 677 of lalr1.cc  */
#line 4889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 563:

/* Line 677 of lalr1.cc  */
#line 4893 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 564:

/* Line 677 of lalr1.cc  */
#line 4899 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 565:

/* Line 677 of lalr1.cc  */
#line 4908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 566:

/* Line 677 of lalr1.cc  */
#line 4917 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 567:

/* Line 677 of lalr1.cc  */
#line 4923 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 568:

/* Line 677 of lalr1.cc  */
#line 4929 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 569:

/* Line 677 of lalr1.cc  */
#line 4939 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 570:

/* Line 677 of lalr1.cc  */
#line 4956 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 571:

/* Line 677 of lalr1.cc  */
#line 4963 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 572:

/* Line 677 of lalr1.cc  */
#line 4978 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 573:

/* Line 677 of lalr1.cc  */
#line 5014 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 574:

/* Line 677 of lalr1.cc  */
#line 5018 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 575:

/* Line 677 of lalr1.cc  */
#line 5027 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
        }
    break;

  case 576:

/* Line 677 of lalr1.cc  */
#line 5036 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new InlineFunction(LOC ((yyloc)), &*(yysemantic_stack_[(3) - (2)].fnsig)->param, &*(yysemantic_stack_[(3) - (2)].fnsig)->ret, dynamic_cast<EnclosedExpr *>((yysemantic_stack_[(3) - (3)].expr)));
          delete (yysemantic_stack_[(3) - (2)].fnsig);
        }
    break;

  case 577:

/* Line 677 of lalr1.cc  */
#line 5046 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 578:

/* Line 677 of lalr1.cc  */
#line 5050 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 579:

/* Line 677 of lalr1.cc  */
#line 5059 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
        }
    break;

  case 580:

/* Line 677 of lalr1.cc  */
#line 5068 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 581:

/* Line 677 of lalr1.cc  */
#line 5072 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 582:

/* Line 677 of lalr1.cc  */
#line 5083 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 583:

/* Line 677 of lalr1.cc  */
#line 5100 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 584:

/* Line 677 of lalr1.cc  */
#line 5106 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 585:

/* Line 677 of lalr1.cc  */
#line 5112 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 586:

/* Line 677 of lalr1.cc  */
#line 5122 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 587:

/* Line 677 of lalr1.cc  */
#line 5126 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 588:

/* Line 677 of lalr1.cc  */
#line 5132 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 589:

/* Line 677 of lalr1.cc  */
#line 5138 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 590:

/* Line 677 of lalr1.cc  */
#line 5142 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 591:

/* Line 677 of lalr1.cc  */
#line 5148 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 592:

/* Line 677 of lalr1.cc  */
#line 5152 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 593:

/* Line 677 of lalr1.cc  */
#line 5158 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 594:

/* Line 677 of lalr1.cc  */
#line 5164 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 595:

/* Line 677 of lalr1.cc  */
#line 5171 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 596:

/* Line 677 of lalr1.cc  */
#line 5181 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 597:

/* Line 677 of lalr1.cc  */
#line 5186 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 598:

/* Line 677 of lalr1.cc  */
#line 5194 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 599:

/* Line 677 of lalr1.cc  */
#line 5200 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 600:

/* Line 677 of lalr1.cc  */
#line 5210 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 601:

/* Line 677 of lalr1.cc  */
#line 5232 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 602:

/* Line 677 of lalr1.cc  */
#line 5241 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 603:

/* Line 677 of lalr1.cc  */
#line 5247 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 604:

/* Line 677 of lalr1.cc  */
#line 5260 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 605:

/* Line 677 of lalr1.cc  */
#line 5274 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 606:

/* Line 677 of lalr1.cc  */
#line 5281 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 607:

/* Line 677 of lalr1.cc  */
#line 5287 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 608:

/* Line 677 of lalr1.cc  */
#line 5297 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 609:

/* Line 677 of lalr1.cc  */
#line 5302 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 610:

/* Line 677 of lalr1.cc  */
#line 5308 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 611:

/* Line 677 of lalr1.cc  */
#line 5318 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 612:

/* Line 677 of lalr1.cc  */
#line 5331 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 613:

/* Line 677 of lalr1.cc  */
#line 5337 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 616:

/* Line 677 of lalr1.cc  */
#line 5358 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 617:

/* Line 677 of lalr1.cc  */
#line 5377 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr(
        LOC((yyloc)), dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)), (yysemantic_stack_[(7) - (6)].expr)
        );
    }
    break;

  case 618:

/* Line 677 of lalr1.cc  */
#line 5383 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr( LOC((yyloc)), new VarGetsDeclList( LOC((yyloc)) ), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 619:

/* Line 677 of lalr1.cc  */
#line 5398 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 620:

/* Line 677 of lalr1.cc  */
#line 5406 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 621:

/* Line 677 of lalr1.cc  */
#line 5410 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 622:

/* Line 677 of lalr1.cc  */
#line 5417 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 623:

/* Line 677 of lalr1.cc  */
#line 5422 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 624:

/* Line 677 of lalr1.cc  */
#line 5430 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 625:

/* Line 677 of lalr1.cc  */
#line 5434 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 626:

/* Line 677 of lalr1.cc  */
#line 5441 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 627:

/* Line 677 of lalr1.cc  */
#line 5445 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 628:

/* Line 677 of lalr1.cc  */
#line 5452 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 629:

/* Line 677 of lalr1.cc  */
#line 5456 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 630:

/* Line 677 of lalr1.cc  */
#line 5463 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 631:

/* Line 677 of lalr1.cc  */
#line 5467 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 632:

/* Line 677 of lalr1.cc  */
#line 5476 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 633:

/* Line 677 of lalr1.cc  */
#line 5488 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 634:

/* Line 677 of lalr1.cc  */
#line 5492 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 635:

/* Line 677 of lalr1.cc  */
#line 5499 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 636:

/* Line 677 of lalr1.cc  */
#line 5503 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 637:

/* Line 677 of lalr1.cc  */
#line 5511 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 638:

/* Line 677 of lalr1.cc  */
#line 5519 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 639:

/* Line 677 of lalr1.cc  */
#line 5527 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 640:

/* Line 677 of lalr1.cc  */
#line 5531 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 641:

/* Line 677 of lalr1.cc  */
#line 5538 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 642:

/* Line 677 of lalr1.cc  */
#line 5542 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 643:

/* Line 677 of lalr1.cc  */
#line 5550 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 644:

/* Line 677 of lalr1.cc  */
#line 5561 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 645:

/* Line 677 of lalr1.cc  */
#line 5565 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 646:

/* Line 677 of lalr1.cc  */
#line 5573 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 647:

/* Line 677 of lalr1.cc  */
#line 5585 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 648:

/* Line 677 of lalr1.cc  */
#line 5591 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 649:

/* Line 677 of lalr1.cc  */
#line 5600 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 650:

/* Line 677 of lalr1.cc  */
#line 5604 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 651:

/* Line 677 of lalr1.cc  */
#line 5612 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 652:

/* Line 677 of lalr1.cc  */
#line 5616 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 653:

/* Line 677 of lalr1.cc  */
#line 5620 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 654:

/* Line 677 of lalr1.cc  */
#line 5627 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 655:

/* Line 677 of lalr1.cc  */
#line 5631 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 656:

/* Line 677 of lalr1.cc  */
#line 5638 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 657:

/* Line 677 of lalr1.cc  */
#line 5642 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 658:

/* Line 677 of lalr1.cc  */
#line 5650 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 659:

/* Line 677 of lalr1.cc  */
#line 5654 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 660:

/* Line 677 of lalr1.cc  */
#line 5658 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 661:

/* Line 677 of lalr1.cc  */
#line 5662 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 662:

/* Line 677 of lalr1.cc  */
#line 5666 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 663:

/* Line 677 of lalr1.cc  */
#line 5674 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 664:

/* Line 677 of lalr1.cc  */
#line 5682 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 665:

/* Line 677 of lalr1.cc  */
#line 5694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 666:

/* Line 677 of lalr1.cc  */
#line 5706 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 667:

/* Line 677 of lalr1.cc  */
#line 5710 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 668:

/* Line 677 of lalr1.cc  */
#line 5714 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 669:

/* Line 677 of lalr1.cc  */
#line 5722 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 670:

/* Line 677 of lalr1.cc  */
#line 5728 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 671:

/* Line 677 of lalr1.cc  */
#line 5738 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 677 of lalr1.cc  */
#line 5742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 677 of lalr1.cc  */
#line 5746 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 677 of lalr1.cc  */
#line 5750 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 675:

/* Line 677 of lalr1.cc  */
#line 5754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 677 of lalr1.cc  */
#line 5758 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 677:

/* Line 677 of lalr1.cc  */
#line 5762 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 678:

/* Line 677 of lalr1.cc  */
#line 5766 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 679:

/* Line 677 of lalr1.cc  */
#line 5774 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 680:

/* Line 677 of lalr1.cc  */
#line 5778 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 681:

/* Line 677 of lalr1.cc  */
#line 5782 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 682:

/* Line 677 of lalr1.cc  */
#line 5786 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 683:

/* Line 677 of lalr1.cc  */
#line 5794 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 684:

/* Line 677 of lalr1.cc  */
#line 5800 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 685:

/* Line 677 of lalr1.cc  */
#line 5810 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 686:

/* Line 677 of lalr1.cc  */
#line 5820 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 687:

/* Line 677 of lalr1.cc  */
#line 5824 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 688:

/* Line 677 of lalr1.cc  */
#line 5832 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 689:

/* Line 677 of lalr1.cc  */
#line 5842 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 690:

/* Line 677 of lalr1.cc  */
#line 5853 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 691:

/* Line 677 of lalr1.cc  */
#line 5860 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 677 of lalr1.cc  */
#line 5864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 693:

/* Line 677 of lalr1.cc  */
#line 5871 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 694:

/* Line 677 of lalr1.cc  */
#line 5875 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(1) - (1)].thesaurus_id_list);
        }
    break;

  case 695:

/* Line 677 of lalr1.cc  */
#line 5882 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 696:

/* Line 677 of lalr1.cc  */
#line 5887 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 697:

/* Line 677 of lalr1.cc  */
#line 5896 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 698:

/* Line 677 of lalr1.cc  */
#line 5905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 699:

/* Line 677 of lalr1.cc  */
#line 5909 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 700:

/* Line 677 of lalr1.cc  */
#line 5916 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 701:

/* Line 677 of lalr1.cc  */
#line 5920 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 702:

/* Line 677 of lalr1.cc  */
#line 5928 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 703:

/* Line 677 of lalr1.cc  */
#line 5937 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 704:

/* Line 677 of lalr1.cc  */
#line 5944 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 705:

/* Line 677 of lalr1.cc  */
#line 5954 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 706:

/* Line 677 of lalr1.cc  */
#line 5958 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 707:

/* Line 677 of lalr1.cc  */
#line 5965 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 708:

/* Line 677 of lalr1.cc  */
#line 5971 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 709:

/* Line 677 of lalr1.cc  */
#line 5980 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 710:

/* Line 677 of lalr1.cc  */
#line 5984 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 711:

/* Line 677 of lalr1.cc  */
#line 5991 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 712:

/* Line 677 of lalr1.cc  */
#line 5996 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 713:

/* Line 677 of lalr1.cc  */
#line 6008 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 714:

/* Line 677 of lalr1.cc  */
#line 6016 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 715:

/* Line 677 of lalr1.cc  */
#line 6028 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 716:

/* Line 677 of lalr1.cc  */
#line 6036 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 717:

/* Line 677 of lalr1.cc  */
#line 6040 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 718:

/* Line 677 of lalr1.cc  */
#line 6048 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 719:

/* Line 677 of lalr1.cc  */
#line 6052 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 720:

/* Line 677 of lalr1.cc  */
#line 6056 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 721:

/* Line 677 of lalr1.cc  */
#line 6064 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 722:

/* Line 677 of lalr1.cc  */
#line 6072 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 723:

/* Line 677 of lalr1.cc  */
#line 6076 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 724:

/* Line 677 of lalr1.cc  */
#line 6080 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 725:

/* Line 677 of lalr1.cc  */
#line 6084 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 726:

/* Line 677 of lalr1.cc  */
#line 6092 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 727:

/* Line 677 of lalr1.cc  */
#line 6100 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 728:

/* Line 677 of lalr1.cc  */
#line 6112 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 729:

/* Line 677 of lalr1.cc  */
#line 6116 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 730:

/* Line 677 of lalr1.cc  */
#line 6124 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 731:

/* Line 677 of lalr1.cc  */
#line 6137 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 732:

/* Line 677 of lalr1.cc  */
#line 6141 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 733:

/* Line 677 of lalr1.cc  */
#line 6147 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("xquery"); }
    break;

  case 734:

/* Line 677 of lalr1.cc  */
#line 6148 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("empty"); }
    break;

  case 735:

/* Line 677 of lalr1.cc  */
#line 6149 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("attribute"); }
    break;

  case 736:

/* Line 677 of lalr1.cc  */
#line 6150 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("comment"); }
    break;

  case 737:

/* Line 677 of lalr1.cc  */
#line 6151 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("document-node"); }
    break;

  case 738:

/* Line 677 of lalr1.cc  */
#line 6152 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("element"); }
    break;

  case 739:

/* Line 677 of lalr1.cc  */
#line 6153 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("item"); }
    break;

  case 740:

/* Line 677 of lalr1.cc  */
#line 6154 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("if"); }
    break;

  case 741:

/* Line 677 of lalr1.cc  */
#line 6155 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("node"); }
    break;

  case 742:

/* Line 677 of lalr1.cc  */
#line 6156 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("processing-instruction"); }
    break;

  case 743:

/* Line 677 of lalr1.cc  */
#line 6157 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema-attribute"); }
    break;

  case 744:

/* Line 677 of lalr1.cc  */
#line 6158 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema-element"); }
    break;

  case 745:

/* Line 677 of lalr1.cc  */
#line 6159 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("text"); }
    break;

  case 746:

/* Line 677 of lalr1.cc  */
#line 6160 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("typeswitch"); }
    break;

  case 747:

/* Line 677 of lalr1.cc  */
#line 6161 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("switch"); }
    break;

  case 748:

/* Line 677 of lalr1.cc  */
#line 6162 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("empty-sequence"); }
    break;

  case 749:

/* Line 677 of lalr1.cc  */
#line 6163 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("boundary-space"); }
    break;

  case 750:

/* Line 677 of lalr1.cc  */
#line 6164 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ft-option"); }
    break;

  case 751:

/* Line 677 of lalr1.cc  */
#line 6165 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("base-uri"); }
    break;

  case 752:

/* Line 677 of lalr1.cc  */
#line 6166 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lax"); }
    break;

  case 753:

/* Line 677 of lalr1.cc  */
#line 6167 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("strict"); }
    break;

  case 754:

/* Line 677 of lalr1.cc  */
#line 6168 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("idiv"); }
    break;

  case 755:

/* Line 677 of lalr1.cc  */
#line 6169 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("document"); }
    break;

  case 756:

/* Line 677 of lalr1.cc  */
#line 6170 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ftnot"); }
    break;

  case 757:

/* Line 677 of lalr1.cc  */
#line 6171 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("not"); }
    break;

  case 758:

/* Line 677 of lalr1.cc  */
#line 6172 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sensitive"); }
    break;

  case 759:

/* Line 677 of lalr1.cc  */
#line 6173 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("insensitive"); }
    break;

  case 760:

/* Line 677 of lalr1.cc  */
#line 6174 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("diacritics"); }
    break;

  case 761:

/* Line 677 of lalr1.cc  */
#line 6175 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("without"); }
    break;

  case 762:

/* Line 677 of lalr1.cc  */
#line 6176 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stemming"); }
    break;

  case 763:

/* Line 677 of lalr1.cc  */
#line 6177 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("thesaurus"); }
    break;

  case 764:

/* Line 677 of lalr1.cc  */
#line 6178 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stop"); }
    break;

  case 765:

/* Line 677 of lalr1.cc  */
#line 6179 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("wildcards"); }
    break;

  case 766:

/* Line 677 of lalr1.cc  */
#line 6180 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("entire"); }
    break;

  case 767:

/* Line 677 of lalr1.cc  */
#line 6181 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("content"); }
    break;

  case 768:

/* Line 677 of lalr1.cc  */
#line 6182 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("word"); }
    break;

  case 769:

/* Line 677 of lalr1.cc  */
#line 6183 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("start"); }
    break;

  case 770:

/* Line 677 of lalr1.cc  */
#line 6184 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("end"); }
    break;

  case 771:

/* Line 677 of lalr1.cc  */
#line 6185 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("most"); }
    break;

  case 772:

/* Line 677 of lalr1.cc  */
#line 6186 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("skip"); }
    break;

  case 773:

/* Line 677 of lalr1.cc  */
#line 6187 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("copy"); }
    break;

  case 774:

/* Line 677 of lalr1.cc  */
#line 6188 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("general"); }
    break;

  case 775:

/* Line 677 of lalr1.cc  */
#line 6189 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("value"); }
    break;

  case 776:

/* Line 677 of lalr1.cc  */
#line 6190 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("eq"); }
    break;

  case 777:

/* Line 677 of lalr1.cc  */
#line 6191 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ne"); }
    break;

  case 778:

/* Line 677 of lalr1.cc  */
#line 6192 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lt"); }
    break;

  case 779:

/* Line 677 of lalr1.cc  */
#line 6193 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("le"); }
    break;

  case 780:

/* Line 677 of lalr1.cc  */
#line 6194 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("gt"); }
    break;

  case 781:

/* Line 677 of lalr1.cc  */
#line 6195 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ge"); }
    break;

  case 782:

/* Line 677 of lalr1.cc  */
#line 6196 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("at"); }
    break;

  case 783:

/* Line 677 of lalr1.cc  */
#line 6197 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("context"); }
    break;

  case 784:

/* Line 677 of lalr1.cc  */
#line 6198 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("variable"); }
    break;

  case 785:

/* Line 677 of lalr1.cc  */
#line 6199 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("return"); }
    break;

  case 786:

/* Line 677 of lalr1.cc  */
#line 6200 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("for"); }
    break;

  case 787:

/* Line 677 of lalr1.cc  */
#line 6201 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("outer"); }
    break;

  case 788:

/* Line 677 of lalr1.cc  */
#line 6202 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sliding"); }
    break;

  case 789:

/* Line 677 of lalr1.cc  */
#line 6203 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("tumbling"); }
    break;

  case 790:

/* Line 677 of lalr1.cc  */
#line 6204 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("previous"); }
    break;

  case 791:

/* Line 677 of lalr1.cc  */
#line 6205 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("next"); }
    break;

  case 792:

/* Line 677 of lalr1.cc  */
#line 6206 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("only"); }
    break;

  case 793:

/* Line 677 of lalr1.cc  */
#line 6207 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("when"); }
    break;

  case 794:

/* Line 677 of lalr1.cc  */
#line 6208 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("count"); }
    break;

  case 795:

/* Line 677 of lalr1.cc  */
#line 6209 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("in"); }
    break;

  case 796:

/* Line 677 of lalr1.cc  */
#line 6210 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("let"); }
    break;

  case 797:

/* Line 677 of lalr1.cc  */
#line 6211 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("where"); }
    break;

  case 798:

/* Line 677 of lalr1.cc  */
#line 6212 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("by"); }
    break;

  case 799:

/* Line 677 of lalr1.cc  */
#line 6213 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("group"); }
    break;

  case 800:

/* Line 677 of lalr1.cc  */
#line 6214 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("order"); }
    break;

  case 801:

/* Line 677 of lalr1.cc  */
#line 6215 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stable"); }
    break;

  case 802:

/* Line 677 of lalr1.cc  */
#line 6216 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ascending"); }
    break;

  case 803:

/* Line 677 of lalr1.cc  */
#line 6217 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("descending"); }
    break;

  case 804:

/* Line 677 of lalr1.cc  */
#line 6218 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("greatest"); }
    break;

  case 805:

/* Line 677 of lalr1.cc  */
#line 6219 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("least"); }
    break;

  case 806:

/* Line 677 of lalr1.cc  */
#line 6220 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("collation"); }
    break;

  case 807:

/* Line 677 of lalr1.cc  */
#line 6221 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("some"); }
    break;

  case 808:

/* Line 677 of lalr1.cc  */
#line 6222 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("every"); }
    break;

  case 809:

/* Line 677 of lalr1.cc  */
#line 6223 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("satisfies"); }
    break;

  case 810:

/* Line 677 of lalr1.cc  */
#line 6224 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("case"); }
    break;

  case 811:

/* Line 677 of lalr1.cc  */
#line 6225 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("as"); }
    break;

  case 812:

/* Line 677 of lalr1.cc  */
#line 6226 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("then"); }
    break;

  case 813:

/* Line 677 of lalr1.cc  */
#line 6227 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("else"); }
    break;

  case 814:

/* Line 677 of lalr1.cc  */
#line 6228 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("or"); }
    break;

  case 815:

/* Line 677 of lalr1.cc  */
#line 6229 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("and"); }
    break;

  case 816:

/* Line 677 of lalr1.cc  */
#line 6230 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("instance"); }
    break;

  case 817:

/* Line 677 of lalr1.cc  */
#line 6231 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("of"); }
    break;

  case 818:

/* Line 677 of lalr1.cc  */
#line 6232 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("castable"); }
    break;

  case 819:

/* Line 677 of lalr1.cc  */
#line 6233 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("to"); }
    break;

  case 820:

/* Line 677 of lalr1.cc  */
#line 6234 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("div"); }
    break;

  case 821:

/* Line 677 of lalr1.cc  */
#line 6235 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("mod"); }
    break;

  case 822:

/* Line 677 of lalr1.cc  */
#line 6236 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("union"); }
    break;

  case 823:

/* Line 677 of lalr1.cc  */
#line 6237 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("intersect"); }
    break;

  case 824:

/* Line 677 of lalr1.cc  */
#line 6238 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("except"); }
    break;

  case 825:

/* Line 677 of lalr1.cc  */
#line 6239 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("validate"); }
    break;

  case 826:

/* Line 677 of lalr1.cc  */
#line 6240 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("cast"); }
    break;

  case 827:

/* Line 677 of lalr1.cc  */
#line 6241 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("treat"); }
    break;

  case 828:

/* Line 677 of lalr1.cc  */
#line 6242 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("is"); }
    break;

  case 829:

/* Line 677 of lalr1.cc  */
#line 6243 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("preserve"); }
    break;

  case 830:

/* Line 677 of lalr1.cc  */
#line 6244 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("strip"); }
    break;

  case 831:

/* Line 677 of lalr1.cc  */
#line 6245 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("namespace"); }
    break;

  case 832:

/* Line 677 of lalr1.cc  */
#line 6246 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("external"); }
    break;

  case 833:

/* Line 677 of lalr1.cc  */
#line 6247 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("encoding"); }
    break;

  case 834:

/* Line 677 of lalr1.cc  */
#line 6248 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("no-preserve"); }
    break;

  case 835:

/* Line 677 of lalr1.cc  */
#line 6249 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("inherit"); }
    break;

  case 836:

/* Line 677 of lalr1.cc  */
#line 6250 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("no-inherit"); }
    break;

  case 837:

/* Line 677 of lalr1.cc  */
#line 6251 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("declare"); }
    break;

  case 838:

/* Line 677 of lalr1.cc  */
#line 6252 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("construction"); }
    break;

  case 839:

/* Line 677 of lalr1.cc  */
#line 6253 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ordering"); }
    break;

  case 840:

/* Line 677 of lalr1.cc  */
#line 6254 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("default"); }
    break;

  case 841:

/* Line 677 of lalr1.cc  */
#line 6255 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("copy-namespaces"); }
    break;

  case 842:

/* Line 677 of lalr1.cc  */
#line 6256 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("option"); }
    break;

  case 843:

/* Line 677 of lalr1.cc  */
#line 6257 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("version"); }
    break;

  case 844:

/* Line 677 of lalr1.cc  */
#line 6258 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("import"); }
    break;

  case 845:

/* Line 677 of lalr1.cc  */
#line 6259 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema"); }
    break;

  case 846:

/* Line 677 of lalr1.cc  */
#line 6260 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("module"); }
    break;

  case 847:

/* Line 677 of lalr1.cc  */
#line 6261 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("function"); }
    break;

  case 848:

/* Line 677 of lalr1.cc  */
#line 6262 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("score"); }
    break;

  case 849:

/* Line 677 of lalr1.cc  */
#line 6263 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("contains"); }
    break;

  case 850:

/* Line 677 of lalr1.cc  */
#line 6264 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("weight"); }
    break;

  case 851:

/* Line 677 of lalr1.cc  */
#line 6265 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("window"); }
    break;

  case 852:

/* Line 677 of lalr1.cc  */
#line 6266 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("distance"); }
    break;

  case 853:

/* Line 677 of lalr1.cc  */
#line 6267 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("occurs"); }
    break;

  case 854:

/* Line 677 of lalr1.cc  */
#line 6268 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("times"); }
    break;

  case 855:

/* Line 677 of lalr1.cc  */
#line 6269 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("same"); }
    break;

  case 856:

/* Line 677 of lalr1.cc  */
#line 6270 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("different"); }
    break;

  case 857:

/* Line 677 of lalr1.cc  */
#line 6271 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lowercase"); }
    break;

  case 858:

/* Line 677 of lalr1.cc  */
#line 6272 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("uppercase"); }
    break;

  case 859:

/* Line 677 of lalr1.cc  */
#line 6273 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("relationship"); }
    break;

  case 860:

/* Line 677 of lalr1.cc  */
#line 6274 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("levels"); }
    break;

  case 861:

/* Line 677 of lalr1.cc  */
#line 6275 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("language"); }
    break;

  case 862:

/* Line 677 of lalr1.cc  */
#line 6276 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("any"); }
    break;

  case 863:

/* Line 677 of lalr1.cc  */
#line 6277 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("all"); }
    break;

  case 864:

/* Line 677 of lalr1.cc  */
#line 6278 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("phrase"); }
    break;

  case 865:

/* Line 677 of lalr1.cc  */
#line 6279 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("exactly"); }
    break;

  case 866:

/* Line 677 of lalr1.cc  */
#line 6280 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("from"); }
    break;

  case 867:

/* Line 677 of lalr1.cc  */
#line 6281 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("words"); }
    break;

  case 868:

/* Line 677 of lalr1.cc  */
#line 6282 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sentences"); }
    break;

  case 869:

/* Line 677 of lalr1.cc  */
#line 6283 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sentence"); }
    break;

  case 870:

/* Line 677 of lalr1.cc  */
#line 6284 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("paragraph"); }
    break;

  case 871:

/* Line 677 of lalr1.cc  */
#line 6285 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("replace"); }
    break;

  case 872:

/* Line 677 of lalr1.cc  */
#line 6286 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("modify"); }
    break;

  case 873:

/* Line 677 of lalr1.cc  */
#line 6287 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("first"); }
    break;

  case 874:

/* Line 677 of lalr1.cc  */
#line 6288 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("insert"); }
    break;

  case 875:

/* Line 677 of lalr1.cc  */
#line 6289 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("before"); }
    break;

  case 876:

/* Line 677 of lalr1.cc  */
#line 6290 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("after"); }
    break;

  case 877:

/* Line 677 of lalr1.cc  */
#line 6291 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("revalidation"); }
    break;

  case 878:

/* Line 677 of lalr1.cc  */
#line 6292 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("with"); }
    break;

  case 879:

/* Line 677 of lalr1.cc  */
#line 6293 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("nodes"); }
    break;

  case 880:

/* Line 677 of lalr1.cc  */
#line 6294 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("rename"); }
    break;

  case 881:

/* Line 677 of lalr1.cc  */
#line 6295 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("last"); }
    break;

  case 882:

/* Line 677 of lalr1.cc  */
#line 6296 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("delete"); }
    break;

  case 883:

/* Line 677 of lalr1.cc  */
#line 6297 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("into"); }
    break;

  case 884:

/* Line 677 of lalr1.cc  */
#line 6298 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("simple"); }
    break;

  case 885:

/* Line 677 of lalr1.cc  */
#line 6299 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sequential"); }
    break;

  case 886:

/* Line 677 of lalr1.cc  */
#line 6300 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("updating"); }
    break;

  case 887:

/* Line 677 of lalr1.cc  */
#line 6301 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("deterministic"); }
    break;

  case 888:

/* Line 677 of lalr1.cc  */
#line 6302 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("nondeterministic"); }
    break;

  case 889:

/* Line 677 of lalr1.cc  */
#line 6303 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ordered"); }
    break;

  case 890:

/* Line 677 of lalr1.cc  */
#line 6304 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("unordered"); }
    break;

  case 891:

/* Line 677 of lalr1.cc  */
#line 6305 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("returning"); }
    break;

  case 892:

/* Line 677 of lalr1.cc  */
#line 6306 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("block"); }
    break;

  case 893:

/* Line 677 of lalr1.cc  */
#line 6307 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("exit"); }
    break;

  case 894:

/* Line 677 of lalr1.cc  */
#line 6308 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("loop"); }
    break;

  case 895:

/* Line 677 of lalr1.cc  */
#line 6309 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("while"); }
    break;

  case 896:

/* Line 677 of lalr1.cc  */
#line 6310 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("break"); }
    break;

  case 897:

/* Line 677 of lalr1.cc  */
#line 6311 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("continue"); }
    break;

  case 898:

/* Line 677 of lalr1.cc  */
#line 6312 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("try"); }
    break;

  case 899:

/* Line 677 of lalr1.cc  */
#line 6313 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("catch"); }
    break;

  case 900:

/* Line 677 of lalr1.cc  */
#line 6314 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("eval"); }
    break;

  case 901:

/* Line 677 of lalr1.cc  */
#line 6315 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("using"); }
    break;

  case 902:

/* Line 677 of lalr1.cc  */
#line 6316 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("set"); }
    break;

  case 903:

/* Line 677 of lalr1.cc  */
#line 6317 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("index"); }
    break;

  case 904:

/* Line 677 of lalr1.cc  */
#line 6318 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("unique"); }
    break;

  case 905:

/* Line 677 of lalr1.cc  */
#line 6319 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("non"); }
    break;

  case 906:

/* Line 677 of lalr1.cc  */
#line 6320 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("on"); }
    break;

  case 907:

/* Line 677 of lalr1.cc  */
#line 6321 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("range"); }
    break;

  case 908:

/* Line 677 of lalr1.cc  */
#line 6322 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("equality"); }
    break;

  case 909:

/* Line 677 of lalr1.cc  */
#line 6323 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("manually"); }
    break;

  case 910:

/* Line 677 of lalr1.cc  */
#line 6324 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("automatically"); }
    break;

  case 911:

/* Line 677 of lalr1.cc  */
#line 6325 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("maintained"); }
    break;

  case 912:

/* Line 677 of lalr1.cc  */
#line 6326 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("decimal-format"); }
    break;

  case 913:

/* Line 677 of lalr1.cc  */
#line 6327 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("decimal-separator"); }
    break;

  case 914:

/* Line 677 of lalr1.cc  */
#line 6328 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("grouping-separator"); }
    break;

  case 915:

/* Line 677 of lalr1.cc  */
#line 6329 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("infinity"); }
    break;

  case 916:

/* Line 677 of lalr1.cc  */
#line 6330 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("minus-sign"); }
    break;

  case 917:

/* Line 677 of lalr1.cc  */
#line 6331 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("NaN"); }
    break;

  case 918:

/* Line 677 of lalr1.cc  */
#line 6332 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("percent"); }
    break;

  case 919:

/* Line 677 of lalr1.cc  */
#line 6333 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("per-mille"); }
    break;

  case 920:

/* Line 677 of lalr1.cc  */
#line 6334 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("zero-digit"); }
    break;

  case 921:

/* Line 677 of lalr1.cc  */
#line 6335 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("digit"); }
    break;

  case 922:

/* Line 677 of lalr1.cc  */
#line 6336 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("pattern-separator"); }
    break;

  case 923:

/* Line 677 of lalr1.cc  */
#line 6337 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("collection"); }
    break;

  case 924:

/* Line 677 of lalr1.cc  */
#line 6338 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("const"); }
    break;

  case 925:

/* Line 677 of lalr1.cc  */
#line 6339 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("append-only"); }
    break;

  case 926:

/* Line 677 of lalr1.cc  */
#line 6340 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("queue"); }
    break;

  case 927:

/* Line 677 of lalr1.cc  */
#line 6341 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("mutable"); }
    break;

  case 928:

/* Line 677 of lalr1.cc  */
#line 6342 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("read-only"); }
    break;

  case 929:

/* Line 677 of lalr1.cc  */
#line 6343 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("integrity"); }
    break;

  case 930:

/* Line 677 of lalr1.cc  */
#line 6344 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("constraint"); }
    break;

  case 931:

/* Line 677 of lalr1.cc  */
#line 6345 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("check"); }
    break;

  case 932:

/* Line 677 of lalr1.cc  */
#line 6346 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("key"); }
    break;

  case 933:

/* Line 677 of lalr1.cc  */
#line 6347 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("foreach"); }
    break;

  case 934:

/* Line 677 of lalr1.cc  */
#line 6348 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("foreign"); }
    break;

  case 935:

/* Line 677 of lalr1.cc  */
#line 6349 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("keys"); }
    break;

  case 936:

/* Line 677 of lalr1.cc  */
#line 6350 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ancestor"); }
    break;

  case 937:

/* Line 677 of lalr1.cc  */
#line 6351 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("child"); }
    break;

  case 938:

/* Line 677 of lalr1.cc  */
#line 6352 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("descendant"); }
    break;

  case 939:

/* Line 677 of lalr1.cc  */
#line 6353 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("parent"); }
    break;

  case 940:

/* Line 677 of lalr1.cc  */
#line 6354 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("preceding"); }
    break;

  case 941:

/* Line 677 of lalr1.cc  */
#line 6355 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("self"); }
    break;

  case 942:

/* Line 677 of lalr1.cc  */
#line 6356 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("following"); }
    break;

  case 943:

/* Line 677 of lalr1.cc  */
#line 6357 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ancestor-or-self"); }
    break;

  case 944:

/* Line 677 of lalr1.cc  */
#line 6358 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("descendant-or-self"); }
    break;

  case 945:

/* Line 677 of lalr1.cc  */
#line 6359 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("following-sibling"); }
    break;

  case 946:

/* Line 677 of lalr1.cc  */
#line 6360 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("preceding-sibling"); }
    break;



/* Line 677 of lalr1.cc  */
#line 11397 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1330;
  const short int
  xquery_parser::yypact_[] =
  {
      1573, -1330, -1330, -1330, -1330, -1330,   865,    -2, -1330, -1330,
     384, -1330, -1330, -1330, -1330,   -34,    50,  9423,    74,   271,
      98,   154,    93, -1330,   223, -1330, -1330, -1330, -1330, -1330,
   -1330,   329, -1330,  7709, -1330,   216,   268, -1330,   313, -1330,
   -1330,   350, -1330,   439, -1330,   393,   429, -1330,   202, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330,   387,   503, -1330, -1330, -1330, -1330,  8855,  7129,
   -1330, -1330, -1330,   520, -1330, -1330, -1330, -1330, -1330,   547,
     552, -1330, -1330, 11127, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330,   564, -1330, -1330,   565,   566, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330,  2165, 11127, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330,   536, -1330, -1330,   568,  8285, -1330,  8571,
     569,   571, -1330, -1330, -1330,   574, -1330,  6837, -1330, -1330,
   -1330, -1330, -1330, -1330,   544, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330,    21,   -77, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330,   404,   542,   407, -1330,   475,   144, -1330,
   -1330, -1330, -1330, -1330, -1330,   581, -1330,   550,   464,   479,
     465, -1330, -1330,   567,   572, -1330,   602, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330,  1873,   719, -1330,
     718,  5085, -1330, -1330,   403,  5377,   541,   543, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,   -13,
   -1330, -1330, -1330, -1330,    29, 11127, -1330, -1330, -1330, -1330,
   -1330, -1330,   570,   637, -1330,   456,   484,   188,   229,   218,
     433, -1330,   683,   538,   633,   638,  5669, -1330, -1330, -1330,
     190, -1330, -1330,  6837, -1330,   385, -1330,   586,  7129, -1330,
     586,  7129, -1330, -1330, -1330,   481, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,   434,
   -1330,   714,   349,   377,   -35,   504, 11127,   504, 11127,   -53,
     695,   696,   697, 11127,   594,   628,   334,  8285, -1330, -1330,
     419,   301,   505, 11127, -1330, -1330, -1330, -1330, -1330,   457,
   11127,   451,   454,   321,   449,   266, -1330, -1330, -1330, -1330,
   -1330,  8285,  5377,   573,  5377,    83, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330,  5377,  9707, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,   601,
    5377,   471,   473, -1330,   639,   -19,   603,  5377,    55,    45,
   11127,   641, -1330,  5377,  7997,   608, -1330, 11127, 11127, 11127,
   11127,  5377,   576,  5377,  5377, 11127,  5377,   611,   612, -1330,
   -1330, -1330,  5377,  9991,   614,   613,   615,   619,   620,   621,
   -1330, -1330, -1330, -1330, -1330, -1330, 11127, -1330, -1330, -1330,
     582,   735,  5377, -1330,    51, -1330,   755, -1330, -1330, -1330,
   -1330,  5377,   575, -1330,   751,  5377,  5377,   596,  5377,  5377,
    5377,  5377,   553, 11127, -1330, -1330, -1330, -1330,  5377,  5377,
    5377, 11127, -1330,   718, -1330, -1330, -1330, -1330,   865,    93,
   -1330, -1330,   403,   747,  5377, -1330,  5377,   665,   271,   223,
     329,   617,   618,   622,  5377,  5377, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330,   681, -1330,   -43,  5961,  5961,  5961, -1330,
    5961,  5961, -1330,  5961, -1330,  5961, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330,  5961,  5961,   717,  5961,  5961,  5961,  5961,
    5961,  5961,  5961,  5961,  5961,  5961,  5961,   561,   698,   699,
     700, -1330, -1330, -1330,  2457, -1330, -1330,  6837,  6837,  5377,
     586, -1330, -1330,   586, -1330,  2749,   586,   644,  3041, -1330,
   -1330, -1330, -1330, -1330, -1330,   690,   692, -1330,    98, -1330,
     773, -1330, -1330, 11127, -1330, 11127,   627,   300, 11127,   440,
     642,   643,   627,   714,   677,   673, -1330, -1330, -1330, -1330,
   -1330,   -11,   560,   -33, -1330,   508, -1330, -1330, -1330, -1330,
   11127, 11127, 11127, -1330,   676,   626, -1330,   631,   615,   268,
   -1330,   632,   634,   636, -1330,   -14,    -1,  3333,   640, -1330,
   -1330, 11127,   -12, 11127,   721,    46, -1330,  5377, -1330,   635,
    8285,   724,   779,  8285,   714,   727,   720, -1330,   -24, -1330,
     646,   645, -1330,   647,  3625,   648,   649,   684,   -26, -1330,
      18,   653, -1330,   651,   652,   674, -1330,   657,  5377,  5377,
     658, -1330,    66,   155,  3917,     1, -1330, 11127,   735, -1330,
     157,   659, -1330, -1330, -1330,   660, -1330,   169, -1330, -1330,
   -1330,    61,    90,   734,   610,   623,   -23, -1330,   702,  6253,
   -1330,   662,   667,    94, -1330, -1330, -1330,   666, -1330,  1019,
   -1330, -1330,    -9, 11127,   686,  5377,   713, -1330, -1330,   738,
   10559,   739,  5377,   741,   -55,   707,   -42,   637, -1330, -1330,
   -1330, -1330, -1330,  5961, -1330, -1330, -1330,    15,   229,   229,
     289,   218,   218,   218,   218,   433,   433, -1330, -1330, 10559,
   10559, 11127, 11127, -1330,   679, -1330, -1330,   680, -1330, -1330,
   -1330,   175, -1330, -1330,   184,   356,   364,   324, -1330,    98,
      98, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330,   627, -1330,   731, 10843,   723,  5377, -1330, -1330, -1330,
     770,   725,  5377,   714,   714,   627, -1330,   519,   714,   337,
   11127,    70,   317,   841, -1330, -1330,   584,   273, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,   -11,
      79,   372, -1330,   650,   192,   -28,   578,   714, -1330, -1330,
   -1330, -1330,   722, 11127, -1330, 11127, -1330, -1330,   688, -1330,
     217,   624, -1330, -1330,   346,   -12,   770, 10559,   753,   777,
     691,   693,   750,   714,   732,   761,   797,   714,   778,  5377,
     758,   -36,   756, -1330, -1330, -1330,   728, -1330, -1330,  5377,
     787,  5377,  5377,   763, -1330,   811,   813,  5377, -1330,   733,
     736,   762, 11127, -1330, 11127, -1330, -1330,   737,  5377,   882,
   -1330,   197, -1330,    71, -1330, -1330,   890, -1330,   412,  5377,
    5377,  5377,   421,  5377,  5377,  5377,  5377,  5377,  5377,   803,
    5377,  5377,   628,    -6,   742,   550,   687,   775,   807,   747,
     853, -1330, -1330,  5377,   467,   827, -1330, 11127,   829, -1330,
   11127,   782,   783, 10843,   784, -1330,   352, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, 11127, -1330, 11127,  5377,   794,  5377,
    5377,   -54,   800, -1330,  5377,    15,   307,   228, -1330,   663,
      44,   694,   689, -1330, -1330,   505, -1330,   701,  -115, -1330,
   -1330, -1330,   806, -1330, -1330, -1330,  5377, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330,  5377, -1330,   360,   362, -1330,   916,
     466, -1330, -1330, -1330,  5377, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330,   668, -1330, -1330,   925, -1330, -1330, -1330, -1330,
   -1330,   314,   927, -1330,   424, -1330, -1330, -1330,   613,    50,
     619,   216,   620,   621,   542,   729,   352,   743,   744,  6545,
     670,   654,    79, -1330,   745,   769,  4209,   781,   786,   815,
     789,   790, -1330,  5377,   814, -1330,   844,   845,  5377, 11127,
      84,   894, -1330, -1330, -1330, -1330, -1330, -1330, 10559, -1330,
    5377,   714,   872, -1330, -1330, -1330,   714,   872, 11127, -1330,
    5377,  5377,   839,  4501, -1330, -1330, 11127, -1330, -1330,  5377,
    5377,   432, -1330,    -4, 10275,   472, -1330,   799, -1330, -1330,
    4793,   798,   801, -1330, -1330, -1330,   851, -1330,   118, -1330,
   -1330,   971, -1330, -1330, 11127, -1330, -1330,   315, -1330, -1330,
   -1330,   804,   754,   757, -1330, -1330, -1330,   760,   764, -1330,
   -1330, -1330, -1330, -1330,   759, 11127,   805, -1330,   855, -1330,
     628, -1330, -1330, -1330,  7421,   687, -1330,  5377, 11127,   827,
   -1330,   714, -1330,   537, -1330,    23,   891, -1330,  5377,   892,
     713, -1330,  9139,   816,   817,   818, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330,  5377, -1330, -1330,  5377,   854,  5377,   823,
     822, -1330,    15,   766, -1330, -1330,   123, -1330,   325,     5,
     767,    15,   325,  5961, -1330,    65, -1330, -1330, -1330, -1330,
   -1330, -1330,    15,   862,   730,   560,     5, -1330, -1330,   740,
     920, -1330, -1330, -1330, -1330, -1330,   828, -1330, -1330, -1330,
    5377, -1330, -1330, -1330, -1330, -1330,   982,     0,   985,     0,
     748,   922, -1330, -1330, -1330, -1330,   852, 11127,   772,   729,
    6545, -1330, -1330,   831, -1330, -1330, -1330, -1330, -1330, -1330,
    5377, 11127, 11127, -1330,   359, -1330,  5377, -1330,   895,   926,
     714,   872, -1330, -1330, -1330,  5377, -1330,   847, -1330, -1330,
   -1330,   842, -1330,  5377,  5377, 11127,   846,    10, -1330, -1330,
   -1330,   849, -1330, -1330,   882, 11127,   394, -1330,   882, 11127,
   -1330, -1330,  5377,  5377,  5377,  5377,  5377, -1330,  5377,  5377,
   -1330, -1330,   201, -1330,   850, -1330, -1330, -1330, -1330,   891,
   -1330, -1330, -1330,   714, -1330, -1330,   939,   856, -1330,   207,
   -1330, -1330, -1330, -1330, -1330,  5377, -1330, -1330, -1330, -1330,
     858,  5961, -1330, -1330, -1330, -1330, -1330,    31,  5961,  5961,
     249, -1330,   694, -1330,     4, -1330,   689,    15,   883, -1330,
   -1330,   765, -1330, -1330, -1330, -1330, -1330,     7, -1330,    14,
      14, -1330,     0, -1330, -1330,   211, -1330,  1009,     5,   857,
     930, -1330,  6545,   -71,   752, -1330,   874, -1330, -1330, -1330,
     992, -1330, -1330,  5377,   714, -1330, -1330, -1330,  5377, -1330,
   -1330,   951,  5377, 11127,  5377, -1330,   -16,   882, 11127,   859,
     882, -1330, -1330, -1330, -1330, -1330, -1330, -1330,   929,  7421,
   -1330, -1330, -1330, -1330, 10559, -1330, 10559,   953, -1330, -1330,
     218,  5961,  5961,   289,   353, -1330, -1330, -1330, -1330, -1330,
   -1330,  5377, -1330, -1330, -1330, -1330, -1330,  1024, -1330, -1330,
   -1330,   788, -1330,   922,   948, -1330,   482, 11127,   938,   834,
   11127,  6545,   943, -1330,   872, -1330, 10559, -1330,   878, -1330,
      59,    64, -1330,   869,   882, -1330,   871, 11127, -1330, -1330,
   -1330, 10559,   289,   289,  5961,   885, -1330, -1330, -1330,  6545,
   -1330,   891,   768, 11127,   950,   864,   948, 11127,   886,  5377,
   -1330, -1330,   975,   161, -1330, -1330, -1330, -1330,   896,   367,
   -1330, -1330, -1330,   879, -1330,   213, -1330,   289, -1330, -1330,
   -1330,  5377,   771, 11127,   960, -1330,  5377, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330,   961,   928, -1330,   793,   785,
   11127, -1330, 11127, -1330,   776,  5377,   791,   215,  6545, -1330,
    6545,   964,   928, -1330,   898, 11127, -1330,   802,   905, 11127,
     928,   868, -1330,   974, 11127,   792,  6545, -1330
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,     8,   418,   419,   731,   572,   837,   846,   751,   749,
     736,   838,   841,   794,   887,   755,   737,   738,   900,   786,
     847,   740,   844,   816,   796,   771,   791,   888,   792,   842,
     839,   787,   790,   742,   845,   743,   744,   885,   902,   884,
     788,   807,   801,   745,   789,   747,   746,   886,   825,   793,
     768,   912,   913,   914,   915,   916,   917,   918,   919,   920,
     921,   922,   936,   943,   815,   811,   802,   782,   735,     0,
     810,   818,   826,   937,   806,   438,   783,   784,   840,   938,
     944,   803,   820,     0,   444,   407,   440,   813,   734,   804,
     805,   833,   808,   824,   832,   942,   945,   754,   795,   835,
     439,   823,   828,   739,     0,     0,   356,   821,   831,   836,
     834,   814,   800,   889,   798,   799,   939,     0,   355,     0,
     940,   946,   829,   785,   809,   941,   385,     0,   417,   830,
     812,   819,   827,   822,   890,   776,   781,   780,   779,   778,
     777,   748,   797,     0,   733,   843,   769,   876,   875,   877,
     753,   752,   772,   882,   741,   874,   879,   880,   871,   775,
     817,   873,   883,   881,   872,   773,   878,   892,   896,   897,
     893,   894,   891,   895,   898,   899,   901,   863,   862,   849,
     767,   760,   856,   852,   770,   766,   865,   866,   756,   757,
     750,   759,   861,   860,   857,   853,   870,   864,   859,   855,
     848,   758,   869,   868,   762,   764,   763,   854,   858,   850,
     765,   851,   761,   867,   923,   924,   925,   926,   927,   928,
     904,   905,   903,   909,   910,   911,   906,   907,   908,   774,
     929,   930,   931,   932,   933,   934,   935,     0,     0,     4,
       2,     0,     9,    11,    17,     0,     0,     0,    23,    25,
      34,    27,    28,    29,    55,    30,    39,    35,    59,    60,
      61,    56,    57,    63,    64,    33,    31,    32,    37,    38,
      58,   208,   207,   204,   205,   206,    36,    16,   184,   185,
     189,   191,   223,   229,     0,     0,   221,   222,   192,   193,
     194,   195,   196,   311,   313,   315,   325,   329,   331,   334,
     339,   342,   345,   347,   349,   351,     0,   353,   359,   361,
       0,   377,   360,   381,   384,   386,   389,   391,     0,   396,
     393,     0,   404,   414,   416,   390,   420,   427,   436,   428,
     429,   430,   433,   434,   431,   432,   451,   453,   454,   455,
     452,   500,   501,   502,   503,   504,   505,   413,   546,   538,
     545,   544,   543,   540,   542,   539,   541,   437,   435,   573,
     574,    62,   197,   198,   200,   199,   201,   202,   203,   415,
     732,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   112,   113,
       0,     0,     0,     0,   108,   109,   110,   111,   118,     0,
       0,     0,     0,     0,     0,     0,   106,   165,   168,   171,
     170,     0,     0,     0,     0,     0,   837,   846,   736,   755,
     737,   738,   900,   786,   847,   740,   844,   796,   787,   742,
     743,   744,   902,   807,   745,   747,   746,   825,   936,   943,
     735,   937,   938,   944,   808,   942,   945,     0,     0,   889,
     939,   940,   946,   941,   890,   733,   882,   741,   874,   880,
     871,   773,   892,   896,   897,   893,   895,   898,   901,     0,
       0,     0,     0,   231,     0,     0,     0,     0,     0,     0,
       0,     0,   615,     0,     0,     0,   616,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   409,
     412,   399,     0,     0,     0,   736,   738,   742,   745,   735,
     405,   415,   397,   398,   401,   441,     0,   403,   402,   442,
       0,   467,     0,   408,     0,   380,     0,   411,   410,   400,
     383,     0,     0,   496,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   155,   152,   163,   164,     0,     0,
       0,     0,     6,     3,     1,     5,    10,    12,     0,     0,
      18,    15,    20,    21,     0,   187,   186,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   209,   228,   224,   230,
     225,   227,   226,   233,   234,     0,     0,     0,     0,   370,
       0,     0,   368,     0,   320,     0,   369,   362,   367,   366,
     365,   364,   363,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   358,   357,   354,     0,   378,   382,     0,     0,     0,
     392,   424,   395,   394,   406,     0,   421,     0,     0,   614,
      81,    66,    67,   146,   147,     0,     0,   167,     0,   166,
       0,    72,    73,     0,   169,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   583,   584,   585,   115,
     114,     0,    71,   122,   119,     0,   121,   120,   117,   116,
       0,     0,     0,   107,     0,     0,   552,     0,     0,     0,
     548,     0,     0,     0,   562,     0,     0,     0,     0,   211,
     212,     0,     0,     0,   148,     0,   178,     0,   576,     0,
       0,    90,     0,     0,     0,    82,   246,   247,     0,   232,
       0,     0,   553,     0,     0,     0,     0,     0,     0,   294,
       0,     0,   551,     0,     0,     0,   570,     0,     0,     0,
       0,   556,     0,     0,     0,     0,   443,   468,   467,   464,
       0,     0,   498,   497,   379,     0,   495,     0,   596,   597,
     547,     0,     0,     0,     0,     0,     0,   602,     0,     0,
     161,     0,     0,     0,   249,   266,     7,     0,    24,     0,
      26,   190,     0,     0,     0,     0,     0,   210,   267,     0,
       0,     0,     0,     0,     0,     0,     0,   312,   314,   318,
     324,   323,   322,     0,   319,   316,   317,     0,   333,   332,
     330,   336,   337,   338,   335,   340,   341,   344,   343,     0,
       0,     0,     0,   375,     0,   387,   388,     0,   425,   422,
     449,     0,   575,   447,     0,     0,     0,     0,    70,     0,
       0,    45,    47,    48,    49,    50,    52,    53,    54,    46,
      51,    41,    42,     0,     0,    98,     0,    94,    96,    97,
     101,   104,     0,     0,     0,    40,    80,     0,     0,     0,
       0,     0,     0,     0,   681,   686,     0,     0,   682,   716,
     669,   671,   672,   673,   675,   677,   676,   674,   678,     0,
       0,     0,   123,     0,     0,   126,     0,     0,   516,   506,
     549,   550,     0,     0,   566,     0,   563,   507,     0,   618,
       0,     0,   213,   214,     0,   219,   180,     0,     0,   149,
       0,     0,     0,     0,     0,     0,    83,     0,     0,     0,
       0,     0,     0,   555,   554,   517,     0,   561,   569,     0,
       0,     0,     0,     0,   515,     0,     0,     0,   371,     0,
       0,     0,     0,   559,     0,   557,   511,     0,     0,   467,
     465,     0,   456,     0,   445,   446,     0,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   837,     0,     0,     0,     0,     0,     0,    22,
       0,   188,   220,     0,   278,   274,   276,     0,   268,   269,
       0,   847,   739,     0,   748,   523,   524,   530,   531,   533,
     577,   578,   534,   537,     0,   236,     0,     0,     0,     0,
       0,     0,     0,   321,     0,     0,     0,     0,   647,   327,
     620,   624,   626,   628,   630,   633,   640,   641,   649,   346,
     348,   350,   521,   352,   376,   426,     0,   423,   448,    78,
      79,    76,    77,   173,     0,   172,     0,     0,    43,     0,
       0,    99,   100,   102,     0,   103,    68,    69,    74,    75,
      65,   687,     0,   690,   717,     0,   680,   679,   684,   683,
     715,     0,     0,   692,     0,   688,   691,   670,     0,     0,
       0,     0,     0,     0,     0,   124,   130,     0,     0,     0,
       0,     0,     0,   127,     0,     0,     0,     0,     0,   570,
       0,     0,   508,     0,     0,   215,     0,     0,     0,     0,
     260,     0,   257,   262,   218,   181,   150,   179,     0,   182,
       0,     0,    92,    86,    89,    88,     0,    84,     0,   251,
       0,     0,     0,     0,   518,   160,     0,   292,   296,     0,
       0,     0,   299,     0,     0,     0,   306,     0,   373,   372,
       0,     0,     0,   512,   293,   468,     0,   457,     0,   491,
     488,     0,   492,   493,     0,   494,   487,     0,   462,   490,
     489,     0,     0,     0,   589,   590,   586,     0,     0,   594,
     595,   591,   600,   598,     0,     0,     0,   604,   158,   157,
       0,   154,   153,   162,     0,   605,   606,     0,     0,   275,
     287,     0,   288,     0,   279,   280,   281,   282,     0,   271,
       0,   235,     0,     0,     0,     0,   527,   529,   528,   525,
     244,   245,   238,     0,   240,   237,     0,     0,     0,     0,
       0,   631,   644,     0,   326,   328,     0,   663,     0,     0,
       0,     0,     0,     0,   619,   621,   622,   658,   659,   660,
     662,   661,     0,     0,   635,   634,     0,   638,   642,   656,
     654,   653,   646,   650,   522,   450,     0,   175,   174,   177,
       0,    44,    95,   105,   704,   685,     0,   709,     0,   709,
     698,   693,   125,   131,   133,   132,     0,     0,     0,   128,
       0,    19,   509,     0,   567,   568,   571,   564,   565,   255,
       0,     0,     0,   217,   258,   261,     0,   151,     0,    91,
       0,    85,   248,   253,   252,     0,   519,     0,   295,   297,
     302,     0,   300,     0,     0,     0,     0,     0,   307,   374,
     513,     0,   560,   558,   467,     0,     0,   499,   467,     0,
     463,    14,     0,     0,     0,     0,     0,   603,     0,     0,
     156,   612,     0,   607,     0,   250,   291,   289,   290,   283,
     284,   285,   277,     0,   272,   270,     0,     0,   535,     0,
     532,   582,   526,   242,   239,     0,   241,   648,   639,   645,
       0,     0,   718,   719,   729,   728,   727,     0,     0,     0,
       0,   720,   625,   726,     0,   623,   627,     0,     0,   632,
     636,     0,   657,   652,   655,   651,   183,     0,   705,     0,
       0,   703,   710,   711,   707,     0,   702,     0,   700,     0,
     694,   695,     0,     0,     0,   129,     0,   510,   256,   264,
     265,   259,   216,     0,     0,    87,   254,   520,     0,   303,
     301,     0,     0,     0,     0,   514,     0,   467,     0,     0,
     467,   587,   588,   592,   593,   599,   601,   159,     0,     0,
     608,   617,   286,   273,     0,   579,     0,     0,   243,   643,
     730,     0,     0,   722,     0,   668,   667,   666,   665,   664,
     629,     0,   721,   176,   714,   713,   712,     0,   706,   699,
     697,     0,   689,     0,   134,   136,   138,     0,     0,     0,
       0,     0,     0,   310,    93,   298,     0,   308,     0,   304,
     477,   471,   466,     0,   467,   458,     0,     0,   613,   580,
     536,     0,   724,   723,     0,     0,   708,   701,   696,     0,
     140,   139,     0,     0,     0,     0,   135,     0,     0,     0,
     485,   479,     0,   478,   480,   486,   483,   473,     0,   472,
     474,   484,   460,     0,   459,     0,   581,   725,   637,   137,
     141,     0,     0,     0,     0,   263,     0,   305,   470,   481,
     482,   469,   475,   476,   461,     0,     0,   142,     0,     0,
       0,   309,     0,   609,     0,     0,     0,     0,     0,   144,
       0,     0,     0,   143,     0,     0,   610,     0,     0,     0,
       0,     0,   611,     0,     0,     0,     0,   145
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1330, -1330,  -211,   860, -1330,   863,   866, -1330,   861, -1330,
     529,   531,  -545, -1330,   436,  -370, -1330, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
    -921, -1330, -1330, -1330, -1330,    34,   240,   711, -1330, -1330,
     703, -1330,    -3,  -874, -1330,  -411,  -438, -1330, -1330,  -602,
   -1330,  -895, -1330, -1330,   -97, -1330, -1330, -1330, -1330, -1330,
     270,   746, -1330, -1330, -1330,   194,   630, -1329,   870,   -96,
   -1330,  -562,   -98, -1330, -1330, -1330, -1330,   195, -1330, -1330,
     830, -1330, -1330, -1330, -1330, -1330,   113,  -544,  -691, -1330,
   -1330, -1330,   -22, -1330, -1330,  -197,     2,   -89, -1330, -1330,
   -1330,   -92, -1330, -1330,   133,   -88, -1330, -1330,   -84, -1184,
   -1330,   616,   -10, -1330, -1330,   -18, -1330, -1330, -1330,   -21,
   -1330, -1330,   555,   556, -1330,  -534, -1330, -1330,  -591,    53,
    -600,    54,    56, -1330, -1330, -1330, -1330, -1330,   833, -1330,
   -1330, -1330, -1330,  -783,  -307, -1092, -1330,  -112, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330,   -41, -1182, -1330, -1330,   284,
     -15, -1330,  -777, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
     511, -1330,  -938, -1330,    -7, -1330,   408,  -746, -1330, -1330,
   -1330, -1330, -1330,  -417,  -398, -1128,  -963, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330,   336,  -717,  -800,
      67,  -801, -1330,  -152,  -776, -1330, -1330, -1330, -1330, -1330,
   -1330, -1330,   749,   774,  -609,   257,   106, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
   -1330,   -29, -1330, -1330,   -38, -1330,  -366,   -94, -1330,  -991,
   -1330, -1330, -1330,   -83,   -93,  -237,   145, -1330, -1330, -1330,
   -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330, -1330,
     -82, -1330, -1330, -1330,  -232,   139,   286, -1330, -1330, -1330,
   -1330, -1330,    92, -1330, -1330, -1253, -1330, -1330, -1330,  -742,
   -1330,  -110, -1330,  -245, -1330, -1330, -1330, -1330, -1216, -1330,
     -70, -1330,   -17, -1330
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   851,   852,   853,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
    1132,   714,   264,   265,   857,   858,   859,  1198,   266,   405,
     406,   267,  1095,   892,   268,  1504,  1505,   269,   270,   476,
     271,   545,   769,   983,  1199,   272,   273,   274,   275,   276,
     407,   408,   409,   410,   705,   706,  1175,  1055,   277,   278,
     566,   279,   280,   281,   576,   474,   914,   915,   282,   577,
     283,   579,   284,   285,   286,   583,   584,  1120,   795,   287,
     716,   773,   717,   702,  1121,  1122,  1123,   774,   580,   581,
     998,   999,  1374,   582,   995,   996,  1214,  1215,  1216,  1217,
     288,   728,   729,   289,  1151,  1152,  1153,   290,  1155,  1156,
     291,   292,   293,   294,   803,   295,  1244,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   603,
     604,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   630,
     631,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     831,   335,   336,   337,  1177,   748,   749,   750,  1522,  1558,
    1559,  1552,  1553,  1560,  1554,  1178,  1179,   338,   339,  1180,
     340,   341,   342,   343,   344,   345,   346,  1041,   796,  1005,
    1229,  1006,  1379,  1007,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   735,  1108,   357,   358,   359,   360,
    1009,  1010,  1011,  1012,   361,   362,   363,   364,   365,   366,
     766,   767,   367,  1205,  1206,  1362,  1133,   485,   368,  1029,
    1254,  1255,  1030,  1031,  1032,  1033,  1034,  1264,  1409,  1410,
    1035,  1267,  1036,  1390,  1037,  1038,  1272,  1273,  1415,  1413,
    1256,  1257,  1258,  1259,  1488,   672,   880,   881,   882,   883,
     884,   885,  1085,  1429,  1430,  1086,  1428,  1500,   886,  1289,
    1425,  1421,  1422,  1423,   887,   888,  1260,  1268,  1400,  1261,
    1396,  1245,   369,   370
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       469,   931,   961,   625,   782,   640,  1137,  1296,   520,   811,
     812,   813,   814,   943,  1008,   530,   486,   810,   780,  1039,
    1040,  1103,  1361,   524,  1027,  1176,   552,   930,   510,   555,
    1028,  1370,  1371,  1470,  1240,     5,   869,   911,  1431,   870,
    1507,   794,   532,  1008,  1008,   790,   837,   791,   791,  1350,
    1411,   504,   511,  1060,   799,   890,   800,   801,   752,   802,
    1102,   804,   567,  1550,   790,   639,   515,  1169,   568,   805,
     806,  1520,  1169,   569,   940,   639,  1481,   979,  1008,  1169,
    1170,   570,   871,  1556,  1017,  1236,   903,   564,   521,  1333,
    1203,   564,   703,   571,  1200,  1397,   792,  1020,  1141,   905,
     486,   940,   526,  1018,  1286,  1022,   790,   564,   651,  1088,
     929,   414,   711,   715,  1096,  1089,   688,  1126,    75,   478,
     688,  1453,  1211,   645,  1269,  1270,  1169,  1170,  1419,   534,
    1116,    86,   987,  1090,  1246,  1091,   689,  1117,   646,   652,
     689,  1008,  1213,  1063,  1092,  1508,   918,  1271,   479,   968,
     411,   712,  1482,   941,   606,  1246,   100,   942,  1521,   704,
    1024,  1278,  1288,  1025,   904,  1550,   952,  1171,   565,  1169,
    1093,   607,   991,  1334,  1172,  1201,  1173,   906,   972,  1172,
     958,  1173,  1493,   119,  1551,  1472,  1172,  1454,  1173,   572,
    1557,  1420,   573,  1114,   988,   891,   912,   713,   415,  1125,
     891,   626,  1224,   980,   707,  1247,   574,   710,  1436,   707,
     793,   793,  1501,  1166,  1171,  1321,   707,   753,  1350,   470,
     105,  1292,   793,   793,   919,   533,  1247,  1008,  1509,   793,
    1176,   575,   872,  1172,   913,  1173,   117,  1056,  1057,  1176,
    1142,   793,  1027,  1027,   953,   873,   475,   874,  1028,  1028,
    1538,  1389,  1021,  1398,  1399,   954,  1174,  1593,   875,   876,
     877,   690,   878,   707,   879,  1485,  1026,   105,   585,  1023,
     969,   970,  1486,  1606,   143,  1046,  1172,   632,  1173,   962,
     634,  1612,  1487,   117,  1046,   971,  1579,  1528,  1248,  1249,
     495,  1250,   966,   665,  1107,  1094,  1110,   866,  1251,   973,
     974,   511,   477,  1345,   511,   790,   707,  1476,  1252,  1248,
    1249,  1497,  1250,  1585,   975,  1601,   685,   684,   687,  1167,
    1253,   143,  1540,  1169,  1170,  1076,  1096,     5,  1317,  1252,
    1237,  1392,   471,   955,   480,   624,  1077,   472,   606,   609,
    1506,  1253,   776,  1161,   963,  1162,  1054,   496,   926,  1468,
     967,   693,  1008,  1047,  1336,   607,  1113,  1570,   119,   648,
     541,   650,  1048,  1082,   487,   542,   656,   610,   481,  1393,
     486,   660,   698,  1242,   661,  1169,   673,   608,  1008,  1083,
     611,   709,   473,   675,  1168,  1477,  1556,   720,   854,  1498,
     723,  1586,  1116,  1602,   486,   731,   119,   733,   734,  1117,
     737,  1469,  1169,  1170,  1286,  1116,   740,   662,  1176,   613,
      75,  1171,  1117,   612,   497,   498,   488,  1118,   614,  1506,
    1287,  1084,  1378,    86,   489,  1435,   751,   388,   558,   855,
    1172,   696,  1173,   663,   856,   755,   791,   758,   759,   606,
     761,   762,   763,   764,   780,   559,  1008,  1506,   100,   791,
     770,   771,  1024,  1053,   772,  1025,   607,  1119,   389,  1027,
     707,   490,  1288,   718,   105,  1028,   781,   486,  1027,  1054,
     725,   726,   727,   730,  1028,   119,   787,   788,   736,  1027,
     117,  1058,  1172,  1100,  1173,  1028,   743,   391,  1226,  1277,
    1171,  1279,  1101,  1582,   664,  1058,  1049,  1066,  1067,   730,
    1349,   499,  1070,   606,  1051,   544,  1603,  1280,  1604,  1172,
    1485,  1173,   707,  1050,  1082,   825,   826,  1486,   143,  1227,
     607,  1052,   641,  1514,  1617,  1150,   768,  1487,   824,   412,
    1083,  1105,   413,   827,   775,   642,  1228,   830,  1331,   707,
     830,   493,  1534,   105,   376,   681,   394,   395,   396,   397,
     643,   398,   399,   682,   401,   402,  1210,  1555,  1561,   117,
     403,   615,   380,   644,   381,  1154,  1211,   627,   628,   861,
     790,   637,  1078,   382,   862,   616,  1212,   494,  1337,  1458,
     588,  1211,   638,  1079,   491,  1394,  1213,   492,   589,   590,
    1555,   591,  1395,   669,   670,   855,  1561,   143,  1456,   592,
     856,   908,  1459,   593,   633,   594,  1071,  1072,  1073,   636,
     595,   920,  1074,   678,   679,   828,   922,   500,   828,   925,
     535,   828,   536,   538,  1027,   539,   596,   629,   936,   635,
    1028,   666,   667,   668,   512,  1182,   839,  1183,   840,  1068,
    1069,   860,   949,   950,  1187,   647,  1188,   649,   957,   597,
     598,   599,   600,   601,   602,  1097,  1098,  1367,  1368,   808,
     809,   513,  1404,   894,   895,   896,   514,   815,   816,  1042,
    1042,   817,   818,   984,  1529,   516,  1530,  1494,  1495,   517,
     518,   522,   523,   527,   910,   528,   916,   994,   529,   531,
     537,   540,   543,   486,  1015,   544,   486,   546,  1008,   548,
    1008,   841,   842,   843,   844,   845,   846,   847,   848,   849,
     850,  1523,   547,   551,  1526,   549,  1548,   550,  1417,   554,
     625,     1,   562,   587,   563,   605,   617,   619,   618,   586,
     959,  1566,   629,   620,   639,   653,   376,   655,   657,   658,
    1008,   676,   674,   671,   677,   680,   697,   699,   707,   700,
     701,   686,   719,   724,   732,  1008,   738,   739,  1062,   744,
     746,   413,   747,   448,  1065,  1319,   992,   484,   492,   503,
     754,   757,   779,  1013,   760,   765,   783,   784,  1563,   756,
     785,   789,   807,   819,   786,   832,   820,   821,   822,  1541,
     835,  1480,   836,   838,   863,   864,   867,   868,   889,   893,
     897,   898,  1013,  1013,  1013,  1013,   899,  1483,  1484,   917,
     900,   902,   901,   921,   923,   909,   924,   927,   939,   947,
     928,   932,   976,   933,   997,   934,   937,   938,   944,   945,
     946,  1139,   948,   951,   964,   965,   981,  1013,   977,   978,
     985,  1145,   986,  1147,  1148,  1366,  1019,   989,   993,  1000,
    1014,  1157,  1016,  1075,  1044,  1059,  1045,   856,   790,  1064,
    1164,  1080,  1081,  1112,   703,  1128,  1129,  1106,  1099,  1104,
    1115,  1184,  1185,  1186,  1131,  1189,  1190,  1191,  1192,  1193,
    1194,  1130,  1196,  1197,  1134,  1135,  1109,  1136,  1109,  1138,
    1532,  1533,  1140,   371,   372,   994,   373,   374,  1146,   375,
    1013,  1143,  1149,  1144,  1150,   376,  1154,  1160,  1158,  1165,
    1181,  1159,  1163,   377,  1195,   378,   379,  1202,  1208,  1232,
    1207,  1234,  1235,   380,  1204,   381,   662,  1218,  1239,  1220,
    1222,  1223,  1225,  1233,   382,   736,     5,   736,   383,  1238,
    1243,  1263,  1274,  1567,  1262,  1285,  1284,  1290,  1275,  1297,
    1301,  1306,  1298,  1310,  1445,  1311,  1312,   891,  1276,  1304,
    1266,  1294,  1295,  1300,  1305,  1316,  1283,  1307,  1308,   384,
     385,   386,  1320,  1325,  1339,  1344,  1342,  1347,  1352,  1343,
    1219,  1353,  1358,   585,  1354,  1351,  1013,  1356,  1355,  1359,
    1211,  1373,  1414,  1385,  1380,  1381,  1382,  1230,  1387,  1231,
    1388,  1407,  1418,  1416,  1408,  1424,  1437,  1473,  1391,  1401,
    1303,  1427,  1082,  1443,  1432,  1309,  1444,   387,  1412,  1448,
    1313,  1434,  1447,  1452,  1455,  1471,   388,  1474,  1491,  1499,
    1503,  1510,  1318,  1479,  1475,  1502,  1511,  1492,  1512,  1516,
    1527,  1531,  1323,  1324,  1536,  1537,  1525,  1327,  1539,  1543,
    1544,  1329,  1330,   375,  1547,  1549,  1562,   389,  1564,   376,
    1568,  1573,  1578,  1576,  1341,  1571,  1584,   377,  1588,   378,
    1581,  1590,  1592,  1054,  1598,  1605,   390,   380,  1594,   381,
    1574,  1609,  1595,  1610,  1613,  1614,   391,  1607,   382,  1600,
    1616,   777,   383,   778,  1282,  1061,   659,   553,   865,  1299,
    1546,  1569,  1314,  1360,   556,   560,   708,   557,   683,  1364,
    1124,  1013,  1127,  1221,   578,   561,  1322,  1441,   392,  1365,
     994,   718,  1315,   384,   385,   990,  1209,   654,  1375,   730,
    1372,  1369,   745,  1332,  1338,  1383,  1328,  1013,  1384,   623,
    1386,   797,  1583,   798,   393,   394,   395,   396,   397,   834,
     398,   399,   400,   401,   402,  1580,   960,  1348,  1043,   403,
     404,  1346,  1111,  1293,   691,  1281,  1357,  1363,  1402,  1406,
    1490,  1241,  1489,  1405,  1265,  1087,  1291,  1496,   768,  1426,
     388,     0,  1403,     0,     0,     0,     0,   511,     0,   692,
       0,   775,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1013,     0,     0,     0,     0,
       0,   389,  1438,     0,     0,     0,     0,     0,  1442,     0,
       0,     0,     0,     0,     0,     0,     0,  1446,     0,     0,
       0,     0,     0,     0,     0,  1449,  1450,     0,     0,     0,
     391,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1461,  1462,  1463,  1464,  1465,     0,
    1466,  1467,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   392,     0,     0,     0,     0,     0,     0,     0,
    1433,     0,     0,     0,     0,     0,     0,  1478,     0,     0,
       0,     0,     0,     0,  1439,  1440,     0,     0,   393,   394,
     395,   396,   397,     0,   398,   399,   400,   401,   402,     0,
       0,     0,     0,   403,   404,     0,     0,     0,  1451,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1457,     0,
       0,     0,  1460,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1513,     0,     0,     0,     0,
    1515,     0,     0,     0,  1517,     0,  1519,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1535,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1518,     0,     0,     0,
       0,  1524,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1577,   511,     0,     0,     0,     0,  1013,     0,  1013,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1587,     0,     0,     0,     0,  1591,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1542,     0,     0,  1545,     0,     0,     0,  1599,     0,  1013,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1565,     0,     0,     0,  1013,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1572,     0,     0,     0,
    1575,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1589,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1596,     0,  1597,     1,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,  1608,     0,
       3,     4,  1611,     5,     0,     0,     0,  1615,     6,     7,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       0,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,    65,    66,    67,    68,    69,    70,    71,    72,     0,
       0,    73,    74,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     0,     0,    86,
       0,    87,    88,    89,    90,     0,    91,     0,     0,     0,
      92,    93,    94,    95,    96,     0,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   103,     0,     0,
       0,   104,   105,   106,   107,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,     0,
     118,   119,     0,     0,   120,   121,   122,     0,     0,     0,
     123,     0,   124,   125,     0,   126,   127,   128,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   144,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,     0,   188,   189,   190,     0,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     1,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     0,     0,
       3,     4,     0,     5,     0,     0,     0,     0,     6,     7,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       0,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,    65,    66,    67,    68,    69,    70,    71,    72,     0,
       0,    73,    74,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     0,     0,    86,
       0,    87,    88,    89,    90,     0,    91,     0,     0,     0,
      92,    93,    94,    95,    96,     0,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   103,     0,     0,
       0,   104,   105,   106,   107,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,     0,
     118,   119,     0,     0,   120,   121,   122,     0,     0,     0,
     123,     0,   124,   125,     0,   126,   127,   128,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   144,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,     0,   188,   189,   190,     0,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     2,     0,     0,     0,     0,
       0,     0,     3,     4,     0,     5,     0,     0,     0,     0,
     416,   417,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   426,    23,    24,
      25,    26,     0,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,    65,    66,    67,    68,    69,    70,    71,
      72,     0,     0,    73,    74,     0,     0,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,     0,
       0,    86,     0,    87,    88,    89,    90,     0,    91,     0,
       0,     0,    92,    93,    94,    95,    96,     0,     0,     0,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   103,
       0,     0,     0,   104,   105,   106,   107,   108,     0,     0,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,     0,   118,   119,     0,     0,   120,   121,   122,     0,
       0,     0,   123,   519,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     455,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,     0,   188,   189,   190,     0,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     2,     0,     0,
       0,     0,     0,     0,     3,     4,     0,     5,     0,     0,
       0,     0,   416,   417,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   426,
      23,    24,    25,    26,     0,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     0,    65,    66,    67,    68,    69,
      70,    71,    72,     0,     0,    73,    74,     0,     0,     0,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,     0,     0,    86,     0,    87,    88,    89,    90,     0,
      91,     0,     0,     0,    92,    93,    94,    95,    96,     0,
       0,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   103,     0,     0,     0,   104,   105,   106,   107,   108,
       0,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,     0,   118,   119,     0,     0,   120,   121,
     122,     0,   823,     0,   123,     0,   124,   125,     0,   126,
     127,   128,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   455,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,     0,   188,   189,
     190,     0,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     2,
       0,     0,     0,     0,     0,     0,     3,     4,     0,     5,
       0,     0,     0,     0,   416,   417,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   426,    23,    24,    25,    26,     0,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,    65,    66,    67,
      68,    69,    70,    71,    72,     0,     0,    73,    74,     0,
       0,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,     0,     0,    86,     0,    87,    88,    89,
      90,     0,    91,     0,     0,     0,    92,    93,    94,    95,
      96,     0,     0,     0,     0,     0,     0,    97,    98,    99,
     100,   101,   102,   103,     0,     0,     0,   104,   105,   106,
     107,   108,     0,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,     0,   118,   119,     0,     0,
     120,   121,   122,     0,     0,     0,   123,   829,   124,   125,
       0,   126,   127,   128,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   455,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,     0,
     188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     2,     0,     0,     0,     0,     0,     0,     3,     4,
       0,     5,     0,     0,     0,     0,   416,   417,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   426,    23,    24,    25,    26,     0,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,    65,
      66,    67,    68,    69,    70,    71,    72,     0,     0,    73,
      74,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     0,     0,    86,     0,    87,
      88,    89,    90,     0,    91,     0,     0,     0,    92,    93,
      94,    95,    96,     0,     0,     0,     0,     0,     0,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,   104,
     105,   106,   107,   108,     0,     0,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     0,   118,   119,
       0,     0,   120,   121,   122,     0,     0,     0,   123,   833,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   455,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,     0,   188,   189,   190,     0,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     2,     0,     0,     0,     0,     0,     0,
       3,     4,     0,     5,     0,     0,     0,     0,   416,   417,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,   426,    23,    24,    25,    26,
       0,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,    65,    66,    67,    68,    69,    70,    71,    72,     0,
       0,    73,    74,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     0,     0,    86,
       0,    87,    88,    89,    90,     0,    91,     0,     0,     0,
      92,    93,    94,    95,    96,     0,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   103,     0,     0,
       0,   104,   105,   106,   107,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,     0,
     118,   119,     0,     0,   120,   121,   122,     0,   907,     0,
     123,     0,   124,   125,     0,   126,   127,   128,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   455,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,     0,   188,   189,   190,     0,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     2,     0,     0,     0,     0,
       0,     0,     3,     4,     0,     5,     0,     0,     0,     0,
     416,   417,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   426,    23,    24,
      25,    26,     0,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,    65,    66,    67,    68,    69,    70,    71,
      72,     0,     0,    73,    74,     0,     0,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,     0,
       0,    86,     0,    87,    88,    89,    90,     0,    91,     0,
       0,     0,    92,    93,    94,    95,    96,     0,     0,     0,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   103,
       0,     0,     0,   104,   105,   106,   107,   108,     0,     0,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,     0,   118,   119,     0,     0,   120,   121,   122,     0,
     935,     0,   123,     0,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     455,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,     0,   188,   189,   190,     0,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     2,     0,     0,
       0,     0,     0,     0,     3,     4,     0,     5,     0,     0,
       0,     0,   416,   417,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   426,
      23,    24,    25,    26,     0,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     0,    65,    66,    67,    68,    69,
      70,    71,    72,     0,     0,    73,    74,     0,     0,     0,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,     0,     0,    86,     0,    87,    88,    89,    90,     0,
      91,     0,     0,     0,    92,    93,    94,    95,    96,     0,
       0,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   103,     0,     0,     0,   104,   105,   106,   107,   108,
       0,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,     0,   118,   119,     0,     0,   120,   121,
     122,     0,   956,     0,   123,     0,   124,   125,     0,   126,
     127,   128,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   455,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,     0,   188,   189,
     190,     0,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     2,
       0,     0,     0,     0,     0,     0,     3,     4,     0,     5,
       0,     0,     0,     0,   416,   417,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   426,    23,    24,    25,    26,     0,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,    65,    66,    67,
      68,    69,    70,    71,    72,     0,     0,    73,    74,     0,
       0,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,     0,     0,    86,     0,    87,    88,    89,
      90,     0,    91,     0,     0,     0,    92,    93,    94,    95,
      96,     0,     0,     0,     0,     0,     0,    97,    98,    99,
     100,   101,   102,   103,     0,     0,     0,   104,   105,   106,
     107,   108,     0,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,     0,   118,   119,     0,     0,
     120,   121,   122,     0,  1302,     0,   123,     0,   124,   125,
       0,   126,   127,   128,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   455,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,     0,
     188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     2,     0,     0,     0,     0,     0,     0,     3,     4,
       0,     5,     0,     0,     0,     0,   416,   417,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   426,    23,    24,    25,    26,     0,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,    65,
      66,    67,    68,    69,    70,    71,    72,     0,     0,    73,
      74,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     0,     0,    86,     0,    87,
      88,    89,    90,     0,    91,     0,     0,     0,    92,    93,
      94,    95,    96,     0,     0,     0,     0,     0,     0,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,   104,
     105,   106,   107,   108,     0,     0,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     0,   118,   119,
       0,     0,   120,   121,   122,     0,  1326,     0,   123,     0,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   455,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,     0,   188,   189,   190,     0,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     2,     0,     0,     0,     0,     0,     0,
       3,     4,     0,     5,     0,     0,     0,     0,   416,   417,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,   426,    23,    24,    25,    26,
       0,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,    65,    66,    67,    68,    69,    70,    71,    72,     0,
       0,    73,    74,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     0,     0,    86,
       0,    87,    88,    89,    90,     0,    91,     0,     0,     0,
      92,    93,    94,    95,    96,     0,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   103,     0,     0,
       0,   104,   105,   106,   107,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,     0,
     118,   119,     0,     0,   120,   121,   122,     0,  1340,     0,
     123,     0,   124,   125,     0,   126,   127,   128,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   455,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,     0,   188,   189,   190,     0,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     2,     0,     0,     0,     0,
       0,     0,     3,     4,     0,     5,     0,     0,     0,     0,
       6,     7,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,     0,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,    65,    66,    67,    68,    69,    70,    71,
      72,     0,     0,    73,    74,     0,     0,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,     0,
       0,    86,     0,    87,    88,    89,    90,     0,    91,     0,
       0,     0,    92,    93,    94,    95,    96,     0,     0,     0,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   103,
       0,     0,     0,   104,   105,   106,   107,   108,     0,     0,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,     0,   118,   119,     0,     0,   120,   121,   122,     0,
       0,     0,   123,     0,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     455,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,     0,   188,   189,   190,     0,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     2,     0,     0,
       0,     0,     0,     0,     3,     4,     0,     5,     0,     0,
       0,     0,   416,   417,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   426,
      23,    24,    25,    26,     0,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     0,    65,    66,    67,    68,    69,
      70,    71,    72,     0,     0,    73,    74,     0,     0,     0,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,     0,     0,    86,     0,    87,    88,    89,    90,     0,
      91,     0,     0,     0,    92,    93,    94,    95,    96,     0,
       0,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   103,     0,     0,     0,   104,   105,   106,   107,   108,
       0,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,     0,   118,   119,     0,     0,   120,   121,
     122,     0,     0,     0,   123,     0,   124,   125,     0,   126,
     127,   128,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   455,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,     0,   188,   189,
     190,     0,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     2,
       0,     0,     0,     0,     0,     0,     3,     4,     0,     5,
       0,     0,     0,     0,   416,   417,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,   422,   423,    20,
     425,   426,    23,   427,    25,    26,     0,    27,    28,    29,
      30,   428,    32,    33,    34,    35,    36,    37,   432,    39,
      40,   433,     0,    42,    43,    44,   435,   436,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,    65,    66,    67,
      68,    69,    70,    71,    72,     0,     0,    73,    74,     0,
       0,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,     0,     0,    86,     0,    87,    88,    89,
      90,     0,    91,     0,     0,     0,   444,    93,    94,    95,
      96,     0,     0,     0,     0,     0,     0,    97,    98,    99,
     100,   101,   102,   103,     0,     0,     0,   104,   105,   621,
     107,   108,     0,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,     0,   622,   119,     0,     0,
     120,   121,   122,     0,     0,     0,   123,     0,   124,   125,
       0,   126,   127,   128,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   455,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   456,   154,   458,   156,   459,   460,
     159,   160,   161,   162,   163,   164,   461,   166,   462,   463,
     464,   465,   171,   172,   466,   467,   175,   468,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,     0,
     188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     2,     0,     0,     0,     0,     0,     0,     3,     4,
       0,     5,     0,     0,     0,     0,   416,   417,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,   422,
     423,    20,   425,   426,    23,   427,    25,    26,     0,    27,
      28,    29,    30,   428,    32,    33,    34,    35,    36,    37,
     432,    39,    40,   433,     0,    42,    43,    44,   435,   436,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,    65,
      66,    67,    68,    69,    70,    71,    72,     0,     0,    73,
      74,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     0,     0,    86,     0,    87,
      88,    89,    90,     0,    91,     0,     0,     0,   444,    93,
      94,    95,    96,     0,     0,     0,     0,     0,     0,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,   104,
     105,   106,   107,   108,     0,     0,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     0,   118,   119,
       0,     0,   120,   121,   122,     0,     0,     0,   123,     0,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   455,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   456,   154,   458,   156,
     459,   460,   159,   160,   161,   162,   163,   164,   461,   166,
     462,   463,   464,   465,   171,   172,   466,   467,   175,   468,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,     0,   188,   189,   190,     0,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     2,     0,     0,     0,     0,     0,     0,
       3,     4,     0,     5,     0,     0,     0,     0,   982,   417,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,   426,    23,    24,    25,    26,
       0,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,    65,    66,    67,    68,    69,    70,    71,    72,     0,
       0,    73,    74,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     0,     0,    86,
       0,    87,    88,    89,    90,     0,    91,     0,     0,     0,
      92,    93,    94,    95,    96,     0,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   103,     0,     0,
       0,   104,   105,   106,   107,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,     0,
     118,   119,     0,     0,   120,   121,   122,     0,     0,     0,
     123,     0,   124,   125,     0,   126,   127,   128,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   455,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,     0,   188,   189,   190,     0,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     2,     0,     0,     0,     0,
       0,     0,     3,     4,     0,     5,     0,     0,     0,     0,
     416,   417,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,   422,   423,    20,   425,   426,    23,   427,
      25,    26,     0,    27,    28,    29,    30,   428,    32,    33,
      34,    35,    36,    37,   432,    39,    40,   433,     0,    42,
      43,    44,   435,   436,    47,   437,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,    65,    66,    67,    68,    69,    70,    71,
      72,     0,     0,    73,    74,     0,     0,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,     0,
       0,    86,     0,    87,    88,    89,    90,     0,    91,     0,
       0,     0,   444,    93,    94,    95,    96,     0,     0,     0,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   103,
       0,     0,     0,   104,   105,     0,   107,   108,     0,     0,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,     0,     0,     0,     0,     0,   120,   121,   122,     0,
       0,     0,   123,     0,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     455,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     456,   154,   458,   156,   459,   460,   159,   160,   161,   162,
     163,   164,   461,   166,   462,   463,   464,   465,   171,   172,
     466,   467,   175,   468,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,     0,   188,   189,   190,     0,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     2,     0,     0,
       0,     0,     0,     0,     3,     4,     0,     5,     0,     0,
       0,     0,   416,   417,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,   422,   423,    20,   425,   426,
      23,   427,    25,    26,     0,    27,    28,    29,    30,   428,
      32,    33,    34,    35,    36,    37,   432,    39,    40,   433,
       0,    42,    43,    44,   435,   436,    47,   437,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     0,    65,    66,    67,    68,    69,
      70,    71,    72,     0,     0,    73,    74,     0,     0,     0,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,     0,     0,    86,     0,    87,    88,    89,    90,     0,
      91,     0,     0,     0,   444,    93,    94,    95,    96,     0,
       0,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   103,     0,     0,     0,   104,   105,     0,   107,   108,
       0,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,     0,     0,     0,     0,     0,   120,   121,
     122,     0,     0,     0,   123,     0,   124,   125,     0,     0,
       0,   128,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   455,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   456,   154,   458,   156,   459,   460,   159,   160,
     161,   162,   163,   164,   461,   166,   462,   463,   464,   465,
     171,   172,   466,   467,   175,   468,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,     0,   188,   189,
     190,     0,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     2,
       0,     0,     0,     0,     0,     0,     3,     4,     0,     0,
       0,     0,     0,     0,   416,   417,     0,     8,     9,   505,
      11,    12,    13,    14,   419,    16,   506,   422,   423,   424,
     425,   426,    23,   427,    25,    26,     0,    27,    28,    29,
      30,   428,    32,   507,    34,    35,    36,    37,   432,    39,
      40,   433,     0,    42,   508,    44,   435,   436,    47,   437,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,   438,   439,    64,     0,    65,    66,    67,
     509,     0,    70,    71,    72,     0,     0,   441,    74,     0,
       0,     0,     0,    76,    77,    78,   442,   443,    81,    82,
       0,     0,     0,     0,     0,     0,     0,    87,    88,    89,
      90,     0,    91,     0,     0,     0,   444,    93,    94,   445,
     446,     0,     0,     0,     0,     0,     0,    97,    98,    99,
       0,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     107,   108,     0,     0,     0,     0,   109,   110,   111,   112,
     449,   114,   115,   450,     0,     0,     0,     0,     0,     0,
     451,   452,   122,     0,     0,     0,   123,     0,   124,   453,
       0,     0,     0,   128,     0,   129,     0,   130,   131,   132,
     133,   454,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   455,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   456,   154,   458,   156,   459,   460,
     159,   160,   161,   162,   163,   164,   461,   166,   462,   463,
     464,   465,   171,   172,   466,   467,   175,   468,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,     0,
     188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     2,     0,     0,     0,     0,     0,     0,     3,     4,
       0,     0,     0,     0,     0,     0,   416,   417,     0,     8,
       9,   418,    11,    12,    13,    14,   419,   420,   421,   422,
     423,   424,   425,   426,    23,   427,    25,    26,     0,    27,
      28,    29,    30,   428,    32,   429,    34,   430,   431,    37,
     432,    39,    40,   433,     0,    42,   434,    44,   435,   436,
      47,   437,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,   438,   439,    64,     0,    65,
      66,    67,   440,     0,    70,    71,    72,     0,     0,   441,
      74,     0,     0,     0,     0,    76,    77,    78,   442,   443,
      81,    82,     0,     0,     0,     0,     0,     0,     0,    87,
      88,    89,    90,     0,    91,     0,     0,     0,   444,    93,
      94,   445,   446,     0,     0,     0,     0,     0,     0,    97,
      98,    99,     0,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   107,   108,     0,     0,     0,     0,   109,   110,
     111,   112,   449,   114,   115,   450,     0,     0,     0,     0,
       0,     0,   451,   452,   122,     0,     0,     0,   123,     0,
     124,   453,     0,     0,     0,   128,     0,   129,     0,   130,
     131,   132,   133,   454,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,     0,     0,   455,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   456,   457,   458,   156,
     459,   460,   159,   160,   161,   162,   163,   164,   461,   166,
     462,   463,   464,   465,   171,   172,   466,   467,   175,   468,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,     0,   188,   189,   190,     0,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   482,     0,     0,     0,     4,     0,     0,
       0,     0,     0,     0,   416,   417,     0,     8,     9,   418,
      11,    12,    13,    14,   419,   420,   421,   422,   423,   424,
     425,   426,    23,   427,    25,    26,     0,    27,    28,    29,
      30,   428,    32,   429,    34,   430,   431,    37,   432,    39,
      40,   433,     0,    42,   434,    44,   435,   436,    47,   437,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,   438,   439,    64,     0,    65,    66,    67,
     440,     0,    70,    71,    72,     0,     0,   441,    74,     0,
       0,     0,     0,    76,    77,    78,   442,   443,    81,    82,
       0,     0,     0,     0,     0,     0,     0,    87,    88,    89,
      90,     0,    91,     0,     0,     0,   444,    93,    94,   445,
     446,     0,     0,     0,     0,     0,     0,    97,    98,    99,
       0,   101,   102,   103,   483,     0,     0,   484,     0,     0,
     107,   108,     0,     0,     0,     0,   109,   110,   111,   112,
     449,   114,   115,   450,     0,     0,     0,     0,     0,     0,
     451,   452,   122,     0,     0,     0,   123,     0,   124,   453,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   454,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   455,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   456,   457,   458,   156,   459,   460,
     159,   160,   161,   162,   163,   164,   461,   166,   462,   463,
     464,   465,   171,   172,   466,   467,   175,   468,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,     0,
     188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   482,     0,     0,     0,     4,     0,   721,     0,     0,
       0,     0,   416,   417,     0,     8,     9,   418,    11,    12,
      13,    14,   419,   420,   421,   422,   423,   424,   425,   426,
      23,   427,    25,    26,     0,    27,    28,    29,    30,   428,
      32,   429,    34,   430,   431,    37,   432,    39,    40,   433,
       0,    42,   434,    44,   435,   436,    47,   437,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,   438,   439,    64,     0,    65,    66,    67,   440,     0,
      70,    71,    72,     0,     0,   441,    74,     0,     0,     0,
       0,    76,    77,    78,   442,   443,    81,    82,     0,     0,
       0,     0,     0,     0,     0,    87,    88,    89,    90,     0,
      91,     0,     0,     0,   444,    93,    94,   445,   446,     0,
       0,     0,     0,     0,     0,    97,    98,    99,     0,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   107,   108,
       0,     0,     0,     0,   109,   110,   111,   112,   449,   114,
     115,   450,     0,     0,     0,     0,     0,     0,   451,   452,
     122,     0,     0,     0,   123,   722,   124,   453,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   454,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   455,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   456,   457,   458,   156,   459,   460,   159,   160,
     161,   162,   163,   164,   461,   166,   462,   463,   464,   465,
     171,   172,   466,   467,   175,   468,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,     0,   188,   189,
     190,     0,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   482,
       0,     0,     0,     4,     0,     0,     0,     0,     0,     0,
     416,   417,     0,     8,     9,   418,    11,    12,    13,    14,
     419,   420,   421,   422,   423,   424,   425,   426,    23,   427,
      25,    26,     0,    27,    28,    29,    30,   428,    32,   429,
      34,   430,   431,    37,   432,    39,    40,   433,     0,    42,
     434,    44,   435,   436,    47,   437,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,   438,
     439,    64,     0,    65,    66,    67,   440,     0,    70,    71,
      72,     0,     0,   441,    74,     0,     0,     0,     0,    76,
      77,    78,   442,   443,    81,    82,     0,     0,     0,     0,
       0,     0,     0,    87,    88,    89,    90,     0,    91,     0,
       0,     0,   444,    93,    94,   445,   446,     0,     0,     0,
       0,     0,     0,    97,    98,    99,     0,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   107,   108,     0,     0,
       0,     0,   109,   110,   111,   112,   449,   114,   115,   450,
       0,     0,     0,     0,     0,     0,   451,   452,   122,     0,
       0,     0,   123,     0,   124,   453,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   454,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,     0,     0,
     455,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     456,   457,   458,   156,   459,   460,   159,   160,   161,   162,
     163,   164,   461,   166,   462,   463,   464,   465,   171,   172,
     466,   467,   175,   468,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,     0,   188,   189,   190,     0,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   525,     0,     4,
       0,     0,     0,     0,     0,     0,   416,   417,     0,     8,
       9,   418,    11,    12,    13,    14,   419,   420,   421,   422,
     423,   424,   425,   426,    23,   427,    25,    26,     0,    27,
      28,    29,    30,   428,    32,   429,    34,   430,   431,    37,
     432,    39,    40,   433,     0,    42,   434,    44,   435,   436,
      47,   437,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,   438,   439,    64,     0,    65,
      66,    67,   440,     0,    70,    71,    72,     0,     0,   441,
      74,     0,     0,     0,     0,    76,    77,    78,   442,   443,
      81,    82,     0,     0,     0,     0,     0,     0,     0,    87,
      88,    89,    90,     0,    91,     0,     0,     0,   444,    93,
      94,   445,   446,     0,     0,     0,     0,     0,     0,    97,
      98,    99,     0,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   107,   108,     0,     0,     0,     0,   109,   110,
     111,   112,   449,   114,   115,   450,     0,     0,     0,     0,
       0,     0,   451,   452,   122,     0,     0,     0,   123,     0,
     124,   453,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   454,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,     0,     0,   455,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   456,   457,   458,   156,
     459,   460,   159,   160,   161,   162,   163,   164,   461,   166,
     462,   463,   464,   465,   171,   172,   466,   467,   175,   468,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,     0,   188,   189,   190,     0,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     4,     0,     0,     0,     0,     0,     0,
     416,   417,     0,     8,     9,   418,    11,    12,    13,    14,
     419,   420,   421,   422,   423,   424,   425,   426,    23,   427,
      25,    26,     0,    27,    28,    29,    30,   428,    32,   429,
      34,   430,   431,    37,   432,    39,    40,   433,     0,    42,
     434,    44,   435,   436,    47,   437,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,   438,
     439,    64,     0,    65,    66,    67,   440,     0,    70,    71,
      72,     0,     0,   441,    74,     0,     0,     0,     0,    76,
      77,    78,   442,   443,    81,    82,     0,     0,     0,   501,
       0,     0,     0,    87,    88,    89,    90,     0,    91,     0,
       0,     0,   444,    93,    94,   445,   446,     0,     0,     0,
       0,     0,     0,    97,    98,    99,     0,   101,   102,   103,
     502,     0,     0,   503,     0,     0,   107,   108,     0,     0,
       0,     0,   109,   110,   111,   112,   449,   114,   115,   450,
       0,     0,     0,     0,     0,     0,   451,   452,   122,     0,
       0,     0,   123,     0,   124,   453,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   454,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,     0,     0,
     455,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     456,   457,   458,   156,   459,   460,   159,   160,   161,   162,
     163,   164,   461,   166,   462,   463,   464,   465,   171,   172,
     466,   467,   175,   468,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,     0,   188,   189,   190,     0,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     4,     0,     0,
       0,     0,     0,     0,   416,   417,     0,     8,     9,   505,
      11,    12,    13,    14,   419,    16,   506,   422,   423,  1001,
     425,   426,    23,   427,    25,    26,     0,    27,    28,    29,
      30,   428,    32,   507,    34,    35,    36,    37,   432,    39,
      40,   433,     0,    42,   508,    44,   435,   436,    47,   437,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,   438,   439,    64,     0,    65,    66,    67,
     509,     0,    70,    71,    72,     0,     0,   441,    74,     0,
       0,     0,     0,    76,    77,    78,   442,   443,    81,    82,
       0,     0,     0,     0,     0,     0,     0,    87,    88,    89,
      90,     0,    91,     0,     0,     0,   444,    93,    94,   445,
     446,     0,     0,     0,     0,     0,     0,    97,    98,    99,
       0,   101,   102,  1002,     0,     0,     0,  1003,     0,     0,
     107,   108,     0,     0,     0,     0,   109,   110,   111,   112,
     449,   114,   115,   450,     0,     0,     0,     0,     0,     0,
     451,   452,   122,     0,     0,     0,   123,  1376,   124,   453,
       0,     0,     0,  1377,     0,   129,     0,   130,   131,   132,
     133,   454,   135,   136,   137,   138,   139,   140,     0,     0,
    1004,   142,     0,     0,   455,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   456,   154,   458,   156,   459,   460,
     159,   160,   161,   162,   163,   164,   461,   166,   462,   463,
     464,   465,   171,   172,   466,   467,   175,   468,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,     0,
     188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     4,     0,     0,     0,     0,     0,     0,   416,   417,
       0,     8,     9,   418,    11,    12,    13,    14,   419,   420,
     421,   422,   423,   424,   425,   426,    23,   427,    25,    26,
       0,    27,    28,    29,    30,   428,    32,   429,    34,   430,
     431,    37,   432,    39,    40,   433,     0,    42,   434,    44,
     435,   436,    47,   437,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,   438,   439,    64,
       0,    65,    66,    67,   440,     0,    70,    71,    72,     0,
       0,   441,    74,     0,     0,     0,     0,    76,    77,    78,
     442,   443,    81,    82,     0,     0,     0,     0,     0,     0,
       0,    87,    88,    89,    90,     0,    91,     0,     0,     0,
     444,    93,    94,   445,   446,     0,     0,     0,     0,     0,
       0,    97,    98,    99,     0,   101,   102,   103,   447,     0,
       0,   448,     0,     0,   107,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   449,   114,   115,   450,     0,     0,
       0,     0,     0,     0,   451,   452,   122,     0,     0,     0,
     123,     0,   124,   453,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   454,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   455,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   456,   457,
     458,   156,   459,   460,   159,   160,   161,   162,   163,   164,
     461,   166,   462,   463,   464,   465,   171,   172,   466,   467,
     175,   468,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,     0,   188,   189,   190,     0,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     4,     0,     0,     0,     0,
       0,     0,   416,   417,     0,     8,     9,   418,    11,    12,
      13,    14,   419,   420,   421,   422,   423,   424,   425,   426,
      23,   427,    25,    26,     0,    27,    28,    29,    30,   428,
      32,   429,    34,   430,   431,    37,   432,    39,    40,   433,
       0,    42,   434,    44,   435,   436,    47,   437,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,   438,   439,    64,     0,    65,    66,    67,   440,     0,
      70,    71,    72,     0,     0,   441,    74,     0,     0,     0,
       0,    76,    77,    78,   442,   443,    81,    82,     0,     0,
       0,     0,     0,     0,     0,    87,    88,    89,    90,     0,
      91,     0,     0,     0,   444,    93,    94,   445,   446,     0,
       0,     0,     0,     0,     0,    97,    98,    99,     0,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   107,   108,
       0,     0,     0,     0,   109,   110,   111,   112,   449,   114,
     115,   450,     0,     0,     0,     0,     0,     0,   451,   452,
     122,     0,     0,     0,   123,   694,   124,   453,     0,     0,
       0,   695,     0,   129,     0,   130,   131,   132,   133,   454,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   455,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   456,   457,   458,   156,   459,   460,   159,   160,
     161,   162,   163,   164,   461,   166,   462,   463,   464,   465,
     171,   172,   466,   467,   175,   468,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,     0,   188,   189,
     190,     0,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     4,
       0,     0,     0,     0,     0,     0,   416,   417,     0,     8,
       9,   418,    11,    12,    13,    14,   419,   420,   421,   422,
     423,   424,   425,   426,    23,   427,    25,    26,     0,    27,
      28,    29,    30,   428,    32,   429,    34,   430,   431,    37,
     432,    39,    40,   433,     0,    42,   434,    44,   435,   436,
      47,   437,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,   438,   439,    64,     0,    65,
      66,    67,   440,     0,    70,    71,    72,     0,     0,   441,
      74,     0,     0,     0,     0,    76,    77,    78,   442,   443,
      81,    82,     0,     0,     0,     0,     0,     0,     0,    87,
      88,    89,    90,     0,    91,     0,     0,     0,   444,    93,
      94,   445,   446,     0,     0,     0,     0,     0,     0,    97,
      98,    99,     0,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   107,   108,     0,     0,     0,     0,   109,   110,
     111,   112,   449,   114,   115,   450,     0,     0,     0,     0,
       0,     0,   451,   452,   122,     0,     0,     0,   123,   741,
     124,   453,     0,     0,     0,   742,     0,   129,     0,   130,
     131,   132,   133,   454,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,     0,     0,   455,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   456,   457,   458,   156,
     459,   460,   159,   160,   161,   162,   163,   164,   461,   166,
     462,   463,   464,   465,   171,   172,   466,   467,   175,   468,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,     0,   188,   189,   190,     0,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     4,     0,     0,     0,     0,     0,     0,
     416,   417,     0,     8,     9,   505,    11,    12,    13,    14,
     419,    16,   506,   422,   423,  1001,   425,   426,    23,   427,
      25,    26,     0,    27,    28,    29,    30,   428,    32,   507,
      34,    35,    36,    37,   432,    39,    40,   433,     0,    42,
     508,    44,   435,   436,    47,   437,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,   438,
     439,    64,     0,    65,    66,    67,   509,     0,    70,    71,
      72,     0,     0,   441,    74,     0,     0,     0,     0,    76,
      77,    78,   442,   443,    81,    82,  1335,     0,     0,     0,
       0,     0,     0,    87,    88,    89,    90,     0,    91,     0,
       0,     0,   444,    93,    94,   445,   446,     0,     0,     0,
       0,     0,     0,    97,    98,    99,     0,   101,   102,  1002,
       0,     0,     0,  1003,     0,     0,   107,   108,     0,     0,
       0,     0,   109,   110,   111,   112,   449,   114,   115,   450,
       0,     0,     0,     0,     0,     0,   451,   452,   122,     0,
       0,     0,   123,     0,   124,   453,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   454,   135,   136,
     137,   138,   139,   140,     0,     0,  1004,   142,     0,     0,
     455,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     456,   154,   458,   156,   459,   460,   159,   160,   161,   162,
     163,   164,   461,   166,   462,   463,   464,   465,   171,   172,
     466,   467,   175,   468,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,     0,   188,   189,   190,     0,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     4,     0,     0,
       0,     0,     0,     0,   416,   417,     0,     8,     9,   505,
      11,    12,    13,    14,   419,    16,   506,   422,   423,  1001,
     425,   426,    23,   427,    25,    26,     0,    27,    28,    29,
      30,   428,    32,   507,    34,    35,    36,    37,   432,    39,
      40,   433,     0,    42,   508,    44,   435,   436,    47,   437,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,   438,   439,    64,     0,    65,    66,    67,
     509,     0,    70,    71,    72,     0,     0,   441,    74,     0,
       0,     0,     0,    76,    77,    78,   442,   443,    81,    82,
       0,     0,     0,     0,     0,     0,     0,    87,    88,    89,
      90,     0,    91,     0,     0,     0,   444,    93,    94,   445,
     446,     0,     0,     0,     0,     0,     0,    97,    98,    99,
       0,   101,   102,  1002,     0,     0,     0,  1003,     0,     0,
     107,   108,     0,     0,     0,     0,   109,   110,   111,   112,
     449,   114,   115,   450,     0,     0,     0,     0,     0,     0,
     451,   452,   122,     0,     0,     0,   123,     0,   124,   453,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   454,   135,   136,   137,   138,   139,   140,     0,     0,
    1004,   142,     0,     0,   455,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   456,   154,   458,   156,   459,   460,
     159,   160,   161,   162,   163,   164,   461,   166,   462,   463,
     464,   465,   171,   172,   466,   467,   175,   468,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,     0,
     188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     4,     0,     0,     0,     0,     0,     0,   416,   417,
       0,     8,     9,   505,    11,    12,    13,    14,   419,    16,
     506,   422,   423,  1001,   425,   426,    23,   427,    25,    26,
       0,    27,    28,    29,    30,   428,    32,   507,    34,    35,
      36,    37,   432,    39,    40,   433,     0,    42,   508,    44,
     435,   436,    47,   437,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,   438,   439,    64,
       0,    65,    66,    67,   509,     0,    70,    71,    72,     0,
       0,   441,    74,     0,     0,     0,     0,    76,    77,    78,
     442,   443,    81,    82,     0,     0,     0,     0,     0,     0,
       0,    87,    88,    89,    90,     0,    91,     0,     0,     0,
     444,    93,    94,   445,   446,     0,     0,     0,     0,     0,
       0,    97,    98,    99,     0,   101,   102,  1002,     0,     0,
       0,  1003,     0,     0,   107,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   449,   114,   115,   450,     0,     0,
       0,     0,     0,     0,   451,   452,   122,     0,     0,     0,
     123,     0,   124,   453,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   454,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   455,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   456,   154,
     458,   156,   459,   460,   159,   160,   161,   162,   163,   164,
     461,   166,   462,   463,   464,   465,   171,   172,   466,   467,
     175,   468,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,     0,   188,   189,   190,     0,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     4,     0,     0,     0,     0,
       0,     0,   416,   417,     0,     8,     9,   418,    11,    12,
      13,    14,   419,   420,   421,   422,   423,   424,   425,   426,
      23,   427,    25,    26,     0,    27,    28,    29,    30,   428,
      32,   429,    34,   430,   431,    37,   432,    39,    40,   433,
       0,    42,   434,    44,   435,   436,    47,   437,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,   438,   439,    64,     0,    65,    66,    67,   440,     0,
      70,    71,    72,     0,     0,   441,    74,     0,     0,     0,
       0,    76,    77,    78,   442,   443,    81,    82,     0,     0,
       0,     0,     0,     0,     0,    87,    88,    89,    90,     0,
      91,     0,     0,     0,   444,    93,    94,   445,   446,     0,
       0,     0,     0,     0,     0,    97,    98,    99,     0,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   107,   108,
       0,     0,     0,     0,   109,   110,   111,   112,   449,   114,
     115,   450,     0,     0,     0,     0,     0,     0,   451,   452,
     122,     0,     0,     0,   123,     0,   124,   453,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   454,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   455,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   456,   457,   458,   156,   459,   460,   159,   160,
     161,   162,   163,   164,   461,   166,   462,   463,   464,   465,
     171,   172,   466,   467,   175,   468,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,     0,   188,   189,
     190,     0,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        17,   718,   748,   310,   566,   371,   927,  1099,   104,   609,
     610,   611,   612,   730,   790,   127,    33,   608,   563,   819,
     820,   895,  1204,   117,   807,   963,   237,   718,    69,   240,
     807,  1215,  1216,  1362,  1025,    20,    47,    49,  1291,    50,
     111,   585,    21,   819,   820,    88,   648,    90,    90,  1177,
    1266,    68,    69,   854,   588,    88,   590,   591,     7,   593,
      88,   595,    33,     4,    88,    20,    83,     8,    39,   603,
     604,    87,     8,    44,   100,    20,    45,   100,   854,     8,
       9,    52,    93,    19,   139,   139,   100,   100,   105,    93,
     985,   100,   111,    64,   100,    90,   139,   139,   134,   100,
     117,   100,   119,   794,    90,   796,    88,   100,   161,    30,
     134,   145,   478,   479,   890,    36,    37,   917,   103,    26,
      37,   111,    99,   158,   239,   240,     8,     9,   128,   206,
      46,   116,    38,    54,    90,    56,    57,    53,   173,   192,
      57,   917,   119,   860,    65,   216,   100,   262,    55,    88,
     152,   106,   121,   179,   150,    90,   141,   139,   174,   178,
     145,  1056,   148,   148,   178,     4,   100,    96,   181,     8,
      91,   167,   181,   177,   115,   181,   117,   178,    88,   115,
     179,   117,   175,   168,   125,  1369,   115,   177,   117,   160,
     126,   191,   163,   910,   100,   228,   208,   152,   148,   916,
     228,   313,  1003,   226,   145,   161,   177,   152,  1300,   145,
     265,   265,  1428,   959,    96,  1136,   145,   166,  1346,   145,
     149,  1095,   265,   265,   178,   204,   161,  1003,   299,   265,
    1168,   202,   243,   115,   246,   117,   165,   839,   840,  1177,
     931,   265,  1025,  1026,   178,   256,   148,   258,  1025,  1026,
    1503,  1242,   796,   248,   249,   100,   185,  1586,   269,   270,
     271,   178,   273,   145,   275,   261,   251,   149,   285,   803,
     209,   210,   268,  1602,   203,   100,   115,   318,   117,   122,
     321,  1610,   278,   165,   100,   224,   125,  1469,   244,   245,
      88,   247,   123,   387,   903,   216,   905,   663,   254,   209,
     210,   318,   148,   185,   321,    88,   145,   100,   264,   244,
     245,   100,   247,   100,   224,   100,   412,   411,   414,   122,
     276,   203,  1506,     8,     9,   255,  1102,    20,  1128,   264,
    1021,   208,    61,   178,   111,   145,   266,    66,   150,   110,
    1432,   276,   553,   952,   187,   954,   145,   145,   714,   148,
     181,   447,  1128,   178,  1154,   167,   139,  1541,   168,   376,
     216,   378,   178,    90,   148,   221,   383,   138,    39,   246,
     387,    37,   470,   145,    40,     8,   393,   189,  1154,   106,
     151,   477,   111,   400,   187,   178,    19,   483,    88,   178,
     484,   178,    46,   178,   411,   491,   168,   493,   494,    53,
     496,   200,     8,     9,    90,    46,   502,    73,  1346,   191,
     103,    96,    53,   184,   212,   213,   148,    71,   200,  1511,
     106,   148,  1222,   116,   111,  1299,   522,   161,    25,   129,
     115,   448,   117,    99,   134,   531,    90,   535,   536,   150,
     538,   539,   540,   541,   989,    42,  1222,  1539,   141,    90,
     548,   549,   145,   129,   550,   148,   167,   111,   192,  1242,
     145,   111,   148,   480,   149,  1242,   564,   484,  1251,   145,
     487,   488,   489,   490,  1251,   168,   574,   575,   495,  1262,
     165,   851,   115,   291,   117,  1262,   503,   221,   136,   129,
      96,   129,   300,   126,   160,   865,   140,   863,   864,   516,
     185,   114,   868,   150,   140,   145,  1598,   145,  1600,   115,
     261,   117,   145,   157,    90,   627,   628,   268,   203,   167,
     167,   157,   173,  1444,  1616,    93,   543,   278,   624,   145,
     106,   897,   148,   629,   551,   186,   184,   635,   106,   145,
     638,   148,   189,   149,    40,   279,   280,   281,   282,   283,
     173,   285,   286,   287,   288,   289,    89,  1520,  1521,   165,
     294,   128,    58,   186,    60,    93,    99,   182,   183,   129,
      88,   137,   255,    69,   134,   142,   109,   148,   106,   185,
     124,    99,   148,   266,   145,   260,   119,   148,   132,   133,
    1553,   135,   267,   292,   293,   129,  1559,   203,  1344,   143,
     134,   697,  1348,   147,   320,   149,   269,   270,   271,   325,
     154,   707,   275,   292,   293,   630,   710,   114,   633,   713,
     216,   636,   218,   216,  1407,   218,   170,   146,   724,   148,
    1407,   212,   213,   214,   114,   223,   653,   225,   655,   120,
     121,   658,   738,   739,   223,   375,   225,   377,   744,   193,
     194,   195,   196,   197,   198,   283,   284,   120,   121,   606,
     607,   114,  1253,   680,   681,   682,   114,   613,   614,   821,
     822,   615,   616,   769,  1474,   111,  1476,  1419,  1420,   114,
     114,   145,   114,   114,   701,   114,   703,   785,   114,   145,
     148,   216,   111,   710,   792,   145,   713,   233,  1474,   234,
    1476,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,  1457,   233,   111,  1460,   148,  1516,   145,  1280,     0,
    1027,     3,   181,    86,   181,   241,    43,    94,   190,   159,
     747,  1531,   146,    95,    20,    40,    40,    40,   144,   111,
    1516,   290,   285,   238,   290,   296,   145,   276,   145,   276,
     111,   178,   111,   145,   178,  1531,   145,   145,   856,   145,
     178,   148,    27,   148,   862,  1131,   783,   148,   148,   148,
      15,    20,    25,   790,   178,   222,   111,   160,  1524,   204,
     162,   100,    65,   222,   162,   141,    88,    88,    88,  1506,
     100,  1391,   100,    20,   152,   152,   119,   124,   238,   291,
     124,   175,   819,   820,   821,   822,   175,  1398,  1399,    88,
     178,   175,   178,   178,    90,   175,    37,    90,   134,   145,
     100,   175,    88,   178,   111,   178,   178,   178,   175,   178,
     178,   929,   175,   175,   175,   175,   134,   854,   228,   216,
     178,   939,   175,   941,   942,  1211,   139,   181,   162,   111,
     111,   947,   111,   870,   175,   124,   176,   134,    88,   134,
     958,    20,   278,   175,   111,    88,   175,   145,   218,   291,
     246,   969,   970,   971,   124,   973,   974,   975,   976,   977,
     978,   188,   980,   981,   152,   124,   903,    90,   905,   111,
    1481,  1482,   134,    28,    29,   993,    31,    32,   111,    34,
     917,   145,   139,   175,    93,    40,    93,   145,   175,    27,
      20,   175,   175,    48,   111,    50,    51,   175,   111,  1017,
     145,  1019,  1020,    58,   237,    60,    73,   100,  1024,   100,
     148,   148,   148,   139,    69,   952,    20,   954,    73,   139,
     277,   252,   136,  1534,   250,    20,   278,    20,  1046,   279,
     181,   136,   298,   139,  1320,   111,   111,   228,  1054,   178,
     259,   218,   218,   218,   178,    71,  1064,   178,   178,   104,
     105,   106,   100,   134,   175,   124,   178,     6,   224,   178,
     997,   224,   177,  1000,   224,   181,  1003,   228,   224,   134,
      99,    99,    72,   139,   178,   178,   178,  1014,   175,  1016,
     178,   139,    20,   175,   274,    20,   175,  1373,   242,   242,
    1106,   263,    90,   118,   162,  1113,    90,   152,   278,   177,
    1118,   249,   175,   177,   175,   175,   161,    88,   145,    20,
     100,   279,  1130,   175,   178,   178,   162,   272,    46,    88,
     111,    88,  1140,  1141,    20,   257,   187,  1143,   100,   111,
     216,  1149,  1150,    34,   111,   177,   187,   192,   187,    40,
     175,   111,    87,   177,  1160,   297,   187,    48,   297,    50,
     174,   111,   111,   145,   298,   111,   211,    58,   285,    60,
     216,   279,   297,   178,   216,   111,   221,   189,    69,   298,
     298,   562,    73,   562,  1060,   855,   385,   237,   662,  1102,
    1511,  1539,  1119,  1200,   241,   244,   476,   241,   405,  1207,
     915,  1128,   918,  1000,   284,   245,  1138,  1314,   253,  1208,
    1218,  1138,  1120,   104,   105,   106,   993,   381,  1220,  1146,
    1218,  1215,   516,  1151,  1155,  1233,  1146,  1154,  1236,   306,
    1238,   586,  1559,   587,   279,   280,   281,   282,   283,   638,
     285,   286,   287,   288,   289,  1553,   748,  1174,   822,   294,
     295,  1168,   905,  1096,   415,  1059,  1195,  1205,  1251,  1262,
    1407,  1026,  1404,  1255,  1035,   889,  1084,  1422,  1195,  1289,
     161,    -1,  1252,    -1,    -1,    -1,    -1,  1204,    -1,   415,
      -1,  1208,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1222,    -1,    -1,    -1,    -1,
      -1,   192,  1310,    -1,    -1,    -1,    -1,    -1,  1316,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1325,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1333,  1334,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1352,  1353,  1354,  1355,  1356,    -1,
    1358,  1359,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1297,    -1,    -1,    -1,    -1,    -1,    -1,  1385,    -1,    -1,
      -1,    -1,    -1,    -1,  1311,  1312,    -1,    -1,   279,   280,
     281,   282,   283,    -1,   285,   286,   287,   288,   289,    -1,
      -1,    -1,    -1,   294,   295,    -1,    -1,    -1,  1335,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1345,    -1,
      -1,    -1,  1349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1443,    -1,    -1,    -1,    -1,
    1448,    -1,    -1,    -1,  1452,    -1,  1454,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1491,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1453,    -1,    -1,    -1,
      -1,  1458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1549,  1469,    -1,    -1,    -1,    -1,  1474,    -1,  1476,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1571,    -1,    -1,    -1,    -1,  1576,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1507,    -1,    -1,  1510,    -1,    -1,    -1,  1595,    -1,  1516,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1527,    -1,    -1,    -1,  1531,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1543,    -1,    -1,    -1,
    1547,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1573,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1590,    -1,  1592,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,  1605,    -1,
      17,    18,  1609,    20,    -1,    -1,    -1,  1614,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    89,    90,    91,    92,    93,    94,    95,    -1,
      -1,    98,    99,    -1,    -1,    -1,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,   116,
      -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
     167,   168,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,
     177,    -1,   179,   180,    -1,   182,   183,   184,    -1,   186,
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
     297,   298,   299,   300,   301,   302,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    89,    90,    91,    92,    93,    94,    95,    -1,
      -1,    98,    99,    -1,    -1,    -1,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,   116,
      -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
     167,   168,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,
     177,    -1,   179,   180,    -1,   182,   183,   184,    -1,   186,
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
     297,   298,   299,   300,   301,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
      -1,   116,    -1,   118,   119,   120,   121,    -1,   123,    -1,
      -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,   167,   168,    -1,    -1,   171,   172,   173,    -1,
      -1,    -1,   177,   178,   179,   180,    -1,   182,   183,   184,
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
     295,   296,   297,   298,   299,   300,   301,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    89,    90,    91,    92,
      93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,    -1,   116,    -1,   118,   119,   120,   121,    -1,
     123,    -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,   167,   168,    -1,    -1,   171,   172,
     173,    -1,   175,    -1,   177,    -1,   179,   180,    -1,   182,
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
     293,   294,   295,   296,   297,   298,   299,   300,   301,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    89,    90,
      91,    92,    93,    94,    95,    -1,    -1,    98,    99,    -1,
      -1,    -1,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    -1,    -1,   116,    -1,   118,   119,   120,
     121,    -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,
     131,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,   167,   168,    -1,    -1,
     171,   172,   173,    -1,    -1,    -1,   177,   178,   179,   180,
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
     301,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    88,
      89,    90,    91,    92,    93,    94,    95,    -1,    -1,    98,
      99,    -1,    -1,    -1,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    -1,    -1,   116,    -1,   118,
     119,   120,   121,    -1,   123,    -1,    -1,    -1,   127,   128,
     129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,   167,   168,
      -1,    -1,   171,   172,   173,    -1,    -1,    -1,   177,   178,
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
     299,   300,   301,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    89,    90,    91,    92,    93,    94,    95,    -1,
      -1,    98,    99,    -1,    -1,    -1,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,   116,
      -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
     167,   168,    -1,    -1,   171,   172,   173,    -1,   175,    -1,
     177,    -1,   179,   180,    -1,   182,   183,   184,    -1,   186,
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
     297,   298,   299,   300,   301,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
      -1,   116,    -1,   118,   119,   120,   121,    -1,   123,    -1,
      -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,   167,   168,    -1,    -1,   171,   172,   173,    -1,
     175,    -1,   177,    -1,   179,   180,    -1,   182,   183,   184,
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
     295,   296,   297,   298,   299,   300,   301,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    89,    90,    91,    92,
      93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,    -1,   116,    -1,   118,   119,   120,   121,    -1,
     123,    -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,   167,   168,    -1,    -1,   171,   172,
     173,    -1,   175,    -1,   177,    -1,   179,   180,    -1,   182,
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
     293,   294,   295,   296,   297,   298,   299,   300,   301,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    89,    90,
      91,    92,    93,    94,    95,    -1,    -1,    98,    99,    -1,
      -1,    -1,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    -1,    -1,   116,    -1,   118,   119,   120,
     121,    -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,
     131,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,   167,   168,    -1,    -1,
     171,   172,   173,    -1,   175,    -1,   177,    -1,   179,   180,
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
     301,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    88,
      89,    90,    91,    92,    93,    94,    95,    -1,    -1,    98,
      99,    -1,    -1,    -1,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    -1,    -1,   116,    -1,   118,
     119,   120,   121,    -1,   123,    -1,    -1,    -1,   127,   128,
     129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,   167,   168,
      -1,    -1,   171,   172,   173,    -1,   175,    -1,   177,    -1,
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
     299,   300,   301,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    89,    90,    91,    92,    93,    94,    95,    -1,
      -1,    98,    99,    -1,    -1,    -1,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,   116,
      -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
     167,   168,    -1,    -1,   171,   172,   173,    -1,   175,    -1,
     177,    -1,   179,   180,    -1,   182,   183,   184,    -1,   186,
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
     297,   298,   299,   300,   301,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
      -1,   116,    -1,   118,   119,   120,   121,    -1,   123,    -1,
      -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,   167,   168,    -1,    -1,   171,   172,   173,    -1,
      -1,    -1,   177,    -1,   179,   180,    -1,   182,   183,   184,
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
     295,   296,   297,   298,   299,   300,   301,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    89,    90,    91,    92,
      93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,    -1,   116,    -1,   118,   119,   120,   121,    -1,
     123,    -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,   167,   168,    -1,    -1,   171,   172,
     173,    -1,    -1,    -1,   177,    -1,   179,   180,    -1,   182,
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
     293,   294,   295,   296,   297,   298,   299,   300,   301,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    89,    90,
      91,    92,    93,    94,    95,    -1,    -1,    98,    99,    -1,
      -1,    -1,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    -1,    -1,   116,    -1,   118,   119,   120,
     121,    -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,
     131,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,   167,   168,    -1,    -1,
     171,   172,   173,    -1,    -1,    -1,   177,    -1,   179,   180,
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
     301,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    88,
      89,    90,    91,    92,    93,    94,    95,    -1,    -1,    98,
      99,    -1,    -1,    -1,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    -1,    -1,   116,    -1,   118,
     119,   120,   121,    -1,   123,    -1,    -1,    -1,   127,   128,
     129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,   167,   168,
      -1,    -1,   171,   172,   173,    -1,    -1,    -1,   177,    -1,
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
     299,   300,   301,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    89,    90,    91,    92,    93,    94,    95,    -1,
      -1,    98,    99,    -1,    -1,    -1,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,   116,
      -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
     167,   168,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,
     177,    -1,   179,   180,    -1,   182,   183,   184,    -1,   186,
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
     297,   298,   299,   300,   301,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
      -1,   116,    -1,   118,   119,   120,   121,    -1,   123,    -1,
      -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,   148,   149,    -1,   151,   152,    -1,    -1,
      -1,    -1,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,    -1,   171,   172,   173,    -1,
      -1,    -1,   177,    -1,   179,   180,    -1,   182,   183,   184,
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
     295,   296,   297,   298,   299,   300,   301,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    89,    90,    91,    92,
      93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,    -1,   116,    -1,   118,   119,   120,   121,    -1,
     123,    -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,   148,   149,    -1,   151,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,    -1,   171,   172,
     173,    -1,    -1,    -1,   177,    -1,   179,   180,    -1,    -1,
      -1,   184,    -1,   186,    -1,   188,   189,   190,   191,   192,
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
     293,   294,   295,   296,   297,   298,   299,   300,   301,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    89,    90,
      91,    -1,    93,    94,    95,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,   104,   105,   106,   107,   108,   109,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,
     121,    -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,
     131,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
      -1,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,
     151,   152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,
     161,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,
     171,   172,   173,    -1,    -1,    -1,   177,    -1,   179,   180,
      -1,    -1,    -1,   184,    -1,   186,    -1,   188,   189,   190,
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
     301,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    88,
      89,    90,    91,    -1,    93,    94,    95,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,   104,   105,   106,   107,   108,
     109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
     119,   120,   121,    -1,   123,    -1,    -1,    -1,   127,   128,
     129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,    -1,   142,   143,   144,    -1,    -1,    -1,    -1,
      -1,    -1,   151,   152,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,
      -1,    -1,   171,   172,   173,    -1,    -1,    -1,   177,    -1,
     179,   180,    -1,    -1,    -1,   184,    -1,   186,    -1,   188,
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
     299,   300,   301,    14,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    89,    90,
      91,    -1,    93,    94,    95,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,   104,   105,   106,   107,   108,   109,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,
     121,    -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,
     131,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
      -1,   142,   143,   144,   145,    -1,    -1,   148,    -1,    -1,
     151,   152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,
     161,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,
     171,   172,   173,    -1,    -1,    -1,   177,    -1,   179,   180,
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
     301,    14,    -1,    -1,    -1,    18,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    89,    90,    91,    -1,
      93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,   104,   105,   106,   107,   108,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,    -1,
     123,    -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,    -1,   142,
     143,   144,    -1,    -1,    -1,    -1,    -1,    -1,   151,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,
     173,    -1,    -1,    -1,   177,   178,   179,   180,    -1,    -1,
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
     293,   294,   295,   296,   297,   298,   299,   300,   301,    14,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    89,    90,    91,    -1,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,   104,
     105,   106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,   119,   120,   121,    -1,   123,    -1,
      -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,    -1,   142,   143,   144,
      -1,    -1,    -1,    -1,    -1,    -1,   151,   152,    -1,    -1,
      -1,    -1,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,    -1,    -1,   171,   172,   173,    -1,
      -1,    -1,   177,    -1,   179,   180,    -1,    -1,    -1,    -1,
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
     295,   296,   297,   298,   299,   300,   301,    16,    -1,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    88,
      89,    90,    91,    -1,    93,    94,    95,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,   104,   105,   106,   107,   108,
     109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
     119,   120,   121,    -1,   123,    -1,    -1,    -1,   127,   128,
     129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,    -1,   142,   143,   144,    -1,    -1,    -1,    -1,
      -1,    -1,   151,   152,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,
      -1,    -1,   171,   172,   173,    -1,    -1,    -1,   177,    -1,
     179,   180,    -1,    -1,    -1,    -1,    -1,   186,    -1,   188,
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
     299,   300,   301,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    89,    90,    91,    -1,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,   104,
     105,   106,   107,   108,   109,   110,    -1,    -1,    -1,   114,
      -1,    -1,    -1,   118,   119,   120,   121,    -1,   123,    -1,
      -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,    -1,   142,   143,   144,
     145,    -1,    -1,   148,    -1,    -1,   151,   152,    -1,    -1,
      -1,    -1,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,    -1,    -1,   171,   172,   173,    -1,
      -1,    -1,   177,    -1,   179,   180,    -1,    -1,    -1,    -1,
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
     295,   296,   297,   298,   299,   300,   301,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    89,    90,
      91,    -1,    93,    94,    95,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,   104,   105,   106,   107,   108,   109,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,
     121,    -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,
     131,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
      -1,   142,   143,   144,    -1,    -1,    -1,   148,    -1,    -1,
     151,   152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,
     161,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,
     171,   172,   173,    -1,    -1,    -1,   177,   178,   179,   180,
      -1,    -1,    -1,   184,    -1,   186,    -1,   188,   189,   190,
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
     301,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    89,    90,    91,    -1,    93,    94,    95,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,   104,   105,   106,
     107,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,    -1,   142,   143,   144,   145,    -1,
      -1,   148,    -1,    -1,   151,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,    -1,
      -1,    -1,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,
     177,    -1,   179,   180,    -1,    -1,    -1,    -1,    -1,   186,
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
     297,   298,   299,   300,   301,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    89,    90,    91,    -1,
      93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,   104,   105,   106,   107,   108,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,    -1,
     123,    -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,    -1,   142,
     143,   144,    -1,    -1,    -1,    -1,    -1,    -1,   151,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,
     173,    -1,    -1,    -1,   177,   178,   179,   180,    -1,    -1,
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
     293,   294,   295,   296,   297,   298,   299,   300,   301,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    88,
      89,    90,    91,    -1,    93,    94,    95,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,   104,   105,   106,   107,   108,
     109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
     119,   120,   121,    -1,   123,    -1,    -1,    -1,   127,   128,
     129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,    -1,   142,   143,   144,    -1,    -1,    -1,    -1,
      -1,    -1,   151,   152,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,
      -1,    -1,   171,   172,   173,    -1,    -1,    -1,   177,   178,
     179,   180,    -1,    -1,    -1,   184,    -1,   186,    -1,   188,
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
     299,   300,   301,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    89,    90,    91,    -1,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,   104,
     105,   106,   107,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,    -1,    -1,   118,   119,   120,   121,    -1,   123,    -1,
      -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,    -1,   142,   143,   144,
      -1,    -1,    -1,   148,    -1,    -1,   151,   152,    -1,    -1,
      -1,    -1,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,    -1,    -1,   171,   172,   173,    -1,
      -1,    -1,   177,    -1,   179,   180,    -1,    -1,    -1,    -1,
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
     295,   296,   297,   298,   299,   300,   301,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    89,    90,
      91,    -1,    93,    94,    95,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,   104,   105,   106,   107,   108,   109,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,
     121,    -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,
     131,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
      -1,   142,   143,   144,    -1,    -1,    -1,   148,    -1,    -1,
     151,   152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,
     161,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,
     171,   172,   173,    -1,    -1,    -1,   177,    -1,   179,   180,
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
     301,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    89,    90,    91,    -1,    93,    94,    95,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,   104,   105,   106,
     107,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,    -1,   142,   143,   144,    -1,    -1,
      -1,   148,    -1,    -1,   151,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,    -1,
      -1,    -1,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,
     177,    -1,   179,   180,    -1,    -1,    -1,    -1,    -1,   186,
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
     297,   298,   299,   300,   301,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    89,    90,    91,    -1,
      93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,   104,   105,   106,   107,   108,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,    -1,
     123,    -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,    -1,   142,
     143,   144,    -1,    -1,    -1,    -1,    -1,    -1,   151,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,
     173,    -1,    -1,    -1,   177,    -1,   179,   180,    -1,    -1,
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
     293,   294,   295,   296,   297,   298,   299,   300,   301
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,     3,    10,    17,    18,    20,    25,    26,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    88,    89,    90,    91,    92,
      93,    94,    95,    98,    99,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   116,   118,   119,   120,
     121,   123,   127,   128,   129,   130,   131,   138,   139,   140,
     141,   142,   143,   144,   148,   149,   150,   151,   152,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   167,   168,
     171,   172,   173,   177,   179,   180,   182,   183,   184,   186,
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
     295,   296,   297,   298,   299,   300,   301,   302,   317,   318,
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
     535,   540,   541,   542,   543,   544,   545,   548,   554,   608,
     609,    28,    29,    31,    32,    34,    40,    48,    50,    51,
      58,    60,    69,    73,   104,   105,   106,   152,   161,   192,
     211,   221,   253,   279,   280,   281,   282,   283,   285,   286,
     287,   288,   289,   294,   295,   355,   356,   376,   377,   378,
     379,   152,   145,   148,   145,   148,    25,    26,    30,    35,
      36,    37,    38,    39,    40,    41,    42,    44,    52,    54,
      56,    57,    59,    62,    65,    67,    68,    70,    84,    85,
      91,    98,   107,   108,   127,   130,   131,   145,   148,   161,
     164,   171,   172,   180,   192,   205,   215,   216,   217,   219,
     220,   227,   229,   230,   231,   232,   235,   236,   238,   608,
     145,    61,    66,   111,   391,   148,   365,   148,    26,    55,
     111,    39,    14,   145,   148,   553,   608,   148,   148,   111,
     111,   145,   148,   148,   148,    88,   145,   212,   213,   114,
     114,   114,   145,   148,   608,    30,    37,    54,    65,    91,
     471,   608,   114,   114,   114,   608,   111,   114,   114,   178,
     385,   608,   145,   114,   553,    16,   608,   114,   114,   114,
     463,   145,    21,   204,   206,   216,   218,   148,   216,   218,
     216,   216,   221,   111,   145,   367,   233,   233,   234,   148,
     145,   111,   318,   319,     0,   318,   321,   322,    25,    42,
     324,   384,   181,   181,   100,   181,   386,    33,    39,    44,
      52,    64,   160,   163,   177,   202,   390,   395,   396,   397,
     414,   415,   419,   401,   402,   608,   159,    86,   124,   132,
     133,   135,   143,   147,   149,   154,   170,   193,   194,   195,
     196,   197,   198,   455,   456,   241,   150,   167,   189,   110,
     138,   151,   184,   191,   200,   128,   142,    43,   190,    94,
      95,   150,   167,   454,   145,   460,   463,   182,   183,   146,
     475,   476,   471,   475,   471,   148,   475,   137,   148,    20,
     552,   173,   186,   173,   186,   158,   173,   376,   608,   376,
     608,   161,   192,    40,   377,    40,   608,   144,   111,   353,
      37,    40,    73,    99,   160,   553,   212,   213,   214,   292,
     293,   238,   581,   608,   285,   608,   290,   290,   292,   293,
     296,   279,   287,   356,   553,   385,   178,   385,    37,    57,
     178,   528,   529,   385,   178,   184,   608,   145,   388,   276,
     276,   111,   409,   111,   178,   380,   381,   145,   382,   385,
     152,   552,   106,   152,   347,   552,   406,   408,   608,   111,
     385,    20,   178,   553,   145,   608,   608,   608,   427,   428,
     608,   385,   178,   385,   385,   530,   608,   385,   145,   145,
     385,   178,   184,   608,   145,   427,   178,    27,   491,   492,
     493,   385,     7,   166,    15,   385,   204,    20,   388,   388,
     178,   388,   388,   388,   388,   222,   546,   547,   608,   368,
     388,   388,   385,   407,   413,   608,   318,   326,   327,    25,
     328,   388,   387,   111,   160,   162,   162,   388,   388,   100,
      88,    90,   139,   265,   403,   404,   514,   438,   439,   441,
     441,   441,   441,   440,   441,   441,   441,    65,   445,   445,
     444,   446,   446,   446,   446,   447,   447,   448,   448,   222,
      88,    88,    88,   175,   385,   463,   463,   385,   476,   178,
     388,   486,   141,   178,   486,   100,   100,   365,    20,   608,
     608,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,   330,   331,   332,    88,   129,   134,   350,   351,   352,
     608,   129,   134,   152,   152,   330,   552,   119,   124,    47,
      50,    93,   243,   256,   258,   269,   270,   271,   273,   275,
     582,   583,   584,   585,   586,   587,   594,   600,   601,   238,
      88,   228,   359,   291,   608,   608,   608,   124,   175,   175,
     178,   178,   175,   100,   178,   100,   178,   175,   385,   175,
     608,    49,   208,   246,   392,   393,   608,    88,   100,   178,
     385,   178,   553,    90,    37,   553,   552,    90,   100,   134,
     404,   514,   175,   178,   178,   175,   385,   178,   178,   134,
     100,   179,   139,   514,   175,   178,   178,   145,   175,   385,
     385,   175,   100,   178,   100,   178,   175,   385,   179,   608,
     492,   493,   122,   187,   175,   175,   123,   181,    88,   209,
     210,   224,    88,   209,   210,   224,    88,   228,   216,   100,
     226,   134,    25,   369,   385,   178,   175,    38,   100,   181,
     106,   181,   608,   162,   388,   420,   421,   111,   416,   417,
     111,    40,   144,   148,   201,   515,   517,   519,   520,   536,
     537,   538,   539,   608,   111,   388,   111,   139,   404,   139,
     139,   403,   404,   441,   145,   148,   251,   459,   478,   555,
     558,   559,   560,   561,   562,   566,   568,   570,   571,   515,
     515,   513,   519,   513,   175,   176,   100,   178,   178,   140,
     157,   140,   157,   129,   145,   383,   365,   365,   331,   124,
     517,   352,   388,   514,   134,   388,   552,   552,   120,   121,
     552,   269,   270,   271,   275,   608,   255,   266,   255,   266,
      20,   278,    90,   106,   148,   588,   591,   582,    30,    36,
      54,    56,    65,    91,   216,   358,   520,   283,   284,   218,
     291,   300,    88,   359,   291,   552,   145,   530,   531,   608,
     530,   531,   175,   139,   514,   246,    46,    53,    71,   111,
     403,   410,   411,   412,   393,   514,   515,   381,    88,   175,
     188,   124,   346,   552,   152,   124,    90,   346,   111,   388,
     134,   134,   404,   145,   175,   388,   111,   388,   388,   139,
      93,   430,   431,   432,    93,   434,   435,   385,   175,   175,
     145,   530,   530,   175,   388,    27,   493,   122,   187,     8,
       9,    96,   115,   117,   185,   382,   488,   490,   501,   502,
     505,    20,   223,   225,   388,   388,   388,   223,   225,   388,
     388,   388,   388,   388,   388,   111,   388,   388,   353,   370,
     100,   181,   175,   367,   237,   549,   550,   145,   111,   420,
      89,    99,   109,   119,   422,   423,   424,   425,   100,   608,
     100,   402,   148,   148,   517,   148,   136,   167,   184,   516,
     608,   608,   388,   139,   388,   388,   139,   404,   139,   385,
     555,   562,   145,   277,   442,   607,    90,   161,   244,   245,
     247,   254,   264,   276,   556,   557,   576,   577,   578,   579,
     602,   605,   250,   252,   563,   581,   259,   567,   603,   239,
     240,   262,   572,   573,   136,   388,   385,   129,   367,   129,
     145,   532,   351,   388,   278,    20,    90,   106,   148,   595,
      20,   588,   359,   516,   218,   218,   461,   279,   298,   358,
     218,   181,   175,   385,   178,   178,   136,   178,   178,   388,
     139,   111,   111,   388,   608,   412,    71,   515,   388,   552,
     100,   346,   408,   388,   388,   134,   175,   385,   428,   388,
     388,   106,   431,    93,   177,   111,   515,   106,   435,   175,
     175,   385,   178,   178,   124,   185,   490,     6,   608,   185,
     501,   181,   224,   224,   224,   224,   228,   547,   177,   134,
     370,   472,   551,   550,   388,   413,   552,   120,   121,   424,
     425,   425,   421,    99,   418,   417,   178,   184,   515,   518,
     178,   178,   178,   388,   388,   139,   388,   175,   178,   555,
     569,   242,   208,   246,   260,   267,   606,    90,   248,   249,
     604,   242,   559,   606,   444,   576,   560,   139,   274,   564,
     565,   604,   278,   575,    72,   574,   175,   387,    20,   128,
     191,   597,   598,   599,    20,   596,   597,   263,   592,   589,
     590,   591,   162,   608,   249,   359,   461,   175,   388,   608,
     608,   411,   388,   118,    90,   552,   388,   175,   177,   388,
     388,   608,   177,   111,   177,   175,   493,   608,   185,   493,
     608,   388,   388,   388,   388,   388,   388,   388,   148,   200,
     383,   175,   425,   552,    88,   178,   100,   178,   388,   175,
     446,    45,   121,   444,   444,   261,   268,   278,   580,   580,
     561,   145,   272,   175,   595,   595,   599,   100,   178,    20,
     593,   604,   178,   100,   361,   362,   461,   111,   216,   299,
     279,   162,    46,   388,   346,   388,    88,   388,   608,   388,
      87,   174,   494,   493,   608,   187,   493,   111,   472,   515,
     515,    88,   444,   444,   189,   385,    20,   257,   591,   100,
     425,   514,   608,   111,   216,   608,   361,   111,   515,   177,
       4,   125,   497,   498,   500,   502,    19,   126,   495,   496,
     499,   502,   187,   493,   187,   608,   515,   444,   175,   362,
     425,   297,   608,   111,   216,   608,   177,   388,    87,   125,
     500,   174,   126,   499,   187,   100,   178,   388,   297,   608,
     111,   388,   111,   383,   285,   297,   608,   608,   298,   388,
     298,   100,   178,   461,   461,   111,   383,   189,   608,   279,
     178,   608,   383,   216,   111,   608,   298,   461
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
     565,   566,   567,   568,   569,   570
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   316,   317,   317,   317,   317,   317,   317,   318,   319,
     319,   319,   319,   320,   320,   321,   321,   322,   322,   323,
     324,   324,   324,   325,   325,   326,   326,   327,   327,   327,
     327,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     329,   329,   330,   330,   331,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   333,   333,   333,   333,   333,
     333,   333,   333,   334,   334,   335,   336,   336,   337,   337,
     338,   339,   340,   340,   341,   341,   342,   342,   342,   342,
     343,   344,   345,   345,   345,   345,   346,   346,   347,   347,
     348,   348,   348,   348,   349,   350,   350,   351,   351,   351,
     352,   353,   353,   354,   354,   354,   355,   355,   356,   356,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     356,   356,   357,   357,   357,   357,   357,   357,   357,   357,
     358,   358,   359,   359,   360,   360,   361,   361,   362,   362,
     362,   362,   363,   363,   363,   363,   364,   364,   365,   365,
     365,   365,   366,   367,   368,   368,   369,   369,   370,   370,
     371,   372,   373,   374,   374,   375,   375,   375,   376,   376,
     376,   376,   377,   377,   378,   378,   379,   379,   380,   380,
     381,   381,   382,   383,   384,   385,   385,   386,   386,   387,
     387,   388,   388,   388,   388,   388,   388,   388,   388,   388,
     388,   388,   388,   388,   388,   388,   388,   388,   388,   389,
     390,   391,   391,   392,   392,   392,   393,   393,   394,   394,
     395,   396,   396,   396,   397,   397,   397,   397,   397,   398,
     398,   399,   399,   400,   401,   401,   402,   402,   402,   402,
     402,   402,   402,   402,   403,   404,   405,   406,   406,   407,
     407,   408,   408,   408,   408,   409,   409,   410,   410,   410,
     411,   411,   411,   412,   412,   412,   413,   414,   415,   416,
     416,   417,   417,   418,   419,   419,   420,   420,   421,   421,
     422,   422,   422,   422,   422,   422,   422,   423,   423,   424,
     424,   425,   426,   426,   427,   427,   428,   428,   429,   430,
     430,   431,   432,   432,   433,   433,   434,   434,   435,   435,
     436,   437,   437,   438,   438,   439,   439,   439,   439,   439,
     440,   439,   439,   439,   439,   441,   441,   442,   442,   443,
     443,   444,   444,   444,   445,   445,   445,   445,   445,   446,
     446,   446,   447,   447,   447,   448,   448,   449,   449,   450,
     450,   451,   451,   452,   452,   453,   453,   453,   453,   454,
     454,   454,   455,   455,   455,   455,   455,   455,   456,   456,
     456,   457,   457,   457,   457,   458,   458,   459,   459,   460,
     460,   461,   461,   461,   461,   462,   463,   463,   463,   464,
     464,   465,   465,   465,   465,   466,   466,   467,   467,   467,
     467,   467,   467,   467,   468,   468,   469,   469,   470,   470,
     470,   470,   470,   471,   471,   472,   472,   473,   473,   473,
     474,   474,   474,   474,   475,   475,   476,   477,   477,   477,
     477,   477,   477,   477,   477,   477,   478,   478,   479,   479,
     479,   480,   481,   481,   482,   483,   484,   485,   485,   486,
     486,   487,   487,   488,   488,   488,   489,   489,   489,   489,
     489,   489,   490,   490,   491,   491,   492,   493,   493,   494,
     494,   495,   495,   496,   496,   496,   496,   497,   497,   498,
     498,   498,   498,   499,   499,   500,   500,   501,   501,   501,
     501,   502,   502,   502,   502,   503,   503,   504,   504,   505,
     506,   506,   506,   506,   506,   506,   507,   508,   508,   508,
     508,   509,   509,   509,   509,   510,   511,   512,   512,   512,
     512,   513,   513,   514,   515,   515,   515,   516,   516,   516,
     517,   517,   517,   517,   517,   518,   518,   519,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   521,   522,   522,
     522,   523,   524,   525,   525,   525,   526,   526,   526,   526,
     526,   527,   528,   528,   528,   528,   528,   528,   528,   529,
     530,   531,   532,   533,   533,   534,   535,   536,   536,   537,
     538,   538,   539,   540,   540,   540,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   542,   542,   543,   543,
     544,   545,   546,   546,   547,   548,   549,   549,   550,   550,
     550,   550,   551,   551,   552,   553,   553,   554,   554,   555,
     556,   556,   557,   557,   558,   558,   559,   559,   560,   560,
     561,   561,   562,   563,   563,   564,   564,   565,   566,   566,
     566,   567,   567,   568,   569,   569,   570,   571,   571,   572,
     572,   573,   573,   573,   574,   574,   575,   575,   576,   576,
     576,   576,   576,   577,   578,   579,   580,   580,   580,   581,
     581,   582,   582,   582,   582,   582,   582,   582,   582,   583,
     583,   583,   583,   584,   584,   585,   586,   586,   587,   587,
     587,   588,   588,   589,   589,   590,   590,   591,   592,   592,
     593,   593,   594,   594,   594,   595,   595,   596,   596,   597,
     597,   598,   598,   599,   599,   600,   601,   601,   602,   602,
     602,   603,   604,   604,   604,   604,   605,   605,   606,   606,
     607,   608,   608,   609,   609,   609,   609,   609,   609,   609,
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
     609,   609,   609,   609,   609,   609,   609,   609,   609,   609,
     609,   609,   609,   609,   609,   609,   609
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     1,     2,     2,     3,     1,     1,
       2,     1,     2,     4,     6,     2,     1,     1,     2,     6,
       2,     2,     4,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     3,     3,     5,     5,
       4,     3,     3,     3,     5,     5,     5,     5,     5,     5,
       4,     3,     3,     4,     5,     6,     1,     3,     3,     3,
       3,     6,     5,     8,     4,     3,     1,     1,     1,     2,
       2,     2,     3,     5,     4,     6,     1,     2,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     1,     2,
       2,     2,     3,     4,     5,     6,     4,     5,     6,     7,
       1,     2,     3,     3,     8,     9,     1,     3,     1,     2,
       2,     3,    11,    14,    13,    22,     3,     3,     2,     3,
       4,     5,     2,     4,     3,     0,     3,     2,     1,     3,
       5,     3,     5,     2,     2,     2,     3,     3,     1,     2,
       1,     1,     4,     4,     5,     5,     7,     5,     1,     3,
       2,     3,     3,     3,     1,     1,     2,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     1,     1,     2,     4,     3,     5,     4,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     2,     1,     4,     3,     4,     4,     5,
       4,     5,     5,     6,     3,     3,     3,     1,     4,     1,
       4,     3,     4,     4,     5,     4,     5,     1,     2,     3,
       1,     2,     1,     6,     3,     3,     1,     2,     3,     1,
       3,     2,     3,     2,     3,     4,     1,     3,     1,     2,
       1,     1,     1,     2,     2,     2,     3,     1,     1,     2,
       2,     2,     5,     5,     1,     4,     3,     4,     8,     1,
       2,     3,     2,     3,     8,    10,     1,     2,     4,     7,
       8,     1,     3,     1,     3,     1,     3,     3,     3,     3,
       0,     4,     3,     3,     3,     1,     5,     0,     1,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     4,     1,     4,     1,
       4,     1,     4,     1,     2,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     5,     5,     6,     3,     4,     1,     2,     3,
       2,     1,     2,     2,     1,     1,     1,     3,     3,     1,
       1,     1,     2,     1,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     1,     2,     2,     1,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     4,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     1,     4,     4,     3,     4,     1,
       3,     1,     1,     1,     1,     1,     4,     5,     8,     9,
       9,    10,     1,     2,     1,     2,     6,     0,     1,     3,
       3,     0,     1,     1,     1,     2,     2,     0,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     3,     3,     2,
       1,     1,     1,     1,     1,     1,     4,     4,     5,     6,
       7,     4,     5,     6,     7,     4,     4,     4,     5,     6,
       7,     1,     2,     2,     1,     2,     3,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     4,
       4,     3,     3,     3,     4,     4,     3,     4,     6,     4,
       6,     4,     3,     4,     6,     6,     4,     6,     6,     4,
       1,     2,     1,     1,     1,     3,     3,     1,     1,     4,
       5,     6,     3,     3,     3,     3,     5,     7,     7,     5,
       5,     5,     7,     7,     5,     5,     3,     3,     5,     7,
       5,     7,     1,     4,     3,     5,     1,     2,     3,     7,
      10,    13,     1,     3,     1,     1,     1,     7,     4,     2,
       0,     1,     1,     2,     1,     3,     1,     3,     1,     4,
       1,     2,     3,     0,     1,     0,     1,     4,     2,     3,
       1,     0,     1,     4,     0,     1,     2,     1,     3,     0,
       1,     2,     2,     1,     0,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     1,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     2,     2,     3,     1,     2,     2,     5,
       2,     1,     1,     0,     1,     1,     3,     4,     0,     2,
       0,     2,     4,     4,     3,     2,     3,     1,     3,     0,
       1,     1,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     3,     2,     3,     3,     4,     2,     2,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1
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
  "\"'*:QName'\"", "\"'QName'\"", "\"'quote attribute content'\"",
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
  "\"'digit'\"", "\"'pattern-separator'\"", "\"'ancestor'\"",
  "\"'ancestor-or-self'\"", "\"'and'\"", "\"'''\"", "\"'as'\"",
  "\"'ascending'\"", "\"'at'\"", "\"'attribute'\"", "\"'@'\"",
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
  "\"'+'\"", "\"'PRAGMA BEGIN'\"", "\"'PRAGMA END'\"", "\"'<<'\"",
  "\"'preceding'\"", "\"'preceding-sibling'\"", "\"'preserve'\"",
  "\"'\\\"'\"", "\"'}'\"", "\"']'\"", "\"'return'\"", "\"')'\"",
  "\"'satisfies'\"", "\"'self'\"", "\"';'\"", "\"'/'\"", "\"'//'\"",
  "\"'*'\"", "\"</ (start tag end)\"", "\"'strip'\"", "\"'> (tag end)'\"",
  "\"'then'\"", "\"'to'\"", "\"'treat'\"", "\"'union'\"",
  "\"'unordered'\"", "\"'eq'\"", "\"'ge'\"", "\"'gt'\"", "\"'le'\"",
  "\"'lt'\"", "\"'ne'\"", "\"'VALUECOMP'\"", "\"'|'\"",
  "\"'empty-sequence'\"", "\"'where'\"", "\"'<!--'\"", "\"'-->'\"",
  "\"'xquery'\"", "\"'version'\"", "\"'#)'\"", "\"'start'\"",
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
  "STEP_REDUCE", "$accept", "Module", "UnrecognizedToken",
  "ModuleWithoutBOM", "VersionDecl", "MainModule", "LibraryModule",
  "ModuleDecl", "Prolog", "SIND_DeclList", "VFO_DeclList", "SIND_Decl",
  "VFO_Decl", "DecimalFormatDecl", "DecimalFormatParamList",
  "DecimalFormatParam", "DecimalFormatParamName", "Setter", "Import",
  "NamespaceDecl", "BoundarySpaceDecl", "DefaultNamespaceDecl",
  "OptionDecl", "FTOptionDecl", "OrderingModeDecl", "EmptyOrderDecl",
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
  "EvalExpr", "FTSelection", "opt_FTPosFilter_list", "FTPosFilter_list",
  "FTOr", "FTAnd", "FTMildNot", "FTUnaryNot", "FTPrimaryWithOptions",
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
  "FTIgnoreOption", "QNAME", "KEYWORD", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       317,     0,    -1,   319,    -1,   302,   319,    -1,   318,    -1,
     319,   318,    -1,   302,   318,    -1,   302,   319,   318,    -1,
       3,    -1,   321,    -1,   320,   321,    -1,   322,    -1,   320,
     322,    -1,   205,   206,    20,   181,    -1,   205,   206,    20,
     123,    20,   181,    -1,   324,   384,    -1,   384,    -1,   323,
      -1,   323,   324,    -1,    26,   152,   553,   124,   552,   181,
      -1,   325,   181,    -1,   326,   181,    -1,   325,   181,   326,
     181,    -1,   327,    -1,   325,   181,   327,    -1,   328,    -1,
     326,   181,   328,    -1,   333,    -1,   334,    -1,   335,    -1,
     337,    -1,   354,    -1,   357,    -1,   349,    -1,   329,    -1,
     339,    -1,   375,    -1,   360,    -1,   363,    -1,   338,    -1,
      25,   106,    73,   330,    -1,    25,    73,   608,   330,    -1,
     331,    -1,   330,   331,    -1,   332,   124,   532,    -1,    74,
      -1,    82,    -1,    75,    -1,    76,    -1,    77,    -1,    78,
      -1,    83,    -1,    79,    -1,    80,    -1,    81,    -1,   336,
      -1,   343,    -1,   344,    -1,   364,    -1,   340,    -1,   341,
      -1,   342,    -1,   540,    -1,   345,    -1,   348,    -1,    25,
     152,   553,   124,   552,    -1,    25,    29,   173,    -1,    25,
      29,   186,    -1,    25,   106,    37,   152,   552,    -1,    25,
     106,    40,   152,   552,    -1,    25,    50,   608,    20,    -1,
      25,   253,   581,    -1,    25,    51,   161,    -1,    25,    51,
     192,    -1,    25,   106,   160,   119,   120,    -1,    25,   106,
     160,   119,   121,    -1,    25,    32,   173,   100,   140,    -1,
      25,    32,   173,   100,   157,    -1,    25,    32,   158,   100,
     140,    -1,    25,    32,   158,   100,   157,    -1,    25,   106,
      99,   552,    -1,    25,    28,   552,    -1,    42,    55,   552,
      -1,    42,    55,   347,   552,    -1,    42,    55,   552,    90,
     346,    -1,    42,    55,   347,   552,    90,   346,    -1,   552,
      -1,   346,   100,   552,    -1,   152,   553,   124,    -1,   106,
      37,   152,    -1,    42,    26,   552,    -1,    42,    26,   152,
     553,   124,   552,    -1,    42,    26,   552,    90,   346,    -1,
      42,    26,   152,   553,   124,   552,    90,   346,    -1,    25,
     104,   144,   350,    -1,    88,   517,   351,    -1,   351,    -1,
     352,    -1,   129,    -1,   129,   352,    -1,   134,   388,    -1,
     111,   608,    -1,   111,   608,   514,    -1,    25,   105,   353,
     134,   388,    -1,    25,   105,   353,   129,    -1,    25,   105,
     353,   129,   134,   388,    -1,   356,    -1,   355,   356,    -1,
     280,    -1,   281,    -1,   282,    -1,   283,    -1,   161,    -1,
     192,    -1,   221,   293,    -1,   221,   292,    -1,   294,   293,
      -1,   294,   292,    -1,   285,    -1,   286,   285,    -1,   289,
     290,    -1,   288,   290,    -1,    25,   279,   608,    -1,    25,
     279,   608,   359,    -1,    25,   279,   608,    88,   358,    -1,
      25,   279,   608,    88,   358,   359,    -1,    25,   355,   279,
     608,    -1,    25,   355,   279,   608,   359,    -1,    25,   355,
     279,   608,    88,   358,    -1,    25,   355,   279,   608,    88,
     358,   359,    -1,   520,    -1,   520,   516,    -1,   228,   284,
     218,    -1,   228,   283,   218,    -1,    25,   287,   608,   291,
     218,   461,   162,   361,    -1,    25,   355,   287,   608,   291,
     218,   461,   162,   361,    -1,   362,    -1,   361,   100,   362,
      -1,   461,    -1,   461,   514,    -1,   461,   425,    -1,   461,
     514,   425,    -1,    25,   295,   296,   608,   291,   279,   608,
     111,   608,   297,   388,    -1,    25,   295,   296,   608,   291,
     279,   608,   216,   111,   608,   297,   285,   298,   461,    -1,
      25,   295,   296,   608,   291,   279,   608,   299,   216,   111,
     608,   297,   388,    -1,    25,   295,   296,   608,   300,   298,
     249,   279,   608,   216,   111,   608,   298,   461,   189,   279,
     608,   216,   111,   608,   298,   461,    -1,    25,    31,   173,
      -1,    25,    31,   186,    -1,   148,   178,    -1,   148,   380,
     178,    -1,   148,   178,    88,   515,    -1,   148,   380,   178,
      88,   515,    -1,   229,   367,    -1,   145,   368,   385,   175,
      -1,   368,   369,   181,    -1,    -1,   369,   100,   370,    -1,
      25,   370,    -1,   353,    -1,   353,   134,   388,    -1,    59,
     111,   608,   134,   388,    -1,   232,   234,   388,    -1,   235,
     148,   388,   178,   367,    -1,   230,   233,    -1,   231,   233,
      -1,    25,   376,    -1,    25,    48,   376,    -1,    25,    34,
     376,    -1,   377,    -1,    60,   377,    -1,   379,    -1,   378,
      -1,    40,   608,   365,   383,    -1,    40,   608,   365,   129,
      -1,    58,    40,   608,   365,   367,    -1,    58,    40,   608,
     365,   129,    -1,    69,    40,   608,   365,   145,   387,   175,
      -1,    69,    40,   608,   365,   129,    -1,   381,    -1,   380,
     100,   381,    -1,   111,   608,    -1,   111,   608,   514,    -1,
     145,   385,   175,    -1,   145,   385,   175,    -1,   385,    -1,
     387,    -1,   387,   386,    -1,   181,    -1,   386,   387,   181,
      -1,   388,    -1,   387,   100,   388,    -1,   389,    -1,   426,
      -1,   429,    -1,   433,    -1,   436,    -1,   437,    -1,   541,
      -1,   542,    -1,   544,    -1,   543,    -1,   545,    -1,   548,
      -1,   554,    -1,   372,    -1,   373,    -1,   374,    -1,   371,
      -1,   366,    -1,   398,   390,    -1,   177,   388,    -1,    61,
     276,    -1,    66,   276,    -1,   208,    -1,   246,    -1,    49,
     246,    -1,   392,   410,    71,   388,    -1,   392,    71,   388,
      -1,    39,   391,   409,   393,   393,    -1,    39,   391,   409,
     393,    -1,    33,   111,   608,    -1,   400,    -1,   405,    -1,
     394,    -1,   396,    -1,   414,    -1,   419,    -1,   415,    -1,
     395,    -1,   396,    -1,   398,   397,    -1,    39,   111,    -1,
      52,    39,   111,    -1,   399,   401,    -1,   402,    -1,   401,
     100,   111,   402,    -1,   608,   139,   388,    -1,   608,   514,
     139,   388,    -1,   608,   403,   139,   388,    -1,   608,   514,
     403,   139,   388,    -1,   608,   404,   139,   388,    -1,   608,
     514,   404,   139,   388,    -1,   608,   403,   404,   139,   388,
      -1,   608,   514,   403,   404,   139,   388,    -1,    90,   111,
     608,    -1,   265,   111,   608,    -1,    44,   111,   406,    -1,
     408,    -1,   406,   100,   111,   408,    -1,   413,    -1,   407,
     100,   111,   413,    -1,   608,   134,   388,    -1,   608,   514,
     134,   388,    -1,   608,   404,   134,   388,    -1,   608,   514,
     404,   134,   388,    -1,   111,   608,   139,   388,    -1,   111,
     608,   514,   139,   388,    -1,   411,    -1,   111,   608,    -1,
     111,   608,   411,    -1,   403,    -1,   403,   412,    -1,   412,
      -1,    53,   111,   608,    46,   111,   608,    -1,    46,   111,
     608,    -1,    53,   111,   608,    -1,   608,    -1,   202,   388,
      -1,   163,   162,   416,    -1,   417,    -1,   416,   100,   417,
      -1,   111,   608,    -1,   111,   608,   418,    -1,    99,   552,
      -1,   160,   162,   420,    -1,    64,   160,   162,   420,    -1,
     421,    -1,   420,   100,   421,    -1,   388,    -1,   388,   422,
      -1,   423,    -1,   424,    -1,   425,    -1,   423,   424,    -1,
     423,   425,    -1,   424,   425,    -1,   423,   424,   425,    -1,
      89,    -1,   109,    -1,   119,   120,    -1,   119,   121,    -1,
      99,   552,    -1,    62,   111,   427,   179,   388,    -1,   127,
     111,   427,   179,   388,    -1,   428,    -1,   427,   100,   111,
     428,    -1,   608,   139,   388,    -1,   608,   514,   139,   388,
      -1,    67,   148,   385,   178,   430,   106,   177,   388,    -1,
     431,    -1,   430,   431,    -1,   432,   177,   388,    -1,    93,
     388,    -1,   432,    93,   388,    -1,    68,   148,   385,   178,
     434,   106,   177,   388,    -1,    68,   148,   385,   178,   434,
     106,   111,   608,   177,   388,    -1,   435,    -1,   434,   435,
      -1,    93,   515,   177,   388,    -1,    93,   111,   608,    88,
     515,   177,   388,    -1,    41,   148,   385,   178,   188,   388,
     118,   388,    -1,   438,    -1,   437,   159,   438,    -1,   439,
      -1,   438,    86,   439,    -1,   441,    -1,   441,   455,   441,
      -1,   441,   456,   441,    -1,   441,   124,   441,    -1,   441,
     154,   441,    -1,    -1,   441,   149,   440,   441,    -1,   441,
     147,   441,    -1,   441,   135,   441,    -1,   441,   133,   441,
      -1,   443,    -1,   443,   241,    65,   555,   442,    -1,    -1,
     607,    -1,   444,    -1,   444,   189,   444,    -1,   445,    -1,
     444,   167,   445,    -1,   444,   150,   445,    -1,   446,    -1,
     445,   184,   446,    -1,   445,   110,   446,    -1,   445,   138,
     446,    -1,   445,   151,   446,    -1,   447,    -1,   446,   191,
     447,    -1,   446,   200,   447,    -1,   448,    -1,   447,   142,
     448,    -1,   447,   128,   448,    -1,   449,    -1,   449,    43,
     222,   515,    -1,   450,    -1,   450,   190,    88,   515,    -1,
     451,    -1,   451,    94,    88,   513,    -1,   452,    -1,   452,
      95,    88,   513,    -1,   454,    -1,   453,   454,    -1,   167,
      -1,   150,    -1,   453,   167,    -1,   453,   150,    -1,   457,
      -1,   461,    -1,   458,    -1,   193,    -1,   198,    -1,   197,
      -1,   196,    -1,   195,    -1,   194,    -1,   143,    -1,   170,
      -1,   132,    -1,    70,   145,   385,   175,    -1,    70,   213,
     145,   385,   175,    -1,    70,   212,   145,   385,   175,    -1,
      70,    88,   530,   145,   385,   175,    -1,   459,   145,   175,
      -1,   459,   145,   385,   175,    -1,   460,    -1,   459,   460,
      -1,   168,   608,    15,    -1,   168,    16,    -1,   462,    -1,
     462,   463,    -1,   183,   463,    -1,   463,    -1,   182,    -1,
     464,    -1,   464,   182,   463,    -1,   464,   183,   463,    -1,
     465,    -1,   474,    -1,   466,    -1,   466,   475,    -1,   469,
      -1,   469,   475,    -1,   467,   471,    -1,   468,    -1,    98,
     114,    -1,   107,   114,    -1,    91,   114,    -1,   180,   114,
      -1,   108,   114,    -1,   131,   114,    -1,   130,   114,    -1,
     471,    -1,    92,   471,    -1,   470,   471,    -1,   113,    -1,
     164,   114,    -1,    84,   114,    -1,   172,   114,    -1,   171,
     114,    -1,    85,   114,    -1,   520,    -1,   472,    -1,   608,
      -1,   473,    -1,   184,    -1,    10,    -1,    17,    -1,   477,
      -1,   474,   475,    -1,   474,   148,   178,    -1,   474,   148,
     486,   178,    -1,   476,    -1,   475,   476,    -1,   146,   385,
     176,    -1,   478,    -1,   480,    -1,   481,    -1,   482,    -1,
     485,    -1,   487,    -1,   483,    -1,   484,    -1,   533,    -1,
     479,    -1,   532,    -1,   103,    -1,   141,    -1,   116,    -1,
     111,   608,    -1,   148,   178,    -1,   148,   385,   178,    -1,
     112,    -1,   161,   145,   385,   175,    -1,   192,   145,   385,
     175,    -1,   608,   148,   178,    -1,   608,   148,   486,   178,
      -1,   388,    -1,   486,   100,   388,    -1,   488,    -1,   506,
      -1,   489,    -1,   503,    -1,   504,    -1,   149,   608,   493,
     122,    -1,   149,   608,   491,   493,   122,    -1,   149,   608,
     493,   187,   185,   608,   493,   187,    -1,   149,   608,   493,
     187,   490,   185,   608,   493,   187,    -1,   149,   608,   491,
     493,   187,   185,   608,   493,   187,    -1,   149,   608,   491,
     493,   187,   490,   185,   608,   493,   187,    -1,   501,    -1,
     490,   501,    -1,   492,    -1,   491,   492,    -1,    27,   608,
     493,   124,   493,   494,    -1,    -1,    27,    -1,   174,   495,
     174,    -1,    87,   497,    87,    -1,    -1,   496,    -1,   126,
      -1,   499,    -1,   496,   126,    -1,   496,   499,    -1,    -1,
     498,    -1,   125,    -1,   500,    -1,   498,   125,    -1,   498,
     500,    -1,    19,    -1,   502,    -1,     4,    -1,   502,    -1,
     488,    -1,     9,    -1,   505,    -1,   502,    -1,     8,    -1,
     115,    -1,   117,    -1,   382,    -1,   203,    21,   204,    -1,
     203,   204,    -1,   165,   553,   166,    -1,   165,   553,     7,
      -1,    96,     6,    -1,   507,    -1,   508,    -1,   509,    -1,
     510,    -1,   511,    -1,   512,    -1,    35,   145,   385,   175,
      -1,    37,   608,   145,   175,    -1,    37,   608,   145,   385,
     175,    -1,    37,   145,   385,   175,   145,   175,    -1,    37,
     145,   385,   175,   145,   385,   175,    -1,    91,   608,   145,
     175,    -1,    91,   608,   145,   385,   175,    -1,    91,   145,
     385,   175,   145,   175,    -1,    91,   145,   385,   175,   145,
     385,   175,    -1,    65,   145,   385,   175,    -1,    30,   145,
     385,   175,    -1,    54,   553,   145,   175,    -1,    54,   553,
     145,   385,   175,    -1,    54,   145,   385,   175,   145,   175,
      -1,    54,   145,   385,   175,   145,   385,   175,    -1,   519,
      -1,   519,   136,    -1,    88,   515,    -1,   517,    -1,   517,
     516,    -1,   201,   148,   178,    -1,   136,    -1,   184,    -1,
     167,    -1,   519,    -1,   520,    -1,   144,   148,   178,    -1,
     536,    -1,   539,    -1,   515,    -1,   518,   100,   515,    -1,
     608,    -1,   522,    -1,   528,    -1,   526,    -1,   529,    -1,
     527,    -1,   525,    -1,   524,    -1,   523,    -1,   521,    -1,
     216,   148,   178,    -1,    36,   148,   178,    -1,    36,   148,
     528,   178,    -1,    36,   148,   529,   178,    -1,    65,   148,
     178,    -1,    30,   148,   178,    -1,    54,   148,   178,    -1,
      54,   148,   553,   178,    -1,    54,   148,    20,   178,    -1,
      91,   148,   178,    -1,    91,   148,   608,   178,    -1,    91,
     148,   608,   100,   530,   178,    -1,    91,   148,   184,   178,
      -1,    91,   148,   184,   100,   530,   178,    -1,    56,   148,
     608,   178,    -1,    37,   148,   178,    -1,    37,   148,   608,
     178,    -1,    37,   148,   608,   100,   530,   178,    -1,    37,
     148,   608,   100,   531,   178,    -1,    37,   148,   184,   178,
      -1,    37,   148,   184,   100,   530,   178,    -1,    37,   148,
     184,   100,   531,   178,    -1,    57,   148,   608,   178,    -1,
     608,    -1,   608,   136,    -1,    20,    -1,   534,    -1,   535,
      -1,   608,   137,   141,    -1,    40,   365,   382,    -1,   537,
      -1,   538,    -1,    40,   148,   184,   178,    -1,    40,   148,
     178,    88,   515,    -1,    40,   148,   518,   178,    88,   515,
      -1,   148,   517,   178,    -1,    25,   211,   212,    -1,    25,
     211,   213,    -1,    25,   211,   214,    -1,   217,   216,   388,
     224,   388,    -1,   217,   216,   388,    88,   223,   224,   388,
      -1,   217,   216,   388,    88,   225,   224,   388,    -1,   217,
     216,   388,   209,   388,    -1,   217,   216,   388,   210,   388,
      -1,   217,   218,   388,   224,   388,    -1,   217,   218,   388,
      88,   223,   224,   388,    -1,   217,   218,   388,    88,   225,
     224,   388,    -1,   217,   218,   388,   209,   388,    -1,   217,
     218,   388,   210,   388,    -1,   215,   216,   388,    -1,   215,
     218,   388,    -1,   220,   216,   388,   228,   388,    -1,   220,
     221,   222,   216,   388,   228,   388,    -1,   219,   216,   388,
      88,   388,    -1,   227,   111,   546,   226,   388,   177,   388,
      -1,   547,    -1,   546,   100,   111,   547,    -1,   608,   134,
     388,    -1,   236,   145,   385,   175,   549,    -1,   550,    -1,
     549,   550,    -1,   237,   551,   383,    -1,   237,   551,   148,
     111,   608,   178,   383,    -1,   237,   551,   148,   111,   608,
     100,   111,   608,   178,   383,    -1,   237,   551,   148,   111,
     608,   100,   111,   608,   100,   111,   608,   178,   383,    -1,
     472,    -1,   551,   200,   472,    -1,    20,    -1,    14,    -1,
     608,    -1,   238,   111,   407,    38,   145,   388,   175,    -1,
      38,   145,   388,   175,    -1,   558,   556,    -1,    -1,   557,
      -1,   576,    -1,   557,   576,    -1,   559,    -1,   558,   254,
     559,    -1,   560,    -1,   559,   250,   560,    -1,   561,    -1,
     560,   252,   139,   561,    -1,   562,    -1,   251,   562,    -1,
     566,   563,   564,    -1,    -1,   581,    -1,    -1,   565,    -1,
     274,   145,   385,   175,    -1,   570,   567,    -1,   148,   555,
     178,    -1,   568,    -1,    -1,   603,    -1,   459,   145,   569,
     175,    -1,    -1,   555,    -1,   571,   572,    -1,   478,    -1,
     145,   385,   175,    -1,    -1,   573,    -1,   240,   574,    -1,
     239,   575,    -1,   262,    -1,    -1,    72,    -1,    -1,   278,
      -1,   577,    -1,   578,    -1,   579,    -1,   605,    -1,   602,
      -1,   161,    -1,   276,   444,   580,    -1,   245,   604,   580,
      -1,   278,    -1,   268,    -1,   261,    -1,   238,   582,    -1,
     581,   238,   582,    -1,   583,    -1,   584,    -1,   585,    -1,
     600,    -1,   586,    -1,   594,    -1,   587,    -1,   601,    -1,
      93,   266,    -1,    93,   255,    -1,   258,    -1,   273,    -1,
     243,   266,    -1,   243,   255,    -1,    50,   608,    20,    -1,
     269,    -1,    47,   269,    -1,   271,   588,    -1,   271,   148,
     588,   589,   178,    -1,    47,   271,    -1,   591,    -1,   106,
      -1,    -1,   590,    -1,   591,    -1,   590,   100,   591,    -1,
      90,    20,   592,   593,    -1,    -1,   263,    20,    -1,    -1,
     604,   257,    -1,   270,   278,   595,   597,    -1,   270,   278,
     106,   597,    -1,    47,   270,   278,    -1,    90,    20,    -1,
     148,   596,   178,    -1,    20,    -1,   596,   100,    20,    -1,
      -1,   598,    -1,   599,    -1,   598,   599,    -1,   191,   595,
      -1,   128,   595,    -1,   256,    20,    -1,   275,    -1,    47,
     275,    -1,    90,   208,    -1,    90,   246,    -1,   247,   242,
      -1,   259,   604,   272,    -1,   248,   444,    -1,    90,   121,
     444,    -1,    90,    45,   444,    -1,   249,   444,   189,   444,
      -1,   264,   606,    -1,   244,   606,    -1,   267,    -1,   260,
      -1,   277,   242,   446,    -1,    18,    -1,   609,    -1,   205,
      -1,   119,    -1,    91,    -1,    30,    -1,    36,    -1,    37,
      -1,   144,    -1,    41,    -1,   216,    -1,    54,    -1,    56,
      -1,    57,    -1,    65,    -1,    68,    -1,    67,    -1,   201,
      -1,    29,    -1,   253,    -1,    28,    -1,   213,    -1,   212,
      -1,   138,    -1,    35,    -1,   251,    -1,   252,    -1,   266,
      -1,   255,    -1,   243,    -1,   277,    -1,   269,    -1,   271,
      -1,   270,    -1,   275,    -1,   247,    -1,   242,    -1,    72,
      -1,   208,    -1,   246,    -1,    45,    -1,   214,    -1,   227,
      -1,   294,    -1,   221,    -1,   193,    -1,   198,    -1,   197,
      -1,   196,    -1,   195,    -1,   194,    -1,    90,    -1,   104,
      -1,   105,    -1,   177,    -1,    39,    -1,    52,    -1,    61,
      -1,    66,    -1,    53,    -1,    46,    -1,    49,    -1,    71,
      -1,    33,    -1,   139,    -1,    44,    -1,   202,    -1,   162,
      -1,   163,    -1,   160,    -1,    64,    -1,    89,    -1,   109,
      -1,   120,    -1,   121,    -1,    99,    -1,    62,    -1,   127,
      -1,   179,    -1,    93,    -1,    88,    -1,   188,    -1,   118,
      -1,   159,    -1,    86,    -1,    43,    -1,   222,    -1,    94,
      -1,   189,    -1,   110,    -1,   151,    -1,   191,    -1,   142,
      -1,   128,    -1,    70,    -1,    95,    -1,   190,    -1,   143,
      -1,   173,    -1,   186,    -1,   152,    -1,   129,    -1,   123,
      -1,   158,    -1,   140,    -1,   157,    -1,    25,    -1,    31,
      -1,    51,    -1,   106,    -1,    32,    -1,    50,    -1,   206,
      -1,    42,    -1,    55,    -1,    26,    -1,    40,    -1,   265,
      -1,   241,    -1,   274,    -1,   276,    -1,   245,    -1,   259,
      -1,   272,    -1,   264,    -1,   244,    -1,   258,    -1,   273,
      -1,   263,    -1,   257,    -1,   256,    -1,   240,    -1,   239,
      -1,   262,    -1,   248,    -1,   249,    -1,   278,    -1,   268,
      -1,   267,    -1,   260,    -1,   220,    -1,   226,    -1,   223,
      -1,   217,    -1,   210,    -1,   209,    -1,   211,    -1,   228,
      -1,   218,    -1,   219,    -1,   225,    -1,   215,    -1,   224,
      -1,    60,    -1,    58,    -1,    69,    -1,    34,    -1,    48,
      -1,   161,    -1,   192,    -1,   234,    -1,   229,    -1,   232,
      -1,   233,    -1,   235,    -1,   230,    -1,   231,    -1,   236,
      -1,   237,    -1,    38,    -1,   238,    -1,    59,    -1,   287,
      -1,   285,    -1,   286,    -1,   291,    -1,   292,    -1,   293,
      -1,   288,    -1,   289,    -1,   290,    -1,    73,    -1,    74,
      -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,    79,
      -1,    80,    -1,    81,    -1,    82,    -1,    83,    -1,   279,
      -1,   280,    -1,   281,    -1,   282,    -1,   283,    -1,   284,
      -1,   295,    -1,   296,    -1,   297,    -1,   298,    -1,   299,
      -1,   300,    -1,   301,    -1,    84,    -1,    98,    -1,   107,
      -1,   164,    -1,   171,    -1,   180,    -1,   130,    -1,    85,
      -1,   108,    -1,   131,    -1,   172,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    10,    13,    16,    20,    22,
      24,    27,    29,    32,    37,    44,    47,    49,    51,    54,
      61,    64,    67,    72,    74,    78,    80,    84,    86,    88,
      90,    92,    94,    96,    98,   100,   102,   104,   106,   108,
     110,   115,   120,   122,   125,   129,   131,   133,   135,   137,
     139,   141,   143,   145,   147,   149,   151,   153,   155,   157,
     159,   161,   163,   165,   167,   169,   175,   179,   183,   189,
     195,   200,   204,   208,   212,   218,   224,   230,   236,   242,
     248,   253,   257,   261,   266,   272,   279,   281,   285,   289,
     293,   297,   304,   310,   319,   324,   328,   330,   332,   334,
     337,   340,   343,   347,   353,   358,   365,   367,   370,   372,
     374,   376,   378,   380,   382,   385,   388,   391,   394,   396,
     399,   402,   405,   409,   414,   420,   427,   432,   438,   445,
     453,   455,   458,   462,   466,   475,   485,   487,   491,   493,
     496,   499,   503,   515,   530,   544,   567,   571,   575,   578,
     582,   587,   593,   596,   601,   605,   606,   610,   613,   615,
     619,   625,   629,   635,   638,   641,   644,   648,   652,   654,
     657,   659,   661,   666,   671,   677,   683,   691,   697,   699,
     703,   706,   710,   714,   718,   720,   722,   725,   727,   731,
     733,   737,   739,   741,   743,   745,   747,   749,   751,   753,
     755,   757,   759,   761,   763,   765,   767,   769,   771,   773,
     776,   779,   782,   785,   787,   789,   792,   797,   801,   807,
     812,   816,   818,   820,   822,   824,   826,   828,   830,   832,
     834,   837,   840,   844,   847,   849,   854,   858,   863,   868,
     874,   879,   885,   891,   898,   902,   906,   910,   912,   917,
     919,   924,   928,   933,   938,   944,   949,   955,   957,   960,
     964,   966,   969,   971,   978,   982,   986,   988,   991,   995,
     997,  1001,  1004,  1008,  1011,  1015,  1020,  1022,  1026,  1028,
    1031,  1033,  1035,  1037,  1040,  1043,  1046,  1050,  1052,  1054,
    1057,  1060,  1063,  1069,  1075,  1077,  1082,  1086,  1091,  1100,
    1102,  1105,  1109,  1112,  1116,  1125,  1136,  1138,  1141,  1146,
    1154,  1163,  1165,  1169,  1171,  1175,  1177,  1181,  1185,  1189,
    1193,  1194,  1199,  1203,  1207,  1211,  1213,  1219,  1220,  1222,
    1224,  1228,  1230,  1234,  1238,  1240,  1244,  1248,  1252,  1256,
    1258,  1262,  1266,  1268,  1272,  1276,  1278,  1283,  1285,  1290,
    1292,  1297,  1299,  1304,  1306,  1309,  1311,  1313,  1316,  1319,
    1321,  1323,  1325,  1327,  1329,  1331,  1333,  1335,  1337,  1339,
    1341,  1343,  1348,  1354,  1360,  1367,  1371,  1376,  1378,  1381,
    1385,  1388,  1390,  1393,  1396,  1398,  1400,  1402,  1406,  1410,
    1412,  1414,  1416,  1419,  1421,  1424,  1427,  1429,  1432,  1435,
    1438,  1441,  1444,  1447,  1450,  1452,  1455,  1458,  1460,  1463,
    1466,  1469,  1472,  1475,  1477,  1479,  1481,  1483,  1485,  1487,
    1489,  1491,  1494,  1498,  1503,  1505,  1508,  1512,  1514,  1516,
    1518,  1520,  1522,  1524,  1526,  1528,  1530,  1532,  1534,  1536,
    1538,  1540,  1543,  1546,  1550,  1552,  1557,  1562,  1566,  1571,
    1573,  1577,  1579,  1581,  1583,  1585,  1587,  1592,  1598,  1607,
    1617,  1627,  1638,  1640,  1643,  1645,  1648,  1655,  1656,  1658,
    1662,  1666,  1667,  1669,  1671,  1673,  1676,  1679,  1680,  1682,
    1684,  1686,  1689,  1692,  1694,  1696,  1698,  1700,  1702,  1704,
    1706,  1708,  1710,  1712,  1714,  1716,  1720,  1723,  1727,  1731,
    1734,  1736,  1738,  1740,  1742,  1744,  1746,  1751,  1756,  1762,
    1769,  1777,  1782,  1788,  1795,  1803,  1808,  1813,  1818,  1824,
    1831,  1839,  1841,  1844,  1847,  1849,  1852,  1856,  1858,  1860,
    1862,  1864,  1866,  1870,  1872,  1874,  1876,  1880,  1882,  1884,
    1886,  1888,  1890,  1892,  1894,  1896,  1898,  1900,  1904,  1908,
    1913,  1918,  1922,  1926,  1930,  1935,  1940,  1944,  1949,  1956,
    1961,  1968,  1973,  1977,  1982,  1989,  1996,  2001,  2008,  2015,
    2020,  2022,  2025,  2027,  2029,  2031,  2035,  2039,  2041,  2043,
    2048,  2054,  2061,  2065,  2069,  2073,  2077,  2083,  2091,  2099,
    2105,  2111,  2117,  2125,  2133,  2139,  2145,  2149,  2153,  2159,
    2167,  2173,  2181,  2183,  2188,  2192,  2198,  2200,  2203,  2207,
    2215,  2226,  2240,  2242,  2246,  2248,  2250,  2252,  2260,  2265,
    2268,  2269,  2271,  2273,  2276,  2278,  2282,  2284,  2288,  2290,
    2295,  2297,  2300,  2304,  2305,  2307,  2308,  2310,  2315,  2318,
    2322,  2324,  2325,  2327,  2332,  2333,  2335,  2338,  2340,  2344,
    2345,  2347,  2350,  2353,  2355,  2356,  2358,  2359,  2361,  2363,
    2365,  2367,  2369,  2371,  2373,  2377,  2381,  2383,  2385,  2387,
    2390,  2394,  2396,  2398,  2400,  2402,  2404,  2406,  2408,  2410,
    2413,  2416,  2418,  2420,  2423,  2426,  2430,  2432,  2435,  2438,
    2444,  2447,  2449,  2451,  2452,  2454,  2456,  2460,  2465,  2466,
    2469,  2470,  2473,  2478,  2483,  2487,  2490,  2494,  2496,  2500,
    2501,  2503,  2505,  2508,  2511,  2514,  2517,  2519,  2522,  2525,
    2528,  2531,  2535,  2538,  2542,  2546,  2551,  2554,  2557,  2559,
    2561,  2565,  2567,  2569,  2571,  2573,  2575,  2577,  2579,  2581,
    2583,  2585,  2587,  2589,  2591,  2593,  2595,  2597,  2599,  2601,
    2603,  2605,  2607,  2609,  2611,  2613,  2615,  2617,  2619,  2621,
    2623,  2625,  2627,  2629,  2631,  2633,  2635,  2637,  2639,  2641,
    2643,  2645,  2647,  2649,  2651,  2653,  2655,  2657,  2659,  2661,
    2663,  2665,  2667,  2669,  2671,  2673,  2675,  2677,  2679,  2681,
    2683,  2685,  2687,  2689,  2691,  2693,  2695,  2697,  2699,  2701,
    2703,  2705,  2707,  2709,  2711,  2713,  2715,  2717,  2719,  2721,
    2723,  2725,  2727,  2729,  2731,  2733,  2735,  2737,  2739,  2741,
    2743,  2745,  2747,  2749,  2751,  2753,  2755,  2757,  2759,  2761,
    2763,  2765,  2767,  2769,  2771,  2773,  2775,  2777,  2779,  2781,
    2783,  2785,  2787,  2789,  2791,  2793,  2795,  2797,  2799,  2801,
    2803,  2805,  2807,  2809,  2811,  2813,  2815,  2817,  2819,  2821,
    2823,  2825,  2827,  2829,  2831,  2833,  2835,  2837,  2839,  2841,
    2843,  2845,  2847,  2849,  2851,  2853,  2855,  2857,  2859,  2861,
    2863,  2865,  2867,  2869,  2871,  2873,  2875,  2877,  2879,  2881,
    2883,  2885,  2887,  2889,  2891,  2893,  2895,  2897,  2899,  2901,
    2903,  2905,  2907,  2909,  2911,  2913,  2915,  2917,  2919,  2921,
    2923,  2925,  2927,  2929,  2931,  2933,  2935,  2937,  2939,  2941,
    2943,  2945,  2947,  2949,  2951,  2953,  2955,  2957,  2959,  2961,
    2963,  2965,  2967,  2969,  2971,  2973,  2975,  2977,  2979,  2981,
    2983,  2985,  2987,  2989,  2991,  2993,  2995
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1024,  1024,  1025,  1030,  1031,  1032,  1033,  1037,  1052,
    1057,  1064,  1069,  1080,  1085,  1093,  1101,  1109,  1115,  1127,
    1136,  1140,  1144,  1156,  1162,  1172,  1178,  1188,  1189,  1190,
    1191,  1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,
    1210,  1215,  1224,  1230,  1239,  1248,  1249,  1250,  1251,  1252,
    1253,  1254,  1255,  1256,  1257,  1262,  1263,  1264,  1265,  1266,
    1267,  1268,  1271,  1276,  1277,  1287,  1296,  1302,  1312,  1318,
    1328,  1338,  1346,  1352,  1363,  1368,  1378,  1384,  1390,  1396,
    1413,  1421,  1429,  1433,  1442,  1451,  1464,  1470,  1481,  1485,
    1493,  1498,  1503,  1510,  1523,  1530,  1536,  1543,  1549,  1553,
    1560,  1571,  1575,  1583,  1589,  1595,  1604,  1610,  1619,  1623,
    1629,  1633,  1637,  1641,  1647,  1653,  1659,  1665,  1671,  1675,
    1681,  1687,  1694,  1702,  1710,  1718,  1726,  1738,  1752,  1766,
    1783,  1787,  1796,  1800,  1807,  1815,  1833,  1839,  1847,  1852,
    1859,  1866,  1876,  1886,  1896,  1906,  1923,  1929,  1940,  1944,
    1948,  1952,  1961,  1968,  1987,  1997,  2003,  2009,  2019,  2026,
    2037,  2044,  2051,  2063,  2067,  2074,  2079,  2094,  2111,  2115,
    2119,  2123,  2131,  2141,  2155,  2165,  2179,  2189,  2204,  2210,
    2222,  2226,  2237,  2244,  2252,  2267,  2271,  2285,  2289,  2298,
    2302,  2316,  2317,  2318,  2319,  2320,  2321,  2324,  2325,  2326,
    2327,  2328,  2330,  2331,  2334,  2335,  2336,  2337,  2338,  2343,
    2358,  2365,  2369,  2376,  2380,  2384,  2391,  2399,  2410,  2420,
    2433,  2442,  2443,  2444,  2448,  2449,  2450,  2451,  2452,  2455,
    2461,  2470,  2474,  2482,  2492,  2498,  2510,  2514,  2522,  2531,
    2541,  2549,  2558,  2567,  2582,  2591,  2601,  2609,  2615,  2624,
    2630,  2642,  2650,  2660,  2668,  2680,  2686,  2697,  2699,  2703,
    2711,  2715,  2720,  2724,  2728,  2732,  2740,  2754,  2762,  2769,
    2775,  2786,  2790,  2799,  2807,  2813,  2823,  2829,  2839,  2843,
    2853,  2859,  2865,  2871,  2880,  2889,  2898,  2911,  2915,  2923,
    2929,  2939,  2947,  2956,  2969,  2976,  2988,  2992,  3004,  3011,
    3017,  3026,  3033,  3039,  3051,  3058,  3071,  3077,  3089,  3095,
    3107,  3116,  3120,  3129,  3133,  3141,  3145,  3155,  3162,  3171,
    3181,  3180,  3194,  3203,  3212,  3225,  3229,  3242,  3245,  3252,
    3256,  3265,  3269,  3273,  3282,  3286,  3292,  3298,  3304,  3315,
    3319,  3323,  3331,  3335,  3341,  3351,  3355,  3365,  3369,  3379,
    3383,  3393,  3397,  3407,  3411,  3419,  3423,  3427,  3431,  3441,
    3445,  3449,  3457,  3461,  3465,  3469,  3473,  3477,  3485,  3489,
    3493,  3501,  3505,  3509,  3513,  3524,  3530,  3540,  3546,  3556,
    3560,  3598,  3604,  3610,  3616,  3627,  3635,  3646,  3652,  3662,
    3666,  3674,  3680,  3688,  3694,  3706,  3712,  3722,  3726,  3730,
    3734,  3738,  3744,  3750,  3773,  3777,  3785,  3789,  3800,  3804,
    3808,  3814,  3818,  3832,  3836,  3844,  3848,  3858,  3862,  3866,
    3875,  3879,  3885,  3889,  3897,  3903,  3913,  3921,  3925,  3929,
    3933,  3937,  3941,  3945,  3949,  3953,  3961,  3965,  3973,  3980,
    3987,  3998,  4006,  4010,  4018,  4026,  4034,  4088,  4092,  4105,
    4111,  4121,  4125,  4133,  4137,  4141,  4149,  4159,  4169,  4179,
    4189,  4199,  4214,  4220,  4231,  4237,  4248,  4259,  4261,  4265,
    4270,  4280,  4283,  4290,  4298,  4304,  4314,  4327,  4330,  4337,
    4343,  4349,  4356,  4367,  4371,  4381,  4385,  4395,  4399,  4403,
    4408,  4417,  4423,  4429,  4435,  4445,  4449,  4461,  4465,  4477,
    4489,  4493,  4497,  4501,  4505,  4509,  4517,  4525,  4531,  4537,
    4541,  4558,  4562,  4566,  4570,  4578,  4586,  4594,  4598,  4602,
    4606,  4614,  4620,  4630,  4638,  4642,  4648,  4683,  4689,  4695,
    4705,  4709,  4713,  4717,  4721,  4728,  4734,  4744,  4752,  4756,
    4760,  4764,  4768,  4772,  4776,  4780,  4784,  4792,  4800,  4804,
    4808,  4818,  4826,  4834,  4838,  4842,  4850,  4854,  4860,  4866,
    4870,  4880,  4888,  4892,  4898,  4907,  4916,  4922,  4928,  4938,
    4955,  4962,  4977,  5013,  5017,  5026,  5035,  5045,  5049,  5058,
    5067,  5071,  5082,  5099,  5105,  5111,  5121,  5125,  5131,  5137,
    5141,  5147,  5151,  5157,  5163,  5170,  5180,  5185,  5193,  5199,
    5209,  5231,  5240,  5246,  5259,  5273,  5280,  5286,  5296,  5301,
    5307,  5317,  5330,  5336,  5346,  5356,  5357,  5376,  5382,  5397,
    5406,  5409,  5416,  5421,  5429,  5433,  5440,  5444,  5451,  5455,
    5462,  5466,  5475,  5488,  5491,  5499,  5502,  5510,  5518,  5526,
    5530,  5538,  5541,  5549,  5561,  5564,  5572,  5584,  5590,  5600,
    5603,  5611,  5615,  5619,  5627,  5630,  5638,  5641,  5649,  5653,
    5657,  5661,  5665,  5673,  5681,  5693,  5705,  5709,  5713,  5721,
    5727,  5737,  5741,  5745,  5749,  5753,  5757,  5761,  5765,  5773,
    5777,  5781,  5785,  5793,  5799,  5809,  5819,  5823,  5831,  5841,
    5852,  5859,  5863,  5871,  5874,  5881,  5886,  5895,  5905,  5908,
    5916,  5919,  5927,  5936,  5943,  5953,  5957,  5964,  5970,  5980,
    5983,  5990,  5995,  6007,  6015,  6027,  6035,  6039,  6047,  6051,
    6055,  6063,  6071,  6075,  6079,  6083,  6091,  6099,  6111,  6115,
    6123,  6136,  6140,  6147,  6148,  6149,  6150,  6151,  6152,  6153,
    6154,  6155,  6156,  6157,  6158,  6159,  6160,  6161,  6162,  6163,
    6164,  6165,  6166,  6167,  6168,  6169,  6170,  6171,  6172,  6173,
    6174,  6175,  6176,  6177,  6178,  6179,  6180,  6181,  6182,  6183,
    6184,  6185,  6186,  6187,  6188,  6189,  6190,  6191,  6192,  6193,
    6194,  6195,  6196,  6197,  6198,  6199,  6200,  6201,  6202,  6203,
    6204,  6205,  6206,  6207,  6208,  6209,  6210,  6211,  6212,  6213,
    6214,  6215,  6216,  6217,  6218,  6219,  6220,  6221,  6222,  6223,
    6224,  6225,  6226,  6227,  6228,  6229,  6230,  6231,  6232,  6233,
    6234,  6235,  6236,  6237,  6238,  6239,  6240,  6241,  6242,  6243,
    6244,  6245,  6246,  6247,  6248,  6249,  6250,  6251,  6252,  6253,
    6254,  6255,  6256,  6257,  6258,  6259,  6260,  6261,  6262,  6263,
    6264,  6265,  6266,  6267,  6268,  6269,  6270,  6271,  6272,  6273,
    6274,  6275,  6276,  6277,  6278,  6279,  6280,  6281,  6282,  6283,
    6284,  6285,  6286,  6287,  6288,  6289,  6290,  6291,  6292,  6293,
    6294,  6295,  6296,  6297,  6298,  6299,  6300,  6301,  6302,  6303,
    6304,  6305,  6306,  6307,  6308,  6309,  6310,  6311,  6312,  6313,
    6314,  6315,  6316,  6317,  6318,  6319,  6320,  6321,  6322,  6323,
    6324,  6325,  6326,  6327,  6328,  6329,  6330,  6331,  6332,  6333,
    6334,  6335,  6336,  6337,  6338,  6339,  6340,  6341,  6342,  6343,
    6344,  6345,  6346,  6347,  6348,  6349,  6350,  6351,  6352,  6353,
    6354,  6355,  6356,  6357,  6358,  6359,  6360
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
     315
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 11428;
  const int xquery_parser::yynnts_ = 294;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 554;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 316;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 570;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1053 of lalr1.cc  */
#line 15518 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"


/* Line 1055 of lalr1.cc  */
#line 6364 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"


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
  if (driver.parserError != NULL)
    driver.set_expr(new ParseErrorNode(driver.parserError->loc, XPST0003, driver.parserError->msg));
  else
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc), XPST0003, msg));
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

